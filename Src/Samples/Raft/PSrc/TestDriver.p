/* This file implements various test-drivers and also provides the various test-cases that are model-checked by the P Checker*/


/*
This machine creates the 2 participants, 1 coordinator, and 2 clients 
*/
machine TestDriver0 {
	start state Init {
		entry {
			var clusterManager : machine;
			var client : machine;
			clusterManager = new ClusterManager();
			new Client(clusterManager);
		}
	}
}


// checks that alll events are handled correctly and also the local assertions in the P machines.
test Test0[main = TestDriver0]: { TestDriver0, ClusterManager, Client };
