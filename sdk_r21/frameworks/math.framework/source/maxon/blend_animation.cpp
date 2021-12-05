#include "maxon/blend_animation.h"

namespace maxon
{

Result<BlendAnimationRef> BlendAnimationInterface::Create()
{
	iferr_scope;
	BlendAnimationRef animBlend = AnimBlendClass().Create() iferr_return;
	return std::move(animBlend);
}

Result<BlendTweenRef> BlendAnimationInterface::AddTween(const BlendFunctionRef& blendFunction,
												const Data& startValue, const Data& endValue,
												AnimBlendTweenCallback&& callback, const JobQueueRef& queue)
{
	iferr_scope;
	BlendTweenRef tween = AddTween(blendFunction, startValue, endValue) iferr_return;
	if (callback)
	{
		tween.ObservableAnimation().AddObserver(std::move(callback), queue) iferr_return;
	}
	return std::move(tween);
}

}
