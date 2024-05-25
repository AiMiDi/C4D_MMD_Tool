// This file contains default implementations for the interfaces of datadescriptiondefinitiondatabaseimpl.h. They are intended for copy&paste usage only.

class MyDataDescriptionDefinitionDatabaseImplImpl : public maxon::Component<MyDataDescriptionDefinitionDatabaseImplImpl, DataDescriptionDefinitionDatabaseImplInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteDataBases() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int> RenameId(const Id& oldId, const Id& newId)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsWritableDatabase(const Id& languageId) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Int GetChangeCounts() const
	{
		return 0;
	}

	MAXON_METHOD Int GetUserChangeCount() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> Write() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> WriteUserChangedDataBases()
	{
		return HXXRET1(NULLIMPL);
	}

};
