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
	/// The asset identifier is defined only for true nodes, but not if this serialization node
	/// represents a port or port list.
	/// @return												Asset identifier of the base template.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IdAndVersion& GetBaseTemplate();

	//----------------------------------------------------------------------------------------
	/// Returns the template arguments for the base template of the node system data.
	/// Template arguments are defined only for true nodes, but not if this serialization node
	/// represents a port or port list.
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

	//----------------------------------------------------------------------------------------
	/// This enum is used for the mode parameter of FindOrAddChild.
	//----------------------------------------------------------------------------------------
	enum class CHILD_MODE
	{
		ADD,			///< Add the child node, it doesn't exist in a base.
		INHERIT,	///< Inherit the child node, it already exists in a base.
		REMOVE		///< Remove the child node which would otherwise be inherited from a base.
	} MAXON_ENUM_LIST_CLASS(CHILD_MODE);

	//----------------------------------------------------------------------------------------
	/// Adds a new child node entry to the serialization data, or returns the already existing one.
	/// The added parameter has to be set correctly:
	/// - Either the node would already exist in the deserialized NodeSystem even without the
	///   added child entry. That's when the node is inherited from a base, and you just want to override
	///   some of its properties or need access to nested nodes.
	///   Then you have to use CHILD_MODE::INHERIT for mode, and it's not necessary to set the base template.
	/// - Or the node wouldn't exist in the deserialized NodeSystem. Then you have to use CHILD_MODE::ADD for
	///   added, and in case of a true node (instead of a port) you have to set the correct values for the base template.
	/// - Or you want to remove a node which otherwise would be inherited from a base, then you have
	///   to use CHILD_MODE::REMOVE.
	/// If the child node entry already existed before, the given arguments for the base template are ignored.
	/// @param[in] child							Identifier of the child.
	/// @param[in] mode								CHILD_MODE::ADD if the child node didn't exist in the deserialized NodeSystem
	/// 															without the new child node entry, CHILD_MODE::INHERIT if the child node
	/// 															is inherited from a base, or CHILD_MODE::REMOVE if you want to flag
	/// 															an inherited node as to be removed.
	/// @param[in] base								Identifier of the base template to use for the node.
	///																Only needed for true nodes when mode is CHILD_MODE::ADD.
	/// @param[in] baseArgs						Identifier of the base template arguments to use for the node.
	///																Only needed for true nodes when mode is CHILD_MODE::ADD.
	/// @param[in] updatePolicy				The update policy to use when the base template is resolved.
	///																Only needed for true nodes when mode is CHILD_MODE::ADD.
	/// @return												Added (or already existing) child node.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SerializationNodeData*> FindOrAddChild(const InternedId& child, CHILD_MODE mode,
																														 const IdAndVersion& base = GetZeroRef<IdAndVersion>(), const DataDictionary& baseArgs = DataDictionary::NullValue(), ASSET_UPDATE_POLICY updatePolicy = ASSET_UPDATE_POLICY::IMPLICIT);
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
