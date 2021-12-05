#if 1
class DataFormatReaderRef;

struct DataFormatReaderInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatReaderInterface>::value || DataFormatBaseReaderInterface::HasBase::template Check<I>::value || DataSerializeReaderInterface::HasBase::template Check<I>::value; static I* Cast(DataFormatReaderInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataFormatReaderInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatReaderRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataFormatBaseReaderInterface, DataSerializeReaderInterface>;
	/// Intermediate helper class for DataFormatReaderInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DataFormatReaderInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, true>::type&() const { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataFormatReaderInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeReaderInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseReaderInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeReaderInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseReaderInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename DataSerializeReaderInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseReaderInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class DataFormatReaderInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatReaderRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataFormatReaderRef is the reference class of DataFormatReaderInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatReaderRef : public DataFormatReaderInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatReaderRef, typename DataFormatReaderInterface::Hxx1::Reference);
};

class DataFormatWriterRef;

struct DataFormatWriterInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatWriterInterface>::value || DataFormatBaseWriterInterface::HasBase::template Check<I>::value || DataSerializeWriterInterface::HasBase::template Check<I>::value; static I* Cast(DataFormatWriterInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataFormatWriterInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatWriterRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataFormatBaseWriterInterface, DataSerializeWriterInterface>;
	/// Intermediate helper class for DataFormatWriterInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DataFormatWriterInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, true>::type&() const { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataFormatWriterInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeWriterInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseWriterInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeWriterInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseWriterInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>, ReferenceFunctionsImpl<typename DataSerializeWriterInterface::Hxx1::template ReferenceFunctionsHelper<typename DataFormatBaseWriterInterface::Hxx1::template ReferenceFunctionsHelper<ST>>::type>>::type> { };
};
class DataFormatWriterInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatWriterRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataFormatWriterRef is the reference class of DataFormatWriterInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatWriterRef : public DataFormatWriterInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatWriterRef, typename DataFormatWriterInterface::Hxx1::Reference);
};

#endif
