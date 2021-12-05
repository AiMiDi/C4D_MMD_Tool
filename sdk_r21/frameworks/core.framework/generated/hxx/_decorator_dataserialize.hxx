// This file contains decorator implementations for the interfaces of dataserialize.h. They are intended for copy&paste usage only.

class DataSerializeDecoratorImpl : public maxon::Component<DataSerializeDecoratorImpl, DataSerializeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const
	{
		return maxon::Cast<DataSerializeRef>(self.GetDecoratedObject()).DescribeElement(name, dt, objectOffset, func, flags, mask, value);
	}

	MAXON_METHOD Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const
	{
		return maxon::Cast<DataSerializeRef>(self.GetDecoratedObject()).PrepareHelperClass(createFunc, deleteFunc, readFunc, writeFunc, flags);
	}

	MAXON_METHOD Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func)
	{
		return maxon::Cast<DataSerializeRef>(self.GetDecoratedObject()).RegisterObjectSubstitution(std::forward<ReferenceSubstitutionFunction>(func));
	}

	MAXON_METHOD Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const
	{
		return maxon::Cast<DataSerializeRef>(self.GetDecoratedObject()).RegisterDefaults(createFunc, deleteFunc);
	}

};

class DataSerializeWriterDecoratorImpl : public maxon::Component<DataSerializeWriterDecoratorImpl, DataSerializeWriterInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> WriteDocument(const Id& id, const ConstDataPtr& data)
	{
		return maxon::Cast<DataSerializeWriterRef>(self.GetDecoratedObject()).WriteDocument(id, data);
	}

};

class DataSerializeReaderDecoratorImpl : public maxon::Component<DataSerializeReaderDecoratorImpl, DataSerializeReaderInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ReadDocument(const Id& id, const DataPtr& data)
	{
		return maxon::Cast<DataSerializeReaderRef>(self.GetDecoratedObject()).ReadDocument(id, data);
	}

};
