#ifndef NETWORK_PROXY_H__
#define NETWORK_PROXY_H__

#include "maxon/url.h"

namespace maxon
{

namespace URLFLAGS
{
	/// Don't use a proxy for this url.
	/// This should only be used for very specific reasons (e.g. the internal proxy loader needs to suppress using a proxy)
	MAXON_ATTRIBUTE(Bool, NETWORK_SUPRESS_PROXY, "net.maxon.url.network_supress_proxy");
}

//----------------------------------------------------------------------------------------
/// This interface allows handle proxy settings of the os for internet connection.
//----------------------------------------------------------------------------------------
class NetworkProxyInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkProxyInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkproxy");

public:

	//----------------------------------------------------------------------------------------
	/// Determines the right proxy for the given urls scheme and authority/server.
	///
	/// Windows: At the moment we support the following windows proxy setups. Network Settings/Internet Options/Connections/LAN Settings you can find the proxy settings for windows/internet explorer.
	/// 1. "Automatic detect settings" - retrieves the proxy settings via dhcp in form of a pac file. this file will be used to find the best fitting proxies.
	/// 2. "Use automatic configuration script" - loads a pac file from a given url and uses this file to find the best fitting proxies.
	/// 3. "Use a proxy server ..." - if 1 and 2 fails or is not available the function uses the manual settings for each kind of scheme.
	/// A nice article can be found here: "http://blogs.msdn.com/b/ieinternals/archive/2013/10/11/web-proxy-configuration-and-ie11-changes.aspx".
	///
	/// OSX: At the moment we support the following OSX proxy setups. System Preferences/Network/Additional Options/Proxies:
	/// 1. "Automatic Proxy Detection" - retrieves the proxy settings via dhcp in form of a pac file. this file will be used to find the best fitting proxies.
	/// 2. "Automatic Proxy Configuration" - uses the given .pac file for the proxy settings to find the best fitting proxies.
	/// 3. "HTTP, HTTPS, FTP, SOCKS" - uses the manual proxy settings to detect the best proxy.
	///
	/// @param[in] url								Url to be used to determine the right proxy servers for this connection.
	/// @return												Returns the proxies in the order of the access. The best suited is the first.
	/// 															If the string is equal to PROXY_DIRECT then no proxy must be used and a direct connection can be used instead.
	/// 															The function returns at least one entry (e.g. PROXY_DIRECT).
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<String>> DetectProxiesForUrl(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Resets all cached proxy configuration files.
	/// This function can be called if network changes are not detected correctly.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void FlushProxyCache();
};

#include "network_proxy1.hxx"
#include "network_proxy2.hxx"

#define PROXY_DIRECT "DIRECT"_s

}

#endif // NETWORK_PROXY_H__
