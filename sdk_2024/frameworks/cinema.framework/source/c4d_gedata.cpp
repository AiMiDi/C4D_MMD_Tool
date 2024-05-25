#include "c4d_gedata.h"
#include "c4d_baselist.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

const BaseList2D* GeData::GetLink(const BaseDocument* doc, Int32 instanceof) const
{
	const BaseLink* link = C4DOS_Gd->GetLink(this);
	if (!link)
		return nullptr;
	return link->GetLink(doc, instanceof);
}

const C4DAtomGoal* GeData::GetLinkAtom(const BaseDocument* doc, Int32 instanceof) const
{
	const BaseLink* link = C4DOS_Gd->GetLink(this);
	if (!link)
		return nullptr;
	return link->GetLinkAtom(doc, instanceof);
}

BrowseContainer::BrowseContainer(BaseContainer* bc)
{
	t_bc = bc;
	handle = C4DOS_Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

void BrowseContainer::Reset()
{
	handle = C4DOS_Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

Bool BrowseContainer::GetNext(Int32* id, GeData** data)
{
	if (!handle)
		return false;
	handle = C4DOS_Bc->BrowseContainer(t_bc, id, const_cast<const GeData**>(data), handle);
	return true;
}

BrowseConstContainer::BrowseConstContainer(const BaseContainer* bc)
{
	t_bc = bc;
	handle = C4DOS_Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

void BrowseConstContainer::Reset()
{
	handle = C4DOS_Bc->BrowseContainer(t_bc, nullptr, nullptr, nullptr);
}

Bool BrowseConstContainer::GetNext(Int32* id, const GeData** data)
{
	if (!handle)
		return false;
	handle = C4DOS_Bc->BrowseContainer(t_bc, id, data, handle);
	return true;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
