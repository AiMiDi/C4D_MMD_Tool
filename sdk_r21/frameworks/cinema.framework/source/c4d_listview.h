/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_LISTVIEW_H__
#define C4D_LISTVIEW_H__

#ifndef __API_INTERN__
	#include "operatingsystem.h"
	#include "c4d_string.h"

class GeDialog;

/// @markInternal
inline void* _ReturnString(const maxon::String& v)
{
	iferr (String* cpy = NewObj(String))
		return nullptr;
	*cpy = v;
	return cpy;
}


/// @markInternal
struct MouseDownInfo
{
	Int32									xpos, ypos, width, height;
	Int32									line, col;

	Float									mx;
	Float									my;
	const BaseContainer*	msg;
};

/// @markInternal
#define ReturnLong(v)		{ res_type = LV_RES_INT; result = (void*)(Int)(v); return; }
/// @markInternal
#define ReturnBitmap(v)	{ res_type = LV_RES_BITMAP; result = (void*)(v); return; }
/// @markInternal
#define ReturnNull()		{ res_type = LV_RES_NIL; result = nullptr; return; }
/// @markInternal
#define ReturnString(v)	{ res_type = LV_RES_STRING; result = _ReturnString(v); return; }
/// @markInternal
#define ReturnVector(v)	{ res_type = LV_RES_VECTOR; result = _ReturnVector(v); return; }


//----------------------------------------------------------------------------------------
/// SimpleListView base class. Mostly internal.
//----------------------------------------------------------------------------------------
class GeListView
{
protected:
	_GeListView*	lv;
	GeDialog*			cd;

public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GeListView();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	virtual ~GeListView();

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	virtual void LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	Int LvCallBackLong(void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	void LvSuperCall(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col);

	//----------------------------------------------------------------------------------------
	/// Redraws the listview.
	//----------------------------------------------------------------------------------------
	void Redraw(void);

	//----------------------------------------------------------------------------------------
	/// Forces a recalculation. Called when the list view data has been changed.
	//----------------------------------------------------------------------------------------
	void DataChanged(void);

	//----------------------------------------------------------------------------------------
	/// Sends a message to the dialog.
	/// @param[in] msg								The message to send.
	/// @return												@trueIfOtherwiseFalse{the message could be sent}
	//----------------------------------------------------------------------------------------
	Bool SendParentMessage(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the list view.
	/// @return												The ID of the list view.
	//----------------------------------------------------------------------------------------
	Int32 GetId(void);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	Bool ExtractMouseInfo(void* secret, MouseDownInfo& info, Int32 size);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	Bool ExtractDrawInfo(void* secret, DrawInfo& info, Int32 size);

	//----------------------------------------------------------------------------------------
	/// Attaches the list view to a @link page_dialog_resource_LISTVIEW LISTVIEW@endlink control in a dialog.
	/// @param[in] cd									The dialog to attach to. @callerOwnsPointed{dialog}
	/// @param[in] id									The ID of the @link page_dialog_resource_LISTVIEW LISTVIEW@endlink control in the dialog.
	/// @return												@trueIfOtherwiseFalse{the listview was attached}
	//----------------------------------------------------------------------------------------
	Bool AttachListView(GeDialog* cd, Int32 id);

	//----------------------------------------------------------------------------------------
	/// Scrolls to the cell specified by @formatParam{line} and @formatParam{col}.
	/// @param[in] line								The line of the cell.
	/// @param[in] col								The column of the cell.
	//----------------------------------------------------------------------------------------
	void ShowCell(Int32 line, Int32 col);
};

/// @addtogroup SLV
/// @ingroup group_enumeration
/// @{
/// @see SimpleListView::SetProperty SimpleListView::GetProperty
#define SLV_MULTIPLESELECTION 1			///< Multiple selection allowed.
/// @}

//----------------------------------------------------------------------------------------
/// A class for simple list views. See @em ListView.cpp SDK example.
//----------------------------------------------------------------------------------------
class SimpleListView : public GeListView
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor. Creates the list view, but does not attach it to any dialog.
	/// @see GeListView::AttachListView
	//----------------------------------------------------------------------------------------
	SimpleListView();

	//----------------------------------------------------------------------------------------
	/// Destructor. Destroys the list view.
	//----------------------------------------------------------------------------------------
	virtual ~SimpleListView();

	//----------------------------------------------------------------------------------------
	/// Sets the current column layout.\n
	/// The data is layed out linearly in the supplied container, i.e. the order of the columns is specified by the order in which the items are added to the container.\n
	/// Each item in the container represents one column. The ID of the element is the column ID. The value of the item (of type ::Int32) should be one of the following:
	/// - LV_COLUMN_TEXT
	/// - LV_COLUMN_CHECKBOX
	/// - LV_COLUMN_BUTTON
	///
	/// Here is an example:
	/// @code
	/// #define COL_CHECK 'chck'
	/// #define COL_NAME 'name'
	/// #define COL_BUTTON 'bttn'
	/// BaseContainer layout;
	/// layout.SetInt32(COL_CHECK, LV_COLUMN_CHECKBOX);
	/// layout.SetInt32(COL_NAME, LV_COLUMN_TEXT);
	/// layout.SetInt32(COL_BUTTON, LV_COLUMN_BUTTON);
	/// listview.SetLayout(3, layout);
	/// @endcode
	/// @param[in] columns						The number of columns.
	/// @param[in] data								The column data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetLayout(Int32 columns, const BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// Sets the data for a list view line, inserting a new one if it is not found.\n
	/// The container should be filled with proper values for each column ID that needs to be changed/set.\n
	/// Here is an example:
	/// @code
	/// BaseContainer data;
	/// data.SetBool(COL_CHECK, obj.GetChecked());
	/// data.SetString(COL_NAME, obj.GetName());
	/// listview.SetItem(obj.GetID(), data);
	/// @endcode
	/// @param[in] id									The ID of the line.
	/// @param[in] data								The data for the line.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetItem(Int32 id, const BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for a list view line.
	/// @param[out] id								The ID of the line.
	/// @param[out] data							For each column of the line an item with the column ID is inserted into @formatParam{data}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetItem(Int32 id, BaseContainer* data);

	//----------------------------------------------------------------------------------------
	/// Gets the number of lines.
	/// @return												The number of lines in the list view.
	//----------------------------------------------------------------------------------------
	Int32 GetItemCount(void);

	//----------------------------------------------------------------------------------------
	/// Like GetItem(), but with the line number instead of line ID.
	/// @param[in] num								The number of the line.
	/// @param[out] id								Assigned the line ID.
	/// @param[out] data							For each column of the line an item with the column ID is inserted into @formatParam{data}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetItemLine(Int32 num, Int32* id, BaseContainer* data);

	//----------------------------------------------------------------------------------------
	/// Removes a line from the list view.
	/// @param[in] id									The ID of the line.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool RemoveItem(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Retrieves the current selection.
	/// @param[out] selection					Filled with the current selection. Multiple selections are possible (see @ref SLV_MULTIPLESELECTION). @callerOwnsPointed{container}
	/// @return												The number of selected items.
	//----------------------------------------------------------------------------------------
	Int32 GetSelection(BaseSelect* selection);

	//----------------------------------------------------------------------------------------
	/// Sets the current selection.
	/// @param[in] selection					The selection to set. Multiple selections are possible (see @ref SLV_MULTIPLESELECTION). @callerOwnsPointed{container}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetSelection(BaseSelect* selection);

	//----------------------------------------------------------------------------------------
	/// Retrieves a property for the list view.
	/// @param[in] id									The ID of the property: @enumerateEnum{SLV}
	/// @return												The property value.
	//----------------------------------------------------------------------------------------
	Int32 GetProperty(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Sets a property for the list view.
	/// @param[in] id									The ID of the property: @ref SLV_MULTIPLESELECTION.
	/// @param[in] val								The property value.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetProperty(Int32 id, Int32 val);

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	virtual void LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);

	//----------------------------------------------------------------------------------------
	/// Scrolls to the cell specified by @formatParam{line} and @formatParam{col}.
	/// @param[in] line								The line of the cell.
	/// @param[in] col								The column of the cell.
	//----------------------------------------------------------------------------------------
	void ShowCell(Int32 line, Int32 col);
};

#else

#include "c4d_gui.h"
#include "intbaselist.h"

#define GeListView			_GeListView
#define SimpleListView	_SimpleListView

#include "operatingsystem.h"
#include "baseselect.h"


class SimpleListNode;


struct MouseDownInfo
{
	Int32									xpos, ypos, width, height;
	Int32									line, col;

	Float									mx;
	Float									my;
	const BaseContainer*	msg;
};


#define ReturnLong(v)		{ res_type = LV_RES_INT; result = (void*)(Int)(v); return; }
#define ReturnBitmap(v)	{ res_type = LV_RES_BITMAP; result = (void*)(v); return; }
#define ReturnString(v)	{ res_type = LV_RES_STRING; result = (void*)NewObjClear(String, v); return; }
#define ReturnNull()		{ res_type = LV_RES_NIL; result = nullptr; return; }
#define ReturnVector(v)	{ res_type = LV_RES_VECTOR; result = (void*)NewObjClear(Vector, v); return; }


class GeListView
{
	friend class GeDialog;

private:
	CUserArea*				cu;
	ListViewCallBack*	callback;
	void*							userdata;

public:
	GeListView();
	virtual ~GeListView();

	virtual void LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);

	Int LvCallBackLong(void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);
	void LvSuperCall(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col);

	void Redraw(void);
	void DataChanged(void);
	void ShowCell(Int32 id, Int32 col);

	Bool SendParentMessage(BaseContainer* msg);
	Bool ExtractMouseInfo(void* secret, MouseDownInfo& info, Int32 size);
	Bool ExtractDrawInfo(void* secret, DrawInfo& info, Int32 size);
	Int32 GetId(void);

	Bool AttachListView(CDialog* cd, Int32 id, ListViewCallBack* callback = nullptr, void* userdata = nullptr);
};


class SimpleRoot : public GeListHead
{
public:
	Int32 GetCount(void);
	SimpleListNode* FindId(Int32 id);
	SimpleListNode* GetNumber(Int32 num);
	Int32 GetNumber(SimpleListNode* node);
};

#define SLV_MULTIPLESELECTION 1

class SimpleListView : public GeListView
{
	BaseSelect	select;
	Int32				focus;

	Int32				columns;
	Int32*			layout;
	Int32*			colidx;
	Bool				multipleselection;

	SimpleRoot	items;

public:
	SimpleListView();
	virtual ~SimpleListView();

	Bool SetLayout(Int32 columns, const BaseContainer& data);
	Bool SetItem(Int32 id, const BaseContainer& data);
	Bool GetItem(Int32 id, BaseContainer* data);
	Int32 GetItemCount(void);
	Bool GetItemLine(Int32 num, Int32* id, BaseContainer* data);

	Bool SetProperty(Int32 id, Int32 val);
	Int32 GetProperty(Int32 id);

	Bool RemoveItem(Int32 id);
	Int32 GetSelection(BaseSelect* selection);
	Bool SetSelection(BaseSelect* selection);
	void ShowCell(Int32 line, Int32 col);

	virtual void LvCallBack(Int32& res_type, void*& result, void* secret, Int32 cmd, Int32 line, Int32 col, void* data1);
};

#endif

#endif // C4D_LISTVIEW_H__
