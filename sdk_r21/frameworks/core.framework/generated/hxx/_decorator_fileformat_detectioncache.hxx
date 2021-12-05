// This file contains decorator implementations for the interfaces of fileformat_detectioncache.h. They are intended for copy&paste usage only.

class FileFormatDetectionCacheDecoratorImpl : public maxon::Component<FileFormatDetectionCacheDecoratorImpl, FileFormatDetectionCacheInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Bool> DetectFile(const Url& url, const Block<const DataType>& limitDetection)
	{
		return maxon::Cast<FileFormatDetectionCacheRef>(self.GetDecoratedObject()).DetectFile(url, limitDetection);
	}

};
