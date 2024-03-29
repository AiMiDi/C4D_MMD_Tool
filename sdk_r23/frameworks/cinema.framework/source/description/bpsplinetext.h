#ifndef BPSPLINETEXT_H__
#define BPSPLINETEXT_H__

#include "bpspline.h"

enum
{
	// object properties
	ID_PAINTSPLINETEXT_						= 2000,

	ID_PAINTSPLINETEXT_TEXT  			= 2001,
	ID_PAINTSPLINETEXT_SIZE  			= 2002,
	ID_PAINTSPLINETEXT_ALIGN 			= 2003,
		PAINTSPLINETEXT_ALIGN_LEFT		= 0,
		PAINTSPLINETEXT_ALIGN_CENTER	= 1,
		PAINTSPLINETEXT_ALIGN_RIGHT		= 2,
	ID_PAINTSPLINETEXT_FONT				= 2004,
	ID_PAINTSPLINETEXT_SPACE_H		= 2005,
	ID_PAINTSPLINETEXT_SPACE_V		= 2006,
	ID_PAINTSPLINETEXT_SEPARATE  	= 2007,

	ID_PAINTSPLINETEXT_END
};

#endif // BPSPLINETEXT_H__
