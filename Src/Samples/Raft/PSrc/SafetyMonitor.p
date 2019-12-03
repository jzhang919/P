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
spec SafetyMonitor observes NotifyLeaderElected // CheckLogsOnShutDown
{
	//unused: int CurrentTerm;
//    HashSet<int> TermsWithLeader;
	var TermsWithLeader: map[int, bool];

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
		on NotifyLeaderElected do (payload: int) {
			ProcessLeaderElected(payload);
		}

		// on CheckLogsOnShutDown do (payload: seq[machine]) {
		// 	CheckFinalLogs(payload);
		// }
	}

	fun ProcessLeaderElected(payload: int)
    {
        var term: int;
        term = payload;
        if (TermsWithLeader[term]){
        	print "Detected more than one leader in term {0}", term;
        }
        assert(!TermsWithLeader[term]);
        TermsWithLeader[term] = true;
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
// }
