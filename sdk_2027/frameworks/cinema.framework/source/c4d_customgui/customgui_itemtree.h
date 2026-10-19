/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_ITEMTREE_H__
#define CUSTOMGUI_ITEMTREE_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "maxon/valuereceiver.h"

namespace cinema
{

class ItemTreeNodeIndex;
class ItemTreeNode;
class ItemTreeNodeData;
class ItemTreeData;

#define CUSTOMDATA_ITEMTREE			1024869 ///< @brief Identifies the item tree custom data type.
#define CUSTOMGUI_ITEMTREE			1024868 ///< @brief Identifies the item tree custom GUI.

#define MSG_ITEMTREE_CALLBACK		1024875 ///< @brief Identifies an item tree callback message.

#define ITEMTREE_ID_LIST_FLAG									2000 ///< @brief Identifies the item tree list setting.
#define ITEMTREE_ID_DRAG_FLAG									2001 ///< @brief Identifies the item tree drag setting.
#define ITEMTREE_ID_HEADERS_FLAG							2002 ///< @brief Identifies the item tree header setting.
#define ITEMTREE_ID_ROWS											2003 ///< @brief Identifies the item tree row-count setting.
#define ITEMTREE_ID_CHECKBOX_FLAG							2004 ///< @brief Identifies the item tree checkbox setting.
#define ITEMTREE_ID_FOLDERS_FLAG							2005 ///< @brief Identifies the item tree folder setting.
#define ITEMTREE_ID_PADLOCK_FLAG							2006 ///< @brief Identifies the item tree padlock setting.
#define ITEMTREE_ID_COLOR_FLAG								2007 ///< @brief Identifies the item tree color setting.
#define ITEMTREE_ID_ICON_FLAG									2008 ///< @brief Identifies the item tree icon setting.
#define ITEMTREE_ID_MULTIPLE_FLAG							2009 ///< @brief Identifies the item tree multiple-selection setting.
#define ITEMTREE_ID_NO_RENAME									2010 ///< @brief Identifies the item tree no-rename setting.
#define ITEMTREE_ID_NO_MENU										2011 ///< @brief Identifies the item tree no-menu setting.
#define ITEMTREE_ID_NO_LAYOUTMODE							2012 ///< @brief Deprecated item tree layout-mode setting. @markDeprecated
#define ITEMTREE_ID_ROWS_MAX									2013 ///< @brief Identifies the maximum item tree row count.
#define ITEMTREE_ID_FOLD_FOLDERS_CMD_FLAG			2014 ///< @brief Identifies the command for folding all folders.
#define ITEMTREE_ID_HIDE_FOLDERS_CMD_FLAG			2015 ///< @brief Identifies the command for hiding all folders.
#define ITEMTREE_ID_SHOW_BL_DEBUG_NAME				2016 ///< @brief Identifies the linked-object debug-name setting.
#define ITEMTREE_ID_RESIZABLE									2017 ///< @brief Deprecated item tree resizable setting. @markDeprecated
#define ITEMTREE_ID_INCREMENT_FOLDER_NAME			2018 ///< @brief Identifies the incremental-folder-name setting.
#define ITEMTREE_ID_ALTERNATE_BG							2019 ///< @brief Identifies the alternate-background setting.
#define ITEMTREE_ID_EMPTY_TEXT								2020 ///< @brief Identifies the empty-tree text setting.
#define ITEMTREE_ID_NO_SELECT_IN_OM_FLAG			2021 ///< @brief Identifies the no-Object-Manager-selection setting.
#define ITEMTREE_ID_NO_COPYPASTEREPLACE_FLAG	2022 ///< @brief Identifies the no-copy, paste, and replace setting.
#define ITEMTREE_ID_HIDE_HIERARCHY_LINES			2023 ///< @brief Identifies the item-tree setting that hides hierarchy lines while retaining indentation and fold controls.
#define ITEMTREE_ID_NO_LEAF_INDENT						2024 ///< @brief Identifies the item-tree setting that suppresses indentation for leaf nodes.
#define ITEMTREE_ID_HEADER_BAND								2025 ///< @brief Identifies the item-tree setting that draws the header as one full-width band with bold column titles.

#define ITEMTREE_ID_HEADERS_DATA			5000 ///< @brief Identifies the item tree header-data array.
#define ITEMTREE_ID_HEADERS_IDS				5001 ///< @brief Identifies the item tree header-ID array.
#define ITEMTREE_USER_COL_TYPES				5002 ///< @brief Identifies the user-column type container.
#define ITEMTREE_USER_COL_ACTIVE			5003 ///< @brief Identifies the active user-defined column.
#define ITEMTREE_CHECKBOX_FRONT				5004 ///< @brief Identifies the column displayed in front of the checkbox.
#define ITEMTREE_USER_COL_MIN					5005 ///< @brief Sets the minimum value for an LV_EDITNUMBER or LV_SLIDER column.
#define ITEMTREE_USER_COL_MAX					5006 ///< @brief Sets the maximum value for an LV_EDITNUMBER or LV_SLIDER column.
#define ITEMTREE_USER_COL_INCREMENT		5007 ///< @brief Sets the step used by an LV_EDITNUMBER column.
#define ITEMTREE_USER_COL_SHOWASINT		5008 ///< @brief Displays an LV_EDITNUMBER value as an integer.
#define ITEMTREE_USER_COL_FORMAT			5009 ///< @brief Sets number formats for numeric columns such as `LV_EDITNUMBER` or `LV_SLIDER`; stores a `BaseContainer` mapping `column id -> Int32 format`, where `format` is one of the `FORMAT_*` constants defined in `c4d_general.h`.

#define ITEMTREE_HEADER_DATA_ID				1000 ///< @brief Identifies the item tree header-data entry.
#define ITEMTREE_HEADER_DATA_STRINGS	5000 ///< @brief Identifies the item tree header-strings entry.

#define ITEMTREE_ID_MOBILE_SUBTITLE_COLUMNS			3000 ///< @brief Identifies the mobile subtitle columns.
#define ITEMTREE_ID_MOBILE_ACCESSORIES_BOTTOM		3001 ///< @brief Identifies the mobile bottom accessories by column ID.
#define ITEMTREE_ID_MOBILE_ACCESSORIES_TRAILING	3002 ///< @brief Identifies the mobile trailing accessories by column ID.

#define ITEMTREE_OBJECT_COL						10000 ///< @brief Identifies the built-in object column.
#define ITEMTREE_ENABLE_COL						10001 ///< @brief Identifies the built-in enable column.
#define ITEMTREE_LOCK_COL							10002 ///< @brief Identifies the built-in lock column.
#define ITEMTREE_COLOR_COL						10003 ///< @brief Identifies the built-in color column.

#define ITEMTREE_USER_COL							50000 ///< @brief Identifies the range reserved for user-defined columns.

#define ITEMTREE_FLAG_NONE								(0) 		 ///< @brief No flags set.
#define ITEMTREE_FLAG_INSERT_BEFORE				(1 << 0) ///< @brief Allows insertion before the current node.
#define ITEMTREE_FLAG_INSERT_AFTER				(1 << 1) ///< @brief Allows insertion after the current node.
#define ITEMTREE_FLAG_INSERT_UNDER				(1 << 2) ///< @brief Allows insertion below the current node.
#define ITEMTREE_FLAG_OPEN								(1 << 3) ///< @brief Opens the node or folder.
#define ITEMTREE_FLAG_SELECT							(1 << 4) ///< @brief Marks the node as selected.
#define ITEMTREE_FLAG_ENABLE							(1 << 5) ///< @brief Enables the node.
#define ITEMTREE_FLAG_NOLINK							(1 << 6) ///< @brief Indicates that the node does not use a linked object.
#define ITEMTREE_FLAG_NODRAG							(1 << 7) ///< @brief Prevents dragging the node.
#define ITEMTREE_FLAG_BL_NAME						  (1 << 8) ///< @brief Uses the linked object's name for the node label when available.
#define ITEMTREE_FLAG_NO_RENAME					  (1 << 9) ///< @brief Prevents renaming the node.
#define ITEMTREE_FLAG_LOCK							  (1 << 10) ///< @brief Locks the node.
#define ITEMTREE_FLAG_DIRTY							  (1 << 11) ///< @brief Marks the node as dirty.
#define ITEMTREE_FLAG_FOLDER						  (1 << 12) ///< @brief Marks the node as a folder.
#define ITEMTREE_FLAG_NO_LOCK						  (1 << 13) ///< @brief Prevents locking the node.
#define ITEMTREE_FLAG_NO_ENABLE						(1 << 14) ///< @brief Prevents enabling or disabling the node.
#define ITEMTREE_FLAG_NO_COLOR						(1 << 15) ///< @brief Prevents changing the node color.
#define ITEMTREE_FLAG_NULLLINK						(1 << 16) ///< @brief Allows a null linked object.
#define ITEMTREE_FLAG_MARK							  (1 << 17) ///< @brief Marks the node with the secondary mark state.
#define ITEMTREE_FLAG_NOREMOVE						(1 << 18) ///< @brief Prevents removing the node.
#define ITEMTREE_FLAG_FORCELINK						(1 << 19) ///< @brief Forces retrieval of the linked object when normal link lookup fails.
#define ITEMTREE_FLAG_HIDDEN							(1 << 20) ///< @brief Hides the node.
#define ITEMTREE_FLAG_INCREMENT_NAME			(1 << 21) ///< @brief Generates an incremented name for the node.
#define ITEMTREE_FLAG_GREYED_OUT					(1 << 22) ///< @brief Displays the node in a greyed-out state.
#define ITEMTREE_FLAG_ISGENERATORCHILD		(1 << 23) ///< @brief Marks a generator child node.
#define ITEMTREE_FLAG_ISINTERNALFILTER		(1 << 24) ///< @brief Marks a node used by an internal filter.
#define ITEMTREE_FLAG_SIMPLELIST					(ITEMTREE_FLAG_NOLINK | ITEMTREE_FLAG_NODRAG | ITEMTREE_FLAG_OPEN) ///< @brief Combines the flags for a simple list.

#define ITEMTREE_CALLBACK_DRAGACCEPT						 1 ///< @brief Handles drag acceptance for the item tree.
#define ITEMTREE_CALLBACK_INSERT								 2 ///< @brief Handles insertion into the item tree.
#define ITEMTREE_CALLBACK_OPEN									 3 ///< @brief Handles opening an item tree node.
#define ITEMTREE_CALLBACK_CREATEMENU						 4 ///< @brief Creates the item tree context menu.
#define ITEMTREE_CALLBACK_CALLMENU							 5 ///< @brief Handles an item tree menu command.
#define ITEMTREE_CALLBACK_DELETE								 6 ///< @brief Handles deletion from the item tree.
#define ITEMTREE_CALLBACK_SELECTIONCHG					 7 ///< @brief Handles an item tree selection change.
#define ITEMTREE_CALLBACK_DBLCLICK							 8 ///< @brief Handles a double-click on an item tree node.
#define ITEMTREE_CALLBACK_INSERTNODE						 9 ///< @brief Handles insertion of an existing item tree node.
#define ITEMTREE_CALLBACK_GETCOLWIDTH					 	10 ///< @brief Queries an item tree column width.
#define ITEMTREE_CALLBACK_GETLINEHEIGHT				 	11 ///< @brief Queries the item tree line height.
#define ITEMTREE_CALLBACK_DRAWCELL							12 ///< @brief Draws an item tree cell.
#define ITEMTREE_CALLBACK_CHECKBOX							13 ///< @brief Handles an item tree checkbox action.
#define ITEMTREE_CALLBACK_GETDRAGTYPE					 	14 ///< @brief Queries the drag type for an item tree node.
#define ITEMTREE_CALLBACK_CALLMENU_PASTE				15 ///< @brief Handles an item tree paste menu command.
#define ITEMTREE_CALLBACK_MOVENODE							16 ///< @brief Handles moving an item tree node.
#define ITEMTREE_CALLBACK_RENAME								17 ///< @brief Handles renaming an item tree node.
#define ITEMTREE_CALLBACK_LOCK									18 ///< @brief Handles locking an item tree node.
#define ITEMTREE_CALLBACK_DELETE_NODE					 	19 ///< @brief Handles deletion of an item tree node.
#define ITEMTREE_CALLBACK_DELETE_END						20 ///< @brief Signals the end of item tree deletion.
#define ITEMTREE_CALLBACK_MOUSEDOWN						 	21 ///< @brief Handles an item tree mouse-down event.
#define ITEMTREE_CALLBACK_PAINT_FINISHED				22 ///< @brief Signals that item tree painting finished.
#define ITEMTREE_CALLBACK_CALLPOSTMENU					23 ///< @brief Handles an item tree post-menu command.
#define ITEMTREE_CALLBACK_HEADERCLICK					 	24 ///< @brief Handles a click on an item tree header.
#define ITEMTREE_CALLBACK_GETDROPDOWNMENU			 	25 ///< @brief Queries an item tree drop-down menu.
#define ITEMTREE_CALLBACK_SETDROPDOWNMENU			 	26 ///< @brief Sets an item tree drop-down menu.
#define ITEMTREE_SELECTIONCHG_SELECTIONID			 	27 ///< @brief Identifies the selection-change item ID.
#define ITEMTREE_SELECTIONCHG_FOCUSID					 	28 ///< @brief Identifies the selection-change focus ID.
#define ITEMTREE_CALLBACK_GETHEADERCOLUMNWIDTH	29 ///< @brief Queries an item tree header-column width.
#define ITEMTREE_CALLBACK_GET_EMPTY_TEXT				30 ///< @brief Queries the item tree empty text.
#define ITEMTREE_CALLBACK_RESET									31 ///< @brief Resets the item tree custom GUI.
#define ITEMTREE_CALLBACK_DRAWHEADERCELL				32 ///< @brief Draws an item tree header cell.
#define ITEMTREE_CALLBACK_GETMINHEADERHEIGHT		33 ///< @brief Queries the minimum item-tree header height; set @c ItemTreeCallbackData::ret to the height in pixels.
#define ITEMTREE_CALLBACK_GETCELLTYPE 					34 ///< @brief Queries the cell type for a user-defined column; set @c ItemTreeCallbackData::ret to override the declared layout type.
#define ITEMTREE_CALLBACK_VALUECHANGED					35 ///< @brief Handles a changed value in a user-defined column; set @c ItemTreeCallbackData::ret to 1 if the change was handled.

#define ITEMTREE_DRAG_TYPE										1000 ///< @brief Identifies the item tree drag type.
#define ITEMTREE_DRAG_OBJECT									1001 ///< @brief Identifies an item tree drag object.
#define ITEMTREE_DRAG_NODE										1002 ///< @brief Identifies an item tree drag node.
#define ITEMTREE_DRAG_MASK										1003 ///< @brief Identifies the item tree drag mask.
#define ITEMTREE_INSERT_INSERTLAST 						1004 ///< @brief Identifies insertion at the end of a sibling list.
#define ITEMTREE_VALUECHANGED_VALUE						1007 ///< @brief Contains the changed custom-column value.
#define ITEMTREE_VALUECHANGED_FINAL						1008 ///< @brief Indicates that the custom-column value change is final.

#define ITEMTREE_SETDROPDOWNMENU_COLUMN 			1005 ///< @brief Identifies the drop-down menu column setting.
#define ITEMTREE_SETDROPDOWNMENU_ENTRY 				1006 ///< @brief Identifies a drop-down menu entry setting.

#define ITEMTREE_MENU_COPY						cinema::ID_TREEVIEW_FIRST_NEW_ID ///< @brief Copies the selected item tree nodes.
#define ITEMTREE_MENU_PASTE						(cinema::ID_TREEVIEW_FIRST_NEW_ID+1) ///< @brief Pastes item tree nodes.
#define ITEMTREE_MENU_SELECT					(cinema::ID_TREEVIEW_FIRST_NEW_ID+2) ///< @brief Selects an item tree node.
#define ITEMTREE_MENU_LOCK						(cinema::ID_TREEVIEW_FIRST_NEW_ID+3) ///< @brief Locks an item tree node.
#define ITEMTREE_MENU_LOCK_ALL				(cinema::ID_TREEVIEW_FIRST_NEW_ID+4) ///< @brief Locks all item tree nodes.
#define ITEMTREE_MENU_UNLOCK					(cinema::ID_TREEVIEW_FIRST_NEW_ID+5) ///< @brief Unlocks an item tree node.
#define ITEMTREE_MENU_UNLOCK_ALL			(cinema::ID_TREEVIEW_FIRST_NEW_ID+6) ///< @brief Unlocks all item tree nodes.
#define ITEMTREE_MENU_NEW_FOLDER			(cinema::ID_TREEVIEW_FIRST_NEW_ID+7) ///< @brief Creates an item tree folder.
#define ITEMTREE_MENU_REPLACE					(cinema::ID_TREEVIEW_FIRST_NEW_ID+8) ///< @brief Replaces item tree content.
#define ITEMTREE_MENU_ENABLE					(cinema::ID_TREEVIEW_FIRST_NEW_ID+9) ///< @brief Enables an item tree node.
#define ITEMTREE_MENU_ENABLE_ALL			(cinema::ID_TREEVIEW_FIRST_NEW_ID+10) ///< @brief Enables all item tree nodes.
#define ITEMTREE_MENU_DISABLE_ALL			(cinema::ID_TREEVIEW_FIRST_NEW_ID+11) ///< @brief Disables all item tree nodes.
#define ITEMTREE_MENU_DISABLE					(cinema::ID_TREEVIEW_FIRST_NEW_ID+12) ///< @brief Disables an item tree node.
#define ITEMTREE_MENU_SELECT_ALL			(cinema::ID_TREEVIEW_FIRST_NEW_ID+13) ///< @brief Selects all item tree nodes.
#define ITEMTREE_MENU_DESELECT_ALL		(cinema::ID_TREEVIEW_FIRST_NEW_ID+14) ///< @brief Deselects all item tree nodes.
#define ITEMTREE_MENU_FOLD						(cinema::ID_TREEVIEW_FIRST_NEW_ID+15) ///< @brief Folds an item tree node.
#define ITEMTREE_MENU_UNFOLD					(cinema::ID_TREEVIEW_FIRST_NEW_ID+16) ///< @brief Unfolds an item tree node.
#define ITEMTREE_MENU_HIDE						(cinema::ID_TREEVIEW_FIRST_NEW_ID+17) ///< @brief Hides an item tree node.
#define ITEMTREE_MENU_UNHIDE					(cinema::ID_TREEVIEW_FIRST_NEW_ID+18) ///< @brief Shows an item tree node.
#define ITEMTREE_MENU_UNHIDE_ALL			(cinema::ID_TREEVIEW_FIRST_NEW_ID+19) ///< @brief Shows all item tree nodes.
#define ITEMTREE_MENU_HIDE_UNSELECTED (cinema::ID_TREEVIEW_FIRST_NEW_ID + 20) ///< @brief Hides unselected item tree nodes.

#define ITEMTREE_MENU_CUSTOM (cinema::ID_TREEVIEW_FIRST_NEW_ID + 1000) ///< @brief Identifies the base ID for custom item tree menu commands.

//----------------------------------------------------------------------------------------
/// @brief Stores and manages the hierarchical data displayed by an item tree custom GUI.
/// @details Maintains item nodes, their hierarchy, associated object links, selection state, and
/// application-defined data. The tree uses an internal sentinel root; regular items begin at
/// @note In a description, configure the custom GUI through the resource and dynamic description
/// data in `NodeData::GetDDescription()`. In a dialog, create the custom GUI settings container
/// directly in `GeDialog::CreateLayout()` and handle its `BFM_ACTION` messages in the dialog.
/// @see The `objectdata_objecttree` example in the SDK demonstrates how to use the item tree custom GUI.
//----------------------------------------------------------------------------------------
class ItemTreeData : public CustomDataTypeT<CUSTOMDATA_ITEMTREE>
{
private:
	ItemTreeData();
	~ItemTreeData();
public:
	//----------------------------------------------------------------------------------------
	/// @brief Allocates an empty item tree data container.
	/// @return The allocated tree, or `nullptr` if allocation or initialization fails.
	//----------------------------------------------------------------------------------------
	static ItemTreeData *Alloc();

	//----------------------------------------------------------------------------------------
	/// @brief Releases an item tree data container and clears the caller's pointer.
	/// @param[in,out] data The tree to release.
	//----------------------------------------------------------------------------------------
	static void Free(ItemTreeData *&data);

	//----------------------------------------------------------------------------------------
	/// @brief Adds a top-level item to the tree.
	/// @details Inserts the item below the internal root and initializes its identifier, name, link, data, and flags.
	/// Set `aslast` to `false` to insert it before the existing top-level items.
	/// @param[in] id The application-defined item identifier.
	/// @param[in] name The item name.
	/// @param[in] bl The object linked to the item, or `nullptr`.
	/// @param[in] data The application-defined data stored by the item.
	/// @param[in] flags The item flags.
	/// @param[in] aslast Places the item last when `true`; otherwise places it first.
	/// @return The new item, or `nullptr` if it cannot be allocated or initialized.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* AddItem(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, Bool aslast = true);

	//----------------------------------------------------------------------------------------
	/// @brief Adds an item at a specified position in the hierarchy.
	/// @details Inserts the item below `parent` or at the top level when `parent` is `nullptr`. When `prev` is
	/// provided, the item is inserted after that sibling; otherwise `aslast` controls its position among siblings.
	/// @param[in] id The application-defined item identifier.
	/// @param[in] name The item name.
	/// @param[in] bl The object linked to the item, or `nullptr`.
	/// @param[in] data The application-defined data stored by the item.
	/// @param[in] flags The item flags.
	/// @param[in] parent The parent item, or `nullptr` for the top level.
	/// @param[in] prev The previous sibling, or `nullptr`.
	/// @param[in] aslast Places the item last among siblings when `true`.
	/// @return The new item, or `nullptr` if it cannot be allocated or initialized.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* AddNode(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast = true);

	//----------------------------------------------------------------------------------------
	/// @brief Adds an object and all its descendants to the tree.
	/// @details The object and every descendant are added as linked tree nodes in depth-first order. The receiver is
	/// called immediately after each node is added and can initialize its data or register notifications.
	/// Returning `false` from the receiver skips traversal of that node's descendants while continuing
	/// with its siblings.
	/// @param[in] node The root object to add together with its descendants.
	/// @param[in] parent The tree parent for the added hierarchy, or nullptr for the tree root.
	/// @param[in] receiver Receives every added node in depth-first order. Return `true` to visit descendants.
	/// @param[in] flags The flags assigned to each added node.
	/// @return `true` on success, or `false` if a node cannot be added or the receiver reports an error.
	//----------------------------------------------------------------------------------------
	Bool AddHierarchy(BaseList2D* node, ItemTreeNode* parent, const maxon::ValueReceiver<ItemTreeNode*>& receiver, UInt32 flags = ITEMTREE_FLAG_NONE);

	//----------------------------------------------------------------------------------------
	/// @brief Returns mutable data stored in a node.
	/// @param[in] node The node whose data to return.
	/// @return The node data, or `nullptr` when `node` is `nullptr`.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeData* GetNodeData(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns read-only data stored in a node.
	/// @param[in] node The node whose data to return.
	/// @return The node data, or `nullptr` when `node` is `nullptr`.
	//----------------------------------------------------------------------------------------
	const ItemTreeNodeData* GetNodeData(const ItemTreeNode* node) const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the next node in depth-first tree order.
	/// @details Starts with the child or following sibling of `node` and walks up through parents as needed.
	/// Traversal stops when it reaches `topnode`; pass `nullptr` to traverse the complete tree.
	/// @param[in] node The current node.
	/// @param[in] topnode The traversal boundary, or `nullptr`.
	/// @return The next node, or `nullptr` when the traversal is complete.
	//----------------------------------------------------------------------------------------
	ItemTreeNode *GetiNext(ItemTreeNode *node, ItemTreeNode *topnode = nullptr);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the next node in depth-first tree order without modifying the tree.
	/// @details Starts with the child or following sibling of `node` and stops at `topnode`; pass `nullptr` to
	/// traverse the complete tree.
	/// @param[in] node The current node.
	/// @param[in] topnode The traversal boundary, or `nullptr`.
	/// @return The next node, or `nullptr` when the traversal is complete.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* GetiNext(const ItemTreeNode* node, const ItemTreeNode* topnode = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the next sibling of a node.
	/// @param[in] node The node whose sibling to return.
	/// @return The next sibling, or `nullptr` when `node` is `nullptr` or has no next sibling.
	//----------------------------------------------------------------------------------------
	ItemTreeNode *GetNext(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the next sibling of a node without modifying the tree.
	/// @param[in] node The node whose sibling to return.
	/// @return The next sibling, or `nullptr` when `node` is `nullptr` or has no next sibling.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode*	GetNext(const ItemTreeNode* node) const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the previous sibling of a node.
	/// @param[in] node The node whose sibling to return.
	/// @return The previous sibling, or `nullptr` when `node` is `nullptr` or has no previous sibling.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetPrev(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the parent of a node.
	/// @param[in] node The node whose parent to return.
	/// @return The parent node, or `nullptr` when `node` is `nullptr` or has no parent.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetUp(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the parent of a node without modifying the tree.
	/// @param[in] node The node whose parent to return.
	/// @return The parent node, or `nullptr` when `node` is `nullptr` or has no parent.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode*	GetUp(const ItemTreeNode* node) const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first child of a node.
	/// @param[in] node The node whose child to return.
	/// @return The first child, or `nullptr` when `node` is `nullptr` or has no children.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetDown(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first child of a node without modifying the tree.
	/// @param[in] node The node whose child to return.
	/// @return The first child, or `nullptr` when `node` is `nullptr` or has no children.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* GetDown(const ItemTreeNode* node) const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the internal sentinel root node.
	/// @details The root does not contain regular item data. Use @ref cinema::ItemTreeData::GetFirst "GetFirst" to access the first top-level item.
	/// @return The internal root node.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetRoot();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first top-level item.
	/// @return The first item, or `nullptr` when the tree is empty.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetFirst();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first top-level item without modifying the tree.
	/// @return The first item, or `nullptr` when the tree is empty.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* GetFirst() const;

	//----------------------------------------------------------------------------------------
	/// @brief Detaches a node and its descendants from the tree without releasing them.
	/// @param[in] node The node to detach.
	//----------------------------------------------------------------------------------------
	void Remove(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Releases a node and its descendants, then clears the caller's pointer.
	/// @param[in,out] node The node to release.
	//----------------------------------------------------------------------------------------
	void FreeNode(ItemTreeNode *&node);

	//----------------------------------------------------------------------------------------
	/// @brief Inserts an existing node at a specified position in the tree.
	/// @param[in] node The detached node to insert.
	/// @param[in] parent The parent item, or `nullptr` for the top level.
	/// @param[in] prev The previous sibling, or `nullptr`.
	/// @param[in] aslast Places the node last among siblings when `true`.
	//----------------------------------------------------------------------------------------
	void Insert(ItemTreeNode *node, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast = true);

	//----------------------------------------------------------------------------------------
	/// @brief Associates an owning object with the tree.
	/// @details Stores a link to `bl` and tracks whether the link must be resolved through a document.
	/// @param[in] bl The owning object, or `nullptr` to clear the owner.
	//----------------------------------------------------------------------------------------
	void SetOwner(BaseList2D *bl);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the user data container associated with the tree.
	/// @return The mutable user data container.
	//----------------------------------------------------------------------------------------
	BaseContainer *GetUserData();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the selected nodes in a newly allocated array.
	/// @details Pass `nullptr` for `table` to retrieve only the count. When an array is returned, the caller owns
	/// its memory and must release it with @ref cinema::DeleteMem "DeleteMem". Set `children` to `false` to stop descending below selected nodes.
	/// @param[out] table Receives the allocated node array, or `nullptr`.
	/// @param[in] children Includes descendants when `true`.
	/// @return The number of selected nodes, or `NOTOK` if array allocation fails.
	//----------------------------------------------------------------------------------------
	Int32 GetSelected(ItemTreeNode ***table, Bool children = true);

	//----------------------------------------------------------------------------------------
	/// @brief Finds a node by its GUID.
	/// @details Searches the complete tree when `node` is `nullptr`; otherwise searches the subtree rooted at `node`.
	/// @param[in] guid The node GUID.
	/// @param[in] node The subtree root, or `nullptr` for the complete tree.
	/// @return The matching node, or `nullptr` when no node matches.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* Find(UInt64 guid, ItemTreeNode *node = nullptr);

	//----------------------------------------------------------------------------------------
	/// @brief Finds a node by its item identifier and optionally its GUID.
	/// @details A `guid` of `CRC64_NEGL` matches any GUID. Set `child` to `false` to search only the specified
	/// level. When `node` is `nullptr`, the top level is searched.
	/// @param[in] guid The node GUID, or `CRC64_NEGL` to ignore the GUID.
	/// @param[in] id The application-defined item identifier.
	/// @param[in] child Searches descendants when `true`.
	/// @param[in] node The level to search, or `nullptr` for the top level.
	/// @return The matching node, or `nullptr` when no node matches.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* Find(UInt64 guid, Int32 id, Bool child = true, ItemTreeNode *node = nullptr);

	//----------------------------------------------------------------------------------------
	/// @brief Finds a node by its GUID without modifying the tree.
	/// @details Searches the complete tree when `node` is `nullptr`; otherwise searches the subtree rooted at `node`.
	/// @param[in] guid The node GUID.
	/// @param[in] node The subtree root, or `nullptr` for the complete tree.
	/// @return The matching node, or `nullptr` when no node matches.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* Find(UInt64 guid, const ItemTreeNode* node = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// @brief Finds a node by its item identifier and optionally its GUID without modifying the tree.
	/// @details A `guid` of `CRC64_NEGL` matches any GUID. Set `child` to `false` to search only the specified
	/// level. When `node` is `nullptr`, the top level is searched.
	/// @param[in] guid The node GUID, or `CRC64_NEGL` to ignore the GUID.
	/// @param[in] id The application-defined item identifier.
	/// @param[in] child Searches descendants when `true`.
	/// @param[in] node The level to search, or `nullptr` for the top level.
	/// @return The matching node, or `nullptr` when no node matches.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* Find(UInt64 guid, Int32 id, Bool child = true, const ItemTreeNode* node = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// @brief Clears the selection state of every node in the tree.
	//----------------------------------------------------------------------------------------
	void ClearSelection();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the GUID of the first selected node.
	/// @return The selected node GUID, or `CRC64_NEGL` when no node is selected.
	//----------------------------------------------------------------------------------------
	UInt64 GetSelectedID();

	//----------------------------------------------------------------------------------------
	/// @brief Selects a node by GUID and clears the previous selection.
	/// @param[in] guid The GUID of the node to select.
	//----------------------------------------------------------------------------------------
	void SetSelectedID(UInt64 guid);

	//----------------------------------------------------------------------------------------
	/// @brief Selects a node and clears the previous selection.
	/// @param[in] node The node to select, or `nullptr` to clear the selection.
	//----------------------------------------------------------------------------------------
	void SetSelected(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first selected node in depth-first order.
	/// @return The first selected node, or `nullptr` when no node is selected.
	//----------------------------------------------------------------------------------------
	ItemTreeNode* GetFirstSelected();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the first selected node in depth-first order without modifying the tree.
	/// @return The first selected node, or `nullptr` when no node is selected.
	//----------------------------------------------------------------------------------------
	const ItemTreeNode* GetFirstSelected() const;

	//----------------------------------------------------------------------------------------
	/// @brief Adds a node to the current selection without clearing other selected nodes.
	/// @param[in] node The node to select, or `nullptr`.
	//----------------------------------------------------------------------------------------
	void AddToSelected(ItemTreeNode *node);

	//----------------------------------------------------------------------------------------
	/// @brief Removes all nodes and resets the tree to its initial empty state.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// @brief Builds a flat table containing every node in depth-first order.
	/// @details The caller owns the returned array and must release it with @ref cinema::DeleteMem "DeleteMem". When `sorted` is `true`,
	/// the entries are sorted by GUID. The table becomes invalid when the tree is modified.
	/// @param[out] tcnt Receives the number of entries in the returned table.
	/// @param[in] sorted Sorts entries by GUID when `true`.
	/// @return The allocated index table, or `nullptr` when the tree is empty or allocation fails.
	//----------------------------------------------------------------------------------------
	ItemTreeNodeIndex* BuildIndexTable(Int32 &tcnt, Bool sorted);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the number of nodes in the global item-tree clipboard.
	/// @return The clipboard node count, or zero when no clipboard exists.
	//----------------------------------------------------------------------------------------
	Int32 GetClipCount();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the global item-tree clipboard array.
	/// @return The clipboard node array, or `nullptr` when no clipboard exists.
	//----------------------------------------------------------------------------------------
	ItemTreeNode** GetClipArray();

	//----------------------------------------------------------------------------------------
	/// @brief Returns all non-folder nodes in a newly allocated array.
	/// @details The result includes the internal sentinel root and all non-folder nodes. Pass `nullptr` for `table`
	/// to retrieve only the count. When an array is returned, the caller owns its memory and must release it with @ref cinema::DeleteMem "DeleteMem".
	/// @param[out] table Receives the allocated node array, or `nullptr`.
	/// @return The number of nodes, or `NOTOK` if array allocation fails.
	//----------------------------------------------------------------------------------------
	Int32 GetNodeTable(ItemTreeNode ***table);

	//----------------------------------------------------------------------------------------
	/// @brief Removes every selected node and its descendants from the tree.
	//----------------------------------------------------------------------------------------
	void RemoveSelected();

	//----------------------------------------------------------------------------------------
	/// @brief Calculates a CRC checksum for the complete tree content.
	/// @details Includes node identifiers, flags, names, stored data, and the memory markers of linked objects.
	/// @return The tree checksum.
	//----------------------------------------------------------------------------------------
	UInt64 GetChecksum() const;

	//----------------------------------------------------------------------------------------
	/// @brief Calculates a hash code for the complete tree content.
	/// @details Set `onlyGuid` to `true` to hash only node GUIDs; otherwise node identifiers, flags, names, stored
	/// data, and linked objects also contribute to the result.
	/// @param[in] onlyGuid Hashes only node GUIDs when `true`.
	/// @return The tree hash code.
	//----------------------------------------------------------------------------------------
	maxon::HashInt GetHashCode(Bool onlyGuid) const;

	//----------------------------------------------------------------------------------------
	/// @brief Sorts sibling nodes by the names of their linked objects.
	/// @details Recursively sorts every sibling level. Only nodes with a resolvable linked object participate in the
	/// comparison; nodes without one are excluded from sorting and retain their relative order.
	/// @param[in] doc The document used to resolve object links, or `nullptr` to use the active document.
	//----------------------------------------------------------------------------------------
	void SortNames(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// @brief Removes nodes whose linked objects can no longer be resolved.
	/// @details Only nodes with a link are checked. Nodes marked with `ITEMTREE_FLAG_NULLLINK` or `ITEMTREE_FLAG_NOLINK`
	/// are exempt from removal.
	/// @param[in] doc The document used to resolve object links.
	//----------------------------------------------------------------------------------------
	void Validate(BaseDocument *doc);

	//----------------------------------------------------------------------------------------
	/// @brief Copies the complete contents of another item tree.
	/// @details Replaces the current node hierarchy with a copy of `src`, including its node data and linked object data.
	/// The destination's user data and owner link are not changed.
	/// @param[in] src The source tree to copy.
	/// @return `true` on success; otherwise `false`.
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(ItemTreeData *src);

	//----------------------------------------------------------------------------------------
	/// @brief Builds an internal index for repeated item identifier and GUID lookups.
	/// @details Populates exact `(id, guid)` entries and wildcard-GUID entries used by @ref cinema::ItemTreeData::Find "Find". Call this before
	/// repeated lookups; tree changes require the index to be rebuilt or cleared.
	/// @return `OK` on success; otherwise an error result.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> PrepareIndex();

	//----------------------------------------------------------------------------------------
	/// @brief Clears the internal lookup index and disables indexed lookup.
	//----------------------------------------------------------------------------------------
	void ClearIndex();
};


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class CINEWARE_SINGLEINHERITANCE iItemTreeData;

struct CustomGuiItemTreeLib : public BaseCustomGuiLib
{
	ItemTreeData		*(*Alloc	)();
	void						(*Free		)(ItemTreeData *&pData);
	ItemTreeNode				*(iItemTreeData::*AddItem						)(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, Bool aslast);
	ItemTreeNode				*(iItemTreeData::*AddNode						)(Int32 id, const maxon::String &name, BaseList2D *bl, const GeData &data, UInt32 flags, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast);
	void								(iItemTreeData::*SetOwner						)(BaseList2D *bl);
	BaseContainer				*(iItemTreeData::*GetUserData				)();
	ItemTreeNodeData		*(iItemTreeData::*GetNodeData				)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetiNext					)(ItemTreeNode *node, ItemTreeNode *topnode);
	ItemTreeNode				*(iItemTreeData::*GetNext						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetPrev						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetUp							)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetDown						)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetRoot						)();
	ItemTreeNode				*(iItemTreeData::*GetFirst					)();
	void								(iItemTreeData::*Remove							)(ItemTreeNode *node);
	void								(iItemTreeData::*FreeNode						)(ItemTreeNode *&node);
	void								(iItemTreeData::*Insert							)(ItemTreeNode *node, ItemTreeNode *parent, ItemTreeNode *prev, Bool aslast);
	Int32								(iItemTreeData::*GetSelected				)(ItemTreeNode ***table, Bool children);
	ItemTreeNode				*(iItemTreeData::*Find							)(UInt64 guid, ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*FindID						)(UInt64 guid, Int32 id, Bool child, ItemTreeNode *node);
	void								(iItemTreeData::*ClearSelection			)();
	void								(iItemTreeData::*SetSelectedID			)(UInt64 guid);
	void								(iItemTreeData::*SetSelected				)(ItemTreeNode *node);
	ItemTreeNode				*(iItemTreeData::*GetFirstSelected	)();
	void								(iItemTreeData::*Reset							)();
	ItemTreeNodeIndex		*(iItemTreeData::*BuildIndexTable		)(Int32 &tcnt, Bool sorted);
	Int32								(iItemTreeData::*GetClipCount				)();
	ItemTreeNode				**(iItemTreeData::*GetClipArray			)();
	Int32								(iItemTreeData::*GetNodeTable				)(ItemTreeNode ***table);
	void								(iItemTreeData::*RemoveSelected			)();
	UInt64							(iItemTreeData::*GetChecksum				)() const;
	void								(iItemTreeData::*SortNames					)(BaseDocument *doc);
	UInt64							(iItemTreeData::*GetSelectedID			)();
	void								(iItemTreeData::*Validate						)(BaseDocument *doc);
	Bool								(iItemTreeData::*CopyFrom						)(ItemTreeData *src);
	
	Int32		(*itnodeGetID)(ItemTreeNode *iNode);
	Int32		(*itnodeGetFlags)(ItemTreeNode *iNode);

	void								(iItemTreeData::*AddToSelected			)(ItemTreeNode *node);
	maxon::HashInt			(iItemTreeData::*GetHashCode        )(Bool onlyGuid) const;
	maxon::Result<void>	(iItemTreeData::*PrepareIndex				)();
	void								(iItemTreeData::*ClearIndex					)();
	Bool 								 (iItemTreeData::*AddHierarchy			)(BaseList2D* node, ItemTreeNode* parent, const maxon::ValueReceiver<ItemTreeNode*>& receiver, UInt32 flags, Int32 startId);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // CUSTOMGUI_ITEMTREE_H__
