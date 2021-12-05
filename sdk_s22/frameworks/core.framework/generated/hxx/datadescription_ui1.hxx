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

struct DataDescriptionUIInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionUIInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataDescriptionUIInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataDescriptionUIInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDescriptionUI;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDescriptionUIInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionUI, false>::type&() const { return reinterpret_cast<const DataDescriptionUI&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionUI, false>::type&() { return reinterpret_cast<const DataDescriptionUI&>(this->GetBaseRef()); }
/// Evaluates a condition for a given uiEntry
/// @param[in] condition					Condition string to evaluate.
/// @param[in] description				Description to use.
/// @param[in] uiEntries					UI entries.
/// @param[in] getDataCallback		Callback to get data for the evaluation.
/// @param[in] externalVariables	External variables for the FormulaParser.
/// @return												True if the condition matches. False if not.
		static inline Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const BaseArray<DataDictionary>& uiEntries, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables);
/// BuildPopupMenuForDescription description.
/// @param[in] description				Description to use.
/// @param[in] externalVariables	External variables for the FormulaParser.
/// @param[in] contextVars				HashMap with variables to execute and evaluate the menu checks for each context that should be used.
/// @param[out] mainMenuEntries		Value Receiver which receives the created menu entries.
/// @return												OK on success.
		static inline Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries);
	};
	/// Intermediate helper class for DataDescriptionUIInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DataDescriptionUIInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataDescriptionUIInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<DataDescriptionUI>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionUIInterface, maxon::StrongRefHandler, DataDescriptionUI>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionUIInterface, maxon::StrongRefHandler, DataDescriptionUI>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DataDescriptionUIInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionUIInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionUIInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
