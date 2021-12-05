#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FileFormatDetectionCacheInterface, "net.maxon.interface.fileformatdetectioncacheinterface", "maxon.FileFormatDetectionCacheInterface", , &Object::_interface);
	const maxon::Char* const FileFormatDetectionCacheInterface::MTable::_ids = 
		"DetectFile@7524950af0f20a5b\0" // DetectFile(const Url& url, const Block<const DataType*>& limitDetection)
	"";
	template <typename DUMMY> maxon::Int FileFormatDetectionCacheInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatDetectionCacheClass, , "net.maxon.class.fileformatdetectioncache");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_fileformat_detectioncache(0
	| maxon::FileFormatDetectionCacheInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
