#if 1
class DataTypeBuilderRef;

struct DataTypeBuilderInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataTypeBuilderInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataTypeBuilderInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataTypeBuilderInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataTypeBuilderRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category);
		static inline Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components);
	};
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataTypeBuilderRef, true>::type&() const { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataTypeBuilderRef, false>::type&() { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataTypeBuilderInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataTypeBuilderRef, false>::type&() { return reinterpret_cast<const DataTypeBuilderRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class DataTypeBuilderInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataTypeBuilderRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataTypeBuilderInterface, maxon::StrongRefHandler, DataTypeBuilderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataTypeBuilderInterface, maxon::StrongRefHandler, DataTypeBuilderRef>>>>);
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
