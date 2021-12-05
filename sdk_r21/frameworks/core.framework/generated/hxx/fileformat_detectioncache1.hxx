#if 1
class FileFormatDetectionCacheRef;

struct FileFormatDetectionCacheInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatDetectionCacheInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(FileFormatDetectionCacheInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FileFormatDetectionCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = FileFormatDetectionCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FileFormatDetectionCacheInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FileFormatDetectionCacheInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, true>::type&() const { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		inline Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection) const;
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url) const;
	};
	/// Intermediate helper class for FileFormatDetectionCacheInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		inline Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection);
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FileFormatDetectionCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<FileFormatDetectionCacheRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// FileFormatDetectionCacheRef is the reference class of FileFormatDetectionCacheInterface.
class FileFormatDetectionCacheRef : public FileFormatDetectionCacheInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatDetectionCacheRef, typename FileFormatDetectionCacheInterface::Hxx1::Reference);
};

#endif
