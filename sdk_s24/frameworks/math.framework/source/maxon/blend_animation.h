#ifndef BLEND_ANIMATION_H__
#define BLEND_ANIMATION_H__


#include "maxon/blend_function.h"
#include "maxon/observerobject.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/timer.h"


namespace maxon
{

class BlendTweenRef;
class BlendAnimationRef;

//----------------------------------------------------------------------------------------
/// Parameter used in the ObservableAnimation of the BlendTweenInterface
//----------------------------------------------------------------------------------------
enum class ANIMBLENDSTATE
{
	NONE,
	STARTED,		///< Optional signal that the animation started. This flags arrives only if duration is != 0.
	RUNNING,		///< Optional signal that the animation is running within some in between state.
	FINISHED,		///< Signals that the animation reached the final state, this state is guaranteed.
	CANCELED		///< The Animation has been canceled.
} MAXON_ENUM_LIST(ANIMBLENDSTATE);

using AnimBlendTweenCallback = Delegate<void(const BlendAnimationRef& self, const BlendTweenRef& tween, ANIMBLENDSTATE state, const Data& animValue)>;

//----------------------------------------------------------------------------------------
/// The BlendTweenInterface allows to add a values animated by BlendAnimationInterface.
/// Each BlendTweenInterface is a separated channel with it's own data type and start and end values.
//----------------------------------------------------------------------------------------
class BlendTweenInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(BlendTweenInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.blendtween")

public:

	//----------------------------------------------------------------------------------------
	/// Calculates the value for the given x value.
	/// @param[in] xValue							Value to be mapped with the given blend function, start and end value. The value is must be with in the 0.0 .. 1.0 range.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetMappedValue(Float xValue);

	//----------------------------------------------------------------------------------------
	/// Allows to set a new target value for the BlendTweenInterface.
	/// The last value calculated by this tween will be used as the new start value.
	/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
	/// @param[in] blendFunction			Blend function to be used to reach the end value.
	/// @param[in] endValue						New end value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue);

	//----------------------------------------------------------------------------------------
	/// Sets the blend function for this tween.
	/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
	/// @param[in] blendFunction			Blend function to be used. See BlendFunctions registry.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetFunction(const BlendFunctionRef& blendFunction);

	//----------------------------------------------------------------------------------------
	/// Returns the current blend function.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BlendFunctionRef GetFunction() const;

	//----------------------------------------------------------------------------------------
	/// Sets the start value of this tween.
	/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
	/// @param[in] value							Start value to be used.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetStart(const Data& value);

	//----------------------------------------------------------------------------------------
	/// Returns the current start value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetStart() const;

	//----------------------------------------------------------------------------------------
	/// Sets the end value of this tween.
	/// Warning: The BlendAnimationInterface should be canceled before calling this function and can be restarted afterwards. Otherwise the behavior is undefined.
	/// @param[in] value							End value to be used.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetEnd(const Data& value);

	//----------------------------------------------------------------------------------------
	/// Returns the current end value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetEnd() const;

	//----------------------------------------------------------------------------------------
	/// Observable which is triggered for each BlendAnimationInterface timer event.
	/// It's only guaranteed that ANIMBLENDSTATE::FINISHED or ANIMBLENDSTATE::CANCELED is triggered.
	/// ANIMBLENDSTATE::STARTED and ANIMBLENDSTATE::RUNNING are optional messages if enough timer events are fired.
	/// @param[in] anim								BlendAnimationRef object.
	/// @param[in] tween							BlendTweenRef object (this object).
	/// @param[in] state							The current state of the animation. See ANIMBLENDSTATE for more details.
	/// @param[in] animValue					The animated value.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableAnimation, (const BlendAnimationRef& anim, const BlendTweenRef& tween, ANIMBLENDSTATE state, const Data& animValue), ObservableCombinerRunAllComponent);
};

//----------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------
class BlendAnimationInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(BlendAnimationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.blendanimation")

public:

	//----------------------------------------------------------------------------------------
	/// Creates a new BlendAnimationRef object.
	//----------------------------------------------------------------------------------------
	static Result<BlendAnimationRef> Create();

	//----------------------------------------------------------------------------------------
	/// Adds an animation tween with the given function, start and end value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue);

	//----------------------------------------------------------------------------------------
	/// Adds an animation tween with the given function, start and end value. The callbacks are automatically mapped to the tween observable.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue, AnimBlendTweenCallback&& callback, const JobQueueRef& queue);

	//----------------------------------------------------------------------------------------
	/// Returns an array with all tweens.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveTween(const BlendTweenRef& tween);

	//----------------------------------------------------------------------------------------
	/// Returns an array with all tweens.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<BlendTweenRef>> GetTweens() const;

	//----------------------------------------------------------------------------------------
	/// Starts the animation with the given timer interval.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration);

	//----------------------------------------------------------------------------------------
	/// Returns a value between 0.0 and 1.0 with the current anim progress.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float GetProgress() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current state value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ANIMBLENDSTATE GetState() const;
	
	//----------------------------------------------------------------------------------------
	/// Kills the animation loop and the associated timer.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CancelAndWait();

	//----------------------------------------------------------------------------------------
	/// Returns the timer used for this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<TimerRef> GetTimerRef() const;
};

#include "blend_animation1.hxx"

MAXON_DECLARATION(Class<BlendAnimationRef>, AnimBlendClass, "net.maxon.class.blendanimationref");

#include "blend_animation2.hxx"

}

#endif // BLEND_ANIMATION_H__
