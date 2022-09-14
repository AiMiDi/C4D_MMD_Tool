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
/// Checks if a file supports a given file format.
/// @param[in] url								Url to detect.
/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
/// @param[in] limitDetection			Datatype to limit the detection e.g. MediaInputRef, nodes::NodeSystem
/// @return                       OK on success.
		inline Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection) const;
/// Checks if a file supports a given file format. Helper function to simplify usage e.g. DetectFile<MediaInputRef>().
/// @param[in] url								Url to detect.
/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
/// @return                       OK on success.
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags) const;
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
/// Checks if a file supports a given file format.
/// @param[in] url								Url to detect.
/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
/// @param[in] limitDetection			Datatype to limit the detection e.g. MediaInputRef, nodes::NodeSystem
/// @return                       OK on success.
		inline Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection);
/// Checks if a file supports a given file format. Helper function to simplify usage e.g. DetectFile<MediaInputRef>().
/// @param[in] url								Url to detect.
/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
/// @return                       OK on success.
		template <typename... LIMITTYPES> inline Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags);
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
///
/// This interface allows to detect files with a file cache to prevent frequently open file io operations.
/// Used together with DragAndDropHandlerInterface to optimize d&d.
/// e.g.
/// FileFormatDetectionCacheRef fileFormatCacheRef = dndHandlerRef.GetFileDetectionCache() iferr_return;
/// ifnoerr (isTrue = fileFormatCacheRef.DetectFile<MediaInputRef>(url, FILEFORMATDETECTIONFLAGS::NONE))
/// {
/// 	if (isTrue)
/// 	{
/// 		isMediaSessionUrl |= isTrue;
/// 		break;
/// 	}
/// }
/// ifnoerr (isTrue = fileFormatCacheRef.DetectFile<nodes::NodeSystem>(url, FILEFORMATDETECTIONFLAGS::NONE))
/// {
/// 	if (isTrue)
/// 	{
/// 		isNodeAsset |= isTrue;
/// 		break;
/// 	}
/// }
class FileFormatDetectionCacheRef : public FileFormatDetectionCacheInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatDetectionCacheRef, typename FileFormatDetectionCacheInterface::Hxx1::Reference);
	using ConstPtr = typename FileFormatDetectionCacheInterface::ConstPtr;
};

#endif
