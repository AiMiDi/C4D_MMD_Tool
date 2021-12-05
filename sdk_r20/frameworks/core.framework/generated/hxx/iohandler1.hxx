#if 1
struct IoHandlerInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, IoHandlerInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(IoHandlerInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class IoHandler;

struct IoHandlerInterface::ReferenceClassHelper { using type = IoHandler; };

/// Intermediate helper class for IoHandlerInterface.
template <typename S> class IoHandlerInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
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
/// Returns the IoHandler which is responsible for the given scheme. The IoHandler is
/// searched for at the IoHandlers registry.
/// @param[in] scheme							The Url scheme for which the matching IoHandler shall be found.
/// @return												The matching IoHandler, or a null reference.
	static inline IoHandler GetHandlerForScheme(const UrlScheme& scheme);
};
#ifdef DOXYGEN
template <typename REF> class IoHandlerInterface::ConstReferenceFunctionsImplDoxy : public IoHandlerInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IoHandlerInterface.
template <typename S> class IoHandlerInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IoHandlerInterface::ReferenceFunctionsImplDoxy : public IoHandlerInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for IoHandlerInterface.
template <typename S> class IoHandlerInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class IoHandlerInterface::COWReferenceFunctionsImplDoxy : public IoHandlerInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct IoHandlerInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class IoHandlerInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<IoHandler>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IoHandlerInterface, maxon::StrongRefHandler, IoHandler>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const IoHandlerInterface, maxon::StrongRefHandler, IoHandler>>>>);
	using NonConst = NonConstRef;
};

class IoHandlerInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IoHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<IoHandlerInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// IoHandler is the reference class of IoHandlerInterface.
///
/// The IoHandler class offers some I/O functionality for filenames.
/// This handler needs to be implemented for each scheme.
class IoHandler : public IoHandlerInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoHandler, Reference);
};

#endif
