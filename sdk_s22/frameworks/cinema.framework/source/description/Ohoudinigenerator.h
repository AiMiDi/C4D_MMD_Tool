#ifndef OHOUDINIGENERATOR_H__
#define OHOUDINIGENERATOR_H__

enum
{
	HOUDINI_PATH = 3000,											// otl asset library file path
	HOUDINI_ASSET_IDENTIFIER,									// name of asset from library
	HOUDINI_OBJECT_IDENTIFIER,								// name of output object from asset
	HOUDINI_ASSET_INSTANCE_ID,								// asset original instance id

	HOUDINI_ASSET_CONTROLS,
	HOUDINI_PRIORITY,													// execution priority type
	HOUDINI_PRIORITY_AUTOMATIC,								// automatic priority
	HOUDINI_PRIORITY_MANUAL,									// manual priority
	HOUDINI_PRIORITY_SETTINGS,								// execution priority settings
	HOUDINI_SELECT_GENERATORS,								// button to select the output generators from an asset generator
	HOUDINI_UPDATE_GENERATORS,								// button to update the output generators from an asset generator
	HOUDINI_UPDATE_MATERIALS_ALL,							// button to update materials for all generators
	HOUDINI_RESET_SIMULATION,									// button to reset the asset simulation

	HOUDINI_OUTPUT_CONTROLS,
	HOUDINI_SELECT_ASSET,											// button to select the asset generator from object generators
	HOUDINI_UPDATE_ASSET,											// button to update the asset generator from object generators
	HOUDINI_UPDATE_MATERIALS_GEN,						  // button to update materials for an output generator
	
	HOUDINI_TYPE,															// generator type: asset, output object

	HOUDINI_UNIT_SCALE,												// scaling control

	HOUDINI_PARAMETER_COUNT,									// number of asset parameters
	HOUDINI_PARAMETER_DEFAULTS,								// initial parameter values (for "Reset to Default")

	HOUDINI_OBJECT_INDEX,											// asset object index
	HOUDINI_GEO_INDEX,												// asset object > geo index
	HOUDINI_PART_INDEX,												// asset object > geo > part index

	HOUDINI_ASSET_GENERATOR_LINK,							// asset generator link

	HOUDINI_ASSET_GENERATOR_INPUTS,						// asset generator inputs container

	HOUDINI_ASSET_INFORMATION,								// asset generator informations
	HOUDINI_OBJECT_INFORMATION,								// object generator informations
	HOUDINI_INFOS,														// generator informations

	HOUDINI_GROUP_MATERIAL_LINKS,							// output generator material links container

	HOUDINI_COOK_ASSET,												// button to cook the asset

	HOUDINI_STREAMING_OPTIONS = 3100,					// streaming options
	HOUDINI_STREAMING_UPDATE_PSR,							// streaming > Update PSR
	HOUDINI_STREAMING_UPDATE_GEOMETRY,				// streaming > Update Geometry
	HOUDINI_STREAMING_NORMALS,								// streaming > Normals
	HOUDINI_STREAMING_UVS,										// streaming > UVs
	HOUDINI_STREAMING_TEXTURES,								// streaming > Textures
	HOUDINI_STREAMING_TEXTURES_UPDATE_ON_PARAMETER_CHANGE,	// streaming > Update Image File On Parameter Change
	HOUDINI_STREAMING_VERTEX_COLORS,					// streaming > Vertex Colors
	HOUDINI_STREAMING_VERTEX_MAPS,						// streaming > Vertex Maps

	HOUDINI_LICENSE_TYPE,

	HOUDINI_PARAMETERS_GROUP = 9999,					// Houdini parameters group

	HOUDINI_DYNAMIC_INPUTS_START = 10000,			// start id of dynamic input parameters
	HOUDINI_DYNAMIC_INPUTS_END   = 19999,			// end id of dynamic input parameters
	HOUDINI_DYNAMIC_PARAMS_START = 20000,			// start id of dynamic asset parameters
	HOUDINI_DYNAMIC_PARAMS_END   = 29999,		  // end id of dynamic asset parameters

	HOUDINI_DYNAMIC_PARAMS_EXTRA_OFFSET = 20000, // offset id of dynamic asset parameters (extra options stored in [40000, 49999] for forward compatibility purpose)
	HOUDINI_DYNAMIC_PARAMS_EXTRA_POINT_POLY_GROUPS = 1, // type of extra parameter to control point and polygon groups
	
	HOUDINI_INPUTS_INPUT = 30000,
	HOUDINI_INPUTS_GROUP = 30001,
	HOUDINI_INPUTS_INCLUDE_CHILDREN		= 30100,
	HOUDINI_INPUTS_INCLUDE_SUBGROUPS	= 30101,
};

#endif // OHOUDINIGENERATOR_H__



