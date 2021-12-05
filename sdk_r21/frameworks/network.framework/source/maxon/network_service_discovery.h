#ifndef NETWORK_SERVICE_DISCOVERY_H__
#define NETWORK_SERVICE_DISCOVERY_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/hashmap.h"
#include "maxon/timer.h"
#include "maxon/tuple.h"
#include "maxon/uuid.h"
#include "maxon/optional.h"
#include "network_types.h"

#include "maxon/network_ip_addr.h"
#include "maxon/network_ioservice.h"

namespace maxon
{

struct ResourceIdentifier;
struct ServiceProviderDetails;

class ServiceAnnouncementRequestInterface;
class ServiceAnnouncementRequestRef;

class ServiceSubscriptionRequestInterface;
class ServiceSubscriptionRequestRef;

class ServiceAnnouncementInterface;
class ServiceAnnouncementRef;

class ServiceSubscriptionInterface;
class ServiceSubscriptionRef;

class ServiceBusInterface;
class ServiceBusRef;


// Common definitions
struct ServiceDiscovery
{
	using DataMap = HashMap<String, String>;

	struct JoinContext
	{
		JoinContext(const ServiceBusInterface& bus, const ResourceIdentifier& identifier, const ServiceProviderDetails& provider, const DataMap& data)
			: serviceBus(bus), serviceIdentifier(identifier), serviceProvider(provider), serviceData(data) { }

		JoinContext(const JoinContext&) = default;
		JoinContext& operator =(const JoinContext&) = default;

		const ServiceBusInterface&		serviceBus;
		const ResourceIdentifier&			serviceIdentifier;
		const ServiceProviderDetails&	serviceProvider;
		const DataMap&								serviceData;
	};

	struct LeaveContext
	{
		LeaveContext(const ServiceBusInterface& bus, const ResourceIdentifier& identifier, const ServiceProviderDetails& provider)
			: serviceBus(bus), serviceIdentifier(identifier), serviceProvider(provider) { }

		LeaveContext(const LeaveContext&) = default;
		LeaveContext& operator =(const LeaveContext&) = default;

		const ServiceBusInterface&		serviceBus;
		const ResourceIdentifier&			serviceIdentifier;
		const ServiceProviderDetails&	serviceProvider;
	};

	using JoinCallback = Delegate<void(JoinContext ctx, Bool moreComing)>;
	using UpdateCallback = Delegate<void(JoinContext ctx, Bool moreComing)>;
	using LeaveCallback = Delegate<void(LeaveContext ctx, Bool moreComing)>;
};

//----------------------------------------------------------------------------------------
/// A named resource with a specific version and a qualified domain name.
//----------------------------------------------------------------------------------------
struct ResourceIdentifier
{
	ResourceIdentifier() = default;

	ResourceIdentifier(const ResourceIdentifier&) = default;
	ResourceIdentifier& operator =(const ResourceIdentifier&) = default;

	ResourceIdentifier(ResourceIdentifier&&) = default;
	ResourceIdentifier& operator =(ResourceIdentifier&&) = default;

	ResourceIdentifier(const String& domainIn, const String& nameIn, Int versionIn = 0) : domain(domainIn), name(nameIn), version(versionIn) { }

	String	domain;
	String	name;
	Int			version = 0;

	friend Bool operator ==(const ResourceIdentifier& lhs, const ResourceIdentifier& rhs);
	friend Bool operator !=(const ResourceIdentifier& lhs, const ResourceIdentifier& rhs);
};

inline Bool operator ==(const ResourceIdentifier& lhs, const ResourceIdentifier& rhs)
{
	return lhs.domain.Compare(rhs.domain) == COMPARERESULT::EQUAL && lhs.name.Compare(rhs.name) == COMPARERESULT:: EQUAL && lhs.version == rhs.version;
}

inline Bool operator !=(const ResourceIdentifier& lhs, const ResourceIdentifier& rhs)
{
	return !(lhs == rhs);
}

//----------------------------------------------------------------------------------------
/// A servicer provider identified by its device UUID and address.
//----------------------------------------------------------------------------------------
struct ServiceProviderDetails
{
	ServiceProviderDetails() = default;

	ServiceProviderDetails(const ServiceProviderDetails&) = default;
	ServiceProviderDetails& operator =(const ServiceProviderDetails&) = default;

	ServiceProviderDetails(ServiceProviderDetails&&) = default;
	ServiceProviderDetails& operator =(ServiceProviderDetails&&) = default;

	ServiceProviderDetails(const String& uuidIn, const NetworkIpAddr& addressIn) : uuid(uuidIn), address(addressIn) { }

	String					uuid;
	NetworkIpAddr		address;

	friend Bool operator ==(const ServiceProviderDetails& lhs, const ServiceProviderDetails& rhs);
	friend Bool operator !=(const ServiceProviderDetails& lhs, const ServiceProviderDetails& rhs);
};

inline Bool operator ==(const ServiceProviderDetails& lhs, const ServiceProviderDetails& rhs)
{
	return lhs.uuid.Compare(rhs.uuid) == COMPARERESULT::EQUAL && lhs.address.IsEqual(rhs.address);
}

inline Bool operator !=(const ServiceProviderDetails& lhs, const ServiceProviderDetails& rhs)
{
	return !(lhs == rhs);
}

//----------------------------------------------------------------------------------------
/// A service announcement request to be passed to NetworkServiceBusInterface::Announce.
/// Contains a service identifier and optionally custom data in the form of key-value pairs.
//----------------------------------------------------------------------------------------
class ServiceAnnouncementRequestInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ServiceAnnouncementRequestInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.serviceannouncementrequest");

public:
	//----------------------------------------------------------------------------------------
	/// Allocates a service announcement request for a service described by the given identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ServiceAnnouncementRequestInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const ResourceIdentifier& identifier);

	//----------------------------------------------------------------------------------------
	/// Returns the service identifier of this request.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResourceIdentifier GetServiceIdentifier() const;

	//----------------------------------------------------------------------------------------
	/// Timing details for this service announcement.
	//----------------------------------------------------------------------------------------
	struct TimingProperties
	{
		/// Interval of keep-alive messages.
		/// Setting this lower allows for a shorter timeout, but also increases network traffic.
		TimeValue refreshInterval = Seconds(10);

		/// Wait time between last received message and timeout. Should be ~2-3x refreshInterval.
		/// Setting this lower means timeouts are detected faster, but also increases risk of false negatives.
		TimeValue timeout = Seconds(25);
	};

	//----------------------------------------------------------------------------------------
	/// Sets the timing properties of this request.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetTimingProperties(TimingProperties props);

	//----------------------------------------------------------------------------------------
	/// Returns the timing properties of this request.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimingProperties GetTimingProperties() const;

	//----------------------------------------------------------------------------------------
	/// Sets custom data associated with this announcement request, provided as key/value pairs.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetCustomData(ServiceDiscovery::DataMap&& customData);

	//----------------------------------------------------------------------------------------
	/// Returns the custom data of this request.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ServiceDiscovery::DataMap& GetCustomData() const;
};

//----------------------------------------------------------------------------------------
/// A service subscription request to be passed to NetworkServiceBusInterface::Subscribe.
/// Callbacks for join/update/leave events can be added to the request before it is submitted.
//----------------------------------------------------------------------------------------
class ServiceSubscriptionRequestInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ServiceSubscriptionRequestInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.servicesubscriptionrequest");

public:
	//----------------------------------------------------------------------------------------
	/// Allocates a service subscription request for a service described by the given identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD ServiceSubscriptionRequestInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const ResourceIdentifier& identifier);

	//----------------------------------------------------------------------------------------
	/// Returns the service identifier of this request.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResourceIdentifier GetServiceIdentifier() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current join callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ServiceDiscovery::JoinCallback& GetJoinCallback() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current update callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ServiceDiscovery::UpdateCallback& GetUpdateCallback() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current leave callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const ServiceDiscovery::LeaveCallback& GetLeaveCallback() const;

	//----------------------------------------------------------------------------------------
	/// Sets the current join callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetJoinCallback(ServiceDiscovery::JoinCallback cb);

	//----------------------------------------------------------------------------------------
	/// Sets the current update callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetUpdateCallback(ServiceDiscovery::UpdateCallback cb);

	//----------------------------------------------------------------------------------------
	/// Sets the current leave callback.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetLeaveCallback(ServiceDiscovery::LeaveCallback cb);
};

//----------------------------------------------------------------------------------------
/// An active service announcement.
//----------------------------------------------------------------------------------------
class ServiceAnnouncementInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ServiceAnnouncementInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.serviceannouncement");

public:
	using ModifierCallback = Delegate<Result<void>(ServiceDiscovery::DataMap& customData)>;

	//----------------------------------------------------------------------------------------
	/// Returns the service bus this announcement is bound to.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ServiceBusRef GetServiceBus() const;

	//----------------------------------------------------------------------------------------
	/// Cancels the announcement if it is active.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Cancel();

	//----------------------------------------------------------------------------------------
	/// Calls the passed delegate, which can then modify the custom data associated with
	/// this announcement.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ModifyCustomData(const ModifierCallback& modifyFunc);
};

//----------------------------------------------------------------------------------------
/// An active service subscription.
//----------------------------------------------------------------------------------------
class ServiceSubscriptionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ServiceSubscriptionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.servicesubscription");

public:
	using ReconfirmCallback = Delegate<void(Bool isConfirmed)>;

	//----------------------------------------------------------------------------------------
	/// Returns the service bus this subscription is bound to.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ServiceBusRef GetServiceBus() const;

	//----------------------------------------------------------------------------------------
	/// Cancels the subscription if it is active.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Cancel();
};

//----------------------------------------------------------------------------------------
/// This class represents an access point to the service discovery bus.
/// It manages announcements and subscriptions.
//----------------------------------------------------------------------------------------
class ServiceBusInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ServiceBusInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.servicebus");

public:
	static MAXON_METHOD ServiceBusInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Settings for the service discovery bus.
	//----------------------------------------------------------------------------------------
	struct Parameters
	{
		/// The IP multicast address used to send and receive and service discovery messages.
		Optional<NetworkIpAddrPort> multicastAddress;

		/// A pre-defined UUID that should be assigned to this service bus endpoint.
		Optional<String> uuid;
	};

	//----------------------------------------------------------------------------------------
	/// Starts the service bus with custom parameters.
	/// After it has been started successfully, the bus broadcasts announcements and listens
	/// for subscriptions on the local network.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start(const Parameters& props);

	//----------------------------------------------------------------------------------------
	/// Starts the service bus with default parameters.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// Stops the service bus if it was running.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Stop();

	//----------------------------------------------------------------------------------------
	/// Registers a new announcement at this service bus endpoint.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ServiceAnnouncementRef> Announce(const ServiceAnnouncementRequestRef& request);

	//----------------------------------------------------------------------------------------
	/// Registers a new subscription at this service bus endpoint.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ServiceSubscriptionRef> Subscribe(const ServiceSubscriptionRequestRef& request);

	//----------------------------------------------------------------------------------------
	/// Returns the UUID that identifies this service bus endpoint.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Uuid GetLocalUuid() const;

	//----------------------------------------------------------------------------------------
	/// Returns the job queue used to synchronize events on this service bus.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD JobQueueRef GetSyncQueue() const;
};

#include "network_service_discovery1.hxx"
#include "network_service_discovery2.hxx"


} // namespace maxon

#endif // NETWORK_SERVICE_DISCOVERY_H__
