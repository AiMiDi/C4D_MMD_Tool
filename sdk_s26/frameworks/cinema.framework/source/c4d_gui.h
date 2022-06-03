/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_GUI_H__
#define C4D_GUI_H__

#ifndef __API_INTERN__
	#include "c4d_basecontainer.h"
	#include "ge_math.h"
	#include "c4d_string.h"
	#include "gui.h"
	#define IDC_OK			1
	#define IDC_CANCEL	2
	#include "c4d_gedata.h"
	#include "c4d_thread.h"
#else
	#include "c4d_basecontainer.h"
	#include "ge_math.h"
	#include "ge_string.h"
	#include "gui_defs.h"
	#include "gui_newdialog.h"
	#include "c4d_basetime.h"
	#include "operatingsystem.h"
#endif

namespace maxon
{
class ImageBaseRef;
enum class IMAGEINTERPOLATIONMODE;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @addtogroup FORMAT_NUMBERS
/// @ingroup group_enumeration
/// @{
enum
{
	FORMAT_FLOAT		= 'frea',			///< Floating point without unit.
	FORMAT_INT			= 'flng',			///< Integer without unit.
	FORMAT_PERCENT	= 'fpct',			///< Floating point with @em % sign, @em 1.0 = @em 100%.
	FORMAT_DEGREE		= 'fdgr',			///< Floating point with @em degree sign. Measured in radians, displayed in degrees.
	FORMAT_METER		= 'fmet',			///< Floating point in the current working unit.
	FORMAT_FRAMES		= 'ffrm',			///< Time formatted as frames. (Overridden by user preference.)
	FORMAT_SECONDS	= 'fsec',			///< Time formatted as seconds. (Overridden by user preference.)
	FORMAT_SMPTE		= 'fsmp'			///< Time formatted as SMPTE. (Overridden by user preference.)
};
/// @}

class BaseBitmap;
class BaseContainer;
class GeResource;
class Filename;
class SubDialog;
class BaseDocument;
class GeDialog;
struct CUSTOMGUIPLUGIN;

typedef UChar OBSOLETE;

/// The first valid sub-menu item ID.
/// @see ShowPopupMenu
#define FIRST_POPUP_ID	(900000)

#define MENU_ALLOWSUBMENUCOMMAND (LIMIT<Int32>::MAX - 1)

/// The menu ID for a close menu item. Can be used in dialog menus.
#define IDM_CM_CLOSEWINDOW	12097

/// The default maximum time value. Equal to @em 1.0 hours at @em 30 fps i.e. about @em 2.77 hours.
#define MAXTIME	108000

/// @addtogroup COREMSG
/// @ingroup group_enumeration
/// @{
#define COREMSG_CINEMA_GETCOMMANDNAME				200000033			///< Returns the name of the command with ID specified by @ref COREMSG_CINEMA_GETCOMMANDNAME in @c msg.\n
																													/// The name is given as a String in the returned GeData.
#define COREMSG_CINEMA_GETCOMMANDENABLED		200000035			///< Checks if the command with ID specified by @ref COREMSG_CINEMA_GETCOMMANDENABLED in @c msg is enabled or disabled.\n
																													///< The state is given as a @formatConstant{true} or @formatConstant{false} integer value in the returned GeData.
#define COREMSG_CINEMA_GETCOMMANDCHECKED		300000115			///< Checks if the command with ID specified by @ref COREMSG_CINEMA_GETCOMMANDCHECKED in @c msg is checked or not.\n
																													///< The state is given as a @formatConstant{true} or @formatConstant{false} integer value in the returned GeData.
#define COREMSG_CINEMA_EXECUTEEDITORCOMMAND	200000023			///< Executes the command with ID specified by @ref COREMSG_CINEMA_EXECUTEEDITORCOMMAND in @c msg.\n
																													///< The result is given as a @formatConstant{true} or @formatConstant{false} integer value in the returned GeData.
#define COREMSG_CINEMA_EXECUTESUBID					300001036			///< Pass the sub-ID for @ref COREMSG_CINEMA_EXECUTEEDITORCOMMAND.
#define COREMSG_CINEMA_EXECUTEOPTIONMODE		300001037			///< Pass whether to open (@formatConstant{true}) the options dialog or not (@formatConstant{false}) for @ref COREMSG_CINEMA_EXECUTEEDITORCOMMAND.
#define COREMSG_CINEMA_GETCOMMANDHELP				200000234			///< Gets the help string of a command. Pass the command's ID.\n
																													///< The help is given as a String in the returned GeData.

#define COREMSG_CINEMA_FORCE_AM_UPDATE	1001077				///< Forces an Attribute Manager update.
#define COREMSG_UPDATECOMMANDSMESSAGE		200000100			///< @markPrivate
/// @}

#define C4DGUIPTR						(-1)	///< ID used for GadgetPtr when initialized with a gadget pointer.
#define C4DGUINOPTR					(-2)	///< ID used for GadgetPtr when not initialized with a gadget pointer.
#define C4DGUISCROLLPARENT	(-3)	///< ID used for parent GadgetPtr when retrieving the dimensions of the Dialog within a scrollgroup.
#define C4DGUIWINDOWID			(-4)	///< ID used for GadgetPtr when querying the size of the window with GetItemDim().

//----------------------------------------------------------------------------------------
/// Represents a gadget in a dialog.
//----------------------------------------------------------------------------------------
class C4DGadget
{
public:
};

//----------------------------------------------------------------------------------------
/// An ID class for dialog gadgets. Can either be initialized with a gadget ID or pointer.\n
/// Most of the time it is not needed to create this object manually, but can rely on the temporary generated by the compiler:
/// @code
/// C4DGadget* ptr = dlg.AddStaticText(123, ...); // Generates GadgetPtr(123)
/// String temp;
/// dlg.GetString(ptr, temp); // Generates GadgetPtr(ptr)
/// dlg.GetString(123, temp); // Generates GadgetPtr(123)
/// @endcode
//----------------------------------------------------------------------------------------
class GadgetPtr
{
	Int32 _id;
	C4DGadget* gad;

public:
	//----------------------------------------------------------------------------------------
	/// Creates a gadget pointer from an ID.
	/// @param[in] t_id								The ID.
	//----------------------------------------------------------------------------------------
	GadgetPtr(Int32 t_id) { _id = t_id; gad = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Creates a gadget pointer from a pointer.
	/// @param[in] t_gad							The gadget pointer.
	//----------------------------------------------------------------------------------------
	GadgetPtr(C4DGadget* t_gad) { _id = C4DGUIPTR; gad = t_gad; }

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the gadget pointer.
	/// @return												The gadget ID.
	//----------------------------------------------------------------------------------------
	Int32 Id() const { return _id; };

	//----------------------------------------------------------------------------------------
	/// Gets the gadget pointer.
	/// @return												The gadget pointer.
	//----------------------------------------------------------------------------------------
	C4DGadget* Ptr() const { return gad; }
};

//----------------------------------------------------------------------------------------
/// A class that can be used to create custom GUI components.\n
/// There are already dozens of predefined buttons in the GUI easy available. But if one wants to make his own button, one needs to use the GeUserArea class.\n
/// Every user area has a specified drawing area and several commands for drawing lines or text. So it is possible to developer whatever needed, either a 3D trackball or a tree like object manager.
///
/// The message sequence when the user area is created:
/// 1. Init() (only once)\n
/// 2. GetMinSize()\n
/// 3. Sized()\n
/// 4. InitValues()\n
/// 5. DrawMsg()\n
///
/// The message sequence if the user area is scaled:
/// 1. Sized()\n
/// 2. DrawMsg()\n
///
/// Does not require special allocation, but must be attached to a dialog with GeDialog::AttachUserArea().
//----------------------------------------------------------------------------------------
class GeUserArea
{
	friend class GeDialog;

	MAXON_DISALLOW_COPY_AND_ASSIGN(GeUserArea);

private:
	Bool owncu;
	CUserArea* cu;

protected:
	/// If the user area is attached to a dialog this points to the dialog, otherwise @formatConstant{nullptr}. Can be used by derived classes.
	GeDialog* dlg;

public:
/// @addtogroup DRAWTEXT
/// @ingroup group_enumeration
/// @{
#define DRAWTEXT_HALIGN_LEFT		0							///< Align to the left.
#define DRAWTEXT_HALIGN_CENTER	1							///< Center horizontally.
#define DRAWTEXT_HALIGN_RIGHT		2							///< Align to the right.
#define DRAWTEXT_HALIGN_MASK		0x000f				///< Horizontal alignment mask.
#define DRAWTEXT_VALIGN_TOP			(0 << 4)			///< Align to the top.
#define DRAWTEXT_VALIGN_CENTER	(1 << 4)			///< Center vertically.
#define DRAWTEXT_VALIGN_BOTTOM	(2 << 4)			///< Align to the bottom.
#define DRAWTEXT_VALIGN_MASK		0x00f0				///< Vertical alignment mask.
#define DRAWTEXT_STD_ALIGN			(DRAWTEXT_HALIGN_LEFT | DRAWTEXT_VALIGN_TOP)			///< Standard alignment (top-left).
/// @}

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Constructs a user area that is not attached to any dialog.
	/// @note The user area must be attached to a dialog with GeDialog::AttachUserArea() before it can be used.
	//----------------------------------------------------------------------------------------
	GeUserArea(void);

	//----------------------------------------------------------------------------------------
	/// Destroys the user area.
	//----------------------------------------------------------------------------------------
	virtual ~GeUserArea(void);

	/// @}

	/// @name Internal Representation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the internal representation of the user area.\n
	/// Needed by some areas in the API for historical reasons.
	/// @return												The internal user area representation. @formatConstant{nullptr} if the user area is not attached to a dialog.
	//----------------------------------------------------------------------------------------
	CUserArea* Get() { return cu; }

	//----------------------------------------------------------------------------------------
	/// Sets the internal representation of the user area.\n
	/// Needed by some areas in the API for historical reasons.
	/// @param[in] t_cu								An internal user area representation.
	//----------------------------------------------------------------------------------------
	void Set(CUserArea* t_cu) { cu = t_cu; owncu = true; }

	/// @}

	/// @name Parent Dialog
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the user area's parent dialog.
	/// @return												The pointer to the user area's parent dialog.
	//----------------------------------------------------------------------------------------
	GeDialog* GetDialog(void) { return dlg; }

	/// @}

	/// @name Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called once when the user area is initialized by the GUI, before the layout is calculated.\n
	/// Override this function to initialize anything.
	/// @return												@formatConstant{true} if successful, or @formatConstant{false} to signalize an error.
	//----------------------------------------------------------------------------------------
	virtual Bool Init(void);

	//----------------------------------------------------------------------------------------
	/// Called after the layout is calculated, before the user area is drawn.\n
	/// Override this function to initialize anything.
	/// @return												@formatConstant{true} if successful, or @formatConstant{false} to signalize an error.
	//----------------------------------------------------------------------------------------
	virtual Bool InitValues(void);

	//----------------------------------------------------------------------------------------
	/// Called to specify a minimum size for the user area.\n
	/// Override this function to set the minimum size of the user area to @formatParam{w} and @formatParam{h}.
	/// @param[in] w									Assign the minimum width in pixels.
	/// @param[in] h									Assign the minimum height in pixels.
	/// @return												@formatConstant{true} if successful, or @formatConstant{false} to signalize an error.
	//----------------------------------------------------------------------------------------
	virtual Bool GetMinSize(Int32& w, Int32& h);

	//----------------------------------------------------------------------------------------
	/// Called when the user area is resized.\n
	/// Override this function to update anything.
	/// @param[in] w									The new width in pixels.
	/// @param[in] h									The new height in pixels.
	//----------------------------------------------------------------------------------------
	virtual void Sized(Int32 w, Int32 h);

	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	//----------------------------------------------------------------------------------------
	virtual OBSOLETE Draw(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

	//----------------------------------------------------------------------------------------
	/// Called to draw the user area.\n
	/// Use the drawing functions to update the user area in the region specified by the rectangle from (@em x1, @em y1) to (@em x2, @em y2).\n
	/// Remember to use @ref OffScreenOn() to avoid flickering.
	/// @param[in] x1									The upper left X coordinate.
	/// @param[in] y1									The upper left Y coordinate.
	/// @param[in] x2									The lower right X coordinate.
	/// @param[in] y2									The lower right Y coordinate.
	/// @param[in] msg								The draw container.
	//----------------------------------------------------------------------------------------
	virtual void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when an input event is received.\n
	/// The information about the input event is stored in the @formatParam{msg} container. See @link page_input_events Input Events@endlink for more information.
	/// @see MOUSEMOVE_DELTA.
	/// @param[in] msg								The event container.
	/// @return												@trueIfOtherwiseFalse{the event was handled}
	//----------------------------------------------------------------------------------------
	virtual Bool InputEvent(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when a core message is received.\n
	/// The message type is given by @formatParam{id} and the message information is stored in @formatParam{msg}.
	/// @see The article @link page_manual_coremessages Core Messages@endlink for more information.
	/// @param[in] id									The message type: @enumerateEnum{EVMSG}
	/// @param[in] msg								The core message container.
	/// @return												Currently not used.
	//----------------------------------------------------------------------------------------
	virtual Bool CoreMessage(Int32 id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when a timer event is received.\n
	/// To subscribe to timer events use SetTimer().
	/// @param[in] msg								The timer message container.
	//----------------------------------------------------------------------------------------
	virtual void Timer(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to more messages than covered by the other virtual functions. Normally this is not necessary.
	/// @note If overriden, include a call to the base version of this function, GeUserArea::Message().
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	/// @}

	/// @name Basic Functions
	/// @{

	//----------------------------------------------------------------------------------------
	/// Forces the user area to redraw itself.
	/// @param[in] threaded						Must be set to @formatConstant{true} if the function is called from another thread than the main @C4D thread.
	//----------------------------------------------------------------------------------------
	void Redraw(Bool threaded = false);

	//----------------------------------------------------------------------------------------
	/// Sends a custom message to the parent dialog.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SendParentMessage(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Sends a custom message to the parent dialog.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @return												returns the result of the message
	//----------------------------------------------------------------------------------------
	GeData SendParentMessageResult(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the user area.
	/// @return												The user area ID.
	//----------------------------------------------------------------------------------------
	Int32 GetId() const;

	//----------------------------------------------------------------------------------------
	/// Gets the width in pixels of the user area.
	/// @return												The user area's width.
	//----------------------------------------------------------------------------------------
	Int32 GetWidth() const;

	//----------------------------------------------------------------------------------------
	/// Gets the height in pixels of the user area.
	/// @return												The user area's height.
	//----------------------------------------------------------------------------------------
	Int32 GetHeight() const;

	//----------------------------------------------------------------------------------------
	/// Checks the enabled state of the user area.
	/// @return												@trueIfOtherwiseFalse{the user area is enabled in the dialog}
	//----------------------------------------------------------------------------------------
	Bool IsEnabled() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the user area has to be drawn in right-to-left layout mode.
	/// @return												@trueIfOtherwiseFalse{the user area is in right-to-left layout mode}
	//----------------------------------------------------------------------------------------
	Bool IsR2L() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the user area has the focus.
	/// @return												@trueIfOtherwiseFalse{the user area has the focus in the dialog}
	//----------------------------------------------------------------------------------------
	Bool HasFocus() const;

	//----------------------------------------------------------------------------------------
	/// Tells @C4D that the user area has new dimensions. That causes @C4D to call:
	/// 1. GetMinSize()\n
	/// 2. Sized()\n
	/// 3. InitValues()\n
	/// 4. Draw()\n
	///
	/// The dialog's layout is recalculated in this process.
	//----------------------------------------------------------------------------------------
	void LayoutChanged(void);

	//----------------------------------------------------------------------------------------
	/// Initializes the timer clock, so that Timer() is called every @formatParam{timer} milliseconds. Use @link SetTimer SetTimer(0)@endlink to stop the timer.
	/// @note Depending on the speed of the computer, the operating system, the complexity of the dialog and the threads running in the background, there is no guarantee that event messages will occur on a regular basis.\n
	/// Using a value of @em 500 ms should be no problem but using a value of 1 ms one might get events with the following time spaces: @em 3 ms, @em 76 ms, @em 15 ms, @em 19 ms, @em 67 ms etc.
	/// @warning Keep in mind that using small timer values results in heavy message traffic in the application which may slow down @C4D (and all other applications running on the computer) to a point where nothing is working any longer besides the dialog.
	/// @param[in] timer							The timer interval in milliseconds. Pass @em 0 to stop the timer.
	//----------------------------------------------------------------------------------------
	void SetTimer(Int32 timer);

	/// @}

	/// @name Input
	/// @{

	//----------------------------------------------------------------------------------------
	/// Polls a certain channel of a device for the current input state.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to ask.
	/// @param[in] askchannel					The channel of the device.
	/// @param[in] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input state could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res) const;

	//----------------------------------------------------------------------------------------
	/// Gets the next input event for a certain device from the event queue.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to poll.
	/// @param[in] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input event could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInputEvent(Int32 askdevice, BaseContainer& res) const;

	//----------------------------------------------------------------------------------------
	/// Flushes all events from the window message queue.\n
	/// For example if looping while the mouse is down (polling), call this function to flush all key downs/mouse clicks that are made during the loop.
	//----------------------------------------------------------------------------------------
	void KillEvents(void);

	//----------------------------------------------------------------------------------------
	/// Checks the standard navigation hotkeys.
	/// @param[in] id									The hotkey to check: @enumerateEnum{HOTKEY}
	/// @return												A value != 0 if the hotkey is pressed.
	//----------------------------------------------------------------------------------------
	HOTKEYFLAGS IsHotkeyDown(Int32 id) const;

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the draw color.
	/// @param[in] color							A color vector.
	//----------------------------------------------------------------------------------------
	void DrawSetPen(const Vector& color);

	//----------------------------------------------------------------------------------------
	/// Sets the draw color.
	/// @param[in] id									A color constant: @enumerateEnum{COLOR}
	//----------------------------------------------------------------------------------------
	void DrawSetPen(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Set the draw color.
	/// @param[in] d									A color data. Can be either a color vector or a color constant in the GeData.
	//----------------------------------------------------------------------------------------
	void DrawSetPen(const GeData& d);

	//----------------------------------------------------------------------------------------
	/// Sets the opacity value.
	/// @param[in] opacity						The opacity.
	//----------------------------------------------------------------------------------------
	void DrawSetOpacity(Float opacity);

	//----------------------------------------------------------------------------------------
	/// Sets the text foreground and background color.
	/// @param[in] fg									A color constant for the foreground: @enumerateEnum{COLOR}
	/// @param[in] bg									A color constant for the background: @enumerateEnum{COLOR}
	//----------------------------------------------------------------------------------------
	void DrawSetTextCol(Int32 fg, Int32 bg);

	//----------------------------------------------------------------------------------------
	/// Sets the text foreground and background color.
	/// @param[in] fg									A color vector for the foreground.
	/// @param[in] bg									A color constant for the background: @enumerateEnum{COLOR}
	//----------------------------------------------------------------------------------------
	void DrawSetTextCol(const Vector& fg, Int32 bg);

	//----------------------------------------------------------------------------------------
	/// Sets the text foreground and background color.
	/// @param[in] fg									A color constant for the foreground: @enumerateEnum{COLOR}
	/// @param[in] bg									A color vector for the background.
	//----------------------------------------------------------------------------------------
	void DrawSetTextCol(Int32 fg, const Vector& bg);

	//----------------------------------------------------------------------------------------
	/// Sets the text foreground and background color.
	/// @param[in] fg									A color vector for the foreground.
	/// @param[in] bg									A color vector for the background.
	//----------------------------------------------------------------------------------------
	void DrawSetTextCol(const Vector& fg, const Vector& bg);

	//----------------------------------------------------------------------------------------
	/// Sets the text foreground and background color.
	/// @param[in] fg									A color data for the foreground. Can be either a color vector or a color ID.
	/// @param[in] bg									A color data for the background. Can be either a color vector or a color ID.
	//----------------------------------------------------------------------------------------
	void DrawSetTextCol(const GeData& fg, const GeData& bg);

	//----------------------------------------------------------------------------------------
	/// Gets the RGB values associated with a color constant.
	/// @param[in] colorid						A color constant: @enumerateEnum{COLOR}
	/// @param[out] r									Assigned the red component of the color.
	/// @param[out] g									Assigned the green component of the color.
	/// @param[out] b									Assigned the blue component of the color.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetColorRGB(Int32 colorid, Int32& r, Int32& g, Int32& b) const;

	//----------------------------------------------------------------------------------------
	/// Activates the fading.
	/// @param[in] milliseconds				The time for the fading in milliseconds.
	//----------------------------------------------------------------------------------------
	void ActivateFading(Int32 milliseconds);

	//----------------------------------------------------------------------------------------
	/// Sets the blend colors for user area fading.
	/// @param[in] colorid						A color constant to fade from: @enumerateEnum{COLOR}
	/// @param[in] highlightid				A color constant to fade to: @enumerateEnum{COLOR}
	/// @param[in] percent						A fading percentage.
	//----------------------------------------------------------------------------------------
	void AdjustColor(Int32 colorid, Int32 highlightid, Float percent);

	//----------------------------------------------------------------------------------------
	/// Draws a line with the current pen color between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
	/// @param[in] x1									The X start coordinate.
	/// @param[in] y1									The Y start coordinate.
	/// @param[in] x2									The X end coordinate.
	/// @param[in] y2									The Y end coordinate.
	//----------------------------------------------------------------------------------------
	void DrawLine(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Float lineWidth = 1.0, LINESTYLE lineStyle = LINESTYLE::NORMAL);

	//----------------------------------------------------------------------------------------
	/// Draws a rectangular frame with the current pen color between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
	/// @param[in] x1									The X coordinate of the first corner.
	/// @param[in] y1									The Y coordinate of the first corner.
	/// @param[in] x2									The X coordinate of the opposite corner.
	/// @param[in] y2									The Y coordinate of the opposite corner.
	/// @param[in] lineWidth					Line width to draw the line.
	//----------------------------------------------------------------------------------------
	void DrawFrame(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Float lineWidth = 1.0, LINESTYLE lineStyle = LINESTYLE::NORMAL);

	//----------------------------------------------------------------------------------------
	/// Fills a rectangular area with the current pen color between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
	/// @param[in] x1									The X coordinate of the first corner.
	/// @param[in] y1									The Y coordinate of the first corner.
	/// @param[in] x2									The X coordinate of the opposite corner.
	/// @param[in] y2									The Y coordinate of the opposite corner.
	//----------------------------------------------------------------------------------------
	void DrawRectangle(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

	//----------------------------------------------------------------------------------------
	/// Draws a bitmap into the user area.\n
	/// The region (@formatParam{x},@formatParam{y}) to (@formatParam{x}+@formatParam{w},@formatParam{y}+@formatParam{h}) from the bitmap will be scaled and transformed into the region (@formatParam{wx},@formatParam{wy}) to (@formatParam{wx}+@formatParam{ww},@formatParam{wy}+@formatParam{wh}) of the destination area.
	/// @note ::BMP_ALLOWALPHA can be combined with the other @ref BMP modes for parameter @formatParam{mode}.
	/// @param[in] bmp								The bitmap to draw. @callerOwnsPointed{bitmap}
	/// @param[in] wx									The X coordinate of the upper left corner of the destination area.
	/// @param[in] wy									The Y coordinate of the upper left corner of the destination area.
	/// @param[in] ww									The width of the destination area.
	/// @param[in] wh									The height of the destination area.
	/// @param[in] x									The X coordinate of the upper left corner of the bitmap area.
	/// @param[in] y									The Y coordinate of the upper left corner of the bitmap area.
	/// @param[in] w									The width of the bitmap area.
	/// @param[in] h									The height of the bitmap area.
	/// @param[in] mode								Can be a combination of the following flags: @enumerateEnum{BMP}
	//----------------------------------------------------------------------------------------
	void DrawBitmap(BaseBitmap* bmp, Int32 wx, Int32 wy, Int32 ww, Int32 wh, Int32 x, Int32 y, Int32 w, Int32 h, Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Draws a image into the user area.
	/// @param[in] imageRef						ImageRef to draw.
	/// @param[in] wx									The X coordinate of the upper left corner of the destination area.
	/// @param[in] wy									The Y coordinate of the upper left corner of the destination area.
	/// @param[in] ww									The width of the destination area.
	/// @param[in] wh									The height of the destination area.
	/// @param[in] opacity						Opacity to draw with (0.0 == completely transparent, 1.0 == fully opaque).
	//----------------------------------------------------------------------------------------
	void DrawImageRef(maxon::ImageBaseRef& imageRef, Float wx, Float wy, Float ww, Float wh, Float opacity, maxon::IMAGEINTERPOLATIONMODE mode);

	//----------------------------------------------------------------------------------------
	/// Draws the string txt with the upper left corner at the position (@formatParam{x},@formatParam{y}).
	/// @note Use @ref DrawGetTextWidth and @ref DrawGetFontHeight to find out where to place the text.
	/// @param[in] txt								The text to draw.
	/// @param[in] x									The X coordinate of the upper left corner for the text to draw.
	/// @param[in] y									The Y coordinate of the upper left corner for the text to draw.
	/// @param[in] flags							The draw text flags: @enumerateEnum{DRAWTEXT}
	//----------------------------------------------------------------------------------------
	void DrawText(const maxon::String& txt, Int32 x, Int32 y, Int32 flags = DRAWTEXT_STD_ALIGN);

	//----------------------------------------------------------------------------------------
	/// Draws concatenated Bezier curves.
	/// @param[in] startPoint					The XY coordinate of the upper left corner of the drawn curve.
	/// @param[in] bezierPoints				An array containing a struct of Bezier curves points.\n
	/// @param[in] closed							If @formatConstant{true}, the last point of the last segment connects back to the starting point (@formatParam{startPoint}).
	/// @param[in] lineWidth					The width of the Bezier curve. Default 1.0.
	/// @param[in] lineStyle          The line style of the Bezier curve.
	//----------------------------------------------------------------------------------------
	void DrawBezierLine(const Vector2d& startPoint, const maxon::Block<const BezierPoint>& bezierPoints, Bool closed, Float lineWidth = 1.0, LINESTYLE lineStyle = LINESTYLE::NORMAL);
	void DrawBezierFill(const Vector2d& startPoint, const maxon::Block<const BezierPoint>& bezierPoints, Bool closed);

	void DrawPolyLine(const maxon::Block<const Vector2d>& p, Bool closed, Float lineWidth = 1.0, LINESTYLE lineStyle = LINESTYLE::NORMAL);
	void DrawPolyFill(const maxon::Block<const Vector2d>& p, Bool closed);

	void DrawEllipseLine(const Vector2d& centerPoint, const Vector2d& radius, Float lineWidth = 1.0, LINESTYLE lineStyle = LINESTYLE::NORMAL);
	void DrawEllipseFill(const Vector2d& centerPoint, const Vector2d& radius);
	
	void DrawCustomButton(Int32 x, Int32 y, Int32 w, Int32 h, const Int32* ids, Bool nofill, Bool focus);

	//----------------------------------------------------------------------------------------
	/// Fills a bitmap with the current pen color.\n
	/// @note The @formatParam{offsetx} and @formatParam{offsety} parameters are used when the background is a pattern and are given in local coordinates of the user area. These can be used to make semi-transparent bitmap blits.
	/// @param[in] bmp								The bitmap to fill. @callerOwnsPointed{bitmap}
	/// @param[in] offsetx						The X offset in pixels.
	/// @param[in] offsety						The Y offset in pixels.
	//----------------------------------------------------------------------------------------
	void FillBitmapBackground(BaseBitmap* bmp, Int32 offsetx, Int32 offsety);

	//----------------------------------------------------------------------------------------
	/// Sets the text font.
	/// @param[in] fontid							The font to use: @enumerateEnum{FONT}
	//----------------------------------------------------------------------------------------
	void DrawSetFont(Int32 fontid);

	//----------------------------------------------------------------------------------------
	/// Retrieves the width in pixels of @formatParam{text}, if it were drawn in the current font.
	/// @param[in] text								The string to measure.
	/// @return												The text width in pixels.
	//----------------------------------------------------------------------------------------
	Int32 DrawGetTextWidth(const maxon::String& text) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the width in pixels of the name of @formatParam{node}.
	/// @param[in] node								The node to check.
	/// @param[in] fontid							The font: @enumerateEnum{FONT}
	/// @return												The text width in pixels.
	//----------------------------------------------------------------------------------------
	Int32 DrawGetTextWidth_ListNodeName(BaseList2D* node, Int32 fontid = FONT_STANDARD) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the height in pixels of a line of text in the current font.
	/// @return												The height in pixels.
	//----------------------------------------------------------------------------------------
	Int32 DrawGetFontHeight() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the base line of the current font.
	/// @return												The base line of the current font.
	//----------------------------------------------------------------------------------------
	Int32 DrawGetFontBaseLine() const;

	//----------------------------------------------------------------------------------------
	/// Rotates the font for drawing.
	/// @note Rotation is clockwise and must be reset to @em 0 after drawing.
	/// @param[in] textrotation				The text rotation in degree.
	//----------------------------------------------------------------------------------------
	void DrawSetTextRotation(Float textrotation);

	/// @}

	/// @name Clipping
	/// @{

	//----------------------------------------------------------------------------------------
	/// Specifies the clipping region for the @c Draw() functions.
	/// @note The clipping region can be set to the whole user area with @ref OffScreenOn automatically, so normally this function is not necessary.
	/// @warning Without specifying a dedicated clipping region everything will be painted, even outside the user area.
	/// @param[in] x									The X coordinate of the upper left corner of the clipping region.
	/// @param[in] y									The Y coordinate of the upper left corner of the clipping region.
	/// @param[in] w									The width of the clipping region.
	/// @param[in] h									The height of the clipping region.
	//----------------------------------------------------------------------------------------
	void SetClippingRegion(Int32 x, Int32 y, Int32 w, Int32 h);

	//----------------------------------------------------------------------------------------
	/// Clears any clipping region set with @ref SetClippingRegion.
	//----------------------------------------------------------------------------------------
	void ClearClippingRegion(void);

	//----------------------------------------------------------------------------------------
	/// Enables double buffering to avoid blinking and flickering effects. Automatically sets the clipping area to the whole user area.\n
	/// The GUI will automatically switch planes. Just call this function before drawing things.
	/// @return												@trueIfOtherwiseFalse{double buffering could be enabled}
	//----------------------------------------------------------------------------------------
	Bool OffScreenOn(void);

	//----------------------------------------------------------------------------------------
	/// Enables double buffering to avoid blinking and flickering effects. Sets the clipping area to the rectangular area determined by @formatParam{x}, @formatParam{y}, @formatParam{w} and @formatParam{h}.
	/// @param[in] x									The X coordinate of the upper left corner of the clipping area.
	/// @param[in] y									The Y coordinate of the upper left corner of the clipping area.
	/// @param[in] w									The width of the clipping area.
	/// @param[in] h									The height of the clipping area.
	/// @return												@trueIfOtherwiseFalse{double buffering could be enabled}
	//----------------------------------------------------------------------------------------
	Bool OffScreenOn(Int32 x, Int32 y, Int32 w, Int32 h);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Scrolls the area from (@formatParam{x},@formatParam{y}) to (@formatParam{x}+@formatParam{w},@formatParam{y}+@formatParam{h}) in the direction specified by @formatParam{xdiff} and @formatParam{ydiff}.
	/// @param[in] xdiff							The X distance to scroll.
	/// @param[in] ydiff							The Y distance to scroll.
	/// @param[in] x									The X coordinate of the upper left corner of the area to scroll.
	/// @param[in] y									The Y coordinate of the upper left corner of the area to scroll.
	/// @param[in] w									The width of the area to scroll.
	/// @param[in] h									The height of the area to scroll.
	//----------------------------------------------------------------------------------------
	void ScrollArea(Int32 xdiff, Int32 ydiff, Int32 x, Int32 y, Int32 w, Int32 h);

	//----------------------------------------------------------------------------------------
	/// @markPrivate Always returns @em 1.0 except for user areas shown on OS X Retina displays, where it returns @em 2.0.
	/// @return												Always @em 1.0 except for user areas shown on OS X Retina displays.
	//----------------------------------------------------------------------------------------
	Float GetPixelRatio() const;

	/// @}

	/// @name Coordinates Transformation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of the user area) to global window coordinates (relative to the top left corner of the application window). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the global window coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the global window coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Global(Int32* x, Int32* y) const;
	Bool Local2Global(Float& x, Float& y) const;

	//----------------------------------------------------------------------------------------
	/// Transforms global window coordinates (relative to the top left corner of the application window) to local coordinates (relative to the top left corner of the user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The global window X coordinate. Assigned the local coordinate.
	/// @param[in,out] y							The global window Y coordinate. Assigned the local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Global2Local(Int32* x, Int32* y) const;
	Bool Global2Local(Float& x, Float& y) const;

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of the user area) to screen coordinates (relative to the top left corner of the system screen). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the screen coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the screen coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Screen(Int32* x, Int32* y) const;
	Bool Local2Screen(Float& x, Float& y) const;

	//----------------------------------------------------------------------------------------
	/// Transforms screen coordinates (relative to the top left corner of the system screen) to local coordinates (relative to the top left corner of the user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The screen X coordinate. Assigned the converted local coordinate.
	/// @param[in,out] y							The screen Y coordinate. Assigned the converted local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Screen2Local(Int32* x, Int32* y) const;
	Bool Screen2Local(Float& x, Float& y) const;

	/// @}

	/// @name Drag and Drop
	/// @{

	//----------------------------------------------------------------------------------------
	/// Extracts local drag coordinates from a drag and drop event. Stores the result in *@formatParam{x} and *@formatParam{y}.\n
	/// @see The article @link page_manual_geuserarea_interaction Drag and Drop@endlink for more information.
	/// @param[in] msg								The original message.
	/// @param[out] x									Assigned the local X position.
	/// @param[out] y									Assigned the local Y position.
	/// @return												@trueIfOtherwiseFalse{the drag position was extracted}
	//----------------------------------------------------------------------------------------
	Bool GetDragPosition(const BaseContainer& msg, Int32* x, Int32* y) const;

	//----------------------------------------------------------------------------------------
	/// Extracts the object from a drag and drop message. Stores the result in *@formatParam{type} and *@formatParam{object}.\n
	/// @see The article @link page_manual_geuserarea_interaction Drag and Drop@endlink for more information.
	/// @param[in] msg								The original message.
	/// @param[out] type							Assigned the type of the object.
	/// @param[out] object						Assigned a pointer to the object. @cinemaOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the drag object was extracted}
	//----------------------------------------------------------------------------------------
	Bool GetDragObject(const BaseContainer& msg, Int32* type, void** object) const;

	//----------------------------------------------------------------------------------------
	/// Starts a drag and drop operation.\n
	/// @see The article @link page_manual_geuserarea_interaction Drag and Drop@endlink for more information.
	/// @param[in] msg								The mouse event message that triggered the drag and drop.
	/// @param[in] type								The type of data passed: @link DRAGTYPE_FILES DRAGTYPE@endlink
	/// @param[in] data								A pointer to the data passed.
	/// @param[in] dragflags					The drag flags. @markPrivate
	/// @return												@formatConstant{true} if the user moved the mouse and a drag and drop operation was initiated.\n
	///																@formatConstant{false} if the user did not move the mouse, so that the original event is a normal mouse click event.
	//----------------------------------------------------------------------------------------
	Bool HandleMouseDrag(const BaseContainer& msg, Int32 type, void* data, Int32 dragflags);

	//----------------------------------------------------------------------------------------
	/// Sets the correct cursor during drag and drop handling.\n
	/// @see The article @link page_manual_geuserarea_interaction Drag and Drop@endlink for more information.
	/// @param[in] cursor							A mouse cursor: @enumerateEnum{MOUSE}
	/// @return												@trueIfOtherwiseFalse{the cursor could be set}
	//----------------------------------------------------------------------------------------
	Bool SetDragDestination(Int32 cursor);

	/// @}

	/// @name Border
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the space required to draw a border.
	/// @param[in] type								The border type: @enumerateEnum{BORDER}
	/// @param[out] l									Assigned the space to the left.
	/// @param[out] t									Assigned the space on the top.
	/// @param[out] r									Assigned the space to the right.
	/// @param[out] b									Assigned the space on the bottom.
	//----------------------------------------------------------------------------------------
	void GetBorderSize(Int32 type, Int32* l, Int32* t, Int32* r, Int32* b) const;

	//----------------------------------------------------------------------------------------
	/// Draws a border within the rectangle from (@formatParam{x1},@formatParam{y1}) to (@formatParam{x2},@formatParam{y2}).
	/// @param[in] type								The border type: @enumerateEnum{BORDER}
	/// @param[in] x1									The X coordinate of the first corner.
	/// @param[in] y1									The Y coordinate of the first corner.
	/// @param[in] x2									The X coordinate of the opposite corner.
	/// @param[in] y2									The Y coordinate of the opposite corner.
	//----------------------------------------------------------------------------------------
	void DrawBorder(Int32 type, Int32 x1, Int32 y1, Int32 x2, Int32 y2);

	//----------------------------------------------------------------------------------------
	/// Checks the drag position in a drag event message against the user area's position in the layout. The check can be limited to only @em X or @em Y coordinates.
	/// @param[in] msg								The drag message.
	/// @param[in] horiz							If @formatConstant{true} the drag position is checked against the horizontal bounds of the region.
	/// @param[in] vert								If @formatConstant{true} the drag position is checked against the vertical bounds of the region.
	/// @return												@trueIfOtherwiseFalse{the drag message is within the bounds specified}
	//----------------------------------------------------------------------------------------
	Bool CheckDropArea(const BaseContainer& msg, Bool horiz, Bool vert) const;

	/// @}

#ifdef __API_INTERN__
	Bool OpenPopUpMenu(Int32 menuid, Int32 localx, Int32 localy, Int32 watchhotkey);
#endif

	/// @name Mouse Drag
	/// @{

	//----------------------------------------------------------------------------------------
	/// Starts a mouse drag. Only call this when a mouse down message is received. Then repeatedly poll with @ref MouseDrag during the drag.
	/// @param[in] button							The mouse button that is pressed: @enumerateEnum{BFM_INPUT_CHANNEL}
	/// @param[in] mx									The X position of the mouse.
	/// @param[in] my									The Y position of the mouse.
	/// @param[in] flag								The mouse drag flags: @enumerateEnum{MOUSEDRAGFLAGS}
	//----------------------------------------------------------------------------------------
	void MouseDragStart(Int32 button, Float mx, Float my, MOUSEDRAGFLAGS flag);

	//----------------------------------------------------------------------------------------
	/// Polls the mouse during a drag started with @ref MouseDragStart.\n
	/// To check for qualifiers see the @formatParam{channels} container:
	/// @code
	/// 	while (MouseDrag(&dx, &dy, &channels)==MOUSEDRAGRESULT::CONTINUE)
	/// 	{
	/// 		if (channels.GetInt32(BFM_INPUT_QUALIFIER) & QSHIFT) shift = true;
	/// 		if (channels.GetInt32(BFM_INPUT_QUALIFIER) & QCTRL) ctrl = true;
	/// 		...
	/// 		}
	/// @endcode
	/// @param[out] mx								Assigned the X delta-coordinate of the mouse (the amount the mouse has moved).
	/// @param[out] my								Assigned the Y delta-coordinate of the mouse (the amount the mouse has moved).
	/// @param[out] channels					Assigned the channels values. See @link page_input_events Input Events@endlink.\n
	///																Also contains these @ref PEN values: @enumerateEnum{PEN}
	/// @return												The mouse drag result: @enumerateEnum{MOUSEDRAGRESULT}
	//----------------------------------------------------------------------------------------
	MOUSEDRAGRESULT MouseDrag(Float* mx, Float* my, BaseContainer* channels);

	//----------------------------------------------------------------------------------------
	/// Ends a mouse drag started with @ref MouseDragStart.
	/// @return												The mouse drag result: @enumerateEnum{MOUSEDRAGRESULT}
	//----------------------------------------------------------------------------------------
	MOUSEDRAGRESULT MouseDragEnd(void);

	/// @}

/// @addtogroup MOUSEMOVE_DELTA
/// @ingroup group_enumeration
/// @{
/// These constants should be used in @ref InputEvent and only movements bigger than MOUSEMOVE_DELTA_TABLET or MOUSEMOVE_DELTA_MOUSE should be processed.\n
/// Here is an example from the material preview:
/// @code
/// 	Float GetMouseMoveDelta()
/// 	{
/// 		return GeIsTabletMode() ? MOUSEMOVE_DELTA_TABLET : MOUSEMOVE_DELTA_MOUSE;
/// 	}
///
/// Bool MaterialPreviewArea::InputEvent(const BaseContainer& msg)
/// {
/// 	...
/// 	Float rMinDelta = GetMouseMoveDelta();
/// 	Float rTotalDeltaX = 0, rTotalDeltaY = 0;
/// 	Float rDeltaX, rDeltaY;
/// 	while (MouseDrag(&rDeltaX, &rDeltaY, nullptr)==MOUSEDRAGRESULT_CONTINUE)
/// 	{
/// 		rTotalDeltaX += rDeltaX;
/// 		rTotalDeltaY += rDeltaY;
/// 		if ((rDeltaX == 0 && rDeltaY == 0) ||
/// 		(!bRotated && Abs(rTotalDeltaX) < rMinDelta && Abs(rTotalDeltaY) < rMinDelta))
/// 		{
/// 			GeSleep(10);
/// 			continue;
/// 		}
/// 		...
/// 		bRotated = true;
/// 		bRestart = true;
/// 	}
/// }
/// @endcode
#define MOUSEMOVE_DELTA_TABLET	6.0			///< Tablet movement threshold.
#define MOUSEMOVE_DELTA_MOUSE		2.0			///< Mouse movement threshold.
/// @}
};

//----------------------------------------------------------------------------------------
/// A convenience class that makes it easier to use the tristate feature of dialog controls, i.e. using a single control to represent the value of multiple objects.\n
/// The template allows manual instantiations for the following types: ::Bool, ::Int32, ::Float, ::Vector, BaseTime and String.
//----------------------------------------------------------------------------------------
template <class TYPE> class TriState
{
	Int32 tri;
	TYPE value;

public:

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty tristate.
	//----------------------------------------------------------------------------------------
	TriState() { tri = -1; value = TYPE(); }

	//----------------------------------------------------------------------------------------
	/// Creates a tristate and adds a single value.
	/// @param[in] val								The value to add.
	//----------------------------------------------------------------------------------------
	TriState(const TYPE& val) { tri = 0; value = val; }
	TriState(TYPE&& val) { tri = 0; value = std::move(val); }

	//----------------------------------------------------------------------------------------
	/// Checks whether all added values are the same, or if a tristate mode is necessary.
	/// @return												@trueIfOtherwiseFalse{any of the added values is different}
	//----------------------------------------------------------------------------------------
	Bool GetTri() const { return tri == 1; }

	//----------------------------------------------------------------------------------------
	/// Sets the tristate without touching the value.
	/// @param[in] state							True if a tristate shall be set.
	//----------------------------------------------------------------------------------------
	void SetTri(Bool state) { tri = state ? 1 : 0; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of the tristate.
	/// @return												The value that was added first, or @c TYPE() if the object is empty.
	//----------------------------------------------------------------------------------------
	const TYPE& GetValue() const { return value; }

	//----------------------------------------------------------------------------------------
	/// Checks if the tristate is empty.
	/// @return												@formatConstant{true} if any values have been added, or @formatConstant{false} if the tristate is empty.
	//----------------------------------------------------------------------------------------
	Bool HasChanged() const { return tri != -1; }

	//----------------------------------------------------------------------------------------
	/// Adds a value to the tristate.
	/// @param[in] val								The value to add.
	//----------------------------------------------------------------------------------------
	void Add(const TYPE& val)
	{
		if (tri == -1)
		{
			tri = 0;
			value = val;
		}
		else if (tri == 0 && value != val)
		{
			tri = 1;
		}
	}

	void Add(TYPE&& val)
	{
		if (tri == -1)
		{
			tri = 0;
			value = std::move(val);
		}
		else if (tri == 0 && value != val)
		{
			tri = 1;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Adds a value to the tristate from a base container.
	/// @param[in] bc									The base container with the value. @callerOwnsPointed{base container}
	/// @param[in] id									The ID of the value to add.
	//----------------------------------------------------------------------------------------
	void Add(BaseContainer* bc, Int32 id);

	//----------------------------------------------------------------------------------------
	/// Analyzes a GeDialog::Command() message to see if a certain dialog control has changed, and in that case adds the new value to the tristate. The value can then be accessed with @ref GetValue.
	/// @warning Use a newly allocated tristate, i.e. one without any values added, or this function will not work.
	/// @param[in] dlg								The dialog the message was sent to. @callerOwnsPointed{dialog}
	/// @param[in] msg								The message container.
	/// @param[in] cid								The control ID that triggered the message.
	/// @param[in] gid								The ID of the control to check for.
	/// @return												@trueIfOtherwiseFalse{the control had changed and its value was added}
	//----------------------------------------------------------------------------------------
	Int32 Check(GeDialog* dlg, const BaseContainer& msg, Int32 cid, Int32 gid);

	//----------------------------------------------------------------------------------------
	/// Analyzes a GeDialog::Command() message to see if any of the three dialog controls making up a vector has changed, and in that case adds the new value as a vector to the tristate. The vector can then be accessed with @ref GetValue.
	/// @warning Use a newly allocated tristate, i.e. one without any values added, or this function will not work.
	/// @param[in] dlg								The dialog the message was sent to. @callerOwnsPointed{dialog}
	/// @param[in] msg								The message container.
	/// @param[in] current_id					The control ID that triggered the message.
	/// @param[in] gidx								The ID of the X control to check for.
	/// @param[in] gidy								The ID of the Y control to check for.
	/// @param[in] gidz								The ID of the Z control to check for.
	/// @return												@trueIfOtherwiseFalse{any of the controls had changed and their values were added}
	//----------------------------------------------------------------------------------------
	Int32 CheckVector(GeDialog* dlg, const BaseContainer& msg, Int32 current_id, Int32 gidx, Int32 gidy, Int32 gidz);

	//----------------------------------------------------------------------------------------
	/// Analyzes a GeDialog::Command() message to see if a time dialog control has changed, and in that case adds the new time to the tristate. The time can then be accessed with @ref GetValue.\n
	/// @warning Use a newly allocated tristate, i.e. one without any values added, or this function will not work.
	/// @param[in] dlg								The dialog the message was sent to. @callerOwnsPointed{dialog}
	/// @param[in] msg								The message container.
	/// @param[in] doc								A document to get framerate settings from.
	/// @param[in] cid								The control ID that triggered the message.
	/// @param[in] gid								The ID of the control to check for.
	/// @return												@trueIfOtherwiseFalse{the control had changed and its time was added}
	//----------------------------------------------------------------------------------------
	Int32 CheckBaseTime(GeDialog* dlg, const BaseContainer& msg, BaseDocument* doc, Int32 cid, Int32 gid);
};

/// @addtogroup GUI_RANGE
/// @ingroup group_enumeration
/// @{
#define GUI_MAXRANGE	( 1.0e18)			///< Maximum GUI range for the number editing gadgets. Defined as @em 1.0e18.
#define GUI_MINRANGE	(-1.0e18)			///< Minimum GUI range for the number editing gadgets. Defined as @em -1.0e18.
/// @}



//----------------------------------------------------------------------------------------
/// Helper class for GeDialog::BeginLayoutChange()
//----------------------------------------------------------------------------------------
class UpdateDialogHelper
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(UpdateDialogHelper);
	friend class GeDialog;

private:
	UpdateDialogHelper(GeDialog* dialog, Int32 id);

	UpdateDialogHelper(GeDialog* dialog, C4DGadget* gad);

public:
	UpdateDialogHelper() = default;

	UpdateDialogHelper(UpdateDialogHelper&& src);

	~UpdateDialogHelper();

	MAXON_OPERATOR_MOVE_ASSIGNMENT(UpdateDialogHelper);

	void CommitChanges();

	static UpdateDialogHelper BeginLayoutChange(GeDialog* dialog, const GadgetPtr& gadget, Bool disableRedraws, Bool doNotFlush);

private:
	void ReenableRedraw();

private:
	GeDialog* _dialog = nullptr;
	GadgetPtr _gadget = GadgetPtr(Int32(0));
	Bool			_committed = false;
	Bool			_redrawDisabled = false;
};


//----------------------------------------------------------------------------------------
/// Used to display GUI dialogs.
/// Derive this class, overriding the necessary functions, and then call @ref Open() to display it.
//----------------------------------------------------------------------------------------
class GeDialog
{
	friend class GeUserArea;
	friend class _GeListView;

	MAXON_DISALLOW_COPY_AND_ASSIGN(GeDialog);

private:
	CDialog* cd;
	Int32 t_lastcoremsg;
	Bool  _folding = false;

protected:
	Bool createlayout;			///< @formatConstant{true} if the layout has been created, otherwise @formatConstant{false}. Normally not needed.

public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates the dialog, but does not open it.
	//----------------------------------------------------------------------------------------
	GeDialog(void);

	//----------------------------------------------------------------------------------------
	/// Destroys the dialog. If the dialog is still open, it is closed.
	//----------------------------------------------------------------------------------------
	virtual ~GeDialog(void);

	/// @}

	/// @name Internal Representation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to the internal dialog pointer.
	/// @return												The internal dialog.
	//----------------------------------------------------------------------------------------
	CDialog* Get() { return cd; }
#ifdef __API_INTERN__
	Bool dontfree;
	void Set(CDialog* set);
#endif

	/// @}

	/// @name Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is about to be displayed. Override this method to define the layout of the dialog.\n
	/// Either use the recommended @ref LoadDialogResource function or the manual functions (for example AddButton()).
	/// See @link page_dialog_layout Dialog Layout@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool CreateLayout(void);

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is initialized by the GUI. Override this method to initialize local variables and the gadgets used.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitValues(void);

	//----------------------------------------------------------------------------------------
	/// Override this method to react to @C4D core messages.
	/// @see The article @link page_manual_coremessages Core Messages@endlink for more information.
	/// @param[in] id									The message ID: @enumerateEnum{EVMSG}
	/// @param[in] msg								The message container.
	/// @return												Currently not used.
	//----------------------------------------------------------------------------------------
	virtual Bool CoreMessage(Int32 id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Whenever the user clicks on a gadget and/or changes its value this function will be called. It is also called when a string menu item is selected. Override this methods to handle such events.
	/// @note Remember StopAllThreads() must be called before making modifications to the scene.
	/// @param[in] id									The ID of the gadget that triggered the event.
	/// @param[in] msg								The message container. Contains the following values: @ref BFM_ACTION_ID and @ref BFM_ACTION_VALUE.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Command(Int32 id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// If the user wants to close the dialog with the OK button this function will be called. Override it to avoid closing the dialog if an error situation has occurred.\n
	/// If @formatConstant{false} is returned everything will be as usual, but if @formatConstant{true} is returned the dialog will not close. This function is especially useful in combination with the GeModalDialog class for handling wrong user input before leaving the dialog.
	/// @warning A buggy function, always returning @formatConstant{true}, will lead to a frustrating user experience.
	/// @return												@formatConstant{true} if the dialog should not be closed, @formatConstant{false} if it should.
	//----------------------------------------------------------------------------------------
	virtual Bool AskClose(void);

	//----------------------------------------------------------------------------------------
	/// Called when a timer event is received.\n
	/// To subscribe to timer events use SetTimer().
	/// @param[in] msg								The timer message container.
	//----------------------------------------------------------------------------------------
	virtual void Timer(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is about to be closed temporarily, for example for layout switching.\n
	/// All pointers to C4DGadget, GeUserArea and SubDialog objects as well as custom GUI objects are invalidated. So set all such stored pointers to @formatConstant{nullptr}.\n
	/// @ref CreateLayout will be called when the dialog is restored.
	//----------------------------------------------------------------------------------------
	virtual void DestroyWindow(void);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to more messages than covered by the other virtual functions. Normally this is not necessary.
	/// @note If overriden, be sure to include a call to the base version of this function, GeDialog::Message().
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	/// @}

	/// @name Open/Close
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens the dialog at the specified position.
	/// @note	If @formatParam{xpos}=@em -1 and @formatParam{ypos}=@em -1 the dialog will be opened at the current mouse position.\n
	/// 			If @formatParam{xpos}=@em -2 and @formatParam{ypos}=@em -2 the dialog will be opened at the center of the screen.
	/// @note Make sure to pass the ID for asynchronous plugins so that @C4D can correctly restore dialogs added by the user to the user interface.
	/// @param[in] dlgtype						The dialog type: @enumerateEnum{DLG_TYPE}
	/// @param[in] pluginid						The plugin ID of the CommandData with the dialog's CommandData::RestoreLayout().
	/// @param[in] xpos								The X position of the dialog. See note above.
	/// @param[in] ypos								The Y position of the dialog. See note above.
	/// @param[in] defaultw						The default width of the dialog in pixels.
	/// @param[in] defaulth						The default height of the dialog in pixels.
	/// @param[in] subid							The dialog sub-ID. This can be used to open several dialogs with a single command plugin for CommandData::ExecuteSubID().
	/// @param[in] flags							See OPENDIALOGFLAGS
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Open(DLG_TYPE dlgtype, Int32 pluginid, Int32 xpos = -1, Int32 ypos = -1, Int32 defaultw = 0, Int32 defaulth = 0, Int32 subid = 0, OPENDIALOGFLAGS flags = OPENDIALOGFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Closes the dialog. Not necessary when using modal dialogs.
	/// @return												@trueIfOtherwiseFalse{the dialog was closed}
	//----------------------------------------------------------------------------------------
	Bool Close(void);

	//----------------------------------------------------------------------------------------
	/// Always calls Close(void).
	/// @param[in] dummy							A dummy boolean state.
	//----------------------------------------------------------------------------------------
	Bool Close(Bool dummy);

	/// @}

	/// @name Basic Functions
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sends a message to a dialog element by ID.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] id									The dialog element ID.
	/// @param[in] msg								The message container.
	/// @return												Depends on the message sent.
	//----------------------------------------------------------------------------------------
	GeData SendMessage(const GadgetPtr& id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Sends a message to the parent dialog.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] receiveSelf				True if the own parent message should process this message. Default is false.
	/// @return												@trueIfOtherwiseFalse{the message was sent}
	//----------------------------------------------------------------------------------------
	Bool SendParentMessage(const BaseContainer& msg, Bool receiveSelf = false);

	//----------------------------------------------------------------------------------------
	/// Gets the dialog ID.
	/// @return												The dialog ID.
	//----------------------------------------------------------------------------------------
	Int32 GetId(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the dialog is open.
	/// @return												@trueIfOtherwiseFalse{the dialog is open}
	//----------------------------------------------------------------------------------------
	Bool IsOpen();

	//----------------------------------------------------------------------------------------
	/// Checks if the dialog is visible.
	/// @return												@trueIfOtherwiseFalse{the dialog is visible}
	//----------------------------------------------------------------------------------------
	Bool IsVisible();

	//----------------------------------------------------------------------------------------
	/// Checks if the dialog is minimized (in the dock or task bar).
	/// @return												@trueIfOtherwiseFalse{the dialog is minimized}
	//----------------------------------------------------------------------------------------
	Bool IsMinimized() const;

	//----------------------------------------------------------------------------------------
	/// Initializes the timer clock, so that Timer() is called every @formatParam{timer} milliseconds. Use @link SetTimer SetTimer(0)@endlink to stop the timer.
	/// @note Depending on the speed of the computer, the operating system, the complexity of the dialog and the threads running in the background, there is no guarantee that event messages will occur on a regular basis.\n
	/// Using a value of @em 500 ms should be no problem but using a value of 1 ms one might get events with the following time spaces: @em 3 ms, @em 76 ms, @em 15 ms, @em 19 ms, @em 67 ms etc.
	/// @warning Keep in mind that using small timer values results in heavy message traffic in the application which may slow down @C4D (and all other applications running on the computer) to a point where nothing is working any longer besides the dialog.
	/// @param[in] timer							The timer interval in milliseconds. Pass @em 0 to stop the timer.
	//----------------------------------------------------------------------------------------
	void SetTimer(Int32 timer);

	//----------------------------------------------------------------------------------------
	/// Sets the title of the dialog window.
	/// @param[in] title							The title.
	//----------------------------------------------------------------------------------------
	void SetTitle(const maxon::String& title);

	//----------------------------------------------------------------------------------------
	/// Gets the title of the dialog window.
	/// @return												The title
	//----------------------------------------------------------------------------------------
	maxon::String GetTitle();

	//----------------------------------------------------------------------------------------
	/// Enables or disables the dialog item with the specified @formatParam{id}.
	/// @param[in] id									The control ID.
	/// @param[in] enabled						@formatConstant{true} to enable and @formatConstant{false} to disable.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Enable(const GadgetPtr& id, Bool enabled);

	//----------------------------------------------------------------------------------------
	/// Checks if a dialog item is enabled.
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the dialog item is enabled}
	//----------------------------------------------------------------------------------------
	Bool IsEnabled(const GadgetPtr& id);

	/// @}

	/// @name Input
	/// @{

	//----------------------------------------------------------------------------------------
	/// Polls a certain channel of a device for the current input state.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to ask.
	/// @param[in] askchannel					The channel of the device.
	/// @param[out] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input state could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res);

	//----------------------------------------------------------------------------------------
	/// Gets the next input event for a certain device from the event queue.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to poll.
	/// @param[out] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input event could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInputEvent(Int32 askdevice, BaseContainer& res);

	//----------------------------------------------------------------------------------------
	/// Flushes all events from the window message queue.\n
	/// For example if looping while the mouse is down (polling), call this function to flush all key downs/mouse clicks that are made during the loop.
	//----------------------------------------------------------------------------------------
	void KillEvents(void);

	/// @}

	/// @name Plain Set
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the value of checkbox controls.
	/// @param[in] id									The control ID.
	/// @param[in] value							The new value. Checked is @formatConstant{true} and unchecked is @formatConstant{false}. If @formatParam{tristate} is @formatConstant{true} then value must be @em 2.
	/// @param[in] tristate						If @formatConstant{true}, and @formatParam{value} is @em 2, the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetBool(const GadgetPtr& id, Int32 value, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of integer fields. Also used for tab groups, radio buttons and combo boxes.
	/// @param[in] id									The control ID.
	/// @param[in] value							The new value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetInt32(const GadgetPtr& id, Int32 value, Int32 min = LIMIT<Int32>::MIN, Int32 max = LIMIT<Int32>::MAX, Int32 step = 1, Int32 tristate = 0, Int32 min2 = LIMIT<Int32>::MIN, Int32 max2 = LIMIT<Int32>::MAX);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of float fields.
	/// @param[in] id									The control ID.
	/// @param[in] value							The new value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] format							The unit and format of the field: @enumerateEnum{FORMAT_NUMBERS}
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @param[in] quadscale					If @formatConstant{true} a quadratic scale is used for the slider, so that more precision is available for lower values.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetFloat(const GadgetPtr& id, Float value, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0, Int32 format = FORMAT_FLOAT, Float min2 = 0.0, Float max2 = 0.0, Bool quadscale = false, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a meter field. Same as @ref SetFloat with @ref FORMAT_METER.
	/// @param[in] id									The control ID.
	/// @param[in] value							The new value.
	/// @param[in] min								The minimum value accepted.
	/// @param[in] max								The maximum value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetMeter(const GadgetPtr& id, Float value, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of an angle field. Same as @ref SetFloat with @ref FORMAT_DEGREE.
	/// @param[in] id									The control ID.
	/// @param[in] radians_value			The new angle in radians.
	/// @param[in] min								The minimum angle accepted in degrees.
	/// @param[in] max								The maximum angle accepted in degrees.
	/// @param[in] step								The step used for arrow buttons in degrees.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetDegree(const GadgetPtr& id, Float radians_value, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a percent field. Same as @ref SetFloat with @ref FORMAT_PERCENT.
	/// @param[in] id									The control ID.
	/// @param[in] value							The new value (real fraction).
	/// @param[in] min								The minimum value accepted (percentage units).
	/// @param[in] max								The maximum value accepted (percentage units).
	/// @param[in] step								The step used for arrow buttons (percentage units).
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetPercent(const GadgetPtr& id, Float value, Float min = 0.0, Float max = 100.0, Float step = 1.0, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a time field. Same as @ref SetFloat with @ref FORMAT_FRAMES.
	/// @param[in] id									The control ID.
	/// @param[in] doc								The document to be used for framerate calculations.
	/// @param[in] value							The new time value.
	/// @param[in] min								The minimum time accepted.
	/// @param[in] max								The maximum time accepted.
	/// @param[in] stepframes					The frame step used for arrow buttons.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetTime(const GadgetPtr& id, const BaseDocument* doc, const BaseTime& value, const BaseTime& min = BaseTime(-MAXTIME, 1), const BaseTime& max = BaseTime(MAXTIME, 1), Int32 stepframes = 1, Int32 tristate = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the text of string controls. Used for all controls that have a text, for example static text fields, edit fields, buttons and check boxes.
	/// @param[in] id									The control ID.
	/// @param[in] text								The new text.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @param[in] flags							Flags: @enumerateEnum{EDITTEXT} @enumerateEnum{FLAG_CENTER_ALIGN}
	/// @return												@trueIfOtherwiseFalse{the text was set}
	//----------------------------------------------------------------------------------------
	Bool SetString(const GadgetPtr& id, const maxon::String& text, Int32 tristate = 0, Int32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the color, brightness and limits of color fields and color choosers.
	/// @warning @formatParam{flags} does not apply to color fields, only to color choosers.
	/// @param[in] id									The control ID.
	/// @param[in] color							The new color value.
	/// @param[in] brightness					The new brightness value.
	/// @param[in] maxbrightness			The maximum brightness allowed.
	/// @param[in] flags							Controls what parts of a color chooser are available: @link DR_COLORFIELD_NO_BRIGHTNESS DR_COLORFIELD@endlink
	/// @return												@trueIfOtherwiseFalse{the color field values were set}
	//----------------------------------------------------------------------------------------
	Bool SetColorField(const GadgetPtr& id, const Vector& color, Float brightness, Float maxbrightness, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Sets the text of string controls, taking the new value from a filename.
	/// @param[in] id									The control ID.
	/// @param[in] fn									The new filename.
	/// @param[in] tristate						If @formatConstant{true} the control is tinted to indicate tristate mode.
	/// @return												@trueIfOtherwiseFalse{the filename was set}
	//----------------------------------------------------------------------------------------
	Bool SetFilename(const GadgetPtr& id, const Filename& fn, Int32 tristate = 0);

	/// @}

	/// @name Plain Get
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the state of checkbox controls.
	/// @param[in] id									The control ID.
	/// @param[out] value							Assigned the current state.
	/// @return												@trueIfOtherwiseFalse{the state was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetBool(const GadgetPtr& id, Bool& value) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of integer fields. Also used for tab groups, radio buttons and combo boxes.
	/// @param[in] id									The control ID.
	/// @param[out] value							Assigned the current value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInt32(const GadgetPtr& id, Int32& value) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of float fields.
	/// @param[in] id									The control ID.
	/// @param[out] value							Assigned the current value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetFloat(const GadgetPtr& id, Float& value) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of three float fields at the same time as a vector.
	/// @param[in] id_x								The control ID of the X field.
	/// @param[in] id_y								The control ID of the Y field.
	/// @param[in] id_z								The control ID of the Z field.
	/// @param[out] value							Assigned the current value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetVector(const GadgetPtr& id_x, const GadgetPtr& id_y, const GadgetPtr& id_z, Vector& value) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the text from string controls. Used for all controls that have a text, for example static text fields, edit fields, buttons and check boxes.
	/// @param[in] id									The control ID.
	/// @param[out] text							Assigned the current text.
	/// @return												@trueIfOtherwiseFalse{the text was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetString(const GadgetPtr& id, maxon::String& text) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the color and brightness of color controls.
	/// @param[in] id									The control ID.
	/// @param[out] color							Assigned the current color.
	/// @param[out] brightness				Assigned the current brightness.
	/// @return												@trueIfOtherwiseFalse{the color field values were retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetColorField(const GadgetPtr& id, Vector& color, Float& brightness) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the time of time fields.
	/// @param[in] id									The control ID.
	/// @param[in] doc								The document to use for framerate calculations.
	/// @param[out] time							Assigned the current time.
	/// @return												@trueIfOtherwiseFalse{the time was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetTime(const GadgetPtr& id, const BaseDocument* doc, BaseTime& time) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the text from string controls as a filename.
	/// @param[in] id									The control ID.
	/// @param[out] fn								Assigned the current filename.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetFilename(const GadgetPtr& id, Filename& fn) const;

	//----------------------------------------------------------------------------------------
	/// Checks if a control content has been changed since the last @em Set.
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the control has been changed}
	//----------------------------------------------------------------------------------------
	Bool CheckTristateChange(const GadgetPtr& id);	// return whether the gadget content has been changed since the last SetXXX or not

	/// @}

	/// @name Container Set
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the value of checkbox controls, taking the new value from a base container.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetBool(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of integer fields, taking the new value from a base container. Also used for tab groups, radio buttons and combo boxes.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetInt32(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Int32 min = LIMIT<Int32>::MIN, Int32 max = LIMIT<Int32>::MAX, Int32 step = 1, Int32 min2 = LIMIT<Int32>::MIN, Int32 max2 = LIMIT<Int32>::MAX);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of float fields, taking the new value from a base container.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] format							The unit and format of the field: @enumerateEnum{FORMAT_NUMBERS}
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @param[in] quadscale					If @formatConstant{true} a quadratic scale is used for the slider, so that more precision is available for lower values.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetFloat(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0, Int32 format = FORMAT_FLOAT, Float min2 = 0.0, Float max2 = 0.0, Bool quadscale = false);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of meter fields, taking the new value from a base container. Same as @ref SetFloat with @ref FORMAT_METER.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] min								The minimum value accepted.
	/// @param[in] max								The maximum value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetMeter(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of angle fields, taking the new value from a base container. Same as @ref SetFloat with @ref FORMAT_DEGREE.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] min								The minimum value accepted.
	/// @param[in] max								The maximum value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetDegree(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of percent fields, taking the new value from a base container. Same as @ref SetFloat with @ref FORMAT_PERCENT.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value (real fraction). @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] min								The minimum value accepted.
	/// @param[in] max								The maximum value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetPercent(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min = 0.0, Float max = 100.0, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a time field, taking the new value from a base container. Same as @ref SetFloat with @ref FORMAT_FRAMES.
	/// @param[in] id									The control ID.
	/// @param[in] doc								The document to get the framerate from. @callerOwnsPointed{document}
	/// @param[in] bc									The base container with the new time. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new time.
	/// @param[in] min								The minimum value accepted.
	/// @param[in] max								The maximum value accepted.
	/// @param[in] stepframes					The frame step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the time was set}
	//----------------------------------------------------------------------------------------
	Bool SetTime(const GadgetPtr& id, const BaseDocument* doc, const BaseContainer* bc, Int32 bcid, const BaseTime& min = BaseTime(-MAXTIME, 1), const BaseTime& max = BaseTime(MAXTIME, 1), Int32 stepframes = 1);

	//----------------------------------------------------------------------------------------
	/// Sets the text of string controls, taking the new value from a base container. Used for all controls that have a text, for example static text fields, edit fields, buttons and check boxes.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @param[in] flags							Flags: @enumerateEnum{EDITTEXT} @enumerateEnum{FLAG_CENTER_ALIGN}
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetString(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Int32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Sets the text of string controls, taking the new value from a filename in a base container.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the new value.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetFilename(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid);

	//----------------------------------------------------------------------------------------
	/// Sets the color, brightness and limits of color fields and color choosers, taking the new values from a base container.
	/// @param[in] id									The control ID.
	/// @param[in] bc									The base container with the new color field values. @callerOwnsPointed{base container}
	/// @param[in] bc_colid						The container ID of the new color value.
	/// @param[in] bc_brightnessid		The container ID of the new brightness value.
	/// @param[in] maxbrightness			The maximum brightness allowed.
	/// @param[in] flags							Controls what parts of a color chooser are available: @link DR_COLORFIELD_NO_BRIGHTNESS DR_COLORFIELD@endlink
	/// @return												@trueIfOtherwiseFalse{the color field values were set}
	//----------------------------------------------------------------------------------------
	Bool SetColorField(const GadgetPtr& id, const BaseContainer* bc, Int32 bc_colid, Int32 bc_brightnessid, Float maxbrightness, Int32 flags);

	/// @}

	/// @name Container Get
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the state of checkbox controls, and stores it in a base container.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the state. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the state.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetBool(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of integer fields, and stores it in a base container. Also used for tab groups, radio buttons and combo boxes.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetInt32(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of float fields, and stores it in a base container.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetFloat(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of a time field, and stores it in a base container.
	/// @param[in] id									The control ID.
	/// @param[in] doc								The document to get the framerate from. @callerOwnsPointed{document}
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetTime(const GadgetPtr& id, const BaseDocument* doc, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value of three float fields at the same time as a vector, and stores it in a base container.
	/// @param[in] id_x								The control ID of the X field.
	/// @param[in] id_y								The control ID of the Y field.
	/// @param[in] id_z								The control ID of the Z field.
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetVector(const GadgetPtr& id_x, const GadgetPtr& id_y, const GadgetPtr& id_z, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value from string controls, and stores it in a base container. Used for all controls that have a text, for example static text fields, edit fields, buttons and check boxes.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetString(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the value from string controls, and stores it as a filename in a base container.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the value. @callerOwnsPointed{base container}
	/// @param[in] bcid								The container ID of the value.
	/// @return												@trueIfOtherwiseFalse{the value was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetFilename(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the values of color and brightness for color controls, and stores them in a base container.
	/// @param[in] id									The control ID.
	/// @param[out] bc								The base container to receive the values. @callerOwnsPointed{base container}
	/// @param[in] bc_colid						The container ID of the color value.
	/// @param[in] bc_brightnessid		The container ID of the brightness value.
	/// @return												@trueIfOtherwiseFalse{the values were retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetColorField(const GadgetPtr& id, BaseContainer* bc, Int32 bc_colid, Int32 bc_brightnessid) const;

	/// @}

	/// @name TriState Set
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the value of checkbox controls using a TriState object.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetBool(const GadgetPtr& id, const TriState<Bool>& tri);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of integer fields using a TriState object.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetInt32(const GadgetPtr& id, const TriState<Int32>& tri, Int32 min = LIMIT<Int32>::MIN, Int32 max = LIMIT<Int32>::MAX, Int32 step = 1, Int32 min2 = LIMIT<Int32>::MIN, Int32 max2 = LIMIT<Int32>::MAX);

	//----------------------------------------------------------------------------------------
	/// Sets the value, unit and limits of float fields using a TriState object.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @param[in] format							The unit and format of the field: @enumerateEnum{FORMAT_NUMBERS}
	/// @param[in] min2								The minimum value allowed outside the visual range used for sliders. Overrides @formatParam{min} for the acceptance check.
	/// @param[in] max2								The maximum value allowed outside the visual range used for sliders. Overrides @formatParam{max} for the acceptance check.
	/// @param[in] quadscale					If @formatConstant{true} a quadratic scale is used for the slider, so that more precision is available for lower values.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetFloat(const GadgetPtr& id, const TriState<Float>& tri, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0, Int32 format = FORMAT_FLOAT, Float min2 = 0.0, Float max2 = 0.0, Bool quadscale = false);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a meter field using a TriState object. Same as @ref SetFloat with @ref FORMAT_METER.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetMeter(const GadgetPtr& id, const TriState<Float>& tri, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of an angle field using a TriState object. Same as @ref SetFloat with @ref FORMAT_DEGREE.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetDegree(const GadgetPtr& id, const TriState<Float>& tri, Float min = GUI_MINRANGE, Float max = GUI_MAXRANGE, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a percent field using a TriState object. Same as @ref SetFloat with @ref FORMAT_PERCENT.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum visual value accepted.
	/// @param[in] max								The maximum visual value accepted.
	/// @param[in] step								The step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetPercent(const GadgetPtr& id, const TriState<Float>& tri, Float min = 0.0, Float max = 100.0, Float step = 1.0);

	//----------------------------------------------------------------------------------------
	/// Sets the value and limits of a time field using a TriState object. Same as @ref SetFloat with @ref FORMAT_FRAMES.
	/// @param[in] id									The control ID.
	/// @param[in] doc								The document to be used for framerate calculations.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] min								The minimum time accepted.
	/// @param[in] max								The maximum time accepted.
	/// @param[in] stepframes					The frame step used for arrow buttons.
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetTime(const GadgetPtr& id, const BaseDocument* doc, const TriState<BaseTime>& tri, const BaseTime& min = BaseTime(-MAXTIME, 1), const BaseTime& max = BaseTime(MAXTIME, 1), Int32 stepframes = 1);

	//----------------------------------------------------------------------------------------
	/// Sets the text of string controls using a TriState object.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the value.
	/// @param[in] flags							Flags: @enumerateEnum{EDITTEXT} @enumerateEnum{FLAG_CENTER_ALIGN}
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetString(const GadgetPtr& id, const TriState<String>& tri, Int32 flags = 0);

/// @addtogroup FLAG_CENTER_ALIGN
/// @ingroup group_enumeration
/// @{
/// Additional flags for GeDialog::SetString()
#define FLAG_CENTER_HORIZ	1			///< Center the string horizontally.
#define FLAG_CENTER_VERT	2			///< Center the string vertically.
#define FLAG_ALIGN_RIGHT	4			///< Align the string to the right.
/// @}

	//----------------------------------------------------------------------------------------
	/// Sets the color, brightness and limits of color fields and color choosers using a TriState object for the color.
	/// @param[in] id									The control ID.
	/// @param[in] tri								A tristate object for the color value.
	/// @param[in] brightness					The new brightness value.
	/// @param[in] maxbrightness			The maximum brightness allowed.
	/// @param[in] flags							Controls what parts of a color chooser are available: @link DR_COLORFIELD_NO_BRIGHTNESS DR_COLORFIELD@endlink
	/// @return												@trueIfOtherwiseFalse{the value was set}
	//----------------------------------------------------------------------------------------
	Bool SetColorField(const GadgetPtr& id, const TriState<Vector>& tri, Float brightness, Float maxbrightness, Int32 flags);

	/// @}

	/// @name Coordinates Transformation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of the user area) to global window coordinates (relative to the top left corner of the application window). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the global window coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the global window coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Global(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms global window coordinates (relative to the top left corner of the application window) to local coordinates (relative to the top left corner of the user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The global window X coordinate. Assigned the local coordinate.
	/// @param[in,out] y							The global window Y coordinate. Assigned the local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Global2Local(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms screen coordinates (relative to the top left corner of the system screen) to local coordinates (relative to the top left corner of the user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The screen X coordinate. Assigned the local coordinate.
	/// @param[in,out] y							The screen Y coordinate. Assigned the local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Screen2Local(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of the user area) to screen coordinates (relative to the top left corner of the system screen). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the screen coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the screen coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Screen(Int32* x, Int32* y);

	/// @}

	/// @name Color
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the RGB values associated with a color constant.
	/// @param[in] colorid						A color constant: @enumerateEnum{COLOR}
	/// @param[out] r									Assigned the red component of the color.
	/// @param[out] g									Assigned the green component of the color.
	/// @param[out] b									Assigned the blue component of the color.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetColorRGB(Int32 colorid, Int32& r, Int32& g, Int32& b);

	//----------------------------------------------------------------------------------------
	/// Sets the default color for GUI elements.
	/// @param[in] id									The control ID to set the color for.
	/// @param[in] colorid						A color constant: @enumerateEnum{COLOR}
	/// @param[in] mapid							The color map ID.
	//----------------------------------------------------------------------------------------
	void SetDefaultColor(const GadgetPtr& id, Int32 colorid, Int32 mapid);

	//----------------------------------------------------------------------------------------
	/// Sets the default color for GUI elements.
	/// @param[in] id									The control ID to set the color for.
	/// @param[in] colorid						A color constant: @enumerateEnum{COLOR}
	/// @param[in] color							The color to set.
	//----------------------------------------------------------------------------------------
	void SetDefaultColor(const GadgetPtr& id, Int32 colorid, const Vector& color);

	/// @}

	/// @name Layout
	/// @{

	//----------------------------------------------------------------------------------------
	/// Loads an external resource file.\n
	/// This is the preferred method for dialog layout since it gives maximum flexibility and easy multi language support.
	/// @note The dialog loaded is automatically surrounded by an additional outer group, so @formatParam{flags} means the same as with dialog groups (e.g. @ref BFV_CENTER).
	/// See @link page_dialog_resource Dialog Resource@endlink for more information.
	/// @param[in] id									The dialog ID.
	/// @param[in] lr									The loaded resource or @formatConstant{nullptr}. If this is @formatConstant{nullptr} then the global ::resource singleton is used. @callerOwnsPointed{resource}
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @return												@trueIfOtherwiseFalse{the dialog was loaded successfully}
	//----------------------------------------------------------------------------------------
	Bool LoadDialogResource(Int32 id, GeResource* lr, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Adds a checkbox to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] name								The name of the checkbox.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddCheckbox(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Adds a button to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] name								The name of the button.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Adds a static text to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] name								The name of the static text.
	/// @param[in] borderstyle				The border style: @enumerateEnum{BORDER}
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddStaticText(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name, Int32 borderstyle);

	//----------------------------------------------------------------------------------------
	/// Adds an arrow button to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] arrowtype					The arrow type: @enumerateEnum{ARROW}
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddArrowButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 arrowtype);

	//----------------------------------------------------------------------------------------
	/// Adds an editable text field to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] editflags					The edit flags: @enumerateEnum{EDITTEXT}
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddEditText(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Int32 editflags = 0);

	//----------------------------------------------------------------------------------------
	/// Adds an editable text field with multiple lines to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] style							The style flags: @link DR_MULTILINE_MONOSPACED DR_MULTILINE@endlink
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddMultiLineEditText(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Int32 style = 0);

	//----------------------------------------------------------------------------------------
	/// Adds an editable number field to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddEditNumber(Int32 id, Int32 flags, Int32 initw = 80, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Adds an editable number field with up/down arrows to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddEditNumberArrows(Int32 id, Int32 flags, Int32 initw = 70, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Adds a slider with an editable number field to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddEditSlider(Int32 id, Int32 flags, Int32 initw = 80, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Adds a slider to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddSlider(Int32 id, Int32 flags, Int32 initw = 90, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Adds a simple color field without sliders to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] colorflags					The color flags: @link DR_COLORFIELD_NO_BRIGHTNESS DR_COLORFIELD@endlink
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddColorField(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Int32 colorflags = 0/*DR_COLORFIELD_ICC_xxxx*/);

	//----------------------------------------------------------------------------------------
	/// Adds a color chooser gadget to the layout.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] layoutflags				The color flags: @link DR_COLORFIELD_NO_BRIGHTNESS DR_COLORFIELD@endlink
	/// @param[in] settings						@markPrivate{The color chooser settings.} @paramSince R17
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddColorChooser(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Int32 layoutflags = 0, const BaseContainer& settings = BaseContainer());

	//----------------------------------------------------------------------------------------
	/// Adds a radio button to the layout. Used with radio groups created with AddRadioGroup().
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] name								The name of the radio button.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddRadioButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Adds a text radio button to the layout (like the ones to the left in the %Material Editor). Used with radio groups created with AddRadioGroup().
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] name								The name of the text radio button.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddRadioText(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Adds a field for editing shortcuts.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] shortcutflags			The shortcut flags.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddEditShortcut(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Int32 shortcutflags = 0);

	//----------------------------------------------------------------------------------------
	/// Adds a horizontal separator to the layout.
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddSeparatorH(Int32 initw, Int32 flags = BFH_FIT);

	//----------------------------------------------------------------------------------------
	/// Adds a vertical separator to the layout.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddSeparatorV(Int32 inith, Int32 flags = BFV_FIT);

	//----------------------------------------------------------------------------------------
	/// Adds a radio group to the layout. To add items to the radio button group use the AddChild() function.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] columns						The number of columns, or @em 0 if @formatParam{rows} is used.
	/// @param[in] rows								The number of rows, or @em 0 if @formatParam{columns} is used.
	/// @return												@trueIfOtherwiseFalse{the radio group was added}
	//----------------------------------------------------------------------------------------
	Bool AddRadioGroup(Int32 id, Int32 flags, Int32 columns = 1, Int32 rows = 0);

	//----------------------------------------------------------------------------------------
	/// Adds a combo box to the layout. To add items to the combo box menu use the AddChild() function.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] specialalign				Used to quantize the width of the combo box.\n
	///																If this is @formatConstant{true} then the width of the combo box will be a multiple of @formatParam{initw}.\n
	///																For example if @formatParam{initw} is @em 60px and @formatParam{specialalign} is @formatConstant{true} the width will be @em 60, @em 120, @em 180px and so on.
	/// @param[in] allowFiltering			True to allow keyboard filtering of the combobox list.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddComboBox(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Bool specialalign = false, Bool allowFiltering = false);

	//----------------------------------------------------------------------------------------
	/// Adds a combo button to the layout. To add items to the combo box menu use the AddChild() function.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] specialalign				Used to quantize the width of the item.\n
	///																If this is @formatConstant{true} then the width of the item will be a multiple of @formatParam{initw}.\n
	///																For example if @formatParam{initw} is @em 60px and @formatParam{specialalign} is @formatConstant{true} the width will be @em 60, @em 120, @em 180px and so on.
	/// @param[in] allowFiltering			True to allow keyboard filtering of the popup list.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddComboButton(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Bool specialalign = false, Bool allowFiltering = false);

	//----------------------------------------------------------------------------------------
	/// Adds a popup button to the layout. To add items to the popup menu use the AddChild() function or SetPopup().
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @param[in] allowFiltering			True to allow keyboard filtering of the popup list.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddPopupButton(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0, Bool allowFiltering = false);

	//----------------------------------------------------------------------------------------
	/// Adds a list view to the layout.
	/// @note Use the SimpleListView class to wrap the created list view control.
	/// @param[in] id									The control ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												@trueIfOtherwiseFalse{the list view was added}
	//----------------------------------------------------------------------------------------
	Bool AddListView(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0);

	/// @}

	/// @name Layout Helpers
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds items to combo boxes or popup buttons. The dialog resource equivalent is @c CHILDS.
	/// @param[in] id									The control ID.
	/// @param[in] subid							The ID of the item to add.
	/// @param[in] child							The name of the item to add.
	/// @return												@trueIfOtherwiseFalse{the child was added}
	//----------------------------------------------------------------------------------------
	Bool AddChild(const GadgetPtr& id, Int32 subid, const maxon::String& child);

	//----------------------------------------------------------------------------------------
	/// Clears the item list of combo boxes and popup buttons.
	/// @note Please note the spelling!
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the children were removed}
	//----------------------------------------------------------------------------------------
	Bool FreeChildren(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// Sets the item list of a popup button using a popup menu base container.\n
	/// This allow things like sub-menus and separators. See ShowPopupMenu() for more information.
	/// @param[in] id									The popup button ID.
	/// @param[in] bc									A base container with menu items.
	/// @return												@trueIfOtherwiseFalse{the popup menu was set}
	//----------------------------------------------------------------------------------------
	Bool SetPopup(const GadgetPtr& id, const BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Adds children to a dialog element using a base container.
	/// @param[in] id									The element to add children to.
	/// @param[in] bc									A base container with items.
	/// @return												@trueIfOtherwiseFalse{the children were added}
	//----------------------------------------------------------------------------------------
	Bool AddChildren(const GadgetPtr& id, const BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Adds a user area to the layout. Use AttachUserArea() to assign a GeUserArea object to the user area control.
	/// @param[in] id									The user area ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												The added gadget, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,gadget}
	//----------------------------------------------------------------------------------------
	C4DGadget* AddUserArea(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Attaches a GeUserArea object to a user area control, added with AddUserArea().\n
	/// The object will handle all messages to the user area and is responsible for painting the user area.
	/// @note A good practice is to place the GeUserArea derived object as a member of the GeDialog derived class.
	/// @param[in] ua									A user area object to attach.
	/// @param[in] id									The user area ID.
	/// @param[in] userareaflags			The user area flags: @enumerateEnum{USERAREAFLAGS}
	/// @return												@trueIfOtherwiseFalse{the user area was attached}
	//----------------------------------------------------------------------------------------
	Bool AttachUserArea(GeUserArea& ua, const GadgetPtr& id, USERAREAFLAGS userareaflags = USERAREAFLAGS::COREMESSAGE);

	//----------------------------------------------------------------------------------------
	/// Adds a sub-dialog to the layout. Use AttachSubDialog() to assign a SubDialog object to the sub-dialog control.
	/// @see SubDialog
	/// @param[in] id									The sub-dialog ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] initw							The initial width. Use SizePixChr() to set this value.
	/// @param[in] inith							The initial height. Use SizePixChr() to set this value.
	/// @return												@trueIfOtherwiseFalse{the sub dialog was added}
	//----------------------------------------------------------------------------------------
	Bool AddSubDialog(Int32 id, Int32 flags, Int32 initw = 0, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Attaches a SubDialog derived object to a SubDialog control, added with AddSubDialog().\n
	/// To replace the sub-dialog with another one, just call this function again.
	/// @param[in] userdlg						The sub-dialog object. @callerOwnsPointed{sub-dialog}
	/// @param[in] id									The sub-dialog ID.
	/// @return												@trueIfOtherwiseFalse{the sub-dialog was attached}
	//----------------------------------------------------------------------------------------
	Bool AttachSubDialog(SubDialog* userdlg, Int32 id);

	//----------------------------------------------------------------------------------------
	/// Adds a dialog group with standard buttons to the layout.
	/// @param[in] type								The standard buttons to add: @enumerateEnum{DLG}
	/// @return												@trueIfOtherwiseFalse{the dialog group was added}
	//----------------------------------------------------------------------------------------
	Bool AddDlgGroup(Int32 type);

	/// @}

	/// @name Group
	/// @{

	//----------------------------------------------------------------------------------------
	/// Begins a group in the menu bar of the dialog. End the group with GroupEnd().
	/// @return												@trueIfOtherwiseFalse{a group in the menu bar could be begun}
	//----------------------------------------------------------------------------------------
	Bool GroupBeginInMenuLine();

	//----------------------------------------------------------------------------------------
	/// Begins a tab group. Add tabs to the tab group with GroupBegin(). End the tab group with GroupEnd().
	/// @param[in] id									The ID of the tab group.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] tabtype						The tab type: @link TAB_TABS TAB@endlink
	/// @return												@trueIfOtherwiseFalse{a tab group could be begun}
	//----------------------------------------------------------------------------------------
	Bool TabGroupBegin(Int32 id, Int32 flags, Int32 tabtype = TAB_TABS);

	//----------------------------------------------------------------------------------------
	/// Begins a group. End the group with GroupEnd().
	/// @note GroupSpace(), GroupBorder(), GroupBorderNoTitle() and GroupBorderSpace() to further specify the look of the group.
	/// @param[in] id									The ID of the group.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] cols								The number of columns, or @em 0 if @formatParam{rows} are used.
	/// @param[in] rows								The number of rows, or @em 0 if @formatParam{cols} are used.
	/// @param[in] title							The title of the the group. Used for tab groups and groups with border.
	/// @param[in] groupflags					The group flags: @enumerateEnum{BFV_GROUP}
	/// @param[in] initw							The initial width.
	/// @param[in] inith							The initial height.
	/// @return												@trueIfOtherwiseFalse{a group could be begun}
	//----------------------------------------------------------------------------------------
	Bool GroupBegin(Int32 id, Int32 flags, Int32 cols, Int32 rows, const maxon::String& title, Int32 groupflags, Int32 initw = 0, Int32 inith = 0);

	//----------------------------------------------------------------------------------------
	/// Ends groups begun with GroupBegin(), TabGroupBegin() and ScrollGroupBegin().
	/// @return												@trueIfOtherwiseFalse{a group was ended}
	//----------------------------------------------------------------------------------------
	Bool GroupEnd(void);

	//----------------------------------------------------------------------------------------
	/// Sets the space in pixels between two elements in the current group. Equivalent to @c SPACE in dialog resources.
	/// @param[in] spacex							The X distance.
	/// @param[in] spacey							The Y distance.
	/// @return												@trueIfOtherwiseFalse{the spacing could be set}
	//----------------------------------------------------------------------------------------
	Bool GroupSpace(Int32 spacex, Int32 spacey);

	//----------------------------------------------------------------------------------------
	/// Sets the border type of the current group, and displays the title in the border if possible.\n
	/// Equivalent to @c BORDERSTYLE in dialog resources, if a @c NAME field is provided with the @link page_dialog_resource_GROUP GROUP@endlink declaration.
	/// @note Use GroupBorderNoTitle() to not have a title. Otherwise there will be a small gap in the border where the title would be.
	/// @param[in] borderstyle				The border style: @enumerateEnum{BORDER}
	/// @return												@trueIfOtherwiseFalse{the border was set}
	//----------------------------------------------------------------------------------------
	Bool GroupBorder(UInt32 borderstyle);

	//----------------------------------------------------------------------------------------
	/// Sets the border type of the current group. Does not display the title in the border.\n
	/// Equivalent to @c BORDERSTYLE in dialog resources, if a @c NAME field is not provided with the @link page_dialog_resource_GROUP GROUP@endlink declaration.
	/// @param[in] borderstyle				The border style: @enumerateEnum{BORDER}
	/// @return												@trueIfOtherwiseFalse{the border was set}
	//----------------------------------------------------------------------------------------
	Bool GroupBorderNoTitle(UInt32 borderstyle);

	//----------------------------------------------------------------------------------------
	/// Sets the border size around the current group in pixels. Equivalent to @c BORDERSIZE in dialog resources.
	/// @param[in] left								The distance to the left of the group.
	/// @param[in] top								The distance above the group.
	/// @param[in] right							The distance to the right of the group.
	/// @param[in] bottom							The distance below the group.
	/// @return												@trueIfOtherwiseFalse{the border space could be set}
	//----------------------------------------------------------------------------------------
	Bool GroupBorderSpace(Int32 left, Int32 top, Int32 right, Int32 bottom);

	//----------------------------------------------------------------------------------------
	/// Retrieves group weights for group @formatParam{id}.
	/// @param[in] id									The ID of the group.
	/// @param[out] weights						Filled with the weights: @enumerateEnum{GROUPWEIGHTS_PERCENT}
	/// @return												@trueIfOtherwiseFalse{the group weights could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GroupWeightsSave(const GadgetPtr& id, BaseContainer& weights);

	//----------------------------------------------------------------------------------------
	/// Sets group weights for group @formatParam{id}.\n
	/// The group weights are usually absolute values. If an element has a bigger minimum size the given weight will be ignored. The sum of the weights do not need to be @em 100.
	/// @note A weight value can be negative. In this case the group keeps its size absolute and it is not resized proportionally.
	/// @param[in] id									The ID of the group.
	/// @param[in] weights						The weights to set: @enumerateEnum{GROUPWEIGHTS_PERCENT}
	/// @return												@trueIfOtherwiseFalse{the group weights could be set}
	//----------------------------------------------------------------------------------------
	Bool GroupWeightsLoad(const GadgetPtr& id, const BaseContainer& weights);

	/// @}

	/// @name Drag and Drop
	/// @{

	//----------------------------------------------------------------------------------------
	/// Queries a dialog control for its current size and position in pixels.
	/// @param[in] id									The control ID. Use C4DGUIWINDOWID to get the pos/size of the window.
	/// @param[out] x									Assigned the X coordinate of the upper left corner of the control.
	/// @param[out] y									Assigned the Y coordinate of the upper left corner of the control.
	/// @param[out] w									Assigned the width of the control.
	/// @param[out] h									Assigned the height of the control.
	/// @return												@trueIfOtherwiseFalse{the item size and position were stored}
	//----------------------------------------------------------------------------------------
	Bool GetItemDim(const GadgetPtr& id, Int32* x, Int32* y, Int32* w, Int32* h) const;

	//----------------------------------------------------------------------------------------
	/// Extracts local drag coordinates from a drag and drop event. Stores the result in *@formatParam{x} and *@formatParam{y}.\n
	/// @see The article @link page_manual_gedialog_interaction_dragdrop Drag and Drop@endlink for more information.
	/// @param[in] msg								The original message.
	/// @param[out] x									Assigned the local X position.
	/// @param[out] y									Assigned the local Y position.
	/// @return												@trueIfOtherwiseFalse{the drag position was extracted}
	//----------------------------------------------------------------------------------------
	Bool GetDragPosition(const BaseContainer& msg, Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Extracts the object from a drag and drop message. Stores the result in *@formatParam{type} and *@formatParam{object}.\n
	/// @see The article @link page_manual_gedialog_interaction_dragdrop Drag and Drop@endlink for more information.
	/// @param[in] msg								The original message.
	/// @param[out] type							Assigned the type of the object.
	/// @param[out] object						Assigned a pointer to the object. @cinemaOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the drag object was extracted}
	//----------------------------------------------------------------------------------------
	Bool GetDragObject(const BaseContainer& msg, Int32* type, void** object);

	//----------------------------------------------------------------------------------------
	/// Sets the correct cursor during drag and drop handling.\n
	/// @see The article @link page_manual_gedialog_interaction_dragdrop Drag and Drop@endlink for more information.
	/// @param[in] cursor							A mouse cursor: @enumerateEnum{MOUSE}
	/// @param[in] gadgetid						The dialog element that this cursor is for, or @em 0.
	/// @return												@trueIfOtherwiseFalse{the cursor could be set}
	//----------------------------------------------------------------------------------------
	Bool SetDragDestination(Int32 cursor, Int32 gadgetid = 0);

	//----------------------------------------------------------------------------------------
	/// Checks the drag position in a drag event message against a certain dialog element's position in the layout. The check can be limited to only @em X or @em Y coordinates.
	/// @see The article @link page_manual_gedialog_interaction_dragdrop Drag and Drop@endlink for more information.
	/// @param[in] id									The dialog element ID.
	/// @param[in] msg								The drag message.
	/// @param[in] horiz							If @formatConstant{true} the drag position is checked against the horizontal bounds of the region.
	/// @param[in] vert								If @formatConstant{true} the drag position is checked against the vertical bounds of the region.
	/// @return												@trueIfOtherwiseFalse{the drag message is within the bounds specified}
	//----------------------------------------------------------------------------------------
	Bool CheckDropArea(const GadgetPtr& id, const BaseContainer& msg, Bool horiz, Bool vert);

	/// @}

	/// @name Scroll Group
	/// @{

	//----------------------------------------------------------------------------------------
	/// Queries a scroll group for its currently visible region, a rectangle between (@formatParam{x1},@formatParam{y1}) and (@formatParam{x2},@formatParam{y2}).
	/// @param[in] scrollgroupid			The scroll group ID.
	/// @param[out] x1								Assigned the X coordinate of the top left visible corner.
	/// @param[out] y1								Assigned the Y coordinate of the top left visible corner.
	/// @param[out] x2								Assigned the X coordinate of the bottom right visible corner.
	/// @param[out] y2								Assigned the Y coordinate of the bottom right visible corner.
	/// @return												@trueIfOtherwiseFalse{the visible area could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetVisibleArea(Int32 scrollgroupid, Int32* x1, Int32* y1, Int32* x2, Int32* y2);

	//----------------------------------------------------------------------------------------
	/// Scrolls a scroll group so that the rectangle between (x1,y1) and (x2,y2) is visible.
	/// - If the area is smaller than the scroll group then it is moved only as much as necessary.
	/// - If the area is bigger than the scroll group then the top left corners are aligned.
	/// @param[in] scrollgroupid			The scroll group ID.
	/// @param[in] x1									The X coordinate of the top left corner of the rectangle.
	/// @param[in] y1									The Y coordinate of the top left corner of the rectangle.
	/// @param[in] x2									The X coordinate of the bottom right corner of the rectangle.
	/// @param[in] y2									The Y coordinate of the bottom right corner of the rectangle.
	/// @return												@trueIfOtherwiseFalse{the group was scrolled or already had the right view}
	//----------------------------------------------------------------------------------------
	Bool SetVisibleArea(Int32 scrollgroupid, Int32 x1, Int32 y1, Int32 x2, Int32 y2);

	//----------------------------------------------------------------------------------------
	/// Begins a scrollable group. End the scroll group with GroupEnd().\n
	/// Use SetVisibleArea() and GetVisibleArea() to control the currently visible area.
	/// @param[in] id									The scroll group ID.
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] scrollflags				Additional flags for the scroll group: @enumerateEnum{SCROLLGROUP}
	/// @param[in] initw							The initial width of the scroll area.
	/// @param[in] inith							The initial height of the scroll area.
	/// @return												@trueIfOtherwiseFalse{a scroll group could be begun}
	//----------------------------------------------------------------------------------------
	Bool ScrollGroupBegin(Int32 id, Int32 flags, Int32 scrollflags, Int32 initw = 0, Int32 inith = 0);

	/// @}

	/// @name Layout
	/// @{

	//----------------------------------------------------------------------------------------
	/// Notifies @C4D that the layout of a dynamic group in the dialog has changed.\n
	/// This is usually done by first calling LayoutFlushGroup() and then adding new controls.
	/// @param[in] id									The ID of the changed group.
	/// @return												@trueIfOtherwiseFalse{the layout was updated}
	//----------------------------------------------------------------------------------------
	Bool LayoutChanged(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// Notifies @C4D that the layout of a dynamic group in the dialog has changed.\n
	/// This is usually done by first calling LayoutFlushGroup() and then adding new controls.
	/// @warning Does not redraw the dialog.
	/// @param[in] id									The ID of the changed group.
	/// @return												@trueIfOtherwiseFalse{the layout was updated}
	//----------------------------------------------------------------------------------------
	Bool LayoutChangedNoRedraw(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// Sets the focus to a specific control within the dialog.
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the control was activated}
	//----------------------------------------------------------------------------------------
	Bool Activate(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// Checks if the given gadget has the focus.
	/// @since R18
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the control is active}
	//----------------------------------------------------------------------------------------
	Bool IsActive(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// BeginLayoutChange simplifies the call of the combinations of LayoutFlushGroup()/LayoutChanged().
	/// @param[in] gadget							Gadget to flush and re-layout.
	/// @param[in] disableRedraws			True if all redraws should be disabled while the result object lives and result.CommitChanges() wasn't
	///																called.
	/// @param[in] doNotFlush			If true, existing elements persist and new elements are added at the end.
	/// @return												UpdateDialogRef on success. The returned object needs to be stored. Calling CommitChanges() will update
	///																the dialog group again and if redraw were disabled it will re-enable the redraw.
	//----------------------------------------------------------------------------------------
	UpdateDialogHelper BeginLayoutChange(const GadgetPtr& gadget, Bool disableRedraws, Bool doNotFlush = false);

	//----------------------------------------------------------------------------------------
	/// Removes all controls from a group and places the control insertion point within the group. This makes it possible to have dynamic groups.\n
	/// After all components are added call LayoutChanged() with the group ID.
	/// @param[in] id									The ID of the group.
	/// @return												@trueIfOtherwiseFalse{the group was flushed}
	//----------------------------------------------------------------------------------------
	Bool LayoutFlushGroup(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// LayoutFlushDisableRedraw description. Warning. For each calls of LayoutFlushDisableRedraw(true) you must call LayoutFlushDisableRedraw(false)!
	/// @param[in] id									The ID of the group.
	/// @param[in] disable						True to disable redraw. Don't forget to enable it. Best use a finally{} to enable it again.
	/// @return												@trueIfOtherwiseFalse{the group was disabled/enabled for redraw}
	//----------------------------------------------------------------------------------------
	Bool LayoutFlushDisableRedraw(const GadgetPtr& id, Bool disable);

	//----------------------------------------------------------------------------------------
	/// Removes an element from the dialog.
	/// @param[in] id									The control ID.
	/// @return												@trueIfOtherwiseFalse{the element was removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveElement(const GadgetPtr& id);

	//----------------------------------------------------------------------------------------
	/// Hides/unhides an element within a dialog.
	/// @param[in] id									The control ID.
	/// @param[in] hide								@formatConstant{true} to hide and @formatConstant{false} to unhide.
	/// @return												@trueIfOtherwiseFalse{the element was hidden/unhidden}
	//----------------------------------------------------------------------------------------
	Bool HideElement(const GadgetPtr& id, Bool hide);

	//----------------------------------------------------------------------------------------
	/// Used to restore an asynchronous dialog that has been placed in the users layout.\n
	/// @note Called from CommandData::RestoreLayout() where the secret pointer is provided.
	/// @param[in] pluginid						The plugin ID of the command plugin.
	/// @param[in] subid							The sub-ID of the dialog.
	/// @param[in] secret							An internal pointer.
	/// @return												@trueIfOtherwiseFalse{the dialog was restored}
	//----------------------------------------------------------------------------------------
	Bool RestoreLayout(Int32 pluginid, Int32 subid, void* secret);

	/// @}

	/// @name Menu
	/// @{

	//----------------------------------------------------------------------------------------
	/// Flushes the menu bar of the dialog, removing all menus.\n
	/// Add menus with MenuSubBegin(). Call MenuFinished() when all menus and items have been added.
	/// @return												@trueIfOtherwiseFalse{the menu bar was flushed}
	//----------------------------------------------------------------------------------------
	Bool MenuFlushAll(void);

	//----------------------------------------------------------------------------------------
	/// Creates a new menu group. At the top level this means a menu, at lower levels a sub-menu.
	/// Add items with MenuAddCommand(), MenuAddString() or MenuAddSeparator(). Call MenuSubEnd() when the menu is finished.
	/// @param[in] string							The name of the sub menu.
	/// @return												@trueIfOtherwiseFalse{a menu group could be begun}
	//----------------------------------------------------------------------------------------
	Bool MenuSubBegin(const maxon::String& string);

	//----------------------------------------------------------------------------------------
	/// Closes the current menu group, opened with MenuSubBegin().
	/// @return												@trueIfOtherwiseFalse{a menu group was ended}
	//----------------------------------------------------------------------------------------
	Bool MenuSubEnd(void);

	//----------------------------------------------------------------------------------------
	/// Adds a command item to the current menu.\n
	/// This can either be a @C4D command or a plugin command. Particularly useful is @ref IDM_CM_CLOSEWINDOW to add a close item for dialogs.
	/// @param[in] cmdid							A @C4D command id or a plugin ID.
	/// @return												@trueIfOtherwiseFalse{the command was added}
	//----------------------------------------------------------------------------------------
	Bool MenuAddCommand(Int32 cmdid);

	//----------------------------------------------------------------------------------------
	/// Adds a string item to the current menu. Command() will be called when the menu item is selected.
	/// @param[in] id									The item ID.
	/// @param[in] string							The item text. Use a &nbsp;d&nbsp; suffix for disabled and a &nbsp;c&nbsp; suffix for checked items.
	/// @return												@trueIfOtherwiseFalse{a string item was added}
	//----------------------------------------------------------------------------------------
	Bool MenuAddString(Int32 id, const maxon::String& string);

	//----------------------------------------------------------------------------------------
	/// Adds a separator to the current menu.
	/// @param[in] title							Optional separator title.
	/// @return												@trueIfOtherwiseFalse{a separator was added}
	//----------------------------------------------------------------------------------------
	Bool MenuAddSeparator(const maxon::String& title = maxon::String());

	//----------------------------------------------------------------------------------------
	/// Call this function when all menus and all items have been added.
	/// @return												@trueIfOtherwiseFalse{the menu bar was updated}
	//----------------------------------------------------------------------------------------
	Bool MenuFinished(void);

	//----------------------------------------------------------------------------------------
	/// Used to change the enabled/disabled and checked/unchecked state of menu items.
	/// @note Can be called after MenuFinished() to update the menu item dynamically.
	/// @param[in] id									The menu item ID.
	/// @param[in] enabled						@formatConstant{true} if the menu item is enabled or @formatConstant{false} if the menu item is disabled (grayed out).
	/// @param[in] checked						@formatConstant{true} if the menu item should be checked, otherwise @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{a string item was updated}
	//----------------------------------------------------------------------------------------
	Bool MenuInitString(Int32 id, Bool enabled, Bool checked);

	//----------------------------------------------------------------------------------------
	/// Sets the menu from a @em MENU resource ID.
	/// @param[in] id									The menu resource ID.
	/// @return												@trueIfOtherwiseFalse{the menu was set from resource}
	//----------------------------------------------------------------------------------------
	Bool MenuSetResource(Int32 id);

	/// @}

	/// @name Custom GUI
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the custom GUI for a certain element ID. The GUI object must have been previously added with AddCustomGui().
	/// @param[in] id									The custom GUI element ID.
	/// @param[in] pluginid						The plugin ID of the custom GUI.
	/// @return												The custom GUI. @theOwnsPointed{dialog,custom GUI}
	//----------------------------------------------------------------------------------------
	void* FindCustomGui(Int32 id, Int32 pluginid);

	//----------------------------------------------------------------------------------------
	/// Gets the custom GUI for a certain element ID. The GUI object must have been previously added with AddCustomGui().
	/// @param[in] id									The custom GUI element ID.
	/// @return												The custom GUI. @theOwnsPointed{dialog,custom GUI}
	//----------------------------------------------------------------------------------------
	template <typename T> T* FindCustomGui(Int32 id)
	{
		return (T*)FindCustomGui(id, T::VALUE);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a custom GUI element to the dialog.
	/// @param[in] id									The dialog element ID of the new custom GUI.
	/// @param[in] pluginid						The plugin ID of the custom GUI.
	/// @param[in] name								The name of the added custom GUI. (Not necessarily used.)
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] minw								The minimum width.
	/// @param[in] minh								The minimum height.
	/// @param[in] customdata					The settings for the new custom GUI.
	/// @return												The custom GUI element that was added, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,custom GUI}
	//----------------------------------------------------------------------------------------
	void* AddCustomGui(Int32 id, Int32 pluginid, const maxon::String& name, Int32 flags, Int32 minw, Int32 minh, const BaseContainer& customdata);

	//----------------------------------------------------------------------------------------
	/// Adds a custom GUI element to the dialog.
	/// @param[in] id									The dialog element ID of the new custom GUI.
	/// @param[in] name								The name of the added custom GUI. (Not necessarily used.)
	/// @param[in] flags							The layout flags: @link BFH_CENTER BFH@endlink @link BFV_CENTER BFV@endlink
	/// @param[in] minw								The minimum width.
	/// @param[in] minh								The minimum height.
	/// @param[in] customdata					The settings for the new custom GUI.
	/// @return												The custom GUI element that was added, or @formatConstant{nullptr} if an error occurred. @theOwnsPointed{dialog,custom GUI}
	//----------------------------------------------------------------------------------------
	template <typename T> T* AddCustomGui(Int32 id, const maxon::String& name, Int32 flags, Int32 minw, Int32 minh, const BaseContainer& customdata)
	{
		return (T*)AddCustomGui(id, T::VALUE, name, flags, minw, minh, customdata);
	}

	/// @}

	/// @name Multi-line Edit
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the edit mode for multi-line edit fields.
	/// @param[in] id									The control ID.
	/// @param[in] mode								The multi-line edit mode: @enumerateEnum{SCRIPTMODE}
	/// @return												@trueIfOtherwiseFalse{the multi-line mode was set}
	//----------------------------------------------------------------------------------------
	Bool SetMultiLineMode(const GadgetPtr& id, SCRIPTMODE mode);

	//----------------------------------------------------------------------------------------
	/// Locks/unlocks multi-line edit fields.
	/// @param[in] id									The control ID.
	/// @param[in] lock								@formatConstant{true} to lock the field, formatConstant{false} to unlock it.
	/// @return												@trueIfOtherwiseFalse{the multi-line edit field was locked/unlocked}
	//----------------------------------------------------------------------------------------
	Bool SetMultiLineLock(const GadgetPtr& id, Bool lock);

	//----------------------------------------------------------------------------------------
	/// Sets the cursor position within a multi-line edit text control.
	/// @param[in] id									The control ID.
	/// @param[in] line								The line number.
	/// @param[in] pos								The position within the line.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetMultiLinePos(const GadgetPtr& id, Int32 line, Int32 pos);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the dialog can be closed. Normally checks the value ranges and calls AskClose().
	/// @return												@trueIfOtherwiseFalse{the dialog should not be closed}
	//----------------------------------------------------------------------------------------
	Bool CheckClose(void);

	//----------------------------------------------------------------------------------------
	/// Checks whether all input fields' values are within the allowed range.
	/// @return												@formatConstant{true} if everything is alright, or @formatConstant{false} if any field is wrong.
	//----------------------------------------------------------------------------------------
	Bool CheckValueRanges(void);

	//----------------------------------------------------------------------------------------
	/// @markPrivate Always returns @em 1.0 except for user areas shown on OS X Retina displays, where it returns @em 2.0.
	/// @return												Always @em 1.0 except for user areas shown on OS X Retina displays.
	//----------------------------------------------------------------------------------------
	Float GetPixelRatio() const;

	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	Bool ReleaseLink();

#ifdef __API_INTERN__
	Bool OpenPopUpMenu(Int32 menuid, Int32 localx, Int32 localy, Int32 watchhotkey);
#endif

	//----------------------------------------------------------------------------------------
	/// Speedup function that checks if a core message is new or has been already processed.
	/// @see The article @link page_manual_coremessages Core Messages@endlink for more information.
	/// @param[in] msg								The core message.
	/// @param[in] ownlastcoremsg			An optional pointer to a last core message.
	/// @return												@formatConstant{true} if the message is new, @formatConstant{false} if it is a message of the same age.
	//----------------------------------------------------------------------------------------
	Bool CheckCoreMessage(const BaseContainer& msg, Int32* ownlastcoremsg = nullptr);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static void HandleHelpString(const BaseContainer& msg, BaseContainer& result, const maxon::String& sym);

	//----------------------------------------------------------------------------------------
	/// Gets the handle of the dialog window (HWND). @markPrivate
	/// @return												The window handle.
	//----------------------------------------------------------------------------------------
	void* GetWindowHandle();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void* GetWindowInterface();

	/// @}

/// @addtogroup GROUPWEIGHTS_PERCENT
/// @ingroup group_containerid
/// @{
#define GROUPWEIGHTS_PERCENT_W_CNT 2000																	///< The number of columns. Has to be equal to the given layout.
#define GROUPWEIGHTS_PERCENT_W_VAL (GROUPWEIGHTS_PERCENT_W_CNT + 1)			///< The column weight for column @em i is in @ref GROUPWEIGHTS_PERCENT_W_VAL + @em i.
#define GROUPWEIGHTS_PERCENT_H_CNT 3000																	///< The number of rows. Has to be equal to the given layout.
#define GROUPWEIGHTS_PERCENT_H_VAL (GROUPWEIGHTS_PERCENT_H_CNT + 1)			///< The row weight for row @em i is in @ref GROUPWEIGHTS_PERCENT_H_VAL + @em i.
/// @}


	//----------------------------------------------------------------------------------------
	/// Retrieve if the dialog is open but currently folded away in the layout.
	/// @return												True if folded.
	//----------------------------------------------------------------------------------------
	Bool GetFolding(void);

	//----------------------------------------------------------------------------------------
	/// Fold the dialog away in the layout.
	/// @param[in] allowClose					True if the dialog should fold away.
	//----------------------------------------------------------------------------------------
	void SetFolding(Bool allowClose);

	//----------------------------------------------------------------------------------------
	/// Returns the docking state of the dialog.
	/// @return                       Bit mask of DIALOG_ISDOCKED and DIALOG_ISTABBED. 0 if the dialog is a individual window.
	//----------------------------------------------------------------------------------------
	Int32 IsDockedOrTabbed();
};

	//----------------------------------------------------------------------------------------
	/// This class is especially designed for modal dialogs. This means that as long as the dialog is open, @C4D has to wait until the user closes the dialog.
	//----------------------------------------------------------------------------------------
class GeModalDialog : public GeDialog
{
private:
	Bool dlg_result;
	Bool close;

public:
	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates the dialog, but does not open it.
	//----------------------------------------------------------------------------------------
	GeModalDialog(void);

	//----------------------------------------------------------------------------------------
	/// Destroys the dialog.
	//----------------------------------------------------------------------------------------
	virtual ~GeModalDialog(void);

	/// @}

	/// @name Open/Close
	/// @{

	//----------------------------------------------------------------------------------------
	/// Opens the dialog at the specified position (@formatParam{xpos}, @formatParam{ypos}). If @formatParam{xpos}=@em -1 and @formatParam{ypos}=@em -1 the dialog will be opened at the current mouse position.
	/// @param[in] xpos								The X position of the dialog.
	/// @param[in] ypos								The Y position of the dialog.
	/// @param[in] defaultw						The default width of the dialog in pixels.
	/// @param[in] defaulth						The default height of the dialog in pixels.
	/// @param[in] resizable					Set to @formatConstant{true} for resizable modal dialogs.
	/// @param[in] flags							see OPENDIALOGFLAGS.
	/// @return												@formatConstant{true} if @em OK was pressed or Close(true) was called.\n
	/// 															@formatConstant{false} if @em Cancel was pressed or Close(false) was called.
	//----------------------------------------------------------------------------------------
	Bool Open(Int32 xpos = -1, Int32 ypos = -1, Int32 defaultw = 0, Int32 defaulth = 0, Bool resizable = false, OPENDIALOGFLAGS flags = OPENDIALOGFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Closes the dialog.
	/// @param[in] result							@formatConstant{true} to report that @em OK was pressed, otherwise @formatConstant{false}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Close(Bool result);

	//----------------------------------------------------------------------------------------
	/// Checks how the dialog was closed.
	/// @return												@trueIfOtherwiseFalse{the dialog was closed pressing @em OK}
	//----------------------------------------------------------------------------------------
	Bool GetResult(void) { return dlg_result; }

	/// @}

	/// @name Message
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to special messages. Normally this is not necessary.
	/// @note If overriden, include a call to the base version of this function, GeModalDialog::Message().
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	/// @}

	/// @name Check
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks integer field values.\n
	/// If the value is outside the allowed range a suitable error is displayed and the field is activated.
	/// @param[in] id									The control ID.
	/// @param[in] type								The comparison: @enumerateEnum{CHECKVALUERANGE}
	/// @param[in] val								The value to check.
	/// @param[in] x									The first parameter of the comparison.
	/// @param[in] y									The second parameter of the comparison.
	//----------------------------------------------------------------------------------------
	void CheckLong(Int32 id, CHECKVALUERANGE type, Int32 val, Int32 x, Int32 y);

	//----------------------------------------------------------------------------------------
	/// Checks real field values.\n
	/// If the value is outside the allowed range a suitable error is displayed and the field is activated.
	/// @param[in] id									The control ID.
	/// @param[in] type								The comparison: @enumerateEnum{CHECKVALUERANGE}
	/// @param[in] val								The value to check.
	/// @param[in] x									The first parameter of the comparison.
	/// @param[in] y									The second parameter of the comparison.
	/// @param[in] format							The format of the field: @enumerateEnum{CHECKVALUEFORMAT}
	//----------------------------------------------------------------------------------------
	void CheckReal(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y, CHECKVALUEFORMAT format = CHECKVALUEFORMAT::NOTHING);

	//----------------------------------------------------------------------------------------
	/// Checks meter field values.\n
	/// If the value is outside the allowed range a suitable error is displayed and the field is activated.
	/// @param[in] id									The control ID.
	/// @param[in] type								The comparison: @enumerateEnum{CHECKVALUERANGE}
	/// @param[in] val								The value to check.
	/// @param[in] x									The first parameter of the comparison.
	/// @param[in] y									The second parameter of the comparison.
	//----------------------------------------------------------------------------------------
	void CheckMeter(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y);

	//----------------------------------------------------------------------------------------
	/// Checks percent field values.\n
	/// If the value is outside the allowed range a suitable error is displayed and the field is activated.
	/// @param[in] id									The control ID.
	/// @param[in] type								The comparison: @enumerateEnum{CHECKVALUERANGE}
	/// @param[in] val								The value to check.
	/// @param[in] x									The first parameter of the comparison.
	/// @param[in] y									The second parameter of the comparison.
	//----------------------------------------------------------------------------------------
	void CheckPercent(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y);

	//----------------------------------------------------------------------------------------
	/// Checks angle field values.\n
	/// If the value is outside the allowed range a suitable error is displayed and the field is activated.
	/// @param[in] id									The control ID.
	/// @param[in] type								The comparison: @enumerateEnum{CHECKVALUERANGE}
	/// @param[in] val								The value to check.
	/// @param[in] x									The first parameter of the comparison.
	/// @param[in] y									The second parameter of the comparison.
	//----------------------------------------------------------------------------------------
	void CheckDegree(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y);

	/// @}
};

//----------------------------------------------------------------------------------------
/// This class is for creating sub-dialogs that can be attached to a @em SUBDIALOG control in an ordinary GeDialog with GeDialog::AttachSubDialog().
//----------------------------------------------------------------------------------------
class SubDialog : public GeDialog
{
	Bool dlg_result;

public:
	//----------------------------------------------------------------------------------------
	/// Creates the sub-dialog.
	//----------------------------------------------------------------------------------------
	SubDialog(void);

	//----------------------------------------------------------------------------------------
	/// Destroys the sub-dialog.
	//----------------------------------------------------------------------------------------
	virtual ~SubDialog(void);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to special messages. Normally this is not necessary.
	/// @note If overriden, include a call to the base version of this function, SubDialog::Message().
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);
};

//----------------------------------------------------------------------------------------
/// Base class for custom GUIs.
/// @see CustomGuiData.
//----------------------------------------------------------------------------------------
class iCustomGui : public SubDialog
{
	Int32 layoutmode;
	Int32 editheight;
	CUSTOMGUIPLUGIN* plugin;

public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @note Usually only called from CustomGuiData::Alloc().
	/// @param[in] settings						The settings container.
	/// @param[in] t_plugin						The plugin structure.
	//----------------------------------------------------------------------------------------
	iCustomGui(const BaseContainer& settings, CUSTOMGUIPLUGIN* t_plugin);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to special messages. Normally this is not necessary.
	/// @note If overriden, include a call to the base version of this function, iCustomGui::Message().
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	//----------------------------------------------------------------------------------------
	/// Retrieves the preferred width of the custom GUI.
	/// @return												The preferred width in pixels.
	//----------------------------------------------------------------------------------------
	virtual Int32 CustomGuiWidth();

	//----------------------------------------------------------------------------------------
	/// Retrieves the preferred height of the custom GUI.
	/// @return												The preferred height in pixels.
	//----------------------------------------------------------------------------------------
	virtual Int32 CustomGuiHeight();

	//----------------------------------------------------------------------------------------
	/// Called when the GUI is redrawn. Use this for instance to update the user areas.
	//----------------------------------------------------------------------------------------
	virtual void CustomGuiRedraw();

	//----------------------------------------------------------------------------------------
	/// Never called.
	//----------------------------------------------------------------------------------------
	virtual Bool CustomGuiLayoutChanged();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	virtual Bool CustomGuiActivate();

	//----------------------------------------------------------------------------------------
	/// Called when the GUI is default constructed in @em ResEdit. Initialize the custom GUI with default values.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool SetDefaultForResEdit();

	//----------------------------------------------------------------------------------------
	/// Called to update the custom GUI to display the value in @formatParam{tristate}.
	/// @note Remember to check for tri state, i.e. when more than one value is to be shown.
	/// @param[in] tristate						The new value to display.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool SetData(const TriState<GeData>& tristate);

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the value(s) currently displayed.
	/// @return												The currently displayed value(s).
	//----------------------------------------------------------------------------------------
	virtual TriState<GeData> GetData();

	//----------------------------------------------------------------------------------------
	/// Called to check if the custom GUI supports the minimized/maximized switch.\n
	/// Normally it is not needed to override this function.
	/// @return												@trueIfOtherwiseFalse{the custom GUI supports layout switch}
	//----------------------------------------------------------------------------------------
	virtual Bool SupportLayoutSwitch();

	//----------------------------------------------------------------------------------------
	/// Called when the minimized/maximized state has changed. Use GetLayoutMode() to retrieve the current mode.
	//----------------------------------------------------------------------------------------
	virtual void LayoutModeChanged();

	//----------------------------------------------------------------------------------------
	/// Sets the current layout mode.\n
	/// Normally it is not needed to override this function.
	/// @param[in] mode								The new layout mode: @enumerateEnum{LAYOUTMODE}
	//----------------------------------------------------------------------------------------
	virtual void SetLayoutMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Gets the current layout mode.\n
	/// Normally it is not needed to override this function.
	/// @return												The layout mode: @enumerateEnum{LAYOUTMODE}
	//----------------------------------------------------------------------------------------
	virtual Int32 GetLayoutMode();

	//----------------------------------------------------------------------------------------
	/// Retrieves the edit height of the custom GUI. (Set by @ref CUSTOMGUI_DEFAULTEDITHEIGHT in the settings container passed to the constructor.)
	/// @return												The edit height.
	//----------------------------------------------------------------------------------------
	Int32 GetEditHeight() { return editheight; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the custom GUI plugin structure passed to the constructor.
	/// @return												The plugin structure.
	//----------------------------------------------------------------------------------------
	CUSTOMGUIPLUGIN* GetPlugin() { return plugin; }

/// @addtogroup LAYOUTMODE
/// @ingroup group_enumeration
/// @{
#define LAYOUTMODE_NONE				0			///< Does not support layout modes.
#define LAYOUTMODE_MINIMIZED	1			///< Minimized.
#define LAYOUTMODE_MAXIMIZED	2			///< Maximized.
/// @}
};

//----------------------------------------------------------------------------------------
/// Combines SizePix() and SizeChr() functions. The returned value is interpreted as a number of characters/lines plus a number of pixels.
/// @note	The number of characters for @formatParam{chars} has to be multiplied by @em 10.\n
///				For example if a size of @em 3 characters is needed, pass @em 3 * @em 10, or @em 30 for @formatParam{chars}.
/// @param[in] pixels							The pixel dimension.
/// @param[in] chars							The number of characters.
/// @return												The size.
//----------------------------------------------------------------------------------------
inline Int32 SizePixChr(Int32 pixels, Int32 chars) { return (pixels << 14) + chars; }

//----------------------------------------------------------------------------------------
/// Bakes a pixel size so that it can be used to specify dialog control dimension.
/// @param[in] pixels							The pixel dimension.
/// @return												The size.
//----------------------------------------------------------------------------------------
inline Int32 SizePix(Int32 pixels) { return SizePixChr(pixels, 0); }

//----------------------------------------------------------------------------------------
/// Bakes a character count so that it can be used to specify dialog control dimension.\n
/// Calculates how many characters will fit in a control for widths, and how many standard lines will fit for heights.
/// @note	The number of characters for @formatParam{chars} has to be multiplied by @em 10.\n
///				For example if a size of @em 3 characters is needed, pass @em 3 * @em 10, or @em 30 for @formatParam{chars}.
/// @param[in] chars							The number of characters.
/// @return												The size.
//----------------------------------------------------------------------------------------
inline Int32 SizeChr(Int32 chars) { return SizePixChr(0, chars); }

#ifndef __API_INTERN__
//----------------------------------------------------------------------------------------
/// Opens a standard message dialog with an exclamation point icon and an @em OK button.
/// @param[in] str								The message to show.
//----------------------------------------------------------------------------------------
void MessageDialog(const maxon::String& str);

//----------------------------------------------------------------------------------------
/// Opens a standard dialog with an exclamation point icon and an @em OK button.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object.
//----------------------------------------------------------------------------------------
void MessageDialog(Int32 id);

//----------------------------------------------------------------------------------------
/// Opens a standard dialog with an exclamation point icon and an @em OK button.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object, including one phrase that is inserted at #'s in the string.
/// @param[in] p1									The phrase to insert.
//----------------------------------------------------------------------------------------
void MessageDialog(Int32 id, const maxon::String& p1);

//----------------------------------------------------------------------------------------
/// Opens a standard dialog with an exclamation point icon and an @em OK button.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object, including two phrases that are inserted at #'s in the string.
/// @param[in] p1									The first phrase to insert.
/// @param[in] p2									The second phrase to insert.
//----------------------------------------------------------------------------------------
void MessageDialog(Int32 id, const maxon::String& p1, const maxon::String& p2);

//----------------------------------------------------------------------------------------
/// Opens a standard question dialog with a question mark icon and @em Yes/@em No buttons.
/// @param[in] str								The message to show.
/// @return												@trueIfOtherwiseFalse{the user answered @em Yes}
//----------------------------------------------------------------------------------------
Bool QuestionDialog(const maxon::String& str);

//----------------------------------------------------------------------------------------
/// Opens a standard question dialog with a question mark icon and @em Yes/@em No buttons.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object.
/// @return												@trueIfOtherwiseFalse{the user answered @em Yes}
//----------------------------------------------------------------------------------------
Bool QuestionDialog(Int32 id);

//----------------------------------------------------------------------------------------
/// Opens a standard question dialog with a question mark icon and @em Yes/@em No buttons.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object, including one phrase that is inserted at #'s in the string.
/// @param[in] p1									The phrase to insert.
/// @return												@trueIfOtherwiseFalse{the user answered @em Yes}
//----------------------------------------------------------------------------------------
Bool QuestionDialog(Int32 id, const maxon::String& p1);

//----------------------------------------------------------------------------------------
/// Opens a standard question dialog with a question mark icon and @em Yes/@em No buttons.
/// @param[in] id									The message to show, specified as a string ID in the global ::resource object, including two phrases that are inserted at #'s in the string.
/// @param[in] p1									The first phrase to insert.
/// @param[in] p2									The second phrase to insert.
/// @return												@trueIfOtherwiseFalse{the user answered @em Yes}
//----------------------------------------------------------------------------------------
Bool QuestionDialog(Int32 id, const maxon::String& p1, const maxon::String& p2);

	//----------------------------------------------------------------------------------------
	/// Gets the next input event for a certain device from the event queue.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to poll.
	/// @param[in] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input event could be retrieved}
	//----------------------------------------------------------------------------------------
Bool GetInputEvent(Int32 askdevice, BaseContainer& res);

	//----------------------------------------------------------------------------------------
	/// Polls a certain channel of a device for the current input state.\n
	/// If the return value is @formatConstant{true}, the container stored in @formatParam{res} is like an input event message, otherwise no state was available.\n
	/// For a list of valid devices and channels, see @link page_input_events Input Events@endlink.
	/// @param[in] askdevice					The device to poll.
	/// @param[in] askchannel					The channel of the device.
	/// @param[in] res								The result container.
	/// @return												@trueIfOtherwiseFalse{an input state could be retrieved}
	//----------------------------------------------------------------------------------------
Bool GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res);
#endif

/// Mouse position constant for ShowPopupMenu().
#define MOUSEPOS (0x7FFFFFFF)

//----------------------------------------------------------------------------------------
/// Displays a popup menu.\n
/// The menu is defined by adding string items sequentially to a base container. (The order the items are set in the container determines their order in the menu.)\n
/// The ID of the string item determines its function:
/// - A string with ID=@em 0 gives a separator
/// @code
/// bc.InsData(0, String(""));
/// @endcode
/// - A string with ID=@em 1 sets the name of the menu (used for sub-menus)
/// @code
/// bc.SetString(1, "Menu name");
/// @endcode
/// - IDs in the range @em 1000 to @em 899999 inserts a @C4D command
/// @code
/// bc.SetString(id, "CMD");
/// @endcode
/// For a list of IDs, see the @em c4d_symbols.coh file. A special case is the @ref IDM_CM_CLOSEWINDOW ID that will close the current dialog.
/// - The same applies to plugin IDs of plugins that have a menu entry (everything above @em 1000000)
/// @code
/// bc.SetString(pluginid, "CMD");
/// @endcode
/// - The IDs that are left, between @em 900000 (@ref FIRST_POPUP_ID) and @em 999999, can be used for custom menu items
/// @code
/// enum
/// {
/// 	FIRST_ITEM = FIRST_POPUP_ID,
/// 	SECOND_ITEM,
/// 	THIRD_ITEM
/// };
/// bc.SetString(FIRST_ITEM, "First item");
/// bc.SetString(SECOND_ITEM, "Second item");
/// bc.SetString(THIRD_ITEM, "Third item");
/// @endcode
/// Sub-menus are simply inserted as sub-containers
/// @code
/// enum
/// {
/// 	NEW_ENTRY = FIRST_POPUP_ID,
/// 	INSERT_NEW,
/// 		INSERT_DOC,
/// 		INSERT_OBJ
/// };
///
/// BaseContainer mainmenu;
/// mainmenu.SetString(NEW_ENTRY, "New");
///
/// BaseContainer submenu;
/// submenu.SetString(1, "Insert new");
/// submenu.SetString(INSERT_DOC, "Document");
/// submenu.SetString(INSERT_OBJ, "Object");
///
/// mainmenu.SetContainer(INSERT_NEW, submenu);
/// @endcode
/// - Disabled and checked items are marked with flags at the end of the name
/// @code
/// bc.SetString(..., "Disabled&d&");
/// bc.SetString(..., "Checked&c&");
/// @endcode
/// @param[in] cd									The internal parent dialog, or @formatConstant{nullptr}.
/// @param[in] screenx						The popup X position in screen pixels, or @ref MOUSEPOS to popup where the cursor is.
/// @param[in] screeny						The popup Y position in screen pixels, or @ref MOUSEPOS to popup where the cursor is.
/// @param[in] bc									The base container with the menu items.
/// @param[in] flags							The popup menu flags: @enumerateEnum{POPUP}
/// @param[in,out] res_mainid			The main id or @formatConstant{nullptr} if the id is returned normally by the function.
/// @return												The ID of the selected item, or @em 0 if nothing was selected.\n
/// 															Sometimes this is a a sub-id of a command, for instance if a command plugin returns a container with sub-items. In this case the main id is passed to @formatParam{res_mainid}.
//----------------------------------------------------------------------------------------
Int32 ShowPopupMenu(CDialog* cd, Int32 screenx, Int32 screeny, const BaseContainer& bc, Int32 flags = POPUP_RIGHT | POPUP_EXECUTECOMMANDS, Int32* res_mainid = nullptr);

//----------------------------------------------------------------------------------------
/// Sets the callback invoked when mouse cursor leaves a user area.
/// @note Useful to remove any highlighted element on mouse over.
/// @param[in] func								The last mouse cursor info callback. It should simply send ::BFM_CURSORINFO_REMOVE to the user area for the mouse leave event.
//----------------------------------------------------------------------------------------
Bool RemoveLastCursorInfo(LASTCURSORINFOFUNC func);

//----------------------------------------------------------------------------------------
/// Converts a shortcut to a readable string.
/// @param[in] shortqual					The shortcut qualifier.
/// @param[in] shortkey						The shortcut key.
/// @return												The shortcut string.
//----------------------------------------------------------------------------------------
String Shortcut2String(Int32 shortqual, Int32 shortkey);

//----------------------------------------------------------------------------------------
/// Converts a shortcut to a readable string.
/// @param[in] sc									The shortcut container.
/// @return												The shortcut string.
//----------------------------------------------------------------------------------------
String Shortcut2String(const BaseContainer& sc);

//----------------------------------------------------------------------------------------
/// Gets a GUI color from its constant ID.
/// @param[in] cid								The color ID. See COLOR constants.
/// @return												The GUI color.
//----------------------------------------------------------------------------------------
inline Vector GetGuiWorldColor(Int32 cid) { return C4DOS.Ge->GetGuiWorldColor(cid); }

//----------------------------------------------------------------------------------------
/// Converts an icon resource identity string into an ID.
/// @param[in] id									The ID of the icon resource string.
/// @param[in] ident							The icon resource identity string. Look them up in the resource file for schemes.
/// @return												@trueIfOtherwiseFalse{the icon resource identity string was found}
//----------------------------------------------------------------------------------------
Bool GetIconCoordInfo(Int32& id, const Char* ident);

/// @addtogroup INTERFACE_ICON_TYPE
/// @ingroup group_enumeration
/// @{
#define INTERFACE_ICON_TYPE_NORMAL		0			///< Normal.
#define INTERFACE_ICON_TYPE_DISABLED	1			///< Disabled.
#define INTERFACE_ICON_TYPE_FOCUS			2			///< Focus.
/// @}

//----------------------------------------------------------------------------------------
/// Retrieves the icon for an interface element.
/// @param[in] type								The icon type: @enumerateEnum{INTERFACE_ICON_TYPE}
/// @param[in] id_x								The X position ID of the icon.
/// @param[in] id_y								The Y position ID of the icon.
/// @param[in] id_w								The width ID of the icon.
/// @param[in] id_h								The height ID of the icon.
/// @param[out] d									Assigned the retrieved icon resource data.
/// @return												The icon could be retrieved.
//----------------------------------------------------------------------------------------
Bool GetInterfaceIcon(Int32 type, Int32 id_x, Int32 id_y, Int32 id_w, Int32 id_h, IconData& d);


class ProgressDialog;
#ifdef __API_INTERN__
	#define C4DThread BaseThread
#endif

//----------------------------------------------------------------------------------------
/// @markInternal
//----------------------------------------------------------------------------------------
class ProgressThread : public C4DThread
{
public:
	virtual void Main(void);
	virtual const Char* GetThreadName(void);

	Bool Start(ProgressDialog* pdlg);
	void End();

private:
	ProgressDialog* AcquireAndLock();
	void AcquireAndClearLock();
	void MarkAsInClose(ProgressDialog* pdlg);
	void ReleaseLock(ProgressDialog* pdlg);

private:
	// keeps the memory layout compatible.
	maxon::AtomicPtr<ProgressDialog> dlg;
};

//----------------------------------------------------------------------------------------
/// This class is especially designed for progress dialogs.\n
/// Here is an implementation:
/// @code
/// class MyProgressDialog : public ProgressDialog
/// {
/// public:
/// 	virtual Bool CreateLayout(void);
/// 	virtual Bool InitValues(void);
///
/// 	virtual void Main(C4DThread *bt);
/// 	virtual String GetTitle(void) { return String("Progress"); }
/// };
///
/// Bool MyProgressDialog::CreateLayout()
/// {
/// 	return ProgressDialog::CreateLayout();
/// }
///
/// Bool MyProgressDialog::InitValues()
/// {
/// 	return ProgressDialog::InitValues();
/// }
///
/// void MyProgressDialog::Main(C4DThread *bt)
/// {
/// 	Int64 cnt = 100000000;
///
/// 	SetPercent(0.f);
///
/// 	for (Int64 i=0; i<cnt; i++)
/// 	{
/// 		SetPercent((Float)i/cnt);
/// 	}
///
/// 	SetPercent(1.f);
/// }
///
/// // Calling code
///
/// MyProgressDialog dlg;
/// return dlg.Open();
/// @endcode
//----------------------------------------------------------------------------------------
class ProgressDialog : public GeModalDialog
{
private:
	ProgressThread thread;
	Float percent;
	maxon::Spinlock deprecatedCallback_lock;
	void* (*deprectatedCallback)(void* context) = nullptr;
	void* deprectatedCallback_context = nullptr;
	void* deprectatedCallback_result = nullptr;

public:
	/// @name Modal Dialog
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is about to be displayed. Override this method to define the layout of the dialog.\n
	/// Either use the recommended @ref LoadDialogResource function or the manual functions (for example AddButton()).
	/// See @link page_dialog_layout Dialog Layout@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool CreateLayout(void);

	//----------------------------------------------------------------------------------------
	/// Called when the dialog is initialized by the GUI. Override this method to initialize local variables and the gadgets used.
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitValues(void);

	//----------------------------------------------------------------------------------------
	/// Called when a timer event is received.\n
	/// To subscribe to timer events use SetTimer().
	/// @param[in] msg								The timer message container.
	//----------------------------------------------------------------------------------------
	virtual void Timer(const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when a message is received.\n
	/// Override this function to react to special messages.\n
	/// Normally this is not necessary. Be sure to include a call the parent version of this function, ProgressDialog::Message(msg, result).
	/// @see The article @link page_gui_messages GUI Messages@endlink for more information.
	/// @param[in] msg								The message container.
	/// @param[in] result							A container to place results in.
	/// @return												Depends on the message.
	//----------------------------------------------------------------------------------------
	virtual Int32 Message(const BaseContainer& msg, BaseContainer& result);

	//----------------------------------------------------------------------------------------
	/// Whenever the user clicks on a gadget and/or changes its value this function will be called. It is also called when a string menu item is selected. Override this methods to handle such events.
	/// @note Remember StopAllThreads() must be called before making modifications to the scene.
	/// @param[in] id									The ID of the gadget that triggered the event.
	/// @param[in] msg								The message container. Contains the following values: @ref BFM_ACTION_ID and @ref BFM_ACTION_VALUE.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Command(Int32 id, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// If the user wants to close the dialog with the OK button this function will be called. Override it to avoid closing the dialog if an error situation has occurred.\n
	/// If @formatConstant{false} is returned everything will be as usual, but if @formatConstant{true} is returned the dialog will not close.
	/// @warning A buggy function, always returning @formatConstant{true}, will lead to a frustrating user experience.
	/// @return												@formatConstant{true} if the dialog should not be closed, @formatConstant{false} if it should.
	//----------------------------------------------------------------------------------------
	virtual Bool AskClose(void);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the progress bar.
	/// @param[in] p									The percentage for the progress bar. Goes from @em 0.0 to @em 1.0 (@em 0-@em 100%).
	//----------------------------------------------------------------------------------------
	void SetPercent(Float p);

	//----------------------------------------------------------------------------------------
	/// Gets the calling thread for the dialog.
	/// @return												The calling thread.
	//----------------------------------------------------------------------------------------
	C4DThread* GetThread(void);

	/// @}

	/// @name Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to execute code within the progress thread.
	/// @param[in] bt									The progress thread.
	//----------------------------------------------------------------------------------------
	virtual void Main(C4DThread* bt) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to retrieve the title of the progress dialog.
	/// @return												The title.
	//----------------------------------------------------------------------------------------
	virtual String GetTitle(void) = 0;

	/// @}
};

//----------------------------------------------------------------------------------------
/// Returns true when the current/preferred input device is a graphic tablet.
/// @since R20
/// @return												True for tablet input.
//----------------------------------------------------------------------------------------
Bool GeIsTabletMode();

//----------------------------------------------------------------------------------------
/// Retrieves the mouse move delta (threshold) depending on the input device.
/// @since R19
/// @return												The mouse move delta.
//----------------------------------------------------------------------------------------
Float GetMouseMoveDelta();

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R16
//----------------------------------------------------------------------------------------
void SetBakeStatus(Bool state);

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R16
//----------------------------------------------------------------------------------------
Bool GetBakeStatus();

//----------------------------------------------------------------------------------------
/// GetDnDFilename extracts the Filename from the given drag and drop data returned by GetDragObject()
/// @param[in] msg								Drag and Drop message.
/// @param[in] dragType						Drag type returned by GetDragObject().
/// @param[in] dragObj						Drag object returned by GetDragObject().
/// @param[in] texturesOnly				True to check for textures only.
/// @param[in] updateUsage				True to update the usage stats of the asset.
/// @param[in] loadUrl						True to show a modal progress dialog when files need to be downloaded.
/// @return                       Filename on success. Filename IsEmpty() if no data was found.
//----------------------------------------------------------------------------------------
Filename GetDnDFilename(const BaseContainer& msg, Int32 dragType, const void* dragObj, Bool texturesOnly, Bool updateUsage, Bool loadUrl);


//----------------------------------------------------------------------------------------
/// Helper class to create a scoped WaitPointer.
/// example 1:
/// @code
/// {
///		AutoWaitPointer waitPointer(true); // show the wait pointer immediately until object is destroyed
/// }
/// @endcode
/// example 2:
/// @code
/// {
///		AutoWaitPointer waitPointer;
///		...
///		waitPointer.SetBusy(); // show the wait pointer from here until object is destroyed
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class AutoWaitPointer
{
public:
	//----------------------------------------------------------------------------------------
	/// AutoWaitPointer constructor.
	/// @param[in] setBusy						True to make the wait pointer immediately visible.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT AutoWaitPointer(Bool setBusy = false);

	//----------------------------------------------------------------------------------------
	/// ~AutoWaitPointer reverts the mouse pointer to normal state.
	//----------------------------------------------------------------------------------------
	~AutoWaitPointer();

	//----------------------------------------------------------------------------------------
	/// SetBusy displays the wait pointer.
	//----------------------------------------------------------------------------------------
	void SetBusy();

	//----------------------------------------------------------------------------------------
	/// SetNormal displays the normal mouse pointer
	//----------------------------------------------------------------------------------------
	void SetNormal();

private:
	Bool _set = false;
};


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_GUI_H__
