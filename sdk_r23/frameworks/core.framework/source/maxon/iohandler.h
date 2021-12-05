#ifndef IOHANDLER_H__
#define IOHANDLER_H__

#include "maxon/ioconnection.h"


namespace maxon
{

class UrlInterface;
class IoHandler;

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// The IoHandler class offers some I/O functionality for filenames.
/// This handler needs to be implemented for each scheme.
//----------------------------------------------------------------------------------------
class IoHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(IoHandlerInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.iohandler");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the url scheme to use in Urls for this handler (such as "file" if this is the IoHandler for the file system).
	/// @return												Url scheme of this handler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetUrlScheme() const;

	//----------------------------------------------------------------------------------------
	/// Converts an OS- or handler-specific system path to a Url.
	/// @param[out] url								The url that will be filled.
	/// @param[in] systemPath					The path.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSystemPath(UrlInterface& url, const String& systemPath) const;

	//----------------------------------------------------------------------------------------
	/// Translates a Url to a OS- or handler-specific system path.
	/// @param[in] url								The Url.
	/// @return												The generated path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetSystemPath(const UrlInterface& url) const;

	//----------------------------------------------------------------------------------------
	/// Appends the given file name to the url.
	/// @param[in,out] url						The Url.
	/// @param[in] name								A file name to add.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const String& name) const;

	//----------------------------------------------------------------------------------------
	/// Appends the given relative url to the url.
	/// @param[in,out] url						The Url.
	/// @param[in] relativeUrl				The Url to be added.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AppendUrl(UrlInterface& url, const Url& relativeUrl) const;

	//----------------------------------------------------------------------------------------
	/// Removes the last part of the given url and returns the parent url.
	/// @param[in,out] url						The Url.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveUrl(UrlInterface& url) const;

	//----------------------------------------------------------------------------------------
	/// Opens a connection and returns the specified IoConnectionRef handler for this type of protocol.
	/// @param[in] name								Url of the connection to open.
	/// @return												Pointer to a specialized IoConnectionRef.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<IoConnectionRef> OpenConnection(const Url& name) const;

	//----------------------------------------------------------------------------------------
	/// Return a normalized a url. Does not involve any Io operation and is just syntax based.
	/// If nothing needs to be normalized the same path is returned.
	/// @param[in] flags							Flags to define type of normalization.
	/// @return												The normalized url. In case of a normalization error *this is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> Normalize(const Url& url, NORMALIZEFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Return a normalized a url. If the normalized url is a link, the IoHandler can resolve it (if supported).
	/// E.g. the file:/// handler resolves symbolic links, where the http:// handler does not resolve llinks.
	/// @param[in] flags							Flags to define type of normalization.
	/// @return												The normalized and resolved url. In case of a normalization error *this is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> IoNormalize(const Url& url, NORMALIZEFLAGS flags) const;

	//----------------------------------------------------------------------------------------
	/// Returns the IoHandler which is responsible for the given scheme. The IoHandler is
	/// searched for at the IoHandlers registry.
	/// @param[in] scheme							The Url scheme for which the matching IoHandler shall be found.
	/// @return												The matching IoHandler, or a null reference.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD IoHandler GetHandlerForScheme(const UrlScheme& scheme);
};

// include autogenerated headerfile here
#include "iohandler1.hxx"

MAXON_REGISTRY(IoHandler, IoHandlers, "net.maxon.registry.iohandlers");

MAXON_DECLARATION(Class<IoHandler>, IoHandlerObjectBaseClass, "net.maxon.class.iohandlerobjectbase");
MAXON_DECLARATION(Class<IoHandler>, IoHandlerObjectFileClass, "net.maxon.class.iohandlerobjectfile");

#include "iohandler2.hxx"

/// @}

} // namespace maxon


#endif // IOHANDLER_H__
