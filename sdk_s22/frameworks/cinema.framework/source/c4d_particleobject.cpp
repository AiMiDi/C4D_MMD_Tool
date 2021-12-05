#include "c4d_particleobject.h"

Int32 ParticleObject::GetParticleCount(void)
{
	return C4DOS.Bo->PrGetCount(this);
}

Bool ParticleObject::IsMatrixAvailable(void)
{
	return C4DOS.Bo->PrIsMatrixAvailable(this);
}

Float ParticleObject::GetLifetime(void)
{
	return C4DOS.Bo->PrGetLifetime(this);
}

ParticleDetails* ParticleObject::GetParticleDetails(BaseDocument* doc)
{
	return C4DOS.Bo->PrGetParticleDetails(doc, this);
}

