#if 1
namespace FILEFORMATPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
struct FileFormatInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatInterface>::value || DataDictionaryObjectInterface::HasBase::Check<I>::value; static I* Cast(FileFormatInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class FileFormat;

struct FileFormatInterface::ReferenceClassHelper { using type = FileFormat; };

/// Intermediate helper class for FileFormatInterface.
template <typename S> class FileFormatInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormat, false>::type&() const { return reinterpret_cast<const FileFormat&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormat, false>::type&() { return reinterpret_cast<const FileFormat&>(this->GetBaseRef()); }
/// For implementations to check if a given url/stream supports this file format.
/// You should never call this function directly. It's triggered by FileFormatDetectionInterface::Detect()/DetectAll().
/// @param[in] url								Url to check.
/// @param[in] probeStream				Optional parameter that allows to read content in case that the url is a file.
/// 															This stream is not a plain file stream but wraps a memory cache stream which allows to seek and read already loaded data without overhead.
/// @return												Returns true if the url/stream fits to this file format implementation.
	inline Result<Bool> Detect(const Url& url, const InputStreamRef& probeStream) const;
};
#ifdef DOXYGEN
template <typename REF> class FileFormatInterface::ConstReferenceFunctionsImplDoxy : public FileFormatInterface::ConstReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FileFormatInterface.
template <typename S> class FileFormatInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FileFormatInterface::ReferenceFunctionsImplDoxy : public FileFormatInterface::ReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FileFormatInterface.
template <typename S> class FileFormatInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class FileFormatInterface::COWReferenceFunctionsImplDoxy : public FileFormatInterface::COWReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FileFormatInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class FileFormatInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<FileFormat>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>);
	using NonConst = NonConstRef;
};

class FileFormatInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FileFormat is the reference class of FileFormatInterface.
///
/// FileFormatInterface allows to implement and register file formats with its detection algorithm.
/// The FileFormats registry allows to register any format (e.g. FileFormats::Browsable, FileFormats::ImageJpg...).
class FileFormat : public FileFormatInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormat, Reference);
};

#endif
