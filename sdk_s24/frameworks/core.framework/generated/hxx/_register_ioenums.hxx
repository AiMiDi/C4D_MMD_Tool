#if 1
namespace maxon
{
	namespace enum20
	{
		enum class IOTIMEMODE
		{
			CREATED,		///< Creation time of files/directories.
			MODIFIED,		///< Modification time of files/directories.
			ACCESSED		///< Last access time of files/directories.
		} ;
		static const maxon::UInt64 IOTIMEMODE_values[] = {maxon::UInt64(enum20::IOTIMEMODE::CREATED), maxon::UInt64(enum20::IOTIMEMODE::MODIFIED), maxon::UInt64(enum20::IOTIMEMODE::ACCESSED)};
		static const maxon::EnumInfo IOTIMEMODE_info{"IOTIMEMODE", SIZEOF(IOTIMEMODE), false, "CREATED\0MODIFIED\0ACCESSED\0", IOTIMEMODE_values, std::extent<decltype(IOTIMEMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOTIMEMODE20(){ return enum20::IOTIMEMODE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IOTIMEMODE, , "net.maxon.datatype.enum.iotimemode");
	namespace enum32
	{
		enum class URLCOMPARE
		{
			DEFAULT			 = 1, ///< Default comparison mode. Urls are case-sensitive.
			NORMALIZE    = 2, ///< Normalizes both operands (via Normalize) before the links are compared with URLCOMPARE::DEFAULT.
			IONORMALIZE  = 3, ///< Normalizes both operands (via IoNormalize) before the links are compared with URLCOMPARE::DEFAULT.
			LEGACY			 = 4, ///< Activates legacy behavior like in C4D which does case-insensitive comparison on Windows and OS X (but not Linux).
		} ;
		static const maxon::UInt64 URLCOMPARE_values[] = {maxon::UInt64(enum32::URLCOMPARE::DEFAULT), maxon::UInt64(enum32::URLCOMPARE::NORMALIZE), maxon::UInt64(enum32::URLCOMPARE::IONORMALIZE), maxon::UInt64(enum32::URLCOMPARE::LEGACY)};
		static const maxon::EnumInfo URLCOMPARE_info{"URLCOMPARE", SIZEOF(URLCOMPARE), false, "DEFAULT\0NORMALIZE\0IONORMALIZE\0LEGACY\0", URLCOMPARE_values, std::extent<decltype(URLCOMPARE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_URLCOMPARE32(){ return enum32::URLCOMPARE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_URLCOMPARE, , "net.maxon.datatype.enum.urlcompare");
	namespace enum46
	{
		enum class IODETECT
		{
			ERRORSTATE,		///< Error code, e.g. IoHandlerInterface not found.
			NONEXISTENT,	///< Url doesn't exist.
			UNKNOWN,			///< Url is of unknown type.
			FILE,					///< Url is a file.
			LINK,					///< Url is a link.
			DIRECTORY			///< Url is a directory, you can use GetBrowseIterator to iterate through the children.
		} ;
		static const maxon::UInt64 IODETECT_values[] = {maxon::UInt64(enum46::IODETECT::ERRORSTATE), maxon::UInt64(enum46::IODETECT::NONEXISTENT), maxon::UInt64(enum46::IODETECT::UNKNOWN), maxon::UInt64(enum46::IODETECT::FILE), maxon::UInt64(enum46::IODETECT::LINK), maxon::UInt64(enum46::IODETECT::DIRECTORY)};
		static const maxon::EnumInfo IODETECT_info{"IODETECT", SIZEOF(IODETECT), false, "ERRORSTATE\0NONEXISTENT\0UNKNOWN\0FILE\0LINK\0DIRECTORY\0", IODETECT_values, std::extent<decltype(IODETECT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IODETECT46(){ return enum46::IODETECT_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IODETECT, , "net.maxon.datatype.enum.iodetect");
	namespace enum77
	{
		enum class OPENSTREAMFLAGS
		{
			NONE														= 0,				///< No flags set.
			WRITE_DONT_TRUNCATE							= (1 << 0), ///< Allows to write to existing files without truncation, so the existing file is kept as is.
			ALLOW_SHARED_READ_WRITE_ACCESS	= (1 << 1), ///< Allows other threads to read / write the file in parallel. The other instance needs to set this flag also. If you open a file for writing WRITE_DONT_TRUNCATE must be specified at the same time. There are certain limitations under OS X and Linux, see @ref FileLocks
			SEEK_TO_END											= (1 << 2), ///< Sets the file handle to the end of file after opening. To append to the end of a file use WRITE_DONT_TRUNCATE | SEEK_TO_END.
			FULL_DUPLEX											= (1 << 3),	///< Allows to open streams (tcp) using full duplex where data can be read and sent simultaneously.
			ASK_FOR_REMOVE_WRITE_PROTECTION	= (1 << 4), ///< If the file that should be written is write protected the system will ask for checkout/remove flags
		} ;
		static const maxon::UInt64 OPENSTREAMFLAGS_values[] = {maxon::UInt64(enum77::OPENSTREAMFLAGS::NONE), maxon::UInt64(enum77::OPENSTREAMFLAGS::WRITE_DONT_TRUNCATE), maxon::UInt64(enum77::OPENSTREAMFLAGS::ALLOW_SHARED_READ_WRITE_ACCESS), maxon::UInt64(enum77::OPENSTREAMFLAGS::SEEK_TO_END), maxon::UInt64(enum77::OPENSTREAMFLAGS::FULL_DUPLEX), maxon::UInt64(enum77::OPENSTREAMFLAGS::ASK_FOR_REMOVE_WRITE_PROTECTION)};
		static const maxon::EnumInfo OPENSTREAMFLAGS_info{"OPENSTREAMFLAGS", SIZEOF(OPENSTREAMFLAGS), true, "NONE\0WRITE_DONT_TRUNCATE\0ALLOW_SHARED_READ_WRITE_ACCESS\0SEEK_TO_END\0FULL_DUPLEX\0ASK_FOR_REMOVE_WRITE_PROTECTION\0", OPENSTREAMFLAGS_values, std::extent<decltype(OPENSTREAMFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OPENSTREAMFLAGS77(){ return enum77::OPENSTREAMFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_OPENSTREAMFLAGS, , "net.maxon.datatype.enum.openstreamflags");
	namespace enum92
	{
		enum class NORMALIZEFLAGS
		{
			NONE                         = 0, ///< Just used for internal purposes. Has no effect when used on a resolve function.
		
			SCHEME_BASED					= (1 << 1), ///< If given the scheme decides on his own how the path is resolved. Exclusive flag.
		
			CASE									= (1 << 3), ///< The path is put to the canonical form (preferred is lowercase). A given authority is untouched.
			PATH_SEGMENT					= (1 << 4), ///< Removes . and .. in case they are full path segments.
			UNICODE_DECOMPOSITION = (1 << 5), ///< Normalization for unicode decompositions. Only used by OSX file handler, ignored by other implementations and OS.
			UNDERLYING						= (1 << 7), ///< Resolve Url to underlying Url if possible. E.g., an asset Url might get resolved to a file Url.
		} ;
		static const maxon::UInt64 NORMALIZEFLAGS_values[] = {maxon::UInt64(enum92::NORMALIZEFLAGS::NONE), maxon::UInt64(enum92::NORMALIZEFLAGS::SCHEME_BASED), maxon::UInt64(enum92::NORMALIZEFLAGS::CASE), maxon::UInt64(enum92::NORMALIZEFLAGS::PATH_SEGMENT), maxon::UInt64(enum92::NORMALIZEFLAGS::UNICODE_DECOMPOSITION), maxon::UInt64(enum92::NORMALIZEFLAGS::UNDERLYING)};
		static const maxon::EnumInfo NORMALIZEFLAGS_info{"NORMALIZEFLAGS", SIZEOF(NORMALIZEFLAGS), true, "NONE\0SCHEME_BASED\0CASE\0PATH_SEGMENT\0UNICODE_DECOMPOSITION\0UNDERLYING\0", NORMALIZEFLAGS_values, std::extent<decltype(NORMALIZEFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NORMALIZEFLAGS92(){ return enum92::NORMALIZEFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_NORMALIZEFLAGS, , "net.maxon.datatype.enum.normalizeflags");
	namespace enum122
	{
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
		} ;
		static const maxon::UInt64 IOATTRIBUTES_values[] = {maxon::UInt64(enum122::IOATTRIBUTES::NONE), maxon::UInt64(enum122::IOATTRIBUTES::READONLY), maxon::UInt64(enum122::IOATTRIBUTES::HIDDEN), maxon::UInt64(enum122::IOATTRIBUTES::ARCHIVE), maxon::UInt64(enum122::IOATTRIBUTES::LOCKED), maxon::UInt64(enum122::IOATTRIBUTES::OWNER_R), maxon::UInt64(enum122::IOATTRIBUTES::OWNER_W), maxon::UInt64(enum122::IOATTRIBUTES::OWNER_X), maxon::UInt64(enum122::IOATTRIBUTES::GROUP_R), maxon::UInt64(enum122::IOATTRIBUTES::GROUP_W), maxon::UInt64(enum122::IOATTRIBUTES::GROUP_X), maxon::UInt64(enum122::IOATTRIBUTES::PUBLIC_R), maxon::UInt64(enum122::IOATTRIBUTES::PUBLIC_W), maxon::UInt64(enum122::IOATTRIBUTES::PUBLIC_X), maxon::UInt64(enum122::IOATTRIBUTES::RW_MASK), maxon::UInt64(enum122::IOATTRIBUTES::RWX_MASK), maxon::UInt64(enum122::IOATTRIBUTES::MASK_ALL)};
		static const maxon::EnumInfo IOATTRIBUTES_info{"IOATTRIBUTES", SIZEOF(IOATTRIBUTES), true, "NONE\0READONLY\0HIDDEN\0ARCHIVE\0LOCKED\0OWNER_R\0OWNER_W\0OWNER_X\0GROUP_R\0GROUP_W\0GROUP_X\0PUBLIC_R\0PUBLIC_W\0PUBLIC_X\0RW_MASK\0RWX_MASK\0MASK_ALL\0", IOATTRIBUTES_values, std::extent<decltype(IOATTRIBUTES_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOATTRIBUTES122(){ return enum122::IOATTRIBUTES_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IOATTRIBUTES, , "net.maxon.datatype.enum.ioattributes");
	namespace enum155
	{
		enum class IOSHOWINOSFLAGS
		{
			NONE							= 0,			///< No flags.
			SHOW_IN_EXPLORER	= 1 << 0,	///< Show the url in the windows explorer or osx finder.
			OPEN_IN_EXPLORER	= 1 << 1, ///< Open the file using the connected app in the operating system.
		} ;
		static const maxon::UInt64 IOSHOWINOSFLAGS_values[] = {maxon::UInt64(enum155::IOSHOWINOSFLAGS::NONE), maxon::UInt64(enum155::IOSHOWINOSFLAGS::SHOW_IN_EXPLORER), maxon::UInt64(enum155::IOSHOWINOSFLAGS::OPEN_IN_EXPLORER)};
		static const maxon::EnumInfo IOSHOWINOSFLAGS_info{"IOSHOWINOSFLAGS", SIZEOF(IOSHOWINOSFLAGS), true, "NONE\0SHOW_IN_EXPLORER\0OPEN_IN_EXPLORER\0", IOSHOWINOSFLAGS_values, std::extent<decltype(IOSHOWINOSFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOSHOWINOSFLAGS155(){ return enum155::IOSHOWINOSFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IOSHOWINOSFLAGS, , "net.maxon.datatype.enum.ioshowinosflags");
	namespace URLFLAGS
	{
		DUMMY_PrivateAttribute DUMMY;
	}
}
#endif
