/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_NETWORK_H__
#define C4D_NETWORK_H__

#ifndef __API_INTERN__
	#include "c4d_string.h"
	#include "c4d_basecontainer.h"
	#include "ge_prepass.h"
#else
	#include "ge_string.h"
#endif

#include "operatingsystem.h"
#include "maxon/basearray.h"

class NetworkIpConnection;

Bool WriteIpAddr(const NetworkIpAddr& addr, HyperFile* hf);
Bool ReadIpAddr(NetworkIpAddr& addr, HyperFile* hf);
Bool WriteIpAddrPort(const NetworkIpAddrPort& addr, HyperFile* hf);
Bool ReadIpAddrPort(NetworkIpAddrPort& addr, HyperFile* hf);

class NetworkIpConnection
{
	NetworkIpConnection() {}
	~NetworkIpConnection() {}
public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the remote IP address + port for the connection.
	/// @param[out] ipaddr						The remote IP address + port.
	//----------------------------------------------------------------------------------------
	void GetRemoteAddr(NetworkIpAddrPort& ipaddr) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the host IP address + port for the connection.
	/// @param[out] ipaddr						The host IP address + port.
	//----------------------------------------------------------------------------------------
	void GetHostAddr(NetworkIpAddrPort& ipaddr) const;
};

//----------------------------------------------------------------------------------------
/// Opens a connection. Supports @em IPv4.
/// @param[in] adr								The destination address to connect to.
/// @param[in] thread							The thread to use for the connection. @callerOwnsPointed{thread}
/// @param[in] connectTimeout			The timeout in seconds for the initial connection.
/// @param[in] sessionTimeout			The timeout in seconds for receive and send operations.
/// @param[in] useNagleAlgorithm	Pass @formatConstant{true} to set the TCP/IP flag for @em TCP_NODELAY. For more information see http://msdn.microsoft.com/en-us/library/windows/desktop/ms740476(v=vs.85).aspx.
/// @param[in] error							Assigned error status if the connection failed. A value different than @em 0 indicates failure.
/// @return												The IP connection object. Must be freed with CloseConnection(). @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
NetworkIpConnection* OpenOutgoing(const NetworkIpAddrPort& adr, BaseThread* thread = nullptr, Int connectTimeout = 30, Int sessionTimeout = 10, Bool useNagleAlgorithm = true, Int* error = nullptr);

//----------------------------------------------------------------------------------------
/// Opens a connection. Supports @em IPv4.
/// @param[in] adr								The destination address to connect to (@em IPv4 address or host name).
/// @param[in] thread							The thread to use for the connection. @callerOwnsPointed{thread}
/// @param[in] connectTimeout			The timeout in seconds for the initial connection.
/// @param[in] sessionTimeout			The timeout in seconds for receive and send operations.
/// @param[in] useNagleAlgorithm	Pass @formatConstant{true} to set the TCP/IP flag for @em TCP_NODELAY. For more information see http://msdn.microsoft.com/en-us/library/windows/desktop/ms740476(v=vs.85).aspx.
/// @param[in] error							Assigned error status if the connection failed. A value different than @em 0 indicates failure.
/// @return												The IP connection object. Must be freed with CloseConnection(). @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
NetworkIpConnection* OpenOutgoing(const maxon::String& adr, BaseThread* thread = nullptr, Int connectTimeout = 30, Int sessionTimeout = 10, Bool useNagleAlgorithm = true, Int* error = nullptr);

//----------------------------------------------------------------------------------------
/// Checks how many bytes are in the input buffer of an IP connection.
/// @param[in] ipc								The IP connection to check. @callerOwnsPointed{NetworkIpConnection}
/// @return												The number of bytes in the input buffer.
//----------------------------------------------------------------------------------------
Int BytesInInputBuffer(NetworkIpConnection* ipc);

//----------------------------------------------------------------------------------------
/// Reads the bytes from the IP connection @formatParam{ipc} to @formatParam{buf}.
/// @note RecvBytes() will try to fill the buffer completely. If not enough data is received, it will run into a timeout and return zero. To prevent this, use BytesInInputBuffer().
/// @param[in] ipc								The IP connection to read from. @callerOwnsPointed{NetworkIpConnection}
/// @param[in] buf								The buffer to read to. @callerOwnsPointed{buffer}
/// @param[in] size								The size of the buffer @formatParam{buf}.
/// @return												The number of bytes read.
//----------------------------------------------------------------------------------------
Int RecvBytes(NetworkIpConnection* ipc, void* buf, Int size);

//----------------------------------------------------------------------------------------
/// Sends the bytes from @formatParam{buf} to the IP connection @formatParam{ipc}.
/// @param[in] ipc								The IP connection to send the bytes to. @callerOwnsPointed{NetworkIpConnection}
/// @param[in] buf								The buffer to send from. @callerOwnsPointed{buffer}
/// @param[in] size								The size of the buffer @formatParam{buf}.
/// @return												The number of bytes sent.
//----------------------------------------------------------------------------------------
Int SendBytes(NetworkIpConnection* ipc, const void* buf, Int size);

//----------------------------------------------------------------------------------------
/// Opens an IP listener.
/// @param[in] adr								The IP address of the network interface to use for the listener.
/// @param[in] thread							The thread to use for the connection. @callerOwnsPointed{thread}
/// @param[in] sessionTimeout			The time after which the listener closes an unresponsive connection.
/// @param[in] dontwait						Pass @formatConstant{true} to set the TCP/IP flag for @em TCP_NODELAY. For more information see http://msdn.microsoft.com/en-us/library/windows/desktop/ms740476(v=vs.85).aspx.
/// @param[in] error							Assigned error status if the connection failed. A value different than @em 0 indicates failure.
/// @return												The IP connection object for the listener. Must be freed with CloseConnection(). @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
NetworkIpConnection* OpenListener(const NetworkIpAddrPort& adr, BaseThread* thread, Int sessionTimeout, Bool dontwait, Int* error);

//----------------------------------------------------------------------------------------
/// Opens an IP listener.
/// @param[in] adr								The IP address of the network interface to use for the listener.
/// @param[in] thread							The thread to use for the connection. @callerOwnsPointed{thread}
/// @param[in] sessionTimeout			The time after which the listener closes an unresponsive connection.
/// @param[in] useNagleAlgorithm	Pass @formatConstant{true} to set the TCP/IP flag for @em TCP_NODELAY. For more information see http://msdn.microsoft.com/en-us/library/windows/desktop/ms740476(v=vs.85).aspx.
/// @param[in] error							Assigned error status if the connection failed. A value different than @em 0 indicates failure.
/// @return												The IP connection object for the listener. Must be freed with CloseConnection(). @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
NetworkIpConnection* OpenListener(const maxon::String& adr, BaseThread* thread, Int sessionTimeout, Bool useNagleAlgorithm, Int* error);

//----------------------------------------------------------------------------------------
/// Waits for an incoming connection to listener.
/// @param[in] listener						The listener IP connection to wait for. Needs to be freed with GeIpCloseConnection(). @callerOwnsPointed{NetworkIpConnection}
/// @param[in] connection					The thread to use for the connection. @callerOwnsPointed{thread}
/// @param[in] error							Assigned error status if the connection failed. A value different than @em 0 indicates failure.
/// @return												The IP connection object for the waiting connection. Must be freed with CloseConnection(). @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
NetworkIpConnection* OpenWaitForIncoming(NetworkIpConnection* listener, BaseThread* connection, Int* error);

//----------------------------------------------------------------------------------------
/// Kills an IP connection.
/// @note Calls End() for the connection thread.
/// @param[in] ipc								The IP connection to kill. @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
void KillConnection(NetworkIpConnection*& ipc);

//----------------------------------------------------------------------------------------
/// Closes and frees an IP connection.
/// @param[in] ipc								The IP connection to close. Assigned @formatConstant{nullptr} afterward. @callerOwnsPointed{NetworkIpConnection}
//----------------------------------------------------------------------------------------
void CloseConnection(NetworkIpConnection*& ipc);

#endif // C4D_NETWORK_H__
