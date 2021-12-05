#ifndef NEUTRON_IDS_H__
#define NEUTRON_IDS_H__

#include "maxon/basearray.h"
#include "maxon/matrix.h"
#include "maxon/vector.h"
#include "maxon/fid.h"

class BaseObject;

namespace maxon
{

class GraphNode;
class ImageRef;

namespace neutron
{

static constexpr Int32 SCENEHOOK_ID = 1054188;


static constexpr Int32 ID_NBO_SCENEEDITOR = 1054189;
static constexpr Int32 ID_NBO_FORCEDIRTY = 1054529;

static constexpr Int32 MATERIAL_PARAMETERS = 180420102;

using InstanceData = Tuple<BaseArray<Matrix>, BaseArray<Color64>, BaseArray<Int32>, BaseArray<HashValue>>;
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
static constexpr Int32 MSG_GET_PERSISTENT_OBJ = 180420113;
static constexpr Int32 MSG_REINITIALIZE_SCENEREPOSITORY_ON_LOAD = 180420114;
using GetIconImageArgs = Tuple<GraphNode, Id, ImageRef>;
static constexpr Int32 MSG_SET_PICKING_RESULT = 431000206;
static constexpr Int32 NEUTRON_INSTANCE_NODE_PATH = 431000207;
static constexpr Int32 NEUTRON_INSTANCE_NODE_MODIFIER_PATH = 431000212;

static constexpr Int32 PERSISTENT_HASH_LOW = 180420112;

static constexpr Int32 LEGACY_CONVERSION_ID = 180420201;

static constexpr Int32 PERSISTENTHOOK_ID = 180420202;
static constexpr Int32 MSG_REGISTER_INSTRUMENTATION = 180420203;
static constexpr Int32 MSG_REGISTER_SCENE_LISTENER = 180420204;
static constexpr Int32 MSG_REGISTER_INSPECTOR = 180420205;
static constexpr Int32 MSG_GET_INSPECTOR_PRESENTER = 180420206;

static constexpr Int32 TAG_ID = 180420300;
static constexpr Int32 MSG_TAG_SET_ASSET = 180420301; // expects a pointer to an Id of a node asset which can be found in the scope of the user repository
static constexpr Int32 MSG_SET_ARCHIGRASS_ASSET = 180420302; // adds a Neutron scene tag to the current object and sets its graph to the archigrass asset

#define CUSTOMDATATYPE_PSRMATRIX 1055305

static constexpr LiteralId NODESPACE{"net.maxon.neutron.nodespace"};

static constexpr Int32 MSG_NODESQUERY_MATERIAL = 1055560;
static constexpr Int32 MSG_NODESQUERY_MATERIAL_CHANNEL_ON = 0;
static constexpr Int32 MSG_NODESQUERY_MATERIAL_HASHCODE = 1;

inline Bool IsNeutronType(Int32 type)
{
	return type == SCENEHOOK_ID || type == TAG_ID;
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
}

#include "neutron_ids1.hxx"
#include "neutron_ids2.hxx"
}

#endif // NEUTRON_IDS_H__
