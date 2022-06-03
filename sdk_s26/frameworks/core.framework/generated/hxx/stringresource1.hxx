#if 1
class LanguageRef;

struct LanguageInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LanguageRef;
	/// Intermediate helper class for LanguageInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(LanguageInterface**);
/// Returns the real (country-specific) name of a language.
/// @return												The name.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetName() const;
/// Returns the identifier of a language.
/// @return												The name.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetIdentifier() const;
/// Returns the fallback language of this language.
/// @return												Nullptr if the language has no fallback language (e.g. "en-US" has none because it's the root of all languages).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<LanguageRef>, LanguageRef>::type GetFallbackLanguage() const;
/// @copydoc DefaultDoc::ToString
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const maxon::FormatStatement* fs = nullptr) const;
	};
	/// Intermediate helper class for LanguageInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(LanguageInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LanguageRef, true>::type&() const { return reinterpret_cast<const LanguageRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LanguageRef, false>::type&() { return reinterpret_cast<const LanguageRef&>(this->GetBaseRef()); }
/// Loads a string from the resource.
/// @param[in] scope							The resource scope of a resource symbol.
/// @param[in] keyValue						The value of a resource symbol.
/// @return												String.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type LoadResourceString(const Id& scope, const InternedId& keyValue) const;
	};
	/// Intermediate helper class for LanguageInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(LanguageInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LanguageRef, false>::type&() { return reinterpret_cast<const LanguageRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class LanguageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<LanguageRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LanguageInterface, maxon::StrongRefHandler, LanguageRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LanguageInterface, maxon::StrongRefHandler, LanguageRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// Allocator for common use.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LanguageRef> Create();
};

/// LanguageRef is the reference class of LanguageInterface.
///
/// Class that handles string resources.
class LanguageRef : public LanguageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LanguageRef, typename LanguageInterface::Hxx1::Reference);
	using ConstPtr = typename LanguageInterface::ConstPtr;
};

class Resource::ObservableLanguageChangedDelegate : public maxon::Delegate<void(const LanguageRef&,const LanguageRef&)>
{
public:
	using Super = maxon::Delegate<void(const LanguageRef&,const LanguageRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleLanguageChanged);
	ObservableLanguageChangedDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleLanguageChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleLanguageChanged); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleLanguageChanged<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
