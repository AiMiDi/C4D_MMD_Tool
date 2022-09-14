#ifndef COMPONENTACCESSATTRIBUTES_H__
#define COMPONENTACCESSATTRIBUTES_H__

#include "maxon/graph_basics.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// A structure for holding all component access required information for each supported DataType.
//----------------------------------------------------------------------------------------
class ComponentAccessType
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(ComponentAccessType);
public:

	ComponentAccessType() = default;
	ComponentAccessType(ComponentAccessType&& src) : MAXON_MOVE_MEMBERS(_portType, _nodeId, _accessNodeResultId, _dummy, _allowNested, _accessIo, _invokeFunc)
	{}
	
	MAXON_OPERATOR_MOVE_ASSIGNMENT(ComponentAccessType);
	
	Result<void> CopyFrom(const ComponentAccessType& src)
	{
		iferr_scope;
		MAXON_COPYFROM_MEMBERS(_portType, _nodeId, _accessNodeResultId, _dummy, _allowNested, _accessIo, _invokeFunc);
		return OK;
	}
	
	DataType _portType;							/// Access port datatype.
	Id _nodeId;											/// The access node id to instantiate.
	Id _accessNodeResultId;					/// Access node port id to connect to the node showing the access ports (generally the access node's single out for an input component access).
	Id _dummy;											/// Unused
	Bool _allowNested = false;			/// True to allow nested component access (break down a matrix's vectors into distinct float inputs.

	using PortInfo = Tuple<Id, Int, Data>;												// {Port Id, 0 based port index (full IO port index), port type and default value (could just default to 0)}
	using PortMap = BaseArray<PortInfo>;													// Port id to index map.
	BufferedBaseArray<PortMap, (Int)PORT_DIR::END> _accessIo;			// Port id to index maps for both directions. Use [PORT_DIR::INPUT] or [PORT_DIR::OUTPUT].

	/// Delegate that will invoke the CoreNode  within the user node #_nodeId.
	using InvokeType = Delegate<Result<void>(const Block<const Tuple<TrivialDataPtr, CORENODE_PORT_FLAGS>>&)>;
	InvokeType _invokeFunc;
};
MAXON_DATATYPE(ComponentAccessType, "net.maxon.nodes.datatype.componentaccesstype");
using ComponentAccessDef = StrongRef<ComponentAccessType>;
using ComponentAccessDefWithId = Tuple<StrongRef<ComponentAccessType>, Id>;

//----------------------------------------------------------------------------------------
/// This attribute gets set on a bundle port using component access. 
/// The given id should be an element of a ComponentAccessTypeDef registry. Hence
/// the port will know which access node to use for showing child ports.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Id, ComponentAccessBundle, "componentaccessbundleport2");

//----------------------------------------------------------------------------------------
/// This attribute is set for a component access child port (child of the bundle port).
/// The given id links to the same definition as the parent port's ComponentAccessBundle.
/// ComponentAccessBundle and ComponentAccessChild can be combined for nested component access.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Id, ComponentAccessChild, "componentaccesschild2");

//----------------------------------------------------------------------------------------
/// This attribute is set for a component access bundle ports which can potentially use access ports.
/// It links to a definition in either InPortComponentAccessTypes or OutPortComponentAccessTypes.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(ComponentAccessDefWithId, ComponentAccessDefAttr, "componentaccessdef");

MAXON_REGISTRY(ComponentAccessDef, InPortComponentAccessTypes, "net.maxon.node.registry.inportcomponentaccess");
namespace InPortComponentAccessTypes
{
	MAXON_DECLARATION(ComponentAccessDef, Matrix32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.matrix32");
	MAXON_DECLARATION(ComponentAccessDef, Matrix64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.matrix64");
	MAXON_DECLARATION(ComponentAccessDef, Vector2d32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector2d32");
	MAXON_DECLARATION(ComponentAccessDef, Vector2d64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector2d64");
	MAXON_DECLARATION(ComponentAccessDef, Vector32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector32");
	MAXON_DECLARATION(ComponentAccessDef, Vector64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector64");
	MAXON_DECLARATION(ComponentAccessDef, Vector4d32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector4d32");
	MAXON_DECLARATION(ComponentAccessDef, Vector4d64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.vector4d64");
	MAXON_DECLARATION(ComponentAccessDef, Color32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.color32");
	MAXON_DECLARATION(ComponentAccessDef, Color64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.color64");
	MAXON_DECLARATION(ComponentAccessDef, ColorA32ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.colora32");
	MAXON_DECLARATION(ComponentAccessDef, ColorA64ComponentAccess, "net.maxon.node.registry.inportcomponentaccess.colora64");
}

MAXON_REGISTRY(ComponentAccessDef, OutPortComponentAccessTypes, "net.maxon.node.registry.outportcomponentaccess");
namespace OutPortComponentAccessTypes
{
	MAXON_DECLARATION(ComponentAccessDef, Matrix32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.matrix32");
	MAXON_DECLARATION(ComponentAccessDef, Matrix64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.matrix64");
	MAXON_DECLARATION(ComponentAccessDef, Vector2d32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector2d32");
	MAXON_DECLARATION(ComponentAccessDef, Vector2d64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector2d64");
	MAXON_DECLARATION(ComponentAccessDef, Vector32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector32");
	MAXON_DECLARATION(ComponentAccessDef, Vector64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector64");
	MAXON_DECLARATION(ComponentAccessDef, Vector4d32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector4d32");
	MAXON_DECLARATION(ComponentAccessDef, Vector4d64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.vector4d64");
	MAXON_DECLARATION(ComponentAccessDef, Color32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.color32");
	MAXON_DECLARATION(ComponentAccessDef, Color64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.color64");
	MAXON_DECLARATION(ComponentAccessDef, ColorA32ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.colora32");
	MAXON_DECLARATION(ComponentAccessDef, ColorA64ComponentAccess, "net.maxon.node.registry.outportcomponentaccess.colora64");
}

#include "componentaccessattributes1.hxx"
#include "componentaccessattributes2.hxx"

}	// namespace nodes

} // namespace maxon

#endif // COMPONENTACCESSATTRIBUTES_H__
