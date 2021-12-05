#if 1
struct BlendTweenInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendTweenInterface>::value || ObserverObjectInterface::HasBase::Check<I>::value; static I* Cast(BlendTweenInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class BlendTweenRef;

struct BlendTweenInterface::ReferenceClassHelper { using type = BlendTweenRef; };

/// Intermediate helper class for BlendTweenInterface.
template <typename S> class BlendTweenInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns the current blend function.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<BlendFunctionRef>, BlendFunctionRef>::type GetFunction() const;
/// Returns the current start value.
	inline Result<Data> GetStart() const;
/// Returns the current end value.
	inline Result<Data> GetEnd() const;
/// Observable which is triggered for each BlendAnimationInterface timer event.
/// It's only guaranteed that ANIMBLENDSTATE::FINISHED or ANIMBLENDSTATE::CANCELED is triggered.
/// ANIMBLENDSTATE::STARTED and ANIMBLENDSTATE::RUNNING are optional messages if enough timer events are fired.
/// -param[in] anim										BlendAnimationRef object.
/// -param[in] tween									BlendTweenRef object (this object).
/// -param[in] state									The current state of the animation. See ANIMBLENDSTATE for more details.
/// -param[in] animValue							The animated value.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableAnimationDelegate>>, maxon::ObservableRef<ObservableAnimationDelegate>>::type ObservableAnimation() const;
};
#ifdef DOXYGEN
template <typename REF> class BlendTweenInterface::ConstReferenceFunctionsImplDoxy : public BlendTweenInterface::ConstReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendTweenInterface.
template <typename S> class BlendTweenInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendTweenRef, true>::type&() const { return reinterpret_cast<const BlendTweenRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendTweenRef, false>::type&() { return reinterpret_cast<const BlendTweenRef&>(this->GetBaseRef()); }
/// Calculates the value for the given x value.
/// @param[in] xValue							Value to be mapped with the given blend function, start and end value. The value is must be with in the 0.0 .. 1.0 range.
	inline Result<Data> GetMappedValue(Float xValue) const;
/// Allows to set a new target value for the BlendTweenInterface.
/// The last value calculated by this tween will be used as the new start value.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] blendFunction			Blend function to be used to reach the end value.
/// @param[in] endValue						New end value.
	inline Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue) const;
/// Sets the blend function for this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] blendFunction			Blend function to be used. See BlendFunctions registry.
	inline Result<void> SetFunction(const BlendFunctionRef& blendFunction) const;
/// Sets the start value of this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] value							Start value to be used.
	inline Result<void> SetStart(const Data& value) const;
/// Sets the end value of this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] value							End value to be used.
	inline Result<void> SetEnd(const Data& value) const;
};
#ifdef DOXYGEN
template <typename REF> class BlendTweenInterface::ReferenceFunctionsImplDoxy : public BlendTweenInterface::ReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendTweenInterface.
template <typename S> class BlendTweenInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BlendTweenRef, false>::type&() { return reinterpret_cast<const BlendTweenRef&>(this->GetBaseRef()); }
/// Calculates the value for the given x value.
/// @param[in] xValue							Value to be mapped with the given blend function, start and end value. The value is must be with in the 0.0 .. 1.0 range.
	inline Result<Data> GetMappedValue(Float xValue);
/// Allows to set a new target value for the BlendTweenInterface.
/// The last value calculated by this tween will be used as the new start value.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] blendFunction			Blend function to be used to reach the end value.
/// @param[in] endValue						New end value.
	inline Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue);
/// Sets the blend function for this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] blendFunction			Blend function to be used. See BlendFunctions registry.
	inline Result<void> SetFunction(const BlendFunctionRef& blendFunction);
/// Sets the start value of this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] value							Start value to be used.
	inline Result<void> SetStart(const Data& value);
/// Sets the end value of this tween.
/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
/// @param[in] value							End value to be used.
	inline Result<void> SetEnd(const Data& value);
};
#ifdef DOXYGEN
template <typename REF> class BlendTweenInterface::COWReferenceFunctionsImplDoxy : public BlendTweenInterface::COWReferenceFunctionsImpl<REF>, public ObserverObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct BlendTweenInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class BlendTweenInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<BlendTweenRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendTweenInterface, maxon::StrongRefHandler, BlendTweenRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendTweenInterface, maxon::StrongRefHandler, BlendTweenRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// BlendTweenRef is the reference class of BlendTweenInterface.
///
/// The BlendTweenInterface allows to add a values animated by BlendAnimationInterface.
/// Each BlendTweenInterface is a separated channel with it's own data type and start and end values.
class BlendTweenRef : public BlendTweenInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendTweenRef, Reference);
};

class BlendTweenInterface::ObservableAnimationDelegate : public maxon::Delegate<void(const BlendAnimationRef&,const BlendTweenRef&,ANIMBLENDSTATE,const Data&)>
{
public:
	using Super = maxon::Delegate<void(const BlendAnimationRef&,const BlendTweenRef&,ANIMBLENDSTATE,const Data&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleAnimation);
	ObservableAnimationDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleAnimation<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleAnimation); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleAnimation<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

struct BlendAnimationInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendAnimationInterface>::value || ObserverObjectInterface::HasBase::Check<I>::value; static I* Cast(BlendAnimationInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class BlendAnimationRef;

struct BlendAnimationInterface::ReferenceClassHelper { using type = BlendAnimationRef; };

/// Intermediate helper class for BlendAnimationInterface.
template <typename S> class BlendAnimationInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns an array with all tweens.
	inline Result<BaseArray<BlendTweenRef>> GetTweens() const;
/// Returns a value between 0.0 and 1.0 with the current anim progress.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetProgress() const;
/// Returns the current state value.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<ANIMBLENDSTATE>, ANIMBLENDSTATE>::type GetState() const;
/// Returns the timer used for this object.
	inline Result<TimerRef> GetTimerRef() const;
};
#ifdef DOXYGEN
template <typename REF> class BlendAnimationInterface::ConstReferenceFunctionsImplDoxy : public BlendAnimationInterface::ConstReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendAnimationInterface.
template <typename S> class BlendAnimationInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendAnimationRef, true>::type&() const { return reinterpret_cast<const BlendAnimationRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendAnimationRef, false>::type&() { return reinterpret_cast<const BlendAnimationRef&>(this->GetBaseRef()); }
/// Adds an animation tween with the given function, start and end value.
	inline Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue) const;
/// Adds an animation tween with the given function, start and end value. The callbacks are automatically mapped to the tween observable.
	inline Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue) const;
/// Returns an array with all tweens.
	inline Result<void> RemoveTween(const BlendTweenRef& tween) const;
/// Starts the animation with the given timer interval.
	inline Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration) const;
/// Kills the animation loop and the associated timer.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type CancelAndWait() const;
};
#ifdef DOXYGEN
template <typename REF> class BlendAnimationInterface::ReferenceFunctionsImplDoxy : public BlendAnimationInterface::ReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendAnimationInterface.
template <typename S> class BlendAnimationInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BlendAnimationRef, false>::type&() { return reinterpret_cast<const BlendAnimationRef&>(this->GetBaseRef()); }
/// Adds an animation tween with the given function, start and end value.
	inline Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue);
/// Adds an animation tween with the given function, start and end value. The callbacks are automatically mapped to the tween observable.
	inline Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue);
/// Returns an array with all tweens.
	inline Result<void> RemoveTween(const BlendTweenRef& tween);
/// Starts the animation with the given timer interval.
	inline Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration);
/// Kills the animation loop and the associated timer.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type CancelAndWait();
};
#ifdef DOXYGEN
template <typename REF> class BlendAnimationInterface::COWReferenceFunctionsImplDoxy : public BlendAnimationInterface::COWReferenceFunctionsImpl<REF>, public ObserverObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct BlendAnimationInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class BlendAnimationInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<BlendAnimationRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendAnimationInterface, maxon::StrongRefHandler, BlendAnimationRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendAnimationInterface, maxon::StrongRefHandler, BlendAnimationRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// BlendAnimationRef is the reference class of BlendAnimationInterface.
///
/// This class allows to handle easy animations using one or more BlendTweenInterfaces with a given timer interval.
/// The following example demonstrates how to use this class:
/// @code
/// // create a new BlendAnimationRef.
///	BlendAnimationRef animBlend = AnimBlendClass().Create() iferr_return;
/// // add one tween to animate a vector data type from 1/2/3 to 10/100/1000.
///	BlendTweenRef tween1 = animBlend.AddTween(BlendFunctions::EaseOutBounce(), Data(Vector(1, 2, 3)), Data(Vector(10, 100, 1000)),
///		[](const BlendAnimationRef& anim, const BlendTweenRef& tween, ANIMBLENDSTATE state, const Data& tickValue)
///		{
///			DiagnosticOutput("Anim: @ @", state, tickValue);
///		}, nullptr) iferr_return;
/// // start the animation with a 50 milli seconds timer interval and a duration of 1 second.
///	animBlend.StartAnimation(Milliseconds(50), TimeValue(), Seconds(1.0)) iferr_return;
/// @endcode
class BlendAnimationRef : public BlendAnimationInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendAnimationRef, Reference);
};

#endif
