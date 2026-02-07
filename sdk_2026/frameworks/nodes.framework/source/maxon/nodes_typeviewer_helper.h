#ifndef NODES_TYPEVIEWER_HELPER_H__
#define NODES_TYPEVIEWER_HELPER_H__

#include "maxon/array.h"
#include "maxon/basearray.h"
#include "maxon/nodepath.h"

namespace maxon
{

#if (defined MAXON_TARGET_WINDOWS) && ((defined MAXON_TARGET_DEBUG) || BRANCH_RELEASE_TYPE_VALUE >= 1)

	// Helper declaration for natvis file. Used to avoid some long ugly type case in natvis.
	// Also not all module debug informations contains the types below. So it can happen
	// that natvis would generate error when casting to some of the types below depending on the module being debugged.
	// So by adding a helper definition, we are sure whatever module is being debugged, those types are known.
	// Definition here would cause some crash cases on shutdown. Keep the definitions in a module with Global<>.

	struct NodePathBaseArrayNatVisHelper : public BaseArray<NodePath> {};

	struct NodePathStaticArrayNatVisHelper : public StaticArray<NodePath> {};

	struct NodePathArrayNodePathTupleNatVisHelper : public Tuple<NodePath, StaticArray<NodePath>> {};

#endif

} // namespace maxon


#endif // NODES_TYPEVIEWER_HELPER_H__
