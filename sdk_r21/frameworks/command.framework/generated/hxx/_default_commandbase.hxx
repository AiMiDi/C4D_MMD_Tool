// This file contains default implementations for the interfaces of commandbase.h. They are intended for copy&paste usage only.

class MyCommandDataImpl : public maxon::Component<MyCommandDataImpl, CommandDataInterface>
{
	MAXON_COMPONENT();

public:
};

class MyLegacyCommandDataImpl : public maxon::Component<MyLegacyCommandDataImpl, LegacyCommandDataInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Generic*> GetLegacyData(Int index)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetLegacyData(const Generic* data, Int index)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetLegacyDataCount() const
	{
		return 0;
	}

};

class MyCommandClassImpl : public maxon::Component<MyCommandClassImpl, CommandClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<COMMANDSTATE> GetState(CommandDataRef& data) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<COMMANDRESULT> Execute(CommandDataRef& data) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyCommandInteractionClassImpl : public maxon::Component<MyCommandInteractionClassImpl, CommandInteractionClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<COMMANDRESULT> Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyCommandDescriptionClassImpl : public maxon::Component<MyCommandDescriptionClassImpl, CommandDescriptionClassInterface>
{
	MAXON_COMPONENT();

public:
};

class MyLegacyCommandClassImpl : public maxon::Component<MyLegacyCommandClassImpl, LegacyCommandClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConvertSettings(LegacyCommandDataRef& data) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyMigratedCommandClassImpl : public maxon::Component<MyMigratedCommandClassImpl, MigratedCommandClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Int32 GetMigratedCommandId() const
	{
		return 0;
	}

};

class MyCommandConversionClassImpl : public maxon::Component<MyCommandConversionClassImpl, CommandConversionClassInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConvertInput(LegacyCommandDataRef& data) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> ConvertOutput(LegacyCommandDataRef& data) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int32 GetLegacyCommandId() const
	{
		return 0;
	}

	MAXON_METHOD Id GetCommandId() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
