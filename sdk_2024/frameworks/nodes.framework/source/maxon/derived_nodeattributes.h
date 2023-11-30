#ifndef DERIVED_NODEATTRIBUTES_H__
#define DERIVED_NODEATTRIBUTES_H__

#include "maxon/fid.h"
#include "maxon/idandversion.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// Id of the asset. Not set in case the node is not an asset (group).
/// The value of this attribute is set automatically upon first request.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(IdAndVersion, AssetId, "net.maxon.node.attribute.assetid");

//----------------------------------------------------------------------------------------
/// Id of the database where the object is stored.
/// The value of this attribute is set automatically upon first request.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Id, RepositoryId, "net.maxon.node.attribute.repositoryid");

//----------------------------------------------------------------------------------------
/// True if the node is inside an asset and, thus, not user-accessible during editing of node graph.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IsInsideAsset, "net.maxon.node.attribute.isinsideasset");

} // namespace nodes

} // namespace maxon

#endif // DERIVED_NODEATTRIBUTES_H__
