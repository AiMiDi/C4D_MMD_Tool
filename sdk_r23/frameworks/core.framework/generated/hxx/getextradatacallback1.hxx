#if 1
#ifdef __API_INTERN__
#endif
class GetExtraDataCallbackRef;

struct GetExtraDataCallbackInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, GetExtraDataCallbackInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(GetExtraDataCallbackInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct GetExtraDataCallbackInterface::Hxx1
{
	class Reference;
	using ReferenceClass = GetExtraDataCallbackRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for GetExtraDataCallbackInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for GetExtraDataCallbackInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GetExtraDataCallbackRef, true>::type&() const { return reinterpret_cast<const GetExtraDataCallbackRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GetExtraDataCallbackRef, false>::type&() { return reinterpret_cast<const GetExtraDataCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement GetExtraDataCallbackInterface.
/// It allows processing extra data requests like ToUuidMessage or ToObjectMessage.
/// @param[in] cmdId							The extra data request command.
/// @return												OK on success.
		inline Result<DelegateBase> GetExtraDataMessage(const Id& cmdId) const;
	};
	/// Intermediate helper class for GetExtraDataCallbackInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, GetExtraDataCallbackRef, false>::type&() { return reinterpret_cast<const GetExtraDataCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement GetExtraDataCallbackInterface.
/// It allows processing extra data requests like ToUuidMessage or ToObjectMessage.
/// @param[in] cmdId							The extra data request command.
/// @return												OK on success.
		inline Result<DelegateBase> GetExtraDataMessage(const Id& cmdId);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class GetExtraDataCallbackInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<GetExtraDataCallbackRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GetExtraDataCallbackInterface, maxon::StrongRefHandler, GetExtraDataCallbackRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<GetExtraDataCallbackInterface, maxon::StrongRefHandler, GetExtraDataCallbackRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// GetExtraDataCallbackRef is the reference class of GetExtraDataCallbackInterface.
///
/// Implement this interface to receive the AMEmulator GetExtraDataCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
class GetExtraDataCallbackRef : public GetExtraDataCallbackInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GetExtraDataCallbackRef, typename GetExtraDataCallbackInterface::Hxx1::Reference);
	using ConstPtr = typename GetExtraDataCallbackInterface::ConstPtr;
};

#ifdef __API_INTERN__
#endif
#endif
