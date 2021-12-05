#include "c4d_nodeplugin.h"
#include "c4d_general.h"

Bool NodeData::Init(GeListNode* node)
{
	return true;
}

void NodeData::Free(GeListNode* node)
{
}

Bool NodeData::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	return true;
}

Bool NodeData::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	return true;
}

Bool NodeData::Write(GeListNode* node, HyperFile* hf)
{
	return true;
}

Bool NodeData::Message(GeListNode* node, Int32 type, void* data)
{
	return true;
}

void NodeData::GetBubbleHelp(GeListNode* node, maxon::String& str)
{
}

Bool NodeData::IsInstanceOf(const GeListNode* node, Int32 type) const
{
	return false;
}

BaseDocument* NodeData::GetDocument(GeListNode* node)
{
	return nullptr;
}

Int32 NodeData::GetBranchInfo(GeListNode* node, BranchInfo* info, Int32 max, GETBRANCHINFO flags)
{
	return 0;
}

Bool NodeData::TranslateDescID(GeListNode* node, const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return false;
}

Bool NodeData::IsDocumentRelated(const GeListNode* node, Bool& docrelated) const
{
	return false;
}

Bool NodeData::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	return false;
}

Bool NodeData::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
{
	return true;
}

Bool NodeData::GetDParameter(GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags)
{
	return true;
}

Bool NodeData::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	return true;
}

void FillNodePlugin(NODEPLUGIN* np, Int32 info, DataAllocator* g, BaseBitmap* icon, Int32 disklevel)
{
	np->Allocator	 = g;
	np->Destructor = &NodeData::Destructor;
	np->Init		= &NodeData::Init;
	np->Free		= &NodeData::Free;
	np->Read		= &NodeData::Read;
	np->Write		= &NodeData::Write;
	np->CopyTo	= &NodeData::CopyTo;
	np->Message	= &NodeData::Message;
	np->GetDocument	= &NodeData::GetDocument;
	np->GetBranchInfo	= &NodeData::GetBranchInfo;
	np->GetDDescription	= &NodeData::GetDDescription;
	np->GetDParameter	= &NodeData::GetDParameter;
	np->SetDParameter	= &NodeData::SetDParameter;
	np->GetDEnabling	= &NodeData::GetDEnabling;
	np->GetBubbleHelp = &NodeData::GetBubbleHelp;
	np->IsInstanceOf	= &NodeData::IsInstanceOf;
	np->TranslateDescID = &NodeData::TranslateDescID;
	np->IsDocumentRelated	= &NodeData::IsDocumentRelated;

	np->disklevel	= disklevel;
	np->info = info;
	np->icon = icon;
	np->fallback	= nullptr;
}

Bool RegisterNodePlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, BaseBitmap* icon, Int32 disklevel, Int32* fallback)
{
	NODEPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillNodePlugin(&np, info, g, icon, disklevel);
	np.fallback = fallback;
	return GeRegisterPlugin(PLUGINTYPE::NODE, id, str, &np, sizeof(np));
}
