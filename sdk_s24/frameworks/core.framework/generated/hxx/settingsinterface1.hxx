#if 1
class SettingsRef;

struct SettingsInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SettingsInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(SettingsInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct SettingsInterface::Hxx1
{
	class Reference;
	using ReferenceClass = SettingsRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using RESTRICT_DICTIONARY_PROPS = SettingsInterface::RESTRICT_DICTIONARY_PROPS;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type GetAccessLevel() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type GetParentSettings() const;
		inline Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL) const;
		static inline SettingsRef GetSettings(ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL);
		static inline maxon::ObservableRef<ObservableSettingsChangedDelegate> ObservableSettingsChanged();
	};
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SettingsRef, true>::type&() const { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SettingsRef, false>::type&() { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, SettingsRef, false>::type&() { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class SettingsInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<SettingsRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SettingsInterface, maxon::StrongRefHandler, SettingsRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<SettingsInterface, maxon::StrongRefHandler, SettingsRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// SettingsRef is the reference class of SettingsInterface.
class SettingsRef : public SettingsInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SettingsRef, typename SettingsInterface::Hxx1::Reference);
	using ConstPtr = typename SettingsInterface::ConstPtr;
};

class SettingsInterface::ObservableSettingsChangedDelegate : public maxon::Delegate<void(const ACCESSLEVEL&,const HashSet<Id>&)>
{
public:
	using Super = maxon::Delegate<void(const ACCESSLEVEL&,const HashSet<Id>&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleSettingsChanged);
	ObservableSettingsChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleSettingsChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleSettingsChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleSettingsChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
