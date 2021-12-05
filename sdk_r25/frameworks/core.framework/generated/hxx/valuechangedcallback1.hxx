#if 1
#ifdef __API_INTERN__
#endif
class ValueChangedCallbackRef;

struct ValueChangedCallbackInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ValueChangedCallbackInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ValueChangedCallbackInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ValueChangedCallbackInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ValueChangedCallbackRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for ValueChangedCallbackInterface.
	template <typename S> class ReferenceFunctionsImpl : public S
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ValueChangedCallbackRef, true>::type&() const { return reinterpret_cast<const ValueChangedCallbackRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ValueChangedCallbackRef, false>::type&() { return reinterpret_cast<const ValueChangedCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement ValueChangedCallbackInterface.
/// It allows receiving value changed callbacks from the attribute manager emulation code on DataDictionary content changes.
/// @param[in] id									The changed data's id.
/// @return												OK on success.
		inline Result<void> ValueChangedMessage(const InternedId& id) const;
	};
	/// Intermediate helper class for ValueChangedCallbackInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ValueChangedCallbackRef, false>::type&() { return reinterpret_cast<const ValueChangedCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement ValueChangedCallbackInterface.
/// It allows receiving value changed callbacks from the attribute manager emulation code on DataDictionary content changes.
/// @param[in] id									The changed data's id.
/// @return												OK on success.
		inline Result<void> ValueChangedMessage(const InternedId& id);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class ValueChangedCallbackInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ValueChangedCallbackRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ValueChangedCallbackInterface, maxon::StrongRefHandler, ValueChangedCallbackRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ValueChangedCallbackInterface, maxon::StrongRefHandler, ValueChangedCallbackRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ValueChangedCallbackRef is the reference class of ValueChangedCallbackInterface.
///
/// Implement this interface to receive the AMEmulator ValueChangedCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
class ValueChangedCallbackRef : public ValueChangedCallbackInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ValueChangedCallbackRef, typename ValueChangedCallbackInterface::Hxx1::Reference);
	using ConstPtr = typename ValueChangedCallbackInterface::ConstPtr;
};

#ifdef __API_INTERN__
#endif
#endif
