
// Election safety: at most one leader can be elected in a given term.
// Leader Append-Only: a leader can only append new entries to its logs (it can neither overwrite nor delete entries).
// Log Matching: if two logs contain an entry with the same index and term, then the logs are identical in all entries up through the given index.
// Leader Completeness: if a log entry is committed in a given term then it will be present in the logs of the leaders since this term
// State Machine Safety: if a server has applied a particular log entry to its state machine, then no other server may apply a different command for the same log.


spec SafetyMonitor observes M_LogAppend, M_NotifyLeaderElected, M_LeaderCommitted
{
	var CurrentTerm: int;
	var TermsWithLeader: map[int, bool];
	// Map from every Server to its Logs.
	var ServerLogs: map[machine, seq[Log]];
	// Map from a term to the latest committed Log for the term. IE, when leader commits, the latest committed log for the current term is updated.
	var CommittedLogs: map[int, seq[Log]];

	start state Init
	{
		entry
		{
			CurrentTerm = -1;
			TermsWithLeader = default(map[int, bool]);
			raise LocalEvent;
		}

		on LocalEvent goto Monitoring;
	}

	state Monitoring
	{
		on M_NotifyLeaderElected do (payload: (Term: int, Logs: seq[Log])) {
			ProcessLeaderElected(payload.Term, payload.Logs);
		}

		on M_LogAppend do (payload: (Server: machine, Logs: seq[Log])) {
			ProcessLogAppend(payload.Server, payload.Logs);
		}

		on M_LeaderCommitted do (payload: seq[Log]) {
			CommittedLogs[CurrentTerm] = payload;
		}


	}

	fun ProcessLeaderElected(Term: int, Logs: seq[Log])
    {
		var i: int;
		var j: int;
		var PrevCommitted: seq[Log];
		var terms: seq[int];
		// Terms should be increasing
		assert(Term > CurrentTerm);
		CurrentTerm = Term;
        if (CurrentTerm in TermsWithLeader){
        	print "Detected more than one leader in term {0}", CurrentTerm;
        }
        assert(!(CurrentTerm in TermsWithLeader));
        TermsWithLeader[CurrentTerm] = true;

		// The newly elected leader should have all previously committed log entries from previous terms.
		terms = keys(CommittedLogs);
		while (i < sizeof(terms)) {
			PrevCommitted = CommittedLogs[terms[i]];
			assert(sizeof(Logs) >= sizeof(PrevCommitted));
			while (j < sizeof(PrevCommitted)) {
				if (PrevCommitted[j] != Logs[j]) {
					print "Newly elected leader should have all previously committed log entries from previous terms.";
				}
				assert(PrevCommitted[j] == Logs[j]);
				j = j + 1;
			}
			i = i + 1;
		}
    }

	fun ProcessLogAppend(Server: machine, Logs: seq[Log]) {
		var i: int;
		var j: int;
		var sharedMinIndex: int;
		var Servers: seq[machine];
		if (!(Server in ServerLogs)) {
			ServerLogs[Server] = Logs;
		} else {
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
}