
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace MODULEVERSIONINFO
{
}

struct ModuleVersionInfoInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ModuleVersionInfoInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ModuleVersionInfoInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ModuleVersionInfoInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(ModuleVersionInfoInterface_RegisterIntern, RegisterIntern, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->ModuleVersionInfoInterface_RegisterIntern = ModuleVersionInfoInterface_RegisterIntern_GetPtr<IMPL>(true);
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ModuleVersionInfoInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ModuleVersionInfoInterface::_interface); if (!vt) return false;
			return true;
		}
		static Result<void> ModuleVersionInfoInterface_RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) { return S::Implementation::RegisterIntern(uniqueId, moduleInfo, info); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ModuleVersionInfoInterface::RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) -> Result<void>
{
	return Hxx2::StaticMTable::_instance.ModuleVersionInfoInterface_RegisterIntern(uniqueId, moduleInfo, info);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ModuleVersionInfoInterface::Hxx1::ConstFn<S>::Register(const Id& uniqueId, const DataDictionary& moduleInfo) -> Result<void>
{
	return (ModuleVersionInfoInterface::Register(uniqueId, moduleInfo));
}
auto ModuleVersionInfoInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ModuleVersionInfoInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_moduleversioninfo)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ModuleVersionInfoInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ModuleVersionInfoInterface() { new (s_ui_maxon_ModuleVersionInfoInterface) maxon::EntityUse(ModuleVersionInfoInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ModuleVersionInfoInterface(ModuleVersionInfoInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_moduleversioninfo)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_ModuleVersionInfoInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_ModuleVersionInfoInterface() { new (s_usi_maxon_ModuleVersionInfoInterface) maxon::EntityUse(ModuleVersionInfoInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_ModuleVersionInfoInterface(ModuleVersionInfoInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

