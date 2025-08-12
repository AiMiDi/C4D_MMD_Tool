#if 1
namespace maxon
{
	namespace enum380
	{
		enum class CONDITIONTOKENTYPE
		{
			NONE = 0,
			ATTRIBUTEID,						/// Identifier for which DataDescriptionDefinitionInterface::GetDataValueOrDefaults will be called.
			DYN_ATTRIBUTEID,				/// Same as ATTRIBUTEID but the attribute is animated, this makes the whole condition bypassed as true.
			VARIABLE,								/// External variable, see DataDescriptionDefinitionInterface::EvaluateCondition.
			CONSTANT,								/// Constant value for comparison.
			FUNCTION,								/// A function call.
			OPERATOR,								/// Comparison operator, logic operator, this token often contains constants and parenthesis.
			PARENTHESIS,						/// Parenthesis open or close token.
		} ;
		static const maxon::UInt64 CONDITIONTOKENTYPE_values[] = {maxon::UInt64(enum380::CONDITIONTOKENTYPE::NONE), maxon::UInt64(enum380::CONDITIONTOKENTYPE::ATTRIBUTEID), maxon::UInt64(enum380::CONDITIONTOKENTYPE::DYN_ATTRIBUTEID), maxon::UInt64(enum380::CONDITIONTOKENTYPE::VARIABLE), maxon::UInt64(enum380::CONDITIONTOKENTYPE::CONSTANT), maxon::UInt64(enum380::CONDITIONTOKENTYPE::FUNCTION), maxon::UInt64(enum380::CONDITIONTOKENTYPE::OPERATOR), maxon::UInt64(enum380::CONDITIONTOKENTYPE::PARENTHESIS)};
		static const maxon::EnumInfo CONDITIONTOKENTYPE_info{"CONDITIONTOKENTYPE", SIZEOF(CONDITIONTOKENTYPE), false, "NONE\0ATTRIBUTEID\0DYN_ATTRIBUTEID\0VARIABLE\0CONSTANT\0FUNCTION\0OPERATOR\0PARENTHESIS\0", CONDITIONTOKENTYPE_values, std::extent<decltype(CONDITIONTOKENTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONDITIONTOKENTYPE380(){ return enum380::CONDITIONTOKENTYPE_info; }
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionUIInterface::Hxx2::Unresolved : public DataDescriptionUIInterface
	{
	public:
		static Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::BuildPopupMenuForDescription(description, externalVariables, contextVars, mainMenuEntries); return HXXRET1(UNRESOLVED);}
		static Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::EvaluateCondition(condition, description, getDataCallback, externalVariables); return HXXRET1(UNRESOLVED);}
		static Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::EvaluateCondition(condition, description, getDescCallback, getDataCallback, externalVariables); return HXXRET1(UNRESOLVED);}
		static Result<BaseArray<CString>> TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::TokenizeCondition(condition, description, getDescCallback, getDataCallback, tokenRecv); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE DataDescriptionUIInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<Bool>>::value,
		maxon::details::UnresolvedReturnType<Result<Bool>>::value,
		maxon::details::UnresolvedReturnType<Result<BaseArray<CString>>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionUIInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_BuildPopupMenuForDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_BuildPopupMenuForDescription), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_BuildPopupMenuForDescription);
		#else
		tbl->DataDescriptionUIInterface_BuildPopupMenuForDescription = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_BuildPopupMenuForDescription), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_BuildPopupMenuForDescription);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_EvaluateCondition = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_EvaluateCondition), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition);
		#else
		tbl->DataDescriptionUIInterface_EvaluateCondition = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_EvaluateCondition), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_EvaluateCondition_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_EvaluateCondition_1), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition_1);
		#else
		tbl->DataDescriptionUIInterface_EvaluateCondition_1 = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_EvaluateCondition_1), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<CString>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_TokenizeCondition = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_TokenizeCondition), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_TokenizeCondition);
		#else
		tbl->DataDescriptionUIInterface_TokenizeCondition = PRIVATE_MAXON_MF_CAST(decltype(DataDescriptionUIInterface_TokenizeCondition), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_TokenizeCondition);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (const void**) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataDescriptionUIInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DataDescriptionUIInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionUIInterface, , "net.maxon.interface.datadescriptionui", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataDescriptionUIInterface::Hxx2::StaticMTable::_ids = 
		"BuildPopupMenuForDescription@72503cbb3e02ee4c\0" // Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries)
		"EvaluateCondition@163a27a4e5ac1671\0" // Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables)
		"EvaluateCondition@b5d3423ab395bfb6\0" // Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables)
		"TokenizeCondition@8454089b835016eb\0" // Result<BaseArray<CString>> TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataDescriptionUIInterface, , "net.maxon.interface.datadescriptionui");
}
#endif
