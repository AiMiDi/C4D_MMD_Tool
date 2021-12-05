#ifndef NETWORK_IP_SSL_H__
#define NETWORK_IP_SSL_H__

#include "maxon/network_ip.h"
#include "maxon/url.h"

namespace maxon
{

enum class SSLSOCKETTYPE
{
	CLIENTCONNECTION,
	SERVERCONNECTION,
} MAXON_ENUM_LIST(SSLSOCKETTYPE);

/// Defines possible ssl protocol versions
enum class SSLPROTOCOLVERSION
{
	TLS1,		///< use TLS1.
	TLS11,	///< use TLS1.1.
	TLS12,	///< use TLS1.2.
	SSL3,		///< use SSL3.
	SSL2,		///< use SSL2.
	SSL23,	///< use SSL2 or SSL3.
} MAXON_ENUM_LIST(SSLPROTOCOLVERSION);

/// Defines possible ssl certificate verification options.
enum class SSLCERTREQUIREMENTS
{
	NONE				= 0,					///< mode: no certificate is required.
	OPTIONAL		= 1,					///< mode: a certificate is optional. If this flag is set you need to deliver a valid caCertsFile file in the SSLNetworkConnectionInterface::Init() function.
	REQUIRED		= 2,					///< mode: a server certificate is required and need to have a valid ca root. If this flag is set you need to deliver a valid caCertsFile file in the SSLNetworkConnectionInterface::Init() function.

	MODE							= (0xff),
	VERIFY_AUTHORITY	= (1 << 8),		///< flag: verifies the server certificate with the given url. if the server authority pattern doesn't match an error is returned in the handshake.
} MAXON_ENUM_FLAGS(SSLCERTREQUIREMENTS);

// extend the URLFLAGS
namespace URLFLAGS
{
	MAXON_ATTRIBUTE(SSLPROTOCOLVERSION, SSLPROTOCOL, "net.maxon.url.sslprotocol");	///< Sets ssl protocol version for ssl connection.
	MAXON_ATTRIBUTE(SSLCERTREQUIREMENTS, SSLREQUIREMENTS, "net.maxon.url.sslrequirements");	///< Sets the required ssl certificate options. The default value is SSLCERTREQUIREMENTS::REQUIRED | SSLCERTREQUIREMENTS::VERIFY_AUTHORITY.
}


enum class SSLFILETYPE
{
	ASN1	= 2, // X509_FILETYPE_ASN1
	PEM	  = 1, // X509_FILETYPE_PEM
} MAXON_ENUM_LIST(SSLFILETYPE);


//----------------------------------------------------------------------------------------
/// This class handles SSL encrypted network connections.
//----------------------------------------------------------------------------------------
class SSLNetworkConnectionInterface : MAXON_INTERFACE_BASES(NetworkConnectionInterface)
{
	MAXON_INTERFACE(SSLNetworkConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.sslnetworkconnection");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the object. This connection wraps a basic NetworkConnectionRef into an SSL connection.
	/// @param[in] authority					Server Name/Authority. This name will be used to compare it against the certificate common name when SSLCERTREQUIREMENTS::VERIFY_AUTHORITY is set.
	/// @param[in] wrapConnection			Wraps a basic ip connection into an SSL layer.
	/// @param[in] type								Select if the connection is a server or client connection.
	/// @param[in] protocolVersion		Choose the SSL encryption type.
	/// @param[in] certRequire				Option to select if certificates are required or not.
	/// @param[in] keyFile						TODO: (Anybody) not implemented yet.
	/// @param[in] certificateFile		TODO: (Anybody) not implemented yet.
	/// @param[in] caCertsFile				Url to a file with trusted ca root certificates to verify the server certificate. You can use SSLNetworkConnectionInterface::GetDefaultCaCertsFile() to get the applications default ca file.
	/// @param[in] useClientCertOverride	TODO: (Anybody) describe.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const String& authority, const NetworkConnectionRef& wrapConnection, SSLSOCKETTYPE type, SSLPROTOCOLVERSION protocolVersion, SSLCERTREQUIREMENTS certRequire, const Url& keyFile, const Url& certificateFile, const Url& caCertsFile, Bool useClientCertOverride);

	//----------------------------------------------------------------------------------------
	/// Executes the handshake with the server.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DoHandShake();

	//----------------------------------------------------------------------------------------
	/// Returns the default ca certification file with trusted root certificates.
	/// @return												Returns the url with the application default trusted ca root certificates.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetDefaultCaCertsFile() const;

	//----------------------------------------------------------------------------------------
	/// Returns the name of the cipher being.
	/// @return												Returns the name after the handshake succeeded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetCipherName();
};


#include "network_ip_ssl1.hxx"

MAXON_DECLARATION(Class<SSLNetworkConnectionRef>, NetworkConnectionSSLClass, "net.maxon.class.networkconnectionssl");

#include "network_ip_ssl2.hxx"

}


#endif // NETWORK_IP_SSL_H__
