// ------------------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------------------------------------------

machine ClusterManager
{
	var Servers: seq[machine];
	var NumberOfServers: int;
	var Leader: machine;
	var LeaderTerm: int;
	var Client: machine;
	var Timer: machine;
	var UpdatingConfig: bool;

	start state Init
	{
		entry
		{
			NumberOfServers = 0;
			LeaderTerm = -1;
			Servers = default(seq[machine]);
			UpdatingConfig = false;
			raise LocalEvent;
		}

		on LocalEvent goto Initialize;
		defer AddServer, RemoveServer, Request, AddServerResponse, RemoveServerResponse;
		ignore MakeUnavailable;

	}

	state Initialize
	{
		entry
		{
			var idx: int;
			idx = 0;
			Timer = new WallclockTimer();
			while(idx < NumberOfServers)
			{
				print "[ClusterManager | Initialize] Initializing server {0}\n", idx;
				send Servers[idx], SConfigureEvent, (Servers = Servers, ClusterManager = this);
				idx = idx + 1;
			}
			//send Client, CConfigureEvent, this;
			if (NumberOfServers > 2){
				send Timer, ConfigureWallclock, (Servers=Servers, ClusterManager=this);
				raise LocalEvent;
			}
		}

		on AddServer do (server: machine){
			var idx: int;
			if (NumberOfServers > 2){
				send this, AddServer, server;
				raise LocalEvent;
			}
			else {
				idx = 0;
				Servers += (sizeof(Servers), server);
				NumberOfServers = NumberOfServers + 1;
				if (NumberOfServers > 2) {
					send Timer, ConfigureWallclock, (Servers=Servers, ClusterManager=this);
					while(idx < NumberOfServers)
					{
						print "[ClusterManager | Initialize] Initializing server {0}\n", idx;
						send Servers[idx], SConfigureEvent, (Servers = Servers, ClusterManager = this);
						idx = idx + 1;
					}
					raise LocalEvent;
				}
			}
		}
		defer RemoveServer, Request, AddServerResponse, RemoveServerResponse;
		on LocalEvent goto Unavailable;
		ignore MakeUnavailable, Response;

	}

	state Unavailable
	{
		entry {
			send Timer, StartTimer;
		}
		on NotifyLeaderUpdate do (payload: (Leader: machine, Term: int)) {
			UpdateLeader(payload);
        	raise LocalEvent;
		}
		on ShutDown do ShuttingDown;
		on LocalEvent goto Available;
		on SentAllTicks do {
			send Timer, TickEvent;
		}
		defer Request, AddServer, RemoveServer, AddServerResponse, RemoveServerResponse;
		ignore MakeUnavailable, Response;
	}

	fun UpdateLeader(request: (Leader: machine, Term: int))
    {
        if (LeaderTerm < request.Term)
        {
            Leader = request.Leader;
            LeaderTerm = request.Term;
        }
    }

	fun ShuttingDown()
	{
		var idx: int;
		idx = 0;
		while (idx < NumberOfServers)
        {
            send Servers[idx], ShutDown;
        	idx = idx + 1;
        }
		send Timer, halt;

        raise halt;
	}

	state Available
	{
		on Request do (payload: (Client: machine, Key: string, Val: string)){
			print "[ClusterManager] Request <{0}, {1}> sent from client {2}\n", payload.Key, payload.Val, payload.Client;
			send Leader, Request, (Client=payload.Client, Key=payload.Key, Val=payload.Val);
		}
		on RedirectRequest do (payload: (Client: machine, Key: string, Val: string)){
			send this, Request, payload;
			raise LocalEvent;
		}
		on NotifyLeaderUpdate do (payload: (Leader: machine, Term: int)){
			UpdateLeader(payload);
		}
		on AddServer do (server: machine){
			if (UpdatingConfig)
			{
				send this, AddServer, server;
			} else {
				AddServerToCluster(server);
			}
		}

		on RemoveServer do (server: machine){
			if (UpdatingConfig)
			{
				send this, RemoveServer, server;
			} else {
				RemoveServerFromCluster(server);
			}	
		}

		on AddServerResponse do (payload: (Server: machine, ServerAdded: bool)){
			UpdatingConfig = false;
			if (!payload.ServerAdded){
				send this, AddServer, payload.Server;
				raise LocalEvent;
			} else {
				Servers += (sizeof(Servers), payload.Server);
				NumberOfServers = NumberOfServers + 1;
				send Timer, UpdateServers, Servers;
			}
		}

		on RemoveServerResponse do (payload: (Server: machine, ServerRemoved: bool)){
			var idx: int;
			idx = 0;
			UpdatingConfig = false;
			if (!payload.ServerRemoved){
				send this, RemoveServer, payload.Server;
				raise LocalEvent;
			} else {
				while (idx < NumberOfServers){
					if (Servers[idx] == payload.Server){
						Servers -= idx;
						break;
					}
					idx = idx + 1;
				} 
				NumberOfServers = NumberOfServers - 1;
				send Timer, UpdateServers, Servers;
			}
		}

		ignore Response;
		on ShutDown do ShuttingDown;
		on LocalEvent goto Unavailable;
		on SentAllTicks do {
			print "ClusterManager sending a tick event\n";
			send Timer, TickEvent;
		}
		on MakeUnavailable goto Unavailable;
	}

    fun AddServerToCluster(server: machine){
    	UpdatingConfig = true;
    	send Timer, UpdateServers, Servers;
    	send Leader, AddServer, server;
    }

    fun RemoveServerFromCluster(server: machine){
    	UpdatingConfig = true;
    	send Leader, RemoveServer, server;
    }
}
