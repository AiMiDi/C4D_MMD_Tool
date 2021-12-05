#ifndef DMODELING_H__
#define DMODELING_H__

enum
{
	QUANTIZE_SETTINGS							= 1000,						///< Groups
	GUIDES_SETTINGS								= 1001,
	SNAP_LIST											= 1002,
	SNAPMODE_COMBO								= 1003,						///< Snap Mode switch Auto/2d/3d
	SNAP_SETTINGS_MODE_AUTO								= 0,
	SNAP_SETTINGS_MODE_2D									= 1,
	SNAP_SETTINGS_MODE_3D									= 2,


	SNAP_SETTINGS									= 440000119,			///< Group - The ID for the settings in the document MODELING_SETTINGS container	(stored as BaseContainer)

	SNAP_SETTINGS_RADIUS					= 440000120,	 		///< Real - The radius for the snap
	SNAP_SETTINGS_ENABLED					= 440000121,			///< Bool - ID for the command to enable the snap
	SNAP_SETTINGS_TOOL						= 440000138,			///< Bool - Store these settings with this tool rather than globally for all tools in the document
	QUANTIZE_ENABLED							= 431000005,			///< Bool - ID for the command to enable quantizing
	QUANTIZE_MOVE									= 440000131,			///< Real - Quantize step for movement
	QUANTIZE_SCALE								= 440000132,			///< Real - Quantize step for scaling
	QUANTIZE_ROTATE								= 440000133,			///< Real - Quantize step for rotation
	QUANTIZE_TEXTURE							= 440000134,			///< Real - Quantize step for movement with textures (UV space)
	QUANTIZE_GRID									= 440000139,			///< Bool - Set quantize move step to use the grid size

	SNAP_SETTINGS_MODE						= 431000020,			///< LONG - hold one of snap mode can be SNAP_SETTINGS_MODE_AUTO/SNAP_SETTINGS_MODE_2D/SNAP_SETTINGS_MODE_3D

	SNAP_SETTINGS_AUTO						= 431000018,			///< Command ID - Auto 2d/3d Snap mode
	SNAP_SETTINGS_3D							= 431000016,			///< Command ID - 3d snap mode
	SNAP_SETTINGS_2D							= 431000019,			///< Command ID - 2d snam mode

	SNAP_SETTINGS_GUIDEANGLE			= 431000002,			///< Real - Angle step for guides

	/////////////////////////////////////////////////////////////////////
	/// Snap Modes

	SNAPMODE_GUIDE								= 440000113,			///< Snap to guide objects
	SNAPMODE_INTERSECTION					= 440000114,			///< Snap to the intersections of objects and guides
	SNAPMODE_POINT								= 440000115,			///< Snap to a vertex on a mesh
	SNAPMODE_SPLINE								= 440000116,			///< Snap to any point along a spline
	SNAPMODE_DYNAMICGUIDE					= 440000117,			///< Snap using dynamic or "inferred" guides
	SNAPMODE_SPLINEMID						= 440000122,			///< Snap to the middle of a spline segment
	SNAPMODE_EDGE									= 440000123,			///< Snap to any point along an edge
	SNAPMODE_EDGEMID							= 440000124,			///< Snap to middle of an edge
	SNAPMODE_POLYGON							= 440000125,			///< Snap to the surface of a polygon
	SNAPMODE_POLYGONCENTER				= 440000126,			///< Snap to the center of individual polygons
	SNAPMODE_WORKPLANE						= 440000127,			///< Snap to the surface of the workplane
	SNAPMODE_AXIS									= 440000128,			///< Snap to the axis of an object
	SNAPMODE_ORTHO								= 440000129,			///< Snap perpendicular to guides edges and splines
	SNAPMODE_GRIDPOINT						= 431000000,			///< Snap to the intersection points of the grid on the workplane
	SNAPMODE_GRIDLINE							= 431000001,			///< Snap to the grid lines on the workplane
	SNAPMODE_MIDPOINT							= 431000013,			///< Snap for mid points .. it allow subsnap for each parent mode that have it
	SNAPMODE_GUIDEMID							= 431000014,			///<a Snap The mid point in between of static guides interesections

	/////////////////////////////////////////////////////////////////////
	/// Mesh Check
	MESH_CHECK										= 1005,
	MESH_CHECK_ENABLED						= 1006,
	MESH_CHECK_MANIFOLD						= 1007,
	MESH_CHECK_BOUNDARY						= 1008,
	MESH_CHECK_BOUNDARY_COLOR			= 1009,
	MESH_CHECK_BOUNDARY_TEXT			= 1010,
	MESH_CHECK_POLY								= 1011,
	MESH_CHECK_POINT							= 1012,
	MESH_CHECK_MANIFOLD_COLOR			= 1013,
	MESH_CHECK_MANIFOLD_TEXT      = 1014,
	MESH_CHECK_POLY_COLOR					= 1015,
	MESH_CHECK_POLY_TEXT					= 1016,
	MESH_CHECK_POINT_COLOR				= 1017,
	MESH_CHECK_POINT_TEXT					= 1018,
	MESH_CHECK_POLEPOINT					= 1019,
	MESH_CHECK_POLEPOINT_COLOR		= 1020,
	MESH_CHECK_POLEPOINT_TEXT			= 1021,
	MESH_CHECK_NORMAL							= 1022,
	MESH_CHECK_NORMAL_COLOR				= 1023,
	MESH_CHECK_NORMAL_TEXT				= 1024,
	MESH_CHECK_POINT_SELECT				= 1025,
	MESH_CHECK_POLEPOINT_SELECT		= 1026,
	MESH_CHECK_MANIFOLD_SELECT		= 1027,
	MESH_CHECK_BOUNDARY_SELECT		= 1028,
	MESH_CHECK_POLY_SELECT				= 1029,
	MESH_CHECK_NORMAL_SELECT			= 1030,
	MESH_CHECK_NORMAL_THRESHOLD		= 1031,
	MESH_CHECK_POLE_MIN						= 1032,

	MESH_CHECK_EDGEPOINT					= 1033,
	MESH_CHECK_EDGEPOINT_COLOR		= 1034,
	MESH_CHECK_EDGEPOINT_THRESHOLD= 1035,
	MESH_CHECK_EDGEPOINT_SELECT		= 1036,
	MESH_CHECK_EDGEPOINT_TEXT			= 1037,

	/////////////////////////////////////////////////////////////////////
	/// modeling utility
	MODELING_OPTION								= 2000,
	MODELING_OPTION_SOLO					= 2001,
	VIEWPORT_SOLO_MODE						= 2002,
	VIEWPORT_SOLO_MODE_OFF				= 0,
	VIEWPORT_SOLO_MODE_SINGLE			= 1,
	VIEWPORT_SOLO_MODE_HIERARCHY	= 2,
	VIEWPORT_SOLO_SELECTION				= 2003
};

#endif // DMODELING_H__
