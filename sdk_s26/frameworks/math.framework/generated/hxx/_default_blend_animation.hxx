// This file contains default implementations for the interfaces of blend_animation.h. They are intended for copy&paste usage only.

class MyBlendTweenImpl : public maxon::Component<MyBlendTweenImpl, BlendTweenInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Data> GetMappedValue(Float xValue)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetNewTarget(const BlendFunctionRef& blendFunction, const Data& endValue)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetFunction(const BlendFunctionRef& blendFunction)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD BlendFunctionRef GetFunction() const
	{
		return maxon::PrivateIncompleteNullReturnValue<BlendFunctionRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> SetStart(const Data& value)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Data> GetStart() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetEnd(const Data& value)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Data> GetEnd() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableAnimationDelegate> ObservableAnimation() const
	{
		return maxon::ObservableRef<ObservableAnimationDelegate>::NullValue();
	}

};

class MyBlendAnimationImpl : public maxon::Component<MyBlendAnimationImpl, BlendAnimationInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BlendTweenRef> AddTween(const BlendFunctionRef& blendFunction, const Data& startValue, const Data& endValue)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> RemoveTween(const BlendTweenRef& tween)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<BlendTweenRef>> GetTweens() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> StartAnimation(const TimeValue& timerInterval, const TimeValue& startDelay, const TimeValue& duration)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Float GetProgress() const
	{
		return 0;
	}

	MAXON_METHOD ANIMBLENDSTATE GetState() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ANIMBLENDSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CancelAndWait()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<TimerRef> GetTimerRef() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void SetStartProgress(Float startProgress)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void SetDirection(Bool reverse)
	{
		return maxon::PrivateLogNullptrError();
	}

};
