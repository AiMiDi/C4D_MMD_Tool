#if 1
namespace maxon
{
	namespace enum20 { enum class DATATYPEBUILDERNAME
	{
		HUMAN_READABLE,
		CODE_CPP,
	} ; }
	maxon::String PrivateToString_DATATYPEBUILDERNAME20(std::underlying_type<enum20::DATATYPEBUILDERNAME>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum20::DATATYPEBUILDERNAME::HUMAN_READABLE, (maxon::UInt64) enum20::DATATYPEBUILDERNAME::CODE_CPP};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DATATYPEBUILDERNAME", SIZEOF(x), false, values, "HUMAN_READABLE\0CODE_CPP\0", fmt);
	}
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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataTypeBuilderInterface, , "net.maxon.datatype.builder", "maxon.DataTypeBuilderInterface", (Object::PrivateGetInterface()));
	const maxon::Char* const DataTypeBuilderInterface::Hxx2::StaticMTable::_ids = 
		"GetDataTypeName@1a2e71fb9981d084\0" // Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category)
		"RecurseDataType@145e170b28ee700c\0" // Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataTypeBuilderInterface, , "net.maxon.datatype.builder");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_DataTypeBuilderEntry,, "net.maxon.datatype.datatypebuilderentry");
	MAXON_REGISTRY_REGISTER(DataTypeBuilderRegistry);
}
#endif
