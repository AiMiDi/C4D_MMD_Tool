#if 1
#ifdef __API_INTERN__
#endif
class DescriptionMessageCallbackRef;

struct DescriptionMessageCallbackInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DescriptionMessageCallbackInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DescriptionMessageCallbackInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DescriptionMessageCallbackInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DescriptionMessageCallbackRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DescriptionMessageCallbackInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DescriptionMessageCallbackInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DescriptionMessageCallbackInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionMessageCallbackRef, true>::type&() const { return reinterpret_cast<const DescriptionMessageCallbackRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DescriptionMessageCallbackRef, false>::type&() { return reinterpret_cast<const DescriptionMessageCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement DescriptionMessageCallbackInterface.
/// It allows receiving commands callbacks from the attribute manager emulation code.
/// @param[in] id									The object's id.
/// @param[in] cmdId							The command's id.
/// @param[in] type								Message type.
/// @param[in] data								The legacy message data.
/// @return												Tuple<Bool HANDLED, Bool RES_VALUE_IF_HANDLED>.
		inline Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) const;
	};
	/// Intermediate helper class for DescriptionMessageCallbackInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DescriptionMessageCallbackInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DescriptionMessageCallbackInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DescriptionMessageCallbackRef, false>::type&() { return reinterpret_cast<const DescriptionMessageCallbackRef&>(this->GetBaseRef()); }
/// Callback function called by a C4dCoreWrapperObject on references that implement DescriptionMessageCallbackInterface.
/// It allows receiving commands callbacks from the attribute manager emulation code.
/// @param[in] id									The object's id.
/// @param[in] cmdId							The command's id.
/// @param[in] type								Message type.
/// @param[in] data								The legacy message data.
/// @return												Tuple<Bool HANDLED, Bool RES_VALUE_IF_HANDLED>.
		inline Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ObjectInterface::Hxx1::template FnHelper<ST>::type, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DescriptionMessageCallbackInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DescriptionMessageCallbackRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DescriptionMessageCallbackInterface, maxon::StrongRefHandler, DescriptionMessageCallbackRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DescriptionMessageCallbackInterface, maxon::StrongRefHandler, DescriptionMessageCallbackRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DescriptionMessageCallbackRef is the reference class of DescriptionMessageCallbackInterface.
///
/// Implement this interface to receive the AMEmulator DescriptionMessageCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
class DescriptionMessageCallbackRef : public DescriptionMessageCallbackInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DescriptionMessageCallbackRef, typename DescriptionMessageCallbackInterface::Hxx1::Reference);
	using ConstPtr = typename DescriptionMessageCallbackInterface::ConstPtr;
};

#ifdef __API_INTERN__
#endif
#endif
