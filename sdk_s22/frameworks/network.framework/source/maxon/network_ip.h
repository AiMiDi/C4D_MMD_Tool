#ifndef NETWORK_IP_H__
#define NETWORK_IP_H__

#include "maxon/apibase.h"
#include "maxon/bytesvalue.h"
#include "maxon/datadictionary.h"
#include "maxon/error.h"
#include "maxon/interface.h"
#include "maxon/network_ip_addr.h"
#include "maxon/object.h"
#include "maxon/observable.h"
#include "maxon/stringencoding.h"
#include "maxon/thread.h"


namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
	using SOCKET = UInt;
#else
	using SOCKET = int;
#endif

class NetworkConnectionRef;

namespace URLFLAGS
{
	/// Reference to a network connection.
	MAXON_ATTRIBUTE(NetworkConnectionRef, TCP_NETWORKCONNECTION_REF, 'tcpr');
	/// Optional Parameter to set a known size for this stream. NOTOK defines an unknown size.
	MAXON_ATTRIBUTE(Int64, TCP_NETWORKCONNECTION_KNOWNSIZE, 'tcps');
}

static const TimeValue NETWORK_DEFAULT_CONNECT_TIMEOUT	= Seconds(-1);		///< The default timeout for network connections. Is -1 for the internal default value.
static const TimeValue NETWORK_DEFAULT_SESSION_TIMEOUT	= Seconds(-1);	///< The default timeout for network sessions. Is -1 for the internal default value.

//----------------------------------------------------------------------------------------
/// Constants for the timeout of NetworkIpInterface::OpenListener(), NetworkIpInterface::OpenWaitForIncoming(), NetworkIpInterface::OpenOutgoing().
//----------------------------------------------------------------------------------------
static const TimeValue SOCKETTIMEOUT_INDEFINITELY = TIMEVALUE_INFINITE;

//----------------------------------------------------------------------------------------
/// Constants for the timeout of NetworkIpInterface::OpenListener(), NetworkIpInterface::OpenWaitForIncoming(), NetworkIpInterface::OpenOutgoing().
//----------------------------------------------------------------------------------------
static const TimeValue SOCKETTIMEOUT_NEVERBLOCK	 = Milliseconds(0.0);

using ReturnResolveError = Result<void>;

//----------------------------------------------------------------------------------------
/// A NetworkError indicates that a network function failed.
//----------------------------------------------------------------------------------------
class NetworkErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(NetworkErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.networkerror");
};

//----------------------------------------------------------------------------------------
/// A NetworkError timeout error.
/// Testing for "err.IsInstanceOf<NetworkTimeoutError>()" will return true in case of a network error.
//----------------------------------------------------------------------------------------
class NetworkTimeoutErrorInterface : MAXON_INTERFACE_BASES(NetworkErrorInterface)
{
	MAXON_INTERFACE(NetworkTimeoutErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.networktimeouterror");
};

enum class SOCKETMODE
{
	READ = 1000,
	WRITE,
	LISTEN,
	CONNECT
} MAXON_ENUM_LIST(SOCKETMODE);

enum class CONNECTIONMODE
{
	UNDEFINED = 0,
	SEND			= 1000,
	READ			= 1001
} MAXON_ENUM_LIST(CONNECTIONMODE);

enum class CONNECTIONTYPE
{
	LISTENER = 1000,
	INCOMING,
	OUTGOING
} MAXON_ENUM_LIST(CONNECTIONTYPE);

class NetworkAdapter;


struct NetworkIpAddressStruct
{
	NetworkIpAddr	_ipAddress, _broadcastAddress, _subnetMask;
};

//----------------------------------------------------------------------------------------
/// The NetworkAdapterInterface represents a physical Ethernet connection.
//----------------------------------------------------------------------------------------
class NetworkAdapterInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkAdapterInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.networkadapter");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the index of the adapter. This value is system dependent.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetAdapterIndex() const;

	//----------------------------------------------------------------------------------------
	/// Returns the name of the network adapter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Returns the mac address of the adapter.
	/// @return												Array with the adapter mac address. Usually the mac address contains 6 characters. You can use
	/// 															NetworkIpInterface::MacAddressToString() to convert the address to a string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<UChar>> GetMacAddress() const;
	MAXON_METHOD Bool SetMacAddress(const BaseArray<UChar>& macAddress);

	MAXON_METHOD void SetInterfaceName(const String& interfaceName);
	MAXON_METHOD String GetInterfaceName() const;

	MAXON_METHOD Result<void> Append(const NetworkIpAddr& ipAddr, const NetworkIpAddr& broadcastAddress, const NetworkIpAddr& subnetMask);

	MAXON_METHOD Int64 GetLinkSpeed() const;
	MAXON_METHOD void SetLinkSpeed(Int64 linkSpeed);

	MAXON_METHOD Bool IsSetViaDhcp() const;
	MAXON_METHOD void SetViaDhcp(Bool setViaDhcp);

	//----------------------------------------------------------------------------------------
	/// Returns a description of the network adapter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetDescription() const;
	MAXON_METHOD void SetDescription(const String& description);

	MAXON_METHOD void SetInterfaceIndex(Int interfaceIndex);
	MAXON_METHOD Int GetInterfaceIndex() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Sebastian) please explain what this is.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsLoopback() const;
	MAXON_METHOD void SetLoopback(Bool isLoopback);

	//----------------------------------------------------------------------------------------
	/// Returns the number of ip addresses connected to this adapter. This defines the valid range for GetIpAddress(), GetBroadcastAddress()
	/// and GetSubnetMask().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<NetworkIpAddressStruct>> GetIpAddresses() const;

	//----------------------------------------------------------------------------------------
	/// Returns custom data connected to this device. Currently unused.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD DataDictionary GetCustomData() const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;
};

//----------------------------------------------------------------------------------------
/// This class offers basic network connection functions to read/send data and manage connections.
//----------------------------------------------------------------------------------------
class NetworkConnectionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NetworkConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkconnection");

public:
	class Properties
	{
	public:
		TimeValue		sessionTimeout;
		Bool				useNagleAlgorithm = false;
		Bool				nonBlockingSocket = false;
		Bool				fullDuplex        = false;
	};

	//----------------------------------------------------------------------------------------
	/// Closes a connection by closing the socket.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CloseConnection();

	//----------------------------------------------------------------------------------------
	/// Killing a connection and canceling the connected threads.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> KillConnection();

	//----------------------------------------------------------------------------------------
	/// Returns the number of bytes that is available in the receive buffer.
	/// @return												Number of bytes available in the read stream. A value of -1 if an error occurred.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> BytesInInputBuffer();

	//----------------------------------------------------------------------------------------
	/// Reads the requested number of bytes from the connection.
	/// The function will not return before the number of requested bytes has been read or an error occurred.
	/// @param[in] data								Block for data buffer with requested number of bytes to read.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RecvBytes(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Reads the requested number of bytes from the connection to the end of the stream.
	/// The function will not return before the number of requested bytes has been read, an error occurred or the stream has been closed.
	/// @param[in] data								Block for data buffer with requested number of bytes to read.
	/// @return												Returns the number of bytes read or the error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RecvBytesEOS(const Block<Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Sends the given number of bytes to the connection. The function will not return before the number of given bytes is sent or an error occurred.
	/// Full duplex connections will not flush the send buffer until FlushWriteBuffer() is called.
	/// @param[in] buffer							Block with the data to send.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendBytes(const Block<const Byte>& buffer);

	//----------------------------------------------------------------------------------------
	/// Flushes the write buffer and send the collected bytes to the network connection.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FlushWriteBuffer();

	//----------------------------------------------------------------------------------------
	/// Empties the read and write buffer for the next connection. This can be useful if the connection is of type keep alive.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ResetBuffers();

	//----------------------------------------------------------------------------------------
	/// Returns the number of transfered bytes. -1 if an error occurred.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 GetTransferedBytes() const;

	//----------------------------------------------------------------------------------------
	/// Returns the remote address of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetRemoteAddr() const;

	//----------------------------------------------------------------------------------------
	/// Returns the host address of this connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddrPort GetHostAddr() const;

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// Returns the system socket this connection. This can be used to pass the socket to ssl for example.
	/// @return												Returns the socket, -1 if an error occured.
	/// @endcond
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SOCKET GetSocket() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetNonBlockingSocket(Bool nonBlockingSocket);

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsNonBlockingSocket() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetUseNagleAlgorithm(Bool useNagleAlgorithm);

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetUseNagleAlgorithm() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetTimeout(TimeValue timeoutInSeconds);

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeValue GetTimeout() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CONNECTIONTYPE GetConnectionType() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetConnectionType(CONNECTIONTYPE type);

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	// MAXON_METHOD void SetSocket(SOCKET sock);

	//----------------------------------------------------------------------------------------
	/// The current thread will always be checked for cancellation. You only have to set a
	/// thread if an additional thread should be checked for cancellation, too.
	/// @param[in] ref								An optional thread which will be checked for cancellation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetThread(const ThreadRef& ref);

	//----------------------------------------------------------------------------------------
	/// Returns the stored proxy server information the was set using SetProxyInfo().
	/// The format of the string is "<<server>>:<<port>>".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetProxyServerInfo() const;

	//----------------------------------------------------------------------------------------
	/// Sets the proxy server to for later use of GetProxyInfo().
	/// @param[in] proxyInfo					Info to set. The format of the proxyInfo must be "<<server>>:<<port>>".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetProxyServerInfo(const String& proxyInfo);
};

//----------------------------------------------------------------------------------------
/// Static interface to access network functionality.
//----------------------------------------------------------------------------------------
class NetworkIpInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkIpInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkip");

public:

	//----------------------------------------------------------------------------------------
	/// Creates an NetworkIpConnection listener. When the listener is created use OpenWaitForIncoming() to wait for incoming connections.
	/// Shutdown the listener with CloseConnection(). When the machine / device goes into the sleep mode and wakes up again, the listener
	/// is still active and ready to accept connections.
	///
	/// @param[in] address						Addresses where the socket is binded to. Pass en empty instance to listen on all adapters.
	/// @param[in] thread							Thread object where this function is called from. Used to interrupt a connection on TestBreak()
	/// @param[in] connectionTimeout	Timeout of the listener object. Use SOCKETTIMEOUT_INDEFINITELY to disable timeout. Use NETWORK_DEFAULT_CONNECTION_TIMEOUT if you want to have the recommended default values.
	/// @param[in] useNagleAlgorithm	Set to true to use the Nagle algorithm, otherwise false.
	/// @return												Listener object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkConnectionRef> OpenListener(const NetworkIpAddrPort& address, const ThreadRef& thread, TimeValue connectionTimeout, Bool useNagleAlgorithm);

	//----------------------------------------------------------------------------------------
	/// Creates an NetworkIpConnection listener. When the listener is created use OpenWaitForIncoming() to wait for incoming connections.
	/// Shutdown the listener with CloseConnection(). When the machine / device goes into the sleep mode and wakes up again, the listener
	/// is still active and ready to accept connections.
	///
	/// @param[in] address						Address as string where the socket is binded to (e.g. "192.168.10.200:1234"). Pass en empty string or "0"
	/// @param[in] thread							Thread object where this function is called from. Used to interrupt a connection on TestBreak()
	/// @param[in] connectionTimeout	Timeout of the listener object. Use SOCKETTIMEOUT_INDEFINITELY to disable timeout. Use NETWORK_DEFAULT_CONNECTION_TIMEOUT if you want to have the recommended default values.
	/// @param[in] useNagleAlgorithm	Set to true to use the Nagle algorithm, otherwise false.
	/// @return												Listener object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkConnectionRef> OpenListener(const String& address, const ThreadRef& thread, TimeValue connectionTimeout, Bool useNagleAlgorithm);

	//----------------------------------------------------------------------------------------
	/// Waits for an incoming connection and blocks until a connection was established.
	/// @param[in] listener						Listener object from OpenListener().
	/// @param[in] connection					Thread object where this function is called from. Used to interrupt this call on TestBreak().
	/// @param[in] connectionTimeout	Timeout in seconds for further operations like send or receive. Use SOCKETTIMEOUT_INDEFINITELY to disable timeout. Use NETWORK_DEFAULT_CONNECTION_TIMEOUT if you want to have the recommended default values.
	/// @param[in] fullDuplex					Set the connection to full duplex mode which means that parallel read and write is allowed.
	/// @return												Incoming connection object or nullptr when an error occured or TestBreak() was called. In this case the content of ferr will be 0.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkConnectionRef> OpenWaitForIncoming(const NetworkConnectionRef& listener, const ThreadRef& connection, TimeValue connectionTimeout, Bool fullDuplex);

	//----------------------------------------------------------------------------------------
	/// Opens a connection. Supports IPv4 and IPv6.
	/// @param[in] address						Pass a host name to connect to. Can be an IPv4, IPv6 address or a host name.
	/// @param[in] thread							TODO: (Seb) ?
	/// @param[in] connectTimeout			Timeout in seconds for the initial connection. Use NETWORK_DEFAULT_INITIAL_TIMEOUT if you want to have the recommended default values.
	/// @param[in] sessionTimeout			Timeout in seconds for further operations like send or receive. Use SOCKETTIMEOUT_INDEFINITELY to disable timeout. Use NETWORK_DEFAULT_CONNECTION_TIMEOUT if you want to have the recommended default values.
	/// @param[in] useNagleAlgorithm	Pass true to set the TCP/IP flag for TCP_NODELAY. For more information see: http://msdn.microsoft.com/en-us/library/ms817942.aspx.
	/// @param[in] fullDuplex					Set the connection to full duplex mode which means that parallel read and write is allowed.
	/// @return												Connection object for the outgoing connection. Must be freed with CloseConnection.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkConnectionRef> OpenOutgoing(const NetworkIpAddrPort& address, const ThreadRef& thread, TimeValue connectTimeout, TimeValue sessionTimeout, Bool useNagleAlgorithm, Bool fullDuplex);
	static MAXON_METHOD Result<NetworkConnectionRef> OpenOutgoing(const String& address, const ThreadRef& thread, TimeValue connectTimeout, TimeValue sessionTimeout, Bool useNagleAlgorithm, Bool fullDuplex);

	//----------------------------------------------------------------------------------------
	/// Returns the host name of the local machine.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetHostname();

	//----------------------------------------------------------------------------------------
	/// Returns the host name of given ip address.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetHostname(const NetworkIpAddr& ipAddr, Bool useShortHostname = false);

	MAXON_OBSERVABLE_STATIC(void, ObservableNetworkInterfaceChanged, (), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Resolves a host name. If the address object can be an ip address object, you should use GetIpAddress(address, a, true) instead.
	/// @param[in] address						Host name to resolve.
	/// @param[in] ptype							Pass PROTOCOL::IPV4 if the result should just contain IPv4 address, same for PROTOCOL::IPV6 with IPv6 address and PROTOCOL::ALL for all addresses.
	/// @param[out] arr								Contains the addresses of the host name when the function succeeded.
	/// @param[in] firstMatch					Address array has a maximum size of 1 element.
	/// @param[in] forceResolve				Set to true to resolve the address via the DNS system.
	/// @return												Returns RESOLVERESULT::OK on success, otherwise the resolve operation failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ReturnResolveError ResolveHostname(const String& address, PROTOCOL ptype, BaseArray<NetworkIpAddr>& arr, Bool firstMatch = true, Bool forceResolve = false);

	//----------------------------------------------------------------------------------------
	/// Splits a passed address in its elements.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SplitAddress(const String& address, String* scheme, String* host, Int32* port);

	static MAXON_METHOD Result<Bool> SocketIOWait(SOCKET socket, SOCKETMODE mode, TimeValue timeoutMode, const ThreadRef& bt);

	//----------------------------------------------------------------------------------------
	/// Converts a host name, IPv4 or IPv6 address into an ip address object. A port value in the address will be ignored. When the resolve
	/// option is enabled, the call blocks and waits for the DNS system when the address is a host name. E.g:
	///			address: Sebastians-Macbook-Pro.local (DNS system used, call blocks)
	///			address: 192.168.10.1 (no DNS system used, call does not block)
	///
	/// @param[in] address						IP address or host name. If the string is a host name, resolve must be set to true otherwise the function fails.
	/// @param[in] resolve						Set to true to resolve the address via the DNS system.
	/// @param[in] forceResolve				TODO: (Seb) ?
	/// @return												Assigned ip address object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkIpAddr> GetIpAddress(const String& address, Bool resolve = true, Bool forceResolve = false);

	//----------------------------------------------------------------------------------------
	/// Converts a host name, IPv4 or IPv6` address into an ip address object. The address can have a port value. When the resolve option is enabled, the
	/// call blocks and waits for the DNS system when the address is a host name. E.g:
	///			address: Sebastians-Macbook-Pro.local:1234 (DNS system used, call blocks)
	///			address: 192.168.10.1:1234 (no DNS system used, call does not block)
	/// @param[in] address						IP address or host name. If the string is a host name, resolve must be set to true otherwise the function fails.
	/// @param[in] resolve						Set to true to resolve the address via the DNS system.
	/// @param[in] forceResolve				TODO: (Seb) ?
	/// @return												Assigned ip address object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkIpAddrPort> GetIpAddressAndPort(const String& address, Bool resolve = true, Bool forceResolve = false);

	//----------------------------------------------------------------------------------------
	/// Wakes a computer up by WOL (Wake-On-LAN). Currently only IPv4 is supported. To get
	/// WOL to work, a broadcast message on port '9' will be sent.
	///
	/// @param[in] macAddress					Mac-Address of the machine which will be woken up.
	/// @param[in] broadcastAddress		Broadcast address where the message should be send to.
	/// @return												True on success if the message was sent, otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WakeOnLan(const BaseArray<UChar>& macAddress, const NetworkIpAddr& broadcastAddress);

	//----------------------------------------------------------------------------------------
	/// Create a human-readable time string.
	/// @return												Time string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String GetTimeString();

	//----------------------------------------------------------------------------------------
	/// Convert a IPv4 broadcast address by a given ip and subnet address.
	/// @param[in] ipAddress					IP address.
	/// @param[in] subnetMask					Subnet address.
	/// @return												Broadcast address.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD NetworkIpAddr GetBroadcastAddress(const NetworkIpAddr& ipAddress, const NetworkIpAddr& subnetMask);

	//----------------------------------------------------------------------------------------
	/// Get the mac address of the machine. When this function returns false an error occurred, but then macAddress is filled at least with a
	/// random-generated macAddress. The random-generated mac address will be changed after a restart of the host application.
	/// @return												BaseArray with the mac address.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<UChar>> GetMacAddress();

	//----------------------------------------------------------------------------------------
	/// Prints a mac address to the debug console. The output is visible in debug builds or in a release build when the debug console with diagnostic output is activated.
	/// @param[in] macAddress					The mac address.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String MacAddressToString(const BaseArray<UChar>& macAddress);

	//----------------------------------------------------------------------------------------
	/// Returns the adapter index. The interface name "all" returns 0.
	/// @param[in] adapterName				The name.
	/// @return												The index.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int> GetAdapterIndex(const String& adapterName);

	//----------------------------------------------------------------------------------------
	/// Returns the best network adapter to the specified protocol.
	/// @param[in] protocol						Specified protocol.
	/// @return												The found network adapter.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkAdapter> GetBestNetworkAdapter(PROTOCOL protocol = PROTOCOL::IPV4);

	//----------------------------------------------------------------------------------------
	/// Returns all current active network adapter objects.
	/// @return												Array with all network adapters.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<NetworkAdapter>> GetAllNetworkAdapters();

	//----------------------------------------------------------------------------------------
	/// Returns the interface index of the network adapter that is in the same network as the given address.
	/// It's not required that the address is assigned to the adapter itself.
	/// If no match was found, -1 is returned.
	/// @return												Interface index of matching network adapter.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int> GetAdapterIndex(const NetworkIpAddr& address);
};

#include "network_ip1.hxx"

//----------HTML-----------------------------------------------------------------------------
/// <HR>
/// <H1>HTML</H1>
/// - encodes characters from Utf32Char to UChar
/// - decodes characters from UChar to Utf32Char
///
/// <B>Details:</B><BR>
/// - characters in the range 0..127 are encoded as single byte values
/// - characters above127 are encoded into a sequence of bytes.
/// - for special characters a character entity table is used to map the characters to a byte sequence see http://www.w3.org/TR/html5/syntax.html#named-character-references.
/// For example $ is converted to @&dollar;
/// - Any other character is encoded by a sequence of characters with @&@#xhhhh; where each hhhh is the hex value representing the character in Unicode space.
///
/// - The decoder reads any of these possible HTML hex value formats (d=decimal digit, h=hex digit):
///
///    - @&@#d;
///    - @&@#dd;
///    - @&@#ddd;
///    - @&@#dddd;
///    - @&@#xh;
///    - @&@#xhh;
///    - @&@#xhhh;
///    - @&@#xhhhh;
///
/// - Also any known character entity name is decoded as well
///
/// <B>Errors:</B><BR>
/// Returns an error if unkown byte codes outside the valid range are used.<BR>
/// HTML forbids the use of the characters with Universal Character Set/Unicode code points:
/// - 0 to 31, except 9, 10, and 13 (C0 control characters)
/// - 127 (DEL character)
/// - 128 to 159 (x80 - x9F, C1 control characters)
/// - 55296 to 57343 (xD800 - xDFFF, the UTF-16 surrogate halves)
/// see http://en.wikipedia.org/wiki/Character_encodings_in_HTML
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("html", Html);

//----------------------------------------------------------------------------------------
// TODO: (Sebastian) please document punycode
//----------------------------------------------------------------------------------------
MAXON_DECLARATION_STRINGENCODING("punycode", Punycode);



#include "network_ip2.hxx"

}

#endif // NETWORK_IP_H__
