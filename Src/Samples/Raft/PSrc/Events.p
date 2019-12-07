event NotifyLeaderUpdate: (Leader: machine, Term: int);
event Request: (Client: machine, Key: string, Val:string);
event RedirectRequest: (Client: machine, Key: string, Val:string);
event ShutDown;
event MakeUnavailable;
event LocalEvent;
event CConfigureEvent: machine;
event Response;
event NotifyLeaderElected: int;
event SConfigureEvent: (Id: int, Servers: seq[machine], ClusterManager: machine);
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

// Argument: newServer, address of server to add to Leader's configuration
event AddServer: machine;
event AddServerResponse: (Server: machine, ServerAdded: bool);

// Argument: oldServer, address of server to remove from Leader's configuration
event RemoveServer: machine; 
event RemoveServerResponse: (Server: machine, ServerRemoved: bool);

// Argument: Leader's configuration list of servers to update followers with.
event UpdateServers: seq[machine];
event UpdateServersResponse: bool;

event EMonitorInit;

type Log = (Term: int, Key: string, Val: string);

type Idxs = (KV: int, Cfg: int); 
type Idxs2 = (KV: int, Cfg: int); 	
type Idxs3 = (KV: int, Cfg: int);

type Config = (Term: int, Servers: seq[machine]);