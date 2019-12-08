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
        if (Counter == 30){
            send Cluster, RemoveServer, UpdateServer;
        }
        if (Counter == 32)
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

