#ifndef FOBJEXPORT2_H__
#define FOBJEXPORT2_H__

enum
{
	/// OBJ export preset name. 
	/// Used in the OBJEXPORTOPTIONS_PRESETS dropbox. (String)
	OBJEXPORTOPTIONS_NAME = 50,

	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP = 500,

	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_PRESETS = 1000, // Presets

	/// Preset drop down (Int)
	OBJEXPORTOPTIONS_PRESETS = 1010,

	/// Save and Delete Preset buttons
	OBJEXPORTOPTIONS_PRESETS_CUSTOM_SAVEBUTTON = 1020,
	OBJEXPORTOPTIONS_PRESETS_CUSTOM_DELETEBUTTON = 1030,

	/// Export animations as sequences
	OBJEXPORTOPTIONS_GROUP_ANIMATION     = 1400,

	OBJEXPORTOPTIONS_ANIMATION_TYPE           = 1500,
	OBJEXPORTOPTIONS_NO_ANIMATION             = 1501,
	OBJEXPORTOPTIONS_MANUAL_RANGE             = 1502,
	OBJEXPORTOPTIONS_LOOP_FRAMES              = 1503,
	OBJEXPORTOPTIONS_PREVIEW_FRAMES           = 1504,
	OBJEXPORTOPTIONS_ALL_ANIMATED_FRAMES      = 1505,

	// Manual range for export
	OBJEXPORTOPTIONS_FRAME_START = 1600,
	OBJEXPORTOPTIONS_FRAME_END   = 1601,

	OBJEXPORTOPTIONS_FRAME_STEP  = 1700,

	OBJEXPORTOPTIONS_SHARED_MTL_FILE = 1800,
	
	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_GEOMETRY		= 2000, // Geometry

	/// Scale widget
	/// We assign 1 OBJ unit as x unit of type y (x, y specified by user)
	OBJEXPORTOPTIONS_SCALE		 				= 2010,

	/// Value controlling how we export normal information (Int)
	OBJEXPORTOPTIONS_NORMALS					= 2020,
		/// No normal information is exported
		OBJEXPORTOPTIONS_NORMALS_NONE							= 0,
		/// Normal vertices are exported.
		OBJEXPORTOPTIONS_NORMALS_VERTEX						= 1,	// default

	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_MATERIAL		= 3000,
	OBJEXPORTOPTIONS_MATERIAL		 	= 3010,
		/// Exported scene won't have any material
		OBJEXPORTOPTIONS_MATERIAL_NONE					= 0,
		/// Export material's name and default material to a .MAT file
		OBJEXPORTOPTIONS_MATERIAL_NAMEANDDEFAULT		= 1,
		/// Export materials the best we can to a .mtl file
		OBJEXPORTOPTIONS_MATERIAL_CONSOLIDATE			= 2,
		/// Export materials the best we can to a .MAT file
		OBJEXPORTOPTIONS_MATERIAL_ORIGINAL_PATHS		= 3,
		

	/// Value controlling the default material to use (Int)
	OBJEXPORTOPTIONS_DEFAULTMATERIAL 	= 3020,
		/// material with white diffuse channel
		OBJEXPORTOPTIONS_DEFAULTMATERIAL_WHITE				= 0,
		/// each new default material use a different color
		OBJEXPORTOPTIONS_DEFAULTMATERIAL_RANDOMCOLORS		= 1,

	/// Switch controlling if transparency value should be inverted (bool)
	OBJEXPORTOPTIONS_INVERT_TRANSPARENCY = 3030,

	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_OPTIONAL		= 4000, // Optional

	/// Switch reversing the X axis (bool)
	/// All flip and swap are performed in order of occurrence.
	/// They are applied to the incoming OBJ data.
	/// These spatial transformation allow to reorient the scene for Cinema 4D
	/// This includes changing between left handed and right handed coordinate systems.
	OBJEXPORTOPTIONS_POINTTRANSFORM_FLIPX = 4010,
	/// Switch reversing the Y axis (bool)
	OBJEXPORTOPTIONS_POINTTRANSFORM_FLIPY = 4020,
	/// Switch reversing the Z axis (bool)
	OBJEXPORTOPTIONS_POINTTRANSFORM_FLIPZ = 4030,
	/// Switch exchanging the X with the Y axis (bool)
	OBJEXPORTOPTIONS_POINTTRANSFORM_SWAPXY = 4040,
	/// Switch exchanging the X with the Z axis (bool)
	OBJEXPORTOPTIONS_POINTTRANSFORM_SWAPXZ = 4050,
	/// Switch exchanging the Y with the Z axis (bool)
	OBJEXPORTOPTIONS_POINTTRANSFORM_SWAPYZ = 4060,

	/// Switch reversing the face definition (polygon winding) (bool)
	OBJEXPORTOPTIONS_FLIPFACES								= 4080,
	/// Triangulate NGONs
	OBJEXPORTOPTIONS_TRIANGULATE_NGONS = 4085,
	/// Vertex Color Exporting
	OBJEXPORTOPTIONS_VERTEX_COLOR = 13000,

  	/// UV coordinates
  	OBJEXPORTOPTIONS_EXPORT_UVS  = 4091,
	OBJEXPORTOPTIONS_UV_NONE     = 4092,
	OBJEXPORTOPTIONS_UV_ORIGINAL = 4093,
	OBJEXPORTOPTIONS_FLIP_U      = 4094,
	OBJEXPORTOPTIONS_FLIP_V      = 4095,
	OBJEXPORTOPTIONS_FLIP_UV     = 4096,

	/// Value describing how big is a dummy object. (float)
	/// As an OBJ dummy we use a cube to represent a location.
	OBJEXPORTOPTIONS_DUMMY_SIZE							= 4200,
	
	/// Switch to export cameras as dummies (bool)
	OBJEXPORTOPTIONS_DUMMY_CAMERA						= 4210,
	/// Switch to export light as dummies (bool)
	OBJEXPORTOPTIONS_DUMMY_LIGHT						= 4220,	
	
	/// Use g (group) to define exported object (bool)
	/// 3ds Max will refuse to load objects defined using o.
	OBJEXPORTOPTIONS_OBJECTS_AS_GROUPS = 6000,

  	/// UTF-8 file importing
  	OBJEXPORTOPTIONS_ENCODING_UTF8 = 8000
};

#endif // FOBJEXPORT2_H__
