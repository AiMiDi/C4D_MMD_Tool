#if 1
namespace maxon
{
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ModuleVersionInfoInterface::Hxx2::Unresolved : public ModuleVersionInfoInterface
	{
	public:
		static Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return ModuleVersionInfoInterface::RegisterIntern(uniqueId, moduleInfo, info); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ModuleVersionInfoInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ModuleVersionInfoInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ModuleVersionInfoInterface_RegisterIntern = PRIVATE_MAXON_MF_CAST(decltype(ModuleVersionInfoInterface_RegisterIntern), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ModuleVersionInfoInterface_RegisterIntern);
		#else
		tbl->ModuleVersionInfoInterface_RegisterIntern = PRIVATE_MAXON_MF_CAST(decltype(ModuleVersionInfoInterface_RegisterIntern), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::ModuleVersionInfoInterface_RegisterIntern);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (const void**) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const ModuleVersionInfoInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS ModuleVersionInfoInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ModuleVersionInfoInterface, , "net.maxon.interface.moduleversioninfo", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const ModuleVersionInfoInterface::Hxx2::StaticMTable::_ids = 
		"RegisterIntern@4491f53baffec0d6\0" // Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(ModuleVersionInfoInterface, , "net.maxon.interface.moduleversioninfo");
	MAXON_REGISTRY_REGISTER(ModuleVersionInfos);
	MAXON_REGISTRY_REGISTER(ReplaceModule);
}
#endif
