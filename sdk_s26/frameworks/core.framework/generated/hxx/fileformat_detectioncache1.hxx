#if 1
class FileFormatDetectionCacheRef;

struct FileFormatDetectionCacheInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatDetectionCacheInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(FileFormatDetectionCacheInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct FileFormatDetectionCacheInterface::Hxx1
{
	class Reference;
	using ReferenceClass = FileFormatDetectionCacheRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FileFormatDetectionCacheInterface.
	template <typename S> class Fn : public S
	{
	public:
		Fn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(FileFormatDetectionCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, true>::type&() const { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		inline Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection) const;
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url) const;
	};
	/// Intermediate helper class for FileFormatDetectionCacheInterface.
	template <typename S> class COWFn : public S
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(FileFormatDetectionCacheInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FileFormatDetectionCacheRef, false>::type&() { return reinterpret_cast<const FileFormatDetectionCacheRef&>(this->GetBaseRef()); }
		inline Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection);
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ObjectInterface::Hxx1::template FnHelper<ST>::type, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class FileFormatDetectionCacheInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<FileFormatDetectionCacheRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FileFormatDetectionCacheInterface, maxon::StrongRefHandler, FileFormatDetectionCacheRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// FileFormatDetectionCacheRef is the reference class of FileFormatDetectionCacheInterface.
class FileFormatDetectionCacheRef : public FileFormatDetectionCacheInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatDetectionCacheRef, typename FileFormatDetectionCacheInterface::Hxx1::Reference);
	using ConstPtr = typename FileFormatDetectionCacheInterface::ConstPtr;
};

#endif
