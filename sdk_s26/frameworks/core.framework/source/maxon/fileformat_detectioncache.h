#ifndef FILEFORMAT_DETECTIONCACHE_H__
#define FILEFORMAT_DETECTIONCACHE_H__

#include "maxon/fileformat_handler.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
class FileFormatDetectionCacheInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FileFormatDetectionCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.fileformatdetectioncacheinterface");
public:

	MAXON_METHOD Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection);

	template <typename... LIMITTYPES> MAXON_WARN_UNUSED MAXON_FUNCTION Result<Bool> DetectFile(const Url& url);
};



#include "fileformat_detectioncache1.hxx"

MAXON_DECLARATION(Class<FileFormatDetectionCacheRef>, FileFormatDetectionCacheClass, "net.maxon.class.fileformatdetectioncache");

#include "fileformat_detectioncache2.hxx"


template <typename... LIMITTYPES> Result<Bool> FileFormatDetectionCacheInterface::DetectFile(const Url& url)
{
	DataType array[] = { DataType(), GetDataType<LIMITTYPES>()... }; // add the nullptr infront to allow 0 template arguments.
	return DetectFile(url, ToBlock(array).Slice(1));
}


}

#endif // FILEFORMAT_DETECTIONCACHE_H__
