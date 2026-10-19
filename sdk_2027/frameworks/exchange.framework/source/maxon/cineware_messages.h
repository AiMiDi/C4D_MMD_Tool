#ifndef CINEWARE_MESSAGES_H__
#define CINEWARE_MESSAGES_H__

#include "maxon/matrix.h"
#include "maxon/url.h"

namespace cinema
{
class BaseList2D;
class BaseObject;
class BaseMaterial;
class BaseTag;
} // namespace cinema

namespace maxon
{

// Here we store all application IDs of known hosts using Cineware to identify the objects origins.
// This list needs to get extended if more integrations of Cineware and Redshift have been implemented.
static constexpr Int32 APPLICATION_ID_VECTORWORKS = 310003000;
static constexpr Int32 APPLICATION_ID_ARCHICAD = 1032064;
static constexpr Int32 APPLICATION_ID_REVIT = 1067207;

// Command ID for sending Cineware undo commands to host application, bypassing Cinema 4D's normal undo behavior.
static constexpr Int32 AEC_UNDO_CMD_ID = 1067118;
// Command ID for sending Cineware redo commands to host application, bypassing Cinema 4D's normal redo behavior.
static constexpr Int32 AEC_REDO_CMD_ID = 1067119;

// Inform AEC host that an undo operation is requested.
static constexpr Int32 MSG_SHOULD_DO_UNDO_IN_AEC = 1067069;

// Inform AEC host that an redo operation is requested.
static constexpr Int32 MSG_SHOULD_DO_REDO_IN_AEC = 1067070;

// Inform AEC host that a save operation is requested.
static constexpr Int32 MSG_SAVE_IN_HOST_FROM_AEC = 1067948;

static constexpr Int32 CINEWARE_SCENEHOOK_ID = 1063096;
static constexpr Int32 CINEWARE_COREMESSAGE = 1066498;

/// Sent when the Xref object representing an asset have been inserted and is final (not in drag operation or within the dynamic).
/// BaseSceneHook* const cinewareHook = doc->FindSceneHook(CINEWARE_SCENEHOOK_ID);
///   if (cinewareHook == nullptr)
///			return maxon::NullptrError(MAXON_SOURCE_LOCATION);
///
/// AssetAddedMessage msg;
/// msg.addedAsset = obj;
/// cinewareHook->Message(MSG_ASSET_ADDED, &msg);
static constexpr Int32 MSG_ASSET_ADDED = 1065130;
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

static constexpr Int32 MSG_SCATTER_INSTANCE_INFO = 1066692;
struct ScatteredInstanceInfo
{
	Url _url;
	cinema::BaseList2D* _asset;
	BaseArray<Matrix> _matrices;

	UniqueHash GetUniqueHashCode() const;
};

struct MsgGetScatterInstanceInfo
{
	cinema::BaseObject* _scatterOp = nullptr;
	BaseArray<ScatteredInstanceInfo> _instanceInfo;
	Bool _hasActiveProjectionSurfaces = false;
};

/// Structure that can be used for both MSG_CINEWARE_TO_HOST_GET_OBJECT_FROM_ID or MSG_CINEWARE_TO_HOST_GET_OBJECT_ID
/// for MSG_CINEWARE_TO_HOST_GET_OBJECT_FROM_ID set abstractID before sending the message.
/// for MSG_CINEWARE_TO_HOST_GET_OBJECT_ID, set the objectPointer before sending the message.
struct MsgToHostGetObjectInformation
{
	UniqueHash abstractID;											 /// Needs to be defined before sending the message to retrieve the object link if used with MSG_CINEWARE_TO_HOST_GET_OBJECT_FROM_ID
	cinema::BaseList2D* objectPointer = nullptr; /// Needs to be defined before sending the message, used with MSG_CINEWARE_TO_HOST_GET_OBJECT_ID.
	Bool sucess = false;												 /// The host was able to find the counterpart.
};

enum class OBJECT_MANIPULATION
{
	ADDED,	 ///< Object was ADDED into the scene.
	DELETED, ///< Object was deleted from the scene.
} MAXON_ENUM_LIST(OBJECT_MANIPULATION);


/// Sent by the host when an object is deleted.
struct MsgFromHostObjectOperation
{
	UniqueHash _abstractID;
	OBJECT_MANIPULATION _operation;
	cinema::BaseObject* _object = nullptr; // only defined if the operation is OBJECT_MANIPULATION::ADDED
};

/// @brief Sent the asset url of a xref when it finishes loading his cache
static constexpr Int32 MSG_XREF_CACHE_LOADED = 1066730;

/// @brief Sent by the Ttexture, when it requests to update the material link to the default material.
static constexpr Int32 MSG_MATERIAL_RESET_DEFAULT = 1065490;

/// @brief Id from the host plugins, used to get the link to the original default material stored in the texture tag of a hosted object.
static constexpr Int32 MXAEC_HOST_DEFAULT_MATERIAL_LINK = 1066164;

// @brief Message that need to be sent to host. The host plugin will retrieve the object ID from the passed object.
static constexpr Int32 MSG_CINEWARE_TO_HOST_GET_OBJECT_ID = 1066705;

/// @brief Message sent by the host plugin to inform an operation was performed on an object. Allow the scatter object to react to such a message for example.
/// The structure of the data for this message will be MsgFromHostObjectOperation.
static constexpr Int32 MSG_CINEWARE_FROM_HOST_OBJECT_OPERATION = 1066643;

// @brief Message that need to be sent to host. The host plugin will received it and define the object pointer in the right structure. MsgToHostGetObjectInformation
static constexpr Int32 MSG_CINEWARE_TO_HOST_GET_OBJECT_FROM_ID = 1066704;

/// @brief Xref object BaseContainer ID, used to retrieve the enabling state of propagated parameters overrides.
/// @detail This can be used by the host plugin to control (en/disable) propagated attributes on the simple xref object.
///         The structure of the data is:
/// 			    bcXref (xref object's BaseContainer)
/// 		      |-- [SXREF_PROPAGATED_PARAMETERS_OVERRIDE_DENABLING = 1068409]  (BaseContainer)
/// 	            |-- [propagatedDescID_Nth.GetHashCode() : HashInt]  ->  Bool  (enabling state of the propagated parameter)
///         e.g. `bcXref[SXREF_PROPAGATED_PARAMETERS_OVERRIDE_DENABLING][ConstDescIDLevel(PLANT_MODEL, DTYPE_LONG, Oplant).GetHashCode()] = false`
///         leads to plant 'season' parameter grayed out on xref
static constexpr maxon::Int32 SXREF_PROPAGATED_PARAMETERS_OVERRIDE_DENABLING = 1068409;

class CinewarePluginHelper
{
	MAXON_INTERFACE_NONVIRTUAL(CinewarePluginHelper, MAXON_REFERENCE_STATIC, "net.maxon.interfaces.cinewarepluginhelper");

public:
	//----------------------------------------------------------------------------------------
	/// @brief Check if the object has a AEC id defined by the host.
	/// @param[in] object							The object where the ID should be retrieve and compare to 0.
	/// @return												True if the ID is defined and different than 0. It means the object is coming from an AEC host.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsFromHost(const cinema::BaseList2D* object);

	//----------------------------------------------------------------------------------------
	/// @brief Retrieve the AEC Unique ID defined by the plugin host. If the ID cannot be retrieve using CINEWARE_GENERIC_APP_ID it will send a message to the plugin.
	/// @param[in] object							The object where the ID should be retrieve.
	/// @return												Hash code of the given object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD UniqueHash GetHostID(const cinema::BaseList2D* object);


	/// @brief Generate hash including dirty data of the asset object.
	static MAXON_METHOD UniqueHash GetScatterUniqueHashCode(const ScatteredInstanceInfo& instanceInfo);
	static MAXON_METHOD maxon::String GetHostName();
	static MAXON_METHOD void SetHostApplicationID(Int32 appID);
	static MAXON_METHOD Bool IsHostVectorworks();
	static MAXON_METHOD Bool IsHostRevit();
	static MAXON_METHOD Bool IsHostArchicad();
	static MAXON_METHOD Bool IsHostLayer(const cinema::BaseObject* obj);
	static MAXON_METHOD Bool IsHostClass(const cinema::BaseObject* obj);
	static MAXON_METHOD Bool IsHostLaubwerkObject(const cinema::BaseObject* obj);
	static MAXON_METHOD Bool IsRedshiftLayer(const cinema::BaseObject* obj);
	static MAXON_METHOD Bool IsRedshiftObjectClass(const cinema::BaseObject* obj);
	static MAXON_METHOD Bool IsRedshiftScatterClass(const cinema::BaseObject* obj);

	//----------------------------------------------------------------------------------------
	/// @brief Show a warning message if the user is trying to hide a layer that is the active layer in the host application.
	/// @param[in] ml									The object to check.
	/// @return												True if the warning message was shown, false if it was not needed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool ShowActiveLayerWarningIfNeeded(const cinema::BaseList2D* ml);

	//----------------------------------------------------------------------------------------
	/// @brief Checks if the object passed as parameter is the current active layer in the host application.
	/// @param[in] obj								The object to check.
	/// @return												True if the object is the active layer in the host application.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsHostActiveLayer(const cinema::BaseObject* obj);

	//----------------------------------------------------------------------------------------
	/// @brief Define the ID of the active layer in the host application if the host application support the concept of active layer.
	/// @param[in] AecEntityHash			The hash of the current active layer that is activated.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetActiveLayerID(const UniqueHash& AecEntityHash);

	/// @brief Required to send MxAnalytics Events from plugin side.
	static MAXON_METHOD Bool SendMxAnalyticsEvent(const maxon::String& eventname, const maxon::DataDictionary& eventParams);
};

inline UniqueHash ScatteredInstanceInfo::GetUniqueHashCode() const
{
	return CinewarePluginHelper::GetScatterUniqueHashCode(*this);
}

#include "cineware_messages1.hxx"
#include "cineware_messages2.hxx"

} // namespace maxon

#endif // CINEWARE_MESSAGES_H__
