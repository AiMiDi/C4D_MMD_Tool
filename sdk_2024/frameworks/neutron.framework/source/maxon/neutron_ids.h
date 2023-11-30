#ifndef NEUTRON_IDS_H__
#define NEUTRON_IDS_H__

#include "maxon/basearray.h"
#include "maxon/matrix.h"
#include "maxon/vector.h"
#include "maxon/fid.h"

class BaseObject;
struct NODEPLUGIN;

namespace maxon
{

class GraphNode;
class ImageRef;

namespace neutron
{

static constexpr Int32 SCENEHOOK_ID = 1054188;


static constexpr Int32 ID_NBO_SCENEEDITOR = 1054189;
static constexpr Int32 ID_NBO_FORCEDIRTY = 1054529;
static constexpr Int32 ID_NBO_CLEAR_DC_CACHE = 1054190;
static constexpr Int32 ID_NBO_CLEAR_DESC_CACHE = 1054191;
static constexpr Int32 ID_NBO_FORCE_DESC_DIRTY = 1054192;

static constexpr Int32 MATERIAL_PARAMETERS = 180420102;

using InstanceData = Tuple<BaseArray<Matrix>, BaseArray<Color64>, BaseArray<Int32>, BaseArray<UniqueHash>>;
static constexpr Int32 MSG_SET_INSTANCE_DATA = 180420104;

static constexpr Int32 MSG_ASK_SKIP_ONWRITE = 1056642;

static constexpr Int32 MSG_GET_XPRESSO_PORTS = 180420105;
static constexpr Int32 MSG_XPRESSO_DIRTY = 180420106;
static constexpr Int32 MSG_GET_NEUTRON_VIEWPORT_SCENE = 180420107;
static constexpr Int32 MSG_HAS_DATA = 180420108;
static constexpr Int32 MSG_UPDATE_LEGACY_OBJECTS = 180420109;
static constexpr Int32 MSG_GET_LEGACY_VIEWPORT_OBJECTS = 180420110;
static constexpr Int32 MSG_GET_SCENE = 180420111;
static constexpr Int32 MSG_GET_ICON_IMAGE = 180420112;
static constexpr Int32 MSG_GET_INSTRUMENTATION_HANDLER = 180420113;
static constexpr Int32 MSG_GET_ASSET_SERIALIZATION_DATA = 180420115;
static constexpr Int32 MSG_DESELECT_NODES = 180420116;
static constexpr Int32 MSG_GET_STORAGE_HELPER = 180420117;
static constexpr Int32 MSG_SETTINGS_NAME = 180420118;

using ChangePluginTypeData = Tuple<Int32, NODEPLUGIN*>;
static constexpr Int32 MSG_CHANGE_PLUGINTYPE = 180420119;

static constexpr Int32 MSG_REGISTER_THREADED_NIMBUS = 180420120;
static constexpr Int32 MSG_RESET_THREADED_NIMBUS = 180420121;
static constexpr Int32 MSG_CREATE_IF_REQUIRED = 180420122;

static constexpr Int32 MSG_ENABLE_ASSET_TO_GROUP = 180420123;

//----------------------------------------------------------------------------------------
/// Message to ask a BaseList2D if it is an editable capsule.
/// That can be true either for a capsule group or a capsule that can be made editable. Otherwise, false.
/// Arguments: Bool*
//----------------------------------------------------------------------------------------
static constexpr Int32 MSG_IS_CAPSULE_EDITABLE = 180420124;

//----------------------------------------------------------------------------------------
/// Message to ask a BaseList2D if it is a capsule group. 
/// Will return the group's identifier if the capsule is a group.
/// Arguments: Id*
//----------------------------------------------------------------------------------------
static constexpr Int32 MSG_IS_CAPSULE_GROUP = 180420125;

using GetIconImageArgs = Tuple<GraphNode, Id, ImageRef>;
static constexpr Int32 MSG_SET_PICKING_RESULT = 431000206;
static constexpr Int32 NEUTRON_INSTANCE_NODE_PATH = 431000207;
static constexpr Int32 NEUTRON_INSTANCE_NODE_MODIFIER_PATH = 431000212;

static constexpr Int32 PERSISTENT_HASH_LOW = 180420112;

static constexpr Int32 LEGACY_CONVERSION_ID = 180420201;

static constexpr Int32 PERSISTENTHOOK_ID = 180420202;
static constexpr Int32 MSG_INSTRUMENTATION_MIN = 180420203;
static constexpr Int32 MSG_REGISTER_SCENE_LISTENER = 180420204;
static constexpr Int32 MSG_REGISTER_PORT_VALUE_LISTENER = 180420205;
static constexpr Int32 MSG_REGISTER_HEATMAP_LISTENER = 180420206;
static constexpr Int32 MSG_GET_INSPECTOR_PRESENTER = 180420207;
static constexpr Int32 MSG_INSTRUMENTATION_MAX = 180420208;

static constexpr Int32 TAG_ID = 180420300; // Please transfer all ID changes to the symbol with the matching integer in ge_prepass.h marked as @PublicExposure.
static constexpr Int32 MSG_TAG_SET_ASSET = 180420301; // expects a pointer to an Id of a node asset which can be found in the scope of the current document's repository
static constexpr Int32 MSG_SET_ARCHIGRASS_ASSET = 180420302; // adds a Neutron scene tag to the current object and sets its graph to the archigrass asset
static constexpr Int32 MSG_SET_FROM_FILTERSTRING = 180420303; // expects a pointer to a Tuple<AssetDescription, String> with a filter string from which attributes of the node are set
static constexpr Int32 MSG_SET_ASSET_WITH_VERSION = 180420304; // expects a pointer to an IdAndVersion of a node asset which can be found in the scope of the current document's repository


static constexpr Int32 NEUTRON_BASE_ID = 190000010;													///< Base instance type for all the neutron related objects (scene hooks, tags, ...).
static constexpr Int32 CAPSULE_BASE_ID = 180420800;													///< Base instance type for all the capsules with types below.
static constexpr Int32 DEFORMER_ID = 180420400;
static constexpr Int32 GENERATOR_ID = 180420500;
static constexpr Int32 DATASET_TO_TAG = 431000229;
static constexpr Int32 PRIMITIVE_GENERATOR_ID = 180420600;
static constexpr Int32 PRIMITIVE_SPLINE_GENERATOR_ID = 180420700;

static constexpr Int32 SCENE_PORT_LINK = 180420710;

static constexpr Int32 IDM_CAPSULE_ASSET_TO_GROUP = 180429000;
static constexpr Int32 IDM_HEATMAP_DUMP = 190000000;													///< No data. Will print heat map data from capsule/scene nodes to console.
static constexpr Int32 IDM_HEATMAP_ENABLE = 190000001;												///< Expecting const Bool* data, true to enable heat map data collection on capsule/scene nodes.
static constexpr Int32 IDM_HEATMAP_ISENABLED = 190000002;											///< Expecting Bool* data, true if heat map is enabled for the capsule/scene nodes.
static constexpr Int32 IDM_HEATMAP_ISSUPPORTED = 190000003;										///< Expecting Bool* data, true if heat map is supported by the object.
static constexpr Int32 IDM_HEATMAP_QUEUE_DUMP = 190000004;										///< No data. Will force a heat map update and print heat map to console afterwards.

static constexpr Int32 MSG_NODESQUERY_MATERIAL = 1055560;
static constexpr Int32 MSG_NODESQUERY_MATERIAL_CHANNEL_ON = 0;
static constexpr Int32 MSG_NODESQUERY_MATERIAL_HASHCODE = 1;

#define CUSTOMDATATYPE_PSRMATRIX 1055305

/// Neutron node space identifier.
static constexpr LiteralId NODESPACE{"net.maxon.neutron.nodespace"};

/// Identifier of the NodeTemplate used to wrap node assets in capsules. It's always the NodeSystem's first base in a capsule graph.
static constexpr LiteralId CAPSULEASSETWRAPPERID{"net.maxon.nbo.classicobject"};


[[deprecated("Use IsInstanceOf(CAPSULE_BASE_ID) instead")]] inline Bool IsNeutronObjectType(Int32 type)
{
	return type == CAPSULE_BASE_ID ||
		type == DEFORMER_ID || type == GENERATOR_ID || type == PRIMITIVE_GENERATOR_ID || type == PRIMITIVE_SPLINE_GENERATOR_ID;
}

[[deprecated("Use IsInstanceOf(NEUTRON_BASE_ID) instead")]] inline Bool IsNeutronType(Int32 type)
{
	return type == NEUTRON_BASE_ID || type == SCENEHOOK_ID || type == TAG_ID ||
		// Same as IsNeutronObjectType, but manually written to avoid nested deprecated call so MSVC don't complain
		type == CAPSULE_BASE_ID ||
		type == DEFORMER_ID || type == GENERATOR_ID || type == PRIMITIVE_GENERATOR_ID || type == PRIMITIVE_SPLINE_GENERATOR_ID;
}

namespace NODESQUERY
{
	namespace MATERIAL
	{
		MAXON_ATTRIBUTE(Int32, MESSAGETYPE, "net.maxon.neutron.material.nodesquery.type");
		MAXON_ATTRIBUTE(Int32, CHANNEL, "net.maxon.neutron.material.nodesquery.channel");
		MAXON_ATTRIBUTE(Bool, RESULT, "net.maxon.neutron.material.nodesquery.channel.on");
		MAXON_ATTRIBUTE(HashInt, HASHCODE, "net.maxon.neutron.material.nodesquery.hashcode");
	}
}

// Can be set in the cached data of a GeometryObject and contains mappings Tuple<String, Id> -> UInt
// which tell who has written the attribute (or selection) of the given name and type.
// Neutron will use a unique stamp for each compiled node graph. The type is one of those in AttributeTypes or SelectionTypes.
MAXON_ATTRIBUTE(DataDictionary, GeometryAttributeStamps, "net.maxon.neutron.geometryattributestamps");

static constexpr LiteralId SCENE_ROOT{"net.maxon.neutron.scene.root"};

}

#include "neutron_ids1.hxx"
#include "neutron_ids2.hxx"
}

#endif // NEUTRON_IDS_H__
