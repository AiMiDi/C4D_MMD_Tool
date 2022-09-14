#ifndef OCUBE_H__
#define OCUBE_H__

enum
{
	PRIM_CUBE_LEN											= 1100, // VECTOR   - Side Length [>=0.0]
	PRIM_CUBE_SEP 										= 1101, // BOOL	   - Seperate Surfaces [only evaluated if no fillet is specified]
	PRIM_CUBE_SUBX										= 1102, // LONG     - X-Subdivision [>0]
	PRIM_CUBE_SUBY										= 1103, // LONG     - Y-Subdivision [>0]
	PRIM_CUBE_SUBZ										= 1104, // LONG     - Z-Subdivision [>0]
	PRIM_CUBE_FRAD										= 1105, // REAL     - Fillet Radius [>=0.0; <=len.x/2; <=len.y/2; <=len.z/2]
	PRIM_CUBE_SUBF										= 1106,	// LONG     - Fillet Subdivision [>0]
	PRIM_CUBE_DOFILLET								= 1107	// BOOL     - Enable Fillet
};

#endif // OCUBE_H__
