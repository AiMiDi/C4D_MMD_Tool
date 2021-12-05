#if 1
namespace maxon
{
	namespace enum20
	{
		enum class DATATYPEBUILDERNAME
		{
			HUMAN_READABLE,
			CODE_CPP,
		} ;
		static const maxon::UInt64 DATATYPEBUILDERNAME_values[] = {maxon::UInt64(enum20::DATATYPEBUILDERNAME::HUMAN_READABLE), maxon::UInt64(enum20::DATATYPEBUILDERNAME::CODE_CPP)};
		static const maxon::EnumInfo DATATYPEBUILDERNAME_info{"DATATYPEBUILDERNAME", SIZEOF(DATATYPEBUILDERNAME), false, "HUMAN_READABLE\0CODE_CPP\0", DATATYPEBUILDERNAME_values, std::extent<decltype(DATATYPEBUILDERNAME_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DATATYPEBUILDERNAME20(){ return enum20::DATATYPEBUILDERNAME_info; }
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataTypeBuilderInterface::Hxx2::Unresolved : public DataTypeBuilderInterface
	{
	public:
		static Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataTypeBuilderInterface::GetDataTypeName(dt, category); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataTypeBuilderInterface::RecurseDataType(category, dt, parentTypeId, globalIdentifier, components); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataTypeBuilderInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<Result<Tuple<String, Bool>>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataTypeBuilderInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeBuilderInterface_GetDataTypeName = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataTypeBuilderInterface_GetDataTypeName;
		#else
		tbl->_DataTypeBuilderInterface_GetDataTypeName = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataTypeBuilderInterface_GetDataTypeName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Tuple<String, Bool>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeBuilderInterface_RecurseDataType = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataTypeBuilderInterface_RecurseDataType;
		#else
		tbl->_DataTypeBuilderInterface_RecurseDataType = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DataTypeBuilderInterface_RecurseDataType;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataTypeBuilderInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DataTypeBuilderInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataTypeBuilderInterface, , "net.maxon.datatype.builder", "maxon.DataTypeBuilderInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataTypeBuilderInterface::Hxx2::StaticMTable::_ids = 
		"GetDataTypeName@1a2e71fb9981d084\0" // Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category)
		"RecurseDataType@145e170b28ee700c\0" // Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataTypeBuilderInterface, , "net.maxon.datatype.builder");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_DataTypeBuilderEntry,, "net.maxon.datatype.datatypebuilderentry");
	MAXON_REGISTRY_REGISTER(DataTypeBuilderRegistry);
}
#endif
