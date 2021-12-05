/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_GRAPHVIEW_DEF_H__
#define C4D_GRAPHVIEW_DEF_H__

#include "c4d_general.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_graphview_enum.h"
#include "lib_description.h"

#ifdef MAXON_TARGET_MACOS
	_Pragma("clang diagnostic push")
	_Pragma("clang diagnostic ignored \"-Wdocumentation\"")
#endif

class BaseDocument;
class BaseDrawHelp;
class BaseDraw;
class GeDialog;
class GeUserArea;
class BaseBitmap;
class GvNodeMaster;
class GvOperatorData;
class GvNode;
class GvPort;
class GvNodeGUI;
class GvShape;
class GvRun;
class GvCalc;
class GvQuery;
class GvInit;
class GvValue;
class GvWorld;
class GvCalcTable;
class GvCalcTime;
class GvPortList;
class String;

struct GvPortListEntry;
struct GvCopyBuffer;
struct OPERATORPLUGIN;

/// @addtogroup group_graphview Graph View
/// @{

/// @defgroup group_graphviewinternal Graph View Internal

// Forward declaration for C4D_GvGlobals::RegisterOperatorPlugin function pointer.
typedef NodeData *DataAllocator(void);


/// @addtogroup GV_VERSION
/// @ingroup group_enumeration
/// @{
#define GV_NODEMASTER_VERSION										5
#define GV_NODE_VERSION													6
#define GV_GROUPNODE_VERSION										5
/// @}

/// @addtogroup VERSION_OPERATOR
/// @ingroup group_enumeration
/// @{
#define VERSION_OPERATOR_GROUP									5
#define VERSION_OPERATOR_DUMMY									0

#define VERSION_OPERATOR_OBJECT									2
#define VERSION_OPERATOR_RANDOM									2
#define VERSION_OPERATOR_REAL2VECT							2
#define VERSION_OPERATOR_VECT2REAL							2
#define VERSION_OPERATOR_ADAPTER								2
#define VERSION_OPERATOR_CROSS									2
#define VERSION_OPERATOR_EQU										2
#define VERSION_OPERATOR_NIL										2
#define VERSION_OPERATOR_TIME										2
#define VERSION_OPERATOR_TRIGO									2
#define VERSION_OPERATOR_MATRIX2VECT						2
#define VERSION_OPERATOR_VECT2MATRIX						2
#define VERSION_OPERATOR_NOT										2
#define VERSION_OPERATOR_POINT									2
#define VERSION_OPERATOR_TRACK									2
#define VERSION_OPERATOR_CLAMP									2
#define VERSION_OPERATOR_VECTCALCMATRIX					2
#define VERSION_OPERATOR_MATRIXCALCHPB					2
#define VERSION_OPERATOR_DISTANCE								2
#define VERSION_OPERATOR_CONDITION							2
#define VERSION_OPERATOR_RESULT									2
#define VERSION_OPERATOR_SPY										2
#define VERSION_OPERATOR_CONST									2
#define VERSION_OPERATOR_MATH										2
#define VERSION_OPERATOR_BOOL										2
#define VERSION_OPERATOR_INV										2
#define VERSION_OPERATOR_NEG										2
#define VERSION_OPERATOR_CMP										2
#define VERSION_OPERATOR_ORDER									2
#define VERSION_OPERATOR_SWITCH									2
#define VERSION_OPERATOR_MIX										2
#define VERSION_OPERATOR_COMMENT								2
#define VERSION_OPERATOR_MEMORY									2
#define VERSION_OPERATOR_ITERATE								4
#define VERSION_OPERATOR_FREEZE									2
#define VERSION_OPERATOR_FORMULA								2
#define VERSION_OPERATOR_ABS										2
#define VERSION_OPERATOR_DEGREE									2
#define VERSION_OPERATOR_RANGEMAPPER						2
#define VERSION_OPERATOR_FLOATMATH							2
#define VERSION_OPERATOR_FLOATFUNC							2
#define VERSION_OPERATOR_POLYGON								2
#define VERSION_OPERATOR_DOT										2
#define VERSION_OPERATOR_COLORSPACE							2
#define VERSION_OPERATOR_SOUND									2
#define VERSION_OPERATOR_NOISE									2
#define VERSION_OPERATOR_TRIGGER								2
#define VERSION_OPERATOR_BOX										2
#define VERSION_OPERATOR_COLLISION							2
#define VERSION_OPERATOR_SPLINE									2
#define VERSION_OPERATOR_MATRIXMULVECTOR				2
#define VERSION_OPERATOR_SELECTION							3
#define VERSION_OPERATOR_HIERARCHY							3
#define VERSION_OPERATOR_DETAILS								2
#define VERSION_OPERATOR_TAG										3
#define VERSION_OPERATOR_MONOFLOP								2
#define VERSION_OPERATOR_REFERENCE							2
#define VERSION_OPERATOR_WEIGHTMAP							2
#define VERSION_OPERATOR_MATERIAL								3
#define VERSION_OPERATOR_INCLUDE								3
#define VERSION_OPERATOR_LINK										2
#define VERSION_OPERATOR_RAY										2
#define VERSION_OPERATOR_BITMAP									2
#define VERSION_OPERATOR_COLORTEMP							2
#define VERSION_OPERATOR_VERTEXCOLOR						1		///< @since R18
#define VERSION_OPERATOR_NEARESTPOINT						1		///< @since R20
#define VERSION_OPERATOR_NEARESTPOINTONSPLINE		1		///< @since R20
/// @}

#define GV_NODEMASTER_RELEASE							(1102)

/// @addtogroup GRAPHVIEW_PRIORITY
/// @ingroup group_enumeration
/// @{
/// Priorities of the GV modules
#define GRAPHVIEW_CORE_PRIORITY						30000			///< Core priority.
#define GRAPHVIEW_EDITOR_PRIORITY					2000			///< Editor priority.
#define GRAPHVIEW_HOOK_PRIORITY						1000			///< Hook priority.
/// @}

/// @addtogroup GVNodeIDs
/// @ingroup group_enumeration
/// @{
#define ID_GRAPHVIEW											1001100
#define ID_GV_NODEDATA										1001101			///< Node data. Same as ::GVbase.
#define ID_GV_GROUPDATA										1001102			///< Group data.
#define ID_GV_NODEMASTERDATA							1001103			///< Node master data.
#define ID_GRAPHVIEW_PRIVATE							1001104			///< @markPrivate
/// @}

#define ID_GV_VALGROUP_TYPE_GENERAL				1001110			///< General value group.

#define ID_GV_OPCLASS_TYPE_GENERAL				1001111			///< General operator class.

/// @addtogroup ID_GV_OPGROUP_TYPE
/// @ingroup group_enumeration
/// @{
#define ID_GV_OPGROUP_TYPE_GENERAL				1001112		///< General group.
#define ID_GV_OPGROUP_TYPE_ADAPTER				1001113		///< Adapter group.
#define ID_GV_OPGROUP_TYPE_BOOL						1001114		///< Bool group.
#define ID_GV_OPGROUP_TYPE_CALCULATE			1001115		///< Calculate group.
#define ID_GV_OPGROUP_TYPE_LOGICAL				1001116		///< Logic group.
#define ID_GV_OPGROUP_TYPE_ITERATOR				1001117		///< Iterator group.
#define ID_GV_OPGROUP_TYPE_SCRIPTING			1026358		///< Script group.
/// @}

/// @addtogroup ID_GV_VALUE_TYPE
/// @ingroup group_enumeration
/// @{
#define ID_GV_VALUE_TYPE_NONE							0							///< No value.
#define ID_GV_VALUE_TYPE_UNDEFINED				400007000			///< Undefined.
#define ID_GV_VALUE_TYPE_BOOL							400007001			///< Boolean.
#define ID_GV_VALUE_TYPE_INTEGER					400007002			///< Integer.
#define ID_GV_VALUE_TYPE_REAL							400007003			///< Float.
#define ID_GV_VALUE_TYPE_VECTOR						400007004			///< Vector.
#define ID_GV_VALUE_TYPE_NORMAL						400007005			///< Normal vector.
#define ID_GV_VALUE_TYPE_MATRIX						400007006			///< Matrix.
#define ID_GV_VALUE_TYPE_TIME							400007007			///< Time.
#define ID_GV_VALUE_TYPE_STRING						400007008			///< String.
#define ID_GV_VALUE_TYPE_GENERAL_OBJECT		400007009			///< General object.
#define ID_GV_VALUE_TYPE_GENERAL_TAG			400007010			///< General tag.
#define ID_GV_VALUE_TYPE_GENERAL_MATERIAL	400007011			///< General material.
#define ID_GV_VALUE_TYPE_GENERAL_INSTANCE	400007012			///< General instance.
#define ID_GV_VALUE_TYPE_COLORA						400006013			///< ColorA.
/// @}

/// @addtogroup ID_GV_DATA_TYPE
/// @ingroup group_enumeration
/// @{
#define ID_GV_DATA_TYPE_NONE							0							///< No data. (@ref DA_NIL)
#define ID_GV_DATA_TYPE_UNDEFINED					400006000			///< Undefined.
#define ID_GV_DATA_TYPE_BOOL							400006001			///< Boolean.
#define ID_GV_DATA_TYPE_INTEGER						15						///< Integer. (@ref DA_LONG)
#define ID_GV_DATA_TYPE_REAL							19						///< Float. (@ref DA_REAL)
#define ID_GV_DATA_TYPE_VECTOR						23						///< Vector (@ref DA_VECTOR)
#define ID_GV_DATA_TYPE_NORMAL						400006005			///< Normal vector.
#define ID_GV_DATA_TYPE_MATRIX						25						///< Matrix. (@ref DA_MATRIX)
#define ID_GV_DATA_TYPE_TIME							22						///< Time. (@ref DA_TIME)
#define ID_GV_DATA_TYPE_STRING						130						///< String. (@ref DA_STRING)
#define ID_GV_DATA_TYPE_GENERAL_OBJECT		400006009			///< General object.
#define ID_GV_DATA_TYPE_GENERAL_TAG				400006010			///< General tag.
#define ID_GV_DATA_TYPE_GENERAL_MATERIAL	400006011			///< General material.
#define ID_GV_DATA_TYPE_GENERAL_INSTANCE	400006012			///< General instance.
#define ID_GV_DATA_TYPE_COLORA						400007013			///< ColorA.
/// @}

/// Normal custom GUI.
#define CUSTOMGUI_NORMAL									ID_GV_DATA_TYPE_NORMAL

/// @addtogroup ID_GV_OPERATOR
/// @ingroup group_enumeration
/// @{
#define ID_GV_OPERATOR_DUMMY							1001143
#define ID_GV_OPERATOR_GROUP							1001144
/// @}

/// @addtogroup ID_OPERATOR
/// @ingroup group_enumeration
/// @{
#define ID_OPERATOR_OBJECT								400001000
#define ID_OPERATOR_RANDOM								400001100
#define ID_OPERATOR_REAL2VECT							400001101
#define ID_OPERATOR_VECT2REAL							400001102
#define ID_OPERATOR_ADAPTER								400001103
#define ID_OPERATOR_CROSS									400001104
#define ID_OPERATOR_EQU										400001105
#define ID_OPERATOR_NIL										400001106
#define ID_OPERATOR_TIME									400001107
#define ID_OPERATOR_TRIGO									400001108
#define ID_OPERATOR_MATRIX2VECT						400001109
#define ID_OPERATOR_VECT2MATRIX						400001110
#define ID_OPERATOR_NOT										400001111
#define ID_OPERATOR_POINT									400001112
#define ID_OPERATOR_CLAMP									400001113
#define ID_OPERATOR_VECTCALCMATRIX				400001114
#define ID_OPERATOR_MATRIXCALCHPB					400001115
#define ID_OPERATOR_DISTANCE							400001116
#define ID_OPERATOR_CONDITION							400001117
#define ID_OPERATOR_RESULT								400001118
#define ID_OPERATOR_SPY										400001119
#define ID_OPERATOR_CONST									400001120
#define ID_OPERATOR_MATH									400001121
#define ID_OPERATOR_BOOL									400001122
#define ID_OPERATOR_INV										400001123
#define ID_OPERATOR_NEG										400001124
#define ID_OPERATOR_CMP										400001125
#define ID_OPERATOR_ORDER									400001126
#define ID_OPERATOR_SWITCH								400001127
#define ID_OPERATOR_MIX										400001128
#define ID_OPERATOR_COMMENT								400001129
#define ID_OPERATOR_MEMORY								400001130
#define ID_OPERATOR_ITERATE								400001131
#define ID_OPERATOR_FREEZE								400001132
#define ID_OPERATOR_FORMULA								400001133
#define ID_OPERATOR_ABS										400001134
#define ID_OPERATOR_DEGREE								400001135
#define ID_OPERATOR_RANGEMAPPER						400001136
#define ID_OPERATOR_FLOATMATH							400001138
#define ID_OPERATOR_FLOATFUNC							400001139
#define ID_OPERATOR_POLYGON								400001140
#define ID_OPERATOR_DOT										400001141
#define ID_OPERATOR_COLORSPACE						400001142
#define ID_OPERATOR_SOUND									400001143
#define ID_OPERATOR_NOISE									400001144
#define ID_OPERATOR_TRIGGER								400001145
#define ID_OPERATOR_BOX										400001146
#define ID_OPERATOR_COLLISION							400001147
#define ID_OPERATOR_SPLINE								400001148
#define ID_OPERATOR_MATRIXMULVECTOR				400001149
#define ID_OPERATOR_SELECTION							400001150
#define ID_OPERATOR_HIERARCHY							400001151
#define ID_OPERATOR_DETAILS								400001152
#define ID_OPERATOR_TAG										400001153
#define	ID_OPERATOR_COFFEE								400001154
#define ID_OPERATOR_MONOFLOP							400001155
#define ID_OPERATOR_REFERENCE							400001156
#define ID_OPERATOR_WEIGHTMAP							400001157
#define ID_OPERATOR_MATERIAL							400001158
#define ID_OPERATOR_INCLUDE								400001159
#define ID_OPERATOR_LINK									400001160
#define ID_OPERATOR_RAY										400001161
#define ID_OPERATOR_BITMAP								450000037
#define ID_OPERATOR_COLORTEMP							450000060
#define ID_OPERATOR_TRACK									1027923
#define ID_OPERATOR_TAKEOVERRIDE					431000066
#define ID_OPERATOR_VERTEXCOLOR						431000166		///< @since R18
#define ID_OPERATOR_NEARESTPOINT					1039901 		///< @since R20
#define ID_OPERATOR_NEARESTPOINTONSPLINE	1039902 		///< @since R20
/// @}

/// @addtogroup ID_GV_OWNER
/// @ingroup group_enumeration
/// @{
#define ID_GV_SYSTEM_OWNER								1001140
#define ID_GV_GENERAL_OWNER								1001141
#define ID_GV_IGNORE_OWNER								1001142
/// @}

/// @addtogroup ID_PLUGIN
/// @ingroup group_enumeration
/// @{
#define ID_OPERATORPOOL_PLUGIN						1001138
#define ID_TREEVIEW_PLUGIN								1001145
#define ID_OBJECT_PLUGIN									1001146
#define ID_SCENEHOOK_PLUGIN								1001147
#define ID_EXPRESSION_PLUGIN							1001148
#define ID_EXPRESSION_TAG									1001149
/// @}

/// @addtogroup ID_PREFS
/// @ingroup group_enumeration
/// @{
#define ID_GRAPHVIEW_PREFS								400005000			///< GraphView preferences.
#define ID_GRAPHVIEW_GUI_PREFS						400005001			///< GraphView GUI preferences.
#define ID_GRAPHVIEW_COLORS_PREFS					400005002			///< GraphView color preferences.
#define ID_GRAPHVIEW_WORLD_PREFS					400005003			///< GraphView world preferences.
#define ID_GRAPHVIEW_MASTER_PREFS					400005004			///< GraphView master preferences.
/// @}

/// @addtogroup DRAGTYPE_GVNODE
/// @ingroup group_enumeration
/// @{
/// Used when dragging nodes into an editor
#define DRAGTYPE_GVNODE_EDITOR						400007000
#define DRAGTYPE_GVNODE_MANAGER						400007001
#define DRAGTYPE_GVNODE_STORE							400007002
#define DRAGTYPE_GVNODE_DUMMY							400007003
/// @}

/// @addtogroup group_graphviewinternal
/// @{
#define ID_OPERATORCONTAINER							1000
#define ID_SHAPECONTAINER									1001
/// @}

/// @addtogroup GV_GROUP
/// @ingroup group_enumeration
/// @{
enum
{
	GV_GROUP_INPUT_FIRST_PRIVATE_ID		= 10000,
	GV_GROUP_INPUT_LAST_PRIVATE_ID		= 49999,
	GV_GROUP_OUTPUT_FIRST_PRIVATE_ID	= 50000,
	GV_GROUP_OUTPUT_LAST_PRIVATE_ID		= 89999,

	GV_GROUP_INPUT_FIRST_ID		= 1000000,
	GV_GROUP_INPUT_LAST_ID		= 536870911,
	GV_GROUP_OUTPUT_FIRST_ID	= 536870912,
	GV_GROUP_OUTPUT_LAST_ID		= 1073741824
};
/// @}

/// @addtogroup GvFileIdent
/// @ingroup group_enumeration
/// @{
enum GvFileIdent
{
	GV_MACRO_IDENT = 1000,
	GV_PRESET_IDENT
};
/// @}

// Predefined IDs for operators BaseContainer

#define GV_OPERATOR_PORTS_ID					101
#define GV_OPERATOR_DATA_ID						102

/// @addtogroup GV_MESSAGE_FIRST_DATA_ID
/// @ingroup group_enumeration
/// @{
enum
{
	GV_MESSAGE_FIRST_DATA_ID = 100			///< The ID of the first message parameter.
};
/// @}

/// @addtogroup GvMessage
/// @ingroup group_enumeration
/// @{
/// Message types sent by the GvNodeMaster.
enum GvMessage
{
	GV_MESSAGE_NONE = 0,
	///< @markInternal
	GV_MESSAGE_PORT_ADDED = 400000000,
	///< Port added:
	///< - <tt>io				= (::GvPortIO)bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>main_id	= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>sub_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	///< - <tt>index		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 3);</tt>
	GV_MESSAGE_PORT_REMOVED,
	///< Port removed:
	///< - <tt>io				= (::GvPortIO)bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>main_id	= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>sub_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	///< - <tt>index		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 3);</tt>
	GV_MESSAGE_PORT_RENAMED,
	///< Port renamed:
	///< - <tt>io				= (::GvPortIO)bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>index		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>name			= bc->@link BaseContainer::GetString GetString@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	///< - <tt>old_name	= bc->@link BaseContainer::GetString GetString@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 3);</tt>
	///< - <tt>sub_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 4);</tt>
	GV_MESSAGE_VIEW_CHANGED,
	///< View changed:
	///< - <tt>state			= (::GvDrawState)bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	GV_MESSAGE_NODE_RENAMED,
	///< Node renamed:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	///< - <tt>name				= bc->@link BaseContainer::GetString GetString@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 3);</tt>
	GV_MESSAGE_NODE_ENABLED,
	///< Node enabled:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_NODE_DISABLED,
	///< Node disabled:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_NODE_CREATED,
	///< Node created:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_NODE_REMOVED,
	///< Node removed:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_NODE_SELECTED,
	///< Node selected:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_NODE_DESELECTED,
	///< Node deselected:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_OPERATOR_MENU,
	///< Operator menu command:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	///< - <tt>menu_index	= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 3);</tt>
	GV_MESSAGE_OPERATOR_EDIT_SETTINGS,
	///< Edit settings:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>oper_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< - <tt>owner_id		= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 2);</tt>
	GV_MESSAGE_MASTER_INIT,
	///< Master init. No parameters.
	GV_MESSAGE_MASTER_REDRAW,
	///< Master redraw. No parameters.
	GV_MESSAGE_TRANSLATE_ID,
	///< @markInternal
	GV_MESSAGE_PORTS_MENU
	///< Ports menu:
	///< - <tt>node				= bc->@link BaseContainer::GetLink GetLink@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 0);</tt>
	///< - <tt>menu_index	= bc->@link BaseContainer::GetInt32 GetInt32@endlink(@ref GV_MESSAGE_FIRST_DATA_ID + @em 1);</tt>
	///< @since R17.032
};
/// @}

/// @addtogroup GV_INITIAL
/// @ingroup group_enumeration
/// @{
#define GV_INITIAL_OPCLASS_SUB_ID		(-1)
#define GV_INITIAL_OPGROUP_SUB_ID		(-1)
#define GV_INITIAL_VALGROUP_SUB_ID	(-1)
#define GV_INITIAL_DATA_SUB_ID			(-1)
#define GV_INITIAL_VALUE_SUB_ID			(-1)
/// @}

/// @addtogroup DataTypes
/// @ingroup group_enumeration
/// @{
typedef Int32 GvOpClassSubID;				///< Operator class sub-ID.
typedef Int32 GvOpGroupSubID;				///< Operator group sub-ID.
typedef Int32 GvValGroupSubID;			///< Value group sub-ID.
typedef Int32 GvDataSubID;					///< Data sub-ID.
typedef Int32 GvValueSubID;					///< Value sub-ID.
/// @}

/// @addtogroup GvOperatorType
/// @ingroup group_enumeration
/// @{
enum GvOperatorType
{
	GV_OPERATOR_TYPE_INVALID = 0,						///< Invalid.
	GV_OPERATOR_TYPE_GROUP,									///< Group.
	GV_OPERATOR_TYPE_NODE,									///< Node.
	GV_OPERATOR_TYPE_DUMMY,									///< Dummy.
	GV_OPERATOR_TYPE_GENERAL,								///< General.
	GV_OPERATOR_TYPE_CALCULATE,							///< Calculate.
	GV_OPERATOR_TYPE_ITERATOR,							///< Iterator.
	GV_OPERATOR_TYPE_BOOL,									///< Bool.
	GV_OPERATOR_TYPE_LOGICAL,								///< Logical.
	GV_OPERATOR_TYPE_ADAPTER,								///< Adapter.
	GV_OPERATOR_TYPE_THINKINGPARTICLES			///< Thinking particles.
};
/// @}

/// @addtogroup GvCalcState
/// @ingroup group_enumeration
/// @{
enum GvCalcState
{
	GV_CALC_STATE_NO_FAILURE = 0,				///< No failure.
	GV_CALC_STATE_DISABLED_FAILURE,			///< Disabled.
	GV_CALC_STATE_LOCAL_FAILURE,				///< Local failure.
	GV_CALC_STATE_MASTER_FAILURE,				///< Master failure.
	GV_CALC_STATE_GLOBAL_FAILURE				///< Global failure.
};
/// @}

/// @addtogroup GvPortIO
/// @ingroup group_enumeration
/// @{
enum GvPortIO
{
	GV_PORT_INVALID = 0,				///< Invalid.
	GV_PORT_INPUT,							///< Input.
	GV_PORT_OUTPUT,							///< Output.
	GV_PORT_INPUT_OR_GEDATA			///< Input or GeData.
};
/// @}

/// @addtogroup GvBodyDefaultSize
/// @ingroup group_enumeration
/// @{
enum GvBodyDefaultSize
{
	GV_DEFAULT_BODY_WIDTH = 32,
	GV_DEFAULT_BODY_HEIGHT = 12
};

#define GV_INVALID_POS_VALUE						(LIMIT<Int32>::MAX)

#define GV_COPY_OFFSET_X								10
#define GV_COPY_OFFSET_Y								10
#define GV_PACK_NODES_EXTRA_BORDER			12
#define GV_OPTIMIZE_NODES_EXTRA_BORDER	6
/// @}

/// @addtogroup GvState
/// @ingroup group_enumeration
/// @{
/// %User interaction states of a node
enum GvState
{
	GV_STATE_NORMAL = 0,								///< Normal.
	GV_STATE_SELECTED,									///< Selected.
	GV_STATE_DISABLED,									///< Disabled.
	GV_STATE_SELECTED_AND_DISABLED,			///< Selected and disabled.

	GV_NR_OF_STATES
};
/// @}

/// @addtogroup GvRunId
/// @ingroup group_enumeration
/// @{
enum GvRunId
{
	GV_RESET_RUN_ID = -1,
	GV_INITIAL_RUN_ID = 1
};
/// @}

#define GV_NODE_INVALID_INDEX		(-1)
#define GV_PORT_INVALID_ID			(-1)
#define GV_PORT_INVALID_INDEX		(-1)
#define GV_PORT_INVALID_SUB_ID	(-1)
#define GV_USERDATA_INVALID_ID	(-1)
#define GV_OPERATOR_INVALID_ID	(-1)
#define GV_PORT_INVALID_DESC		DescID()


/// @addtogroup GvDataType
/// @ingroup group_enumeration
/// @{
enum
{
	GV_INVALID = 0,													///< Undefined.
	GV_ATOMARRAY = DRAGTYPE_ATOMARRAY,			///< AtomArray*
	GV_BOOL = 400000000,										///< Bool*
	GV_INT,																	///< Int32*
	GV_REAL,																///< Float*
	GV_VECTOR,															///< Vector*
	GV_NORMAL,															///< Vector*
	GV_MATRIX,															///< Matrix*
	GV_TIME,																///< BaseTime*
	GV_STRING,															///< String*
	GV_ATOM,																///< C4DAtom*
	GV_USERDEF,															///< %User defined or private.
	GV_DESCID																///< DescID*
};

typedef Int32 GvDataType;
/// @}

/// @addtogroup GvOpSetDataMode
/// @ingroup group_enumeration
/// @{
enum GvOpSetDataMode
{
	GV_OP_NOP = 0,						///< Ignore.
	GV_OP_SET,								///< Set the internal value to the parameter value. (The constant node uses this.)
	GV_OP_DROP,								///< An atom has been dropped over the node.
	GV_OP_DROP_IN_BODY,				///< An atom has been dropped over the body of the node.
	GV_OP_DROP_IN_INDOCK,			///< An atom has been dropped in the inport area of the node.
	GV_OP_DROP_IN_OUTDOCK			///< An atom has been dropped in the outport area of the node.
};
/// @}

/// @addtogroup GvPortID
/// @ingroup group_enumeration
/// @{
/// Offsets of in/out ports
enum GvPortID
{
	GV_INPUT_FIRST_ID						= 10000000,				///< First input port ID.
	GV_INPUT_LAST_ID						= 19999990,				///< Last input port ID.
	GV_OUTPUT_FIRST_ID					= 20000000,				///< First output port ID.
	GV_OUTPUT_LAST_ID						= 29999990,				///< Last output port ID.
	GV_INPUT_FIRST_PRIVATE_ID		= 30000000,				///< First private input port ID.
	GV_INPUT_LAST_PRIVATE_ID		= 39999990,				///< Last private input port ID.
	GV_OUTPUT_FIRST_PRIVATE_ID	= 40000000,				///< First private output port ID.
	GV_OUTPUT_LAST_PRIVATE_ID		= 49999990				///< Last private output port ID.
};
/// @}

/// @addtogroup GvLayoutType
/// @ingroup group_enumeration
/// @{
/// Direction of editor layout.
enum GvLayoutType
{
	GV_LAYOUT_IN_LEFT = 0,			///< Left.
	GV_LAYOUT_IN_RIGHT,					///< Right.
	GV_LAYOUT_IN_TOP,						///< Top.
	GV_LAYOUT_IN_BOTTOM,				///< Bottom.

	GV_NR_OF_LAYOUT_TYPES
};
/// @}

/// @addtogroup GvConnMode
/// @ingroup group_enumeration
/// @{
enum GvConnMode
{
	GV_CONNECTION_MODE_DIRECT = 0,			///< Direct.
	GV_CONNECTION_MODE_STRAIGHT,				///< Straight.
	GV_CONNECTION_MODE_NORMAL,					///< Normal.
	GV_CONNECTION_MODE_CURVED						///< Curved.
};
/// @}

/// @addtogroup GvDrawState
/// @ingroup group_enumeration
/// @{
/// Nodes display states.
enum GvDrawState
{
	GV_DRAW_NONE = -1,					///< None.
	GV_DRAW_MINIMIZED = 0,			///< Minimized.
	GV_DRAW_NORMAL,							///< Normal.
	GV_DRAW_EXTENDED,						///< Extended.
	GV_DRAW_FULLSCREEN					///< Fullscreen.
};
/// @}

/// @addtogroup GV_PREFERENCES_ID
/// @ingroup group_containerid
/// @{
#define GV_GUI_PREFERENCES_ID 40000000				///< GUI preferences ID.
#define GV_WORLD_PREFERENCES_ID 40000001			///< World preferences ID.
#define GV_MASTER_PREFERENCES_ID 40000002			///< Master preferences ID.
/// @}

/// @addtogroup GvGuiConfigIDs
/// @ingroup group_containerid
/// @{
enum GvGuiConfigIDs
{
	GV_GUI_CONFIG_LAYOUT_TYPE = 1000,										///< ::GvLayoutType
	GV_GUI_CONFIG_CONNECTION_MODE,											///< ::GvConnMode
	GV_GUI_CONFIG_GRID_X,																///< ::Int32
	GV_GUI_CONFIG_GRID_Y,																///< ::Int32
	GV_GUI_CONFIG_STATUS_BAR,														///< ::Bool
	GV_GUI_CONFIG_CONNECTION_MIN_OFFSET,								///< ::Int32
	GV_GUI_CONFIG_CONNECTION_MAX_OFFSET,								///< ::Int32
	GV_GUI_CONFIG_TEXT_BORDER_HORZ,											///< ::Bool
	GV_GUI_CONFIG_TEXT_BORDER_VERT,											///< ::Bool
	GV_GUI_CONFIG_BORDER_SIZE,													///< ::Int32
	GV_GUI_CONFIG_DOCK_WIDTH,														///< ::Int32
	GV_GUI_CONFIG_DOCK_HEIGHT,													///< ::Int32
	GV_GUI_CONFIG_PORT_WIDTH,														///< ::Int32
	GV_GUI_CONFIG_PORT_HEIGHT,													///< ::Int32
	GV_GUI_CONFIG_PAN_WIDTH,														///< ::Int32
	GV_GUI_CONFIG_PAN_HEIGHT,														///< ::Int32
	GV_GUI_CONFIG_ZOOM_WIDTH,														///< ::Int32
	GV_GUI_CONFIG_ZOOM_HEIGHT,													///< ::Int32
	GV_GUI_CONFIG_PORT_SPACE,														///< ::Int32
	GV_GUI_CONFIG_HEAD_HEIGHT,													///< ::Int32
	GV_GUI_CONFIG_FOOT_HEIGHT,													///< ::Int32
	GV_GUI_CONFIG_CONNECTION_SELECT_DISTANCE,						///< ::Int32
	GV_GUI_CONFIG_ADDITIONAL_FRAME_SELECT_DISTANCE,			///< ::Int32
	GV_GUI_CONFIG_ADDITIONAL_PORT_LABEL_SPACE,					///< ::Int32
	GV_GUI_CONFIG_LINE_SPACE,														///< ::Int32
	GV_GUI_CONFIG_TEXT_COLOR,														///< ::Vector
	GV_GUI_CONFIG_HEAD_NORMAL_COLOR,										///< ::Vector
	GV_GUI_CONFIG_HEAD_ERROR_COLOR,											///< ::Vector
	GV_GUI_CONFIG_FOOT_COLOR,														///< ::Vector
	GV_GUI_CONFIG_BODY_COLOR,														///< ::Vector
	GV_GUI_CONFIG_GRID_COLOR,														///< ::Vector
	GV_GUI_CONFIG_INPORT_AREA_COLOR,										///< ::Vector
	GV_GUI_CONFIG_OUTPORT_AREA_COLOR,										///< ::Vector
	GV_GUI_CONFIG_INPORT_COLOR,													///< ::Vector
	GV_GUI_CONFIG_OUTPORT_COLOR,												///< ::Vector
	GV_GUI_CONFIG_INDOCK_COLOR,													///< ::Vector
	GV_GUI_CONFIG_OUTDOCK_COLOR,												///< ::Vector
	GV_GUI_CONFIG_PAN_COLOR,														///< ::Vector
	GV_GUI_CONFIG_ZOOM_COLOR,														///< ::Vector
	GV_GUI_CONFIG_SELECTBOX_COLOR,											///< ::Vector
	GV_GUI_CONFIG_BORDER_NORMAL_COLOR,									///< ::Vector
	GV_GUI_CONFIG_BORDER_SELECTED_COLOR,								///< ::Vector
	GV_GUI_CONFIG_INPORTLABEL_COLOR,										///< ::Vector
	GV_GUI_CONFIG_OUTPORTLABEL_COLOR,										///< ::Vector
	GV_GUI_CONFIG_INPORTLABEL_BORDER_COLOR,							///< ::Vector
	GV_GUI_CONFIG_OUTPORTLABEL_BORDER_COLOR,						///< ::Vector
	GV_GUI_CONFIG_CONNECTION_NORMAL_COLOR,							///< ::Vector
	GV_GUI_CONFIG_CONNECTION_TEMP_COLOR,								///< ::Vector
	GV_GUI_CONFIG_CONNECTION_VALID_COLOR,								///< ::Vector
	GV_GUI_CONFIG_CONNECTION_DISABLED_COLOR,						///< ::Vector
	GV_GUI_CONFIG_CONNECTION_FORBIDDEN_COLOR,						///< ::Vector
	GV_GUI_CONFIG_CONNECTION_SELECTED_COLOR,						///< ::Vector
	GV_GUI_CONFIG_CONNECTION_IN_FOCUS_COLOR,						///< ::Vector
	GV_GUI_CONFIG_PORTS_SQUARE,													///< ::Bool
	GV_GUI_CONFIG_BORDER_NORMAL_DISABLED_COLOR,					///< ::Vector
	GV_GUI_CONFIG_BORDER_SELECTED_DISABLED_COLOR,				///< ::Vector
	GV_GUI_CONFIG_SORT_MENUS,														///< ::Bool
	GV_GUI_CONFIG_SORT_PORTS,														///< ::Bool

	GV_GUI_CONFIG_NR_OF_ENTRIES
};
/// @}

/// @addtogroup GvMasterConfigIDs
/// @ingroup group_containerid
/// @{
/// GraphView master node preferences.
/// @see GvNodeMaster::GetPrefs() GvNodeMaster::SetPrefs()
enum GvMasterConfigIDs
{
	GV_MASTER_CONFIG_LIVE_REFRESH = 100,									///< ::Bool
	GV_MASTER_CONFIG_ANIM_REFRESH,												///< ::Bool

	GV_MASTER_CONFIG_PERFORMANCEVIEW_ENABLE,							///< ::Bool
	GV_MASTER_CONFIG_PERFORMANCEVIEW_MODE,								///< ::Int32
	GV_MASTER_CONFIG_PERFORMANCEVIEW_INTENSITY_COUNT,			///< ::Int32
	GV_MASTER_CONFIG_PERFORMANCEVIEW_INTENSITY_TIME				///< ::Float
};
/// @}

/// @addtogroup GvWorldConfigIDs
/// @ingroup group_containerid
/// @{
/// GraphView world preferences.
/// @see GvWorld::GetPrefs() GvWorld::SetPrefs()
enum GvWorldConfigIDs
{
	GV_WORLD_CONFIG_UNDO_DEPTH = 100,
};
/// @}


/// @addtogroup DataTypes
/// @ingroup group_enumeration
/// @{
typedef Int32 GvOperatorID;			///< Operator ID.
typedef Int32 GvOpClassID;			///< Operator class ID.
typedef Int32 GvOpGroupID;			///< Operator group ID.
typedef Int32 GvValGroupID;			///< Value group ID.
typedef Int32 GvDataID;					///< Data type ID.
typedef Int32 GvValueID;				///< Value type ID.
typedef Int32 GvUserDataID;			///< %User data ID.
/// @}


//----------------------------------------------------------------------------------------
/// Operator class handler. Use GvRegisterOpClassType() to register.
//----------------------------------------------------------------------------------------
struct GV_OPCLASS_HANDLER
{
		GvOpClassID class_id;			///< The operator class ID.

		//----------------------------------------------------------------------------------------
		/// Get the name of the operator class.
		/// @return												The operator class name. @theOwnsPointed{handler,String}
		//----------------------------------------------------------------------------------------
		const String* (*GetName)(void);

		//----------------------------------------------------------------------------------------
		/// Get the icon for the operator class.
		/// @note Currently not used.
		/// @return												The operator class icon. @theOwnsPointed{handler,BaseBitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* (*GetIcon)(void);
};

//----------------------------------------------------------------------------------------
/// Operator group handler. Use GvRegisterOpGroupType() to register.
//----------------------------------------------------------------------------------------
struct GV_OPGROUP_HANDLER
{
		GvOpGroupID group_id;			///< The operator group ID.

		//----------------------------------------------------------------------------------------
		/// Get the operator group name.
		/// @return												The operator group name. @theOwnsPointed{handler,String}
		//----------------------------------------------------------------------------------------
		const String* (*GetName)(void);

		//----------------------------------------------------------------------------------------
		/// Get the icon for the operator group.
		/// @note Currently not used.
		/// @return												The operator group icon. @theOwnsPointed{handler,BaseBitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* (*GetIcon)(void);
};

//----------------------------------------------------------------------------------------
/// Value handler. Use GvRegisterValueType() to register.
//----------------------------------------------------------------------------------------
struct GV_VALUE_HANDLER
{

		GvValueID			value_id;					///< Value ID.
		GvValueFlags	value_flags;			///< Value flags: @enumerateEnum{GvValueFlags}
		void*					userdata;					///< %User data.

		//----------------------------------------------------------------------------------------
		/// Allocate an array of @formatParam{nr_of_cpus} instances of the value and set data to point to this array.
		/// @param[in] userdata						%User data.
		/// @param[out] data							Assign a pointer to the allocated array.
		/// @param[in] nr_of_cpus					Number of CPUs to allocate values for.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool (*Alloc)(void *userdata, void *&data, Int32 nr_of_cpus);

		//----------------------------------------------------------------------------------------
		/// Free allocated values in @ref Alloc.
		/// @param[in] userdata						%User data.
		/// @param[out] data							An array of @formatParam{nr_of_cpus} values to free. Assigned @formatConstant{nullptr} afterwards.
		/// @param[in] nr_of_cpus					Number of CPUs to free values for.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		void (*Free)(void *userdata, void *&data, Int32 nr_of_cpus);

		//----------------------------------------------------------------------------------------
		/// Convert @formatParam{source} to @formatParam{dest} if possible.
		/// @param[in] userdata						%User data.
		/// @param[in] source_id					Determines the type of @formatParam{source}.
		/// @param[in] source							Source data. Points to GV data. The layout of the pointed data is determined by @formatParam{source_id}.
		/// @param[in] dest_id						Determines the type of @formatParam{dest}.
		/// @param[out] dest							Destination data. Points to GV data. The layout of the pointed data is determined by @formatParam{dest_id}.
		/// @param[in] cpu_id							CPU ID.
		/// @return												Result: @enumerateEnum{GvCalcError}
		//----------------------------------------------------------------------------------------
		GvCalcError (*Convert)(void *userdata, GvValueID source_id, const void* const source, GvValueID dest_id, void *dest, Int32 cpu_id);

		//----------------------------------------------------------------------------------------
		/// Perform a @formatParam{calculation}.
		/// @param[in] userdata						%User data.
		/// @param[in] id									Determines the type of the data parameters.
		/// @param[in] source1						First source data. Points to GV data. The layout of the pointed data is determined by @formatParam{id}.
		/// @param[in] source2						Second source data. Points to GV data. The layout of the pointed data is determined by @formatParam{id}.
		/// @param[out] dest							Destination data. Points to GV data. The layout of the pointed data is determined by @formatParam{id}.
		/// @param[in] cpu_id							CPU ID.
		/// @param[in] calculation				Calculation: @enumerateEnum{GvValueFlags}
		/// @param[in] parm1							Parameter.
		/// @return												Result: @enumerateEnum{GvCalcError}
		//----------------------------------------------------------------------------------------
		GvCalcError (*Calculate)(void *userdata, GvValueID id, const void* const source1, const void* const source2, void *dest, Int32 cpu_id, GvValueFlags calculation, Float parm1);

		//----------------------------------------------------------------------------------------
		/// Copy the data from an array in @formatParam{source} to @formatParam{dest}: <tt>*dest = source[cpu_id]</tt>.
		/// @param[in] userdata						%User data.
		/// @param[in] source							Source data. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[out] dest							Destination data. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] cpu_id							CPU ID.
		//----------------------------------------------------------------------------------------
		void (*CopyFrom)(void *userdata, const void* const source, void *dest, Int32 cpu_id);

		//----------------------------------------------------------------------------------------
		/// Copy the data from @formatParam{source} to an array in @formatParam{dest}: <tt>dest[cpu_id] = *source</tt>.
		/// @param[in] userdata						%User data.
		/// @param[in] source							Source data. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[out] dest							Destination data. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] cpu_id							CPU ID.
		//----------------------------------------------------------------------------------------
		void (*CopyTo)(void *userdata, const void* const source, void *dest, Int32 cpu_id);

		//----------------------------------------------------------------------------------------
		/// Report the value types that this value handler can convert from.
		/// @param[in] userdata						%User data.
		/// @param[out] table							Assign a pointer to a table of value IDs. @theOwnsPointed{handler,table}
		/// @return												The number of entries in @formatParam{table}.
		//----------------------------------------------------------------------------------------
		Int32 (*GetConversionsFrom)(void *userdata, GvValueID *&table);

		//----------------------------------------------------------------------------------------
		/// Report the value types that this value handler can convert to.
		/// @param[in] userdata						%User data.
		/// @param[out] table							Assign a pointer to a table of value IDs. @theOwnsPointed{handler,table}
		/// @return												Number of entries in @formatParam{table}.
		//----------------------------------------------------------------------------------------
		Int32 (*GetConversionsTo)(void *userdata, GvValueID *&table);

		//----------------------------------------------------------------------------------------
		/// Get the value name.
		/// @param[in] userdata						%User data.
		/// @return												Value name. @theOwnsPointed{handler,String}
		//----------------------------------------------------------------------------------------
		String (*GetName)(void *userdata);

		//----------------------------------------------------------------------------------------
		/// Read the value to @formatParam{data} from @formatParam{hf}.
		/// @param[in] userdata						%User data.
		/// @param[out] data							Data to read to. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] nr_of_cpus					Number of CPUs.
		/// @param[in] hf									Hyper file to read from.
		/// @param[in] level							Disc level.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool (*Read)(void *userdata, void* data, Int32 nr_of_cpus, HyperFile &hf, Int32 level);

		//----------------------------------------------------------------------------------------
		/// Write the value in @formatParam{data} to @formatParam{hf}.
		/// @param[in] userdata						%User data.
		/// @param[in] data								Data to write from. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] nr_of_cpus					Number of CPUs.
		/// @param[out] hf								Hyper file to write to.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool (*Write)(void *userdata, const void* const data, Int32 nr_of_cpus, HyperFile &hf);

		//----------------------------------------------------------------------------------------
		/// Get the icon for the value.
		/// @note Currently not used.
		/// @return												Value icon. @theOwnsPointed{handler,BaseBitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* (*GetIcon)(void *userdata);

		//----------------------------------------------------------------------------------------
		/// Retrieve a pointer to the data in @formatParam{source}: <tt>&source[cpu_id]</tt>.
		/// @warning This is a dangerous function, but it can be useful to avoid unnecessary copies.
		/// @param[in] userdata						%User data.
		/// @param[in] source							Source data. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] cpu_id							CPU ID.
		/// @return												Pointer to the data.
		//----------------------------------------------------------------------------------------
		const void* (*GetDataInstance)(void *userdata, const void* const source, Int32 cpu_id);
};

//----------------------------------------------------------------------------------------
/// Value group handler. Use GvRegisterValGroupType() to register.
//----------------------------------------------------------------------------------------
struct GV_VALGROUP_HANDLER
{
		GvValGroupID	group_id;			///< The value group ID.
		void*					userdata;			///< The user data.

		//----------------------------------------------------------------------------------------
		/// Get the value group name.
		/// @param[in] userdata						%User data.
		/// @return												The value group name. @theOwnsPointed{handler,String}
		//----------------------------------------------------------------------------------------
		String (*GetName)(void *userdata);
};

/// Resource symbol maximum length.
#define GV_RESOURCE_SYMBOL_MAX_LENGTH 32

//----------------------------------------------------------------------------------------
/// Data type handler. Use GvRegisterDataType() to register.
//----------------------------------------------------------------------------------------
struct GV_DATA_HANDLER
{
		//----------------------------------------------------------------------------------------
		/// Constructor.
		//----------------------------------------------------------------------------------------
		GV_DATA_HANDLER() { x_flags = 0; disclevel = 1; }

		GvDataID			data_id;				///< The data ID.
		GvValueID			value_id;				///< The value ID.
		GvValGroupID	group_id;				///< The value group Id.
		void*					userdata;				///< The user data.
		Int32					edit_id;				///< Not used. Should be set to @em 0.
		char					resource_symbol[GV_RESOURCE_SYMBOL_MAX_LENGTH];			///< Resource symbol.
		UInt32					x_flags;			///< Flags. See @ref GV_DATAHANDLER_FLAGS_DISCLEVEL.

		//----------------------------------------------------------------------------------------
		/// Get the data type name.
		/// @param[in] userdata						The user data.
		/// @return												The data type name. @theOwnsPointed{handler,String}
		//----------------------------------------------------------------------------------------
		String (*GetName)(void *userdata);

		//----------------------------------------------------------------------------------------
		/// Get the icon for the data type.
		/// @note Currently not used.
		/// @param[in] userdata						The user data.
		/// @return												The data type icon. @theOwnsPointed{handler,BaseBitmap}
		//----------------------------------------------------------------------------------------
		BaseBitmap* (*GetIcon)(void *userdata);

		//----------------------------------------------------------------------------------------
		/// Retrieve a container with the names of the default values the custom data type provides.\n
		/// For example, the ::Float data type provides default values like @em "Thousand" and @em "PI / 2".
		/// @param[in] userdata						The user data.
		/// @param[out] bc								The container to add the default values to.
		/// @return												The number of default value added to @formatParam{bc}.
		//----------------------------------------------------------------------------------------
		Int32 (*GetDefaultsList)(void *userdata, BaseContainer &bc);

		//----------------------------------------------------------------------------------------
		/// Set one of the constants reported by @ref GetDefaultsList() in <tt>data[cpu_id]</tt>.
		/// @param[in] userdata						The user data.
		/// @param[in] id									The default value ID.
		/// @param[in] data								The data to set the default value in. Points to GV data. The layout of the pointed data is determined by @ref value_id.
		/// @param[in] cpu_id							The CPU ID.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool (*SetDefault)(void *userdata, Int32 id, void *data, Int32 cpu_id);

		Int32 disclevel;			///< The disc level.
};

/// GV_DATA_HANDLER has a @ref GV_DATA_HANDLER::disclevel.
#define GV_DATAHANDLER_FLAGS_DISCLEVEL	(1 << 0)



/// @addtogroup GV_CONSTANT
/// @ingroup group_enumeration
/// @{
#define GV_CONSTANT_NONE		0
#define GV_CONSTANT_FIRST		1
/// @}

/// @addtogroup group_graphviewinternal
/// @{
struct GvDataInfo
{
	GV_DATA_HANDLER*			data_handler;
	GV_VALUE_HANDLER*			value_handler;
	GV_VALGROUP_HANDLER*	group_handler;
};

#define INDEX_GV_VALUE_TYPE_UNDEFINED	0
#define INDEX_GV_DATA_TYPE_UNDEFINED	0
#define INDEX_GV_GROUP_TYPE_UNDEFINED	0
#define INDEX_GV_CLASS_TYPE_UNDEFINED	0

#define INDEX_GV_VALUE_TYPE_INVALID		(-1)
#define INDEX_GV_DATA_TYPE_INVALID		(-1)
#define INDEX_GV_GROUP_TYPE_INVALID		(-1)
#define INDEX_GV_CLASS_TYPE_INVALID		(-1)

#define GV_DATA_TYPE_MENU_OFFSET 1000

#define GV_VALUE_SEPERATOR					String(";")
#define GV_VALUE_SEPERATOR_SPACED		String(" ; ")
#define GV_VALUE_SEPERATOR_CHR			';'

#define GV_ELEMENT_SEPERATOR				String("|")
#define GV_ELEMENT_SEPERATOR_SPACED	String(" | ")
#define GV_ELEMENT_SEPERATOR_CHR		'|'
/// @}

/// @addtogroup GvCalcFlags
/// @ingroup group_enumeration
/// @{
enum GvCalcFlags
{
	GV_CALC_FLAG_NONE					= (0),					///< No flag.
	GV_CALC_FLAG_READ_ONLY		= (1 << 0)			///< Operators are not allowed to write to the document.
};
/// @}

//----------------------------------------------------------------------------------------
/// Connections destination data.
//----------------------------------------------------------------------------------------
struct GvDestination
{
	//----------------------------------------------------------------------------------------
	/// Constructor. Sets pointers to @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	GvDestination() : node(nullptr), port(nullptr) { }

	GvNode*	node;			///< Destination node.
	GvPort*	port;			///< Destination port.
};

/// @addtogroup GvPortDescFlags
/// @ingroup group_enumeration
/// @{
enum GvPortDescFlags
{
	GV_PORTDESCRIPTION_NONE				= (0),					///< No flag.
	GV_PORTDESCRIPTION_MULTIPLE		= (1 << 0),			///< Allow multiple instances per node.
	GV_PORTDESCRIPTION_INVISIBLE	= (1 << 1),			///< Invisible port.
	GV_PORTDESCRIPTION_STATIC			= (1 << 2),			///< Static port.
	GV_PORTDESCRIPTION_FIXED			= (1 << 3),			///< Not movable.
	GV_PORTDESCRIPTION_PORTONLY		= (1 << 4),			///< Only as port.
	GV_PORTDESCRIPTION_NEEDED			= (1 << 5),			///< Needs a connection.
	GV_PORTDESCRIPTION_ITERATOR		= (1 << 6)			///< Iterator output.
};
/// @}

//----------------------------------------------------------------------------------------
/// Port description data.
//----------------------------------------------------------------------------------------
struct GvPortDescription
{
	//----------------------------------------------------------------------------------------
	/// Constructor. Sets pointers to @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	GvPortDescription() : name(String()), flags(GV_PORTDESCRIPTION_NONE), data_id(ID_GV_DATA_TYPE_NONE), ports_min(0), ports_max(0), parent_id(GV_PORT_INVALID_ID) { }

	String					name;						///< Name.
	GvPortDescFlags	flags;					///< Flags: @enumerateEnum{GvPortDescFlags}
	GvDataID				data_id;				///< Data type ID: @enumerateEnum{GvDataID}
	Int32						ports_min;			///< Minimum number of ports.
	Int32						ports_max;			///< Maximum number of ports.
	Int32						parent_id;			///< Parent ID.
};

//----------------------------------------------------------------------------------------
/// Port information data.
//----------------------------------------------------------------------------------------
struct GvPortInfo
{
	String	io;					///< I/O mode.
	String	name;				///< Name.
	String	data;				///< Data.
	String	value;			///< value.
};

/// @addtogroup GvPortFlags
/// @ingroup group_enumeration
/// @{
enum GvPortFlags
{
	GV_PORT_FLAG_NONE						= 0,						///< No flag.
	GV_PORT_FLAG_IS_VISIBLE			= (1 << 0),			///< Visible port.
	GV_PORT_FLAG_IS_ITERATE			= (1 << 1)			///< Iteration port.
};
/// @}

//----------------------------------------------------------------------------------------
/// Port description information.
//----------------------------------------------------------------------------------------
struct GvPortDescInfo
{
	struct PortInfo
	{
		GvDataID				type;				///< data IDs.
		UInt32					flag;				///< port flags.
		Int32						id;					///< port IDs.
		String					name;				///< port names.
	};
	maxon::BaseArray<PortInfo> _portInfo;
};

//----------------------------------------------------------------------------------------
/// Convenience collection of 2 GvPortDescInfo structures for the input and output ports.
//----------------------------------------------------------------------------------------
struct GvPortsDescInfo
{
	GvPortDescInfo	in;				///< Input ports information.
	GvPortDescInfo	out;			///< Output ports information.
};

//----------------------------------------------------------------------------------------
/// Convenience structure for port calculation speedup.
//----------------------------------------------------------------------------------------
struct GvPortsInfo
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvPortsInfo() : in_ports(nullptr), out_ports(nullptr), nr_of_in_ports(0), nr_of_out_ports(0) { }

	GvPort**	in_ports;							///< Array of input ports.
	GvPort**	out_ports;						///< Array of output ports.
	Int32			nr_of_in_ports;				///< Number of input ports.
	Int32			nr_of_out_ports;			///< Number of output ports.
};

struct GvValuesInfo
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvValuesInfo() { }

	maxon::BaseArray<GvValue*> in_values;						///< Array of input values.
	maxon::BaseArray<GvPort*> out_ports;						///< Array of output ports.

	//----------------------------------------------------------------------------------------
	/// Retrieves an input value by index.
	/// @param[in] value_index				The index of the value to get: @em 0 <= @formatParam{value_index} < @ref nr_of_in_values.
	/// @return												The value.
	//----------------------------------------------------------------------------------------
	GvValue* GetInValue(Int32 value_index) { return value_index >= 0 && value_index < in_values.GetCount() ? in_values[value_index] : nullptr; }
};

//----------------------------------------------------------------------------------------
/// Represents a GV data and information about its data type.
//----------------------------------------------------------------------------------------
struct GvDynamicData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvDynamicData() : data(nullptr), info(nullptr), cpu_count(0) { }

	void*				data;						///< Data pointer.
	GvDataInfo*	info;						///< Data type information.
	Int32				cpu_count;			///< CPU count.
};

/// @addtogroup GvOperatorDescriptionFlags
/// @ingroup group_enumeration
/// @{
enum GvOperatorDescriptionFlags
{
	GV_DESCRIPTIONFLAG_NONE					= (0)			///< No flag.
};
/// @}

struct GvOperatorDescription
{
	GvOperatorDescriptionFlags	flags;			///< Flags. See @ref GvOperatorDescriptionFlags.
};

/// @addtogroup GvOperatorFlags
/// @ingroup group_enumeration
/// @{
enum GvOperatorFlags
{
	GV_OPERATORFLAG_NONE								= (0),					///< No flag.
	GV_OPERATORFLAG_MP_SAVE							= (1 << 0),			///< MP save.
	GV_OPERATORFLAG_READ_ONLY_SAVE			= (1 << 1),			///< Read only save.
	GV_OPERATORFLAG_MULTIPLE_DRAW				= (1 << 2),			///< Multiple draw.
	GV_OPERATORFLAG_REFRESH_ON_DELETE		= (1 << 3),			///< Refresh on delete.
	GV_OPERATORFLAG_ITERATOR						= (1 << 4),			///< Iterator operator.
	GV_OPERATORFLAG_SAVE								= (GV_OPERATORFLAG_MP_SAVE | GV_OPERATORFLAG_READ_ONLY_SAVE)			///< A combination of @ref GV_OPERATORFLAG_MP_SAVE and @ref GV_OPERATORFLAG_READ_ONLY_SAVE.
};
/// @}

/// Mask for @ref GvOperatorFlags.
#define GV_OPERATORFLAGS_MASK			0x0000ffff


struct GvDropHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvDropHook() : master(nullptr), document(nullptr), user(nullptr), parent(nullptr), type(GV_INVALID), data(nullptr), mode(GV_OP_NOP), x(0), y(0), activate(true) { }

	GvNodeMaster*		master;				///< Node master.
	BaseDocument*		document;			///< Document.
	void*						user;					///< %User data.
	GvNode*					parent;				///< Parent.
	GvDataType			type;					///< Data type: @enumerateEnum{GvDataType}
	void*						data;					///< Dropped data.
	GvOpSetDataMode	mode;					///< Mode: @enumerateEnum{GvOpSetDataMode}
	Int32						x,						///< X coordinate.
									y;						///< Y coordinate.
	Bool						activate;			///< Activate.
};

struct GvCalcHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvCalcHook() : master(nullptr), document(nullptr), user(nullptr), calc(nullptr), status(false) { }

	GvNodeMaster*		master;				///< Node master.
	BaseDocument*		document;			///< Document.
	void*						user;					///< %User data.
	GvCalc*					calc;					///< Calculation helper.
	Bool						status;				///< Calculation status.
};

struct GvMenuHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvMenuHook() : master(nullptr), document(nullptr), user(nullptr), menu_id(0), menu(BaseContainer()) { }

	GvNodeMaster*		master;				///< Node master.
	BaseDocument*		document;			///< Document.
	void*						user;					///< %User data.
	Int32						menu_id;			///< Menu ID.
	BaseContainer		menu;					///< Menu structure. See ::ShowPopupMenu().
};

struct GvMessHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvMessHook() : master(nullptr), document(nullptr), user(nullptr), id(GV_MESSAGE_NONE), mess(BaseContainer()) { }

	GvNodeMaster*		master;				///< Node master.
	BaseDocument*		document;			///< Document.
	void*						user;					///< %User data.
	Int32						id;						///< Message ID.
	BaseContainer		mess;					///< Message container.
};

struct GvAnimHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvAnimHook() : document(nullptr), user(nullptr), time(nullptr) { }

	BaseDocument*		document;			///< Document.
	void*						user;					///< %User data.
	GvCalcTime*			time;					///< Calculation time information.
};

struct GvDrawHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvDrawHook() : document(nullptr), user(nullptr), base_draw(nullptr), draw_help(nullptr) { }

	BaseDocument*		document;					///< Document.
	void*						user;							///< %User data.
	BaseDraw*				base_draw;				///< Base draw.
	BaseDrawHelp*		draw_help;				///< Base draw helper.
	BaseThread*			base_thread;			///< The current thread.
	SCENEHOOKDRAW		flags;						///< The pass: @enumerateEnum{SCENEHOOKDRAW}
};

//----------------------------------------------------------------------------------------
/// Drop hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*GvDropHookFunc)(GvDropHook &hook);

//----------------------------------------------------------------------------------------
/// Calculation hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*GvCalcHookFunc)(GvCalcHook &hook);

//----------------------------------------------------------------------------------------
/// Menu hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*GvMenuHookFunc)(GvMenuHook &hook);

//----------------------------------------------------------------------------------------
/// Message hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*GvMessHookFunc)(GvMessHook &hook);

//----------------------------------------------------------------------------------------
/// Animation hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*GvAnimHookFunc)(GvAnimHook &hook);

//----------------------------------------------------------------------------------------
/// Draw hook function pointer.
/// @param[in] hook								The hook data.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef void (*GvDrawHookFunc)(GvDrawHook &hook);

//----------------------------------------------------------------------------------------
/// A structure for the various hooks that can be registered with the Graph View world. See each hook structure for more information.\n
/// Use GvWorld::RegisterHook() to register a hook.
//----------------------------------------------------------------------------------------
struct GvHook
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	GvHook() :
		drop_function(nullptr), init_calculation(nullptr), begin_calculation(nullptr), end_calculation(nullptr),
		begin_recalculation(nullptr), end_recalculation(nullptr), free_calculation(nullptr), menu_command(nullptr),
		build_menu(nullptr), message(nullptr), hook_init(nullptr), hook_main(nullptr), hook_free(nullptr),
		draw(nullptr),
		hook_id(0), owner_id(0), hook_name(String()), menu_name(String()) { }

	GvDropHookFunc	drop_function;						///< Drop hook.
	GvCalcHookFunc	init_calculation;					///< Init calculation hook.
	GvCalcHookFunc	begin_calculation;				///< Begin calculation hook.
	GvCalcHookFunc	end_calculation;					///< End calculation hook.
	GvCalcHookFunc	begin_recalculation;			///< Begin recalculation hook.
	GvCalcHookFunc	end_recalculation;				///< End recalculation hook.
	GvCalcHookFunc	free_calculation;					///< Free calculation hook.
	GvMenuHookFunc	menu_command;							///< Menu command hook.
	GvMenuHookFunc	build_menu;								///< Build menu hook.
	GvMessHookFunc	message;									///< Message hook.
	GvAnimHookFunc	hook_init;								///< Animation init hook.
	GvAnimHookFunc	hook_main;								///< Animation main hook.
	GvAnimHookFunc	hook_free;								///< Animation free hook.
	GvDrawHookFunc	draw;											///< Draw hook.

	Int32		hook_id;				///< A unique hook ID. Must be obtained from http://www.plugincafe.com
	Int32		owner_id;				///< Owner ID.
	String	hook_name;			///< Hook name.
	String	menu_name;			///< Menu hook name.
};

/// @addtogroup GvCalcHookType
/// @ingroup group_enumeration
/// @{
enum GvCalcHookType
{
	GV_CALC_HOOK_INIT = 0,							///< Init calculation.
	GV_CALC_HOOK_BEGIN,									///< Begin calculation.
	GV_CALC_HOOK_END,										///< End calculation.
	GV_CALC_HOOK_RECALCULATE_BEGIN,			///< Begin recalculation.
	GV_CALC_HOOK_RECALCULATE_END,				///< End recalculation.
	GV_CALC_HOOK_FREE										///< Free calculation.
};
/// @}

/// @addtogroup GvAnimHookType
/// @ingroup group_enumeration
/// @{
enum GvAnimHookType
{
	GV_ANIM_HOOK_INIT = 0,			///< Init animation.
	GV_ANIM_HOOK_FREE,					///< Free animation.
	GV_ANIM_HOOK_MAIN						///< Animation main function.
};
/// @}

//----------------------------------------------------------------------------------------
/// Hook callback function pointer.
/// @param[in] doc								Document.
/// @param[in] id									Hook ID.
/// @return												The scene hook.
//----------------------------------------------------------------------------------------
typedef BaseList2D *(*GvHookCallback)(BaseDocument *doc, Int32 id);


/// @addtogroup GvInsertMode
/// @ingroup group_enumeration
/// @{
enum GvInsertMode
{
	GV_INSERT_UNDER = 0,			///< Insert under.
	GV_INSERT_UNDER_LAST,			///< Insert under as last item.
	GV_INSERT_BEFORE,					///< Insert before.
	GV_INSERT_AFTER,					///< Insert after.
	GV_INSERT_NONE						///< Not used.
};
/// @}

typedef Int32 GvValueType;
#define GV_MULTIPLE_PORTS		((GvValueType)(-1))			///< All ports.

typedef Int32* GvIdTablePtr;
/// @addtogroup GV_PORTS
/// @ingroup group_enumeration
/// @{
#define GV_EXISTING_PORTS		((GvIdTablePtr)(0x00000000))			///< Existing ports.
#define GV_DEFINED_PORTS		((GvIdTablePtr)(Int)(-1))					///< Defined ports.
/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

//----------------------------------------------------------------------------------------
// Global functions
//----------------------------------------------------------------------------------------

struct C4D_GvGlobals
{
	GvWorld*						(*GetWorld									)(void);

	void								(*OperatorDefaultDraw				)(GvNode *node, GvNodeGUI* gui, GeUserArea *da, Int32 x1, Int32 y1, Int32 x2, Int32 y2);
	Vector							(*GetDefaultBodyColor				)(GvNode *node);
	void								(*GetDefaultBodySize				)(Int32 *width, Int32 *height);
	Bool								(*DefaultSetRecalculate			)(GvNode *bn, GvPort *port, GvRun *r, Bool force_set);
	Int32								(*FillPortsMenu							)(GvNode *bn, BaseContainer &names, BaseContainer &ids, GvValueID value_type, GvPortIO port, Int32 first_menu_id);

	void								(*GetPortList								)(GvPortsDescInfo *info, GvPortIO port, GvPortList &portlist);
	Bool								(*GetAllDataTypes						)(GvPortDescInfo *info, UInt32 default_flag, Int32 first_id);
	void								(*FreePortDescInfo					)(GvPortDescInfo *info);

	Bool								(*RegisterOperatorPlugin		)(GvOperatorID id, const maxon::String &str, Int32 info, DataAllocator *at, Int32 disklevel, GvOpClassID op_class, GvOpGroupID op_group, Int32 op_owner, OPERATORPLUGIN *plug, BaseBitmap *icon);
	Bool								(*RegisterOpClassType				)(GV_OPCLASS_HANDLER *data, Int32 struct_size);
	Bool								(*RegisterOpGroupType				)(GV_OPGROUP_HANDLER *data, Int32 struct_size);
	Bool								(*RegisterValGroupType			)(GV_VALGROUP_HANDLER *data, Int32 struct_size);
	Bool								(*RegisterValueType					)(GV_VALUE_HANDLER *data, Int32 struct_size);
	Bool								(*RegisterDataType					)(GV_DATA_HANDLER *data, Int32 struct_size, const char *symbol);

	GV_OPCLASS_HANDLER* (*FindRegisteredOpClass			)(GvOpClassID id);
	GV_OPGROUP_HANDLER* (*FindRegisteredOpGroup			)(GvOpGroupID id);

	const String				(*GetEmptyString						)(void);
	const String				(*GetErrorString						)(const maxon::String &command, Int32 err);
};

//----------------------------------------------------------------------------------------
// GvWorld functions
//----------------------------------------------------------------------------------------

struct C4D_GvWorld
{
	GvNodeMaster*		(*AllocNodeMaster						)(GvWorld *world, BaseList2D *object, Bool add_to_list, Bool send_messages);
	void						(*FreeNodeMaster						)(GvWorld *world, GvNodeMaster *&master);

	GvShape*				(*AllocShape								)(GvWorld *world);
	GvShape*				(*AllocGroupShape						)(GvWorld *world);
	void						(*FreeShape									)(GvWorld *world, GvShape *&shape);

	GvNodeGUI*			(*AllocNodeGUI							)(GvWorld *world, GvShape *shape, GvShape *group, Int32 user_area_id);
	void						(*FreeNodeGUI								)(GvWorld *world, GvNodeGUI *&gui);
	Bool						(*AttachNode								)(GvWorld *world, GvNodeMaster *master, GvNode *node, Int32 x, Int32 y);
	void						(*RedrawAll									)(GvWorld *world);
	void						(*RedrawMaster							)(GvWorld *world, GvNodeMaster *master);

	const String		(*GetString									)(GvWorld *world, const maxon::String &title, const maxon::String &default_value);
	Float						(*GetFloat									)(GvWorld *world, const maxon::String &title, Float default_value);
	Int32						(*GetInteger								)(GvWorld *world, const maxon::String &title, Int32 default_value);

	Int32						(*GetDataTypesMenu					)(GvWorld *world, BaseContainer &bc, BaseContainer &index, Int32 first_menu_id, Int32 first_sub_id, Bool show_undefined_type, GvValueFlags flags);
	Int32						(*GetDataTypes							)(GvWorld *world, BaseContainer &bc, GvDataOptions options, GvValueFlags flags);
	Bool						(*GetDataTypesTable					)(GvWorld *world, GvDataInfo *&info, Int32 &count);
	Int32						(*GetDataTypeIndex					)(GvWorld *world, GvDataID id);
	GvDataInfo*			(*GetDataTypeInfo						)(GvWorld *world, Int32 index);

	Bool						(*RegisterHook							)(GvWorld *world, const GvHook &hook, void *user);
	Bool						(*AttachHook								)(GvWorld *world, Int32 hook_id, GvHookCallback callback);
	void						(*DetachHook								)(GvWorld *world, Int32 hook_id);
	BaseList2D*			(*GetHookInstance						)(GvWorld *world, BaseDocument *doc, Int32 hook_id);

	Bool						(*SendHookMessage						)(GvWorld *world, BaseDocument *doc, GvNodeMaster *master, GvMessHook &data, Int32 owner_id);
	Bool						(*SendOperatorMessage				)(GvWorld *world, BaseDocument *doc, Int32 message_id, void *data);

	Bool						(*OpenDialog								)(GvWorld *world, Int32 id, GvNodeMaster *master);
	void						(*CloseDialog								)(GvWorld *world, Int32 id);

	GvNodeGUI*			(*GetMasterGUI							)(GvWorld *world, GvNodeMaster *master, UInt32 nr);
	UInt32					(*GetUniqueID								)(GvWorld *world);

	BaseBitmap*			(*GetDefaultOperatorIcon		)(GvWorld *world, GvOperatorType type);

	void						(*WorldSetPrefs							)(GvWorld *world, const BaseContainer &bc);
	void						(*WorldGetPrefs							)(GvWorld *world, BaseContainer &bc);

	Int32						(*GetDataTypeNames					)(GvWorld *world, BaseContainer &bc, GvDataID *ids);
	GvNodeMaster*		(*GetMaster									)(GvWorld *world, Int32 id);

	void						(*SetForceUpdate						)(GvWorld *world);
};

//----------------------------------------------------------------------------------------
// GvNodeMaster functions
//----------------------------------------------------------------------------------------

struct C4D_GvNodeMaster
{
	GvNode*					(*AllocNode									)(GvNodeMaster *master, Int32 id);
	void						(*FreeNode									)(GvNodeMaster *master, GvNode *&node);
	GvNode*					(*CreateNode								)(GvNodeMaster *master, GvNode *parent, Int32 id, GvNode *insert, Int32 x, Int32 y);
	GvNode*					(*GetRoot										)(GvNodeMaster *master);
	BaseList2D*			(*GetOwner									)(GvNodeMaster *master);
	Bool						(*IsConnectionValid					)(GvNodeMaster *master, GvNode *source_node, GvPort *source_port, GvNode *dest_node, GvPort *dest_port, GvNode *&source_node_out, GvPort *&source_port_out, GvNode *&dest_node_out, GvPort *&dest_port_out);
	Bool						(*InsertFirst								)(GvNodeMaster *master, GvNode *parent, GvNode *node);
	Bool						(*InsertLast								)(GvNodeMaster *master, GvNode *parent, GvNode *node);
	Bool						(*SetHierarchy							)(GvNodeMaster *master, GvNode *insert, GvNode *node, GvInsertMode mode);
	GvCalcError			(*QueryCalculation					)(GvNodeMaster *master, GvQuery *query, BaseThread *thread);
	GvCalcError			(*InitCalculation						)(GvNodeMaster *master, GvInit *init, BaseThread *thread);
	GvCalcError			(*Calculate									)(GvNodeMaster *master, Int32 cpu_id);
	GvCalcError			(*Recalculate								)(GvNodeMaster *master, GvNode *node, Int32 cpu_id);
	void						(*FreeCalculation						)(GvNodeMaster *master);
	GvRun*					(*GetRun										)(GvNodeMaster *master);
	GvCalc*					(*GetCalc										)(GvNodeMaster *master);
	GvQuery*				(*AllocQuery								)(GvNodeMaster *master);
	void						(*FreeQuery									)(GvNodeMaster *master, GvQuery *&query);
	GvInit*					(*AllocInit									)(GvNodeMaster *master);
	void						(*FreeInit									)(GvNodeMaster *master, GvInit *&init);
	GvUserDataID		(*RegisterUserData					)(GvNodeMaster *master, void *data);
	void						(*SetUserData								)(GvNodeMaster *master, GvUserDataID id, void *data);
	void*						(*GetUserData								)(GvNodeMaster *master, GvUserDataID id);
	GvCalcTable*		(*AllocCalculationTable			)(GvNodeMaster *master, Int32 cpu_count, Bool sort, Int32 nr_of_preallocated_entries, Bool iteration);
	void						(*FreeCalculationTable			)(GvNodeMaster *master, GvCalcTable *&table);
	Bool						(*AddToDrawList							)(GvNodeMaster *master, GvNode *bn, void **data, Int32 data_size);
	void						(*MasterSetPrefs						)(GvNodeMaster *master, const BaseContainer &bc);
	void						(*MasterGetPrefs						)(GvNodeMaster *master, BaseContainer &bc);
	GvCopyBuffer*		(*GetCopyBuffer							)(GvNodeMaster *master, GvNode *first, Bool copy_selected);
	void						(*FreeCopyBuffer						)(GvNodeMaster *master, GvCopyBuffer *&buffer);
	Bool						(*PasteFromBuffer						)(GvNodeMaster *master, GvCopyBuffer &buffer, GvInsertMode mode, GvNode *dest, Int32 x, Int32 y, Bool center, void *info);
	Bool						(*IsEnabled									)(GvNodeMaster *master);
	GvCalcError			(*Execute										)(GvNodeMaster *master, BaseThread *thread);
	Int32						(*GetBranchInfo							)(GvNodeMaster *master, BranchInfo *info, Int32 max);
	Bool						(*AddUndo										)(GvNodeMaster *master);
	GvCalcError			(*Execute2									)(GvNodeMaster *master, BaseThread *thread, GvCalcFlags flags);
};

//----------------------------------------------------------------------------------------
// GvNodeGUI functions
//----------------------------------------------------------------------------------------

struct C4D_GvNodeGUI
{
	Bool						(*GuiAttach									)(GvNodeGUI *gui, GeDialog *dialog, GvNodeMaster *master);
	void						(*GuiDetach									)(GvNodeGUI *gui);
	Bool						(*GuiInitShapes							)(GvNodeGUI *gui);
	void						(*GuiDraw										)(GvNodeGUI *gui);
	void						(*GuiMouseDown							)(GvNodeGUI *gui, Int32 x, Int32 y, Int32 chn, Int32 qa, const BaseContainer &msg);
	Int32						(*GuiMessage								)(GvNodeGUI *gui, const BaseContainer &msg, BaseContainer &result);
	Int32						(*GuiCommand								)(GvNodeGUI *gui, Int32 id);
	void						(*GuiSelectAllNodes					)(GvNodeGUI *gui, GvNode *node, Bool select_state, Bool add_to_selection);
	void						(*GuiRemoveAllSelectedNodes	)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiSelectNode							)(GvNodeGUI *gui, GvNode *node, Bool select_state, Bool add_to_selection, Bool send_message);
	GvNode*					(*GuiGetNodeGlobal					)(GvNodeGUI *gui, Int32 x, Int32 y);
	GvNode*					(*GuiGetNodeLocal						)(GvNodeGUI *gui, GvNode *node, Int32 x, Int32 y);
	Bool						(*GuiIsInNodeBody						)(GvNodeGUI *gui, GvNode *node, Int32 x, Int32 y);
	Bool						(*GuiIsInNodeHead						)(GvNodeGUI *gui, GvNode *node, Int32 x, Int32 y);
	void						(*GuiRedraw									)(GvNodeGUI *gui);
	GeUserArea*			(*GuiGetUserArea						)(GvNodeGUI *gui);
	GvNodeMaster*		(*GuiGetMaster							)(GvNodeGUI *gui);
	GeDialog*				(*GuiGetDialog							)(GvNodeGUI *gui);
	void						(*GuiDisableSelected				)(GvNodeGUI *gui, GvNode *node, Bool disable_state);
	void						(*GuiSetPrefs								)(GvNodeGUI *gui, const BaseContainer &bc);
	void						(*GuiGetPrefs								)(GvNodeGUI *gui, BaseContainer &bc);
	void						(*GuiSetNodePosGlobal				)(GvNodeGUI *gui, GvNode *node, Int32 x, Int32 y, Bool center);
	Bool						(*GuiNodeContextMenu				)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiSetNodePos							)(GvNodeGUI *gui, GvNode *node, Int32 x, Int32 y);
	void						(*GuiSetNodeSize						)(GvNodeGUI *gui, GvNode *node, Int32 width, Int32 height);
	void						(*GuiOptimizeNode						)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiShowAllNodes						)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiCenterNodes						)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiAlignNodesToUpperLeft	)(GvNodeGUI *gui, GvNode *node);
	void						(*GuiGetZoom								)(GvNodeGUI *gui, GvNode *node, Float &zoom);
	void						(*GuiSetFocus								)(GvNodeGUI *gui, GvNode *node, Bool activate);
};


//----------------------------------------------------------------------------------------
// GvNode functions
//----------------------------------------------------------------------------------------

struct C4D_GvNode
{
	void						(*Redraw										)(GvNode *gn);
	GvPort*					(*AddPort										)(GvNode *gn, GvPortIO io, Int32 id, GvPortFlags flags, Bool message);
	Bool						(*AddPortIsOK								)(GvNode *gn, GvPortIO io, Int32 id);
	Bool						(*SetPortType								)(GvNode *gn, GvPort *port, Int32 id);
	Bool						(*ResetPortType							)(GvNode *gn, Int32 id);
	void						(*RemovePort								)(GvNode *gn, GvPort *port, Bool message);
	Bool						(*RemovePortIsOK						)(GvNode *gn, GvPort *port);
	void						(*RemoveUnusedPorts					)(GvNode *gn, Bool message);
	GvPort*					(*AddConnection							)(GvNode *gn, GvNode *source_node, GvPort *source_port, GvNode *dest_node, GvPort *dest_port);
	void						(*RemoveNodeConnections			)(GvNode *gn);
	Int32						(*GetInPortCount						)(GvNode *gn);
	Int32						(*GetOutPortCount						)(GvNode *gn);
	GvPort*					(*GetInPort									)(GvNode *gn, Int32 index);
	GvPort*					(*GetOutPort								)(GvNode *gn, Int32 index);
	GvPort*					(*GetInPortMainID						)(GvNode *gn, Int32 id, Int32 &start);
	GvPort*					(*GetOutPortMainID					)(GvNode *gn, Int32 id, Int32 &start);
	GvPort*					(*GetInPortFirstMainID			)(GvNode *gn, Int32 id);
	GvPort*					(*GetOutPortFirstMainID			)(GvNode *gn, Int32 id);
	GvPort*					(*GetInPortSubID						)(GvNode *gn, Int32 id);
	GvPort*					(*GetOutPortSubID						)(GvNode *gn, Int32 id);
	GvNodeMaster*		(*GetNodeMaster							)(GvNode *gn);
	GvOperatorData*	(*GetOperatorData						)(GvNode *gn);
	Int32						(*GetOperatorID							)(GvNode *gn);
	Int32						(*GetOwnerID								)(GvNode *gn);
	Bool						(*IsGroupNode								)(GvNode *gn);
	GvPort*					(*NodeCalculateInPortIndex	)(GvNode *gn, Int32 port_index, GvRun *run, GvCalc *calc);
	GvPort*					(*NodeCalculateOutPortIndex	)(GvNode *gn, Int32 port_index, GvRun *run, GvCalc *calc);
	BaseContainer*	(*GetOpContainerInstance		)(GvNode *gn);
	BaseContainer		(*GetOperatorContainer			)(GvNode *gn);
	void						(*SetOperatorContainer			)(GvNode *gn, const BaseContainer &bc);
	Bool						(*SetRecalculate						)(GvNode *gn, GvRun *run, Bool force_set);
	Int32						(*GetPortIndex							)(GvNode *gn, Int32 sub_id);
	GvPort*					(*GetPort										)(GvNode *gn, Int32 sub_id);
	GvPort*					(*NodeCalculateInPort				)(GvNode *gn, GvPort *port, GvRun *run, GvCalc *calc);
	GvPort*					(*NodeCalculateOutPort			)(GvNode *gn, GvPort *port, GvRun *run, GvCalc *calc);
	const String		(*OperatorGetDetailedText		)(GvNode *gn);
	const String		(*OperatorGetErrorString		)(GvNode *gn, Int32 error);
	Bool						(*OperatorSetData						)(GvNode *gn, GvDataType type, void *data, GvOpSetDataMode mode);
	Bool						(*OperatorIsSetDataAllowed	)(GvNode *gn, GvDataType type, void *data, GvOpSetDataMode mode);
	Bool						(*GetSelectState						)(GvNode *gn);
	Bool						(*GetFailureState						)(GvNode *gn);
	Bool						(*GetDisabledState					)(GvNode *gn);
	Bool						(*GetOpenState							)(GvNode *gn);
	void						(*SetOpenState							)(GvNode *gn, Bool state);
	Bool						(*GetLockState							)(GvNode *gn);
	void						(*SetLockState							)(GvNode *gn, Bool state);
	Bool						(*GetShowPortNamesState			)(GvNode *gn);
	void						(*SetShowPortNamesState			)(GvNode *gn, Bool state);
	void						(*OperatorGetIcon						)(GvNode *gn, IconData &dat);
	GvValue*				(*AllocCalculationHandler		)(GvNode *gn, Int32 main_id, GvCalc *calc, GvRun *run, Int32 singleport);
	void						(*FreeCalculationHandler		)(GvNode *gn, GvValue *&value);

	Bool						(*GetPortDescription				)(GvNode *gn, GvPortIO port, Int32 id, GvPortDescription *pd, Int32 privateflags);
	void						(*GetPortList								)(GvNode *bn, GvPortIO port, GvPortList &portlist, Int32 privateflags);
	const String		(*GetTitle									)(GvNode *bn, Int32 privateflags);
	void						(*SetTitle									)(GvNode *bn, const maxon::String &title, Int32 privateflags);
	Bool						(*CreateOperator						)(GvNode *bn, Int32 privateflags);

	Bool						(*CalculateRawData					)(GvNode *bn, GvValueID value_id, const void* const data1, const void* const data2, void *dest, GvValueFlags calculation, Float parm1);
};

//----------------------------------------------------------------------------------------
// GvPort functions
//----------------------------------------------------------------------------------------

struct C4D_GvPort
{
	void						(*RemoveConnection					)(GvPort *port);
	Int32						(*GetNrOfConnections				)(GvPort *port);
	void						(*RemovePortConnections			)(GvPort *port);
	Bool						(*IsIncomingConnected				)(GvPort *port);
	Bool						(*GetIncomingDestination		)(GvPort *port, GvNode *&node, GvPort *&prt);
	Bool						(*GetIncomingSource					)(GvPort *port, GvNode *&node, GvPort *&prt);
	GvPortIO				(*GetIO											)(GvPort *port);
	void						(*SetMainID									)(GvPort *port, Int32 id);
	Int32						(*GetMainID									)(GvPort *port);
	void						(*SetUserID									)(GvPort *port, Int32 id);
	Int32						(*GetUserID									)(GvPort *port);
	Int32						(*GetSubID									)(GvPort *port);
	GvValueID				(*GetValueType							)(GvPort *port);
	void						(*SetVisible								)(GvPort *port, Bool v);
	Bool						(*GetVisible								)(GvPort *port);
	void						(*SetValid									)(GvPort *port, GvRun *r, Bool v);
	Bool						(*GetValid									)(GvPort *port, GvRun *r);
	void						(*SetCalculated							)(GvPort *port, GvRun *r);
	GvPort*					(*Calculate									)(GvPort *port, GvNode *bn, GvRun *r, GvCalc *c);
	Bool						(*SetRecalculate						)(GvPort *port, GvRun *r, Bool force_set);
	Bool						(*GetBool										)(GvPort *port, Bool *b, GvRun *r);
	Bool						(*GetInteger								)(GvPort *port, Int32 *i, GvRun *r);
	Bool						(*GetFloat									)(GvPort *port, Float *f, GvRun *r);
	Bool						(*GetVector									)(GvPort *port, Vector *v, GvRun *r);
	Bool						(*GetNormal									)(GvPort *port, Vector *n, GvRun *r);
	Bool						(*GetMatrix									)(GvPort *port, Matrix *m, GvRun *r);
	Bool						(*GetTime										)(GvPort *port, BaseTime *t, GvRun *r);
	Bool						(*GetData										)(GvPort *port, void *d, GvValueID type, GvRun *r);
	Bool						(*SetBool										)(GvPort *port, Bool b, GvRun *r);
	Bool						(*SetInteger								)(GvPort *port, Int32 i, GvRun *r);
	Bool						(*SetFloat									)(GvPort *port, Float f, GvRun *r);
	Bool						(*SetVector									)(GvPort *port, const Vector &v, GvRun *r);
	Bool						(*SetNormal									)(GvPort *port, const Vector &n, GvRun *r);
	Bool						(*SetMatrix									)(GvPort *port, const Matrix &m, GvRun *r);
	Bool						(*SetTime										)(GvPort *port, const BaseTime &t, GvRun *r);
	Bool						(*SetData										)(GvPort *port, const void* const d, GvValueID type, GvRun *r);
	const String		(*GetName										)(GvPort *port, GvNode *node);
	void						(*SetName										)(GvPort *port, const maxon::String &name);
	Bool						(*CopyRawData								)(GvPort *port, void *source, GvRun *r);
	Bool						(*CopyPortData							)(GvPort *port, GvPort *source, GvRun *r);
	Bool						(*CalculateRawData					)(GvPort *port, void *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1);
	Bool						(*CalculateRawRawData				)(GvPort *port, void *data1, void *dats2, void *dest, GvRun *r, GvValueFlags calculation, Float parm1);
	Bool						(*CalculatePortData					)(GvPort *port, GvPort *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1);
	Bool						(*GetString									)(GvPort *port, maxon::String *s, GvRun *r);
	Bool						(*SetString									)(GvPort *port, const maxon::String &s, GvRun *r);
	Bool						(*GetObject									)(GvPort *port, BaseList2D *&o, GvRun *r);
	Bool						(*SetObject									)(GvPort *port, const BaseList2D* const o, GvRun *r);
	Bool						(*CalculateRawDataRev				)(GvPort *port, void *data, void *dest, GvRun *r, GvValueFlags calculation, Float parm1);
	Bool						(*GetDataInstance						)(GvPort *port, const void *&d, GvValueID type, GvRun *r);
	Bool						(*GetTag										)(GvPort *port, BaseList2D *&t, GvRun *r, Int32 *index);
	Bool						(*SetTag										)(GvPort *port, const BaseList2D* const t, GvRun *r, Int32 index);
	Bool						(*GetMaterial								)(GvPort *port, BaseList2D *&m, GvRun *r, Int32 *index);
	Bool						(*SetMaterial								)(GvPort *port, const BaseList2D* const m, GvRun *r, Int32 index);
	Bool						(*GetInstance								)(GvPort *port, BaseList2D *&i, GvRun *r, Int32 *index);
	Bool						(*SetInstance								)(GvPort *port, const BaseList2D* const i, GvRun *r, Int32 index);
	Bool						(*GetObjectWithIndex				)(GvPort *port, BaseList2D *&o, GvRun *r, Int32 *index);
	Bool						(*SetObjectWithIndex				)(GvPort *port, const BaseList2D* const o, GvRun *r, Int32 index);
	GvDestination*	(*GetOutgoing								)(GvPort *port, Int32 index);

	GeData*					(*GetUserData								)(GvPort *port);
	void						(*SetUserData								)(GvPort *port, const GeData& data);
};

//----------------------------------------------------------------------------------------
// GvRun functions
//----------------------------------------------------------------------------------------

struct C4D_GvRun
{
	void						(*SetError									)(GvRun *run, GvCalcError error);
	GvCalcError			(*GetError									)(GvRun *run);
	void						(*SetState									)(GvRun *run, GvCalcState state);
	GvCalcState			(*GetState									)(GvRun *run);
	void						(*IncrementID								)(GvRun *run);
	void						(*SetCalculationTable				)(GvRun *run, GvCalcTable *t);
	Bool						(*AddNodeToCalculationTable	)(GvRun *run, GvNode *node, Bool force_add);
	Bool						(*CalculateTable						)(GvRun *run, GvCalc *calc);
	Int32						(*GetCpuID									)(GvRun *run);
	Bool						(*IsIterationPath						)(GvRun *run);
};

//----------------------------------------------------------------------------------------
// GvCalcTable functions
//----------------------------------------------------------------------------------------

struct C4D_GvCalcTable
{
	Bool						(*AddNodeToTable						)(GvCalcTable *table, GvRun *run, GvNode *node);
	void						(*ResetTable								)(GvCalcTable *table, GvRun *run);
	Int32						(*GetTableCount							)(GvCalcTable *table, GvRun *run);
	GvNode*					(*GetTableNode							)(GvCalcTable *table, GvRun *run, Int32 id);
};

//----------------------------------------------------------------------------------------
// GvQuery functions
//----------------------------------------------------------------------------------------

struct C4D_GvQuery
{
	void						(*SetFlags									)(GvQuery *query, GvCalcFlags flags);
	GvCalcFlags			(*GetFlags									)(GvQuery *query);
	void						(*SetError									)(GvQuery *query, GvCalcError error);
	GvCalcError			(*GetError									)(GvQuery *query);
};

//----------------------------------------------------------------------------------------
// GvInit functions
//----------------------------------------------------------------------------------------

struct C4D_GvInit
{
	void						(*SetError									)(GvInit *init, GvCalcError error);
	GvCalcError			(*GetError									)(GvInit *init);
};

//----------------------------------------------------------------------------------------
// GvValue functions
//----------------------------------------------------------------------------------------

struct C4D_GvValue
{
	Bool						(*Calculate									)(GvValue *value, GvNode *node, GvPortIO io, GvRun *r, GvCalc *c, Int32 index, BaseTime *time);
	Bool						(*IsConnected								)(GvValue *value, Int32 index);
	Bool						(*IsPort										)(GvValue *value);
	Int32						(*NrOfPorts									)(GvValue *value);
	GvValueID				(*GetValueID								)(GvValue *value);
	GvPort*					(*GetPort										)(GvValue *value, Int32 index);
	Int32						(*GetMainID									)(GvValue *value);
};

class iGvPortList;

//----------------------------------------------------------------------------------------
// GvPortList functions
//----------------------------------------------------------------------------------------

struct C4D_GvPortList
{
	iGvPortList*		(*Alloc											)();
	void						(*Free											)(iGvPortList* &list);

	Int32						(iGvPortList::*GetCount			)(void) const;
	Bool						(iGvPortList::*Append				)(GvPortListEntry *e);
	Bool						(iGvPortList::*Remove				)(GvPortListEntry *e);
	GvPortListEntry*(iGvPortList::*GetIndex			)(Int32 i) const;
	void						(iGvPortList::*FlushAll			)(void);
};

//----------------------------------------------------------------------------------------
// Global function table
//----------------------------------------------------------------------------------------

struct C4D_GraphView
{
	C4D_GvGlobals*		globals;
	C4D_GvWorld*			world;
	C4D_GvNodeGUI*		gui;
	C4D_GvNode*				node;
	C4D_GvPort*				port;
	C4D_GvNodeMaster*	master;
	C4D_GvRun*				run;
	C4D_GvCalcTable*	table;
	C4D_GvQuery*			query;
	C4D_GvInit*				init;
	C4D_GvValue*			value;
	C4D_GvPortList*		portlist;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

/// @addtogroup group_graphviewinternal
/// @{
struct GvWrapper
{
	void *data;
};
/// @}

/// @}

#ifdef MAXON_TARGET_MACOS
	_Pragma("clang diagnostic pop")
#endif

#endif // C4D_GRAPHVIEW_DEF_H__
