#if 1
namespace maxon
{
	const maxon::Char* const DataDescriptionDefinitionDatabaseImplInterface::MTable::_ids = 
		"Contains@bc9ef407c7caf41c\0" // Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const
		"LoadDescription@2422bd6379334912\0" // Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const
		"StoreDescription@aa95141549ccc804\0" // Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
		"DeleteDescription@65aef61bc3defe75\0" // Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"GetRegisteredDescriptions@1a16af4c95f7e840\0" // Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const
		"GetRegisteredLanguages@140dfdd02956b01f\0" // Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const
		"WriteDataBases@0499ab9fb052eea2\0" // Result<void> WriteDataBases() const
		"RenameId@ba77b560b678ba5b\0" // Result<Int> RenameId(const Id& oldId, const Id& newId)
		"RenameAttribute@d71c15fcc18ae4b9\0" // Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId)
		"CheckUniqueAttributeName@c25c6af811986ccb\0" // Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const
		"UpdateDescriptions@177502fd96fd1d1d\0" // Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const
		"IsWritableDatabase@102c54c30eda6105\0" // Bool IsWritableDatabase(const Id& languageId) const
		"GetChangeCount@4386c86\0" // Int GetChangeCount() const
		"Write@0499ab9fb052eea2\0" // Result<void> Write() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionDefinitionDatabaseImplInterface, , "net.maxon.interface.datadescriptiondefinitiondatabaseimpl", "maxon.DataDescriptionDefinitionDatabaseImplInterface", (&ObjectInterface::_interface));
}
#endif
