#ifndef RAMDISK_H__
#define RAMDISK_H__

#include "maxon/file_utilities.h"
#include "maxon/observerobject.h"
#include "maxon/url.h"

namespace maxon
{

class RamDiskRef;
class IoMemoryRef;

MAXON_ATTRIBUTE(UniversalDateTime, DATE_FILECREATED, "net.maxon.ramdisk.date.created");
MAXON_ATTRIBUTE(UniversalDateTime, DATE_FILEMODIFIED, "net.maxon.ramdisk.date.modified");
MAXON_ATTRIBUTE(UniversalDateTime, DATE_FILEACCESSED, "net.maxon.ramdisk.date.accessed");

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
	/// reference on this RAM disk.
	///
	/// @return												The Url of this RAM disk's root directory.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetRoot();

	//----------------------------------------------------------------------------------------
	/// Mounts the external directory source at the path given by mountPoint.
	/// This makes the Url hierarchy of source accessible (including browsing) via this RAM disk.
	/// But you have to tell the RAM disk which Urls exist under source by subsequent invocations of
	/// the returned ReadDirectoryTreeReceiver. This allows to convert non-browsable Urls such as
	/// https to browsable Urls if you can provide the list of nested Urls which shall be accessible.
	///
	/// In addition, you can also set a cache path which will be used to cache content loaded from source.
	/// This could be a Url for a local directory to cache files downloaded from a https source.
	///
	/// This mount function will return an error if a file which would be mounted already exists,
	/// use UpdateMount below in order to update the mount with new files and keep existing files.
	///
	/// @param[in] mountPoint					The path where the source directory shall be mounted. Children of the source directory
	/// 															will be children of this path.
	/// @param[in] source							The source directory.
	/// @param[in] cache							An optional directory to use for caching files downloaded from source.
	/// @return												A ReadDirectoryTreeReceiver which you have to provide with the list of files
	/// 															(within the hierarchy of source) you want to mount.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<FileUtilities::ReadDirectoryTreeReceiver> Mount(const Block<const String>& mountPoint, const Url& source, const Url& cache);

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
	/// @return												Returns the url of the cache if the file cached. If empty no cache exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Tuple<Bool, Url>> IsInCache(const Url& url);

 	static MAXON_METHOD Result<void> LoadIntoCache(const Url& url, const IoProgressDelegate& progress);

	static MAXON_METHOD Result<void> RemoveFromCache(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Creates a new RAM disk with randomly chosen unique identifier. Use GetRoot() on the returned reference to obtain the Url of the RAM disk's root folder.
	/// @return												New RAM disk.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<RamDiskRef> Create();

	//----------------------------------------------------------------------------------------
	/// Creates a new RAM disk. Use GetRoot() on the returned reference to obtain the Url of the RAM disk's root folder.
	/// @param[in] ramdiskId					Identifier to use for the RAM disk. This has to be unique. If empty, a UUID will be chosen.
	/// @return												New RAM disk.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<RamDiskRef> Create(const String& ramdiskId);

	//----------------------------------------------------------------------------------------
	/// Creates a new RAM disk. Use GetRoot() on the returned reference to obtain the Url of the RAM disk's root folder.
	/// You can pass a size limit. If a file exceeds this size, it's reset to an empty file (no error is returned).
	/// Further writes to the file will be discarded. This feature can be used for write tests similar to a null device.
	/// @param[in] ramdiskId					Identifier to use for the RAM disk. This has to be unique. If empty, a UUID will be chosen.
	/// @param[in] sizeLimit					Limit for byte size of files.
	/// @return												New RAM disk.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<RamDiskRef> Create(const String& ramdiskId, Int64 sizeLimit);

	MAXON_METHOD Result<void> ChangeMirrorPath(const Url& oldBase, const Url& newBase);

	static MAXON_METHOD Result<void> ChangeRamDiskMirrorPath(const Url& oldBase, const Url& newBase);

	//----------------------------------------------------------------------------------------
	/// FindExisting returns an existing ram disk.
	/// @param[in] ramdiskId					Id to find.
	/// @return												RamDiskRef on success. Otherwise nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD RamDiskRef FindExisting(const String& ramdiskId);

	//----------------------------------------------------------------------------------------
	/// Mounts the external directory source at the path given by mountPoint, or updates an existing mount.
	/// This does the same as Mount, but will not return an error in case of hitting existing files.
	/// This allows to update an existing mount with new files while keeping existing files.
	///
	/// @param[in] mountPoint					The path where the source directory shall be mounted. Children of the source directory
	/// 															will be children of this path.
	/// @param[in] source							The source directory.
	/// @param[in] cache							An optional directory to use for caching files downloaded from source.
	/// @return												A ReadDirectoryTreeReceiver which you have to provide with the list of files
	/// 															(within the hierarchy of source) you want to mount.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<FileUtilities::ReadDirectoryTreeReceiver> UpdateMount(const Block<const String>& mountPoint, const Url& source, const Url& cache);
};

#include "ramdisk1.hxx"
#include "ramdisk2.hxx"

} // namespace maxon

#endif // RAMDISK_H__
