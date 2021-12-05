// This file contains default implementations for the interfaces of genericfunction.h. They are intended for copy&paste usage only.

class MyFunctionImpl : public Component<MyFunctionImpl, FunctionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const FunctionDataType* GetFunctionType() const
	{
		return nullptr;
	}

	MAXON_METHOD Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Invoke(DynamicTupleInterface* outputs, DynamicTupleInterface* inputs, Data& cacheData) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD ConstDataPtr GetConstantValue(const Member& output) const
	{
		return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
