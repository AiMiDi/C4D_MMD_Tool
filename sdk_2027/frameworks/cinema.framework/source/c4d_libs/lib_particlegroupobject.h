/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_PARTICLEGROUPOBJECT_H__
#define LIB_PARTICLEGROUPOBJECT_H__

#include "c4d_library.h"
#include "maxon/block.h"
#include "maxon/quaternion.h"

#ifdef __API_INTERN__
#include "baseobject.h"
#else
#include "c4d_baseobject.h"
#endif

/// @addtogroup group_particlegroupobjectlibrary ParticleGroupObject
/// @ingroup group_library
/// @{

namespace cinema
{

//----------------------------------------------------------------------------------------
/// The particle group object object class of type @ref Ofpgroup.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class ParticleGroupObject : public PointObject
{
private:
	ParticleGroupObject();
	~ParticleGroupObject();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{ParticleGroupObject object}
	/// @return												@allocReturn{ParticleGroupObject object}
	//----------------------------------------------------------------------------------------
	static ParticleGroupObject* Alloc() 
	{ 
#ifdef __API_INTERN__
		return (ParticleGroupObject*)AllocObject(Ofpgroup);
#else
		return (ParticleGroupObject*)BaseList2D::Alloc(Ofpgroup);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{ParticleGroupObject objects}
	/// @param[in] p									@theToDestruct{ParticleGroupObject object}
	//----------------------------------------------------------------------------------------
	static void Free(ParticleGroupObject*& p)
	{
#ifdef __API_INTERN__
		DeleteObj(p);
#else
		BaseList2D::Free(reinterpret_cast<BaseList2D*&>(p));
#endif	
	}

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns the unique ids of the particles.
	/// @return												The particle ids as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const UInt32> GetParticleUniqueIdsR() const;
	const maxon::Block<UInt32> GetParticleUniqueIdsW();

	//----------------------------------------------------------------------------------------
	/// Returns the position of the particles. This is equivalent to GetPointR().
	/// @return												The particle positions as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const Vector> GetParticlePositionsR() const;
	const maxon::Block<Vector> GetParticlePositionsW();

	//----------------------------------------------------------------------------------------
	/// Returns the colors of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle colors as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const maxon::ColorA32> GetParticleColorsR() const;
	const maxon::Block<maxon::ColorA32> GetParticleColorsW();

	//----------------------------------------------------------------------------------------
	/// Returns the velocities of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle velocities as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::StridedBlock<const Vector32> GetParticleVelocitiesR() const;
	const maxon::StridedBlock<Vector32> GetParticleVelocitiesW();

	//----------------------------------------------------------------------------------------
	/// Returns the ages of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle ages as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const Float32> GetParticleAgesR() const;
	const maxon::Block<Float32> GetParticleAgesW();

	//----------------------------------------------------------------------------------------
	/// Returns the lifetimes of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle lifetimes as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const Float32> GetParticleLifetimesR() const;
	const maxon::Block<Float32> GetParticleLifetimesW();

	//----------------------------------------------------------------------------------------
	/// Returns the radii of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle radii as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const Float32> GetParticleRadiiR() const;
	const maxon::Block<Float32> GetParticleRadiiW();
	//----------------------------------------------------------------------------------------
	/// Returns the distances traversed of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle distance traversed as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const Float32> GetParticleDistancesTraversedR() const;
	const maxon::Block<Float32> GetParticleDistancesTraversedW();

	//----------------------------------------------------------------------------------------
	/// Returns the alignment of the particles as a quaternion. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle alignment as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::Block<const maxon::Quaternion<Float32>> GetParticleAlignmentsR() const;
	const maxon::Block<maxon::Quaternion<Float32>> GetParticleAlignmentsW();

	//----------------------------------------------------------------------------------------
	/// Returns the angular velocity of the particles. If the count is 0 but the particles positions exist, it means this attribute was not allocated.
	/// @return												The particle angular velocity as a continuous memory block.
	//----------------------------------------------------------------------------------------
	const maxon::StridedBlock<const Vector32> GetParticleAngularVelocitiesR() const;
	const maxon::StridedBlock<Vector32> GetParticleAngularVelocitiesW();

	//----------------------------------------------------------------------------------------
	/// Returns the a list of channel ids.
	/// idReceiver[in]								a value receiver that will be called with the channel ids and their datatype.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> GetAttributeChannelIds(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const;

	//----------------------------------------------------------------------------------------
	/// Returns the an attribute channel as a generic block and a datatype.
	/// channelId[in]									The id of the channel.
	/// @return												The Data of the channel.
	//----------------------------------------------------------------------------------------
	maxon::Data GetAttributeChannel(const maxon::InternedId& channelId) const;

	template<typename ATTR>
	maxon::Data GetAttributeChannel(const ATTR& channelAttribute) const
	{
		return GetAttributeChannel(channelAttribute.Get());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the a list of system channel ids - default attributes.
	/// idReceiver[in]								a value receiver that will be called with the channel ids and their datatype.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> GetSystemAttributeChannelIds(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const;

	//----------------------------------------------------------------------------------------
	/// Returns a single group index for a particle group object (multi groups excluded and will return -1). The single particle groups start at 1 as 0 is reserved for the root group.
	/// @return												The group index of the simulation, -1 if it wasn't found or the simulation has not started.
	//----------------------------------------------------------------------------------------
	Int32 GetParticleGroupIndex() const;
	/// @}
};

/// Particle Group Object library ID.
#define LIBRARY_PARTICLEGROUPOBJECT 1062042

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class CINEWARE_SINGLEINHERITANCE iParticleGroupObject;

struct ParticleGroupObjectLib : public C4DLibrary
{
	const maxon::Block<UInt32>(iParticleGroupObject::*GetParticleUniqueIds)();
	const maxon::Block<Vector>(iParticleGroupObject::*GetParticlePositions)();
	const maxon::Block<maxon::ColorA32>(iParticleGroupObject::*GetParticleColors)();
	const maxon::StridedBlock<Vector32>(iParticleGroupObject::*GetParticleVelocities)();
	const maxon::Block<Float32>(iParticleGroupObject::*GetParticleAges)();
	const maxon::Block<Float32>(iParticleGroupObject::*GetParticleLifetimes)();
	const maxon::Block<Float32>(iParticleGroupObject::*GetParticleRadii)();
	const maxon::Block<Float32>(iParticleGroupObject::*GetParticleDistancesTraversed)();
	const maxon::Block<maxon::Quaternion<Float32>>(iParticleGroupObject::*GetParticleAlignments)();
	const maxon::StridedBlock<Vector32>(iParticleGroupObject::*GetParticleAngularVelocities)();
	const maxon::Block<const UInt32>(iParticleGroupObject::*GetParticleUniqueIdsC)() const;
	const maxon::Block<const Vector>(iParticleGroupObject::*GetParticlePositionsC)() const;
	const maxon::Block<const maxon::ColorA32>(iParticleGroupObject::*GetParticleColorsC)() const;
	const maxon::StridedBlock<const Vector32>(iParticleGroupObject::*GetParticleVelocitiesC)() const;
	const maxon::Block<const Float32>(iParticleGroupObject::*GetParticleAgesC)() const;
	const maxon::Block<const Float32>(iParticleGroupObject::*GetParticleLifetimesC)() const;
	const maxon::Block<const Float32>(iParticleGroupObject::*GetParticleRadiiC)() const;
	const maxon::Block<const Float32>(iParticleGroupObject::*GetParticleDistancesTraversedC)() const;
	maxon::Result<void>(iParticleGroupObject::*GetAttributeChannelIds)(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const;
	const maxon::Block<const maxon::Quaternion<Float32>>(iParticleGroupObject::* GetParticleAlignmentsC)() const;
	const maxon::StridedBlock<const Vector32>(iParticleGroupObject::* GetParticleAngularVelocitiesC)() const;
	maxon::Data(iParticleGroupObject::*GetAttributeChannel)(const maxon::InternedId& channelId) const;
	maxon::Result<void>(iParticleGroupObject::*GetSystemAttributeChannelIds)(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const;
	Int32(iParticleGroupObject::*GetParticleGroupIndex)() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_PARTICLEGROUPOBJECT_H__
