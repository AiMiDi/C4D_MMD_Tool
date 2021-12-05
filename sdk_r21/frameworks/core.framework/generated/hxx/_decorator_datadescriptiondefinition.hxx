// This file contains decorator implementations for the interfaces of datadescriptiondefinition.h. They are intended for copy&paste usage only.

class DataDescriptionDefinitionDecoratorImpl : public maxon::Component<DataDescriptionDefinitionDecoratorImpl, DataDescriptionDefinitionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD DataDictionary GetInfo() const
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).GetInfo();
	}

	MAXON_METHOD Result<void> SetInfo(const DataDictionary& info)
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).SetInfo(info);
	}

	MAXON_METHOD Int GetEntryCount() const
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).GetEntryCount();
	}

	MAXON_METHOD Result<BaseArray<DataDescriptionEntry>> GetEntries() const
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).GetEntries();
	}

	MAXON_METHOD Result<DataDescriptionEntry> GetEntry(Int idx) const
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).GetEntry(idx);
	}

	MAXON_METHOD Result<DataDescriptionEntry> FindEntry(const InternedId& id) const
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).FindEntry(id);
	}

	MAXON_METHOD Result<Int> AddEntry(const DataDescriptionEntry& props)
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).AddEntry(props);
	}

	MAXON_METHOD Result<void> ReplaceEntry(const DataDescriptionEntry& props)
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).ReplaceEntry(props);
	}

	MAXON_METHOD Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props)
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).ReplaceEntry(idx, props);
	}

	MAXON_METHOD Result<void> EraseEntry(Int idx)
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).EraseEntry(idx);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::Cast<DataDescriptionDefinition>(self.GetDecoratedObject()).Reset();
	}

};
