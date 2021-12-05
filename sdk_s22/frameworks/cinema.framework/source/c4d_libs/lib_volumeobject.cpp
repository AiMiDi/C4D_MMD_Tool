#include "lib_volumeobject.h"

VolumeObjectLib* lib_volumeobject = nullptr;

static VolumeObjectLib* CheckVolumeObjectLib(Int32 offset)
{
	return (VolumeObjectLib*)CheckLib(LIBRARY_VOLUMEOBJECT, offset, (C4DLibrary**)&lib_volumeobject);
}


#define VolumeObjectLibCall(b) 		VolumeObjectLib* lib = CheckVolumeObjectLib(LIBOFFSET(VolumeObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(((iVolumeObject*)this)->*lib->b)

#define VolumeObjectLibCallR(a, b) VolumeObjectLib* lib = CheckVolumeObjectLib(LIBOFFSET(VolumeObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iVolumeObject*)this)->*lib->b)

const maxon::VolumeInterface* VolumeObject::GetVolume() const
{
	VolumeObjectLibCallR(nullptr, GetVolume)();
}

void VolumeObject::SetVolume(const maxon::VolumeInterface* volumeObj)
{
	VolumeObjectLibCall(SetVolume)(volumeObj);
}

GRIDTYPE VolumeObject::GetGridType() const
{
	VolumeObjectLibCallR(GRIDTYPE::NONE, GetGridType)();
}

GRIDCLASS VolumeObject::GetGridClass() const
{
	VolumeObjectLibCallR(GRIDCLASS::NONE, GetGridClass)();
}
