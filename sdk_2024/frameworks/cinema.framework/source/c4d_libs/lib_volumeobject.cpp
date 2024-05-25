#include "lib_volumeobject.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

VolumeObjectLib* lib_volumeobject = nullptr;

static VolumeObjectLib* CheckVolumeObjectLib(Int32 offset)
{
	return CheckLib<VolumeObjectLib>(LIBRARY_VOLUMEOBJECT, offset, lib_volumeobject);
}


#define VolumeObjectLibCall(b) 		VolumeObjectLib* lib = CheckVolumeObjectLib(LIBOFFSET(VolumeObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iVolumeObject*>(this)->*lib->b)

#define VolumeObjectLibCallR(a, b) VolumeObjectLib* lib = CheckVolumeObjectLib(LIBOFFSET(VolumeObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iVolumeObject*>(this)->*lib->b)

#define VolumeObjectLibCallRC(a, b) VolumeObjectLib* lib = CheckVolumeObjectLib(LIBOFFSET(VolumeObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iVolumeObject*>(this)->*lib->b)

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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
