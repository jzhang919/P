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
    var CommitIndex: int;
    var LastApplied: int;
    var NextIndex: map[machine, int];
    var MatchIndex: map[machine, int];
    var VotesReceived: int;
    var LastClientRequest: (Client: machine, Command: int);

    var MaxTicks: int;  // Randomly set ceiling for tick count
    var TickCounter: int; // Ticks seen so far. Reset at certain points.

    start state Init
    {
        entry
        {
            CurrentTerm = 0;
            LeaderId = default(machine);
            VotedFor = default(machine);
            Logs = default(seq[Log]);
            CommitIndex = 0;
            LastApplied = 0;
            NextIndex = default(map[machine, int]);
            MatchIndex = default(map[machine, int]);
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

        on Request do (payload: (Client: machine, Command: int)) {
            if (LeaderId != null)
            {
                print "[Follower | Request] {0} sends request to Leader {1}", this, LeaderId;
                send LeaderId, Request, payload.Client, payload.Command;
            }
            else
            {
                print "[Follower | Request] {0} no Leader, redirect to ClusterManager.", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        on VoteRequest do (payload: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int)) {
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

        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: int, 
            PrevLogTerm: int, Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine)){
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
            print "\n [Candidate] {0} on Entry | Term {1} | Votes Received {2} | Log # entries: {3}\n", this, CurrentTerm, VotesReceived, sizeof(Logs); 

            BroadcastVoteRequests();
        }

        on Request do (payload: (Client: machine, Command: int)) {
            // this should be throwing an error?
            if (LeaderId != null)
            {
                print "[Candidate | Request] {0} sends request to Leader {1}", this, LeaderId;
                send LeaderId, Request, payload.Client, payload.Command;
            }
            else
            {
                print "[Candidate | Request] {0} no leader, redirect to ClusterManager", this;
                send ClusterManager, RedirectRequest, payload;
            }
        }
        
        on VoteRequest do (request: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int)){
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
                    print "\n [Leader] {0} | term {1} | election votes {2} | log {3}\n", this, CurrentTerm, VotesReceived, sizeof(Logs); 
                    VotesReceived = 0;
                    raise BecomeLeader;
                }
            }
        }
        // TODO: Confirm that commenting out AppendEntries below is correct
        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: int, PrevLogTerm: int,
         Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine)) {
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

        idx = 0;
        while (idx < sizeof(Servers)) {
           if (idx == ServerId) {
                idx = idx + 1;
                continue;
           }
            lastLogIndex = sizeof(Logs) - 1;
            lastLogTerm = GetLogTermForIndex(lastLogIndex);

            print "Sending VoteRequest from Server {0} to Server {1}", this, Servers[idx];
            send Servers[idx], VoteRequest, (Term=CurrentTerm, CandidateId=this, LastLogIndex=lastLogIndex, LastLogTerm=lastLogTerm);
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
            var logIndex: int;
            var logTerm: int;
            var idx: int;

            CommitIndex = 0;                                                                              

            announce EMonitorInit, (NotifyLeaderElected, CurrentTerm);
            //monitor<SafetyMonitor>(NotifyLeaderElected, CurrentTerm);
            send ClusterManager, NotifyLeaderUpdate, (Leader=this, Term=CurrentTerm);
            
            // Fixed Leader MaxTicks. Used for heartbeat
            MaxTicks = 5;
            logIndex = sizeof(Logs) - 1;
            logTerm = GetLogTermForIndex(logIndex);

            //this.NextIndex.Clear();
            //this.MatchIndex.Clear();
            NextIndex = default(map[machine, int]);
            MatchIndex = default(map[machine, int]);
            
            idx = 0;
            while (idx < sizeof(Servers))
            {
                if (idx == ServerId) {
                    idx = idx + 1;
                    continue;
                }
                
                NextIndex[Servers[idx]] = logIndex + 1;
                MatchIndex[Servers[idx]] = 0;
                idx = idx + 1;
            }
            // HeartbeatSendAsLeader();
        }

        on Request do (request: (Client: machine, Command: int)) {
            ProcessClientRequest(request);
        }
        on VoteRequest do (request: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int)) {
            VoteAsLeader(request);
        }
        on VoteResponse do (request: (Term: int, VoteGranted: bool)) {
            RespondVoteAsLeader(request);
        }
        on AppendEntriesRequest do (request: (Term: int, LeaderId: machine, PrevLogIndex: int, 
            PrevLogTerm: int, Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine)) {
            AppendEntriesAsLeader(request);
        }
        on AppendEntriesResponse do (request: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine)) {
            RespondAppendEntriesAsLeader(request);
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

    fun ProcessClientRequest(trigger: (Client: machine, Command: int))
    {
        var log: Log;
        print "[Leader | Request] Leader {0} processing Client {1}", this, trigger.Client;
        LastClientRequest = trigger;
        log = default(Log);
        log.Term = CurrentTerm;
        log.Command = LastClientRequest.Command;
        print "[Leader | Request] Log Term: {0}, Log Command: {1}, idx: {2}", log.Term, log.Command, sizeof(Logs);
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
        var sIdx: int;
        var logIdx: int;
        var server: machine;
        var sendLog: seq[Log];
        var prevLogIndex: int;
        var prevLogTerm: int;

        lastLogIndex = sizeof(Logs) - 1;
        print "\n[Leader | PCR | HeartbeatSendAsLeader] [Leader] {0} sends append requests | term {1} | lastLogIndex: {2}\n", this, CurrentTerm, lastLogIndex;

        while (sIdx < sizeof(Servers))
        {
            // print "On server {0}", sIdx;
            server = Servers[sIdx];
            if (sIdx == ServerId || lastLogIndex < NextIndex[server]){
                sIdx = sIdx + 1;
                continue;
            }
            sendLog = default(seq[Log]);
            logIdx = NextIndex[server];
            while(logIdx <= lastLogIndex){
                sendLog += (logIdx - NextIndex[server], Logs[logIdx]);
                logIdx = logIdx + 1;
            }
            print "[Leader | PCR | HeartbeatSendAsLeader] Next index: {0} | sendLog size: {1}", NextIndex[server], sizeof(sendLog);
            prevLogIndex = NextIndex[server] - 1;
            prevLogTerm = GetLogTermForIndex(prevLogIndex);
            send server, AppendEntriesRequest, (Term=CurrentTerm, LeaderId=this, PrevLogIndex=prevLogIndex,
                PrevLogTerm=prevLogTerm, Entries=sendLog, LeaderCommit=CommitIndex, ReceiverEndpoint=LastClientRequest.Client);
            sIdx = sIdx + 1;
        } 
    }

    fun VoteAsLeader(request: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int))
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

    fun AppendEntriesAsLeader(request: (Term: int, LeaderId: machine, PrevLogIndex: int, PrevLogTerm: int, Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine))
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
        var prevLogIndex: int;
        var prevLogTerm: int; 
        var idx: int;
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
            NextIndex[request.Server] = sizeof(Logs);
            MatchIndex[request.Server] = sizeof(Logs) - 1;
            print "[Leader | AppendEntriesResponse] Updated Indices: NextIndex: {0}, MatchIndex: {1}", NextIndex[request.Server], MatchIndex[request.Server];
            
            VotesReceived = VotesReceived + 1;
            print "[Leader | AppendEntriesResponse] VotesReceived: {0}", VotesReceived;
            if (request.ReceiverEndpoint == null){
                print "[Leader | AppendEntriesResponse] request.ReceiverEndpoint: null";    
                return;
            }        
            else if (VotesReceived > (sizeof(Servers)-1) / 2)
            {
                //this.Logger.WriteLine("\n [Leader] " + this.ServerId + " | term " + this.CurrentTerm +
                  //  " | append votes " + this.VotesReceived + " | append success\n");
                print "\n[Leader] {0} | term {1} | append votes {2} | append success\n", this, CurrentTerm, VotesReceived; 
                commitIndex = MatchIndex[request.Server];
                if (commitIndex > CommitIndex &&
                    Logs[commitIndex - 1].Term == CurrentTerm)
                {
                    CommitIndex = commitIndex;

                   // this.Logger.WriteLine("\n [Leader] " + this.ServerId + " | term " + this.CurrentTerm + " | log " + this.Logs.Count + " | command " + this.Logs[commitIndex - 1].Command + "\n");
                    print "\n[Leader] {0} | term {1} | log {2} | command {3}\n", this, CurrentTerm, sizeof(Logs), Logs[commitIndex - 1].Command; 

                }

                VotesReceived = 0;
                LastClientRequest = (Client=default(machine), Command=default(int));

                send request.ReceiverEndpoint, Response;
            }
        }
        else
        {
            if (NextIndex[request.Server] > 0)
            {
                NextIndex[request.Server] = NextIndex[request.Server] - 1;
            }

//            List<Log> logs = this.Logs.GetRange(this.NextIndex[request.Server] - 1, this.Logs.Count - (this.NextIndex[request.Server] - 1));
            logsAppend = default(seq[Log]);
            
            prevLogIndex = NextIndex[request.Server] - 1;
            prevLogTerm = GetLogTermForIndex(prevLogIndex);

            idx = NextIndex[request.Server];
            
            while (idx < sizeof(Logs)) {
                logsAppend += (idx - NextIndex[request.Server], Logs[idx]);
                idx = idx + 1;
            }

            //this.Logger.WriteLine("\n [Leader] " + this.ServerId + " | term " + this.CurrentTerm + " | log " + this.Logs.Count + " | append votes " + this.VotesReceived + " | append fail (next idx = " + this.NextIndex[request.Server] + ")\n");
            print "\n[Leader] {0} | term {1} | log {2} | append votes {3} | append fail (next idx = {4})\n", this, CurrentTerm, sizeof(Logs), VotesReceived, NextIndex[request.Server];
            send request.Server, AppendEntriesRequest, (Term=CurrentTerm, LeaderId=this, PrevLogIndex=prevLogIndex,
                PrevLogTerm=prevLogTerm, Entries=Logs, LeaderCommit=CommitIndex, ReceiverEndpoint=request.ReceiverEndpoint);
        }
        print "[Leader | AppendEntriesResponse] CommitIndex: {0}", CommitIndex;
    }

    fun Vote(request: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int))
    {
        var lastLogIndex: int;
        var lastLogTerm: int;
        lastLogIndex = sizeof(Logs) - 1;
        lastLogTerm = GetLogTermForIndex(lastLogIndex);

        if (request.Term < CurrentTerm ||
            (VotedFor != default(machine) && VotedFor != request.CandidateId) ||
            lastLogIndex > request.LastLogIndex ||
            lastLogTerm > request.LastLogTerm)
        {
            //this.Logger.WriteLine("\n [Server] " + this.ServerId + " | term " + this.CurrentTerm +
              //  " | log " + this.Logs.Count + " | vote false\n");
            print "\n [Server] {0} | term {1} | log {2} | Reject {3}", ServerId, CurrentTerm, sizeof(Logs), request.CandidateId;
            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=false);
        }
        else
        {
            //this.Logger.WriteLine("\n [Server] " + this.ServerId + " | term " + this.CurrentTerm +
               // " | log " + this.Logs.Count + " | vote true\n");
            print "\n [Server] {0} | term {1} | log {2} | Approve {3}", ServerId, CurrentTerm, sizeof(Logs), request.CandidateId;
            TickCounter = 0;

            VotedFor = request.CandidateId;
            LeaderId = default(machine);

            send request.CandidateId, VoteResponse, (Term=CurrentTerm, VoteGranted=true);
        }
    }

    fun AppendEntries(request: (Term: int, LeaderId: machine, PrevLogIndex: int, PrevLogTerm: int, Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine))
    {
        var startIndex: int;
        var idx: int;
        var decIdx: int;
        var logEntry: Log;

        if (request.Term < CurrentTerm)
        {
            // AppendEntries RPC #1
            print "\n[Server] {0} | term {1} | log {2} | last applied {3} | append false (<term) \n", this, CurrentTerm, sizeof(Logs), LastApplied;
            send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=false, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
        }
        else
        {
            // AppendEntries RPC #2
            if (request.PrevLogIndex > 0 &&
                (sizeof(Logs) < request.PrevLogIndex ||
                Logs[request.PrevLogIndex - 1].Term != request.PrevLogTerm))
            {
                print "\n[Leader] {0} | term {1} | log {2} | last applied: {3} | append false (not in log)\n", this, CurrentTerm, sizeof(Logs), LastApplied; 
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
                    (idx + request.PrevLogIndex + 1) < sizeof(Logs)){
                    if (Logs[idx + request.PrevLogIndex + 1] != request.Entries[idx]){
                        print "[Follower | AppendEntries] Conflict: Deleting from log entry {0} on", idx + request.PrevLogIndex + 1;
                        DeleteFromLog(idx + request.PrevLogIndex + 1, sizeof(Logs));
                        break;
                    }
                    idx = idx + 1;
                } 

                // print "Num of entries to add: {0}", sizeof(request.Entries);
                // AppendEntries RPC #4. Note we explicitly DO NOT reset idx.
                while (idx < sizeof(request.Entries)){
                    print "debugging idx {0}", idx;
                    Logs += (idx + request.PrevLogIndex + 1, request.Entries[idx]);
                    idx = idx + 1;
                }

                // AppendEntries RPC #5. Index of last new entry is sizeof(Logs) - 1
                if (request.LeaderCommit > CommitIndex &&
                    (sizeof(Logs) - 1) < request.LeaderCommit)
                {
                    CommitIndex = sizeof(Logs) - 1;
                }
                else if (request.LeaderCommit > CommitIndex)
                {
                    CommitIndex = request.LeaderCommit;
                }

                if (CommitIndex > LastApplied)
                {
                    LastApplied = LastApplied + sizeof(request.Entries);
                }

                print "\n[Server] {0} | term {1} | log {2} | entries received {3} | last applied {4} | append true\n", this, CurrentTerm, sizeof(Logs), sizeof(request.Entries), LastApplied; 

                LeaderId = request.LeaderId;
                send request.LeaderId, AppendEntriesResponse, (Term=CurrentTerm, Success=true, Server=this, ReceiverEndpoint=request.ReceiverEndpoint);
            }
        }
    }

    /* Delete entries from class variable Logs, a seq<.
        @param start: Inclusive, first index to delete.
        @param end: Exclusive, delete up to but not including this index.
    */
    fun DeleteFromLog(startIndex: int, endIndex: int)
    {
        var idx: int;
        idx = endIndex - 1;
        while (idx >= startIndex){
            Logs -= idx;
        }
    }



    fun RedirectLastClientRequestToClusterManager()
    {
        if (LastClientRequest != null)
        {
            send ClusterManager, Request, (Client=LastClientRequest.Client, Command=LastClientRequest.Command);
        }
    }

    fun GetLogTermForIndex(logIndex: int) : int
    {
        var logTerm: int;
        logTerm = 0;
        print "LogIndex: {0}", logIndex;
        if (logIndex > 0)
        {
            logTerm = Logs[logIndex].Term;
        }

        return logTerm;
    }

    fun ShuttingDown()
    {
        raise halt;
    }
}
// }

