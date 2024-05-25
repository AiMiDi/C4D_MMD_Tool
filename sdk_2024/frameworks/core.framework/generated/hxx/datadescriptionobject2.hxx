
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDescriptionObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetObjectDescription);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataDescriptionObjectInterface_GetObjectDescription, GetObjectDescription, true, maxon::GenericComponent, const, (Result<DataDescription>), const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData);
	maxon::Int DataDescriptionObjectInterface_GetObjectDescription_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDescriptionObjectInterface, GetObjectDescription))
	{
		maxon::Tie(DataDescriptionObjectInterface_GetObjectDescription, DataDescriptionObjectInterface_GetObjectDescription_Offset) = DataDescriptionObjectInterface_GetObjectDescription_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataDescriptionObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDescriptionObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionObjectInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(DataDescriptionObjectInterface_GetObjectName, GetObjectName, MAXON_EXPAND_VA_ARGS, (Result<String>), const Id& classId, const LanguageRef& language);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DataDescriptionObjectInterface_GetObjectName = DataDescriptionObjectInterface_GetObjectName_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetObjectDescription);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataDescriptionObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataDescriptionObjectInterface_GetObjectDescription, maxon::GenericComponent, const, (Result<DataDescription>), const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetObjectDescription(category, language, objectData); }
		static Result<String> DataDescriptionObjectInterface_GetObjectName(const Id& classId, const LanguageRef& language) { return S::Implementation::GetObjectName(classId, language); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const -> Result<DataDescription>
{
	const DataDescriptionObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDescriptionObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDescriptionObjectInterface_GetObjectDescription_Offset), mt_.DataDescriptionObjectInterface_GetObjectDescription, category, language, objectData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::GetObjectName(const Id& classId, const LanguageRef& language) -> Result<String>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionObjectInterface_GetObjectName(classId, language);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::Hxx1::ConstFn<S>::GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const -> Result<DataDescription>
{
	HXXRETURN0(Result<DataDescription>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDescriptionObjectInterface_GetObjectDescription); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDescriptionObjectInterface_GetObjectDescription_Offset), mt_.DataDescriptionObjectInterface_GetObjectDescription, category, language, objectData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionObjectInterface::Hxx1::ConstFn<S>::GetObjectName(const Id& classId, const LanguageRef& language) -> Result<String>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionObjectInterface_GetObjectName(classId, language));
}
auto DataDescriptionObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptionobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionObjectInterface() { new (s_ui_maxon_DataDescriptionObjectInterface) maxon::EntityUse(DataDescriptionObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescriptionobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DataDescriptionObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DataDescriptionObjectInterface() { new (s_usi_maxon_DataDescriptionObjectInterface) maxon::EntityUse(DataDescriptionObjectInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescriptionobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

