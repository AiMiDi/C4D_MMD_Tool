#if 1
class NoiseRef;

struct NoiseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = NoiseRef;
	/// Intermediate helper class for NoiseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the seed value the noise was initialized with.
/// @return												Seed value of that was passed to Init() or 0 if noise was not initialized.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type GetSeed() const;
/// Returns the power of the permutation table the noise was initialized with.
/// @return												Value that was passed to Init() or 0 if noise was not initialized.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetPermutationTablePower() const;
/// Returns a pointer to the permutation table. The table is only valid as long as the class exists and no further Init() is called. All values are read-only.
/// The permutation table has at least (1 << permutationTablePower) entries. Any additional entries are repetitions of the original elements.
/// @return												The permutation table or nullptr if noise was not initialized. Ownership doesn't change - the table is still owned by the NoiseRef class.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type GetPermutationTable() const;
/// Fills an array with the gradient data.
/// @param[in] gradient3D					If this parameter is true, the table for the 3D gradient is returned, otherwise a 4D gradient is returned.
/// @param[in] gradient						The gradient array to fill.
/// @return												OK on success.
		inline Result<void> GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const;
/// Fills an array with the FBM data. The table must have been initialized with InitFbm, otherwise the function will fail.
/// @param[in] table							Table that was initialized with InitFbm.
/// @param[in] fbm								The table array to fill.
/// @return												OK on success.
		inline Result<void> GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const;
/// Returns a pointer to the random point table. Each component of each point is in the range of [0..1].
/// The table is only valid as long as the class exists and no further Init() is called. All values are read-only.
/// The random table has at least (1 << permutationTablePower) entries. Any additional entries are repetitions of the original elements.
/// @return												The random table or nullptr if noise was not initialized. Ownership doesn't change - the table is still owned by the NoiseRef class.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type GetRandomTable() const;
/// Calculates an 'Improved Perlin Noise' value for three dimensions.
/// The noise will repeat itself after a distance of (1 << permutationTablePower).
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// @param[in] p									Point for noise calculation.
/// @return												Noise value in the range of [-1..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type SNoise(const Vector32& p) const;
/// Calculates an 'Improved Perlin Noise' value for four dimensions.
/// The noise will repeat itself after a distance of (1 << permutationTablePower).
/// @param[in] p									Point for noise calculation.
/// @return												Noise value in the range of [-1..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type SNoise(const Vector4d32& p) const;
/// Calculates an 'Improved Perlin Noise' value for four dimensions.
/// The noise will repeat itself after a distance of (1 << permutationTablePower).
/// This is a convenience function that assigns the time to the fourth (w) component.
/// @param[in] p									Point for noise calculation.
/// @param[in] time								Time (fourth dimension) for noise calculation.
/// @return												Noise value in the range of [-1..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type SNoise(const Vector32& p, Float32 time) const;
/// Calculates a periodic 'Improved Perlin Noise' value for three dimensions.
/// The noise will repeat itself after a distance of repeatX/repeatY/repeatZ.
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// Periodic noise is more than 2x slower than regular noise. If you have repetitions that are a power of 2 use a noise with fitting permutationTable instead.
/// @param[in] p									Point for noise calculation.
/// @param[in] repeatX						X repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @param[in] repeatY						Y repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @param[in] repeatZ						Z repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @return												Noise value in the range of [-1..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const;
/// Calculates a periodic 'Improved Perlin Noise' value for four dimensions.
/// The noise will repeat itself after a distance of repeatX/repeatY/repeatZ/repeatT.
/// Periodic noise is more than 2x slower than regular noise. If you have repetitions that are a power of 2 use a noise with fitting permutationTable instead.
/// @param[in] p									Point for noise calculation.
/// @param[in] repeatX						X repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @param[in] repeatY						Y repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @param[in] repeatZ						Z repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @param[in] repeatT						T repetition. Needs to be in the range of [2..(1 << permutationTablePower)].
/// @return												Noise value in the range of [-1..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const;
/// Calculates voronoi noise for three dimensions.
/// The noise will repeat itself after a distance of (1 << permutationTablePower).
/// Make sure to choose maximumOrder as small as possible to optimize speed. Also passing nullptr for index will increase calculation speed.
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// @param[in] p									Point for noise calculation.
/// @param[in] maximumOrder				Maximum order that will be calculated. This value must be in the range [1..3], otherwise undefined behaviour will happen.
/// @param[out] distance					Pointer to an array that will be filled with distance values. It is guaranteed that distance[i] <= distance[i + 1]. The array must at least have maximumOrder elements, otherwise the routine will crash.
/// @param[out] index							Nullptr or pointer to an array that will be filled with indices to the noise permutation table that correspond to the distance values. The array must at least have maximumOrder elements, otherwise the routine will crash.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const;
/// Calculates voronoi noise for four dimensions.
/// The noise will repeat itself after a distance of (1 << permutationTablePower).
/// Make sure to choose maximumOrder as small as possible to optimize speed. Also passing nullptr for index will increase calculation speed.
/// @param[in] p									Point for noise calculation.
/// @param[in] maximumOrder				Maximum order that will be calculated. This value must be in the range [1..3], otherwise undefined behaviour will happen.
/// @param[out] distance					Pointer to an array that will be filled with distance values. It is guaranteed that distance[i] <= distance[i + 1]. The array must at least have maximumOrder elements, otherwise the routine will crash.
/// @param[out] index							Nullptr or pointer to an array that will be filled with indices to the noise permutation table that correspond to the distance values. The array must at least have maximumOrder elements, otherwise the routine will crash.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const;
/// Initializes the Fractal Brownian Motion coefficients. The standard is lacunarity 2.0 and gain 0.5.
/// http://code.google.com/p/fractalterraingeneration/wiki/Fractional_Brownian_Motion.
/// @param[in] lacunarity					Frequency multiplier between successive octaves, must be >0.0. A lacunarity of 2.0 means that the frequency doubles each octave.
/// @param[in] gain								Value that shrinks the amplitude. Each octave the amplitude is multiplied by the gain. Values need to be >0.0.
/// @return												Reference to precomputed Fbm coefficients or nullptr if not enough memory.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type InitFbm(Float32 lacunarity, Float32 gain) const;
/// Calculates Fractal Brownian Motion noise.
/// @param[in] table							Table that was initialized with InitFbm.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated in the range of [0..15]. The higher the number, the more computationally expensive the function.
/// @return												Noise value. The range dependens on the values passed to InitFbm.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const;
/// Calculates Fractal Brownian Motion noise.
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// @param[in] table							Table that was initialized with InitFbm.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated in the range of [0..15]. The higher the number, the more computationally expensive the function.
/// @return												Noise value. The range dependens on the values passed to InitFbm.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const;
/// Calculates Perlin's Turbulence function.
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
/// @param[in] absolute						If true the absolute values of each octave are summed.
/// @return												Turbulence value, in the range of [-1.75..1.75]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Turbulence(Vector32 p, Float32 octaves, Bool absolute) const;
/// Calculates Perlin's Turbulence function.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
/// @param[in] absolute						If true the absolute values of each octave are summed.
/// @return												Turbulence value, in the range of [-1.75..1.75]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const;
/// Calculates Musgraves Ridged Multifractal function.
/// Note that calling with Vector4d32 and the fourth (w) component set to zero delivers different results as the 4-dimensional tables are different.
/// @param[in] table							Table that was initialized with InitFbm.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
/// @param[in] offset							Must be >0.0. Offset where the details begin to ramp sharply. A good start value is 1.0.
/// @param[in] threshold					Must be >0.0. The higher the value, the more sharp details / peaks. A good start value is 2.0.
/// @return												Multifractal value. The range depends on the used parameters.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const;
/// Calculates Musgraves Ridged Multifractal function.
/// @param[in] table							Table that was initialized with InitFbm.
/// @param[in] p									Point for noise calculation.
/// @param[in] octaves						Number of octaves to be calculated. The higher the number, the more computationally expensive the function.
/// @param[in] offset							Must be >0.0. Offset where the details begin to ramp sharply. A good start value is 1.0.
/// @param[in] threshold					Must be >0.0. The higher the value, the more sharp details / peaks. A good start value is 2.0.
/// @return												Multifractal value. The range depends on the used parameters.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const;
	};
	/// Intermediate helper class for NoiseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NoiseRef, true>::type&() const { return reinterpret_cast<const NoiseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NoiseRef, false>::type&() { return reinterpret_cast<const NoiseRef&>(this->GetBaseRef()); }
/// Initializes the noise.
/// A permutationTablePower of 10 results in 1024 elements, which is a good compromise between too frequent repetition and memory consumption.
/// @param[in] seed								Start value for the random table generation.
/// @param[in] permutationTablePower	This specifies the size of the permutation table, which will have (2 ^ permutationTablePower) entries. permutationTablePower must be [5..16], otherwise initialization fails.
/// @return												OK on success. IllegalArgumentError is returned if the permutationTablePower was out of range.
		inline Result<void> Init(UInt32 seed, Int permutationTablePower) const;
	};
	/// Intermediate helper class for NoiseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NoiseRef, false>::type&() { return reinterpret_cast<const NoiseRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type
	> { };
};
class NoiseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NoiseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NoiseInterface, maxon::StrongRefHandler, NoiseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NoiseInterface, maxon::StrongRefHandler, NoiseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// allocator for common use.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<NoiseRef> Create();
};

/// NoiseRef is the reference class of NoiseInterface.
class NoiseRef : public NoiseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NoiseRef, typename NoiseInterface::Hxx1::Reference);
	using ConstPtr = typename NoiseInterface::ConstPtr;
};

namespace NOISEPROPERTY
{
#ifndef PRIVATE_MAXON_GUARD_maxon_NOISEPROPERTY
#define PRIVATE_MAXON_GUARD_maxon_NOISEPROPERTY
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class RenderNoiseRef;

struct RenderNoiseInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, RenderNoiseInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(RenderNoiseInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct RenderNoiseInterface::Hxx1
{
	class Reference;
	using ReferenceClass = RenderNoiseRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for RenderNoiseInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Calculates a noise value.
/// @param[in] p									Point for which noise is calculated.
/// @param[in] time								Time for which noise is calculated.
/// @param[in] octaves						Maximum number of octaves calculated. Does only apply to some noises.
/// @param[in] absolute						If true the absolute value of the noise will be returned.
/// @param[in] sampleRadius				The radius that determines how much details of the noise will be retained. A value of 0.0 returns the original value. Any higher values reduce details and might blend the result towards an average value.
/// @return												Noise value in the range of [0..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Noise(const Vector32& p, Float32 time, Float32 octaves = 6.0, Bool absolute = false, Float32 sampleRadius = 0.0) const;
/// Calculates a noise value.
/// @param[in] p									Point for which noise is calculated.
/// @param[in] time								Time for which noise is calculated.
/// @param[in] octaves						Maximum number of octaves calculated. Does only apply to some noises.
/// @param[in] absolute						If true the absolute value of the noise will be returned.
/// @param[in] sampleRadius				The radius that determines how much details of the noise will be retained. A value of 0.0 returns the original value. Any higher values reduce details and might blend the result towards an average value.
/// @return												Noise value in the range of [0..1]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type Noise(const Vector2d32& p, Float32 time, Float32 octaves = 6.0, Bool absolute = false, Float32 sampleRadius = 0.0) const;
	};
	/// Intermediate helper class for RenderNoiseInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, RenderNoiseRef, true>::type&() const { return reinterpret_cast<const RenderNoiseRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, RenderNoiseRef, false>::type&() { return reinterpret_cast<const RenderNoiseRef&>(this->GetBaseRef()); }
/// Initializes the noise.
/// A permutationTablePower of 10 results in 1024 elements, which is a good compromise between too frequent repetition and memory consumption.
/// @param[in] seed								Start value for the random table generation.
/// @param[in] permutationTablePower	This specifies the size of the permutation table, which will have (2 ^ permutationTablePower) entries. permutationTablePower must be [5..16], otherwise initialization fails.
/// @param[in] additionalParameters	Additional noise-specific parameters.
/// @return												OK on success. An error is also returned if the passed noise reference was not yet initialized.
		inline Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) const;
	};
	/// Intermediate helper class for RenderNoiseInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, RenderNoiseRef, false>::type&() { return reinterpret_cast<const RenderNoiseRef&>(this->GetBaseRef()); }
/// Initializes the noise.
/// A permutationTablePower of 10 results in 1024 elements, which is a good compromise between too frequent repetition and memory consumption.
/// @param[in] seed								Start value for the random table generation.
/// @param[in] permutationTablePower	This specifies the size of the permutation table, which will have (2 ^ permutationTablePower) entries. permutationTablePower must be [5..16], otherwise initialization fails.
/// @param[in] additionalParameters	Additional noise-specific parameters.
/// @return												OK on success. An error is also returned if the passed noise reference was not yet initialized.
		inline Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class RenderNoiseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<RenderNoiseRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<RenderNoiseInterface, maxon::StrongRefHandler, RenderNoiseRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<RenderNoiseInterface, maxon::StrongRefHandler, RenderNoiseRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// RenderNoiseRef is the reference class of RenderNoiseInterface.
///
/// RenderNoiseInterface class for noises that perform more complex operations on basic noises.
/// To allocate an instance of a RenderNoiseInterface call RenderNoiseClasses::Get("<name>").Create().
class RenderNoiseRef : public RenderNoiseInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(RenderNoiseRef, typename RenderNoiseInterface::Hxx1::Reference);
	using ConstPtr = typename RenderNoiseInterface::ConstPtr;
};

#endif
