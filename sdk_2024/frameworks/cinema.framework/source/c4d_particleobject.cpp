#include "c4d_particleobject.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

Int32 ParticleObject::GetParticleCount()
{
	return C4DOS_Bo->PrGetCount(this);
}

Bool ParticleObject::IsMatrixAvailable()
{
	return C4DOS_Bo->PrIsMatrixAvailable(this);
}

Float ParticleObject::GetLifetime()
{
	return C4DOS_Bo->PrGetLifetime(this);
}

ParticleDetails* ParticleObject::GetParticleDetails(const BaseDocument* doc)
{
	return C4DOS_Bo->PrGetParticleDetails(doc, this);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
