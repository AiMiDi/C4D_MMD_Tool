#if 1
namespace maxon
{
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionObjectInterface::Hxx2::Unresolved : public DataDescriptionObjectInterface
	{
	public:
		static Result<String> GetObjectName(const Id& classId, const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionObjectInterface::GetObjectName(classId, language); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE DataDescriptionObjectInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<String>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionObjectInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<String>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionObjectInterface_GetObjectName = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionObjectInterface_GetObjectName), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionObjectInterface_GetObjectName);
		#else
		tbl->DataDescriptionObjectInterface_GetObjectName = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionObjectInterface_GetObjectName), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionObjectInterface_GetObjectName);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (const void**) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataDescriptionObjectInterface::MTable::_ids = 
		"GetObjectDescription@abbf2a4c9fb247e6\0" // Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const
	"";
	const maxon::METHOD_FLAGS DataDescriptionObjectInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionObjectInterface, , "net.maxon.interface.datadescriptionobject", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataDescriptionObjectInterface::Hxx2::StaticMTable::_ids = 
		"GetObjectName@934323b297984277\0" // Result<String> GetObjectName(const Id& classId, const LanguageRef& language)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataDescriptionObjectInterface, , "net.maxon.interface.datadescriptionobject");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataDescriptionObjectClass, , "net.maxon.class.datadescriptionobject");
}
#endif
