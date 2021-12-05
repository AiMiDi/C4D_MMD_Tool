#ifndef FOBJIMPORT2_H__
#define FOBJIMPORT2_H__

enum
{
	/// OBJ import preset name. 
	/// Used in the OBJIMPORTOPTIONS_PRESETS dropbox. (String)
	OBJIMPORTOPTIONS_NAME = 50,
	
	/// Static group used by res file
	OBJIMPORTOPTIONS_GROUP = 500,

	/// Static group used by res file
	OBJIMPORTOPTIONS_GROUP_PRESETS = 1000,	// Presets

	/// Preset drop down (Int)
	OBJIMPORTOPTIONS_PRESETS = 1010,

	/// Save and Delete Preset buttons
	OBJIMPORTOPTIONS_PRESETS_CUSTOM_SAVEBUTTON = 1020,
	OBJIMPORTOPTIONS_PRESETS_CUSTOM_DELETEBUTTON = 1030,
	
	/// Static group used by res file
	OBJIMPORTOPTIONS_GROUP_GENERAL	= 2000,	// General

	/// Scale widget
	/// We assign 1 OBJ unit as x unit of type y (x, y specified by user)
	OBJIMPORTOPTIONS_SCALE												= 2010,

	/// Value controlling how we separate the OBJ content into objects (Int)
	OBJIMPORTOPTIONS_SPLITBY											= 2020,
		/// All content is imported as part of one object
		OBJIMPORTOPTIONS_SPLITBY_ONEOBJECT						= 0,
		/// All content is separated by object (o primitive)
		OBJIMPORTOPTIONS_SPLITBY_OBJECT								= 1,
		/// All content is separated by group (g primitive), while renaming groups with naming collisions to keep the data separate
		OBJIMPORTOPTIONS_SPLITBY_GROUP								= 2,
		/// All content is separated by material assignment (usemtl statement)
		OBJIMPORTOPTIONS_SPLITBY_MATERIAL							= 3,
		/// All content is separated by group (g primitive) while combining data found with naming collisions
		OBJIMPORTOPTIONS_SPLITBY_GROUP_COMBINE_NAME_COLLISIONS		= 4,

	/// Value controlling how we import normal information (Int)
	OBJIMPORTOPTIONS_NORMALS											= 2030,
		/// No normal information is imported (or set)
		OBJIMPORTOPTIONS_NORMALS_NOIMPORT							= 0,
		/// A phong tag is applied.  No normal information is read
		OBJIMPORTOPTIONS_NORMALS_PHONGTAG							= 1,
		/// Normal vertices are imported if any.  A phong tag is applied in case there is no normals.
		OBJIMPORTOPTIONS_NORMALS_VERTEX								= 2,

	/// Phong tag default angle value (float)
	OBJIMPORTOPTIONS_PHONG_ANGLE_DEFAULT					= 2040,

	/// Switch controlling if we import UV Coordinates (bool)
	OBJIMPORTOPTIONS_TEXTURECOORDINATES						= 2050,

	/// Static group used by res file
	OBJIMPORTOPTIONS_GROUP_OPTIONAL								= 3000,	// Options

	/// Switch reversing the X axis (bool)
	/// All flip and swap are performed in order of occurrence.
	/// They are applied to the incoming OBJ data.
	/// These spatial transformation allow to reorient the scene for Cinema 4D
	/// This includes changing between left handed and right handed coordinate systems.
	OBJIMPORTOPTIONS_POINTTRANSFORM_FLIPX = 3010,
	/// Switch reversing the Y axis (bool)
	OBJIMPORTOPTIONS_POINTTRANSFORM_FLIPY = 3020,
	/// Switch reversing the Z axis (bool)
	OBJIMPORTOPTIONS_POINTTRANSFORM_FLIPZ = 3030,
	/// Switch exchanging the X with the Y axis (bool)
	OBJIMPORTOPTIONS_POINTTRANSFORM_SWAPXY = 3040,
	/// Switch exchanging the X with the Z axis (bool)
	OBJIMPORTOPTIONS_POINTTRANSFORM_SWAPXZ = 3050,
	/// Switch exchanging the Y with the Z axis (bool)
	OBJIMPORTOPTIONS_POINTTRANSFORM_SWAPYZ = 3060,

	/// Switch reversing the face definition (polygon winding) (bool)
	OBJIMPORTOPTIONS_FLIPFACES										= 3070,

	/// Switch reversing the U and V dimension for texture coordinates (bool)
	OBJIMPORTOPTIONS_FLIPUVW											= 3080,

	/// Value controlling how the lines are imported (Int)
	OBJIMPORTOPTIONS_LINES												= 3090,
		/// Lines are imported as is. Possibly as segment, unless they list their beginning for end.
		OBJIMPORTOPTIONS_LINES_DEFAULT								= 0,
		/// Lines are ensured to be closed.  Some exporter have this assumption.
		OBJIMPORTOPTIONS_LINES_CLOSED									= 1,
		/// Lines are closed and are imported as polygon in the object (opaque)
		OBJIMPORTOPTIONS_LINES_ASPOLYS								= 2,

	/// Switch controlling the printing of the import report to the script console
	OBJIMPORTOPTIONS_REPORT_SCRIPTCONSOLE					= 3100,
	
	/// Optimize vertices and potentially polygons
	// Taken out of R17 SP1 HF because UI change was rejected and other changes were accepted
	// OBJIMPORTOPTIONS_OPTIMIZE_VERTICES						= 3200,
	
	/// Static group used by res file
	OBJIMPORTOPTIONS_GROUP_MATERIAL								= 4000,	// Options

	/// Value controlling how we import normal information (Int)
	OBJIMPORTOPTIONS_MATERIAL	= 4010,
		/// Imported scene won't have any material
		OBJIMPORTOPTIONS_MATERIAL_NONE								= 0,
		/// Assign one default material per object
		OBJIMPORTOPTIONS_MATERIAL_DEFAULTPEROBJECT		= 1,
		/// Import .MAT file and use them in the imported scene
		OBJIMPORTOPTIONS_MATERIAL_MTLFILE							= 2,
		/// Import material name but use a default material instead
		OBJIMPORTOPTIONS_MATERIAL_DEFAULTPERMTLFILE		= 3,

	/// Value controlling the default material to use (Int)
	OBJIMPORTOPTIONS_DEFAULTMATERIAL							= 4020,
		/// material with white diffuse channel
		OBJIMPORTOPTIONS_DEFAULTMATERIAL_WHITE				= 0,
		/// each new default material use a different color
		OBJIMPORTOPTIONS_DEFAULTMATERIAL_RANDOMCOLORS	= 1,

	/// Value controlling the material mix mode to use (Int)
	OBJIMPORTOPTIONS_MATERIAL_MIXMODE							= 4025,
		/// The blended mix mode
		OBJIMPORTOPTIONS_MATERIAL_MIXMODE_BLEND = 0,
		/// The add mix mode
		OBJIMPORTOPTIONS_MATERIAL_MIXMODE_ADD = 1,
		/// The subtract mix mode
		OBJIMPORTOPTIONS_MATERIAL_MIXMODE_SUB = 2,
		/// The multiply mix mode
		OBJIMPORTOPTIONS_MATERIAL_MIXMODE_MUL = 3,

	/// Switch controlling if transparency value should be inverted (bool)
	OBJIMPORTOPTIONS_INVERT_TRANSPARENCY = 4030,

	/// Extended configuration information. Not used in the UI.
	OBJIMPORTOPTIONS_FILENAME = 10000,

	/// Extended configuration information. Not used in the UI.
	OBJIMPORTOPTIONS_PER_FACE_MATERIAL = 10010
};

#endif // FOBJIMPORT2_H__
