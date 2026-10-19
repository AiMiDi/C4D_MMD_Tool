#ifndef CINEWARE_COMMUNICATION_H__
#define CINEWARE_COMMUNICATION_H__

#include "maxon/url.h"
#include "maxon/fixedsizebitset.h"

namespace cinema
{
class BaseList2D;
class BaseObject;
class BaseDocument;
class BaseContainer;
class GeListNode;
class BaseSceneHook;
class GeMarker;
class UniqueIDMap;
} // namespace cinema

namespace maxon
{
//-------------------------------------------------------------------------------------------------
/// A CinewareCommunicationListenerInterface implementation can be registered (using CinewareCommunicationInterface)
/// to receive notifications about changes in documents. Currently, all objects, materials and render settings are tracked.
//-------------------------------------------------------------------------------------------------
class CinewareCommunicationListenerInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(CinewareCommunicationListenerInterface, MAXON_REFERENCE_NORMAL);

public:
	//----------------------------------------------------------------------------------------
	/// Called whenever the user has made a change of the active camera.
	/// @param[in] doc								The document of the active camera.
	/// @param[in] camera							The changed camera object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void CameraChanged(cinema::BaseDocument* doc, cinema::BaseObject* camera);

	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Message(cinema::GeListNode* node, Int32 type, void* data);
	MAXON_METHOD void CoreMessage(maxon::Int32 id, const cinema::BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Called whenever the user has made a document change (BaseDocument::SetChanged).
	/// This excludes changes due to animation of values.
	/// @param[in] doc								The changed document.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void DocumentChanged(cinema::BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Called whenever a new object is added to the document.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The added object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListAdded(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// Called whenever an object is removed from the document.
	/// @param[in] doc								The document to which the removed object belonged.
	/// @param[in] marker							The GeMarker of the object.
	/// @param[in] uidMap							The map of all unique ids set for the object.
	/// @param[in] nbits							The n-bits of the object.
	/// @param[in] object							The removed object. This is passed as a void pointer because the object has been freed,
	/// 															so the memory is invalid and none of the BaseList2D functions can be called.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListDeleted(cinema::BaseDocument* doc, const cinema::GeMarker& marker, const cinema::UniqueIDMap& uidMap, const FixedSizeBitSet<7>& nbits, const void* object);

	//----------------------------------------------------------------------------------------
	/// Called whenever the pointer of an object has changed, for example because of an undo or the "make editable" command.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] newPtr							The new pointer for the object.
	/// @param[in] oldPtr							The old pointer for the object (no longer valid).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListPointerChanged(cinema::BaseDocument* doc, cinema::BaseList2D* newPtr, const void* oldPtr);

	//----------------------------------------------------------------------------------------
	/// Called whenever the parent of an object has changed. If a whole hierarchy is moved, this notification
	/// is sent only for the root object of the moved hierarchy.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The moved object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListParentChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// Called whenever some data of an object has changed.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The changed object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListDataChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// Called whenever the matrix of an object has changed.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The changed object.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BaseObjectMatrixChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// Called once, before any per-object notifications (e.g. BaseListAdded, BaseListDeleted, 
	/// BaseListDataChanged, BaseObjectMatrixChanged) are dispatched for the given document.
	/// @note Called only if a change is made to the document, if no changes is made this is not called.
	/// @param[in] doc								The document whose scene hierarchy is about to be traversed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void BeginChanges(cinema::BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Called once at the end of a scene change detection pass, after all per-object
	/// notifications (e.g. BaseListAdded, BaseListDeleted, BaseListDataChanged, BaseObjectMatrixChanged)
	/// for the given document have been dispatched.
	/// @note Called only if BeginChanges is called, if no changes is made this is not called.
	/// @param[in] doc								The document whose scene hierarchy has just been traversed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void EndChanges(cinema::BaseDocument* doc);
};

class CinewareCommunicationListenerRef;

class CinewareCommunicationInterface
{
	MAXON_INTERFACE_NONVIRTUAL(CinewareCommunicationInterface, MAXON_REFERENCE_NONE, "net.maxon.interfaces.cinewarecommunication");

public:

	static MAXON_METHOD Result<GenericData> AddListener(const CinewareCommunicationListenerRef& listener);

	using ListenersArray = BufferedBaseArray<CinewareCommunicationListenerRef, 16>;

	static MAXON_METHOD Result<void> GetListeners(ListenersArray& listeners);

	static MAXON_METHOD cinema::BaseSceneHook* FindSceneHook(cinema::BaseDocument* doc);

	static MAXON_METHOD cinema::BaseList2D* FindObject(const cinema::BaseSceneHook* hook, const maxon::UniqueHash& objectHash);

	static MAXON_METHOD CinewareCommunicationListenerRef GetListener(const GenericData& handle);
};

#include "cineware_communication1.hxx"

#include "cineware_communication2.hxx"

} // namespace maxon

#endif // CINEWARE_COMMUNICATION_H__
