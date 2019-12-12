// ------------------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------------------------------------------

machine Server
{
    var ClusterManager : machine;
    var Servers: seq[machine];
    var LeaderId: machine;
    var CurrentTerm: int;
    var VotedFor: machine;
    var Logs: seq[Log];
    var ConfigLogs: seq[Config];
    var CommitServers: seq[machine];
    var CommitIndex: Idxs;
    var NextIndex: map[machine, Idxs];
    var MatchIndex: map[machine, Idxs];
    var VotesReceived: int;
    var LastClientRequest: (Client: machine, Key: string, Val: string);

    // Server to be added or removed from configuration.
    var UpdateServer: machine;
    //0 if no update; 1 if add; 2 if remove
    var UpdateType: int;

    var MaxTicks: int;  // Randomly set ceiling for tick count
    var TickCounter: int; // Ticks seen so far. Reset at certain points.

    // Special case when the Leader is being removed from the config through removeServer.
    // Check Raft paper Section 6, issue 2 on page 12. 
    // "there will be a period of time when the leader is managing a cluster that does not include itself; it replicates log entries but does not count itself in majorities."
    var LeaderNotInCfg: bool;

    start state Init
    {
        entry
        {
            CurrentTerm = 0;
            LeaderId = default(machine);
            VotedFor = default(machine);
            ConfigLogs = default(seq[Config]);
            Logs = default(seq[Log]);
            CommitIndex = default(Idxs);
            NextIndex = default(map[machine, Idxs]);
            MatchIndex = default(map[machine, Idxs]);

            UpdateServer = default(machine);
            UpdateType = 0;
            LeaderNotInCfg = false;
        }

        /*
            @Receive: Configuration payload from ClusterManager. 
        */
        on SConfigureEvent do (payload: (Servers: seq[machine], ClusterManager: machine)) {
            configServer(payload);            
        }
        on BecomeFollower goto Follower;
        on BecomeLeader goto Leader;
        defer VoteRequest, AppendEntriesRequest;
    }

    fun configServer(payload: (Servers: seq[machine], ClusterManager: machine)){
            Servers = payload.Servers;
            ClusterManager = payload.ClusterManager;    
            TickCounter = 0;
            MaxTicks = getMaxTickValue();
            raise BecomeFollower;
        
    }

    // Get "random" value for MaxTicks
    fun getMaxTickValue() : int {
        var i: int;
        i = 350;
        while (i > 250) {    
            i = i - 5;
            if ($) {
                if ($) {
                    if ($) {
                    print "MaxTicks {0} for {1}\n", i, this;
                    return i;
                    }
                }
            }
        }
        print "MaxTicks {0} for {1}\n", i, this;
        return i;
    }

    state Follower
    {
        entry
        {
            print "[Follower] {0} onEntry\n", this;
            LeaderId = default(machine);
            VotesReceived = 0;
            TickCounter = 0;  // Reset on entry
        }

        on Request do (payload: (Client: machine, Key: string, Val: string)) {
            if (LeaderId != null)
            {
                print "[Follower | Request] {0} sends request to Leader {1}\n", this, LeaderId;
                send LeaderId, Request, (Client=payload.Client, Key=payload.Key, Val=payload.Val);
            }
            else
            {
                print "[Follower | Request] {0} no Leader, redirect to ClusterManager.\n", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        on VoteRequest do (payload: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs)) {
            // Section 6: Servers disregard RequestVote RPCs when they believe a current leader exists
            if (LeaderId == null) {
                print "[Follower | VoteRequest] Server {0} | Payload Term {1} | Current Term {2}\n", this, payload.Term, CurrentTerm;
                if (payload.Term > CurrentTerm)
                {
                    CurrentTerm = payload.Term;
                    VotedFor = default(machine);
                }
                Vote(payload);
            }
        }

        // TODO: see if this ever shows up. It doesn't really make sense for a follower to receive a vote response
        on VoteResponse do (request: (Term: int, VoteGranted: bool)) {
            print "[Follower | VoteResponse] Server {0} | Payload Term {1} | Current Term {2}\n", this, request.Term, CurrentTerm;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
            }
        }

        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine)){
            print "[Follower | AppendEntriesRequest] Server {0}", this;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
            }
            AppendEntries(request);
        }

        // TODO: see if this ever shows up. It doesn't really make sense for a follower to receive an append entries response
        on AppendEntriesResponse do (request: (Term: int, Success: bool, KV: bool, Cfg: bool, Server: machine,
         ReceiverEndpoint: machine)){
            print "[Follower | AppendEntriesResponse] Server {0}\n", this;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
            }
        }
        // on ETimeout do {
        //     raise BecomeCandidate;
        // }
        on TickEvent do {
            TickCounter = TickCounter + 1;
            print "[Follower] {0} TickCounter {1}, MaxTicks {2}\n", this, TickCounter, MaxTicks;
            if (TickCounter >= MaxTicks) {
                LeaderId = default(machine);
                raise BecomeCandidate;
            }
        }
        on ShutDown do { 
            ShuttingDown();
        }
        on AddServer do (server: machine){
            send ClusterManager, AddServerResponse, (Server=server, ServerAdded=false);
        }
        on RemoveServer do(server: machine){
            send ClusterManager, RemoveServerResponse, (Server=server, ServerRemoved=false);
        }
        on BecomeFollower goto Follower;
        on BecomeCandidate goto Candidate;

        ignore SConfigureEvent;
    }


    state Candidate
    {
        entry
        {
            send ClusterManager, MakeUnavailable;
            CurrentTerm = CurrentTerm + 1;
            VotedFor = this;
            VotesReceived = 1;
            TickCounter = 0;  // Reset on entry

            //Logger.WriteLine("\n [Candidate] " + this.ServerId + " | term " + this.CurrentTerm + " | election votes " + this.VotesReceived + " | log " + this.Logs.Count + "\n");
            print "\n [Candidate] {0} on Entry | Term {1} | Votes Received {2} | KV Log # entries: {3} | Cfg Log # Entries {4}\n", this, CurrentTerm, VotesReceived, sizeof(Logs), sizeof(ConfigLogs); 

            BroadcastVoteRequests();
        }

        on Request do (payload: (Client: machine, Key: string, Val: string)) {
            // this should be throwing an error?
            if (LeaderId != null)
            {
                print "[Candidate | Request] {0} sends request to Leader {1}\n", this, LeaderId;
                send LeaderId, Request, payload;
            }
            else
            {
                print "[Candidate | Request] {0} no leader, redirect to ClusterManager\n", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        
        on VoteRequest do (request: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs)){
            print "[Candidate | VoteRequest] Server {0} | Payload Term {1} | Current Term {2}\n", this, request.Term, CurrentTerm;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
                Vote(request);
                raise BecomeFollower;
            }
            else
            {
                Vote(request);
            }
        }

        on VoteResponse do (request: (Term: int, VoteGranted: bool)) {
            print "[Candidate | VoteResponse] Server {0} | Payload Term {1} | Current Term {2}\n", this, request.Term, CurrentTerm;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
                raise BecomeFollower;
            }
            else if (request.Term != CurrentTerm)
            {
            }

            else if (request.VoteGranted)
            {
                VotesReceived = VotesReceived + 1;
                if (VotesReceived >= (sizeof(Servers) / 2) + 1)
                {
                  print "\n [Leader] {0} | term {1} | election votes {2} | KV log size {3} | Cfg Log size {4} \n", this, CurrentTerm, VotesReceived, sizeof(Logs), sizeof(ConfigLogs); 
                    VotesReceived = 0;
                    raise BecomeLeader;
                }
            }
        }

        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine)){
            var success: bool;
            print "[Candidate | AppendEntriesRequest] Server {0}\n", this;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
                AppendEntries(request);
                raise BecomeFollower;
            }
            else
            {
                success = AppendEntries(request);
                if (success) {
                    // If a candidate successfully appendsEntry from another server, it should revert back to the follower state.
                    // Note: this seems to happen in the case the request.Term == CurrentTerm
                    raise BecomeFollower;
                }
            }
        }
        on AppendEntriesResponse do (request: (Term: int, Success: bool, KV: bool, Cfg: bool, Server: machine, ReceiverEndpoint: machine)) {
            print "[Candidate | AppendEntriesResponse] Server {0}\n", this;
            RespondAppendEntriesAsCandidate(request);
        }
        // on ETimeout do {
        //     raise BecomeCandidate;
        // }
       // on PTimeout do BroadcastVoteRequests;
        on TickEvent do {
            TickCounter = TickCounter + 1;
            print "[Candidate] {0} TickCounter {1}, MaxTicks {2}\n", this, TickCounter, MaxTicks;
            if (TickCounter >= MaxTicks) {
                raise BecomeCandidate;
            }
        }
        on AddServer do (server: machine){
            send ClusterManager, AddServerResponse, (Server=server, ServerAdded=false);
        }
        on RemoveServer do(server: machine){
            send ClusterManager, RemoveServerResponse, (Server=server, ServerRemoved=false);
        }
        on ShutDown do ShuttingDown;
        on BecomeLeader goto Leader;
        on BecomeFollower goto Follower;
        on BecomeCandidate goto Candidate;
        ignore SConfigureEvent;
    }

    fun BroadcastVoteRequests()
    {
        // BUG: duplicate votes from same follower
        var idx: int;
        var lastLogIndex: int;
        var lastLogTerm: int; 
        var lastCfgLogIndex: int;
        var lastCfgLogTerm: int;

        idx = 0;
        while (idx < sizeof(Servers)) {
           if (this == Servers[idx]) {
                idx = idx + 1;
                continue;
           }
            lastLogIndex = sizeof(Logs) - 1;
            lastLogTerm = GetLogTermForIndex(lastLogIndex, true);
            lastCfgLogIndex = sizeof(ConfigLogs) - 1;
            lastCfgLogTerm = GetLogTermForIndex(lastCfgLogIndex, false);

            print "Sending VoteRequest from Server {0} to Server {1}\n", this, Servers[idx];
            send Servers[idx], VoteRequest, (Term=CurrentTerm, CandidateId=this, LastLogIndex=(KV=lastLogIndex, Cfg=lastCfgLogIndex), LastLogTerm=(KV=lastLogTerm, Cfg=lastCfgLogTerm));
            idx = idx + 1;
        }
    }

    fun RespondAppendEntriesAsCandidate(request: (Term: int, Success: bool, KV:bool, Cfg:bool, Server: machine, ReceiverEndpoint: machine))
    {
        if (request.Term > CurrentTerm)
        {
            CurrentTerm = request.Term;
            VotedFor = default(machine);
            raise BecomeFollower;
        }
    }

    state Leader
    {
        entry
        {
            var KVLogIndex: int;
            var ConfigLogIndex: int;
            var KVLogTerm: int;
            var ConfigLogTerm: int;
            var idx: int;

            CommitIndex = default(Idxs);                                                                              

            announce M_NotifyLeaderElected, (Term=CurrentTerm, Logs=Logs);
            send ClusterManager, NotifyLeaderUpdate, (Leader=this, Term=CurrentTerm);
            
            // Fixed Leader MaxTicks. Used for heartbeat
            MaxTicks = 5;
            KVLogIndex = sizeof(Logs) - 1;
            KVLogTerm = GetLogTermForIndex(KVLogIndex, true);
            ConfigLogIndex = sizeof(ConfigLogs) - 1;
            ConfigLogTerm = GetLogTermForIndex(ConfigLogIndex, false);

            NextIndex = default(map[machine, Idxs]);
            MatchIndex = default(map[machine, Idxs]);
            
            idx = 0;
            while (idx < sizeof(Servers))
            {
                if (this == Servers[idx]) {
                    idx = idx + 1;
                    continue;
                }
                NextIndex[Servers[idx]] = (KV=KVLogIndex + 1, Cfg=ConfigLogIndex + 1);
                MatchIndex[Servers[idx]] = (KV=0, Cfg=0);
                idx = idx + 1;
            }
            // HeartbeatSendAsLeader();
        }

        on Request do (payload: (Client: machine, Key: string, Val: string)) {
            ProcessClientRequest(payload);
        }
        on VoteRequest do (request: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs)) {
            VoteAsLeader(request);
        }
        on VoteResponse do (request: (Term: int, VoteGranted: bool)) {
            RespondVoteAsLeader(request);
        }
        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine)){
            AppendEntriesAsLeader(request);
        }
        on AppendEntriesResponse do (request: (Term: int, Success: bool, KV: bool, Cfg: bool, Server: machine, ReceiverEndpoint: machine)) {
            RespondAppendEntriesAsLeader(request);
        }
        on AddServer do (server: machine){
            UpdateServer = server;
            UpdateType = 1;
            AddServerToConfig(server);
        }
        on RemoveServer do (server: machine){
            UpdateServer = server;
            UpdateType = 2;
            RemoveServerFromConfig(server);
        }

        on ShutDown do ShuttingDown;
        on BecomeFollower goto Follower;

        on TickEvent do {
            TickCounter = TickCounter + 1;
            if (TickCounter >= MaxTicks) {
                HeartbeatSendAsLeader();
                TickCounter = 0;
            }
        }
        ignore SConfigureEvent;
    }

    fun AddServerToConfig(server: machine){
        var cfg: Config;
        Servers += (sizeof(Servers), server);
        send server, SConfigureEvent, (Servers = Servers, ClusterManager = ClusterManager);
        NextIndex[server] = (KV=sizeof(Logs), Cfg=sizeof(ConfigLogs));
        MatchIndex[server] = (KV=0, Cfg=0);
        cfg.Term = CurrentTerm;
        cfg.Servers = Servers;
        ConfigLogs += (sizeof(ConfigLogs), cfg);
    }

    fun RemoveServerFromConfig(server: machine){
        var idx: int;
        var sIdx: int;
        var cfg: Config;

        idx = 0;
        sIdx = -1;

        while (idx < sizeof(Servers)){
            if (Servers[idx]==server){
                sIdx = idx;
                break;
            }
            idx = idx + 1;
        }

        if (sIdx >= 0 && sIdx < sizeof(Servers)){
            if (Servers[sIdx] == this) {
                LeaderNotInCfg = true;
                print "\nSpecial case: removing the current leader from config\n";
            }
            Servers -= sIdx;
        }
        cfg.Term = CurrentTerm;
        cfg.Servers = Servers;
        ConfigLogs += (sizeof(ConfigLogs), cfg);     
    }

    fun UpdateFollowerConfigs (){

    }

    fun ProcessClientRequest(trigger: (Client: machine, Key: string, Val: string))
    {
        var log: Log;
        var cfg: Config;

        print "[Leader | Request] Leader {0} processing Client {1}\n", this, trigger.Client;
        if (LeaderNotInCfg) {
            // Leader should not count itself to majority.
            VotesReceived = 0;
        } else {
            VotesReceived = 1;
        }
        LastClientRequest = trigger;
        log = default(Log);
        log.Term = CurrentTerm;
        log.Key = LastClientRequest.Key;
        log.Val = LastClientRequest.Val;
        print "[Leader | Request] Log Term: {0}, Log Key: {1}, Log Val: {2}, idx: {3}\n", log.Term, log.Key, log.Val, sizeof(Logs);
        Logs += (sizeof(Logs), log);
        announce M_LogAppend, (Server=this, Logs=Logs);

        print "[Leader | Request] Printing Log\n";
        PrintLog();
    }

    fun PrintLog(){
        var idx: int;
        idx = 0;
        while (idx < sizeof(Logs)){
            print "[PrintLog] Log element {0}: {1}\n", idx, Logs[idx];
            idx = idx + 1;
        }
        idx = 0;
        while (idx < sizeof(ConfigLogs)){
            print "[ConfigLog] Log element {0}: {1}\n", idx, ConfigLogs[idx];
            idx = idx + 1;
        }
        print "CommitIndex: KV: {0}, CFG: {1}\n", CommitIndex.KV, CommitIndex.Cfg;
        print "\n\n SIZE OF KV: {0}, CONFIG: {1} \n\n", sizeof(Logs), sizeof(ConfigLogs);
    }

    fun HeartbeatSendAsLeader(){
        var lastLogIndex: int;
        var lastCfgLogIndex: int;
        var sIdx: int;
        var logIdx: int;
        var cfgLogIdx: int;
        var server: machine;
        var sendLog: seq[Log];
        var cfgSendLog: seq[Config];
        var prevLogIndex: int;
        var prevLogTerm: int;
        var prevCfgLogIndex: int;
        var prevCfgLogTerm: int;

        lastLogIndex = sizeof(Logs) - 1;
        lastCfgLogIndex = sizeof(ConfigLogs) - 1;
        // print "\n[Leader | PCR | HeartbeatSendAsLeader] [Leader] {0} sends append requests | term {1} | lastLogIndex: {2}\n", this, CurrentTerm, lastLogIndex;

        while (sIdx < sizeof(Servers))
        {
            server = Servers[sIdx];
            if (this == Servers[sIdx]){                
                sIdx = sIdx + 1;
                continue;
            }
            sendLog = default(seq[Log]);
            cfgSendLog = default(seq[Config]);

            if (lastLogIndex >= NextIndex[server].KV){
                logIdx = NextIndex[server].KV;
                while (logIdx <= lastLogIndex){
                    sendLog += (logIdx - NextIndex[server].KV, Logs[logIdx]);
                    logIdx = logIdx + 1;
                }
            }
            if (lastCfgLogIndex >= NextIndex[server].Cfg){
                cfgLogIdx = NextIndex[server].Cfg;
                while (cfgLogIdx <= lastCfgLogIndex){
                    cfgSendLog += (cfgLogIdx - NextIndex[server].Cfg, ConfigLogs[cfgLogIdx]);
                    cfgLogIdx = cfgLogIdx + 1;
                }
            }

            // print "[Leader | PCR | HeartbeatSendAsLeader] Next index: {0} | sendLog size: {1}", NextIndex[server], sizeof(sendLog);
            prevLogIndex = NextIndex[server].KV - 1;
            prevLogTerm = GetLogTermForIndex(prevLogIndex, true);
            prevCfgLogIndex = NextIndex[server].Cfg - 1;
            prevCfgLogTerm = GetLogTermForIndex(prevCfgLogIndex, false);
            send server, AppendEntriesRequest, (Term=CurrentTerm, LeaderId=this, PrevLogIndex=(KV=prevLogIndex, Cfg=prevCfgLogIndex), 
                PrevLogTerm=(KV=prevLogTerm, Cfg=prevCfgLogTerm), Entries = sendLog, CfgEntries = cfgSendLog, LeaderCommit = CommitIndex, 
                ReceiverEndpoint=LastClientRequest.Client);
            sIdx = sIdx + 1;
        }
    }

    fun VoteAsLeader(request: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs))
    {
        if (request.Term > CurrentTerm)
        {
            print "[Leader | VoteAsLeader] Leader {0} term {1} behind request term {2}.\n", this, CurrentTerm, request.Term;
            CurrentTerm = request.Term;
            VotedFor = default(machine);

            Vote(request);

            raise BecomeFollower;
        }
        else
        {
            Vote(request);
        }
    }

    fun RespondVoteAsLeader(request: (Term: int, VoteGranted: bool))
    {
        if (request.Term > CurrentTerm)
        {
            CurrentTerm = request.Term;
            VotedFor = default(machine);

            RedirectLastClientRequestToClusterManager();
            raise BecomeFollower;
        }
    }

    fun AppendEntriesAsLeader(request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine))
    {
        if (request.Term > CurrentTerm)
        {
            // Leader must have somehow been disconnected from the network?
            print "AppendEntriesAsLeader\n";
            CurrentTerm = request.Term;
            VotedFor = default(machine);

            AppendEntries(request);

            raise BecomeFollower;
        }
    }

    fun RespondAppendEntriesAsLeader(request: (Term: int, Success: bool, KV: bool, Cfg: bool, Server: machine, ReceiverEndpoint: machine))
    {
        var logsAppend: seq[Log];
        var cfgLogsAppend: seq[Config];
        var prevLogIndex: int;
        var prevLogTerm: int; 
        var prevCfgLogIndex: int;
        var prevCfgLogTerm: int;
        var idx: int;
        var cfgLogIdx: int;
        var committedLogs: seq[Log];

        print "[Leader | AppendEntriesResponse] {0} received response {1} from server {2}\n", this, request.Success, request.Server; 
        print "[Leader | AppendEntriesResponse] Leader term: {0}, follower term: {1}\n", CurrentTerm, request.Term;
        if (request.Term > CurrentTerm)
        {
            CurrentTerm = request.Term;
            VotedFor = default(machine);

            RedirectLastClientRequestToClusterManager();
            raise BecomeFollower;
        }
        else if (request.Term < CurrentTerm)
        {
            //Ignore if out of date
        }
        // TODO: check final bullet point of "Rules for servers" in paper
        else if (request.Success)
        {
            print "[Leader | AppendEntriesResponse] Success\n";
            if (request.KV){
                NextIndex[request.Server].KV = sizeof(Logs);
                MatchIndex[request.Server].KV = sizeof(Logs) - 1;                
            }
            if (request.Cfg){
                NextIndex[request.Server].Cfg = sizeof(ConfigLogs);
                MatchIndex[request.Server].Cfg = sizeof(ConfigLogs) - 1;  
            }

            print "[Leader | AppendEntriesResponse] Updated KV Indices: NextIndex: {0}, MatchIndex: {1}\n", NextIndex[request.Server].KV, MatchIndex[request.Server].KV;
            
            VotesReceived = VotesReceived + 1;
            print "[Leader | AppendEntriesResponse] VotesReceived: {0}\n", VotesReceived;
            if (request.ReceiverEndpoint == null) {
                if (!request.Cfg) {
                    VotesReceived = 0;
                }
                print "[Leader | AppendEntriesResponse] request.ReceiverEndpoint: null\n";    
                return;
            }        
            else if (VotesReceived > (sizeof(Servers)-1) / 2)
            {
                print "\n[Leader] {0} | term {1} | append votes {2} | append success\n", this, CurrentTerm, VotesReceived; 
                if (request.KV && MatchIndex[request.Server].KV > CommitIndex.KV &&
                    Logs[MatchIndex[request.Server].KV - 1].Term == CurrentTerm)
                {
                    CommitIndex.KV = MatchIndex[request.Server].KV;
                    print "\n[Leader] {0} | term {1} | log {2} | Key {3} | Val {4}\n", this, CurrentTerm, sizeof(Logs), Logs[MatchIndex[request.Server].KV - 1].Key, Logs[MatchIndex[request.Server].KV - 1].Val;

                }
                if (request.Cfg && MatchIndex[request.Server].Cfg > CommitIndex.Cfg &&
                    ConfigLogs[MatchIndex[request.Server].Cfg -1].Term == CurrentTerm)
                {
                    print "[Leader] Config CommitIndex updated from {0} to {1}\n", CommitIndex.Cfg, MatchIndex[request.Server].Cfg;
                    CommitIndex.Cfg = MatchIndex[request.Server].Cfg;
                }

                VotesReceived = 0;
                // TODO: Should this be null?
                LastClientRequest = (Client=request.ReceiverEndpoint, Key=Logs[CommitIndex.KV].Key, Val=Logs[CommitIndex.KV].Val);

                send request.ReceiverEndpoint, Response;
                
                // Send all CommittedLogs to the SafetyMonitor
                idx = 0;
                while (idx < CommitIndex.KV) {
                    committedLogs += (idx, Logs[idx]);
                    idx = idx + 1;
                }
                announce M_LeaderCommitted, committedLogs;

                if (request.Cfg){
                    if (UpdateType == 1){
                        send ClusterManager, AddServerResponse, (Server=UpdateServer, ServerAdded=true);
                    }
                    if (UpdateType == 2){
                        send ClusterManager, RemoveServerResponse, (Server=UpdateServer, ServerRemoved=true);
                    }
                    UpdateServer = default(machine);
                    UpdateType = 0;
                    if (LeaderNotInCfg) {
                        print "[LeaderNotInCfg] New configuration should have committed, now becoming follower.\n";
                        LeaderNotInCfg = false;
                        raise BecomeFollower;
                    }
                }
            }
        }
        else
        {
            if (NextIndex[request.Server].KV > 0)
            {
                NextIndex[request.Server].KV = NextIndex[request.Server].KV - 1;
                print "NextIndex for {0} is {1}\n", request.Server, NextIndex[request.Server].KV;
            }
            if (NextIndex[request.Server].Cfg > 0){
                NextIndex[request.Server].Cfg = NextIndex[request.Server].Cfg - 1;
            }
            logsAppend = default(seq[Log]);
            
            prevLogIndex = NextIndex[request.Server].KV - 1;
            prevLogTerm = GetLogTermForIndex(prevLogIndex, true);
            prevCfgLogIndex = NextIndex[request.Server].Cfg - 1;
            prevCfgLogTerm = GetLogTermForIndex(prevCfgLogIndex, false);

            idx = NextIndex[request.Server].KV;
            cfgLogIdx = NextIndex[request.Server].Cfg;

            while (idx < sizeof(Logs)) {
                logsAppend += (idx - NextIndex[request.Server].KV, Logs[idx]);
                idx = idx + 1;
            }

            while (cfgLogIdx < sizeof(ConfigLogs)){
                cfgLogsAppend += (cfgLogIdx - NextIndex[request.Server].Cfg, ConfigLogs[cfgLogIdx]);
                cfgLogIdx = cfgLogIdx + 1;
            }

            print "\n[Leader] {0} | term {1} | log {2} | append votes {3} | append fail (next idx = {4})\n", this, CurrentTerm, sizeof(Logs), VotesReceived, NextIndex[request.Server].KV;
            send request.Server, AppendEntriesRequest, (Term=CurrentTerm, LeaderId=this, PrevLogIndex=(KV=prevLogIndex, Cfg=prevCfgLogIndex), 
                PrevLogTerm=(KV=prevLogTerm, Cfg=prevCfgLogTerm), Entries = logsAppend, CfgEntries = cfgLogsAppend, LeaderCommit = CommitIndex, 
                ReceiverEndpoint=LastClientRequest.Client);

        }
        print "[Leader | AppendEntriesResponse] CommitIndex: {0}\n", CommitIndex.KV;
    }

    fun Vote(request: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs))
    {
        var lastLogIndex: int;
        var lastLogTerm: int;
        var lastCfgLogIndex: int;
        var lastCfgLogTerm: int;

        lastLogIndex = sizeof(Logs) - 1;
        lastLogTerm = GetLogTermForIndex(lastLogIndex, true);
        lastCfgLogIndex = sizeof(ConfigLogs) - 1;
        lastCfgLogTerm = GetLogTermForIndex(lastCfgLogIndex, false);

        if (request.Term < CurrentTerm ||
            (VotedFor != default(machine) && VotedFor != request.CandidateId) ||
            lastLogIndex > request.LastLogIndex.KV ||
            lastLogTerm > request.LastLogTerm.KV ||
            lastCfgLogIndex > request.LastLogIndex.Cfg ||
            lastCfgLogTerm > request.LastLogTerm.Cfg)
        {
            print "\n [Server] {0} | term {1} | log {2} | Reject {3}\n", this, CurrentTerm, sizeof(Logs), request.CandidateId;
            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=false);
        }
        else
        {
            print "\n [Server] {0} | term {1} | log {2} | Approve {3}\n", this, CurrentTerm, sizeof(Logs), request.CandidateId;
            TickCounter = 0;

            VotedFor = request.CandidateId;
            LeaderId = default(machine);

            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=true);
        }
    }

    fun AppendEntries(request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine)) : bool
    {
        var idx: int;
        var cfgLogIdx: int;
        var cfg_success: bool;
        var kv_success: bool;

        cfg_success = false;
        kv_success = false;
        if (request.Term < CurrentTerm)
        {   
            // AppendEntries RPC #1
            print "\n[Server] {0} | term {1} | log {2} | append false (<term) \n", this, CurrentTerm, sizeof(Logs);
            send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=false, KV=false, Cfg=false, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
            return false;
        }
        else
        {
            // AppendEntries RPC #2
            // Reply false if log doesn't contain entry @ prevLogIndex (1,2)
            // whose term matches prevLogTerm (3,4)
            if (request.PrevLogIndex.KV >= 0 && sizeof(Logs) <= request.PrevLogIndex.KV ||
                request.PrevLogIndex.Cfg >= 0 && sizeof(ConfigLogs) <= request.PrevLogIndex.Cfg ||
                request.PrevLogIndex.KV >= 0 && Logs[request.PrevLogIndex.KV].Term != request.PrevLogTerm.KV ||
                request.PrevLogIndex.Cfg >= 0 && ConfigLogs[request.PrevLogIndex.Cfg].Term != request.PrevLogTerm.Cfg)
            {
                print "\n[Leader] {0} | term {1} | log {2} | append false (not in log)\n", this, CurrentTerm, sizeof(Logs); 
                send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=false, KV=false, Cfg=false, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
                return false;
            }
            else
            {
                idx = 0;
                // On AppendEntries RPC from current leader, reset ElectionTimer
                if (LeaderId == request.LeaderId) {
                    TickCounter = 0;
                }
              

                // AppendEntries RPC #3
                while (idx < sizeof(request.Entries) && 
                    (idx + request.PrevLogIndex.KV + 1) < sizeof(Logs)){
                    if (Logs[idx + request.PrevLogIndex.KV + 1] != request.Entries[idx]){
                        print "[Follower | AppendEntries] Conflict: Deleting from log entry {0} on\n", idx + request.PrevLogIndex.KV + 1;
                        DeleteFromLog(idx + request.PrevLogIndex.KV + 1, sizeof(Logs), true);
                        break;
                    }
                    idx = idx + 1;
                } 
 
                while (cfgLogIdx < sizeof(request.CfgEntries) &&
                    (cfgLogIdx + request.PrevLogIndex.Cfg + 1) < sizeof(ConfigLogs)){
                    if (ConfigLogs[cfgLogIdx + request.PrevLogIndex.Cfg + 1] != request.CfgEntries[cfgLogIdx]){
                        print "[Follower | AppendEntries] Conflict: Deleting from config log entry {0} on\n", cfgLogIdx + request.PrevLogIndex.Cfg + 1;
                        DeleteFromLog(cfgLogIdx + request.PrevLogIndex.Cfg + 1, sizeof(ConfigLogs), false);
                        break;
                    }
                    cfgLogIdx = cfgLogIdx + 1;
                }

                // print "Num of entries to add: {0}", sizeof(request.Entries);
                // AppendEntries RPC #4. Note we explicitly DO NOT reset idx.
                while (idx < sizeof(request.Entries)){
                    // print "KV Idx: {0}", idx + request.PrevLogIndex.KV + 1;
                    Logs += (idx + request.PrevLogIndex.KV + 1, request.Entries[idx]);
                    announce M_LogAppend, (Server=this, Logs=Logs);
                    idx = idx + 1;
                    kv_success = true;
                }

                while (cfgLogIdx < sizeof(request.CfgEntries)){
                    // print "Cfg Idx: {0}", cfgLogIdx + request.PrevLogIndex.Cfg + 1;
                    ConfigLogs += (cfgLogIdx + request.PrevLogIndex.Cfg + 1, request.CfgEntries[cfgLogIdx]);
                    cfgLogIdx = cfgLogIdx + 1;
                    cfg_success = true;
                }

                if (sizeof(request.CfgEntries) > 0){
                    Servers = ConfigLogs[sizeof(ConfigLogs) - 1].Servers;
                }
                print "finishedloop\n";

                // AppendEntries RPC #5. Index of last new entry is sizeof(Logs) - 1
                if ((request.LeaderCommit.KV > CommitIndex.KV &&
                    sizeof(Logs) <= request.LeaderCommit.KV) ||
                    (request.LeaderCommit.Cfg > CommitIndex.Cfg &&
                    sizeof(ConfigLogs) <= request.LeaderCommit.Cfg))
                {
                    CommitIndex = (KV = sizeof(Logs) - 1, Cfg = sizeof(ConfigLogs) - 1);   
                }
                else if (request.LeaderCommit.KV > CommitIndex.KV &&
                    request.LeaderCommit.Cfg > CommitIndex.Cfg)
                {
                    CommitIndex = request.LeaderCommit;
                }

                print "\n[Server] {0} | term {1} | log {2} | entries received {3} | append true\n", this, CurrentTerm, sizeof(Logs), sizeof(request.Entries); 

                LeaderId = request.LeaderId;
                send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=true, KV=kv_success, Cfg=cfg_success, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
                return true;
            }
        }
    }

    /* Delete entries from class variable Logs, a seq<.
        @param start: Inclusive, first index to delete.
        @param end: Exclusive, delete up to but not including this index.
    */
    fun DeleteFromLog(startIndex: int, endIndex: int, isKV: bool)
    {
        var idx: int;
        idx = endIndex - 1;
        if (isKV){
            while (idx >= startIndex){
                Logs -= idx;
            }
        } else {
            while (idx >= startIndex){
                ConfigLogs -= idx;
            }
        }
    }



    fun RedirectLastClientRequestToClusterManager()
    {
        if (LastClientRequest != null)
        {
            send ClusterManager, Request, (Client=LastClientRequest.Client, Key=LastClientRequest.Key, Val=LastClientRequest.Val);
        }
    }

    fun GetLogTermForIndex(logIndex: int, isKV: bool) : int
    {
        var logTerm: int;
        logTerm = 0;
        print "LogIndex: {0}\n", logIndex;
        if (logIndex >= 0)
        {
            if (isKV){
                logTerm = Logs[logIndex].Term;
            }
            else {
                logTerm = ConfigLogs[logIndex].Term;
            }
        }

        return logTerm;
    }

    fun ShuttingDown()
    {
        raise halt;
    }
}
// }

