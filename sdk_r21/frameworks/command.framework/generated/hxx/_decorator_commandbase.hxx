// This file contains decorator implementations for the interfaces of commandbase.h. They are intended for copy&paste usage only.

class CommandDataDecoratorImpl : public maxon::Component<CommandDataDecoratorImpl, CommandDataInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class LegacyCommandDataDecoratorImpl : public maxon::Component<LegacyCommandDataDecoratorImpl, LegacyCommandDataInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Generic*> GetLegacyData(Int index)
	{
		return maxon::Cast<LegacyCommandDataRef>(self.GetDecoratedObject()).GetLegacyData(index);
	}

	MAXON_METHOD Result<void> SetLegacyData(const Generic* data, Int index)
	{
		return maxon::Cast<LegacyCommandDataRef>(self.GetDecoratedObject()).SetLegacyData(data, index);
	}

	MAXON_METHOD Int GetLegacyDataCount() const
	{
		return maxon::Cast<LegacyCommandDataRef>(self.GetDecoratedObject()).GetLegacyDataCount();
	}

};

class CommandClassDecoratorImpl : public maxon::Component<CommandClassDecoratorImpl, CommandClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<COMMANDSTATE> GetState(CommandDataRef& data) const
	{
		return maxon::Cast<CommandClass>(self.GetDecoratedObject()).GetState(data);
	}

	MAXON_METHOD Result<COMMANDRESULT> Execute(CommandDataRef& data) const
	{
		return maxon::Cast<CommandClass>(self.GetDecoratedObject()).Execute(data);
	}

};

class CommandInteractionClassDecoratorImpl : public maxon::Component<CommandInteractionClassDecoratorImpl, CommandInteractionClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const
	{
		return maxon::Cast<CommandInteractionClass>(self.GetDecoratedObject()).Interact(data, interactionType);
	}

};

class CommandDescriptionClassDecoratorImpl : public maxon::Component<CommandDescriptionClassDecoratorImpl, CommandDescriptionClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class LegacyCommandClassDecoratorImpl : public maxon::Component<LegacyCommandClassDecoratorImpl, LegacyCommandClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConvertSettings(LegacyCommandDataRef& data) const
	{
		return maxon::Cast<LegacyCommandClass>(self.GetDecoratedObject()).ConvertSettings(data);
	}

};

class MigratedCommandClassDecoratorImpl : public maxon::Component<MigratedCommandClassDecoratorImpl, MigratedCommandClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int32 GetMigratedCommandId() const
	{
		return maxon::Cast<MigratedCommandClass>(self.GetDecoratedObject()).GetMigratedCommandId();
	}

};

class CommandConversionClassDecoratorImpl : public maxon::Component<CommandConversionClassDecoratorImpl, CommandConversionClassInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConvertInput(LegacyCommandDataRef& data) const
	{
		return maxon::Cast<CommandConversionClass>(self.GetDecoratedObject()).ConvertInput(data);
	}

	MAXON_METHOD Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const
	{
		return maxon::Cast<CommandConversionClass>(self.GetDecoratedObject()).ExecuteCustomActions(data, actionId, flags);
	}

	MAXON_METHOD Result<void> ConvertOutput(LegacyCommandDataRef& data) const
	{
		return maxon::Cast<CommandConversionClass>(self.GetDecoratedObject()).ConvertOutput(data);
	}

	MAXON_METHOD Int32 GetLegacyCommandId() const
	{
		return maxon::Cast<CommandConversionClass>(self.GetDecoratedObject()).GetLegacyCommandId();
	}

	MAXON_METHOD Id GetCommandId() const
	{
		return maxon::Cast<CommandConversionClass>(self.GetDecoratedObject()).GetCommandId();
	}

};
