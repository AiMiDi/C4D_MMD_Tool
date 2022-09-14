#if 1
class SettingsRef;

struct SettingsInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, SettingsInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(SettingsInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct SettingsInterface::Hxx1
{
	class Reference;
	using ReferenceClass = SettingsRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(SettingsInterface**);
		using RESTRICT_DICTIONARY_PROPS = SettingsInterface::RESTRICT_DICTIONARY_PROPS;
/// GetAccessLevel returns the current level of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ACCESSLEVEL>, ACCESSLEVEL>::type GetAccessLevel() const;
/// GetParentSettings returns the SettingsRef from which settings are inherited.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<SettingsRef>, SettingsRef>::type GetParentSettings() const;
/// GetSettingsCopy returns a copy of all settings starting at the given level.
/// @param[in] optionalList				Optional list of ids of interest. If empty, everything is returned.
/// @param[in] accessLevel				Unused (for future extensions).
/// @return                       OK on success.
		inline Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL) const;
/// GetSettings returns all settings on the current access level (see order above ACCESSLEVEL).
/// The settings contain all inherited settings from lower levels.
/// @param[in] accessLevel				ACCESSLEVEL to ask for.
/// @return                       SettingsRef on success.
		static inline SettingsRef GetSettings(ACCESSLEVEL accessLevel = ACCESSLEVEL::ALL);
		static inline maxon::ObservableRef<ObservableSettingsChangedDelegate> ObservableSettingsChanged();
	};
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(SettingsInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SettingsRef, true>::type&() const { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, SettingsRef, false>::type&() { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for SettingsInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(SettingsInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, SettingsRef, false>::type&() { return reinterpret_cast<const SettingsRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class SettingsInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<SettingsRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SettingsInterface, maxon::StrongRefHandler, SettingsRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<SettingsInterface, maxon::StrongRefHandler, SettingsRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// SettingsRef is the reference class of SettingsInterface.
///
/// Settings interface to store and load settings like preferences.
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
