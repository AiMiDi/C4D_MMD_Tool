#ifndef IOARCHIVEHANDLER_H__
#define IOARCHIVEHANDLER_H__

#include "maxon/datetime.h"
#include "maxon/ioenums.h"
#include "maxon/iostreams.h"
#include "maxon/string.h"
#include "maxon/thread.h"
#include "maxon/url.h"

namespace maxon
{

class UniversalDateTime;

/// @addtogroup IO
/// @{


//----------------------------------------------------------------------------------------
/// Compression methods for files in archives.
//----------------------------------------------------------------------------------------
enum class IOARCHIVESTOREMETHOD
{
	STORE,		///< Simply store the file without compression.
	DEFLATE		///< Deflates the file in the archive.
} MAXON_ENUM_LIST(IOARCHIVESTOREMETHOD);


//----------------------------------------------------------------------------------------
/// Extract Flags used in ReadArchiveInterface::Extract() and ReadArchiveInterface::ExtractSingleFile().
//----------------------------------------------------------------------------------------
enum class IOARCHIVEEXTRACTFLAGS
{
	NONE										= 0,				///< No flags.
	OVERWRITE_EXISTING_FILE	= (1 << 0),	///< Overwrites the file silently if it already exists in the directory.
} MAXON_ENUM_FLAGS(IOARCHIVEEXTRACTFLAGS);


// TODO: (Tilo) WriteArchiveInterface should use Url instead of Strings with '/' delimiter
// TODO: (Tilo) Default compression level should be described (if it wasn't manually modified), maybe mention that high levels perform slow for ZIP

/// Callback used by ReadArchiveRef::Extract.
/// This callback will be called before each file is extracted.
/// inputName is the name that is stored within the archive.
/// outputName is the (modifyable) path at which the file will be created.
/// fileAttributes are the (modifyable) attributes that will be set.
/// The return value determines whether the file will be extracted or not.
using ExtractCallback = Delegate<Result<Bool>(const String& inputName, Url& outputName, IOATTRIBUTES& fileAttributes)>;

//----------------------------------------------------------------------------------------
/// Interface class to read archives.
///
//----------------------------------------------------------------------------------------
class ReadArchiveInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ReadArchiveInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.readarchive");

public:
	//----------------------------------------------------------------------------------------
	/// Opens an archive for reading.
	/// @param[in] inputFile					The path of the archive.
	/// @param[in] password						An optional password.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Open(const Url& inputFile, const String& password = String());

	//----------------------------------------------------------------------------------------
	/// Closes the archive.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	//----------------------------------------------------------------------------------------
	/// Extracts a single file from an archive. Using extractCallback you can modify attributes.
	/// @param[in] archiveFile				The file to extract from the archive. Note that this must match exactly the name within the archive.
	/// @param[in] outputDirectory		The path the archive shall be extracted to. If the directory does not exist if will be created.
	/// @param[in] thread							An optional thread to check for IsCancelled. Can be nullptr.
	/// @param[in] flags							Control the behavior of the function see IOARCHIVEEXTRACTFLAGS.
	/// @param[in] extractCallback		A callback that allows you to control the extraction process.
	/// @return												Returns the name of the extracted file on success. If the file was not found in the archive an empty Url will be returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);

	//----------------------------------------------------------------------------------------
	/// Extracts all files from an archive. Using extractCallback you can filter which files shall be extracted and modify attributes.
	/// @param[in] outputDirectory		The path the archive shall be extracted to. If the directory does not exist if will be created.
	/// @param[in] thread							An optional thread to check for IsCancelled. Can be nullptr.
	/// @param[in] flags							Control the behavior of the function see IOARCHIVEEXTRACTFLAGS.
	/// @param[in] extractCallback		A callback that allows you to control the extraction process.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback);
};

//----------------------------------------------------------------------------------------
/// Interface class to write archives.
///
//----------------------------------------------------------------------------------------
class WriteArchiveInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(WriteArchiveInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.writearchive");

public:
	//----------------------------------------------------------------------------------------
	/// Opens an archive for writing.
	/// @param[in] inputFile					The path of the archive.
	/// @param[in] append							True if files shall be added to an existing archive.
	/// @param[in] password						An optional password.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Open(const Url& inputFile, Bool append, const String& password = String());

	//----------------------------------------------------------------------------------------
	/// Closes the archive and finishes all write operations. After that call the file is closed.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	//----------------------------------------------------------------------------------------
	/// Sets the compression level for files in the archive.
	/// This function can be called before a new CreateFile() operation to change the compression level. One call at the beginning is enough.
	/// @param[in] compressionLevel		Compression level depending on the compression algorithm [ zip: 0 (low) ... 9 (high) ].
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCompressionLevel(Int compressionLevel);

	//----------------------------------------------------------------------------------------
	/// Returns the current compression level.
	/// @return												The current compression level.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCompressionLevel() const;

	//----------------------------------------------------------------------------------------
	/// Creates a directory within an archive file. The name should contain '/' as directory separator.
	/// @param[in] name								The name of the directory. use '/' to separate subdirectories.
	/// @param[in] dateTime						The file time/date of the directory.
	/// @param[in] fileAttributes			OS file attributes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes);

	//----------------------------------------------------------------------------------------
	/// Creates a file within an archive file. The name should contain '/' as directory separator.
	/// Use WriteFile() to write the data into the file. CloseFile() needs to be called to close the file.
	/// A file can be directly created within the archive without the need to create the parent directories first.
	/// @param[in] name								The name of the directory. use '/' to separate subdirectories.
	/// @param[in] dateTime						The file time/date of the directory.
	/// @param[in] method							Gives the method how the file is stores in the archive.
	/// @param[in] fileAttributes			OS file attributes.
	/// @param[in] cryptCrc						CRC for crypting.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc);

	//----------------------------------------------------------------------------------------
	/// Writes data into the given file created by calling CreateFile(). Multiple calls to WriteFile() are possible for one single file.
	/// @param[in] data								Buffer with file data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteFile(const Block<const Byte>& data);

	//----------------------------------------------------------------------------------------
	/// Closes the file opened with CreateFile().
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CloseFile();

	//----------------------------------------------------------------------------------------
	/// Copies a file into the archive file. The default parameter for the fileAttributes takes the bits from the original file.
	/// CopyFile(fn, str, IOATTRIBUTES::OWNER_X, IOATTRIBUTES::OWNER_X | IOATTRIBUTES::GROUP_X | IOATTRIBUTES::PUBLIC_X); will take the original file bits but forces to set the unix X bits ontop of this only for the owner.
	/// @param[in] fn									The source file name.
	/// @param[in] str								The virtual filename within the archive.
	/// @param[in] fileAttributes			Bits for the file attributes. Only corresponding bits in the mask are set/cleared.
	/// @param[in] fileAttributesMask	This mask defines, which bits are taken from fileAttributes (mask bit==1) and which are taken from the original file (mask bit==0).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes = IOATTRIBUTES::NONE, IOATTRIBUTES fileAttributesMask = IOATTRIBUTES::NONE);
};


#include "ioarchivehandler1.hxx"


MAXON_REGISTRY(Class<ReadArchiveRef>, ReadArchiveClasses, "net.maxon.registry.readarchiveclasses");
namespace ReadArchiveClasses
{
	MAXON_DECLARATION(ReadArchiveClasses::EntryType, Zip, "net.maxon.readarchiveclass.zip");
}

MAXON_REGISTRY(Class<WriteArchiveRef>, WriteArchiveClasses, "net.maxon.registry.writearchiveclasses");
namespace WriteArchiveClasses
{
	MAXON_DECLARATION(WriteArchiveClasses::EntryType, Zip, "net.maxon.writearchiveclass.zip");
}


#include "ioarchivehandler2.hxx"

/// @}

}

#endif // IOARCHIVEHANDLER_H__
