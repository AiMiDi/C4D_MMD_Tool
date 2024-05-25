#if 1
class DataFormatReaderRef;

struct DataFormatReaderInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatReaderInterface>::value || DataFormatBaseReaderInterface::HasBaseDetector::template Check<I>::value || DataSerializeReaderInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataFormatReaderInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataFormatReaderInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatReaderRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataFormatBaseReaderInterface, DataSerializeReaderInterface>;
	/// Intermediate helper class for DataFormatReaderInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataFormatReaderInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataFormatReaderInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, true>::type&() const { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataFormatReaderInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataFormatReaderInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataFormatReaderInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatReaderRef, false>::type&() { return reinterpret_cast<const DataFormatReaderRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataSerializeReaderInterface::Hxx1::template FnHelper<typename DataFormatBaseReaderInterface::Hxx1::template FnHelper<ST>>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename DataSerializeReaderInterface::Hxx1::template FnHelper<typename DataFormatBaseReaderInterface::Hxx1::template FnHelper<ST>>::type, Fn<typename DataSerializeReaderInterface::Hxx1::template FnHelper<typename DataFormatBaseReaderInterface::Hxx1::template FnHelper<ST>>::type>>::type
	> { };
};
class DataFormatReaderInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DataFormatReaderRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataFormatReaderInterface, maxon::StrongRefHandler, DataFormatReaderRef>>>>);
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
	using ConstPtr = typename DataFormatReaderInterface::ConstPtr;
};

class DataFormatWriterRef;

struct DataFormatWriterInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatWriterInterface>::value || DataFormatBaseWriterInterface::HasBaseDetector::template Check<I>::value || DataSerializeWriterInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataFormatWriterInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataFormatWriterInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatWriterRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataFormatBaseWriterInterface, DataSerializeWriterInterface>;
	/// Intermediate helper class for DataFormatWriterInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataFormatWriterInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataFormatWriterInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, true>::type&() const { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for DataFormatWriterInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataFormatWriterInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataFormatWriterInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatWriterRef, false>::type&() { return reinterpret_cast<const DataFormatWriterRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename DataSerializeWriterInterface::Hxx1::template FnHelper<typename DataFormatBaseWriterInterface::Hxx1::template FnHelper<ST>>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename DataSerializeWriterInterface::Hxx1::template FnHelper<typename DataFormatBaseWriterInterface::Hxx1::template FnHelper<ST>>::type, Fn<typename DataSerializeWriterInterface::Hxx1::template FnHelper<typename DataFormatBaseWriterInterface::Hxx1::template FnHelper<ST>>::type>>::type
	> { };
};
class DataFormatWriterInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DataFormatWriterRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataFormatWriterInterface, maxon::StrongRefHandler, DataFormatWriterRef>>>>);
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
	using ConstPtr = typename DataFormatWriterInterface::ConstPtr;
};

#endif
