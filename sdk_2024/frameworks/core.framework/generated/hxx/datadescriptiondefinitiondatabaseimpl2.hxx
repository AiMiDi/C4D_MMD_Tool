
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChangeCounts);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetRegisteredDescriptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetRegisteredLanguages);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUserChangeCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsWritableDatabase);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(LoadDescription);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RenameAttribute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RenameId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(StoreDescription);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(UpdateDescriptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteDataBases);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteUserChangedDataBases);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_Contains, Contains, true, maxon::GenericComponent, const, (Bool), const Id& category, const IdAndVersion& dataType, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, LoadDescription, true, maxon::GenericComponent, const, (Result<DataDescriptionDefinition>), LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, StoreDescription, true, maxon::GenericComponent,, (Result<Tuple<Bool, DataDescriptionDefinition*>>), const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, DeleteDescription, true, maxon::GenericComponent,, (Result<Bool>), const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, GetRegisteredDescriptions, true, maxon::GenericComponent, const, (Result<BaseArray<IdAndVersion>>), const Id& category, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages, GetRegisteredLanguages, true, maxon::GenericComponent, const, (Result<BaseArray<LanguageRef>>));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases, WriteDataBases, true, maxon::GenericComponent, const, (Result<void>));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_RenameId, RenameId, true, maxon::GenericComponent,, (Result<Int>), const Id& oldId, const Id& newId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, RenameAttribute, true, maxon::GenericComponent,, (Result<Int>), const InternedId& oldId, const InternedId& newId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, CheckUniqueAttributeName, true, maxon::GenericComponent, const, (Result<Bool>), const InternedId& searchId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, UpdateDescriptions, true, maxon::GenericComponent, const, (Result<DataDescription>), const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, IsWritableDatabase, true, maxon::GenericComponent, const, (Bool), const Id& languageId);
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts, GetChangeCounts, true, maxon::GenericComponent, const, (Int));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount, GetUserChangeCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_Write, Write, true, maxon::GenericComponent, const, (Result<void>));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_Write_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases, WriteUserChangedDataBases, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Contains))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_Contains, DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset) = DataDescriptionDefinitionDatabaseImplInterface_Contains_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, LoadDescription))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset) = DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, StoreDescription))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset) = DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, DeleteDescription))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset) = DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredDescriptions))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset) = DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetRegisteredLanguages))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages, DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset) = DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, WriteDataBases))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases, DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset) = DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameId))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_RenameId, DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset) = DataDescriptionDefinitionDatabaseImplInterface_RenameId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, RenameAttribute))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset) = DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, CheckUniqueAttributeName))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset) = DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, UpdateDescriptions))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset) = DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, IsWritableDatabase))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset) = DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetChangeCounts))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts, DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_Offset) = DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, GetUserChangeCount))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount, DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_Offset) = DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, Write))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_Write, DataDescriptionDefinitionDatabaseImplInterface_Write_Offset) = DataDescriptionDefinitionDatabaseImplInterface_Write_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionDefinitionDatabaseImplInterface, WriteUserChangedDataBases))
	{
		maxon::Tie(DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases, DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset) = DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataDescriptionDefinitionDatabaseImplInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChangeCounts);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetRegisteredDescriptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetRegisteredLanguages);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUserChangeCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsWritableDatabase);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(LoadDescription);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RenameAttribute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RenameId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(StoreDescription);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(UpdateDescriptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteDataBases);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteUserChangedDataBases);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataDescriptionDefinitionDatabaseImplInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionDefinitionDatabaseImplInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_Contains, maxon::GenericComponent, const, (Bool), const Id& category, const IdAndVersion& dataType, const LanguageRef& language) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Contains(category, dataType, language); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, maxon::GenericComponent, const, (Result<DataDescriptionDefinition>), LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->LoadDescription(mode, category, language, dataType, foundInDatabase); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, maxon::GenericComponent,, (Result<Tuple<Bool, DataDescriptionDefinition*>>), const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->StoreDescription(databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, maxon::GenericComponent,, (Result<Bool>), const Id& category, const LanguageRef& language, const IdAndVersion& dataType) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->DeleteDescription(category, language, dataType); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, maxon::GenericComponent, const, (Result<BaseArray<IdAndVersion>>), const Id& category, const LanguageRef& language) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetRegisteredDescriptions(category, language); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages, maxon::GenericComponent, const, (Result<BaseArray<LanguageRef>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetRegisteredLanguages(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases, maxon::GenericComponent, const, (Result<void>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->WriteDataBases(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_RenameId, maxon::GenericComponent,, (Result<Int>), const Id& oldId, const Id& newId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RenameId(oldId, newId); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, maxon::GenericComponent,, (Result<Int>), const InternedId& oldId, const InternedId& newId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RenameAttribute(oldId, newId); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, maxon::GenericComponent, const, (Result<Bool>), const InternedId& searchId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CheckUniqueAttributeName(searchId); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, maxon::GenericComponent, const, (Result<DataDescription>), const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->UpdateDescriptions(category, dataTypeId, language); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, maxon::GenericComponent, const, (Bool), const Id& languageId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsWritableDatabase(languageId); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChangeCounts(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUserChangeCount(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_Write, maxon::GenericComponent, const, (Result<void>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Write(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->WriteUserChangedDataBases(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains, category, dataType, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, mode, category, language, dataType, foundInDatabase);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, category, language, dataType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, category, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::WriteDataBases() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, oldId, newId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, searchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, category, dataTypeId, language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::IsWritableDatabase(const Id& languageId) const -> Bool
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, languageId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetChangeCounts() const -> Int
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::GetUserChangeCount() const -> Int
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Write() const -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_Write_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_Write);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::WriteUserChangedDataBases() -> Result<void>
{
	const DataDescriptionDefinitionDatabaseImplInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionDefinitionDatabaseImplInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_Contains); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_Contains, category, dataType, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase) const -> Result<DataDescriptionDefinition>
{
	HXXRETURN0(Result<DataDescriptionDefinition>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_LoadDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_LoadDescription, mode, category, language, dataType, foundInDatabase));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) const -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	HXXRETURN0(Result<Tuple<Bool, DataDescriptionDefinition*>>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_StoreDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) -> Result<Tuple<Bool, DataDescriptionDefinition*>>
{
	HXXRETURN0(Result<Tuple<Bool, DataDescriptionDefinition*>>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_StoreDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_StoreDescription, databaseId, category, language, dataType, description, overwrittenDescription, usePendingSystem));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_DeleteDescription, category, language, dataType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const -> Result<BaseArray<IdAndVersion>>
{
	HXXRETURN0(Result<BaseArray<IdAndVersion>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredDescriptions, category, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetRegisteredLanguages() const -> Result<BaseArray<LanguageRef>>
{
	HXXRETURN0(Result<BaseArray<LanguageRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetRegisteredLanguages));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::WriteDataBases() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteDataBases));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::RenameId(const Id& oldId, const Id& newId) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_RenameId); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::RenameId(const Id& oldId, const Id& newId) -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_RenameId); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameId, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::RenameAttribute(const InternedId& oldId, const InternedId& newId) -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_RenameAttribute, oldId, newId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::CheckUniqueAttributeName(const InternedId& searchId) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_CheckUniqueAttributeName, searchId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const -> Result<DataDescription>
{
	HXXRETURN0(Result<DataDescription>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_UpdateDescriptions, category, dataTypeId, language));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::IsWritableDatabase(const Id& languageId) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_IsWritableDatabase, languageId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetChangeCounts() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetChangeCounts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::GetUserChangeCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_GetUserChangeCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::ConstFn<S>::Write() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_Write); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_Write_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_Write));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Fn<S>::WriteUserChangedDataBases() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionDefinitionDatabaseImplInterface::Hxx1::COWFn<S>::WriteUserChangedDataBases() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases_Offset), mt_.DataDescriptionDefinitionDatabaseImplInterface_WriteUserChangedDataBases));
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

