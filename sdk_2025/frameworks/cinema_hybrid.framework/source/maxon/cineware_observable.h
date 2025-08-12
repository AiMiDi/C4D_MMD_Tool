#ifndef _CINEWARE_OBSERVABLE_H__
#define _CINEWARE_OBSERVABLE_H__
#include "maxon/apibase.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/fid.h"
#include "maxon/array.h"

static maxon::Int32 g_cinewareObservableGenericId = -1;
namespace maxon
{

namespace CinewareEvent
{
namespace DocInfoData
{
	MAXON_ATTRIBUTE(Int32, FILEFORMAT, "net.maxon.cineware.event.docinfo.fileformat");
	MAXON_ATTRIBUTE(void*, DOC, "net.maxon.cineware.event.docinfo.basedocument");
	MAXON_ATTRIBUTE(Url, FILENAME, "net.maxon.cineware.event.docinfo.filename");
	MAXON_ATTRIBUTE(void*, BL, "net.maxon.cineware.event.docinfo.baselist2d");
	MAXON_ATTRIBUTE(Bool, GUIALLOWED, "net.maxon.cineware.event.docinfo.guiallowed");
	MAXON_ATTRIBUTE(void*, DATA, "net.maxon.cineware.event.docinfo.data");
	MAXON_ATTRIBUTE(Int32, TYPE, "net.maxon.cineware.event.docinfo.type");
} // namespace CinewareDocumentInfoData

MAXON_ATTRIBUTE(Id, TYPE, "net.maxon.cineware.event.eventType",
	RESOURCE_DEFINE(ENUM_GENERAL, LiteralId("general"))
	RESOURCE_DEFINE(ENUM_MERGE, LiteralId("merge"))
	RESOURCE_DEFINE(ENUM_OBJECT, LiteralId("object"))
	RESOURCE_DEFINE(ENUM_TAG, LiteralId("tag"))
	RESOURCE_DEFINE(ENUM_MAT, LiteralId("mat")));

} // namespace CinewareEvent


class CinewareObservableRef;

class CinewareObservableBaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CinewareObservableBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.cinewareobservablebase");

public:
	MAXON_METHOD void														Init(Int32 type, DataDictionary& data);
	static Result<void>													Register();
	static void																	Free();
	MAXON_METHOD Result<const DataDictionary&>	GetAndCheckData(const Id& typeToCheck) const;
};

class CinewareObservableInterface : MAXON_INTERFACE_BASES(CinewareObservableBaseInterface, ObserverObjectInterface)
{
	MAXON_INTERFACE(CinewareObservableInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.cinewareobservable");

public:
	MAXON_METHOD void											NotifyCinewareHost();
	MAXON_OBSERVABLE(void, ObservableSceneChanged, (void*, const DataDictionary& info), ObservableCombinerRunAllComponent);

};

#include "cineware_observable1.hxx"

MAXON_DECLARATION(Class<CinewareObservableBaseRef>, CinewareObservableBaseClass, "net.maxon.class.cinewareobservable.base");
MAXON_DECLARATION(Class<CinewareObservableRef>, CinewareObservableGeneralClass, "net.maxon.class.cinewareobservable.generic");
MAXON_DECLARATION(Class<CinewareObservableRef>, CinewareObservableMergeClass, "net.maxon.class.cinewareobservable.doc");
MAXON_DECLARATION(Class<CinewareObservableRef>, CinewareObservableObjecClass, "net.maxon.class.cinewareobservable.object");
MAXON_DECLARATION(Class<CinewareObservableRef>, CinewareObservableTagClass, "net.maxon.class.cinewareobservable.tag");


// Factory to find the right implementation for the event.
struct CinewareEventFactoryRegisterType
{
		Array<Int32>								 EventId; // The object Id.
		Class<CinewareObservableRef> _class;	// The class to instantiate the right event implementation.
};

MAXON_DATATYPE(CinewareEventFactoryRegisterType, "net.maxon.cineware.datatype.cinewareeventfactoryregistertype");

/// This factory allow to find the right implementation. The Implementation will notify the host.
using HostEventNotification = Factory<CinewareObservableRef(Int32 type, DataDictionary& data)>;
MAXON_DECLARATION(HostEventNotification, HostEventNotificationFactory,	
	"net.maxon.cineware.factory.hosteventnotification");


namespace ObservableClasses
{
MAXON_REGISTRY(CinewareEventFactoryRegisterType, CinewareEvents,
			"net.maxon.cinewre.registry.cinewareeventfactoryregistertype");
}


#include "cineware_observable2.hxx"

} // namespace maxon
#endif // MYHEADER_H