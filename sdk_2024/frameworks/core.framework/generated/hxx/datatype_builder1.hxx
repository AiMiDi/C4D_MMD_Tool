#if 1
class DataTypeBuilderRef;

struct DataTypeBuilderInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataTypeBuilderInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataTypeBuilderInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataTypeBuilderInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataTypeBuilderRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataTypeBuilderInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DataTypeBuilderInterface**);
		static inline Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category);
		static inline Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components);
	};
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataTypeBuilderInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataTypeBuilderInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataTypeBuilderRef, true>::type&() const { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataTypeBuilderRef, false>::type&() { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataTypeBuilderInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataTypeBuilderInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataTypeBuilderRef, false>::type&() { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DataTypeBuilderInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DataTypeBuilderRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataTypeBuilderInterface, maxon::StrongRefHandler, DataTypeBuilderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataTypeBuilderInterface, maxon::StrongRefHandler, DataTypeBuilderRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataTypeBuilderRef is the reference class of DataTypeBuilderInterface.
class DataTypeBuilderRef : public DataTypeBuilderInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataTypeBuilderRef, typename DataTypeBuilderInterface::Hxx1::Reference);
	using ConstPtr = typename DataTypeBuilderInterface::ConstPtr;
};

constexpr inline const maxon::Char* DT_DataTypeBuilderEntry_CppName() { return "maxon::DataTypeBuilderEntry"; }
#endif
