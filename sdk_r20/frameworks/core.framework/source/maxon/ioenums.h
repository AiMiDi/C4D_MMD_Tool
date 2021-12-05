#ifndef IOENUMS_H__
#define IOENUMS_H__


#include "maxon/apibase.h"
#include "maxon/fid.h"


namespace maxon
{


//----------------------------------------------------------------------------------------
/// Requested IoTime.
//----------------------------------------------------------------------------------------
enum class IOTIMEMODE
{
	CREATED,		///< Creation time of files/directories.
	MODIFIED,		///< Modification time of files/directories.
	ACCESSED		///< Last access time of files/directories.
} MAXON_ENUM_LIST(IOTIMEMODE, "net.maxon.datatype.enum.iotimemode");


//----------------------------------------------------------------------------------------
/// Flag to pass to Compare
//----------------------------------------------------------------------------------------
enum class URLCOMPARE
{
	DEFAULT			 = 1, ///< Default comparison mode. Urls are case-sensitive.
	NORMALIZE    = 2, ///< Normalizes both operands (via Normalize) before the links are compared with URLCOMPARE::DEFAULT.
	IONORMALIZE  = 3, ///< Normalizes both operands (via IoNormalize) before the links are compared with URLCOMPARE::DEFAULT.
	LEGACY			 = 4, ///< Activates legacy behavior like in C4D which does case-insensitive comparison on Windows and OS X (but not Linux).
} MAXON_ENUM_LIST(URLCOMPARE, "net.maxon.datatype.enum.urlcompare");


//----------------------------------------------------------------------------------------
/// Return value of IoDetect().
//----------------------------------------------------------------------------------------
enum class IODETECT
{
	ERRORSTATE,		///< Error code, e.g. IoHandlerInterface not found.
	NONEXISTENT,	///< Url doesn't exist.
	UNKNOWN,			///< Url is of unknown type.
	FILE,					///< Url is a file.
	LINK,					///< Url is a link.
	DIRECTORY			///< Url is a directory, you can use GetBrowseIterator to iterate through the children.
} MAXON_ENUM_LIST(IODETECT, "net.maxon.datatype.enum.iodetect");

//----------------------------------------------------------------------------------------
/// @page FileLocks
///
/// Locking under OS X and Linux
///
/// Under Unix-based operating systems unfortunately there is no defined system for mandatory file locks available. Instead
/// various implementations of advisory locks are offered, all varying and partially incompatible. If another application doesn't
/// support the exact same advisory lock concept that we're using then there is e.g. no protection against file content changes
/// while you're reading it. Also certain protocols like SMB may not support advisory locks at all.
///
/// Within the MAXON API files are protected using advisory locks. However there are a couple situations not covered due to the limits of Unix:
///
/// - An input stream that is opened with OPENSTREAMFLAGS::NONE can still be opened for writing if ALLOW_SHARED_READ_WRITE_ACCESS is specified (which it shouldn't).
/// - An output stream that is opened with OPENSTREAMFLAGS::ALLOW_SHARED_READ_WRITE_ACCESS can still be opened for reading even when the reader does not specify ALLOW_SHARED_READ_WRITE_ACCESS.
///
/// So be extra careful when you use ALLOW_SHARED_READ_WRITE_ACCESS as other code may be able to access your stream even if you never intended it to work that way.
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
/// Flags for Url::OpenInputStream(), Url::OpenOutputStream(), Url::OpenInOutputStream()
//----------------------------------------------------------------------------------------
enum class OPENSTREAMFLAGS
{
	NONE														= 0,				///< No flags set.
	WRITE_DONT_TRUNCATE							= (1 << 0), ///< Allows to write to existing files without truncation, so the existing file is kept as is.
	ALLOW_SHARED_READ_WRITE_ACCESS	= (1 << 1), ///< Allows other threads to read / write the file in parallel. The other instance needs to set this flag also. If you open a file for writing WRITE_DONT_TRUNCATE must be specified at the same time. There are certain limitations under OS X and Linux, see @ref FileLocks
	SEEK_TO_END											= (1 << 2), ///< Sets the file handle to the end of file after opening. To append to the end of a file use WRITE_DONT_TRUNCATE | SEEK_TO_END.
	FULL_DUPLEX											= (1 << 3),	///< Allows to open streams (tcp) using full duplex where data can be read and sent simultaneously.
} MAXON_ENUM_FLAGS(OPENSTREAMFLAGS, "net.maxon.datatype.enum.openstreamflags");

//----------------------------------------------------------------------------------------
/// Flags for Url::Normalize and Url::IoNormalize
//----------------------------------------------------------------------------------------
enum class NORMALIZEFLAGS
{
	NONE                         = 0, ///< Just used for internal purposes. Has no effect when used on a resolve function.

	SCHEME_BASED					= (1 << 1), ///< If given the scheme decides on his own how the path is resolved. Exclusive flag.

	CASE									= (1 << 3), ///< The path is put to the canonical form (preferred is lowercase). A given authority is untouched.
	PATH_SEGMENT					= (1 << 4), ///< Removes . and .. in case they are full path segments.
	UNICODE_DECOMPOSITION = (1 << 5), ///< Normalization for unicode decompositions. Only used by OSX file handler, ignored by other implementations and OS.
	UNDERLYING						= (1 << 7), ///< Resolve Url to underlying Url if possible. E.g., an asset Url might get resolved to a file Url.
} MAXON_ENUM_FLAGS(NORMALIZEFLAGS, "net.maxon.datatype.enum.normalizeflags");

// linux collides with this define
#undef HIDDEN

//----------------------------------------------------------------------------------------
/// Attributes of Url.
//----------------------------------------------------------------------------------------
enum class IOATTRIBUTES : UInt
{
	NONE = 0,
	READONLY = 0x00000001, ///< Url is read only.
	HIDDEN = 0x00000002,	 ///< Url is hidden.
	ARCHIVE = 0x00000004,	///< Url has archive bit set.
	LOCKED = 0x00000010,	 ///< Url is locked (only for Mac, ignored on Windows).
	OWNER_R = 0x00000100,	///< Url RWX flags (osx/linux).
	OWNER_W = 0x00000200,	///< Url RWX flags (osx/linux).
	OWNER_X = 0x00000400,	///< Url RWX flags (osx/linux).
	GROUP_R = 0x00000800,	///< Url RWX flags (osx/linux).
	GROUP_W = 0x00001000,	///< Url RWX flags (osx/linux).
	GROUP_X = 0x00002000,	///< Url RWX flags (osx/linux).
	PUBLIC_R = 0x00004000, ///< Url RWX flags (osx/linux).
	PUBLIC_W = 0x00008000, ///< Url RWX flags (osx/linux).
	PUBLIC_X = 0x00010000, ///< Url RWX flags (osx/linux).

	RW_MASK = (OWNER_R | OWNER_W | GROUP_R | GROUP_W | PUBLIC_R | PUBLIC_W), ///< Url RW mask (osx/linux).

	RWX_MASK = (OWNER_R | OWNER_W | OWNER_X | GROUP_R | GROUP_W | GROUP_X | PUBLIC_R | PUBLIC_W | PUBLIC_X), ///< Url RWX mask (osx/linux).

	MASK_ALL = 0xffffffff ///< Masks all attributes, e.g. IoSetAttributes(IoGetAttributes(),IOATTRIBUTES::MASK_ALL).
} MAXON_ENUM_FLAGS(IOATTRIBUTES, "net.maxon.datatype.enum.ioattributes");

//----------------------------------------------------------------------------------------
/// Converts an IOATTRIBUTES value between different operating systems.
/// If there is no RWX bit set the R attribute will be set in Linux and OSX. The W bit is set if the read-only bit is not set.
/// On Windows the read-only bit is set if at least one RWX bit is set and no W bit is set.
/// @param[in,out] attributes			Attributes to convert.
//----------------------------------------------------------------------------------------
inline void ConvertIoAttributes(IOATTRIBUTES& attributes)
{
#if defined MAXON_TARGET_LINUX || defined MAXON_TARGET_MACOS
	if (!(attributes & IOATTRIBUTES::RWX_MASK))
	{
		// no flags at all
		IOATTRIBUTES attr = attributes;
		attributes = IOATTRIBUTES::OWNER_R | IOATTRIBUTES::GROUP_R | IOATTRIBUTES::PUBLIC_R;
		if (!(attr & IOATTRIBUTES::READONLY))
			attributes |= IOATTRIBUTES::OWNER_W | IOATTRIBUTES::GROUP_W | IOATTRIBUTES::PUBLIC_W;
	}
#else
	if (!(attributes & (IOATTRIBUTES::OWNER_W | IOATTRIBUTES::GROUP_W | IOATTRIBUTES::PUBLIC_W)))
	{
		attributes |= IOATTRIBUTES::READONLY;
	}
#endif
}

/// Flags used by Url::IoShowInOS and IoConnection::IoShowInOS
enum class IOSHOWINOSFLAGS
{
	NONE							= 0,			///< No flags.
	SHOW_IN_EXPLORER	= 1 << 0,	///< Show the url in the windows explorer or osx finder.
	OPEN_IN_EXPLORER	= 1 << 1, ///< Open the file using the connected app in the operating system.
} MAXON_ENUM_FLAGS(IOSHOWINOSFLAGS, "net.maxon.datatype.enum.ioshowinosflags");

namespace URLFLAGS
{
	MAXON_ATTRIBUTE(Bool, DUMMY, "net.maxon.dummy");						///< dummy value to trigger source processor to create restriction class
}

#include "ioenums1.hxx"
#include "ioenums2.hxx"

}


#endif // IOENUMS_H__
