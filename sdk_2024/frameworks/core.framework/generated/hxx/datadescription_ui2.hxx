
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace DESCRIPTION
{
	namespace UI
	{
		namespace BASE
		{
			namespace ADDMINMAX
			{
			}
		}
		namespace INFO
		{
		}
		namespace NET
		{
			namespace MAXON
			{
				namespace UI
				{
					namespace DATA
					{
					}
					namespace NUMBER
					{
					}
					namespace STRING
					{
					}
					namespace URL
					{
					}
					namespace VARIADICPORT
					{
					}
				}
			}
		}
	}
}

struct DataDescriptionUIInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataDescriptionUIInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDescriptionUIInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDescriptionUIInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	PRIVATE_MAXON_SF_POINTER(DataDescriptionUIInterface_BuildPopupMenuForDescription, BuildPopupMenuForDescription, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionUIInterface_EvaluateCondition, EvaluateCondition, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionUIInterface_EvaluateCondition_1, EvaluateCondition, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
	PRIVATE_MAXON_SF_POINTER(DataDescriptionUIInterface_TokenizeCondition, TokenizeCondition, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<CString>>), const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->DataDescriptionUIInterface_BuildPopupMenuForDescription = DataDescriptionUIInterface_BuildPopupMenuForDescription_GetPtr<IMPL>(true);
		tbl->DataDescriptionUIInterface_EvaluateCondition = DataDescriptionUIInterface_EvaluateCondition_GetPtr<IMPL>(true);
		tbl->DataDescriptionUIInterface_EvaluateCondition_1 = DataDescriptionUIInterface_EvaluateCondition_1_GetPtr<IMPL>(true);
		tbl->DataDescriptionUIInterface_TokenizeCondition = DataDescriptionUIInterface_TokenizeCondition_GetPtr<IMPL>(true);
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
			auto* vt = (DataDescriptionUIInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDescriptionUIInterface::_interface); if (!vt) return false;
			return true;
		}
		static Result<void> DataDescriptionUIInterface_BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries) { return S::Implementation::BuildPopupMenuForDescription(description, externalVariables, contextVars, mainMenuEntries); }
		static Result<Bool> DataDescriptionUIInterface_EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { return S::Implementation::EvaluateCondition(condition, description, getDataCallback, externalVariables); }
		static Result<Bool> DataDescriptionUIInterface_EvaluateCondition_1(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { return S::Implementation::EvaluateCondition(condition, description, getDescCallback, getDataCallback, externalVariables); }
		static Result<BaseArray<CString>> DataDescriptionUIInterface_TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv) { return S::Implementation::TokenizeCondition(condition, description, getDescCallback, getDataCallback, tokenRecv); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries) -> Result<void>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_BuildPopupMenuForDescription(description, externalVariables, contextVars, mainMenuEntries);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) -> Result<Bool>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_EvaluateCondition(condition, description, getDataCallback, externalVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) -> Result<Bool>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_EvaluateCondition_1(condition, description, getDescCallback, getDataCallback, externalVariables);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv) -> Result<BaseArray<CString>>
{
	return Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_TokenizeCondition(condition, description, getDescCallback, getDataCallback, tokenRecv);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::Hxx1::ConstFn<S>::BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries) -> Result<void>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_BuildPopupMenuForDescription(description, externalVariables, contextVars, mainMenuEntries));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::Hxx1::ConstFn<S>::EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) -> Result<Bool>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_EvaluateCondition(condition, description, getDataCallback, externalVariables));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::Hxx1::ConstFn<S>::EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) -> Result<Bool>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_EvaluateCondition_1(condition, description, getDescCallback, getDataCallback, externalVariables));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDescriptionUIInterface::Hxx1::ConstFn<S>::TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv) -> Result<BaseArray<CString>>
{
	return (Hxx2::StaticMTable::_instance.DataDescriptionUIInterface_TokenizeCondition(condition, description, getDescCallback, getDataCallback, tokenRecv));
}
auto DataDescriptionUIInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDescriptionUIInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescription_ui)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDescriptionUIInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDescriptionUIInterface() { new (s_ui_maxon_DataDescriptionUIInterface) maxon::EntityUse(DataDescriptionUIInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription_ui.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDescriptionUIInterface(DataDescriptionUIInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription_ui.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadescription_ui)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DataDescriptionUIInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DataDescriptionUIInterface() { new (s_usi_maxon_DataDescriptionUIInterface) maxon::EntityUse(DataDescriptionUIInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription_ui.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DataDescriptionUIInterface(DataDescriptionUIInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datadescription_ui.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

