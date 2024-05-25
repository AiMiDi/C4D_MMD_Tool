#ifndef RAMDISK_H__
#define RAMDISK_H__

#include "maxon/file_utilities.h"
#include "maxon/observerobject.h"
#include "maxon/url.h"

namespace maxon
{

class RamDiskRef;
class IoMemoryRef;

//----------------------------------------------------------------------------------------
/// A RamDisk provides a complete in-memory file system. It supports a Clone method
/// to efficiently duplicate a whole file system.
//----------------------------------------------------------------------------------------
class RamDiskInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(RamDiskInterface, MAXON_REFERENCE_NORMAL, "net.maxon.misc.interface.ramdisk");

public:
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

	MAXON_METHOD Result<FileUtilities::ReadDirectoryTreeReceiver> Mount(const Block<const String>& mountPoint, const Url& source, const Url& mirror);

	using ContentCreator = Delegate<Result<IoMemoryRef>()>;

	//----------------------------------------------------------------------------------------
	/// Creates a Url for a file whose content is created lazily by the creator Delegate.
	/// @param[in] path								The path of the file to be created. The file mustn't exist yet.
	/// @param[in] creator						The delegate which will create the file's content on first access.
	/// @return												The Url for the file.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> CreateLazyFile(const Block<const String>& path, ContentCreator&& creator);

	using PermissionChecker = Delegate<Result<void>(const Url& url)>;

	//----------------------------------------------------------------------------------------
	/// Sets the permission checker for this RAM disk.
	/// @param[in] permissions				Delegate which gets called to check for valid permissions whenever a stream is opened.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetPermissions(PermissionChecker&& permissions);

 	MAXON_OBSERVABLE(void, ObservableLoadIntoCacheChange, (const RamDiskRef& ramDisk, Bool finished), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// IsInCache allows to detect if the url is cached.
	/// @param[in] url								Url to detect.
	/// @return                       returns the url of the cache if the file cached. If empty no cache exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<Bool, Url>> IsInCache(const Url& url);

 	static MAXON_METHOD Result<void> LoadIntoCache(const Url& url, const IoProgressDelegate& progress);

	static MAXON_METHOD Result<void> RemoveFromCache(const Url& url);

	static MAXON_METHOD Result<RamDiskRef> Create();

	static MAXON_METHOD Result<RamDiskRef> Create(const String& ramdiskId);

	MAXON_METHOD Result<void> ChangeMirrorPath(const Url& oldBase, const Url& newBase);

	static MAXON_METHOD Result<void> ChangeRamDiskMirrorPath(const Url& oldBase, const Url& newBase);

	//----------------------------------------------------------------------------------------
	/// FindExisting returns an existing ram disk.
	/// @param[in] ramdiskId					Id to find
	/// @return                       RamDiskRef on success. Otherwise nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD RamDiskRef FindExisting(const String& ramdiskId);
};

#include "ramdisk1.hxx"
#include "ramdisk2.hxx"

} // namespace maxon

#endif // RAMDISK_H__
