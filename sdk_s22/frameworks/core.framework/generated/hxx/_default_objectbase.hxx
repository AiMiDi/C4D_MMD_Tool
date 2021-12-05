// This file contains default implementations for the interfaces of objectbase.h. They are intended for copy&paste usage only.

class MyObjectImpl : public maxon::Component<MyObjectImpl, ObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> InitObject()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool IsEqual(const maxon::ObjectInterface* other) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD COMPARERESULT Compare(const maxon::ObjectInterface* other) const
	{
		return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD UInt GetHashCodeImpl() const
	{
		return 0;
	}

};

class MyErrorImpl : public maxon::Component<MyErrorImpl, ErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const SourceLocation& GetLocation() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const SourceLocation&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetLocation(const maxon::SourceLocation& allocLocation)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Block<void* const> GetStackTrace() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Block<void* const>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetStackTrace(const Block<void* const>& trace)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String GetMessage() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetMessage(const String& message)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const Error& GetCause() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetCause(const Error& cause)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetMachine(MachineRef& machine) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void SetMachine(const MachineRef& machine)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Int PrivateGetCode() const
	{
		return 0;
	}

	MAXON_METHOD void PrivateSetCode(Int code)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void PrivateSetPreallocation(ThreadReferencedError preallocation) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD ThreadReferencedError PrivateGetPreallocation() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ThreadReferencedError>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void PrivateSetDebugError(const Error& cause) const
	{
		return maxon::PrivateLogNullptrError();
	}

};
