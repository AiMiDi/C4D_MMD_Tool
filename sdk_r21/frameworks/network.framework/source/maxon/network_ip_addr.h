#ifndef NETWORK_IP_ADDR_H__
#define NETWORK_IP_ADDR_H__

#include "maxon/errorbase.h"
#include "maxon/interfacebase.h"
#include "maxon/string.h"


// must not be declared in namespace maxon!
struct in_addr;
struct in6_addr;
#define in_addr6 in6_addr
struct sockaddr_in;
struct sockaddr_in6;
struct sockaddr_storage;
// must not be declared in namespace maxon!

namespace maxon
{

class NetworkIpAddrInterface;
class NetworkIpAddr;

class NetworkIpAddrPortInterface;
class NetworkIpAddrPort;

//----------------------------------------------------------------------------------------
/// Defines the type of an IP address used by NetworkIpAddrInterface.
//----------------------------------------------------------------------------------------
enum class PROTOCOL
{
	UNSPEC = 0,		///< Unspecified.
	IPV4 = 1000,	///< IPV4 address.
	IPV6 = 1001		///< IPV6 address.
} MAXON_ENUM_LIST(PROTOCOL);

//----------------------------------------------------------------------------------------
/// Any IPv4 address. Equivalent to INADDR_ANY.
//----------------------------------------------------------------------------------------
enum class WILDCARD_IPV4_ADDRESS_TYPE
{
	VALUE = 1
} MAXON_ENUM_LIST(WILDCARD_IPV4_ADDRESS_TYPE);

static const WILDCARD_IPV4_ADDRESS_TYPE WILDCARD_IPV4_ADDRESS = WILDCARD_IPV4_ADDRESS_TYPE::VALUE;

//----------------------------------------------------------------------------------------
/// Any IPv6 address. Equivalent to in6addr_any.
//----------------------------------------------------------------------------------------
enum class WILDCARD_IPV6_ADDRESS_TYPE
{
	VALUE = 1
} MAXON_ENUM_LIST(WILDCARD_IPV6_ADDRESS_TYPE);

static const WILDCARD_IPV6_ADDRESS_TYPE WILDCARD_IPV6_ADDRESS = WILDCARD_IPV6_ADDRESS_TYPE::VALUE;

//----------------------------------------------------------------------------------------
/// Any IP port.
//----------------------------------------------------------------------------------------
static const Int WILDCARD_IP_PORT = 0;

//----------------------------------------------------------------------------------------
/// Native storage format of IP addresses. See NetworkIpAddrInterface::GetSockaddrIn() and NetworkIpAddrInterface::SetSockaddrIn().
/// The Members are stored in Motorola / IBM / Network byte-order.
//----------------------------------------------------------------------------------------
struct NetworkSockAddrIn
{
	static const Int IPV4_SIZE = 4;		// IPv4 32-Bit
	static const Int IPV6_SIZE = 16;	// IPv6 128-Bit

	union
	{
		UInt32	ipv4Int;
		UInt64	ipv6Int64s[IPV6_SIZE / 8];

		UChar		ipv4[IPV4_SIZE];
		UChar		ipv6[IPV6_SIZE];
	};
};

//----------------------------------------------------------------------------------------
/// This class represents an Internet Protocol (IP) address.
/// It is version agnostic and supports both IPv4 and IPv6.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class NetworkIpAddrInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkIpAddrInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.networkipaddr");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the internal POD representation of this address.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkSockAddrIn GetNetworkSockAddrIn() const;

	//----------------------------------------------------------------------------------------
	/// Sets the raw NetworkSockAddrIn into this class.
	/// @param[in] sa									Reference to the NetworkSockAddrIn value.
	/// @param[in] protocol						Type of the IP address given in the variable "in".
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetNetworkSockaddrIn(const NetworkSockAddrIn& sa, PROTOCOL protocol);

	//----------------------------------------------------------------------------------------
	/// Resets the content of this value. The protocol is set to PROTOCOL::UNSPEC.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// DEPRECATED. Exists for backward compatibility. Use Reset() instead.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	//----------------------------------------------------------------------------------------
	/// Sets an IPV4 address.
	/// @param[in] ip									IP address to be set.
	/// @param[in] isHostByteOrder		True if the address is delivered in the host specific byte order.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv4(UInt32 ip, Bool isHostByteOrder);

	//----------------------------------------------------------------------------------------
	/// Sets an IPV4 address.
	/// @param[in] a									IP address of the format "a.b.c.d" to be set.
	/// @param[in] b									IP address of the format "a.b.c.d" to be set.
	/// @param[in] c									IP address of the format "a.b.c.d" to be set.
	/// @param[in] d									IP address of the format "a.b.c.d" to be set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv4(UChar a, UChar b, UChar c, UChar d);

	//----------------------------------------------------------------------------------------
	/// Sets an IPV6 address.
	/// @param[in] x1									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x2									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x3									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x4									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x5									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x6									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x7									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	/// @param[in] x8									IP address of the format "x1:x2:x3:x4:x5:x6:x7:x8" to be set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv6(UInt16 x1, UInt16 x2, UInt16 x3, UInt16 x4, UInt16 x5, UInt16 x6, UInt16 x7, UInt16 x8);

	//----------------------------------------------------------------------------------------
	/// Sets an ip v4 address from the native in_addr structure.
	/// @param[in] in									Reference to the ip v4 structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv4(const in_addr& in);

	//----------------------------------------------------------------------------------------
	/// Sets an ip v6 address from the native in_addr6 structure.
	/// @param[in] in									Reference to the ip v6 structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv6(const in_addr6& in);

	//----------------------------------------------------------------------------------------
	/// Sets an ip v4 address from the native sockaddr_in structure.
	/// @param[in] in									Pointer to sockaddr_in structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIPv4(const sockaddr_in* in);

	//----------------------------------------------------------------------------------------
	/// Sets an ip v4 address from the native sockaddr_in6 structure.
	/// @param[in] in									Pointer to sockaddr_in6 structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIPv6(const sockaddr_in6* in);

	//----------------------------------------------------------------------------------------
	/// Sets an IP v4 address from the native in_addr structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv4(WILDCARD_IPV4_ADDRESS_TYPE);

	//----------------------------------------------------------------------------------------
	/// Sets an IP v6 address from the native in_addr structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetIPv6(WILDCARD_IPV6_ADDRESS_TYPE);

	//----------------------------------------------------------------------------------------
	/// Returns the IP v4 address.
	/// @param[out] a									Returns the 'a' component of the address in the format "a.b.c.d".
	/// @param[out] b									Returns the 'b' component of the address in the format "a.b.c.d".
	/// @param[out] c									Returns the 'c' component of the address in the format "a.b.c.d".
	/// @param[out] d									Returns the 'd' component of the address in the format "a.b.c.d".
	/// @return												Returns OK on success or an error if the protocol doesn't match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv4(UChar& a, UChar& b, UChar& c, UChar& d) const;

	//----------------------------------------------------------------------------------------
	/// Returns the IP v6 address.
	/// @param[out] x1								Returns the 'x1' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x2								Returns the 'x2' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x3								Returns the 'x3' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x4								Returns the 'x4' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x5								Returns the 'x5' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x6								Returns the 'x6' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x7								Returns the 'x7' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @param[out] x8								Returns the 'x8' component of the address in the format "x1:x2:x3:x4:x5:x6:x7:x8".
	/// @return												Returns OK on success or an error if the protocol doesn't match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv6(UInt16& x1, UInt16& x2, UInt16& x3, UInt16& x4, UInt16& x5, UInt16& x6, UInt16& x7, UInt16& x8) const;

	//----------------------------------------------------------------------------------------
	/// Returns the IP v4 address as sockaddr_in structure.
	/// @param[out] sockaddr					Pointer to sockaddr_in structure.
	/// @return												Returns OK on success or an error if the protocol doesn't match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv4(sockaddr_in* sockaddr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the IP v6 address as sockaddr_in6 structure.
	/// @param[out] sockaddr					Pointer to sockaddr_in structure.
	/// @return												Returns OK on success or an error if the protocol doesn't match.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv6(sockaddr_in6* sockaddr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the type of the IP address used in this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PROTOCOL GetProtocol() const;

	//----------------------------------------------------------------------------------------
	/// Returns the type of the IP address used in this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD int GetNativeProtocol() const;


	MAXON_METHOD void SetProtocol(PROTOCOL protocol);

	//----------------------------------------------------------------------------------------
	/// Returns whether the IP address is a private address.
	/// The following ranges are defined as private (RFC 1918, Chapter 3):
	///		IPv4: 10/8, 172.16/12, 192.168/16 (IPv4)
	///		IPv6: fc00::/7
	/// For an invalid address, the result is always false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsPrivateAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the IP address is a multicast address.
	/// The following ranges are reserved for multicast:
	///		IPv4: 224.0.0.0/4
	///		IPv6: ff00::/8
	/// For an invalid address, the result is always false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsMulticastAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the IP address is a wildcard address.
	/// This refers to the following addresses:
	///		IPv4: 0.0.0.0 (INADDR_ANY)
	///		IPv6: ::0 (in6addr_any)
	/// For an invalid address, the result is always false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsWildcardAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the value of the IP address is unspecified.
	/// This is true iff GetProtocol() == PROTOCOL::UNSPEC.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsUnspecified() const;

	//----------------------------------------------------------------------------------------
	/// DEPRECATED. Exists for backward compatibility.
	/// Use IsUnspecified() and IsWildcardAddress() instead.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEmpty() const;

	//----------------------------------------------------------------------------------------
	/// DEPRECATED. Exists for backward compatibility.
	/// Use IsUnspecified() and IsWildcardAddress() instead.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsPopulated() const
	{
		return IsEmpty() == false;
	}

	//----------------------------------------------------------------------------------------
	/// DEPRECATED. Exists for backward compatibility.
	/// Use IsUnspecified() and IsWildcardAddress() instead.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsValid() const;

	MAXON_METHOD String GetString(Int32 port = 0) const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return GetString();
	}

	//----------------------------------------------------------------------------------------
	/// Compares the object against another given object.
	/// @param[in] adr								IP address to compare.
	/// @return												True if both ip addresses are identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const NetworkIpAddrInterface* adr) const;

	//----------------------------------------------------------------------------------------
	/// Returns if this address is in the same network as other address based on the given subnet mask.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsInSameNetwork(const NetworkIpAddr& otherAddress, const NetworkIpAddr& subnetMask) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash value of this object. This value can be used for all HashSet<>/HashMap<> classes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;
};

//----------------------------------------------------------------------------------------
/// Provides an Internet Protocol (IP) address + port.
/// This class extends the NetworkIpAddrInterface with a port.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class NetworkIpAddrPortInterface : public NetworkIpAddrInterface
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(NetworkIpAddrPortInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.networkipaddrport");

public:
	static MAXON_METHOD NetworkIpAddrPortInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const NetworkIpAddr& addr, Int32 port);

	//----------------------------------------------------------------------------------------
	/// Sets the port.
	/// @param[in] port								The port or 0 to reset port information.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetPort(Int32 port);

	//----------------------------------------------------------------------------------------
	/// Returns the port.
	/// @return												The port or 0 if no port was set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int32 GetPort() const;

	//----------------------------------------------------------------------------------------
	/// Returns the address without the port.
	/// @return												Returns the address without the port.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NetworkIpAddr GetAddress() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return GetString(true);
	}

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv4AndPort(sockaddr_in* sockaddr) const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPv6AndPort(sockaddr_in6* sockaddr) const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetIPAndPort(sockaddr_storage* sockaddr, Int32& len) const;

	//----------------------------------------------------------------------------------------
	/// Sets an ip v4 address from the native sockaddr_in structure.
	/// @param[in] in									Pointer to sockaddr_in structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIPv4AndPort(const sockaddr_in* in);

	//----------------------------------------------------------------------------------------
	/// Sets an ip v4 address from the native sockaddr_in6 structure.
	/// @param[in] in									Pointer to sockaddr_in6 structure.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIPv6AndPort(const sockaddr_in6* in);

	//----------------------------------------------------------------------------------------
	/// TODO: (Seb) Comment
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetIPAndPort(const sockaddr_storage* in);

	//----------------------------------------------------------------------------------------
	/// Compares the object against another given object.
	/// @param[in] adr								IP address to compare.
	/// @return												True if both ip addresses are identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const NetworkIpAddrPortInterface* adr) const;

	// we have to repeat this method from the base interface, otherwise it would be hidden and we'd get a compile error for the Null implementation
	MAXON_METHOD Bool IsEqual(const NetworkIpAddrInterface* adr) const;
};


#include "network_ip_addr1.hxx"

/// Reference counted class of NetworkIpAddrInterface
class NetworkIpAddr : public NetworkIpAddrInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NetworkIpAddr, Reference);

	NetworkIpAddr(UChar a, UChar b, UChar c, UChar d)
	{
		SetIPv4(a, b, c, d) iferr_cannot_fail("SetIPv4 cannot fail");
	}

	NetworkIpAddr(UInt16 x1, UInt16 x2, UInt16 x3, UInt16 x4, UInt16 x5, UInt16 x6, UInt16 x7, UInt16 x8)
	{
		SetIPv6(x1, x2, x3, x4, x5, x6, x7, x8) iferr_cannot_fail("SetIPv6 cannot fail");
	}

	explicit NetworkIpAddr(WILDCARD_IPV4_ADDRESS_TYPE)
	{
		SetIPv4(0, 0, 0, 0) iferr_cannot_fail("SetIPv4 cannot fail");
	}

	explicit NetworkIpAddr(WILDCARD_IPV6_ADDRESS_TYPE)
	{
		SetIPv6(0, 0, 0, 0, 0, 0, 0, 0) iferr_cannot_fail("SetIPv6 cannot fail");
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return GetString(0);
	}

	const NetworkIpAddrPort operator +(Int32 port) const;
};

class NetworkIpAddrPort : public NetworkIpAddrPortInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NetworkIpAddrPort, NetworkIpAddrPortInterface::Reference);

	NetworkIpAddrPort(UChar a, UChar b, UChar c, UChar d, Int32 port)
	{
		SetIPv4(a, b, c, d) iferr_cannot_fail("SetIPv4 cannot fail");
		SetPort(port) iferr_cannot_fail("SetPort cannot fail");
	}

	NetworkIpAddrPort(UInt16 x1, UInt16 x2, UInt16 x3, UInt16 x4, UInt16 x5, UInt16 x6, UInt16 x7, UInt16 x8, UInt32 port)
	{
		SetIPv6(x1, x2, x3, x4, x5, x6, x7, x8) iferr_cannot_fail("SetIPv6 cannot fail");
		SetPort(port) iferr_cannot_fail("SetPort cannot fail");
	}

	NetworkIpAddrPort(const NetworkIpAddr& addr, Int32 port)
	{
		SetNetworkSockaddrIn(addr.GetNetworkSockAddrIn(), addr.GetProtocol()) iferr_cannot_fail("SetNetworkSockaddrIn cannot fail");
		SetPort(port) iferr_cannot_fail("SetPort cannot fail");
	}

	explicit NetworkIpAddrPort(const sockaddr_storage* addr)
	{
		iferr (SetIPAndPort(addr))
			err.DbgStop();
	}

	NetworkIpAddrPort(WILDCARD_IPV4_ADDRESS_TYPE, Int32 port)
	{
		SetIPv4(WILDCARD_IPV4_ADDRESS) iferr_cannot_fail("SetIPv4 cannot fail");
		SetPort(port) iferr_cannot_fail("SetPort cannot fail");
	}

	NetworkIpAddrPort(WILDCARD_IPV6_ADDRESS_TYPE, Int32 port)
	{
		SetIPv6(WILDCARD_IPV6_ADDRESS) iferr_cannot_fail("SetIPv6 cannot fail");
		SetPort(port) iferr_cannot_fail("SetPort cannot fail");
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const
	{
		return GetString(GetPort());
	}
};

inline const NetworkIpAddrPort NetworkIpAddr::operator +(Int32 port) const
{
	return NetworkIpAddrPort(*this, port);
}

#include "network_ip_addr2.hxx"

}

#endif // NETWORK_IP_ADDR_H__
