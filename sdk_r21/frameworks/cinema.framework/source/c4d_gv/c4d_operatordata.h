/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_OPERATORDATA_H__
#define C4D_OPERATORDATA_H__

#include "c4d_nodedata.h"
#include "c4d_graphview.h"

/// @addtogroup group_graphview Graph View
/// @{

//----------------------------------------------------------------------------------------
/// A class for registering new Graph View operators. These show up as nodes in XPresso.\n
/// Use GvRegisterOperatorPlugin() to register a Graph View operator.\n
/// Information on how to handle data in a GvOperatorData plugin can be found in the articles @ref page_graphview_calculation and @ref page_graphview_data_format.
//----------------------------------------------------------------------------------------
class GvOperatorData : public NodeData
{
	public:
		/// @name NodeData Overloads
		/// @{

		// Inherited from NodeData
		virtual Bool Init(GeListNode *node);
		// virtual void Free(GeListNode *node);
		// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
		// virtual Bool Write(GeListNode *node, HyperFile *hf);
		// virtual Bool Message(GeListNode *node, Int32 type, void *data);
		// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
		// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
		virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
		virtual Bool GetDParameter(GeListNode *node, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags);
		virtual Bool GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc);
		virtual Bool SetDParameter(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_SET &flags);
		// Inherited from NodeData

		/// @}

		/// @name Internal
		/// @{

		//----------------------------------------------------------------------------------------
		/// Internal wrapper for GvNode::GetPortList(). Normally it is not need to override this function.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] port								Only retrieve ports with the IO mode: @enumerateEnum{GvPortIO}
		/// @param[out] portlist					Filled with the ports for this node. @callerOwnsPointed{GvPortList}
		//----------------------------------------------------------------------------------------
		virtual void iGetPortList(GvNode *bn, GvPortIO port, GvPortList &portlist);

		//----------------------------------------------------------------------------------------
		/// Internal wrapper for GvNode::GetPortDescription(). Normally it is not need to override this function.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] port								Only retrieve port description with the IO mode: @enumerateEnum{GvPortIO}
		/// @param[in] id									The port ID.
		/// @param[in] pd									Filled with the port description. @callerOwnsPointed{GvPortDescription}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool iGetPortDescription(GvNode *bn, GvPortIO port, Int32 id, GvPortDescription *pd);

		//----------------------------------------------------------------------------------------
		/// Internal wrapper for GvNode::CreateOperator().\n
		/// Initialize here default parameters for the operator:
		/// @code
		/// virtual Bool iCreateOperator(GvNode *bn)
		/// {
		/// 	BaseContainer *bc = bn->GetOpContainerInstance();
		/// 	if (!bc)
		/// 		return false;
		///
		/// 	return SUPER::iCreateOperator(bn);
		/// }
		/// @endcode
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool iCreateOperator(GvNode *bn);

		/// @}

		/// @name Port Description Cache
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called before a node master's Calculate() is executed to give the node the chance to cache internal data.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] lock_only					@formatConstant{true} to lock only.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool CreatePortDescriptionCache(GvNode *bn, Bool lock_only = false);

		//----------------------------------------------------------------------------------------
		/// Called after a node master's Calculate() is executed to free the cached internal data.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		//----------------------------------------------------------------------------------------
		virtual void FreePortDescriptionCache(GvNode *bn);

		/// @}

		/// @name Operator Information
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the detailed text for the operator. The easiest way is to just return @link GvGetOperatorDetailedText@endlink(this, bn).
		/// @see GvGetOperatorDetailedText()
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @return												The operator detailed text.
		//----------------------------------------------------------------------------------------
		virtual const String GetDetailedText(GvNode *bn);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the text for the operator.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @return												The operator text.
		//----------------------------------------------------------------------------------------
		virtual const String GetText(GvNode *bn);

		//----------------------------------------------------------------------------------------
		/// Called to retrieve the title of the operator. The easiest way is to just return @link GvGetOperatorTitle@endlink(this, bn).
		/// @see GvGetOperatorTitle()
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @return												The operator title.
		//----------------------------------------------------------------------------------------
		virtual const String GetTitle(GvNode *bn);

		//----------------------------------------------------------------------------------------
		/// Called to provide an icon for a port.
		/// @note Currently this is not used anywhere.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] id									The port ID.
		/// @param[in] layout_type				The layout type: @enumerateEnum{GvLayoutType}
		/// @return												The port icon. @theOwnsPointed{operator,BaseBitmap}
		//----------------------------------------------------------------------------------------
		virtual BaseBitmap* GetPortIcon(GvNode *bn, Int32 id, GvLayoutType layout_type);

		//----------------------------------------------------------------------------------------
		/// Called to give a default body size for the operator.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] width							Assign the default width in pixels.
		/// @param[out] height						Assign the default height in pixels.
		//----------------------------------------------------------------------------------------
		virtual void GetBodySize(GvNode *bn, Int32 *width, Int32 *height);

		//----------------------------------------------------------------------------------------
		/// Called to give a default body color for the operator.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @return												The default body color.
		//----------------------------------------------------------------------------------------
		virtual const Vector GetBodyColor(GvNode *bn);

		//----------------------------------------------------------------------------------------
		/// Called to set operator flags in @formatParam{od}.
		/// @note This is for future extensions. Currently all flags that affect the node are static and set with GvRegisterOperatorPlugin().
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] od								The operator description. @callerOwnsPointed{GvOperatorDescription}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool GetOperatorDescription(GvNode *bn, GvOperatorDescription *od);

		/// @}

		/// @name Special Events
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to draw inside the operator body.\n
		/// Use the @formatParam{da} pointer to draw in the rectangle defined by (@formatParam{x1}, @formatParam{y1}) and (@formatParam{x2}, @formatParam{y2}).\n
		/// A clipping rectangle is set, so it does not matter if draw occurs outside this bound.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] gui								The current GUI. @callerOwnsPointed{GvNodeGUI}
		/// @param[in] da									The user area to draw in. @callerOwnsPointed{GeUserArea}
		/// @param[in] x1									The upper left X coordinate.
		/// @param[in] y1									The upper left Y coordinate.
		/// @param[in] x2									The lower right X coordinate.
		/// @param[in] y2									The lower right Y coordinate.
		//----------------------------------------------------------------------------------------
		virtual void EditorDraw(GvNode *bn, GvNodeGUI* gui, GeUserArea *da, Int32 x1, Int32 y1, Int32 x2, Int32 y2);

		//----------------------------------------------------------------------------------------
		/// Allows the node to draw into the editor window.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] bd									The BaseDraw object for the active editor view. @cinemaOwnsPointed{BaseDraw}
		/// @param[in] bh									The BaseDrawHelp object for the active editor view. @cinemaOwnsPointed{BaseDrawHelp}
		/// @param[in] bt									The calling thread. @cinemaOwnsPointed{BaseThread}
		/// @param[in] flags							The pass: @enumerateEnum{SCENEHOOKDRAW}
		/// @param[in] data								The user defined data passed to GvNodeMaster::AddToDrawList(), or @formatConstant{nullptr}.
		/// @param[in] counter						This counter is increased on every InitCalculation(). It helps determine when the GvNodeMaster::AddToDrawList() occurred. The counter will be the same for every SceneDraw().
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool SceneDraw(GvNode *bn, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, SCENEHOOKDRAW flags, void *data, UInt32 counter);

		//----------------------------------------------------------------------------------------
		/// Called if the user clicks in the body of the node.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] gui								The node GUI. @callerOwnsPointed{GvNodeGUI}
		/// @param[in] x									The mouse X coordinate.
		/// @param[in] y									The mouse Y coordinate.
		/// @param[in] chn								The mouse channel: @enumerateEnum{BFM_INPUT_CHANNEL}
		/// @param[in] qua								A bitmask with the qualifiers at the time when the mouse event occurred: @enumerateEnum{QUALIFIERS}
		/// @param[in] msg								The original message. See @link page_input_events Input Events@endlink.
		/// @return												@trueIfOtherwiseFalse{the message was handled}
		//----------------------------------------------------------------------------------------
		virtual Bool BodyMessage(GvNode* bn, GvNodeGUI *gui, Int32 x, Int32 y, Int32 chn, Int32 qua, const BaseContainer &msg);

		//----------------------------------------------------------------------------------------
		/// Called to give the operator the chance to provide a custom settings dialog.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] gui								The node GUI. @callerOwnsPointed{GvNodeGUI}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool EditSettings(GvNode* bn, GvNodeGUI *gui);

		/// @}

		/// @name Calculation
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to check if it is OK to start a calculation. If false is returned tell the caller why by setting an error flag in @formatParam{query}.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] query							The query parameter. @callerOwnsPointed{GvQuery}
		/// @return												@trueIfOtherwiseFalse{it is OK to start a calculation}
		//----------------------------------------------------------------------------------------
		virtual Bool QueryCalculation(GvNode *bn, GvQuery *query);

		//----------------------------------------------------------------------------------------
		/// Called before the calculation is started.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] calc								The current calculation helper. @callerOwnsPointed{GvCalc}
		/// @param[in] run								The current run helper. @callerOwnsPointed{GvRun}
		/// @return												@trueIfOtherwiseFalse{calculation was initialized}
		//----------------------------------------------------------------------------------------
		virtual Bool InitCalculation(GvNode *bn, GvCalc *calc, GvRun *run);

		//----------------------------------------------------------------------------------------
		/// Called after the calculation is finished.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] calc								The current calculation helper. @callerOwnsPointed{GvCalc}
		//----------------------------------------------------------------------------------------
		virtual void FreeCalculation(GvNode *bn, GvCalc *calc);

		//----------------------------------------------------------------------------------------
		/// Called either from the node master, when the node has called GvRun::AddNodeToCalculationTable(), or from another node that calls GvValue::Calculate() for a port that is connected to the node.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] port								If the call comes directly from the node master this is @formatConstant{nullptr}. Otherwise it is the outport that another node wants to be calculated. @callerOwnsPointed{GvPort}
		/// @param[in] run								The current run helper. @callerOwnsPointed{GvRun}
		/// @param[in] calc								The current calculation helper. @callerOwnsPointed{GvCalc}
		/// @return												@trueIfOtherwiseFalse{calculation was successful}
		//----------------------------------------------------------------------------------------
		virtual Bool Calculate(GvNode *bn, GvPort *port, GvRun *run, GvCalc *calc);

		//----------------------------------------------------------------------------------------
		/// Called by the node master before the calculation starts.\n
		/// To set if a node can be evaluated regardless of whether another node requests data from its output ports or not, call GvRun::AddNodeToCalculationTable() here.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] run								The current run helper. @callerOwnsPointed{GvRun}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool AddToCalculationTable(GvNode *bn, GvRun *run);

		//----------------------------------------------------------------------------------------
		/// Called by the node master when someone has called SetRecalculate().\n
		/// As a rule of thumb, if GvRun::AddNodeToCalculationTable() is called in AddToCalculationTable() this should be done here as well. Otherwise this method should not be implemented.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] port								The port that was invalidated.
		/// @param[in] run								The current run helper. @callerOwnsPointed{GvRun}
		/// @param[in] force_set					If @formatConstant{true} the recalculation is forced even if the data is already updated.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool SetRecalculate(GvNode *bn, GvPort *port, GvRun *run, Bool force_set = false);

		/// @}

		/// @name Set Data
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called for example when the user drops something on the node.
		/// @note Overload IsSetDataAllowed() to specify what kinds of @formatParam{data} is accepted.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] type								The data type: @enumerateEnum{GvDataType}
		/// @param[in] data								The data pointer. The format depends on @formatParam{type}.
		/// @param[in] mode								The mode: @enumerateEnum{GvOpSetDataMode}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		virtual Bool SetData(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode = GV_OP_SET);

		//----------------------------------------------------------------------------------------
		/// Called to check if the specified data would be acceptable for a SetData() action. This is used to for example determine the cursor during drag-and-drop.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] type								The data type: @enumerateEnum{GvDataType}
		/// @param[in] data								The data pointer. The format depends on @formatParam{type}.
		/// @param[in] mode								The mode: @enumerateEnum{GvOpSetDataMode}
		/// @return												@trueIfOtherwiseFalse{@formatParam{data} is acceptable}
		//----------------------------------------------------------------------------------------
		virtual Bool IsSetDataAllowed(GvNode *bn, GvDataType type, void *data, GvOpSetDataMode mode = GV_OP_SET);

		/// @}

		/// @name Menus
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called when the user has opened the port menu, for example by right-clicking on a port.\n
		/// Add menu items to the @formatParam{menu} container, as described in ShowPopupMenu(), and then return the number of entries added. Do not use menu IDs below @formatParam{first_menu_id}.\n
		/// If the user chooses one of the commands, PortMenuCommand() is called.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] menu							The menu container to add entries to.
		/// @param[in] port_id						The port ID.
		/// @param[in] first_menu_id			The first menu item ID.
		/// @return												The number of menu entries added.
		//----------------------------------------------------------------------------------------
		virtual Int32 FillPortMenu(GvNode *bn, BaseContainer &menu, Int32 port_id, Int32 first_menu_id);

		//----------------------------------------------------------------------------------------
		/// Called when the user chooses one of the commands in the port menu set in FillPortMenu().
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] menu_id						The menu item ID.
		/// @param[in] port_id						The port ID.
		/// @param[in] mx									The mouse X coordinate.
		/// @param[in] my									The mouse Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the command was handled}
		//----------------------------------------------------------------------------------------
		virtual Bool PortMenuCommand(GvNode *bn, Int32 menu_id, Int32 port_id, Int32 mx, Int32 my);

		//----------------------------------------------------------------------------------------
		/// Called when the user has opened the operator menu, for example by right-clicking on the operator.\n
		/// Add menu items to the menu container, as described in ShowPopupMenu(), and then return the number of entries added. Do not use menu IDs below @formatParam{first_menu_id}.\n
		/// If the user chooses one of the commands, OperatorMenuCommand() is called.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] menu							The menu container to add entries to.
		/// @param[in] first_menu_id			The first menu item ID.
		/// @return												The number of menu entries added.
		//----------------------------------------------------------------------------------------
		virtual Int32 FillOperatorMenu(GvNode *bn, BaseContainer &menu, Int32 first_menu_id);

		//----------------------------------------------------------------------------------------
		/// Called when the user chooses one of the commands in the operator menu set in FillOperatorMenu().
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] menu_id						The menu item ID.
		/// @param[in] mx									The mouse X coordinate.
		/// @param[in] my									The mouse Y coordinate.
		/// @return												@trueIfOtherwiseFalse{the command was handled}
		//----------------------------------------------------------------------------------------
		virtual Bool OperatorMenuCommand(GvNode *bn, Int32 menu_id, Int32 mx, Int32 my);

		//----------------------------------------------------------------------------------------
		/// Called when the user has opened the ports menu, for example by clicking on the corner of the node or dragging a connection from another port.\n
		/// Add a name entry to @formatParam{names} and an ID entry to @formatParam{ids} for each possible port to create for this action and return the number of added entries.\n
		/// The @formatParam{ids} container is a translation between menu IDs and the port IDs of the data types:
		/// @code
		/// names.SetString(first_menu_id + i, "Port name");
		/// ids.SetInt32(first_menu_id + i, PORT_ID);
		/// @endcode
		/// @see ShowPopupMenu() for the name formatting.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[out] names							The container with the menu entries.
		/// @param[out] ids								The container for the translation between menu ID and port ID.
		/// @param[in] value_type					The value type for drag-and-drop, or @ref ID_GV_VALUE_TYPE_NONE if this is not a drag-and-drop action.
		/// @param[in] port								The IO mode: @enumerateEnum{GvPortIO}
		/// @param[in] first_menu_id			The first menu item ID.
		/// @return												The number of menu entries added.
		//----------------------------------------------------------------------------------------
		virtual Int32 FillPortsMenu(GvNode *bn, BaseContainer &names, BaseContainer &ids, GvValueID value_type, GvPortIO port, Int32 first_menu_id);

		/// @}

		/// @name Miscellaneous
		/// @{

		//----------------------------------------------------------------------------------------
		/// Called to let translate error messages that have been set when the calculation failed.
		/// @note Currently this function is not called.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] error							The error ID.
		/// @return												The error message.
		//----------------------------------------------------------------------------------------
		virtual const String GetErrorString(GvNode *bn, Int32 error);

		//----------------------------------------------------------------------------------------
		/// Return the port main ID of the given @formatParam{desc_id}.
		/// @note Normally it is not need to implement this method. It is currently only used by the object node.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] io									The IO mode: @enumerateEnum{GvPortIO}
		/// @param[in] desc_id						The description ID.
		/// @return												The main ID.
		//----------------------------------------------------------------------------------------
		virtual Int32 GetMainID(GvNode *bn, GvPortIO io, const DescID &desc_id);

		//----------------------------------------------------------------------------------------
		/// Return the description ID of the given port @formatParam{main_id}.
		/// @note Normally it is not need to implement this method. It is currently only used by the object node.
		/// @param[in] bn									Equal to static_cast<@ref GvNode*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
		/// @param[in] io									The IO mode: @enumerateEnum{GvPortIO}
		/// @param[in] main_id						The main ID.
		/// @return												The description ID.
		//----------------------------------------------------------------------------------------
		virtual const DescID GetDescID(GvNode *bn, GvPortIO io, Int32 main_id);

		/// @}
};

//----------------------------------------------------------------------------------------
/// Registers an operator plugin with @C4D.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The settings for the plugin. Possible flags are: @enumerateEnum{PLUGINFLAG} @enumerateEnum{GvOperatorFlags}
/// @param[in] at									The allocator for the operator plugin. This is a pointer to a function that creates a new instance of GvOperatorData with @ref NewObj.
/// @param[in] description				The name of the description resource file to use for the operator plugin without @em .res extension, for example @em "GVoperator".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings you can increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @param[in] op_class						The operator class. Either a class registered with GvRegisterOpClassType() or @ref ID_GV_OPCLASS_TYPE_GENERAL.
/// @param[in] op_group						The operator group. Either a group registered with GvRegisterOpGroupType() or one of these: @enumerateEnum{ID_GV_OPGROUP_TYPE}
/// @param[in] op_owner						The owner ID. Either @em 0 or a unique ID for a custom plugin family.
/// @param[in] icon								The icon for the operator. The bitmap is copied. \n
/// 															The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
/// 															It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @return												@trueIfOtherwiseFalse{the plugin was registered}
//----------------------------------------------------------------------------------------
Bool GvRegisterOperatorPlugin(GvOperatorID id, const maxon::String &str, Int32 info, DataAllocator *at, const maxon::String &description, Int32 disklevel, GvOpClassID op_class, GvOpGroupID op_group, Int32 op_owner, BaseBitmap *icon);

/// @}

#endif // C4D_OPERATORDATA_H__
