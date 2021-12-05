#if 1
class MediaSessionProgressRef;

struct MediaSessionProgressInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, MediaSessionProgressInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(MediaSessionProgressInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct MediaSessionProgressInterface::Hxx1
{
	class Reference;
	using ReferenceClass = MediaSessionProgressRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for MediaSessionProgressInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Observable will be called as soon as the progress changes.
/// -param[in] progress						Reference to this object.
/// -param[in] percent						Percentage between 0.0 and 1.0 of the done work.
/// -param[in] duration						Duration of the current operation.
/// -param[in] expectedTotalTime	Expected total time of the current operation. TIMEVALUE_INFINITE will be set for infinite time.
/// -param[in] userData						User data passed from the caller.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableProgressNotificationDelegate>>, maxon::ObservableRef<ObservableProgressNotificationDelegate>>::type ObservableProgressNotification() const;
/// GetTotalWeight returns the total weight of all jobs.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetTotalWeight() const;
	};
	/// Intermediate helper class for MediaSessionProgressInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionProgressRef, true>::type&() const { return reinterpret_cast<const MediaSessionProgressRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, MediaSessionProgressRef, false>::type&() { return reinterpret_cast<const MediaSessionProgressRef&>(this->GetBaseRef()); }
/// @param[in] delayFirstProgress	Time to delay the first progress notification.
/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
		inline Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate) const;
/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
/// @return												Index of the job.
		inline Result<Int> AddProgressJob(const Float jobWeight, const String& jobName) const;
/// Sets the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or -1 if no jobs are added
/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work.
		inline Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent) const;
/// Returns the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or -1 if no jobs are added
		inline Result<Float> GetProgress(Int jobIndex) const;
	};
	/// Intermediate helper class for MediaSessionProgressInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, MediaSessionProgressRef, false>::type&() { return reinterpret_cast<const MediaSessionProgressRef&>(this->GetBaseRef()); }
/// @param[in] delayFirstProgress	Time to delay the first progress notification.
/// @param[in] minProgressUpdate	Minimum time difference to call the progress callback.
		inline Result<void> InitProgress(const TimeValue& delayFirstProgress, const TimeValue& minProgressUpdate);
/// @param[in] jobWeight					Add the weight for this job. All the weights are summed up and is taken into account for the overall percentage.
/// @return												Index of the job.
		inline Result<Int> AddProgressJob(const Float jobWeight, const String& jobName);
/// Sets the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or -1 if no jobs are added
/// @param[in] percent						Percentage between 0.0 and 1.0 of the done work.
		inline Result<void> SetProgressAndCheckBreak(Int jobIndex, Float percent);
/// Returns the progress of the current operation.
/// @param[in] jobIndex						Job index returned by AddProgressJob or -1 if no jobs are added
		inline Result<Float> GetProgress(Int jobIndex);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class MediaSessionProgressInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<MediaSessionProgressRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionProgressInterface, maxon::StrongRefHandler, MediaSessionProgressRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<MediaSessionProgressInterface, maxon::StrongRefHandler, MediaSessionProgressRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// MediaSessionProgressRef is the reference class of MediaSessionProgressInterface.
///
/// This class simplifies the progress tracking of operations.
/// Once created a operation can simply put the current progress into the object by calling SetProgressAndCheckBreak().
/// On the other end the ObservableProgressNotification can be hooked up to get notifications (e.g. for the ui).
class MediaSessionProgressRef : public MediaSessionProgressInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(MediaSessionProgressRef, typename MediaSessionProgressInterface::Hxx1::Reference);
	using ConstPtr = typename MediaSessionProgressInterface::ConstPtr;
};

class MediaSessionProgressInterface::ObservableProgressNotificationDelegate : public maxon::Delegate<void(const MediaSessionProgressRef&,Float,const TimeValue&,const TimeValue&)>
{
public:
	using Super = maxon::Delegate<void(const MediaSessionProgressRef&,Float,const TimeValue&,const TimeValue&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleProgressNotification);
	ObservableProgressNotificationDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleProgressNotification); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleProgressNotification<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
