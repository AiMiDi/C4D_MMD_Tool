#if 1
struct DataFormatReaderInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatReaderInterface>::value || DataFormatBaseReaderInterface::HasBase::Check<I>::value || DataSerializeReaderInterface::HasBase::Check<I>::value; static I* Cast(DataFormatReaderInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataFormatReaderRef;

struct DataFormatReaderInterface::ReferenceClassHelper { using type = DataFormatReaderRef; };

/// Intermediate helper class for DataFormatReaderInterface.
template <typename S> class DataFormatReaderInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatReaderInterface::ConstReferenceFunctionsImplDoxy : public DataFormatReaderInterface::ConstReferenceFunctionsImpl<REF>, public DataFormatBaseReaderInterface::ConstReferenceFunctionsImplDoxy<REF>, public DataSerializeReaderInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatReaderInterface.
template <typename S> class DataFormatReaderInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, true>::type&() const { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataFormatReaderInterface::ReferenceFunctionsImplDoxy : public DataFormatReaderInterface::ReferenceFunctionsImpl<REF>, public DataFormatBaseReaderInterface::ReferenceFunctionsImplDoxy<REF>, public DataSerializeReaderInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatReaderInterface.
template <typename S> class DataFormatReaderInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataFormatReaderInterface::COWReferenceFunctionsImplDoxy : public DataFormatReaderInterface::COWReferenceFunctionsImpl<REF>, public DataFormatBaseReaderInterface::COWReferenceFunctionsImplDoxy<REF>, public DataSerializeReaderInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataFormatReaderInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeReaderInterface::ReferenceFunctions<DataFormatBaseReaderInterface::ReferenceFunctions<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeReaderInterface::ReferenceFunctions<DataFormatBaseReaderInterface::ReferenceFunctions<ST>>::type>, ReferenceFunctionsImpl<typename DataSerializeReaderInterface::ReferenceFunctions<DataFormatBaseReaderInterface::ReferenceFunctions<ST>>::type>>::type>::type; };
class DataFormatReaderInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatReaderRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataFormatReaderRef is the reference class of DataFormatReaderInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatReaderRef : public DataFormatReaderInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatReaderRef, Reference);
};

struct DataFormatWriterInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatWriterInterface>::value || DataFormatBaseWriterInterface::HasBase::Check<I>::value || DataSerializeWriterInterface::HasBase::Check<I>::value; static I* Cast(DataFormatWriterInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataFormatWriterRef;

struct DataFormatWriterInterface::ReferenceClassHelper { using type = DataFormatWriterRef; };

/// Intermediate helper class for DataFormatWriterInterface.
template <typename S> class DataFormatWriterInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatWriterInterface::ConstReferenceFunctionsImplDoxy : public DataFormatWriterInterface::ConstReferenceFunctionsImpl<REF>, public DataFormatBaseWriterInterface::ConstReferenceFunctionsImplDoxy<REF>, public DataSerializeWriterInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatWriterInterface.
template <typename S> class DataFormatWriterInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, true>::type&() const { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataFormatWriterInterface::ReferenceFunctionsImplDoxy : public DataFormatWriterInterface::ReferenceFunctionsImpl<REF>, public DataFormatBaseWriterInterface::ReferenceFunctionsImplDoxy<REF>, public DataSerializeWriterInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatWriterInterface.
template <typename S> class DataFormatWriterInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DataFormatWriterInterface::COWReferenceFunctionsImplDoxy : public DataFormatWriterInterface::COWReferenceFunctionsImpl<REF>, public DataFormatBaseWriterInterface::COWReferenceFunctionsImplDoxy<REF>, public DataSerializeWriterInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataFormatWriterInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataSerializeWriterInterface::ReferenceFunctions<DataFormatBaseWriterInterface::ReferenceFunctions<ST>>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataSerializeWriterInterface::ReferenceFunctions<DataFormatBaseWriterInterface::ReferenceFunctions<ST>>::type>, ReferenceFunctionsImpl<typename DataSerializeWriterInterface::ReferenceFunctions<DataFormatBaseWriterInterface::ReferenceFunctions<ST>>::type>>::type>::type; };
class DataFormatWriterInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatWriterRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataFormatWriterRef is the reference class of DataFormatWriterInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatWriterRef : public DataFormatWriterInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatWriterRef, Reference);
};

#endif
