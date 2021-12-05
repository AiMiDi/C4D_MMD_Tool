/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_TOOLDATA_H__
#define C4D_TOOLDATA_H__

#include "c4d_basedata.h"
#include "customgui_description.h"

class AtomArray;
class String;
class BaseContainer;
class BaseBitmap;
class BaseDocument;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseThread;
class CDialog;
class EditorWindow;
class SubDialog;

enum class VERTEXCOLOR_DISPLAYMODE
{
	NONE = 0,
	COLOR,
	ALPHA
} MAXON_ENUM_FLAGS(VERTEXCOLOR_DISPLAYMODE);

//----------------------------------------------------------------------------------------
/// DisplayControl data.
//----------------------------------------------------------------------------------------
struct ControlDisplayStruct
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	ControlDisplayStruct() : displaymode(DISPLAYMODE::UNKNOWN), backface_culling(false), editmode(false), vertex_color(nullptr), dontfreevertexcolor(false), vertex_color_shading(false), perPolygonVertexColor(false), vertexColorDisplayMode(VERTEXCOLOR_DISPLAYMODE::NONE) { }

	DISPLAYMODE displaymode;									///< The display mode: @enumerateEnum{DISPLAYMODE}
	Bool backface_culling;										///< Backface culling.
	Bool editmode;												///< Edit mode.
	Vector32* vertex_color;										///< An array of vertex colors for each point.
	Bool dontfreevertexcolor;									///< If @formatConstant{false}, the caller frees @ref vertex_color. If @formatConstant{true}, the called function owns the memory, the caller does not free @ref vertex_color.
	Bool vertex_color_shading;									///< Vertex color shading.
	Bool perPolygonVertexColor;									///< Each polygon vertex own a specific color. @since R18
	VERTEXCOLOR_DISPLAYMODE vertexColorDisplayMode;             /// Is set to ALPHA only if paint tool is active and mode is vertexColor(Alpha), is set to COLOR if the tool is active and the mode is vertexColor(RGB) or vertexColor(RGB + Alpha), and set to NONE if the tool is inactive.
};

//----------------------------------------------------------------------------------------
/// Helper class for the editor's window.
//----------------------------------------------------------------------------------------
class EditorWindow
{
private:
	EditorWindow();
	~EditorWindow();

public:
	//----------------------------------------------------------------------------------------
	/// @markDeprecated
	/// Draws an XOR line in the editor view.
	/// @param[in] x1									Start X coordinate of the line.
	/// @param[in] y1									Start Y coordinate of the line.
	/// @param[in] x2									End X coordinate of the line.
	/// @param[in] y2									End Y coordinate of the line.
	//----------------------------------------------------------------------------------------
	void DrawXORLine(Int32 x1, Int32 y1, Int32 x2, Int32 y2);

	//----------------------------------------------------------------------------------------
	/// Initializes a mouse dragging loop.\n
	/// For example:
	/// @code
	/// BaseContainer bc;
	/// BaseContainer device;
	/// win->MouseDragStart(button, mx, my, MOUSEDRAGFLAGS::NOMOVE);
	/// while (win->MouseDrag(&dx, &dy, &device)==MOUSEDRAGRESULT::CONTINUE)
	/// {
	/// }
	/// @endcode
	/// @param[in] button							State of the mouse buttons, passed through from ToolData::MouseInput. See @ref BFM_INPUT.
	/// @param[in] mx									Mouse X coordinate.
	/// @param[in] my									Mouse Y coordinate.
	/// @param[in] flag								The mouse drag flags: @enumerateEnum{MOUSEDRAGFLAGS}
	//----------------------------------------------------------------------------------------
	void MouseDragStart(Int32 button, Float mx, Float my, MOUSEDRAGFLAGS flag);

	//----------------------------------------------------------------------------------------
	/// Checks for the mouse drag status.
	/// @note To check for qualifiers, see the channels container:
	/// @code
	/// while (win->MouseDrag(&dx, &dy, &channels)==MOUSEDRAGRESULT::CONTINUE)
	/// {
	/// 	if (channels.GetInt32(BFM_INPUT_QUALIFIER) & QSHIFT) shift = true;
	/// 	if (channels.GetInt32(BFM_INPUT_QUALIFIER) & QCTRL) ctrl = true;
	/// 	...
	/// }
	/// @endcode
	/// @param[in] mx									Mouse X coordinate.
	/// @param[in] my									Mouse Y coordinate.
	/// @param[in] channels						A container to take the state of the mouse: @enumerateEnum{PEN}
	/// @return												The mouse drag result: @enumerateEnum{MOUSEDRAGRESULT}
	//----------------------------------------------------------------------------------------
	MOUSEDRAGRESULT MouseDrag(Float* mx, Float* my, BaseContainer* channels);

	//----------------------------------------------------------------------------------------
	/// Checks why the mouse drag ended. Allows to perform any undo operations needed if the user canceled the drag.
	/// @return												The mouse drag result: @enumerateEnum{MOUSEDRAGRESULT}
	//----------------------------------------------------------------------------------------
	MOUSEDRAGRESULT MouseDragEnd(void);

	//----------------------------------------------------------------------------------------
	/// Gets the status of an input device.
	/// @param[in] askdevice					The device: @ref BFM_INPUT_MOUSE or @ref BFM_INPUT_KEYBOARD.
	/// @param[in] askchannel					The channel: @enumerateEnum{BFM_INPUT}
	/// @param[in] res								A container to take the input state results.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool BfGetInputState(Int32 askdevice, Int32 askchannel, BaseContainer* res);

	//----------------------------------------------------------------------------------------
	/// Gets the status of an input device from the event queue if present.
	/// @param[in] askdevice					The device: @ref BFM_INPUT_MOUSE or @ref BFM_INPUT_KEYBOARD.
	/// @param[in] res								A container to take the input event results.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool BfGetInputEvent(Int32 askdevice, BaseContainer* res);

	//----------------------------------------------------------------------------------------
	/// Checks the standard navigation hotkeys.
	/// @param[in] id									The hotkey to check: @enumerateEnum{HOTKEY}
	/// @return												A value != 0 if the hotkey is pressed.
	//----------------------------------------------------------------------------------------
	HOTKEYFLAGS IsHotkeyDown(Int32 id);

	//----------------------------------------------------------------------------------------
	/// Sets the text in the status bar.
	/// @param[in] str								The text for the status bar.
	//----------------------------------------------------------------------------------------
	void StatusSetText(const maxon::String& str);

	//----------------------------------------------------------------------------------------
	/// Transforms screen coordinates (relative to the top left corner of the system screen) to local coordinates (relative to the top left corner of a user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The screen X coordinate. Assigned the converted local coordinate.
	/// @param[in,out] y							The screen Y coordinate. Assigned the converted local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Screen2Local(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of a user area) to screen coordinates (relative to the top left corner of the system screen). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the screen coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the screen coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Screen(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms global window coordinates (relative to the top left corner of the application window) to local coordinates (relative to the top left corner of a user area). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The global window X coordinate. Assigned the local coordinate.
	/// @param[in,out] y							The global window Y coordinate. Assigned the local coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Global2Local(Int32* x, Int32* y);

	//----------------------------------------------------------------------------------------
	/// Transforms local coordinates (relative to the top left corner of the user area) to global window coordinates (relative to the top left corner of the application window). Stores the result in *@formatParam{x} and *@formatParam{y}.
	/// @param[in,out] x							The local X coordinate. Assigned the global window coordinate.
	/// @param[in,out] y							The local Y coordinate. Assigned the global window coordinate.
	/// @return												@trueIfOtherwiseFalse{the coordinates were converted}
	//----------------------------------------------------------------------------------------
	Bool Local2Global(Int32* x, Int32* y);
};

/// @addtogroup PEN
/// @ingroup group_enumeration
/// @{
/// @ref EditorWindow::MouseDrag channel container IDs.
enum
{
	PENPRESSURE						= 1,			///< Pressure.
	PENTILT								= 2,			///< Tilt.
	PENROTATION						= 3,			///< Rotation.
	PENDRAWROTATION				= 4,			///< Draw rotation.
	PENDRAWRANDOMNESS			= 5,			///< Draw randomness.
	PENDRAWWHEELROTATION	= 6,			///< Draw wheel rotation.
	PENDRAWWHEELPRESSURE	= 7,			///< Draw wheel pressure.
	PENDRAWDISTANCE				= 8,			///< Draw distance.
	PENFINGERWHEEL				= 9				///< Finger wheel
};
/// @}

/// @addtogroup PLUGINFLAG_TOOL
/// @ingroup group_enumeration
/// @{
#define PLUGINFLAG_TOOL_EVALUATEHANDLES			(1 << 1)									///< Evaluate object handles when tool is active. (Otherwise they are ignored.)
#define PLUGINFLAG_TOOL_DRAW_MULTIPLANE			(1 << 2)									///< Draw multiple planes.
#define PLUGINFLAG_TOOL_TWEAK								(1 << 3)									///< Tweak mode supported.
#define PLUGINFLAG_TOOL_HIGHLIGHT						(1 << 4)									///< Highlighting supported.
#define PLUGINFLAG_TOOL_EDITSTATES					(1 << 5)									///< Edit states supported.
#define PLUGINFLAG_TOOL_SNAPSETTINGS				(1 << 6)									///< Snap settings supported.
#define PLUGINFLAG_TOOL_SINGLECLICK					(1 << 7)									///< Single click tool.
#define PLUGINFLAG_TOOL_TWEAK_NO_HIGHLIGHT	((1 << 3) | (1 << 8))			///< Tweak mode with no highlighting.
#define PLUGINFLAG_TOOL_NO_WIREFRAME				(1 << 9)									///< Wireframe not supported.
#define PLUGINFLAG_TOOL_SCULPTBRUSH					(1 << 10)									///< Tool is a sculpt brush.
#define PLUGINFLAG_TOOL_NO_OBJECTOUTLINE		(1 << 11)									///< Object outlines on selection not supported.
#define PLUGINFLAG_TOOL_OBJECTHIGHLIGHT			(1 << 12)									///< Object outlines during mouse-over supported.
#define PLUGINFLAG_TOOL_SWITCHACTION				(1 << 13)									///< Allow the tool to switch to a different tool on modifier. @since R17.032
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating tool plugins.\n
/// Use RegisterToolPlugin() to register a tool plugin.
/// @note To make modeling tools that support the Transform/Apply buttons use DescriptionToolData instead.
//----------------------------------------------------------------------------------------
class ToolData : public BaseData
{
	friend Bool RegisterToolPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, ToolData* dat);
	friend Bool RegisterPyToolPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, ToolData* dat, GeResource *res);

private:
	virtual CDialog* AllocDialog(BaseContainer* bc, CDialog* cd_parent, Int32 dlg_id);
	virtual void FreeDialog(CDialog* cd);

public:
	/// @name Init/Free Tool
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called each time the tool is selected.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitTool(BaseDocument* doc, BaseContainer& data, BaseThread* bt);

	//----------------------------------------------------------------------------------------
	/// Called each time the user chooses another tool.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	//----------------------------------------------------------------------------------------
	virtual void FreeTool(BaseDocument* doc, BaseContainer& data);

	/// @}

	/// @name Input
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when the user clicks with the mouse in any of the editors views.\n
	/// Use @ref GetToolScale to make adjustments relative to the view size.
	/// @note If a tool allows the user to move, rotate or scale the currently selected object, then it should call @ref GeSyncMessage(@ref EVMSG_ASYNCEDITORMOVE) so that managers can update their position fields during the drag.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] win								The window for the active editor view. @cinemaOwnsPointed{editor window}
	/// @param[in] msg								The mouse message container. See @link page_input_events Input Events@endlink.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool MouseInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when the user types something in any of the editors views.
	/// @note Make sure this function is used only when the user is somehow working with the tool plugin, so that other plugins can also use this hook when it is their turn.
	/// @warning Always returning @formatConstant{true} here will block all keyboard use.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] win								The window for the active editor view. @cinemaOwnsPointed{editor window}
	/// @param[in] msg								The keyboard message container. See @link page_input_events Input Events@endlink.
	/// @return												@formatConstant{true} if the keyboard event was used, @formatConstant{false} if it should be passed along.
	//----------------------------------------------------------------------------------------
	virtual Bool KeyboardInput(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when the editor view is updated to display graphics for the tool in the view.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{base draw helper}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @param[in] flags							The tool draw flags: @enumerateEnum{TOOLDRAWFLAGS}
	/// @return												The tool draw result: @enumerateEnum{TOOLDRAW}
	//----------------------------------------------------------------------------------------
	virtual TOOLDRAW Draw(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, TOOLDRAWFLAGS flags);

/// @}

	/// @name DisplayControl
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to set information about how the active object should be displayed.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] op									The active object. @cinemaOwnsPointed{object}
	/// @param[in] chainstart					The start of the object chain. @cinemaOwnsPointed{object}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
	/// @param[in] cds								The display control settings.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);

	//----------------------------------------------------------------------------------------
	/// Called to initialize resources for the display control used in @ref DisplayControl.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] active							The active objects array. @cinemaOwnsPointed{array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitDisplayControl(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// Called to free resources allocated in @ref InitDisplayControl.
	//----------------------------------------------------------------------------------------
	virtual void FreeDisplayControl(void);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get the sub-dialog for the Active Tool window.\n
	/// Return here an instance of the tool's sub-dialog.
	/// @param[in] bc									Currently not used.
	/// @return												The allocated sub-dialog. @cinemaOwnsPointed{sub-dialog}
	//----------------------------------------------------------------------------------------
	virtual SubDialog* AllocSubDialog(BaseContainer* bc);

	//----------------------------------------------------------------------------------------
	/// Called by @ref SendModelingCommand to perform the command in @formatParam{mdat}.
	/// @param[in] mdat								The data for the modeling command to perform.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool DoCommand(ModelingCommandData& mdat);

	//----------------------------------------------------------------------------------------
	/// Called when the cursor is over the editor views to get the state of the mouse pointer.\n
	/// Set the bubble help and cursor, for example:
	/// @code
	/// bc.SetString(RESULT_BUBBLEHELP, "My Tools Help");
	/// bc.SetInt32(RESULT_CURSOR, MOUSE_POINT_HAND);
	/// @endcode
	/// @note Make sure this function is used only when the user is somehow working with the scene hook plugin, so that other plugins can also use this hook when it is their turn.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] x									The X coordinate of the mouse cursor relative to the top-left of the active editor view.
	/// @param[in] y									The Y coordinate of the mouse cursor relative to the top-left of the active editor view.
	/// @param[in] bc									The container to store the cursor information in: @link RESULT_CURSOR BFM_GETCURSORINFO_RESULT@endlink
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool GetCursorInfo(BaseDocument* doc, BaseContainer& data, BaseDraw* bd, Float x, Float y, BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Called to get the description resource symbol for the tool.
	/// @return												The name of the description resource file to use for the plugin without .res extension, for example @em "Toolname".\n
	///																The name has to be unique, i.e. @em "Tdisplay" cannot be used for two different descriptions. See Description Resource for more information.
	//----------------------------------------------------------------------------------------
	virtual const String GetResourceSymbol();

	//----------------------------------------------------------------------------------------
	/// Called to check if the tool should be enabled or not.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @return												A combination of the 2 command flags: @ref CMD_ENABLED @ref CMD_VALUE.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetState(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Called to initialize the default tool settings in @formatParam{data}.
	/// @param[in] pDoc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	//----------------------------------------------------------------------------------------
	virtual void InitDefaultSettings(BaseDocument* pDoc, BaseContainer& data);

	/// @}

	/// @name Description
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to add parameters to the description for the tool.\n
	/// Modify the passed @formatParam{description} as needed, set the appropriate @formatParam{flags} and then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDescription(data, description, flags, parentdescription);
	/// @endcode
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in,out] description		The node's description to add the parameters to. @cinemaOwnsPointed{description}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDDescription(BaseDocument* doc, BaseContainer& data, Description* description, DESCFLAGS_DESC& flags);

	//----------------------------------------------------------------------------------------
	/// Called to override the reading of description parameters.\n
	/// Necessary for parameters that are not simply stored in the tool's container.\n
	/// Modify the passed @formatParam{t_data} if the right @formatParam{id} is provided, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDParameter(data, id, t_data, flags);
	/// @endcode
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						The parameter data to return. @cinemaOwnsPointed{data}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to override the writing of parameters.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, store the data, and set the appropriate @formatParam{flags}. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::SetDParameter(data, id, t_data, flags);
	/// @endcode
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The parameter data to set. @cinemaOwnsPointed{data}
	/// @param[in,out] flags					The flags for the description operation: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{successful} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool SetDParameter(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);

	//----------------------------------------------------------------------------------------
	/// Called to decide which description parameters should be enabled or disabled.\n
	/// Can be used both for parameters that are stored in the tool's description and for dynamic parameters.\n
	/// Read the passed @formatParam{t_data} if the right @formatParam{id} was provided, and return @formatConstant{true} to enable the parameter or @formatConstant{false} to disable it. Then make sure to include a call to the parent at the end:
	/// @code
	/// return SUPER::GetDEnabling(data, id, t_data, flags, itemdesc);
	/// @endcode
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The parameter data. @cinemaOwnsPointed{data}
	/// @param[in] flags							Not used.
	/// @param[in] itemdesc						The parameter's description, encoded to a container as described in Description.
	/// @return												@trueIfOtherwiseFalse{the parameter should be enabled} It is recommended to include a call to the parent function as last return.
	//----------------------------------------------------------------------------------------
	virtual Bool GetDEnabling(BaseDocument* doc, BaseContainer& data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// Called by the Attribute Manager for every object and every description ID.\n
	/// Gives the opportunity to route a description ID in the description of a tool to another one.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] id									The source description ID.
	/// @param[out] res_id						Assign the target description ID.
	/// @param[out] res_at						Assign the target object.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool TranslateDescID(BaseDocument* doc, BaseContainer& data, const DescID& id, DescID& res_id, C4DAtom*& res_at);

	/// @}

	/// @name Message
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called when a tool receives messages.\n
	/// For example description messages such as @ref MSG_DESCRIPTION_COMMAND are sent here.
	/// @see C4DAtom::Message
	/// @note Some notification messages are automatically passed along to branches: @ref MSG_POINTS_CHANGED, @ref MSG_POLYGONS_CHANGED and @ref MSG_SEGMENTS_CHANGED. This is for convenience and historical reasons.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	/// @param[in] type								The message type: @enumerateEnum{MSG}
	/// @param[in,out] t_data					The message data. @senderOwnsPointed{data}
	/// @return												@formatConstant{true} or @formatConstant{false} depending on the message @formatParam{type}.
	//----------------------------------------------------------------------------------------
	virtual Bool Message(BaseDocument* doc, BaseContainer& data, Int32 type, void* t_data);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Gets the data container for the tool with ID @formatParam{pluginid}.
/// @param[in] doc								The document to get the settings for. @callerOwnsPointed{document}
/// @param[in] pluginid						The plugin ID of the tool to get the data for.
/// @return												The tool data container. @cinemaOwnsPointed{container}
//----------------------------------------------------------------------------------------
BaseContainer* GetToolData(BaseDocument* doc, Int32 pluginid);

//----------------------------------------------------------------------------------------
/// Retrieves the scale between the local size of the objects in @formatParam{arr} and their screen size in @formatParam{bd}. The scale is quantized to a power of @em 10.\n
/// For example:\n
/// <table cellspacing="6" border="0">
/// <tr>
/// <th>Object size (units)</th>
/// <th>Screen size (px)</th>
/// <th>Scale</th>
/// </tr>
/// <tr>
/// <td valign="top"><p>100</p></td>
/// <td valign="top"><p>100</p></td>
/// <td valign="top"><p>1</p></td>
/// </tr>
/// <tr>
/// <td valign="top"><p>100</p></td>
/// <td valign="top"><p>900</p></td>
/// <td valign="top"><p>1</p></td>
/// </tr>
/// <tr>
/// <td valign="top"><p>100</p></td>
/// <td valign="top"><p>1001</p></td>
/// <td valign="top"><p>0.1</p></td>
/// </tr>
/// <tr>
/// <td valign="top"><p>100</p></td>
/// <td valign="top"><p>10</p></td>
/// <td valign="top"><p>10</p></td>
/// </tr>
/// </table>
/// @note Useful to make mouse movements relative to the view size.
/// @param[in] bd									The view to check the scale in. @callerOwnsPointed{base draw}
/// @param[in] arr								The array with objects to check. @callerOwnsPointed{array}
/// @param[in] all								If @formatConstant{true} all points are used for the calculation. If @formatConstant{false} the selection is used. If @ref NOTOK the function checks if something is selected.
/// @param[in] mode								::NOTOK to use the bounding box (default) or @ref Mpoints/@ref Medges/@ref Mpolygons.
/// @return												The calculated scale.
//----------------------------------------------------------------------------------------
Float GetToolScale(BaseDraw* bd, AtomArray* arr, Int32 all, Int32 mode = NOTOK);

//----------------------------------------------------------------------------------------
/// Registers a tool plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
///																To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
///																Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The tool plugin info flags: @enumerateEnum{PLUGINFLAG_TOOL} @enumerateEnum{PLUGINFLAG}
/// @param[in] icon								The icon for the tool. The bitmap is copied. \n
///																The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
///																It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] help								The tool tips and status bar help text for the tool.\n
///																When using strings it is advised to use the resources string (@em .str) files and the GeLoadString() function.\n
///																This keeps the plugin easy to localize for any language to support and makes full use of the language features of @C4D.
/// @param[in] dat								The tool data instance for the plugin. @C4D takes over the ownership of the pointed tool data.
/// @return												@trueIfOtherwiseFalse{the tool plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterToolPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, ToolData* dat);

#endif // C4D_TOOLDATA_H__
