#ifndef NETWORK_IP_UDP_H__
#define NETWORK_IP_UDP_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"

#include "network_types.h"

#include "maxon/network_ioservice.h"
#include "maxon/network_ip_addr.h"

namespace maxon
{

class NetworkUdpSocketInterface;
class NetworkUdpSocketRef;

class NetworkUdpBoundSocketInterface;
class NetworkUdpBoundSocketRef;

class NetworkUdpChannelInterface;
class NetworkUdpChannelRef;

class NetworkUdpSenderInterface;
class NetworkUdpSenderRef;

class NetworkUdpServerInterface;
class NetworkUdpServerRef;

//----------------------------------------------------------------------------------------
/// A basic UDP network socket.
//----------------------------------------------------------------------------------------
class NetworkUdpSocketInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NetworkUdpSocketInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkudpsocket");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the raw socket handle associated with this socket.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SocketT GetSocketHandle() const;
};

//----------------------------------------------------------------------------------------
/// A UDP network socket that is bound to a local address and thus able to receive data.
//----------------------------------------------------------------------------------------
class NetworkUdpBoundSocketInterface : MAXON_INTERFACE_BASES(NetworkUdpSocketInterface)
{
	MAXON_INTERFACE(NetworkUdpBoundSocketInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkudpboundsocket");

public:
	//----------------------------------------------------------------------------------------
	/// Joins a multicast group. The given groupAddress must be a valid multicast address
	/// and its protocol must match that of the socket (i.e. no mixing of IPv4 and IPv6);
	/// otherwise, an error will be returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> JoinMulticastGroup(const NetworkIpAddr& groupAddress);

	//----------------------------------------------------------------------------------------
	/// Leaves a multicast group. Results in an error if the group was not previously joined.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> LeaveMulticastGroup(const NetworkIpAddr& groupAddress);

	//----------------------------------------------------------------------------------------
	/// Returns the local address this socket is bound to. May be a wildcard address.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetLocalAddress() const;
};

//----------------------------------------------------------------------------------------
/// An asynchronous UDP channel.
//----------------------------------------------------------------------------------------
class NetworkUdpChannelInterface : MAXON_INTERFACE_BASES(NetworkUdpBoundSocketInterface, AioReaderInterface, AioWriterInterface)
{
	MAXON_INTERFACE(NetworkUdpChannelInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkudpchannel");

public:
	using ReceiveCompletionHandler = Delegate<Result<void>(Result<void>, AioBuffer, NetworkIpAddrPort)>;
	using SendCompletionHandler = Delegate<Result<void>(Result<void>)>;

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
	/// @param[in] destAddress				Destination address.
	/// @param[in] handler						Handler delegate.
	/// @return												True if the request has been enqueued, error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(const AioStatusRef& status, AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Equivalent to Send(AioStatusRef(), data, destAddress, handler).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Returns the I/O service that processes I/O operations of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AioServiceRef GetIoService() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue that runs completion handlers of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetJobQueue() const;
};

//----------------------------------------------------------------------------------------
/// An asynchronous UDP sender.
//----------------------------------------------------------------------------------------
class NetworkUdpSenderInterface : MAXON_INTERFACE_BASES(NetworkUdpSocketInterface, AioWriterInterface)
{
	MAXON_INTERFACE(NetworkUdpSenderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkudpsender");

public:
	using SendCompletionHandler = NetworkUdpChannelInterface::SendCompletionHandler;

	//----------------------------------------------------------------------------------------
	/// Enqueues an asynchronous send request.
	/// As soon as data has been sent, the given handler delegate is called.
	/// A status instance can be used to synchronously wait on the operation and check its success.
	///
	/// @param[in] status							Status monitor for the operation.
	/// @param[in] data								Buffer containing data to be sent.
	/// @param[in] destAddress				Destination address.
	/// @param[in] handler						Handler delegate.
	/// @return												True if the request has been enqueued, error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(const AioStatusRef& status, AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = NetworkUdpChannelInterface::DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Equivalent to Send(AioStatusRef(), data, destAddress, handler).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = NetworkUdpChannelInterface::DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Returns the I/O service that processes I/O operations of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AioServiceRef GetIoService() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue that runs completion handlers of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetJobQueue() const;
};

//----------------------------------------------------------------------------------------
/// An asynchronous UDP server.
//----------------------------------------------------------------------------------------
class NetworkUdpServerInterface : MAXON_INTERFACE_BASES(NetworkUdpBoundSocketInterface, AioReaderInterface, AioWriterInterface)
{
	MAXON_INTERFACE(NetworkUdpServerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkudpserver");

public:
	using ReceiveCompletionHandler = NetworkUdpChannelInterface::ReceiveCompletionHandler;
	using SendCompletionHandler = NetworkUdpChannelInterface::SendCompletionHandler;

	//----------------------------------------------------------------------------------------
	/// Starts the server. Returns an error if the server was already started, or if it failed
	/// to set up a listening socket. After the server is successfully started, it will receive
	/// incoming packets.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Start();

	//----------------------------------------------------------------------------------------
	/// Stops the server.
	/// Afterwards the server no longer accepts incoming connections.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void	Stop();

	//----------------------------------------------------------------------------------------
	/// Returns true if the server is not started.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsStopped() const;

	//----------------------------------------------------------------------------------------
	/// Enqueues an asynchronous send request.
	/// As soon as data has been sent, the given handler delegate is called.
	/// A status instance can be used to synchronously wait on the operation and check its success.
	///
	/// @param[in] status							Status monitor for the operation.
	/// @param[in] data								Buffer containing data to be sent.
	/// @param[in] destAddress				Destination address.
	/// @param[in] handler						Handler delegate.
	/// @return												True if the request has been enqueued, error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(const AioStatusRef& status, AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = NetworkUdpChannelInterface::DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Equivalent to Send(AioStatusRef(), data, handler).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void>	Send(AioBuffer data, const NetworkIpAddrPort& destAddress, SendCompletionHandler handler = NetworkUdpChannelInterface::DefaultSendCompletionHandler);

	//----------------------------------------------------------------------------------------
	/// Returns the I/O service that processes I/O operations of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AioServiceRef GetIoService() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue that runs completion handlers of this instance.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetJobQueue() const;
};

//----------------------------------------------------------------------------------------
/// Initialization options for an UDP receiver.
//----------------------------------------------------------------------------------------
struct NetworkUdpChannelOptions
{
	Bool allowAddressReuse = true;
	Bool enableMulticastLoopback = true;
};

//----------------------------------------------------------------------------------------
/// Initialization options for an UDP sender.
//----------------------------------------------------------------------------------------
struct NetworkUdpSenderOptions
{
};

//----------------------------------------------------------------------------------------
/// Initialization options for an UDP server.
//----------------------------------------------------------------------------------------
struct NetworkUdpServerOptions
{
	Bool allowAddressReuse = true;
};

//----------------------------------------------------------------------------------------
/// Static interface to create UDP entities.
//----------------------------------------------------------------------------------------
class NetworkUdpInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkUdpInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.networkudp");

public:
	//----------------------------------------------------------------------------------------
	/// Creates a new UDP channel.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkUdpChannelRef>	CreateUdpChannel(const NetworkUdpChannelOptions& initOptions, const NetworkIpAddrPort& address, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);
	static inline MAXON_FUNCTION Result<NetworkUdpChannelRef> CreateUdpChannel(const NetworkIpAddrPort& address, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);

	//----------------------------------------------------------------------------------------
	/// Creates a new UDP sender.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkUdpSenderRef> CreateUdpSender(const NetworkUdpSenderOptions& initOptions, PROTOCOL protocol, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);
	static inline MAXON_FUNCTION Result<NetworkUdpSenderRef> CreateUdpSender(PROTOCOL protocol, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);

	//----------------------------------------------------------------------------------------
	/// Creates a new UDP server.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkUdpServerRef> CreateUdpServer(const NetworkUdpServerOptions& initOptions, const NetworkIpAddrPort& address, NetworkUdpServerInterface::ReceiveCompletionHandler handler, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);
	static inline MAXON_FUNCTION Result<NetworkUdpServerRef> CreateUdpServer(const NetworkIpAddrPort& address, NetworkUdpServerInterface::ReceiveCompletionHandler handler, const AioServiceRef& ioService, const JobQueueRef& jobQueue = JOBQUEUE_CURRENT);
};

#include "network_ip_udp1.hxx"

Result<NetworkUdpChannelRef> NetworkUdpInterface::CreateUdpChannel(const NetworkIpAddrPort& address, const AioServiceRef& ioService, const JobQueueRef& jobQueue)
{
	NetworkUdpChannelOptions defaultOptions;
	return NetworkUdpInterface::CreateUdpChannel(defaultOptions, address, ioService, jobQueue);
}

Result<NetworkUdpSenderRef> NetworkUdpInterface::CreateUdpSender(PROTOCOL protocol, const AioServiceRef& ioService, const JobQueueRef& jobQueue)
{
	NetworkUdpSenderOptions defaultOptions;
	return NetworkUdpInterface::CreateUdpSender(defaultOptions, protocol, ioService, jobQueue);
}

Result<NetworkUdpServerRef> NetworkUdpInterface::CreateUdpServer(const NetworkIpAddrPort& address, NetworkUdpServerInterface::ReceiveCompletionHandler handler, const AioServiceRef& ioService, const JobQueueRef& jobQueue)
{
	NetworkUdpServerOptions defaultOptions;
	return NetworkUdpInterface::CreateUdpServer(defaultOptions, address, std::move(handler), ioService, jobQueue);
}

#include "network_ip_udp2.hxx"

} // namespace maxon

#endif // NETWORK_IP_UDP_H__
