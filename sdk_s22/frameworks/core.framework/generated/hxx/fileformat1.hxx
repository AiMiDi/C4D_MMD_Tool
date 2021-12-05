#if 1
namespace FILEFORMATPROPERTIES
{
#ifndef PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
#define PRIVATE_MAXON_GUARD_maxon_FILEFORMATPROPERTIES
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class FileFormat;

struct FileFormatInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(FileFormatInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FileFormatInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = FileFormat;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for FileFormatInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
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
	/// Intermediate helper class for FileFormatInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FileFormatInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FileFormatInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<FileFormat>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatInterface, maxon::StrongRefHandler, FileFormat>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FileFormatInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
