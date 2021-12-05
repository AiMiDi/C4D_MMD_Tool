#include "c4d_library.h"
#include "lib_noise.h"
#include "c4d_basecontainer.h"

NoiseLib* lib_noise = nullptr;

static NoiseLib *CheckLibNoise(Int32 offset)
{
	return (NoiseLib*)CheckLib(NOISE_LIB, offset, (C4DLibrary**)&lib_noise);
}

#define NoiseLibCall(b) 		NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, b)); \
															if (!lib || !lib->b) return; \
															(((iNoise*)this)->*lib->b)

#define NoiseLibCallR(a, b)  NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iNoise*)this)->*lib->b)

C4DNoise* C4DNoise::Alloc(Int32 seed)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_Alloc)); if (!lib) return nullptr;
	return (C4DNoise*)lib->NoiseLib_Alloc(seed);
}

C4DNoise* C4DNoise::Alloc2(Int32 seed)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_Alloc2)); if (!lib) return nullptr;
	return (C4DNoise*)lib->NoiseLib_Alloc2(seed);
}

void C4DNoise::Free(C4DNoise *&p)
{
	if (!p) return;
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_Free)); if (!lib) return;
	iNoise* i = (iNoise*)p;
	lib->NoiseLib_Free(i);
	p = nullptr;
}

BaseContainer C4DNoise::CreateMenuContainer(Bool bIncludeNone)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_CreateMenuContainer));
	if (!lib) return BaseContainer();
	return lib->NoiseLib_CreateMenuContainer(bIncludeNone);
}

Bool C4DNoise::HasOctaves(NoiseType t)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_HasOctaves));
	if (!lib) return false;
	return lib->NoiseLib_HasOctaves(t);
}

Bool C4DNoise::HasAbsolute(NoiseType t)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_HasAbsolute));
	if (!lib) return false;
	return lib->NoiseLib_HasAbsolute(t);
}

Bool C4DNoise::HasCycles(NoiseType t)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_HasCycles));
	if (!lib) return false;
	return lib->NoiseLib_HasCycles(t);
}

void C4DNoise::EvaluateSampleOffset(NoiseType type, Float rOctaves, Float rDelta, Float &rSampleOffset)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_EvaluateSampleOffset));
	if (!lib) { rSampleOffset = 0.01_f; return; }
	lib->NoiseLib_EvaluateSampleOffset(type, rOctaves, rDelta, rSampleOffset);
}

void C4DNoise::GetNoisePreview(NoiseType t, IconData &dat, String *str)
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_GetNoisePreview));
	if (!lib) { dat.bmp = nullptr; return; }
	lib->NoiseLib_GetNoisePreview(t, dat, str);
}


Float C4DNoise::Noise(NoiseType t, Bool two_d, const Vector &p, Float time, Float octaves, Bool absolute, Float sampleRad, Float detailAtt, Int32 t_repeat)
{
	NoiseLibCallR(0, NoiseLib_Noise)(t, two_d, p, time, octaves, absolute, sampleRad, detailAtt, t_repeat);
}

Bool C4DNoise::InitFbm(Int32 lMaxOctaves, Float rLacunarity, Float h)
{
	NoiseLibCallR(false, NoiseLib_InitFbm)(lMaxOctaves, rLacunarity, h);
}

const Float* C4DNoise::GetFBMTable()
{
	NoiseLibCallR(nullptr, NoiseLib_GetFBMTable)();
}

const Float* C4DNoise::GetValueTable()
{
	NoiseLibCallR(nullptr, NoiseLib_GetValueTable)();
}

const Float* C4DNoise::GetImpulseTable()
{
	NoiseLibCallR(nullptr, NoiseLib_GetImpulseTable)();
}

const UChar* C4DNoise::GetPermutationTable()
{
	NoiseLib *lib = CheckLibNoise(LIBOFFSET(NoiseLib, NoiseLib_GetPermutationTable));
	if (!lib) return nullptr;
	return lib->NoiseLib_GetPermutationTable();
}

const NoiseGradient* C4DNoise::GetNoiseGradient()
{
	NoiseLibCallR(nullptr, NoiseLib_GetNoiseGradient)();
}

const Int32* C4DNoise::GetPermutationTableA()
{
	NoiseLibCallR(nullptr, NoiseLib_GetPermutationTableA)();
}

Float C4DNoise::SNoise(Vector p)
{
	NoiseLibCallR(0.0, SNoise)(p);
}

Float C4DNoise::SNoise(Vector p, Float t, Int32 lRepeat)
{
	NoiseLibCallR(0.0, SNoiseR)(p, t, lRepeat);
}

Float C4DNoise::Turbulence(Vector p, Float t, Float rOctaves, Bool bAbsolute, Int32 lRepeat)
{
	NoiseLibCallR(0.0, Turbulence)(p, t, rOctaves, bAbsolute, lRepeat);
}

Float C4DNoise::Fbm(Vector p, Float t, Float rOctaves, Int32 lRepeat)
{
	NoiseLibCallR(0.0, Fbm)(p, t, rOctaves, lRepeat);
}

Float C4DNoise::RidgedMultifractal(Vector p, Float t, Float rOctaves, Float rOffset, Float rGain, Int32 lRepeat)
{
	NoiseLibCallR(0.0, RidgedMultifractal)(p, t, rOctaves, rOffset, rGain, lRepeat);
}
