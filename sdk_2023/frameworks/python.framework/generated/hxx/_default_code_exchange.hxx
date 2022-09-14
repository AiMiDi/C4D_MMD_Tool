// This file contains default implementations for the interfaces of code_exchange.h. They are intended for copy&paste usage only.

class MyCodeExchangeImpl : public maxon::Component<MyCodeExchangeImpl, CodeExchangeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Start()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Stop()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SendScriptToIDE(const PythonElementScriptRef& script)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SendConsoleOutput(const String& content)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD InternedId GetLanguage() const
	{
		return maxon::PrivateIncompleteNullReturnValue<InternedId>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD String GetName() const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
