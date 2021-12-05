// This file contains decorator implementations for the interfaces of blend_animation.h. They are intended for copy&paste usage only.

class BlendTweenDecoratorImpl : public maxon::Component<BlendTweenDecoratorImpl, BlendTweenInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Data> GetMappedValue(Float xValue)
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).GetMappedValue(xValue);
	}

	MAXON_METHOD Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue)
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).SetNewTarget(blendFunction, endValue);
	}

	MAXON_METHOD Result<void> SetFunction(const BlendFunctionRef& blendFunction)
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).SetFunction(blendFunction);
	}

	MAXON_METHOD BlendFunctionRef GetFunction() const
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).GetFunction();
	}

	MAXON_METHOD Result<void> SetStart(const Data& value)
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).SetStart(value);
	}

	MAXON_METHOD Result<Data> GetStart() const
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).GetStart();
	}

	MAXON_METHOD Result<void> SetEnd(const Data& value)
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).SetEnd(value);
	}

	MAXON_METHOD Result<Data> GetEnd() const
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).GetEnd();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableAnimationDelegate> ObservableAnimation() const
	{
		return maxon::Cast<BlendTweenRef>(self.GetDecoratedObject()).ObservableAnimation();
	}

};

class BlendAnimationDecoratorImpl : public maxon::Component<BlendAnimationDecoratorImpl, BlendAnimationInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue)
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).AddTween(blendFunction, startValue, endValue);
	}

	MAXON_METHOD Result<void> RemoveTween(const BlendTweenRef& tween)
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).RemoveTween(tween);
	}

	MAXON_METHOD Result<BaseArray<BlendTweenRef>> GetTweens() const
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).GetTweens();
	}

	MAXON_METHOD Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration)
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).StartAnimation(timerInterval, startDelay, duration);
	}

	MAXON_METHOD Float GetProgress() const
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).GetProgress();
	}

	MAXON_METHOD ANIMBLENDSTATE GetState() const
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).GetState();
	}

	MAXON_METHOD void CancelAndWait()
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).CancelAndWait();
	}

	MAXON_METHOD Result<TimerRef> GetTimerRef() const
	{
		return maxon::Cast<BlendAnimationRef>(self.GetDecoratedObject()).GetTimerRef();
	}

};
