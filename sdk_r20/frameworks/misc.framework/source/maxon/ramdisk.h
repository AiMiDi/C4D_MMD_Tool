#ifndef RAMDISK_H__
#define RAMDISK_H__

#include "maxon/url.h"

namespace maxon
{

class RamDiskRef;

class RamDiskInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RamDiskInterface, MAXON_REFERENCE_NORMAL, "net.maxon.misc.interface.ramdisk");

public:
	static MAXON_METHOD Result<RamDiskInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	MAXON_METHOD Result<Url> GetRoot();

	MAXON_METHOD Result<RamDiskRef> Clone() const;
};

#include "ramdisk1.hxx"
#include "ramdisk2.hxx"

} // namespace maxon

#endif // RAMDISK_H__
