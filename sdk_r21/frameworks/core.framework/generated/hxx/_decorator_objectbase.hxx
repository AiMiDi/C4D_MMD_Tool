// This file contains decorator implementations for the interfaces of objectbase.h. They are intended for copy&paste usage only.

class ObjectDecoratorImpl : public maxon::Component<ObjectDecoratorImpl, ObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const
	{
		return maxon::Cast<ObjectRef>(self.GetDecoratedObject()).ToString(formatStatement);
	}

	MAXON_METHOD Result<void> InitObject()
	{
		return maxon::Cast<ObjectRef>(self.GetDecoratedObject()).InitObject();
	}

	MAXON_METHOD Bool IsEqual(const maxon::ObjectInterface* other) const
	{
		return maxon::Cast<ObjectRef>(self.GetDecoratedObject()).IsEqual(other);
	}

	MAXON_METHOD COMPARERESULT Compare(const maxon::ObjectInterface* other) const
	{
		return maxon::Cast<ObjectRef>(self.GetDecoratedObject()).Compare(other);
	}

	MAXON_METHOD UInt GetHashCodeImpl() const
	{
		return maxon::Cast<ObjectRef>(self.GetDecoratedObject()).GetHashCodeImpl();
	}

};

class ErrorDecoratorImpl : public maxon::Component<ErrorDecoratorImpl, ErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const SourceLocation& GetLocation() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).GetLocation();
	}

	MAXON_METHOD void SetLocation(const maxon::SourceLocation& allocLocation)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).SetLocation(allocLocation);
	}

	MAXON_METHOD Block<void* const> GetStackTrace() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).GetStackTrace();
	}

	MAXON_METHOD void SetStackTrace(const Block<void* const>& trace)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).SetStackTrace(trace);
	}

	MAXON_METHOD String GetMessage() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).GetMessage();
	}

	MAXON_METHOD void SetMessage(const String& message)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).SetMessage(message);
	}

	MAXON_METHOD const Error& GetCause() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).GetCause();
	}

	MAXON_METHOD void SetCause(const Error& cause)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).SetCause(cause);
	}

	MAXON_METHOD void GetMachine(MachineRef& machine) const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).GetMachine(machine);
	}

	MAXON_METHOD void SetMachine(const MachineRef& machine)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).SetMachine(machine);
	}

	MAXON_METHOD Int PrivateGetCode() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).PrivateGetCode();
	}

	MAXON_METHOD void PrivateSetCode(Int code)
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).PrivateSetCode(code);
	}

	MAXON_METHOD void PrivateSetPreallocation(ThreadReferencedError preallocation) const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).PrivateSetPreallocation(std::forward<ThreadReferencedError>(preallocation));
	}

	MAXON_METHOD ThreadReferencedError PrivateGetPreallocation() const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).PrivateGetPreallocation();
	}

	MAXON_METHOD void PrivateSetDebugError(const Error& cause) const
	{
		return maxon::Cast<Error>(self.GetDecoratedObject()).PrivateSetDebugError(cause);
	}

};
