// This file contains default implementations for the interfaces of fileformat_detectioncache.h. They are intended for copy&paste usage only.

class MyFileFormatDetectionCacheImpl : public maxon::Component<MyFileFormatDetectionCacheImpl, FileFormatDetectionCacheInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
