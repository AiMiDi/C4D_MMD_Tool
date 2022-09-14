#if 1
namespace maxon
{
	const maxon::Char* const FileFormatDetectionCacheInterface::MTable::_ids = 
		"DetectFile@7008c4f48ac79cd9\0" // Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection)
	"";
	const maxon::METHOD_FLAGS FileFormatDetectionCacheInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatDetectionCacheInterface, , "net.maxon.interface.fileformatdetectioncacheinterface", "maxon.FileFormatDetectionCacheInterface", (ObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatDetectionCacheClass, , "net.maxon.class.fileformatdetectioncache");
}
#endif
