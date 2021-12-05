// This file contains default implementations for the interfaces of cpython_ref.h. They are intended for copy&paste usage only.

class MyCPyImpl : public Component<MyCPyImpl, CPyInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void Incref()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void Decref()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Int64 GetRefCount()
	{
		return 0;
	}

	MAXON_METHOD const CPythonLibraryInterface* GetLibrary() const
	{
		return nullptr;
	}

	MAXON_METHOD CPyTypeRef GetTypeRef() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD NativePyObject* GetPyObject() const
	{
		return nullptr;
	}

	MAXON_METHOD NativePyObject* Disconnect()
	{
		return nullptr;
	}

};

class MyCPyTypeImpl : public Component<MyCPyTypeImpl, CPyTypeInterface>
{
	MAXON_COMPONENT();

public:
};

class MyCPyFrameImpl : public Component<MyCPyFrameImpl, CPyFrameInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyFrameRef GetBack() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyCodeRef GetCode() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int32 GetLastInstruction() const
	{
		return 0;
	}

};

class MyCPyTracebackImpl : public Component<MyCPyTracebackImpl, CPyTracebackInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyTracebackRef GetNext() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTracebackRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int32 GetLineNumber() const
	{
		return 0;
	}

	MAXON_METHOD CPyFrameRef GetFrameRef() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyFrameRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyCPyCodeImpl : public Component<MyCPyCodeImpl, CPyCodeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyRef GetFilename() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef GetName() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyMPyClassImpl : public Component<MyMPyClassImpl, MPyClassInterface>
{
	MAXON_COMPONENT();

public:
};

class MyMPyMemberImpl : public Component<MyMPyMemberImpl, MPyMemberInterface>
{
	MAXON_COMPONENT();

public:
};

class MyMPyFunctionImpl : public Component<MyMPyFunctionImpl, MPyFunctionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const reflection::Function* GetFunction()
	{
		return nullptr;
	}

};

class MyMPyDataTypeImpl : public Component<MyMPyDataTypeImpl, MPyDataTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType* GetType() const
	{
		return nullptr;
	}

};

class MyMPyDataImpl : public Component<MyMPyDataImpl, MPyDataInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType* GetType() const
	{
		return nullptr;
	}

	MAXON_METHOD const DataType* GetMappingType() const
	{
		return nullptr;
	}

	MAXON_METHOD Data* GetData()
	{
		return nullptr;
	}

	MAXON_METHOD const Data* GetData() const
	{
		return nullptr;
	}

	MAXON_METHOD const Generic* PrivateGetPtr() const
	{
		return nullptr;
	}

	MAXON_METHOD Generic* PrivateGetPtr()
	{
		return nullptr;
	}

};

class MyMPyCallerContextImpl : public Component<MyMPyCallerContextImpl, MPyCallerContextInterface>
{
	MAXON_COMPONENT();

public:
};
