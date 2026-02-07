#include "lib_particlegroupobject.h"

namespace cinema
{

ParticleGroupObjectLib* lib_particlegroupobject = nullptr;

static ParticleGroupObjectLib* CheckParticleGroupObjectLib(Int32 offset)
{
	return CheckLib<ParticleGroupObjectLib>(LIBRARY_PARTICLEGROUPOBJECT, offset, lib_particlegroupobject);
}


#define ParticleGroupObjectLibCall(b) 		cinema::ParticleGroupObjectLib* lib = cinema::CheckParticleGroupObjectLib(LIBOFFSET(cinema::ParticleGroupObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iParticleGroupObject*>(this)->*lib->b)

#define ParticleGroupObjectLibCallC(b) 		cinema::ParticleGroupObjectLib* lib = cinema::CheckParticleGroupObjectLib(LIBOFFSET(cinema::ParticleGroupObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<const cinema::iParticleGroupObject*>(this)->*lib->b)

#define ParticleGroupObjectLibCallR(a, b) cinema::ParticleGroupObjectLib* lib = cinema::CheckParticleGroupObjectLib(LIBOFFSET(cinema::ParticleGroupObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iParticleGroupObject*>(this)->*lib->b)

#define ParticleGroupObjectLibCallRC(a, b) cinema::ParticleGroupObjectLib* lib = cinema::CheckParticleGroupObjectLib(LIBOFFSET(cinema::ParticleGroupObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iParticleGroupObject*>(this)->*lib->b)

const maxon::Block<const UInt32> ParticleGroupObject::GetParticleUniqueIdsR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const UInt32>(nullptr, 0), GetParticleUniqueIdsC)();
}
const maxon::Block<const Vector> ParticleGroupObject::GetParticlePositionsR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const Vector>(nullptr, 0), GetParticlePositionsC)();
}
const maxon::Block<const maxon::ColorA32> ParticleGroupObject::GetParticleColorsR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const maxon::ColorA32>(nullptr, 0), GetParticleColorsC)();
}
const maxon::StridedBlock<const Vector32> ParticleGroupObject::GetParticleVelocitiesR() const
{
	ParticleGroupObjectLibCallRC(maxon::StridedBlock<const Vector32>(nullptr, 0), GetParticleVelocitiesC)();
}
const maxon::Block<const Float32> ParticleGroupObject::GetParticleAgesR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const Float32>(nullptr, 0), GetParticleAgesC)();
}
const maxon::Block<const Float32> ParticleGroupObject::GetParticleLifetimesR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const Float32>(nullptr, 0), GetParticleLifetimesC)();
}
const maxon::Block<const Float32> ParticleGroupObject::GetParticleRadiiR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const Float32>(nullptr, 0), GetParticleRadiiC)();
}
const maxon::Block<const Float32> ParticleGroupObject::GetParticleDistancesTraversedR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const Float32>(nullptr, 0), GetParticleDistancesTraversedC)();
}
const maxon::Block<const maxon::Quaternion<Float32>> ParticleGroupObject::GetParticleAlignmentsR() const
{
	ParticleGroupObjectLibCallRC(maxon::Block<const maxon::Quaternion<Float32>>(nullptr, 0), GetParticleAlignmentsC)();
}
const maxon::StridedBlock<const maxon::Vector32> ParticleGroupObject::GetParticleAngularVelocitiesR() const
{
	ParticleGroupObjectLibCallRC(maxon::StridedBlock<const maxon::Vector32>(nullptr, 0), GetParticleAngularVelocitiesC)();
}


const maxon::Block<UInt32> ParticleGroupObject::GetParticleUniqueIdsW()
{
	ParticleGroupObjectLibCallR(maxon::Block<UInt32>(nullptr, 0), GetParticleUniqueIds)();
}
const maxon::Block<Vector> ParticleGroupObject::GetParticlePositionsW()
{
	ParticleGroupObjectLibCallR(maxon::Block<Vector>(nullptr, 0), GetParticlePositions)();
}
const maxon::Block<maxon::ColorA32> ParticleGroupObject::GetParticleColorsW()
{
	ParticleGroupObjectLibCallR(maxon::Block<maxon::ColorA32>(nullptr, 0), GetParticleColors)();
}
const maxon::StridedBlock<Vector32> ParticleGroupObject::GetParticleVelocitiesW()
{
	ParticleGroupObjectLibCallR(maxon::StridedBlock<Vector32>(nullptr, 0), GetParticleVelocities)();
}
const maxon::Block<Float32> ParticleGroupObject::GetParticleAgesW()
{
	ParticleGroupObjectLibCallR(maxon::Block<Float32>(nullptr, 0), GetParticleAges)();
}
const maxon::Block<Float32> ParticleGroupObject::GetParticleLifetimesW()
{
	ParticleGroupObjectLibCallR(maxon::Block<Float32>(nullptr, 0), GetParticleLifetimes)();
}
const maxon::Block<Float32> ParticleGroupObject::GetParticleRadiiW()
{
	ParticleGroupObjectLibCallR(maxon::Block<Float32>(nullptr, 0), GetParticleRadii)();
}
const maxon::Block<Float32> ParticleGroupObject::GetParticleDistancesTraversedW()
{
	ParticleGroupObjectLibCallR(maxon::Block<Float32>(nullptr, 0), GetParticleDistancesTraversed)();
}
const maxon::Block<maxon::Quaternion<Float32>> ParticleGroupObject::GetParticleAlignmentsW()
{
	ParticleGroupObjectLibCallR(maxon::Block<maxon::Quaternion<Float32>>(nullptr, 0), GetParticleAlignments)();
}
const maxon::StridedBlock<maxon::Vector32> ParticleGroupObject::GetParticleAngularVelocitiesW()
{
	ParticleGroupObjectLibCallR(maxon::StridedBlock<maxon::Vector32>(nullptr, 0), GetParticleAngularVelocities)();
}

maxon::Result<void> ParticleGroupObject::GetAttributeChannelIds(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const
{
	ParticleGroupObjectLibCallRC(maxon::OK, GetAttributeChannelIds)(idReceiver);
}

maxon::Data ParticleGroupObject::GetAttributeChannel(const maxon::InternedId& channelId) const
{
	ParticleGroupObjectLibCallRC(maxon::Data(), GetAttributeChannel)(channelId);
}

maxon::Result<void> ParticleGroupObject::GetSystemAttributeChannelIds(const maxon::ValueReceiver<const maxon::Tuple<maxon::InternedId, maxon::DataType, maxon::String>&>& idReceiver) const
{
	ParticleGroupObjectLibCallRC(maxon::OK, GetSystemAttributeChannelIds)(idReceiver);
}

Int32 ParticleGroupObject::GetParticleGroupIndex() const
{
	ParticleGroupObjectLibCallRC(-1, GetParticleGroupIndex)();
}

} // namespace cinema
