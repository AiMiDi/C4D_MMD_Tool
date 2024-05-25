#include "c4d_accessedobjects.h"
#include "c4d_nodeplugin.h"
#include "c4d_general.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

Bool NodeData::Init(GeListNode* node, Bool isCloneInit)
{
	return true;
}

void NodeData::Free(GeListNode* node)
{
}

Bool NodeData::CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) const
{
	return true;
}

Bool NodeData::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	return true;
}

Bool NodeData::Write(const GeListNode* node, HyperFile* hf) const
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

const BaseDocument* NodeData::GetDocument(const GeListNode* node) const
{
	return nullptr;
}

maxon::Result<Bool> NodeData::GetBranchInfo(const GeListNode* node, const maxon::ValueReceiver<const BranchInfo&>& info, GETBRANCHINFO flags) const
{
	return true;
}

Bool NodeData::TranslateDescID(GeListNode* node, const DescID& id, DescID& res_id, C4DAtom*& res_at)
{
	return false;
}

Bool NodeData::IsDocumentRelated(const GeListNode* node, Bool& docrelated) const
{
	return false;
}

Bool NodeData::GetDDescription(const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) const
{
	return false;
}

Bool NodeData::GetDEnabling(const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) const
{
	return true;
}

Bool NodeData::GetDParameter(const GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags) const
{
	return true;
}

Bool NodeData::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	return true;
}

maxon::Result<Bool> NodeData::GetAccessedObjects(const BaseList2D* node, METHOD_ID method, AccessedObjectsCallback& access) const
{
	return access.MayAccessAnything();
}

maxon::Result<maxon::GenericData> NodeData::GroupChanges(BaseList2D* node)
{
	return {};
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
	np->IsDocumentRelated = &NodeData::IsDocumentRelated;
	np->GetAccessedObjects = &NodeData::GetAccessedObjects;
	np->GroupChanges = &NodeData::GroupChanges;

	np->disklevel	= disklevel;
	np->infoBits = info;
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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
