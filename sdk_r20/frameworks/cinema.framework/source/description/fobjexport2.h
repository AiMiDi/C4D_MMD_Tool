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
	
	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_GENERAL		= 2000, // General

	/// Scale widget
	/// We assign 1 OBJ unit as x unit of type y (x, y specified by user)
	OBJEXPORTOPTIONS_SCALE		 				= 2010,

	/// Value controlling how we export normal information (Int)
	OBJEXPORTOPTIONS_NORMALS					= 2020,
		/// No normal information is exported
		OBJEXPORTOPTIONS_NORMALS_NONE							= 0,
		/// Normal vertices are exported.
		OBJEXPORTOPTIONS_NORMALS_VERTEX						= 1,	// default
	OBJEXPORTOPTIONS_TEXTURECOORDINATES = 2030,

	/// Static group used by res file
	OBJEXPORTOPTIONS_GROUP_MATERIAL		= 3000, // General
	OBJEXPORTOPTIONS_MATERIAL		 	= 3010,
		/// Exported scene won't have any material
		OBJEXPORTOPTIONS_MATERIAL_NONE					= 0,
		/// Export material's name and default material to a .MAT file
		OBJEXPORTOPTIONS_MATERIAL_NAMEANDDEFAULT		= 1,
		/// Export materials the best we can to a .MAT file
		OBJEXPORTOPTIONS_MATERIAL_MATERIAL				= 2,

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

	/// Value controlling how topologies are exported (Int)
	OBJEXPORTOPTIONS_TOPOLOGY = 4070,
		/// Export points, without face/poly definition
		OBJEXPORTOPTIONS_TOPOLOGY_POINTS = 0,
		/// Export faces (polygon)
		OBJEXPORTOPTIONS_TOPOLOGY_FACES = 1,

		/// Switch reversing the face definition (polygon winding) (bool)
	OBJEXPORTOPTIONS_FLIPFACES								= 4080,

	/// Switch reversing the U and V dimension for texture coordinates (bool)
	OBJEXPORTOPTIONS_FLIPUVW								= 4090,

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

	/// obsolete
	OBJEXPORTOPTIONS_EXPORT_DUPLICATE_VERTICES = 7000
};

#endif // FOBJEXPORT2_H__
