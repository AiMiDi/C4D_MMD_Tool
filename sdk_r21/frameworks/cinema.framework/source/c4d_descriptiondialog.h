/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_DESCRIPTIONDIALOG_H__
#define C4D_DESCRIPTIONDIALOG_H__

#ifdef __API_INTERN__
abc def xyz
#endif

#include "c4d_tooldata.h"

//----------------------------------------------------------------------------------------
/// A specialized data class for creating modeling tool plugins.\n
/// Implements @ref InitDefaultSettings, @ref GetDDescription, @ref GetDEnabling and @ref Message to support stuff like Transform/Apply. Be sure to call the parent versions if these functions are overridden.\n
/// Use RegisterToolPlugin() to register a description tool plugin.
//----------------------------------------------------------------------------------------
class DescriptionToolData : public ToolData
{
	INSTANCEOF(DescriptionToolData, ToolData)

protected:
	Bool firstaction;
	Int32 last_dirty;

public:
	// Inherited from ToolData
	// virtual Bool DoCommand(ModelingCommandData &mdat);
	// virtual Bool MouseInput(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg);
	// virtual Bool KeyboardInput(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, EditorWindow *win, const BaseContainer &msg);
	// virtual Int32 GetState(BaseDocument *doc);
	// virtual Bool GetCursorInfo(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, Float x, Float y, BaseContainer &bc);
	// virtual TOOLDRAW Draw(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt,TOOLDRAWFLAGS flags);
	// virtual Bool InitDisplayControl(BaseDocument *doc, BaseContainer &data, BaseDraw *bd, const AtomArray *active);
	// virtual void FreeDisplayControl(void);
	// virtual Bool DisplayControl(BaseDocument *doc, BaseObject *op, BaseObject *chainstart, BaseDraw *bd, BaseDrawHelp *bh, ControlDisplayStruct &cds);
	// virtual Bool GetDParameter(BaseDocument *doc, BaseContainer &data, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(BaseDocument *doc, BaseContainer &data, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(BaseDocument *doc, BaseContainer &data, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// Inherited from ToolData

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

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to return the resource symbol of the tool.
	/// @return												The name of the description resource file to use for the plugin without .res extension, for example @em "Toolname".\n
	/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for two different descriptions. See Description Resource for more information.
	//----------------------------------------------------------------------------------------
	virtual const String GetResourceSymbol() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to return the plugin ID of the tool.
	/// @return												The tool plugin ID. This should be the same as the ID used with @ref RegisterToolPlugin.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetToolPluginId() = 0;

	//----------------------------------------------------------------------------------------
	/// Called to initialize the default tool settings in @formatParam{data}.
	/// @param[in] pDoc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] data								The tool settings container.
	//----------------------------------------------------------------------------------------
	virtual void InitDefaultSettings(BaseDocument* pDoc, BaseContainer& data);

	//----------------------------------------------------------------------------------------
	/// Called when the interactive modeling is restarted.\n
	/// Applies the last modeling undo so that new values of the modeling tool can be applied (by calling the global function InteractiveModeling_Restart()).
	/// @warning Be sure to call the parent method as last return if overridden.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InteractiveModeling_Restart(BaseDocument* doc);

	/// @}
};

#endif // C4D_DESCRIPTIONDIALOG_H__
