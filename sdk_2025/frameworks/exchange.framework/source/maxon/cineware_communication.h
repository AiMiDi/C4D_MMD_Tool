#ifndef CINEWARE_COMMUNICATION_H__
#define CINEWARE_COMMUNICATION_H__

#include "maxon/matrix.h"
#include "maxon/observerobject.h"

namespace cinema
{
class BaseObject;
class BaseDocument;
class GeListNode;
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

class CinewareCommunicationListenerInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(CinewareCommunicationListenerInterface, MAXON_REFERENCE_NORMAL);
public:
	MAXON_METHOD void Message(cinema::GeListNode* node, Int32 type, void* data);

	MAXON_METHOD void ObjectAdded(cinema::BaseDocument* doc, cinema::BaseObject* object);

	MAXON_METHOD void ObjectMatrixChanged(cinema::BaseDocument* doc, cinema::BaseObject* object);

	MAXON_METHOD void ObjectDataChanged(cinema::BaseDocument* doc, cinema::BaseObject* object);
};

class CinewareCommunicationListenerRef;

class CinewareCommunicationInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(CinewareCommunicationInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.cinewarecommunication");

public:
	MAXON_OBSERVABLE(Result<Int32>, ObservableMessage, (void* node, Int32 type, void* data), ObservableCombinerRunAllComponent);
	MAXON_METHOD Result<Bool> NotifyHost(void* node, Int32 type, void* data);

	static MAXON_METHOD Result<GenericData> AddListener(const CinewareCommunicationListenerRef& listener);

	using ListenersArray = BufferedBaseArray<CinewareCommunicationListenerRef, 16>;

	static MAXON_METHOD Result<void> GetListeners(ListenersArray& listeners);
};

#include "cineware_communication1.hxx"

MAXON_DECLARATION(Class<CinewareCommunicationRef>, CinewareCommunicationClass, "net.maxon.class.cinewarecommunication.message");

#include "cineware_communication2.hxx"

} // namespace maxon

#endif // CINEWARE_COMMUNICATION_H__
