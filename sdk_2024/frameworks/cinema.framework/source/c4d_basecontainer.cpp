#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_memory.h"
#include "c4d_baseobject.h"
#include "c4d_basematerial.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BaseContainer::BaseContainer(Int32 id)
{
	BcCall(SDKInit) (id, nullptr);
}

BaseContainer::BaseContainer(const BaseContainer& src)
{
	BcCall(SDKInit) (NOTOK, &src);
}

const BaseContainer& BaseContainer::operator = (const BaseContainer& n)
{
	n.CopyTo(this, COPYFLAGS::NONE, nullptr);
	return *this;
}

Bool BaseContainer::operator == (const BaseContainer& c) const
{
	return C4DOS_Bc->Compare(*this, c);
}

Bool BaseContainer::operator != (const BaseContainer& c) const
{
	return !C4DOS_Bc->Compare(*this, c);
}

const BaseLink* BaseContainer::GetBaseLink(Int32 id) const
{
	const GeData& dat = GetData(id);
	return dat.GetBaseLink();
}

const BaseObject* BaseContainer::GetObjectLink(Int32 id, const BaseDocument* doc) const
{
	return static_cast<const BaseObject*>(GetLink(id, doc, Obase));
}

const BaseMaterial* BaseContainer::GetMaterialLink(Int32 id, const BaseDocument* doc) const
{
	return static_cast<const BaseMaterial*>(GetLink(id, doc, Mbase));
}

void BaseContainer::MergeContainer(const BaseContainer& src)
{
	BcCall(Merge) (src);
}

Int32 BaseContainer::GetType(Int32 id) const
{
	const GeData* d = BcCall(GetDataPointer) (id);
	if (!d)
		return DA_NIL;
	return d->GetType();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
