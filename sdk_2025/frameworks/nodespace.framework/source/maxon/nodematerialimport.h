#ifndef NODEMATERIALIMPORT_H__
#define NODEMATERIALIMPORT_H__

#include "maxon/nodesgraph.h"
#include "maxon/datatypebase.h"

namespace maxon
{

namespace material
{
struct MaterialExchangeData;
} // namespace material

namespace nodes
{

class NodeMaterialImportHelperRef;
class NodeMaterialImportHelperInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeMaterialImportHelperInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.nodematerialimporthelper");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
public:

	struct GroupNodeData
	{
		GraphNode _node;
		BaseArray<Tuple<Id, Id>> _ports;
	};

	static MAXON_METHOD Result<NodeMaterialImportHelperRef> CreateAndInitialize(NodesGraphModelRef& graph, const Id& materialType);

	MAXON_METHOD Result<void> AddBoolParameter(Bool value, const InternedId& id);
	MAXON_METHOD Result<void> AddIntParameter(Int value, const InternedId& id);
	MAXON_METHOD Result<void> AddUIntParameter(UInt value, const InternedId& id);
	MAXON_METHOD Result<void> AddFloatParameter(Float value, const InternedId& id);
	MAXON_METHOD Result<void> AddVector2dParameter(Vector2d value, const InternedId& id);
	MAXON_METHOD Result<void> AddVectorParameter(Vector value, const InternedId& id);
	MAXON_METHOD Result<void> AddVector4dParameter(Vector4d value, const InternedId& id);
	MAXON_METHOD Result<void> AddColorParameter(Color value, const InternedId& id);
	MAXON_METHOD Result<void> AddColorAParameter(ColorA value, const InternedId& id);
	MAXON_METHOD Result<void> AddUrlParameter(Url value, const InternedId& id);
	MAXON_METHOD Result<void> AddStringParameter(String value, const InternedId& id);
	MAXON_METHOD Result<void> AddIdParameter(Id value, const InternedId& id);
	MAXON_METHOD Result<void> AddInternedIdParameter(InternedId value, const InternedId& id);
	MAXON_METHOD Result<void> AddCStringParameter(CString value, const InternedId& id);

	MAXON_METHOD Result<void> AddParameters(const DataDictionary& parameters);

	MAXON_METHOD Result<GroupNodeData> Finalize();

	static MAXON_METHOD Result<void> AddConnectedTextureNodes(const GroupNodeData& groupData, const material::MaterialExchangeData& materialData);
};

#include "nodematerialimport1.hxx"
#include "nodematerialimport2.hxx"

} // namespace nodes
} // namespace maxon

#endif // NODEMATERIALIMPORT_H__