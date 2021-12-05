// This file contains default implementations for the interfaces of datadescriptiondefinition.h. They are intended for copy&paste usage only.

class MyDataDescriptionDefinitionImpl : public maxon::Component<MyDataDescriptionDefinitionImpl, DataDescriptionDefinitionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD DataDictionary GetInfo() const
	{
		return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> SetInfo(const DataDictionary& info)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetEntryCount() const
	{
		return 0;
	}

	MAXON_METHOD Result<BaseArray<DataDescriptionEntry>> GetEntries() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<DataDescriptionEntry> GetEntry(Int idx) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<DataDescriptionEntry> FindEntry(const InternedId& id) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Int> AddEntry(const DataDescriptionEntry& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> ReplaceEntry(const DataDescriptionEntry& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> EraseEntry(Int idx)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::PrivateLogNullptrError();
	}

};
