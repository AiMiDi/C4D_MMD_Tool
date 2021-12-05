#ifndef NOISE_H__
#define NOISE_H__

#include "maxon/apibase.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"
#include "maxon/datadictionary.h"
#include "maxon/basearray.h"
#include "maxon/object.h"
#include "maxon/opaqueref.h"

namespace maxon
{

/// @addtogroup MATH
/// @{
using FbmTableRef = OpaqueRef;

class NoiseInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NoiseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.render.interface.noise");

public:
	/// allocator for common use.
	static MAXON_METHOD NoiseInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Initializes the noise.
	/// A permutationTablePower of 10 results in 1024 elements, which is a good compromise between too frequent repetition and memory consumption.
	/// @param[in] seed								Start value for the random table generation.
	/// @param[in] permutationTablePower	This specifies the size of the permutation table, which will have (2 ^ permutationTablePower) entries. permutationTablePower must be [5..16], otherwise initialization fails.
	/// @return												OK on success. IllegalArgumentError is returned if the permutationTablePower was out of range.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(UInt32 seed, Int permutationTablePower);

	//----------------------------------------------------------------------------------------
	/// Returns the seed value the noise was initialized with.
	/// @return												Seed value of that was passed to Init() or 0 if noise was not initialized.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt32 GetSeed() const;

	//----------------------------------------------------------------------------------------
	/// Returns the power of the permutation table the noise was initialized with.
	/// @return												Value that was passed to Init() or 0 if noise was not initialized.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetPermutationTablePower() const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the permutation table. The table is only valid as long as the class exists and no further Init() is called. All values are read-only.
	/// The permutation table has at least (1 << permutationTablePower) entries. Any additional entries are repetitions of the original elements.
	/// @return												The permutation table or nullptr if noise was not initialized. Ownership doesn't change - the table is still owned by the NoiseRef class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<UInt16>* GetPermutationTable() const;

	//----------------------------------------------------------------------------------------
	/// Fills an array with the gradient data.
	/// @param[in] gradient3D					If this parameter is true, the table for the 3D gradient is returned, otherwise a 4D gradient is returned.
	/// @param[in] gradient						The gradient array to fill.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const;

	//----------------------------------------------------------------------------------------
	/// Fills an array with the FBM data. The table must have been initialized with InitFbm, otherwise the function will fail.
	/// @param[in] table							Table that was initialized with InitFbm.
	/// @param[in] fbm								The table array to fill.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const;

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the random point table. Each component of each point is in the range of [0..1].
	/// The table is only valid as long as the class exists and no further Init() is called. All values are read-only.
	/// The random table has at least (1 << permutationTablePower) entries. Any additional entries are repetitions of the original elements.
	/// @return												The random table or nullptr if noise was not initialized. Ownership doesn't change - the table is still owned by the NoiseRef class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const BaseArray<Vector4d32>* GetRandomTable() const;

	//----------------------------------------------------------------------------------------
	/// Calculates an 'Improved Perlin Noise' value for three dimensions.
	/// The noise will repeat itself after a distance of (1 << permutationTablePower).
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// @param[in] p									Point for noise calculation.
	/// @return												Noise value in the range of [-1..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 SNoise(const Vector32& p) const;

	//----------------------------------------------------------------------------------------
	/// Calculates an 'Improved Perlin Noise' value for four dimensions.
	/// The noise will repeat itself after a distance of (1 << permutationTablePower).
	/// @param[in] p									Point for noise calculation.
	/// @return												Noise value in the range of [-1..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 SNoise(const Vector4d32& p) const;

	//----------------------------------------------------------------------------------------
	/// Calculates an 'Improved Perlin Noise' value for four dimensions.
	/// The noise will repeat itself after a distance of (1 << permutationTablePower).
	/// This is a convenience function that assigns the time to the fourth (w) component.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] time								Time (fourth dimension) for noise calculation.
	/// @return												Noise value in the range of [-1..1]
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Float32 SNoise(const Vector32& p, Float32 time) const
	{
		return SNoise(Vector4d32(p.x, p.y, p.z, time));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates a periodic 'Improved Perlin Noise' value for three dimensions.
	/// The noise will repeat itself after a distance of repeatX/repeatY/repeatZ.
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// Periodic noise is more than 2x slower than regular noise. If you have repetitions that are a power of 2 use a noise with fitting permutationTable instead.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] repeatX						X repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @param[in] repeatY						Y repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @param[in] repeatZ						Z repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @return												Noise value in the range of [-1..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const;

	//----------------------------------------------------------------------------------------
	/// Calculates a periodic 'Improved Perlin Noise' value for four dimensions.
	/// The noise will repeat itself after a distance of repeatX/repeatY/repeatZ/repeatT.
	/// Periodic noise is more than 2x slower than regular noise. If you have repetitions that are a power of 2 use a noise with fitting permutationTable instead.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] repeatX						X repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @param[in] repeatY						Y repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @param[in] repeatZ						Z repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @param[in] repeatT						T repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
	/// @return												Noise value in the range of [-1..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const;

	//----------------------------------------------------------------------------------------
	/// Calculates voronoi noise for three dimensions.
	/// The noise will repeat itself after a distance of (1 << permutationTablePower).
	/// Make sure to choose maximumOrder as small as possible to optimize speed. Also passing nullptr for index will increase calculation speed.
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] maximumOrder				Maximum order that will be calculated. This value must be in the range [1..3], otherwise undefined behaviour will happen.
	/// @param[out] distance					Pointer to an array that will be filled with distance values. It is guaranteed that distance[i] <= distance[i + 1]. The array must at least have maximumOrder elements, otherwise the routine will crash.
	/// @param[out] index							Nullptr or pointer to an array that will be filled with indices to the noise permutation table that correspond to the distance values. The array must at least have maximumOrder elements, otherwise the routine will crash.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const;

	//----------------------------------------------------------------------------------------
	/// Calculates voronoi noise for four dimensions.
	/// The noise will repeat itself after a distance of (1 << permutationTablePower).
	/// Make sure to choose maximumOrder as small as possible to optimize speed. Also passing nullptr for index will increase calculation speed.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] maximumOrder				Maximum order that will be calculated. This value must be in the range [1..3], otherwise undefined behaviour will happen.
	/// @param[out] distance					Pointer to an array that will be filled with distance values. It is guaranteed that distance[i] <= distance[i + 1]. The array must at least have maximumOrder elements, otherwise the routine will crash.
	/// @param[out] index							Nullptr or pointer to an array that will be filled with indices to the noise permutation table that correspond to the distance values. The array must at least have maximumOrder elements, otherwise the routine will crash.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the Fractal Brownian Motion coefficients. The standard is lacunarity 2.0 and gain 0.5.
	/// http://code.google.com/p/fractalterraingeneration/wiki/Fractional_Brownian_Motion.
	/// @param[in] lacunarity					Frequency multiplier between successive octaves, must be >0.0. A lacunarity of 2.0 means that the frequency doubles each octave.
	/// @param[in] gain								Value that shrinks the amplitude. Each octave the amplitude is multiplied by the gain. Values need to be >0.0.
	/// @return												Reference to precomputed Fbm coefficients or nullptr if not enough memory.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMemT<FbmTableRef> InitFbm(Float32 lacunarity, Float32 gain) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Fractal Brownian Motion noise.
	/// @param[in] table							Table that was initialized with InitFbm.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated in the range of [0..15]. The higher the number, the more computationally expensive the function.
	/// @return												Noise value. The range dependens on the values passed to InitFbm.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Fractal Brownian Motion noise.
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// @param[in] table							Table that was initialized with InitFbm.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated in the range of [0..15]. The higher the number, the more computationally expensive the function.
	/// @return												Noise value. The range dependens on the values passed to InitFbm.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Perlin's Turbulence function.
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
	/// @param[in] absolute						If true the absolute values of each octave are summed.
	/// @return												Turbulence value, in the range of [-1.75..1.75]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Turbulence(Vector32 p, Float32 octaves, Bool absolute) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Perlin's Turbulence function.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
	/// @param[in] absolute						If true the absolute values of each octave are summed.
	/// @return												Turbulence value, in the range of [-1.75..1.75]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Musgraves Ridged Multifractal function.
	/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
	/// @param[in] table							Table that was initialized with InitFbm.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
	/// @param[in] offset							Must be >0.0. Offset where the details begin to ramp sharply. A good start value is 1.0.
	/// @param[in] threshold					Must be >0.0. The higher the value, the more sharp details / peaks. A good start value is 2.0.
	/// @return												Multifractal value. The range depends on the used parameters.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const;

	//----------------------------------------------------------------------------------------
	/// Calculates Musgraves Ridged Multifractal function.
	/// @param[in] table							Table that was initialized with InitFbm.
	/// @param[in] p									Point for noise calculation.
	/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
	/// @param[in] offset							Must be >0.0. Offset where the details begin to ramp sharply. A good start value is 1.0.
	/// @param[in] threshold					Must be >0.0. The higher the value, the more sharp details / peaks. A good start value is 2.0.
	/// @return												Multifractal value. The range depends on the used parameters.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const;
};

//----------------------------------------------------------------------------------------
/// Properties of the DataDictionary in RenderNoiseInterface::Init.
//----------------------------------------------------------------------------------------
namespace NOISEPROPERTY
{
	MAXON_ATTRIBUTE(Float, LACUNARITY, 0);		///< Property for all Fbm-based noises
	MAXON_ATTRIBUTE(Float, GAIN, 1);					///< Property for all Fbm-based noises
	MAXON_ATTRIBUTE(Float, EXPONENT, 2);			///< Property for all Voronoi-based noises
}

//----------------------------------------------------------------------------------------
/// RenderNoiseInterface class for noises that perform more complex operations on basic noises.
/// To allocate an instance of a RenderNoiseInterface call RenderNoiseClasses::Get("<name>").Create().
//----------------------------------------------------------------------------------------
class RenderNoiseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(RenderNoiseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.render.interface.rendernoise");

public:
	//----------------------------------------------------------------------------------------
	/// Initializes the noise.
	/// A permutationTablePower of 10 results in 1024 elements, which is a good compromise between too frequent repetition and memory consumption.
	/// @param[in] seed								Start value for the random table generation.
	/// @param[in] permutationTablePower	This specifies the size of the permutation table, which will have (2 ^ permutationTablePower) entries. permutationTablePower must be [5..16], otherwise initialization fails.
	/// @param[in] additionalParameters	Additional noise-specific parameters.
	/// @return												OK on success. An error is also returned if the passed noise reference was not yet initialized.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters);

	//----------------------------------------------------------------------------------------
	/// Calculates a noise value.
	/// @param[in] p									Point for which noise is calculated.
	/// @param[in] time								Time for which noise is calculated.
	/// @param[in] octaves						Maximum number of octaves calculated. Does only apply to some noises.
	/// @param[in] absolute						If true the absolute value of the noise will be returned.
	/// @param[in] sampleRadius				The radius that determines how much details of the noise will be retained. A value of 0.0 returns the original value. Any higher values reduce details and might blend the result towards an average value.
	/// @return												Noise value in the range of [0..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Noise(const Vector32& p, Float32 time, Float32 octaves = 6.0, Bool absolute = false, Float32 sampleRadius = 0.0) const;

	//----------------------------------------------------------------------------------------
	/// Calculates a noise value.
	/// @param[in] p									Point for which noise is calculated.
	/// @param[in] time								Time for which noise is calculated.
	/// @param[in] octaves						Maximum number of octaves calculated. Does only apply to some noises.
	/// @param[in] absolute						If true the absolute value of the noise will be returned.
	/// @param[in] sampleRadius				The radius that determines how much details of the noise will be retained. A value of 0.0 returns the original value. Any higher values reduce details and might blend the result towards an average value.
	/// @return												Noise value in the range of [0..1]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float32 Noise(const Vector2d32& p, Float32 time, Float32 octaves = 6.0, Bool absolute = false, Float32 sampleRadius = 0.0) const;
};

#include "noise1.hxx"


MAXON_REGISTRY(Class<RenderNoiseRef>, RenderNoiseClasses, "net.maxon.render.registry.rendernoiseclasses");

namespace RenderNoiseClasses
{
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, PERLIN, "net.maxon.render.rendernoiseclass.perlin");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, FBM, "net.maxon.render.rendernoiseclass.fbm");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, TURBULENCE, "net.maxon.render.rendernoiseclass.turbulence");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, RIDGEDMULTIFRACTAL, "net.maxon.render.rendernoiseclass.ridgedmultifractal");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, GASEOUS, "net.maxon.render.rendernoiseclass.gaseous");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, ELECTRIC, "net.maxon.render.rendernoiseclass.electric");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, BOX, "net.maxon.render.rendernoiseclass.box");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, BLISTEREDTURBULENCE, "net.maxon.render.rendernoiseclass.blisteredturbulence");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, CRANAL, "net.maxon.render.rendernoiseclass.cranal");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, BUYA, "net.maxon.render.rendernoiseclass.buya");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, DENTS, "net.maxon.render.rendernoiseclass.dents");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, CELL, "net.maxon.render.rendernoiseclass.cell");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, DISPLACEDTURBULENCE, "net.maxon.render.rendernoiseclass.displacedturbulence");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, HAMA, "net.maxon.render.rendernoiseclass.hama");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, LUKA, "net.maxon.render.rendernoiseclass.luka");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, MOD, "net.maxon.render.rendernoiseclass.mod");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, NAKI, "net.maxon.render.rendernoiseclass.naki");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, NUTOUS, "net.maxon.render.rendernoiseclass.nutous");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, OBER, "net.maxon.render.rendernoiseclass.ober");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, PEZO, "net.maxon.render.rendernoiseclass.pezo");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, POXO, "net.maxon.render.rendernoiseclass.poxo");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, SEMA, "net.maxon.render.rendernoiseclass.sema");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, STUPL, "net.maxon.render.rendernoiseclass.stupl");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, VL, "net.maxon.render.rendernoiseclass.vl");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, WAVYTURBULENCE, "net.maxon.render.rendernoiseclass.wavyturbulence");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, ZADA, "net.maxon.render.rendernoiseclass.zada");
//	MAXON_DECLARATION(RenderNoiseClasses::EntryType, SPARSECONVOLUTION, "net.maxon.render.rendernoiseclass.sparseconvolution");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, CELLVORONOI, "net.maxon.render.rendernoiseclass.cellvoronoi");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, DISPLACEDVORONOI, "net.maxon.render.rendernoiseclass.displacedvoronoi");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, VORONOI1, "net.maxon.render.rendernoiseclass.voronoi1");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, VORONOI2, "net.maxon.render.rendernoiseclass.voronoi2");
	MAXON_DECLARATION(RenderNoiseClasses::EntryType, VORONOI3, "net.maxon.render.rendernoiseclass.voronoi3");
}

#include "noise2.hxx"

/// @}

} // namespace maxon

#endif // NOISE_H__
