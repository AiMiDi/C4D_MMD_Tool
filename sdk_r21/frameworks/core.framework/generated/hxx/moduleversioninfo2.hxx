
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
	struct MODULENAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x54c4a1b107931f87LL), maxon::UInt(38))> { };
	struct DESCRIPTION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x43b47a21ca73016cLL), maxon::UInt(39))> { };
	struct VERSIONNUMBERSTRING_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf10cd071429e86e2LL), maxon::UInt(47))> { };
	struct VERSIONDATE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x43e8e3ce5a575df6LL), maxon::UInt(39))> { };
	struct COPYRIGHT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x8f1f163e2b238d37LL), maxon::UInt(37))> { };
	struct LICENSE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x0358793cc0e639b1LL), maxon::UInt(35))> { };
	struct USEDINMODULE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3900d122bfa8931eLL), maxon::UInt(40))> { };
}

struct ModuleVersionInfoInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ModuleVersionInfoInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ModuleVersionInfoInterface);
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
	Result<void> (*_ModuleVersionInfoInterface_RegisterIntern) (const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_ModuleVersionInfoInterface_RegisterIntern = &IMPL::_ModuleVersionInfoInterface_RegisterIntern;
		}
	};
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
	static Result<void> _ModuleVersionInfoInterface_RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) { return S::Implementation::RegisterIntern(uniqueId, moduleInfo, info); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ModuleVersionInfoInterface::RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) -> Result<void>
{
	return Hxx2::StaticMTable::_instance._ModuleVersionInfoInterface_RegisterIntern(uniqueId, moduleInfo, info);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ModuleVersionInfoInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Register(const Id& uniqueId, const DataDictionary& moduleInfo) -> Result<void> { return (ModuleVersionInfoInterface::Register(uniqueId, moduleInfo)); }
auto ModuleVersionInfoInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ModuleVersionInfoInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ModuleVersionInfoInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ModuleVersionInfoInterface() { new (s_ui_maxon_ModuleVersionInfoInterface) maxon::EntityUse(ModuleVersionInfoInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ModuleVersionInfoInterface(ModuleVersionInfoInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/moduleversioninfo.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

