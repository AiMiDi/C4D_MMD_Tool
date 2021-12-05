/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef MODELINGIDS_H__
#define MODELINGIDS_H__

/// @addtogroup ModelingToolsParameters
/// @ingroup group_enumeration
/// @{
#define ID_MODELING_EDGECUT_TOOL														1009661				///< Edge cut tool. See tooledgecut.h
#define ID_MODELING_FILL_SELECTION_TOOL											1011178				///< Fill selection tool.
#define ID_MODELING_OUTLINE_SELECTION_TOOL									1011179				///< @markPrivate
#define ID_MODELING_LOOP_TOOL																1011192				///< Loop selection tool. See toolloopselection.h
#define ID_MODELING_RING_TOOL																1011180				///< Ring selection tool.
#define ID_MODELING_EXTRUDE_TOOL														1011183				///< Extrude tool. See toolextrude.h
#define ID_MODELING_MATRIX_EXTRUDE_TOOL											1011126				///< Matrix extrude tool. See toolmatrixextrude.h
#define ID_MODELING_NORMALMOVE_TOOL													450000000			///< Normal move tool. See toolnormalmove.h
#define ID_MODELING_NORMALSCALE_TOOL												450000001			///< Normal scale tool. See toolnormalscale.h
#define ID_MODELING_NORMALROTATE_TOOL												450000002			///< Normal rotate tool. See toolnormalrotate.h
#define ID_MODELING_SMOOTH_SHIFT_TOOL												450000003			///< Smooth shift tool. See toolsmoothshift.h
#define ID_MODELING_EXTRUDE_INNER_TOOL											450000004			///< Extrude inner tool. See toolextrudeinner.h
#define ID_XBEVELTOOL 																			431000015			///< Bevel tool. See xtoolbevel.h @since R19
#define ID_MODELING_BEVEL_TOOL															450000005			///< @markDeprecated Old Bevel tool.
#define ID_MODELING_POLYGON_CREATE_TOOL											450000006			///< Create polygon tool. See toolcreatepolygon.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_POINT_ADD_TOOL													450000007			///< Add point tool. See tooladdpoint.h
#define ID_MODELING_BRIDGE_TOOL															450000008			///< Bridge tool. See toolbridge.h
#define ID_MODELING_WELD_TOOL																450000009			///< Weld tool. See toolpointweld.h
#define ID_MODELING_CLOSEHOLE_TOOL													450000010			///< Close polygon hole tool. See toolclosehold.h
#define ID_MODELING_STITCHANDSEW_TOOL												450000011			///< Stich and sew tool. See toolstitchandsew.h
#define ID_MODELING_SLIDE_TOOL															450000012			///< Slide tool. See toolslide.h
#define ID_MODELING_IRON_TOOL																450000014			///< Iron tool. See tooliron.h
#define ID_MODELING_SETVALUE_TOOL														200000065			///< Set value tool. See toolsetvalue.h
#define ID_MODELING_DUPLICATE_TOOL													200000067			///< Duplicate tool. See toolduplicate.h
#define ID_MODELING_ARRANGE_TOOL														200000068			///< Arrange tool. See toolarrange.h
#define ID_MODELING_TRANSFER_TOOL														200000069			///< Transfer tool. See tooltransfer.h
#define ID_MODELING_RANDOMIZE_TOOL													200000070			///< Randomize tool. See toolrandomize.h
#define ID_MODELING_CENTER_TOOL															200000071			///< Center tool. See toolcenter.h
#define ID_MODELING_KNIFE_LINE 														 	431000163			///< Knife line tool. See toolknifeline.h
																																					///< @note This tool cannot be used with SendModelingCommand().
																																					///< @since R18
#define ID_MODELING_KNIFE_PLANE															431000164			///< Knife plane tool. See toolknifeplane.h @since R18
#define ID_MODELING_KNIFE_PATH 															431000165			///< Knife path/loop tool. See toolknifepath.h @since R18
#define ID_MODELING_LIVESELECTION														200000083			///< Live selection tool. See toolliveselection.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_RECTSELECTION														200000084			///< Rectangle selection tool. See toolrectselection.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_FREESELECTION														200000085			///< Free selection tool. See toolfreeselection.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_POLYSELECTION														200000086			///< Polygon selection tool. See toolpolyselection.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_SPLINE_ROUND_TOOL												450000039			///< Spline round tool. See toolsplineround.h
#define ID_MODELING_CLONE_TOOL															450000042			///< Clone tool. See toolclone.h
#define ID_MODELING_SPLINE_CHAMFER_TOOL											450000043			///< Spline chamfer tool. See toolsplinechamfer.h
#define ID_MODELING_ARRAY_TOOL															450000045			///< Array tool. See toolarray.h
#define ID_MODELING_SPLINE_PROJECT_TOOL											450000046			///< Spline project tool. See toolsplineproject.h
#define ID_MODELING_MAGNET_TOOL															1016185				///< Magnet tool. See toolmagnet.h
#define ID_MODELING_BRUSH_TOOL															1016202				///< Brush tool. See toolbrush.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MODELING_MODIFY_TOOL															200000074			///< Modify tool. See toolmodify.h
																																					///< @note This tool cannot be used with SendModelingCommand().
#define ID_MEASURE_TOOL																			1011182				///< Measure tool. See toolmeasure.h
																																					///< @note This tool cannot be used with SendModelingCommand().
/// @}

/// @addtogroup ID_CAMERA_CONTAINERIDS
/// @ingroup group_enumeration
/// @{
#define ID_CAMERA_POINT_OF_INTEREST													440000081			///< ::Vector The Point of Interest (POI) in world coordinates.
#define ID_CAMERA_DISPLAY_POI																440000087			///< ::Vector Normally this is the Point of Interest (POI) in screen space. This is usually set automatically at the start of each navigation move.\n
																																					///< When the POI is locked this changes from screen to world space and becomes identical with @ref ID_CAMERA_POINT_OF_INTEREST.
/// @}

/// @addtogroup ModelingToolsNoParameters
/// @ingroup group_enumeration
/// @{
#define ID_MODELING_MELT_COMMAND														1010136				///< Melt.
#define ID_MODELING_EDGE_SPLINE_COMMAND											1009671				///< Edge to spline.
#define ID_MODELING_COLLAPSE_COMMAND												1015924				///< Collapse.

#define ID_CAMERA_SET_PIVOT																	1021420				///< Set the camera pivot.
#define ID_CAMERA_LOCK_PIVOT																440000104			///< Locks/unlocks the camera's Point of Interest (POI) to the last used POI location.
#define ID_CAMERA_SET_FOCUS																	440000089			///< Set the camera focus.

#define ID_VIEW_BASE_MATRIX																	450000260			///< Only for undo. @markPrivate
#define ID_VIEW_PLANAR_ROT																	450000261			///< Only for undo. @markPrivate

#define ID_VIEW_SCENEHOOKHIGHLIGHT													200000078			///< @markPrivate
#define ID_VIEW_SCENEHOOKHUD																1011173				///< @markPrivate
#define ID_VIEW_MESSAGEHUD																	1022763				///< @markPrivate

#define ID_LASTTOOL_START	1021385			///< The first of the last used tools. The next last used tools can be accessed with @ref ID_LASTTOOL_START + (@em 1...@em 6)
#define ID_LASTTOOL_END		1021392			///< The last of the last used tools.

#define ID_NGON_RETRI_MENU					1016160				///< Retriangulate N-gons.
#define ID_NGON_REMOVE_MENU					1016174				///< Remove N-gons.
#define ID_NGON_FORCERETRI_MENU			1016173				///< Force N-gon triangulation.

#define ID_OBJECTHANDLES_ONOFF_MENU	1016176				///< Object handles toggle.

#define ID_SDS_INC_MENU							1016177				///< Increment SDS.
#define ID_SDS_DEC_MENU							1016178				///< Decrement SDS.
#define ID_SDS_ONFFF_MENU						1016179				///< Toggle SDS.

#define ID_MODELING_OM_SELECT_INVERT	1016207			///< Invert object manager selection.
#define ID_MODELING_OM_SELECT_HIDE		1016208			///< Hide selected objects.
#define ID_MODELING_OM_SELECT_SHOW		1016209			///< Show selected objects.

#define ID_MODELING_SHORTCUT_SELECTVISIBLE	1016757				///< Toggle select visible.
/// @}

/// @addtogroup ModelingToolsMiscellaneous
/// @ingroup group_enumeration
/// @{
#define ID_CONVERT_SELECTION_TOOL														1011181				///< Convert selection.

#define ID_TOOL_BASE																				200000064			///< @markPrivate

#define ID_MODELING_INTERACTIVEMODELINGUNDO_RESTART_COMMAND	200000060			///< Restart undo.
#define ID_MODELING_INTERACTIVEMODELINGUNDO_COMMAND					200000061			///< Undo.

#define ID_CAMERA_MOVE																			1016007				///< Camera move.
#define ID_CAMERA_MAGNIFY																		1016008				///< Camera magnify.
#define ID_CAMERA_ZOOM																			1016009				///< Camera zoom.
#define ID_CAMERA_ZOOM_IN																		1016010				///< Camera zoom in.
#define ID_CAMERA_ZOOM_OUT																	1016011				///< Camera zoom out.

#define ID_MODELING_AXIS																		200000087			///< Axis.
#define ID_MODELING_MOVE																		200000088			///< Move.
#define ID_MODELING_SCALE																		200000089			///< Scale.
#define ID_MODELING_ROTATE																	200000090			///< Rotate.
#define ID_MODELING_SOFTSELECTION														1016699				///< Soft selection.

#define ID_SCALEDOCUMENT_CMD 200000277			///< Document scale tool.
/// @}

#define ID_MODELING_HANDLE					440000084			///< @markPrivate

#define ID_EXTENDED_MODE						1016116				///< Extended mode.

#define ID_MEASURE_SCENEHOOK				200000079			///< Measure scene hook.
#define ID_MEASURE_OBJECT						200000082			///< Measure object.

#define MESSAGE_SOFTPREVIEW					1016765				///< Soft preview message.

#define TWEAK_ENABLED								440000163			///< @markPrivate

/// @addtogroup EXTENDED_MODE
/// @ingroup group_enumeration
/// @{
#define EXTENDED_MODE_NORMAL			0			///< Normal.
#define EXTENDED_MODE_TWEAK				1			///< Tweak.
#define EXTENDED_MODE_SOFT				2			///< Not supported.
#define EXTENDED_MODE_AUTOSWITCH	3			///< Auto switch.
/// @}

/// @addtogroup NORMALTOOL
/// @ingroup group_enumeration
/// @{
#define NORMALTOOL_MOVE		0			///< Move.
#define NORMALTOOL_SCALE	1			///< Scale.
#define NORMALTOOL_ROTATE	2			///< Rotate.
/// @}

#define TOOL_IS_CHECKED		440000080

#endif // MODELINGIDS_H__
