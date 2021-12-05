#ifndef IOCONNECTION_H__
#define IOCONNECTION_H__

#include "maxon/iostreams.h"
#include "maxon/datatype.h"
#include "maxon/iobrowse.h"
#include "maxon/ioenums.h"
#include "maxon/url.h"
#include "maxon/datadictionaryobject.h"


namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// Static interface to access Url resolve functionality.
//----------------------------------------------------------------------------------------
class ResolveInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ResolveInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.resolve");

public:
	//----------------------------------------------------------------------------------------
	/// Remove dot segments from a URI path according to RFC3986 Section 5.2.4
	/// @param[in] url								Url as input.
	/// @return												Resolved Url object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> RemoveDotSegments(const Url& url);
};

//----------------------------------------------------------------------------------------
/// The connection interface a given Url.
/// This connection needs to be implemented for each protocol. @see UrlScheme.
//----------------------------------------------------------------------------------------
class IoConnectionInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(IoConnectionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.ioconnection");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the corresponding Url connected to the IoConnectionRef.
	/// @return												Returns the name of the connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Returns a IoBrowseInterface class to browse through all children of an Url.
	/// The return value needs to be checked against nullptr.
	/// @param[in] flags							See GETBROWSEITERATORFLAGS.
	/// @return												IoBrowseInterface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<IoBrowseRef> GetBrowseIterator(GETBROWSEITERATORFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Opens an InputStreamRef for the given connection. With this kind of streams it's only possible to read from it.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												A pointer to the input stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Opens an OutputStreamRef for the given connection. With this kind of streams it's only possible to write to it.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												Pointer to the output stream. the pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Opens an InOutputStreamRef which can read/write for the given connection.
	/// @param[in] flags							See OPENSTREAMFLAGS for details.
	/// @return												Pointer to the inoutputstream. The pointer must be freed by ObjectInterface::Free(). The return value needs to be checked against nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags = OPENSTREAMFLAGS::NONE);

	//----------------------------------------------------------------------------------------
	/// Returns length of the content.
	/// @return												The effective size in bytes of the IoConnectionInterface (e.g. filesize).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int64> GetContentLength();

	//----------------------------------------------------------------------------------------
	/// Detects the type of the Url.
	/// This allows to check if a file or directory exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IODETECT IoDetect() const;

	//----------------------------------------------------------------------------------------
	/// Returns the file attributes.
	/// @return												IOATTRIBUTES of the files.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const;

	//----------------------------------------------------------------------------------------
	/// Modify the file attributes.
	/// @param[in] flags							Flags to set/clear.
	/// @param[in] mask								Mask with all flags to be changed.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask);

	//----------------------------------------------------------------------------------------
	/// Returns the DateTime of the current file. the time is in local time.
	/// @param[in] mode								IOTIMEMODE of the requested time.
	/// @return												Returns the DateTime or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;

	//----------------------------------------------------------------------------------------
	/// Modifies the DateTime of the current file. the time is in local time.
	/// @param[in] mode								IOTIMEMODE of the requested time.
	/// @param[in] dateTime						New datetime for the file.
	/// @return												True is the operation was successful.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime);

	//----------------------------------------------------------------------------------------
	/// Deletes the file physically on the medium.
	/// @param[in] force							True tries to deletes the file/directory even if the file/directory has read only flags set.
	/// @return												True if the file/directory could be removed successfully.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoDelete(Bool force);

	//----------------------------------------------------------------------------------------
	/// Creates a new directory. The function returns false if the directory already exists.
	/// @param[in] createParents			Check if parent directory exists and if not create them recursively.
	/// @param[out] createdDirs				An array that will contain all newly created subdirectories in the order in which they were created. If this parameter is nullptr it will be ignored.
	/// @return												True if the directory could be created successfully.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs = nullptr);

	//----------------------------------------------------------------------------------------
	/// Copies a file to a different location, the path must exist otherwise the function returns an error.
	/// @param[in] destName						Destination name for the copy operation.
	/// @param[in] overwrite					True to allow overwriting destName file if it was already there.
	/// @param[in] removeReadOnly			True to remove the read only flag on the newly created copy.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly);

	//----------------------------------------------------------------------------------------
	/// Moves a file or directory (including hierarchy) to a different location, the path must
	/// exist otherwise the function returns an error. If the destName file or directory does
	/// already exist the function returns with an error.
	/// Moving a file or directory on the same partition will perform without a temporary copy.
	/// @param[in] destName						Destination name for the move operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoMove(const Url& destName);

	//----------------------------------------------------------------------------------------
	/// Renames a file or directory. The newName must not be the name of an existing file
	/// or directory.
	/// @param[in] newName						Destination name for the move operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoRename(const Url& newName);

	//----------------------------------------------------------------------------------------
	/// Calculates the free space on a volume. The Url can point to a volume or directory.
	/// @param[out] availableBytes		The number of available bytes on the volume.
	/// @param[out] totalBytes				The total size of the volume in bytes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const;

	//----------------------------------------------------------------------------------------
	/// Opens or shows the file in the systems explorer (desktop/finder).
	/// Under windows that would be on the desktop/explorer. Under OSX this would be the Finder.
	/// Depending on the url scheme this could also open another browser.
	/// @param[in] flags							Flags to define how to show/open that file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IoShowInOS(IOSHOWINOSFLAGS flags) const;
};

// include autogenerated headerfile here
#include "ioconnection1.hxx"

MAXON_DECLARATION(Class<IoConnectionRef>, IoConnectionBaseClass, "net.maxon.class.ioconnectionbase");
MAXON_DECLARATION(Class<IoConnectionRef>, IoConnectionFileClass, "net.maxon.class.ioconnectionfile");

// include autogenerated headerfile here
#include "ioconnection2.hxx"

/// @}

} // namespace maxon


#endif // IOCONNECTION_H__
