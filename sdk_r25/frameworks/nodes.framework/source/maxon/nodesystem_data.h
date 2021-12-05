#ifndef NODESYSTEM_DATA_H__
#define NODESYSTEM_DATA_H__

#include "maxon/nodesystem.h"

namespace maxon
{

namespace nodes
{

class SerializationNodeData;

//----------------------------------------------------------------------------------------
/// NodeSystemData represents the serializable data of a NodeSystem. Node systems themselves
/// can't be serialized, however you can call NodeSystem::GetNodeSystemData() to extract
/// their persistent, serializable data and serialize that. After deserialization you have
/// to call Instantiate to obtain a node system from the pure data.
//----------------------------------------------------------------------------------------
class NodeSystemDataInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemDataInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.nodesystemdata");
public:
	//----------------------------------------------------------------------------------------
	/// Instantiates the node system described by this NodeSystemData for the given node system
	/// class. To resolve asset references #repo will be used.
	/// @param[in] cls								The node system class to use for the instantiation.
	/// @param[in] repo								The asset repository to use for asset resolution.
	/// @param[out] updateReferences	If nullptr, asset references won't be updated to the latest version. Otherwise
	///																they will (where the ASSET_UPDATE_POLICY allows), and the Bool will be set to
	///																true if at least one asset reference was updated.
	/// @return												The node system which is described by this NodeSystemData.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, Bool* updateReferences) const;

	MAXON_METHOD SerializationNodeData* GetData();

	//----------------------------------------------------------------------------------------
	/// Instantiates the node system described by this NodeSystemData for the given node system
	/// class. To resolve asset references #repo will be used.
	/// @param[in] cls								The node system class to use for the instantiation.
	/// @param[in] repo								The asset repository to use for asset resolution.
	/// @param[in] additionalContext	Supplementary instantiation context parameters.
	/// @param[out] updateReferences	If nullptr, asset references won't be updated to the latest version. Otherwise
	///																they will (where the ASSET_UPDATE_POLICY allows), and the Bool will be set to
	///																true if at least one asset reference was updated.
	/// @return												The node system which is described by this NodeSystemData.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodeSystem> Instantiate(const NodeSystemClass& cls, const AssetRepositoryRef& repo, const DataDictionary& additionalContext, Bool* updateReferences) const;
};


#include "nodesystem_data1.hxx"

#include "nodesystem_data2.hxx"

}

} // namespace maxon

#endif // NODESYSTEM_DATA_H__
