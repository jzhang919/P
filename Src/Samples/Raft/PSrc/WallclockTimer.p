machine WallclockTimer
{
    var Servers: seq[machine];
    var ClusterManager: machine;

    start state Init
    {
        on ConfigureWallclock do (payload: (Servers: seq[machine], ClusterManager: machine)) {
            Servers = payload.Servers;
            ClusterManager = payload.ClusterManager;
        }
        on StartTimer goto Active;
    }

    state Active
    {
        entry
        {
            send this, TickEvent;
        }

        on UpdateServers do (Svrs: seq[machine]){
            Servers = Svrs;
        }
        on TickEvent do Tick;
        on CancelTimer goto Inactive;
        ignore StartTimer; //, CheckLogsOnShutDown;
    }

    fun Tick()
    {
        // send TickEvents to every server
        var i: int;
        i = 0;
        print "Size of Servers: {0}\n", sizeof(Servers);
        while (i < sizeof(Servers))
        {
            send Servers[i], TickEvent;
            i = i + 1;
        }
        send ClusterManager, SentAllTicks; // After broadcasting send to ClusterManager
    }

    state Inactive
    {
        on StartTimer goto Active;
        defer CancelTimer, TickEvent; // defer or ignore?
    }
}

