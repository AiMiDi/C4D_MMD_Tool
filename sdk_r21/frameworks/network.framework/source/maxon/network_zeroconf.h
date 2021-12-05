#ifndef NETWORK_ZEROCONF_H__
#define NETWORK_ZEROCONF_H__


#include "maxon/datadictionary.h"
#include "maxon/interface.h"
#include "maxon/network_ip.h"
#include "maxon/observerobject.h"

namespace maxon
{

// TODO: (Sebastian) please document
enum class ZEROCONFACTION
{
	NONE		= 0,
	RESOLVE = (1 << 0),
	MONITOR = (1 << 1)
} MAXON_ENUM_FLAGS(ZEROCONFACTION);

// TODO: (Sebastian) please document
enum class ZEROCONFMACHINESTATE
{
	ONLINE 	= 1,
	OFFLINE	= 2,
	REMOVED	= 3,
	UPDATE 	= 4,
} MAXON_ENUM_LIST(ZEROCONFMACHINESTATE);

// TODO: (Sebastian) please document
enum class ZEROCONFERROR
{
	NONE											= 0,
	UNKNOWN										= -65537,	/* 0xFFFE FFFF */
	NOSUCHNAME								= -65538,
	NOMEMORY									= -65539,
	BADPARAM									= -65540,
	BADREFERENCE							= -65541,
	BADSTATE									= -65542,
	BADFLAGS									= -65543,
	UNSUPPORTED								= -65544,
	NOTINITIALIZED						= -65545,
	ALREADYREGISTERED					= -65547,
	NAMECONFLICT							= -65548,
	INVALID										= -65549,
	FIREWALL									= -65550,
	INCOMPATIBLE							= -65551,	/* Client Library Incompatible with daemon */
	BADINTERFACEINDEX					= -65552,
	REFUSED										= -65553,
	NOSUCHRECORD							= -65554,
	NOAUTH										= -65555,
	NOSUCHKEY									= -65556,
	NATTRAVERSAL							= -65557,
	DOUBLENAT									= -65558,
	BADTIME										= -65559,	/* Codes up to here existed in Tiger */
	BADSIGNAL									= -65560,
	BADKEY										= -65561,
	TRANSIENT									= -65562,
	SERVICENOTRUNNING					= -65563,	/* Background daemon not running */
	NATPORTMAPPINGUNSUPPORTED = -65564,	/* NAT doesn't support NAT_PMP or UPNP */
	NATPORTMAPPINGDISABLED		= -65565,	/* NAT supports NAT-PMP or UPNP but it's disabled by the administrator */
	NOROUTER									= -65566,	/* No router currently configured (probably no network connectivity) */
	POLLINGMODE								= -65567
} MAXON_ENUM_LIST(ZEROCONFERROR);


class NetworkZeroConfBrowserRef;
class NetworkZeroConfServiceRef;

//----------------------------------------------------------------------------------------
/// Class to watch ZeroConf notifications. After starting the browser the signals ObservableDetected
/// and ObservableResolved will be fired whenever machines hooking up, removing from or updating this service.
/// Objects of this class needs to be allocated using NetworkZeroConfInterface::AllocBrowser().
/// This class if reference counted.
//----------------------------------------------------------------------------------------
class NetworkZeroConfBrowserInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(NetworkZeroConfBrowserInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkzeroconfbrowser");

public:
	//----------------------------------------------------------------------------------------
	/// Registers and starts the ZeroConf browser. Make sure that you setup the signals (ObservableDetect, ObservableResolved) before starting the browser.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// Stops and unregister the ZeroConf browser. The callback will not triggered afterwards anymore.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Stop();

public:
	MAXON_OBSERVABLE(ZEROCONFACTION, ObservableDetected, (const NetworkZeroConfBrowserRef& ref, const String& serviceName, Int networkAdapter, ZEROCONFMACHINESTATE state, Bool moreComing, ZEROCONFERROR  error, void* context), ObservableCombinerRunAllEnumFlagsOrComponent);
	MAXON_OBSERVABLE(void, ObservableResolved, (const NetworkZeroConfBrowserRef& ref, const String& serviceName, const String& fullyQualifiedDomainName, Int port, Int networkAdapter, Bool txtRecordUpdate, const DataDictionary& values, ZEROCONFERROR error, void* context), ObservableCombinerRunAllComponent);
};


//----------------------------------------------------------------------------------------
/// NetworkZeroConfServiceInterface allows to broadcast a new network service.
/// Objects for this class will be created using NetworkZeroConfInterface::AllocService().
//----------------------------------------------------------------------------------------
class NetworkZeroConfServiceInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkZeroConfServiceInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkzeroconfservice");

public:
	//----------------------------------------------------------------------------------------
	/// Starts the Service. Other machines will be able to detect this service on the current machine.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// Stops the Service. Other machines are not longer able to detect this service on the current machine.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{default=OK}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Stop();

	//----------------------------------------------------------------------------------------
	/// Adds/Updates the TXT records for the Service. Other machines will see this keys/values when they browse this service.
	/// @param[in] values							DataDictionary of values. The ids of the values should be strings. Otherwise the ids are converted into strings using ToString().
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetTXTRecord(const DataDictionary& values);

	//----------------------------------------------------------------------------------------
	/// Remove all TXT records for the Service. Other machines will not longer see additional informations when they browse this service.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveTXTRecord();
};




// TODO: (Sebastian) please document
class NetworkZeroConfInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NetworkZeroConfInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.networkzeroconf");

public:
	//----------------------------------------------------------------------------------------
	/// Get the version number of the ZeroConf version.
	/// @param[out] versionNumber			Main version number of ZeroConf.
	/// @param[out] revisionNumber		Revision number.
	/// @param[out] isRunning					TODO: (Seb), please document.
	/// @return												True if ZeroConf is installed, otherwise false.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetBonjourVersion(Int& versionNumber, Int& revisionNumber, Bool& isRunning);

	//----------------------------------------------------------------------------------------
	/// Allocates a new NetworkZeroConfBrowserRef.
	/// @param[in] serviceType				Name of the service type to browse. e.g. "_test._tcp"_s.
	/// @param[in] context						User data pointer passed through the notification signals.
	/// @param[in] thirdPartyInstance	TODO: (Seb), please document.
	/// @return												If successful the return value i a new NetworkZeroConfBrowserRef object. otherwise nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkZeroConfBrowserRef> AllocBrowser(const String& serviceType, void* context, Bool thirdPartyInstance = false);

	//----------------------------------------------------------------------------------------
	/// Allocates a new NetworkZeroConfServiceRef.
	/// @param[in] serviceName				Name of the service.
	/// @param[in] serviceType				Name of the service type. e.g. "_test._tcp"_s.
	/// @param[in] networkAdapter			Network adapter to bind the service on. The network adapter is returned by
	///																NetworkAdapterInterface::GetAdapterIndex(). 0 registers the service for all interfaces.
	/// @param[in] port								Network port to bind the service. The port must be > 0 and < 65535 and a valid tcp port. -1 can be set
	///																for an undefined port.
	/// @param[in] domainName					(optional) a domain name where the service is bind to.
	/// @param[in] thirdPartyInstance	TODO: (Seb), please document.
	/// @return												If successful the return value is a new NetworkZeroConfBrowserRef object. otherwise nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkZeroConfServiceRef> AllocService(const String& serviceName, const String& serviceType,
		Int networkAdapter, Int port, const String& domainName = String(), Bool thirdPartyInstance = false);

	//----------------------------------------------------------------------------------------
	/// Announces a service for the given serverIpAndPort, serviceName with optional txtRecords.
	/// @param[in] serverIpAndPort		Ip address and port where a server is running.
	/// @param[in] serviceName				Name of the service.
	/// @param[in] serviceType				Name of the service type to browse. e.g. "_test._tcp"_s.
	/// @param[in] txtRecords					Optional txt records.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NetworkZeroConfServiceRef> AnnounceServer(
		const NetworkIpAddrPort& serverIpAndPort, const String& serviceName, const String& serviceType, const DataDictionary& txtRecords);

	static MAXON_METHOD void ShutdownEntireZeroConfSystem();

	static MAXON_METHOD void RemoveAllThirdPartyZeroConfTasks();
};


#include "network_zeroconf1.hxx"

#include "network_zeroconf2.hxx"


}


#endif // NETWORK_ZEROCONF_H__
