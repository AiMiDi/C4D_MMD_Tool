#include "lib_volumeobject.h"

namespace cinema
{

VolumeObjectLib* lib_volumeobject = nullptr;

static VolumeObjectLib* CheckVolumeObjectLib(Int32 offset)
{
	return CheckLib<VolumeObjectLib>(LIBRARY_VOLUMEOBJECT, offset, lib_volumeobject);
}


#define VolumeObjectLibCall(b) 		cinema::VolumeObjectLib* lib = cinema::CheckVolumeObjectLib(LIBOFFSET(cinema::VolumeObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iVolumeObject*>(this)->*lib->b)

#define VolumeObjectLibCallR(a, b) cinema::VolumeObjectLib* lib = cinema::CheckVolumeObjectLib(LIBOFFSET(cinema::VolumeObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iVolumeObject*>(this)->*lib->b)

#define VolumeObjectLibCallRC(a, b) cinema::VolumeObjectLib* lib = cinema::CheckVolumeObjectLib(LIBOFFSET(cinema::VolumeObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iVolumeObject*>(this)->*lib->b)

const maxon::VolumeInterface* VolumeObject::GetVolume() const
{
	VolumeObjectLibCallRC(nullptr, GetVolume)();
}

void VolumeObject::SetVolume(const maxon::VolumeInterface* volumeObj)
{
	VolumeObjectLibCall(SetVolume)(volumeObj);
}

GRIDTYPE VolumeObject::GetGridType() const
{
	VolumeObjectLibCallRC(GRIDTYPE::NONE, GetGridType)();
}

GRIDCLASS VolumeObject::GetGridClass() const
{
	VolumeObjectLibCallRC(GRIDCLASS::NONE, GetGridClass)();
}

} // namespace cinema
