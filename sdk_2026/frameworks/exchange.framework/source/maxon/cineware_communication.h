#ifndef CINEWARE_COMMUNICATION_H__
#define CINEWARE_COMMUNICATION_H__

#include "maxon/matrix.h"

namespace cinema
{
class BaseList2D;
class BaseObject;
class BaseDocument;
class GeListNode;
class BaseSceneHook;
class GeMarker;
class UniqueIDMap;
} // namespace cinema

namespace maxon
{
static const Int32 CINEWARE_SCENEHOOK_ID = 1063096;



/// Sent when the Xref object representing an asset have been inserted and is final (not in drag operation or within the dynamic).
/// BaseSceneHook* const cinewareHook = doc->FindSceneHook(CINEWARE_SCENEHOOK_ID);
///   if (cinewareHook == nullptr)
///			return maxon::NullptrError(MAXON_SOURCE_LOCATION);
/// 
/// AssetAddedMessage msg;
/// msg.addedAsset = obj;
/// cinewareHook->Message(MSG_ASSET_ADDED, &msg);
static const Int32 MSG_ASSET_ADDED = 1065130;
struct AssetAddedMessage
{
	cinema::BaseObject* addedAsset = nullptr;
};

static constexpr Int32 MSG_SCATTER_FINALIZED = 1065386;
struct ScatterObjectFinalizedMessage
{
	cinema::BaseObject* scatterObject = nullptr;
	cinema::BaseObject* distributionCapsule = nullptr;
};

/// @brief Sent by the Ttexture, when it requests to update the material link to the default material.
static constexpr Int32 MSG_MATERIAL_RESET_DEFAULT = 1065490;

/// @brief Id from the VW plugin, it marks that a TextureTag has been created from the VW RW-Texture
static constexpr Int32 MXAEC_VW_DEFAULT_TEXTURETAG = 1065447;

//-------------------------------------------------------------------------------------------------
/// A CinewareCommunicationListenerInterface implementation can be registered (using CinewareCommunicationInterface)
/// to receive notifications about changes in documents. Currently, all objects, materials and render settings are tracked.
//-------------------------------------------------------------------------------------------------
class CinewareCommunicationListenerInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(CinewareCommunicationListenerInterface, MAXON_REFERENCE_NORMAL);
public:
	MAXON_METHOD void Message(cinema::GeListNode* node, Int32 type, void* data);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever the user has made a document change (BaseDocument::SetChanged).
	/// This excludes changes due to animation of values.
	/// @param[in] doc								The changed document.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void DocumentChanged(cinema::BaseDocument* doc);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever a new object is added to the document.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The added object.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListAdded(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever an object is removed from the document.
	/// @param[in] doc								The document to which the removed object belonged.
	/// @param[in] marker							The GeMarker of the object.
	/// @param[in] uidMap							The map of all unique ids set for the object.
	/// @param[in] object							The removed object. This is passed as a void pointer because the object has been freed,
	/// 															so the memory is invalid and none of the BaseList2D functions can be called.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListDeleted(cinema::BaseDocument* doc, const cinema::GeMarker& marker, const cinema::UniqueIDMap& uidMap, const void* object);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever the pointer of an object has changed, for example because of an undo or the "make editable" command.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] newPtr							The new pointer for the object.
	/// @param[in] oldPtr							The old pointer for the object (no longer valid).
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListPointerChanged(cinema::BaseDocument* doc, cinema::BaseList2D* newPtr, const void* oldPtr);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever the parent of an object has changed. If a whole hierarchy is moved, this notification
	/// is sent only for the root object of the moved hierarchy.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The moved object.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListParentChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever some data of an object has changed.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The changed object.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseListDataChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);

	//-------------------------------------------------------------------------------------------------
	/// Called whenever the matrix of an object has changed.
	/// @param[in] doc								The document to which the object belongs.
	/// @param[in] object							The changed object.
	//-------------------------------------------------------------------------------------------------
	MAXON_METHOD void BaseObjectMatrixChanged(cinema::BaseDocument* doc, cinema::BaseList2D* object);
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
