#ifndef TPYRO_H__
#define TPYRO_H__

enum
{
	PYRO_TAG_DENSITY_ADD = 1000,
	PYRO_TAG_DENSITY_COLOR_ENABLED = 1001,
	PYRO_TAG_DENSITY_COLOR = 1002,
	PYRO_TAG_TEMPERATURE_ENABLED = 1003,
	PYRO_TAG_TEMPERATURE_MIN = 1004,
	PYRO_TAG_TEMPERATURE_MAX = 1005,
	PYRO_TAG_TEMPERATURE_ADD = 1006,
	PYRO_TAG_FUEL_ENABLED = 1007,
	PYRO_TAG_FUEL_MIN = 1008,
	PYRO_TAG_FUEL_MAX = 1009,
	PYRO_TAG_FUEL_ADD = 1010,
	PYRO_TAG_VELOCITY_ENABLED = 1011,
	PYRO_TAG_VELOCITY_STRENGTH = 1012,
	PYRO_TAG_VELOCITY_TYPE = 1013,
		PYRO_TAG_VELOCITY_TYPE_ADD = 0,
		PYRO_TAG_VELOCITY_TYPE_ABSOLUTE = 1,
		PYRO_TAG_VELOCITY_TYPE_DIRECTION = 2,
		PYRO_TAG_VELOCITY_TYPE_MOVEMENT = 3,
	PYRO_TAG_VELOCITY_DIRECTION = 1014,
	PYRO_TAG_OBJECT_VOXEL_SIZE = 1015,
	PYRO_TAG_SURFACE_EMISSION_ENABLED = 1016,
	PYRO_TAG_SURFACE_THICKNESS = 1017,
	PYRO_TAG_NOISE = 1018,
	PYRO_TAG_NOISE_STRENGTH = 1019,
	PYRO_TAG_NOISE_SCALE = 1020,
	PYRO_TAG_NOISE_FREQUENCY = 1021,
	//////////////////////////////////////////////////////////////////////////
	PYRO_TAG_DUMMY
};

#endif // TPBDCONSTRAINT_H__