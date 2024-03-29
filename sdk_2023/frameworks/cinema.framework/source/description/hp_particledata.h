#ifndef HP_PARTICLEDATA_H__
#define HP_PARTICLEDATA_H__

#include "gvbase.h"

enum
{
//Ports
	IN_HPPART_PARTICLE = 2000,

	OUT_PART_POSITION = 3000,
	OUT_PART_VELOCITY,
	OUT_PART_AGE,
	OUT_PART_LIFE,
	OUT_PART_SIZE,
	OUT_PART_SCALE,
	OUT_PART_MASS,
	OUT_PART_ALIGNMENT,
	OUT_PART_SPIN,
	OUT_PART_RANDOMSEED,
	OUT_PART_SHAPE,
	OUT_PART_GROUP,
	OUT_PART_DTFAC,
	OUT_PART_COLOR,

	OUT_PART_DATACHANNEL = 10000
};



#endif // HP_PARTICLEDATA_H__
