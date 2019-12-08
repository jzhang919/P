event NotifyLeaderUpdate: (Leader: machine, Term: int);

event RedirectRequest: (Client: machine, Key: string, Val:string);
event ShutDown;
event MakeUnavailable;
event LocalEvent;
event CConfigureEvent: machine;
event Response;
event SConfigureEvent: (Servers: seq[machine], ClusterManager: machine);
event VoteRequest: (Term: int, CandidateId: machine, LastLogIndex: Idxs, LastLogTerm: Idxs2);
event VoteResponse: (Term: int, VoteGranted: bool);
event AppendEntriesRequest: (Term: int, LeaderId: machine, PrevLogIndex: Idxs, PrevLogTerm: Idxs2, Entries: seq[Log], CfgEntries: seq[Config], LeaderCommit: Idxs3, ReceiverEndpoint: machine);
event AppendEntriesResponse: (Term: int, Success: bool, KV: bool, Cfg:bool, Server: machine, ReceiverEndpoint: machine);
event BecomeFollower;
event BecomeCandidate;
event BecomeLeader;
event ConfigureWallclock: (Servers: seq[machine], ClusterManager: machine);
event TickEvent;
event CancelTimer;
event StartTimer;
event SentAllTicks;
event CheckLogsOnShutDown: seq[machine];
// Argument: Leader's configuration list of servers to update followers with.
event UpdateServers: seq[machine];
event UpdateServersResponse: bool;
event AddServerResponse: (Server: machine, ServerAdded: bool);
event RemoveServerResponse: (Server: machine, ServerRemoved: bool);
event EMonitorInit;


// External Events below (Client to ClusterManager)

// Argument: Client, address of server, Key, Val: String K/V entry to Raft Log.
event Request: (Client: machine, Key: string, Val:string);
// Argument: newServer, address of server to add to Leader's configuration
event AddServer: machine;
// Argument: oldServer, address of server to remove from Leader's configuration
event RemoveServer: machine; 


// Events specifically announced for the SafetyMonitor
event M_LogAppend: (Server: machine, Logs: seq[Log]); // Used to indicate to the Monitor that a Log is being appended.
event M_NotifyLeaderElected: (Term: int, Logs: seq[Log]);
event M_LeaderCommitted: seq[Log];

type Log = (Term: int, Key: string, Val: string);

type Idxs = (KV: int, Cfg: int); 
type Idxs2 = (KV: int, Cfg: int); 	
type Idxs3 = (KV: int, Cfg: int);

type Config = (Term: int, Servers: seq[machine]);