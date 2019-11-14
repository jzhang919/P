#pragma once
#ifndef P_EVENTS_H_
#define P_EVENTS_H_
#include "Prt.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    extern PRT_EVENTDECL P_EVENT_NotifyLeaderUpdate;
    extern PRT_EVENTDECL P_EVENT_Request;
    extern PRT_EVENTDECL P_EVENT_RedirectRequest;
    extern PRT_EVENTDECL P_EVENT_ShutDown;
    extern PRT_EVENTDECL P_EVENT_LocalEvent;
    extern PRT_EVENTDECL P_EVENT_CConfigureEvent;
    extern PRT_EVENTDECL P_EVENT_Response;
    extern PRT_EVENTDECL P_EVENT_NotifyLeaderElected;
    extern PRT_EVENTDECL P_EVENT_SConfigureEvent;
    extern PRT_EVENTDECL P_EVENT_VoteRequest;
    extern PRT_EVENTDECL P_EVENT_VoteResponse;
    extern PRT_EVENTDECL P_EVENT_AppendEntriesRequest;
    extern PRT_EVENTDECL P_EVENT_AppendEntriesResponse;
    extern PRT_EVENTDECL P_EVENT_BecomeFollower;
    extern PRT_EVENTDECL P_EVENT_BecomeCandidate;
    extern PRT_EVENTDECL P_EVENT_BecomeLeader;
    extern PRT_EVENTDECL P_EVENT_EConfigureEvent;
    extern PRT_EVENTDECL P_EVENT_EStartTimer;
    extern PRT_EVENTDECL P_EVENT_ECancelTimer;
    extern PRT_EVENTDECL P_EVENT_ETimeout;
    extern PRT_EVENTDECL P_EVENT_ETickEvent;
    extern PRT_EVENTDECL P_EVENT_PConfigureEvent;
    extern PRT_EVENTDECL P_EVENT_PStartTimer;
    extern PRT_EVENTDECL P_EVENT_PCancelTimer;
    extern PRT_EVENTDECL P_EVENT_PTimeout;
    extern PRT_EVENTDECL P_EVENT_PTickEvent;
    extern PRT_EVENTDECL P_EVENT_EMonitorInit;
    extern PRT_INTERFACEDECL P_I_Client;
    extern PRT_INTERFACEDECL P_I_ClusterManager;
    extern PRT_INTERFACEDECL P_I_Server;
    extern PRT_MACHINEDECL P_MACHINE_Client;
    extern PRT_MACHINEDECL P_MACHINE_ClusterManager;
    extern PRT_MACHINEDECL P_MACHINE_SafetyMonitor;
    extern PRT_MACHINEDECL P_MACHINE_Server;
    extern PRT_TYPE* P_TYPEDEF_Log;
    extern PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl;
    
#ifdef __cplusplus
}
#endif

#endif // P_EVENTS_H_
