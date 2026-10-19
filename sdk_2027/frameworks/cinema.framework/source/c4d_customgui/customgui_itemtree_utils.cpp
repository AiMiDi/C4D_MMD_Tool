#include "customgui_itemtree_utils.h"

namespace cinema
{

static ItemTreeNodeDataLib* lib_itemtree_node_data = nullptr;

static ItemTreeNodeDataLib* CheckItemTreeNodeData(Int32 offset)
{
	return CheckLib<ItemTreeNodeDataLib>(LIBRARY_ITEMTREE_NODEDATA, offset, lib_itemtree_node_data);
}

#define ItemTreeNodeDataCallR(a, b) ItemTreeNodeDataLib* lib = cinema::CheckItemTreeNodeData(LIBOFFSET(cinema::ItemTreeNodeDataLib, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)

ItemTreeNodeData::ItemTreeNodeData()
{
	ItemTreeNodeDataLib* lib = CheckItemTreeNodeData(LIBOFFSET(ItemTreeNodeDataLib, Construct));
	if (lib && lib->Construct)
		lib->Construct(this);
}

ItemTreeNodeData::~ItemTreeNodeData()
{
	ItemTreeNodeDataLib* lib = CheckItemTreeNodeData(LIBOFFSET(ItemTreeNodeDataLib, Destruct));
	if (lib && lib->Destruct)
		lib->Destruct(this);
}

ItemTreeNodeData::ItemTreeNodeData(const ItemTreeNodeData& src)
{
	ItemTreeNodeDataLib* lib = CheckItemTreeNodeData(LIBOFFSET(ItemTreeNodeDataLib, CopyConstruct));
	if (lib && lib->CopyConstruct)
		lib->CopyConstruct(this, &src);
}

const ItemTreeNodeData& ItemTreeNodeData::operator =(const ItemTreeNodeData& src)
{
	ItemTreeNodeDataCallR(*this, Assign)(this, &src);
}

Bool ItemTreeNodeData::operator !=(const ItemTreeNodeData& rhs) const
{
	ItemTreeNodeDataCallR(false, NotEqual)(this, &rhs);
}

Bool ItemTreeNodeData::CopyFrom(const ItemTreeNodeData& src, AliasTrans* trn)
{
	ItemTreeNodeDataCallR(false, CopyFrom)(this, &src, trn);
}

Bool ItemTreeNodeData::Init()
{
	ItemTreeNodeDataCallR(false, Init)(this);
}

Bool ItemTreeNodeData::Write(HyperFile* hf) const
{
	ItemTreeNodeDataCallR(false, Write)(this, hf);
}

Bool ItemTreeNodeData::Read(HyperFile* hf)
{
	ItemTreeNodeDataCallR(false, Read)(this, hf);
}

} // namespace cinema