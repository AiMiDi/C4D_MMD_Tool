#ifndef FSKPIMPORT_H__
#define FSKPIMPORT_H__

enum
{
	/// Static group used by res file
	SKPIMPORT_GROUP = 999,
	/// Static group used by res file
	SKPIMPORT_GRP_GENERAL = 1000,
	/// Create a daylight system and physical sky using the SketchUp model's latitude and longitude data (bool)
	SKPIMPORT_DAYLIGHT_SYSTEM_PHYSICAL_SKY,
	/// Create a camera using the SketchUp model's camera data (bool)
	SKPIMPORT_CAMERA,
	/// Skip importing hidden objects, or otherwise import them with the editor hidden and render hidden switches set on (bool)
	SKPIMPORT_SKIP_HIDDEN_OBJECTS,
	/// Create layers and split the imported objects accordingly using the SketchUp model's layer data (bool)
	SKPIMPORT_SPLIT_OBJECTS_BY_LAYER,
	/// Static group used by res file
	SKPIMPORT_GRP_ADDITIONAL,
	/// Show the SketchUp model's statistics in the script console (bool)
	SKPIMPORT_SHOW_STATISTICS_IN_CONSOLE
};

#endif // FSKPIMPORT_H__
