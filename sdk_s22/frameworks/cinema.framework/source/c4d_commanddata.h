/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_COMMANDDATA_H__
#define C4D_COMMANDDATA_H__

#include "c4d_basedata.h"

class String;
class BaseContainer;
class BaseDocument;
class BaseBitmap;
class GeDialog;

/// @see CommandData::RestoreLayout
struct RestoreLayoutSecret
{
	Int32     subid; ///< The sub-ID of the dialog to restore.
	GeDialog* dlg;   ///< The dialog itself if available. @Note: When dlg==nullptr you have to manually create a new dialog with the given subid. Else the dialog was already created.
};

/// @addtogroup PLUGINFLAG_COMMAND
/// @ingroup group_enumeration
/// @{
#define PLUGINFLAG_COMMAND_HOTKEY					(1 << 27)			///< Command is a hotkey command. Hotkey commands can only work globally.
#define PLUGINFLAG_COMMAND_OPTION_DIALOG	(1 << 26)			///< Command has additional options. The user can access them through a small gadget.
#define PLUGINFLAG_COMMAND_STICKY					(1 << 25)			///< Command is a "sticky" command. This means CommandData::Execute() is called when the user presses an assigned hotkey and when the hotkey is released. Otherwise the command would be called continuously.
#define PLUGINFLAG_COMMAND_ICONGADGET			(1 << 24)			///< Command can be dragged into an icon bar and delivers its own dialogs instead of icons.
/// @}

/// @addtogroup MSG_COMMAND
/// @ingroup group_enumeration
/// @see CommandData::Message
/// @{
#define MSG_COMMANDINFORMATION	300001001			///< Sent to retrieve command information. The corresponding @em data is CommandInformationData.
#define MSG_BODYPAINTEXCHANGE		300001002			///< For BodyPaint3D messages.
/// @}

#define TOOLHOTKEY_RECEIVER			200000290			///< Special tool hotkey overwrite for command plugins.

/// @see ::MSG_COMMANDINFORMATION
struct CommandInformationData
{
	Int32 command_id;				///< Command ID. (Read)

	Int32 managergroup;			///< Manager group. (Write)
	Int32 parentid;					///< Parent ID. (Write)
};

//----------------------------------------------------------------------------------------
/// A data class for creating command plugins. (Previously known as menu plugins.)\n
/// Use RegisterCommandPlugin() to register a command plugin.
//----------------------------------------------------------------------------------------
class CommandData : public BaseData
{
public:
	//----------------------------------------------------------------------------------------
	/// Executes the command.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @return												@trueIfOtherwiseFalse{the command was executed successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool Execute(BaseDocument* doc, GeDialog* parentManager);

	//----------------------------------------------------------------------------------------
	/// Executes the command with the sub-command ID that was given by GetSubContainer().
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] subid							The sub-command ID.
	/// @return												@trueIfOtherwiseFalse{the command was executed successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool ExecuteSubID(BaseDocument* doc, Int32 subid, GeDialog* parentManager);

	//----------------------------------------------------------------------------------------
	/// Executes the command when the user calls it through its options dialog.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] plugid							The command plugin ID.
	/// @param[in] subid							The sub-command ID. Only available for plugins that have sub-IDs (which normally are called using ExecuteSubID).
	/// @return												@trueIfOtherwiseFalse{the command was executed successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool ExecuteOptionID(BaseDocument* doc, Int32 plugid, Int32 subid, GeDialog* parentManager);

	//----------------------------------------------------------------------------------------
	/// Called to get the state of the command.
	/// @note Affects how it is displayed in menus and toolbars.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @return												A combination of the 2 command flags: @ref CMD_ENABLED @ref CMD_VALUE.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetState(BaseDocument* doc, GeDialog* parentManager);

	//----------------------------------------------------------------------------------------
	/// Called to get the command sub-menu.\n
	/// Container @formatParam{submenu} is passed to create dynamic sub-container entries.
	/// @note	The menu entries on the top level will all be placed at the point where the command plugin was placed.\n
	///				To create a sub-menu, place the entries as sub-containers in the returned container with ID @em 0. In the sub-container, place a string with ID @em 1 to name it:
	///				@code
	///				BaseContainer bc;
	///				bc.SetString(1, "Submenu Test");
	///				bc.SetString(1000, "First Entry");
	///				submenu.InsData(0, bc);
	///				@endcode
	/// Use <i>&d&</i> and <i>&c&</i> to disable and check items.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] submenu						Fill with the sub-menu structure.
	/// @return												@trueIfOtherwiseFalse{the sub-menu container was filled}
	//----------------------------------------------------------------------------------------
	virtual Bool GetSubContainer(BaseDocument* doc, BaseContainer& submenu, GeDialog* parentManager);

	//----------------------------------------------------------------------------------------
	/// Called when loading a layout and restoring async dialogs.
	/// @warning	If implemented then it must create the @c dialog and call @c dialog->RestoreLayout.\n
	///						If the command has more than one dialog, RestoreLayoutSecret::subid gives the ID of the sub-dialog to restore.
	/// @note If not implemented @C4D will create an empty @em "???" dialog.
	/// @param[in] secret							Points to a RestoreLayoutSecret structure.
	/// @return												@trueIfOtherwiseFalse{the dialog was restored}
	//----------------------------------------------------------------------------------------
	virtual Bool RestoreLayout(void* secret);

	//----------------------------------------------------------------------------------------
	/// Called to get the script name of the command.
	/// @note If implemented the command is stored by name rather than by ID in layouts, shortcuts and menus.
	/// @return												The script name for the command.
	//----------------------------------------------------------------------------------------
	virtual String GetScriptName(void);

	//----------------------------------------------------------------------------------------
	/// Called to respond to command messages.
	/// @param[in] type								The message type: @enumerateEnum{MSG_COMMAND}
	/// @param[in] data								The message data. Depends on the command message @formatParam{type}.
	/// @return												@trueIfOtherwiseFalse{the message was processed}
	//----------------------------------------------------------------------------------------
	virtual Bool Message(Int32 type, void* data);
};

//----------------------------------------------------------------------------------------
/// Registers a command plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
///																To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
///																Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The command plugin info flags: @enumerateEnum{PLUGINFLAG_COMMAND} @enumerateEnum{PLUGINFLAG}
/// @param[in] icon								The icon for the command. The bitmap is copied. \n
///																The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
///																It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] help								The tool tips and status bar help text for the command.\n
///																When using strings it is advised to use the resources string (<i>.str</i>) files and the GeLoadString() function.\n
///																This keeps the plugin easy to localize for any language to support and makes full use of the language features of @C4D.
/// @param[in] dat								The command data instance for the plugin. @C4D takes over the ownership of the pointed command data.
/// @return												@trueIfOtherwiseFalse{the command plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterCommandPlugin(Int32 id, const maxon::String& str, Int32 info, BaseBitmap* icon, const maxon::String& help, CommandData* dat);

//----------------------------------------------------------------------------------------
/// Registers manager information for use when registering shortcuts with AddShortcut().
/// @param[in] id									@uniquePluginID
/// @param[in] str								The manager name.
/// @param[in] info								The manager info flags: @enumerateEnum{PLUGINFLAG}
/// @return												@trueIfOtherwiseFalse{the manager was registered}
//----------------------------------------------------------------------------------------
Bool RegisterManagerInformation(Int32 id, const maxon::String& str, Int32 info);

#endif // C4D_COMMANDDATA_H__
