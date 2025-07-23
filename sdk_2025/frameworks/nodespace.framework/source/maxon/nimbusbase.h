#ifndef NIMBUSBASE_H__
#define NIMBUSBASE_H__

#include "maxon/assets.h"
#include "maxon/graph.h"
#include "maxon/idandversion.h"
#include "maxon/uuid.h"
#include "maxon/weakref.h"

namespace cinema
{

class BaseList2D;
class DescID;

} // namespace cinema


namespace maxon
{

namespace nodes
{
class NodesGraphModelRef;
}

//----------------------------------------------------------------------------------------
/// NIMBUS_PATH is used as argument for NimbusBaseInterface::GetPath and NimbusBaseInterface::SetPath.
//----------------------------------------------------------------------------------------
enum class NIMBUS_PATH
{
	STARTNODE = 0,			 ///< Path of the node initially shown in the Attributes Manager.
	SOLO = 1,						 ///< Path of the node or port used for solo mode.
	MATERIALENDNODE = 2, ///< Path of the material end node
} MAXON_ENUM_LIST(NIMBUS_PATH);

//----------------------------------------------------------------------------------------
/// NimbusBaseRef manages a NodesGraphModelRef that is owned by a classic BaseList2D object.
/// A BaseList2D object can own multiple graphs, one for each node space.
//----------------------------------------------------------------------------------------
class NimbusBaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NimbusBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.nimbusbase");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the node graph connected to this object.
	/// @return												NodesGraphModelRef on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const nodes::NodesGraphModelRef& GetGraph();

	//----------------------------------------------------------------------------------------
	/// Returns the C4D object that holds the NimbusBaseRef.
	/// @return												BaseList2D element, e.g. a Material.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD cinema::BaseList2D* GetBaseListRoot();

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the node space of the node graph.
	/// @return												Node space identifier.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetSpaceId();

	//----------------------------------------------------------------------------------------
	/// Sets a path.
	/// @param[in] type								Path type.
	/// @param[in] path								Absolute Path to a Node or an empty path.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetPath(NIMBUS_PATH type, const NodePath& path);

	//----------------------------------------------------------------------------------------
	/// Returns a path.
	/// Note that the returned path can be invalid and point to a non-existing object.
	/// @param[in] type								Path type.
	/// @return												Absolute Path to a Node or Port, depending on the given type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NodePath GetPath(NIMBUS_PATH type);

	//----------------------------------------------------------------------------------------
	/// Opens the node editor for the node graph held by this NimbusBaseRef.
	/// @param[in] path								An optional path pointing to a group of the node graph.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> OpenInEditor(const NodePath& path = NodePath::DefaultValue());

	//----------------------------------------------------------------------------------------
	/// Returns the BaseList2D element with the given uuid.
	/// @param[in] uuid								Uuid to find.
	/// @return												BaseList2D object on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<cinema::BaseList2D*> UuidToBaseList2D(const Uuid& uuid) const;

	//----------------------------------------------------------------------------------------
	/// Returns the uuid of the given BaseList2D object.
	/// @param[in] object							BaseList2D object to find.
	/// @return												Uuid on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Uuid> BaseList2DToUuid(cinema::BaseList2D* object) const;

	//----------------------------------------------------------------------------------------
	/// Sets up the DescID of the parameter which corresponds to the given port.
	/// @param[in] port								A port path.
	/// @param[out] result						The DescID to set up.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetDescID(const NodePath& port, cinema::DescID& result);

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding BaseList element for a GraphNode but will not create one if not already present.
	/// @param[in] absolutePath				Absolute Path to the Node.
	/// @return												BaseList2D element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD cinema::BaseList2D* FindCorrespondingBaseList(const NodePath& absolutePath) const;

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding BaseList element for a GraphNode. This function creates a new one if not already present.
	/// @param[in] absolutePath				Absolute Path to the Node.
	/// @return												BaseList2D element. The return value can be nullptr in case no element can be created for the given path, e.g. if it is invalid
	///																of refers to an inner node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<cinema::BaseList2D*> FindOrCreateCorrespondingBaseList(const NodePath& absolutePath);

	//----------------------------------------------------------------------------------------
	/// Updates global context values using the delegates registered at NimbusContextGetters.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> UpdateGlobalContext();

	//----------------------------------------------------------------------------------------
	/// Returns the node connected to the BaseList2D element.
	/// @return												GraphNode on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GraphNode> GetGraphNodeFromBaseList(const cinema::BaseList2D* bl);

	//----------------------------------------------------------------------------------------
	/// Returns the path of the node connected to the BaseList2D element.
	/// @return												GraphNode on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> GetNodePathFromBaseList(const cinema::BaseList2D* bl);
};

//----------------------------------------------------------------------------------------
/// @brief Node graph asset update message.
/// Send it to a BaseList2D containing a NimbusRef to allow the graph to apply the given updates.
/// For capsule objects, this will use message MSG_SET_ASSET_WITH_VERSION to update the capsule itself if required.
/// For non capsule graphs and editable capsule groups, this will update all the asset instances from the requested list.
/// Expects a pointer to a list of applicable updates. List should be reduced each time a message handler takes care of some entries.
/// Arguments: NodeApplicableUpdateList*
//----------------------------------------------------------------------------------------
static constexpr Int32 MSG_APPLY_NODE_UPDATES = 190000007;
using NodeApplicableUpdateList = BaseArray<Tuple<AssetReference /* Reference to the updatable asset instance */, AssetBase /* Applicable update */>>;

namespace URLFLAGS
{
	/// @brief AssetLink added to Url for node assets collected with MSG_GETALLASSETS.
	MAXON_ATTRIBUTE(AssetLink, AssetLinkData, "net.maxon.url.assetlink.link");
	/// @brief Additional asset missing flag added to Url for node assets collected with MSG_GETALLASSETS.
	MAXON_ATTRIBUTE(Bool, AssetLinkMissing, "net.maxon.url.assetlink.missing");
}

#include "nimbusbase1.hxx"


using WeakNimbusBaseRef = WeakRef<NimbusBaseRef>;

MAXON_DATATYPE(WeakNimbusBaseRef, "net.maxon.datatype.weaknimbusref");


namespace ARGUMENTS
{
	namespace NIMBUSCORE
	{
		// ARGUMENTS::NODECORE::GRAPHMODEL
		// ARGUMENTS::NODECORE::NODEPATH
		// ARGUMENTS::NODECORE::PORTPATH
		MAXON_ATTRIBUTE(WeakNimbusBaseRef, NIMBUSROOT, "net.maxon.arguments.nodecore.nimbusroot");
		MAXON_ATTRIBUTE(Id, NODESPACE, "net.maxon.arguments.nodecore.nimbusnodespace");
	}
}

#include "nimbusbase2.hxx"

} // namespace maxon

#endif // NIMBUSBASE_H__
