#ifndef NETWORK_IP_TCP_H__
#define NETWORK_IP_TCP_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"

#include "network_types.h"

#include "maxon/network_ioservice.h"
#include "maxon/network_ip_addr.h"


namespace maxon
{

class NetworkTcpSocketInterface;
class NetworkTcpSocketRef;

class NetworkTcpConnectionInterface;
class NetworkTcpConnectionRef;

class NetworkTcpServerInterface;
class NetworkTcpServerRef;

//----------------------------------------------------------------------------------------
/// A basic TCP network socket.
//----------------------------------------------------------------------------------------
class NetworkTcpSocketInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NetworkTcpSocketInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networktcpsocket");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the raw socket handle associated with this socket.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SocketT GetSocketHandle() const;
};

//----------------------------------------------------------------------------------------
/// An asynchronous TCP connection.
//----------------------------------------------------------------------------------------
class NetworkTcpConnectionInterface : MAXON_INTERFACE_BASES(NetworkTcpSocketInterface, AioReaderInterface, AioWriterInterface)
{
	MAXON_INTERFACE(NetworkTcpConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networktcpconnection");

public:
	using ReceiveCompletionHandler = Delegate<Result<void>(Result<void>, AioBuffer)>;
	using SendCompletionHandler = Delegate<Result<void>(Result<void>)>;
	using ConnectCompletionHandler = Delegate<Result<void>(Result<void>, NetworkTcpConnectionRef)>;

	static Result<void> DefaultSendCompletionHandler(Result<void> res) { return res; }

	//----------------------------------------------------------------------------------------
	/// Enqueues an asynchronous receive request.
	/// As soon as data has been received, the given handler delegate is called.
	/// A status instance can be used to synchronously wait on the operation and check its success.
	///
	/// @param[in] status							Status monitor for the operation.
	/// @param[in] handler						Handler delegate.
	/// @return												True if the request has been enqueued, error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Receive(const AioStatusRef& status, ReceiveCompletionHandler handler);

	//----------------------------------------------------------------------------------------
	/// Equivalent to Receive(AioStatusRef(), handler).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Receive(ReceiveCompletionHandler handler);

	//----------------------------------------------------------------------------------------
	/// Enqueues an asynchronous send request.
	/// As soon as data has been sent, the given handler delegate is called.
	/// A status instance can be used to synchronously wait on the operation and check its success.
	///
	/// @param[in] status							Status monitor for the operation.
	/// @param[in] data								Buffer containing data to be sent.
	/// @param[in] handler						Handler delegate.
	/// @return												True if the request has been enqueued, error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(const AioStatusRef& status, AioBuffer data, SendCompletionHandler handler = DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Equivalent to Send(AioStatusRef(), data, handler).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(AioBuffer data, SendCompletionHandler handler = DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Returns the address of the local endpoint of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetLocalAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns the address of the remote endpoint of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetRemoteAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns the I/O service that processes I/O operations of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AioServiceRef GetIoService() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue that runs completion handlers of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetJobQueue() const;
};

//----------------------------------------------------------------------------------------
/// An asynchronous TCP server.
//----------------------------------------------------------------------------------------
class NetworkTcpServerInterface : MAXON_INTERFACE_BASES(NetworkTcpSocketInterface, AioReaderInterface)
{
	MAXON_INTERFACE(NetworkTcpServerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networktcpserver");

public:
	using AcceptCompletionHandler = Delegate<Result<void>(Result<void>, NetworkTcpConnectionRef)>;

	//----------------------------------------------------------------------------------------
	/// Starts the server. Returns an error if the server was already started, or if it failed
	/// to set up a listening socket. After the server is successfully started, it will accept
	/// incoming connections.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Start();

	//----------------------------------------------------------------------------------------
	/// Stops the server.
	/// Afterwards the server no longer accepts incoming connections.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Stop();

	//----------------------------------------------------------------------------------------
	/// Returns true if the server is not started.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsStopped() const;

	//----------------------------------------------------------------------------------------
	/// Returns the actual address of the local endpoint this server is bound to.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetLocalAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns the I/O service that processes I/O operations of this server.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AioServiceRef GetIoService() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue that runs completion handlers of this server.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetJobQueue() const;
};

//----------------------------------------------------------------------------------------
/// Initialization options for a TCP connection.
//----------------------------------------------------------------------------------------
struct NetworkTcpConnectionOptions
{
	TimeValue connectTimeout		= Seconds(15);
	TimeValue sessionTimeout		= Seconds(15);
	Bool			useNagleAlgorithm = true;
};

//----------------------------------------------------------------------------------------
/// Static interface to access network functionality.
//----------------------------------------------------------------------------------------
class NetworkTcpInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkTcpInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networktcp");

public:
	using ConnectCompletionHandler = NetworkTcpConnectionInterface::ConnectCompletionHandler;
	using AcceptCompletionHandler = NetworkTcpServerInterface::AcceptCompletionHandler;

	//----------------------------------------------------------------------------------------
	/// Enqueues an asynchronous TCP connection attempt to the given address.
	/// As soon as the attempt is done, the given handler delegate is called.
	///
	/// @param[in] address						Address to connect to.
	/// @param[in] handler						Handler delegate.
	/// @param[in] ioService					I/O service for the connection.
	/// @param[in] jobQueue						Job queue for the connection.
	/// @return												True if the connection was established, error otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> OpenOutgoingConnection(const NetworkIpAddrPort& address, ConnectCompletionHandler handler, const AioServiceRef& ioService, const JobQueueRef& jobQueue);

	//----------------------------------------------------------------------------------------
	/// Creates an asynchronous TCP server bound to the given address.
	/// As soon as a connection is incoming, the given handler delegate is called.
	///
	/// @param[in] localAddress				Address to connect to.
	/// @param[in] handler						Handler delegate.
	/// @param[in] ioService					I/O service for the connection.
	/// @param[in] jobQueue						Job queue for the connection.
	/// @return												True if the connection was established, error otherwise.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkTcpServerRef> CreateServer(const NetworkIpAddrPort& localAddress, AcceptCompletionHandler handler, const AioServiceRef& ioService, const JobQueueRef& jobQueue);
};

#include "network_ip_tcp1.hxx"

#include "network_ip_tcp2.hxx"

}

#endif // NETWORK_IP_TCP_H__
