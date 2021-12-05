#if 1
namespace maxon
{
	namespace enum26 { enum class IOARCHIVESTOREMETHOD
	{
		STORE,		///< Simply store the file without compression.
		DEFLATE		///< Deflates the file in the archive.
	} ; }
	maxon::String PrivateToString_IOARCHIVESTOREMETHOD26(std::underlying_type<enum26::IOARCHIVESTOREMETHOD>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum26::IOARCHIVESTOREMETHOD::STORE, (maxon::UInt64) enum26::IOARCHIVESTOREMETHOD::DEFLATE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IOARCHIVESTOREMETHOD", SIZEOF(x), false, values, "STORE\0DEFLATE\0", fmt);
	}
	namespace enum36 { enum class IOARCHIVEEXTRACTFLAGS
	{
		NONE										= 0,				///< No flags.
		OVERWRITE_EXISTING_FILE	= (1 << 0),	///< Overwrites the file silently if it already exists in the directory.
	} ; }
	maxon::String PrivateToString_IOARCHIVEEXTRACTFLAGS36(std::underlying_type<enum36::IOARCHIVEEXTRACTFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum36::IOARCHIVEEXTRACTFLAGS::NONE, (maxon::UInt64) enum36::IOARCHIVEEXTRACTFLAGS::OVERWRITE_EXISTING_FILE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IOARCHIVEEXTRACTFLAGS", SIZEOF(x), true, values, "NONE\0OVERWRITE_EXISTING_FILE\0", fmt);
	}
	const maxon::Char* const ReadArchiveInterface::MTable::_ids = 
		"Open@97e00d0cf19ccaab\0" // Result<void> Open(const Url& inputFile, const String& password)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"ExtractSingleFile@14c88a5d12c54ff4\0" // Result<Url> ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
		"Extract@47c24194f5bba6d7\0" // Result<void> Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ReadArchiveInterface, , "net.maxon.interface.readarchive", "maxon.ReadArchiveInterface", (ObjectInterface::PrivateGetInterface()));
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
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(WriteArchiveInterface, , "net.maxon.interface.writearchive", "maxon.WriteArchiveInterface", (ObjectInterface::PrivateGetInterface()));
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
