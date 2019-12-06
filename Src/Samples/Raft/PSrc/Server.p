// ------------------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------------------------------------------

machine Server
{
    var ServerId : int;
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

    var MaxTicks: int;  // Randomly set ceiling for tick count
    var TickCounter: int; // Ticks seen so far. Reset at certain points.

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
        }

        /*
            @Receive: Configuration payload from ClusterManager. 
        */
        on SConfigureEvent do (payload: (Id: int, Servers: seq[machine], ClusterManager: machine)) {
            configServer(payload);            
        }
        on BecomeFollower goto Follower;
        on BecomeLeader goto Leader;
        defer VoteRequest, AppendEntriesRequest;
    }

    fun configServer(payload: (Id: int, Servers: seq[machine], ClusterManager: machine)){
            ServerId = payload.Id;
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
                    print "MaxTicks {0} for {1}", i, this;
                    return i;
                    }
                }
            }
        }
        print "MaxTicks {0} for {1}", i, this;
        return i;
    }

    state Follower
    {
        entry
        {
            print "[Follower] {0} onEntry", this;
            LeaderId = default(machine);
            VotesReceived = 0;
            TickCounter = 0;  // Reset on entry
        }

        on Request do (payload: (Client: machine, Key: string, Val: string)) {
            if (LeaderId != null)
            {
                print "[Follower | Request] {0} sends request to Leader {1}", this, LeaderId;
                send LeaderId, Request, (Client=payload.Client, Key=payload.Key, Val=payload.Val);
            }
            else
            {
                print "[Follower | Request] {0} no Leader, redirect to ClusterManager.", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        on VoteRequest do (payload: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs)) {
            print "[Follower | VoteRequest] Server {0} | Payload Term {1} | Current Term {2}", this, payload.Term, CurrentTerm;
            if (payload.Term > CurrentTerm)
            {
                CurrentTerm = payload.Term;
                VotedFor = default(machine);
            }
            Vote(payload);
        }

        // TODO: see if this ever shows up. It doesn't really make sense for a follower to receive a vote response
        on VoteResponse do (request: (Term: int, VoteGranted: bool)) {
            print "[Follower | VoteResponse] Server {0} | Payload Term {1} | Current Term {2}", this, request.Term, CurrentTerm;
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
        on AppendEntriesResponse do (request: (Term: int, Success: bool, Server: machine,
         ReceiverEndpoint: machine)){
            print "[Follower | AppendEntriesResponse] Server {0}", this;
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
            print "[Follower] {0} TickCounter {1}, MaxTicks {2}", this, TickCounter, MaxTicks;
            if (TickCounter >= MaxTicks) {
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

        //ignore PTimeout;
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
                print "[Candidate | Request] {0} sends request to Leader {1}", this, LeaderId;
                send LeaderId, Request, payload;
            }
            else
            {
                print "[Candidate | Request] {0} no leader, redirect to ClusterManager", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        
        on VoteRequest do (request: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs)){
            print "[Candidate | VoteRequest] Server {0} | Payload Term {1} | Current Term {2}", this, request.Term, CurrentTerm;
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
            print "[Candidate | VoteResponse] Server {0} | Payload Term {1} | Current Term {2}", this, request.Term, CurrentTerm;
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
                   // this.Logger.WriteLine("\n [Leader] " + this.ServerId + " | term " + this.CurrentTerm +
                    //    " | election votes " + this.VotesReceived + " | log " + this.Logs.Count + "\n");
                    print "\n [Leader] {0} | term {1} | election votes {2} | KV log size {3} | Cfg Log size {4} \n", this, CurrentTerm, VotesReceived, sizeof(Logs), sizeof(ConfigLogs); 
                    VotesReceived = 0;
                    raise BecomeLeader;
                }
            }
        }
        // TODO: Confirm that commenting out AppendEntries below is correct
        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine)){
            print "[Candidate | AppendEntriesRequest] Server {0}", this;
            if (request.Term > CurrentTerm)
            {
                CurrentTerm = request.Term;
                VotedFor = default(machine);
                AppendEntries(request);
                raise BecomeFollower;
            }
            else
            {
                AppendEntries(request);
            }
        }
        on AppendEntriesResponse do (request: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine)) {
            print "[Candidate | AppendEntriesResponse] Server {0}", this;
            RespondAppendEntriesAsCandidate(request);
        }
        // on ETimeout do {
        //     raise BecomeCandidate;
        // }
       // on PTimeout do BroadcastVoteRequests;
        on TickEvent do {
            TickCounter = TickCounter + 1;
            print "[Candidate] {0} TickCounter {1}, MaxTicks {2}", this, TickCounter, MaxTicks;
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
           if (idx == ServerId) {
                idx = idx + 1;
                continue;
           }
            lastLogIndex = sizeof(Logs) - 1;
            lastLogTerm = GetLogTermForIndex(lastLogIndex, true);
            lastCfgLogIndex = sizeof(ConfigLogs) - 1;
            lastCfgLogTerm = GetLogTermForIndex(lastCfgLogIndex, false);

            print "Sending VoteRequest from Server {0} to Server {1}", this, Servers[idx];
            send Servers[idx], VoteRequest, (Term=CurrentTerm, CandidateId=this, LastLogIndex=(KV=lastLogIndex, Cfg=lastCfgLogIndex), LastLogTerm=(KV=lastLogTerm, Cfg=lastCfgLogTerm));
            idx = idx + 1;
        }
    }

    fun RespondAppendEntriesAsCandidate(request: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine))
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

            announce EMonitorInit, (NotifyLeaderElected, CurrentTerm);
            //monitor<SafetyMonitor>(NotifyLeaderElected, CurrentTerm);
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
                if (idx == ServerId) {
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
        on AppendEntriesResponse do (request: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine)) {
            RespondAppendEntriesAsLeader(request);
        }
        on AddServer do (server: machine){
            AddServerToConfig(server);
            UpdateFollowerConfigs();
        }
        on RemoveServer do (server: machine){
            RemoveServerFromConfig(server);
            UpdateFollowerConfigs();
        }

        on ShutDown do ShuttingDown;
        on BecomeFollower goto Follower;

        on TickEvent do {
            TickCounter = TickCounter + 1;
            if (TickCounter >= MaxTicks) {
                // TODO : sent heartbeat here
                HeartbeatSendAsLeader();
                TickCounter = 0;
            }
        }
        //ignore ETimeout, PTimeout;
    }

    fun AddServerToConfig(server: machine){
        Servers += (sizeof(Servers), server);
    }

    fun RemoveServerFromConfig(server: machine){
        var idx: int;
        var sIdx: int;
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
            Servers -= sIdx;
        }
    }

    fun UpdateFollowerConfigs (){

    }

    fun ProcessClientRequest(trigger: (Client: machine, Key: string, Val: string))
    {
        var log: Log;
        print "[Leader | Request] Leader {0} processing Client {1}", this, trigger.Client;
        LastClientRequest = trigger;
        log = default(Log);
        log.Term = CurrentTerm;
        log.Key = LastClientRequest.Key;
        log.Val = LastClientRequest.Val;
        print "[Leader | Request] Log Term: {0}, Log Key: {1}, Log Val: {2}, idx: {3}", log.Term, log.Key, log.Val, sizeof(Logs);
        Logs += (sizeof(Logs), log);
        print "[Leader | Request] Printing Log";
        PrintLog();
    }

    fun PrintLog(){
        var idx: int;
        idx = 0;
        while (idx < sizeof(Logs)){
            print "[PrintLog] Log element {0}: {1}", idx, Logs[idx];
            idx = idx + 1;
        }
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
        print "\n[Leader | PCR | HeartbeatSendAsLeader] [Leader] {0} sends append requests | term {1} | lastLogIndex: {2}\n", this, CurrentTerm, lastLogIndex;

        while (sIdx < sizeof(Servers))
        {
            // print "On server {0}", sIdx;
            server = Servers[sIdx];
            if (sIdx == ServerId || lastLogIndex < NextIndex[server].KV || lastCfgLogIndex < NextIndex[server].Cfg){
                sIdx = sIdx + 1;
                continue;
            }
            sendLog = default(seq[Log]);
            logIdx = NextIndex[server].KV;
            cfgLogIdx = NextIndex[server].Cfg;
            while (logIdx <= lastLogIndex){
                sendLog += (logIdx - NextIndex[server].KV, Logs[logIdx]);
                logIdx = logIdx + 1;
            }
            while (cfgLogIdx <= lastCfgLogIndex){
                cfgSendLog += (cfgLogIdx - NextIndex[server].Cfg, ConfigLogs[cfgLogIdx]);
                cfgLogIdx = cfgLogIdx + 1;
            }
            print "[Leader | PCR | HeartbeatSendAsLeader] Next index: {0} | sendLog size: {1}", NextIndex[server], sizeof(sendLog);
            prevLogIndex = NextIndex[server].KV - 1;
            prevLogTerm = GetLogTermForIndex(prevLogIndex, true);
            prevCfgLogIndex = NextIndex[server].Cfg - 1;
            prevCfgLogTerm = GetLogTermForIndex(prevCfgLogIndex, false);
            //TODO: Fix compile error
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
            print "[Leader | VoteAsLeader] Leader {0} term {1} behind request term {2}.", this, CurrentTerm, request.Term;
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
            CurrentTerm = request.Term;
            VotedFor = default(machine);

            AppendEntries(request);

            raise BecomeFollower;
        }
    }

    fun RespondAppendEntriesAsLeader(request: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine))
    {
        var commitIndex: int;
        var logsAppend: seq[Log];
        var cfgLogsAppend: seq[Config];
        var prevLogIndex: int;
        var prevLogTerm: int; 
        var prevCfgLogIndex: int;
        var prevCfgLogTerm: int;
        var idx: int;
        var cfgLogIdx: int;

        print "[Leader | AppendEntriesResponse] {0} received response {1} from server {2}", this, request.Success, request.Server; 
        print "[Leader | AppendEntriesResponse] Leader term: {0}, follower term: {1}", CurrentTerm, request.Term;
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
            print "[Leader | AppendEntriesResponse] Success; preparing commit.";
            NextIndex[request.Server].KV = sizeof(Logs);
            MatchIndex[request.Server].KV = sizeof(Logs) - 1;
            print "[Leader | AppendEntriesResponse] Updated KV Indices: NextIndex: {0}, MatchIndex: {1}", NextIndex[request.Server].KV, MatchIndex[request.Server].KV;
            
            VotesReceived = VotesReceived + 1;
            print "[Leader | AppendEntriesResponse] VotesReceived: {0}", VotesReceived;
            if (request.ReceiverEndpoint == null){
                print "[Leader | AppendEntriesResponse] request.ReceiverEndpoint: null";    
                return;
            }        
            else if (VotesReceived > (sizeof(Servers)-1) / 2)
            {
                print "\n[Leader] {0} | term {1} | append votes {2} | append success\n", this, CurrentTerm, VotesReceived; 
                commitIndex = MatchIndex[request.Server].KV;
                if (commitIndex > CommitIndex.KV &&
                    Logs[commitIndex - 1].Term == CurrentTerm)
                {
                    CommitIndex.KV = commitIndex;
                    print "\n[Leader] {0} | term {1} | log {2} | Key {3} | Val {4}\n", this, CurrentTerm, sizeof(Logs), Logs[commitIndex - 1].Key, Logs[commitIndex - 1].Val;
                }

                VotesReceived = 0;
                // TODO: Should this be null?
                LastClientRequest = (Client=default(machine), Key=default(string), Val=default(string));

                send request.ReceiverEndpoint, Response;
            }
        }
        else
        {
            if (NextIndex[request.Server].KV > 0)
            {
                NextIndex[request.Server].KV = NextIndex[request.Server].KV - 1;
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

            //this.Logger.WriteLine("\n [Leader] " + this.ServerId + " | term " + this.CurrentTerm + " | log " + this.Logs.Count + " | append votes " + this.VotesReceived + " | append fail (next idx = " + this.NextIndex[request.Server] + ")\n");
            print "\n[Leader] {0} | term {1} | log {2} | append votes {3} | append fail (next idx = {4})\n", this, CurrentTerm, sizeof(Logs), VotesReceived, NextIndex[request.Server].KV;
            //TODO FIX THIS
            send request.Server, AppendEntriesRequest, (Term=CurrentTerm, LeaderId=this, PrevLogIndex=(KV=prevLogIndex, Cfg=prevCfgLogIndex), 
                PrevLogTerm=(KV=prevLogTerm, Cfg=prevCfgLogTerm), Entries = logsAppend, CfgEntries = cfgLogsAppend, LeaderCommit = CommitIndex, 
                ReceiverEndpoint=LastClientRequest.Client);

        }
        print "[Leader | AppendEntriesResponse] CommitIndex: {0}", CommitIndex.KV;
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
            print "\n [Server] {0} | term {1} | log {2} | Reject {3}", ServerId, CurrentTerm, sizeof(Logs), request.CandidateId;
            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=false);
        }
        else
        {
            print "\n [Server] {0} | term {1} | log {2} | Approve {3}", ServerId, CurrentTerm, sizeof(Logs), request.CandidateId;
            TickCounter = 0;

            VotedFor = request.CandidateId;
            LeaderId = default(machine);

            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=true);
        }
    }

    fun AppendEntries(request: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs,
            Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs, ReceiverEndpoint: machine))
    {
        var idx: int;
        var cfgLogIdx: int;

        if (request.Term < CurrentTerm)
        {
            // AppendEntries RPC #1
            print "\n[Server] {0} | term {1} | log {2} | append false (<term) \n", this, CurrentTerm, sizeof(Logs);
            send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=false, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
        }
        else
        {
            // AppendEntries RPC #2
            //TODO WHY NOT STRICT <?
            if (request.PrevLogIndex.KV > 0 && (sizeof(Logs) <= request.PrevLogIndex.KV ||
                request.PrevLogIndex.Cfg > 0 && (sizeof(ConfigLogs) <= request.PrevLogIndex.Cfg) ||
                Logs[request.PrevLogIndex.KV - 1].Term != request.PrevLogTerm.KV) ||
                ConfigLogs[request.PrevLogIndex.Cfg - 1].Term != request.PrevLogTerm.Cfg)
            {
                print "\n[Leader] {0} | term {1} | log {2} | append false (not in log)\n", this, CurrentTerm, sizeof(Logs); 
                send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=false, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
            }
            else
            {
                idx = 0;
                // print "We successfully begin appending.";
                // On AppendEntries RPC from current leader, reset ElectionTimer
                if (LeaderId == request.LeaderId) {
                    TickCounter = 0;
                }
                // AppendEntries RPC #3
                while (idx < sizeof(request.Entries) && 
                    (idx + request.PrevLogIndex.KV + 1) < sizeof(Logs)){
                    if (Logs[idx + request.PrevLogIndex.KV + 1] != request.Entries[idx]){
                        print "[Follower | AppendEntries] Conflict: Deleting from log entry {0} on", idx + request.PrevLogIndex.KV + 1;
                        DeleteFromLog(idx + request.PrevLogIndex.KV + 1, sizeof(Logs), true);
                        break;
                    }
                    idx = idx + 1;
                } 

                while (cfgLogIdx < sizeof(request.CfgEntries) &&
                    (cfgLogIdx + request.PrevLogIndex.Cfg + 1) < sizeof(ConfigLogs)){
                    if (ConfigLogs[cfgLogIdx + request.PrevLogIndex.Cfg + 1] != request.CfgEntries[cfgLogIdx]){
                        print "[Follower | AppendEntries] Conflict: Deleting from config log entry {0} on", cfgLogIdx + request.PrevLogIndex.Cfg + 1;
                        DeleteFromLog(cfgLogIdx + request.PrevLogIndex.Cfg + 1, sizeof(ConfigLogs), false);
                        break;
                    }
                    cfgLogIdx = cfgLogIdx + 1;
                }

                // print "Num of entries to add: {0}", sizeof(request.Entries);
                // AppendEntries RPC #4. Note we explicitly DO NOT reset idx.
                while (idx < sizeof(request.Entries)){
                    print "debugging idx {0}", idx;
                    Logs += (idx + request.PrevLogIndex.KV + 1, request.Entries[idx]);
                    idx = idx + 1;
                }

                while (cfgLogIdx < sizeof(request.CfgEntries)){
                    print "debugging idx {0}", cfgLogIdx;
                    ConfigLogs += (cfgLogIdx + request.PrevLogIndex.Cfg + 1, request.CfgEntries[cfgLogIdx]);
                    cfgLogIdx = cfgLogIdx + 1;
                }

                // AppendEntries RPC #5. Index of last new entry is sizeof(Logs) - 1
                if (request.LeaderCommit.KV > CommitIndex.KV &&
                    sizeof(Logs) <= request.LeaderCommit.KV &&
                    request.LeaderCommit.Cfg > CommitIndex.Cfg &&
                    sizeof(ConfigLogs) <= request.LeaderCommit.Cfg)
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
                send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=true, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
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
        print "LogIndex: {0}", logIndex;
        if (logIndex > 0)
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

