#ifndef XSLARIPPLE_H__
#define XSLARIPPLE_H__

enum
{
	XSLARipple                              = 1000,

	SLA_WAVE_PARAMS_LENGTH                  = 3000, // real
	SLA_WAVE_PARAMS_MIN_STRENGTH            = 3001, // real
	SLA_WAVE_PARAMS_SPEED                   = 3002, // real
	SLA_WAVE_PARAMS_SPEED_PARTICLE_DEPENDENT = 3003, // bool
	SLA_WAVE_PARTICLE                       = 3004, // link
	SLA_WAVE_FALLOFF                        = 3005, // real
	SLA_WAVE_AMPLITUDE                      = 3006, // real
	SLA_WAVE_PERIODS                        = 3007, // long
	SLA_WAVE_PARAMS_OBJECT                  = 4000, // link

	SLA_WAVE_DUMMY_
};

#endif // XSLARIPPLE_H__
