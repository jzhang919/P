using Microsoft.PSharp;
using System;
using System.Runtime;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using Plang.PrtSharp;
using Plang.PrtSharp.Values;
using Plang.PrtSharp.Exceptions;
using System.Threading;
using System.Threading.Tasks;

#pragma warning disable 162, 219, 414
namespace Raft
{
    public static partial class GlobalFunctions {}
    internal partial class NotifyLeaderUpdate : PEvent
    {
        public NotifyLeaderUpdate() : base() {}
        public NotifyLeaderUpdate (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new NotifyLeaderUpdate();}
    }
    internal partial class Request : PEvent
    {
        public Request() : base() {}
        public Request (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new Request();}
    }
    internal partial class RedirectRequest : PEvent
    {
        public RedirectRequest() : base() {}
        public RedirectRequest (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new RedirectRequest();}
    }
    internal partial class ShutDown : PEvent
    {
        public ShutDown() : base() {}
        public ShutDown (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new ShutDown();}
    }
    internal partial class LocalEvent : PEvent
    {
        public LocalEvent() : base() {}
        public LocalEvent (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new LocalEvent();}
    }
    internal partial class CConfigureEvent : PEvent
    {
        public CConfigureEvent() : base() {}
        public CConfigureEvent (PMachineValue payload): base(payload){ }
        public override IPrtValue Clone() { return new CConfigureEvent();}
    }
    internal partial class Response : PEvent
    {
        public Response() : base() {}
        public Response (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new Response();}
    }
    internal partial class NotifyLeaderElected : PEvent
    {
        public NotifyLeaderElected() : base() {}
        public NotifyLeaderElected (PrtInt payload): base(payload){ }
        public override IPrtValue Clone() { return new NotifyLeaderElected();}
    }
    internal partial class SConfigureEvent : PEvent
    {
        public SConfigureEvent() : base() {}
        public SConfigureEvent (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new SConfigureEvent();}
    }
    internal partial class VoteRequest : PEvent
    {
        public VoteRequest() : base() {}
        public VoteRequest (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new VoteRequest();}
    }
    internal partial class VoteResponse : PEvent
    {
        public VoteResponse() : base() {}
        public VoteResponse (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new VoteResponse();}
    }
    internal partial class AppendEntriesRequest : PEvent
    {
        public AppendEntriesRequest() : base() {}
        public AppendEntriesRequest (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new AppendEntriesRequest();}
    }
    internal partial class AppendEntriesResponse : PEvent
    {
        public AppendEntriesResponse() : base() {}
        public AppendEntriesResponse (PrtNamedTuple payload): base(payload){ }
        public override IPrtValue Clone() { return new AppendEntriesResponse();}
    }
    internal partial class BecomeFollower : PEvent
    {
        public BecomeFollower() : base() {}
        public BecomeFollower (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new BecomeFollower();}
    }
    internal partial class BecomeCandidate : PEvent
    {
        public BecomeCandidate() : base() {}
        public BecomeCandidate (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new BecomeCandidate();}
    }
    internal partial class BecomeLeader : PEvent
    {
        public BecomeLeader() : base() {}
        public BecomeLeader (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new BecomeLeader();}
    }
    internal partial class EConfigureEvent : PEvent
    {
        public EConfigureEvent() : base() {}
        public EConfigureEvent (PMachineValue payload): base(payload){ }
        public override IPrtValue Clone() { return new EConfigureEvent();}
    }
    internal partial class EStartTimer : PEvent
    {
        public EStartTimer() : base() {}
        public EStartTimer (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new EStartTimer();}
    }
    internal partial class ECancelTimer : PEvent
    {
        public ECancelTimer() : base() {}
        public ECancelTimer (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new ECancelTimer();}
    }
    internal partial class ETimeout : PEvent
    {
        public ETimeout() : base() {}
        public ETimeout (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new ETimeout();}
    }
    internal partial class ETickEvent : PEvent
    {
        public ETickEvent() : base() {}
        public ETickEvent (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new ETickEvent();}
    }
    internal partial class PConfigureEvent : PEvent
    {
        public PConfigureEvent() : base() {}
        public PConfigureEvent (PMachineValue payload): base(payload){ }
        public override IPrtValue Clone() { return new PConfigureEvent();}
    }
    internal partial class PStartTimer : PEvent
    {
        public PStartTimer() : base() {}
        public PStartTimer (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new PStartTimer();}
    }
    internal partial class PCancelTimer : PEvent
    {
        public PCancelTimer() : base() {}
        public PCancelTimer (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new PCancelTimer();}
    }
    internal partial class PTimeout : PEvent
    {
        public PTimeout() : base() {}
        public PTimeout (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new PTimeout();}
    }
    internal partial class PTickEvent : PEvent
    {
        public PTickEvent() : base() {}
        public PTickEvent (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new PTickEvent();}
    }
    internal partial class EMonitorInit : PEvent
    {
        public EMonitorInit() : base() {}
        public EMonitorInit (IPrtValue payload): base(payload){ }
        public override IPrtValue Clone() { return new EMonitorInit();}
    }
    internal partial class Client : PMachine
    {
        private PMachineValue Cluster = null;
        private PrtInt LatestCommand = ((PrtInt)0);
        private PrtInt Counter = ((PrtInt)0);
        public class ConstructorEvent : PEvent{public ConstructorEvent(PMachineValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((PMachineValue)value); }
        public Client() {
            this.sends.Add(nameof(AppendEntriesRequest));
            this.sends.Add(nameof(AppendEntriesResponse));
            this.sends.Add(nameof(BecomeCandidate));
            this.sends.Add(nameof(BecomeFollower));
            this.sends.Add(nameof(BecomeLeader));
            this.sends.Add(nameof(CConfigureEvent));
            this.sends.Add(nameof(ECancelTimer));
            this.sends.Add(nameof(EConfigureEvent));
            this.sends.Add(nameof(EMonitorInit));
            this.sends.Add(nameof(EStartTimer));
            this.sends.Add(nameof(ETickEvent));
            this.sends.Add(nameof(ETimeout));
            this.sends.Add(nameof(LocalEvent));
            this.sends.Add(nameof(NotifyLeaderElected));
            this.sends.Add(nameof(NotifyLeaderUpdate));
            this.sends.Add(nameof(PCancelTimer));
            this.sends.Add(nameof(PConfigureEvent));
            this.sends.Add(nameof(PStartTimer));
            this.sends.Add(nameof(PTickEvent));
            this.sends.Add(nameof(PTimeout));
            this.sends.Add(nameof(RedirectRequest));
            this.sends.Add(nameof(Request));
            this.sends.Add(nameof(Response));
            this.sends.Add(nameof(SConfigureEvent));
            this.sends.Add(nameof(ShutDown));
            this.sends.Add(nameof(VoteRequest));
            this.sends.Add(nameof(VoteResponse));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(AppendEntriesRequest));
            this.receives.Add(nameof(AppendEntriesResponse));
            this.receives.Add(nameof(BecomeCandidate));
            this.receives.Add(nameof(BecomeFollower));
            this.receives.Add(nameof(BecomeLeader));
            this.receives.Add(nameof(CConfigureEvent));
            this.receives.Add(nameof(ECancelTimer));
            this.receives.Add(nameof(EConfigureEvent));
            this.receives.Add(nameof(EMonitorInit));
            this.receives.Add(nameof(EStartTimer));
            this.receives.Add(nameof(ETickEvent));
            this.receives.Add(nameof(ETimeout));
            this.receives.Add(nameof(LocalEvent));
            this.receives.Add(nameof(NotifyLeaderElected));
            this.receives.Add(nameof(NotifyLeaderUpdate));
            this.receives.Add(nameof(PCancelTimer));
            this.receives.Add(nameof(PConfigureEvent));
            this.receives.Add(nameof(PStartTimer));
            this.receives.Add(nameof(PTickEvent));
            this.receives.Add(nameof(PTimeout));
            this.receives.Add(nameof(RedirectRequest));
            this.receives.Add(nameof(Request));
            this.receives.Add(nameof(Response));
            this.receives.Add(nameof(SConfigureEvent));
            this.receives.Add(nameof(ShutDown));
            this.receives.Add(nameof(VoteRequest));
            this.receives.Add(nameof(VoteResponse));
            this.receives.Add(nameof(PHalt));
        }
        
        public void Anon()
        {
            Client currentMachine = this;
            PMachineValue payload = (PMachineValue)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0 = ((PrtInt)0);
            TMP_tmp0 = (PrtInt)(-(((PrtInt)1)));
            LatestCommand = TMP_tmp0;
            Counter = (PrtInt)(((PrtInt)0));
        }
        public void Anon_1()
        {
            Client currentMachine = this;
            PMachineValue payload_1 = (PMachineValue)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_1 = null;
            TMP_tmp0_1 = (PMachineValue)(((PMachineValue)((IPrtValue)payload_1)?.Clone()));
            Configure(TMP_tmp0_1);
        }
        public void Configure(PMachineValue payload_2)
        {
            Client currentMachine = this;
            PEvent TMP_tmp0_2 = null;
            Cluster = (PMachineValue)(((PMachineValue)((IPrtValue)payload_2)?.Clone()));
            TMP_tmp0_2 = (PEvent)(new LocalEvent(null));
            currentMachine.RaiseEvent((Event)TMP_tmp0_2);
            throw new PUnreachableCodeException();
        }
        public void Anon_2()
        {
            Client currentMachine = this;
            PrtInt TMP_tmp0_3 = ((PrtInt)0);
            PrtInt TMP_tmp1 = ((PrtInt)0);
            PMachineValue TMP_tmp2 = null;
            PEvent TMP_tmp3 = null;
            PMachineValue TMP_tmp4 = null;
            PrtInt TMP_tmp5 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp6 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_3 = (PrtInt)(ChooseVal());
            LatestCommand = TMP_tmp0_3;
            TMP_tmp1 = (PrtInt)((Counter) + (((PrtInt)1)));
            Counter = TMP_tmp1;
            TMP_tmp2 = (PMachineValue)(((PMachineValue)((IPrtValue)Cluster)?.Clone()));
            TMP_tmp3 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
            TMP_tmp4 = (PMachineValue)(currentMachine.self);
            TMP_tmp5 = (PrtInt)(((PrtInt)((IPrtValue)LatestCommand)?.Clone()));
            TMP_tmp6 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Client","Command"}, TMP_tmp4, TMP_tmp5)));
            currentMachine.SendEvent(TMP_tmp2, (Event)TMP_tmp3, TMP_tmp6);
        }
        public void Anon_3()
        {
            Client currentMachine = this;
            ProcessResponse();
        }
        public PrtInt ChooseVal()
        {
            Client currentMachine = this;
            PrtInt index = ((PrtInt)0);
            PrtBool TMP_tmp0_4 = ((PrtBool)false);
            PrtBool TMP_tmp1_1 = ((PrtBool)false);
            PrtBool TMP_tmp2_1 = ((PrtBool)false);
            PrtInt TMP_tmp3_1 = ((PrtInt)0);
            index = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp0_4 = (PrtBool)((index) < (((PrtInt)100)));
                TMP_tmp1_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp0_4)?.Clone()));
                if (TMP_tmp1_1)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp2_1 = (PrtBool)(((PrtBool)currentMachine.Random()));
                if (TMP_tmp2_1)
                {
                    return ((PrtInt)((IPrtValue)index)?.Clone());
                }
                TMP_tmp3_1 = (PrtInt)((index) + (((PrtInt)1)));
                index = TMP_tmp3_1;
            }
            return ((PrtInt)((IPrtValue)index)?.Clone());
        }
        public void ProcessResponse()
        {
            Client currentMachine = this;
            PrtBool TMP_tmp0_5 = ((PrtBool)false);
            PMachineValue TMP_tmp1_2 = null;
            PEvent TMP_tmp2_2 = null;
            PEvent TMP_tmp3_2 = null;
            PEvent TMP_tmp4_1 = null;
            TMP_tmp0_5 = (PrtBool)((PrtValues.SafeEquals(Counter,((PrtInt)3))));
            if (TMP_tmp0_5)
            {
                TMP_tmp1_2 = (PMachineValue)(((PMachineValue)((IPrtValue)Cluster)?.Clone()));
                TMP_tmp2_2 = (PEvent)(new ShutDown(null));
                currentMachine.SendEvent(TMP_tmp1_2, (Event)TMP_tmp2_2);
                TMP_tmp3_2 = (PEvent)(new PHalt(null));
                currentMachine.RaiseEvent((Event)TMP_tmp3_2);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp4_1 = (PEvent)(new LocalEvent(null));
                currentMachine.RaiseEvent((Event)TMP_tmp4_1);
                throw new PUnreachableCodeException();
            }
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init))]
        class __InitState__ : MachineState { }
        
        [OnEntry(nameof(Anon))]
        [OnEventDoAction(typeof(CConfigureEvent), nameof(Anon_1))]
        [OnEventGotoState(typeof(LocalEvent), typeof(PumpRequest))]
        class Init : MachineState
        {
        }
        [OnEntry(nameof(Anon_2))]
        [OnEventDoAction(typeof(Response), nameof(Anon_3))]
        [OnEventGotoState(typeof(LocalEvent), typeof(PumpRequest))]
        class PumpRequest : MachineState
        {
        }
    }
    internal partial class ClusterManager : PMachine
    {
        private PrtSeq Servers = new PrtSeq();
        private PrtInt NumberOfServers = ((PrtInt)0);
        private PMachineValue Leader = null;
        private PrtInt LeaderTerm = ((PrtInt)0);
        private PMachineValue Client_1 = null;
        public class ConstructorEvent : PEvent{public ConstructorEvent(IPrtValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((IPrtValue)value); }
        public ClusterManager() {
            this.sends.Add(nameof(AppendEntriesRequest));
            this.sends.Add(nameof(AppendEntriesResponse));
            this.sends.Add(nameof(BecomeCandidate));
            this.sends.Add(nameof(BecomeFollower));
            this.sends.Add(nameof(BecomeLeader));
            this.sends.Add(nameof(CConfigureEvent));
            this.sends.Add(nameof(ECancelTimer));
            this.sends.Add(nameof(EConfigureEvent));
            this.sends.Add(nameof(EMonitorInit));
            this.sends.Add(nameof(EStartTimer));
            this.sends.Add(nameof(ETickEvent));
            this.sends.Add(nameof(ETimeout));
            this.sends.Add(nameof(LocalEvent));
            this.sends.Add(nameof(NotifyLeaderElected));
            this.sends.Add(nameof(NotifyLeaderUpdate));
            this.sends.Add(nameof(PCancelTimer));
            this.sends.Add(nameof(PConfigureEvent));
            this.sends.Add(nameof(PStartTimer));
            this.sends.Add(nameof(PTickEvent));
            this.sends.Add(nameof(PTimeout));
            this.sends.Add(nameof(RedirectRequest));
            this.sends.Add(nameof(Request));
            this.sends.Add(nameof(Response));
            this.sends.Add(nameof(SConfigureEvent));
            this.sends.Add(nameof(ShutDown));
            this.sends.Add(nameof(VoteRequest));
            this.sends.Add(nameof(VoteResponse));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(AppendEntriesRequest));
            this.receives.Add(nameof(AppendEntriesResponse));
            this.receives.Add(nameof(BecomeCandidate));
            this.receives.Add(nameof(BecomeFollower));
            this.receives.Add(nameof(BecomeLeader));
            this.receives.Add(nameof(CConfigureEvent));
            this.receives.Add(nameof(ECancelTimer));
            this.receives.Add(nameof(EConfigureEvent));
            this.receives.Add(nameof(EMonitorInit));
            this.receives.Add(nameof(EStartTimer));
            this.receives.Add(nameof(ETickEvent));
            this.receives.Add(nameof(ETimeout));
            this.receives.Add(nameof(LocalEvent));
            this.receives.Add(nameof(NotifyLeaderElected));
            this.receives.Add(nameof(NotifyLeaderUpdate));
            this.receives.Add(nameof(PCancelTimer));
            this.receives.Add(nameof(PConfigureEvent));
            this.receives.Add(nameof(PStartTimer));
            this.receives.Add(nameof(PTickEvent));
            this.receives.Add(nameof(PTimeout));
            this.receives.Add(nameof(RedirectRequest));
            this.receives.Add(nameof(Request));
            this.receives.Add(nameof(Response));
            this.receives.Add(nameof(SConfigureEvent));
            this.receives.Add(nameof(ShutDown));
            this.receives.Add(nameof(VoteRequest));
            this.receives.Add(nameof(VoteResponse));
            this.receives.Add(nameof(PHalt));
        }
        
        public void Anon_4()
        {
            ClusterManager currentMachine = this;
            PrtInt idx = ((PrtInt)0);
            PMachineValue mac = null;
            PrtSeq TMP_tmp0_6 = new PrtSeq();
            PrtBool TMP_tmp1_3 = ((PrtBool)false);
            PrtBool TMP_tmp2_3 = ((PrtBool)false);
            PMachineValue TMP_tmp3_3 = null;
            PMachineValue TMP_tmp4_2 = null;
            PrtInt TMP_tmp5_1 = ((PrtInt)0);
            PMachineValue TMP_tmp6_1 = null;
            PEvent TMP_tmp7 = null;
            NumberOfServers = (PrtInt)(((PrtInt)5));
            LeaderTerm = (PrtInt)(((PrtInt)0));
            idx = (PrtInt)(((PrtInt)0));
            TMP_tmp0_6 = (PrtSeq)(new PrtSeq());
            Servers = TMP_tmp0_6;
            while (((PrtBool)true))
            {
                TMP_tmp1_3 = (PrtBool)((idx) < (NumberOfServers));
                TMP_tmp2_3 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp1_3)?.Clone()));
                if (TMP_tmp2_3)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp3_3 = (PMachineValue)(null);
                mac = TMP_tmp3_3;
                TMP_tmp4_2 = (PMachineValue)(((PMachineValue)((IPrtValue)mac)?.Clone()));
                ((PrtSeq)Servers).Insert(idx, TMP_tmp4_2);
                TMP_tmp5_1 = (PrtInt)((idx) + (((PrtInt)1)));
                idx = TMP_tmp5_1;
            }
            TMP_tmp6_1 = (PMachineValue)(null);
            Client_1 = TMP_tmp6_1;
            TMP_tmp7 = (PEvent)(new LocalEvent(null));
            currentMachine.RaiseEvent((Event)TMP_tmp7);
            throw new PUnreachableCodeException();
        }
        public void Anon_5()
        {
            ClusterManager currentMachine = this;
            PrtInt idx_1 = ((PrtInt)0);
            PrtBool TMP_tmp0_7 = ((PrtBool)false);
            PrtBool TMP_tmp1_4 = ((PrtBool)false);
            PMachineValue TMP_tmp2_4 = null;
            PMachineValue TMP_tmp3_4 = null;
            PEvent TMP_tmp4_3 = null;
            PrtInt TMP_tmp5_2 = ((PrtInt)0);
            PrtSeq TMP_tmp6_2 = new PrtSeq();
            PMachineValue TMP_tmp7_1 = null;
            PrtNamedTuple TMP_tmp8 = (new PrtNamedTuple(new string[]{"Id","Servers","ClusterManager"},((PrtInt)0), new PrtSeq(), null));
            PrtInt TMP_tmp9 = ((PrtInt)0);
            PMachineValue TMP_tmp10 = null;
            PEvent TMP_tmp11 = null;
            PMachineValue TMP_tmp12 = null;
            PEvent TMP_tmp13 = null;
            idx_1 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp0_7 = (PrtBool)((idx_1) < (NumberOfServers));
                TMP_tmp1_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp0_7)?.Clone()));
                if (TMP_tmp1_4)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp2_4 = (PMachineValue)(((PrtSeq)Servers)[idx_1]);
                TMP_tmp3_4 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp2_4)?.Clone()));
                TMP_tmp4_3 = (PEvent)(new SConfigureEvent((new PrtNamedTuple(new string[]{"Id","Servers","ClusterManager"},((PrtInt)0), new PrtSeq(), null))));
                TMP_tmp5_2 = (PrtInt)(((PrtInt)((IPrtValue)idx_1)?.Clone()));
                TMP_tmp6_2 = (PrtSeq)(((PrtSeq)((IPrtValue)Servers)?.Clone()));
                TMP_tmp7_1 = (PMachineValue)(currentMachine.self);
                TMP_tmp8 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Id","Servers","ClusterManager"}, TMP_tmp5_2, TMP_tmp6_2, TMP_tmp7_1)));
                currentMachine.SendEvent(TMP_tmp3_4, (Event)TMP_tmp4_3, TMP_tmp8);
                TMP_tmp9 = (PrtInt)((idx_1) + (((PrtInt)1)));
                idx_1 = TMP_tmp9;
            }
            TMP_tmp10 = (PMachineValue)(((PMachineValue)((IPrtValue)Client_1)?.Clone()));
            TMP_tmp11 = (PEvent)(new CConfigureEvent(null));
            TMP_tmp12 = (PMachineValue)(currentMachine.self);
            currentMachine.SendEvent(TMP_tmp10, (Event)TMP_tmp11, TMP_tmp12);
            TMP_tmp13 = (PEvent)(new LocalEvent(null));
            currentMachine.RaiseEvent((Event)TMP_tmp13);
            throw new PUnreachableCodeException();
        }
        public void Anon_6()
        {
            ClusterManager currentMachine = this;
            PrtNamedTuple payload_3 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_8 = (new PrtNamedTuple(new string[]{"Leader","Term"},null, ((PrtInt)0)));
            PEvent TMP_tmp1_5 = null;
            TMP_tmp0_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_3)?.Clone()));
            UpdateLeader(TMP_tmp0_8);
            TMP_tmp1_5 = (PEvent)(new LocalEvent(null));
            currentMachine.RaiseEvent((Event)TMP_tmp1_5);
            throw new PUnreachableCodeException();
        }
        public void UpdateLeader(PrtNamedTuple request)
        {
            ClusterManager currentMachine = this;
            PrtInt TMP_tmp0_9 = ((PrtInt)0);
            PrtBool TMP_tmp1_6 = ((PrtBool)false);
            PMachineValue TMP_tmp2_5 = null;
            PrtInt TMP_tmp3_5 = ((PrtInt)0);
            TMP_tmp0_9 = (PrtInt)(((PrtNamedTuple)request)["Term"]);
            TMP_tmp1_6 = (PrtBool)((LeaderTerm) < (TMP_tmp0_9));
            if (TMP_tmp1_6)
            {
                TMP_tmp2_5 = (PMachineValue)(((PrtNamedTuple)request)["Leader"]);
                Leader = TMP_tmp2_5;
                TMP_tmp3_5 = (PrtInt)(((PrtNamedTuple)request)["Term"]);
                LeaderTerm = TMP_tmp3_5;
            }
        }
        public void ShuttingDown()
        {
            ClusterManager currentMachine = this;
            PrtInt idx_2 = ((PrtInt)0);
            PrtBool TMP_tmp0_10 = ((PrtBool)false);
            PrtBool TMP_tmp1_7 = ((PrtBool)false);
            PMachineValue TMP_tmp2_6 = null;
            PMachineValue TMP_tmp3_6 = null;
            PEvent TMP_tmp4_4 = null;
            PrtInt TMP_tmp5_3 = ((PrtInt)0);
            PEvent TMP_tmp6_3 = null;
            idx_2 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp0_10 = (PrtBool)((idx_2) < (NumberOfServers));
                TMP_tmp1_7 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp0_10)?.Clone()));
                if (TMP_tmp1_7)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp2_6 = (PMachineValue)(((PrtSeq)Servers)[idx_2]);
                TMP_tmp3_6 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp2_6)?.Clone()));
                TMP_tmp4_4 = (PEvent)(new ShutDown(null));
                currentMachine.SendEvent(TMP_tmp3_6, (Event)TMP_tmp4_4);
                TMP_tmp5_3 = (PrtInt)((idx_2) + (((PrtInt)1)));
                idx_2 = TMP_tmp5_3;
            }
            TMP_tmp6_3 = (PEvent)(new PHalt(null));
            currentMachine.RaiseEvent((Event)TMP_tmp6_3);
            throw new PUnreachableCodeException();
        }
        public void Anon_7()
        {
            ClusterManager currentMachine = this;
            PrtNamedTuple payload_4 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_11 = null;
            PEvent TMP_tmp1_8 = null;
            PMachineValue TMP_tmp2_7 = null;
            PrtInt TMP_tmp3_7 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp4_5 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_11 = (PMachineValue)(((PMachineValue)((IPrtValue)Leader)?.Clone()));
            TMP_tmp1_8 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
            TMP_tmp2_7 = (PMachineValue)(((PrtNamedTuple)payload_4)["Client"]);
            TMP_tmp3_7 = (PrtInt)(((PrtNamedTuple)payload_4)["Command"]);
            TMP_tmp4_5 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Client","Command"}, TMP_tmp2_7, TMP_tmp3_7)));
            currentMachine.SendEvent(TMP_tmp0_11, (Event)TMP_tmp1_8, TMP_tmp4_5);
        }
        public void Anon_8()
        {
            ClusterManager currentMachine = this;
            PrtNamedTuple payload_5 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PMachineValue TMP_tmp0_12 = null;
            PEvent TMP_tmp1_9 = null;
            PrtNamedTuple TMP_tmp2_8 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_12 = (PMachineValue)(currentMachine.self);
            TMP_tmp1_9 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
            TMP_tmp2_8 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_5)?.Clone()));
            currentMachine.SendEvent(TMP_tmp0_12, (Event)TMP_tmp1_9, TMP_tmp2_8);
        }
        public void Anon_9()
        {
            ClusterManager currentMachine = this;
            PrtNamedTuple payload_6 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_13 = (new PrtNamedTuple(new string[]{"Leader","Term"},null, ((PrtInt)0)));
            TMP_tmp0_13 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_6)?.Clone()));
            UpdateLeader(TMP_tmp0_13);
        }
        public void BecomeUnavailable()
        {
            ClusterManager currentMachine = this;
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_1))]
        class __InitState__ : MachineState { }
        
        [OnEntry(nameof(Anon_4))]
        [OnEventGotoState(typeof(LocalEvent), typeof(Configuring))]
        class Init_1 : MachineState
        {
        }
        [OnEntry(nameof(Anon_5))]
        [OnEventGotoState(typeof(LocalEvent), typeof(Unavailable))]
        class Configuring : MachineState
        {
        }
        [OnEventDoAction(typeof(NotifyLeaderUpdate), nameof(Anon_6))]
        [OnEventDoAction(typeof(ShutDown), nameof(ShuttingDown))]
        [OnEventGotoState(typeof(LocalEvent), typeof(Available))]
        [DeferEvents(typeof(Request))]
        class Unavailable : MachineState
        {
        }
        [OnEventDoAction(typeof(Request), nameof(Anon_7))]
        [OnEventDoAction(typeof(RedirectRequest), nameof(Anon_8))]
        [OnEventDoAction(typeof(NotifyLeaderUpdate), nameof(Anon_9))]
        [OnEventDoAction(typeof(ShutDown), nameof(ShuttingDown))]
        [OnEventGotoState(typeof(LocalEvent), typeof(Unavailable))]
        class Available : MachineState
        {
        }
    }
    internal partial class SafetyMonitor : PMonitor
    {
        private PrtMap TermsWithLeader = new PrtMap();
        static SafetyMonitor() {
            observes.Add(nameof(NotifyLeaderElected));
        }
        
        public void Anon_10()
        {
            try {
                SafetyMonitor currentMachine = this;
                PrtMap TMP_tmp0_14 = new PrtMap();
                PEvent TMP_tmp1_10 = null;
                TMP_tmp0_14 = (PrtMap)(new PrtMap());
                TermsWithLeader = TMP_tmp0_14;
                TMP_tmp1_10 = (PEvent)(new LocalEvent(null));
                currentMachine.RaiseEvent((Event)TMP_tmp1_10);
                throw new PUnreachableCodeException();
            }
            catch(PNonStandardReturnException) {}
        }
        public void Anon_11()
        {
            try {
                SafetyMonitor currentMachine = this;
                PrtInt payload_7 = (PrtInt)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
                this.gotoPayload = null;
                PrtInt TMP_tmp0_15 = ((PrtInt)0);
                TMP_tmp0_15 = (PrtInt)(((PrtInt)((IPrtValue)payload_7)?.Clone()));
                ProcessLeaderElected(TMP_tmp0_15);
            }
            catch(PNonStandardReturnException) {}
        }
        public void ProcessLeaderElected(PrtInt payload_8)
        {
            SafetyMonitor currentMachine = this;
            PrtInt term = ((PrtInt)0);
            PrtBool TMP_tmp0_16 = ((PrtBool)false);
            PrtBool TMP_tmp1_11 = ((PrtBool)false);
            PrtBool TMP_tmp2_9 = ((PrtBool)false);
            term = (PrtInt)(((PrtInt)((IPrtValue)payload_8)?.Clone()));
            TMP_tmp0_16 = (PrtBool)(((PrtMap)TermsWithLeader)[term]);
            if (TMP_tmp0_16)
            {
                PModule.runtime.Logger.WriteLine("<PrintLog> Detected more than one leader in term {0}", term);
            }
            TMP_tmp1_11 = (PrtBool)(((PrtMap)TermsWithLeader)[term]);
            TMP_tmp2_9 = (PrtBool)(!(TMP_tmp1_11));
            currentMachine.Assert(TMP_tmp2_9,"Assertion Failed: ");
            ((PrtMap)TermsWithLeader)[term] = (PrtBool)(((PrtBool)true));
        }
        [Start]
        [OnEntry(nameof(Anon_10))]
        [OnEventGotoState(typeof(LocalEvent), typeof(Monitoring))]
        class Init_2 : MonitorState
        {
        }
        [OnEventDoAction(typeof(NotifyLeaderElected), nameof(Anon_11))]
        class Monitoring : MonitorState
        {
        }
    }
    internal partial class Server : PMachine
    {
        private PrtInt ServerId = ((PrtInt)0);
        private PMachineValue ClusterManager_1 = null;
        private PrtSeq Servers_1 = new PrtSeq();
        private PMachineValue LeaderId = null;
        private PMachineValue ElectionTimer = null;
        private PMachineValue PeriodicTimer = null;
        private PrtInt CurrentTerm = ((PrtInt)0);
        private PMachineValue VotedFor = null;
        private PrtSeq Logs = new PrtSeq();
        private PrtInt CommitIndex = ((PrtInt)0);
        private PrtInt LastApplied = ((PrtInt)0);
        private PrtMap NextIndex = new PrtMap();
        private PrtMap MatchIndex = new PrtMap();
        private PrtInt VotesReceived = ((PrtInt)0);
        private PrtNamedTuple LastClientRequest = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
        private PrtInt i = ((PrtInt)0);
        public class ConstructorEvent : PEvent{public ConstructorEvent(IPrtValue val) : base(val) { }}
        
        protected override Event GetConstructorEvent(IPrtValue value) { return new ConstructorEvent((IPrtValue)value); }
        public Server() {
            this.sends.Add(nameof(AppendEntriesRequest));
            this.sends.Add(nameof(AppendEntriesResponse));
            this.sends.Add(nameof(BecomeCandidate));
            this.sends.Add(nameof(BecomeFollower));
            this.sends.Add(nameof(BecomeLeader));
            this.sends.Add(nameof(CConfigureEvent));
            this.sends.Add(nameof(ECancelTimer));
            this.sends.Add(nameof(EConfigureEvent));
            this.sends.Add(nameof(EMonitorInit));
            this.sends.Add(nameof(EStartTimer));
            this.sends.Add(nameof(ETickEvent));
            this.sends.Add(nameof(ETimeout));
            this.sends.Add(nameof(LocalEvent));
            this.sends.Add(nameof(NotifyLeaderElected));
            this.sends.Add(nameof(NotifyLeaderUpdate));
            this.sends.Add(nameof(PCancelTimer));
            this.sends.Add(nameof(PConfigureEvent));
            this.sends.Add(nameof(PStartTimer));
            this.sends.Add(nameof(PTickEvent));
            this.sends.Add(nameof(PTimeout));
            this.sends.Add(nameof(RedirectRequest));
            this.sends.Add(nameof(Request));
            this.sends.Add(nameof(Response));
            this.sends.Add(nameof(SConfigureEvent));
            this.sends.Add(nameof(ShutDown));
            this.sends.Add(nameof(VoteRequest));
            this.sends.Add(nameof(VoteResponse));
            this.sends.Add(nameof(PHalt));
            this.receives.Add(nameof(AppendEntriesRequest));
            this.receives.Add(nameof(AppendEntriesResponse));
            this.receives.Add(nameof(BecomeCandidate));
            this.receives.Add(nameof(BecomeFollower));
            this.receives.Add(nameof(BecomeLeader));
            this.receives.Add(nameof(CConfigureEvent));
            this.receives.Add(nameof(ECancelTimer));
            this.receives.Add(nameof(EConfigureEvent));
            this.receives.Add(nameof(EMonitorInit));
            this.receives.Add(nameof(EStartTimer));
            this.receives.Add(nameof(ETickEvent));
            this.receives.Add(nameof(ETimeout));
            this.receives.Add(nameof(LocalEvent));
            this.receives.Add(nameof(NotifyLeaderElected));
            this.receives.Add(nameof(NotifyLeaderUpdate));
            this.receives.Add(nameof(PCancelTimer));
            this.receives.Add(nameof(PConfigureEvent));
            this.receives.Add(nameof(PStartTimer));
            this.receives.Add(nameof(PTickEvent));
            this.receives.Add(nameof(PTimeout));
            this.receives.Add(nameof(RedirectRequest));
            this.receives.Add(nameof(Request));
            this.receives.Add(nameof(Response));
            this.receives.Add(nameof(SConfigureEvent));
            this.receives.Add(nameof(ShutDown));
            this.receives.Add(nameof(VoteRequest));
            this.receives.Add(nameof(VoteResponse));
            this.receives.Add(nameof(PHalt));
        }
        
        public void Anon_12()
        {
            Server currentMachine = this;
            PMachineValue TMP_tmp0_17 = null;
            PMachineValue TMP_tmp1_12 = null;
            PrtSeq TMP_tmp2_10 = new PrtSeq();
            PrtMap TMP_tmp3_8 = new PrtMap();
            PrtMap TMP_tmp4_6 = new PrtMap();
            i = (PrtInt)(((PrtInt)0));
            CurrentTerm = (PrtInt)(((PrtInt)0));
            TMP_tmp0_17 = (PMachineValue)(null);
            LeaderId = TMP_tmp0_17;
            TMP_tmp1_12 = (PMachineValue)(null);
            VotedFor = TMP_tmp1_12;
            TMP_tmp2_10 = (PrtSeq)(new PrtSeq());
            Logs = TMP_tmp2_10;
            CommitIndex = (PrtInt)(((PrtInt)0));
            LastApplied = (PrtInt)(((PrtInt)0));
            TMP_tmp3_8 = (PrtMap)(new PrtMap());
            NextIndex = TMP_tmp3_8;
            TMP_tmp4_6 = (PrtMap)(new PrtMap());
            MatchIndex = TMP_tmp4_6;
        }
        public void Anon_13()
        {
            Server currentMachine = this;
            PrtNamedTuple payload_9 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_18 = ((PrtInt)0);
            PrtSeq TMP_tmp1_13 = new PrtSeq();
            PMachineValue TMP_tmp2_11 = null;
            PMachineValue TMP_tmp3_9 = null;
            PMachineValue TMP_tmp4_7 = null;
            PEvent TMP_tmp5_4 = null;
            PMachineValue TMP_tmp6_4 = null;
            PMachineValue TMP_tmp7_2 = null;
            PMachineValue TMP_tmp8_1 = null;
            PEvent TMP_tmp9_1 = null;
            PMachineValue TMP_tmp10_1 = null;
            PEvent TMP_tmp11_1 = null;
            TMP_tmp0_18 = (PrtInt)(((PrtNamedTuple)payload_9)["Id"]);
            ServerId = TMP_tmp0_18;
            TMP_tmp1_13 = (PrtSeq)(((PrtNamedTuple)payload_9)["Servers"]);
            Servers_1 = TMP_tmp1_13;
            TMP_tmp2_11 = (PMachineValue)(((PrtNamedTuple)payload_9)["ClusterManager"]);
            ClusterManager_1 = TMP_tmp2_11;
            TMP_tmp3_9 = (PMachineValue)(null);
            ElectionTimer = TMP_tmp3_9;
            TMP_tmp4_7 = (PMachineValue)(((PMachineValue)((IPrtValue)ElectionTimer)?.Clone()));
            TMP_tmp5_4 = (PEvent)(new EConfigureEvent(null));
            TMP_tmp6_4 = (PMachineValue)(currentMachine.self);
            currentMachine.SendEvent(TMP_tmp4_7, (Event)TMP_tmp5_4, TMP_tmp6_4);
            TMP_tmp7_2 = (PMachineValue)(null);
            PeriodicTimer = TMP_tmp7_2;
            TMP_tmp8_1 = (PMachineValue)(((PMachineValue)((IPrtValue)PeriodicTimer)?.Clone()));
            TMP_tmp9_1 = (PEvent)(new PConfigureEvent(null));
            TMP_tmp10_1 = (PMachineValue)(currentMachine.self);
            currentMachine.SendEvent(TMP_tmp8_1, (Event)TMP_tmp9_1, TMP_tmp10_1);
            TMP_tmp11_1 = (PEvent)(new BecomeFollower(null));
            currentMachine.RaiseEvent((Event)TMP_tmp11_1);
            throw new PUnreachableCodeException();
        }
        public void Anon_14()
        {
            Server currentMachine = this;
            PMachineValue TMP_tmp0_19 = null;
            PMachineValue TMP_tmp1_14 = null;
            PEvent TMP_tmp2_12 = null;
            TMP_tmp0_19 = (PMachineValue)(null);
            LeaderId = TMP_tmp0_19;
            VotesReceived = (PrtInt)(((PrtInt)0));
            TMP_tmp1_14 = (PMachineValue)(((PMachineValue)((IPrtValue)ElectionTimer)?.Clone()));
            TMP_tmp2_12 = (PEvent)(new EStartTimer(null));
            currentMachine.SendEvent(TMP_tmp1_14, (Event)TMP_tmp2_12);
        }
        public void Anon_15()
        {
            Server currentMachine = this;
            PrtNamedTuple payload_10 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtBool TMP_tmp0_20 = ((PrtBool)false);
            PMachineValue TMP_tmp1_15 = null;
            PEvent TMP_tmp2_13 = null;
            PMachineValue TMP_tmp3_10 = null;
            PrtInt TMP_tmp4_8 = ((PrtInt)0);
            PMachineValue TMP_tmp5_5 = null;
            PEvent TMP_tmp6_5 = null;
            PrtNamedTuple TMP_tmp7_3 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_20 = (PrtBool)((!PrtValues.SafeEquals(LeaderId,null)));
            if (TMP_tmp0_20)
            {
                TMP_tmp1_15 = (PMachineValue)(((PMachineValue)((IPrtValue)LeaderId)?.Clone()));
                TMP_tmp2_13 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
                TMP_tmp3_10 = (PMachineValue)(((PrtNamedTuple)payload_10)["Client"]);
                TMP_tmp4_8 = (PrtInt)(((PrtNamedTuple)payload_10)["Command"]);
                currentMachine.SendEvent(TMP_tmp1_15, (Event)TMP_tmp2_13, new PrtTuple(TMP_tmp3_10,TMP_tmp4_8));
            }
            else
            {
                TMP_tmp5_5 = (PMachineValue)(((PMachineValue)((IPrtValue)ClusterManager_1)?.Clone()));
                TMP_tmp6_5 = (PEvent)(new RedirectRequest((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
                TMP_tmp7_3 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_10)?.Clone()));
                currentMachine.SendEvent(TMP_tmp5_5, (Event)TMP_tmp6_5, TMP_tmp7_3);
            }
        }
        public void Anon_16()
        {
            Server currentMachine = this;
            PrtNamedTuple payload_11 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_21 = ((PrtInt)0);
            PrtBool TMP_tmp1_16 = ((PrtBool)false);
            PrtInt TMP_tmp2_14 = ((PrtInt)0);
            PMachineValue TMP_tmp3_11 = null;
            PrtNamedTuple TMP_tmp4_9 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            TMP_tmp0_21 = (PrtInt)(((PrtNamedTuple)payload_11)["Term"]);
            TMP_tmp1_16 = (PrtBool)((TMP_tmp0_21) > (CurrentTerm));
            if (TMP_tmp1_16)
            {
                TMP_tmp2_14 = (PrtInt)(((PrtNamedTuple)payload_11)["Term"]);
                CurrentTerm = TMP_tmp2_14;
                TMP_tmp3_11 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_11;
            }
            TMP_tmp4_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_11)?.Clone()));
            Vote(TMP_tmp4_9);
        }
        public void Anon_17()
        {
            Server currentMachine = this;
            PrtNamedTuple request_1 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_22 = ((PrtInt)0);
            PrtBool TMP_tmp1_17 = ((PrtBool)false);
            PrtInt TMP_tmp2_15 = ((PrtInt)0);
            PMachineValue TMP_tmp3_12 = null;
            TMP_tmp0_22 = (PrtInt)(((PrtNamedTuple)request_1)["Term"]);
            TMP_tmp1_17 = (PrtBool)((TMP_tmp0_22) > (CurrentTerm));
            if (TMP_tmp1_17)
            {
                TMP_tmp2_15 = (PrtInt)(((PrtNamedTuple)request_1)["Term"]);
                CurrentTerm = TMP_tmp2_15;
                TMP_tmp3_12 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_12;
            }
        }
        public void Anon_18()
        {
            Server currentMachine = this;
            PrtNamedTuple request_2 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_23 = ((PrtInt)0);
            PrtBool TMP_tmp1_18 = ((PrtBool)false);
            PrtInt TMP_tmp2_16 = ((PrtInt)0);
            PMachineValue TMP_tmp3_13 = null;
            PrtNamedTuple TMP_tmp4_10 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_23 = (PrtInt)(((PrtNamedTuple)request_2)["Term"]);
            TMP_tmp1_18 = (PrtBool)((TMP_tmp0_23) > (CurrentTerm));
            if (TMP_tmp1_18)
            {
                TMP_tmp2_16 = (PrtInt)(((PrtNamedTuple)request_2)["Term"]);
                CurrentTerm = TMP_tmp2_16;
                TMP_tmp3_13 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_13;
            }
            TMP_tmp4_10 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_2)?.Clone()));
            AppendEntries(TMP_tmp4_10);
        }
        public void Anon_19()
        {
            Server currentMachine = this;
            PrtNamedTuple request_3 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_24 = ((PrtInt)0);
            PrtBool TMP_tmp1_19 = ((PrtBool)false);
            PrtInt TMP_tmp2_17 = ((PrtInt)0);
            PMachineValue TMP_tmp3_14 = null;
            TMP_tmp0_24 = (PrtInt)(((PrtNamedTuple)request_3)["Term"]);
            TMP_tmp1_19 = (PrtBool)((TMP_tmp0_24) > (CurrentTerm));
            if (TMP_tmp1_19)
            {
                TMP_tmp2_17 = (PrtInt)(((PrtNamedTuple)request_3)["Term"]);
                CurrentTerm = TMP_tmp2_17;
                TMP_tmp3_14 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_14;
            }
        }
        public void Anon_20()
        {
            Server currentMachine = this;
            PEvent TMP_tmp0_25 = null;
            TMP_tmp0_25 = (PEvent)(new BecomeCandidate(null));
            currentMachine.RaiseEvent((Event)TMP_tmp0_25);
            throw new PUnreachableCodeException();
        }
        public void Anon_21()
        {
            Server currentMachine = this;
            ShuttingDown_1();
        }
        public void Anon_22()
        {
            Server currentMachine = this;
            PrtInt TMP_tmp0_26 = ((PrtInt)0);
            PMachineValue TMP_tmp1_20 = null;
            PEvent TMP_tmp2_18 = null;
            TMP_tmp0_26 = (PrtInt)((CurrentTerm) + (((PrtInt)1)));
            CurrentTerm = TMP_tmp0_26;
            VotedFor = (PMachineValue)(new PMachineValue(currentMachine.self));
            VotesReceived = (PrtInt)(((PrtInt)1));
            TMP_tmp1_20 = (PMachineValue)(((PMachineValue)((IPrtValue)ElectionTimer)?.Clone()));
            TMP_tmp2_18 = (PEvent)(new EStartTimer(null));
            currentMachine.SendEvent(TMP_tmp1_20, (Event)TMP_tmp2_18);
            BroadcastVoteRequests();
        }
        public void Anon_23()
        {
            Server currentMachine = this;
            PrtNamedTuple payload_12 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtBool TMP_tmp0_27 = ((PrtBool)false);
            PMachineValue TMP_tmp1_21 = null;
            PEvent TMP_tmp2_19 = null;
            PMachineValue TMP_tmp3_15 = null;
            PrtInt TMP_tmp4_11 = ((PrtInt)0);
            PMachineValue TMP_tmp5_6 = null;
            PEvent TMP_tmp6_6 = null;
            PrtNamedTuple TMP_tmp7_4 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_27 = (PrtBool)((!PrtValues.SafeEquals(LeaderId,null)));
            if (TMP_tmp0_27)
            {
                TMP_tmp1_21 = (PMachineValue)(((PMachineValue)((IPrtValue)LeaderId)?.Clone()));
                TMP_tmp2_19 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
                TMP_tmp3_15 = (PMachineValue)(((PrtNamedTuple)payload_12)["Client"]);
                TMP_tmp4_11 = (PrtInt)(((PrtNamedTuple)payload_12)["Command"]);
                currentMachine.SendEvent(TMP_tmp1_21, (Event)TMP_tmp2_19, new PrtTuple(TMP_tmp3_15,TMP_tmp4_11));
            }
            else
            {
                TMP_tmp5_6 = (PMachineValue)(((PMachineValue)((IPrtValue)ClusterManager_1)?.Clone()));
                TMP_tmp6_6 = (PEvent)(new RedirectRequest((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
                TMP_tmp7_4 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)payload_12)?.Clone()));
                currentMachine.SendEvent(TMP_tmp5_6, (Event)TMP_tmp6_6, TMP_tmp7_4);
            }
        }
        public void Anon_24()
        {
            Server currentMachine = this;
            PrtNamedTuple request_4 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_28 = ((PrtInt)0);
            PrtBool TMP_tmp1_22 = ((PrtBool)false);
            PrtInt TMP_tmp2_20 = ((PrtInt)0);
            PMachineValue TMP_tmp3_16 = null;
            PrtNamedTuple TMP_tmp4_12 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            PEvent TMP_tmp5_7 = null;
            PrtNamedTuple TMP_tmp6_7 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            TMP_tmp0_28 = (PrtInt)(((PrtNamedTuple)request_4)["Term"]);
            TMP_tmp1_22 = (PrtBool)((TMP_tmp0_28) > (CurrentTerm));
            if (TMP_tmp1_22)
            {
                TMP_tmp2_20 = (PrtInt)(((PrtNamedTuple)request_4)["Term"]);
                CurrentTerm = TMP_tmp2_20;
                TMP_tmp3_16 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_16;
                TMP_tmp4_12 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_4)?.Clone()));
                Vote(TMP_tmp4_12);
                TMP_tmp5_7 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp5_7);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp6_7 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_4)?.Clone()));
                Vote(TMP_tmp6_7);
            }
        }
        public void Anon_25()
        {
            Server currentMachine = this;
            PrtNamedTuple request_5 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_29 = ((PrtInt)0);
            PrtBool TMP_tmp1_23 = ((PrtBool)false);
            PrtInt TMP_tmp2_21 = ((PrtInt)0);
            PMachineValue TMP_tmp3_17 = null;
            PEvent TMP_tmp4_13 = null;
            PrtInt TMP_tmp5_8 = ((PrtInt)0);
            PrtBool TMP_tmp6_8 = ((PrtBool)false);
            PrtBool TMP_tmp7_5 = ((PrtBool)false);
            PrtInt TMP_tmp8_2 = ((PrtInt)0);
            PrtInt TMP_tmp9_2 = ((PrtInt)0);
            PrtInt TMP_tmp10_2 = ((PrtInt)0);
            PrtInt TMP_tmp11_2 = ((PrtInt)0);
            PrtBool TMP_tmp12_1 = ((PrtBool)false);
            PEvent TMP_tmp13_1 = null;
            TMP_tmp0_29 = (PrtInt)(((PrtNamedTuple)request_5)["Term"]);
            TMP_tmp1_23 = (PrtBool)((TMP_tmp0_29) > (CurrentTerm));
            if (TMP_tmp1_23)
            {
                TMP_tmp2_21 = (PrtInt)(((PrtNamedTuple)request_5)["Term"]);
                CurrentTerm = TMP_tmp2_21;
                TMP_tmp3_17 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_17;
                TMP_tmp4_13 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp4_13);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp5_8 = (PrtInt)(((PrtNamedTuple)request_5)["Term"]);
                TMP_tmp6_8 = (PrtBool)((!PrtValues.SafeEquals(TMP_tmp5_8,CurrentTerm)));
                if (TMP_tmp6_8)
                {
                }
                else
                {
                    TMP_tmp7_5 = (PrtBool)(((PrtNamedTuple)request_5)["VoteGranted"]);
                    if (TMP_tmp7_5)
                    {
                        TMP_tmp8_2 = (PrtInt)((VotesReceived) + (((PrtInt)1)));
                        VotesReceived = TMP_tmp8_2;
                        TMP_tmp9_2 = (PrtInt)(((PrtInt)(Servers_1).Count));
                        TMP_tmp10_2 = (PrtInt)((TMP_tmp9_2) / (((PrtInt)2)));
                        TMP_tmp11_2 = (PrtInt)((TMP_tmp10_2) + (((PrtInt)1)));
                        TMP_tmp12_1 = (PrtBool)((VotesReceived) >= (TMP_tmp11_2));
                        if (TMP_tmp12_1)
                        {
                            VotesReceived = (PrtInt)(((PrtInt)0));
                            TMP_tmp13_1 = (PEvent)(new BecomeLeader(null));
                            currentMachine.RaiseEvent((Event)TMP_tmp13_1);
                            throw new PUnreachableCodeException();
                        }
                    }
                }
            }
        }
        public void Anon_26()
        {
            Server currentMachine = this;
            PrtNamedTuple request_6 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtInt TMP_tmp0_30 = ((PrtInt)0);
            PrtBool TMP_tmp1_24 = ((PrtBool)false);
            PrtInt TMP_tmp2_22 = ((PrtInt)0);
            PMachineValue TMP_tmp3_18 = null;
            PrtNamedTuple TMP_tmp4_14 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            PEvent TMP_tmp5_9 = null;
            PrtNamedTuple TMP_tmp6_9 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_30 = (PrtInt)(((PrtNamedTuple)request_6)["Term"]);
            TMP_tmp1_24 = (PrtBool)((TMP_tmp0_30) > (CurrentTerm));
            if (TMP_tmp1_24)
            {
                TMP_tmp2_22 = (PrtInt)(((PrtNamedTuple)request_6)["Term"]);
                CurrentTerm = TMP_tmp2_22;
                TMP_tmp3_18 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_18;
                TMP_tmp4_14 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_6)?.Clone()));
                AppendEntries(TMP_tmp4_14);
                TMP_tmp5_9 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp5_9);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp6_9 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_6)?.Clone()));
                AppendEntries(TMP_tmp6_9);
            }
        }
        public void Anon_27()
        {
            Server currentMachine = this;
            PrtNamedTuple request_7 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_31 = (new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null));
            TMP_tmp0_31 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_7)?.Clone()));
            RespondAppendEntriesAsCandidate(TMP_tmp0_31);
        }
        public void Anon_28()
        {
            Server currentMachine = this;
            PEvent TMP_tmp0_32 = null;
            TMP_tmp0_32 = (PEvent)(new BecomeCandidate(null));
            currentMachine.RaiseEvent((Event)TMP_tmp0_32);
            throw new PUnreachableCodeException();
        }
        public void BroadcastVoteRequests()
        {
            Server currentMachine = this;
            PrtInt idx_3 = ((PrtInt)0);
            PrtInt lastLogIndex = ((PrtInt)0);
            PrtInt lastLogTerm = ((PrtInt)0);
            PMachineValue TMP_tmp0_33 = null;
            PEvent TMP_tmp1_25 = null;
            PrtInt TMP_tmp2_23 = ((PrtInt)0);
            PrtBool TMP_tmp3_19 = ((PrtBool)false);
            PrtBool TMP_tmp4_15 = ((PrtBool)false);
            PrtBool TMP_tmp5_10 = ((PrtBool)false);
            PrtInt TMP_tmp6_10 = ((PrtInt)0);
            PrtInt TMP_tmp7_6 = ((PrtInt)0);
            PrtInt TMP_tmp8_3 = ((PrtInt)0);
            PMachineValue TMP_tmp9_3 = null;
            PMachineValue TMP_tmp10_3 = null;
            PEvent TMP_tmp11_3 = null;
            PrtInt TMP_tmp12_2 = ((PrtInt)0);
            PMachineValue TMP_tmp13_2 = null;
            PrtInt TMP_tmp14 = ((PrtInt)0);
            PrtInt TMP_tmp15 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp16 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp17 = ((PrtInt)0);
            TMP_tmp0_33 = (PMachineValue)(((PMachineValue)((IPrtValue)PeriodicTimer)?.Clone()));
            TMP_tmp1_25 = (PEvent)(new PStartTimer(null));
            currentMachine.SendEvent(TMP_tmp0_33, (Event)TMP_tmp1_25);
            idx_3 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp2_23 = (PrtInt)(((PrtInt)(Servers_1).Count));
                TMP_tmp3_19 = (PrtBool)((idx_3) < (TMP_tmp2_23));
                TMP_tmp4_15 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp3_19)?.Clone()));
                if (TMP_tmp4_15)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp5_10 = (PrtBool)((PrtValues.SafeEquals(idx_3,ServerId)));
                if (TMP_tmp5_10)
                {
                    continue;
                }
                TMP_tmp6_10 = (PrtInt)(((PrtInt)(Logs).Count));
                lastLogIndex = TMP_tmp6_10;
                TMP_tmp7_6 = (PrtInt)(((PrtInt)((IPrtValue)lastLogIndex)?.Clone()));
                TMP_tmp8_3 = (PrtInt)(GetLogTermForIndex(TMP_tmp7_6));
                lastLogTerm = TMP_tmp8_3;
                TMP_tmp9_3 = (PMachineValue)(((PrtSeq)Servers_1)[idx_3]);
                TMP_tmp10_3 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp9_3)?.Clone()));
                TMP_tmp11_3 = (PEvent)(new VoteRequest((new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)))));
                TMP_tmp12_2 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp13_2 = (PMachineValue)(currentMachine.self);
                TMP_tmp14 = (PrtInt)(((PrtInt)((IPrtValue)lastLogIndex)?.Clone()));
                TMP_tmp15 = (PrtInt)(((PrtInt)((IPrtValue)lastLogTerm)?.Clone()));
                TMP_tmp16 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"}, TMP_tmp12_2, TMP_tmp13_2, TMP_tmp14, TMP_tmp15)));
                currentMachine.SendEvent(TMP_tmp10_3, (Event)TMP_tmp11_3, TMP_tmp16);
                TMP_tmp17 = (PrtInt)((idx_3) + (((PrtInt)1)));
                idx_3 = TMP_tmp17;
            }
        }
        public void RespondAppendEntriesAsCandidate(PrtNamedTuple request_8)
        {
            Server currentMachine = this;
            PrtInt TMP_tmp0_34 = ((PrtInt)0);
            PrtBool TMP_tmp1_26 = ((PrtBool)false);
            PrtInt TMP_tmp2_24 = ((PrtInt)0);
            PMachineValue TMP_tmp3_20 = null;
            PEvent TMP_tmp4_16 = null;
            TMP_tmp0_34 = (PrtInt)(((PrtNamedTuple)request_8)["Term"]);
            TMP_tmp1_26 = (PrtBool)((TMP_tmp0_34) > (CurrentTerm));
            if (TMP_tmp1_26)
            {
                TMP_tmp2_24 = (PrtInt)(((PrtNamedTuple)request_8)["Term"]);
                CurrentTerm = TMP_tmp2_24;
                TMP_tmp3_20 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_20;
                TMP_tmp4_16 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp4_16);
                throw new PUnreachableCodeException();
            }
        }
        public void Anon_29()
        {
            Server currentMachine = this;
            PrtInt logIndex = ((PrtInt)0);
            PrtInt logTerm = ((PrtInt)0);
            PrtInt idx_4 = ((PrtInt)0);
            PEvent TMP_tmp0_35 = null;
            PrtInt TMP_tmp1_27 = ((PrtInt)0);
            PrtTuple TMP_tmp2_25 = (new PrtTuple(null, ((PrtInt)0)));
            PMachineValue TMP_tmp3_21 = null;
            PEvent TMP_tmp4_17 = null;
            PMachineValue TMP_tmp5_11 = null;
            PrtInt TMP_tmp6_11 = ((PrtInt)0);
            PrtInt TMP_tmp7_7 = ((PrtInt)0);
            PrtInt TMP_tmp8_4 = ((PrtInt)0);
            PrtInt TMP_tmp9_4 = ((PrtInt)0);
            PrtMap TMP_tmp10_4 = new PrtMap();
            PrtMap TMP_tmp11_4 = new PrtMap();
            PrtInt TMP_tmp12_3 = ((PrtInt)0);
            PrtBool TMP_tmp13_3 = ((PrtBool)false);
            PrtBool TMP_tmp14_1 = ((PrtBool)false);
            PrtBool TMP_tmp15_1 = ((PrtBool)false);
            PMachineValue TMP_tmp16_1 = null;
            PrtInt TMP_tmp17_1 = ((PrtInt)0);
            PMachineValue TMP_tmp18 = null;
            PrtInt TMP_tmp19 = ((PrtInt)0);
            PrtInt TMP_tmp20 = ((PrtInt)0);
            PrtBool TMP_tmp21 = ((PrtBool)false);
            PrtBool TMP_tmp22 = ((PrtBool)false);
            PrtBool TMP_tmp23 = ((PrtBool)false);
            PMachineValue TMP_tmp24 = null;
            PMachineValue TMP_tmp25 = null;
            PEvent TMP_tmp26 = null;
            PrtInt TMP_tmp27 = ((PrtInt)0);
            PMachineValue TMP_tmp28 = null;
            PrtInt TMP_tmp29 = ((PrtInt)0);
            PrtInt TMP_tmp30 = ((PrtInt)0);
            PrtSeq TMP_tmp31 = new PrtSeq();
            PrtInt TMP_tmp32 = ((PrtInt)0);
            PMachineValue TMP_tmp33 = null;
            PrtNamedTuple TMP_tmp34 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_35 = (PEvent)(new NotifyLeaderElected(((PrtInt)0)));
            TMP_tmp1_27 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
            TMP_tmp2_25 = (PrtTuple)(new PrtTuple(TMP_tmp0_35, TMP_tmp1_27));
            currentMachine.Announce((Event)new EMonitorInit(null), TMP_tmp2_25);
            TMP_tmp3_21 = (PMachineValue)(((PMachineValue)((IPrtValue)ClusterManager_1)?.Clone()));
            TMP_tmp4_17 = (PEvent)(new NotifyLeaderUpdate((new PrtNamedTuple(new string[]{"Leader","Term"},null, ((PrtInt)0)))));
            TMP_tmp5_11 = (PMachineValue)(currentMachine.self);
            TMP_tmp6_11 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
            currentMachine.SendEvent(TMP_tmp3_21, (Event)TMP_tmp4_17, new PrtTuple(TMP_tmp5_11,TMP_tmp6_11));
            TMP_tmp7_7 = (PrtInt)(((PrtInt)(Logs).Count));
            logIndex = TMP_tmp7_7;
            TMP_tmp8_4 = (PrtInt)(((PrtInt)((IPrtValue)logIndex)?.Clone()));
            TMP_tmp9_4 = (PrtInt)(GetLogTermForIndex(TMP_tmp8_4));
            logTerm = TMP_tmp9_4;
            TMP_tmp10_4 = (PrtMap)(new PrtMap());
            NextIndex = TMP_tmp10_4;
            TMP_tmp11_4 = (PrtMap)(new PrtMap());
            MatchIndex = TMP_tmp11_4;
            idx_4 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp12_3 = (PrtInt)(((PrtInt)(Servers_1).Count));
                TMP_tmp13_3 = (PrtBool)((idx_4) < (TMP_tmp12_3));
                TMP_tmp14_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp13_3)?.Clone()));
                if (TMP_tmp14_1)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp15_1 = (PrtBool)((PrtValues.SafeEquals(idx_4,ServerId)));
                if (TMP_tmp15_1)
                {
                    continue;
                }
                TMP_tmp16_1 = (PMachineValue)(((PrtSeq)Servers_1)[idx_4]);
                TMP_tmp17_1 = (PrtInt)((logIndex) + (((PrtInt)1)));
                ((PrtMap)NextIndex)[TMP_tmp16_1] = TMP_tmp17_1;
                TMP_tmp18 = (PMachineValue)(((PrtSeq)Servers_1)[idx_4]);
                ((PrtMap)MatchIndex)[TMP_tmp18] = (PrtInt)(((PrtInt)0));
                TMP_tmp19 = (PrtInt)((idx_4) + (((PrtInt)1)));
                idx_4 = TMP_tmp19;
            }
            idx_4 = (PrtInt)(((PrtInt)0));
            while (((PrtBool)true))
            {
                TMP_tmp20 = (PrtInt)(((PrtInt)(Servers_1).Count));
                TMP_tmp21 = (PrtBool)((idx_4) < (TMP_tmp20));
                TMP_tmp22 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp21)?.Clone()));
                if (TMP_tmp22)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp23 = (PrtBool)((PrtValues.SafeEquals(idx_4,ServerId)));
                if (TMP_tmp23)
                {
                    continue;
                }
                TMP_tmp24 = (PMachineValue)(((PrtSeq)Servers_1)[idx_4]);
                TMP_tmp25 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp24)?.Clone()));
                TMP_tmp26 = (PEvent)(new AppendEntriesRequest((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null))));
                TMP_tmp27 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp28 = (PMachineValue)(currentMachine.self);
                TMP_tmp29 = (PrtInt)(((PrtInt)((IPrtValue)logIndex)?.Clone()));
                TMP_tmp30 = (PrtInt)(((PrtInt)((IPrtValue)logTerm)?.Clone()));
                TMP_tmp31 = (PrtSeq)(new PrtSeq());
                TMP_tmp32 = (PrtInt)(((PrtInt)((IPrtValue)CommitIndex)?.Clone()));
                TMP_tmp33 = (PMachineValue)(null);
                TMP_tmp34 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"}, TMP_tmp27, TMP_tmp28, TMP_tmp29, TMP_tmp30, TMP_tmp31, TMP_tmp32, TMP_tmp33)));
                currentMachine.SendEvent(TMP_tmp25, (Event)TMP_tmp26, TMP_tmp34);
            }
        }
        public void Anon_30()
        {
            Server currentMachine = this;
            PrtNamedTuple request_9 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_36 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_36 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_9)?.Clone()));
            ProcessClientRequest(TMP_tmp0_36);
        }
        public void Anon_31()
        {
            Server currentMachine = this;
            PrtNamedTuple request_10 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_37 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            TMP_tmp0_37 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_10)?.Clone()));
            VoteAsLeader(TMP_tmp0_37);
        }
        public void Anon_32()
        {
            Server currentMachine = this;
            PrtNamedTuple request_11 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_38 = (new PrtNamedTuple(new string[]{"Term","VoteGranted"},((PrtInt)0), ((PrtBool)false)));
            TMP_tmp0_38 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_11)?.Clone()));
            RespondVoteAsLeader(TMP_tmp0_38);
        }
        public void Anon_33()
        {
            Server currentMachine = this;
            PrtNamedTuple request_12 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_39 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_39 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_12)?.Clone()));
            AppendEntriesAsLeader(TMP_tmp0_39);
        }
        public void Anon_34()
        {
            Server currentMachine = this;
            PrtNamedTuple request_13 = (PrtNamedTuple)(gotoPayload ?? ((PEvent)currentMachine.ReceivedEvent).Payload);
            this.gotoPayload = null;
            PrtNamedTuple TMP_tmp0_40 = (new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null));
            TMP_tmp0_40 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_13)?.Clone()));
            RespondAppendEntriesAsLeader(TMP_tmp0_40);
        }
        public void ProcessClientRequest(PrtNamedTuple trigger)
        {
            Server currentMachine = this;
            PrtNamedTuple log = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtNamedTuple TMP_tmp0_41 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp1_28 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp2_26 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp3_22 = ((PrtInt)0);
            LastClientRequest = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)trigger)?.Clone()));
            TMP_tmp0_41 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0))));
            log = TMP_tmp0_41;
            ((PrtNamedTuple)log)["Term"] = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
            TMP_tmp1_28 = (PrtInt)(((PrtNamedTuple)LastClientRequest)["Command"]);
            ((PrtNamedTuple)log)["Command"] = TMP_tmp1_28;
            TMP_tmp2_26 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)log)?.Clone()));
            ((PrtSeq)Logs).Insert(i, TMP_tmp2_26);
            TMP_tmp3_22 = (PrtInt)((i) + (((PrtInt)1)));
            i = TMP_tmp3_22;
            BroadcastLastClientRequest();
        }
        public void BroadcastLastClientRequest()
        {
            Server currentMachine = this;
            PrtInt lastLogIndex_1 = ((PrtInt)0);
            PrtInt idx_5 = ((PrtInt)0);
            PrtInt prevLogIndex = ((PrtInt)0);
            PrtInt prevLogTerm = ((PrtInt)0);
            PMachineValue server = null;
            PrtSeq logsAppend = new PrtSeq();
            PrtInt TMP_tmp0_42 = ((PrtInt)0);
            PrtInt TMP_tmp1_29 = ((PrtInt)0);
            PrtBool TMP_tmp2_27 = ((PrtBool)false);
            PrtBool TMP_tmp3_23 = ((PrtBool)false);
            PrtBool TMP_tmp4_18 = ((PrtBool)false);
            PMachineValue TMP_tmp5_12 = null;
            PrtInt TMP_tmp6_12 = ((PrtInt)0);
            PrtBool TMP_tmp7_8 = ((PrtBool)false);
            PrtSeq TMP_tmp8_5 = new PrtSeq();
            PrtInt TMP_tmp9_5 = ((PrtInt)0);
            PrtInt TMP_tmp10_5 = ((PrtInt)0);
            PrtInt TMP_tmp11_5 = ((PrtInt)0);
            PrtBool TMP_tmp12_4 = ((PrtBool)false);
            PrtBool TMP_tmp13_4 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp14_2 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp15_2 = ((PrtInt)0);
            PrtInt TMP_tmp16_2 = ((PrtInt)0);
            PrtInt TMP_tmp17_2 = ((PrtInt)0);
            PrtInt TMP_tmp18_1 = ((PrtInt)0);
            PrtInt TMP_tmp19_1 = ((PrtInt)0);
            PMachineValue TMP_tmp20_1 = null;
            PEvent TMP_tmp21_1 = null;
            PrtInt TMP_tmp22_1 = ((PrtInt)0);
            PMachineValue TMP_tmp23_1 = null;
            PrtInt TMP_tmp24_1 = ((PrtInt)0);
            PrtInt TMP_tmp25_1 = ((PrtInt)0);
            PrtSeq TMP_tmp26_1 = new PrtSeq();
            PrtInt TMP_tmp27_1 = ((PrtInt)0);
            PMachineValue TMP_tmp28_1 = null;
            PrtNamedTuple TMP_tmp29_1 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_42 = (PrtInt)(((PrtInt)(Logs).Count));
            lastLogIndex_1 = TMP_tmp0_42;
            VotesReceived = (PrtInt)(((PrtInt)1));
            while (((PrtBool)true))
            {
                TMP_tmp1_29 = (PrtInt)(((PrtInt)(Servers_1).Count));
                TMP_tmp2_27 = (PrtBool)((idx_5) < (TMP_tmp1_29));
                TMP_tmp3_23 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp2_27)?.Clone()));
                if (TMP_tmp3_23)
                {
                }
                else
                {
                    break;
                }
                TMP_tmp4_18 = (PrtBool)((PrtValues.SafeEquals(idx_5,ServerId)));
                if (TMP_tmp4_18)
                {
                    continue;
                }
                TMP_tmp5_12 = (PMachineValue)(((PrtSeq)Servers_1)[idx_5]);
                server = TMP_tmp5_12;
                TMP_tmp6_12 = (PrtInt)(((PrtMap)NextIndex)[server]);
                TMP_tmp7_8 = (PrtBool)((lastLogIndex_1) < (TMP_tmp6_12));
                if (TMP_tmp7_8)
                {
                    continue;
                }
                TMP_tmp8_5 = (PrtSeq)(new PrtSeq());
                logsAppend = TMP_tmp8_5;
                TMP_tmp9_5 = (PrtInt)(((PrtMap)NextIndex)[server]);
                TMP_tmp10_5 = (PrtInt)((TMP_tmp9_5) - (((PrtInt)1)));
                idx_5 = TMP_tmp10_5;
                while (((PrtBool)true))
                {
                    TMP_tmp11_5 = (PrtInt)(((PrtInt)(Logs).Count));
                    TMP_tmp12_4 = (PrtBool)((idx_5) < (TMP_tmp11_5));
                    TMP_tmp13_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp12_4)?.Clone()));
                    if (TMP_tmp13_4)
                    {
                    }
                    else
                    {
                        break;
                    }
                    TMP_tmp14_2 = (PrtNamedTuple)(((PrtSeq)Logs)[idx_5]);
                    ((PrtSeq)logsAppend).Insert(idx_5, TMP_tmp14_2);
                    TMP_tmp15_2 = (PrtInt)((idx_5) + (((PrtInt)1)));
                    idx_5 = TMP_tmp15_2;
                }
                TMP_tmp16_2 = (PrtInt)(((PrtMap)NextIndex)[server]);
                TMP_tmp17_2 = (PrtInt)((TMP_tmp16_2) - (((PrtInt)1)));
                prevLogIndex = TMP_tmp17_2;
                TMP_tmp18_1 = (PrtInt)(((PrtInt)((IPrtValue)prevLogIndex)?.Clone()));
                TMP_tmp19_1 = (PrtInt)(GetLogTermForIndex(TMP_tmp18_1));
                prevLogTerm = TMP_tmp19_1;
                TMP_tmp20_1 = (PMachineValue)(((PMachineValue)((IPrtValue)server)?.Clone()));
                TMP_tmp21_1 = (PEvent)(new AppendEntriesRequest((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null))));
                TMP_tmp22_1 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp23_1 = (PMachineValue)(currentMachine.self);
                TMP_tmp24_1 = (PrtInt)(((PrtInt)((IPrtValue)prevLogIndex)?.Clone()));
                TMP_tmp25_1 = (PrtInt)(((PrtInt)((IPrtValue)prevLogTerm)?.Clone()));
                TMP_tmp26_1 = (PrtSeq)(((PrtSeq)((IPrtValue)Logs)?.Clone()));
                TMP_tmp27_1 = (PrtInt)(((PrtInt)((IPrtValue)CommitIndex)?.Clone()));
                TMP_tmp28_1 = (PMachineValue)(((PrtNamedTuple)LastClientRequest)["Client"]);
                TMP_tmp29_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"}, TMP_tmp22_1, TMP_tmp23_1, TMP_tmp24_1, TMP_tmp25_1, TMP_tmp26_1, TMP_tmp27_1, TMP_tmp28_1)));
                currentMachine.SendEvent(TMP_tmp20_1, (Event)TMP_tmp21_1, TMP_tmp29_1);
            }
        }
        public void VoteAsLeader(PrtNamedTuple request_14)
        {
            Server currentMachine = this;
            PrtInt TMP_tmp0_43 = ((PrtInt)0);
            PrtBool TMP_tmp1_30 = ((PrtBool)false);
            PrtInt TMP_tmp2_28 = ((PrtInt)0);
            PMachineValue TMP_tmp3_24 = null;
            PrtNamedTuple TMP_tmp4_19 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            PEvent TMP_tmp5_13 = null;
            PrtNamedTuple TMP_tmp6_13 = (new PrtNamedTuple(new string[]{"Term","CandidateId","LastLogIndex","LastLogTerm"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0)));
            TMP_tmp0_43 = (PrtInt)(((PrtNamedTuple)request_14)["Term"]);
            TMP_tmp1_30 = (PrtBool)((TMP_tmp0_43) > (CurrentTerm));
            if (TMP_tmp1_30)
            {
                TMP_tmp2_28 = (PrtInt)(((PrtNamedTuple)request_14)["Term"]);
                CurrentTerm = TMP_tmp2_28;
                TMP_tmp3_24 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_24;
                RedirectLastClientRequestToClusterManager();
                TMP_tmp4_19 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_14)?.Clone()));
                Vote(TMP_tmp4_19);
                TMP_tmp5_13 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp5_13);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp6_13 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_14)?.Clone()));
                Vote(TMP_tmp6_13);
            }
        }
        public void RespondVoteAsLeader(PrtNamedTuple request_15)
        {
            Server currentMachine = this;
            PrtInt TMP_tmp0_44 = ((PrtInt)0);
            PrtBool TMP_tmp1_31 = ((PrtBool)false);
            PrtInt TMP_tmp2_29 = ((PrtInt)0);
            PMachineValue TMP_tmp3_25 = null;
            PEvent TMP_tmp4_20 = null;
            TMP_tmp0_44 = (PrtInt)(((PrtNamedTuple)request_15)["Term"]);
            TMP_tmp1_31 = (PrtBool)((TMP_tmp0_44) > (CurrentTerm));
            if (TMP_tmp1_31)
            {
                TMP_tmp2_29 = (PrtInt)(((PrtNamedTuple)request_15)["Term"]);
                CurrentTerm = TMP_tmp2_29;
                TMP_tmp3_25 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_25;
                RedirectLastClientRequestToClusterManager();
                TMP_tmp4_20 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp4_20);
                throw new PUnreachableCodeException();
            }
        }
        public void AppendEntriesAsLeader(PrtNamedTuple request_16)
        {
            Server currentMachine = this;
            PrtInt TMP_tmp0_45 = ((PrtInt)0);
            PrtBool TMP_tmp1_32 = ((PrtBool)false);
            PrtInt TMP_tmp2_30 = ((PrtInt)0);
            PMachineValue TMP_tmp3_26 = null;
            PrtNamedTuple TMP_tmp4_21 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            PEvent TMP_tmp5_14 = null;
            TMP_tmp0_45 = (PrtInt)(((PrtNamedTuple)request_16)["Term"]);
            TMP_tmp1_32 = (PrtBool)((TMP_tmp0_45) > (CurrentTerm));
            if (TMP_tmp1_32)
            {
                TMP_tmp2_30 = (PrtInt)(((PrtNamedTuple)request_16)["Term"]);
                CurrentTerm = TMP_tmp2_30;
                TMP_tmp3_26 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_26;
                RedirectLastClientRequestToClusterManager();
                TMP_tmp4_21 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)request_16)?.Clone()));
                AppendEntries(TMP_tmp4_21);
                TMP_tmp5_14 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp5_14);
                throw new PUnreachableCodeException();
            }
        }
        public void RespondAppendEntriesAsLeader(PrtNamedTuple request_17)
        {
            Server currentMachine = this;
            PrtInt commitIndex = ((PrtInt)0);
            PrtSeq logsAppend_1 = new PrtSeq();
            PrtInt prevLogIndex_1 = ((PrtInt)0);
            PrtInt prevLogTerm_1 = ((PrtInt)0);
            PrtInt idx_6 = ((PrtInt)0);
            PrtInt TMP_tmp0_46 = ((PrtInt)0);
            PrtBool TMP_tmp1_33 = ((PrtBool)false);
            PrtInt TMP_tmp2_31 = ((PrtInt)0);
            PMachineValue TMP_tmp3_27 = null;
            PEvent TMP_tmp4_22 = null;
            PrtInt TMP_tmp5_15 = ((PrtInt)0);
            PrtBool TMP_tmp6_14 = ((PrtBool)false);
            PrtBool TMP_tmp7_9 = ((PrtBool)false);
            PMachineValue TMP_tmp8_6 = null;
            PrtInt TMP_tmp9_6 = ((PrtInt)0);
            PrtInt TMP_tmp10_6 = ((PrtInt)0);
            PMachineValue TMP_tmp11_6 = null;
            PrtInt TMP_tmp12_5 = ((PrtInt)0);
            PrtInt TMP_tmp13_5 = ((PrtInt)0);
            PMachineValue TMP_tmp14_3 = null;
            PrtBool TMP_tmp15_3 = ((PrtBool)false);
            PrtInt TMP_tmp16_3 = ((PrtInt)0);
            PrtInt TMP_tmp17_3 = ((PrtInt)0);
            PrtInt TMP_tmp18_2 = ((PrtInt)0);
            PrtBool TMP_tmp19_2 = ((PrtBool)false);
            PrtBool TMP_tmp20_2 = ((PrtBool)false);
            PMachineValue TMP_tmp21_2 = null;
            PrtInt TMP_tmp22_2 = ((PrtInt)0);
            PrtBool TMP_tmp23_2 = ((PrtBool)false);
            PrtInt TMP_tmp24_2 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp25_2 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp26_2 = ((PrtInt)0);
            PrtBool TMP_tmp27_2 = ((PrtBool)false);
            PrtBool TMP_tmp28_2 = ((PrtBool)false);
            PMachineValue TMP_tmp29_2 = null;
            PrtInt TMP_tmp30_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp31_1 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            PMachineValue TMP_tmp32_1 = null;
            PMachineValue TMP_tmp33_1 = null;
            PEvent TMP_tmp34_1 = null;
            PMachineValue TMP_tmp35 = null;
            PrtInt TMP_tmp36 = ((PrtInt)0);
            PrtBool TMP_tmp37 = ((PrtBool)false);
            PMachineValue TMP_tmp38 = null;
            PMachineValue TMP_tmp39 = null;
            PrtInt TMP_tmp40 = ((PrtInt)0);
            PrtInt TMP_tmp41 = ((PrtInt)0);
            PrtSeq TMP_tmp42 = new PrtSeq();
            PMachineValue TMP_tmp43 = null;
            PrtInt TMP_tmp44 = ((PrtInt)0);
            PrtInt TMP_tmp45 = ((PrtInt)0);
            PrtInt TMP_tmp46 = ((PrtInt)0);
            PrtBool TMP_tmp47 = ((PrtBool)false);
            PrtBool TMP_tmp48 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp49 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp50 = ((PrtInt)0);
            PMachineValue TMP_tmp51 = null;
            PrtInt TMP_tmp52 = ((PrtInt)0);
            PrtInt TMP_tmp53 = ((PrtInt)0);
            PrtInt TMP_tmp54 = ((PrtInt)0);
            PrtInt TMP_tmp55 = ((PrtInt)0);
            PMachineValue TMP_tmp56 = null;
            PMachineValue TMP_tmp57 = null;
            PEvent TMP_tmp58 = null;
            PrtInt TMP_tmp59 = ((PrtInt)0);
            PMachineValue TMP_tmp60 = null;
            PrtInt TMP_tmp61 = ((PrtInt)0);
            PrtInt TMP_tmp62 = ((PrtInt)0);
            PrtSeq TMP_tmp63 = new PrtSeq();
            PrtInt TMP_tmp64 = ((PrtInt)0);
            PMachineValue TMP_tmp65 = null;
            PrtNamedTuple TMP_tmp66 = (new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null));
            TMP_tmp0_46 = (PrtInt)(((PrtNamedTuple)request_17)["Term"]);
            TMP_tmp1_33 = (PrtBool)((TMP_tmp0_46) > (CurrentTerm));
            if (TMP_tmp1_33)
            {
                TMP_tmp2_31 = (PrtInt)(((PrtNamedTuple)request_17)["Term"]);
                CurrentTerm = TMP_tmp2_31;
                TMP_tmp3_27 = (PMachineValue)(null);
                VotedFor = TMP_tmp3_27;
                RedirectLastClientRequestToClusterManager();
                TMP_tmp4_22 = (PEvent)(new BecomeFollower(null));
                currentMachine.RaiseEvent((Event)TMP_tmp4_22);
                throw new PUnreachableCodeException();
            }
            else
            {
                TMP_tmp5_15 = (PrtInt)(((PrtNamedTuple)request_17)["Term"]);
                TMP_tmp6_14 = (PrtBool)((!PrtValues.SafeEquals(TMP_tmp5_15,CurrentTerm)));
                if (TMP_tmp6_14)
                {
                }
                else
                {
                    TMP_tmp7_9 = (PrtBool)(((PrtNamedTuple)request_17)["Success"]);
                    if (TMP_tmp7_9)
                    {
                        TMP_tmp8_6 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp9_6 = (PrtInt)(((PrtInt)(Logs).Count));
                        TMP_tmp10_6 = (PrtInt)((TMP_tmp9_6) + (((PrtInt)1)));
                        ((PrtMap)NextIndex)[TMP_tmp8_6] = TMP_tmp10_6;
                        TMP_tmp11_6 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp12_5 = (PrtInt)(((PrtInt)(Logs).Count));
                        ((PrtMap)MatchIndex)[TMP_tmp11_6] = TMP_tmp12_5;
                        TMP_tmp13_5 = (PrtInt)((VotesReceived) + (((PrtInt)1)));
                        VotesReceived = TMP_tmp13_5;
                        TMP_tmp14_3 = (PMachineValue)(((PrtNamedTuple)request_17)["ReceiverEndpoint"]);
                        TMP_tmp15_3 = (PrtBool)((!PrtValues.SafeEquals(TMP_tmp14_3,null)));
                        TMP_tmp20_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp15_3)?.Clone()));
                        if (TMP_tmp20_2)
                        {
                            TMP_tmp16_3 = (PrtInt)(((PrtInt)(Servers_1).Count));
                            TMP_tmp17_3 = (PrtInt)((TMP_tmp16_3) / (((PrtInt)2)));
                            TMP_tmp18_2 = (PrtInt)((TMP_tmp17_3) + (((PrtInt)1)));
                            TMP_tmp19_2 = (PrtBool)((VotesReceived) >= (TMP_tmp18_2));
                            TMP_tmp20_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp19_2)?.Clone()));
                        }
                        if (TMP_tmp20_2)
                        {
                            TMP_tmp21_2 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                            TMP_tmp22_2 = (PrtInt)(((PrtMap)MatchIndex)[TMP_tmp21_2]);
                            commitIndex = TMP_tmp22_2;
                            TMP_tmp23_2 = (PrtBool)((commitIndex) > (CommitIndex));
                            TMP_tmp28_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp23_2)?.Clone()));
                            if (TMP_tmp28_2)
                            {
                                TMP_tmp24_2 = (PrtInt)((commitIndex) - (((PrtInt)1)));
                                TMP_tmp25_2 = (PrtNamedTuple)(((PrtSeq)Logs)[TMP_tmp24_2]);
                                TMP_tmp26_2 = (PrtInt)(((PrtNamedTuple)TMP_tmp25_2)["Term"]);
                                TMP_tmp27_2 = (PrtBool)((PrtValues.SafeEquals(TMP_tmp26_2,CurrentTerm)));
                                TMP_tmp28_2 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp27_2)?.Clone()));
                            }
                            if (TMP_tmp28_2)
                            {
                                CommitIndex = (PrtInt)(((PrtInt)((IPrtValue)commitIndex)?.Clone()));
                            }
                            VotesReceived = (PrtInt)(((PrtInt)0));
                            TMP_tmp29_2 = (PMachineValue)(null);
                            TMP_tmp30_1 = (PrtInt)(((PrtInt)0));
                            TMP_tmp31_1 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Client","Command"}, TMP_tmp29_2, TMP_tmp30_1)));
                            LastClientRequest = TMP_tmp31_1;
                            TMP_tmp32_1 = (PMachineValue)(((PrtNamedTuple)request_17)["ReceiverEndpoint"]);
                            TMP_tmp33_1 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp32_1)?.Clone()));
                            TMP_tmp34_1 = (PEvent)(new Response(null));
                            currentMachine.SendEvent(TMP_tmp33_1, (Event)TMP_tmp34_1);
                        }
                    }
                    else
                    {
                        TMP_tmp35 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp36 = (PrtInt)(((PrtMap)NextIndex)[TMP_tmp35]);
                        TMP_tmp37 = (PrtBool)((TMP_tmp36) > (((PrtInt)1)));
                        if (TMP_tmp37)
                        {
                            TMP_tmp38 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                            TMP_tmp39 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                            TMP_tmp40 = (PrtInt)(((PrtMap)NextIndex)[TMP_tmp39]);
                            TMP_tmp41 = (PrtInt)((TMP_tmp40) - (((PrtInt)1)));
                            ((PrtMap)NextIndex)[TMP_tmp38] = TMP_tmp41;
                        }
                        TMP_tmp42 = (PrtSeq)(new PrtSeq());
                        logsAppend_1 = TMP_tmp42;
                        TMP_tmp43 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp44 = (PrtInt)(((PrtMap)NextIndex)[TMP_tmp43]);
                        TMP_tmp45 = (PrtInt)((TMP_tmp44) - (((PrtInt)1)));
                        idx_6 = TMP_tmp45;
                        while (((PrtBool)true))
                        {
                            TMP_tmp46 = (PrtInt)(((PrtInt)(Logs).Count));
                            TMP_tmp47 = (PrtBool)((idx_6) < (TMP_tmp46));
                            TMP_tmp48 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp47)?.Clone()));
                            if (TMP_tmp48)
                            {
                            }
                            else
                            {
                                break;
                            }
                            TMP_tmp49 = (PrtNamedTuple)(((PrtSeq)Logs)[idx_6]);
                            ((PrtSeq)logsAppend_1).Insert(idx_6, TMP_tmp49);
                            TMP_tmp50 = (PrtInt)((idx_6) + (((PrtInt)1)));
                            idx_6 = TMP_tmp50;
                        }
                        TMP_tmp51 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp52 = (PrtInt)(((PrtMap)NextIndex)[TMP_tmp51]);
                        TMP_tmp53 = (PrtInt)((TMP_tmp52) - (((PrtInt)1)));
                        prevLogIndex_1 = TMP_tmp53;
                        TMP_tmp54 = (PrtInt)(((PrtInt)((IPrtValue)prevLogIndex_1)?.Clone()));
                        TMP_tmp55 = (PrtInt)(GetLogTermForIndex(TMP_tmp54));
                        prevLogTerm_1 = TMP_tmp55;
                        TMP_tmp56 = (PMachineValue)(((PrtNamedTuple)request_17)["Server"]);
                        TMP_tmp57 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp56)?.Clone()));
                        TMP_tmp58 = (PEvent)(new AppendEntriesRequest((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"},((PrtInt)0), null, ((PrtInt)0), ((PrtInt)0), new PrtSeq(), ((PrtInt)0), null))));
                        TMP_tmp59 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                        TMP_tmp60 = (PMachineValue)(currentMachine.self);
                        TMP_tmp61 = (PrtInt)(((PrtInt)((IPrtValue)prevLogIndex_1)?.Clone()));
                        TMP_tmp62 = (PrtInt)(((PrtInt)((IPrtValue)prevLogTerm_1)?.Clone()));
                        TMP_tmp63 = (PrtSeq)(((PrtSeq)((IPrtValue)Logs)?.Clone()));
                        TMP_tmp64 = (PrtInt)(((PrtInt)((IPrtValue)CommitIndex)?.Clone()));
                        TMP_tmp65 = (PMachineValue)(((PrtNamedTuple)request_17)["ReceiverEndpoint"]);
                        TMP_tmp66 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","LeaderId","PrevLogIndex","PrevLogTerm","Entries","LeaderCommit","ReceiverEndpoint"}, TMP_tmp59, TMP_tmp60, TMP_tmp61, TMP_tmp62, TMP_tmp63, TMP_tmp64, TMP_tmp65)));
                        currentMachine.SendEvent(TMP_tmp57, (Event)TMP_tmp58, TMP_tmp66);
                    }
                }
            }
        }
        public void Vote(PrtNamedTuple request_18)
        {
            Server currentMachine = this;
            PrtInt lastLogIndex_2 = ((PrtInt)0);
            PrtInt lastLogTerm_1 = ((PrtInt)0);
            PrtInt TMP_tmp0_47 = ((PrtInt)0);
            PrtInt TMP_tmp1_34 = ((PrtInt)0);
            PrtInt TMP_tmp2_32 = ((PrtInt)0);
            PrtInt TMP_tmp3_28 = ((PrtInt)0);
            PrtBool TMP_tmp4_23 = ((PrtBool)false);
            PrtBool TMP_tmp5_16 = ((PrtBool)false);
            PMachineValue TMP_tmp6_15 = null;
            PrtBool TMP_tmp7_10 = ((PrtBool)false);
            PrtBool TMP_tmp8_7 = ((PrtBool)false);
            PrtBool TMP_tmp9_7 = ((PrtBool)false);
            PrtInt TMP_tmp10_7 = ((PrtInt)0);
            PrtBool TMP_tmp11_7 = ((PrtBool)false);
            PrtBool TMP_tmp12_6 = ((PrtBool)false);
            PrtInt TMP_tmp13_6 = ((PrtInt)0);
            PrtBool TMP_tmp14_4 = ((PrtBool)false);
            PrtBool TMP_tmp15_4 = ((PrtBool)false);
            PMachineValue TMP_tmp16_4 = null;
            PMachineValue TMP_tmp17_4 = null;
            PEvent TMP_tmp18_3 = null;
            PrtInt TMP_tmp19_3 = ((PrtInt)0);
            PrtBool TMP_tmp20_3 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp21_3 = (new PrtNamedTuple(new string[]{"Term","VoteGranted"},((PrtInt)0), ((PrtBool)false)));
            PMachineValue TMP_tmp22_3 = null;
            PMachineValue TMP_tmp23_3 = null;
            PMachineValue TMP_tmp24_3 = null;
            PMachineValue TMP_tmp25_3 = null;
            PEvent TMP_tmp26_3 = null;
            PrtInt TMP_tmp27_3 = ((PrtInt)0);
            PrtBool TMP_tmp28_3 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp29_3 = (new PrtNamedTuple(new string[]{"Term","VoteGranted"},((PrtInt)0), ((PrtBool)false)));
            TMP_tmp0_47 = (PrtInt)(((PrtInt)(Logs).Count));
            lastLogIndex_2 = TMP_tmp0_47;
            TMP_tmp1_34 = (PrtInt)(((PrtInt)((IPrtValue)lastLogIndex_2)?.Clone()));
            TMP_tmp2_32 = (PrtInt)(GetLogTermForIndex(TMP_tmp1_34));
            lastLogTerm_1 = TMP_tmp2_32;
            TMP_tmp3_28 = (PrtInt)(((PrtNamedTuple)request_18)["Term"]);
            TMP_tmp4_23 = (PrtBool)((TMP_tmp3_28) < (CurrentTerm));
            TMP_tmp9_7 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp4_23)?.Clone()));
            if (TMP_tmp9_7)
            {
            }
            else
            {
                TMP_tmp5_16 = (PrtBool)((!PrtValues.SafeEquals(VotedFor,null)));
                TMP_tmp8_7 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp5_16)?.Clone()));
                if (TMP_tmp8_7)
                {
                    TMP_tmp6_15 = (PMachineValue)(((PrtNamedTuple)request_18)["CandidateId"]);
                    TMP_tmp7_10 = (PrtBool)((!PrtValues.SafeEquals(VotedFor,TMP_tmp6_15)));
                    TMP_tmp8_7 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp7_10)?.Clone()));
                }
                TMP_tmp9_7 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp8_7)?.Clone()));
            }
            TMP_tmp12_6 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp9_7)?.Clone()));
            if (TMP_tmp12_6)
            {
            }
            else
            {
                TMP_tmp10_7 = (PrtInt)(((PrtNamedTuple)request_18)["LastLogIndex"]);
                TMP_tmp11_7 = (PrtBool)((lastLogIndex_2) > (TMP_tmp10_7));
                TMP_tmp12_6 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp11_7)?.Clone()));
            }
            TMP_tmp15_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp12_6)?.Clone()));
            if (TMP_tmp15_4)
            {
            }
            else
            {
                TMP_tmp13_6 = (PrtInt)(((PrtNamedTuple)request_18)["LastLogTerm"]);
                TMP_tmp14_4 = (PrtBool)((lastLogTerm_1) > (TMP_tmp13_6));
                TMP_tmp15_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp14_4)?.Clone()));
            }
            if (TMP_tmp15_4)
            {
                TMP_tmp16_4 = (PMachineValue)(((PrtNamedTuple)request_18)["CandidateId"]);
                TMP_tmp17_4 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp16_4)?.Clone()));
                TMP_tmp18_3 = (PEvent)(new VoteResponse((new PrtNamedTuple(new string[]{"Term","VoteGranted"},((PrtInt)0), ((PrtBool)false)))));
                TMP_tmp19_3 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp20_3 = (PrtBool)(((PrtBool)false));
                TMP_tmp21_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","VoteGranted"}, TMP_tmp19_3, TMP_tmp20_3)));
                currentMachine.SendEvent(TMP_tmp17_4, (Event)TMP_tmp18_3, TMP_tmp21_3);
            }
            else
            {
                TMP_tmp22_3 = (PMachineValue)(((PrtNamedTuple)request_18)["CandidateId"]);
                VotedFor = TMP_tmp22_3;
                TMP_tmp23_3 = (PMachineValue)(null);
                LeaderId = TMP_tmp23_3;
                TMP_tmp24_3 = (PMachineValue)(((PrtNamedTuple)request_18)["CandidateId"]);
                TMP_tmp25_3 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp24_3)?.Clone()));
                TMP_tmp26_3 = (PEvent)(new VoteResponse((new PrtNamedTuple(new string[]{"Term","VoteGranted"},((PrtInt)0), ((PrtBool)false)))));
                TMP_tmp27_3 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp28_3 = (PrtBool)(((PrtBool)true));
                TMP_tmp29_3 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","VoteGranted"}, TMP_tmp27_3, TMP_tmp28_3)));
                currentMachine.SendEvent(TMP_tmp25_3, (Event)TMP_tmp26_3, TMP_tmp29_3);
            }
        }
        public void AppendEntries(PrtNamedTuple request_19)
        {
            Server currentMachine = this;
            PrtInt currentIndex = ((PrtInt)0);
            PrtInt idx_7 = ((PrtInt)0);
            PrtInt decIdx = ((PrtInt)0);
            PrtNamedTuple logEntry = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp0_48 = ((PrtInt)0);
            PrtBool TMP_tmp1_35 = ((PrtBool)false);
            PMachineValue TMP_tmp2_33 = null;
            PMachineValue TMP_tmp3_29 = null;
            PEvent TMP_tmp4_24 = null;
            PrtInt TMP_tmp5_17 = ((PrtInt)0);
            PrtBool TMP_tmp6_16 = ((PrtBool)false);
            PMachineValue TMP_tmp7_11 = null;
            PMachineValue TMP_tmp8_8 = null;
            PrtNamedTuple TMP_tmp9_8 = (new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null));
            PrtInt TMP_tmp10_8 = ((PrtInt)0);
            PrtBool TMP_tmp11_8 = ((PrtBool)false);
            PrtInt TMP_tmp12_7 = ((PrtInt)0);
            PrtInt TMP_tmp13_7 = ((PrtInt)0);
            PrtBool TMP_tmp14_5 = ((PrtBool)false);
            PrtInt TMP_tmp15_5 = ((PrtInt)0);
            PrtInt TMP_tmp16_5 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp17_5 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp18_4 = ((PrtInt)0);
            PrtInt TMP_tmp19_4 = ((PrtInt)0);
            PrtBool TMP_tmp20_4 = ((PrtBool)false);
            PrtBool TMP_tmp21_4 = ((PrtBool)false);
            PrtBool TMP_tmp22_4 = ((PrtBool)false);
            PMachineValue TMP_tmp23_4 = null;
            PMachineValue TMP_tmp24_4 = null;
            PEvent TMP_tmp25_4 = null;
            PrtInt TMP_tmp26_4 = ((PrtInt)0);
            PrtBool TMP_tmp27_4 = ((PrtBool)false);
            PMachineValue TMP_tmp28_4 = null;
            PMachineValue TMP_tmp29_4 = null;
            PrtNamedTuple TMP_tmp30_2 = (new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null));
            PrtSeq TMP_tmp31_2 = new PrtSeq();
            PrtInt TMP_tmp32_2 = ((PrtInt)0);
            PrtBool TMP_tmp33_2 = ((PrtBool)false);
            PrtInt TMP_tmp34_2 = ((PrtInt)0);
            PrtInt TMP_tmp35_1 = ((PrtInt)0);
            PrtSeq TMP_tmp36_1 = new PrtSeq();
            PrtInt TMP_tmp37_1 = ((PrtInt)0);
            PrtBool TMP_tmp38_1 = ((PrtBool)false);
            PrtBool TMP_tmp39_1 = ((PrtBool)false);
            PrtSeq TMP_tmp40_1 = new PrtSeq();
            PrtNamedTuple TMP_tmp41_1 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp42_1 = ((PrtInt)0);
            PrtBool TMP_tmp43_1 = ((PrtBool)false);
            PrtNamedTuple TMP_tmp44_1 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp45_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp46_1 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp47_1 = ((PrtInt)0);
            PrtInt TMP_tmp48_1 = ((PrtInt)0);
            PrtBool TMP_tmp49_1 = ((PrtBool)false);
            PrtInt TMP_tmp50_1 = ((PrtInt)0);
            PrtInt TMP_tmp51_1 = ((PrtInt)0);
            PrtInt TMP_tmp52_1 = ((PrtInt)0);
            PrtBool TMP_tmp53_1 = ((PrtBool)false);
            PrtBool TMP_tmp54_1 = ((PrtBool)false);
            PrtInt TMP_tmp55_1 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp56_1 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp57_1 = ((PrtInt)0);
            PrtInt TMP_tmp58_1 = ((PrtInt)0);
            PrtInt TMP_tmp59_1 = ((PrtInt)0);
            PrtBool TMP_tmp60_1 = ((PrtBool)false);
            PrtInt TMP_tmp61_1 = ((PrtInt)0);
            PrtInt TMP_tmp62_1 = ((PrtInt)0);
            PrtBool TMP_tmp63_1 = ((PrtBool)false);
            PrtBool TMP_tmp64_1 = ((PrtBool)false);
            PrtInt TMP_tmp65_1 = ((PrtInt)0);
            PrtInt TMP_tmp66_1 = ((PrtInt)0);
            PrtBool TMP_tmp67 = ((PrtBool)false);
            PrtInt TMP_tmp68 = ((PrtInt)0);
            PrtBool TMP_tmp69 = ((PrtBool)false);
            PrtInt TMP_tmp70 = ((PrtInt)0);
            PMachineValue TMP_tmp71 = null;
            PMachineValue TMP_tmp72 = null;
            PMachineValue TMP_tmp73 = null;
            PEvent TMP_tmp74 = null;
            PrtInt TMP_tmp75 = ((PrtInt)0);
            PrtBool TMP_tmp76 = ((PrtBool)false);
            PMachineValue TMP_tmp77 = null;
            PMachineValue TMP_tmp78 = null;
            PrtNamedTuple TMP_tmp79 = (new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null));
            TMP_tmp0_48 = (PrtInt)(((PrtNamedTuple)request_19)["Term"]);
            TMP_tmp1_35 = (PrtBool)((TMP_tmp0_48) < (CurrentTerm));
            if (TMP_tmp1_35)
            {
                TMP_tmp2_33 = (PMachineValue)(((PrtNamedTuple)request_19)["LeaderId"]);
                TMP_tmp3_29 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp2_33)?.Clone()));
                TMP_tmp4_24 = (PEvent)(new AppendEntriesResponse((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null))));
                TMP_tmp5_17 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                TMP_tmp6_16 = (PrtBool)(((PrtBool)false));
                TMP_tmp7_11 = (PMachineValue)(currentMachine.self);
                TMP_tmp8_8 = (PMachineValue)(((PrtNamedTuple)request_19)["ReceiverEndpoint"]);
                TMP_tmp9_8 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"}, TMP_tmp5_17, TMP_tmp6_16, TMP_tmp7_11, TMP_tmp8_8)));
                currentMachine.SendEvent(TMP_tmp3_29, (Event)TMP_tmp4_24, TMP_tmp9_8);
            }
            else
            {
                TMP_tmp10_8 = (PrtInt)(((PrtNamedTuple)request_19)["PrevLogIndex"]);
                TMP_tmp11_8 = (PrtBool)((TMP_tmp10_8) > (((PrtInt)0)));
                TMP_tmp22_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp11_8)?.Clone()));
                if (TMP_tmp22_4)
                {
                    TMP_tmp12_7 = (PrtInt)(((PrtInt)(Logs).Count));
                    TMP_tmp13_7 = (PrtInt)(((PrtNamedTuple)request_19)["PrevLogIndex"]);
                    TMP_tmp14_5 = (PrtBool)((TMP_tmp12_7) < (TMP_tmp13_7));
                    TMP_tmp21_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp14_5)?.Clone()));
                    if (TMP_tmp21_4)
                    {
                    }
                    else
                    {
                        TMP_tmp15_5 = (PrtInt)(((PrtNamedTuple)request_19)["PrevLogIndex"]);
                        TMP_tmp16_5 = (PrtInt)((TMP_tmp15_5) - (((PrtInt)1)));
                        TMP_tmp17_5 = (PrtNamedTuple)(((PrtSeq)Logs)[TMP_tmp16_5]);
                        TMP_tmp18_4 = (PrtInt)(((PrtNamedTuple)TMP_tmp17_5)["Term"]);
                        TMP_tmp19_4 = (PrtInt)(((PrtNamedTuple)request_19)["PrevLogTerm"]);
                        TMP_tmp20_4 = (PrtBool)((!PrtValues.SafeEquals(TMP_tmp18_4,TMP_tmp19_4)));
                        TMP_tmp21_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp20_4)?.Clone()));
                    }
                    TMP_tmp22_4 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp21_4)?.Clone()));
                }
                if (TMP_tmp22_4)
                {
                    TMP_tmp23_4 = (PMachineValue)(((PrtNamedTuple)request_19)["LeaderId"]);
                    TMP_tmp24_4 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp23_4)?.Clone()));
                    TMP_tmp25_4 = (PEvent)(new AppendEntriesResponse((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null))));
                    TMP_tmp26_4 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                    TMP_tmp27_4 = (PrtBool)(((PrtBool)false));
                    TMP_tmp28_4 = (PMachineValue)(currentMachine.self);
                    TMP_tmp29_4 = (PMachineValue)(((PrtNamedTuple)request_19)["ReceiverEndpoint"]);
                    TMP_tmp30_2 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"}, TMP_tmp26_4, TMP_tmp27_4, TMP_tmp28_4, TMP_tmp29_4)));
                    currentMachine.SendEvent(TMP_tmp24_4, (Event)TMP_tmp25_4, TMP_tmp30_2);
                }
                else
                {
                    TMP_tmp31_2 = (PrtSeq)(((PrtNamedTuple)request_19)["Entries"]);
                    TMP_tmp32_2 = (PrtInt)(((PrtInt)(TMP_tmp31_2).Count));
                    TMP_tmp33_2 = (PrtBool)((TMP_tmp32_2) > (((PrtInt)0)));
                    if (TMP_tmp33_2)
                    {
                        TMP_tmp34_2 = (PrtInt)(((PrtNamedTuple)request_19)["PrevLogIndex"]);
                        TMP_tmp35_1 = (PrtInt)((TMP_tmp34_2) + (((PrtInt)1)));
                        currentIndex = TMP_tmp35_1;
                        idx_7 = (PrtInt)(((PrtInt)0));
                        while (((PrtBool)true))
                        {
                            TMP_tmp36_1 = (PrtSeq)(((PrtNamedTuple)request_19)["Entries"]);
                            TMP_tmp37_1 = (PrtInt)(((PrtInt)(TMP_tmp36_1).Count));
                            TMP_tmp38_1 = (PrtBool)((idx_7) < (TMP_tmp37_1));
                            TMP_tmp39_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp38_1)?.Clone()));
                            if (TMP_tmp39_1)
                            {
                            }
                            else
                            {
                                break;
                            }
                            TMP_tmp40_1 = (PrtSeq)(((PrtNamedTuple)request_19)["Entries"]);
                            TMP_tmp41_1 = (PrtNamedTuple)(((PrtSeq)TMP_tmp40_1)[idx_7]);
                            logEntry = TMP_tmp41_1;
                            TMP_tmp42_1 = (PrtInt)(((PrtInt)(Logs).Count));
                            TMP_tmp43_1 = (PrtBool)((TMP_tmp42_1) < (currentIndex));
                            if (TMP_tmp43_1)
                            {
                                TMP_tmp44_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)logEntry)?.Clone()));
                                ((PrtSeq)Logs).Insert(idx_7, TMP_tmp44_1);
                            }
                            else
                            {
                                TMP_tmp45_1 = (PrtInt)((currentIndex) - (((PrtInt)1)));
                                TMP_tmp46_1 = (PrtNamedTuple)(((PrtSeq)Logs)[TMP_tmp45_1]);
                                TMP_tmp47_1 = (PrtInt)(((PrtNamedTuple)TMP_tmp46_1)["Term"]);
                                TMP_tmp48_1 = (PrtInt)(((PrtNamedTuple)logEntry)["Term"]);
                                TMP_tmp49_1 = (PrtBool)((!PrtValues.SafeEquals(TMP_tmp47_1,TMP_tmp48_1)));
                                if (TMP_tmp49_1)
                                {
                                    TMP_tmp50_1 = (PrtInt)(((PrtInt)(Logs).Count));
                                    TMP_tmp51_1 = (PrtInt)((TMP_tmp50_1) - (((PrtInt)1)));
                                    decIdx = TMP_tmp51_1;
                                    while (((PrtBool)true))
                                    {
                                        TMP_tmp52_1 = (PrtInt)((currentIndex) - (((PrtInt)1)));
                                        TMP_tmp53_1 = (PrtBool)((decIdx) >= (TMP_tmp52_1));
                                        TMP_tmp54_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp53_1)?.Clone()));
                                        if (TMP_tmp54_1)
                                        {
                                        }
                                        else
                                        {
                                            break;
                                        }
                                        ((PrtSeq)Logs).RemoveAt(decIdx);
                                        TMP_tmp55_1 = (PrtInt)((decIdx) - (((PrtInt)1)));
                                        decIdx = TMP_tmp55_1;
                                    }
                                    TMP_tmp56_1 = (PrtNamedTuple)(((PrtNamedTuple)((IPrtValue)logEntry)?.Clone()));
                                    ((PrtSeq)Logs).Insert(decIdx, TMP_tmp56_1);
                                }
                            }
                            TMP_tmp57_1 = (PrtInt)((idx_7) + (((PrtInt)1)));
                            idx_7 = TMP_tmp57_1;
                            TMP_tmp58_1 = (PrtInt)((currentIndex) + (((PrtInt)1)));
                            currentIndex = TMP_tmp58_1;
                        }
                    }
                    TMP_tmp59_1 = (PrtInt)(((PrtNamedTuple)request_19)["LeaderCommit"]);
                    TMP_tmp60_1 = (PrtBool)((TMP_tmp59_1) > (CommitIndex));
                    TMP_tmp64_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp60_1)?.Clone()));
                    if (TMP_tmp64_1)
                    {
                        TMP_tmp61_1 = (PrtInt)(((PrtInt)(Logs).Count));
                        TMP_tmp62_1 = (PrtInt)(((PrtNamedTuple)request_19)["LeaderCommit"]);
                        TMP_tmp63_1 = (PrtBool)((TMP_tmp61_1) < (TMP_tmp62_1));
                        TMP_tmp64_1 = (PrtBool)(((PrtBool)((IPrtValue)TMP_tmp63_1)?.Clone()));
                    }
                    if (TMP_tmp64_1)
                    {
                        TMP_tmp65_1 = (PrtInt)(((PrtInt)(Logs).Count));
                        CommitIndex = TMP_tmp65_1;
                    }
                    else
                    {
                        TMP_tmp66_1 = (PrtInt)(((PrtNamedTuple)request_19)["LeaderCommit"]);
                        TMP_tmp67 = (PrtBool)((TMP_tmp66_1) > (CommitIndex));
                        if (TMP_tmp67)
                        {
                            TMP_tmp68 = (PrtInt)(((PrtNamedTuple)request_19)["LeaderCommit"]);
                            CommitIndex = TMP_tmp68;
                        }
                    }
                    TMP_tmp69 = (PrtBool)((CommitIndex) > (LastApplied));
                    if (TMP_tmp69)
                    {
                        TMP_tmp70 = (PrtInt)((LastApplied) + (((PrtInt)1)));
                        LastApplied = TMP_tmp70;
                    }
                    TMP_tmp71 = (PMachineValue)(((PrtNamedTuple)request_19)["LeaderId"]);
                    LeaderId = TMP_tmp71;
                    TMP_tmp72 = (PMachineValue)(((PrtNamedTuple)request_19)["LeaderId"]);
                    TMP_tmp73 = (PMachineValue)(((PMachineValue)((IPrtValue)TMP_tmp72)?.Clone()));
                    TMP_tmp74 = (PEvent)(new AppendEntriesResponse((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"},((PrtInt)0), ((PrtBool)false), null, null))));
                    TMP_tmp75 = (PrtInt)(((PrtInt)((IPrtValue)CurrentTerm)?.Clone()));
                    TMP_tmp76 = (PrtBool)(((PrtBool)true));
                    TMP_tmp77 = (PMachineValue)(currentMachine.self);
                    TMP_tmp78 = (PMachineValue)(((PrtNamedTuple)request_19)["ReceiverEndpoint"]);
                    TMP_tmp79 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Term","Success","Server","ReceiverEndpoint"}, TMP_tmp75, TMP_tmp76, TMP_tmp77, TMP_tmp78)));
                    currentMachine.SendEvent(TMP_tmp73, (Event)TMP_tmp74, TMP_tmp79);
                }
            }
        }
        public void RedirectLastClientRequestToClusterManager()
        {
            Server currentMachine = this;
            PrtBool TMP_tmp0_49 = ((PrtBool)false);
            PMachineValue TMP_tmp1_36 = null;
            PEvent TMP_tmp2_34 = null;
            PMachineValue TMP_tmp3_30 = null;
            PrtInt TMP_tmp4_25 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp5_18 = (new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)));
            TMP_tmp0_49 = (PrtBool)((!PrtValues.SafeEquals(LastClientRequest,null)));
            if (TMP_tmp0_49)
            {
                TMP_tmp1_36 = (PMachineValue)(((PMachineValue)((IPrtValue)ClusterManager_1)?.Clone()));
                TMP_tmp2_34 = (PEvent)(new Request((new PrtNamedTuple(new string[]{"Client","Command"},null, ((PrtInt)0)))));
                TMP_tmp3_30 = (PMachineValue)(((PrtNamedTuple)LastClientRequest)["Client"]);
                TMP_tmp4_25 = (PrtInt)(((PrtNamedTuple)LastClientRequest)["Command"]);
                TMP_tmp5_18 = (PrtNamedTuple)((new PrtNamedTuple(new string[]{"Client","Command"}, TMP_tmp3_30, TMP_tmp4_25)));
                currentMachine.SendEvent(TMP_tmp1_36, (Event)TMP_tmp2_34, TMP_tmp5_18);
            }
        }
        public PrtInt GetLogTermForIndex(PrtInt logIndex_1)
        {
            Server currentMachine = this;
            PrtInt logTerm_1 = ((PrtInt)0);
            PrtBool TMP_tmp0_50 = ((PrtBool)false);
            PrtInt TMP_tmp1_37 = ((PrtInt)0);
            PrtNamedTuple TMP_tmp2_35 = (new PrtNamedTuple(new string[]{"Term","Command"},((PrtInt)0), ((PrtInt)0)));
            PrtInt TMP_tmp3_31 = ((PrtInt)0);
            logTerm_1 = (PrtInt)(((PrtInt)0));
            TMP_tmp0_50 = (PrtBool)((logIndex_1) > (((PrtInt)0)));
            if (TMP_tmp0_50)
            {
                TMP_tmp1_37 = (PrtInt)((logIndex_1) - (((PrtInt)1)));
                TMP_tmp2_35 = (PrtNamedTuple)(((PrtSeq)Logs)[TMP_tmp1_37]);
                TMP_tmp3_31 = (PrtInt)(((PrtNamedTuple)TMP_tmp2_35)["Term"]);
                logTerm_1 = TMP_tmp3_31;
            }
            return ((PrtInt)((IPrtValue)logTerm_1)?.Clone());
        }
        public void ShuttingDown_1()
        {
            Server currentMachine = this;
            PMachineValue TMP_tmp0_51 = null;
            PEvent TMP_tmp1_38 = null;
            PMachineValue TMP_tmp2_36 = null;
            PEvent TMP_tmp3_32 = null;
            PEvent TMP_tmp4_26 = null;
            TMP_tmp0_51 = (PMachineValue)(((PMachineValue)((IPrtValue)ElectionTimer)?.Clone()));
            TMP_tmp1_38 = (PEvent)(new PHalt(null));
            currentMachine.SendEvent(TMP_tmp0_51, (Event)TMP_tmp1_38);
            TMP_tmp2_36 = (PMachineValue)(((PMachineValue)((IPrtValue)PeriodicTimer)?.Clone()));
            TMP_tmp3_32 = (PEvent)(new PHalt(null));
            currentMachine.SendEvent(TMP_tmp2_36, (Event)TMP_tmp3_32);
            TMP_tmp4_26 = (PEvent)(new PHalt(null));
            currentMachine.RaiseEvent((Event)TMP_tmp4_26);
            throw new PUnreachableCodeException();
        }
        [Start]
        [OnEntry(nameof(InitializeParametersFunction))]
        [OnEventGotoState(typeof(ConstructorEvent), typeof(Init_3))]
        class __InitState__ : MachineState { }
        
        [OnEntry(nameof(Anon_12))]
        [OnEventDoAction(typeof(SConfigureEvent), nameof(Anon_13))]
        [OnEventGotoState(typeof(BecomeFollower), typeof(Follower))]
        [DeferEvents(typeof(VoteRequest), typeof(AppendEntriesRequest))]
        class Init_3 : MachineState
        {
        }
        [OnEntry(nameof(Anon_14))]
        [OnEventDoAction(typeof(Request), nameof(Anon_15))]
        [OnEventDoAction(typeof(VoteRequest), nameof(Anon_16))]
        [OnEventDoAction(typeof(VoteResponse), nameof(Anon_17))]
        [OnEventDoAction(typeof(AppendEntriesRequest), nameof(Anon_18))]
        [OnEventDoAction(typeof(AppendEntriesResponse), nameof(Anon_19))]
        [OnEventDoAction(typeof(ETimeout), nameof(Anon_20))]
        [OnEventDoAction(typeof(ShutDown), nameof(Anon_21))]
        [OnEventGotoState(typeof(BecomeFollower), typeof(Follower))]
        [OnEventGotoState(typeof(BecomeCandidate), typeof(Candidate))]
        [IgnoreEvents(typeof(PTimeout))]
        class Follower : MachineState
        {
        }
        [OnEntry(nameof(Anon_22))]
        [OnEventDoAction(typeof(Request), nameof(Anon_23))]
        [OnEventDoAction(typeof(VoteRequest), nameof(Anon_24))]
        [OnEventDoAction(typeof(VoteResponse), nameof(Anon_25))]
        [OnEventDoAction(typeof(AppendEntriesRequest), nameof(Anon_26))]
        [OnEventDoAction(typeof(AppendEntriesResponse), nameof(Anon_27))]
        [OnEventDoAction(typeof(ETimeout), nameof(Anon_28))]
        [OnEventDoAction(typeof(PTimeout), nameof(BroadcastVoteRequests))]
        [OnEventDoAction(typeof(ShutDown), nameof(ShuttingDown_1))]
        [OnEventGotoState(typeof(BecomeLeader), typeof(Leader_1))]
        [OnEventGotoState(typeof(BecomeFollower), typeof(Follower))]
        [OnEventGotoState(typeof(BecomeCandidate), typeof(Candidate))]
        class Candidate : MachineState
        {
        }
        [OnEntry(nameof(Anon_29))]
        [OnEventDoAction(typeof(Request), nameof(Anon_30))]
        [OnEventDoAction(typeof(VoteRequest), nameof(Anon_31))]
        [OnEventDoAction(typeof(VoteResponse), nameof(Anon_32))]
        [OnEventDoAction(typeof(AppendEntriesRequest), nameof(Anon_33))]
        [OnEventDoAction(typeof(AppendEntriesResponse), nameof(Anon_34))]
        [OnEventDoAction(typeof(ShutDown), nameof(ShuttingDown_1))]
        [OnEventGotoState(typeof(BecomeFollower), typeof(Follower))]
        [IgnoreEvents(typeof(ETimeout), typeof(PTimeout))]
        class Leader_1 : MachineState
        {
        }
    }
    public class DefaultImpl {
        public static void InitializeLinkMap() {
            PModule.linkMap.Clear();
            PModule.linkMap[nameof(I_Client)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_ClusterManager)] = new Dictionary<string, string>();
            PModule.linkMap[nameof(I_Server)] = new Dictionary<string, string>();
        }
        
        public static void InitializeInterfaceDefMap() {
            PModule.interfaceDefinitionMap.Clear();
            PModule.interfaceDefinitionMap.Add(nameof(I_Client), typeof(Client));
            PModule.interfaceDefinitionMap.Add(nameof(I_ClusterManager), typeof(ClusterManager));
            PModule.interfaceDefinitionMap.Add(nameof(I_Server), typeof(Server));
        }
        
        public static void InitializeMonitorObserves() {
            PModule.monitorObserves.Clear();
        }
        
        public static void InitializeMonitorMap(IMachineRuntime runtime) {
            PModule.monitorMap.Clear();
        }
        
        
        [Microsoft.PSharp.Test]
        public static void Execute(IMachineRuntime runtime) {
            runtime.SetLogWriter(new PLogger());
            PModule.runtime = runtime;
            PHelper.InitializeInterfaces();
            PHelper.InitializeEnums();
            InitializeLinkMap();
            InitializeInterfaceDefMap();
            InitializeMonitorMap(runtime);
            InitializeMonitorObserves();
            runtime.CreateMachine(typeof(_GodMachine), new _GodMachine.Config(typeof(Main)));
        }
    }
    public class I_Client : PMachineValue {
        public I_Client (MachineId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_ClusterManager : PMachineValue {
        public I_ClusterManager (MachineId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public class I_Server : PMachineValue {
        public I_Server (MachineId machine, List<string> permissions) : base(machine, permissions) { }
    }
    
    public partial class PHelper {
        public static void InitializeInterfaces() {
            PInterfaces.Clear();
            PInterfaces.AddInterface(nameof(I_Client), nameof(AppendEntriesRequest), nameof(AppendEntriesResponse), nameof(BecomeCandidate), nameof(BecomeFollower), nameof(BecomeLeader), nameof(CConfigureEvent), nameof(ECancelTimer), nameof(EConfigureEvent), nameof(EMonitorInit), nameof(EStartTimer), nameof(ETickEvent), nameof(ETimeout), nameof(LocalEvent), nameof(NotifyLeaderElected), nameof(NotifyLeaderUpdate), nameof(PCancelTimer), nameof(PConfigureEvent), nameof(PStartTimer), nameof(PTickEvent), nameof(PTimeout), nameof(RedirectRequest), nameof(Request), nameof(Response), nameof(SConfigureEvent), nameof(ShutDown), nameof(VoteRequest), nameof(VoteResponse), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_ClusterManager), nameof(AppendEntriesRequest), nameof(AppendEntriesResponse), nameof(BecomeCandidate), nameof(BecomeFollower), nameof(BecomeLeader), nameof(CConfigureEvent), nameof(ECancelTimer), nameof(EConfigureEvent), nameof(EMonitorInit), nameof(EStartTimer), nameof(ETickEvent), nameof(ETimeout), nameof(LocalEvent), nameof(NotifyLeaderElected), nameof(NotifyLeaderUpdate), nameof(PCancelTimer), nameof(PConfigureEvent), nameof(PStartTimer), nameof(PTickEvent), nameof(PTimeout), nameof(RedirectRequest), nameof(Request), nameof(Response), nameof(SConfigureEvent), nameof(ShutDown), nameof(VoteRequest), nameof(VoteResponse), nameof(PHalt));
            PInterfaces.AddInterface(nameof(I_Server), nameof(AppendEntriesRequest), nameof(AppendEntriesResponse), nameof(BecomeCandidate), nameof(BecomeFollower), nameof(BecomeLeader), nameof(CConfigureEvent), nameof(ECancelTimer), nameof(EConfigureEvent), nameof(EMonitorInit), nameof(EStartTimer), nameof(ETickEvent), nameof(ETimeout), nameof(LocalEvent), nameof(NotifyLeaderElected), nameof(NotifyLeaderUpdate), nameof(PCancelTimer), nameof(PConfigureEvent), nameof(PStartTimer), nameof(PTickEvent), nameof(PTimeout), nameof(RedirectRequest), nameof(Request), nameof(Response), nameof(SConfigureEvent), nameof(ShutDown), nameof(VoteRequest), nameof(VoteResponse), nameof(PHalt));
        }
    }
    
    public partial class PHelper {
        public static void InitializeEnums() {
            PrtEnum.Clear();
        }
    }
    
}
#pragma warning restore 162, 219, 414
