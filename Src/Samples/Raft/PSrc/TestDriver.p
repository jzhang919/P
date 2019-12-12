/* This file implements various test-drivers and also provides the various test-cases that are model-checked by the P Checker*/


/*
This machine creates 3 servers, 1 client
*/

machine TestDriver0 {
	var Cluster : machine;
	var Counter: int;
	var ServiceCounter: int;
	var Servers: seq[machine];
	var NumServers: int;
    var LatestKey: string;
    var LatestVal: string;

	start state Init {
		entry {
			var Server: machine;
			var idx: int;
			
			ServiceCounter = 0;
			Counter = 0;
			NumServers = 3;
            LatestKey = default(string);
            LatestVal = default(string);
			idx = 0;
			Cluster = new ClusterManager(this);

			while (idx < NumServers) {
				Server = new Server();
				Servers += (idx, Server);
        		send Cluster, AddServer, Server;
				idx = idx + 1;
			}
			goto Running;
		}	
	}

	state Running {
		entry {
			SendRequestToCluster();
		}
		on Response do {
			ServiceCounter = ServiceCounter + 1;
			if (ServiceCounter == 100) {
				send Cluster, ShutDown;
				raise halt;
			}
		}

		on TickEvent do {
			SendRequestToCluster();
		}
	}
    
	fun SendRequestToCluster() {
        LatestKey = "k{0}", Counter;
        LatestVal = "v{0}", Counter;
        Counter = Counter + 1;
        print "\n\n\n[Client] new request <{0}, {1}>\n", LatestKey, LatestVal;
        send Cluster, Request, (Client=this, Key=LatestKey, Val=LatestVal);
    }
}



// checks that all events are handled correctly in the ideal case with no failures
test Test0[main = TestDriver0]: assert SafetyMonitor in { TestDriver0, ClusterManager, Server, WallclockTimer };


// Removes a server from the cluster and then adds a new one every request.
machine TestDriver1 {
	var Cluster : machine;
	var Counter: int;
	var Servers: seq[machine];
	var NumServers: int;
    var LatestKey: string;
    var LatestVal: string;

	start state Init {
		entry {
			var Server: machine;
			var idx: int;
			
			Counter = 0;
			NumServers = 5;
            LatestKey = default(string);
            LatestVal = default(string);
			idx = 0;
			Cluster = new ClusterManager(this);

			while (idx < NumServers) {
				Server = new Server();
				Servers += (idx, Server);
        		send Cluster, AddServer, Server;
				idx = idx + 1;
			}
			goto Running1;
		}	
	}

	state Running1 {
		entry {
			SendRequestToCluster();
		}
		on Response do {
			var Server: machine;

			if (Counter >= 100) {
				send Cluster, ShutDown;
				raise halt;
			}
			send Cluster, RemoveServer, Servers[2];
			Servers -= 2;
			SendRequestToCluster();

			Server = new Server();
			Servers += (sizeof(Servers), Server);
			send Cluster, AddServer, Server;
			
			SendRequestToCluster();
		}
	}
    
	fun SendRequestToCluster() {
        LatestKey = "k{0}", Counter;
        LatestVal = "v{0}", Counter;
        Counter = Counter + 1;
        print "\n\n\n[Client] new request <{0}, {1}>\n", LatestKey, LatestVal;
        send Cluster, Request, (Client=this, Key=LatestKey, Val=LatestVal);
    }
}

test Test1[main = TestDriver1] : assert SafetyMonitor in { TestDriver1, ClusterManager, Server, WallclockTimer };


/* 
The failure injector machine randomly selects a participant machine and enqueues a special event "halt"
On dequeueing a halt event, the P machine destroyes itself safely. 
This is one way of modeling node failures in P.
Note that as the model-checker explores all possible interleavings. The failure injecture is exhaustive and can add a failure at all possible interleaving points.
*/

event InjectFailure;

machine FailureInjector {
	var Participants: seq[machine];
	var FailedSoFar: int;

	start state Init {
		entry (participants: seq[machine]){
			Participants = participants;
			FailedSoFar = 0;
		}
		on InjectFailure do {
			var i : int;
			i = 0;
			while(i< sizeof(Participants)) {
				if(FailedSoFar < 5 && $) {
					if ($) {
						send Participants[i], halt;
						FailedSoFar = FailedSoFar + 1;
						break;
					}
				}
				i = i + 1;
			}		
		}
	}
}

// Randomly fails 4 machines. Raft can tolerate (n-1)/2 failures
machine TestDriver2 {
	var Cluster : machine;
	var Counter: int;
	var Servers: seq[machine];
	var NumServers: int;
    var LatestKey: string;
    var LatestVal: string;
	var FailureInjector: machine;

	start state Init {
		entry {
			var Server: machine;
			var idx: int;
			
			Counter = 0;
			NumServers = 10;
            LatestKey = default(string);
            LatestVal = default(string);
			idx = 0;
			Cluster = new ClusterManager(this);

			while (idx < NumServers) {
				Server = new Server();
				Servers += (idx, Server);
        		send Cluster, AddServer, Server;
				idx = idx + 1;
			}
			FailureInjector = new FailureInjector(Servers);
			goto Running2;
		}	
	}

	state Running2 {
		entry {
			SendRequestToCluster();
		}
		on Response do {
			var Server: machine;

			if (Counter >= 100) {
				send Cluster, ShutDown;
				raise halt;
			}
			if ($) {
				send FailureInjector, InjectFailure;
			}
			
			SendRequestToCluster();
		}
	}
    
	fun SendRequestToCluster() {
        LatestKey = "k{0}", Counter;
        LatestVal = "v{0}", Counter;
        Counter = Counter + 1;
        print "\n\n\n[Client] new request <{0}, {1}>\n", LatestKey, LatestVal;
        send Cluster, Request, (Client=this, Key=LatestKey, Val=LatestVal);
    }
}

test Test2[main = TestDriver2] : assert SafetyMonitor in { TestDriver2, ClusterManager, Server, WallclockTimer, FailureInjector };
