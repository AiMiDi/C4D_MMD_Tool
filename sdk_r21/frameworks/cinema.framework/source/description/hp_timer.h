#ifndef HP_TIMER_H__
#define HP_TIMER_H__

#include "gvbase.h"

enum
{
	TIM_VERSION	= 1000,
	TIM_TIME,
	TIM_EXTEND,
	TIM_SINGLE,


//Ports
	IN_TIM_START = 2000,
	IN_TIM_ATIME,
	IN_TIM_PARTICLE,
	OUT_TIM_ON = 3000,
	OUT_TIM_TIME,
	OUT_TIM_PERCENT,
	OUT_TIM_PARTICLE
};



#endif // HP_TIMER_H__
