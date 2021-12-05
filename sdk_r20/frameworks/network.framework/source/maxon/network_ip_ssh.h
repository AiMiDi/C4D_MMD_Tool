#ifndef NETWORK_IP_SSH_H__
#define NETWORK_IP_SSH_H__

#include "maxon/network_ip.h"

struct _LIBSSH2_SESSION;
typedef struct _LIBSSH2_SESSION LIBSSH2_SESSION;

namespace maxon
{

// stylecheck.naming=false

using SSH_CHANGE_PASSWORD_CALLBACK = void(*)(String& newPassword);

//----------------------------------------------------------------------------------------
/// This class handles SSH encrypted network connections.
//----------------------------------------------------------------------------------------
class SSHNetworkConnectionInterface : MAXON_INTERFACE_BASES(NetworkConnectionInterface)
{
	MAXON_INTERFACE(SSHNetworkConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.sshnetworkconnection");

public:
	MAXON_METHOD Result<void> Init(const NetworkConnectionRef& connection, Bool blocking);
	MAXON_METHOD Result<void> DoHandShake();
	MAXON_METHOD Result<void> LogIn(const String& name, const String& password, SSH_CHANGE_PASSWORD_CALLBACK changePasswordCallback = nullptr);
	MAXON_METHOD LIBSSH2_SESSION* GetSession();

	//----------------------------------------------------------------------------------------
	/// Gets the fingerprint of the server.
	/// @return												The server's fingerprint.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const String& GetFingerprint() const;
};


#include "network_ip_ssh1.hxx"

MAXON_DECLARATION(Class<SSHNetworkConnectionRef>, NetworkConnectionSSHClass, "net.maxon.class.networkconnectionssh");

#include "network_ip_ssh2.hxx"

}

#endif // NETWORK_IP_SSH_H__
