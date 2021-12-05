/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LISTVIEW_H__
#define CUSTOMGUI_LISTVIEW_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "customgui_base.h"

/// Tree/List view custom GUI ID.
#define CUSTOMGUI_TREEVIEW		1000475

/// @addtogroup TREEVIEW_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define TREEVIEW_BORDER							'brdr'			///< Border type.
#define TREEVIEW_OUTSIDE_DROP				'tvod'			///< @formatConstant{true} if an object may be dropped under all the objects in the tree view.
#define TREEVIEW_HIDE_LINES					'tvhl'			///< @formatConstant{true} if no lines should be drawn.
#define TREEVIEW_CTRL_DRAG					'ctdr'			///< @formatConstant{true} if item may be duplicated by Ctrl + Drag.
#define TREEVIEW_NO_MULTISELECT			'tvnm'			///< @formatConstant{true} if no multiple selection is allowed.
#define TREEVIEW_HAS_HEADER					'tvhh'			///< @formatConstant{true} if the tree view may have a header line.
#define TREEVIEW_RESIZE_HEADER			'tvrh'			///< @formatConstant{true} if the column width can be changed by the user.
#define TREEVIEW_MOVE_COLUMN				'tvmc'			///< @formatConstant{true} if the user can move the columns.
#define TREEVIEW_FIXED_LAYOUT				'tvfl'			///< @formatConstant{true} if all lines have the same height.
#define TREEVIEW_NOAUTOCOLUMNS			'noau'			///< @formatConstant{true} if only the first line is asked for the columns width, resulting in a huge speedup.
#define TREEVIEW_NO_OPEN_CTRLCLK		'tvcd'			///< @formatConstant{true} if it is not allowed to open the complete tree with Ctrl + Click.
#define TREEVIEW_ALT_DRAG						'tvad'			///< @formatConstant{true} if Alt should be used instead of Ctrl for drag and drop; implies item may be duplicated by Alt + Drag.
#define TREEVIEW_NO_BACK_DELETE			'tvnb'			///< Disable "delete pressed" messages if backspace was hit.
#define TREEVIEW_NO_DELETE					'tvnd'			///< Disable Delete Message Callback completely for backspace and delete
#define TREEVIEW_ALTERNATE_BG				'tvab'			///< Alternate background per line.
#define TREEVIEW_CURSORKEYS					'tvck'			///< @formatConstant{true} if cursor keys should be processed. @b Note: The focus item has to be set to @formatConstant{nullptr} if it is deleted and this flag is set.
#define TREEVIEW_NOENTERRENAME			'tver'			///< Suppresses the rename popup when the user presses enter.
#define TREEVIEW_NO_VERTICALSCROLL	'novs'			///< @formatConstant{true} true to disable vertical scrolling and show the full list.
#define TREEVIEW_ADDROW							'adrw'			///< Show an add new column row at the bottom of the list
#define TREEVIEW_RESIZABLE					'rsiz'			///< The treeview is resizable from the bottom edge
/// @}

/// @addtogroup TREEVIEW_DRAGSTART
/// @ingroup group_enumeration
/// @{
#define TREEVIEW_DRAGSTART_ALLOW		1			///< Allow dragging.
#define TREEVIEW_DRAGSTART_SELECT		2			///< Select the picked object.
/// @}


/// @addtogroup LV_COLUMN
/// @ingroup group_enumeration
/// @{
#define LV_TREE					'tree'			///< Tree or list.
#define LV_USERTREE			'ustr'			///< %User tree. If set, the tree view calls TreeViewFunctions::DrawCell() for the left cell of each line (otherwise it would display the object's name in the cell).
#define LV_USER					'user'			///< Custom.
#define LV_CHECKBOX			'cbox'			///< Checkbox. If set, the tree view calls TreeViewFunctions::IsChecked() and TreeViewFunctions::SetCheck() for each column and row.
#define LV_CHECKBOXUSER	'cboX'			///< Checkbox. If set, the tree view calls TreeViewFunctions::IsChecked() and TreeViewFunctions::SetCheck() for each column and row. User draw by TreeViewFunctions::DrawCell().
#define LV_SLIDER				'slid'			///< Slider. If set, the tree view calls TreeViewFunctions::GetFloatValue() and TreeViewFunctions::SetFloatValue() for each column and row.
#define LV_DROPDOWN			'drop'			///< Dropdown cycle box. If set, the tree view calls TreeViewFunctions::GetDropDownMenu() and TreeViewFunctions::SetDropDownMenu() for each column and row.
/// @}

/// @addtogroup LV_CHECKBOX
/// @ingroup group_enumeration
/// @{
#define LV_CHECKBOX_ENABLED		1			///< Checkbox is enabled.
#define LV_CHECKBOX_CHECKED		2			///< Checkbox is checked.
#define LV_CHECKBOX_TRISTATE	4			///< Checkbox tristate.
#define LV_CHECKBOX_HIDE			8			///< Checkbox is hidden.
#define LV_CHECKBOX_GREYEDOUT	16		///< Checkbox is greyed out.
/// @}

/// @addtogroup LV_COLUMN_WIDTH_LAYOUT
/// @ingroup group_enumeration
/// @{
#define LV_COLUMN_WIDTH_AUTOMATIC		-1		///< Within TreeViewFunctions::GetColumnWidth() return it to use automatic width for the given column. @since R18
#define LV_COLUMN_WIDTH_FIT					-2		///< Within TreeViewFunctions::GetColumnWidth() return it to use automatic fitting to available space for the given column. @since R18
/// @}


/// Use this to force a copy cursor. The next TreeViewFunctions::InsertObject() call will have <tt>bCopy = true</tt>.
#define ACCEPT_DRAG_OBJECT_FORCE_COPY	(1 << 30)

/// @markPrivate
#define LISTVIEW_TABLE_SIZE						55

class TreeViewCustomGui;

class GeUserArea;

//----------------------------------------------------------------------------------------
/// Tree/List view cell information.
//----------------------------------------------------------------------------------------
struct CellInfo
{
	GeUserArea	*frame;			///< The user area to draw in.

	Int32	xpos,				///< The position X coordinate.
				ypos,				///< The position Y coordinate.
				width,			///< The width.
				height;			///< The height.

	Int32	line,				///< The line.
				col;				///< The column.
};

//----------------------------------------------------------------------------------------
/// Tree/List view draw information.
//----------------------------------------------------------------------------------------
struct DrawInfo : public CellInfo
{
	GeData bgCol;			///< The background color, can be a vector or a color ID.
};

/// @addtogroup MOUSEINFO_BUTTON
/// @ingroup group_enumeration
/// @{
#define MOUSEINFO_BUTTON_LEFT		0			///< Left button.
#define MOUSEINFO_BUTTON_RIGHT	1			///< Right button.
#define MOUSEINFO_BUTTON_MIDDLE	2			///< Middle button.
/// @}

//----------------------------------------------------------------------------------------
/// Tree/List view mouse information.
//----------------------------------------------------------------------------------------
struct MouseInfo : public CellInfo
{
	Float	mx;							///< The mouse X coordinate.
	Float	my;							///< The mouse Y coordinate.
	Int32	button;					///< The mouse button: @enumerateEnum{MOUSEINFO_BUTTON}
	Float	mxRelative;			///< The mouse position relative to the end of the horizontal tree lines.\n
												///< Usually mouse coordinates are in list view space. This can become difficult when the user clicks into the @ref LV_USERTREE column, hence this member.
	Bool	startDrag;			///< Not used.
	Bool	startpaint,			///< This is needed in the Layer Manager. The user can change the state of the column by clicking somewhere and dragging the mouse.\n
												///< To start this drag, set <tt>startpaint = @formatConstant{true}</tt> in TreeViewFunctions::MouseDown().
				inpaint;				///< This is needed in the Layer Manager. The user can change the state of the column by clicking somewhere and dragging the mouse.\n
												///< TreeViewFunctions::MouseDown() will be called for each line with <tt>inpaint = @formatConstant{true}</tt>.
	const BaseContainer	*inputmsg;			///< The container originally sent to the @link GeUserArea::InputEvent InputEvent()@endlink of the tree view's user area. Always <tt>!= @formatConstant{nullptr}</tt>.
};

//----------------------------------------------------------------------------------------
/// Tree/List view drag information.
//----------------------------------------------------------------------------------------
struct DragInfo : public CellInfo
{
	Float	mx;								///< The mouse X coordinate.
	Float	my;								///< The mouse Y coordinate.
	BaseContainer msg;			///< The message container.

	void	*dragobject;			///< The dragged object.
	Int32	dragtype;					///< The drag type: @link DRAGTYPE_FILES DRAGTYPE@endlink
};

//-------------------------------------------------------------------------------------------------
/// DropDown menu information, filled out by the user
//-------------------------------------------------------------------------------------------------
struct TreeViewDropDownMenuInfo
{
	TreeViewDropDownMenuInfo() { entry = NOTOK; menu = nullptr; icons = nullptr; state = LV_CHECKBOX_ENABLED; }
	Int32 entry;						///< The selected entry
	BaseContainer *menu;		///< The menu itself described by id : string(name), user owns the pointed container
	BaseContainer *icons;		///< The icons for the menu described by id : int(icon), user owns the pointed container
	Int32 state;						///< Set to the current state of the dropdown
};

//-------------------------------------------------------------------------------------------------
/// Percentage floating slider information, filled out by the user.
//-------------------------------------------------------------------------------------------------
struct TreeViewFloatSliderInfo
{
	TreeViewFloatSliderInfo() :value(1.0), minValue(0.0), maxValue(1.0), increment(0.01), floatFormat(FORMAT_PERCENT), state(LV_CHECKBOX_ENABLED) {}

	Float value;						///< The current value for the entry
	Float minValue;					///< The minimum range of the slider as drawn
	Float maxValue;					///< The maximum range of the slider as drawn
	Float minNominalValue;	///< The minimum range of the slider should the user drag the value out of bounds to re-size the slider range extents
	Float maxNominalValue;	///< The minimum range of the slider should the user drag the value out of bounds to re-size the slider range extents
	Float increment;				///< The increment used for vertical modification
	Int32 floatFormat;			///< The format one of the following FORMAT_PERCENT, FORMAT_DEGREE, FORMAT_REAL, FORMAT_METER
	Int32 state;						///< Set to the current state of the slider
	Int32	unit;							///< The sliders unit
};

//----------------------------------------------------------------------------------------
/// Callback for TreeViewFunctions::VisitChildren. Called for each child.
/// @param[in] root								The tree view root.
/// @param[in] obj								The child object.
/// @param[in] userdata						The user data.
/// @param[in] data1							The first data.
/// @param[in] data2							The second data.
/// @param[out] bCont							Set to @formatConstant{true} to continue browsing, otherwise to @formatConstant{false}.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*VisitChildrenCallback)(void* root, void* obj, void* userdata, void* data1, void* data2, Bool &bCont);


/// @addtogroup ID_TREEVIEW
/// @ingroup group_enumeration
/// @{
enum
{
	ID_TREEVIEW_CONTEXT_DISABLE = 1000,									///< Return an empty container to disable context menu in tree view.
	ID_TREEVIEW_CONTEXT_REMOVE = FIRST_POPUP_ID,				///< Remove the current item.
	ID_TREEVIEW_CONTEXT_RESET,													///< Remove all items.
	ID_TREEVIEW_FIRST_NEW_ID = FIRST_POPUP_ID + 10			///< First custom popup menu ID.
};
/// @}

//----------------------------------------------------------------------------------------
/// Inherit this class to supply a data and view model for TreeViewCustomGui. See @em ActiveObject.cpp SDK example.
//----------------------------------------------------------------------------------------
class TreeViewFunctions
{
	public:

		/// @name Destructor
		/// @{

		//----------------------------------------------------------------------------------------
		/// Destructor
		//----------------------------------------------------------------------------------------
		virtual ~TreeViewFunctions() { }

		/// @}

		/// @name Navigation
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the first object of the tree.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @return												The first object.
		//----------------------------------------------------------------------------------------
		virtual void* GetFirst(void *root, void *userdata) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the first child of @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The first child of @formatParam{obj}.
		//----------------------------------------------------------------------------------------
		virtual void* GetDown(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the object after @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The object after @formatParam{obj}.
		//----------------------------------------------------------------------------------------
		virtual void* GetNext(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the object before @formatParam{obj}.
		/// @note This is only used for drag and drop checks.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The object before @formatParam{obj}.
		//----------------------------------------------------------------------------------------
		virtual void* GetPred(void *root, void *userdata, void *obj);

		/// @}

		/// @name Layout
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the column width of object @formatParam{obj} in column @formatParam{col}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] area								The user area used to determine the text width with @formatParam{area}->@link GeUserArea::DrawGetTextWidth DrawGetTextWidth()@endlink. @callerOwnsPointed{user area}
		/// @return												The column width.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetColumnWidth(void *root, void *userdata, void *obj, Int32 col, GeUserArea* area);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the width of the header for column @formatParam{col}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] col								The column index.
		/// @param[in] area								The user area used to determine the text width with @formatParam{area}->@link GeUserArea::DrawGetTextWidth DrawGetTextWidth()@endlink. @callerOwnsPointed{user area}
		/// @return												The header column width, or a negative number for auto header width.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetHeaderColumnWidth(void *root, void *userdata, Int32 col, GeUserArea* area);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the minimum header height.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] area								The user area used to determine the text width with @formatParam{area}->@link GeUserArea::DrawGetTextWidth DrawGetTextWidth()@endlink. @callerOwnsPointed{user area}
		/// @return												The minimum header height, or a negative value for auto header height.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetMinHeaderHeight(void *root, void *userdata, GeUserArea* area);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the line height of object @formatParam{obj} in column @formatParam{col}. Always return a positive value.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] area								The user area used to determine the text width with @formatParam{area}->@link GeUserArea::DrawGetTextWidth DrawGetTextWidth()@endlink. @callerOwnsPointed{user area}
		/// @return												The line height.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetLineHeight(void *root, void *userdata, void *obj, Int32 col, GeUserArea* area); // always return a value > 0 !

		//----------------------------------------------------------------------------------------
		/// Called to specify the text colors of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[out] pNormal						Set this to the normal text color for @formatParam{obj}. Can be a vector or a color ID. @callerOwnsPointed{data}
		/// @param[out] pSelected					Set this to the selected text color for @formatParam{obj}. Can be a vector or a color ID. @callerOwnsPointed{data}
		//----------------------------------------------------------------------------------------
		virtual void GetColors(void *root, void *userdata, void *obj, GeData* pNormal, GeData* pSelected);

		//----------------------------------------------------------------------------------------
		/// Called to specify the background color of @formatParam{line}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] line								The line index.
		/// @param[out] col								Set this to the background color for @formatParam{line}. Can be a vector or a color ID. @callerOwnsPointed{data}
		//----------------------------------------------------------------------------------------
		virtual void GetBackgroundColor(void* root, void* userdata, void* obj, Int32 line, GeData* col);

		/// @}

		/// @name Draw
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to draw the cell for object @formatParam{obj} in column @formatParam{col} into the user area in @formatParam{drawinfo}->@link DrawInfo::frame frame@endlink.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] drawinfo						The draw information. @callerOwnsPointed{draw information}
		/// @param[in] bgColor						The background color. Can be a vector or a color ID.
		//----------------------------------------------------------------------------------------
		virtual void DrawCell(void *root, void *userdata, void *obj, Int32 col, DrawInfo *drawinfo, const GeData &bgColor);

		//----------------------------------------------------------------------------------------
		/// Called to draw the header for column @formatParam{col} into the user area in @formatParam{drawinfo}->@link DrawInfo::frame frame@endlink.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] col								The column index.
		/// @param[in] drawinfo						The draw information. @callerOwnsPointed{draw information}
		/// @return												@formatConstant{true} if you have drawn the header or @formatConstant{false} if the header should be drawn by the tree view.
		//----------------------------------------------------------------------------------------
		virtual Bool DrawHeaderCell(void *root, void *userdata, Int32 col, DrawInfo *drawinfo);

		/// @}

		/// @name Select
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the selection status of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												@trueIfOtherwiseFalse{the object is selected}
		//----------------------------------------------------------------------------------------
		virtual Bool IsSelected(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to select object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
		//----------------------------------------------------------------------------------------
		virtual void Select(void *root, void *userdata, void *obj, Int32 mode);

		/// @}

		/// @name Open
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the folding status of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												@trueIfOtherwiseFalse{the object is opened}
		//----------------------------------------------------------------------------------------
		virtual Bool IsOpened(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to open or close object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] onoff							@trueIfOtherwiseFalse{@formatParam{obj} should be opened}
		//----------------------------------------------------------------------------------------
		virtual void Open(void *root, void *userdata, void *obj, Bool onoff);

		/// @}

		/// @name Name and Bubble help
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the name of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The object name.
		//----------------------------------------------------------------------------------------
		virtual String GetName(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to set the name of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] str								The new object name.
		//----------------------------------------------------------------------------------------
		virtual void SetName(void *root, void *userdata, void *obj, const maxon::String &str);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the bubble help of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] info								The cell information.
		/// @return												The bubble help of the object.
		//----------------------------------------------------------------------------------------
		virtual String GetBubbleHelp(void* root, void* userdata, void* obj, Int32 col, CellInfo* info);

		/// @}

		/// @name ID
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the ID of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The object ID.
		//----------------------------------------------------------------------------------------
		virtual Int GetId(void *root, void *userdata, void *obj) = 0;

		/// @}

		/// @name Check
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the checkbox status of object @formatParam{obj} for column @formatParam{lColumn}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column index.
		/// @return												A combination of the following flags or @ref NOTOK to show no checkbox: @enumerateEnum{LV_CHECKBOX}
		//----------------------------------------------------------------------------------------
		virtual Int32 IsChecked(void *root, void *userdata, void *obj, Int32 lColumn);

		//----------------------------------------------------------------------------------------
		/// Called to set the checkbox status of object @formatParam{obj}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column index.
		/// @param[in] bCheck							@trueIfOtherwiseFalse{the checkbox should be checked}
		/// @param[in] bcMsg							The container originally sent to the @link GeUserArea::InputEvent InputEvent()@endlink of the tree view's user area.
		//----------------------------------------------------------------------------------------
		virtual void SetCheck(void *root, void *userdata, void *obj, Int32 lColumn, Bool bCheck, const BaseContainer& bcMsg);

		/// @}

		/// @name Tristate
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the tristate flag of the tree.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @return												@trueIfOtherwiseFalse{the tristate flag is set}
		//----------------------------------------------------------------------------------------
		virtual Bool IsTristate(void *root, void *userdata);

		/// @}

		/// @name Drag
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the drag type of object @formatParam{obj}, i.e. the type that the user would get if he started a drag in that cell.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												The object drag type, or @ref NOTOK to disable drag-and-drop: @link DRAGTYPE_FILES DRAGTYPE@endlink
		//----------------------------------------------------------------------------------------
		virtual Int32 GetDragType(void *root, void *userdata, void *obj) = 0;

		//----------------------------------------------------------------------------------------
		/// Called to determine if object @formatParam{obj} can be dragged or not and if dragged objects will be selected or not.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @return												A combination of the following flags: @enumerateEnum{TREEVIEW_DRAGSTART}
		//----------------------------------------------------------------------------------------
		virtual Int32 DragStart(void *root, void *userdata, void *obj);

		//----------------------------------------------------------------------------------------
		/// Called to check if object @formatParam{obj} can accept the specified drag-and-drop action, and in that case what the result would be.
		/// @note if @formatParam{obj} is @formatConstant{nullptr} @formatParam{dragobject} should be inserted as a child of the root.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] dragtype						The drag type: @link DRAGTYPE_FILES DRAGTYPE@endlink
		/// @param[in] dragobject					The drag object. @callerOwnsPointed{object}
		/// @param[in] bAllowCopy					@trueIfOtherwiseFalse{copying is allowed to this position.}
		/// @return												The result: @enumerateEnum{INSERT}\n
		/// 															The @ref ACCEPT_DRAG_OBJECT_FORCE_COPY bit flag can be used together with the @ref INSERT constants.
		//----------------------------------------------------------------------------------------
		virtual Int32 AcceptDragObject(void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Bool &bAllowCopy);

		//----------------------------------------------------------------------------------------
		/// Called to set the drag object to @formatParam{obj}.
		/// @note	Useful to determine if dragging happens internally (rearrange items) or externally (dragged items from another tree for instance).
		///				To check this, store the drag object data and compare it with @em dragobject in InsertObject().
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								The drag object on drag start.
		//----------------------------------------------------------------------------------------
		virtual void SetDragObject(void *root, void *userdata, void *obj);

		//----------------------------------------------------------------------------------------
		/// Called to generate a drag array for object @formatParam{obj} in @formatParam{ar}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								The drag object.
		/// @param[out] ar								Fill this array with the drag objects for @formatParam{obj}. @callerOwnsPointed{array}
		//----------------------------------------------------------------------------------------
		virtual void GenerateDragArray(void *root, void *userdata, void *obj, AtomArray* ar);

		//----------------------------------------------------------------------------------------
		/// Called to generate drag data and return a pointer to it in @formatParam{dragdata}, to be freed with FreeDragData().
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								The drag object.
		/// @param[out] dragdata					Points to a pointer that should be set to the generated drag data.
		//----------------------------------------------------------------------------------------
		virtual void GenerateDragData(void *root, void *userdata, void* obj, void **dragdata);

		//----------------------------------------------------------------------------------------
		/// Called to free the drag data generated by GenerateDragData().
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in,out] dragdata				The drag data to free.
		//----------------------------------------------------------------------------------------
		virtual void FreeDragData(void *root, void *userdata, void *dragdata);

		/// @}

		/// @name Insert Object
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to insert @formatParam{dragobject} as specified.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] dragtype						The drag type: @link DRAGTYPE_FILES DRAGTYPE@endlink
		/// @param[in] dragobject					The drag object on drag receive. @callerOwnsPointed{object}
		/// @param[in] insertmode					The insert mode: @enumerateEnum{INSERT}
		/// @param[in] bCopy							@trueIfOtherwiseFalse{the object should be copied}
		//----------------------------------------------------------------------------------------
		virtual void InsertObject(void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Int32 insertmode, Bool bCopy);

/// @addtogroup INSERT
/// @ingroup group_enumeration
/// @{
#define INSERT_BEFORE		(1 << 0)			///< Insert before.
#define INSERT_AFTER		(1 << 1)			///< Insert after.
#define INSERT_UNDER		(1 << 2)			///< Insert under.
#define INSERT_REPLACE  (1 << 3)			///< Replace the object.
/// @}

		/// @}

		/// @name Context Menu
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to build a context menu for object @formatParam{obj} and column @formatParam{lColumn}. See ShowPopupMenu() for the format.
		/// @note @formatParam{bc} container already contains 2 default items: @ref ID_TREEVIEW_CONTEXT_REMOVE and @ref ID_TREEVIEW_CONTEXT_RESET. These may be removed.\n
		///				The added menu entry IDs must be larger than @ref ID_TREEVIEW_FIRST_NEW_ID.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column index.
		/// @param[in,out] bc							Add context menu entries to this container. @callerOwnsPointed{container}
		//----------------------------------------------------------------------------------------
		virtual void CreateContextMenu(void *root, void *userdata, void *obj, Int32 lColumn, BaseContainer* bc);

		//----------------------------------------------------------------------------------------
		/// Called by a command in the context menu setup in CreateContextMenu().
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column index.
		/// @param[in] lCommand						The menu command ID.
		/// @return												@trueIfOtherwiseFalse{the command has been processed and the data needs to be updated}
		//----------------------------------------------------------------------------------------
		virtual Bool ContextMenuCall(void *root, void *userdata, void *obj, Int32 lColumn, Int32 lCommand);

		/// @}

		/// @name Header/Column
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the sort mode of column @formatParam{lColID}.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] lColID							The column index.
		/// @return												The sort direction.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetHeaderSortArrow(void *root, void *userdata, Int32 lColID);

		//----------------------------------------------------------------------------------------
		/// Called to check if column @formatParam{lColID} can be resized or not.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] lColID							The column index.
		/// @return												@trueIfOtherwiseFalse{the column can be resized}
		//----------------------------------------------------------------------------------------
		virtual Bool IsResizeColAllowed(void *root, void *userdata, Int32 lColID);

		//----------------------------------------------------------------------------------------
		/// Called to check if column @formatParam{lColID} can be moved or not.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] lColID							The column index.
		/// @return												@trueIfOtherwiseFalse{the column can be moved}
		//----------------------------------------------------------------------------------------
		virtual Bool IsMoveColAllowed(void *root, void *userdata, Int32 lColID);

		/// @}

		/// @name Input Events
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called when an input event is received. All information about the input event is stored in the @formatParam{msg} container.\n
		/// See @link page_input_events Input Events@endlink for more information. See also @ref MOUSEMOVE_DELTA.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] pArea							The user area of the tree view. @callerOwnsPointed{user area}
		/// @param[in] msg								The event container.
		/// @return												@trueIfOtherwiseFalse{the event was handled}
		//----------------------------------------------------------------------------------------
		virtual Bool InputEvent(void* root, void* userdata, GeUserArea* pArea, const BaseContainer &msg);

		//----------------------------------------------------------------------------------------
		/// Called when a mouse down event is received.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] mouseinfo					The mouse information. @callerOwnsPointed{mouse information}
		/// @param[in] rightButton				@trueIfOtherwiseFalse{the right mouse button was used}
		/// @return												@trueIfOtherwiseFalse{the event was handled}
		//----------------------------------------------------------------------------------------
		virtual Bool MouseDown(void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo, Bool rightButton);

		//----------------------------------------------------------------------------------------
		/// Called when a mouse double click event is received.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] obj								An object in the tree.
		/// @param[in] col								The column index.
		/// @param[in] mouseinfo					The mouse information. @callerOwnsPointed{mouse information}
		/// @return												!=0 if the event was handled.
		//----------------------------------------------------------------------------------------
		virtual Int32 DoubleClick(void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo); // return false, if you want to open the rename dialog

		//----------------------------------------------------------------------------------------
		/// Called when a delete event is received.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		//----------------------------------------------------------------------------------------
		virtual void DeletePressed(void *root, void *userdata);

		//----------------------------------------------------------------------------------------
		/// Called when a header has been clicked.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] lColID							The column index.
		/// @param[in] lChannel						The mouse channel: @enumerateEnum{BFM_INPUT_CHANNEL}
		/// @param[in] bDblClk						@trueOtherwiseFalse{for double-click event}
		/// @param[in] mouseX							The mouse horizontal position local to the left hand edge of the column or NOTOK if dragging a column
		/// @param[in] mouseY							The mouse vertical position local to the header top or NOTOK if dragging a column
		/// @param[in] ua									The header's userarea or nullptr if dragging a column
		/// @return												@trueIfOtherwiseFalse{the tree view needs to be updated}
		//----------------------------------------------------------------------------------------
		virtual Bool HeaderClick(void *root, void *userdata, Int32 lColID, Int32 lChannel, Bool bDblClk, Int32 mouseX, Int32 mouseY, GeUserArea* ua);

		/// @}

		/// @name Notifications
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called when the tree view has been scrolled.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] h									The horizontal scroll steps.
		/// @param[in] v									The vertical scroll steps.
		/// @param[in] x									The X offset.
		/// @param[in] y									The Y offset.
		//----------------------------------------------------------------------------------------
		virtual void Scrolled(void *root, void *userdata, Int32 h, Int32 v, Int32 x, Int32 y);

		//----------------------------------------------------------------------------------------
		/// Called when a paint selection has been performed in the tree view.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		//----------------------------------------------------------------------------------------
		virtual void PaintFinished(void *root, void *userdata);

		//----------------------------------------------------------------------------------------
		/// Called when a column has been moved.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		/// @param[in] lColID							The column index.
		/// @param[in] lInsertBeforeCol		The column to insert @formatParam{lColID} before.
		/// @param[in] plIndexMap					The column index map array. @callerOwnsPointed{array}
		/// @param[in] pbcLayout					The new layout container. Basically the same as the container passed in TreeViewCustomGui::SetLayout() but reflecting the changed column order.
		/// @return												@trueIfOtherwiseFalse{the move is acceptable}\n
		/// 															If @formatConstant{false} is returned the layout change is canceled.
		//----------------------------------------------------------------------------------------
		virtual Bool ColumnMoved(void *root, void *userdata, Int32 lColID, Int32 lInsertBeforeCol, Int32* plIndexMap, const BaseContainer* pbcLayout);

		//----------------------------------------------------------------------------------------
		/// Called when selection has changed.
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The user data.
		//----------------------------------------------------------------------------------------
		virtual void SelectionChanged(void *root, void *userdata);

		/// @}

		/// @name Private
		/// @{

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		virtual void InitCache(void *root, void *userdata);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		virtual Bool PythonCleanup(void *root, void *userdata);

		//----------------------------------------------------------------------------------------
		/// Gets a drop down menu and it's current selected entry.
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column.
		/// @param[out] menuInfo					The MenuInfo that the user must fill out.
		//----------------------------------------------------------------------------------------
		virtual void GetDropDownMenu(void *root, void *userdata, void *obj, Int32 lColumn, TreeViewDropDownMenuInfo* menuInfo);

		//----------------------------------------------------------------------------------------
		/// Called to set the current menu entry by e.g. user interaction.
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column.
		/// @param[in] entry							The entry that the user has picked.
		//----------------------------------------------------------------------------------------
		virtual void SetDropDownMenu(void *root, void *userdata, void *obj, Int32 lColumn, Int32 entry);

		//----------------------------------------------------------------------------------------
		/// Gets the value and ranges for a float slider.
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column.
		/// @param[out] sliderInfo				The information that the user must fill out about the slider, it's
		/// 															range and values.
		//----------------------------------------------------------------------------------------
		virtual void GetFloatValue(void *root, void *userdata, void *obj, Int32 lColumn, TreeViewFloatSliderInfo* sliderInfo);

		//----------------------------------------------------------------------------------------
		/// Sets the float value from the slider by e.g. user interaction.
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column.
		/// @param[in] value							The value to set.
		//----------------------------------------------------------------------------------------
		virtual void SetFloatValueEx(void *root, void *userdata, void *obj, Int32 lColumn, Float value);

		//----------------------------------------------------------------------------------------
		/// Requests to add a row to the treeview
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		///
		/// @return												true if it succeeds, false if it fails.
		//----------------------------------------------------------------------------------------
		virtual Bool AddRow(void* root, void* userdata);

		//----------------------------------------------------------------------------------------
		/// Requests the text to display when the treeview area is completely empty such as "Drag falloff object's here"
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		///
		/// @return												the text to display in the empty treeview area.
		//----------------------------------------------------------------------------------------
		virtual String EmptyText(void* root, void* userdata);

		/// @}

		/// @name Non-Overridable
		/// @{

		//----------------------------------------------------------------------------------------
		/// Visits object @formatParam{obj} and all its children, calling <tt>@formatParam{fn}(@formatParam{root}, @formatParam{obj}, @formatParam{userdata}, @formatParam{data1}, @formatParam{data2}, result)</tt> for each object.
		/// @param[in] root								The tree root.
		/// @param[in] obj								An object in the tree.
		/// @param[in] fn									Callback to evaluate for each child.
		/// @param[in] userdata						The user data.
		/// @param[in] data1							The first data.
		/// @param[in] data2							The second data.
		/// @return												@trueIfOtherwiseFalse{all evaluations were successful}
		//----------------------------------------------------------------------------------------
		Bool VisitChildren(void* root, void* obj, VisitChildrenCallback fn, void* userdata, void* data1, void* data2);

		//----------------------------------------------------------------------------------------
		/// Sets the float value from the slider by e.g. user interaction.
		///
		/// @param[in] root								The tree root.
		/// @param[in] userdata						The userdata.
		/// @param[in] obj								An object in the tree.
		/// @param[in] lColumn						The column.
		/// @param[in] value							The value to set.
		/// @param[in] finalValue					True if this is the final value that will be set for this interaction.
		//----------------------------------------------------------------------------------------
		virtual void SetFloatValue(void *root, void *userdata, void *obj, Int32 lColumn, Float value, Bool finalValue);

		/// @}
};


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class TreeViewF
{
public:
	Int32		GetTableSize() { return LISTVIEW_TABLE_SIZE; }

	// Navigation Functions
	void*		GetFirst(TreeViewFunctions* pFuncs, void *root, void *userdata);
	void*		GetDown(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	void*		GetNext(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	void*		GetPred(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);

	// Layout&Draw Functions
	Int32		GetColumnWidth(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area);
	Int32		GetHeaderColumnWidth(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, GeUserArea* area);
	Int32		GetMinHeaderHeight(TreeViewFunctions* pFuncs, void *root, void *userdata, GeUserArea* area);
	Int32		GetLineHeight(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area);
	void		GetColors(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, GeData* pNormal, GeData* pSelected);
	void		GetBackgroundColor(TreeViewFunctions* pFuncs, void* root, void* userdata, void* obj, Int32 line, GeData* col);
	void		DrawCell(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, DrawInfo *drawinfo, const GeData& bgColor);
	Bool		DrawHeaderCell(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, DrawInfo *drawinfo);

	// Get Functions
	Bool		IsSelected(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	Bool		IsOpened(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	String	GetName(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	Int			GetId(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	Int32		GetDragType(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	Int32		DragStart(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	Int32		IsChecked(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn);
	Bool		IsTristate(TreeViewFunctions* pFuncs, void *root, void *userdata);

	// Set Functions
	void		Open(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Bool onoff);
	void		SetName(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, const maxon::String &str);
	void		Select(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 mode);
	Int32		AcceptDragObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Bool &bAllowCopy);
	void		InsertObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Int32 insertmode, Bool bCopy);
	void		SetCheck(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Bool bCheck, const BaseContainer& bcMsg);

	// GUI and Drag&Drop
	void		CreateContextMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, BaseContainer* bc);
	void		SetDragObject(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	void		GenerateDragArray(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, AtomArray* ar);
	void		GenerateDragData(TreeViewFunctions* pFuncs, void *root, void *userdata, void* obj, void **dragdata);
	void		FreeDragData(TreeViewFunctions* pFuncs, void *root, void *userdata, void *dragdata);
	Int32		GetHeaderSortArrow(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);
	Bool		IsResizeColAllowed(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);
	Bool		IsMoveColAllowed(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);

	Bool		InputEvent(TreeViewFunctions* pFuncs, void* root, void* userdata, GeUserArea* pArea, const BaseContainer &msg);
	Bool		MouseDown(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo, Bool rightButton);
	Int32		DoubleClick(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo);
	void		DeletePressed(TreeViewFunctions* pFuncs, void *root, void *userdata);

	// Notifications
	void		Scrolled(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 h, Int32 v, Int32 x, Int32 y);
	void		PaintFinished(TreeViewFunctions* pFuncs, void *root, void *userdata);
	Bool		ColumnMoved(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lInsertBeforeCol, Int32* plIndexMap, const BaseContainer* pbcLayout);
	void		SelectionChanged(TreeViewFunctions* pFuncs, void *root, void *userdata);
	Bool		HeaderClick(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lChannel, Bool bDbl, Int32 mouseX, Int32 mouseY, GeUserArea* ua);
	Bool		ContextMenuCall(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 lCommand);

	void		InitCache(TreeViewFunctions* pFuncs, void *root, void *userdata);
	Bool		PythonCleanup(TreeViewFunctions* pFuncs, void *root, void *userdata);

	void		GetDropDownMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewDropDownMenuInfo* menuInfo);
	void		SetDropDownMenu(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 entry);
	void		GetFloatValue(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewFloatSliderInfo* sliderInfo);
	void		SetFloatValueEx(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value);

	Bool		AddRow(TreeViewFunctions* pFuncs, void* root, void* userdata);

	String		EmptyText(TreeViewFunctions* pFuncs, void* root, void* userdata);

	String		GetBubbleHelp(TreeViewFunctions* pFuncs, void* root, void* userdata, void* obj, Int32 col, CellInfo* info);
	void		SetFloatValue(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value, Bool finalValue);
};

struct InternalFunctionTable
{
	/* 1*/ Int32		(TreeViewF::*GetTableSize)();

	// Navigation functions
	/* 2*/ void*		(TreeViewF::*GetFirst)(TreeViewFunctions* pFuncs, void *root, void *userdata);
	/* 3*/ void*		(TreeViewF::*GetDown)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/* 4*/ void*		(TreeViewF::*GetNext)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/* 5*/ void*		(TreeViewF::*GetPred)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj); // only for drag&drop check

	// Layout&Draw functions
	/* 6*/ Int32		(TreeViewF::*GetColumnWidth)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area);
	/* 7*/ Int32		(TreeViewF::*GetHeaderColumnWidth)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, GeUserArea* area);
	/* 8*/ Int32		(TreeViewF::*GetMinHeaderHeight)(TreeViewFunctions* pFuncs, void *root, void *userdata, GeUserArea* area);
	/* 9*/ Int32		(TreeViewF::*GetLineHeight)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, GeUserArea* area);
	/*10*/ void			(TreeViewF::*GetColors)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, GeData* pNormal, GeData* pSelected);
	/*11*/ void			(TreeViewF::*GetBackgroundColor)(TreeViewFunctions* pFuncs, void* root, void* userdata, void* obj, Int32 line, GeData* col);
	/*12*/ void			(TreeViewF::*DrawCell)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, DrawInfo *drawinfo, const GeData &bgColor);
	/*13*/ Bool			(TreeViewF::*DrawHeaderCell)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 col, DrawInfo *drawinfo);

	// Get functions
	/*14*/ Bool			(TreeViewF::*IsSelected)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*15*/ Bool			(TreeViewF::*IsOpened)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*16*/ String		(TreeViewF::*GetName)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*17*/ Int			(TreeViewF::*GetId)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*18*/ Int32		(TreeViewF::*GetDragType)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj); // return NOTOK to disable D&D
	/*19*/ Int32		(TreeViewF::*DragStart)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*20*/ Int32		(TreeViewF::*IsChecked)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn);
	/*21*/ Bool			(TreeViewF::*IsTristate)(TreeViewFunctions* pFuncs, void *root, void *userdata);

	// Set functions
	/*22*/ void			(TreeViewF::*Open)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Bool onoff);
	/*23*/ void			(TreeViewF::*SetName)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, const maxon::String &str);
	/*24*/ void			(TreeViewF::*Select)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 mode);
	/*25*/ Int32		(TreeViewF::*AcceptDragObject)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Bool &bAllowCopy); // return INSERT_xxx
	/*26*/ void			(TreeViewF::*InsertObject)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 dragtype, void *dragobject, Int32 insertmode, Bool bCopy);
	/*27*/ void			(TreeViewF::*SetCheck)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Bool bCheck, const BaseContainer& bcMsg);

	// GUI and Drag&Drop
	/*28*/ void			(TreeViewF::*CreateContextMenu)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, BaseContainer* bc);
	/*29*/ void			(TreeViewF::*SetDragObject)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj);
	/*30*/ void			(TreeViewF::*GenerateDragArray)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, AtomArray* ar);
	/*31*/ void			(TreeViewF::*GenerateDragData)(TreeViewFunctions* pFuncs, void *root, void *userdata, void* obj, void **dragdata);
	/*32*/ void			(TreeViewF::*FreeDragData)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *dragdata);
	/*33*/ Int32		(TreeViewF::*GetHeaderSortArrow)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);
	/*34*/ Bool			(TreeViewF::*IsResizeColAllowed)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);
	/*35*/ Bool			(TreeViewF::*IsMoveColAllowed)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID);

	/*36*/ Bool			(TreeViewF::*InputEvent)(TreeViewFunctions* pFuncs, void* root, void* userdata, GeUserArea* pArea, const BaseContainer &msg);
	/*37*/ Bool			(TreeViewF::*MouseDown)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo, Bool rightButton);
	/*38*/ Int32		(TreeViewF::*DoubleClick)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 col, MouseInfo *mouseinfo); // return false, if you want to open the rename dialog
	/*39*/ void			(TreeViewF::*DeletePressed)(TreeViewFunctions* pFuncs, void *root, void *userdata);

	// Notifications
	/*40*/ void			(TreeViewF::*Scrolled)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 h, Int32 v, Int32 x, Int32 y);
	/*41*/ void			(TreeViewF::*PaintFinished)(TreeViewFunctions* pFuncs, void *root, void *userdata);
	/*42*/ Bool			(TreeViewF::*ColumnMoved)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lInsertBeforeCol, Int32* plIndexMap, const BaseContainer* pbcLayout);
	/*43*/ void			(TreeViewF::*SelectionChanged)(TreeViewFunctions* pFuncs, void *root, void *userdata);
	/*44*/ Bool			(TreeViewF::*HeaderClick)(TreeViewFunctions* pFuncs, void *root, void *userdata, Int32 lColID, Int32 lChannel, Bool bDbl, Int32 mouseX, Int32 mouseY, GeUserArea* ua);
	/*45*/ Bool			(TreeViewF::*ContextMenuCall)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 lCommand); // called by the delete command in the context menu

	/*46*/ void			(TreeViewF::*InitCache)(TreeViewFunctions* pFuncs, void *root, void *userdata);
	/*47*/ Bool			(TreeViewF::*PythonCleanup)(TreeViewFunctions* pFuncs, void *root, void *userdata);

	/*48*/ void			(TreeViewF::*GetDropDownMenu)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewDropDownMenuInfo* menuInfo);
	/*49*/ void			(TreeViewF::*SetDropDownMenu)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Int32 entry);

	/*50*/ void			(TreeViewF::*GetFloatValue)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, TreeViewFloatSliderInfo* sliderInfo);
	/*51*/ void			(TreeViewF::*SetFloatValueEx)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value);

	/*52*/ Bool			(TreeViewF::*AddRow)(TreeViewFunctions* pFuncs, void* root, void* userdata);

	/*53*/ String		(TreeViewF::*EmptyText)(TreeViewFunctions* pFuncs, void* root, void* userdata);

	/*54*/ String		(TreeViewF::*GetBubbleHelp)(TreeViewFunctions* pFuncs, void* root, void* userdata, void* obj, Int32 col, CellInfo* info);
	/*55*/ void			(TreeViewF::*SetFloatValue)(TreeViewFunctions* pFuncs, void *root, void *userdata, void *obj, Int32 lColumn, Float value, Bool finalValue);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

//----------------------------------------------------------------------------------------
/// The tree view custom GUI (@ref CUSTOMGUI_TREEVIEW) is a very versatile list view interface.\n
/// Here are the settings: @enumerateEnum{TREEVIEW_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class TreeViewCustomGui : public BaseCustomGui<CUSTOMGUI_TREEVIEW>
{
		TreeViewCustomGui();
		~TreeViewCustomGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Initializes the tree.
		/// @param[in] root								The root object. @callerOwnsPointed{object}
		/// @param[in] functions					The tree view functions. @callerOwnsPointed{object}
		/// @param[in] userdata						The user data. @callerOwnsPointed{object}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetRoot(void *root, TreeViewFunctions *functions, void *userdata);

		//----------------------------------------------------------------------------------------
		/// Sets the layout of the tree view.
		/// @param[in] columns						The number of columns.
		/// @param[in] data								The layout container, with one column type entry for each column: @enumerateEnum{LV_COLUMN}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetLayout(Int32 columns, const BaseContainer &data);

		//----------------------------------------------------------------------------------------
		/// Sets the header text for a column.
		/// @param[in] lColumnID					The column index.
		/// @param[in] str								The header text.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetHeaderText(Int32 lColumnID, const maxon::String &str);

		//----------------------------------------------------------------------------------------
		/// Gets the tree view user area.
		/// @return												The tree view user area. @theOwnsPointed{tree view,user area}
		//----------------------------------------------------------------------------------------
		GeUserArea* GetTreeViewArea();

		//----------------------------------------------------------------------------------------
		/// Gets the header user area.
		/// @return												The header user area. @theOwnsPointed{tree view,user area}
		//----------------------------------------------------------------------------------------
		GeUserArea* GetHeaderArea();

		//----------------------------------------------------------------------------------------
		/// Refreshes the tree view.
		//----------------------------------------------------------------------------------------
		void Refresh();

		//----------------------------------------------------------------------------------------
		/// Gets the auto-width of the column.
		/// @param[in] lColID							The column index.
		/// @return												The column auto width.
		//----------------------------------------------------------------------------------------
		Int32 GetAutoColumnWidth(Int32 lColID);

		//----------------------------------------------------------------------------------------
		/// Gets the size of the column the user has set.
		/// @param[in] lColID							The column index.
		/// @return												The column user width.
		//----------------------------------------------------------------------------------------
		Int32 GetColumnWidthUser(Int32 lColID);

		//----------------------------------------------------------------------------------------
		/// Gets the real column width.
		/// @param[in] lColID							The column index.
		/// @return												The real column width.
		//----------------------------------------------------------------------------------------
		Int32 GetRealColumnWidth(Int32 lColID);

		//----------------------------------------------------------------------------------------
		/// Sets the user column width.
		/// @param[in] lColID							The column index.
		/// @param[in] lWidth							The column width to set.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetColumnWidthUser(Int32 lColID, Int32 lWidth);

		//----------------------------------------------------------------------------------------
		/// Scrolls to @formatParam{pObj} and expands the tree if necessary.
		/// @param[in] pObj								The object to scroll to.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool MakeVisible(void* pObj);

		//----------------------------------------------------------------------------------------
		/// Expands the tree to @formatParam{pObj}.
		/// @param[in] pObj								The object to show.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool ShowObject(void* pObj);

		//----------------------------------------------------------------------------------------
		/// Gets the cell position of @formatParam{pObj}.
		/// @param[in] pObj								The object to get the cell position for.
		/// @param[in] lColID							The column index.
		/// @param[out] pArea							Assigned the user area pointer.
		/// @param[out] x									Assigned the left X coordinate.
		/// @param[out] y									Assigned the left Y coordinate.
		/// @param[out] w									Assigned the width.
		/// @param[out] h									Assigned the height.
		/// @param[out] lTextOffset				Assigned the text offset.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetCellPosition(void* pObj, Int32 lColID, GeUserArea *&pArea, Int32 &x, Int32 &y, Int32 &w, Int32 &h, Int32 &lTextOffset);

		//----------------------------------------------------------------------------------------
		/// Queries the internal scroll group for its currently visible region, a rectangle between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
		/// @since R17.032
		/// @param[out] x1								Assigned the X coordinate of the top left visible corner.
		/// @param[out] y1								Assigned the Y coordinate of the top left visible corner.
		/// @param[out] x2								Assigned the X coordinate of the bottom right visible corner.
		/// @param[out] y2								Assigned the Y coordinate of the bottom right visible corner.
		/// @return												@trueIfOtherwiseFalse{the visible area could be retrieved}
		//----------------------------------------------------------------------------------------
		Bool GetVisibleScrollArea(Int32& x1, Int32& y1, Int32& x2, Int32& y2);

		//----------------------------------------------------------------------------------------
		/// Gets the number of currently visible lines related to folded and unfolded items of the tree.
		/// @since R17.032
		/// @return												The number of visible lines.
		//----------------------------------------------------------------------------------------
		Int32 GetVisibleLineCount();

		//----------------------------------------------------------------------------------------
		/// Checks if @formatParam{pObj} is the focus item.
		/// @param[in] pObj								The object to check.
		/// @return												@trueIfOtherwiseFalse{@formatParam{pObj} is the focus item}
		//----------------------------------------------------------------------------------------
		Bool IsFocusItem(void* pObj);

		//----------------------------------------------------------------------------------------
		/// Retrieves the focus item.
		/// @return												The focus item.
		//----------------------------------------------------------------------------------------
		void* GetFocusItem();

		//----------------------------------------------------------------------------------------
		/// Sets the focus item.
		/// @param[in] pItem							The new focus item.
		//----------------------------------------------------------------------------------------
		void SetFocusItem(void* pItem);

		//----------------------------------------------------------------------------------------
		/// Retrieves the layout container of the tree view.
		/// @return												The container of the tree view layout. Basically the same container passed in SetLayout() but reflecting any change of the column order.
		//----------------------------------------------------------------------------------------
		const BaseContainer* GetLayout();

		//----------------------------------------------------------------------------------------
		/// Gets the object for a line in the tree view.
		/// @param[in] line								The line in the tree view.
		/// @param[out] level							Assigned the hierarchy level of the tree.
		/// @return												The object, or @formatConstant{nullptr} if there is no object.
		//----------------------------------------------------------------------------------------
		void* GetObject(Int32 line, Int32 *level);

		//----------------------------------------------------------------------------------------
		/// Retrieves the selected item.
		/// @return												The selected item.
		//----------------------------------------------------------------------------------------
		void* GetSelectionItem();

		//----------------------------------------------------------------------------------------
		/// Sets the selected item.
		/// @param[in] pItem							The new selected item.
		//----------------------------------------------------------------------------------------
		void SetSelectionItem(void* pItem);

		//----------------------------------------------------------------------------------------
		/// Sets the internal scroll group currently visible region, a rectangle between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
		/// @since R18
		/// @param[in] x1									The left x value.
		/// @param[in] y1									The top y value.
		/// @param[in] x2									The right x value.
		/// @param[in] y2									The bottom y value.
		///
		/// @return												true if it succeeds, false if it fails.
		// -------------------------------------------------------------------------------------------------
		//----------------------------------------------------------------------------------------
		Bool SetVisibleScrollArea(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iTreeViewCustomGui
	{
	};
#else
	class iTreeViewCustomGui;
#endif

struct TreeViewLib : public BaseCustomGuiLib
{
	Bool					(iTreeViewCustomGui::*SetRoot)(void *root, InternalFunctionTable* f, void *userdata, Int32 lSize, TreeViewF* pControl, TreeViewFunctions* pFunctions);
	void					(iTreeViewCustomGui::*Refresh)();
	Bool					(iTreeViewCustomGui::*SetLayout)(Int32 columns, const BaseContainer &data);
	Bool					(iTreeViewCustomGui::*ShowObject)(void *o);
	Bool					(iTreeViewCustomGui::*SetHeaderText)(Int32 lColumnID, const maxon::String &str);
	GeUserArea*		(iTreeViewCustomGui::*GetTreeViewArea)();
	GeUserArea*		(iTreeViewCustomGui::*GetHeaderArea)();
	Int32					(iTreeViewCustomGui::*GetAutoColumnWidth)(Int32 lColID);
	Int32					(iTreeViewCustomGui::*GetColumnWidthUser)(Int32 lColID);
	Int32					(iTreeViewCustomGui::*GetRealColumnWidth)(Int32 lColID);
	Bool					(iTreeViewCustomGui::*SetColumnWidthUser)(Int32 lColID, Int32 lWidth);
	Bool					(iTreeViewCustomGui::*MakeVisible)(void* pObj);
	Bool					(iTreeViewCustomGui::*GetCellPosition)(void* pObj, Int32 lColID, GeUserArea *&pArea, Int32 &x, Int32 &y, Int32 &w, Int32 &h, Int32 &lTextOffset);
	Bool					(iTreeViewCustomGui::*IsFocusItem)(void* pObj);
	void*					(iTreeViewCustomGui::*GetFocusItem)();
	void					(iTreeViewCustomGui::*SetFocusItem)(void* pItem);
	const BaseContainer*	(iTreeViewCustomGui::*GetLayout)();
	void*					(iTreeViewCustomGui::*GetObject)(Int32 line, Int32 *level);
	void*					(iTreeViewCustomGui::*GetSelectionItem)();
	void					(iTreeViewCustomGui::*SetSelectionItem)(void* pItem);
	Bool					(iTreeViewCustomGui::*GetVisibleScrollArea)(Int32& x1, Int32& y1, Int32& x2, Int32& y2);
	Int32					(iTreeViewCustomGui::*GetVisibleLineCount)();
	Bool					(iTreeViewCustomGui::*SetVisibleScrollArea)(Int32 x1, Int32 y1, Int32 x2, Int32 y2);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LISTVIEW_H__
