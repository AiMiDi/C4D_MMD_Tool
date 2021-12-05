#ifndef RAMDISK_H__
#define RAMDISK_H__

#include "maxon/url.h"

namespace maxon
{

class RamDiskRef;

//----------------------------------------------------------------------------------------
/// A RamDisk provides a complete in-memory file system. It supports a Clone method
/// to efficiently duplicate a whole file system.
//----------------------------------------------------------------------------------------
class RamDiskInterface
{
	MAXON_INTERFACE_NONVIRTUAL(RamDiskInterface, MAXON_REFERENCE_NORMAL, "net.maxon.misc.interface.ramdisk");

public:
	//----------------------------------------------------------------------------------------
	/// Creates a new empty RAM disk. The RAM disk will use a unique identifier for its root.
	/// As long as the RAM disk is alive, it can be found with a Url with the @c ramdisk scheme
	/// and the unique identifier as authority.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @return												New RAM disk.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<RamDiskInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Returns the Url of the root directory of this RAM disk. The Url has the @c ramdisk scheme
	/// and uses the unique identifier of the RAM disk as authority. Also the returned Url contains
	/// a strong reference on this RAM disk, so it suffices to keep the Url alive to keep this RAM
	/// disk alive. Likewise all Urls which are derived from the returned Url will contain a strong
	/// reference.
	///
	/// @return												The Url of this RAM disk's root directory.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetRoot();

	//----------------------------------------------------------------------------------------
	/// Returns a clone of this RAM disk. This is a cheap operation because as much as possible
	/// is shared between the original and the clone.
	///
	/// @return												Clone of this RAM disk.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<RamDiskRef> Clone() const;
};

#include "ramdisk1.hxx"
#include "ramdisk2.hxx"

} // namespace maxon

#endif // RAMDISK_H__
