#ifndef NODEATTRIBUTES_H__
#define NODEATTRIBUTES_H__

#include "maxon/assets.h"
#include "maxon/fid.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// Id of the scaffold to which the node is attached. Optional.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(InternedId, ScaffoldId, "net.maxon.node.attribute.scaffoldid");

//----------------------------------------------------------------------------------------
/// When this attribute is true for the root node of a node system then that node system
/// is a user-editable group. In the node editor, the user can enter the group and make changes.
/// This includes non-trivial groups like instances of loop-carried-value nodes.
/// 
/// By default, a node system is a user-editable group unless it's a direct instantiation of a non-group template
/// (a template where IsGroupBase() returns false) or an instance of such an instantiation.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IsEditableGroup, "isgroup", MAXON_ATTRIBUTE_READONLY);

[[deprecated("use IsEditableGroup (since 2024.2)")]] static const IsEditableGroup_PrivateHelper& IsGroup = IsEditableGroup;

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for a root node of a template instantiation to tell
/// that the instantiation can be detached from the template and turned into a user-editable node.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, DetachableForEdit, "detachableforedit");

[[deprecated("renamed to DetachableForEdit (since 2026.0)")]] static const DetachableForEdit_PrivateHelper& IsConvertibleToGroup = DetachableForEdit;

//----------------------------------------------------------------------------------------
/// When this attribute is true for a group node this means that the group can't be dissolved
/// into its components (e.g. because it has some extra semantics like ports which receive
/// context or hidden nodes inherited from a base, for example the loop-carried-value node).
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IndissolubleGroup, "indissolublegroup");

//----------------------------------------------------------------------------------------
/// This attribute can be set to true for nodes that will ignore their first base
/// in HasBase and GetAllBases calls.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IgnoreBase, "ignorebase");

//----------------------------------------------------------------------------------------
/// This attribute can be set on a node to restrict description derivation to the node itself.
/// Any connected nodes aren't considered for description derivation. This can help to speed
/// up description derivation when a node knows that its descriptions are self-contained.
/// 
/// The value of this attribute must not be modified after first validation.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, InternalDescriptionDerivation, "internaldescriptionderivation");

//----------------------------------------------------------------------------------------
/// This attribute contains the node asset's instance. 
/// AssetInstance is DerivedAttribute::KIND::COMPUTED and cannot be written to.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Asset, AssetInstance, "net.maxon.node.attribute.asset", MAXON_ATTRIBUTE_READONLY);

//----------------------------------------------------------------------------------------
/// Set when an asset is converted to group, reset when the group is saved as asset.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(IdAndVersion, OriginalAsset, "net.maxon.node.originalasset");

//----------------------------------------------------------------------------------------
/// Id and the version of the original Asset Id NodeTemplate of a scene node capsule.
/// The value of this attribute is set on capsule creation and its stored on the root node of the capsule graph.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(IdAndVersion, CapsuleAssetId, "net.maxon.node.attribute.capsuleassetid", MAXON_ATTRIBUTE_READONLY);

//----------------------------------------------------------------------------------------
/// Set a detailed node error in this attribute to indicate graph execution failure.
/// The message will be visible to users, so it shall be readable.
/// The error can be set on any node (including root node) so that users can pinpoint the source of the issue.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Error, ExecutionError, "executionerror");

//----------------------------------------------------------------------------------------
/// Set a detailed node message in this attribute to indicate graph execution non blocking issue.
/// The message will be visible to users, so it shall be readable.
/// The message can be set on any node (including root node) so that users can pinpoint the source of the issue.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Error, ExecutionMessage, "executionmsg");

} // namespace nodes

} // namespace maxon

#endif // NODEATTRIBUTES_H__
