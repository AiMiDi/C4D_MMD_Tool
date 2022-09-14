#if 1
namespace DESCRIPTION
{
#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace UI
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI
	#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI
		class RESTRICT : public DESCRIPTION::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
		namespace BASE
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_BASE
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_BASE
			class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
			namespace ADDMINMAX
			{
			#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_BASE_ADDMINMAX
			#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_BASE_ADDMINMAX
				class RESTRICT : public BASE::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
			#endif
			}
		}
		namespace INFO
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_INFO
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_INFO
			class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
		}
		namespace NET
		{
		#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET
		#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET
			class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
		#endif
			namespace MAXON
			{
			#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON
			#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON
				class RESTRICT : public NET::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
			#endif
				namespace UI
				{
				#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI
				#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI
					class RESTRICT : public MAXON::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
				#endif
					namespace NUMBER
					{
					#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_NUMBER
					#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_NUMBER
						class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
					#endif
					}
					namespace STRING
					{
					#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_STRING
					#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_STRING
						class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
					#endif
					}
					namespace URL
					{
					#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_URL
					#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_URL
						class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
					#endif
					}
					namespace VARIADICPORT
					{
					#ifndef PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_VARIADICPORT
					#define PRIVATE_MAXON_GUARD_maxon_DESCRIPTION_UI_NET_MAXON_UI_VARIADICPORT
						class RESTRICT : public UI::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
					#endif
					}
				}
			}
		}
	}
}
class DataDescriptionUI;

struct DataDescriptionUIInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionUIInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataDescriptionUIInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataDescriptionUIInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDescriptionUI;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDescriptionUIInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DataDescriptionUIInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionUI, false>::type&() const { return reinterpret_cast<const DataDescriptionUI&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionUI, false>::type&() { return reinterpret_cast<const DataDescriptionUI&>(this->GetBaseRef()); }
/// Evaluates a condition for a given uiEntry.
/// @markDeprecated Not used anymore, switch to other EvaluateCondition functions.
/// @param[in] condition					Condition string to evaluate.
/// @param[in] description				Description to use.
/// @param[in] uiEntries					UI entries.
/// @param[in] getDataCallback		Callback to get data for the evaluation.
/// @param[in] externalVariables	External variables for the FormulaParser.
/// @return												True if the condition matches. False if not.
		[[deprecated("Use other EvaluateCondition")]] static inline Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const BaseArray<DataDictionary>& uiEntries, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
/// BuildPopupMenuForDescription description.
/// @param[in] description				Description to use.
/// @param[in] externalVariables	External variables for the FormulaParser.
/// @param[in] contextVars				HashMap with variables to execute and evaluate the menu checks for each context that should be used.
/// @param[out] mainMenuEntries		Value Receiver which receives the created menu entries.
/// @return												OK on success.
		static inline Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries);
/// Evaluates a condition within a given description.
/// @see EvaluateCondition, will use a default GetDescEntriesCallbackType callback to read from #description.
		static inline Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
/// Evaluates a condition within a given description. The GetDescEntriesCallbackType allows to provided altered DataDictionary
/// for requested attributes if desired.
/// @param[in] condition					Condition string to evaluate.
/// @param[in] description				Description to use.
/// @param[in] getDescCallback		Callback to get "data"/"gui" description entries related to the condition to evaluate.
///																Also can modify the id given to #getDataCallback;
/// @param[in] getDataCallback		Callback to get data for the evaluation.
/// @param[in] externalVariables	External variables for the FormulaParser.
/// @return												True if the condition matches. False if not.
		static inline Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
/// Split a condition into tokens. Called from EvaluateCondition. Token will be replaced by their value
/// for the FormulaParser.
/// @see EvaluateCondition.
/// @param[in] tokenRecv					Receiver for the tokens.
/// @return												The final (replaced) token list.
		static inline Result<BaseArray<CString>> TokenizeCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const ValueReceiver<const ConditionToken&>& tokenRecv = ValueReceiver<const ConditionToken&>{});
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class DataDescriptionUIInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<DataDescriptionUI>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DataDescriptionUIInterface, maxon::StrongRefHandler, DataDescriptionUI>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DataDescriptionUIInterface, maxon::StrongRefHandler, DataDescriptionUI>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DataDescriptionUIInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionUIInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionUIInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DataDescriptionUI is the reference class of DataDescriptionUIInterface.
///
/// This interface provides helper functions for ui stuff in combination with descriptions.
class DataDescriptionUI : public DataDescriptionUIInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescriptionUI, typename DataDescriptionUIInterface::Hxx1::Reference);
};

#endif
