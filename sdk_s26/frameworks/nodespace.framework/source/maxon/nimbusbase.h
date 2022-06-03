#ifndef NIMBUSBASE_H__
#define NIMBUSBASE_H__

#include "maxon/nodepath.h"
#include "maxon/uuid.h"
#include "maxon/weakref.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseList2D;
class DescID;

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

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
	MAXON_METHOD BaseList2D* GetBaseListRoot();

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
	MAXON_METHOD Result<void> OpenInEditor(const NodePath& path = NodePath::NullValue());

	//----------------------------------------------------------------------------------------
	/// Returns the BaseList2D element with the given uuid.
	/// @param[in] uuid								Uuid to find.
	/// @return												BaseList2D object on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseList2D*> UuidToBaseList2D(const Uuid& uuid) const;

	//----------------------------------------------------------------------------------------
	/// Returns the uuid of the given BaseList2D object.
	/// @param[in] object							BaseList2D object to find.
	/// @return												Uuid on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Uuid> BaseList2DToUuid(BaseList2D* object) const;

	//----------------------------------------------------------------------------------------
	/// Sets up the DescID of the parameter which corresponds to the given port.
	/// @param[in] port								A port path.
	/// @param[out] result						The DescID to set up.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetDescID(const NodePath& port, DescID& result);
};

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
