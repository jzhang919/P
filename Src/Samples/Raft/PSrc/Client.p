// ------------------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------------------------------------------

machine Client
{
    var Cluster: machine;
    var LatestKey: string;
    var LatestVal: string;
    var Counter: int;
    var LeaderServer: machine;
    var LeaderServer2: machine;
    var UpdateServer: machine;

    start state Init
    {
        entry
        {
            LatestKey = default(string);
            LatestVal = default(string);
            Counter = 0;
        }
        on CConfigureEvent do (payload: machine) {
            Configure(payload);
        } 
        on LocalEvent goto PumpRequest;
    }

    fun Configure(payload: machine)
    {
        Cluster = payload;
        UpdateServer = new Server();
        LeaderServer = UpdateServer;
        send Cluster, AddServer, UpdateServer;
        UpdateServer = new Server();
        LeaderServer2 = UpdateServer;
        send Cluster, AddServer, UpdateServer;
        UpdateServer = new Server();
        send Cluster, AddServer, UpdateServer;
        UpdateServer = new Server();
        send Cluster, AddServer, UpdateServer;
        raise LocalEvent;
    }

    state PumpRequest
    { 
        entry
        {
            LatestKey = "k{0}", Counter;
            LatestVal = "v{0}", Counter;
            Counter = Counter + 1;
            //Logger.WriteLine("\n [Client] new request " + this.LatestCommand + "\n");
            print "\n\n\n[Client] new request <{0}, {1}>\n", LatestKey, LatestVal;
            send Cluster, Request, (Client=this, Key=LatestKey, Val=LatestVal);
        }    

        on Response do {
            ProcessResponse();
        }
        on LocalEvent goto PumpRequest;
    }


    fun ChooseVal() : int {
        // return a random value between 0 - 100
        return Counter;
        // var index : int;
        // index = 0;
        // while(index < 100)
        // {
        //     if($)
        //     {
        //         return index;
        //     }
        //     index = index + 1;
        // }

        // return index;
    }

    fun ProcessResponse()
    {
        print "In ProcessResponse of Client";
        if (Counter == 20){
            UpdateServer = new Server();
            send Cluster, AddServer, UpdateServer;
        }
        if (Counter == 50){
            send Cluster, RemoveServer, LeaderServer;
            // send Cluster, RemoveServer, LeaderServer2;
        }
        if (Counter == 100)
        {

            send Cluster, ShutDown;
            raise halt;
        }
        else
        {
            raise LocalEvent;
        }
    }
}

