#if 1
class UnregisteredDataTypeError;

struct UnregisteredDataTypeErrorInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, UnregisteredDataTypeErrorInterface>::value || ErrorInterface::HasBaseDetector::template Check<I>::value; static I* Cast(UnregisteredDataTypeErrorInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct UnregisteredDataTypeErrorObject_PrivateHelper;
struct UnregisteredDataTypeErrorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ErrObj = UnregisteredDataTypeErrorObject_PrivateHelper;
	using ReferenceClass = UnregisteredDataTypeError;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ErrorInterface>;
	/// Intermediate helper class for UnregisteredDataTypeErrorInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = UnregisteredDataTypeErrorInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(UnregisteredDataTypeErrorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() const { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, UnregisteredDataTypeError, false>::type&() { return reinterpret_cast<const UnregisteredDataTypeError&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ErrorInterface::Hxx1::template FnHelper<ST>::type>,
	typename ErrorInterface::Hxx1::template FnHelper<ST>::type
	> { };
};
class UnregisteredDataTypeErrorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<UnregisteredDataTypeError>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnregisteredDataTypeErrorInterface, maxon::StrongCOWRefHandler, UnregisteredDataTypeError>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnregisteredDataTypeErrorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnregisteredDataTypeErrorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// UnregisteredDataTypeError is the reference class of UnregisteredDataTypeErrorInterface.
///
/// An UnregisteredDataTypeError is returned by GetDataType<T>() when there is no data type
/// registration for T (or a part of T as in Block<X>).
class UnregisteredDataTypeError : public UnregisteredDataTypeErrorInterface::Hxx1::Reference
{
public:
	friend class UnregisteredDataTypeErrorObject;
	friend class maxon::ResultBase<UnregisteredDataTypeError>;
	UnregisteredDataTypeError(maxon::ERROR_OK) { }
	PRIVATE_MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(UnregisteredDataTypeError, typename UnregisteredDataTypeErrorInterface::Hxx1::Reference);
	template <typename D> UnregisteredDataTypeError(const D& allocLocation, typename D::SourceLocationMarker* dummy = nullptr) { maxon::SFINAEHelper<UnregisteredDataTypeError, D>::type::Create(MAXON_SOURCE_LOCATION_FORWARD); }
	template <typename ARG1, typename... ARGS> UnregisteredDataTypeError(MAXON_SOURCE_LOCATION_DECLARATION, ARG1&& arg1, ARGS&&... args) { maxon::SFINAEHelper<UnregisteredDataTypeError, ARG1>::type::Create(MAXON_SOURCE_LOCATION_FORWARD, std::forward<ARG1>(arg1), std::forward<ARGS>(args)...); }
private:
	UnregisteredDataTypeError() = default;
};

MAXON_DECLARATION(UnregisteredDataTypeError, UnregisteredDataTypeErrorObject, "net.maxon.error.unregistereddatatype");
#ifdef MAXON_COMPILER_INTEL
#else
#endif
constexpr inline const maxon::Char* DT_Char_CppName() { return "maxon::Char"; }
constexpr inline const maxon::Char* DT_UChar_CppName() { return "maxon::UChar"; }
constexpr inline const maxon::Char* DT_Int16_CppName() { return "maxon::Int16"; }
constexpr inline const maxon::Char* DT_UInt16_CppName() { return "maxon::UInt16"; }
constexpr inline const maxon::Char* DT_Int32_CppName() { return "maxon::Int32"; }
constexpr inline const maxon::Char* DT_UInt32_CppName() { return "maxon::UInt32"; }
constexpr inline const maxon::Char* DT_Int64_CppName() { return "maxon::Int64"; }
constexpr inline const maxon::Char* DT_UInt64_CppName() { return "maxon::UInt64"; }
constexpr inline const maxon::Char* DT_Utf16Char_CppName() { return "maxon::Utf16Char"; }
constexpr inline const maxon::Char* DT_Utf32Char_CppName() { return "maxon::Utf32Char"; }
constexpr inline const maxon::Char* DT_Float32_CppName() { return "maxon::Float32"; }
constexpr inline const maxon::Char* DT_Float64_CppName() { return "maxon::Float64"; }
constexpr inline const maxon::Char* DT_Bool_CppName() { return "maxon::Bool"; }
constexpr inline const maxon::Char* DT_Byte_CppName() { return "maxon::Byte"; }
constexpr inline const maxon::Char* DT_AInt_CppName() { return "maxon::Int"; }
constexpr inline const maxon::Char* DT_AUInt_CppName() { return "maxon::UInt"; }
constexpr inline const maxon::Char* DT_AFloat_CppName() { return "maxon::Float"; }
constexpr inline const maxon::Char* DT_UniqueHash_CppName() { return "maxon::UniqueHash"; }
constexpr inline const maxon::Char* DT_Id_CppName() { return "maxon::Id"; }
constexpr inline const maxon::Char* DT_LiteralId_CppName() { return "maxon::LiteralId"; }
constexpr inline const maxon::Char* DT_InternedId_CppName() { return "maxon::InternedId"; }
constexpr inline const maxon::Char* DT_Data_CppName() { return "maxon::Data"; }
constexpr inline const maxon::Char* DT_UnitType_CppName() { return "maxon::UnitType"; }
constexpr inline const maxon::Char* DT_SourceLocation_CppName() { return "maxon::SourceLocation"; }
constexpr inline const maxon::Char* DT_DelegateBase_CppName() { return "maxon::DelegateBase"; }
constexpr inline const maxon::Char* DT_ConstDataPtr_CppName() { return "maxon::ConstDataPtr"; }
constexpr inline const maxon::Char* DT_TrivialDataPtr_CppName() { return "maxon::TrivialDataPtr"; }
constexpr inline const maxon::Char* DT_DataPtr_CppName() { return "maxon::DataPtr"; }
constexpr inline const maxon::Char* DT_MoveDataPtr_CppName() { return "maxon::MoveDataPtr"; }
constexpr inline const maxon::Char* DT_ForwardingDataPtr_CppName() { return "maxon::ForwardingDataPtr"; }
constexpr inline const maxon::Char* DT_Member_CppName() { return "maxon::Member"; }
#endif
