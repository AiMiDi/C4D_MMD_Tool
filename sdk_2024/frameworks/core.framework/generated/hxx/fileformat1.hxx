#if 1
namespace FILEFORMATPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class FileFormat;

struct FileFormatInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(FileFormatInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct FileFormatInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = FileFormat;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for FileFormatInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = FileFormatInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(FileFormatInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormat, false>::type&() const { return reinterpret_cast<const FileFormat&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormat, false>::type&() { return reinterpret_cast<const FileFormat&>(this->GetBaseRef()); }
/// For implementations to check if a given url/stream supports this file format.
/// You should never call this function directly. It's triggered by FileFormatDetectionInterface::Detect()/DetectAll().
/// @param[in] url								Url to check.
/// @param[in] probeStream				Optional parameter that allows to read content in case that the url is a file.
/// 															This stream is not a plain file stream but wraps a memory cache stream which allows to seek and read already loaded data without overhead.
/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
/// @return												Returns true if the url/stream fits to this file format implementation.
		inline Result<Bool> Detect(const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename DataDictionaryObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class FileFormatInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<FileFormat>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FileFormatInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FileFormat is the reference class of FileFormatInterface.
///
/// FileFormatInterface allows to implement and register file formats with its detection algorithm.
/// The FileFormats registry allows to register any format (e.g. FileFormats::Browsable, FileFormats::ImageJpg...).
class FileFormat : public FileFormatInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormat, typename FileFormatInterface::Hxx1::Reference);
};

#endif
