// This file contains default implementations for the interfaces of objectbase.h. They are intended for copy&paste usage only.

class MyObjectImpl : public maxon::Component<MyObjectImpl, ObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD Result<void> InitObject(const void* argument)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> HandleMessage(const InternedId& message, void* argument)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> HandleConstMessage(const InternedId& message, void* argument) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsEqual(const maxon::ObjectInterface* other) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD COMPARERESULT Compare(const maxon::ObjectInterface* other) const
	{
		return HXXRET3(NULLIMPL, COMPARERESULT);
	}

	MAXON_METHOD HashInt GetHashCodeImpl() const
	{
		return HXXRET3(NULLIMPL, HashInt);
	}

	MAXON_METHOD UniqueHash GetUniqueHashCodeImpl() const
	{
		return HXXRET3(NULLIMPL, UniqueHash);
	}

};

class MyErrorImpl : public maxon::Component<MyErrorImpl, ErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const SourceLocation& GetLocation() const
	{
		return HXXRET3(NULLIMPL, const SourceLocation&);
	}

	MAXON_METHOD void SetLocation(const maxon::SourceLocation& allocLocation)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Block<void* const> GetStackTrace() const
	{
		return HXXRET3(NULLIMPL, Block<void* const>);
	}

	MAXON_METHOD void SetStackTrace(const Block<void* const>& trace)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String GetMessage() const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD void SetMessage(const String& message)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD String FormatMessage(const LanguageRef& language, const PartFormatter& partFormatter) const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD void SetMessageDelegate(Delegate<String(const LanguageRef&language,const ErrorInterface::PartFormatter&fmt)>&& message)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const Error& GetCause() const
	{
		return HXXRET3(NULLIMPL, const Error&);
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
		return HXXRET3(NULLIMPL, ThreadReferencedError);
	}

	MAXON_METHOD void PrivateSetDebugError(const Error& cause) const
	{
		return maxon::PrivateLogNullptrError();
	}

};
