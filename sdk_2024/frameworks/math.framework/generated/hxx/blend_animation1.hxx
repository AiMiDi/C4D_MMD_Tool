#if 1
class BlendTweenRef;

struct BlendTweenInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendTweenInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(BlendTweenInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct BlendTweenInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BlendTweenRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for BlendTweenInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendTweenInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(BlendTweenInterface**);
/// Returns the current blend function.
		inline HXXADDRET2(BlendFunctionRef) GetFunction() const;
/// Returns the current start value.
		inline Result<Data> GetStart() const;
/// Returns the current end value.
		inline Result<Data> GetEnd() const;
/// Observable which is triggered for each BlendAnimationInterface timer event.
/// It's only guaranteed that ANIMBLENDSTATE::FINISHED or ANIMBLENDSTATE::CANCELED is triggered.
/// ANIMBLENDSTATE::STARTED and ANIMBLENDSTATE::RUNNING are optional messages if enough timer events are fired.
/// -param[in] anim								BlendAnimationRef object.
/// -param[in] tween							BlendTweenRef object (this object).
/// -param[in] state							The current state of the animation. See ANIMBLENDSTATE for more details.
/// -param[in] animValue					The animated value.
		inline HXXADDRET2(maxon::ObservableRef<ObservableAnimationDelegate>) ObservableAnimation(Bool create) const;
	};
	/// Intermediate helper class for BlendTweenInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendTweenInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BlendTweenInterface**);
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
	/// Intermediate helper class for BlendTweenInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendTweenInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BlendTweenInterface**);
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
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class BlendTweenInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<BlendTweenRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendTweenInterface, maxon::StrongRefHandler, BlendTweenRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendTweenInterface, maxon::StrongRefHandler, BlendTweenRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// BlendTweenRef is the reference class of BlendTweenInterface.
///
/// The BlendTweenInterface allows to add a values animated by BlendAnimationInterface.
/// Each BlendTweenInterface is a separated channel with it's own data type and start and end values.
class BlendTweenRef : public BlendTweenInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendTweenRef, typename BlendTweenInterface::Hxx1::Reference);
	using ConstPtr = typename BlendTweenInterface::ConstPtr;
};

class BlendTweenInterface::ObservableAnimationDelegate : public maxon::Delegate<void(const BlendAnimationRef&,const BlendTweenRef&,ANIMBLENDSTATE,const Data&)>
{
public:
	using Super = maxon::Delegate<void(const BlendAnimationRef&,const BlendTweenRef&,ANIMBLENDSTATE,const Data&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleAnimation);
	ObservableAnimationDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleAnimation<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleAnimation); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleAnimation<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponent_PrivateHelper;
};

class BlendAnimationRef;

struct BlendAnimationInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendAnimationInterface>::value || ObserverObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(BlendAnimationInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct BlendAnimationInterface::Hxx1
{
	class Reference;
	using ReferenceClass = BlendAnimationRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for BlendAnimationInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendAnimationInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(BlendAnimationInterface**);
/// Returns an array with all tweens.
		inline Result<BaseArray<BlendTweenRef>> GetTweens() const;
/// Returns a value between 0.0 and 1.0 with the current anim progress.
		inline HXXADDRET2(Float) GetProgress() const;
/// Returns the current state value.
		inline HXXADDRET2(ANIMBLENDSTATE) GetState() const;
/// Returns the timer used for this object.
		inline Result<TimerRef> GetTimerRef() const;
	};
	/// Intermediate helper class for BlendAnimationInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendAnimationInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(BlendAnimationInterface**);
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
		inline HXXADDRET2(void) CancelAndWait() const;
/// SetStartProgress allows to set the progress where the animation should start. this can be useful if you try to reverse another animation.
/// @param[in] startProgress			Start value.
		inline HXXADDRET2(void) SetStartProgress(Float startProgress) const;
/// SetDirection allows to change the animation direction to play the reverse blend functions.
/// @param[in] reverse						True to animate backwards.
		inline HXXADDRET2(void) SetDirection(Bool reverse) const;
	};
	/// Intermediate helper class for BlendAnimationInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = BlendAnimationInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(BlendAnimationInterface**);
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
		inline HXXADDRET1(void) CancelAndWait();
/// SetStartProgress allows to set the progress where the animation should start. this can be useful if you try to reverse another animation.
/// @param[in] startProgress			Start value.
		inline HXXADDRET1(void) SetStartProgress(Float startProgress);
/// SetDirection allows to change the animation direction to play the reverse blend functions.
/// @param[in] reverse						True to animate backwards.
		inline HXXADDRET1(void) SetDirection(Bool reverse);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObserverObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class BlendAnimationInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<BlendAnimationRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendAnimationInterface, maxon::StrongRefHandler, BlendAnimationRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<BlendAnimationInterface, maxon::StrongRefHandler, BlendAnimationRef>>>>);
	using NonConst = typename Super::ReferenceClass;
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
class BlendAnimationRef : public BlendAnimationInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendAnimationRef, typename BlendAnimationInterface::Hxx1::Reference);
	using ConstPtr = typename BlendAnimationInterface::ConstPtr;
};

#endif
