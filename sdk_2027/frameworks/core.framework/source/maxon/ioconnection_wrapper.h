#ifndef IOCONNECTION_WRAPPER_H__
#define IOCONNECTION_WRAPPER_H__

#include "maxon/iohandler.h"

namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// An io connection wrapper wraps an underlying connection.
/// There's the default implementation IoConnectionWrapperClass which forwards all calls to the underlying connection.
//----------------------------------------------------------------------------------------
class IoConnectionWrapperInterface : MAXON_INTERFACE_BASES(IoConnectionInterface)
{
	MAXON_INTERFACE(IoConnectionWrapperInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.ioconnectionwrapper", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));

public:
	//----------------------------------------------------------------------------------------
	/// Initializes this connection wrapper.
	/// @param[in] url								The Url for the connection.
	/// @param[in] wrappedConnection	The underlying connection.
	/// @param[in] readOnly						True if this connection shall be read-only, i.e., all methods which would write to the underlying connection shall fail with an error.
	/// @param[in] forwardStreams			True if stream-related methods shall be forwarded to the underlying connection. If false, you have to implement the necessary methods yourself.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& url, const IoConnectionRef& wrappedConnection, Bool readOnly, Bool forwardStreams);

	//----------------------------------------------------------------------------------------
	/// Returns the underlying connection which has been set by Init().
	/// @return												Underlying connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const IoConnectionRef& GetWrappedConnection() const;
};

#include "ioconnection_wrapper1.hxx"

//----------------------------------------------------------------------------------------
/// Default implementation of IoConnectionWrapperInterface which forwards all calls to the underlying connection.
/// See IoConnectionWrapperInterface::Init for options for the forwarding (readOnly, forwardStreams).
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<IoConnectionRef>, IoConnectionWrapperClass, "net.maxon.class.ioconnectionwrapper", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));


//----------------------------------------------------------------------------------------
/// Url scheme for Urls which shall be handled by IoWrappedUrlHandlerClass. To make sense, such Urls
/// need a valid URLFLAGS::OPEN_CONNECTION delegate which is used by he handler's OpenConnection method.
///
/// One use case of this scheme is when you want to attach extra code to stream operations for a Url,
/// such as hashing bytes while they are written to an output stream of the Url. In that case,
/// you create a wrapper Url of this scheme, set the original Url as embedded Url, and also
/// set the URLFLAGS::OPEN_CONNECTION delegate to return a connection which wraps the original Url's
/// output stream with a stream implementation that hashes written bytes.
//----------------------------------------------------------------------------------------
static constexpr LiteralId URLSCHEME_WRAPPED = LiteralId("wrapped");

//----------------------------------------------------------------------------------------
/// The implementation class for the io handler of URLSCHEME_WRAPPED. AppendUrl/RemoveUrl calls are applied
/// to the embedded Url. The OpenConnection method requires a valid URLFLAGS::OPEN_CONNECTION delegate
/// set at the Url, otherwise it returns with an error.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<IoHandler>, IoWrappedUrlHandlerClass, "net.maxon.class.wrappedurlhandler", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));

using OpenConnectionDelegate = Delegate<Result<IoConnectionRef>(const Url& url)>;

namespace URLFLAGS
{
	//----------------------------------------------------------------------------------------
	/// This delegate is used by Urls of scheme URLSCHEME_WRAPPED to open a connection.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(OpenConnectionDelegate, OPEN_CONNECTION, "net.maxon.wrappedurlhandler.openconnection");
}

#include "ioconnection_wrapper2.hxx"

/// @}

} // namespace maxon


#endif // IOCONNECTION_WRAPPER_H__
