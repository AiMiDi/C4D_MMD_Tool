#if 1
class ProgressRef;

struct ProgressInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ProgressInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ProgressInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ProgressInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ProgressRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for ProgressInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ProgressInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ProgressInterface**);
/// GetTotalWeight returns the total weight of all jobs.
		inline HXXADDRET2(Float) GetTotalWeight() const;
/// Observable will be called as soon as the progress changes.
/// -param[in] progress						Reference to this object.
/// -param[in] percent						Percentage between 0.0 and 1.0 of the done work.
/// -param[in] duration						Duration of the current operation.
/// -param[in] expectedTotalTime	Expected total time of the current operation. TIMEVALUE_INFINITE will be set for infinite time.
/// -param[in] userData						User data passed from the caller.
		inline HXXADDRET2(maxon::ObservableRef<ObservableProgressNotificationDelegate>) ObservableProgressNotification(Bool create) const;
/// GetTime returns a tuple with the "running time" and "expected total time" of the progress.
/// Expected time might be TIMEVALUE_INFINITE if the time is unknown.
		inline Result<Tuple<TimeValue, TimeValue>> GetTime() const;
/// Returns the details of the progress.
		inline HXXADDRET2(String) GetDetailsText() const;
/// SupportsCancelJob returns true if the progress object supports job cancellation.
		inline HXXADDRET2(Bool) SupportsCancelJob() const;
	};
	/// Intermediate helper class for ProgressInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ProgressInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ProgressInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ProgressRef, true>::type&() const { return reinterpret_cast<const ProgressRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ProgressRef, false>::type&() { return reinterpret_cast<const ProgressRef&>(this->GetBaseRef()); }
/// @param[in] delayFirstProgress	Time to delay the first progress notification.
/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
		inline Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) const;
/// The first call of AddProgressJob() switches from simple mode to multi job mode.
/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
/// @return												Index of the newly created job.
		inline Result<Int> AddProgressJob(Float jobWeight, const String& jobName) const;
/// Sets the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob() or 0 when running in simple mode.
/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work. use UNKNOWNPROGRESS to set spinning mode
		inline Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent) const;
/// Returns the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or 0 when running in simple mode or -1 to get the total progress.
/// @return												Progress between 0 and 1 or UNKNOWNPROGRESS for unknown duration (ui should show a spinner in that case.
		inline Result<Float> GetProgress(Int jobIndex) const;
/// Sets the details of the progress.
/// @param[in] details						New details to be set.
		inline HXXADDRET2(void) SetDetailsText(const String& details) const;
/// SetCancelJobDelegate allows to set a job cancellation delegate.
/// @param[in] cancelJobDelegate	Delegate which is called to cancel the job
/// @return                       OK on success.
		inline Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate) const;
/// CancelJob cancels the job by calling the job cancel delegate (see SetCancelJobDelegate).
/// @return                       OK on success.
		inline Result<void> CancelJob() const;
/// IsCancelled returns true if the job is cancelled.
		inline HXXADDRET2(Bool) IsCancelled() const;
	};
	/// Intermediate helper class for ProgressInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = ProgressInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ProgressInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ProgressRef, false>::type&() { return reinterpret_cast<const ProgressRef&>(this->GetBaseRef()); }
/// @param[in] delayFirstProgress	Time to delay the first progress notification.
/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
		inline Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);
/// The first call of AddProgressJob() switches from simple mode to multi job mode.
/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
/// @return												Index of the newly created job.
		inline Result<Int> AddProgressJob(Float jobWeight, const String& jobName);
/// Sets the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob() or 0 when running in simple mode.
/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work. use UNKNOWNPROGRESS to set spinning mode
		inline Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent);
/// Returns the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or 0 when running in simple mode or -1 to get the total progress.
/// @return												Progress between 0 and 1 or UNKNOWNPROGRESS for unknown duration (ui should show a spinner in that case.
		inline Result<Float> GetProgress(Int jobIndex);
/// Sets the details of the progress.
/// @param[in] details						New details to be set.
		inline HXXADDRET1(void) SetDetailsText(const String& details);
/// SetCancelJobDelegate allows to set a job cancellation delegate.
/// @param[in] cancelJobDelegate	Delegate which is called to cancel the job
/// @return                       OK on success.
		inline Result<void> SetCancelJobDelegate(JobCancelDelegate&& cancelJobDelegate);
/// CancelJob cancels the job by calling the job cancel delegate (see SetCancelJobDelegate).
/// @return                       OK on success.
		inline Result<void> CancelJob();
/// IsCancelled returns true if the job is cancelled.
		inline HXXADDRET1(Bool) IsCancelled();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class ProgressInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<ProgressRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ProgressInterface, maxon::StrongRefHandler, ProgressRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ProgressInterface, maxon::StrongRefHandler, ProgressRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ProgressRef is the reference class of ProgressInterface.
///
/// This class simplifies the progress tracking of operations.
/// Once created a operation can simply put the current progress into the object by calling SetProgressAndCheckBreak().
/// On the other end the ObservableProgressNotification can be hooked up to get notifications (e.g. for the ui).
/// The implementation can handle 2 modes.
/// 1.) simple mode: without calling AddProgressJob() there is one default job available with a weight of 1.0. you can use this mode to call all functions with idx == 0 to set or get the progress.
/// 2.) multi mode: after calling AddProgressJob() the first time you need to provide the idx for the job you want to set or get. the implementation calculates the total progress depending on the weights of the individual sub jobs.
class ProgressRef : public ProgressInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ProgressRef, typename ProgressInterface::Hxx1::Reference);
	using ConstPtr = typename ProgressInterface::ConstPtr;
};

class ProgressInterface::ObservableProgressNotificationDelegate : public maxon::Delegate<void(const ProgressRef&,Float,const TimeValue&,const TimeValue&)>
{
public:
	using Super = maxon::Delegate<void(const ProgressRef&,Float,const TimeValue&,const TimeValue&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleProgressNotification);
	ObservableProgressNotificationDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleProgressNotification); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

#endif
