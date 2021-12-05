#if 1
namespace maxon
{
	namespace MODULEVERSIONINFO
	{
		MODULENAME_PrivateAttribute MODULENAME;
		DESCRIPTION_PrivateAttribute DESCRIPTION;
		VERSIONNUMBERSTRING_PrivateAttribute VERSIONNUMBERSTRING;
		VERSIONDATE_PrivateAttribute VERSIONDATE;
		COPYRIGHT_PrivateAttribute COPYRIGHT;
		LICENSE_PrivateAttribute LICENSE;
		USEDINMODULE_PrivateAttribute USEDINMODULE;
	}
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ModuleVersionInfoInterface::Hxx2::Unresolved : public ModuleVersionInfoInterface
	{
	public:
		static Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ModuleVersionInfoInterface::RegisterIntern(uniqueId, moduleInfo, info); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ModuleVersionInfoInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ModuleVersionInfoInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ModuleVersionInfoInterface_RegisterIntern = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ModuleVersionInfoInterface_RegisterIntern;
		#else
		tbl->_ModuleVersionInfoInterface_RegisterIntern = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_ModuleVersionInfoInterface_RegisterIntern;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ModuleVersionInfoInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ModuleVersionInfoInterface, , "net.maxon.interface.moduleversioninfo", "maxon.ModuleVersionInfoInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ModuleVersionInfoInterface::Hxx2::StaticMTable::_ids = 
		"RegisterIntern@4491f53baffec0d6\0" // Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ModuleVersionInfoInterface, , "net.maxon.interface.moduleversioninfo");
	MAXON_REGISTRY_REGISTER(ModuleVersionInfos);
}
#endif
