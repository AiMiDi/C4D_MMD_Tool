// This file contains decorator implementations for the interfaces of datadescriptiondefinitiondatabaseimpl.h. They are intended for copy&paste usage only.

class DataDescriptionDefinitionDatabaseImplDecoratorImpl : public maxon::Component<DataDescriptionDefinitionDatabaseImplDecoratorImpl, DataDescriptionDefinitionDatabaseImplInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).Contains(category, dataType, language);
	}

	MAXON_METHOD Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).LoadDescription(mode, category, language, dataType, foundInDatabase);
	}

	MAXON_METHOD Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
	}

	MAXON_METHOD Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).DeleteDescription(category, language, dataType);
	}

	MAXON_METHOD Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).GetRegisteredDescriptions(category, language);
	}

	MAXON_METHOD Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).GetRegisteredLanguages();
	}

	MAXON_METHOD Result<void> WriteDataBases() const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).WriteDataBases();
	}

	MAXON_METHOD Result<Int> RenameId(const Id& oldId, const Id& newId)
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).RenameId(oldId, newId);
	}

	MAXON_METHOD Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId)
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).RenameAttribute(oldId, newId);
	}

	MAXON_METHOD Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).CheckUniqueAttributeName(searchId);
	}

	MAXON_METHOD Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).UpdateDescriptions(category, dataTypeId, language);
	}

	MAXON_METHOD Bool IsWritableDatabase(const Id& languageId) const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).IsWritableDatabase(languageId);
	}

	MAXON_METHOD Int GetChangeCount() const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).GetChangeCount();
	}

	MAXON_METHOD Result<void> Write() const
	{
		return maxon::Cast<DataDescriptionDefinitionDatabaseImplRef>(self.GetDecoratedObject()).Write();
	}

};
