#if 1
class IoHandler;

struct IoHandlerInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoHandlerInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(IoHandlerInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct IoHandlerInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = IoHandler;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for IoHandlerInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(IoHandlerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoHandler, false>::type&() const { return reinterpret_cast<const IoHandler&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoHandler, false>::type&() { return reinterpret_cast<const IoHandler&>(this->GetBaseRef()); }
/// Returns the url scheme to use in Urls for this handler (such as "file" if this is the IoHandler for the file system).
/// @return												Url scheme of this handler.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetUrlScheme() const;
/// Converts an OS- or handler-specific system path to a Url.
/// @param[out] url								The url that will be filled.
/// @param[in] systemPath					The path.
/// @return												OK on success.
		inline Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const;
/// Translates a Url to a OS- or handler-specific system path.
/// @param[in] url								The Url.
/// @return												The generated path.
		inline Result<String> GetSystemPath(const UrlInterface& url) const;
/// Appends the given file name to the url.
/// @param[in,out] url						The Url.
/// @param[in] name								A file name to add.
/// @return												OK on success.
		inline Result<void> AppendUrl(UrlInterface& url, const String& name) const;
/// Appends the given relative url to the url.
/// @param[in,out] url						The Url.
/// @param[in] relativeUrl				The Url to be added.
/// @return												OK on success.
		inline Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const;
/// Removes the last part of the given url and returns the parent url.
/// @param[in,out] url						The Url.
/// @return												OK on success.
		inline Result<void> RemoveUrl(UrlInterface& url) const;
/// Opens a connection and returns the specified IoConnectionRef handler for this type of protocol.
/// @param[in] name								Url of the connection to open.
/// @return												Pointer to a specialized IoConnectionRef.
		inline Result<IoConnectionRef> OpenConnection(const Url& name) const;
/// Return a normalized a url. Does not involve any Io operation and is just syntax based.
/// If nothing needs to be normalized the same path is returned.
/// @param[in] flags							Flags to define type of normalization.
/// @return												The normalized url. In case of a normalization error *this is returned.
		inline Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const;
/// Return a normalized a url. If the normalized url is a link, the IoHandler can resolve it (if supported).
/// E.g. the file:/// handler resolves symbolic links, where the http:// handler does not resolve llinks.
/// @param[in] flags							Flags to define type of normalization.
/// @return												The normalized and resolved url. In case of a normalization error *this is returned.
		inline Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const;
/// ConvertToUiName converts the url into a humans readable string.
/// Implementations can use this function to convert string.
/// e.g. Assets can build a nice human readable url string.
/// @param[in] url								Url to convert.
/// @param[in] flags							See CONVERTTOUINAMEFLAGS.
/// @return                       String on success.
		[[deprecated("use ConvertToUiNameWithRepository instead")]] inline Result<String> ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const;
/// Returns the IoHandler which is responsible for the given scheme. The IoHandler is
/// searched for at the IoHandlers registry.
/// @param[in] scheme							The Url scheme for which the matching IoHandler shall be found.
/// @return												The matching IoHandler, or a null reference.
		static inline IoHandler GetHandlerForScheme(const UrlScheme& scheme);
/// ConvertToUiNameWithRepository converts the url into a humans readable string.
/// Implementations can use this function to convert string.
/// e.g. Assets can build a nice human readable url string.
/// @param[in] url								Url to convert.
/// @param[in] flags							See CONVERTTOUINAMEFLAGS.
/// @param[in] lookupRepository		AssetRespoitory to search in.
/// @return                       String on success.
		inline Result<String> ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class IoHandlerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<IoHandler>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IoHandlerInterface, maxon::StrongRefHandler, IoHandler>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const IoHandlerInterface, maxon::StrongRefHandler, IoHandler>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class IoHandlerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<IoHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IoHandler is the reference class of IoHandlerInterface.
///
/// The IoHandler class offers some I/O functionality for filenames.
/// This handler needs to be implemented for each scheme.
class IoHandler : public IoHandlerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoHandler, typename IoHandlerInterface::Hxx1::Reference);
};

#endif
