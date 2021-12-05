#include "lib_volumetag.h"

VolumeTagLib* lib_volumetag = nullptr;

static VolumeTagLib* CheckVolumeTagLib(Int32 offset)
{
	return (VolumeTagLib*)CheckLib(LIBRARY_VOLUMETAG, offset, (C4DLibrary**)&lib_volumetag);
}


#define VolumeTagLibCall(b) 		VolumeTagLib* lib = CheckVolumeTagLib(LIBOFFSET(VolumeTagLib, b)); \
															if (!lib || !lib->b) return; \
															(((iVolumeTag*)this)->*lib->b)

#define VolumeTagLibCallR(a, b) VolumeTagLib* lib = CheckVolumeTagLib(LIBOFFSET(VolumeTagLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iVolumeTag*)this)->*lib->b)


const BaseLinkArray& VolumeTag::GetVolumeObjectList() const
{
	VolumeTagLibCallR(maxon::GetZeroRef<BaseLinkArray>(), GetVolumeObjectList)();
}

const BaseObject* VolumeTag::GetVolumeObject(VOLUMECHANNEL channel)
{
	VolumeTagLibCallR(nullptr, GetVolumeObject)(channel);
}

maxon::VolumeInterface* VolumeTag::GetVolume(VOLUMECHANNEL channel)
{
	VolumeTagLibCallR(nullptr, GetVolume)(channel);
}
