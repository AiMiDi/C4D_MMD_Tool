#ifndef NODES_IMPORT_H__
#define NODES_IMPORT_H__

#include "maxon/graph.h"
#include "maxon/map.h"
#include "maxon/idandversion.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// SerializationNodeData represents the data of a Node, PortList or Port for serialization.
/// It can be adapted by an ImportAdapter to the current version, for example if
/// attribute values shall be modified.
/// @MAXON_ANNOTATION{noUnresolved}
//----------------------------------------------------------------------------------------
class SerializationNodeData
{
	MAXON_INTERFACE_NONVIRTUAL(SerializationNodeData, MAXON_REFERENCE_NONE, "net.maxon.node.interface.serializationdata");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the complete node path of this node.
	/// @return												Path of this node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NodePath& GetPath() const;

	//----------------------------------------------------------------------------------------
	/// Returns the attributes of this node. An ImportAdapter can use this to modify, add or remove attribute values.
	/// @return												Attributes of this node as a map.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MapInterface<InternedId, Data>& GetAttributes();

	//----------------------------------------------------------------------------------------
	/// Returns the targets of this port. The map represents the outgoing connections of a port
	/// where the target port is identified by its path. An ImportAdapter can modify the connections
	/// by direct modification of the map.
	/// @return												Outgoing connections of this port as a map.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MapInterface<NodePath, Wires>& GetTargets();

	//----------------------------------------------------------------------------------------
	/// Returns the asset identifier of the base template of the node system data.
	/// An ImportAdapter can modify the identifier to handle renamings of node assets.
	/// @return												Asset identifier of the base template.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IdAndVersion& GetBaseTemplate();

	//----------------------------------------------------------------------------------------
	/// Returns the template arguments for the base template of the node system data.
	/// @return												Template arguments for base template.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD DataDictionary& GetBaseTemplateArguments();

	//----------------------------------------------------------------------------------------
	/// Yields the children of this node to #receiver.
	/// @param[in] receiver						All children are reported to this receiver.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetChildren(const ValueReceiver<SerializationNodeData&>& receiver);

	//----------------------------------------------------------------------------------------
	/// Finds the child of this node with the given identifer.
	/// @param[in] child							Identifier of the child.
	/// @return												Found child or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SerializationNodeData* FindChild(const Id& child);

	//----------------------------------------------------------------------------------------
	/// Removes the child of this node with the given identifer (if it exists).
	/// @param[in] child							Identifier of the child.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RemoveChild(const Id& child);
};


//----------------------------------------------------------------------------------------
/// An ImportAdapter is called right after node system data has been read from a stream
/// to adapt the data from the serialized version to the current version. For example,
/// such an adapter can rename identifers of referenced node templates
/// or change attribute values.
///
/// You have to register an ImportAdapter at the ImportAdapters registry. Then it will be
/// called on serialization to add version information to the stream, and on
/// de-serialization to adapt to the current version.
//----------------------------------------------------------------------------------------
class ImportAdapterInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ImportAdapterInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.importadapter");

public:
	//----------------------------------------------------------------------------------------
	/// Adds version information to the node data starting at #root before serialization.
	/// For example the implementation can tag certain nodes with version numbers so that
	/// the Adapt method knows their serialized version and can take appropriate actions to adapt
	/// to the current version.
	/// @return												The current version of this adapter, to be used for serialization.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> BeforeWrite(SerializationNodeData& root) const;

	//----------------------------------------------------------------------------------------
	/// Adapts the node system data starting at #root. This method is called on de-serialization
	/// of node system data to allow for adaptations between different versions. #root gives
	/// write access to the de-serialized data.
	/// @param[in,out] root						The SerializationNodeData root node of the de-serialized node system data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AfterRead(SerializationNodeData& root) const;
};

#include "nodes_import1.hxx"
#include "nodes_import2.hxx"

//----------------------------------------------------------------------------------------
/// The registry of ImportAdapter objects.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(ImportAdapter, ImportAdapters, "net.maxon.node.registry.importadapters");

}

}

#endif // NODES_IMPORT_H__
