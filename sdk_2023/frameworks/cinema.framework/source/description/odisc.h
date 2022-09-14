#ifndef ODISC_H__
#define ODISC_H__

enum
{
	PRIM_DISC_IRAD						= 1160, // REAL	   - Inner Radius [>=0.0]
	PRIM_DISC_ORAD						= 1161, // REAL	   - Outer Radius [>=Inner Radius]
	PRIM_DISC_CSUB						= 1162, // LONG	   - Disc-Cap Subdivision [>0]
	PRIM_DISC_SEG							= 1163 // LONG     - Rotational Segments [>2]
};

#endif // ODISC_H__
