#if 1
namespace maxon
{
	namespace enum27 { enum class ANIMBLENDSTATE
	{
		NONE,
		STARTED,		///< Optional signal that the animation started. This flags arrives only if duration is != 0.
		RUNNING,		///< Optional signal that the animation is running within some in between state.
		FINISHED,		///< Signals that the animation reached the final state, this state is guaranteed.
		CANCELED		///< The Animation has been canceled.
	} ; }
	maxon::String PrivateToString_ANIMBLENDSTATE27(std::underlying_type<enum27::ANIMBLENDSTATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum27::ANIMBLENDSTATE::NONE, (maxon::UInt64) enum27::ANIMBLENDSTATE::STARTED, (maxon::UInt64) enum27::ANIMBLENDSTATE::RUNNING, (maxon::UInt64) enum27::ANIMBLENDSTATE::FINISHED, (maxon::UInt64) enum27::ANIMBLENDSTATE::CANCELED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ANIMBLENDSTATE", SIZEOF(x), false, values, "NONE\0STARTED\0RUNNING\0FINISHED\0CANCELED\0", fmt);
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BlendTweenInterface, "net.maxon.interface.blendtween", "maxon.BlendTweenInterface", , &ObserverObjectInterface::_interface);
	const maxon::Char* const BlendTweenInterface::MTable::_ids = 
		"GetMappedValue@820398451190d1ae\0" // GetMappedValue(Float xValue)
		"SetNewTarget@3d9f5bcaf7b1461a\0" // SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue)
		"SetFunction@fe4b4327e60f11a7\0" // SetFunction(const BlendFunctionRef& blendFunction)
		"GetFunction@5cecc2ab34063ea1\0" // GetFunction() const
		"SetStart@5b3e46c91f9c1707\0" // SetStart(const Data& value)
		"GetStart@0499ab95441128ac\0" // GetStart() const
		"SetEnd@5b3e46c91f9c1707\0" // SetEnd(const Data& value)
		"GetEnd@0499ab95441128ac\0" // GetEnd() const
		"ObservableAnimation@c78db15b92ab7abe\0" // ObservableAnimation() const
	"";
	template <typename DUMMY> maxon::Int BlendTweenInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BlendFunctionRef>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BlendAnimationInterface, "net.maxon.interface.blendanimation", "maxon.BlendAnimationInterface", , &ObserverObjectInterface::_interface);
	const maxon::Char* const BlendAnimationInterface::MTable::_ids = 
		"AddTween@d5b85797ac080666\0" // AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue)
		"RemoveTween@368855503a7764c2\0" // RemoveTween(const BlendTweenRef& tween)
		"GetTweens@3bda17a69bc8555d\0" // GetTweens() const
		"StartAnimation@c7f24991e10e0937\0" // StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration)
		"GetProgress@f358997b3\0" // GetProgress() const
		"GetState@3327731b52698fe8\0" // GetState() const
		"CancelAndWait@6b2e10f\0" // CancelAndWait()
		"GetTimerRef@8232ea84a4765e48\0" // GetTimerRef() const
	"";
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
