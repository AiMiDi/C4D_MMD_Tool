/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_NOISE_H__
#define LIB_NOISE_H__

#include "c4d_library.h"

#ifdef __API_INTERN__
#include "intbaselist.h"
#endif

/// @addtogroup group_noiselibrary Noise
/// @ingroup group_library
/// @{

/// For the noise GUI.
#define NOISE_OFFSET					2000

/// Noise library ID.\n
/// SLA must be installed to use this class.
#define NOISE_LIB 1011190

/// @addtogroup NoiseType
/// @ingroup group_enumeration
/// @{
enum NoiseType
{
	NOISE_UNKNOWN								=  0,			///< Unknown.

	NOISE_BOX_NOISE							=  1,			///< Box noise.
	NOISE_BLIST_TURB						=  2,			///< Blistered turbulence.
	NOISE_BUYA									=  3,			///< Buya.
	NOISE_CELL_NOISE						=  4,			///< Cell noise.
	NOISE_CRANAL								=  5,			///< Cranal.
	NOISE_DENTS									=  6,			///< Dents.
	NOISE_DISPL_TURB						=  7,			///< Displaced turbulence.
	NOISE_FBM										=  8,			///< FBM.
	NOISE_HAMA									=  9,			///< Hama.
	NOISE_LUKA									= 10,			///< Luka.
	NOISE_MOD_NOISE							= 11,			///< Mod noise.
	NOISE_NAKI									= 12,			///< Naki.
	NOISE_NOISE									= 13,			///< Noise.
	NOISE_NUTOUS								= 14,			///< Nutous.
	NOISE_OBER									= 15,			///< Ober.
	NOISE_PEZO									= 16,			///< Pezo.
	NOISE_POXO									= 17,			///< Poxo.
	NOISE_RANDOM								= 18,			///< %Random.
	NOISE_SEMA									= 19,			///< Sema.
	NOISE_STUPL									= 20,			///< Stupl.
	NOISE_TURBULENCE						= 21,			///< Turbulence.
	NOISE_VL_NOISE							= 22,			///< VL noise.
	NOISE_WAVY_TURB							= 23,			///< Wavy turbulence.
	NOISE_CELL_VORONOI					= 24,			///< Cell voronoi.
	NOISE_DISPL_VORONOI					= 25,			///< Displaced voronoi.
	NOISE_SPARSE_CONV						= 26,			///< Sparse convolution.
	NOISE_VORONOI_1							= 27,			///< Voronoi 1.
	NOISE_VORONOI_2							= 28,			///< Voronoi 2.
	NOISE_VORONOI_3							= 29,			///< Voronoi 3.
	NOISE_ZADA									= 30,			///< Zada.
	NOISE_FIRE									= 31,			///< Fire.
	NOISE_ELECTRIC							= 32,			///< Electric.
	NOISE_GASEOUS								= 33,			///< Gaseous.

	NOISE_NONE									= 99			///< None.
};
/// @}

class BaseContainer;
struct NoiseGradient;

//----------------------------------------------------------------------------------------
/// The noise class used for the @C4D shaders.
//----------------------------------------------------------------------------------------
class C4DNoise
{
private:
	C4DNoise();
	~C4DNoise();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{noise instance}
	/// @param[in] seed								The noise seed.
	/// @return												@allocReturn{noise instance}
	//----------------------------------------------------------------------------------------
	static C4DNoise* Alloc(Int32 seed);

	//----------------------------------------------------------------------------------------
	/// @allocatesA{noise instance}
	/// @note This uses a different seed than Alloc() for the internal noises so that they look exactly like the old noises.
	/// @param[in] seed								The noise seed.
	/// @return												@allocReturn{noise instance}
	//----------------------------------------------------------------------------------------
	static C4DNoise* Alloc2(Int32 seed);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{noise instances}
	/// @param[in,out] p							@theToDestruct{noise instance}
	//----------------------------------------------------------------------------------------
	static void Free(C4DNoise *&p);

	/// @}

	/// @name Menu Container
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a menu container with the different noise options available.
	/// @param[in] bIncludeNone				Pass @formatConstant{true} to include the None option.
	/// @return												The generated noise menu. The NoiseType IDs are used.
	//----------------------------------------------------------------------------------------
	static BaseContainer CreateMenuContainer(Bool bIncludeNone = false);

	/// @}

	/// @name Has Octaves/Absolute/Cycles
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if a certain noise type supports the octaves parameter.
	/// @param[in] t									The noise type: @enumerateEnum{NoiseType}
	/// @return												@trueIfOtherwiseFalse{octaves is supported}
	//----------------------------------------------------------------------------------------
	static Bool HasOctaves(NoiseType t);

	//----------------------------------------------------------------------------------------
	/// Checks if a certain noise type supports the absolute parameter.
	/// @param[in] t									The noise type: @enumerateEnum{NoiseType}
	/// @return												@trueIfOtherwiseFalse{absolute is supported}
	//----------------------------------------------------------------------------------------
	static Bool HasAbsolute(NoiseType t);

	//----------------------------------------------------------------------------------------
	/// Checks if a certain noise type supports the cycles parameter.
	/// @param[in] t									The noise type: @enumerateEnum{NoiseType}
	/// @return												@trueIfOtherwiseFalse{cycles is supported}
	//----------------------------------------------------------------------------------------
	static Bool HasCycles(NoiseType t);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Evaluates the sample offset.
	/// @param[in] type								The noise type: @enumerateEnum{NoiseType}
	/// @param[in] rOctaves						The number of octaves.
	/// @param[in] rDelta							The delta.
	/// @param[out] rSampleOffset			Assigned the sample offset.
	//----------------------------------------------------------------------------------------
	static void EvaluateSampleOffset(NoiseType type, Float rOctaves, Float rDelta, Float &rSampleOffset);

	//----------------------------------------------------------------------------------------
	/// Generates a noise preview in @formatParam{dat}.
	/// @param[in] t									The noise type: @enumerateEnum{NoiseType}
	/// @param[out] dat								Filled with the noise preview.
	/// @param[out] str								If not @formatConstant{nullptr} then the name of the noise is assigned. @callerOwnsPointed{string}
	//----------------------------------------------------------------------------------------
	static void GetNoisePreview(NoiseType t, IconData &dat, String *str = nullptr);

	/// @}

	/// @name Noise
	/// @{

	//----------------------------------------------------------------------------------------
	/// Samples a 2D or 3D noise.
	/// @param[in] t									The noise type: @enumerateEnum{NoiseType}
	/// @param[in] two_d							@formatConstant{true} for 2D sampling, @formatConstant{false} for 3D sampling.
	/// @param[in] p									The position.
	/// @param[in] time								The time.
	/// @param[in] octaves						The number of octaves.
	/// @param[in] absolute						@formatConstant{true} to return an absolute value.
	/// @param[in] sampleRad					The sample radius.
	/// @param[in] detailAtt					The detail attenuation.
	/// @param[in] t_repeat						Must be <tt>2^x - 1</tt>, where <tt>x = [1..10]</tt>, i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
	///																A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{t_repeat} the noise will repeat at an earlier time.
	/// @return												The noise sample.
	//----------------------------------------------------------------------------------------
	Float Noise(NoiseType t, Bool two_d, const Vector &p, Float time = 0.0, Float octaves = 4.0, Bool absolute = false, Float sampleRad = 0.25, Float detailAtt = 0.25, Int32 t_repeat = 0);

	/// @}

	/// @name Init Fbm
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes Fractal Brownian Motion.
	/// @param[in] lMaxOctaves				The maximum number of octaves.
	/// @param[in] rLacunarity				The lacunarity.
	/// @param[in] h									The h parameter.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitFbm(Int32 lMaxOctaves, Float rLacunarity, Float h);

	/// @}

	/// @name Private
	/// @{

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const Float* GetFBMTable();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const Float* GetValueTable();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const Float* GetImpulseTable();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static const UChar* GetPermutationTable();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const Int32* GetTPPermutationTable();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const NoiseGradient* GetNoiseGradient();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const Int32* GetPermutationTableA();

	/// @}

	/// @name SNoise
	/// @{

	//----------------------------------------------------------------------------------------
	/// Generates a signed noise value.
	/// @param[in] p									The noise coordinate.
	/// @return												A signed noise value, between @em -1.0 and @em 1.0.
	//----------------------------------------------------------------------------------------
	Float SNoise(Vector p);

	//----------------------------------------------------------------------------------------
	/// Generates a periodic signed noise value.
	/// @param[in] p									The noise coordinate.
	/// @param[in] t									The time.
	/// @param[in] lRepeat						Must be <tt>2^x - 1</tt>, where <tt>x = [1..10]</tt>, i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
	///																A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{lRepeat} the noise will repeat at an earlier time.
	/// @return												A signed noise value, between @em -1.0 and @em 1.0.
	//----------------------------------------------------------------------------------------
	Float SNoise(Vector p, Float t, Int32 lRepeat);

	/// @}

	/// @name Turbulence
	/// @{

	//----------------------------------------------------------------------------------------
	/// Generates a periodic turbulence value, this is a sum of multiple noises with different frequency.
	/// @param[in] p									The noise coordinate.
	/// @param[in] t									The time.
	/// @param[in] rOctaves						The number of octaves.
	/// @param[in] bAbsolute					@formatConstant{true} to return an absolute value.
	/// @param[in] lRepeat						Must be <tt>2^x - 1</tt>, where <tt>x = [1..10]</tt>, i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
	///																A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{lRepeat} the noise will repeat at an earlier time.
	/// @return												A turbulence value, between @em -1.0 and @em 1.0 unless @formatParam{bAbsolute} is @formatConstant{true}, in which case it will be between @em 0.0 to @em 1.0.
	//----------------------------------------------------------------------------------------
	Float Turbulence(Vector p, Float t, Float rOctaves, Bool bAbsolute, Int32 lRepeat);

	/// @}

	/// @name Fbm/Multifractal
	/// @{

	//----------------------------------------------------------------------------------------
	/// Generates a periodic Fractional Brownian Motion value.
	/// @note Before using this function call InitFbm().
	/// @param[in] p									The noise coordinate.
	/// @param[in] t									The time.
	/// @param[in] rOctaves						The number of octaves. Must not exceed the value passed to InitFbm(), but can be lower.
	/// @param[in] lRepeat						Must be <tt>2^x - 1</tt>, where <tt>x = [1..10]</tt>, i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
	///																A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{lRepeat} the noise will repeat at an earlier time.
	/// @return												The Fbm value.
	//----------------------------------------------------------------------------------------
	Float Fbm(Vector p, Float t, Float rOctaves, Int32 lRepeat);

	//----------------------------------------------------------------------------------------
	/// Generates a periodic fractal function used for such things as landscapes or mountain ranges.
	/// @note Before using this function call InitFbm().
	/// @param[in] p									The evaluation point.
	/// @param[in] t									The time.
	/// @param[in] rOctaves						The number of octaves. Must not exceed the value passed to InitFbm(), but can be lower.
	/// @param[in] rOffset						The zero offset, this controls the multifractality.
	/// @param[in] rGain							The amplification of the fractal value.
	/// @param[in] lRepeat						Must be <tt>2^x - 1</tt>, where <tt>x = [1..10]</tt>, i.e. one of @em 1, @em 3, @em 7, @em 15, @em 31, @em 63, @em 127, @em 255, @em 511, and @em 1023.\n
	///																A noise repeats itself in time every @em 1024 units. Using a smaller @formatParam{lRepeat} the noise will repeat at an earlier time.
	/// @return												The fractal value.
	//----------------------------------------------------------------------------------------
	Float RidgedMultifractal(Vector p, Float t, Float rOctaves, Float rOffset, Float rGain, Int32 lRepeat);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iNoise;

struct NoiseLib : public C4DLibrary
{
	iNoise*				(*NoiseLib_Alloc)(Int32 seed);
	void					(*NoiseLib_Free)(iNoise *&p);

	Float					(iNoise::*NoiseLib_Noise2D)(const NoiseType t, const Vector &p, const Float time, const Float octaves, const Bool absolute, const Float sampleRad, const Float detailAtt);
	Float					(iNoise::*NoiseLib_Noise3D)(const NoiseType t, const Vector &p, const Float time, const Float octaves, const Bool absolute, const Float sampleRad, const Float detailAtt);
	Bool					(iNoise::*NoiseLib_InitFbm)(Int32 lMaxOctaves, Float rLacunarity, Float h);
	BaseContainer	(*NoiseLib_CreateMenuContainer)(Bool bIncludeNone);
	Bool					(*NoiseLib_HasOctaves)(NoiseType t);
	void					(*NoiseLib_EvaluateSampleOffset)(NoiseType type, Float rOctaves, Float rDelta, Float &rSampleOffset);
	void					(*NoiseLib_GetNoisePreview)(NoiseType t, IconData &dat, String *str);
	Float					(iNoise::*NoiseLib_Noise)(NoiseType t, Bool two_d, const Vector &p, Float time, Float octaves, Bool absolute, Float sampleRad, Float detailAtt, Int32 t_repeat);
	const Float*	(iNoise::*NoiseLib_GetFBMTable)();
	const Float*	(iNoise::*NoiseLib_GetValueTable)();
	const Float*	(iNoise::*NoiseLib_GetImpulseTable)();
	const UChar*	(*NoiseLib_GetPermutationTable)();
	Bool					(*NoiseLib_HasAbsolute)(NoiseType t);
	Bool					(*NoiseLib_HasCycles)(NoiseType t);
	Float					(iNoise::*SNoiseR)(Vector p, Float t, Int32 lRepeat);
	Float					(iNoise::*SNoise)(Vector p);
	Float					(iNoise::*Turbulence)(Vector p, Float t, Float rOctaves, Bool bAbsolute, Int32 lRepeat);
	Float					(iNoise::*Fbm)(Vector p, Float t, Float rOctaves, Int32 lRepeat);
	Float					(iNoise::*RidgedMultifractal)(Vector p, Float t, Float rOctaves, Float rOffset, Float rGain, Int32 lRepeat);

	iNoise*				(*NoiseLib_Alloc2)(Int32 seed);
	const NoiseGradient*	(iNoise::*NoiseLib_GetNoiseGradient)();
	const Int32*	(iNoise::*NoiseLib_GetPermutationTableA)();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_NOISE_H__
