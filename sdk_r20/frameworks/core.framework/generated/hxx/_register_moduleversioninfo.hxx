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
	class ModuleVersionInfoInterface::Unresolved : public ModuleVersionInfoInterface
	{
	public:
		static Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ModuleVersionInfoInterface::RegisterIntern(uniqueId, moduleInfo, info); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ModuleVersionInfoInterface::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ModuleVersionInfoInterface::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_ModuleVersionInfoInterface_RegisterIntern = &Wrapper<maxon::StaticHelper<Unresolved>>::_ModuleVersionInfoInterface_RegisterIntern;
	#else
		tbl->_ModuleVersionInfoInterface_RegisterIntern = &Wrapper<maxon::StaticHelper<Unresolved>>::_ModuleVersionInfoInterface_RegisterIntern;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ModuleVersionInfoInterface, "net.maxon.interface.moduleversioninfo", "maxon.ModuleVersionInfoInterface", , &Object::_interface);
	const maxon::Char* const ModuleVersionInfoInterface::MTable::_ids = 
	"";
	const maxon::Char* const ModuleVersionInfoInterface::StaticMTable::_ids = 
		"RegisterIntern@a8969be59e7438cd\0" // RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info)
	"";
	MAXON_INTERFACE_REGISTER_STATIC(ModuleVersionInfoInterface, "net.maxon.interface.moduleversioninfo");
	template <typename DUMMY> maxon::Int ModuleVersionInfoInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_REGISTRY_REGISTER(ModuleVersionInfos);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_moduleversioninfo(0
	| maxon::ModuleVersionInfoInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
