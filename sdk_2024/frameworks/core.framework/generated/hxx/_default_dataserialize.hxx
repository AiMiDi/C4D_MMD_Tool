// This file contains default implementations for the interfaces of dataserialize.h. They are intended for copy&paste usage only.

class MyDataSerializeImpl : public maxon::Component<MyDataSerializeImpl, DataSerializeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyDataSerializeWriterImpl : public maxon::Component<MyDataSerializeWriterImpl, DataSerializeWriterInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> WriteDocument(const Id& id, const ConstDataPtr& data)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyDataSerializeReaderImpl : public maxon::Component<MyDataSerializeReaderImpl, DataSerializeReaderInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ReadDocument(const Id& id, const DataPtr& data)
	{
		return HXXRET1(NULLIMPL);
	}

};
