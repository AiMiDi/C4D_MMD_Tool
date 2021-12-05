#ifndef FILEFORMAT_HANDLER_H__
#define FILEFORMAT_HANDLER_H__


#include "maxon/fileformat.h"

namespace maxon
{


class FileFormatHandler;

//----------------------------------------------------------------------------------------
/// FILEFORMAT_PRIORITY defines the priority order of file formats.
/// The lower the value the later it will be called.
//----------------------------------------------------------------------------------------
enum class FILEFORMAT_PRIORITY
{
	SHIFT_ONE = 1,					///< Add/Sub this value to in/decrease the priority by 1.
	SHIFT_TEN = 10,					///< Add/sub this value to in/decrease the priority by 10.

	FALLBACKFORMAT = 10000, ///< Specifies the lowest priority of a file format.
	GENERALFORMAT = 20000,	///< Specifies the medium priority of a file format. This should be used for general loaders which handle many formats through other APIS (e.g. ffmpeg)
	NATIVEFORMAT = 30000,		///< Specifies the highest priority of a file format. This should be used for native implementations (e.g. image formats like jpg, tif done by us).

} MAXON_ENUM_LIST(FILEFORMAT_PRIORITY);

inline FILEFORMAT_PRIORITY operator+(FILEFORMAT_PRIORITY s1, FILEFORMAT_PRIORITY s2)
{
	return FILEFORMAT_PRIORITY(Int(s1) + Int(s2));
}

inline FILEFORMAT_PRIORITY operator-(FILEFORMAT_PRIORITY s1, FILEFORMAT_PRIORITY s2)
{
	return FILEFORMAT_PRIORITY(Int(s1) - Int(s2));
}



//----------------------------------------------------------------------------------------
/// FileFormatHandlerInterface implements a handler for a specific FileFormat.
/// E.g. two different implementations could offer different loaders for one and the same FileFormat.
/// FileFormat::Zip implements one handler for Directory Browsing (IoBrowseRef) and one for ReadArchiveRef.
//----------------------------------------------------------------------------------------
class FileFormatHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(FileFormatHandlerInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.fileformathandler");
public:

	//----------------------------------------------------------------------------------------
	/// Returns the FileFormat which is handled by this FileFormatHandler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const FileFormat& GetFileFormat() const;

	//----------------------------------------------------------------------------------------
	/// Returns the datatype of the reference class of the handler returned by CreateHandler().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataType> GetHandlerType() const;

	//----------------------------------------------------------------------------------------
	/// Creates an ObjectRef which handles the given url with the generic interface.
	/// CreateHandler<InterfaceRef>() can be used to get the expected reference in the right format.
	/// E.g. FileFormat::Zip implements one handler for Directory Browsing "IoBrowseRef" and one for working with archives "ReadArchiveRef".
	/// @param[in] url								Url to be used with this handler.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<ObjectRef> CreateHandler(const Url& url) const;

	//----------------------------------------------------------------------------------------
	/// Creates an ObjectRef which handles the given url with the specific interface.
	/// E.g. FileFormat::Zip implements one handler for Directory Browsing "IoBrowseRef" and one for workign with archives "ReadArchiveRef".
	/// @param[in] url								Url to be used with this handler.
	/// @tparam HANDLER								Reference class to be expected with the result of CreateHandler.
	//----------------------------------------------------------------------------------------
	template <typename HANDLER> MAXON_FUNCTION Result<HANDLER> CreateHandler(const Url& url) const
	{
		iferr_scope;
		ObjectRef handler = FileFormatHandlerInterface::CreateHandler(url) iferr_return;
		HANDLER castHandler = Cast<HANDLER>(std::move(handler));
		if (!castHandler)
			return NullptrError(MAXON_SOURCE_LOCATION);
		return std::move(castHandler);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the dependencies of this FileFormatHandler. This allows to give an priority order for a implementation.
	/// This function should not be called except from FileFormatDetectionInterface::DetectAll().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD FILEFORMAT_PRIORITY GetDependends() const;
};


//----------------------------------------------------------------------------------------
/// FileFormatDetectionInterface offers functions to detect file formats.
//----------------------------------------------------------------------------------------
class FileFormatDetectionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(FileFormatDetectionInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.fileformatdetection");

public:
	//----------------------------------------------------------------------------------------
#ifndef MAXON_COMPILER_CLANG	// circumvent clang bug that creates false positives
	/// @return												The callback should return true if the file format detection should stop at this point. Returning false
	///																will search other compatible fileformat handlers. If you return a error the search will be continued. If no valid
	///																handler can be found the first error will be returned as the result of DetectAll().
#endif
	//----------------------------------------------------------------------------------------
	using DetectedCallback = Delegate<Result<Bool>(const Url& url, const FileFormatHandler& handler)>;

	//----------------------------------------------------------------------------------------
	/// Detects all available FileFormatHandler in the order of priority.
	/// The first value in the array should be used first.
	/// @param[in] url								Url to detect.
	/// @param[in] limitDetection			Limit FileFormatHandler which return the given data types in their CreateHandler() call.
	/// @param[in] detectedCallback		Every detected file format handler will call this callback before adding it to the result BaseArray<FileFormatHandler>. For details see DetectedCallback.
	/// @return												Returns an array with FileFormatHandler which all can handle this url.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const Block<const DataType>& limitDetection, const DetectedCallback& detectedCallback);

	//----------------------------------------------------------------------------------------
	/// Detects all available FileFormatHandler in the order of priority.
	/// The first value in the array should be used first.
	/// @tparam LIMITTYPES						List with reference types to limit the DetectAll call. E.g. DetectAll<MediaLoaderRef>(), DetectAll<MediaLoaderRef, MovieLoaderRef>().
	/// @param[in] url								Url to detect.
	/// @return												Returns an array with FileFormatHandler which all can handle this url.
	//----------------------------------------------------------------------------------------
	template <typename... LIMITTYPES> MAXON_WARN_UNUSED
	static MAXON_FUNCTION Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const DetectedCallback& detectedCallback);

	//----------------------------------------------------------------------------------------
	/// Detects the first available FileFormatHandler in the order of priority.
	/// @tparam LIMITTYPES						List with reference types to limit the DetectAll call. E.g. DetectAll<MediaLoaderRef>(), DetectAll<MediaLoaderRef, MovieLoaderRef>().
	/// @param[in] url								Url to detect.
	/// @return												Returns a FileFormatHandler which can handle this url.
	//----------------------------------------------------------------------------------------
	template <typename... LIMITTYPES> MAXON_WARN_UNUSED
	static MAXON_FUNCTION Result<FileFormatHandler> Detect(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Detects all available FileFormatHandler in the order of priority.
	/// The first value in the array should be used first.
	/// @param[in] url								Url to detect.
	/// @param[in] stream							Url to detect.
	/// @param[in] limitDetection			Limit FileFormatHandler which return the given data types in their CreateHandler() call.
	/// @return												Returns an array with FileFormatHandler which all can handle this url.
	//----------------------------------------------------------------------------------------
	//static MAXON_METHOD Result<BaseArray<FileFormatHandler>> DetectAll(const Url& url, const InputStreamRef& stream, const Block<const DataType>& limitDetection);
};


#include "fileformat_handler1.hxx"

//----------------------------------------------------------------------------------------
/// Registry to register/iterate all available FileFormatHandler implementations.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(FileFormatHandler, FileFormatHandlers, "net.maxon.registry.fileformathandlers");

//----------------------------------------------------------------------------------------
///
//----------------------------------------------------------------------------------------
namespace FileFormatHandlers
{
	/// returns no handler because it indicates just a regular file
	MAXON_DECLARATION(FileFormatHandler, GenericFile, "net.maxon.fileformathandler.genericfile");

	/// returns IoBrowseRef for directories
	MAXON_DECLARATION(FileFormatHandler, Browsable, "net.maxon.fileformathandler.browsable");

	/// returns DataFormatReaderRef
	MAXON_DECLARATION(FileFormatHandler, MaxonDocumentBinaryHandler, "net.maxon.fileformathandler.maxondocumentbinaryhandler");

	/// returns DataFormatReaderRef
	MAXON_DECLARATION(FileFormatHandler, MaxonDocumentJsonHandler, "net.maxon.fileformathandler.maxondocumentjsonhandler");

	/// returns DataFormatReaderRef
	MAXON_DECLARATION(FileFormatHandler, MaxonDocumentXmlHandler, "net.maxon.fileformathandler.maxondocumentxmlhandler");
};


#include "fileformat_handler2.hxx"

template <typename... LIMITTYPES> Result<BaseArray<FileFormatHandler>> FileFormatDetectionInterface::DetectAll(const Url& url, const DetectedCallback& detectedCallback)
{
	DataType array[] = { DataType::NullValue(), GetDataType<LIMITTYPES>()... }; // add the nullptr infront to allow 0 template arguments.
	return DetectAll(url, ToBlock(array).Slice(1), detectedCallback);
}

template <typename... LIMITTYPES> Result<FileFormatHandler> FileFormatDetectionInterface::Detect(const Url& url)
{
	iferr_scope;

	BaseArray<FileFormatHandler> handler = DetectAll<LIMITTYPES...>(url,
		[](const Url& u, const FileFormatHandler& h) -> Result<Bool>
		{
			// return true to stop execution when the first format was found.
			return true;
		}) iferr_return;

	if (handler.IsEmpty())
		return FileFormatHandler();

	return handler[0];
}


}

#endif // FILEFORMAT_HANDLER_H__
