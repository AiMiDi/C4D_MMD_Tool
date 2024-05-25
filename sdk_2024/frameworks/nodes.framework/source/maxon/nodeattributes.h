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
/// When this attribute is true for a root node of a node system then that node system
/// can be converted to a user-editable group.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(Bool, IsGroup, "isgroup");

//----------------------------------------------------------------------------------------
/// When this attribute is true for a group node this means that the group can't be dissolved
/// into its components (e.g. because it has some extra semantics like ports which receive
/// context or hidden nodes inherited from a base).
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
MAXON_ATTRIBUTE(Asset, AssetInstance, "net.maxon.node.attribute.asset");

/// Id prefix used for filling the AssetId attribute on wrapped CoreNodes.
/// The rest of the Id will be the CoreNode's real registered Id.
/// @markPrivate
static constexpr Char g_corePrefix[] = "net.maxon.corenode:";

/// Lifetime node identifier prefix. The rest of the identifier is the identifier of the associated port.
/// For instance: ".containerin".
/// @markPrivate
static constexpr Char g_lifetimeNodePrefix = '.';

// This separator is used when the compiler sets up a core node id from a user node NodePath.
// It separates the path part from possible suffixes (such as component access information or instantiation scopes).
// These suffixes are needed to make the core node id unique. Also used internally to identify variadic ports.
/// @markPrivate
static constexpr Char g_userNodeIdSeparator = '#';

} // namespace nodes

} // namespace maxon

#endif // NODEATTRIBUTES_H__
