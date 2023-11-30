/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_NODEPLUGIN_H__
#define C4D_NODEPLUGIN_H__

#include "c4d_nodedata.h"
#include "c4d_baseplugin.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct NODEPLUGIN : public BASEPLUGIN
{
	Int32					disklevel;
	const String* name;
	Int32*				fallback;
	BaseBitmap*		icon;

	NodeData*			(*Allocator										)();

	Bool					(NodeData::*Init							)(GeListNode *node, Bool isCloneInit);
	void					(NodeData::*Free							)(GeListNode *node);
	Bool					(NodeData::*Read							)(GeListNode *node, HyperFile *hf, Int32 level);
	Bool					(NodeData::*Write							)(const GeListNode *node, HyperFile *hf) const;
	Bool					(NodeData::*CopyTo						)(NodeData *dest, const GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn) const;
	Bool					(NodeData::*Message						)(GeListNode *node, Int32 type, void *data);
	const BaseDocument*	(NodeData::*GetDocument				)(const GeListNode *node) const;
	void					(NodeData::*GetBubbleHelp			)(GeListNode *node, maxon::String &str);
	Bool					(NodeData::*GetDDescription		)(const GeListNode *node, Description *description, DESCFLAGS_DESC &flags) const;
	Bool					(NodeData::*GetDParameter			)(const GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags) const;
	Bool					(NodeData::*SetDParameter			)(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_SET &flags);
	Bool					(NodeData::*GetDEnabling			)(const GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc) const;
	Bool					(NodeData::*IsInstanceOf			)(const GeListNode *node, Int32 type) const;
	maxon::Result<Bool> (NodeData::*GetBranchInfo)(const GeListNode *node, const maxon::ValueReceiver<const BranchInfo&>& info, GETBRANCHINFO flags) const;
	Bool					(NodeData::*TranslateDescID		)(GeListNode *node, const DescID &id, DescID &res_id, C4DAtom *&res_at);
	Bool					(NodeData::*IsDocumentRelated	)(const GeListNode *node, Bool &docrelated) const;
	maxon::Result<Bool> (NodeData::*GetAccessedObjects)(const BaseList2D* node, METHOD_ID method, AccessedObjectsCallback& access) const;
	maxon::Result<maxon::GenericData> (NodeData::*GroupChanges)(BaseList2D* node);

	void* reserved[(32 - 18) * C4DPL_MEMBERMULTIPLIER - 5];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_NODEPLUGIN_H__
