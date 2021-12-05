#if 1
class FileFormatHandler;

struct FileFormatHandlerInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FileFormatHandlerInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(FileFormatHandlerInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct FileFormatHandlerInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = FileFormatHandler;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for FileFormatHandlerInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatHandler, false>::type&() const { return reinterpret_cast<const FileFormatHandler&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FileFormatHandler, false>::type&() { return reinterpret_cast<const FileFormatHandler&>(this->GetBaseRef()); }
/// Returns the FileFormat which is handled by this FileFormatHandler.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type GetFileFormat() const;
/// Returns the datatype of the reference class of the handler returned by CreateHandler().
		inline Result<DataType> GetHandlerType() const;
/// Creates an ObjectRef which handles the given url with the generic interface.
/// CreateHandler<InterfaceRef>() can be used to get the expected reference in the right format.
/// E.g. FileFormat::Zip implements one handler for Directory Browsing "IoBrowseRef" and one for working with archives "ReadArchiveRef".
/// @param[in] url								Url to be used with this handler.
		inline Result<ObjectRef> CreateHandler(const Url& url) const;
/// Creates an ObjectRef which handles the given url with the specific interface.
/// E.g. FileFormat::Zip implements one handler for Directory Browsing "IoBrowseRef" and one for workign with archives "ReadArchiveRef".
/// @param[in] url								Url to be used with this handler.
/// @tparam HANDLER								Reference class to be expected with the result of CreateHandler.
		template <typename HANDLER> inline Result<HANDLER> CreateHandler(const Url& url) const;
/// Returns the dependencies of this FileFormatHandler. This allows to give an priority order for a implementation.
/// This function should not be called except from FileFormatDetectionInterface::DetectAll().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<FILEFORMAT_PRIORITY>, FILEFORMAT_PRIORITY>::type GetDependends() const;
	};
	/// Intermediate helper class for FileFormatHandlerInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for FileFormatHandlerInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class FileFormatHandlerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<FileFormatHandler>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatHandlerInterface, maxon::StrongRefHandler, FileFormatHandler>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const FileFormatHandlerInterface, maxon::StrongRefHandler, FileFormatHandler>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class FileFormatHandlerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<FileFormatHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// FileFormatHandler is the reference class of FileFormatHandlerInterface.
///
/// FileFormatHandlerInterface implements a handler for a specific FileFormat.
/// E.g. two different implementations could offer different loaders for one and the same FileFormat.
/// FileFormat::Zip implements one handler for Directory Browsing (IoBrowseRef) and one for ReadArchiveRef.
class FileFormatHandler : public FileFormatHandlerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FileFormatHandler, typename FileFormatHandlerInterface::Hxx1::Reference);
};

#ifndef MAXON_COMPILER_CLANG
#endif
#endif
