
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*DataDescriptionDefinitionDatabaseImplInterface_Contains) (const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataType, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset;
	Result<DataDescriptionDefinition> (*DataDescriptionDefinitionDatabaseImplInterface_LoadDescription) (const maxon::GenericComponent* this_, LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset;
	Result<Tuple<Bool, DataDescriptionDefinition*>> (*DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) (maxon::GenericComponent* this_, const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset;
	Result<Bool> (*DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) (maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset;
	Result<BaseArray<IdAndVersion>> (*DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions) (const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset;
	Result<BaseArray<LanguageRef>> (*DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset;
	Result<void> (*DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset;
	Result<Int> (*DataDescriptionDefinitionDatabaseImplInterface_RenameId) (maxon::GenericComponent* this_, const Id& oldId, const Id& newId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset;
	Result<Int> (*DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) (maxon::GenericComponent* this_, const InternedId& oldId, const InternedId& newId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset;
	Result<Bool> (*DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName) (const maxon::GenericComponent* this_, const InternedId& searchId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset;
	Result<DataDescription> (*DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions) (const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset;
	Bool (*DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase) (const maxon::GenericComponent* this_, const Id& languageId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset;
	Int (*DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset;
	Result<void> (*DataDescriptionDefinitionDatabaseImplInterface_Write) (const maxon::GenericComponent* this_);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_Write_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Contains))
	{
		DataDescriptionDefinitionDatabaseImplInterface_Contains = &W::DataDescriptionDefinitionDatabaseImplInterface_Contains;
		DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, LoadDescription))
	{
		DataDescriptionDefinitionDatabaseImplInterface_LoadDescription = &W::DataDescriptionDefinitionDatabaseImplInterface_LoadDescription;
		DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, StoreDescription))
	{
		DataDescriptionDefinitionDatabaseImplInterface_StoreDescription = &W::DataDescriptionDefinitionDatabaseImplInterface_StoreDescription;
		DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, DeleteDescription))
	{
		DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription = &W::DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription;
		DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredDescriptions))
	{
		DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions = &W::DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions;
		DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredLanguages))
	{
		DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages = &W::DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages;
		DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, WriteDataBases))
	{
		DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases = &W::DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases;
		DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameId))
	{
		DataDescriptionDefinitionDatabaseImplInterface_RenameId = &W::DataDescriptionDefinitionDatabaseImplInterface_RenameId;
		DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameAttribute))
	{
		DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute = &W::DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute;
		DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, CheckUniqueAttributeName))
	{
		DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName = &W::DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName;
		DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, UpdateDescriptions))
	{
		DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions = &W::DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions;
		DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, IsWritableDatabase))
	{
		DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase = &W::DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase;
		DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetChangeCount))
	{
		DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount = &W::DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount;
		DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Write))
	{
		DataDescriptionDefinitionDatabaseImplInterface_Write = &W::DataDescriptionDefinitionDatabaseImplInterface_Write;
		DataDescriptionDefinitionDatabaseImplInterface_Write_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDescriptionDefinitionDatabaseImplInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDescriptionDefinitionDatabaseImplInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionDefinitionDatabaseImplInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataDescriptionDefinitionDatabaseImplInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionDefinitionDatabaseImplInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Bool DataDescriptionDefinitionDatabaseImplInterface_Contains(const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataType, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->Contains(category, dataType, language); }
		static Result<DataDescriptionDefinition> DataDescriptionDefinitionDatabaseImplInterface_LoadDescription(const maxon::GenericComponent* this_, LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { return ((const typename S::Implementation*) this_)->LoadDescription(mode, category, language, dataType, foundInDatabase); }
		static Result<Tuple<Bool, DataDescriptionDefinition*>> DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(maxon::GenericComponent* this_, const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { return ((typename S::Implementation*) this_)->StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); }
		static Result<Bool> DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(maxon::GenericComponent* this_, const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return ((typename S::Implementation*) this_)->DeleteDescription(category, language, dataType); }
		static Result<BaseArray<IdAndVersion>> DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions(const maxon::GenericComponent* this_, const Id& category, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->GetRegisteredDescriptions(category, language); }
		static Result<BaseArray<LanguageRef>> DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetRegisteredLanguages(); }
		static Result<void> DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->WriteDataBases(); }
		static Result<Int> DataDescriptionDefinitionDatabaseImplInterface_RenameId(maxon::GenericComponent* this_, const Id& oldId, const Id& newId) { return ((typename S::Implementation*) this_)->RenameId(oldId, newId); }
		static Result<Int> DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(maxon::GenericComponent* this_, const InternedId& oldId, const InternedId& newId) { return ((typename S::Implementation*) this_)->RenameAttribute(oldId, newId); }
		static Result<Bool> DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName(const maxon::GenericComponent* this_, const InternedId& searchId) { return ((const typename S::Implementation*) this_)->CheckUniqueAttributeName(searchId); }
		static Result<DataDescription> DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions(const maxon::GenericComponent* this_, const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { return ((const typename S::Implementation*) this_)->UpdateDescriptions(category, dataTypeId, language); }
		static Bool DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase(const maxon::GenericComponent* this_, const Id& languageId) { return ((const typename S::Implementation*) this_)->IsWritableDatabase(languageId); }
		static Int DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChangeCount(); }
		static Result<void> DataDescriptionDefinitionDatabaseImplInterface_Write(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->Write(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset, category, dataType, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset, mode, category, language, dataType, foundInDatabase);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset, category, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::WriteDataBases() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset, searchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset, category, dataTypeId, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::IsWritableDatabase(const Id& languageId) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset, languageId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetChangeCount() const -> Int
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Write() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return mt_.DataDescriptionDefinitionDatabaseImplInterface_Write((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_Write_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_Contains) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset, category, dataType, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescriptionDefinition>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_LoadDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset, mode, category, language, dataType, foundInDatabase));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) const -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, DataDescriptionDefinition*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, DataDescriptionDefinition*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<IdAndVersion>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset, category, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<LanguageRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::WriteDataBases() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::RenameId(const Id& oldId, const Id& newId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDescriptionDefinitionDatabaseImplInterface* o_ = (DataDescriptionDefinitionDatabaseImplInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset, searchId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataDescription>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset, category, dataTypeId, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::IsWritableDatabase(const Id& languageId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset, languageId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetChangeCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::Write() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDescriptionDefinitionDatabaseImplInterface* o_ = (const DataDescriptionDefinitionDatabaseImplInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDescriptionDefinitionDatabaseImplInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_, DataDescriptionDefinitionDatabaseImplInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDescriptionDefinitionDatabaseImplInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDescriptionDefinitionDatabaseImplInterface>() : PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, o_); 
	return (mt_.DataDescriptionDefinitionDatabaseImplInterface_Write(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Write_Offset));
}
auto DataDescriptionDefinitionDatabaseImplInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionDefinitionDatabaseImplInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptiondefinitiondatabaseimpl)
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

