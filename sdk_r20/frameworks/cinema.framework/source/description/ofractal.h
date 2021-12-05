#ifndef OFRACTAL_H__
#define OFRACTAL_H__

enum
{
	// object properties
	PRIM_FRACTAL_LEN					= 1240, // VECTOR   - Fractal Size [>=0.0]
	PRIM_FRACTAL_SUBW					= 1241, // LONG     - Width Segments [>0]
	PRIM_FRACTAL_SUBH					= 1242, // LONG     - Height Segments [>0]
	PRIM_FRACTAL_ROUGH				= 1243, // REAL     - Rough Furrows [>=0.0; <=1.0]
	PRIM_FRACTAL_FINE					= 1244, // REAL     - Fine Furrows [>=0.0; <=1.0]
	PRIM_FRACTAL_SCALE				= 1245, // REAL     - Scale [>=0.1; <=1.0]
	PRIM_FRACTAL_BLEVEL				= 1246, // REAL     - Pbottom Level (Sea) [>=0.0; <=1.0]
	PRIM_FRACTAL_TLEVEL				= 1247, // REAL     - Ptop Level (Plateau) [>=0.0; <=1.0]
	PRIM_FRACTAL_MULTIFRACTAL	= 1248, // BOOL     - Multifractal Function
	PRIM_FRACTAL_BORDERS			= 1249, // BOOL     - Borders At Sealevel
	PRIM_FRACTAL_SPHERICAL		= 1250, // BOOL     - Generate Spherical Shape
	PRIM_FRACTAL_SEED					= 1251  // LONG			- Random Seed
};

#endif // OFRACTAL_H__
