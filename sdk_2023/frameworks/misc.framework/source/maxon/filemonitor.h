#ifndef FILEMONITOR_H__
#define FILEMONITOR_H__

#include "maxon/observerobject.h"
#include "maxon/url.h"

namespace maxon
{


class FileMonitorItemInterface
{
	MAXON_INTERFACE_NONVIRTUAL(FileMonitorItemInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.filemonitoritem");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD FileMonitorItemInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);
};

class FileMonitorItemRef;

class FileMonitor
{
	MAXON_INTERFACE_NONVIRTUAL(FileMonitor, MAXON_REFERENCE_NONE, "net.maxon.interface.filemonitor");

public:
	//----------------------------------------------------------------------------------------
	/// Types of CaptureDevices.
	//----------------------------------------------------------------------------------------
	enum class STATE : Int
	{
		RESCAN = 0x0000,			///< Something in the directory was modified, rescan to find modified files (and check if the directory still exists).
		MODIFIED = 0x0001,		///< The object specified by the URL was modified (write).
		DELETED = 0x0002,			///< The object specified by the URL was deleted.
		METADATA = 0x0004,		///< The attributes and or metadata of the object specified by the URL changed.
		RENAMED = 0x0008,			///< The object specified by the URL was renamed (and possibly moved).
		CREATED = 0x0010			///< The object specified by the URL was created.
	} MAXON_ENUM_FLAGS_CLASS(STATE);

	using Observer = Delegate<void(const Url& watched, const Url& updated, STATE state)>;

	static MAXON_METHOD Result<FileMonitorItemRef> WatchFile(const Url& url, Observer&& observer);
	
	//----------------------------------------------------------------------------------------
	/// WatchDirectory description.
	/// @param[in] url								Url of the directory to watch
	/// @param[in] watchSubtree				True if the function should watch all sub directories.
	/// @param[in] observer						Delegate which is triggered on file change detection.
	/// @return                       FileMonitorItemRef on success. If watchSubtree is true then FileMonitorItemRef might return nullptr if the implementation 
	///																doesn't support the watching the subtree.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<FileMonitorItemRef> WatchDirectory(const Url& url, Bool watchSubtree, Observer&& observer);

};

#include "filemonitor1.hxx"
#include "filemonitor2.hxx"

}

#endif // FILEMONITOR_H__
