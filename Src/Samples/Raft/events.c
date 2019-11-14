#include "events.h"

// Type universe for program:
static PRT_STRING P_NMDTUP_N[] = { "Leader", "Term" };
static PRT_TYPE P_GEND_TYPE_m = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE P_GEND_TYPE_i = { PRT_KIND_INT, { NULL } };
static PRT_TYPE* P_NMDTUP_T[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP = { 2U, P_NMDTUP_N, P_NMDTUP_T };
static PRT_TYPE P_GEND_TYPE_T2mi = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP } };
static PRT_STRING P_NMDTUP_N_1[] = { "Client", "Command" };
static PRT_TYPE* P_NMDTUP_T_1[] = { &P_GEND_TYPE_m, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_1 = { 2U, P_NMDTUP_N_1, P_NMDTUP_T_1 };
static PRT_TYPE P_GEND_TYPE_T2mi_1 = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_1 } };
static PRT_TYPE P_GEND_TYPE_n = { PRT_KIND_NULL, { NULL } };
static PRT_STRING P_NMDTUP_N_2[] = { "Id", "Servers", "ClusterManager" };
static PRT_SEQTYPE P_SEQTYPE = { &P_GEND_TYPE_m };
static PRT_TYPE P_GEND_TYPE_Sm = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE } };
static PRT_TYPE* P_NMDTUP_T_2[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_Sm, &P_GEND_TYPE_m };
static PRT_NMDTUPTYPE P_NMDTUP_2 = { 3U, P_NMDTUP_N_2, P_NMDTUP_T_2 };
static PRT_TYPE P_GEND_TYPE_T3iSmm = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_2 } };
static PRT_STRING P_NMDTUP_N_3[] = { "Term", "CandidateId", "LastLogIndex", "LastLogTerm" };
static PRT_TYPE* P_NMDTUP_T_3[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_m, &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_3 = { 4U, P_NMDTUP_N_3, P_NMDTUP_T_3 };
static PRT_TYPE P_GEND_TYPE_T4imii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_3 } };
static PRT_STRING P_NMDTUP_N_4[] = { "Term", "VoteGranted" };
static PRT_TYPE P_GEND_TYPE_b = { PRT_KIND_BOOL, { NULL } };
static PRT_TYPE* P_NMDTUP_T_4[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_b };
static PRT_NMDTUPTYPE P_NMDTUP_4 = { 2U, P_NMDTUP_N_4, P_NMDTUP_T_4 };
static PRT_TYPE P_GEND_TYPE_T2ib = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_4 } };
static PRT_STRING P_NMDTUP_N_5[] = { "Term", "LeaderId", "PrevLogIndex", "PrevLogTerm", "Entries", "LeaderCommit", "ReceiverEndpoint" };
static PRT_STRING P_NMDTUP_N_6[] = { "Term", "Command" };
static PRT_TYPE* P_NMDTUP_T_6[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_6 = { 2U, P_NMDTUP_N_6, P_NMDTUP_T_6 };
static PRT_TYPE P_GEND_TYPE_T2ii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_6 } };
static PRT_SEQTYPE P_SEQTYPE_1 = { &P_GEND_TYPE_T2ii };
static PRT_TYPE P_GEND_TYPE_ST2ii = { PRT_KIND_SEQ, { .seq = &P_SEQTYPE_1 } };
static PRT_TYPE* P_NMDTUP_T_5[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_m, &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_ST2ii, &P_GEND_TYPE_i, &P_GEND_TYPE_m };
static PRT_NMDTUPTYPE P_NMDTUP_5 = { 7U, P_NMDTUP_N_5, P_NMDTUP_T_5 };
static PRT_TYPE P_GEND_TYPE_T7imiiST2iiim = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_5 } };
static PRT_STRING P_NMDTUP_N_7[] = { "Term", "Success", "Server", "ReceiverEndpoint" };
static PRT_TYPE* P_NMDTUP_T_7[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_b, &P_GEND_TYPE_m, &P_GEND_TYPE_m };
static PRT_NMDTUPTYPE P_NMDTUP_7 = { 4U, P_NMDTUP_N_7, P_NMDTUP_T_7 };
static PRT_TYPE P_GEND_TYPE_T4ibmm = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_7 } };
static PRT_STRING P_NMDTUP_N_8[] = { "Client", "Command" };
static PRT_TYPE P_GEND_TYPE_R = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_8[] = { &P_GEND_TYPE_R, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_8 = { 2U, P_NMDTUP_N_8, P_NMDTUP_T_8 };
static PRT_TYPE P_GEND_TYPE_T2Ri = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_8 } };
static PRT_STRING P_NMDTUP_N_9[] = { "Id", "Servers", "ClusterManager" };
static PRT_TYPE P_GEND_TYPE_R_1 = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_9[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_Sm, &P_GEND_TYPE_R_1 };
static PRT_NMDTUPTYPE P_NMDTUP_9 = { 3U, P_NMDTUP_N_9, P_NMDTUP_T_9 };
static PRT_TYPE P_GEND_TYPE_T3iSmR = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_9 } };
static PRT_MAPTYPE P_MAPTYPE = { &P_GEND_TYPE_i, &P_GEND_TYPE_b };
static PRT_TYPE P_GEND_TYPE_MKiVb = { PRT_KIND_MAP, { .map = &P_MAPTYPE } };
static PRT_MAPTYPE P_MAPTYPE_1 = { &P_GEND_TYPE_m, &P_GEND_TYPE_i };
static PRT_TYPE P_GEND_TYPE_MKmVi = { PRT_KIND_MAP, { .map = &P_MAPTYPE_1 } };
static PRT_STRING P_NMDTUP_N_10[] = { "Term", "CandidateId", "LastLogIndex", "LastLogTerm" };
static PRT_TYPE P_GEND_TYPE_R_2 = { PRT_KIND_MACHINE, { NULL } };
static PRT_TYPE* P_NMDTUP_T_10[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_R_2, &P_GEND_TYPE_i, &P_GEND_TYPE_i };
static PRT_NMDTUPTYPE P_NMDTUP_10 = { 4U, P_NMDTUP_N_10, P_NMDTUP_T_10 };
static PRT_TYPE P_GEND_TYPE_T4iRii = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_10 } };
static PRT_TYPE P_GEND_TYPE_e = { PRT_KIND_EVENT, { NULL } };
static PRT_TYPE* P_TUP_T[] = { &P_GEND_TYPE_e, &P_GEND_TYPE_i };
static PRT_TUPTYPE P_TUP = { 2U, P_TUP_T };
static PRT_TYPE P_GEND_TYPE_T2ei = { PRT_KIND_TUPLE, { .tuple = &P_TUP } };
static PRT_STRING P_NMDTUP_N_11[] = { "Term", "LeaderId", "PrevLogIndex", "PrevLogTerm", "Entries", "LeaderCommit", "ReceiverEndpoint" };
static PRT_TYPE* P_NMDTUP_T_11[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_R_2, &P_GEND_TYPE_i, &P_GEND_TYPE_i, &P_GEND_TYPE_ST2ii, &P_GEND_TYPE_i, &P_GEND_TYPE_m };
static PRT_NMDTUPTYPE P_NMDTUP_11 = { 7U, P_NMDTUP_N_11, P_NMDTUP_T_11 };
static PRT_TYPE P_GEND_TYPE_T7iRiiST2iiim = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_11 } };
static PRT_STRING P_NMDTUP_N_12[] = { "Term", "Success", "Server", "ReceiverEndpoint" };
static PRT_TYPE* P_NMDTUP_T_12[] = { &P_GEND_TYPE_i, &P_GEND_TYPE_b, &P_GEND_TYPE_R_2, &P_GEND_TYPE_m };
static PRT_NMDTUPTYPE P_NMDTUP_12 = { 4U, P_NMDTUP_N_12, P_NMDTUP_T_12 };
static PRT_TYPE P_GEND_TYPE_T4ibRm = { PRT_KIND_NMDTUP, { .nmTuple = &P_NMDTUP_12 } };

// Function implementation prototypes:
PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon;

PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_1;

PRT_VALUE* P_Configure_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Configure;

PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_2;

PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_3;

PRT_VALUE* P_ChooseVal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ChooseVal;

PRT_VALUE* P_ProcessResponse_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ProcessResponse;

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_4;

PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_5;

PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_6;

PRT_VALUE* P_UpdateLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_UpdateLeader;

PRT_VALUE* P_ShuttingDown_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ShuttingDown;

PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_7;

PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_8;

PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_9;

PRT_VALUE* P_BecomeUnavailable_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_BecomeUnavailable;

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_10;

PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_11;

PRT_VALUE* P_ProcessLeaderElected_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ProcessLeaderElected;

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_12;

PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_13;

PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_14;

PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_15;

PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_16;

PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_17;

PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_18;

PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_19;

PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_20;

PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_21;

PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_22;

PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_23;

PRT_VALUE* P_Anon_IMPL_24(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_24;

PRT_VALUE* P_Anon_IMPL_25(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_25;

PRT_VALUE* P_Anon_IMPL_26(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_26;

PRT_VALUE* P_Anon_IMPL_27(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_27;

PRT_VALUE* P_Anon_IMPL_28(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_28;

PRT_VALUE* P_BroadcastVoteRequests_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_BroadcastVoteRequests;

PRT_VALUE* P_RespondAppendEntriesAsCandidate_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RespondAppendEntriesAsCandidate;

PRT_VALUE* P_Anon_IMPL_29(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_29;

PRT_VALUE* P_Anon_IMPL_30(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_30;

PRT_VALUE* P_Anon_IMPL_31(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_31;

PRT_VALUE* P_Anon_IMPL_32(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_32;

PRT_VALUE* P_Anon_IMPL_33(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_33;

PRT_VALUE* P_Anon_IMPL_34(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Anon_34;

PRT_VALUE* P_ProcessClientRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ProcessClientRequest;

PRT_VALUE* P_BroadcastLastClientRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_BroadcastLastClientRequest;

PRT_VALUE* P_VoteAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_VoteAsLeader;

PRT_VALUE* P_RespondVoteAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RespondVoteAsLeader;

PRT_VALUE* P_AppendEntriesAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AppendEntriesAsLeader;

PRT_VALUE* P_RespondAppendEntriesAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RespondAppendEntriesAsLeader;

PRT_VALUE* P_Vote_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_Vote;

PRT_VALUE* P_AppendEntries_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_AppendEntries;

PRT_VALUE* P_RedirectLastClientRequestToClusterManager_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_RedirectLastClientRequestToClusterManager;

PRT_VALUE* P_GetLogTermForIndex_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_GetLogTermForIndex;

PRT_VALUE* P_ShuttingDown_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs);
extern PRT_FUNDECL P_FUNCTION_ShuttingDown_1;


PRT_EVENTDECL P_EVENT_NotifyLeaderUpdate = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "NotifyLeaderUpdate",
    4294967295U,
    &P_GEND_TYPE_T2mi
};

PRT_EVENTDECL P_EVENT_Request = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Request",
    4294967295U,
    &P_GEND_TYPE_T2mi_1
};

PRT_EVENTDECL P_EVENT_RedirectRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "RedirectRequest",
    4294967295U,
    &P_GEND_TYPE_T2mi_1
};

PRT_EVENTDECL P_EVENT_ShutDown = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "ShutDown",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_LocalEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "LocalEvent",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_CConfigureEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "CConfigureEvent",
    4294967295U,
    &P_GEND_TYPE_m
};

PRT_EVENTDECL P_EVENT_Response = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "Response",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_NotifyLeaderElected = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "NotifyLeaderElected",
    4294967295U,
    &P_GEND_TYPE_i
};

PRT_EVENTDECL P_EVENT_SConfigureEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "SConfigureEvent",
    4294967295U,
    &P_GEND_TYPE_T3iSmm
};

PRT_EVENTDECL P_EVENT_VoteRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "VoteRequest",
    4294967295U,
    &P_GEND_TYPE_T4imii
};

PRT_EVENTDECL P_EVENT_VoteResponse = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "VoteResponse",
    4294967295U,
    &P_GEND_TYPE_T2ib
};

PRT_EVENTDECL P_EVENT_AppendEntriesRequest = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AppendEntriesRequest",
    4294967295U,
    &P_GEND_TYPE_T7imiiST2iiim
};

PRT_EVENTDECL P_EVENT_AppendEntriesResponse = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "AppendEntriesResponse",
    4294967295U,
    &P_GEND_TYPE_T4ibmm
};

PRT_EVENTDECL P_EVENT_BecomeFollower = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "BecomeFollower",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_BecomeCandidate = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "BecomeCandidate",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_BecomeLeader = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "BecomeLeader",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_EConfigureEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "EConfigureEvent",
    4294967295U,
    &P_GEND_TYPE_m
};

PRT_EVENTDECL P_EVENT_EStartTimer = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "EStartTimer",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_ECancelTimer = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "ECancelTimer",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_ETimeout = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "ETimeout",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_ETickEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "ETickEvent",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_PConfigureEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PConfigureEvent",
    4294967295U,
    &P_GEND_TYPE_m
};

PRT_EVENTDECL P_EVENT_PStartTimer = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PStartTimer",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_PCancelTimer = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PCancelTimer",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_PTimeout = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PTimeout",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_PTickEvent = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "PTickEvent",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL P_EVENT_EMonitorInit = 
{
    { PRT_VALUE_KIND_EVENT, 0U },
    "EMonitorInit",
    4294967295U,
    &P_GEND_TYPE_n
};

PRT_EVENTDECL* P_Client_RECV_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Client_RECV =
{
    28U,
    P_Client_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Client =
{
    0U,
    "Client",
    &P_GEND_TYPE_m,
    &P_EVENTSET_Client_RECV
};

PRT_EVENTDECL* P_ClusterManager_RECV_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClusterManager_RECV =
{
    28U,
    P_ClusterManager_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_ClusterManager =
{
    1U,
    "ClusterManager",
    &P_GEND_TYPE_n,
    &P_EVENTSET_ClusterManager_RECV
};

PRT_EVENTDECL* P_Server_RECV_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Server_RECV =
{
    28U,
    P_Server_RECV_INNER,
    NULL
};

PRT_INTERFACEDECL P_I_Server =
{
    2U,
    "Server",
    &P_GEND_TYPE_n,
    &P_EVENTSET_Server_RECV
};

PRT_VARDECL P_Client_VARS[] = {
    { "Cluster", &P_GEND_TYPE_m },
    { "LatestCommand", &P_GEND_TYPE_i },
    { "Counter", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS =
{
    0U,
    P_Init_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS =
{
    1U,
    P_Init_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER[] = { &P_EVENT_CConfigureEvent };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS =
{
    1U,
    P_Init_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS[] =
{
    { 0, &P_EVENT_LocalEvent, 1, &_P_NO_OP }
};

PRT_DODECL P_DOS[] =
{
    { 0, &P_EVENT_CConfigureEvent, &P_FUNCTION_Anon_1 }
};

#define P_STATE_Client_Init \
{ \
    "Client.Init", \
    1U, \
    1U, \
    &P_EVENTSET_Init_DEFERS, \
    &P_EVENTSET_Init_TRANS, \
    &P_EVENTSET_Init_DOS, \
    P_TRANS, \
    P_DOS, \
    &P_FUNCTION_Anon, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_PumpRequest_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_PumpRequest_DEFERS =
{
    0U,
    P_PumpRequest_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_PumpRequest_TRANS_INNER[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_PumpRequest_TRANS =
{
    1U,
    P_PumpRequest_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_PumpRequest_DOS_INNER[] = { &P_EVENT_Response };
PRT_EVENTSETDECL P_EVENTSET_PumpRequest_DOS =
{
    1U,
    P_PumpRequest_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_1[] =
{
    { 1, &P_EVENT_LocalEvent, 1, &_P_NO_OP }
};

PRT_DODECL P_DOS_1[] =
{
    { 1, &P_EVENT_Response, &P_FUNCTION_Anon_3 }
};

#define P_STATE_Client_PumpRequest \
{ \
    "Client.PumpRequest", \
    1U, \
    1U, \
    &P_EVENTSET_PumpRequest_DEFERS, \
    &P_EVENTSET_PumpRequest_TRANS, \
    &P_EVENTSET_PumpRequest_DOS, \
    P_TRANS_1, \
    P_DOS_1, \
    &P_FUNCTION_Anon_2, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Client_STATES[] = { P_STATE_Client_Init, P_STATE_Client_PumpRequest };

PRT_VALUE* P_Anon_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload = argRefs[0];
    PRT_VALUE* PTMP_tmp0 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_1 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE = &(PTMP_tmp0);
    PrtFreeValue(*P_LVALUE);
    *P_LVALUE = PrtMkIntValue(-PrtPrimGetInt((&P_LIT_INT32)));
    
    {
        PRT_VALUE** P_LVALUE_1 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_1);
        *P_LVALUE_1 = PTMP_tmp0;
        PTMP_tmp0 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_2 = &(p_this->varValues[2]);
    PrtFreeValue(*P_LVALUE_2);
    *P_LVALUE_2 = PrtCloneValue((&P_LIT_INT32_1));
    
p_return: ;
    PrtFreeValue(PTMP_tmp0); PTMP_tmp0 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon =
{
    NULL,
    &P_Anon_IMPL,
    &P_GEND_TYPE_m
};


PRT_VALUE* P_Anon_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_3 = &(PTMP_tmp0_1);
    PrtFreeValue(*P_LVALUE_3);
    *P_LVALUE_3 = PrtCloneValue(*P_VAR_payload_1);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_1);
    PrtFreeValue(P_Configure_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_1);
    PTMP_tmp0_1 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_1;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_1;
    }
    
p_return_1: ;
    PrtFreeValue(PTMP_tmp0_1); PTMP_tmp0_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_1 =
{
    NULL,
    &P_Anon_IMPL_1,
    &P_GEND_TYPE_m
};


PRT_VALUE* P_Configure_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_2 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_4 = &(p_this->varValues[0]);
    PrtFreeValue(*P_LVALUE_4);
    *P_LVALUE_4 = PrtCloneValue(*P_VAR_payload_2);
    
    PRT_VALUE** P_LVALUE_5 = &(PTMP_tmp0_2);
    PrtFreeValue(*P_LVALUE_5);
    *P_LVALUE_5 = PrtCloneValue((&P_EVENT_LocalEvent.value));
    
    PrtRaise(p_this, PTMP_tmp0_2, 0);
    *(&(PTMP_tmp0_2)) = NULL;
    goto p_return_2;
    
p_return_2: ;
    PrtFreeValue(PTMP_tmp0_2); PTMP_tmp0_2 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Configure =
{
    "Configure",
    &P_Configure_IMPL,
    NULL
};


PRT_VALUE* P_Anon_IMPL_2(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_3 = NULL;
    PRT_VALUE* PTMP_tmp1 = NULL;
    PRT_VALUE* PTMP_tmp2 = NULL;
    PRT_VALUE* PTMP_tmp3 = NULL;
    PRT_VALUE* PTMP_tmp4 = NULL;
    PRT_VALUE* PTMP_tmp5 = NULL;
    PRT_VALUE* PTMP_tmp6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_2 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_6 = &(PTMP_tmp0_3);
    PrtFreeValue(*P_LVALUE_6);
    *P_LVALUE_6 = ((_P_GEN_funval = P_ChooseVal_IMPL(context, _P_GEN_funargs)), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
    {
        PRT_VALUE** P_LVALUE_7 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_7);
        *P_LVALUE_7 = PTMP_tmp0_3;
        PTMP_tmp0_3 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_8 = &(PTMP_tmp1);
    PrtFreeValue(*P_LVALUE_8);
    *P_LVALUE_8 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[2]) + PrtPrimGetInt((&P_LIT_INT32_2)));
    
    {
        PRT_VALUE** P_LVALUE_9 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_9);
        *P_LVALUE_9 = PTMP_tmp1;
        PTMP_tmp1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_10 = &(PTMP_tmp2);
    PrtFreeValue(*P_LVALUE_10);
    *P_LVALUE_10 = PrtCloneValue(p_this->varValues[0]);
    
    PRT_VALUE** P_LVALUE_11 = &(PTMP_tmp3);
    PrtFreeValue(*P_LVALUE_11);
    *P_LVALUE_11 = PrtCloneValue((&P_EVENT_Request.value));
    
    PRT_VALUE** P_LVALUE_12 = &(PTMP_tmp4);
    PrtFreeValue(*P_LVALUE_12);
    *P_LVALUE_12 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_13 = &(PTMP_tmp5);
    PrtFreeValue(*P_LVALUE_13);
    *P_LVALUE_13 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_14 = &(PTMP_tmp6);
    PrtFreeValue(*P_LVALUE_14);
    *P_LVALUE_14 = (PrtMkTuple(&P_GEND_TYPE_T2Ri, &(PTMP_tmp4), &(PTMP_tmp5)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp2), PTMP_tmp3, 1, &(PTMP_tmp6));
    *(&(PTMP_tmp3)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_3;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_3;
    }
    
p_return_3: ;
    PrtFreeValue(PTMP_tmp0_3); PTMP_tmp0_3 = NULL;
    PrtFreeValue(PTMP_tmp1); PTMP_tmp1 = NULL;
    PrtFreeValue(PTMP_tmp2); PTMP_tmp2 = NULL;
    PrtFreeValue(PTMP_tmp3); PTMP_tmp3 = NULL;
    PrtFreeValue(PTMP_tmp4); PTMP_tmp4 = NULL;
    PrtFreeValue(PTMP_tmp5); PTMP_tmp5 = NULL;
    PrtFreeValue(PTMP_tmp6); PTMP_tmp6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_2 =
{
    NULL,
    &P_Anon_IMPL_2,
    NULL
};


PRT_VALUE* P_Anon_IMPL_3(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtFreeValue(P_ProcessResponse_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_4;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_4;
    }
    
p_return_4: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_3 =
{
    NULL,
    &P_Anon_IMPL_3,
    NULL
};


PRT_VALUE* P_ChooseVal_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_index = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_4 = NULL;
    PRT_VALUE* PTMP_tmp1_1 = NULL;
    PRT_VALUE* PTMP_tmp2_1 = NULL;
    PRT_VALUE* PTMP_tmp3_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_3 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_4 = { PRT_VALUE_KIND_INT, { .nt = 100 } };
    PRT_VALUE P_LIT_INT32_5 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_15 = &(P_VAR_index);
    PrtFreeValue(*P_LVALUE_15);
    *P_LVALUE_15 = PrtCloneValue((&P_LIT_INT32_3));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN)))
    {
        PRT_VALUE** P_LVALUE_16 = &(PTMP_tmp0_4);
        PrtFreeValue(*P_LVALUE_16);
        *P_LVALUE_16 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_index) < PrtPrimGetInt((&P_LIT_INT32_4)));
        
        PRT_VALUE** P_LVALUE_17 = &(PTMP_tmp1_1);
        PrtFreeValue(*P_LVALUE_17);
        *P_LVALUE_17 = PrtCloneValue(PTMP_tmp0_4);
        
        if (PrtPrimGetBool(PTMP_tmp1_1))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_18 = &(PTMP_tmp2_1);
        PrtFreeValue(*P_LVALUE_18);
        *P_LVALUE_18 = (PrtMkNondetBoolValue());
        
        if (PrtPrimGetBool(PTMP_tmp2_1))
        {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = PrtCloneValue(P_VAR_index);
            goto p_return_5;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_19 = &(PTMP_tmp3_1);
        PrtFreeValue(*P_LVALUE_19);
        *P_LVALUE_19 = PrtMkIntValue(PrtPrimGetInt(P_VAR_index) + PrtPrimGetInt((&P_LIT_INT32_5)));
        
        {
            PRT_VALUE** P_LVALUE_20 = &(P_VAR_index);
            PrtFreeValue(*P_LVALUE_20);
            *P_LVALUE_20 = PTMP_tmp3_1;
            PTMP_tmp3_1 = NULL;
        }
        
    }
    
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_index);
    goto p_return_5;
    
p_return_5: ;
    PrtFreeValue(P_VAR_index); P_VAR_index = NULL;
    PrtFreeValue(PTMP_tmp0_4); PTMP_tmp0_4 = NULL;
    PrtFreeValue(PTMP_tmp1_1); PTMP_tmp1_1 = NULL;
    PrtFreeValue(PTMP_tmp2_1); PTMP_tmp2_1 = NULL;
    PrtFreeValue(PTMP_tmp3_1); PTMP_tmp3_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ChooseVal =
{
    "ChooseVal",
    &P_ChooseVal_IMPL,
    NULL
};


PRT_VALUE* P_ProcessResponse_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_5 = NULL;
    PRT_VALUE* PTMP_tmp1_2 = NULL;
    PRT_VALUE* PTMP_tmp2_2 = NULL;
    PRT_VALUE* PTMP_tmp3_2 = NULL;
    PRT_VALUE* PTMP_tmp4_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_6 = { PRT_VALUE_KIND_INT, { .nt = 3 } };
    PRT_VALUE** P_LVALUE_21 = &(PTMP_tmp0_5);
    PrtFreeValue(*P_LVALUE_21);
    *P_LVALUE_21 = PrtMkBoolValue(PrtIsEqualValue(p_this->varValues[2], (&P_LIT_INT32_6)));
    
    if (PrtPrimGetBool(PTMP_tmp0_5))
    {
        PRT_VALUE** P_LVALUE_22 = &(PTMP_tmp1_2);
        PrtFreeValue(*P_LVALUE_22);
        *P_LVALUE_22 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_23 = &(PTMP_tmp2_2);
        PrtFreeValue(*P_LVALUE_23);
        *P_LVALUE_23 = PrtCloneValue((&P_EVENT_ShutDown.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_2), PTMP_tmp2_2, 0);
        *(&(PTMP_tmp2_2)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_6;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_6;
        }
        
        PRT_VALUE** P_LVALUE_24 = &(PTMP_tmp3_2);
        PrtFreeValue(*P_LVALUE_24);
        *P_LVALUE_24 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
        
        PrtRaise(p_this, PTMP_tmp3_2, 0);
        *(&(PTMP_tmp3_2)) = NULL;
        goto p_return_6;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_25 = &(PTMP_tmp4_1);
        PrtFreeValue(*P_LVALUE_25);
        *P_LVALUE_25 = PrtCloneValue((&P_EVENT_LocalEvent.value));
        
        PrtRaise(p_this, PTMP_tmp4_1, 0);
        *(&(PTMP_tmp4_1)) = NULL;
        goto p_return_6;
        
    }
    
    
p_return_6: ;
    PrtFreeValue(PTMP_tmp0_5); PTMP_tmp0_5 = NULL;
    PrtFreeValue(PTMP_tmp1_2); PTMP_tmp1_2 = NULL;
    PrtFreeValue(PTMP_tmp2_2); PTMP_tmp2_2 = NULL;
    PrtFreeValue(PTMP_tmp3_2); PTMP_tmp3_2 = NULL;
    PrtFreeValue(PTMP_tmp4_1); PTMP_tmp4_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ProcessResponse =
{
    "ProcessResponse",
    &P_ProcessResponse_IMPL,
    NULL
};


PRT_FUNDECL* P_Client_METHODS[] = { &P_FUNCTION_Anon, &P_FUNCTION_Anon_1, &P_FUNCTION_Configure, &P_FUNCTION_Anon_2, &P_FUNCTION_Anon_3, &P_FUNCTION_ChooseVal, &P_FUNCTION_ProcessResponse };

PRT_EVENTDECL* P_Client_RECV_INNER_1[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Client_RECV_1 =
{
    28U,
    P_Client_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Client_SEND_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Client_SEND =
{
    28U,
    P_Client_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Client = 
{
    0U,
    "Client",
    &P_EVENTSET_Client_RECV_1,
    &P_EVENTSET_Client_SEND,
    NULL,
    3U,
    2U,
    7U,
    4294967295U,
    0U,
    P_Client_VARS,
    P_Client_STATES,
    P_Client_METHODS
};

PRT_VARDECL P_ClusterManager_VARS[] = {
    { "Servers", &P_GEND_TYPE_Sm },
    { "NumberOfServers", &P_GEND_TYPE_i },
    { "Leader", &P_GEND_TYPE_m },
    { "LeaderTerm", &P_GEND_TYPE_i },
    { "Client", &P_GEND_TYPE_m }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_1 =
{
    0U,
    P_Init_DEFERS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_1[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_1 =
{
    1U,
    P_Init_TRANS_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_1[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_1 =
{
    0U,
    P_Init_DOS_INNER_1,
    NULL
};

PRT_TRANSDECL P_TRANS_2[] =
{
    { 0, &P_EVENT_LocalEvent, 1, &_P_NO_OP }
};

#define P_STATE_ClusterManager_Init \
{ \
    "ClusterManager.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_1, \
    &P_EVENTSET_Init_TRANS_1, \
    &P_EVENTSET_Init_DOS_1, \
    P_TRANS_2, \
    NULL, \
    &P_FUNCTION_Anon_4, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Configuring_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Configuring_DEFERS =
{
    0U,
    P_Configuring_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Configuring_TRANS_INNER[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Configuring_TRANS =
{
    1U,
    P_Configuring_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Configuring_DOS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Configuring_DOS =
{
    0U,
    P_Configuring_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_3[] =
{
    { 1, &P_EVENT_LocalEvent, 2, &_P_NO_OP }
};

#define P_STATE_ClusterManager_Configuring \
{ \
    "ClusterManager.Configuring", \
    1U, \
    0U, \
    &P_EVENTSET_Configuring_DEFERS, \
    &P_EVENTSET_Configuring_TRANS, \
    &P_EVENTSET_Configuring_DOS, \
    P_TRANS_3, \
    NULL, \
    &P_FUNCTION_Anon_5, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Unavailable_DEFERS_INNER[] = { &P_EVENT_Request };
PRT_EVENTSETDECL P_EVENTSET_Unavailable_DEFERS =
{
    1U,
    P_Unavailable_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Unavailable_TRANS_INNER[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Unavailable_TRANS =
{
    1U,
    P_Unavailable_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Unavailable_DOS_INNER[] = { &P_EVENT_NotifyLeaderUpdate, &P_EVENT_ShutDown };
PRT_EVENTSETDECL P_EVENTSET_Unavailable_DOS =
{
    2U,
    P_Unavailable_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_4[] =
{
    { 2, &P_EVENT_LocalEvent, 3, &_P_NO_OP }
};

PRT_DODECL P_DOS_2[] =
{
    { 2, &P_EVENT_NotifyLeaderUpdate, &P_FUNCTION_Anon_6 },
    { 2, &P_EVENT_ShutDown, &P_FUNCTION_ShuttingDown }
};

#define P_STATE_ClusterManager_Unavailable \
{ \
    "ClusterManager.Unavailable", \
    1U, \
    2U, \
    &P_EVENTSET_Unavailable_DEFERS, \
    &P_EVENTSET_Unavailable_TRANS, \
    &P_EVENTSET_Unavailable_DOS, \
    P_TRANS_4, \
    P_DOS_2, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Available_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Available_DEFERS =
{
    0U,
    P_Available_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Available_TRANS_INNER[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Available_TRANS =
{
    1U,
    P_Available_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Available_DOS_INNER[] = { &P_EVENT_NotifyLeaderUpdate, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_ShutDown };
PRT_EVENTSETDECL P_EVENTSET_Available_DOS =
{
    4U,
    P_Available_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_5[] =
{
    { 3, &P_EVENT_LocalEvent, 2, &_P_NO_OP }
};

PRT_DODECL P_DOS_3[] =
{
    { 3, &P_EVENT_Request, &P_FUNCTION_Anon_7 },
    { 3, &P_EVENT_RedirectRequest, &P_FUNCTION_Anon_8 },
    { 3, &P_EVENT_NotifyLeaderUpdate, &P_FUNCTION_Anon_9 },
    { 3, &P_EVENT_ShutDown, &P_FUNCTION_ShuttingDown }
};

#define P_STATE_ClusterManager_Available \
{ \
    "ClusterManager.Available", \
    1U, \
    4U, \
    &P_EVENTSET_Available_DEFERS, \
    &P_EVENTSET_Available_TRANS, \
    &P_EVENTSET_Available_DOS, \
    P_TRANS_5, \
    P_DOS_3, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_ClusterManager_STATES[] = { P_STATE_ClusterManager_Init, P_STATE_ClusterManager_Configuring, P_STATE_ClusterManager_Unavailable, P_STATE_ClusterManager_Available };

PRT_VALUE* P_Anon_IMPL_4(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_idx = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_mac = PrtMkDefaultValue(&P_GEND_TYPE_m);
    PRT_VALUE* PTMP_tmp0_6 = NULL;
    PRT_VALUE* PTMP_tmp1_3 = NULL;
    PRT_VALUE* PTMP_tmp2_3 = NULL;
    PRT_VALUE* PTMP_tmp3_3 = NULL;
    PRT_VALUE* PTMP_tmp4_2 = NULL;
    PRT_VALUE* PTMP_tmp5_1 = NULL;
    PRT_VALUE* PTMP_tmp6_1 = NULL;
    PRT_VALUE* PTMP_tmp7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_7 = { PRT_VALUE_KIND_INT, { .nt = 5 } };
    PRT_VALUE P_LIT_INT32_8 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_9 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_1 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_26 = &(p_this->varValues[1]);
    PrtFreeValue(*P_LVALUE_26);
    *P_LVALUE_26 = PrtCloneValue((&P_LIT_INT32_7));
    
    PRT_VALUE** P_LVALUE_27 = &(p_this->varValues[3]);
    PrtFreeValue(*P_LVALUE_27);
    *P_LVALUE_27 = PrtCloneValue((&P_LIT_INT32_8));
    
    PRT_VALUE** P_LVALUE_28 = &(P_VAR_idx);
    PrtFreeValue(*P_LVALUE_28);
    *P_LVALUE_28 = PrtCloneValue((&P_LIT_INT32_8));
    
    PRT_VALUE** P_LVALUE_29 = &(PTMP_tmp0_6);
    PrtFreeValue(*P_LVALUE_29);
    *P_LVALUE_29 = PrtMkDefaultValue(&P_GEND_TYPE_Sm);
    
    {
        PRT_VALUE** P_LVALUE_30 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_30);
        *P_LVALUE_30 = PTMP_tmp0_6;
        PTMP_tmp0_6 = NULL;
    }
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_1)))
    {
        PRT_VALUE** P_LVALUE_31 = &(PTMP_tmp1_3);
        PrtFreeValue(*P_LVALUE_31);
        *P_LVALUE_31 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx) < PrtPrimGetInt(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_32 = &(PTMP_tmp2_3);
        PrtFreeValue(*P_LVALUE_32);
        *P_LVALUE_32 = PrtCloneValue(PTMP_tmp1_3);
        
        if (PrtPrimGetBool(PTMP_tmp2_3))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_33 = &(PTMP_tmp3_3);
        PrtFreeValue(*P_LVALUE_33);
        *P_LVALUE_33 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_34 = &(P_VAR_mac);
            PrtFreeValue(*P_LVALUE_34);
            *P_LVALUE_34 = PTMP_tmp3_3;
            PTMP_tmp3_3 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_35 = &(PTMP_tmp4_2);
        PrtFreeValue(*P_LVALUE_35);
        *P_LVALUE_35 = PrtCloneValue(P_VAR_mac);
        
        PrtSeqInsertEx(p_this->varValues[0], P_VAR_idx, PTMP_tmp4_2, PRT_FALSE);
        *(&(PTMP_tmp4_2)) = NULL;
        
        PRT_VALUE** P_LVALUE_36 = &(PTMP_tmp5_1);
        PrtFreeValue(*P_LVALUE_36);
        *P_LVALUE_36 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx) + PrtPrimGetInt((&P_LIT_INT32_9)));
        
        {
            PRT_VALUE** P_LVALUE_37 = &(P_VAR_idx);
            PrtFreeValue(*P_LVALUE_37);
            *P_LVALUE_37 = PTMP_tmp5_1;
            PTMP_tmp5_1 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_38 = &(PTMP_tmp6_1);
    PrtFreeValue(*P_LVALUE_38);
    *P_LVALUE_38 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_39 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_39);
        *P_LVALUE_39 = PTMP_tmp6_1;
        PTMP_tmp6_1 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_40 = &(PTMP_tmp7);
    PrtFreeValue(*P_LVALUE_40);
    *P_LVALUE_40 = PrtCloneValue((&P_EVENT_LocalEvent.value));
    
    PrtRaise(p_this, PTMP_tmp7, 0);
    *(&(PTMP_tmp7)) = NULL;
    goto p_return_7;
    
p_return_7: ;
    PrtFreeValue(P_VAR_idx); P_VAR_idx = NULL;
    PrtFreeValue(P_VAR_mac); P_VAR_mac = NULL;
    PrtFreeValue(PTMP_tmp0_6); PTMP_tmp0_6 = NULL;
    PrtFreeValue(PTMP_tmp1_3); PTMP_tmp1_3 = NULL;
    PrtFreeValue(PTMP_tmp2_3); PTMP_tmp2_3 = NULL;
    PrtFreeValue(PTMP_tmp3_3); PTMP_tmp3_3 = NULL;
    PrtFreeValue(PTMP_tmp4_2); PTMP_tmp4_2 = NULL;
    PrtFreeValue(PTMP_tmp5_1); PTMP_tmp5_1 = NULL;
    PrtFreeValue(PTMP_tmp6_1); PTMP_tmp6_1 = NULL;
    PrtFreeValue(PTMP_tmp7); PTMP_tmp7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_4 =
{
    NULL,
    &P_Anon_IMPL_4,
    NULL
};


PRT_VALUE* P_Anon_IMPL_5(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_idx_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_7 = NULL;
    PRT_VALUE* PTMP_tmp1_4 = NULL;
    PRT_VALUE* PTMP_tmp2_4 = NULL;
    PRT_VALUE* PTMP_tmp3_4 = NULL;
    PRT_VALUE* PTMP_tmp4_3 = NULL;
    PRT_VALUE* PTMP_tmp5_2 = NULL;
    PRT_VALUE* PTMP_tmp6_2 = NULL;
    PRT_VALUE* PTMP_tmp7_1 = NULL;
    PRT_VALUE* PTMP_tmp8 = NULL;
    PRT_VALUE* PTMP_tmp9 = NULL;
    PRT_VALUE* PTMP_tmp10 = NULL;
    PRT_VALUE* PTMP_tmp11 = NULL;
    PRT_VALUE* PTMP_tmp12 = NULL;
    PRT_VALUE* PTMP_tmp13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_10 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_11 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_2 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_41 = &(P_VAR_idx_1);
    PrtFreeValue(*P_LVALUE_41);
    *P_LVALUE_41 = PrtCloneValue((&P_LIT_INT32_10));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_2)))
    {
        PRT_VALUE** P_LVALUE_42 = &(PTMP_tmp0_7);
        PrtFreeValue(*P_LVALUE_42);
        *P_LVALUE_42 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_1) < PrtPrimGetInt(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_43 = &(PTMP_tmp1_4);
        PrtFreeValue(*P_LVALUE_43);
        *P_LVALUE_43 = PrtCloneValue(PTMP_tmp0_7);
        
        if (PrtPrimGetBool(PTMP_tmp1_4))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_44 = &(PTMP_tmp2_4);
        PrtFreeValue(*P_LVALUE_44);
        *P_LVALUE_44 = PrtSeqGet(p_this->varValues[0], P_VAR_idx_1);
        
        PRT_VALUE** P_LVALUE_45 = &(PTMP_tmp3_4);
        PrtFreeValue(*P_LVALUE_45);
        *P_LVALUE_45 = PrtCloneValue(PTMP_tmp2_4);
        
        PRT_VALUE** P_LVALUE_46 = &(PTMP_tmp4_3);
        PrtFreeValue(*P_LVALUE_46);
        *P_LVALUE_46 = PrtCloneValue((&P_EVENT_SConfigureEvent.value));
        
        PRT_VALUE** P_LVALUE_47 = &(PTMP_tmp5_2);
        PrtFreeValue(*P_LVALUE_47);
        *P_LVALUE_47 = PrtCloneValue(P_VAR_idx_1);
        
        PRT_VALUE** P_LVALUE_48 = &(PTMP_tmp6_2);
        PrtFreeValue(*P_LVALUE_48);
        *P_LVALUE_48 = PrtCloneValue(p_this->varValues[0]);
        
        PRT_VALUE** P_LVALUE_49 = &(PTMP_tmp7_1);
        PrtFreeValue(*P_LVALUE_49);
        *P_LVALUE_49 = PrtCloneValue((p_this->id));
        
        PRT_VALUE** P_LVALUE_50 = &(PTMP_tmp8);
        PrtFreeValue(*P_LVALUE_50);
        *P_LVALUE_50 = (PrtMkTuple(&P_GEND_TYPE_T3iSmR, &(PTMP_tmp5_2), &(PTMP_tmp6_2), &(PTMP_tmp7_1)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_4), PTMP_tmp4_3, 1, &(PTMP_tmp8));
        *(&(PTMP_tmp4_3)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_8;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_8;
        }
        
        PRT_VALUE** P_LVALUE_51 = &(PTMP_tmp9);
        PrtFreeValue(*P_LVALUE_51);
        *P_LVALUE_51 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_1) + PrtPrimGetInt((&P_LIT_INT32_11)));
        
        {
            PRT_VALUE** P_LVALUE_52 = &(P_VAR_idx_1);
            PrtFreeValue(*P_LVALUE_52);
            *P_LVALUE_52 = PTMP_tmp9;
            PTMP_tmp9 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_53 = &(PTMP_tmp10);
    PrtFreeValue(*P_LVALUE_53);
    *P_LVALUE_53 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_54 = &(PTMP_tmp11);
    PrtFreeValue(*P_LVALUE_54);
    *P_LVALUE_54 = PrtCloneValue((&P_EVENT_CConfigureEvent.value));
    
    PRT_VALUE** P_LVALUE_55 = &(PTMP_tmp12);
    PrtFreeValue(*P_LVALUE_55);
    *P_LVALUE_55 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp10), PTMP_tmp11, 1, &(PTMP_tmp12));
    *(&(PTMP_tmp11)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_8;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_8;
    }
    
    PRT_VALUE** P_LVALUE_56 = &(PTMP_tmp13);
    PrtFreeValue(*P_LVALUE_56);
    *P_LVALUE_56 = PrtCloneValue((&P_EVENT_LocalEvent.value));
    
    PrtRaise(p_this, PTMP_tmp13, 0);
    *(&(PTMP_tmp13)) = NULL;
    goto p_return_8;
    
p_return_8: ;
    PrtFreeValue(P_VAR_idx_1); P_VAR_idx_1 = NULL;
    PrtFreeValue(PTMP_tmp0_7); PTMP_tmp0_7 = NULL;
    PrtFreeValue(PTMP_tmp1_4); PTMP_tmp1_4 = NULL;
    PrtFreeValue(PTMP_tmp2_4); PTMP_tmp2_4 = NULL;
    PrtFreeValue(PTMP_tmp3_4); PTMP_tmp3_4 = NULL;
    PrtFreeValue(PTMP_tmp4_3); PTMP_tmp4_3 = NULL;
    PrtFreeValue(PTMP_tmp5_2); PTMP_tmp5_2 = NULL;
    PrtFreeValue(PTMP_tmp6_2); PTMP_tmp6_2 = NULL;
    PrtFreeValue(PTMP_tmp7_1); PTMP_tmp7_1 = NULL;
    PrtFreeValue(PTMP_tmp8); PTMP_tmp8 = NULL;
    PrtFreeValue(PTMP_tmp9); PTMP_tmp9 = NULL;
    PrtFreeValue(PTMP_tmp10); PTMP_tmp10 = NULL;
    PrtFreeValue(PTMP_tmp11); PTMP_tmp11 = NULL;
    PrtFreeValue(PTMP_tmp12); PTMP_tmp12 = NULL;
    PrtFreeValue(PTMP_tmp13); PTMP_tmp13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_5 =
{
    NULL,
    &P_Anon_IMPL_5,
    NULL
};


PRT_VALUE* P_Anon_IMPL_6(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_8 = NULL;
    PRT_VALUE* PTMP_tmp1_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_57 = &(PTMP_tmp0_8);
    PrtFreeValue(*P_LVALUE_57);
    *P_LVALUE_57 = PrtCloneValue(*P_VAR_payload_3);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_8);
    PrtFreeValue(P_UpdateLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_8);
    PTMP_tmp0_8 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_9;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_9;
    }
    
    PRT_VALUE** P_LVALUE_58 = &(PTMP_tmp1_5);
    PrtFreeValue(*P_LVALUE_58);
    *P_LVALUE_58 = PrtCloneValue((&P_EVENT_LocalEvent.value));
    
    PrtRaise(p_this, PTMP_tmp1_5, 0);
    *(&(PTMP_tmp1_5)) = NULL;
    goto p_return_9;
    
p_return_9: ;
    PrtFreeValue(PTMP_tmp0_8); PTMP_tmp0_8 = NULL;
    PrtFreeValue(PTMP_tmp1_5); PTMP_tmp1_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_6 =
{
    NULL,
    &P_Anon_IMPL_6,
    &P_GEND_TYPE_T2mi
};


PRT_VALUE* P_UpdateLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request = argRefs[0];
    PRT_VALUE* PTMP_tmp0_9 = NULL;
    PRT_VALUE* PTMP_tmp1_6 = NULL;
    PRT_VALUE* PTMP_tmp2_5 = NULL;
    PRT_VALUE* PTMP_tmp3_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_59 = &(PTMP_tmp0_9);
    PrtFreeValue(*P_LVALUE_59);
    *P_LVALUE_59 = PrtTupleGet(*P_VAR_request, 1);
    
    PRT_VALUE** P_LVALUE_60 = &(PTMP_tmp1_6);
    PrtFreeValue(*P_LVALUE_60);
    *P_LVALUE_60 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[3]) < PrtPrimGetInt(PTMP_tmp0_9));
    
    if (PrtPrimGetBool(PTMP_tmp1_6))
    {
        PRT_VALUE** P_LVALUE_61 = &(PTMP_tmp2_5);
        PrtFreeValue(*P_LVALUE_61);
        *P_LVALUE_61 = PrtTupleGet(*P_VAR_request, 0);
        
        {
            PRT_VALUE** P_LVALUE_62 = &(p_this->varValues[2]);
            PrtFreeValue(*P_LVALUE_62);
            *P_LVALUE_62 = PTMP_tmp2_5;
            PTMP_tmp2_5 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_63 = &(PTMP_tmp3_5);
        PrtFreeValue(*P_LVALUE_63);
        *P_LVALUE_63 = PrtTupleGet(*P_VAR_request, 1);
        
        {
            PRT_VALUE** P_LVALUE_64 = &(p_this->varValues[3]);
            PrtFreeValue(*P_LVALUE_64);
            *P_LVALUE_64 = PTMP_tmp3_5;
            PTMP_tmp3_5 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
p_return_10: ;
    PrtFreeValue(PTMP_tmp0_9); PTMP_tmp0_9 = NULL;
    PrtFreeValue(PTMP_tmp1_6); PTMP_tmp1_6 = NULL;
    PrtFreeValue(PTMP_tmp2_5); PTMP_tmp2_5 = NULL;
    PrtFreeValue(PTMP_tmp3_5); PTMP_tmp3_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_UpdateLeader =
{
    "UpdateLeader",
    &P_UpdateLeader_IMPL,
    NULL
};


PRT_VALUE* P_ShuttingDown_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_idx_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_10 = NULL;
    PRT_VALUE* PTMP_tmp1_7 = NULL;
    PRT_VALUE* PTMP_tmp2_6 = NULL;
    PRT_VALUE* PTMP_tmp3_6 = NULL;
    PRT_VALUE* PTMP_tmp4_4 = NULL;
    PRT_VALUE* PTMP_tmp5_3 = NULL;
    PRT_VALUE* PTMP_tmp6_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_12 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_13 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_3 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_65 = &(P_VAR_idx_2);
    PrtFreeValue(*P_LVALUE_65);
    *P_LVALUE_65 = PrtCloneValue((&P_LIT_INT32_12));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_3)))
    {
        PRT_VALUE** P_LVALUE_66 = &(PTMP_tmp0_10);
        PrtFreeValue(*P_LVALUE_66);
        *P_LVALUE_66 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_2) < PrtPrimGetInt(p_this->varValues[1]));
        
        PRT_VALUE** P_LVALUE_67 = &(PTMP_tmp1_7);
        PrtFreeValue(*P_LVALUE_67);
        *P_LVALUE_67 = PrtCloneValue(PTMP_tmp0_10);
        
        if (PrtPrimGetBool(PTMP_tmp1_7))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_68 = &(PTMP_tmp2_6);
        PrtFreeValue(*P_LVALUE_68);
        *P_LVALUE_68 = PrtSeqGet(p_this->varValues[0], P_VAR_idx_2);
        
        PRT_VALUE** P_LVALUE_69 = &(PTMP_tmp3_6);
        PrtFreeValue(*P_LVALUE_69);
        *P_LVALUE_69 = PrtCloneValue(PTMP_tmp2_6);
        
        PRT_VALUE** P_LVALUE_70 = &(PTMP_tmp4_4);
        PrtFreeValue(*P_LVALUE_70);
        *P_LVALUE_70 = PrtCloneValue((&P_EVENT_ShutDown.value));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_6), PTMP_tmp4_4, 0);
        *(&(PTMP_tmp4_4)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_11;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_11;
        }
        
        PRT_VALUE** P_LVALUE_71 = &(PTMP_tmp5_3);
        PrtFreeValue(*P_LVALUE_71);
        *P_LVALUE_71 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_2) + PrtPrimGetInt((&P_LIT_INT32_13)));
        
        {
            PRT_VALUE** P_LVALUE_72 = &(P_VAR_idx_2);
            PrtFreeValue(*P_LVALUE_72);
            *P_LVALUE_72 = PTMP_tmp5_3;
            PTMP_tmp5_3 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_73 = &(PTMP_tmp6_3);
    PrtFreeValue(*P_LVALUE_73);
    *P_LVALUE_73 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtRaise(p_this, PTMP_tmp6_3, 0);
    *(&(PTMP_tmp6_3)) = NULL;
    goto p_return_11;
    
p_return_11: ;
    PrtFreeValue(P_VAR_idx_2); P_VAR_idx_2 = NULL;
    PrtFreeValue(PTMP_tmp0_10); PTMP_tmp0_10 = NULL;
    PrtFreeValue(PTMP_tmp1_7); PTMP_tmp1_7 = NULL;
    PrtFreeValue(PTMP_tmp2_6); PTMP_tmp2_6 = NULL;
    PrtFreeValue(PTMP_tmp3_6); PTMP_tmp3_6 = NULL;
    PrtFreeValue(PTMP_tmp4_4); PTMP_tmp4_4 = NULL;
    PrtFreeValue(PTMP_tmp5_3); PTMP_tmp5_3 = NULL;
    PrtFreeValue(PTMP_tmp6_3); PTMP_tmp6_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ShuttingDown =
{
    "ShuttingDown",
    &P_ShuttingDown_IMPL,
    NULL
};


PRT_VALUE* P_Anon_IMPL_7(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_11 = NULL;
    PRT_VALUE* PTMP_tmp1_8 = NULL;
    PRT_VALUE* PTMP_tmp2_7 = NULL;
    PRT_VALUE* PTMP_tmp3_7 = NULL;
    PRT_VALUE* PTMP_tmp4_5 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_74 = &(PTMP_tmp0_11);
    PrtFreeValue(*P_LVALUE_74);
    *P_LVALUE_74 = PrtCloneValue(p_this->varValues[2]);
    
    PRT_VALUE** P_LVALUE_75 = &(PTMP_tmp1_8);
    PrtFreeValue(*P_LVALUE_75);
    *P_LVALUE_75 = PrtCloneValue((&P_EVENT_Request.value));
    
    PRT_VALUE** P_LVALUE_76 = &(PTMP_tmp2_7);
    PrtFreeValue(*P_LVALUE_76);
    *P_LVALUE_76 = PrtTupleGet(*P_VAR_payload_4, 0);
    
    PRT_VALUE** P_LVALUE_77 = &(PTMP_tmp3_7);
    PrtFreeValue(*P_LVALUE_77);
    *P_LVALUE_77 = PrtTupleGet(*P_VAR_payload_4, 1);
    
    PRT_VALUE** P_LVALUE_78 = &(PTMP_tmp4_5);
    PrtFreeValue(*P_LVALUE_78);
    *P_LVALUE_78 = (PrtMkTuple(&P_GEND_TYPE_T2mi_1, &(PTMP_tmp2_7), &(PTMP_tmp3_7)));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_11), PTMP_tmp1_8, 1, &(PTMP_tmp4_5));
    *(&(PTMP_tmp1_8)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_12;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_12;
    }
    
p_return_12: ;
    PrtFreeValue(PTMP_tmp0_11); PTMP_tmp0_11 = NULL;
    PrtFreeValue(PTMP_tmp1_8); PTMP_tmp1_8 = NULL;
    PrtFreeValue(PTMP_tmp2_7); PTMP_tmp2_7 = NULL;
    PrtFreeValue(PTMP_tmp3_7); PTMP_tmp3_7 = NULL;
    PrtFreeValue(PTMP_tmp4_5); PTMP_tmp4_5 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_7 =
{
    NULL,
    &P_Anon_IMPL_7,
    &P_GEND_TYPE_T2mi_1
};


PRT_VALUE* P_Anon_IMPL_8(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_12 = NULL;
    PRT_VALUE* PTMP_tmp1_9 = NULL;
    PRT_VALUE* PTMP_tmp2_8 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_79 = &(PTMP_tmp0_12);
    PrtFreeValue(*P_LVALUE_79);
    *P_LVALUE_79 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_80 = &(PTMP_tmp1_9);
    PrtFreeValue(*P_LVALUE_80);
    *P_LVALUE_80 = PrtCloneValue((&P_EVENT_Request.value));
    
    PRT_VALUE** P_LVALUE_81 = &(PTMP_tmp2_8);
    PrtFreeValue(*P_LVALUE_81);
    *P_LVALUE_81 = PrtCloneValue(*P_VAR_payload_5);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_12), PTMP_tmp1_9, 1, &(PTMP_tmp2_8));
    *(&(PTMP_tmp1_9)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_13;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_13;
    }
    
p_return_13: ;
    PrtFreeValue(PTMP_tmp0_12); PTMP_tmp0_12 = NULL;
    PrtFreeValue(PTMP_tmp1_9); PTMP_tmp1_9 = NULL;
    PrtFreeValue(PTMP_tmp2_8); PTMP_tmp2_8 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_8 =
{
    NULL,
    &P_Anon_IMPL_8,
    &P_GEND_TYPE_T2mi_1
};


PRT_VALUE* P_Anon_IMPL_9(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_6 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_82 = &(PTMP_tmp0_13);
    PrtFreeValue(*P_LVALUE_82);
    *P_LVALUE_82 = PrtCloneValue(*P_VAR_payload_6);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_13);
    PrtFreeValue(P_UpdateLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_13);
    PTMP_tmp0_13 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_14;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_14;
    }
    
p_return_14: ;
    PrtFreeValue(PTMP_tmp0_13); PTMP_tmp0_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_9 =
{
    NULL,
    &P_Anon_IMPL_9,
    &P_GEND_TYPE_T2mi
};


PRT_VALUE* P_BecomeUnavailable_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
p_return_15: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_BecomeUnavailable =
{
    "BecomeUnavailable",
    &P_BecomeUnavailable_IMPL,
    NULL
};


PRT_FUNDECL* P_ClusterManager_METHODS[] = { &P_FUNCTION_Anon_4, &P_FUNCTION_Anon_5, &P_FUNCTION_Anon_6, &P_FUNCTION_UpdateLeader, &P_FUNCTION_ShuttingDown, &P_FUNCTION_Anon_7, &P_FUNCTION_Anon_8, &P_FUNCTION_Anon_9, &P_FUNCTION_BecomeUnavailable };

PRT_EVENTDECL* P_ClusterManager_RECV_INNER_1[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClusterManager_RECV_1 =
{
    28U,
    P_ClusterManager_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_ClusterManager_SEND_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_ClusterManager_SEND =
{
    28U,
    P_ClusterManager_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_ClusterManager = 
{
    1U,
    "ClusterManager",
    &P_EVENTSET_ClusterManager_RECV_1,
    &P_EVENTSET_ClusterManager_SEND,
    NULL,
    5U,
    4U,
    9U,
    4294967295U,
    0U,
    P_ClusterManager_VARS,
    P_ClusterManager_STATES,
    P_ClusterManager_METHODS
};

PRT_VARDECL P_SafetyMonitor_VARS[] = {
    { "TermsWithLeader", &P_GEND_TYPE_MKiVb }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_2 =
{
    0U,
    P_Init_DEFERS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_2[] = { &P_EVENT_LocalEvent };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_2 =
{
    1U,
    P_Init_TRANS_INNER_2,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_2[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_2 =
{
    0U,
    P_Init_DOS_INNER_2,
    NULL
};

PRT_TRANSDECL P_TRANS_6[] =
{
    { 0, &P_EVENT_LocalEvent, 1, &_P_NO_OP }
};

#define P_STATE_SafetyMonitor_Init \
{ \
    "SafetyMonitor.Init", \
    1U, \
    0U, \
    &P_EVENTSET_Init_DEFERS_2, \
    &P_EVENTSET_Init_TRANS_2, \
    &P_EVENTSET_Init_DOS_2, \
    P_TRANS_6, \
    NULL, \
    &P_FUNCTION_Anon_10, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Monitoring_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Monitoring_DEFERS =
{
    0U,
    P_Monitoring_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Monitoring_TRANS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Monitoring_TRANS =
{
    0U,
    P_Monitoring_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Monitoring_DOS_INNER[] = { &P_EVENT_NotifyLeaderElected };
PRT_EVENTSETDECL P_EVENTSET_Monitoring_DOS =
{
    1U,
    P_Monitoring_DOS_INNER,
    NULL
};

PRT_DODECL P_DOS_4[] =
{
    { 1, &P_EVENT_NotifyLeaderElected, &P_FUNCTION_Anon_11 }
};

#define P_STATE_SafetyMonitor_Monitoring \
{ \
    "SafetyMonitor.Monitoring", \
    0U, \
    1U, \
    &P_EVENTSET_Monitoring_DEFERS, \
    &P_EVENTSET_Monitoring_TRANS, \
    &P_EVENTSET_Monitoring_DOS, \
    NULL, \
    P_DOS_4, \
    &_P_NO_OP, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_SafetyMonitor_STATES[] = { P_STATE_SafetyMonitor_Init, P_STATE_SafetyMonitor_Monitoring };

PRT_VALUE* P_Anon_IMPL_10(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_14 = NULL;
    PRT_VALUE* PTMP_tmp1_10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_83 = &(PTMP_tmp0_14);
    PrtFreeValue(*P_LVALUE_83);
    *P_LVALUE_83 = PrtMkDefaultValue(&P_GEND_TYPE_MKiVb);
    
    {
        PRT_VALUE** P_LVALUE_84 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_84);
        *P_LVALUE_84 = PTMP_tmp0_14;
        PTMP_tmp0_14 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_85 = &(PTMP_tmp1_10);
    PrtFreeValue(*P_LVALUE_85);
    *P_LVALUE_85 = PrtCloneValue((&P_EVENT_LocalEvent.value));
    
    PrtRaise(p_this, PTMP_tmp1_10, 0);
    *(&(PTMP_tmp1_10)) = NULL;
    goto p_return_16;
    
p_return_16: ;
    PrtFreeValue(PTMP_tmp0_14); PTMP_tmp0_14 = NULL;
    PrtFreeValue(PTMP_tmp1_10); PTMP_tmp1_10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_10 =
{
    NULL,
    &P_Anon_IMPL_10,
    NULL
};


PRT_VALUE* P_Anon_IMPL_11(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_15 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_86 = &(PTMP_tmp0_15);
    PrtFreeValue(*P_LVALUE_86);
    *P_LVALUE_86 = PrtCloneValue(*P_VAR_payload_7);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_15);
    PrtFreeValue(P_ProcessLeaderElected_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_15);
    PTMP_tmp0_15 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_17;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_17;
    }
    
p_return_17: ;
    PrtFreeValue(PTMP_tmp0_15); PTMP_tmp0_15 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_11 =
{
    NULL,
    &P_Anon_IMPL_11,
    &P_GEND_TYPE_i
};


PRT_VALUE* P_ProcessLeaderElected_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_8 = argRefs[0];
    PRT_VALUE* P_VAR_term = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_16 = NULL;
    PRT_VALUE* PTMP_tmp1_11 = NULL;
    PRT_VALUE* PTMP_tmp2_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_4 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_87 = &(P_VAR_term);
    PrtFreeValue(*P_LVALUE_87);
    *P_LVALUE_87 = PrtCloneValue(*P_VAR_payload_8);
    
    PRT_VALUE** P_LVALUE_88 = &(PTMP_tmp0_16);
    PrtFreeValue(*P_LVALUE_88);
    *P_LVALUE_88 = PrtMapGet(p_this->varValues[0], P_VAR_term);
    
    if (PrtPrimGetBool(PTMP_tmp0_16))
    {
        PrtFormatPrintf("Detected more than one leader in term ", 1, P_VAR_term, 1, 0, "");
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_89 = &(PTMP_tmp1_11);
    PrtFreeValue(*P_LVALUE_89);
    *P_LVALUE_89 = PrtMapGet(p_this->varValues[0], P_VAR_term);
    
    PRT_VALUE** P_LVALUE_90 = &(PTMP_tmp2_9);
    PrtFreeValue(*P_LVALUE_90);
    *P_LVALUE_90 = PrtMkBoolValue(!PrtPrimGetBool(PTMP_tmp1_11));
    
    PrtAssert(PrtPrimGetBool(PTMP_tmp2_9), "");
    
    PRT_VALUE** P_LVALUE_91 = &(*(PrtMapGetLValue(p_this->varValues[0], P_VAR_term, PRT_TRUE, &P_GEND_TYPE_MKiVb)));
    PrtFreeValue(*P_LVALUE_91);
    *P_LVALUE_91 = PrtCloneValue((&P_LIT_BOOLEAN_4));
    
p_return_18: ;
    PrtFreeValue(P_VAR_term); P_VAR_term = NULL;
    PrtFreeValue(PTMP_tmp0_16); PTMP_tmp0_16 = NULL;
    PrtFreeValue(PTMP_tmp1_11); PTMP_tmp1_11 = NULL;
    PrtFreeValue(PTMP_tmp2_9); PTMP_tmp2_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ProcessLeaderElected =
{
    "ProcessLeaderElected",
    &P_ProcessLeaderElected_IMPL,
    NULL
};


PRT_FUNDECL* P_SafetyMonitor_METHODS[] = { &P_FUNCTION_Anon_10, &P_FUNCTION_Anon_11, &P_FUNCTION_ProcessLeaderElected };

PRT_EVENTDECL* P_SafetyMonitor_RECV_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SafetyMonitor_RECV =
{
    0U,
    P_SafetyMonitor_RECV_INNER,
    NULL
};

PRT_EVENTDECL* P_SafetyMonitor_SEND_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_SafetyMonitor_SEND =
{
    0U,
    P_SafetyMonitor_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_SafetyMonitor = 
{
    2U,
    "SafetyMonitor",
    &P_EVENTSET_SafetyMonitor_RECV,
    &P_EVENTSET_SafetyMonitor_SEND,
    NULL,
    1U,
    2U,
    3U,
    4294967295U,
    0U,
    P_SafetyMonitor_VARS,
    P_SafetyMonitor_STATES,
    P_SafetyMonitor_METHODS
};

PRT_VARDECL P_Server_VARS[] = {
    { "ServerId", &P_GEND_TYPE_i },
    { "ClusterManager", &P_GEND_TYPE_m },
    { "Servers", &P_GEND_TYPE_Sm },
    { "LeaderId", &P_GEND_TYPE_m },
    { "ElectionTimer", &P_GEND_TYPE_m },
    { "PeriodicTimer", &P_GEND_TYPE_m },
    { "CurrentTerm", &P_GEND_TYPE_i },
    { "VotedFor", &P_GEND_TYPE_m },
    { "Logs", &P_GEND_TYPE_ST2ii },
    { "CommitIndex", &P_GEND_TYPE_i },
    { "LastApplied", &P_GEND_TYPE_i },
    { "NextIndex", &P_GEND_TYPE_MKmVi },
    { "MatchIndex", &P_GEND_TYPE_MKmVi },
    { "VotesReceived", &P_GEND_TYPE_i },
    { "LastClientRequest", &P_GEND_TYPE_T2mi_1 },
    { "i", &P_GEND_TYPE_i }
};

PRT_EVENTDECL* P_Init_DEFERS_INNER_3[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_VoteRequest };
PRT_EVENTSETDECL P_EVENTSET_Init_DEFERS_3 =
{
    2U,
    P_Init_DEFERS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_TRANS_INNER_3[] = { &P_EVENT_BecomeFollower };
PRT_EVENTSETDECL P_EVENTSET_Init_TRANS_3 =
{
    1U,
    P_Init_TRANS_INNER_3,
    NULL
};

PRT_EVENTDECL* P_Init_DOS_INNER_3[] = { &P_EVENT_SConfigureEvent };
PRT_EVENTSETDECL P_EVENTSET_Init_DOS_3 =
{
    1U,
    P_Init_DOS_INNER_3,
    NULL
};

PRT_TRANSDECL P_TRANS_7[] =
{
    { 0, &P_EVENT_BecomeFollower, 1, &_P_NO_OP }
};

PRT_DODECL P_DOS_5[] =
{
    { 0, &P_EVENT_SConfigureEvent, &P_FUNCTION_Anon_13 }
};

#define P_STATE_Server_Init \
{ \
    "Server.Init", \
    1U, \
    1U, \
    &P_EVENTSET_Init_DEFERS_3, \
    &P_EVENTSET_Init_TRANS_3, \
    &P_EVENTSET_Init_DOS_3, \
    P_TRANS_7, \
    P_DOS_5, \
    &P_FUNCTION_Anon_12, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Follower_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Follower_DEFERS =
{
    0U,
    P_Follower_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Follower_TRANS_INNER[] = { &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower };
PRT_EVENTSETDECL P_EVENTSET_Follower_TRANS =
{
    2U,
    P_Follower_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Follower_DOS_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_ETimeout, &P_EVENT_PTimeout, &P_EVENT_Request, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse };
PRT_EVENTSETDECL P_EVENTSET_Follower_DOS =
{
    8U,
    P_Follower_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_8[] =
{
    { 1, &P_EVENT_BecomeFollower, 1, &_P_NO_OP },
    { 1, &P_EVENT_BecomeCandidate, 2, &_P_NO_OP }
};

PRT_DODECL P_DOS_6[] =
{
    { 1, &P_EVENT_Request, &P_FUNCTION_Anon_15 },
    { 1, &P_EVENT_VoteRequest, &P_FUNCTION_Anon_16 },
    { 1, &P_EVENT_VoteResponse, &P_FUNCTION_Anon_17 },
    { 1, &P_EVENT_AppendEntriesRequest, &P_FUNCTION_Anon_18 },
    { 1, &P_EVENT_AppendEntriesResponse, &P_FUNCTION_Anon_19 },
    { 1, &P_EVENT_ETimeout, &P_FUNCTION_Anon_20 },
    { 1, &P_EVENT_ShutDown, &P_FUNCTION_Anon_21 },
    { 1, &P_EVENT_PTimeout, NULL }
};

#define P_STATE_Server_Follower \
{ \
    "Server.Follower", \
    2U, \
    8U, \
    &P_EVENTSET_Follower_DEFERS, \
    &P_EVENTSET_Follower_TRANS, \
    &P_EVENTSET_Follower_DOS, \
    P_TRANS_8, \
    P_DOS_6, \
    &P_FUNCTION_Anon_14, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Candidate_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Candidate_DEFERS =
{
    0U,
    P_Candidate_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Candidate_TRANS_INNER[] = { &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader };
PRT_EVENTSETDECL P_EVENTSET_Candidate_TRANS =
{
    3U,
    P_Candidate_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Candidate_DOS_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_ETimeout, &P_EVENT_PTimeout, &P_EVENT_Request, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse };
PRT_EVENTSETDECL P_EVENTSET_Candidate_DOS =
{
    8U,
    P_Candidate_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_9[] =
{
    { 2, &P_EVENT_BecomeLeader, 3, &_P_NO_OP },
    { 2, &P_EVENT_BecomeFollower, 1, &_P_NO_OP },
    { 2, &P_EVENT_BecomeCandidate, 2, &_P_NO_OP }
};

PRT_DODECL P_DOS_7[] =
{
    { 2, &P_EVENT_Request, &P_FUNCTION_Anon_23 },
    { 2, &P_EVENT_VoteRequest, &P_FUNCTION_Anon_24 },
    { 2, &P_EVENT_VoteResponse, &P_FUNCTION_Anon_25 },
    { 2, &P_EVENT_AppendEntriesRequest, &P_FUNCTION_Anon_26 },
    { 2, &P_EVENT_AppendEntriesResponse, &P_FUNCTION_Anon_27 },
    { 2, &P_EVENT_ETimeout, &P_FUNCTION_Anon_28 },
    { 2, &P_EVENT_PTimeout, &P_FUNCTION_BroadcastVoteRequests },
    { 2, &P_EVENT_ShutDown, &P_FUNCTION_ShuttingDown_1 }
};

#define P_STATE_Server_Candidate \
{ \
    "Server.Candidate", \
    3U, \
    8U, \
    &P_EVENTSET_Candidate_DEFERS, \
    &P_EVENTSET_Candidate_TRANS, \
    &P_EVENTSET_Candidate_DOS, \
    P_TRANS_9, \
    P_DOS_7, \
    &P_FUNCTION_Anon_22, \
    &_P_NO_OP, \
}

PRT_EVENTDECL* P_Leader_DEFERS_INNER[] = { NULL };
PRT_EVENTSETDECL P_EVENTSET_Leader_DEFERS =
{
    0U,
    P_Leader_DEFERS_INNER,
    NULL
};

PRT_EVENTDECL* P_Leader_TRANS_INNER[] = { &P_EVENT_BecomeFollower };
PRT_EVENTSETDECL P_EVENTSET_Leader_TRANS =
{
    1U,
    P_Leader_TRANS_INNER,
    NULL
};

PRT_EVENTDECL* P_Leader_DOS_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_ETimeout, &P_EVENT_PTimeout, &P_EVENT_Request, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse };
PRT_EVENTSETDECL P_EVENTSET_Leader_DOS =
{
    8U,
    P_Leader_DOS_INNER,
    NULL
};

PRT_TRANSDECL P_TRANS_10[] =
{
    { 3, &P_EVENT_BecomeFollower, 1, &_P_NO_OP }
};

PRT_DODECL P_DOS_8[] =
{
    { 3, &P_EVENT_Request, &P_FUNCTION_Anon_30 },
    { 3, &P_EVENT_VoteRequest, &P_FUNCTION_Anon_31 },
    { 3, &P_EVENT_VoteResponse, &P_FUNCTION_Anon_32 },
    { 3, &P_EVENT_AppendEntriesRequest, &P_FUNCTION_Anon_33 },
    { 3, &P_EVENT_AppendEntriesResponse, &P_FUNCTION_Anon_34 },
    { 3, &P_EVENT_ShutDown, &P_FUNCTION_ShuttingDown_1 },
    { 3, &P_EVENT_ETimeout, NULL },
    { 3, &P_EVENT_PTimeout, NULL }
};

#define P_STATE_Server_Leader \
{ \
    "Server.Leader", \
    1U, \
    8U, \
    &P_EVENTSET_Leader_DEFERS, \
    &P_EVENTSET_Leader_TRANS, \
    &P_EVENTSET_Leader_DOS, \
    P_TRANS_10, \
    P_DOS_8, \
    &P_FUNCTION_Anon_29, \
    &_P_NO_OP, \
}

PRT_STATEDECL P_Server_STATES[] = { P_STATE_Server_Init, P_STATE_Server_Follower, P_STATE_Server_Candidate, P_STATE_Server_Leader };

PRT_VALUE* P_Anon_IMPL_12(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_17 = NULL;
    PRT_VALUE* PTMP_tmp1_12 = NULL;
    PRT_VALUE* PTMP_tmp2_10 = NULL;
    PRT_VALUE* PTMP_tmp3_8 = NULL;
    PRT_VALUE* PTMP_tmp4_6 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_14 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_92 = &(p_this->varValues[15]);
    PrtFreeValue(*P_LVALUE_92);
    *P_LVALUE_92 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_93 = &(p_this->varValues[6]);
    PrtFreeValue(*P_LVALUE_93);
    *P_LVALUE_93 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_94 = &(PTMP_tmp0_17);
    PrtFreeValue(*P_LVALUE_94);
    *P_LVALUE_94 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_95 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_95);
        *P_LVALUE_95 = PTMP_tmp0_17;
        PTMP_tmp0_17 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_96 = &(PTMP_tmp1_12);
    PrtFreeValue(*P_LVALUE_96);
    *P_LVALUE_96 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_97 = &(p_this->varValues[7]);
        PrtFreeValue(*P_LVALUE_97);
        *P_LVALUE_97 = PTMP_tmp1_12;
        PTMP_tmp1_12 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_98 = &(PTMP_tmp2_10);
    PrtFreeValue(*P_LVALUE_98);
    *P_LVALUE_98 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
    
    {
        PRT_VALUE** P_LVALUE_99 = &(p_this->varValues[8]);
        PrtFreeValue(*P_LVALUE_99);
        *P_LVALUE_99 = PTMP_tmp2_10;
        PTMP_tmp2_10 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_100 = &(p_this->varValues[9]);
    PrtFreeValue(*P_LVALUE_100);
    *P_LVALUE_100 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_101 = &(p_this->varValues[10]);
    PrtFreeValue(*P_LVALUE_101);
    *P_LVALUE_101 = PrtCloneValue((&P_LIT_INT32_14));
    
    PRT_VALUE** P_LVALUE_102 = &(PTMP_tmp3_8);
    PrtFreeValue(*P_LVALUE_102);
    *P_LVALUE_102 = PrtMkDefaultValue(&P_GEND_TYPE_MKmVi);
    
    {
        PRT_VALUE** P_LVALUE_103 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_103);
        *P_LVALUE_103 = PTMP_tmp3_8;
        PTMP_tmp3_8 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_104 = &(PTMP_tmp4_6);
    PrtFreeValue(*P_LVALUE_104);
    *P_LVALUE_104 = PrtMkDefaultValue(&P_GEND_TYPE_MKmVi);
    
    {
        PRT_VALUE** P_LVALUE_105 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_105);
        *P_LVALUE_105 = PTMP_tmp4_6;
        PTMP_tmp4_6 = NULL;
    }
    
p_return_19: ;
    PrtFreeValue(PTMP_tmp0_17); PTMP_tmp0_17 = NULL;
    PrtFreeValue(PTMP_tmp1_12); PTMP_tmp1_12 = NULL;
    PrtFreeValue(PTMP_tmp2_10); PTMP_tmp2_10 = NULL;
    PrtFreeValue(PTMP_tmp3_8); PTMP_tmp3_8 = NULL;
    PrtFreeValue(PTMP_tmp4_6); PTMP_tmp4_6 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_12 =
{
    NULL,
    &P_Anon_IMPL_12,
    NULL
};


PRT_VALUE* P_Anon_IMPL_13(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_9 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_18 = NULL;
    PRT_VALUE* PTMP_tmp1_13 = NULL;
    PRT_VALUE* PTMP_tmp2_11 = NULL;
    PRT_VALUE* PTMP_tmp3_9 = NULL;
    PRT_VALUE* PTMP_tmp4_7 = NULL;
    PRT_VALUE* PTMP_tmp5_4 = NULL;
    PRT_VALUE* PTMP_tmp6_4 = NULL;
    PRT_VALUE* PTMP_tmp7_2 = NULL;
    PRT_VALUE* PTMP_tmp8_1 = NULL;
    PRT_VALUE* PTMP_tmp9_1 = NULL;
    PRT_VALUE* PTMP_tmp10_1 = NULL;
    PRT_VALUE* PTMP_tmp11_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_106 = &(PTMP_tmp0_18);
    PrtFreeValue(*P_LVALUE_106);
    *P_LVALUE_106 = PrtTupleGet(*P_VAR_payload_9, 0);
    
    {
        PRT_VALUE** P_LVALUE_107 = &(p_this->varValues[0]);
        PrtFreeValue(*P_LVALUE_107);
        *P_LVALUE_107 = PTMP_tmp0_18;
        PTMP_tmp0_18 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_108 = &(PTMP_tmp1_13);
    PrtFreeValue(*P_LVALUE_108);
    *P_LVALUE_108 = PrtTupleGet(*P_VAR_payload_9, 1);
    
    {
        PRT_VALUE** P_LVALUE_109 = &(p_this->varValues[2]);
        PrtFreeValue(*P_LVALUE_109);
        *P_LVALUE_109 = PTMP_tmp1_13;
        PTMP_tmp1_13 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_110 = &(PTMP_tmp2_11);
    PrtFreeValue(*P_LVALUE_110);
    *P_LVALUE_110 = PrtTupleGet(*P_VAR_payload_9, 2);
    
    {
        PRT_VALUE** P_LVALUE_111 = &(p_this->varValues[1]);
        PrtFreeValue(*P_LVALUE_111);
        *P_LVALUE_111 = PTMP_tmp2_11;
        PTMP_tmp2_11 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_112 = &(PTMP_tmp3_9);
    PrtFreeValue(*P_LVALUE_112);
    *P_LVALUE_112 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_113 = &(p_this->varValues[4]);
        PrtFreeValue(*P_LVALUE_113);
        *P_LVALUE_113 = PTMP_tmp3_9;
        PTMP_tmp3_9 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_114 = &(PTMP_tmp4_7);
    PrtFreeValue(*P_LVALUE_114);
    *P_LVALUE_114 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_115 = &(PTMP_tmp5_4);
    PrtFreeValue(*P_LVALUE_115);
    *P_LVALUE_115 = PrtCloneValue((&P_EVENT_EConfigureEvent.value));
    
    PRT_VALUE** P_LVALUE_116 = &(PTMP_tmp6_4);
    PrtFreeValue(*P_LVALUE_116);
    *P_LVALUE_116 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp4_7), PTMP_tmp5_4, 1, &(PTMP_tmp6_4));
    *(&(PTMP_tmp5_4)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_20;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_20;
    }
    
    PRT_VALUE** P_LVALUE_117 = &(PTMP_tmp7_2);
    PrtFreeValue(*P_LVALUE_117);
    *P_LVALUE_117 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_118 = &(p_this->varValues[5]);
        PrtFreeValue(*P_LVALUE_118);
        *P_LVALUE_118 = PTMP_tmp7_2;
        PTMP_tmp7_2 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_119 = &(PTMP_tmp8_1);
    PrtFreeValue(*P_LVALUE_119);
    *P_LVALUE_119 = PrtCloneValue(p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_120 = &(PTMP_tmp9_1);
    PrtFreeValue(*P_LVALUE_120);
    *P_LVALUE_120 = PrtCloneValue((&P_EVENT_PConfigureEvent.value));
    
    PRT_VALUE** P_LVALUE_121 = &(PTMP_tmp10_1);
    PrtFreeValue(*P_LVALUE_121);
    *P_LVALUE_121 = PrtCloneValue((p_this->id));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp8_1), PTMP_tmp9_1, 1, &(PTMP_tmp10_1));
    *(&(PTMP_tmp9_1)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_20;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_20;
    }
    
    PRT_VALUE** P_LVALUE_122 = &(PTMP_tmp11_1);
    PrtFreeValue(*P_LVALUE_122);
    *P_LVALUE_122 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
    
    PrtRaise(p_this, PTMP_tmp11_1, 0);
    *(&(PTMP_tmp11_1)) = NULL;
    goto p_return_20;
    
p_return_20: ;
    PrtFreeValue(PTMP_tmp0_18); PTMP_tmp0_18 = NULL;
    PrtFreeValue(PTMP_tmp1_13); PTMP_tmp1_13 = NULL;
    PrtFreeValue(PTMP_tmp2_11); PTMP_tmp2_11 = NULL;
    PrtFreeValue(PTMP_tmp3_9); PTMP_tmp3_9 = NULL;
    PrtFreeValue(PTMP_tmp4_7); PTMP_tmp4_7 = NULL;
    PrtFreeValue(PTMP_tmp5_4); PTMP_tmp5_4 = NULL;
    PrtFreeValue(PTMP_tmp6_4); PTMP_tmp6_4 = NULL;
    PrtFreeValue(PTMP_tmp7_2); PTMP_tmp7_2 = NULL;
    PrtFreeValue(PTMP_tmp8_1); PTMP_tmp8_1 = NULL;
    PrtFreeValue(PTMP_tmp9_1); PTMP_tmp9_1 = NULL;
    PrtFreeValue(PTMP_tmp10_1); PTMP_tmp10_1 = NULL;
    PrtFreeValue(PTMP_tmp11_1); PTMP_tmp11_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_13 =
{
    NULL,
    &P_Anon_IMPL_13,
    &P_GEND_TYPE_T3iSmm
};


PRT_VALUE* P_Anon_IMPL_14(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_19 = NULL;
    PRT_VALUE* PTMP_tmp1_14 = NULL;
    PRT_VALUE* PTMP_tmp2_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_15 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_123 = &(PTMP_tmp0_19);
    PrtFreeValue(*P_LVALUE_123);
    *P_LVALUE_123 = PrtMkDefaultValue(&P_GEND_TYPE_m);
    
    {
        PRT_VALUE** P_LVALUE_124 = &(p_this->varValues[3]);
        PrtFreeValue(*P_LVALUE_124);
        *P_LVALUE_124 = PTMP_tmp0_19;
        PTMP_tmp0_19 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_125 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_125);
    *P_LVALUE_125 = PrtCloneValue((&P_LIT_INT32_15));
    
    PRT_VALUE** P_LVALUE_126 = &(PTMP_tmp1_14);
    PrtFreeValue(*P_LVALUE_126);
    *P_LVALUE_126 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_127 = &(PTMP_tmp2_12);
    PrtFreeValue(*P_LVALUE_127);
    *P_LVALUE_127 = PrtCloneValue((&P_EVENT_EStartTimer.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_14), PTMP_tmp2_12, 0);
    *(&(PTMP_tmp2_12)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_21;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_21;
    }
    
p_return_21: ;
    PrtFreeValue(PTMP_tmp0_19); PTMP_tmp0_19 = NULL;
    PrtFreeValue(PTMP_tmp1_14); PTMP_tmp1_14 = NULL;
    PrtFreeValue(PTMP_tmp2_12); PTMP_tmp2_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_14 =
{
    NULL,
    &P_Anon_IMPL_14,
    NULL
};


PRT_VALUE* P_Anon_IMPL_15(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_20 = NULL;
    PRT_VALUE* PTMP_tmp1_15 = NULL;
    PRT_VALUE* PTMP_tmp2_13 = NULL;
    PRT_VALUE* PTMP_tmp3_10 = NULL;
    PRT_VALUE* PTMP_tmp4_8 = NULL;
    PRT_VALUE* PTMP_tmp5_5 = NULL;
    PRT_VALUE* PTMP_tmp6_5 = NULL;
    PRT_VALUE* PTMP_tmp7_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_128 = &(PTMP_tmp0_20);
    PrtFreeValue(*P_LVALUE_128);
    *P_LVALUE_128 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[3], (&_P_GEN_null)));
    
    if (PrtPrimGetBool(PTMP_tmp0_20))
    {
        PRT_VALUE** P_LVALUE_129 = &(PTMP_tmp1_15);
        PrtFreeValue(*P_LVALUE_129);
        *P_LVALUE_129 = PrtCloneValue(p_this->varValues[3]);
        
        PRT_VALUE** P_LVALUE_130 = &(PTMP_tmp2_13);
        PrtFreeValue(*P_LVALUE_130);
        *P_LVALUE_130 = PrtCloneValue((&P_EVENT_Request.value));
        
        PRT_VALUE** P_LVALUE_131 = &(PTMP_tmp3_10);
        PrtFreeValue(*P_LVALUE_131);
        *P_LVALUE_131 = PrtTupleGet(*P_VAR_payload_10, 0);
        
        PRT_VALUE** P_LVALUE_132 = &(PTMP_tmp4_8);
        PrtFreeValue(*P_LVALUE_132);
        *P_LVALUE_132 = PrtTupleGet(*P_VAR_payload_10, 1);
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_15), PTMP_tmp2_13, 2, &(PTMP_tmp3_10), &(PTMP_tmp4_8));
        *(&(PTMP_tmp2_13)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_22;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_22;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_133 = &(PTMP_tmp5_5);
        PrtFreeValue(*P_LVALUE_133);
        *P_LVALUE_133 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_134 = &(PTMP_tmp6_5);
        PrtFreeValue(*P_LVALUE_134);
        *P_LVALUE_134 = PrtCloneValue((&P_EVENT_RedirectRequest.value));
        
        PRT_VALUE** P_LVALUE_135 = &(PTMP_tmp7_3);
        PrtFreeValue(*P_LVALUE_135);
        *P_LVALUE_135 = PrtCloneValue(*P_VAR_payload_10);
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp5_5), PTMP_tmp6_5, 1, &(PTMP_tmp7_3));
        *(&(PTMP_tmp6_5)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_22;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_22;
        }
        
    }
    
    
p_return_22: ;
    PrtFreeValue(PTMP_tmp0_20); PTMP_tmp0_20 = NULL;
    PrtFreeValue(PTMP_tmp1_15); PTMP_tmp1_15 = NULL;
    PrtFreeValue(PTMP_tmp2_13); PTMP_tmp2_13 = NULL;
    PrtFreeValue(PTMP_tmp3_10); PTMP_tmp3_10 = NULL;
    PrtFreeValue(PTMP_tmp4_8); PTMP_tmp4_8 = NULL;
    PrtFreeValue(PTMP_tmp5_5); PTMP_tmp5_5 = NULL;
    PrtFreeValue(PTMP_tmp6_5); PTMP_tmp6_5 = NULL;
    PrtFreeValue(PTMP_tmp7_3); PTMP_tmp7_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_15 =
{
    NULL,
    &P_Anon_IMPL_15,
    &P_GEND_TYPE_T2mi_1
};


PRT_VALUE* P_Anon_IMPL_16(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_11 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_21 = NULL;
    PRT_VALUE* PTMP_tmp1_16 = NULL;
    PRT_VALUE* PTMP_tmp2_14 = NULL;
    PRT_VALUE* PTMP_tmp3_11 = NULL;
    PRT_VALUE* PTMP_tmp4_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_136 = &(PTMP_tmp0_21);
    PrtFreeValue(*P_LVALUE_136);
    *P_LVALUE_136 = PrtTupleGet(*P_VAR_payload_11, 0);
    
    PRT_VALUE** P_LVALUE_137 = &(PTMP_tmp1_16);
    PrtFreeValue(*P_LVALUE_137);
    *P_LVALUE_137 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_21) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_16))
    {
        PRT_VALUE** P_LVALUE_138 = &(PTMP_tmp2_14);
        PrtFreeValue(*P_LVALUE_138);
        *P_LVALUE_138 = PrtTupleGet(*P_VAR_payload_11, 0);
        
        {
            PRT_VALUE** P_LVALUE_139 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_139);
            *P_LVALUE_139 = PTMP_tmp2_14;
            PTMP_tmp2_14 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_140 = &(PTMP_tmp3_11);
        PrtFreeValue(*P_LVALUE_140);
        *P_LVALUE_140 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_141 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_141);
            *P_LVALUE_141 = PTMP_tmp3_11;
            PTMP_tmp3_11 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_142 = &(PTMP_tmp4_9);
    PrtFreeValue(*P_LVALUE_142);
    *P_LVALUE_142 = PrtCloneValue(*P_VAR_payload_11);
    
    _P_GEN_funargs[0] = &(PTMP_tmp4_9);
    PrtFreeValue(P_Vote_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp4_9);
    PTMP_tmp4_9 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_23;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_23;
    }
    
p_return_23: ;
    PrtFreeValue(PTMP_tmp0_21); PTMP_tmp0_21 = NULL;
    PrtFreeValue(PTMP_tmp1_16); PTMP_tmp1_16 = NULL;
    PrtFreeValue(PTMP_tmp2_14); PTMP_tmp2_14 = NULL;
    PrtFreeValue(PTMP_tmp3_11); PTMP_tmp3_11 = NULL;
    PrtFreeValue(PTMP_tmp4_9); PTMP_tmp4_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_16 =
{
    NULL,
    &P_Anon_IMPL_16,
    &P_GEND_TYPE_T4imii
};


PRT_VALUE* P_Anon_IMPL_17(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_1 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_22 = NULL;
    PRT_VALUE* PTMP_tmp1_17 = NULL;
    PRT_VALUE* PTMP_tmp2_15 = NULL;
    PRT_VALUE* PTMP_tmp3_12 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_143 = &(PTMP_tmp0_22);
    PrtFreeValue(*P_LVALUE_143);
    *P_LVALUE_143 = PrtTupleGet(*P_VAR_request_1, 0);
    
    PRT_VALUE** P_LVALUE_144 = &(PTMP_tmp1_17);
    PrtFreeValue(*P_LVALUE_144);
    *P_LVALUE_144 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_22) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_17))
    {
        PRT_VALUE** P_LVALUE_145 = &(PTMP_tmp2_15);
        PrtFreeValue(*P_LVALUE_145);
        *P_LVALUE_145 = PrtTupleGet(*P_VAR_request_1, 0);
        
        {
            PRT_VALUE** P_LVALUE_146 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_146);
            *P_LVALUE_146 = PTMP_tmp2_15;
            PTMP_tmp2_15 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_147 = &(PTMP_tmp3_12);
        PrtFreeValue(*P_LVALUE_147);
        *P_LVALUE_147 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_148 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_148);
            *P_LVALUE_148 = PTMP_tmp3_12;
            PTMP_tmp3_12 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
p_return_24: ;
    PrtFreeValue(PTMP_tmp0_22); PTMP_tmp0_22 = NULL;
    PrtFreeValue(PTMP_tmp1_17); PTMP_tmp1_17 = NULL;
    PrtFreeValue(PTMP_tmp2_15); PTMP_tmp2_15 = NULL;
    PrtFreeValue(PTMP_tmp3_12); PTMP_tmp3_12 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_17 =
{
    NULL,
    &P_Anon_IMPL_17,
    &P_GEND_TYPE_T2ib
};


PRT_VALUE* P_Anon_IMPL_18(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_2 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_23 = NULL;
    PRT_VALUE* PTMP_tmp1_18 = NULL;
    PRT_VALUE* PTMP_tmp2_16 = NULL;
    PRT_VALUE* PTMP_tmp3_13 = NULL;
    PRT_VALUE* PTMP_tmp4_10 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_149 = &(PTMP_tmp0_23);
    PrtFreeValue(*P_LVALUE_149);
    *P_LVALUE_149 = PrtTupleGet(*P_VAR_request_2, 0);
    
    PRT_VALUE** P_LVALUE_150 = &(PTMP_tmp1_18);
    PrtFreeValue(*P_LVALUE_150);
    *P_LVALUE_150 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_23) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_18))
    {
        PRT_VALUE** P_LVALUE_151 = &(PTMP_tmp2_16);
        PrtFreeValue(*P_LVALUE_151);
        *P_LVALUE_151 = PrtTupleGet(*P_VAR_request_2, 0);
        
        {
            PRT_VALUE** P_LVALUE_152 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_152);
            *P_LVALUE_152 = PTMP_tmp2_16;
            PTMP_tmp2_16 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_153 = &(PTMP_tmp3_13);
        PrtFreeValue(*P_LVALUE_153);
        *P_LVALUE_153 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_154 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_154);
            *P_LVALUE_154 = PTMP_tmp3_13;
            PTMP_tmp3_13 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
    PRT_VALUE** P_LVALUE_155 = &(PTMP_tmp4_10);
    PrtFreeValue(*P_LVALUE_155);
    *P_LVALUE_155 = PrtCloneValue(*P_VAR_request_2);
    
    _P_GEN_funargs[0] = &(PTMP_tmp4_10);
    PrtFreeValue(P_AppendEntries_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp4_10);
    PTMP_tmp4_10 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_25;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_25;
    }
    
p_return_25: ;
    PrtFreeValue(PTMP_tmp0_23); PTMP_tmp0_23 = NULL;
    PrtFreeValue(PTMP_tmp1_18); PTMP_tmp1_18 = NULL;
    PrtFreeValue(PTMP_tmp2_16); PTMP_tmp2_16 = NULL;
    PrtFreeValue(PTMP_tmp3_13); PTMP_tmp3_13 = NULL;
    PrtFreeValue(PTMP_tmp4_10); PTMP_tmp4_10 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_18 =
{
    NULL,
    &P_Anon_IMPL_18,
    &P_GEND_TYPE_T7imiiST2iiim
};


PRT_VALUE* P_Anon_IMPL_19(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_3 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_24 = NULL;
    PRT_VALUE* PTMP_tmp1_19 = NULL;
    PRT_VALUE* PTMP_tmp2_17 = NULL;
    PRT_VALUE* PTMP_tmp3_14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_156 = &(PTMP_tmp0_24);
    PrtFreeValue(*P_LVALUE_156);
    *P_LVALUE_156 = PrtTupleGet(*P_VAR_request_3, 0);
    
    PRT_VALUE** P_LVALUE_157 = &(PTMP_tmp1_19);
    PrtFreeValue(*P_LVALUE_157);
    *P_LVALUE_157 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_24) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_19))
    {
        PRT_VALUE** P_LVALUE_158 = &(PTMP_tmp2_17);
        PrtFreeValue(*P_LVALUE_158);
        *P_LVALUE_158 = PrtTupleGet(*P_VAR_request_3, 0);
        
        {
            PRT_VALUE** P_LVALUE_159 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_159);
            *P_LVALUE_159 = PTMP_tmp2_17;
            PTMP_tmp2_17 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_160 = &(PTMP_tmp3_14);
        PrtFreeValue(*P_LVALUE_160);
        *P_LVALUE_160 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_161 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_161);
            *P_LVALUE_161 = PTMP_tmp3_14;
            PTMP_tmp3_14 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
p_return_26: ;
    PrtFreeValue(PTMP_tmp0_24); PTMP_tmp0_24 = NULL;
    PrtFreeValue(PTMP_tmp1_19); PTMP_tmp1_19 = NULL;
    PrtFreeValue(PTMP_tmp2_17); PTMP_tmp2_17 = NULL;
    PrtFreeValue(PTMP_tmp3_14); PTMP_tmp3_14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_19 =
{
    NULL,
    &P_Anon_IMPL_19,
    &P_GEND_TYPE_T4ibmm
};


PRT_VALUE* P_Anon_IMPL_20(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_25 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_162 = &(PTMP_tmp0_25);
    PrtFreeValue(*P_LVALUE_162);
    *P_LVALUE_162 = PrtCloneValue((&P_EVENT_BecomeCandidate.value));
    
    PrtRaise(p_this, PTMP_tmp0_25, 0);
    *(&(PTMP_tmp0_25)) = NULL;
    goto p_return_27;
    
p_return_27: ;
    PrtFreeValue(PTMP_tmp0_25); PTMP_tmp0_25 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_20 =
{
    NULL,
    &P_Anon_IMPL_20,
    NULL
};


PRT_VALUE* P_Anon_IMPL_21(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PrtFreeValue(P_ShuttingDown_IMPL_1(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_28;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_28;
    }
    
p_return_28: ;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_21 =
{
    NULL,
    &P_Anon_IMPL_21,
    NULL
};


PRT_VALUE* P_Anon_IMPL_22(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_26 = NULL;
    PRT_VALUE* PTMP_tmp1_20 = NULL;
    PRT_VALUE* PTMP_tmp2_18 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_16 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_163 = &(PTMP_tmp0_26);
    PrtFreeValue(*P_LVALUE_163);
    *P_LVALUE_163 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[6]) + PrtPrimGetInt((&P_LIT_INT32_16)));
    
    {
        PRT_VALUE** P_LVALUE_164 = &(p_this->varValues[6]);
        PrtFreeValue(*P_LVALUE_164);
        *P_LVALUE_164 = PTMP_tmp0_26;
        PTMP_tmp0_26 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_165 = &(p_this->varValues[7]);
    PrtFreeValue(*P_LVALUE_165);
    *P_LVALUE_165 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_166 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_166);
    *P_LVALUE_166 = PrtCloneValue((&P_LIT_INT32_16));
    
    PRT_VALUE** P_LVALUE_167 = &(PTMP_tmp1_20);
    PrtFreeValue(*P_LVALUE_167);
    *P_LVALUE_167 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_168 = &(PTMP_tmp2_18);
    PrtFreeValue(*P_LVALUE_168);
    *P_LVALUE_168 = PrtCloneValue((&P_EVENT_EStartTimer.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_20), PTMP_tmp2_18, 0);
    *(&(PTMP_tmp2_18)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_29;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_29;
    }
    
    PrtFreeValue(P_BroadcastVoteRequests_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_29;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_29;
    }
    
p_return_29: ;
    PrtFreeValue(PTMP_tmp0_26); PTMP_tmp0_26 = NULL;
    PrtFreeValue(PTMP_tmp1_20); PTMP_tmp1_20 = NULL;
    PrtFreeValue(PTMP_tmp2_18); PTMP_tmp2_18 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_22 =
{
    NULL,
    &P_Anon_IMPL_22,
    NULL
};


PRT_VALUE* P_Anon_IMPL_23(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_payload_12 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_27 = NULL;
    PRT_VALUE* PTMP_tmp1_21 = NULL;
    PRT_VALUE* PTMP_tmp2_19 = NULL;
    PRT_VALUE* PTMP_tmp3_15 = NULL;
    PRT_VALUE* PTMP_tmp4_11 = NULL;
    PRT_VALUE* PTMP_tmp5_6 = NULL;
    PRT_VALUE* PTMP_tmp6_6 = NULL;
    PRT_VALUE* PTMP_tmp7_4 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_169 = &(PTMP_tmp0_27);
    PrtFreeValue(*P_LVALUE_169);
    *P_LVALUE_169 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[3], (&_P_GEN_null)));
    
    if (PrtPrimGetBool(PTMP_tmp0_27))
    {
        PRT_VALUE** P_LVALUE_170 = &(PTMP_tmp1_21);
        PrtFreeValue(*P_LVALUE_170);
        *P_LVALUE_170 = PrtCloneValue(p_this->varValues[3]);
        
        PRT_VALUE** P_LVALUE_171 = &(PTMP_tmp2_19);
        PrtFreeValue(*P_LVALUE_171);
        *P_LVALUE_171 = PrtCloneValue((&P_EVENT_Request.value));
        
        PRT_VALUE** P_LVALUE_172 = &(PTMP_tmp3_15);
        PrtFreeValue(*P_LVALUE_172);
        *P_LVALUE_172 = PrtTupleGet(*P_VAR_payload_12, 0);
        
        PRT_VALUE** P_LVALUE_173 = &(PTMP_tmp4_11);
        PrtFreeValue(*P_LVALUE_173);
        *P_LVALUE_173 = PrtTupleGet(*P_VAR_payload_12, 1);
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_21), PTMP_tmp2_19, 2, &(PTMP_tmp3_15), &(PTMP_tmp4_11));
        *(&(PTMP_tmp2_19)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_30;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_30;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_174 = &(PTMP_tmp5_6);
        PrtFreeValue(*P_LVALUE_174);
        *P_LVALUE_174 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_175 = &(PTMP_tmp6_6);
        PrtFreeValue(*P_LVALUE_175);
        *P_LVALUE_175 = PrtCloneValue((&P_EVENT_RedirectRequest.value));
        
        PRT_VALUE** P_LVALUE_176 = &(PTMP_tmp7_4);
        PrtFreeValue(*P_LVALUE_176);
        *P_LVALUE_176 = PrtCloneValue(*P_VAR_payload_12);
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp5_6), PTMP_tmp6_6, 1, &(PTMP_tmp7_4));
        *(&(PTMP_tmp6_6)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_30;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_30;
        }
        
    }
    
    
p_return_30: ;
    PrtFreeValue(PTMP_tmp0_27); PTMP_tmp0_27 = NULL;
    PrtFreeValue(PTMP_tmp1_21); PTMP_tmp1_21 = NULL;
    PrtFreeValue(PTMP_tmp2_19); PTMP_tmp2_19 = NULL;
    PrtFreeValue(PTMP_tmp3_15); PTMP_tmp3_15 = NULL;
    PrtFreeValue(PTMP_tmp4_11); PTMP_tmp4_11 = NULL;
    PrtFreeValue(PTMP_tmp5_6); PTMP_tmp5_6 = NULL;
    PrtFreeValue(PTMP_tmp6_6); PTMP_tmp6_6 = NULL;
    PrtFreeValue(PTMP_tmp7_4); PTMP_tmp7_4 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_23 =
{
    NULL,
    &P_Anon_IMPL_23,
    &P_GEND_TYPE_T2mi_1
};


PRT_VALUE* P_Anon_IMPL_24(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_4 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_28 = NULL;
    PRT_VALUE* PTMP_tmp1_22 = NULL;
    PRT_VALUE* PTMP_tmp2_20 = NULL;
    PRT_VALUE* PTMP_tmp3_16 = NULL;
    PRT_VALUE* PTMP_tmp4_12 = NULL;
    PRT_VALUE* PTMP_tmp5_7 = NULL;
    PRT_VALUE* PTMP_tmp6_7 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_177 = &(PTMP_tmp0_28);
    PrtFreeValue(*P_LVALUE_177);
    *P_LVALUE_177 = PrtTupleGet(*P_VAR_request_4, 0);
    
    PRT_VALUE** P_LVALUE_178 = &(PTMP_tmp1_22);
    PrtFreeValue(*P_LVALUE_178);
    *P_LVALUE_178 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_28) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_22))
    {
        PRT_VALUE** P_LVALUE_179 = &(PTMP_tmp2_20);
        PrtFreeValue(*P_LVALUE_179);
        *P_LVALUE_179 = PrtTupleGet(*P_VAR_request_4, 0);
        
        {
            PRT_VALUE** P_LVALUE_180 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_180);
            *P_LVALUE_180 = PTMP_tmp2_20;
            PTMP_tmp2_20 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_181 = &(PTMP_tmp3_16);
        PrtFreeValue(*P_LVALUE_181);
        *P_LVALUE_181 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_182 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_182);
            *P_LVALUE_182 = PTMP_tmp3_16;
            PTMP_tmp3_16 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_183 = &(PTMP_tmp4_12);
        PrtFreeValue(*P_LVALUE_183);
        *P_LVALUE_183 = PrtCloneValue(*P_VAR_request_4);
        
        _P_GEN_funargs[0] = &(PTMP_tmp4_12);
        PrtFreeValue(P_Vote_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp4_12);
        PTMP_tmp4_12 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_31;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_31;
        }
        
        PRT_VALUE** P_LVALUE_184 = &(PTMP_tmp5_7);
        PrtFreeValue(*P_LVALUE_184);
        *P_LVALUE_184 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp5_7, 0);
        *(&(PTMP_tmp5_7)) = NULL;
        goto p_return_31;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_185 = &(PTMP_tmp6_7);
        PrtFreeValue(*P_LVALUE_185);
        *P_LVALUE_185 = PrtCloneValue(*P_VAR_request_4);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_7);
        PrtFreeValue(P_Vote_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_7);
        PTMP_tmp6_7 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_31;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_31;
        }
        
    }
    
    
p_return_31: ;
    PrtFreeValue(PTMP_tmp0_28); PTMP_tmp0_28 = NULL;
    PrtFreeValue(PTMP_tmp1_22); PTMP_tmp1_22 = NULL;
    PrtFreeValue(PTMP_tmp2_20); PTMP_tmp2_20 = NULL;
    PrtFreeValue(PTMP_tmp3_16); PTMP_tmp3_16 = NULL;
    PrtFreeValue(PTMP_tmp4_12); PTMP_tmp4_12 = NULL;
    PrtFreeValue(PTMP_tmp5_7); PTMP_tmp5_7 = NULL;
    PrtFreeValue(PTMP_tmp6_7); PTMP_tmp6_7 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_24 =
{
    NULL,
    &P_Anon_IMPL_24,
    &P_GEND_TYPE_T4imii
};


PRT_VALUE* P_Anon_IMPL_25(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_5 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_29 = NULL;
    PRT_VALUE* PTMP_tmp1_23 = NULL;
    PRT_VALUE* PTMP_tmp2_21 = NULL;
    PRT_VALUE* PTMP_tmp3_17 = NULL;
    PRT_VALUE* PTMP_tmp4_13 = NULL;
    PRT_VALUE* PTMP_tmp5_8 = NULL;
    PRT_VALUE* PTMP_tmp6_8 = NULL;
    PRT_VALUE* PTMP_tmp7_5 = NULL;
    PRT_VALUE* PTMP_tmp8_2 = NULL;
    PRT_VALUE* PTMP_tmp9_2 = NULL;
    PRT_VALUE* PTMP_tmp10_2 = NULL;
    PRT_VALUE* PTMP_tmp11_2 = NULL;
    PRT_VALUE* PTMP_tmp12_1 = NULL;
    PRT_VALUE* PTMP_tmp13_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_17 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_18 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_19 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE** P_LVALUE_186 = &(PTMP_tmp0_29);
    PrtFreeValue(*P_LVALUE_186);
    *P_LVALUE_186 = PrtTupleGet(*P_VAR_request_5, 0);
    
    PRT_VALUE** P_LVALUE_187 = &(PTMP_tmp1_23);
    PrtFreeValue(*P_LVALUE_187);
    *P_LVALUE_187 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_29) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_23))
    {
        PRT_VALUE** P_LVALUE_188 = &(PTMP_tmp2_21);
        PrtFreeValue(*P_LVALUE_188);
        *P_LVALUE_188 = PrtTupleGet(*P_VAR_request_5, 0);
        
        {
            PRT_VALUE** P_LVALUE_189 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_189);
            *P_LVALUE_189 = PTMP_tmp2_21;
            PTMP_tmp2_21 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_190 = &(PTMP_tmp3_17);
        PrtFreeValue(*P_LVALUE_190);
        *P_LVALUE_190 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_191 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_191);
            *P_LVALUE_191 = PTMP_tmp3_17;
            PTMP_tmp3_17 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_192 = &(PTMP_tmp4_13);
        PrtFreeValue(*P_LVALUE_192);
        *P_LVALUE_192 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp4_13, 0);
        *(&(PTMP_tmp4_13)) = NULL;
        goto p_return_32;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_193 = &(PTMP_tmp5_8);
        PrtFreeValue(*P_LVALUE_193);
        *P_LVALUE_193 = PrtTupleGet(*P_VAR_request_5, 0);
        
        PRT_VALUE** P_LVALUE_194 = &(PTMP_tmp6_8);
        PrtFreeValue(*P_LVALUE_194);
        *P_LVALUE_194 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp5_8, p_this->varValues[6]));
        
        if (PrtPrimGetBool(PTMP_tmp6_8))
        {
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_195 = &(PTMP_tmp7_5);
            PrtFreeValue(*P_LVALUE_195);
            *P_LVALUE_195 = PrtTupleGet(*P_VAR_request_5, 1);
            
            if (PrtPrimGetBool(PTMP_tmp7_5))
            {
                PRT_VALUE** P_LVALUE_196 = &(PTMP_tmp8_2);
                PrtFreeValue(*P_LVALUE_196);
                *P_LVALUE_196 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[13]) + PrtPrimGetInt((&P_LIT_INT32_17)));
                
                {
                    PRT_VALUE** P_LVALUE_197 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_197);
                    *P_LVALUE_197 = PTMP_tmp8_2;
                    PTMP_tmp8_2 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_198 = &(PTMP_tmp9_2);
                PrtFreeValue(*P_LVALUE_198);
                *P_LVALUE_198 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
                
                PRT_VALUE** P_LVALUE_199 = &(PTMP_tmp10_2);
                PrtFreeValue(*P_LVALUE_199);
                *P_LVALUE_199 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp9_2) / PrtPrimGetInt((&P_LIT_INT32_18)));
                
                PRT_VALUE** P_LVALUE_200 = &(PTMP_tmp11_2);
                PrtFreeValue(*P_LVALUE_200);
                *P_LVALUE_200 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp10_2) + PrtPrimGetInt((&P_LIT_INT32_17)));
                
                PRT_VALUE** P_LVALUE_201 = &(PTMP_tmp12_1);
                PrtFreeValue(*P_LVALUE_201);
                *P_LVALUE_201 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[13]) >= PrtPrimGetInt(PTMP_tmp11_2));
                
                if (PrtPrimGetBool(PTMP_tmp12_1))
                {
                    PRT_VALUE** P_LVALUE_202 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_202);
                    *P_LVALUE_202 = PrtCloneValue((&P_LIT_INT32_19));
                    
                    PRT_VALUE** P_LVALUE_203 = &(PTMP_tmp13_1);
                    PrtFreeValue(*P_LVALUE_203);
                    *P_LVALUE_203 = PrtCloneValue((&P_EVENT_BecomeLeader.value));
                    
                    PrtRaise(p_this, PTMP_tmp13_1, 0);
                    *(&(PTMP_tmp13_1)) = NULL;
                    goto p_return_32;
                    
                }
                
                else
                {
                }
                
                
            }
            
            else
            {
            }
            
            
        }
        
        
    }
    
    
p_return_32: ;
    PrtFreeValue(PTMP_tmp0_29); PTMP_tmp0_29 = NULL;
    PrtFreeValue(PTMP_tmp1_23); PTMP_tmp1_23 = NULL;
    PrtFreeValue(PTMP_tmp2_21); PTMP_tmp2_21 = NULL;
    PrtFreeValue(PTMP_tmp3_17); PTMP_tmp3_17 = NULL;
    PrtFreeValue(PTMP_tmp4_13); PTMP_tmp4_13 = NULL;
    PrtFreeValue(PTMP_tmp5_8); PTMP_tmp5_8 = NULL;
    PrtFreeValue(PTMP_tmp6_8); PTMP_tmp6_8 = NULL;
    PrtFreeValue(PTMP_tmp7_5); PTMP_tmp7_5 = NULL;
    PrtFreeValue(PTMP_tmp8_2); PTMP_tmp8_2 = NULL;
    PrtFreeValue(PTMP_tmp9_2); PTMP_tmp9_2 = NULL;
    PrtFreeValue(PTMP_tmp10_2); PTMP_tmp10_2 = NULL;
    PrtFreeValue(PTMP_tmp11_2); PTMP_tmp11_2 = NULL;
    PrtFreeValue(PTMP_tmp12_1); PTMP_tmp12_1 = NULL;
    PrtFreeValue(PTMP_tmp13_1); PTMP_tmp13_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_25 =
{
    NULL,
    &P_Anon_IMPL_25,
    &P_GEND_TYPE_T2ib
};


PRT_VALUE* P_Anon_IMPL_26(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_6 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_30 = NULL;
    PRT_VALUE* PTMP_tmp1_24 = NULL;
    PRT_VALUE* PTMP_tmp2_22 = NULL;
    PRT_VALUE* PTMP_tmp3_18 = NULL;
    PRT_VALUE* PTMP_tmp4_14 = NULL;
    PRT_VALUE* PTMP_tmp5_9 = NULL;
    PRT_VALUE* PTMP_tmp6_9 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_204 = &(PTMP_tmp0_30);
    PrtFreeValue(*P_LVALUE_204);
    *P_LVALUE_204 = PrtTupleGet(*P_VAR_request_6, 0);
    
    PRT_VALUE** P_LVALUE_205 = &(PTMP_tmp1_24);
    PrtFreeValue(*P_LVALUE_205);
    *P_LVALUE_205 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_30) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_24))
    {
        PRT_VALUE** P_LVALUE_206 = &(PTMP_tmp2_22);
        PrtFreeValue(*P_LVALUE_206);
        *P_LVALUE_206 = PrtTupleGet(*P_VAR_request_6, 0);
        
        {
            PRT_VALUE** P_LVALUE_207 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_207);
            *P_LVALUE_207 = PTMP_tmp2_22;
            PTMP_tmp2_22 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_208 = &(PTMP_tmp3_18);
        PrtFreeValue(*P_LVALUE_208);
        *P_LVALUE_208 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_209 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_209);
            *P_LVALUE_209 = PTMP_tmp3_18;
            PTMP_tmp3_18 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_210 = &(PTMP_tmp4_14);
        PrtFreeValue(*P_LVALUE_210);
        *P_LVALUE_210 = PrtCloneValue(*P_VAR_request_6);
        
        _P_GEN_funargs[0] = &(PTMP_tmp4_14);
        PrtFreeValue(P_AppendEntries_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp4_14);
        PTMP_tmp4_14 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_33;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_33;
        }
        
        PRT_VALUE** P_LVALUE_211 = &(PTMP_tmp5_9);
        PrtFreeValue(*P_LVALUE_211);
        *P_LVALUE_211 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp5_9, 0);
        *(&(PTMP_tmp5_9)) = NULL;
        goto p_return_33;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_212 = &(PTMP_tmp6_9);
        PrtFreeValue(*P_LVALUE_212);
        *P_LVALUE_212 = PrtCloneValue(*P_VAR_request_6);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_9);
        PrtFreeValue(P_AppendEntries_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_9);
        PTMP_tmp6_9 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_33;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_33;
        }
        
    }
    
    
p_return_33: ;
    PrtFreeValue(PTMP_tmp0_30); PTMP_tmp0_30 = NULL;
    PrtFreeValue(PTMP_tmp1_24); PTMP_tmp1_24 = NULL;
    PrtFreeValue(PTMP_tmp2_22); PTMP_tmp2_22 = NULL;
    PrtFreeValue(PTMP_tmp3_18); PTMP_tmp3_18 = NULL;
    PrtFreeValue(PTMP_tmp4_14); PTMP_tmp4_14 = NULL;
    PrtFreeValue(PTMP_tmp5_9); PTMP_tmp5_9 = NULL;
    PrtFreeValue(PTMP_tmp6_9); PTMP_tmp6_9 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_26 =
{
    NULL,
    &P_Anon_IMPL_26,
    &P_GEND_TYPE_T7imiiST2iiim
};


PRT_VALUE* P_Anon_IMPL_27(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_7 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_31 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_213 = &(PTMP_tmp0_31);
    PrtFreeValue(*P_LVALUE_213);
    *P_LVALUE_213 = PrtCloneValue(*P_VAR_request_7);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_31);
    PrtFreeValue(P_RespondAppendEntriesAsCandidate_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_31);
    PTMP_tmp0_31 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_34;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_34;
    }
    
p_return_34: ;
    PrtFreeValue(PTMP_tmp0_31); PTMP_tmp0_31 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_27 =
{
    NULL,
    &P_Anon_IMPL_27,
    &P_GEND_TYPE_T4ibmm
};


PRT_VALUE* P_Anon_IMPL_28(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_32 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_214 = &(PTMP_tmp0_32);
    PrtFreeValue(*P_LVALUE_214);
    *P_LVALUE_214 = PrtCloneValue((&P_EVENT_BecomeCandidate.value));
    
    PrtRaise(p_this, PTMP_tmp0_32, 0);
    *(&(PTMP_tmp0_32)) = NULL;
    goto p_return_35;
    
p_return_35: ;
    PrtFreeValue(PTMP_tmp0_32); PTMP_tmp0_32 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_28 =
{
    NULL,
    &P_Anon_IMPL_28,
    NULL
};


PRT_VALUE* P_BroadcastVoteRequests_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_idx_3 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_lastLogIndex = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_lastLogTerm = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_33 = NULL;
    PRT_VALUE* PTMP_tmp1_25 = NULL;
    PRT_VALUE* PTMP_tmp2_23 = NULL;
    PRT_VALUE* PTMP_tmp3_19 = NULL;
    PRT_VALUE* PTMP_tmp4_15 = NULL;
    PRT_VALUE* PTMP_tmp5_10 = NULL;
    PRT_VALUE* PTMP_tmp6_10 = NULL;
    PRT_VALUE* PTMP_tmp7_6 = NULL;
    PRT_VALUE* PTMP_tmp8_3 = NULL;
    PRT_VALUE* PTMP_tmp9_3 = NULL;
    PRT_VALUE* PTMP_tmp10_3 = NULL;
    PRT_VALUE* PTMP_tmp11_3 = NULL;
    PRT_VALUE* PTMP_tmp12_2 = NULL;
    PRT_VALUE* PTMP_tmp13_2 = NULL;
    PRT_VALUE* PTMP_tmp14 = NULL;
    PRT_VALUE* PTMP_tmp15 = NULL;
    PRT_VALUE* PTMP_tmp16 = NULL;
    PRT_VALUE* PTMP_tmp17 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_20 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_21 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_5 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_215 = &(PTMP_tmp0_33);
    PrtFreeValue(*P_LVALUE_215);
    *P_LVALUE_215 = PrtCloneValue(p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_216 = &(PTMP_tmp1_25);
    PrtFreeValue(*P_LVALUE_216);
    *P_LVALUE_216 = PrtCloneValue((&P_EVENT_PStartTimer.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_33), PTMP_tmp1_25, 0);
    *(&(PTMP_tmp1_25)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_36;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_36;
    }
    
    PRT_VALUE** P_LVALUE_217 = &(P_VAR_idx_3);
    PrtFreeValue(*P_LVALUE_217);
    *P_LVALUE_217 = PrtCloneValue((&P_LIT_INT32_20));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_5)))
    {
        PRT_VALUE** P_LVALUE_218 = &(PTMP_tmp2_23);
        PrtFreeValue(*P_LVALUE_218);
        *P_LVALUE_218 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
        
        PRT_VALUE** P_LVALUE_219 = &(PTMP_tmp3_19);
        PrtFreeValue(*P_LVALUE_219);
        *P_LVALUE_219 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_3) < PrtPrimGetInt(PTMP_tmp2_23));
        
        PRT_VALUE** P_LVALUE_220 = &(PTMP_tmp4_15);
        PrtFreeValue(*P_LVALUE_220);
        *P_LVALUE_220 = PrtCloneValue(PTMP_tmp3_19);
        
        if (PrtPrimGetBool(PTMP_tmp4_15))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_221 = &(PTMP_tmp5_10);
        PrtFreeValue(*P_LVALUE_221);
        *P_LVALUE_221 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_idx_3, p_this->varValues[0]));
        
        if (PrtPrimGetBool(PTMP_tmp5_10))
        {
            continue;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_222 = &(PTMP_tmp6_10);
        PrtFreeValue(*P_LVALUE_222);
        *P_LVALUE_222 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
        
        {
            PRT_VALUE** P_LVALUE_223 = &(P_VAR_lastLogIndex);
            PrtFreeValue(*P_LVALUE_223);
            *P_LVALUE_223 = PTMP_tmp6_10;
            PTMP_tmp6_10 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_224 = &(PTMP_tmp7_6);
        PrtFreeValue(*P_LVALUE_224);
        *P_LVALUE_224 = PrtCloneValue(P_VAR_lastLogIndex);
        
        PRT_VALUE** P_LVALUE_225 = &(PTMP_tmp8_3);
        PrtFreeValue(*P_LVALUE_225);
        *P_LVALUE_225 = ((_P_GEN_funargs[0] = &(PTMP_tmp7_6)), (_P_GEN_funval = P_GetLogTermForIndex_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp7_6), PTMP_tmp7_6 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_36;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_36;
        }
        
        {
            PRT_VALUE** P_LVALUE_226 = &(P_VAR_lastLogTerm);
            PrtFreeValue(*P_LVALUE_226);
            *P_LVALUE_226 = PTMP_tmp8_3;
            PTMP_tmp8_3 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_227 = &(PTMP_tmp9_3);
        PrtFreeValue(*P_LVALUE_227);
        *P_LVALUE_227 = PrtSeqGet(p_this->varValues[2], P_VAR_idx_3);
        
        PRT_VALUE** P_LVALUE_228 = &(PTMP_tmp10_3);
        PrtFreeValue(*P_LVALUE_228);
        *P_LVALUE_228 = PrtCloneValue(PTMP_tmp9_3);
        
        PRT_VALUE** P_LVALUE_229 = &(PTMP_tmp11_3);
        PrtFreeValue(*P_LVALUE_229);
        *P_LVALUE_229 = PrtCloneValue((&P_EVENT_VoteRequest.value));
        
        PRT_VALUE** P_LVALUE_230 = &(PTMP_tmp12_2);
        PrtFreeValue(*P_LVALUE_230);
        *P_LVALUE_230 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_231 = &(PTMP_tmp13_2);
        PrtFreeValue(*P_LVALUE_231);
        *P_LVALUE_231 = PrtCloneValue((p_this->id));
        
        PRT_VALUE** P_LVALUE_232 = &(PTMP_tmp14);
        PrtFreeValue(*P_LVALUE_232);
        *P_LVALUE_232 = PrtCloneValue(P_VAR_lastLogIndex);
        
        PRT_VALUE** P_LVALUE_233 = &(PTMP_tmp15);
        PrtFreeValue(*P_LVALUE_233);
        *P_LVALUE_233 = PrtCloneValue(P_VAR_lastLogTerm);
        
        PRT_VALUE** P_LVALUE_234 = &(PTMP_tmp16);
        PrtFreeValue(*P_LVALUE_234);
        *P_LVALUE_234 = (PrtMkTuple(&P_GEND_TYPE_T4iRii, &(PTMP_tmp12_2), &(PTMP_tmp13_2), &(PTMP_tmp14), &(PTMP_tmp15)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp10_3), PTMP_tmp11_3, 1, &(PTMP_tmp16));
        *(&(PTMP_tmp11_3)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_36;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_36;
        }
        
        PRT_VALUE** P_LVALUE_235 = &(PTMP_tmp17);
        PrtFreeValue(*P_LVALUE_235);
        *P_LVALUE_235 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_3) + PrtPrimGetInt((&P_LIT_INT32_21)));
        
        {
            PRT_VALUE** P_LVALUE_236 = &(P_VAR_idx_3);
            PrtFreeValue(*P_LVALUE_236);
            *P_LVALUE_236 = PTMP_tmp17;
            PTMP_tmp17 = NULL;
        }
        
    }
    
    
p_return_36: ;
    PrtFreeValue(P_VAR_idx_3); P_VAR_idx_3 = NULL;
    PrtFreeValue(P_VAR_lastLogIndex); P_VAR_lastLogIndex = NULL;
    PrtFreeValue(P_VAR_lastLogTerm); P_VAR_lastLogTerm = NULL;
    PrtFreeValue(PTMP_tmp0_33); PTMP_tmp0_33 = NULL;
    PrtFreeValue(PTMP_tmp1_25); PTMP_tmp1_25 = NULL;
    PrtFreeValue(PTMP_tmp2_23); PTMP_tmp2_23 = NULL;
    PrtFreeValue(PTMP_tmp3_19); PTMP_tmp3_19 = NULL;
    PrtFreeValue(PTMP_tmp4_15); PTMP_tmp4_15 = NULL;
    PrtFreeValue(PTMP_tmp5_10); PTMP_tmp5_10 = NULL;
    PrtFreeValue(PTMP_tmp6_10); PTMP_tmp6_10 = NULL;
    PrtFreeValue(PTMP_tmp7_6); PTMP_tmp7_6 = NULL;
    PrtFreeValue(PTMP_tmp8_3); PTMP_tmp8_3 = NULL;
    PrtFreeValue(PTMP_tmp9_3); PTMP_tmp9_3 = NULL;
    PrtFreeValue(PTMP_tmp10_3); PTMP_tmp10_3 = NULL;
    PrtFreeValue(PTMP_tmp11_3); PTMP_tmp11_3 = NULL;
    PrtFreeValue(PTMP_tmp12_2); PTMP_tmp12_2 = NULL;
    PrtFreeValue(PTMP_tmp13_2); PTMP_tmp13_2 = NULL;
    PrtFreeValue(PTMP_tmp14); PTMP_tmp14 = NULL;
    PrtFreeValue(PTMP_tmp15); PTMP_tmp15 = NULL;
    PrtFreeValue(PTMP_tmp16); PTMP_tmp16 = NULL;
    PrtFreeValue(PTMP_tmp17); PTMP_tmp17 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_BroadcastVoteRequests =
{
    "BroadcastVoteRequests",
    &P_BroadcastVoteRequests_IMPL,
    NULL
};


PRT_VALUE* P_RespondAppendEntriesAsCandidate_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_8 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_34 = NULL;
    PRT_VALUE* PTMP_tmp1_26 = NULL;
    PRT_VALUE* PTMP_tmp2_24 = NULL;
    PRT_VALUE* PTMP_tmp3_20 = NULL;
    PRT_VALUE* PTMP_tmp4_16 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_237 = &(PTMP_tmp0_34);
    PrtFreeValue(*P_LVALUE_237);
    *P_LVALUE_237 = PrtTupleGet(*P_VAR_request_8, 0);
    
    PRT_VALUE** P_LVALUE_238 = &(PTMP_tmp1_26);
    PrtFreeValue(*P_LVALUE_238);
    *P_LVALUE_238 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_34) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_26))
    {
        PRT_VALUE** P_LVALUE_239 = &(PTMP_tmp2_24);
        PrtFreeValue(*P_LVALUE_239);
        *P_LVALUE_239 = PrtTupleGet(*P_VAR_request_8, 0);
        
        {
            PRT_VALUE** P_LVALUE_240 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_240);
            *P_LVALUE_240 = PTMP_tmp2_24;
            PTMP_tmp2_24 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_241 = &(PTMP_tmp3_20);
        PrtFreeValue(*P_LVALUE_241);
        *P_LVALUE_241 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_242 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_242);
            *P_LVALUE_242 = PTMP_tmp3_20;
            PTMP_tmp3_20 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_243 = &(PTMP_tmp4_16);
        PrtFreeValue(*P_LVALUE_243);
        *P_LVALUE_243 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp4_16, 0);
        *(&(PTMP_tmp4_16)) = NULL;
        goto p_return_37;
        
    }
    
    else
    {
    }
    
    
p_return_37: ;
    PrtFreeValue(PTMP_tmp0_34); PTMP_tmp0_34 = NULL;
    PrtFreeValue(PTMP_tmp1_26); PTMP_tmp1_26 = NULL;
    PrtFreeValue(PTMP_tmp2_24); PTMP_tmp2_24 = NULL;
    PrtFreeValue(PTMP_tmp3_20); PTMP_tmp3_20 = NULL;
    PrtFreeValue(PTMP_tmp4_16); PTMP_tmp4_16 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RespondAppendEntriesAsCandidate =
{
    "RespondAppendEntriesAsCandidate",
    &P_RespondAppendEntriesAsCandidate_IMPL,
    NULL
};


PRT_VALUE* P_Anon_IMPL_29(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_logIndex = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_logTerm = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_idx_4 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_35 = NULL;
    PRT_VALUE* PTMP_tmp1_27 = NULL;
    PRT_VALUE* PTMP_tmp2_25 = NULL;
    PRT_VALUE* PTMP_tmp3_21 = NULL;
    PRT_VALUE* PTMP_tmp4_17 = NULL;
    PRT_VALUE* PTMP_tmp5_11 = NULL;
    PRT_VALUE* PTMP_tmp6_11 = NULL;
    PRT_VALUE* PTMP_tmp7_7 = NULL;
    PRT_VALUE* PTMP_tmp8_4 = NULL;
    PRT_VALUE* PTMP_tmp9_4 = NULL;
    PRT_VALUE* PTMP_tmp10_4 = NULL;
    PRT_VALUE* PTMP_tmp11_4 = NULL;
    PRT_VALUE* PTMP_tmp12_3 = NULL;
    PRT_VALUE* PTMP_tmp13_3 = NULL;
    PRT_VALUE* PTMP_tmp14_1 = NULL;
    PRT_VALUE* PTMP_tmp15_1 = NULL;
    PRT_VALUE* PTMP_tmp16_1 = NULL;
    PRT_VALUE* PTMP_tmp17_1 = NULL;
    PRT_VALUE* PTMP_tmp18 = NULL;
    PRT_VALUE* PTMP_tmp19 = NULL;
    PRT_VALUE* PTMP_tmp20 = NULL;
    PRT_VALUE* PTMP_tmp21 = NULL;
    PRT_VALUE* PTMP_tmp22 = NULL;
    PRT_VALUE* PTMP_tmp23 = NULL;
    PRT_VALUE* PTMP_tmp24 = NULL;
    PRT_VALUE* PTMP_tmp25 = NULL;
    PRT_VALUE* PTMP_tmp26 = NULL;
    PRT_VALUE* PTMP_tmp27 = NULL;
    PRT_VALUE* PTMP_tmp28 = NULL;
    PRT_VALUE* PTMP_tmp29 = NULL;
    PRT_VALUE* PTMP_tmp30 = NULL;
    PRT_VALUE* PTMP_tmp31 = NULL;
    PRT_VALUE* PTMP_tmp32 = NULL;
    PRT_VALUE* PTMP_tmp33 = NULL;
    PRT_VALUE* PTMP_tmp34 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_22 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_23 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_6 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_244 = &(PTMP_tmp0_35);
    PrtFreeValue(*P_LVALUE_244);
    *P_LVALUE_244 = PrtCloneValue((&P_EVENT_NotifyLeaderElected.value));
    
    PRT_VALUE** P_LVALUE_245 = &(PTMP_tmp1_27);
    PrtFreeValue(*P_LVALUE_245);
    *P_LVALUE_245 = PrtCloneValue(p_this->varValues[6]);
    
    PRT_VALUE** P_LVALUE_246 = &(PTMP_tmp2_25);
    PrtFreeValue(*P_LVALUE_246);
    *P_LVALUE_246 = (PrtMkTuple(&P_GEND_TYPE_T2ei, &(PTMP_tmp0_35), &(PTMP_tmp1_27)));
    
    
    PRT_VALUE** P_LVALUE_247 = &(PTMP_tmp3_21);
    PrtFreeValue(*P_LVALUE_247);
    *P_LVALUE_247 = PrtCloneValue(p_this->varValues[1]);
    
    PRT_VALUE** P_LVALUE_248 = &(PTMP_tmp4_17);
    PrtFreeValue(*P_LVALUE_248);
    *P_LVALUE_248 = PrtCloneValue((&P_EVENT_NotifyLeaderUpdate.value));
    
    PRT_VALUE** P_LVALUE_249 = &(PTMP_tmp5_11);
    PrtFreeValue(*P_LVALUE_249);
    *P_LVALUE_249 = PrtCloneValue((p_this->id));
    
    PRT_VALUE** P_LVALUE_250 = &(PTMP_tmp6_11);
    PrtFreeValue(*P_LVALUE_250);
    *P_LVALUE_250 = PrtCloneValue(p_this->varValues[6]);
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_21), PTMP_tmp4_17, 2, &(PTMP_tmp5_11), &(PTMP_tmp6_11));
    *(&(PTMP_tmp4_17)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_38;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_38;
    }
    
    PRT_VALUE** P_LVALUE_251 = &(PTMP_tmp7_7);
    PrtFreeValue(*P_LVALUE_251);
    *P_LVALUE_251 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
    
    {
        PRT_VALUE** P_LVALUE_252 = &(P_VAR_logIndex);
        PrtFreeValue(*P_LVALUE_252);
        *P_LVALUE_252 = PTMP_tmp7_7;
        PTMP_tmp7_7 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_253 = &(PTMP_tmp8_4);
    PrtFreeValue(*P_LVALUE_253);
    *P_LVALUE_253 = PrtCloneValue(P_VAR_logIndex);
    
    PRT_VALUE** P_LVALUE_254 = &(PTMP_tmp9_4);
    PrtFreeValue(*P_LVALUE_254);
    *P_LVALUE_254 = ((_P_GEN_funargs[0] = &(PTMP_tmp8_4)), (_P_GEN_funval = P_GetLogTermForIndex_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp8_4), PTMP_tmp8_4 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_38;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_38;
    }
    
    {
        PRT_VALUE** P_LVALUE_255 = &(P_VAR_logTerm);
        PrtFreeValue(*P_LVALUE_255);
        *P_LVALUE_255 = PTMP_tmp9_4;
        PTMP_tmp9_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_256 = &(PTMP_tmp10_4);
    PrtFreeValue(*P_LVALUE_256);
    *P_LVALUE_256 = PrtMkDefaultValue(&P_GEND_TYPE_MKmVi);
    
    {
        PRT_VALUE** P_LVALUE_257 = &(p_this->varValues[11]);
        PrtFreeValue(*P_LVALUE_257);
        *P_LVALUE_257 = PTMP_tmp10_4;
        PTMP_tmp10_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_258 = &(PTMP_tmp11_4);
    PrtFreeValue(*P_LVALUE_258);
    *P_LVALUE_258 = PrtMkDefaultValue(&P_GEND_TYPE_MKmVi);
    
    {
        PRT_VALUE** P_LVALUE_259 = &(p_this->varValues[12]);
        PrtFreeValue(*P_LVALUE_259);
        *P_LVALUE_259 = PTMP_tmp11_4;
        PTMP_tmp11_4 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_260 = &(P_VAR_idx_4);
    PrtFreeValue(*P_LVALUE_260);
    *P_LVALUE_260 = PrtCloneValue((&P_LIT_INT32_22));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
    {
        PRT_VALUE** P_LVALUE_261 = &(PTMP_tmp12_3);
        PrtFreeValue(*P_LVALUE_261);
        *P_LVALUE_261 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
        
        PRT_VALUE** P_LVALUE_262 = &(PTMP_tmp13_3);
        PrtFreeValue(*P_LVALUE_262);
        *P_LVALUE_262 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_4) < PrtPrimGetInt(PTMP_tmp12_3));
        
        PRT_VALUE** P_LVALUE_263 = &(PTMP_tmp14_1);
        PrtFreeValue(*P_LVALUE_263);
        *P_LVALUE_263 = PrtCloneValue(PTMP_tmp13_3);
        
        if (PrtPrimGetBool(PTMP_tmp14_1))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_264 = &(PTMP_tmp15_1);
        PrtFreeValue(*P_LVALUE_264);
        *P_LVALUE_264 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_idx_4, p_this->varValues[0]));
        
        if (PrtPrimGetBool(PTMP_tmp15_1))
        {
            continue;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_265 = &(PTMP_tmp16_1);
        PrtFreeValue(*P_LVALUE_265);
        *P_LVALUE_265 = PrtSeqGet(p_this->varValues[2], P_VAR_idx_4);
        
        PRT_VALUE** P_LVALUE_266 = &(PTMP_tmp17_1);
        PrtFreeValue(*P_LVALUE_266);
        *P_LVALUE_266 = PrtMkIntValue(PrtPrimGetInt(P_VAR_logIndex) + PrtPrimGetInt((&P_LIT_INT32_23)));
        
        {
            PRT_VALUE** P_LVALUE_267 = &(*(PrtMapGetLValue(p_this->varValues[11], PTMP_tmp16_1, PRT_TRUE, &P_GEND_TYPE_MKmVi)));
            PrtFreeValue(*P_LVALUE_267);
            *P_LVALUE_267 = PTMP_tmp17_1;
            PTMP_tmp17_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_268 = &(PTMP_tmp18);
        PrtFreeValue(*P_LVALUE_268);
        *P_LVALUE_268 = PrtSeqGet(p_this->varValues[2], P_VAR_idx_4);
        
        PRT_VALUE** P_LVALUE_269 = &(*(PrtMapGetLValue(p_this->varValues[12], PTMP_tmp18, PRT_TRUE, &P_GEND_TYPE_MKmVi)));
        PrtFreeValue(*P_LVALUE_269);
        *P_LVALUE_269 = PrtCloneValue((&P_LIT_INT32_22));
        
        PRT_VALUE** P_LVALUE_270 = &(PTMP_tmp19);
        PrtFreeValue(*P_LVALUE_270);
        *P_LVALUE_270 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_4) + PrtPrimGetInt((&P_LIT_INT32_23)));
        
        {
            PRT_VALUE** P_LVALUE_271 = &(P_VAR_idx_4);
            PrtFreeValue(*P_LVALUE_271);
            *P_LVALUE_271 = PTMP_tmp19;
            PTMP_tmp19 = NULL;
        }
        
    }
    
    
    PRT_VALUE** P_LVALUE_272 = &(P_VAR_idx_4);
    PrtFreeValue(*P_LVALUE_272);
    *P_LVALUE_272 = PrtCloneValue((&P_LIT_INT32_22));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_6)))
    {
        PRT_VALUE** P_LVALUE_273 = &(PTMP_tmp20);
        PrtFreeValue(*P_LVALUE_273);
        *P_LVALUE_273 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
        
        PRT_VALUE** P_LVALUE_274 = &(PTMP_tmp21);
        PrtFreeValue(*P_LVALUE_274);
        *P_LVALUE_274 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_4) < PrtPrimGetInt(PTMP_tmp20));
        
        PRT_VALUE** P_LVALUE_275 = &(PTMP_tmp22);
        PrtFreeValue(*P_LVALUE_275);
        *P_LVALUE_275 = PrtCloneValue(PTMP_tmp21);
        
        if (PrtPrimGetBool(PTMP_tmp22))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_276 = &(PTMP_tmp23);
        PrtFreeValue(*P_LVALUE_276);
        *P_LVALUE_276 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_idx_4, p_this->varValues[0]));
        
        if (PrtPrimGetBool(PTMP_tmp23))
        {
            continue;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_277 = &(PTMP_tmp24);
        PrtFreeValue(*P_LVALUE_277);
        *P_LVALUE_277 = PrtSeqGet(p_this->varValues[2], P_VAR_idx_4);
        
        PRT_VALUE** P_LVALUE_278 = &(PTMP_tmp25);
        PrtFreeValue(*P_LVALUE_278);
        *P_LVALUE_278 = PrtCloneValue(PTMP_tmp24);
        
        PRT_VALUE** P_LVALUE_279 = &(PTMP_tmp26);
        PrtFreeValue(*P_LVALUE_279);
        *P_LVALUE_279 = PrtCloneValue((&P_EVENT_AppendEntriesRequest.value));
        
        PRT_VALUE** P_LVALUE_280 = &(PTMP_tmp27);
        PrtFreeValue(*P_LVALUE_280);
        *P_LVALUE_280 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_281 = &(PTMP_tmp28);
        PrtFreeValue(*P_LVALUE_281);
        *P_LVALUE_281 = PrtCloneValue((p_this->id));
        
        PRT_VALUE** P_LVALUE_282 = &(PTMP_tmp29);
        PrtFreeValue(*P_LVALUE_282);
        *P_LVALUE_282 = PrtCloneValue(P_VAR_logIndex);
        
        PRT_VALUE** P_LVALUE_283 = &(PTMP_tmp30);
        PrtFreeValue(*P_LVALUE_283);
        *P_LVALUE_283 = PrtCloneValue(P_VAR_logTerm);
        
        PRT_VALUE** P_LVALUE_284 = &(PTMP_tmp31);
        PrtFreeValue(*P_LVALUE_284);
        *P_LVALUE_284 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
        
        PRT_VALUE** P_LVALUE_285 = &(PTMP_tmp32);
        PrtFreeValue(*P_LVALUE_285);
        *P_LVALUE_285 = PrtCloneValue(p_this->varValues[9]);
        
        PRT_VALUE** P_LVALUE_286 = &(PTMP_tmp33);
        PrtFreeValue(*P_LVALUE_286);
        *P_LVALUE_286 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        PRT_VALUE** P_LVALUE_287 = &(PTMP_tmp34);
        PrtFreeValue(*P_LVALUE_287);
        *P_LVALUE_287 = (PrtMkTuple(&P_GEND_TYPE_T7iRiiST2iiim, &(PTMP_tmp27), &(PTMP_tmp28), &(PTMP_tmp29), &(PTMP_tmp30), &(PTMP_tmp31), &(PTMP_tmp32), &(PTMP_tmp33)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp25), PTMP_tmp26, 1, &(PTMP_tmp34));
        *(&(PTMP_tmp26)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_38;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_38;
        }
        
    }
    
    
p_return_38: ;
    PrtFreeValue(P_VAR_logIndex); P_VAR_logIndex = NULL;
    PrtFreeValue(P_VAR_logTerm); P_VAR_logTerm = NULL;
    PrtFreeValue(P_VAR_idx_4); P_VAR_idx_4 = NULL;
    PrtFreeValue(PTMP_tmp0_35); PTMP_tmp0_35 = NULL;
    PrtFreeValue(PTMP_tmp1_27); PTMP_tmp1_27 = NULL;
    PrtFreeValue(PTMP_tmp2_25); PTMP_tmp2_25 = NULL;
    PrtFreeValue(PTMP_tmp3_21); PTMP_tmp3_21 = NULL;
    PrtFreeValue(PTMP_tmp4_17); PTMP_tmp4_17 = NULL;
    PrtFreeValue(PTMP_tmp5_11); PTMP_tmp5_11 = NULL;
    PrtFreeValue(PTMP_tmp6_11); PTMP_tmp6_11 = NULL;
    PrtFreeValue(PTMP_tmp7_7); PTMP_tmp7_7 = NULL;
    PrtFreeValue(PTMP_tmp8_4); PTMP_tmp8_4 = NULL;
    PrtFreeValue(PTMP_tmp9_4); PTMP_tmp9_4 = NULL;
    PrtFreeValue(PTMP_tmp10_4); PTMP_tmp10_4 = NULL;
    PrtFreeValue(PTMP_tmp11_4); PTMP_tmp11_4 = NULL;
    PrtFreeValue(PTMP_tmp12_3); PTMP_tmp12_3 = NULL;
    PrtFreeValue(PTMP_tmp13_3); PTMP_tmp13_3 = NULL;
    PrtFreeValue(PTMP_tmp14_1); PTMP_tmp14_1 = NULL;
    PrtFreeValue(PTMP_tmp15_1); PTMP_tmp15_1 = NULL;
    PrtFreeValue(PTMP_tmp16_1); PTMP_tmp16_1 = NULL;
    PrtFreeValue(PTMP_tmp17_1); PTMP_tmp17_1 = NULL;
    PrtFreeValue(PTMP_tmp18); PTMP_tmp18 = NULL;
    PrtFreeValue(PTMP_tmp19); PTMP_tmp19 = NULL;
    PrtFreeValue(PTMP_tmp20); PTMP_tmp20 = NULL;
    PrtFreeValue(PTMP_tmp21); PTMP_tmp21 = NULL;
    PrtFreeValue(PTMP_tmp22); PTMP_tmp22 = NULL;
    PrtFreeValue(PTMP_tmp23); PTMP_tmp23 = NULL;
    PrtFreeValue(PTMP_tmp24); PTMP_tmp24 = NULL;
    PrtFreeValue(PTMP_tmp25); PTMP_tmp25 = NULL;
    PrtFreeValue(PTMP_tmp26); PTMP_tmp26 = NULL;
    PrtFreeValue(PTMP_tmp27); PTMP_tmp27 = NULL;
    PrtFreeValue(PTMP_tmp28); PTMP_tmp28 = NULL;
    PrtFreeValue(PTMP_tmp29); PTMP_tmp29 = NULL;
    PrtFreeValue(PTMP_tmp30); PTMP_tmp30 = NULL;
    PrtFreeValue(PTMP_tmp31); PTMP_tmp31 = NULL;
    PrtFreeValue(PTMP_tmp32); PTMP_tmp32 = NULL;
    PrtFreeValue(PTMP_tmp33); PTMP_tmp33 = NULL;
    PrtFreeValue(PTMP_tmp34); PTMP_tmp34 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_29 =
{
    NULL,
    &P_Anon_IMPL_29,
    NULL
};


PRT_VALUE* P_Anon_IMPL_30(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_9 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_36 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_288 = &(PTMP_tmp0_36);
    PrtFreeValue(*P_LVALUE_288);
    *P_LVALUE_288 = PrtCloneValue(*P_VAR_request_9);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_36);
    PrtFreeValue(P_ProcessClientRequest_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_36);
    PTMP_tmp0_36 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_39;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_39;
    }
    
p_return_39: ;
    PrtFreeValue(PTMP_tmp0_36); PTMP_tmp0_36 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_30 =
{
    NULL,
    &P_Anon_IMPL_30,
    &P_GEND_TYPE_T2mi_1
};


PRT_VALUE* P_Anon_IMPL_31(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_10 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_37 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_289 = &(PTMP_tmp0_37);
    PrtFreeValue(*P_LVALUE_289);
    *P_LVALUE_289 = PrtCloneValue(*P_VAR_request_10);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_37);
    PrtFreeValue(P_VoteAsLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_37);
    PTMP_tmp0_37 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_40;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_40;
    }
    
p_return_40: ;
    PrtFreeValue(PTMP_tmp0_37); PTMP_tmp0_37 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_31 =
{
    NULL,
    &P_Anon_IMPL_31,
    &P_GEND_TYPE_T4imii
};


PRT_VALUE* P_Anon_IMPL_32(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_11 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_38 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_290 = &(PTMP_tmp0_38);
    PrtFreeValue(*P_LVALUE_290);
    *P_LVALUE_290 = PrtCloneValue(*P_VAR_request_11);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_38);
    PrtFreeValue(P_RespondVoteAsLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_38);
    PTMP_tmp0_38 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_41;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_41;
    }
    
p_return_41: ;
    PrtFreeValue(PTMP_tmp0_38); PTMP_tmp0_38 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_32 =
{
    NULL,
    &P_Anon_IMPL_32,
    &P_GEND_TYPE_T2ib
};


PRT_VALUE* P_Anon_IMPL_33(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_12 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_39 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_291 = &(PTMP_tmp0_39);
    PrtFreeValue(*P_LVALUE_291);
    *P_LVALUE_291 = PrtCloneValue(*P_VAR_request_12);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_39);
    PrtFreeValue(P_AppendEntriesAsLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_39);
    PTMP_tmp0_39 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_42;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_42;
    }
    
p_return_42: ;
    PrtFreeValue(PTMP_tmp0_39); PTMP_tmp0_39 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_33 =
{
    NULL,
    &P_Anon_IMPL_33,
    &P_GEND_TYPE_T7imiiST2iiim
};


PRT_VALUE* P_Anon_IMPL_34(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_13 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_40 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_292 = &(PTMP_tmp0_40);
    PrtFreeValue(*P_LVALUE_292);
    *P_LVALUE_292 = PrtCloneValue(*P_VAR_request_13);
    
    _P_GEN_funargs[0] = &(PTMP_tmp0_40);
    PrtFreeValue(P_RespondAppendEntriesAsLeader_IMPL(context, _P_GEN_funargs));
    PrtFreeValue(PTMP_tmp0_40);
    PTMP_tmp0_40 = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_43;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_43;
    }
    
p_return_43: ;
    PrtFreeValue(PTMP_tmp0_40); PTMP_tmp0_40 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Anon_34 =
{
    NULL,
    &P_Anon_IMPL_34,
    &P_GEND_TYPE_T4ibmm
};


PRT_VALUE* P_ProcessClientRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_trigger = argRefs[0];
    PRT_VALUE* P_VAR_log = PrtMkDefaultValue(&P_GEND_TYPE_T2ii);
    PRT_VALUE* PTMP_tmp0_41 = NULL;
    PRT_VALUE* PTMP_tmp1_28 = NULL;
    PRT_VALUE* PTMP_tmp2_26 = NULL;
    PRT_VALUE* PTMP_tmp3_22 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_24 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_293 = &(p_this->varValues[14]);
    PrtFreeValue(*P_LVALUE_293);
    *P_LVALUE_293 = PrtCloneValue(*P_VAR_trigger);
    
    PRT_VALUE** P_LVALUE_294 = &(PTMP_tmp0_41);
    PrtFreeValue(*P_LVALUE_294);
    *P_LVALUE_294 = PrtMkDefaultValue(&P_GEND_TYPE_T2ii);
    
    {
        PRT_VALUE** P_LVALUE_295 = &(P_VAR_log);
        PrtFreeValue(*P_LVALUE_295);
        *P_LVALUE_295 = PTMP_tmp0_41;
        PTMP_tmp0_41 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_296 = &(*(PrtTupleGetLValue(P_VAR_log, 0)));
    PrtFreeValue(*P_LVALUE_296);
    *P_LVALUE_296 = PrtCloneValue(p_this->varValues[6]);
    
    PRT_VALUE** P_LVALUE_297 = &(PTMP_tmp1_28);
    PrtFreeValue(*P_LVALUE_297);
    *P_LVALUE_297 = PrtTupleGet(p_this->varValues[14], 1);
    
    {
        PRT_VALUE** P_LVALUE_298 = &(*(PrtTupleGetLValue(P_VAR_log, 1)));
        PrtFreeValue(*P_LVALUE_298);
        *P_LVALUE_298 = PTMP_tmp1_28;
        PTMP_tmp1_28 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_299 = &(PTMP_tmp2_26);
    PrtFreeValue(*P_LVALUE_299);
    *P_LVALUE_299 = PrtCloneValue(P_VAR_log);
    
    PrtSeqInsertEx(p_this->varValues[8], p_this->varValues[15], PTMP_tmp2_26, PRT_FALSE);
    *(&(PTMP_tmp2_26)) = NULL;
    
    PRT_VALUE** P_LVALUE_300 = &(PTMP_tmp3_22);
    PrtFreeValue(*P_LVALUE_300);
    *P_LVALUE_300 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[15]) + PrtPrimGetInt((&P_LIT_INT32_24)));
    
    {
        PRT_VALUE** P_LVALUE_301 = &(p_this->varValues[15]);
        PrtFreeValue(*P_LVALUE_301);
        *P_LVALUE_301 = PTMP_tmp3_22;
        PTMP_tmp3_22 = NULL;
    }
    
    PrtFreeValue(P_BroadcastLastClientRequest_IMPL(context, _P_GEN_funargs));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_44;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_44;
    }
    
p_return_44: ;
    PrtFreeValue(P_VAR_log); P_VAR_log = NULL;
    PrtFreeValue(PTMP_tmp0_41); PTMP_tmp0_41 = NULL;
    PrtFreeValue(PTMP_tmp1_28); PTMP_tmp1_28 = NULL;
    PrtFreeValue(PTMP_tmp2_26); PTMP_tmp2_26 = NULL;
    PrtFreeValue(PTMP_tmp3_22); PTMP_tmp3_22 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ProcessClientRequest =
{
    "ProcessClientRequest",
    &P_ProcessClientRequest_IMPL,
    NULL
};


PRT_VALUE* P_BroadcastLastClientRequest_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* P_VAR_lastLogIndex_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_idx_5 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_prevLogIndex = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_prevLogTerm = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_server = PrtMkDefaultValue(&P_GEND_TYPE_m);
    PRT_VALUE* P_VAR_logsAppend = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
    PRT_VALUE* PTMP_tmp0_42 = NULL;
    PRT_VALUE* PTMP_tmp1_29 = NULL;
    PRT_VALUE* PTMP_tmp2_27 = NULL;
    PRT_VALUE* PTMP_tmp3_23 = NULL;
    PRT_VALUE* PTMP_tmp4_18 = NULL;
    PRT_VALUE* PTMP_tmp5_12 = NULL;
    PRT_VALUE* PTMP_tmp6_12 = NULL;
    PRT_VALUE* PTMP_tmp7_8 = NULL;
    PRT_VALUE* PTMP_tmp8_5 = NULL;
    PRT_VALUE* PTMP_tmp9_5 = NULL;
    PRT_VALUE* PTMP_tmp10_5 = NULL;
    PRT_VALUE* PTMP_tmp11_5 = NULL;
    PRT_VALUE* PTMP_tmp12_4 = NULL;
    PRT_VALUE* PTMP_tmp13_4 = NULL;
    PRT_VALUE* PTMP_tmp14_2 = NULL;
    PRT_VALUE* PTMP_tmp15_2 = NULL;
    PRT_VALUE* PTMP_tmp16_2 = NULL;
    PRT_VALUE* PTMP_tmp17_2 = NULL;
    PRT_VALUE* PTMP_tmp18_1 = NULL;
    PRT_VALUE* PTMP_tmp19_1 = NULL;
    PRT_VALUE* PTMP_tmp20_1 = NULL;
    PRT_VALUE* PTMP_tmp21_1 = NULL;
    PRT_VALUE* PTMP_tmp22_1 = NULL;
    PRT_VALUE* PTMP_tmp23_1 = NULL;
    PRT_VALUE* PTMP_tmp24_1 = NULL;
    PRT_VALUE* PTMP_tmp25_1 = NULL;
    PRT_VALUE* PTMP_tmp26_1 = NULL;
    PRT_VALUE* PTMP_tmp27_1 = NULL;
    PRT_VALUE* PTMP_tmp28_1 = NULL;
    PRT_VALUE* PTMP_tmp29_1 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_25 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_7 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_302 = &(PTMP_tmp0_42);
    PrtFreeValue(*P_LVALUE_302);
    *P_LVALUE_302 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
    
    {
        PRT_VALUE** P_LVALUE_303 = &(P_VAR_lastLogIndex_1);
        PrtFreeValue(*P_LVALUE_303);
        *P_LVALUE_303 = PTMP_tmp0_42;
        PTMP_tmp0_42 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_304 = &(p_this->varValues[13]);
    PrtFreeValue(*P_LVALUE_304);
    *P_LVALUE_304 = PrtCloneValue((&P_LIT_INT32_25));
    
    while (PrtPrimGetBool((&P_LIT_BOOLEAN_7)))
    {
        PRT_VALUE** P_LVALUE_305 = &(PTMP_tmp1_29);
        PrtFreeValue(*P_LVALUE_305);
        *P_LVALUE_305 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
        
        PRT_VALUE** P_LVALUE_306 = &(PTMP_tmp2_27);
        PrtFreeValue(*P_LVALUE_306);
        *P_LVALUE_306 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_5) < PrtPrimGetInt(PTMP_tmp1_29));
        
        PRT_VALUE** P_LVALUE_307 = &(PTMP_tmp3_23);
        PrtFreeValue(*P_LVALUE_307);
        *P_LVALUE_307 = PrtCloneValue(PTMP_tmp2_27);
        
        if (PrtPrimGetBool(PTMP_tmp3_23))
        {
        }
        
        else
        {
            break;
            
        }
        
        
        PRT_VALUE** P_LVALUE_308 = &(PTMP_tmp4_18);
        PrtFreeValue(*P_LVALUE_308);
        *P_LVALUE_308 = PrtMkBoolValue(PrtIsEqualValue(P_VAR_idx_5, p_this->varValues[0]));
        
        if (PrtPrimGetBool(PTMP_tmp4_18))
        {
            continue;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_309 = &(PTMP_tmp5_12);
        PrtFreeValue(*P_LVALUE_309);
        *P_LVALUE_309 = PrtSeqGet(p_this->varValues[2], P_VAR_idx_5);
        
        {
            PRT_VALUE** P_LVALUE_310 = &(P_VAR_server);
            PrtFreeValue(*P_LVALUE_310);
            *P_LVALUE_310 = PTMP_tmp5_12;
            PTMP_tmp5_12 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_311 = &(PTMP_tmp6_12);
        PrtFreeValue(*P_LVALUE_311);
        *P_LVALUE_311 = PrtMapGet(p_this->varValues[11], P_VAR_server);
        
        PRT_VALUE** P_LVALUE_312 = &(PTMP_tmp7_8);
        PrtFreeValue(*P_LVALUE_312);
        *P_LVALUE_312 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_lastLogIndex_1) < PrtPrimGetInt(PTMP_tmp6_12));
        
        if (PrtPrimGetBool(PTMP_tmp7_8))
        {
            continue;
            
        }
        
        else
        {
        }
        
        
        PRT_VALUE** P_LVALUE_313 = &(PTMP_tmp8_5);
        PrtFreeValue(*P_LVALUE_313);
        *P_LVALUE_313 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
        
        {
            PRT_VALUE** P_LVALUE_314 = &(P_VAR_logsAppend);
            PrtFreeValue(*P_LVALUE_314);
            *P_LVALUE_314 = PTMP_tmp8_5;
            PTMP_tmp8_5 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_315 = &(PTMP_tmp9_5);
        PrtFreeValue(*P_LVALUE_315);
        *P_LVALUE_315 = PrtMapGet(p_this->varValues[11], P_VAR_server);
        
        PRT_VALUE** P_LVALUE_316 = &(PTMP_tmp10_5);
        PrtFreeValue(*P_LVALUE_316);
        *P_LVALUE_316 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp9_5) - PrtPrimGetInt((&P_LIT_INT32_25)));
        
        {
            PRT_VALUE** P_LVALUE_317 = &(P_VAR_idx_5);
            PrtFreeValue(*P_LVALUE_317);
            *P_LVALUE_317 = PTMP_tmp10_5;
            PTMP_tmp10_5 = NULL;
        }
        
        while (PrtPrimGetBool((&P_LIT_BOOLEAN_7)))
        {
            PRT_VALUE** P_LVALUE_318 = &(PTMP_tmp11_5);
            PrtFreeValue(*P_LVALUE_318);
            *P_LVALUE_318 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
            
            PRT_VALUE** P_LVALUE_319 = &(PTMP_tmp12_4);
            PrtFreeValue(*P_LVALUE_319);
            *P_LVALUE_319 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_5) < PrtPrimGetInt(PTMP_tmp11_5));
            
            PRT_VALUE** P_LVALUE_320 = &(PTMP_tmp13_4);
            PrtFreeValue(*P_LVALUE_320);
            *P_LVALUE_320 = PrtCloneValue(PTMP_tmp12_4);
            
            if (PrtPrimGetBool(PTMP_tmp13_4))
            {
            }
            
            else
            {
                break;
                
            }
            
            
            PRT_VALUE** P_LVALUE_321 = &(PTMP_tmp14_2);
            PrtFreeValue(*P_LVALUE_321);
            *P_LVALUE_321 = PrtSeqGet(p_this->varValues[8], P_VAR_idx_5);
            
            PrtSeqInsertEx(P_VAR_logsAppend, P_VAR_idx_5, PTMP_tmp14_2, PRT_FALSE);
            *(&(PTMP_tmp14_2)) = NULL;
            
            PRT_VALUE** P_LVALUE_322 = &(PTMP_tmp15_2);
            PrtFreeValue(*P_LVALUE_322);
            *P_LVALUE_322 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_5) + PrtPrimGetInt((&P_LIT_INT32_25)));
            
            {
                PRT_VALUE** P_LVALUE_323 = &(P_VAR_idx_5);
                PrtFreeValue(*P_LVALUE_323);
                *P_LVALUE_323 = PTMP_tmp15_2;
                PTMP_tmp15_2 = NULL;
            }
            
        }
        
        
        PRT_VALUE** P_LVALUE_324 = &(PTMP_tmp16_2);
        PrtFreeValue(*P_LVALUE_324);
        *P_LVALUE_324 = PrtMapGet(p_this->varValues[11], P_VAR_server);
        
        PRT_VALUE** P_LVALUE_325 = &(PTMP_tmp17_2);
        PrtFreeValue(*P_LVALUE_325);
        *P_LVALUE_325 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp16_2) - PrtPrimGetInt((&P_LIT_INT32_25)));
        
        {
            PRT_VALUE** P_LVALUE_326 = &(P_VAR_prevLogIndex);
            PrtFreeValue(*P_LVALUE_326);
            *P_LVALUE_326 = PTMP_tmp17_2;
            PTMP_tmp17_2 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_327 = &(PTMP_tmp18_1);
        PrtFreeValue(*P_LVALUE_327);
        *P_LVALUE_327 = PrtCloneValue(P_VAR_prevLogIndex);
        
        PRT_VALUE** P_LVALUE_328 = &(PTMP_tmp19_1);
        PrtFreeValue(*P_LVALUE_328);
        *P_LVALUE_328 = ((_P_GEN_funargs[0] = &(PTMP_tmp18_1)), (_P_GEN_funval = P_GetLogTermForIndex_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp18_1), PTMP_tmp18_1 = NULL), (_P_GEN_funval));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_45;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_45;
        }
        
        {
            PRT_VALUE** P_LVALUE_329 = &(P_VAR_prevLogTerm);
            PrtFreeValue(*P_LVALUE_329);
            *P_LVALUE_329 = PTMP_tmp19_1;
            PTMP_tmp19_1 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_330 = &(PTMP_tmp20_1);
        PrtFreeValue(*P_LVALUE_330);
        *P_LVALUE_330 = PrtCloneValue(P_VAR_server);
        
        PRT_VALUE** P_LVALUE_331 = &(PTMP_tmp21_1);
        PrtFreeValue(*P_LVALUE_331);
        *P_LVALUE_331 = PrtCloneValue((&P_EVENT_AppendEntriesRequest.value));
        
        PRT_VALUE** P_LVALUE_332 = &(PTMP_tmp22_1);
        PrtFreeValue(*P_LVALUE_332);
        *P_LVALUE_332 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_333 = &(PTMP_tmp23_1);
        PrtFreeValue(*P_LVALUE_333);
        *P_LVALUE_333 = PrtCloneValue((p_this->id));
        
        PRT_VALUE** P_LVALUE_334 = &(PTMP_tmp24_1);
        PrtFreeValue(*P_LVALUE_334);
        *P_LVALUE_334 = PrtCloneValue(P_VAR_prevLogIndex);
        
        PRT_VALUE** P_LVALUE_335 = &(PTMP_tmp25_1);
        PrtFreeValue(*P_LVALUE_335);
        *P_LVALUE_335 = PrtCloneValue(P_VAR_prevLogTerm);
        
        PRT_VALUE** P_LVALUE_336 = &(PTMP_tmp26_1);
        PrtFreeValue(*P_LVALUE_336);
        *P_LVALUE_336 = PrtCloneValue(p_this->varValues[8]);
        
        PRT_VALUE** P_LVALUE_337 = &(PTMP_tmp27_1);
        PrtFreeValue(*P_LVALUE_337);
        *P_LVALUE_337 = PrtCloneValue(p_this->varValues[9]);
        
        PRT_VALUE** P_LVALUE_338 = &(PTMP_tmp28_1);
        PrtFreeValue(*P_LVALUE_338);
        *P_LVALUE_338 = PrtTupleGet(p_this->varValues[14], 0);
        
        PRT_VALUE** P_LVALUE_339 = &(PTMP_tmp29_1);
        PrtFreeValue(*P_LVALUE_339);
        *P_LVALUE_339 = (PrtMkTuple(&P_GEND_TYPE_T7iRiiST2iiim, &(PTMP_tmp22_1), &(PTMP_tmp23_1), &(PTMP_tmp24_1), &(PTMP_tmp25_1), &(PTMP_tmp26_1), &(PTMP_tmp27_1), &(PTMP_tmp28_1)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp20_1), PTMP_tmp21_1, 1, &(PTMP_tmp29_1));
        *(&(PTMP_tmp21_1)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_45;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_45;
        }
        
    }
    
    
p_return_45: ;
    PrtFreeValue(P_VAR_lastLogIndex_1); P_VAR_lastLogIndex_1 = NULL;
    PrtFreeValue(P_VAR_idx_5); P_VAR_idx_5 = NULL;
    PrtFreeValue(P_VAR_prevLogIndex); P_VAR_prevLogIndex = NULL;
    PrtFreeValue(P_VAR_prevLogTerm); P_VAR_prevLogTerm = NULL;
    PrtFreeValue(P_VAR_server); P_VAR_server = NULL;
    PrtFreeValue(P_VAR_logsAppend); P_VAR_logsAppend = NULL;
    PrtFreeValue(PTMP_tmp0_42); PTMP_tmp0_42 = NULL;
    PrtFreeValue(PTMP_tmp1_29); PTMP_tmp1_29 = NULL;
    PrtFreeValue(PTMP_tmp2_27); PTMP_tmp2_27 = NULL;
    PrtFreeValue(PTMP_tmp3_23); PTMP_tmp3_23 = NULL;
    PrtFreeValue(PTMP_tmp4_18); PTMP_tmp4_18 = NULL;
    PrtFreeValue(PTMP_tmp5_12); PTMP_tmp5_12 = NULL;
    PrtFreeValue(PTMP_tmp6_12); PTMP_tmp6_12 = NULL;
    PrtFreeValue(PTMP_tmp7_8); PTMP_tmp7_8 = NULL;
    PrtFreeValue(PTMP_tmp8_5); PTMP_tmp8_5 = NULL;
    PrtFreeValue(PTMP_tmp9_5); PTMP_tmp9_5 = NULL;
    PrtFreeValue(PTMP_tmp10_5); PTMP_tmp10_5 = NULL;
    PrtFreeValue(PTMP_tmp11_5); PTMP_tmp11_5 = NULL;
    PrtFreeValue(PTMP_tmp12_4); PTMP_tmp12_4 = NULL;
    PrtFreeValue(PTMP_tmp13_4); PTMP_tmp13_4 = NULL;
    PrtFreeValue(PTMP_tmp14_2); PTMP_tmp14_2 = NULL;
    PrtFreeValue(PTMP_tmp15_2); PTMP_tmp15_2 = NULL;
    PrtFreeValue(PTMP_tmp16_2); PTMP_tmp16_2 = NULL;
    PrtFreeValue(PTMP_tmp17_2); PTMP_tmp17_2 = NULL;
    PrtFreeValue(PTMP_tmp18_1); PTMP_tmp18_1 = NULL;
    PrtFreeValue(PTMP_tmp19_1); PTMP_tmp19_1 = NULL;
    PrtFreeValue(PTMP_tmp20_1); PTMP_tmp20_1 = NULL;
    PrtFreeValue(PTMP_tmp21_1); PTMP_tmp21_1 = NULL;
    PrtFreeValue(PTMP_tmp22_1); PTMP_tmp22_1 = NULL;
    PrtFreeValue(PTMP_tmp23_1); PTMP_tmp23_1 = NULL;
    PrtFreeValue(PTMP_tmp24_1); PTMP_tmp24_1 = NULL;
    PrtFreeValue(PTMP_tmp25_1); PTMP_tmp25_1 = NULL;
    PrtFreeValue(PTMP_tmp26_1); PTMP_tmp26_1 = NULL;
    PrtFreeValue(PTMP_tmp27_1); PTMP_tmp27_1 = NULL;
    PrtFreeValue(PTMP_tmp28_1); PTMP_tmp28_1 = NULL;
    PrtFreeValue(PTMP_tmp29_1); PTMP_tmp29_1 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_BroadcastLastClientRequest =
{
    "BroadcastLastClientRequest",
    &P_BroadcastLastClientRequest_IMPL,
    NULL
};


PRT_VALUE* P_VoteAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_14 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_43 = NULL;
    PRT_VALUE* PTMP_tmp1_30 = NULL;
    PRT_VALUE* PTMP_tmp2_28 = NULL;
    PRT_VALUE* PTMP_tmp3_24 = NULL;
    PRT_VALUE* PTMP_tmp4_19 = NULL;
    PRT_VALUE* PTMP_tmp5_13 = NULL;
    PRT_VALUE* PTMP_tmp6_13 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_340 = &(PTMP_tmp0_43);
    PrtFreeValue(*P_LVALUE_340);
    *P_LVALUE_340 = PrtTupleGet(*P_VAR_request_14, 0);
    
    PRT_VALUE** P_LVALUE_341 = &(PTMP_tmp1_30);
    PrtFreeValue(*P_LVALUE_341);
    *P_LVALUE_341 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_43) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_30))
    {
        PRT_VALUE** P_LVALUE_342 = &(PTMP_tmp2_28);
        PrtFreeValue(*P_LVALUE_342);
        *P_LVALUE_342 = PrtTupleGet(*P_VAR_request_14, 0);
        
        {
            PRT_VALUE** P_LVALUE_343 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_343);
            *P_LVALUE_343 = PTMP_tmp2_28;
            PTMP_tmp2_28 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_344 = &(PTMP_tmp3_24);
        PrtFreeValue(*P_LVALUE_344);
        *P_LVALUE_344 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_345 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_345);
            *P_LVALUE_345 = PTMP_tmp3_24;
            PTMP_tmp3_24 = NULL;
        }
        
        PrtFreeValue(P_RedirectLastClientRequestToClusterManager_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_46;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_46;
        }
        
        PRT_VALUE** P_LVALUE_346 = &(PTMP_tmp4_19);
        PrtFreeValue(*P_LVALUE_346);
        *P_LVALUE_346 = PrtCloneValue(*P_VAR_request_14);
        
        _P_GEN_funargs[0] = &(PTMP_tmp4_19);
        PrtFreeValue(P_Vote_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp4_19);
        PTMP_tmp4_19 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_46;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_46;
        }
        
        PRT_VALUE** P_LVALUE_347 = &(PTMP_tmp5_13);
        PrtFreeValue(*P_LVALUE_347);
        *P_LVALUE_347 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp5_13, 0);
        *(&(PTMP_tmp5_13)) = NULL;
        goto p_return_46;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_348 = &(PTMP_tmp6_13);
        PrtFreeValue(*P_LVALUE_348);
        *P_LVALUE_348 = PrtCloneValue(*P_VAR_request_14);
        
        _P_GEN_funargs[0] = &(PTMP_tmp6_13);
        PrtFreeValue(P_Vote_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp6_13);
        PTMP_tmp6_13 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_46;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_46;
        }
        
    }
    
    
p_return_46: ;
    PrtFreeValue(PTMP_tmp0_43); PTMP_tmp0_43 = NULL;
    PrtFreeValue(PTMP_tmp1_30); PTMP_tmp1_30 = NULL;
    PrtFreeValue(PTMP_tmp2_28); PTMP_tmp2_28 = NULL;
    PrtFreeValue(PTMP_tmp3_24); PTMP_tmp3_24 = NULL;
    PrtFreeValue(PTMP_tmp4_19); PTMP_tmp4_19 = NULL;
    PrtFreeValue(PTMP_tmp5_13); PTMP_tmp5_13 = NULL;
    PrtFreeValue(PTMP_tmp6_13); PTMP_tmp6_13 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_VoteAsLeader =
{
    "VoteAsLeader",
    &P_VoteAsLeader_IMPL,
    NULL
};


PRT_VALUE* P_RespondVoteAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_15 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_44 = NULL;
    PRT_VALUE* PTMP_tmp1_31 = NULL;
    PRT_VALUE* PTMP_tmp2_29 = NULL;
    PRT_VALUE* PTMP_tmp3_25 = NULL;
    PRT_VALUE* PTMP_tmp4_20 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_349 = &(PTMP_tmp0_44);
    PrtFreeValue(*P_LVALUE_349);
    *P_LVALUE_349 = PrtTupleGet(*P_VAR_request_15, 0);
    
    PRT_VALUE** P_LVALUE_350 = &(PTMP_tmp1_31);
    PrtFreeValue(*P_LVALUE_350);
    *P_LVALUE_350 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_44) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_31))
    {
        PRT_VALUE** P_LVALUE_351 = &(PTMP_tmp2_29);
        PrtFreeValue(*P_LVALUE_351);
        *P_LVALUE_351 = PrtTupleGet(*P_VAR_request_15, 0);
        
        {
            PRT_VALUE** P_LVALUE_352 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_352);
            *P_LVALUE_352 = PTMP_tmp2_29;
            PTMP_tmp2_29 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_353 = &(PTMP_tmp3_25);
        PrtFreeValue(*P_LVALUE_353);
        *P_LVALUE_353 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_354 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_354);
            *P_LVALUE_354 = PTMP_tmp3_25;
            PTMP_tmp3_25 = NULL;
        }
        
        PrtFreeValue(P_RedirectLastClientRequestToClusterManager_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_47;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_47;
        }
        
        PRT_VALUE** P_LVALUE_355 = &(PTMP_tmp4_20);
        PrtFreeValue(*P_LVALUE_355);
        *P_LVALUE_355 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp4_20, 0);
        *(&(PTMP_tmp4_20)) = NULL;
        goto p_return_47;
        
    }
    
    else
    {
    }
    
    
p_return_47: ;
    PrtFreeValue(PTMP_tmp0_44); PTMP_tmp0_44 = NULL;
    PrtFreeValue(PTMP_tmp1_31); PTMP_tmp1_31 = NULL;
    PrtFreeValue(PTMP_tmp2_29); PTMP_tmp2_29 = NULL;
    PrtFreeValue(PTMP_tmp3_25); PTMP_tmp3_25 = NULL;
    PrtFreeValue(PTMP_tmp4_20); PTMP_tmp4_20 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RespondVoteAsLeader =
{
    "RespondVoteAsLeader",
    &P_RespondVoteAsLeader_IMPL,
    NULL
};


PRT_VALUE* P_AppendEntriesAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_16 = argRefs[0];
    PRT_VALUE* PTMP_tmp0_45 = NULL;
    PRT_VALUE* PTMP_tmp1_32 = NULL;
    PRT_VALUE* PTMP_tmp2_30 = NULL;
    PRT_VALUE* PTMP_tmp3_26 = NULL;
    PRT_VALUE* PTMP_tmp4_21 = NULL;
    PRT_VALUE* PTMP_tmp5_14 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_356 = &(PTMP_tmp0_45);
    PrtFreeValue(*P_LVALUE_356);
    *P_LVALUE_356 = PrtTupleGet(*P_VAR_request_16, 0);
    
    PRT_VALUE** P_LVALUE_357 = &(PTMP_tmp1_32);
    PrtFreeValue(*P_LVALUE_357);
    *P_LVALUE_357 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_45) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_32))
    {
        PRT_VALUE** P_LVALUE_358 = &(PTMP_tmp2_30);
        PrtFreeValue(*P_LVALUE_358);
        *P_LVALUE_358 = PrtTupleGet(*P_VAR_request_16, 0);
        
        {
            PRT_VALUE** P_LVALUE_359 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_359);
            *P_LVALUE_359 = PTMP_tmp2_30;
            PTMP_tmp2_30 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_360 = &(PTMP_tmp3_26);
        PrtFreeValue(*P_LVALUE_360);
        *P_LVALUE_360 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_361 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_361);
            *P_LVALUE_361 = PTMP_tmp3_26;
            PTMP_tmp3_26 = NULL;
        }
        
        PrtFreeValue(P_RedirectLastClientRequestToClusterManager_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_48;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_48;
        }
        
        PRT_VALUE** P_LVALUE_362 = &(PTMP_tmp4_21);
        PrtFreeValue(*P_LVALUE_362);
        *P_LVALUE_362 = PrtCloneValue(*P_VAR_request_16);
        
        _P_GEN_funargs[0] = &(PTMP_tmp4_21);
        PrtFreeValue(P_AppendEntries_IMPL(context, _P_GEN_funargs));
        PrtFreeValue(PTMP_tmp4_21);
        PTMP_tmp4_21 = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_48;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_48;
        }
        
        PRT_VALUE** P_LVALUE_363 = &(PTMP_tmp5_14);
        PrtFreeValue(*P_LVALUE_363);
        *P_LVALUE_363 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp5_14, 0);
        *(&(PTMP_tmp5_14)) = NULL;
        goto p_return_48;
        
    }
    
    else
    {
    }
    
    
p_return_48: ;
    PrtFreeValue(PTMP_tmp0_45); PTMP_tmp0_45 = NULL;
    PrtFreeValue(PTMP_tmp1_32); PTMP_tmp1_32 = NULL;
    PrtFreeValue(PTMP_tmp2_30); PTMP_tmp2_30 = NULL;
    PrtFreeValue(PTMP_tmp3_26); PTMP_tmp3_26 = NULL;
    PrtFreeValue(PTMP_tmp4_21); PTMP_tmp4_21 = NULL;
    PrtFreeValue(PTMP_tmp5_14); PTMP_tmp5_14 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_AppendEntriesAsLeader =
{
    "AppendEntriesAsLeader",
    &P_AppendEntriesAsLeader_IMPL,
    NULL
};


PRT_VALUE* P_RespondAppendEntriesAsLeader_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_17 = argRefs[0];
    PRT_VALUE* P_VAR_commitIndex = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_logsAppend_1 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
    PRT_VALUE* P_VAR_prevLogIndex_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_prevLogTerm_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_idx_6 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_46 = NULL;
    PRT_VALUE* PTMP_tmp1_33 = NULL;
    PRT_VALUE* PTMP_tmp2_31 = NULL;
    PRT_VALUE* PTMP_tmp3_27 = NULL;
    PRT_VALUE* PTMP_tmp4_22 = NULL;
    PRT_VALUE* PTMP_tmp5_15 = NULL;
    PRT_VALUE* PTMP_tmp6_14 = NULL;
    PRT_VALUE* PTMP_tmp7_9 = NULL;
    PRT_VALUE* PTMP_tmp8_6 = NULL;
    PRT_VALUE* PTMP_tmp9_6 = NULL;
    PRT_VALUE* PTMP_tmp10_6 = NULL;
    PRT_VALUE* PTMP_tmp11_6 = NULL;
    PRT_VALUE* PTMP_tmp12_5 = NULL;
    PRT_VALUE* PTMP_tmp13_5 = NULL;
    PRT_VALUE* PTMP_tmp14_3 = NULL;
    PRT_VALUE* PTMP_tmp15_3 = NULL;
    PRT_VALUE* PTMP_tmp16_3 = NULL;
    PRT_VALUE* PTMP_tmp17_3 = NULL;
    PRT_VALUE* PTMP_tmp18_2 = NULL;
    PRT_VALUE* PTMP_tmp19_2 = NULL;
    PRT_VALUE* PTMP_tmp20_2 = NULL;
    PRT_VALUE* PTMP_tmp21_2 = NULL;
    PRT_VALUE* PTMP_tmp22_2 = NULL;
    PRT_VALUE* PTMP_tmp23_2 = NULL;
    PRT_VALUE* PTMP_tmp24_2 = NULL;
    PRT_VALUE* PTMP_tmp25_2 = NULL;
    PRT_VALUE* PTMP_tmp26_2 = NULL;
    PRT_VALUE* PTMP_tmp27_2 = NULL;
    PRT_VALUE* PTMP_tmp28_2 = NULL;
    PRT_VALUE* PTMP_tmp29_2 = NULL;
    PRT_VALUE* PTMP_tmp30_1 = NULL;
    PRT_VALUE* PTMP_tmp31_1 = NULL;
    PRT_VALUE* PTMP_tmp32_1 = NULL;
    PRT_VALUE* PTMP_tmp33_1 = NULL;
    PRT_VALUE* PTMP_tmp34_1 = NULL;
    PRT_VALUE* PTMP_tmp35 = NULL;
    PRT_VALUE* PTMP_tmp36 = NULL;
    PRT_VALUE* PTMP_tmp37 = NULL;
    PRT_VALUE* PTMP_tmp38 = NULL;
    PRT_VALUE* PTMP_tmp39 = NULL;
    PRT_VALUE* PTMP_tmp40 = NULL;
    PRT_VALUE* PTMP_tmp41 = NULL;
    PRT_VALUE* PTMP_tmp42 = NULL;
    PRT_VALUE* PTMP_tmp43 = NULL;
    PRT_VALUE* PTMP_tmp44 = NULL;
    PRT_VALUE* PTMP_tmp45 = NULL;
    PRT_VALUE* PTMP_tmp46 = NULL;
    PRT_VALUE* PTMP_tmp47 = NULL;
    PRT_VALUE* PTMP_tmp48 = NULL;
    PRT_VALUE* PTMP_tmp49 = NULL;
    PRT_VALUE* PTMP_tmp50 = NULL;
    PRT_VALUE* PTMP_tmp51 = NULL;
    PRT_VALUE* PTMP_tmp52 = NULL;
    PRT_VALUE* PTMP_tmp53 = NULL;
    PRT_VALUE* PTMP_tmp54 = NULL;
    PRT_VALUE* PTMP_tmp55 = NULL;
    PRT_VALUE* PTMP_tmp56 = NULL;
    PRT_VALUE* PTMP_tmp57 = NULL;
    PRT_VALUE* PTMP_tmp58 = NULL;
    PRT_VALUE* PTMP_tmp59 = NULL;
    PRT_VALUE* PTMP_tmp60 = NULL;
    PRT_VALUE* PTMP_tmp61 = NULL;
    PRT_VALUE* PTMP_tmp62 = NULL;
    PRT_VALUE* PTMP_tmp63 = NULL;
    PRT_VALUE* PTMP_tmp64 = NULL;
    PRT_VALUE* PTMP_tmp65 = NULL;
    PRT_VALUE* PTMP_tmp66 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_26 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_INT32_27 = { PRT_VALUE_KIND_INT, { .nt = 2 } };
    PRT_VALUE P_LIT_INT32_28 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_BOOLEAN_8 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_364 = &(PTMP_tmp0_46);
    PrtFreeValue(*P_LVALUE_364);
    *P_LVALUE_364 = PrtTupleGet(*P_VAR_request_17, 0);
    
    PRT_VALUE** P_LVALUE_365 = &(PTMP_tmp1_33);
    PrtFreeValue(*P_LVALUE_365);
    *P_LVALUE_365 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_46) > PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_33))
    {
        PRT_VALUE** P_LVALUE_366 = &(PTMP_tmp2_31);
        PrtFreeValue(*P_LVALUE_366);
        *P_LVALUE_366 = PrtTupleGet(*P_VAR_request_17, 0);
        
        {
            PRT_VALUE** P_LVALUE_367 = &(p_this->varValues[6]);
            PrtFreeValue(*P_LVALUE_367);
            *P_LVALUE_367 = PTMP_tmp2_31;
            PTMP_tmp2_31 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_368 = &(PTMP_tmp3_27);
        PrtFreeValue(*P_LVALUE_368);
        *P_LVALUE_368 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_369 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_369);
            *P_LVALUE_369 = PTMP_tmp3_27;
            PTMP_tmp3_27 = NULL;
        }
        
        PrtFreeValue(P_RedirectLastClientRequestToClusterManager_IMPL(context, _P_GEN_funargs));
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_49;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_49;
        }
        
        PRT_VALUE** P_LVALUE_370 = &(PTMP_tmp4_22);
        PrtFreeValue(*P_LVALUE_370);
        *P_LVALUE_370 = PrtCloneValue((&P_EVENT_BecomeFollower.value));
        
        PrtRaise(p_this, PTMP_tmp4_22, 0);
        *(&(PTMP_tmp4_22)) = NULL;
        goto p_return_49;
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_371 = &(PTMP_tmp5_15);
        PrtFreeValue(*P_LVALUE_371);
        *P_LVALUE_371 = PrtTupleGet(*P_VAR_request_17, 0);
        
        PRT_VALUE** P_LVALUE_372 = &(PTMP_tmp6_14);
        PrtFreeValue(*P_LVALUE_372);
        *P_LVALUE_372 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp5_15, p_this->varValues[6]));
        
        if (PrtPrimGetBool(PTMP_tmp6_14))
        {
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_373 = &(PTMP_tmp7_9);
            PrtFreeValue(*P_LVALUE_373);
            *P_LVALUE_373 = PrtTupleGet(*P_VAR_request_17, 1);
            
            if (PrtPrimGetBool(PTMP_tmp7_9))
            {
                PRT_VALUE** P_LVALUE_374 = &(PTMP_tmp8_6);
                PrtFreeValue(*P_LVALUE_374);
                *P_LVALUE_374 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_375 = &(PTMP_tmp9_6);
                PrtFreeValue(*P_LVALUE_375);
                *P_LVALUE_375 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                
                PRT_VALUE** P_LVALUE_376 = &(PTMP_tmp10_6);
                PrtFreeValue(*P_LVALUE_376);
                *P_LVALUE_376 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp9_6) + PrtPrimGetInt((&P_LIT_INT32_26)));
                
                {
                    PRT_VALUE** P_LVALUE_377 = &(*(PrtMapGetLValue(p_this->varValues[11], PTMP_tmp8_6, PRT_TRUE, &P_GEND_TYPE_MKmVi)));
                    PrtFreeValue(*P_LVALUE_377);
                    *P_LVALUE_377 = PTMP_tmp10_6;
                    PTMP_tmp10_6 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_378 = &(PTMP_tmp11_6);
                PrtFreeValue(*P_LVALUE_378);
                *P_LVALUE_378 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_379 = &(PTMP_tmp12_5);
                PrtFreeValue(*P_LVALUE_379);
                *P_LVALUE_379 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                
                {
                    PRT_VALUE** P_LVALUE_380 = &(*(PrtMapGetLValue(p_this->varValues[12], PTMP_tmp11_6, PRT_TRUE, &P_GEND_TYPE_MKmVi)));
                    PrtFreeValue(*P_LVALUE_380);
                    *P_LVALUE_380 = PTMP_tmp12_5;
                    PTMP_tmp12_5 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_381 = &(PTMP_tmp13_5);
                PrtFreeValue(*P_LVALUE_381);
                *P_LVALUE_381 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[13]) + PrtPrimGetInt((&P_LIT_INT32_26)));
                
                {
                    PRT_VALUE** P_LVALUE_382 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_382);
                    *P_LVALUE_382 = PTMP_tmp13_5;
                    PTMP_tmp13_5 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_383 = &(PTMP_tmp14_3);
                PrtFreeValue(*P_LVALUE_383);
                *P_LVALUE_383 = PrtTupleGet(*P_VAR_request_17, 3);
                
                PRT_VALUE** P_LVALUE_384 = &(PTMP_tmp15_3);
                PrtFreeValue(*P_LVALUE_384);
                *P_LVALUE_384 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp14_3, (&_P_GEN_null)));
                
                PRT_VALUE** P_LVALUE_385 = &(PTMP_tmp20_2);
                PrtFreeValue(*P_LVALUE_385);
                *P_LVALUE_385 = PrtCloneValue(PTMP_tmp15_3);
                
                if (PrtPrimGetBool(PTMP_tmp20_2))
                {
                    PRT_VALUE** P_LVALUE_386 = &(PTMP_tmp16_3);
                    PrtFreeValue(*P_LVALUE_386);
                    *P_LVALUE_386 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[2]));
                    
                    PRT_VALUE** P_LVALUE_387 = &(PTMP_tmp17_3);
                    PrtFreeValue(*P_LVALUE_387);
                    *P_LVALUE_387 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp16_3) / PrtPrimGetInt((&P_LIT_INT32_27)));
                    
                    PRT_VALUE** P_LVALUE_388 = &(PTMP_tmp18_2);
                    PrtFreeValue(*P_LVALUE_388);
                    *P_LVALUE_388 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp17_3) + PrtPrimGetInt((&P_LIT_INT32_26)));
                    
                    PRT_VALUE** P_LVALUE_389 = &(PTMP_tmp19_2);
                    PrtFreeValue(*P_LVALUE_389);
                    *P_LVALUE_389 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[13]) >= PrtPrimGetInt(PTMP_tmp18_2));
                    
                    PRT_VALUE** P_LVALUE_390 = &(PTMP_tmp20_2);
                    PrtFreeValue(*P_LVALUE_390);
                    *P_LVALUE_390 = PrtCloneValue(PTMP_tmp19_2);
                    
                }
                
                
                if (PrtPrimGetBool(PTMP_tmp20_2))
                {
                    PRT_VALUE** P_LVALUE_391 = &(PTMP_tmp21_2);
                    PrtFreeValue(*P_LVALUE_391);
                    *P_LVALUE_391 = PrtTupleGet(*P_VAR_request_17, 2);
                    
                    PRT_VALUE** P_LVALUE_392 = &(PTMP_tmp22_2);
                    PrtFreeValue(*P_LVALUE_392);
                    *P_LVALUE_392 = PrtMapGet(p_this->varValues[12], PTMP_tmp21_2);
                    
                    {
                        PRT_VALUE** P_LVALUE_393 = &(P_VAR_commitIndex);
                        PrtFreeValue(*P_LVALUE_393);
                        *P_LVALUE_393 = PTMP_tmp22_2;
                        PTMP_tmp22_2 = NULL;
                    }
                    
                    PRT_VALUE** P_LVALUE_394 = &(PTMP_tmp23_2);
                    PrtFreeValue(*P_LVALUE_394);
                    *P_LVALUE_394 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_commitIndex) > PrtPrimGetInt(p_this->varValues[9]));
                    
                    PRT_VALUE** P_LVALUE_395 = &(PTMP_tmp28_2);
                    PrtFreeValue(*P_LVALUE_395);
                    *P_LVALUE_395 = PrtCloneValue(PTMP_tmp23_2);
                    
                    if (PrtPrimGetBool(PTMP_tmp28_2))
                    {
                        PRT_VALUE** P_LVALUE_396 = &(PTMP_tmp24_2);
                        PrtFreeValue(*P_LVALUE_396);
                        *P_LVALUE_396 = PrtMkIntValue(PrtPrimGetInt(P_VAR_commitIndex) - PrtPrimGetInt((&P_LIT_INT32_26)));
                        
                        PRT_VALUE** P_LVALUE_397 = &(PTMP_tmp25_2);
                        PrtFreeValue(*P_LVALUE_397);
                        *P_LVALUE_397 = PrtSeqGet(p_this->varValues[8], PTMP_tmp24_2);
                        
                        PRT_VALUE** P_LVALUE_398 = &(PTMP_tmp26_2);
                        PrtFreeValue(*P_LVALUE_398);
                        *P_LVALUE_398 = PrtTupleGet(PTMP_tmp25_2, 0);
                        
                        PRT_VALUE** P_LVALUE_399 = &(PTMP_tmp27_2);
                        PrtFreeValue(*P_LVALUE_399);
                        *P_LVALUE_399 = PrtMkBoolValue(PrtIsEqualValue(PTMP_tmp26_2, p_this->varValues[6]));
                        
                        PRT_VALUE** P_LVALUE_400 = &(PTMP_tmp28_2);
                        PrtFreeValue(*P_LVALUE_400);
                        *P_LVALUE_400 = PrtCloneValue(PTMP_tmp27_2);
                        
                    }
                    
                    
                    if (PrtPrimGetBool(PTMP_tmp28_2))
                    {
                        PRT_VALUE** P_LVALUE_401 = &(p_this->varValues[9]);
                        PrtFreeValue(*P_LVALUE_401);
                        *P_LVALUE_401 = PrtCloneValue(P_VAR_commitIndex);
                        
                    }
                    
                    else
                    {
                    }
                    
                    
                    PRT_VALUE** P_LVALUE_402 = &(p_this->varValues[13]);
                    PrtFreeValue(*P_LVALUE_402);
                    *P_LVALUE_402 = PrtCloneValue((&P_LIT_INT32_28));
                    
                    PRT_VALUE** P_LVALUE_403 = &(PTMP_tmp29_2);
                    PrtFreeValue(*P_LVALUE_403);
                    *P_LVALUE_403 = PrtMkDefaultValue(&P_GEND_TYPE_m);
                    
                    PRT_VALUE** P_LVALUE_404 = &(PTMP_tmp30_1);
                    PrtFreeValue(*P_LVALUE_404);
                    *P_LVALUE_404 = PrtMkDefaultValue(&P_GEND_TYPE_i);
                    
                    PRT_VALUE** P_LVALUE_405 = &(PTMP_tmp31_1);
                    PrtFreeValue(*P_LVALUE_405);
                    *P_LVALUE_405 = (PrtMkTuple(&P_GEND_TYPE_T2mi_1, &(PTMP_tmp29_2), &(PTMP_tmp30_1)));
                    
                    {
                        PRT_VALUE** P_LVALUE_406 = &(p_this->varValues[14]);
                        PrtFreeValue(*P_LVALUE_406);
                        *P_LVALUE_406 = PTMP_tmp31_1;
                        PTMP_tmp31_1 = NULL;
                    }
                    
                    PRT_VALUE** P_LVALUE_407 = &(PTMP_tmp32_1);
                    PrtFreeValue(*P_LVALUE_407);
                    *P_LVALUE_407 = PrtTupleGet(*P_VAR_request_17, 3);
                    
                    PRT_VALUE** P_LVALUE_408 = &(PTMP_tmp33_1);
                    PrtFreeValue(*P_LVALUE_408);
                    *P_LVALUE_408 = PrtCloneValue(PTMP_tmp32_1);
                    
                    PRT_VALUE** P_LVALUE_409 = &(PTMP_tmp34_1);
                    PrtFreeValue(*P_LVALUE_409);
                    *P_LVALUE_409 = PrtCloneValue((&P_EVENT_Response.value));
                    
                    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp33_1), PTMP_tmp34_1, 0);
                    *(&(PTMP_tmp34_1)) = NULL;
                    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                        goto p_return_49;
                    }
                    if (p_this->isHalted == PRT_TRUE) {
                        PrtFreeValue(_P_GEN_retval);
                        _P_GEN_retval = NULL;
                        goto p_return_49;
                    }
                    
                }
                
                else
                {
                }
                
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_410 = &(PTMP_tmp35);
                PrtFreeValue(*P_LVALUE_410);
                *P_LVALUE_410 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_411 = &(PTMP_tmp36);
                PrtFreeValue(*P_LVALUE_411);
                *P_LVALUE_411 = PrtMapGet(p_this->varValues[11], PTMP_tmp35);
                
                PRT_VALUE** P_LVALUE_412 = &(PTMP_tmp37);
                PrtFreeValue(*P_LVALUE_412);
                *P_LVALUE_412 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp36) > PrtPrimGetInt((&P_LIT_INT32_26)));
                
                if (PrtPrimGetBool(PTMP_tmp37))
                {
                    PRT_VALUE** P_LVALUE_413 = &(PTMP_tmp38);
                    PrtFreeValue(*P_LVALUE_413);
                    *P_LVALUE_413 = PrtTupleGet(*P_VAR_request_17, 2);
                    
                    PRT_VALUE** P_LVALUE_414 = &(PTMP_tmp39);
                    PrtFreeValue(*P_LVALUE_414);
                    *P_LVALUE_414 = PrtTupleGet(*P_VAR_request_17, 2);
                    
                    PRT_VALUE** P_LVALUE_415 = &(PTMP_tmp40);
                    PrtFreeValue(*P_LVALUE_415);
                    *P_LVALUE_415 = PrtMapGet(p_this->varValues[11], PTMP_tmp39);
                    
                    PRT_VALUE** P_LVALUE_416 = &(PTMP_tmp41);
                    PrtFreeValue(*P_LVALUE_416);
                    *P_LVALUE_416 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp40) - PrtPrimGetInt((&P_LIT_INT32_26)));
                    
                    {
                        PRT_VALUE** P_LVALUE_417 = &(*(PrtMapGetLValue(p_this->varValues[11], PTMP_tmp38, PRT_TRUE, &P_GEND_TYPE_MKmVi)));
                        PrtFreeValue(*P_LVALUE_417);
                        *P_LVALUE_417 = PTMP_tmp41;
                        PTMP_tmp41 = NULL;
                    }
                    
                }
                
                else
                {
                }
                
                
                PRT_VALUE** P_LVALUE_418 = &(PTMP_tmp42);
                PrtFreeValue(*P_LVALUE_418);
                *P_LVALUE_418 = PrtMkDefaultValue(&P_GEND_TYPE_ST2ii);
                
                {
                    PRT_VALUE** P_LVALUE_419 = &(P_VAR_logsAppend_1);
                    PrtFreeValue(*P_LVALUE_419);
                    *P_LVALUE_419 = PTMP_tmp42;
                    PTMP_tmp42 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_420 = &(PTMP_tmp43);
                PrtFreeValue(*P_LVALUE_420);
                *P_LVALUE_420 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_421 = &(PTMP_tmp44);
                PrtFreeValue(*P_LVALUE_421);
                *P_LVALUE_421 = PrtMapGet(p_this->varValues[11], PTMP_tmp43);
                
                PRT_VALUE** P_LVALUE_422 = &(PTMP_tmp45);
                PrtFreeValue(*P_LVALUE_422);
                *P_LVALUE_422 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp44) - PrtPrimGetInt((&P_LIT_INT32_26)));
                
                {
                    PRT_VALUE** P_LVALUE_423 = &(P_VAR_idx_6);
                    PrtFreeValue(*P_LVALUE_423);
                    *P_LVALUE_423 = PTMP_tmp45;
                    PTMP_tmp45 = NULL;
                }
                
                while (PrtPrimGetBool((&P_LIT_BOOLEAN_8)))
                {
                    PRT_VALUE** P_LVALUE_424 = &(PTMP_tmp46);
                    PrtFreeValue(*P_LVALUE_424);
                    *P_LVALUE_424 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                    
                    PRT_VALUE** P_LVALUE_425 = &(PTMP_tmp47);
                    PrtFreeValue(*P_LVALUE_425);
                    *P_LVALUE_425 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_6) < PrtPrimGetInt(PTMP_tmp46));
                    
                    PRT_VALUE** P_LVALUE_426 = &(PTMP_tmp48);
                    PrtFreeValue(*P_LVALUE_426);
                    *P_LVALUE_426 = PrtCloneValue(PTMP_tmp47);
                    
                    if (PrtPrimGetBool(PTMP_tmp48))
                    {
                    }
                    
                    else
                    {
                        break;
                        
                    }
                    
                    
                    PRT_VALUE** P_LVALUE_427 = &(PTMP_tmp49);
                    PrtFreeValue(*P_LVALUE_427);
                    *P_LVALUE_427 = PrtSeqGet(p_this->varValues[8], P_VAR_idx_6);
                    
                    PrtSeqInsertEx(P_VAR_logsAppend_1, P_VAR_idx_6, PTMP_tmp49, PRT_FALSE);
                    *(&(PTMP_tmp49)) = NULL;
                    
                    PRT_VALUE** P_LVALUE_428 = &(PTMP_tmp50);
                    PrtFreeValue(*P_LVALUE_428);
                    *P_LVALUE_428 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_6) + PrtPrimGetInt((&P_LIT_INT32_26)));
                    
                    {
                        PRT_VALUE** P_LVALUE_429 = &(P_VAR_idx_6);
                        PrtFreeValue(*P_LVALUE_429);
                        *P_LVALUE_429 = PTMP_tmp50;
                        PTMP_tmp50 = NULL;
                    }
                    
                }
                
                
                PRT_VALUE** P_LVALUE_430 = &(PTMP_tmp51);
                PrtFreeValue(*P_LVALUE_430);
                *P_LVALUE_430 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_431 = &(PTMP_tmp52);
                PrtFreeValue(*P_LVALUE_431);
                *P_LVALUE_431 = PrtMapGet(p_this->varValues[11], PTMP_tmp51);
                
                PRT_VALUE** P_LVALUE_432 = &(PTMP_tmp53);
                PrtFreeValue(*P_LVALUE_432);
                *P_LVALUE_432 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp52) - PrtPrimGetInt((&P_LIT_INT32_26)));
                
                {
                    PRT_VALUE** P_LVALUE_433 = &(P_VAR_prevLogIndex_1);
                    PrtFreeValue(*P_LVALUE_433);
                    *P_LVALUE_433 = PTMP_tmp53;
                    PTMP_tmp53 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_434 = &(PTMP_tmp54);
                PrtFreeValue(*P_LVALUE_434);
                *P_LVALUE_434 = PrtCloneValue(P_VAR_prevLogIndex_1);
                
                PRT_VALUE** P_LVALUE_435 = &(PTMP_tmp55);
                PrtFreeValue(*P_LVALUE_435);
                *P_LVALUE_435 = ((_P_GEN_funargs[0] = &(PTMP_tmp54)), (_P_GEN_funval = P_GetLogTermForIndex_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp54), PTMP_tmp54 = NULL), (_P_GEN_funval));
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_49;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_49;
                }
                
                {
                    PRT_VALUE** P_LVALUE_436 = &(P_VAR_prevLogTerm_1);
                    PrtFreeValue(*P_LVALUE_436);
                    *P_LVALUE_436 = PTMP_tmp55;
                    PTMP_tmp55 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_437 = &(PTMP_tmp56);
                PrtFreeValue(*P_LVALUE_437);
                *P_LVALUE_437 = PrtTupleGet(*P_VAR_request_17, 2);
                
                PRT_VALUE** P_LVALUE_438 = &(PTMP_tmp57);
                PrtFreeValue(*P_LVALUE_438);
                *P_LVALUE_438 = PrtCloneValue(PTMP_tmp56);
                
                PRT_VALUE** P_LVALUE_439 = &(PTMP_tmp58);
                PrtFreeValue(*P_LVALUE_439);
                *P_LVALUE_439 = PrtCloneValue((&P_EVENT_AppendEntriesRequest.value));
                
                PRT_VALUE** P_LVALUE_440 = &(PTMP_tmp59);
                PrtFreeValue(*P_LVALUE_440);
                *P_LVALUE_440 = PrtCloneValue(p_this->varValues[6]);
                
                PRT_VALUE** P_LVALUE_441 = &(PTMP_tmp60);
                PrtFreeValue(*P_LVALUE_441);
                *P_LVALUE_441 = PrtCloneValue((p_this->id));
                
                PRT_VALUE** P_LVALUE_442 = &(PTMP_tmp61);
                PrtFreeValue(*P_LVALUE_442);
                *P_LVALUE_442 = PrtCloneValue(P_VAR_prevLogIndex_1);
                
                PRT_VALUE** P_LVALUE_443 = &(PTMP_tmp62);
                PrtFreeValue(*P_LVALUE_443);
                *P_LVALUE_443 = PrtCloneValue(P_VAR_prevLogTerm_1);
                
                PRT_VALUE** P_LVALUE_444 = &(PTMP_tmp63);
                PrtFreeValue(*P_LVALUE_444);
                *P_LVALUE_444 = PrtCloneValue(p_this->varValues[8]);
                
                PRT_VALUE** P_LVALUE_445 = &(PTMP_tmp64);
                PrtFreeValue(*P_LVALUE_445);
                *P_LVALUE_445 = PrtCloneValue(p_this->varValues[9]);
                
                PRT_VALUE** P_LVALUE_446 = &(PTMP_tmp65);
                PrtFreeValue(*P_LVALUE_446);
                *P_LVALUE_446 = PrtTupleGet(*P_VAR_request_17, 3);
                
                PRT_VALUE** P_LVALUE_447 = &(PTMP_tmp66);
                PrtFreeValue(*P_LVALUE_447);
                *P_LVALUE_447 = (PrtMkTuple(&P_GEND_TYPE_T7iRiiST2iiim, &(PTMP_tmp59), &(PTMP_tmp60), &(PTMP_tmp61), &(PTMP_tmp62), &(PTMP_tmp63), &(PTMP_tmp64), &(PTMP_tmp65)));
                
                PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp57), PTMP_tmp58, 1, &(PTMP_tmp66));
                *(&(PTMP_tmp58)) = NULL;
                if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                    goto p_return_49;
                }
                if (p_this->isHalted == PRT_TRUE) {
                    PrtFreeValue(_P_GEN_retval);
                    _P_GEN_retval = NULL;
                    goto p_return_49;
                }
                
            }
            
            
        }
        
        
    }
    
    
p_return_49: ;
    PrtFreeValue(P_VAR_commitIndex); P_VAR_commitIndex = NULL;
    PrtFreeValue(P_VAR_logsAppend_1); P_VAR_logsAppend_1 = NULL;
    PrtFreeValue(P_VAR_prevLogIndex_1); P_VAR_prevLogIndex_1 = NULL;
    PrtFreeValue(P_VAR_prevLogTerm_1); P_VAR_prevLogTerm_1 = NULL;
    PrtFreeValue(P_VAR_idx_6); P_VAR_idx_6 = NULL;
    PrtFreeValue(PTMP_tmp0_46); PTMP_tmp0_46 = NULL;
    PrtFreeValue(PTMP_tmp1_33); PTMP_tmp1_33 = NULL;
    PrtFreeValue(PTMP_tmp2_31); PTMP_tmp2_31 = NULL;
    PrtFreeValue(PTMP_tmp3_27); PTMP_tmp3_27 = NULL;
    PrtFreeValue(PTMP_tmp4_22); PTMP_tmp4_22 = NULL;
    PrtFreeValue(PTMP_tmp5_15); PTMP_tmp5_15 = NULL;
    PrtFreeValue(PTMP_tmp6_14); PTMP_tmp6_14 = NULL;
    PrtFreeValue(PTMP_tmp7_9); PTMP_tmp7_9 = NULL;
    PrtFreeValue(PTMP_tmp8_6); PTMP_tmp8_6 = NULL;
    PrtFreeValue(PTMP_tmp9_6); PTMP_tmp9_6 = NULL;
    PrtFreeValue(PTMP_tmp10_6); PTMP_tmp10_6 = NULL;
    PrtFreeValue(PTMP_tmp11_6); PTMP_tmp11_6 = NULL;
    PrtFreeValue(PTMP_tmp12_5); PTMP_tmp12_5 = NULL;
    PrtFreeValue(PTMP_tmp13_5); PTMP_tmp13_5 = NULL;
    PrtFreeValue(PTMP_tmp14_3); PTMP_tmp14_3 = NULL;
    PrtFreeValue(PTMP_tmp15_3); PTMP_tmp15_3 = NULL;
    PrtFreeValue(PTMP_tmp16_3); PTMP_tmp16_3 = NULL;
    PrtFreeValue(PTMP_tmp17_3); PTMP_tmp17_3 = NULL;
    PrtFreeValue(PTMP_tmp18_2); PTMP_tmp18_2 = NULL;
    PrtFreeValue(PTMP_tmp19_2); PTMP_tmp19_2 = NULL;
    PrtFreeValue(PTMP_tmp20_2); PTMP_tmp20_2 = NULL;
    PrtFreeValue(PTMP_tmp21_2); PTMP_tmp21_2 = NULL;
    PrtFreeValue(PTMP_tmp22_2); PTMP_tmp22_2 = NULL;
    PrtFreeValue(PTMP_tmp23_2); PTMP_tmp23_2 = NULL;
    PrtFreeValue(PTMP_tmp24_2); PTMP_tmp24_2 = NULL;
    PrtFreeValue(PTMP_tmp25_2); PTMP_tmp25_2 = NULL;
    PrtFreeValue(PTMP_tmp26_2); PTMP_tmp26_2 = NULL;
    PrtFreeValue(PTMP_tmp27_2); PTMP_tmp27_2 = NULL;
    PrtFreeValue(PTMP_tmp28_2); PTMP_tmp28_2 = NULL;
    PrtFreeValue(PTMP_tmp29_2); PTMP_tmp29_2 = NULL;
    PrtFreeValue(PTMP_tmp30_1); PTMP_tmp30_1 = NULL;
    PrtFreeValue(PTMP_tmp31_1); PTMP_tmp31_1 = NULL;
    PrtFreeValue(PTMP_tmp32_1); PTMP_tmp32_1 = NULL;
    PrtFreeValue(PTMP_tmp33_1); PTMP_tmp33_1 = NULL;
    PrtFreeValue(PTMP_tmp34_1); PTMP_tmp34_1 = NULL;
    PrtFreeValue(PTMP_tmp35); PTMP_tmp35 = NULL;
    PrtFreeValue(PTMP_tmp36); PTMP_tmp36 = NULL;
    PrtFreeValue(PTMP_tmp37); PTMP_tmp37 = NULL;
    PrtFreeValue(PTMP_tmp38); PTMP_tmp38 = NULL;
    PrtFreeValue(PTMP_tmp39); PTMP_tmp39 = NULL;
    PrtFreeValue(PTMP_tmp40); PTMP_tmp40 = NULL;
    PrtFreeValue(PTMP_tmp41); PTMP_tmp41 = NULL;
    PrtFreeValue(PTMP_tmp42); PTMP_tmp42 = NULL;
    PrtFreeValue(PTMP_tmp43); PTMP_tmp43 = NULL;
    PrtFreeValue(PTMP_tmp44); PTMP_tmp44 = NULL;
    PrtFreeValue(PTMP_tmp45); PTMP_tmp45 = NULL;
    PrtFreeValue(PTMP_tmp46); PTMP_tmp46 = NULL;
    PrtFreeValue(PTMP_tmp47); PTMP_tmp47 = NULL;
    PrtFreeValue(PTMP_tmp48); PTMP_tmp48 = NULL;
    PrtFreeValue(PTMP_tmp49); PTMP_tmp49 = NULL;
    PrtFreeValue(PTMP_tmp50); PTMP_tmp50 = NULL;
    PrtFreeValue(PTMP_tmp51); PTMP_tmp51 = NULL;
    PrtFreeValue(PTMP_tmp52); PTMP_tmp52 = NULL;
    PrtFreeValue(PTMP_tmp53); PTMP_tmp53 = NULL;
    PrtFreeValue(PTMP_tmp54); PTMP_tmp54 = NULL;
    PrtFreeValue(PTMP_tmp55); PTMP_tmp55 = NULL;
    PrtFreeValue(PTMP_tmp56); PTMP_tmp56 = NULL;
    PrtFreeValue(PTMP_tmp57); PTMP_tmp57 = NULL;
    PrtFreeValue(PTMP_tmp58); PTMP_tmp58 = NULL;
    PrtFreeValue(PTMP_tmp59); PTMP_tmp59 = NULL;
    PrtFreeValue(PTMP_tmp60); PTMP_tmp60 = NULL;
    PrtFreeValue(PTMP_tmp61); PTMP_tmp61 = NULL;
    PrtFreeValue(PTMP_tmp62); PTMP_tmp62 = NULL;
    PrtFreeValue(PTMP_tmp63); PTMP_tmp63 = NULL;
    PrtFreeValue(PTMP_tmp64); PTMP_tmp64 = NULL;
    PrtFreeValue(PTMP_tmp65); PTMP_tmp65 = NULL;
    PrtFreeValue(PTMP_tmp66); PTMP_tmp66 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RespondAppendEntriesAsLeader =
{
    "RespondAppendEntriesAsLeader",
    &P_RespondAppendEntriesAsLeader_IMPL,
    NULL
};


PRT_VALUE* P_Vote_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_18 = argRefs[0];
    PRT_VALUE* P_VAR_lastLogIndex_2 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_lastLogTerm_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_47 = NULL;
    PRT_VALUE* PTMP_tmp1_34 = NULL;
    PRT_VALUE* PTMP_tmp2_32 = NULL;
    PRT_VALUE* PTMP_tmp3_28 = NULL;
    PRT_VALUE* PTMP_tmp4_23 = NULL;
    PRT_VALUE* PTMP_tmp5_16 = NULL;
    PRT_VALUE* PTMP_tmp6_15 = NULL;
    PRT_VALUE* PTMP_tmp7_10 = NULL;
    PRT_VALUE* PTMP_tmp8_7 = NULL;
    PRT_VALUE* PTMP_tmp9_7 = NULL;
    PRT_VALUE* PTMP_tmp10_7 = NULL;
    PRT_VALUE* PTMP_tmp11_7 = NULL;
    PRT_VALUE* PTMP_tmp12_6 = NULL;
    PRT_VALUE* PTMP_tmp13_6 = NULL;
    PRT_VALUE* PTMP_tmp14_4 = NULL;
    PRT_VALUE* PTMP_tmp15_4 = NULL;
    PRT_VALUE* PTMP_tmp16_4 = NULL;
    PRT_VALUE* PTMP_tmp17_4 = NULL;
    PRT_VALUE* PTMP_tmp18_3 = NULL;
    PRT_VALUE* PTMP_tmp19_3 = NULL;
    PRT_VALUE* PTMP_tmp20_3 = NULL;
    PRT_VALUE* PTMP_tmp21_3 = NULL;
    PRT_VALUE* PTMP_tmp22_3 = NULL;
    PRT_VALUE* PTMP_tmp23_3 = NULL;
    PRT_VALUE* PTMP_tmp24_3 = NULL;
    PRT_VALUE* PTMP_tmp25_3 = NULL;
    PRT_VALUE* PTMP_tmp26_3 = NULL;
    PRT_VALUE* PTMP_tmp27_3 = NULL;
    PRT_VALUE* PTMP_tmp28_3 = NULL;
    PRT_VALUE* PTMP_tmp29_3 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_BOOLEAN_9 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE P_LIT_BOOLEAN_10 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_448 = &(PTMP_tmp0_47);
    PrtFreeValue(*P_LVALUE_448);
    *P_LVALUE_448 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
    
    {
        PRT_VALUE** P_LVALUE_449 = &(P_VAR_lastLogIndex_2);
        PrtFreeValue(*P_LVALUE_449);
        *P_LVALUE_449 = PTMP_tmp0_47;
        PTMP_tmp0_47 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_450 = &(PTMP_tmp1_34);
    PrtFreeValue(*P_LVALUE_450);
    *P_LVALUE_450 = PrtCloneValue(P_VAR_lastLogIndex_2);
    
    PRT_VALUE** P_LVALUE_451 = &(PTMP_tmp2_32);
    PrtFreeValue(*P_LVALUE_451);
    *P_LVALUE_451 = ((_P_GEN_funargs[0] = &(PTMP_tmp1_34)), (_P_GEN_funval = P_GetLogTermForIndex_IMPL(context, _P_GEN_funargs)), (PrtFreeValue(PTMP_tmp1_34), PTMP_tmp1_34 = NULL), (_P_GEN_funval));
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_50;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_50;
    }
    
    {
        PRT_VALUE** P_LVALUE_452 = &(P_VAR_lastLogTerm_1);
        PrtFreeValue(*P_LVALUE_452);
        *P_LVALUE_452 = PTMP_tmp2_32;
        PTMP_tmp2_32 = NULL;
    }
    
    PRT_VALUE** P_LVALUE_453 = &(PTMP_tmp3_28);
    PrtFreeValue(*P_LVALUE_453);
    *P_LVALUE_453 = PrtTupleGet(*P_VAR_request_18, 0);
    
    PRT_VALUE** P_LVALUE_454 = &(PTMP_tmp4_23);
    PrtFreeValue(*P_LVALUE_454);
    *P_LVALUE_454 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp3_28) < PrtPrimGetInt(p_this->varValues[6]));
    
    PRT_VALUE** P_LVALUE_455 = &(PTMP_tmp9_7);
    PrtFreeValue(*P_LVALUE_455);
    *P_LVALUE_455 = PrtCloneValue(PTMP_tmp4_23);
    
    if (PrtPrimGetBool(PTMP_tmp9_7))
    {
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_456 = &(PTMP_tmp5_16);
        PrtFreeValue(*P_LVALUE_456);
        *P_LVALUE_456 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[7], (&_P_GEN_null)));
        
        PRT_VALUE** P_LVALUE_457 = &(PTMP_tmp8_7);
        PrtFreeValue(*P_LVALUE_457);
        *P_LVALUE_457 = PrtCloneValue(PTMP_tmp5_16);
        
        if (PrtPrimGetBool(PTMP_tmp8_7))
        {
            PRT_VALUE** P_LVALUE_458 = &(PTMP_tmp6_15);
            PrtFreeValue(*P_LVALUE_458);
            *P_LVALUE_458 = PrtTupleGet(*P_VAR_request_18, 1);
            
            PRT_VALUE** P_LVALUE_459 = &(PTMP_tmp7_10);
            PrtFreeValue(*P_LVALUE_459);
            *P_LVALUE_459 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[7], PTMP_tmp6_15));
            
            PRT_VALUE** P_LVALUE_460 = &(PTMP_tmp8_7);
            PrtFreeValue(*P_LVALUE_460);
            *P_LVALUE_460 = PrtCloneValue(PTMP_tmp7_10);
            
        }
        
        
        PRT_VALUE** P_LVALUE_461 = &(PTMP_tmp9_7);
        PrtFreeValue(*P_LVALUE_461);
        *P_LVALUE_461 = PrtCloneValue(PTMP_tmp8_7);
        
    }
    
    
    PRT_VALUE** P_LVALUE_462 = &(PTMP_tmp12_6);
    PrtFreeValue(*P_LVALUE_462);
    *P_LVALUE_462 = PrtCloneValue(PTMP_tmp9_7);
    
    if (PrtPrimGetBool(PTMP_tmp12_6))
    {
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_463 = &(PTMP_tmp10_7);
        PrtFreeValue(*P_LVALUE_463);
        *P_LVALUE_463 = PrtTupleGet(*P_VAR_request_18, 2);
        
        PRT_VALUE** P_LVALUE_464 = &(PTMP_tmp11_7);
        PrtFreeValue(*P_LVALUE_464);
        *P_LVALUE_464 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_lastLogIndex_2) > PrtPrimGetInt(PTMP_tmp10_7));
        
        PRT_VALUE** P_LVALUE_465 = &(PTMP_tmp12_6);
        PrtFreeValue(*P_LVALUE_465);
        *P_LVALUE_465 = PrtCloneValue(PTMP_tmp11_7);
        
    }
    
    
    PRT_VALUE** P_LVALUE_466 = &(PTMP_tmp15_4);
    PrtFreeValue(*P_LVALUE_466);
    *P_LVALUE_466 = PrtCloneValue(PTMP_tmp12_6);
    
    if (PrtPrimGetBool(PTMP_tmp15_4))
    {
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_467 = &(PTMP_tmp13_6);
        PrtFreeValue(*P_LVALUE_467);
        *P_LVALUE_467 = PrtTupleGet(*P_VAR_request_18, 3);
        
        PRT_VALUE** P_LVALUE_468 = &(PTMP_tmp14_4);
        PrtFreeValue(*P_LVALUE_468);
        *P_LVALUE_468 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_lastLogTerm_1) > PrtPrimGetInt(PTMP_tmp13_6));
        
        PRT_VALUE** P_LVALUE_469 = &(PTMP_tmp15_4);
        PrtFreeValue(*P_LVALUE_469);
        *P_LVALUE_469 = PrtCloneValue(PTMP_tmp14_4);
        
    }
    
    
    if (PrtPrimGetBool(PTMP_tmp15_4))
    {
        PRT_VALUE** P_LVALUE_470 = &(PTMP_tmp16_4);
        PrtFreeValue(*P_LVALUE_470);
        *P_LVALUE_470 = PrtTupleGet(*P_VAR_request_18, 1);
        
        PRT_VALUE** P_LVALUE_471 = &(PTMP_tmp17_4);
        PrtFreeValue(*P_LVALUE_471);
        *P_LVALUE_471 = PrtCloneValue(PTMP_tmp16_4);
        
        PRT_VALUE** P_LVALUE_472 = &(PTMP_tmp18_3);
        PrtFreeValue(*P_LVALUE_472);
        *P_LVALUE_472 = PrtCloneValue((&P_EVENT_VoteResponse.value));
        
        PRT_VALUE** P_LVALUE_473 = &(PTMP_tmp19_3);
        PrtFreeValue(*P_LVALUE_473);
        *P_LVALUE_473 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_474 = &(PTMP_tmp20_3);
        PrtFreeValue(*P_LVALUE_474);
        *P_LVALUE_474 = PrtCloneValue((&P_LIT_BOOLEAN_9));
        
        PRT_VALUE** P_LVALUE_475 = &(PTMP_tmp21_3);
        PrtFreeValue(*P_LVALUE_475);
        *P_LVALUE_475 = (PrtMkTuple(&P_GEND_TYPE_T2ib, &(PTMP_tmp19_3), &(PTMP_tmp20_3)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp17_4), PTMP_tmp18_3, 1, &(PTMP_tmp21_3));
        *(&(PTMP_tmp18_3)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_50;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_50;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_476 = &(PTMP_tmp22_3);
        PrtFreeValue(*P_LVALUE_476);
        *P_LVALUE_476 = PrtTupleGet(*P_VAR_request_18, 1);
        
        {
            PRT_VALUE** P_LVALUE_477 = &(p_this->varValues[7]);
            PrtFreeValue(*P_LVALUE_477);
            *P_LVALUE_477 = PTMP_tmp22_3;
            PTMP_tmp22_3 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_478 = &(PTMP_tmp23_3);
        PrtFreeValue(*P_LVALUE_478);
        *P_LVALUE_478 = PrtMkDefaultValue(&P_GEND_TYPE_m);
        
        {
            PRT_VALUE** P_LVALUE_479 = &(p_this->varValues[3]);
            PrtFreeValue(*P_LVALUE_479);
            *P_LVALUE_479 = PTMP_tmp23_3;
            PTMP_tmp23_3 = NULL;
        }
        
        PRT_VALUE** P_LVALUE_480 = &(PTMP_tmp24_3);
        PrtFreeValue(*P_LVALUE_480);
        *P_LVALUE_480 = PrtTupleGet(*P_VAR_request_18, 1);
        
        PRT_VALUE** P_LVALUE_481 = &(PTMP_tmp25_3);
        PrtFreeValue(*P_LVALUE_481);
        *P_LVALUE_481 = PrtCloneValue(PTMP_tmp24_3);
        
        PRT_VALUE** P_LVALUE_482 = &(PTMP_tmp26_3);
        PrtFreeValue(*P_LVALUE_482);
        *P_LVALUE_482 = PrtCloneValue((&P_EVENT_VoteResponse.value));
        
        PRT_VALUE** P_LVALUE_483 = &(PTMP_tmp27_3);
        PrtFreeValue(*P_LVALUE_483);
        *P_LVALUE_483 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_484 = &(PTMP_tmp28_3);
        PrtFreeValue(*P_LVALUE_484);
        *P_LVALUE_484 = PrtCloneValue((&P_LIT_BOOLEAN_10));
        
        PRT_VALUE** P_LVALUE_485 = &(PTMP_tmp29_3);
        PrtFreeValue(*P_LVALUE_485);
        *P_LVALUE_485 = (PrtMkTuple(&P_GEND_TYPE_T2ib, &(PTMP_tmp27_3), &(PTMP_tmp28_3)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp25_3), PTMP_tmp26_3, 1, &(PTMP_tmp29_3));
        *(&(PTMP_tmp26_3)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_50;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_50;
        }
        
    }
    
    
p_return_50: ;
    PrtFreeValue(P_VAR_lastLogIndex_2); P_VAR_lastLogIndex_2 = NULL;
    PrtFreeValue(P_VAR_lastLogTerm_1); P_VAR_lastLogTerm_1 = NULL;
    PrtFreeValue(PTMP_tmp0_47); PTMP_tmp0_47 = NULL;
    PrtFreeValue(PTMP_tmp1_34); PTMP_tmp1_34 = NULL;
    PrtFreeValue(PTMP_tmp2_32); PTMP_tmp2_32 = NULL;
    PrtFreeValue(PTMP_tmp3_28); PTMP_tmp3_28 = NULL;
    PrtFreeValue(PTMP_tmp4_23); PTMP_tmp4_23 = NULL;
    PrtFreeValue(PTMP_tmp5_16); PTMP_tmp5_16 = NULL;
    PrtFreeValue(PTMP_tmp6_15); PTMP_tmp6_15 = NULL;
    PrtFreeValue(PTMP_tmp7_10); PTMP_tmp7_10 = NULL;
    PrtFreeValue(PTMP_tmp8_7); PTMP_tmp8_7 = NULL;
    PrtFreeValue(PTMP_tmp9_7); PTMP_tmp9_7 = NULL;
    PrtFreeValue(PTMP_tmp10_7); PTMP_tmp10_7 = NULL;
    PrtFreeValue(PTMP_tmp11_7); PTMP_tmp11_7 = NULL;
    PrtFreeValue(PTMP_tmp12_6); PTMP_tmp12_6 = NULL;
    PrtFreeValue(PTMP_tmp13_6); PTMP_tmp13_6 = NULL;
    PrtFreeValue(PTMP_tmp14_4); PTMP_tmp14_4 = NULL;
    PrtFreeValue(PTMP_tmp15_4); PTMP_tmp15_4 = NULL;
    PrtFreeValue(PTMP_tmp16_4); PTMP_tmp16_4 = NULL;
    PrtFreeValue(PTMP_tmp17_4); PTMP_tmp17_4 = NULL;
    PrtFreeValue(PTMP_tmp18_3); PTMP_tmp18_3 = NULL;
    PrtFreeValue(PTMP_tmp19_3); PTMP_tmp19_3 = NULL;
    PrtFreeValue(PTMP_tmp20_3); PTMP_tmp20_3 = NULL;
    PrtFreeValue(PTMP_tmp21_3); PTMP_tmp21_3 = NULL;
    PrtFreeValue(PTMP_tmp22_3); PTMP_tmp22_3 = NULL;
    PrtFreeValue(PTMP_tmp23_3); PTMP_tmp23_3 = NULL;
    PrtFreeValue(PTMP_tmp24_3); PTMP_tmp24_3 = NULL;
    PrtFreeValue(PTMP_tmp25_3); PTMP_tmp25_3 = NULL;
    PrtFreeValue(PTMP_tmp26_3); PTMP_tmp26_3 = NULL;
    PrtFreeValue(PTMP_tmp27_3); PTMP_tmp27_3 = NULL;
    PrtFreeValue(PTMP_tmp28_3); PTMP_tmp28_3 = NULL;
    PrtFreeValue(PTMP_tmp29_3); PTMP_tmp29_3 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_Vote =
{
    "Vote",
    &P_Vote_IMPL,
    NULL
};


PRT_VALUE* P_AppendEntries_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE** P_VAR_request_19 = argRefs[0];
    PRT_VALUE* P_VAR_currentIndex = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_idx_7 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_decIdx = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* P_VAR_logEntry = PrtMkDefaultValue(&P_GEND_TYPE_T2ii);
    PRT_VALUE* PTMP_tmp0_48 = NULL;
    PRT_VALUE* PTMP_tmp1_35 = NULL;
    PRT_VALUE* PTMP_tmp2_33 = NULL;
    PRT_VALUE* PTMP_tmp3_29 = NULL;
    PRT_VALUE* PTMP_tmp4_24 = NULL;
    PRT_VALUE* PTMP_tmp5_17 = NULL;
    PRT_VALUE* PTMP_tmp6_16 = NULL;
    PRT_VALUE* PTMP_tmp7_11 = NULL;
    PRT_VALUE* PTMP_tmp8_8 = NULL;
    PRT_VALUE* PTMP_tmp9_8 = NULL;
    PRT_VALUE* PTMP_tmp10_8 = NULL;
    PRT_VALUE* PTMP_tmp11_8 = NULL;
    PRT_VALUE* PTMP_tmp12_7 = NULL;
    PRT_VALUE* PTMP_tmp13_7 = NULL;
    PRT_VALUE* PTMP_tmp14_5 = NULL;
    PRT_VALUE* PTMP_tmp15_5 = NULL;
    PRT_VALUE* PTMP_tmp16_5 = NULL;
    PRT_VALUE* PTMP_tmp17_5 = NULL;
    PRT_VALUE* PTMP_tmp18_4 = NULL;
    PRT_VALUE* PTMP_tmp19_4 = NULL;
    PRT_VALUE* PTMP_tmp20_4 = NULL;
    PRT_VALUE* PTMP_tmp21_4 = NULL;
    PRT_VALUE* PTMP_tmp22_4 = NULL;
    PRT_VALUE* PTMP_tmp23_4 = NULL;
    PRT_VALUE* PTMP_tmp24_4 = NULL;
    PRT_VALUE* PTMP_tmp25_4 = NULL;
    PRT_VALUE* PTMP_tmp26_4 = NULL;
    PRT_VALUE* PTMP_tmp27_4 = NULL;
    PRT_VALUE* PTMP_tmp28_4 = NULL;
    PRT_VALUE* PTMP_tmp29_4 = NULL;
    PRT_VALUE* PTMP_tmp30_2 = NULL;
    PRT_VALUE* PTMP_tmp31_2 = NULL;
    PRT_VALUE* PTMP_tmp32_2 = NULL;
    PRT_VALUE* PTMP_tmp33_2 = NULL;
    PRT_VALUE* PTMP_tmp34_2 = NULL;
    PRT_VALUE* PTMP_tmp35_1 = NULL;
    PRT_VALUE* PTMP_tmp36_1 = NULL;
    PRT_VALUE* PTMP_tmp37_1 = NULL;
    PRT_VALUE* PTMP_tmp38_1 = NULL;
    PRT_VALUE* PTMP_tmp39_1 = NULL;
    PRT_VALUE* PTMP_tmp40_1 = NULL;
    PRT_VALUE* PTMP_tmp41_1 = NULL;
    PRT_VALUE* PTMP_tmp42_1 = NULL;
    PRT_VALUE* PTMP_tmp43_1 = NULL;
    PRT_VALUE* PTMP_tmp44_1 = NULL;
    PRT_VALUE* PTMP_tmp45_1 = NULL;
    PRT_VALUE* PTMP_tmp46_1 = NULL;
    PRT_VALUE* PTMP_tmp47_1 = NULL;
    PRT_VALUE* PTMP_tmp48_1 = NULL;
    PRT_VALUE* PTMP_tmp49_1 = NULL;
    PRT_VALUE* PTMP_tmp50_1 = NULL;
    PRT_VALUE* PTMP_tmp51_1 = NULL;
    PRT_VALUE* PTMP_tmp52_1 = NULL;
    PRT_VALUE* PTMP_tmp53_1 = NULL;
    PRT_VALUE* PTMP_tmp54_1 = NULL;
    PRT_VALUE* PTMP_tmp55_1 = NULL;
    PRT_VALUE* PTMP_tmp56_1 = NULL;
    PRT_VALUE* PTMP_tmp57_1 = NULL;
    PRT_VALUE* PTMP_tmp58_1 = NULL;
    PRT_VALUE* PTMP_tmp59_1 = NULL;
    PRT_VALUE* PTMP_tmp60_1 = NULL;
    PRT_VALUE* PTMP_tmp61_1 = NULL;
    PRT_VALUE* PTMP_tmp62_1 = NULL;
    PRT_VALUE* PTMP_tmp63_1 = NULL;
    PRT_VALUE* PTMP_tmp64_1 = NULL;
    PRT_VALUE* PTMP_tmp65_1 = NULL;
    PRT_VALUE* PTMP_tmp66_1 = NULL;
    PRT_VALUE* PTMP_tmp67 = NULL;
    PRT_VALUE* PTMP_tmp68 = NULL;
    PRT_VALUE* PTMP_tmp69 = NULL;
    PRT_VALUE* PTMP_tmp70 = NULL;
    PRT_VALUE* PTMP_tmp71 = NULL;
    PRT_VALUE* PTMP_tmp72 = NULL;
    PRT_VALUE* PTMP_tmp73 = NULL;
    PRT_VALUE* PTMP_tmp74 = NULL;
    PRT_VALUE* PTMP_tmp75 = NULL;
    PRT_VALUE* PTMP_tmp76 = NULL;
    PRT_VALUE* PTMP_tmp77 = NULL;
    PRT_VALUE* PTMP_tmp78 = NULL;
    PRT_VALUE* PTMP_tmp79 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_29 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_30 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE P_LIT_BOOLEAN_11 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_FALSE } };
    PRT_VALUE P_LIT_BOOLEAN_12 = { PRT_VALUE_KIND_BOOL, { .bl = PRT_TRUE } };
    PRT_VALUE** P_LVALUE_486 = &(PTMP_tmp0_48);
    PrtFreeValue(*P_LVALUE_486);
    *P_LVALUE_486 = PrtTupleGet(*P_VAR_request_19, 0);
    
    PRT_VALUE** P_LVALUE_487 = &(PTMP_tmp1_35);
    PrtFreeValue(*P_LVALUE_487);
    *P_LVALUE_487 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp0_48) < PrtPrimGetInt(p_this->varValues[6]));
    
    if (PrtPrimGetBool(PTMP_tmp1_35))
    {
        PRT_VALUE** P_LVALUE_488 = &(PTMP_tmp2_33);
        PrtFreeValue(*P_LVALUE_488);
        *P_LVALUE_488 = PrtTupleGet(*P_VAR_request_19, 1);
        
        PRT_VALUE** P_LVALUE_489 = &(PTMP_tmp3_29);
        PrtFreeValue(*P_LVALUE_489);
        *P_LVALUE_489 = PrtCloneValue(PTMP_tmp2_33);
        
        PRT_VALUE** P_LVALUE_490 = &(PTMP_tmp4_24);
        PrtFreeValue(*P_LVALUE_490);
        *P_LVALUE_490 = PrtCloneValue((&P_EVENT_AppendEntriesResponse.value));
        
        PRT_VALUE** P_LVALUE_491 = &(PTMP_tmp5_17);
        PrtFreeValue(*P_LVALUE_491);
        *P_LVALUE_491 = PrtCloneValue(p_this->varValues[6]);
        
        PRT_VALUE** P_LVALUE_492 = &(PTMP_tmp6_16);
        PrtFreeValue(*P_LVALUE_492);
        *P_LVALUE_492 = PrtCloneValue((&P_LIT_BOOLEAN_11));
        
        PRT_VALUE** P_LVALUE_493 = &(PTMP_tmp7_11);
        PrtFreeValue(*P_LVALUE_493);
        *P_LVALUE_493 = PrtCloneValue((p_this->id));
        
        PRT_VALUE** P_LVALUE_494 = &(PTMP_tmp8_8);
        PrtFreeValue(*P_LVALUE_494);
        *P_LVALUE_494 = PrtTupleGet(*P_VAR_request_19, 6);
        
        PRT_VALUE** P_LVALUE_495 = &(PTMP_tmp9_8);
        PrtFreeValue(*P_LVALUE_495);
        *P_LVALUE_495 = (PrtMkTuple(&P_GEND_TYPE_T4ibRm, &(PTMP_tmp5_17), &(PTMP_tmp6_16), &(PTMP_tmp7_11), &(PTMP_tmp8_8)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp3_29), PTMP_tmp4_24, 1, &(PTMP_tmp9_8));
        *(&(PTMP_tmp4_24)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_51;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_51;
        }
        
    }
    
    else
    {
        PRT_VALUE** P_LVALUE_496 = &(PTMP_tmp10_8);
        PrtFreeValue(*P_LVALUE_496);
        *P_LVALUE_496 = PrtTupleGet(*P_VAR_request_19, 2);
        
        PRT_VALUE** P_LVALUE_497 = &(PTMP_tmp11_8);
        PrtFreeValue(*P_LVALUE_497);
        *P_LVALUE_497 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp10_8) > PrtPrimGetInt((&P_LIT_INT32_29)));
        
        PRT_VALUE** P_LVALUE_498 = &(PTMP_tmp22_4);
        PrtFreeValue(*P_LVALUE_498);
        *P_LVALUE_498 = PrtCloneValue(PTMP_tmp11_8);
        
        if (PrtPrimGetBool(PTMP_tmp22_4))
        {
            PRT_VALUE** P_LVALUE_499 = &(PTMP_tmp12_7);
            PrtFreeValue(*P_LVALUE_499);
            *P_LVALUE_499 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
            
            PRT_VALUE** P_LVALUE_500 = &(PTMP_tmp13_7);
            PrtFreeValue(*P_LVALUE_500);
            *P_LVALUE_500 = PrtTupleGet(*P_VAR_request_19, 2);
            
            PRT_VALUE** P_LVALUE_501 = &(PTMP_tmp14_5);
            PrtFreeValue(*P_LVALUE_501);
            *P_LVALUE_501 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp12_7) < PrtPrimGetInt(PTMP_tmp13_7));
            
            PRT_VALUE** P_LVALUE_502 = &(PTMP_tmp21_4);
            PrtFreeValue(*P_LVALUE_502);
            *P_LVALUE_502 = PrtCloneValue(PTMP_tmp14_5);
            
            if (PrtPrimGetBool(PTMP_tmp21_4))
            {
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_503 = &(PTMP_tmp15_5);
                PrtFreeValue(*P_LVALUE_503);
                *P_LVALUE_503 = PrtTupleGet(*P_VAR_request_19, 2);
                
                PRT_VALUE** P_LVALUE_504 = &(PTMP_tmp16_5);
                PrtFreeValue(*P_LVALUE_504);
                *P_LVALUE_504 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp15_5) - PrtPrimGetInt((&P_LIT_INT32_30)));
                
                PRT_VALUE** P_LVALUE_505 = &(PTMP_tmp17_5);
                PrtFreeValue(*P_LVALUE_505);
                *P_LVALUE_505 = PrtSeqGet(p_this->varValues[8], PTMP_tmp16_5);
                
                PRT_VALUE** P_LVALUE_506 = &(PTMP_tmp18_4);
                PrtFreeValue(*P_LVALUE_506);
                *P_LVALUE_506 = PrtTupleGet(PTMP_tmp17_5, 0);
                
                PRT_VALUE** P_LVALUE_507 = &(PTMP_tmp19_4);
                PrtFreeValue(*P_LVALUE_507);
                *P_LVALUE_507 = PrtTupleGet(*P_VAR_request_19, 3);
                
                PRT_VALUE** P_LVALUE_508 = &(PTMP_tmp20_4);
                PrtFreeValue(*P_LVALUE_508);
                *P_LVALUE_508 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp18_4, PTMP_tmp19_4));
                
                PRT_VALUE** P_LVALUE_509 = &(PTMP_tmp21_4);
                PrtFreeValue(*P_LVALUE_509);
                *P_LVALUE_509 = PrtCloneValue(PTMP_tmp20_4);
                
            }
            
            
            PRT_VALUE** P_LVALUE_510 = &(PTMP_tmp22_4);
            PrtFreeValue(*P_LVALUE_510);
            *P_LVALUE_510 = PrtCloneValue(PTMP_tmp21_4);
            
        }
        
        
        if (PrtPrimGetBool(PTMP_tmp22_4))
        {
            PRT_VALUE** P_LVALUE_511 = &(PTMP_tmp23_4);
            PrtFreeValue(*P_LVALUE_511);
            *P_LVALUE_511 = PrtTupleGet(*P_VAR_request_19, 1);
            
            PRT_VALUE** P_LVALUE_512 = &(PTMP_tmp24_4);
            PrtFreeValue(*P_LVALUE_512);
            *P_LVALUE_512 = PrtCloneValue(PTMP_tmp23_4);
            
            PRT_VALUE** P_LVALUE_513 = &(PTMP_tmp25_4);
            PrtFreeValue(*P_LVALUE_513);
            *P_LVALUE_513 = PrtCloneValue((&P_EVENT_AppendEntriesResponse.value));
            
            PRT_VALUE** P_LVALUE_514 = &(PTMP_tmp26_4);
            PrtFreeValue(*P_LVALUE_514);
            *P_LVALUE_514 = PrtCloneValue(p_this->varValues[6]);
            
            PRT_VALUE** P_LVALUE_515 = &(PTMP_tmp27_4);
            PrtFreeValue(*P_LVALUE_515);
            *P_LVALUE_515 = PrtCloneValue((&P_LIT_BOOLEAN_11));
            
            PRT_VALUE** P_LVALUE_516 = &(PTMP_tmp28_4);
            PrtFreeValue(*P_LVALUE_516);
            *P_LVALUE_516 = PrtCloneValue((p_this->id));
            
            PRT_VALUE** P_LVALUE_517 = &(PTMP_tmp29_4);
            PrtFreeValue(*P_LVALUE_517);
            *P_LVALUE_517 = PrtTupleGet(*P_VAR_request_19, 6);
            
            PRT_VALUE** P_LVALUE_518 = &(PTMP_tmp30_2);
            PrtFreeValue(*P_LVALUE_518);
            *P_LVALUE_518 = (PrtMkTuple(&P_GEND_TYPE_T4ibRm, &(PTMP_tmp26_4), &(PTMP_tmp27_4), &(PTMP_tmp28_4), &(PTMP_tmp29_4)));
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp24_4), PTMP_tmp25_4, 1, &(PTMP_tmp30_2));
            *(&(PTMP_tmp25_4)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_51;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_51;
            }
            
        }
        
        else
        {
            PRT_VALUE** P_LVALUE_519 = &(PTMP_tmp31_2);
            PrtFreeValue(*P_LVALUE_519);
            *P_LVALUE_519 = PrtTupleGet(*P_VAR_request_19, 4);
            
            PRT_VALUE** P_LVALUE_520 = &(PTMP_tmp32_2);
            PrtFreeValue(*P_LVALUE_520);
            *P_LVALUE_520 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp31_2));
            
            PRT_VALUE** P_LVALUE_521 = &(PTMP_tmp33_2);
            PrtFreeValue(*P_LVALUE_521);
            *P_LVALUE_521 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp32_2) > PrtPrimGetInt((&P_LIT_INT32_29)));
            
            if (PrtPrimGetBool(PTMP_tmp33_2))
            {
                PRT_VALUE** P_LVALUE_522 = &(PTMP_tmp34_2);
                PrtFreeValue(*P_LVALUE_522);
                *P_LVALUE_522 = PrtTupleGet(*P_VAR_request_19, 2);
                
                PRT_VALUE** P_LVALUE_523 = &(PTMP_tmp35_1);
                PrtFreeValue(*P_LVALUE_523);
                *P_LVALUE_523 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp34_2) + PrtPrimGetInt((&P_LIT_INT32_30)));
                
                {
                    PRT_VALUE** P_LVALUE_524 = &(P_VAR_currentIndex);
                    PrtFreeValue(*P_LVALUE_524);
                    *P_LVALUE_524 = PTMP_tmp35_1;
                    PTMP_tmp35_1 = NULL;
                }
                
                PRT_VALUE** P_LVALUE_525 = &(P_VAR_idx_7);
                PrtFreeValue(*P_LVALUE_525);
                *P_LVALUE_525 = PrtCloneValue((&P_LIT_INT32_29));
                
                while (PrtPrimGetBool((&P_LIT_BOOLEAN_12)))
                {
                    PRT_VALUE** P_LVALUE_526 = &(PTMP_tmp36_1);
                    PrtFreeValue(*P_LVALUE_526);
                    *P_LVALUE_526 = PrtTupleGet(*P_VAR_request_19, 4);
                    
                    PRT_VALUE** P_LVALUE_527 = &(PTMP_tmp37_1);
                    PrtFreeValue(*P_LVALUE_527);
                    *P_LVALUE_527 = PrtMkIntValue(PrtSeqSizeOf(PTMP_tmp36_1));
                    
                    PRT_VALUE** P_LVALUE_528 = &(PTMP_tmp38_1);
                    PrtFreeValue(*P_LVALUE_528);
                    *P_LVALUE_528 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_idx_7) < PrtPrimGetInt(PTMP_tmp37_1));
                    
                    PRT_VALUE** P_LVALUE_529 = &(PTMP_tmp39_1);
                    PrtFreeValue(*P_LVALUE_529);
                    *P_LVALUE_529 = PrtCloneValue(PTMP_tmp38_1);
                    
                    if (PrtPrimGetBool(PTMP_tmp39_1))
                    {
                    }
                    
                    else
                    {
                        break;
                        
                    }
                    
                    
                    PRT_VALUE** P_LVALUE_530 = &(PTMP_tmp40_1);
                    PrtFreeValue(*P_LVALUE_530);
                    *P_LVALUE_530 = PrtTupleGet(*P_VAR_request_19, 4);
                    
                    PRT_VALUE** P_LVALUE_531 = &(PTMP_tmp41_1);
                    PrtFreeValue(*P_LVALUE_531);
                    *P_LVALUE_531 = PrtSeqGet(PTMP_tmp40_1, P_VAR_idx_7);
                    
                    {
                        PRT_VALUE** P_LVALUE_532 = &(P_VAR_logEntry);
                        PrtFreeValue(*P_LVALUE_532);
                        *P_LVALUE_532 = PTMP_tmp41_1;
                        PTMP_tmp41_1 = NULL;
                    }
                    
                    PRT_VALUE** P_LVALUE_533 = &(PTMP_tmp42_1);
                    PrtFreeValue(*P_LVALUE_533);
                    *P_LVALUE_533 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                    
                    PRT_VALUE** P_LVALUE_534 = &(PTMP_tmp43_1);
                    PrtFreeValue(*P_LVALUE_534);
                    *P_LVALUE_534 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp42_1) < PrtPrimGetInt(P_VAR_currentIndex));
                    
                    if (PrtPrimGetBool(PTMP_tmp43_1))
                    {
                        PRT_VALUE** P_LVALUE_535 = &(PTMP_tmp44_1);
                        PrtFreeValue(*P_LVALUE_535);
                        *P_LVALUE_535 = PrtCloneValue(P_VAR_logEntry);
                        
                        PrtSeqInsertEx(p_this->varValues[8], P_VAR_idx_7, PTMP_tmp44_1, PRT_FALSE);
                        *(&(PTMP_tmp44_1)) = NULL;
                        
                    }
                    
                    else
                    {
                        PRT_VALUE** P_LVALUE_536 = &(PTMP_tmp45_1);
                        PrtFreeValue(*P_LVALUE_536);
                        *P_LVALUE_536 = PrtMkIntValue(PrtPrimGetInt(P_VAR_currentIndex) - PrtPrimGetInt((&P_LIT_INT32_30)));
                        
                        PRT_VALUE** P_LVALUE_537 = &(PTMP_tmp46_1);
                        PrtFreeValue(*P_LVALUE_537);
                        *P_LVALUE_537 = PrtSeqGet(p_this->varValues[8], PTMP_tmp45_1);
                        
                        PRT_VALUE** P_LVALUE_538 = &(PTMP_tmp47_1);
                        PrtFreeValue(*P_LVALUE_538);
                        *P_LVALUE_538 = PrtTupleGet(PTMP_tmp46_1, 0);
                        
                        PRT_VALUE** P_LVALUE_539 = &(PTMP_tmp48_1);
                        PrtFreeValue(*P_LVALUE_539);
                        *P_LVALUE_539 = PrtTupleGet(P_VAR_logEntry, 0);
                        
                        PRT_VALUE** P_LVALUE_540 = &(PTMP_tmp49_1);
                        PrtFreeValue(*P_LVALUE_540);
                        *P_LVALUE_540 = PrtMkBoolValue(!PrtIsEqualValue(PTMP_tmp47_1, PTMP_tmp48_1));
                        
                        if (PrtPrimGetBool(PTMP_tmp49_1))
                        {
                            PRT_VALUE** P_LVALUE_541 = &(PTMP_tmp50_1);
                            PrtFreeValue(*P_LVALUE_541);
                            *P_LVALUE_541 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                            
                            PRT_VALUE** P_LVALUE_542 = &(PTMP_tmp51_1);
                            PrtFreeValue(*P_LVALUE_542);
                            *P_LVALUE_542 = PrtMkIntValue(PrtPrimGetInt(PTMP_tmp50_1) - PrtPrimGetInt((&P_LIT_INT32_30)));
                            
                            {
                                PRT_VALUE** P_LVALUE_543 = &(P_VAR_decIdx);
                                PrtFreeValue(*P_LVALUE_543);
                                *P_LVALUE_543 = PTMP_tmp51_1;
                                PTMP_tmp51_1 = NULL;
                            }
                            
                            while (PrtPrimGetBool((&P_LIT_BOOLEAN_12)))
                            {
                                PRT_VALUE** P_LVALUE_544 = &(PTMP_tmp52_1);
                                PrtFreeValue(*P_LVALUE_544);
                                *P_LVALUE_544 = PrtMkIntValue(PrtPrimGetInt(P_VAR_currentIndex) - PrtPrimGetInt((&P_LIT_INT32_30)));
                                
                                PRT_VALUE** P_LVALUE_545 = &(PTMP_tmp53_1);
                                PrtFreeValue(*P_LVALUE_545);
                                *P_LVALUE_545 = PrtMkBoolValue(PrtPrimGetInt(P_VAR_decIdx) >= PrtPrimGetInt(PTMP_tmp52_1));
                                
                                PRT_VALUE** P_LVALUE_546 = &(PTMP_tmp54_1);
                                PrtFreeValue(*P_LVALUE_546);
                                *P_LVALUE_546 = PrtCloneValue(PTMP_tmp53_1);
                                
                                if (PrtPrimGetBool(PTMP_tmp54_1))
                                {
                                }
                                
                                else
                                {
                                    break;
                                    
                                }
                                
                                
                                PrtRemoveByKey(p_this->varValues[8], P_VAR_decIdx);
                                
                                PRT_VALUE** P_LVALUE_547 = &(PTMP_tmp55_1);
                                PrtFreeValue(*P_LVALUE_547);
                                *P_LVALUE_547 = PrtMkIntValue(PrtPrimGetInt(P_VAR_decIdx) - PrtPrimGetInt((&P_LIT_INT32_30)));
                                
                                {
                                    PRT_VALUE** P_LVALUE_548 = &(P_VAR_decIdx);
                                    PrtFreeValue(*P_LVALUE_548);
                                    *P_LVALUE_548 = PTMP_tmp55_1;
                                    PTMP_tmp55_1 = NULL;
                                }
                                
                            }
                            
                            
                            PRT_VALUE** P_LVALUE_549 = &(PTMP_tmp56_1);
                            PrtFreeValue(*P_LVALUE_549);
                            *P_LVALUE_549 = PrtCloneValue(P_VAR_logEntry);
                            
                            PrtSeqInsertEx(p_this->varValues[8], P_VAR_decIdx, PTMP_tmp56_1, PRT_FALSE);
                            *(&(PTMP_tmp56_1)) = NULL;
                            
                        }
                        
                        else
                        {
                        }
                        
                        
                    }
                    
                    
                    PRT_VALUE** P_LVALUE_550 = &(PTMP_tmp57_1);
                    PrtFreeValue(*P_LVALUE_550);
                    *P_LVALUE_550 = PrtMkIntValue(PrtPrimGetInt(P_VAR_idx_7) + PrtPrimGetInt((&P_LIT_INT32_30)));
                    
                    {
                        PRT_VALUE** P_LVALUE_551 = &(P_VAR_idx_7);
                        PrtFreeValue(*P_LVALUE_551);
                        *P_LVALUE_551 = PTMP_tmp57_1;
                        PTMP_tmp57_1 = NULL;
                    }
                    
                    PRT_VALUE** P_LVALUE_552 = &(PTMP_tmp58_1);
                    PrtFreeValue(*P_LVALUE_552);
                    *P_LVALUE_552 = PrtMkIntValue(PrtPrimGetInt(P_VAR_currentIndex) + PrtPrimGetInt((&P_LIT_INT32_30)));
                    
                    {
                        PRT_VALUE** P_LVALUE_553 = &(P_VAR_currentIndex);
                        PrtFreeValue(*P_LVALUE_553);
                        *P_LVALUE_553 = PTMP_tmp58_1;
                        PTMP_tmp58_1 = NULL;
                    }
                    
                }
                
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_554 = &(PTMP_tmp59_1);
            PrtFreeValue(*P_LVALUE_554);
            *P_LVALUE_554 = PrtTupleGet(*P_VAR_request_19, 5);
            
            PRT_VALUE** P_LVALUE_555 = &(PTMP_tmp60_1);
            PrtFreeValue(*P_LVALUE_555);
            *P_LVALUE_555 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp59_1) > PrtPrimGetInt(p_this->varValues[9]));
            
            PRT_VALUE** P_LVALUE_556 = &(PTMP_tmp64_1);
            PrtFreeValue(*P_LVALUE_556);
            *P_LVALUE_556 = PrtCloneValue(PTMP_tmp60_1);
            
            if (PrtPrimGetBool(PTMP_tmp64_1))
            {
                PRT_VALUE** P_LVALUE_557 = &(PTMP_tmp61_1);
                PrtFreeValue(*P_LVALUE_557);
                *P_LVALUE_557 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                
                PRT_VALUE** P_LVALUE_558 = &(PTMP_tmp62_1);
                PrtFreeValue(*P_LVALUE_558);
                *P_LVALUE_558 = PrtTupleGet(*P_VAR_request_19, 5);
                
                PRT_VALUE** P_LVALUE_559 = &(PTMP_tmp63_1);
                PrtFreeValue(*P_LVALUE_559);
                *P_LVALUE_559 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp61_1) < PrtPrimGetInt(PTMP_tmp62_1));
                
                PRT_VALUE** P_LVALUE_560 = &(PTMP_tmp64_1);
                PrtFreeValue(*P_LVALUE_560);
                *P_LVALUE_560 = PrtCloneValue(PTMP_tmp63_1);
                
            }
            
            
            if (PrtPrimGetBool(PTMP_tmp64_1))
            {
                PRT_VALUE** P_LVALUE_561 = &(PTMP_tmp65_1);
                PrtFreeValue(*P_LVALUE_561);
                *P_LVALUE_561 = PrtMkIntValue(PrtSeqSizeOf(p_this->varValues[8]));
                
                {
                    PRT_VALUE** P_LVALUE_562 = &(p_this->varValues[9]);
                    PrtFreeValue(*P_LVALUE_562);
                    *P_LVALUE_562 = PTMP_tmp65_1;
                    PTMP_tmp65_1 = NULL;
                }
                
            }
            
            else
            {
                PRT_VALUE** P_LVALUE_563 = &(PTMP_tmp66_1);
                PrtFreeValue(*P_LVALUE_563);
                *P_LVALUE_563 = PrtTupleGet(*P_VAR_request_19, 5);
                
                PRT_VALUE** P_LVALUE_564 = &(PTMP_tmp67);
                PrtFreeValue(*P_LVALUE_564);
                *P_LVALUE_564 = PrtMkBoolValue(PrtPrimGetInt(PTMP_tmp66_1) > PrtPrimGetInt(p_this->varValues[9]));
                
                if (PrtPrimGetBool(PTMP_tmp67))
                {
                    PRT_VALUE** P_LVALUE_565 = &(PTMP_tmp68);
                    PrtFreeValue(*P_LVALUE_565);
                    *P_LVALUE_565 = PrtTupleGet(*P_VAR_request_19, 5);
                    
                    {
                        PRT_VALUE** P_LVALUE_566 = &(p_this->varValues[9]);
                        PrtFreeValue(*P_LVALUE_566);
                        *P_LVALUE_566 = PTMP_tmp68;
                        PTMP_tmp68 = NULL;
                    }
                    
                }
                
                else
                {
                }
                
                
            }
            
            
            PRT_VALUE** P_LVALUE_567 = &(PTMP_tmp69);
            PrtFreeValue(*P_LVALUE_567);
            *P_LVALUE_567 = PrtMkBoolValue(PrtPrimGetInt(p_this->varValues[9]) > PrtPrimGetInt(p_this->varValues[10]));
            
            if (PrtPrimGetBool(PTMP_tmp69))
            {
                PRT_VALUE** P_LVALUE_568 = &(PTMP_tmp70);
                PrtFreeValue(*P_LVALUE_568);
                *P_LVALUE_568 = PrtMkIntValue(PrtPrimGetInt(p_this->varValues[10]) + PrtPrimGetInt((&P_LIT_INT32_30)));
                
                {
                    PRT_VALUE** P_LVALUE_569 = &(p_this->varValues[10]);
                    PrtFreeValue(*P_LVALUE_569);
                    *P_LVALUE_569 = PTMP_tmp70;
                    PTMP_tmp70 = NULL;
                }
                
            }
            
            else
            {
            }
            
            
            PRT_VALUE** P_LVALUE_570 = &(PTMP_tmp71);
            PrtFreeValue(*P_LVALUE_570);
            *P_LVALUE_570 = PrtTupleGet(*P_VAR_request_19, 1);
            
            {
                PRT_VALUE** P_LVALUE_571 = &(p_this->varValues[3]);
                PrtFreeValue(*P_LVALUE_571);
                *P_LVALUE_571 = PTMP_tmp71;
                PTMP_tmp71 = NULL;
            }
            
            PRT_VALUE** P_LVALUE_572 = &(PTMP_tmp72);
            PrtFreeValue(*P_LVALUE_572);
            *P_LVALUE_572 = PrtTupleGet(*P_VAR_request_19, 1);
            
            PRT_VALUE** P_LVALUE_573 = &(PTMP_tmp73);
            PrtFreeValue(*P_LVALUE_573);
            *P_LVALUE_573 = PrtCloneValue(PTMP_tmp72);
            
            PRT_VALUE** P_LVALUE_574 = &(PTMP_tmp74);
            PrtFreeValue(*P_LVALUE_574);
            *P_LVALUE_574 = PrtCloneValue((&P_EVENT_AppendEntriesResponse.value));
            
            PRT_VALUE** P_LVALUE_575 = &(PTMP_tmp75);
            PrtFreeValue(*P_LVALUE_575);
            *P_LVALUE_575 = PrtCloneValue(p_this->varValues[6]);
            
            PRT_VALUE** P_LVALUE_576 = &(PTMP_tmp76);
            PrtFreeValue(*P_LVALUE_576);
            *P_LVALUE_576 = PrtCloneValue((&P_LIT_BOOLEAN_12));
            
            PRT_VALUE** P_LVALUE_577 = &(PTMP_tmp77);
            PrtFreeValue(*P_LVALUE_577);
            *P_LVALUE_577 = PrtCloneValue((p_this->id));
            
            PRT_VALUE** P_LVALUE_578 = &(PTMP_tmp78);
            PrtFreeValue(*P_LVALUE_578);
            *P_LVALUE_578 = PrtTupleGet(*P_VAR_request_19, 6);
            
            PRT_VALUE** P_LVALUE_579 = &(PTMP_tmp79);
            PrtFreeValue(*P_LVALUE_579);
            *P_LVALUE_579 = (PrtMkTuple(&P_GEND_TYPE_T4ibRm, &(PTMP_tmp75), &(PTMP_tmp76), &(PTMP_tmp77), &(PTMP_tmp78)));
            
            PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp73), PTMP_tmp74, 1, &(PTMP_tmp79));
            *(&(PTMP_tmp74)) = NULL;
            if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
                goto p_return_51;
            }
            if (p_this->isHalted == PRT_TRUE) {
                PrtFreeValue(_P_GEN_retval);
                _P_GEN_retval = NULL;
                goto p_return_51;
            }
            
        }
        
        
    }
    
    
p_return_51: ;
    PrtFreeValue(P_VAR_currentIndex); P_VAR_currentIndex = NULL;
    PrtFreeValue(P_VAR_idx_7); P_VAR_idx_7 = NULL;
    PrtFreeValue(P_VAR_decIdx); P_VAR_decIdx = NULL;
    PrtFreeValue(P_VAR_logEntry); P_VAR_logEntry = NULL;
    PrtFreeValue(PTMP_tmp0_48); PTMP_tmp0_48 = NULL;
    PrtFreeValue(PTMP_tmp1_35); PTMP_tmp1_35 = NULL;
    PrtFreeValue(PTMP_tmp2_33); PTMP_tmp2_33 = NULL;
    PrtFreeValue(PTMP_tmp3_29); PTMP_tmp3_29 = NULL;
    PrtFreeValue(PTMP_tmp4_24); PTMP_tmp4_24 = NULL;
    PrtFreeValue(PTMP_tmp5_17); PTMP_tmp5_17 = NULL;
    PrtFreeValue(PTMP_tmp6_16); PTMP_tmp6_16 = NULL;
    PrtFreeValue(PTMP_tmp7_11); PTMP_tmp7_11 = NULL;
    PrtFreeValue(PTMP_tmp8_8); PTMP_tmp8_8 = NULL;
    PrtFreeValue(PTMP_tmp9_8); PTMP_tmp9_8 = NULL;
    PrtFreeValue(PTMP_tmp10_8); PTMP_tmp10_8 = NULL;
    PrtFreeValue(PTMP_tmp11_8); PTMP_tmp11_8 = NULL;
    PrtFreeValue(PTMP_tmp12_7); PTMP_tmp12_7 = NULL;
    PrtFreeValue(PTMP_tmp13_7); PTMP_tmp13_7 = NULL;
    PrtFreeValue(PTMP_tmp14_5); PTMP_tmp14_5 = NULL;
    PrtFreeValue(PTMP_tmp15_5); PTMP_tmp15_5 = NULL;
    PrtFreeValue(PTMP_tmp16_5); PTMP_tmp16_5 = NULL;
    PrtFreeValue(PTMP_tmp17_5); PTMP_tmp17_5 = NULL;
    PrtFreeValue(PTMP_tmp18_4); PTMP_tmp18_4 = NULL;
    PrtFreeValue(PTMP_tmp19_4); PTMP_tmp19_4 = NULL;
    PrtFreeValue(PTMP_tmp20_4); PTMP_tmp20_4 = NULL;
    PrtFreeValue(PTMP_tmp21_4); PTMP_tmp21_4 = NULL;
    PrtFreeValue(PTMP_tmp22_4); PTMP_tmp22_4 = NULL;
    PrtFreeValue(PTMP_tmp23_4); PTMP_tmp23_4 = NULL;
    PrtFreeValue(PTMP_tmp24_4); PTMP_tmp24_4 = NULL;
    PrtFreeValue(PTMP_tmp25_4); PTMP_tmp25_4 = NULL;
    PrtFreeValue(PTMP_tmp26_4); PTMP_tmp26_4 = NULL;
    PrtFreeValue(PTMP_tmp27_4); PTMP_tmp27_4 = NULL;
    PrtFreeValue(PTMP_tmp28_4); PTMP_tmp28_4 = NULL;
    PrtFreeValue(PTMP_tmp29_4); PTMP_tmp29_4 = NULL;
    PrtFreeValue(PTMP_tmp30_2); PTMP_tmp30_2 = NULL;
    PrtFreeValue(PTMP_tmp31_2); PTMP_tmp31_2 = NULL;
    PrtFreeValue(PTMP_tmp32_2); PTMP_tmp32_2 = NULL;
    PrtFreeValue(PTMP_tmp33_2); PTMP_tmp33_2 = NULL;
    PrtFreeValue(PTMP_tmp34_2); PTMP_tmp34_2 = NULL;
    PrtFreeValue(PTMP_tmp35_1); PTMP_tmp35_1 = NULL;
    PrtFreeValue(PTMP_tmp36_1); PTMP_tmp36_1 = NULL;
    PrtFreeValue(PTMP_tmp37_1); PTMP_tmp37_1 = NULL;
    PrtFreeValue(PTMP_tmp38_1); PTMP_tmp38_1 = NULL;
    PrtFreeValue(PTMP_tmp39_1); PTMP_tmp39_1 = NULL;
    PrtFreeValue(PTMP_tmp40_1); PTMP_tmp40_1 = NULL;
    PrtFreeValue(PTMP_tmp41_1); PTMP_tmp41_1 = NULL;
    PrtFreeValue(PTMP_tmp42_1); PTMP_tmp42_1 = NULL;
    PrtFreeValue(PTMP_tmp43_1); PTMP_tmp43_1 = NULL;
    PrtFreeValue(PTMP_tmp44_1); PTMP_tmp44_1 = NULL;
    PrtFreeValue(PTMP_tmp45_1); PTMP_tmp45_1 = NULL;
    PrtFreeValue(PTMP_tmp46_1); PTMP_tmp46_1 = NULL;
    PrtFreeValue(PTMP_tmp47_1); PTMP_tmp47_1 = NULL;
    PrtFreeValue(PTMP_tmp48_1); PTMP_tmp48_1 = NULL;
    PrtFreeValue(PTMP_tmp49_1); PTMP_tmp49_1 = NULL;
    PrtFreeValue(PTMP_tmp50_1); PTMP_tmp50_1 = NULL;
    PrtFreeValue(PTMP_tmp51_1); PTMP_tmp51_1 = NULL;
    PrtFreeValue(PTMP_tmp52_1); PTMP_tmp52_1 = NULL;
    PrtFreeValue(PTMP_tmp53_1); PTMP_tmp53_1 = NULL;
    PrtFreeValue(PTMP_tmp54_1); PTMP_tmp54_1 = NULL;
    PrtFreeValue(PTMP_tmp55_1); PTMP_tmp55_1 = NULL;
    PrtFreeValue(PTMP_tmp56_1); PTMP_tmp56_1 = NULL;
    PrtFreeValue(PTMP_tmp57_1); PTMP_tmp57_1 = NULL;
    PrtFreeValue(PTMP_tmp58_1); PTMP_tmp58_1 = NULL;
    PrtFreeValue(PTMP_tmp59_1); PTMP_tmp59_1 = NULL;
    PrtFreeValue(PTMP_tmp60_1); PTMP_tmp60_1 = NULL;
    PrtFreeValue(PTMP_tmp61_1); PTMP_tmp61_1 = NULL;
    PrtFreeValue(PTMP_tmp62_1); PTMP_tmp62_1 = NULL;
    PrtFreeValue(PTMP_tmp63_1); PTMP_tmp63_1 = NULL;
    PrtFreeValue(PTMP_tmp64_1); PTMP_tmp64_1 = NULL;
    PrtFreeValue(PTMP_tmp65_1); PTMP_tmp65_1 = NULL;
    PrtFreeValue(PTMP_tmp66_1); PTMP_tmp66_1 = NULL;
    PrtFreeValue(PTMP_tmp67); PTMP_tmp67 = NULL;
    PrtFreeValue(PTMP_tmp68); PTMP_tmp68 = NULL;
    PrtFreeValue(PTMP_tmp69); PTMP_tmp69 = NULL;
    PrtFreeValue(PTMP_tmp70); PTMP_tmp70 = NULL;
    PrtFreeValue(PTMP_tmp71); PTMP_tmp71 = NULL;
    PrtFreeValue(PTMP_tmp72); PTMP_tmp72 = NULL;
    PrtFreeValue(PTMP_tmp73); PTMP_tmp73 = NULL;
    PrtFreeValue(PTMP_tmp74); PTMP_tmp74 = NULL;
    PrtFreeValue(PTMP_tmp75); PTMP_tmp75 = NULL;
    PrtFreeValue(PTMP_tmp76); PTMP_tmp76 = NULL;
    PrtFreeValue(PTMP_tmp77); PTMP_tmp77 = NULL;
    PrtFreeValue(PTMP_tmp78); PTMP_tmp78 = NULL;
    PrtFreeValue(PTMP_tmp79); PTMP_tmp79 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_AppendEntries =
{
    "AppendEntries",
    &P_AppendEntries_IMPL,
    NULL
};


PRT_VALUE* P_RedirectLastClientRequestToClusterManager_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_49 = NULL;
    PRT_VALUE* PTMP_tmp1_36 = NULL;
    PRT_VALUE* PTMP_tmp2_34 = NULL;
    PRT_VALUE* PTMP_tmp3_30 = NULL;
    PRT_VALUE* PTMP_tmp4_25 = NULL;
    PRT_VALUE* PTMP_tmp5_18 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_580 = &(PTMP_tmp0_49);
    PrtFreeValue(*P_LVALUE_580);
    *P_LVALUE_580 = PrtMkBoolValue(!PrtIsEqualValue(p_this->varValues[14], (&_P_GEN_null)));
    
    if (PrtPrimGetBool(PTMP_tmp0_49))
    {
        PRT_VALUE** P_LVALUE_581 = &(PTMP_tmp1_36);
        PrtFreeValue(*P_LVALUE_581);
        *P_LVALUE_581 = PrtCloneValue(p_this->varValues[1]);
        
        PRT_VALUE** P_LVALUE_582 = &(PTMP_tmp2_34);
        PrtFreeValue(*P_LVALUE_582);
        *P_LVALUE_582 = PrtCloneValue((&P_EVENT_Request.value));
        
        PRT_VALUE** P_LVALUE_583 = &(PTMP_tmp3_30);
        PrtFreeValue(*P_LVALUE_583);
        *P_LVALUE_583 = PrtTupleGet(p_this->varValues[14], 0);
        
        PRT_VALUE** P_LVALUE_584 = &(PTMP_tmp4_25);
        PrtFreeValue(*P_LVALUE_584);
        *P_LVALUE_584 = PrtTupleGet(p_this->varValues[14], 1);
        
        PRT_VALUE** P_LVALUE_585 = &(PTMP_tmp5_18);
        PrtFreeValue(*P_LVALUE_585);
        *P_LVALUE_585 = (PrtMkTuple(&P_GEND_TYPE_T2mi_1, &(PTMP_tmp3_30), &(PTMP_tmp4_25)));
        
        PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp1_36), PTMP_tmp2_34, 1, &(PTMP_tmp5_18));
        *(&(PTMP_tmp2_34)) = NULL;
        if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
            goto p_return_52;
        }
        if (p_this->isHalted == PRT_TRUE) {
            PrtFreeValue(_P_GEN_retval);
            _P_GEN_retval = NULL;
            goto p_return_52;
        }
        
    }
    
    else
    {
    }
    
    
p_return_52: ;
    PrtFreeValue(PTMP_tmp0_49); PTMP_tmp0_49 = NULL;
    PrtFreeValue(PTMP_tmp1_36); PTMP_tmp1_36 = NULL;
    PrtFreeValue(PTMP_tmp2_34); PTMP_tmp2_34 = NULL;
    PrtFreeValue(PTMP_tmp3_30); PTMP_tmp3_30 = NULL;
    PrtFreeValue(PTMP_tmp4_25); PTMP_tmp4_25 = NULL;
    PrtFreeValue(PTMP_tmp5_18); PTMP_tmp5_18 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_RedirectLastClientRequestToClusterManager =
{
    "RedirectLastClientRequestToClusterManager",
    &P_RedirectLastClientRequestToClusterManager_IMPL,
    NULL
};


PRT_VALUE* P_GetLogTermForIndex_IMPL(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE** P_VAR_logIndex_1 = argRefs[0];
    PRT_VALUE* P_VAR_logTerm_1 = PrtMkDefaultValue(&P_GEND_TYPE_i);
    PRT_VALUE* PTMP_tmp0_50 = NULL;
    PRT_VALUE* PTMP_tmp1_37 = NULL;
    PRT_VALUE* PTMP_tmp2_35 = NULL;
    PRT_VALUE* PTMP_tmp3_31 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE P_LIT_INT32_31 = { PRT_VALUE_KIND_INT, { .nt = 0 } };
    PRT_VALUE P_LIT_INT32_32 = { PRT_VALUE_KIND_INT, { .nt = 1 } };
    PRT_VALUE** P_LVALUE_586 = &(P_VAR_logTerm_1);
    PrtFreeValue(*P_LVALUE_586);
    *P_LVALUE_586 = PrtCloneValue((&P_LIT_INT32_31));
    
    PRT_VALUE** P_LVALUE_587 = &(PTMP_tmp0_50);
    PrtFreeValue(*P_LVALUE_587);
    *P_LVALUE_587 = PrtMkBoolValue(PrtPrimGetInt(*P_VAR_logIndex_1) > PrtPrimGetInt((&P_LIT_INT32_31)));
    
    if (PrtPrimGetBool(PTMP_tmp0_50))
    {
        PRT_VALUE** P_LVALUE_588 = &(PTMP_tmp1_37);
        PrtFreeValue(*P_LVALUE_588);
        *P_LVALUE_588 = PrtMkIntValue(PrtPrimGetInt(*P_VAR_logIndex_1) - PrtPrimGetInt((&P_LIT_INT32_32)));
        
        PRT_VALUE** P_LVALUE_589 = &(PTMP_tmp2_35);
        PrtFreeValue(*P_LVALUE_589);
        *P_LVALUE_589 = PrtSeqGet(p_this->varValues[8], PTMP_tmp1_37);
        
        PRT_VALUE** P_LVALUE_590 = &(PTMP_tmp3_31);
        PrtFreeValue(*P_LVALUE_590);
        *P_LVALUE_590 = PrtTupleGet(PTMP_tmp2_35, 0);
        
        {
            PRT_VALUE** P_LVALUE_591 = &(P_VAR_logTerm_1);
            PrtFreeValue(*P_LVALUE_591);
            *P_LVALUE_591 = PTMP_tmp3_31;
            PTMP_tmp3_31 = NULL;
        }
        
    }
    
    else
    {
    }
    
    
    PrtFreeValue(_P_GEN_retval);
    _P_GEN_retval = PrtCloneValue(P_VAR_logTerm_1);
    goto p_return_53;
    
p_return_53: ;
    PrtFreeValue(P_VAR_logTerm_1); P_VAR_logTerm_1 = NULL;
    PrtFreeValue(PTMP_tmp0_50); PTMP_tmp0_50 = NULL;
    PrtFreeValue(PTMP_tmp1_37); PTMP_tmp1_37 = NULL;
    PrtFreeValue(PTMP_tmp2_35); PTMP_tmp2_35 = NULL;
    PrtFreeValue(PTMP_tmp3_31); PTMP_tmp3_31 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_GetLogTermForIndex =
{
    "GetLogTermForIndex",
    &P_GetLogTermForIndex_IMPL,
    NULL
};


PRT_VALUE* P_ShuttingDown_IMPL_1(PRT_MACHINEINST* context, PRT_VALUE*** argRefs)
{
    PRT_VALUE* _P_GEN_funval = NULL;
    PRT_VALUE** _P_GEN_funargs[32];
    PRT_MACHINEINST_PRIV* p_this = (PRT_MACHINEINST_PRIV*)context;
    PRT_VALUE* _P_GEN_retval = NULL;
    PRT_VALUE* PTMP_tmp0_51 = NULL;
    PRT_VALUE* PTMP_tmp1_38 = NULL;
    PRT_VALUE* PTMP_tmp2_36 = NULL;
    PRT_VALUE* PTMP_tmp3_32 = NULL;
    PRT_VALUE* PTMP_tmp4_26 = NULL;
    
    PRT_VALUE _P_GEN_null = { PRT_VALUE_KIND_NULL, { .ev = PRT_SPECIAL_EVENT_NULL } };
    PRT_VALUE** P_LVALUE_592 = &(PTMP_tmp0_51);
    PrtFreeValue(*P_LVALUE_592);
    *P_LVALUE_592 = PrtCloneValue(p_this->varValues[4]);
    
    PRT_VALUE** P_LVALUE_593 = &(PTMP_tmp1_38);
    PrtFreeValue(*P_LVALUE_593);
    *P_LVALUE_593 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp0_51), PTMP_tmp1_38, 0);
    *(&(PTMP_tmp1_38)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_54;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_54;
    }
    
    PRT_VALUE** P_LVALUE_594 = &(PTMP_tmp2_36);
    PrtFreeValue(*P_LVALUE_594);
    *P_LVALUE_594 = PrtCloneValue(p_this->varValues[5]);
    
    PRT_VALUE** P_LVALUE_595 = &(PTMP_tmp3_32);
    PrtFreeValue(*P_LVALUE_595);
    *P_LVALUE_595 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtSendInternal(context, PrtGetMachine(context->process, PTMP_tmp2_36), PTMP_tmp3_32, 0);
    *(&(PTMP_tmp3_32)) = NULL;
    if (p_this->returnKind != ReturnStatement && p_this->returnKind != ReceiveStatement) {
        goto p_return_54;
    }
    if (p_this->isHalted == PRT_TRUE) {
        PrtFreeValue(_P_GEN_retval);
        _P_GEN_retval = NULL;
        goto p_return_54;
    }
    
    PRT_VALUE** P_LVALUE_596 = &(PTMP_tmp4_26);
    PrtFreeValue(*P_LVALUE_596);
    *P_LVALUE_596 = PrtCloneValue((&_P_EVENT_HALT_STRUCT.value));
    
    PrtRaise(p_this, PTMP_tmp4_26, 0);
    *(&(PTMP_tmp4_26)) = NULL;
    goto p_return_54;
    
p_return_54: ;
    PrtFreeValue(PTMP_tmp0_51); PTMP_tmp0_51 = NULL;
    PrtFreeValue(PTMP_tmp1_38); PTMP_tmp1_38 = NULL;
    PrtFreeValue(PTMP_tmp2_36); PTMP_tmp2_36 = NULL;
    PrtFreeValue(PTMP_tmp3_32); PTMP_tmp3_32 = NULL;
    PrtFreeValue(PTMP_tmp4_26); PTMP_tmp4_26 = NULL;
    return _P_GEN_retval;
}

PRT_FUNDECL P_FUNCTION_ShuttingDown_1 =
{
    "ShuttingDown",
    &P_ShuttingDown_IMPL_1,
    NULL
};


PRT_FUNDECL* P_Server_METHODS[] = { &P_FUNCTION_Anon_12, &P_FUNCTION_Anon_13, &P_FUNCTION_Anon_14, &P_FUNCTION_Anon_15, &P_FUNCTION_Anon_16, &P_FUNCTION_Anon_17, &P_FUNCTION_Anon_18, &P_FUNCTION_Anon_19, &P_FUNCTION_Anon_20, &P_FUNCTION_Anon_21, &P_FUNCTION_Anon_22, &P_FUNCTION_Anon_23, &P_FUNCTION_Anon_24, &P_FUNCTION_Anon_25, &P_FUNCTION_Anon_26, &P_FUNCTION_Anon_27, &P_FUNCTION_Anon_28, &P_FUNCTION_BroadcastVoteRequests, &P_FUNCTION_RespondAppendEntriesAsCandidate, &P_FUNCTION_Anon_29, &P_FUNCTION_Anon_30, &P_FUNCTION_Anon_31, &P_FUNCTION_Anon_32, &P_FUNCTION_Anon_33, &P_FUNCTION_Anon_34, &P_FUNCTION_ProcessClientRequest, &P_FUNCTION_BroadcastLastClientRequest, &P_FUNCTION_VoteAsLeader, &P_FUNCTION_RespondVoteAsLeader, &P_FUNCTION_AppendEntriesAsLeader, &P_FUNCTION_RespondAppendEntriesAsLeader, &P_FUNCTION_Vote, &P_FUNCTION_AppendEntries, &P_FUNCTION_RedirectLastClientRequestToClusterManager, &P_FUNCTION_GetLogTermForIndex, &P_FUNCTION_ShuttingDown_1 };

PRT_EVENTDECL* P_Server_RECV_INNER_1[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Server_RECV_1 =
{
    28U,
    P_Server_RECV_INNER_1,
    NULL
};

PRT_EVENTDECL* P_Server_SEND_INNER[] = { &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeFollower, &P_EVENT_BecomeLeader, &P_EVENT_CConfigureEvent, &P_EVENT_ECancelTimer, &P_EVENT_EConfigureEvent, &P_EVENT_EMonitorInit, &P_EVENT_EStartTimer, &P_EVENT_ETickEvent, &P_EVENT_ETimeout, &P_EVENT_LocalEvent, &P_EVENT_NotifyLeaderElected, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_PCancelTimer, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PTickEvent, &P_EVENT_PTimeout, &P_EVENT_RedirectRequest, &P_EVENT_Request, &P_EVENT_Response, &P_EVENT_SConfigureEvent, &P_EVENT_ShutDown, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &_P_EVENT_HALT_STRUCT };
PRT_EVENTSETDECL P_EVENTSET_Server_SEND =
{
    28U,
    P_Server_SEND_INNER,
    NULL
};

PRT_MACHINEDECL P_MACHINE_Server = 
{
    3U,
    "Server",
    &P_EVENTSET_Server_RECV_1,
    &P_EVENTSET_Server_SEND,
    NULL,
    16U,
    4U,
    36U,
    4294967295U,
    0U,
    P_Server_VARS,
    P_Server_STATES,
    P_Server_METHODS
};

PRT_TYPE* P_TYPEDEF_Log = &P_GEND_TYPE_T2ii;
PRT_EVENTDECL* P_ALL_EVENTS[] = { &_P_EVENT_NULL_STRUCT, &_P_EVENT_HALT_STRUCT, &P_EVENT_NotifyLeaderUpdate, &P_EVENT_Request, &P_EVENT_RedirectRequest, &P_EVENT_ShutDown, &P_EVENT_LocalEvent, &P_EVENT_CConfigureEvent, &P_EVENT_Response, &P_EVENT_NotifyLeaderElected, &P_EVENT_SConfigureEvent, &P_EVENT_VoteRequest, &P_EVENT_VoteResponse, &P_EVENT_AppendEntriesRequest, &P_EVENT_AppendEntriesResponse, &P_EVENT_BecomeFollower, &P_EVENT_BecomeCandidate, &P_EVENT_BecomeLeader, &P_EVENT_EConfigureEvent, &P_EVENT_EStartTimer, &P_EVENT_ECancelTimer, &P_EVENT_ETimeout, &P_EVENT_ETickEvent, &P_EVENT_PConfigureEvent, &P_EVENT_PStartTimer, &P_EVENT_PCancelTimer, &P_EVENT_PTimeout, &P_EVENT_PTickEvent, &P_EVENT_EMonitorInit };
PRT_MACHINEDECL* P_ALL_MACHINES[] = { &P_MACHINE_Client, &P_MACHINE_ClusterManager, &P_MACHINE_SafetyMonitor, &P_MACHINE_Server };
PRT_INTERFACEDECL* P_ALL_INTERFACES[] = { &P_I_Client, &P_I_ClusterManager, &P_I_Server };
PRT_FUNDECL* P_ALL_FUNCTIONS[] = { NULL };
PRT_FOREIGNTYPEDECL* P_ALL_FOREIGN_TYPES[] = { NULL };
int P_DefaultImpl_LME_0[] = { -1,-1,-1 };
int P_DefaultImpl_LME_1[] = { -1,-1,-1 };
int P_DefaultImpl_LME_2[] = { -1,-1,-1 };
int* P_DefaultImpl_LINKMAP[] = { P_DefaultImpl_LME_0, P_DefaultImpl_LME_1, P_DefaultImpl_LME_2 };
int P_DefaultImpl_DEFMAP[] = { 0,1,3 };
PRT_PROGRAMDECL P_GEND_IMPL_DefaultImpl = {
    29U,
    4U,
    3U,
    0U,
    0U,
    P_ALL_EVENTS,
    P_ALL_MACHINES,
    P_ALL_INTERFACES,
    P_ALL_FUNCTIONS,
    P_ALL_FOREIGN_TYPES,
    P_DefaultImpl_LINKMAP,
    P_DefaultImpl_DEFMAP
};
