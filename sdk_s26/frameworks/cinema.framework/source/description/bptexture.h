#ifndef BPTEXTURE_H__
#define BPTEXTURE_H__

#include "bpbitmap.h"

enum
{
	// object properties
	ID_PAINTTEXTURE_FILENAME			= 2000,
	ID_PAINTTEXTURE_MODE					= 2001,
	ID_PAINTTEXTURE_SAVEFORMAT		= 2003,
	ID_PAINTTEXTURE_PATHS					= 2004,
	ID_PAINTTEXTURE_ICCPROFILE		= 2005,
	ID_PAINTTEXTURE_DPI						= 2006,
	ID_PAINTTEXTURE_ASPECTRATIO		= 2007,

	// private data
	ID_PAINTTEXTURE_VIEWWINDOW		= 99999,

	ID_PAINTTEXTURE_END
};

#endif // BPTEXTURE_H__