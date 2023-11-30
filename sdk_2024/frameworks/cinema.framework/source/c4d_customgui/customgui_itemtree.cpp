#include "customgui_itemtree.h"
#include "c4d_string.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static CustomGuiItemTreeLib *lib_itemtree = nullptr;

static CustomGuiItemTreeLib *CheckItemTree(Int32 offset)
{
	return CheckLib<CustomGuiItemTreeLib>(CUSTOMGUI_ITEMTREE, offset, lib_itemtree);
}

#define ItemTreeCall(b)       CustomGuiItemTreeLib *lib = CheckItemTree(LIBOFFSET(CustomGuiItemTreeLib, b)); \
	if (!lib || !lib->b) return; \
	(reinterpret_cast<iItemTreeData*>(this)->*lib->b)

#define ItemTreeCallR(a, b)     CustomGuiItemTreeLib *lib = CheckItemTree(LIBOFFSET(CustomGuiItemTreeLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<iItemTreeData*>(this)->*lib->b)

#define ItemTreeCallRC(a, b)     CustomGuiItemTreeLib *lib = CheckItemTree(LIBOFFSET(CustomGuiItemTreeLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<const iItemTreeData*>(this)->*lib->b)

#define ItemTreeStaticCall(b)       CustomGuiItemTreeLib *lib = CheckItemTree(LIBOFFSET(CustomGuiItemTreeLib, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define ItemTreeStaticCallR(a, b)     CustomGuiItemTreeLib *lib = CheckItemTree(LIBOFFSET(CustomGuiItemTreeLib, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)

ItemTreeNode *ItemTreeData::AddItem(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, Bool aslast) { ItemTreeCallR(nullptr, AddItem)(id, name, bl, data, flags, aslast); }
ItemTreeNode *ItemTreeData::AddNode(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast) { ItemTreeCallR(nullptr, AddNode)(id, name, bl, data, flags, parent, prev, aslast); }
BaseContainer *ItemTreeData::GetUserData() { ItemTreeCallR(nullptr, GetUserData)(); }
void ItemTreeData::SetOwner(BaseList2D *bl) { ItemTreeCall(SetOwner)(bl); }
ItemTreeNodeData *ItemTreeData::GetNodeData(ItemTreeNode *node) { ItemTreeCallR(nullptr, GetNodeData)(node); }
const ItemTreeNodeData* ItemTreeData::GetNodeData(const ItemTreeNode* node) const { return MAXON_REMOVE_CONST(this)->GetNodeData(MAXON_REMOVE_CONST(node)); }
ItemTreeNode *ItemTreeData::GetiNext(ItemTreeNode *node, ItemTreeNode *topnode) { ItemTreeCallR(nullptr, GetiNext)(node, topnode); }
const ItemTreeNode* ItemTreeData::GetiNext(const ItemTreeNode* node, const ItemTreeNode* topnode) const { return MAXON_REMOVE_CONST(this)->GetiNext(MAXON_REMOVE_CONST(node), MAXON_REMOVE_CONST(topnode)); }
ItemTreeNode *ItemTreeData::GetNext(ItemTreeNode *node) { ItemTreeCallR(nullptr, GetNext)(node); }
const ItemTreeNode* ItemTreeData::GetNext(const ItemTreeNode* node) const { return MAXON_REMOVE_CONST(this)->GetNext(MAXON_REMOVE_CONST(node)); }
ItemTreeNode *ItemTreeData::GetPrev(ItemTreeNode *node) { ItemTreeCallR(nullptr, GetPrev)(node); }
ItemTreeNode *ItemTreeData::GetUp(ItemTreeNode *node) { ItemTreeCallR(nullptr, GetUp)(node); }
const ItemTreeNode *ItemTreeData::GetUp(const ItemTreeNode *node) const { return MAXON_REMOVE_CONST(this)->GetUp(MAXON_REMOVE_CONST(node)); }
ItemTreeNode *ItemTreeData::GetDown(ItemTreeNode *node) { ItemTreeCallR(nullptr, GetDown)(node); }
const ItemTreeNode* ItemTreeData::GetDown(const ItemTreeNode* node) const { return MAXON_REMOVE_CONST(this)->GetDown(MAXON_REMOVE_CONST(node)); }
ItemTreeNode *ItemTreeData::GetRoot() { ItemTreeCallR(nullptr, GetRoot)(); }
ItemTreeNode *ItemTreeData::GetFirst() { ItemTreeCallR(nullptr, GetFirst)(); }
const ItemTreeNode* ItemTreeData::GetFirst() const { return MAXON_REMOVE_CONST(this)->GetFirst(); }
void ItemTreeData::Remove(ItemTreeNode *node) { ItemTreeCall(Remove)(node); }
void ItemTreeData::FreeNode(ItemTreeNode *&node) { ItemTreeCall(FreeNode)(node); }
void ItemTreeData::Insert(ItemTreeNode *node, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast) { ItemTreeCall(Insert)(node, parent, prev, aslast); }
Int32 ItemTreeData::GetSelected(ItemTreeNode ***table, Bool children) { ItemTreeCallR(0, GetSelected)(table, children); }
ItemTreeNode *ItemTreeData::Find(UInt64 guid, ItemTreeNode *node) { ItemTreeCallR(nullptr, Find)(guid, node); }
const ItemTreeNode* ItemTreeData::Find(UInt64 guid, const ItemTreeNode* node) const
{
	return MAXON_REMOVE_CONST(this)->Find(guid, MAXON_REMOVE_CONST(node));
}
ItemTreeNode *ItemTreeData::Find(UInt64 guid, Int32 id, Bool child, ItemTreeNode *node) { ItemTreeCallR(nullptr, FindID)(guid, id, child, node); }
const ItemTreeNode* ItemTreeData::Find(UInt64 guid, Int32 id, Bool child, const ItemTreeNode* node) const
{
	return MAXON_REMOVE_CONST(this)->Find(guid, id, child, MAXON_REMOVE_CONST(node));
}
void ItemTreeData::ClearSelection() { ItemTreeCall(ClearSelection)(); }
void ItemTreeData::SetSelectedID(UInt64 guid) { ItemTreeCall(SetSelectedID)(guid); }
void ItemTreeData::SetSelected(ItemTreeNode *node) { ItemTreeCall(SetSelected)(node); }
ItemTreeNode *ItemTreeData::GetFirstSelected() { ItemTreeCallR(nullptr, GetFirstSelected)(); }
const ItemTreeNode* ItemTreeData::GetFirstSelected() const
{
	return MAXON_REMOVE_CONST(this)->GetFirstSelected();
}
void ItemTreeData::Reset() { ItemTreeCall(Reset)(); }
ItemTreeNodeIndex *ItemTreeData::BuildIndexTable(Int32 &tcnt, Bool sorted) { ItemTreeCallR(nullptr, BuildIndexTable)(tcnt, sorted); }
Int32 ItemTreeData::GetClipCount() { ItemTreeCallR(0, GetClipCount)(); }
ItemTreeNode **ItemTreeData::GetClipArray() { ItemTreeCallR(nullptr, GetClipArray)(); }
Int32 ItemTreeData::GetNodeTable(ItemTreeNode ***table) { ItemTreeCallR(0, GetNodeTable)(table); }
void ItemTreeData::RemoveSelected() { ItemTreeCall(RemoveSelected)(); }
UInt64 ItemTreeData::GetChecksum() const { ItemTreeCallRC(UInt64(-1), GetChecksum)(); }
maxon::HashInt ItemTreeData::GetHashCode(Bool onlyGuid) const { ItemTreeCallRC(maxon::HashInt(), GetHashCode)(onlyGuid); }
void ItemTreeData::SortNames(BaseDocument *doc) { ItemTreeCall(SortNames)(doc); }
UInt64 ItemTreeData::GetSelectedID() { ItemTreeCallR(0, GetSelectedID)(); }
void ItemTreeData::Validate(BaseDocument *doc) { ItemTreeCall(Validate)(doc); }
Bool ItemTreeData::CopyFrom(ItemTreeData *src) { ItemTreeCallR(false, CopyFrom)(src); }
void ItemTreeData::AddToSelected(ItemTreeNode *node) { ItemTreeCall(AddToSelected)(node); }

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
