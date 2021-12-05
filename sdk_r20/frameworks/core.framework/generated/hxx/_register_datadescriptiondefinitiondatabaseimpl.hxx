#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionDefinitionDatabaseImplInterface, "net.maxon.interface.datadescriptiondefinitiondatabaseimpl", "maxon.DataDescriptionDefinitionDatabaseImplInterface", , &Object::_interface);
	const maxon::Char* const DataDescriptionDefinitionDatabaseImplInterface::MTable::_ids = 
		"Contains@bc9ef407c7caf41c\0" // Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const
		"LoadDescription@2422bd6379334912\0" // LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const
		"StoreDescription@aa95141549ccc804\0" // StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
		"DeleteDescription@65aef61bc3defe75\0" // DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"GetRegisteredDescriptions@1a16af4c95f7e840\0" // GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const
		"GetRegisteredLanguages@140dfdd02956b01f\0" // GetRegisteredLanguages() const
		"WriteDataBases@0499ab9fb052eea2\0" // WriteDataBases() const
		"RenameId@ba77b560b678ba5b\0" // RenameId(const Id& oldId, const Id& newId)
		"RenameAttribute@d71c15fcc18ae4b9\0" // RenameAttribute(const InternedId& oldId, const InternedId& newId)
		"CheckUniqueAttributeName@c25c6af811986ccb\0" // CheckUniqueAttributeName(const InternedId& searchId) const
		"UpdateDescriptions@177502fd96fd1d1d\0" // UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const
		"IsWritableDatabase@102c54c30eda6105\0" // IsWritableDatabase(const Id& languageId) const
		"GetChangeCount@4386c86\0" // GetChangeCount() const
		"Write@0499ab9fb052eea2\0" // Write() const
	"";
	template <typename DUMMY> maxon::Int DataDescriptionDefinitionDatabaseImplInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datadescriptiondefinitiondatabaseimpl(0
	| maxon::DataDescriptionDefinitionDatabaseImplInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
