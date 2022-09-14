#if 1
namespace maxon
{
	const maxon::Char* const DataDescriptionDefinitionDatabaseImplInterface::MTable::_ids = 
		"Contains@c4c43b037d7d6eff\0" // Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const
		"LoadDescription@addab3645092677d\0" // Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const
		"StoreDescription@69e2fbba606b1c89\0" // Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem)
		"DeleteDescription@25ff94eae19048d0\0" // Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType)
		"GetRegisteredDescriptions@17834f864255c5b9\0" // Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const
		"GetRegisteredLanguages@efe23a860d2503e4\0" // Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const
		"WriteDataBases@a0cff72f111cef5d\0" // Result<void> WriteDataBases() const
		"RenameId@13c111108648d182\0" // Result<Int> RenameId(const Id& oldId, const Id& newId)
		"RenameAttribute@49c38790c7af88ca\0" // Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId)
		"CheckUniqueAttributeName@dc6d74c35296fd2e\0" // Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const
		"UpdateDescriptions@39a48e2883a1896\0" // Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const
		"IsWritableDatabase@1c8d04d0c3b095e6\0" // Bool IsWritableDatabase(const Id& languageId) const
		"GetChangeCounts@7d0e6f3d29c239e7\0" // Int GetChangeCounts() const
		"GetUserChangeCount@7d0e6f3d29c239e7\0" // Int GetUserChangeCount() const
		"Write@a0cff72f111cef5d\0" // Result<void> Write() const
		"WriteUserChangedDataBases@3008090429c5a175\0" // Result<void> WriteUserChangedDataBases()
	"";
	const maxon::METHOD_FLAGS DataDescriptionDefinitionDatabaseImplInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionDefinitionDatabaseImplInterface, , "net.maxon.interface.datadescriptiondefinitiondatabaseimpl", "maxon.DataDescriptionDefinitionDatabaseImplInterface", (ObjectInterface::PrivateGetInterface()));
}
#endif
