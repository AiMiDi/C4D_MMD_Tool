#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_memory.h"
#include "c4d_basecontainer.h"

BaseContainer::BaseContainer(void)
{
	BcCall(SDKInit) (NOTOK, nullptr);
}

BaseContainer::BaseContainer(Int32 id)
{
	BcCall(SDKInit) (id, nullptr);
}

BaseContainer::BaseContainer(const BaseContainer& src)
{
	BcCall(SDKInit) (NOTOK, &src);
}

BaseContainer::~BaseContainer(void)
{
	FlushAll();
}

const BaseContainer& BaseContainer::operator = (const BaseContainer& n)
{
	n.CopyTo(this, COPYFLAGS::NONE, nullptr);
	return *this;
}

Bool BaseContainer::operator == (const BaseContainer& c) const
{
	return C4DOS.Bc->Compare(*this, c);
}

Bool BaseContainer::operator != (const BaseContainer& c) const
{
	return !C4DOS.Bc->Compare(*this, c);
}

BaseLink* BaseContainer::GetBaseLink (Int32 id) const
{
	const GeData& dat = GetData(id);
	return dat.GetBaseLink();
}

BaseObject* BaseContainer::GetObjectLink(Int32 id, const BaseDocument* doc) const
{
	return (BaseObject*)GetLink(id, doc, Obase);
}

BaseMaterial* BaseContainer::GetMaterialLink(Int32 id, const BaseDocument* doc) const
{
	return (BaseMaterial*)GetLink(id, doc, Mbase);
}

const CustomDataType*	BaseContainer::GetCustomDataType(Int32 id, Int32 datatype) const
{
	const GeData& dat = GetData(id);
	return dat.GetCustomDataType(datatype);
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

