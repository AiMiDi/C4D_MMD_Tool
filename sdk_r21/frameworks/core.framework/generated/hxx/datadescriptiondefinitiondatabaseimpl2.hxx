
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionDefinitionDatabaseImplInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CheckUniqueAttributeName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Contains);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DeleteDescription);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChangeCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetRegisteredDescriptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetRegisteredLanguages);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsWritableDatabase);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(LoadDescription);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RenameAttribute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RenameId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(StoreDescription);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(UpdateDescriptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteDataBases);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_DataDescriptionDefinitionDatabaseImplInterface_Contains) (const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataType, const LanguageRef& language);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset;
	Result<DataDescriptionDefinition> (*_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription) (const maxon::GenericComponent* this_, LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset;
	Result<Tuple<Bool, DataDescriptionDefinition*>> (*_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) (maxon::GenericComponent* this_, const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset;
	Result<Bool> (*_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) (maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset;
	Result<BaseArray<IdAndVersion>> (*_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions) (const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset;
	Result<BaseArray<LanguageRef>> (*_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset;
	Result<void> (*_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset;
	Result<Int> (*_DataDescriptionDefinitionDatabaseImplInterface_RenameId) (maxon::GenericComponent* this_, const Id& oldId, const Id& newId);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset;
	Result<Int> (*_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) (maxon::GenericComponent* this_, const InternedId& oldId, const InternedId& newId);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset;
	Result<Bool> (*_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName) (const maxon::GenericComponent* this_, const InternedId& searchId);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset;
	Result<DataDescription> (*_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions) (const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset;
	Bool (*_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase) (const maxon::GenericComponent* this_, const Id& languageId);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset;
	Int (*_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset;
	Result<void> (*_DataDescriptionDefinitionDatabaseImplInterface_Write) (const maxon::GenericComponent* this_);
	maxon::Int _DataDescriptionDefinitionDatabaseImplInterface_Write_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Contains))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Contains), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_Contains;
			_DataDescriptionDefinitionDatabaseImplInterface_Contains = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_Contains)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, LoadDescription))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, LoadDescription), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription;
			_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, StoreDescription))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, StoreDescription), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription;
			_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, DeleteDescription))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, DeleteDescription), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription;
			_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredDescriptions))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredDescriptions), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions;
			_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredLanguages))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredLanguages), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages;
			_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, WriteDataBases))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, WriteDataBases), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases;
			_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameId), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_RenameId;
			_DataDescriptionDefinitionDatabaseImplInterface_RenameId = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_RenameId)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameAttribute))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameAttribute), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute;
			_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, CheckUniqueAttributeName))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, CheckUniqueAttributeName), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName;
			_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, UpdateDescriptions))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, UpdateDescriptions), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions;
			_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, IsWritableDatabase))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, IsWritableDatabase), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase;
			_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetChangeCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetChangeCount), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount;
			_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Write))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Write), W, MTable>::type::_DataDescriptionDefinitionDatabaseImplInterface_Write;
			_DataDescriptionDefinitionDatabaseImplInterface_Write = reinterpret_cast<const decltype(_DataDescriptionDefinitionDatabaseImplInterface_Write)&>(ptr);
			_DataDescriptionDefinitionDatabaseImplInterface_Write_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionDefinitionDatabaseImplInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataDescriptionDefinitionDatabaseImplInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionDefinitionDatabaseImplInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CheckUniqueAttributeName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Contains);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DeleteDescription);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChangeCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetRegisteredDescriptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetRegisteredLanguages);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsWritableDatabase);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(LoadDescription);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RenameAttribute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RenameId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(StoreDescription);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(UpdateDescriptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteDataBases);
	static Bool _DataDescriptionDefinitionDatabaseImplInterface_Contains(const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataType, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->Contains(category, dataType, language); }
	static Result<DataDescriptionDefinition> _DataDescriptionDefinitionDatabaseImplInterface_LoadDescription(const maxon::GenericComponent* this_, LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { return ((const typename S::Implementation*) this_)->LoadDescription(mode, category, language, dataType, foundInDatabase); }
	static Result<Tuple<Bool, DataDescriptionDefinition*>> _DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(maxon::GenericComponent* this_, const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { return ((typename S::Implementation*) this_)->StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); }
	static Result<Bool> _DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return ((typename S::Implementation*) this_)->DeleteDescription(category, language, dataType); }
	static Result<BaseArray<IdAndVersion>> _DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions(const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->GetRegisteredDescriptions(category, language); }
	static Result<BaseArray<LanguageRef>> _DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetRegisteredLanguages(); }
	static Result<void> _DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->WriteDataBases(); }
	static Result<Int> _DataDescriptionDefinitionDatabaseImplInterface_RenameId(maxon::GenericComponent* this_, const Id& oldId, const Id& newId) { return ((typename S::Implementation*) this_)->RenameId(oldId, newId); }
	static Result<Int> _DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(maxon::GenericComponent* this_, const InternedId& oldId, const InternedId& newId) { return ((typename S::Implementation*) this_)->RenameAttribute(oldId, newId); }
	static Result<Bool> _DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName(const maxon::GenericComponent* this_, const InternedId& searchId) { return ((const typename S::Implementation*) this_)->CheckUniqueAttributeName(searchId); }
	static Result<DataDescription> _DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions(const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->UpdateDescriptions(category, dataTypeId, language); }
	static Bool _DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase(const maxon::GenericComponent* this_, const Id& languageId) { return ((const typename S::Implementation*) this_)->IsWritableDatabase(languageId); }
	static Int _DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChangeCount(); }
	static Result<void> _DataDescriptionDefinitionDatabaseImplInterface_Write(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->Write(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_Contains((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset, category, dataType, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_LoadDescription((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset, mode, category, language, dataType, foundInDatabase);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset, category, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::WriteDataBases() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute((maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset, searchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset, category, dataTypeId, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::IsWritableDatabase(const Id& languageId) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset, languageId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetChangeCount() const -> Int
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Write() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_._DataDescriptionDefinitionDatabaseImplInterface_Write((const maxon::GenericComponent*) this + mt_._DataDescriptionDefinitionDatabaseImplInterface_Write_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_Contains) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_Contains(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset, category, dataType, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionDefinition>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_LoadDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_LoadDescription(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset, mode, category, language, dataType, foundInDatabase));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ReferenceFunctionsImpl<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) const -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, DataDescriptionDefinition*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWReferenceFunctionsImpl<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, DataDescriptionDefinition*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ReferenceFunctionsImpl<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWReferenceFunctionsImpl<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<IdAndVersion>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset, category, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<LanguageRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::WriteDataBases() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ReferenceFunctionsImpl<S>::RenameId(const Id& oldId, const Id& newId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWReferenceFunctionsImpl<S>::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ReferenceFunctionsImpl<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWReferenceFunctionsImpl<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset, searchId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescription>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset, category, dataTypeId, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsWritableDatabase(const Id& languageId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset, languageId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChangeCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Write() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_._DataDescriptionDefinitionDatabaseImplInterface_Write(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDescriptionDefinitionDatabaseImplInterface_Write_Offset));
}
auto DataDescriptionDefinitionDatabaseImplInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionDefinitionDatabaseImplInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionDefinitionDatabaseImplInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionDefinitionDatabaseImplInterface() { new (s_ui_maxon_DataDescriptionDefinitionDatabaseImplInterface) maxon::EntityUse(DataDescriptionDefinitionDatabaseImplInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinitiondatabaseimpl.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionDefinitionDatabaseImplInterface(DataDescriptionDefinitionDatabaseImplInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptiondefinitiondatabaseimpl.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

