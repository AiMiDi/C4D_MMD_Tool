// This file contains default implementations for the interfaces of observable.h. They are intended for copy&paste usage only.

class MyFunctionBaseImpl : public maxon::Component<MyFunctionBaseImpl, FunctionBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const ObservableForwardFunction forwardFunction, DelegateBase&& function, const JobQueueRef& queue)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void Set(ObserverObjectInterface* owner, ObserverObjectInterface* observer)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetOwner(ObserverObjectRef& res) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetObserver(ObserverObjectRef& res) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const void* GetObserverPointer() const
	{
		return nullptr;
	}

	MAXON_METHOD Result<Data> Execute(const Block<const ConstDataPtr>& args)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyCombinerImpl : public maxon::Component<MyCombinerImpl, CombinerInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitCombine(Result<Data>& combinedRes) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> CombineResult(Result<Data>& combinedRes, Result<Data>&& newRes) const
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyObservableBaseImpl : public maxon::Component<MyObservableBaseImpl, ObservableBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(ObserverObjectInterface* owner, const Id& observableName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Id GetObservableId() const
	{
		return HXXRET3(NULLIMPL, Id);
	}

	MAXON_METHOD void PrivateDisconnectAll(ObserverObjectInterface* observer, Int pass)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<void> AddObserver(ObserverObjectInterface* observer, const FunctionBaseRef& observerFunction, Int priority)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Data> Notify(const Block<const ConstDataPtr>& args) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool RemoveObserver(const FunctionBaseRef& observerEntry)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD void SetInverseNotification(Bool inverse)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Int GetObserverCount()
	{
		return 0;
	}

	MAXON_METHOD ObserverObjectInterface* GetOwner() const
	{
		return nullptr;
	}

};
