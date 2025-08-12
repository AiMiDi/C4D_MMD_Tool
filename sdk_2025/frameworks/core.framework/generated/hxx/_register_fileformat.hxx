#if 1
namespace maxon
{
	namespace enum21
	{
		enum class FILEFORMATDETECTIONFLAGS
		{
			NONE = 0,
			FASTDETECTION = (1 << 0), ///< perform a faster detection when scanning many files (e.g. check suffixes before running real identification code for windows media foundation movies files because windows needs 500 ms for each)
		} ;
		static const maxon::UInt64 FILEFORMATDETECTIONFLAGS_values[] = {maxon::UInt64(enum21::FILEFORMATDETECTIONFLAGS::NONE), maxon::UInt64(enum21::FILEFORMATDETECTIONFLAGS::FASTDETECTION)};
		static const maxon::EnumInfo FILEFORMATDETECTIONFLAGS_info{"FILEFORMATDETECTIONFLAGS", SIZEOF(FILEFORMATDETECTIONFLAGS), true, "NONE\0FASTDETECTION\0", FILEFORMATDETECTIONFLAGS_values, std::extent<decltype(FILEFORMATDETECTIONFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FILEFORMATDETECTIONFLAGS21(){ return enum21::FILEFORMATDETECTIONFLAGS_info; }
	const maxon::Char* const FileFormatInterface::MTable::_ids = 
		"Detect@865bb4ef0f16b9a2\0" // Result<Bool> Detect(const Url& url, const InputStreamRef& probeStream, FILEFORMATDETECTIONFLAGS flags) const
	"";
	const maxon::METHOD_FLAGS FileFormatInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatInterface, , "net.maxon.interface.fileformat", (DataDictionaryObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(FileFormats);
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Browsable, , "net.maxon.fileformat.browsable");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(File, , "net.maxon.fileformat.file");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentBinary, , "net.maxon.fileformat.maxondocumentbinary");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentJson, , "net.maxon.fileformat.maxondocumentjson");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MaxonDocumentXml, , "net.maxon.fileformat.maxondocumentxml");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatBaseClass, , "net.maxon.class.fileformatbase");
}
#endif
