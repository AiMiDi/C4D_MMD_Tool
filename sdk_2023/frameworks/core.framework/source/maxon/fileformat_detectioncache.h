#ifndef FILEFORMAT_DETECTIONCACHE_H__
#define FILEFORMAT_DETECTIONCACHE_H__

#include "maxon/fileformat_handler.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// This interface allows to detect files with a file cache to prevent frequently open file io operations.
/// Used together with DragAndDropHandlerInterface to optimize d&d.
/// e.g.
/// FileFormatDetectionCacheRef fileFormatCacheRef = dndHandlerRef.GetFileDetectionCache() iferr_return;
/// ifnoerr (isTrue = fileFormatCacheRef.DetectFile<MediaInputRef>(url, FILEFORMATDETECTIONFLAGS::NONE))
/// {
/// 	if (isTrue)
/// 	{
/// 		isMediaSessionUrl |= isTrue;
/// 		break;
/// 	}
/// }
/// ifnoerr (isTrue = fileFormatCacheRef.DetectFile<nodes::NodeSystem>(url, FILEFORMATDETECTIONFLAGS::NONE))
/// {
/// 	if (isTrue)
/// 	{
/// 		isNodeAsset |= isTrue;
/// 		break;
/// 	}
/// }
//----------------------------------------------------------------------------------------
class FileFormatDetectionCacheInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FileFormatDetectionCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.fileformatdetectioncacheinterface");
public:

	//----------------------------------------------------------------------------------------
	/// Checks if a file supports a given file format.
	/// @param[in] url								Url to detect.
	/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
	/// @param[in] limitDetection			Datatype to limit the detection e.g. MediaInputRef, nodes::NodeSystem
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags, const Block<const DataType>& limitDetection);

	//----------------------------------------------------------------------------------------
	/// Checks if a file supports a given file format. Helper function to simplify usage e.g. DetectFile<MediaInputRef>().
	/// @param[in] url								Url to detect.
	/// @param[in] flags							see FILEFORMATDETECTIONFLAGS.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	template <typename... LIMITTYPES> MAXON_WARN_UNUSED MAXON_FUNCTION Result<Bool> DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags);
};



#include "fileformat_detectioncache1.hxx"

MAXON_DECLARATION(Class<FileFormatDetectionCacheRef>, FileFormatDetectionCacheClass, "net.maxon.class.fileformatdetectioncache");

#include "fileformat_detectioncache2.hxx"


template <typename... LIMITTYPES> Result<Bool> FileFormatDetectionCacheInterface::DetectFile(const Url& url, FILEFORMATDETECTIONFLAGS flags)
{
	DataType array[] = { DataType(), GetDataType<LIMITTYPES>()... }; // add the nullptr infront to allow 0 template arguments.
	return DetectFile(url, flags, ToBlock(array).Slice(1));
}


}

#endif // FILEFORMAT_DETECTIONCACHE_H__
