/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_NODEPLUGIN_H__
#define C4D_NODEPLUGIN_H__

#include "c4d_nodedata.h"
#include "c4d_baseplugin.h"

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

	NodeData*			(*Allocator										)(void);

	Bool					(NodeData::*Init							)(GeListNode *node);
	void					(NodeData::*Free							)(GeListNode *node);
	Bool					(NodeData::*Read							)(GeListNode *node, HyperFile *hf, Int32 level);
	Bool					(NodeData::*Write							)(GeListNode *node, HyperFile *hf);
	Bool					(NodeData::*CopyTo						)(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	Bool					(NodeData::*Message						)(GeListNode *node, Int32 type, void *data);
	BaseDocument*	(NodeData::*GetDocument				)(GeListNode *node);
	void					(NodeData::*GetBubbleHelp			)(GeListNode *node, maxon::String &str);
	Bool					(NodeData::*GetDDescription		)(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	Bool					(NodeData::*GetDParameter			)(GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags);
	Bool					(NodeData::*SetDParameter			)(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_SET &flags);
	Bool					(NodeData::*GetDEnabling			)(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc);
	Bool					(NodeData::*IsInstanceOf			)(const GeListNode *node, Int32 type) const;
	Int32					(NodeData::*GetBranchInfo			)(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	Bool					(NodeData::*TranslateDescID		)(GeListNode *node, const DescID &id, DescID &res_id, C4DAtom *&res_at);
	Bool					(NodeData::*IsDocumentRelated	)(const GeListNode *node, Bool &docrelated) const;

	void* reserved[(32-16)*C4DPL_MEMBERMULTIPLIER - 5];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_NODEPLUGIN_H__
