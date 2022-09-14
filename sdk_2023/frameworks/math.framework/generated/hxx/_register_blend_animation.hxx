#if 1
namespace maxon
{
	namespace enum27
	{
		enum class ANIMBLENDSTATE
		{
			NONE,
			STARTED,		///< Optional signal that the animation started. This flags arrives only if duration is != 0.
			RUNNING,		///< Optional signal that the animation is running within some in between state.
			FINISHED,		///< Signals that the animation reached the final state, this state is guaranteed.
			CANCELED		///< The Animation has been canceled.
		} ;
		static const maxon::UInt64 ANIMBLENDSTATE_values[] = {maxon::UInt64(enum27::ANIMBLENDSTATE::NONE), maxon::UInt64(enum27::ANIMBLENDSTATE::STARTED), maxon::UInt64(enum27::ANIMBLENDSTATE::RUNNING), maxon::UInt64(enum27::ANIMBLENDSTATE::FINISHED), maxon::UInt64(enum27::ANIMBLENDSTATE::CANCELED)};
		static const maxon::EnumInfo ANIMBLENDSTATE_info{"ANIMBLENDSTATE", SIZEOF(ANIMBLENDSTATE), false, "NONE\0STARTED\0RUNNING\0FINISHED\0CANCELED\0", ANIMBLENDSTATE_values, std::extent<decltype(ANIMBLENDSTATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ANIMBLENDSTATE27(){ return enum27::ANIMBLENDSTATE_info; }
	const maxon::Char* const BlendTweenInterface::MTable::_ids = 
		"GetMappedValue@f24d33e2a9650b1f\0" // Result<Data> GetMappedValue(Float xValue)
		"SetNewTarget@d4ba38aff1520f47\0" // Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue)
		"SetFunction@f99f6c046e130242\0" // Result<void> SetFunction(const BlendFunctionRef& blendFunction)
		"GetFunction@44dabdf7726fb580\0" // BlendFunctionRef GetFunction() const
		"SetStart@6517ddb76f613bd6\0" // Result<void> SetStart(const Data& value)
		"GetStart@b1d39bbb7aec8c43\0" // Result<Data> GetStart() const
		"SetEnd@6517ddb76f613bd6\0" // Result<void> SetEnd(const Data& value)
		"GetEnd@b1d39bbb7aec8c43\0" // Result<Data> GetEnd() const
		"ObservableAnimation@4c86e08c174cc7b3\0" // maxon::ObservableRef<ObservableAnimationDelegate> ObservableAnimation() const
	"";
	const maxon::METHOD_FLAGS BlendTweenInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BlendTweenInterface, , "net.maxon.interface.blendtween", "maxon.BlendTweenInterface", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int BlendTweenInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BlendFunctionRef>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const BlendAnimationInterface::MTable::_ids = 
		"AddTween@a40c17f7e64c812d\0" // Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue)
		"RemoveTween@1628a74b4bfbe90f\0" // Result<void> RemoveTween(const BlendTweenRef& tween)
		"GetTweens@f894db2391c423fc\0" // Result<BaseArray<BlendTweenRef>> GetTweens() const
		"StartAnimation@6dae5d7a84020182\0" // Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration)
		"GetProgress@e6d3186387d3ce58\0" // Float GetProgress() const
		"GetState@49c216a997457085\0" // ANIMBLENDSTATE GetState() const
		"CancelAndWait@780cdac8f1a33934\0" // void CancelAndWait()
		"GetTimerRef@49b08b34cb2c4cd9\0" // Result<TimerRef> GetTimerRef() const
		"SetStartProgress@9999e08c086b1526\0" // void SetStartProgress(Float startProgress)
		"SetDirection@add9409250097f0c\0" // void SetDirection(Bool reverse)
	"";
	const maxon::METHOD_FLAGS BlendAnimationInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BlendAnimationInterface, , "net.maxon.interface.blendanimation", "maxon.BlendAnimationInterface", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int BlendAnimationInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ANIMBLENDSTATE>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AnimBlendClass, , "net.maxon.class.blendanimationref");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_blend_animation(0
	| maxon::BlendTweenInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::BlendAnimationInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
