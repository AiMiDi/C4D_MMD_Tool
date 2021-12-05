// This file contains decorator implementations for the interfaces of observable.h. They are intended for copy&paste usage only.

class FunctionBaseDecoratorImpl : public maxon::Component<FunctionBaseDecoratorImpl, FunctionBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function)
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function));
	}

	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue)
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).Init(std::forward<const ObservableForwardFunction>(forwardFunction), std::forward<DelegateBase>(function), queue);
	}

	MAXON_METHOD void Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer)
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).Set(owner, observer);
	}

	MAXON_METHOD void GetOwner(ObserverObjectRef& res) const
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).GetOwner(res);
	}

	MAXON_METHOD void GetObserver(ObserverObjectRef& res) const
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).GetObserver(res);
	}

	MAXON_METHOD const void* GetObserverPointer() const
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).GetObserverPointer();
	}

	MAXON_METHOD Result<Data> Execute(const Block<const ConstDataPtr>& args)
	{
		return maxon::Cast<FunctionBaseRef>(self.GetDecoratedObject()).Execute(args);
	}

};

class CombinerDecoratorImpl : public maxon::Component<CombinerDecoratorImpl, CombinerInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitCombine(Result<Data>& combinedRes) const
	{
		return maxon::Cast<CombinerRef>(self.GetDecoratedObject()).InitCombine(combinedRes);
	}

	MAXON_METHOD Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const
	{
		return maxon::Cast<CombinerRef>(self.GetDecoratedObject()).CombineResult(combinedRes, std::forward<Result<Data>>(newRes));
	}

};

class ObservableBaseDecoratorImpl : public maxon::Component<ObservableBaseDecoratorImpl, ObservableBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(ObserverObjectInterface* owner, const Id& observableName)
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).Init(owner, observableName);
	}

	MAXON_METHOD Id GetObservableId() const
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).GetObservableId();
	}

	MAXON_METHOD void _intDisconnectAll(ObserverObjectInterface* observer, Int pass)
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject())._intDisconnectAll(observer, pass);
	}

	MAXON_METHOD Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction)
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).AddObserver(observer, observerFunction);
	}

	MAXON_METHOD Result<Data> Notify(const Block<const ConstDataPtr>& args) const
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).Notify(args);
	}

	MAXON_METHOD Result<void> RemoveObserver(const FunctionBaseRef& observerEntry)
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).RemoveObserver(observerEntry);
	}

	MAXON_METHOD void SetInverseNotification(Bool inverse)
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).SetInverseNotification(inverse);
	}

	MAXON_METHOD Int GetObserverCount()
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).GetObserverCount();
	}

	MAXON_METHOD ObserverObjectInterface* GetOwner() const
	{
		return maxon::Cast<ObservableBaseRef>(self.GetDecoratedObject()).GetOwner();
	}

};
