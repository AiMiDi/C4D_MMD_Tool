/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_PARTICLEOBJECT_H__
#define C4D_PARTICLEOBJECT_H__

#ifdef __API_INTERN__
#error "Not in the kernel"
#endif

#include "c4d_baseobject.h"
#include "c4d_basetag.h"

//----------------------------------------------------------------------------------------
/// Structure used to change the particle path by the particle modifiers.
//----------------------------------------------------------------------------------------
struct BaseParticle
{
	Vector	v;					///< The velocity sum of the modifications to the particle, the current velocity of the particle is found from Particle.\n
											///< The new velocity is calculated using this velocity sum and dividing by the sum @ref count.
	Int32		count;			///< The sum count of the velocities added to the velocity vector @ref v.
};

//----------------------------------------------------------------------------------------
/// The information for each particle: its location, movement and life.
//----------------------------------------------------------------------------------------
class Particle
{
public:
	Vector				off,			///< The current position of the particle.
								v1,				///< This vector is usually calculated by @C4D when using the Tangential option in the particle emitter.\n
													///< The vectors @ref v1 and @ref v3 are used to form the axes to align the direction in which the objects attached to the particles are aligned.
								v3;				///< The current velocity of the particle (speed and direction). See CalcParticleMatrix().
	Float					t;				///< The current time from the particles birth, this is the age of the particle.
	PARTICLEFLAGS bits;			///< The flags for the particle state: @enumerateEnum{PARTICLEFLAGS}
};

//----------------------------------------------------------------------------------------
/// Details about the position and life of a particle, this is retrieved using ParticleObject::GetParticleDetails().
//----------------------------------------------------------------------------------------
struct ParticleDetails
{
	Matrix	m;						///< The position and rotation of the objects on the particles.
	Float		lifetime;			///< The lifetime of the particle. When Particle::t reaches this value the particle will die.
};

//----------------------------------------------------------------------------------------
/// The invisible tag associated with each emitter that stores the particles. GetType() returns @ref Tparticle.
/// @note The arrays returned by GetLowlevelDataAddressR() and GetLowlevelDataAddressW() are private.
/// @see ParticleObject::GetParticleR ParticleObject::GetParticleW
//----------------------------------------------------------------------------------------
class ParticleTag : public VariableTag
{
private:
	ParticleTag();
	~ParticleTag();
};

//----------------------------------------------------------------------------------------
/// Represents the main emitter object that creates and holds the particles.
/// @note Particles can only be created using an emitter object, but once they are created their velocity can be modified.
//----------------------------------------------------------------------------------------
class ParticleObject : public BaseObject
{
private:
	ParticleObject();
	~ParticleObject();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the number of particles in the particle array.
	/// @return												The total number of particles created by this emitter.
	//----------------------------------------------------------------------------------------
	Int32 GetParticleCount(void);

	//----------------------------------------------------------------------------------------
	/// Checks if the Particle::v1 vector in the particles can be accessed, effective if the emitter has the Tangential option enabled.
	/// @return												@trueIfOtherwiseFalse{the direction vector is valid and used}
	//----------------------------------------------------------------------------------------
	Bool IsMatrixAvailable(void);

	//----------------------------------------------------------------------------------------
	/// Gets the lifetime for the particles. When Particle::t reaches this time the particle will die.
	/// @return												The number of frames the particles will live for.
	//----------------------------------------------------------------------------------------
	Float GetLifetime(void);

	//----------------------------------------------------------------------------------------
	/// Gets the read-only Particle structure for a particle in the particle array.
	/// @param[in] pt									The particle tag from the emitter (this particle object) to get the particles for. @callerOwnsPointed{tag}\n
	///																This tag is not visible in the @C4D editor, to retrieve it use:
	///																@code
	///																(ParticleTag*) op->GetTag(Tparticle)
	///																@endcode
	///																where @c op is the particle emitter object.
	/// @param[in] i									The index in the array of the particle to get: @em 0 <= @formatParam{i} < GetParticleCount()
	/// @return												The particle information structure. @theOwnsPointed{particle object,particle information}
	//----------------------------------------------------------------------------------------
	const Particle* GetParticleR(ParticleTag* pt, Int32 i) { return C4DOS.Bo->PrGetParticleR(this, pt, i); }

	//----------------------------------------------------------------------------------------
	/// Gets the writable Particle structure for a particle in the particle array.
	/// @param[in] pt									The particle tag from the emitter (this particle object) to get the particles for. @callerOwnsPointed{tag}\n
	///																This tag is not visible in the @C4D editor, to retrieve it use:
	///																@code
	///																(ParticleTag*) op->GetTag(Tparticle)
	///																@endcode
	///																where @c op is the particle emitter object.
	/// @param[in] i									The index in the array of the particle to get: @em 0 <= @formatParam{i} < GetParticleCount()
	/// @return												The particle information structure. @theOwnsPointed{particle object,particle information}
	//----------------------------------------------------------------------------------------
	Particle* GetParticleW(ParticleTag* pt, Int32 i) { return C4DOS.Bo->PrGetParticleW(this, pt, i); }

	//----------------------------------------------------------------------------------------
	/// Gets an array of ParticleDetails for each particle of this emitter.\n
	/// @warning The returned ParticleDetails array must be freed using DeleteMem() afterwards.
	/// @param[in] doc								The document that the emitter is in. @callerOwnsPointed{document}\n
	///																Generally every object, tag etc. can obtain the document it is linked to, but this costs (a bit) time.\n
	///																So for speed optimizations the document is often explicitly passed.
	/// @return												The particle details for the emitter's particles.
	//----------------------------------------------------------------------------------------
	ParticleDetails* GetParticleDetails(BaseDocument* doc);
};

//----------------------------------------------------------------------------------------
/// Calculates a particle matrix.\n
/// This represents the position and direction of a particle as used when objects are aligned with a particle using the emitter Tangential option.
/// @param[in] cp									The particle to get the matrix for. @callerOwnsPointed{particle}
/// @return												The particle matrix.
//----------------------------------------------------------------------------------------
static inline Matrix CalcParticleMatrix(Particle* cp)
{
	Matrix m;
	m.sqmat.v1	= !cp->v1;
	m.sqmat.v3	= !cp->v3;
	m.sqmat.v2	= !Cross(m.sqmat.v3, m.sqmat.v1);
	m.off = cp->off;
	return m;
}

#endif // C4D_PARTICLEOBJECT_H__
