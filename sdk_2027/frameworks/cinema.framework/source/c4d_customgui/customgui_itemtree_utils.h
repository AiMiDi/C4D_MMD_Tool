/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_ITEMTREE_UTILS_H__
#define CUSTOMGUI_ITEMTREE_UTILS_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"

#include "customgui_itemtree.h"

namespace cinema
{

#define LIBRARY_ITEMTREE_NODEDATA 1069781 ///< @brief Identifies the item tree node data library.

class TreeViewCustomGui;
struct DrawInfo;
class ItemTreeNode;
class ItemTreeData;
class ItemTreeNodeData;
class iBaseCustomGui;

static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_OPEN = 1 << 3; // @brief Node is open in the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_SELECT = 1 << 4; // @brief Node is selected in the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_ENABLE = 1 << 5; // @brief Node is enabled in the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_FOLDER = 1 << 12; // @brief Node is a folder in the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_MARK = 1 << 17; // @brief Node is marked in the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_NOREMOVE = 1 << 18; // @brief Node cannot be removed from the tree view.
static constexpr UInt32 ITEMTREE_NODEDATA_FLAG_HIDDEN = 1 << 20; // @brief Node is hidden in the tree view.

//----------------------------------------------------------------------------------------
/// @brief Identifies a node in an item tree's flattened index table.
/// @details Stores the node's traversal index, stable GUID, opaque node pointer, and
/// associated payload pointer. The records can be sorted by GUID for stable lookup.
/// @note The use of the predefined `ITEMTREE_NODEDATA_FLAG` flags is optional. You can also define and use your own flags.
//----------------------------------------------------------------------------------------
class ItemTreeNodeIndex
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Initializes an empty index record.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeIndex() { }

	//----------------------------------------------------------------------------------------
	/// @brief Initializes an index record with a node GUID.
	/// @param[in] guid Node GUID.
	//----------------------------------------------------------------------------------------
	explicit ItemTreeNodeIndex(UInt64 guid) : m_GUID(guid) { }

	//----------------------------------------------------------------------------------------
	/// @brief Compares two records by GUID.
	/// @param[in] dst Record to compare with this record.
	/// @return `true` if this record's GUID is less than `dst`'s GUID.
	//----------------------------------------------------------------------------------------
	Bool operator <(const ItemTreeNodeIndex& dst) const { return m_GUID < dst.m_GUID; }

	//----------------------------------------------------------------------------------------
	/// @brief Compares two records by GUID.
	/// @param[in] dst Record to compare with this record.
	/// @return `true` if this record's GUID is greater than `dst`'s GUID.
	//----------------------------------------------------------------------------------------
	Bool operator >(const ItemTreeNodeIndex& dst) const { return m_GUID > dst.m_GUID; }

	//----------------------------------------------------------------------------------------
	/// @brief Compares two records by GUID.
	/// @param[in] dst Record to compare with this record.
	/// @return `true` if this record's GUID is less than or equal to `dst`'s GUID.
	//----------------------------------------------------------------------------------------
	Bool operator <=(const ItemTreeNodeIndex& dst) const { return m_GUID <= dst.m_GUID; }

	//----------------------------------------------------------------------------------------
	/// @brief Compares two records by GUID.
	/// @param[in] dst Record to compare with this record.
	/// @return `true` if this record's GUID is greater than or equal to `dst`'s GUID.
	//----------------------------------------------------------------------------------------
	Bool operator >=(const ItemTreeNodeIndex& dst) const { return m_GUID >= dst.m_GUID; }

	//----------------------------------------------------------------------------------------
	/// @brief Compares two records by GUID.
	/// @param[in] dst Record to compare with this record.
	/// @return `true` if both records have the same GUID.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const ItemTreeNodeIndex& dst) const { return m_GUID == dst.m_GUID; }

	Int32 m_Index = NOTOK; ///< Zero-based traversal index of the node.
	UInt64 m_GUID = 0; ///< Stable identifier of the node.
	ItemTreeNode* node = nullptr; ///< Opaque pointer to the represented node.
	ItemTreeNodeData* data = nullptr; ///< Pointer to the node payload.
};

//----------------------------------------------------------------------------------------
/// @brief Represents an element in a tree view through its state and custom data.
/// @details The payload combines the node's stable identifier, application ID, display text, view
/// flags, application-defined data, and an optional linked object. Use this class to describe
/// how a node should appear and behave; the item tree owns the payload while the payload owns
/// its linked-object reference.
//----------------------------------------------------------------------------------------
class ItemTreeNodeData
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Initializes an empty item-tree node payload.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeData();

	//----------------------------------------------------------------------------------------
	/// @brief Releases the linked object reference owned by the payload.
	//----------------------------------------------------------------------------------------
	~ItemTreeNodeData();

	//----------------------------------------------------------------------------------------
	/// @brief Copies the payload and linked-object state from `src`.
	/// @param[in] src Source payload.
	/// @return This payload after the assignment.
	//----------------------------------------------------------------------------------------
	const ItemTreeNodeData& operator =(const ItemTreeNodeData& src);

	//----------------------------------------------------------------------------------------
	/// @brief Creates a copy of an item-tree node payload.
	/// @param[in] src Source payload.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeData(const ItemTreeNodeData& src);

	//----------------------------------------------------------------------------------------
	/// @brief Compares this payload with `rhs`.
	/// @param[in] rhs Payload to compare with this payload.
	//----------------------------------------------------------------------------------------
	Bool operator !=(const ItemTreeNodeData& rhs) const;

	//----------------------------------------------------------------------------------------
	/// @brief Copies the payload and linked-object state.
	/// @param[in] src Source payload.
	/// @param[in] trn Optional alias translator for referenced data.
	/// @return `true` on success; `false` if link allocation or copying fails.
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(const ItemTreeNodeData& src, AliasTrans* trn);

	//----------------------------------------------------------------------------------------
	/// @brief Prepares the payload for use by allocating its link and assigning a stable GUID.
	/// @return `true` on success; `false` if link allocation fails.
	//----------------------------------------------------------------------------------------
	Bool Init();

	//----------------------------------------------------------------------------------------
	/// @brief Serializes the payload and linked-object state to a hyper file.
	/// @param[in] hf Hyper file receiving the serialized payload.
	/// @return `true` on success; `false` if the link cannot be allocated or written.
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile* hf) const;

	//----------------------------------------------------------------------------------------
	/// @brief Restores the payload and linked-object state from a hyper file.
	/// @param[in] hf Hyper file containing the serialized payload.
	/// @return `true` on success; `false` if the link cannot be allocated or read.
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is selected through `ITEMTREE_FLAG_SELECT`.
	/// @param[in] state `true` to select the node; `false` to clear the state.
	//----------------------------------------------------------------------------------------
	inline void SetSelected(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_SELECT, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is selected.
	/// @return `true` if the node is selected; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsSelected() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_SELECT); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is marked through `ITEMTREE_FLAG_MARK`.
	/// @param[in] state `true` to mark the node; `false` to clear the state.
	//----------------------------------------------------------------------------------------
	inline void SetMarked(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_MARK, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is marked.
	/// @return `true` if the node is marked; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsMarked() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_MARK); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is open through `ITEMTREE_FLAG_OPEN`.
	/// @param[in] state `true` to open the node; `false` to close it.
	//----------------------------------------------------------------------------------------
	inline void SetOpened(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_OPEN, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is open.
	/// @return `true` if the node is open; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsOpen() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_OPEN); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is hidden through `ITEMTREE_FLAG_HIDDEN`.
	/// @param[in] state `true` to hide the node; `false` to show it.
	//----------------------------------------------------------------------------------------
	inline void SetHidden(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_HIDDEN, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is hidden.
	/// @return `true` if the node is hidden; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsHidden() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_HIDDEN); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is enabled through `ITEMTREE_FLAG_ENABLE`.
	/// @param[in] state `true` to enable the node; `false` to disable it.
	//----------------------------------------------------------------------------------------
	inline void SetEnabled(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_ENABLE, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is enabled.
	/// @return `true` if the node is enabled; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsEnabled() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_ENABLE); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node can be removed through `ITEMTREE_FLAG_NOREMOVE`.
	/// @param[in] state `true` to prevent removal; `false` to allow it.
	//----------------------------------------------------------------------------------------
	inline void SetNoRemove(Bool state) { SetFlag(ITEMTREE_NODEDATA_FLAG_NOREMOVE, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets whether the node is visually greyed out through `ITEMTREE_FLAG_GREYED_OUT`.
	/// @param[in] state `true` to grey out the node; `false` to restore its normal appearance.
	//----------------------------------------------------------------------------------------
	inline void SetGreyedOut(Bool state) { SetFlag(ITEMTREE_FLAG_GREYED_OUT, state); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node represents a folder.
	/// @return `true` if `ITEMTREE_FLAG_FOLDER` is set; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsFolder() const { return GetFlag(ITEMTREE_NODEDATA_FLAG_FOLDER); }

	//----------------------------------------------------------------------------------------
	/// @brief Sets or clears an arbitrary item-tree flag.
	/// @param[in] flag Flag to change.
	/// @param[in] state `true` to set the flag; `false` to clear it.
	//----------------------------------------------------------------------------------------
	inline void SetFlag(const UInt32 flag, const Bool state)
	{
		if (state)
			m_Flags |= flag;
		else
			m_Flags &= ~flag;
	}

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether an arbitrary item-tree flag is set.
	/// @param[in] flag Flag to query.
	/// @return `true` if the flag is set; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool GetFlag(const UInt32 flag) const { return (m_Flags & flag) != 0; }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is selected and visible.
	/// @return `true` if the node is selected and not hidden; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsSelectedAndVisible() const { return IsSelected() && !IsHidden(); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is marked and visible.
	/// @return `true` if the node is marked and not hidden; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsMarkedAndVisible() const { return IsMarked() && !IsHidden(); }

	//----------------------------------------------------------------------------------------
	/// @brief Reports whether the node is highlighted and visible.
	/// @return `true` if the node is selected or marked and not hidden; otherwise `false`.
	//----------------------------------------------------------------------------------------
	inline Bool IsHighlightAndVisible() const { return (IsSelected() || IsMarked()) && !IsHidden(); }

	UInt64 m_GUID = 0; ///< Stable identifier of the node.
	Int32 m_ID = 0; ///< Application-defined identifier of the node.
	UInt32 m_Flags = 0; ///< Combination of `ITEMTREE_FLAG_*` values describing the node state.
	String m_Text; ///< Display text of the node.
	GeData m_Data; ///< Application-defined custom data associated with the node.
	BaseLink* m_pLink = nullptr; ///< Optional link to the represented object.
};

//----------------------------------------------------------------------------------------
/// @brief Carries the state and text used to draw one item-tree cell.
/// @details The item-tree implementation supplies this structure through
/// `ItemTreeCallbackData::typedata` for `ITEMTREE_CALLBACK_DRAWCELL` callbacks.
//----------------------------------------------------------------------------------------
class ItemTreeDrawCellData
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Initializes empty cell-drawing data.
	//----------------------------------------------------------------------------------------
	ItemTreeDrawCellData() { }

	DrawInfo* drawinfo = nullptr; ///< Drawing context for the cell.
	String txt; ///< Cell text to draw or modify.
	BaseList2D* bl = nullptr; ///< Object owning the item-tree data.
	Int32 flags = 0; ///< Cell drawing flags.
};

//----------------------------------------------------------------------------------------
/// @brief Carries the context and result of an item-tree callback.
/// @details The item-tree GUI fills this structure before sending `MSG_ITEMTREE_CALLBACK` to the
/// tree owner. The meaning of `data`, `typedata`, and `ret` depends on `type`.
//----------------------------------------------------------------------------------------
class ItemTreeCallbackData
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Prevents construction of callback data with the internal constructor marker.
	/// @param[in] v Internal construction marker.
	//----------------------------------------------------------------------------------------
	explicit ItemTreeCallbackData(_DONTCONSTRUCT v) { }

	//----------------------------------------------------------------------------------------
	/// @brief Initializes empty callback data.
	//----------------------------------------------------------------------------------------
	ItemTreeCallbackData() { }

	ItemTreeNode* node = nullptr; ///< Node involved in the callback.
	ItemTreeData* item = nullptr; ///< Item-tree data associated with the callback.
	ItemTreeNodeData* nodedata = nullptr; ///< Payload of `node`.
	BaseDocument* doc = nullptr; ///< Document in which the callback is handled.
	Int32 id = NOTOK; ///< Callback-specific ID, such as a column or menu ID.
	Int32 type = 0; ///< `ITEMTREE_CALLBACK_*` value describing the callback.
	BaseContainer* data = nullptr; ///< Callback-specific input data.
	Int32 ret = 0; ///< Callback result interpreted by the item-tree implementation.
	Int32 flags = 0; ///< Callback-specific flags.
	GeUserArea* garea = nullptr; ///< User area associated with the callback.
	iBaseCustomGui* gui = nullptr; ///< Custom GUI receiving or sending the callback.
	void* typedata = nullptr; ///< Pointer to callback-specific typed data.
	TreeViewCustomGui* tree = nullptr; ///< Tree-view GUI associated with the callback.
};

//----------------------------------------------------------------------------------------
/// @brief Owns the node array generated for an item-tree drag operation.
/// @details The item-tree implementation creates this structure while preparing drag data and
/// releases it after the operation. The destructor owns cleanup of the node array.
//----------------------------------------------------------------------------------------
class ItemTreeNodeDragData
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Initializes empty drag data.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeDragData() { }

	//----------------------------------------------------------------------------------------
	/// @brief Releases the allocated node array.
	//----------------------------------------------------------------------------------------
	~ItemTreeNodeDragData()
	{
		DeleteMem(m_pNodes);
	}

	ItemTreeNode** m_pNodes = nullptr; ///< Selected nodes included in the drag.
	Int32 m_Count = 0; ///< Number of entries in `m_pNodes`.
};

//----------------------------------------------------------------------------------------
/// @brief Stores temporary state for an item-tree popup editor.
/// @details The item-tree implementation fills this structure before opening a popup and uses the
/// stored GUI, screen position, dimensions, column, and node GUID to associate the popup with its
/// corresponding item-tree node.
//----------------------------------------------------------------------------------------
class ItemTreePopupData
{
public:
	//----------------------------------------------------------------------------------------
	/// @brief Initializes empty popup-edit data.
	//----------------------------------------------------------------------------------------
	ItemTreePopupData() { }

	//----------------------------------------------------------------------------------------
	/// @brief Releases popup-edit data without owning the referenced GUI.
	//----------------------------------------------------------------------------------------
	~ItemTreePopupData() { }

	//----------------------------------------------------------------------------------------
	/// @brief Allocates popup data with the MAXON object allocator.
	//----------------------------------------------------------------------------------------
	static ItemTreePopupData* Alloc()
	{
		iferr (ItemTreePopupData* data = NewObj(ItemTreePopupData))
		{
			return nullptr;
		}

		return data;
	}

	//----------------------------------------------------------------------------------------
	/// @brief Deletes popup data allocated with `Alloc()` and clears the pointer.
	//----------------------------------------------------------------------------------------
	static void Free(ItemTreePopupData*& p)
	{
		if (!p)
			return;

		DeleteObj(p);
	}

	iBaseCustomGui* dlg = nullptr; ///< GUI that owns the item tree associated with the popup.
	Int32 col = NOTOK; ///< Column containing the node associated with the popup.
	Int32 xpos = NOTOK, ypos = NOTOK, height = NOTOK; ///< Screen position and height of the popup editor.
	UInt64 guid = LIMIT<UInt64>::MAX; ///< GUID of the node associated with the popup.
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct ItemTreeNodeDataLib : public C4DLibrary
{
	void (*Construct)(ItemTreeNodeData* data);
	void (*Destruct)(ItemTreeNodeData* data);
	void (*CopyConstruct)(ItemTreeNodeData* data, const ItemTreeNodeData* src);
	const ItemTreeNodeData& (*Assign)(ItemTreeNodeData* data, const ItemTreeNodeData* src);
	Bool (*NotEqual)(const ItemTreeNodeData* data, const ItemTreeNodeData* rhs);
	Bool (*CopyFrom)(ItemTreeNodeData* data, const ItemTreeNodeData* src, AliasTrans* trn);
	Bool (*Init)(ItemTreeNodeData* data);
	Bool (*Write)(const ItemTreeNodeData* data, HyperFile* hf);
	Bool (*Read)(ItemTreeNodeData* data, HyperFile* hf);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_ITEMTREE_UTILS_H__
