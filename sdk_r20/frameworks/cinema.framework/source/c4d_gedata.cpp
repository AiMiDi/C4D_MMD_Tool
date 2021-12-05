#include "c4d_gedata.h"
#include "c4d_baselist.h"

BaseList2D* GeData::GetLink(const BaseDocument* doc, Int32 instanceof) const
{
	BaseLink* link = C4DOS.Gd->GetLink(this);
	if (!link)
		return nullptr;
	return link->GetLink(doc, instanceof);
}

C4DAtomGoal* GeData::GetLinkAtom(const BaseDocument* doc, Int32 instanceof) const
{
	BaseLink* link = C4DOS.Gd->GetLink(this);
	if (!link)
		return nullptr;
	return link->GetLinkAtom(doc, instanceof);
}

BrowseContainer::BrowseContainer(const BaseContainer* bc)
{
	t_bc = (BaseContainer*)bc;
	handle = C4DOS.Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

void BrowseContainer::Reset(void)
{
	handle = C4DOS.Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

Bool BrowseContainer::GetNext(Int32* id, GeData** data)
{
	if (!handle)
		return false;
	handle = C4DOS.Bc->BrowseContainer(t_bc, id, data, handle);
	return true;
}
