// ------------------------------------------------------------------------------------------------
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------------------------------------------

// using System;
// using System.Collections.Generic;
// using System.Linq;
// using System.Text;
// using System.Threading.Tasks;

// namespace Raft
// {
// #region events

event NotifyLeaderUpdate: (Leader: machine, Term: int);
event Request: (Client: machine, Command: int);
event RedirectRequest: (Req: (Client: machine, Command: int));
event ShutDown;
event LocalEvent;
event CConfigureEvent: (Cluster: machine);
event Response;
event NotifyLeaderElected: (Term: int);
event SConfigureEvent: (Id: int, Servers: seq[machine], ClusterManager: machine);
event VoteRequest: (Term: int, CandidateId: machine, LastLogIndex: int, LastLogTerm: int);
event VoteResponse: (Term: int, VoteGranted: bool);
event AppendEntriesRequest: (Term: int, LeaderId: machine, PrevLogIndex: int, PrevLogTerm: int, Entries: seq[Log], LeaderCommit: int, ReceiverEndpoint: machine);
event AppendEntriesResponse: (Term: int, Success: bool, Server: machine, ReceiverEndpoint: machine);
event BecomeFollower;
event BecomeCandidate;
event BecomeLeader;
event EConfigureEvent: (Target: machine);
event EStartTimer;
event ECancelTimer;
event ETimeout;
event ETickEvent;
event PConfigureEvent: (Target: machine);
event PStartTimer;
event PCancelTimer;
event PTimeout;
event PTickEvent;

event EMonitorInit;

type Log = (Term: int, Command: int);
// #endregion
// }