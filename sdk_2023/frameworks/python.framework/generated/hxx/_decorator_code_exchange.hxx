// This file contains decorator implementations for the interfaces of code_exchange.h. They are intended for copy&paste usage only.

class CodeExchangeDecoratorImpl : public maxon::Component<CodeExchangeDecoratorImpl, CodeExchangeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Start()
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).Start();
	}

	MAXON_METHOD Result<void> Stop()
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).Stop();
	}

	MAXON_METHOD Result<void> SendScriptToIDE(const PythonElementScriptRef& script)
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).SendScriptToIDE(script);
	}

	MAXON_METHOD Result<void> SendConsoleOutput(const String& content)
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).SendConsoleOutput(content);
	}

	MAXON_METHOD InternedId GetLanguage() const
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).GetLanguage();
	}

	MAXON_METHOD String GetName() const
	{
		return maxon::Cast<CodeExchangeRef>(self.GetDecoratedObject()).GetName();
	}

};
