#if 1
namespace maxon
{
	namespace enum26
	{
		enum class IOARCHIVESTOREMETHOD
		{
			STORE,		///< Simply store the file without compression.
			DEFLATE		///< Deflates the file in the archive.
		} ;
		static const maxon::UInt64 IOARCHIVESTOREMETHOD_values[] = {maxon::UInt64(enum26::IOARCHIVESTOREMETHOD::STORE), maxon::UInt64(enum26::IOARCHIVESTOREMETHOD::DEFLATE)};
		static const maxon::EnumInfo IOARCHIVESTOREMETHOD_info{"IOARCHIVESTOREMETHOD", SIZEOF(IOARCHIVESTOREMETHOD), false, "STORE\0DEFLATE\0", IOARCHIVESTOREMETHOD_values, std::extent<decltype(IOARCHIVESTOREMETHOD_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOARCHIVESTOREMETHOD26(){ return enum26::IOARCHIVESTOREMETHOD_info; }
	namespace enum36
	{
		enum class IOARCHIVEEXTRACTFLAGS
		{
			NONE										= 0,				///< No flags.
			OVERWRITE_EXISTING_FILE	= (1 << 0),	///< Overwrites the file silently if it already exists in the directory.
		} ;
		static const maxon::UInt64 IOARCHIVEEXTRACTFLAGS_values[] = {maxon::UInt64(enum36::IOARCHIVEEXTRACTFLAGS::NONE), maxon::UInt64(enum36::IOARCHIVEEXTRACTFLAGS::OVERWRITE_EXISTING_FILE)};
		static const maxon::EnumInfo IOARCHIVEEXTRACTFLAGS_info{"IOARCHIVEEXTRACTFLAGS", SIZEOF(IOARCHIVEEXTRACTFLAGS), true, "NONE\0OVERWRITE_EXISTING_FILE\0", IOARCHIVEEXTRACTFLAGS_values, std::extent<decltype(IOARCHIVEEXTRACTFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOARCHIVEEXTRACTFLAGS36(){ return enum36::IOARCHIVEEXTRACTFLAGS_info; }
	const maxon::Char* const ReadArchiveInterface::MTable::_ids = 
		"Open@97e00d0cf19ccaab\0" // Result<void> Open(const Url& inputFile, const String& password)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"ExtractSingleFile@14c88a5d12c54ff4\0" // Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
		"Extract@47c24194f5bba6d7\0" // Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	"";
	const maxon::METHOD_FLAGS ReadArchiveInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ReadArchiveInterface, , "net.maxon.interface.readarchive", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const WriteArchiveInterface::MTable::_ids = 
		"Open@404ce1cf100fd3a1\0" // Result<void> Open(const Url& inputFile, Bool append, const String& password)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"SetCompressionLevel@c49f7df11faba36e\0" // Result<void> SetCompressionLevel(Int compressionLevel)
		"GetCompressionLevel@7d0e6f3d29c239e7\0" // Int GetCompressionLevel() const
		"CreateDirectory@56a91b5bcf1a2849\0" // Result<void> CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes)
		"CreateFile@207165c5884e69c\0" // Result<void> CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc)
		"WriteFile@f8f7b06e2c55bd6c\0" // Result<void> WriteFile(const Block<const Byte>& data)
		"CloseFile@3008090429c5a175\0" // Result<void> CloseFile()
		"CopyFile@59b0c2400bb19d39\0" // Result<void> CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask)
	"";
	const maxon::METHOD_FLAGS WriteArchiveInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(WriteArchiveInterface, , "net.maxon.interface.writearchive", (ObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(ReadArchiveClasses);
	namespace ReadArchiveClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Zip, , "net.maxon.readarchiveclass.zip");
	}
	MAXON_REGISTRY_REGISTER(WriteArchiveClasses);
	namespace WriteArchiveClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Zip, , "net.maxon.writearchiveclass.zip");
	}
}
#endif
