
// Election safety: at most one leader can be elected in a given term.
// Leader Append-Only: a leader can only append new entries to its logs (it can neither overwrite nor delete entries).
// Log Matching: if two logs contain an entry with the same index and term, then the logs are identical in all entries up through the given index.
// Leader Completeness: if a log entry is committed in a given term then it will be present in the logs of the leaders since this term
// State Machine Safety: if a server has applied a particular log entry to its state machine, then no other server may apply a different command for the same log.


spec SafetyMonitor observes M_LogAppend, M_NotifyLeaderElected
{
	//unused: int CurrentTerm;
	var TermsWithLeader: map[int, bool];
	var ServerLogs: map[machine, seq[Log]]; // Map from every Server to its Logs.

	start state Init
	{
		entry
		{
			//this.CurrentTerm = -1;
			TermsWithLeader = default(map[int, bool]);
			raise LocalEvent;
		}

		on LocalEvent goto Monitoring;
	}

	state Monitoring
	{
		on M_NotifyLeaderElected do (payload: int) {
			ProcessLeaderElected(payload);
		}

		on M_LogAppend do (payload: (Server: machine, Logs: seq[Log])) {
			ProcessLogAppend(payload.Server, payload.Logs);
		}


	}

	fun ProcessLeaderElected(payload: int)
    {
        var term: int;
        term = payload;
        if (term in TermsWithLeader){
        	print "Detected more than one leader in term {0}", term;
        }
        assert(!(term in TermsWithLeader));
        TermsWithLeader[term] = true;
    }

	fun ProcessLogAppend(Server: machine, Logs: seq[Log]) {
		var i: int;
		var j: int;
		var sharedMinIndex: int;
		var Servers: seq[machine];
		print "processLogAppend";
		if (!(Server in ServerLogs)) {
			ServerLogs[Server] = Logs;
		} else {
			print "eliot 2";
			i = 0;
			ServerLogs[Server] = Logs;
			Servers = keys(ServerLogs);
			while (i < sizeof(Servers)) {
				j = 0;
				if (Servers[i] == Server) {
					i = i + 1;
					continue;
				}
				sharedMinIndex = getSharedMinIndex(ServerLogs[Servers[i]], Logs);
				//Log Matching property
				if (sharedMinIndex >= 0) {
					while (j <= sharedMinIndex) {
						assert(ServerLogs[Servers[i]][j] == Logs[j]);
						j = j + 1;
					}
				}
			

				i = i + 1;
			}
		}
	}

	fun getSharedMinIndex(Logs1: seq[Log], Logs2: seq[Log]) : int{
		var idx: int;
		if (sizeof(Logs1) > sizeof(Logs2)) {
			idx = sizeof(Logs2) - 1;
		} else {
			idx = sizeof(Logs1) - 1;
		}
		// Go backward from idx until you find the sharedMinIndex, the index for the entry in both logs that have the same term
		while (idx >= 0) {
			if (Logs1[idx].Term == Logs2[idx].Term) {
				return idx;
			}
			idx = idx - 1;
		}
		return idx;
	}

	// fun CheckFinalLogs(payload: seq[machine]) {
	// 	var idx: int;
	// 	var logs: seq[Log];
	// 	idx = 0;
	// 	while (idx < sizeof(payload)) {

	// 		idx = idx + 1;
	// 	}
	// }
}