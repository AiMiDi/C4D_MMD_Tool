#if 1
struct FileFormatDetectionCacheInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatDetectionCacheInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(FileFormatDetectionCacheInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class FileFormatDetectionCacheRef;

struct FileFormatDetectionCacheInterface::ReferenceClassHelper { using type = FileFormatDetectionCacheRef; };

/// Intermediate helper class for FileFormatDetectionCacheInterface.
template <typename S> class FileFormatDetectionCacheInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FileFormatDetectionCacheInterface::ConstReferenceFunctionsImplDoxy : public FileFormatDetectionCacheInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FileFormatDetectionCacheInterface.
template <typename S> class FileFormatDetectionCacheInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, true>::type&() const { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
	inline Result<Bool> DetectFile(const Url& url, const Block<const DataType*>& limitDetection) const;
	template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url) const;
};
#ifdef DOXYGEN
template <typename REF> class FileFormatDetectionCacheInterface::ReferenceFunctionsImplDoxy : public FileFormatDetectionCacheInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FileFormatDetectionCacheInterface.
template <typename S> class FileFormatDetectionCacheInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
	inline Result<Bool> DetectFile(const Url& url, const Block<const DataType*>& limitDetection);
	template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url);
};
#ifdef DOXYGEN
template <typename REF> class FileFormatDetectionCacheInterface::COWReferenceFunctionsImplDoxy : public FileFormatDetectionCacheInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FileFormatDetectionCacheInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class FileFormatDetectionCacheInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<FileFormatDetectionCacheRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// FileFormatDetectionCacheRef is the reference class of FileFormatDetectionCacheInterface.
class FileFormatDetectionCacheRef : public FileFormatDetectionCacheInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatDetectionCacheRef, Reference);
};

#endif
