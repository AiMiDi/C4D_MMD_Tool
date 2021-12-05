#ifndef OBSERVEROBJECT_H__
#define OBSERVEROBJECT_H__

#include "maxon/apibase.h"
#include "maxon/object.h"
#include "maxon/observable.h"

namespace maxon
{

class ObserverObjectInterface;
class ObserverObjectRef;



//----------------------------------------------------------------------------------------
/// Component to allow objects to use the observable concept.
/// Object interfaces can define observables by writing:
/// @code
/// MAXON_OBSERVABLE(void, ObserverDestroyed, (ObserverObjectInterface* sender), ObservableCombinerRunAllComponent);
/// @endcode
/// A observable can be hooked up by external objects. As soon as a observable is fired all objects get this notification.
//----------------------------------------------------------------------------------------
class ObserverObjectInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ObserverObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.observerobject");

public:
	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Private.
	/// Adds a observable to this object. AddObserver calls this function to connect observables to objects.
	/// @param[in] observable					Adds the given observable to this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddSenderSignal(ObservableBaseInterface* observable);

	//----------------------------------------------------------------------------------------
	/// Private.
	/// Removes a observable from this object. DisconnectAll calls this function to disconnect observables from objects.
	/// @param[in] observable					Adds the given observable to this object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RemoveSenderSignal(ObservableBaseInterface* observable);

	/// @endcond

	//----------------------------------------------------------------------------------------
	/// Returns the name of the object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Sets the name of the object.
	/// @param[in] name								New name to be set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetName(const String& name);

	//----------------------------------------------------------------------------------------
	/// observable: This observable is fired as soon as the object is destroyed.
	/// Please be aware of that it's not longer possible to create BaseRef to this object within this code!
	/// The reason is that the Destroy is called as soon as the last reference is going to 0. As soon as you would do that it would crash!
	/// -observableparam[in] sender				A pointer to the destroyed object. Do not convert this pointer into a BaseRef (see comments above).
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObserverDestroyed, (ObserverObjectInterface* sender), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Observable: This observable is fired as soon as anybody disconnects from a observable of this object.
	/// -observableparam[in] owner				A reference to the object which owns the observable.
	/// -observableparam[in] observableId	The name of the observable that has been disconnected.
	/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObserverDisconnectNotify, (const ObserverObjectRef& owner, const Id& observerId, const ObserverObjectRef& observer), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Observable: This observable is fired as soon as anybody connects to a observable of this object.
	/// -observableparam[in] owner				A reference to the object which owns the observable.
	/// -observableparam[in] observableId	The name of the observable that will be connected.
	/// -observableparam[in] observer			A reference to the connected object. This parameter can be zero, e.g. if a lambda function is connected.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObserverConnectNotify, (const ObserverObjectRef& owner, const Id& observableId, const ObserverObjectRef& observer), ObservableCombinerRunAllComponent);

	// TODO: (Tilo) idea from jan,
	// AddCustomObservable(const Id& observableName, ObservableCustom);
	// FindCustomObservable(const Id& observableName);
	// BrowseCustomObservables();
	// MAXON_OBSERVABLE(void, ObservableCustom, (ObserverObjectRef sender, const DataDictionary& data), NCombinerRunAllVoid);
};

#include "observerobject1.hxx"

MAXON_DECLARATION(Class<ObserverObjectRef>, ObserverObjectClass, "net.maxon.class.observerobject");

#include "observerobject2.hxx"

//----------------------------------------------------------------------------------------
/// This helper template reduces the effort of creating static observables.
///
/// static StaticObservableStorage<LicenseInterface::ObservableLicenseUpdatedDelegate> g_observableLicenseUpdated;
///
/// required code in global Init:
/// g_observableLicenseUpdated.Init("ObservableLicenseUpdated") iferr_return;
///
/// required code in global Free:
/// g_observableLicenseUpdated.Free();
//----------------------------------------------------------------------------------------
template <typename T> class StaticObservableStorage
{
public:
	Result<void> Init(const Char* observableId)
	{
		iferr_scope;

		_notificationObject = NewObj(ObserverObjectRef) iferr_return;
		*_notificationObject = ObserverObjectClass().Create() iferr_return;

		_observable = NewObj(ObservableType) iferr_return;
		_observable->Init(*_notificationObject, Id(observableId)) iferr_return;

		return OK;
	}

	void Free()
	{
		if (_observable)
		{
			_observable->Free();
			DeleteObj(_observable);
		}
		DeleteObj(_notificationObject);
	}

	ObservableRef<T> Get()
	{
		return _observable ? *_observable : ObservableRef<T>();
	}

private:
	using ObservableType = ObservableImplRef<ObservableClassPrivateHelper, T>;

	ObserverObjectRef* _notificationObject = nullptr;
	ObservableType*		 _observable = nullptr;
};

}


#endif // OBSERVEROBJECT_H__
