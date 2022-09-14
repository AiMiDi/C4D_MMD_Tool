// This file contains decorator implementations for the interfaces of cpython_ref.h. They are intended for copy&paste usage only.

class CPyDecoratorImpl : public maxon::Component<CPyDecoratorImpl, CPyInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).Init(lib, refType, pyObject);
	}

	MAXON_METHOD void Incref()
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).Incref();
	}

	MAXON_METHOD void Decref()
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).Decref();
	}

	MAXON_METHOD Int64 GetRefCount()
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).GetRefCount();
	}

	MAXON_METHOD const CPythonLibraryInterface* GetLibrary() const
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).GetLibrary();
	}

	MAXON_METHOD CPyTypeRef GetTypeRef() const
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).GetTypeRef();
	}

	MAXON_METHOD NativePyObject* GetPyObject() const
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).GetPyObject();
	}

	MAXON_METHOD NativePyObject* Disconnect()
	{
		return maxon::Cast<CPyRef>(self.GetDecoratedObject()).Disconnect();
	}

};

class CPyTypeDecoratorImpl : public maxon::Component<CPyTypeDecoratorImpl, CPyTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class CPyFrameDecoratorImpl : public maxon::Component<CPyFrameDecoratorImpl, CPyFrameInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyFrameRef GetBack() const
	{
		return maxon::Cast<CPyFrameRef>(self.GetDecoratedObject()).GetBack();
	}

	MAXON_METHOD CPyCodeRef GetCode() const
	{
		return maxon::Cast<CPyFrameRef>(self.GetDecoratedObject()).GetCode();
	}

	MAXON_METHOD Int32 GetLastInstruction() const
	{
		return maxon::Cast<CPyFrameRef>(self.GetDecoratedObject()).GetLastInstruction();
	}

};

class CPyTracebackDecoratorImpl : public maxon::Component<CPyTracebackDecoratorImpl, CPyTracebackInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyTracebackRef GetNext() const
	{
		return maxon::Cast<CPyTracebackRef>(self.GetDecoratedObject()).GetNext();
	}

	MAXON_METHOD Int32 GetLineNumber() const
	{
		return maxon::Cast<CPyTracebackRef>(self.GetDecoratedObject()).GetLineNumber();
	}

	MAXON_METHOD CPyFrameRef GetFrameRef() const
	{
		return maxon::Cast<CPyTracebackRef>(self.GetDecoratedObject()).GetFrameRef();
	}

};

class CPyCodeDecoratorImpl : public maxon::Component<CPyCodeDecoratorImpl, CPyCodeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD CPyRef GetFilename() const
	{
		return maxon::Cast<CPyCodeRef>(self.GetDecoratedObject()).GetFilename();
	}

	MAXON_METHOD CPyRef GetName() const
	{
		return maxon::Cast<CPyCodeRef>(self.GetDecoratedObject()).GetName();
	}

};

class MPyClassDecoratorImpl : public maxon::Component<MPyClassDecoratorImpl, MPyClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class MPyMemberDecoratorImpl : public maxon::Component<MPyMemberDecoratorImpl, MPyMemberInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class MPyFunctionDecoratorImpl : public maxon::Component<MPyFunctionDecoratorImpl, MPyFunctionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const reflection::Function* GetFunction()
	{
		return maxon::Cast<MPyFunctionRef>(self.GetDecoratedObject()).GetFunction();
	}

};

class MPyHashMapDecoratorImpl : public maxon::Component<MPyHashMapDecoratorImpl, MPyHashMapInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD HashMap<Data, Data>* GetHashMap()
	{
		return maxon::Cast<MPyHashMapRef>(self.GetDecoratedObject()).GetHashMap();
	}

};

class MPyDataTypeDecoratorImpl : public maxon::Component<MPyDataTypeDecoratorImpl, MPyDataTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetType() const
	{
		return maxon::Cast<MPyDataTypeRef>(self.GetDecoratedObject()).GetType();
	}

};

class MPyDataDecoratorImpl : public maxon::Component<MPyDataDecoratorImpl, MPyDataInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetType() const
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).GetType();
	}

	MAXON_METHOD const DataType& GetMappingType() const
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).GetMappingType();
	}

	MAXON_METHOD Data* GetData()
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).GetData();
	}

	MAXON_METHOD const Data* GetData() const
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).GetData();
	}

	MAXON_METHOD const Generic* PrivateGetPtr() const
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).PrivateGetPtr();
	}

	MAXON_METHOD Generic* PrivateGetPtr()
	{
		return maxon::Cast<MPyDataRef>(self.GetDecoratedObject()).PrivateGetPtr();
	}

};

class MPyCallerContextDecoratorImpl : public maxon::Component<MPyCallerContextDecoratorImpl, MPyCallerContextInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
