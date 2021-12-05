#if 1
namespace maxon
{
	namespace enum27 { enum class IOARCHIVESTOREMETHOD
	{
		STORE,		///< Simply store the file without compression.
		DEFLATE		///< Deflates the file in the archive.
	} ; }
	maxon::String PrivateToString_IOARCHIVESTOREMETHOD27(std::underlying_type<enum27::IOARCHIVESTOREMETHOD>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum27::IOARCHIVESTOREMETHOD::STORE, (maxon::UInt64) enum27::IOARCHIVESTOREMETHOD::DEFLATE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IOARCHIVESTOREMETHOD", SIZEOF(x), false, values, "STORE\0DEFLATE\0", fmt);
	}
	namespace enum37 { enum class IOARCHIVEEXTRACTFLAGS
	{
		NONE										= 0,				///< No flags.
		OVERWRITE_EXISTING_FILE	= (1 << 0),	///< Overwrites the file silently if it already exists in the directory.
	} ; }
	maxon::String PrivateToString_IOARCHIVEEXTRACTFLAGS37(std::underlying_type<enum37::IOARCHIVEEXTRACTFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum37::IOARCHIVEEXTRACTFLAGS::NONE, (maxon::UInt64) enum37::IOARCHIVEEXTRACTFLAGS::OVERWRITE_EXISTING_FILE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IOARCHIVEEXTRACTFLAGS", SIZEOF(x), true, values, "NONE\0OVERWRITE_EXISTING_FILE\0", fmt);
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ReadArchiveInterface, "net.maxon.interface.readarchive", "maxon.ReadArchiveInterface", , &Object::_interface);
	const maxon::Char* const ReadArchiveInterface::MTable::_ids = 
		"Open@43bb3f719247d698\0" // Open(const Url& inputFile, const String& password)
		"Close@a54f4799cbe1a498\0" // Close()
		"ExtractSingleFile@1e9c0bcaac20bbf9\0" // ExtractSingleFile(const String& archiveFile, const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
		"Extract@549d9a6d1828d64a\0" // Extract(const Url& outputDirectory, ThreadRef thread, IOARCHIVEEXTRACTFLAGS flags, const ExtractCallback& extractCallback)
	"";
	template <typename DUMMY> maxon::Int ReadArchiveInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(WriteArchiveInterface, "net.maxon.interface.writearchive", "maxon.WriteArchiveInterface", , &Object::_interface);
	const maxon::Char* const WriteArchiveInterface::MTable::_ids = 
		"Open@497c981b5e8202f6\0" // Open(const Url& inputFile, Bool append, const String& password)
		"Close@a54f4799cbe1a498\0" // Close()
		"SetCompressionLevel@44dd4274e7521437\0" // SetCompressionLevel(Int compressionLevel)
		"GetCompressionLevel@4386c86\0" // GetCompressionLevel() const
		"CreateDirectory@8e7c675abbff0e80\0" // CreateDirectory(const String& name, const UniversalDateTime& dateTime, IOATTRIBUTES fileAttributes)
		"CreateFile@a70db100263e51c5\0" // CreateFile(const String& name, const UniversalDateTime& dateTime, IOARCHIVESTOREMETHOD method, IOATTRIBUTES fileAttributes, UInt32 cryptCrc)
		"WriteFile@c6fd6f387b0ccd91\0" // WriteFile(const Block<const Byte>& data)
		"CloseFile@a54f4799cbe1a498\0" // CloseFile()
		"CopyFile@39fe06ff841fb338\0" // CopyFile(const Url& fn, const String& str, IOATTRIBUTES fileAttributes, IOATTRIBUTES fileAttributesMask)
	"";
	template <typename DUMMY> maxon::Int WriteArchiveInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
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
static maxon::details::ForceEvaluation s_forceEval_ioarchivehandler(0
	| maxon::ReadArchiveInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::WriteArchiveInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
