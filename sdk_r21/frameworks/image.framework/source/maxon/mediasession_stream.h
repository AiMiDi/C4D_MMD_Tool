#ifndef MEDIASESSION_STREAM_H__
#define MEDIASESSION_STREAM_H__

#include "maxon/mediasession_streamformat.h"
#include "maxon/gfx_image.h"
#include "maxon/basearray.h"
#include "maxon/hierarchyobject.h"



namespace maxon
{

class MediaStreamRef;
//----------------------------------------------------------------------------------------
/// Single Stream within a MediaConverterInterface.
/// Streams might have sub streams as children (see HierarchyObjectInterface).
//----------------------------------------------------------------------------------------
class MediaStreamInterface : MAXON_INTERFACE_BASES(MediaBaseInterface, HierarchyObjectInterface<DefaultHierarchy<MediaStreamRef>>)
{
	MAXON_INTERFACE(MediaStreamInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastream");

public:
	using RESTRICT_DICTIONARY_PROPS = MEDIASTREAM::RESTRICT;

	/// returns the formatId of all available formats.
	MAXON_METHOD Result<BaseArray<Data>> GetFormats() const;

	/// returns the format of the given id.
	MAXON_METHOD MediaStreamFormat GetFormat(const Data& formatId) const;

	/// returns the selected format.
	MAXON_METHOD const Data& GetSelectedFormat() const;

	/// used by reader implementations to set the selected format of the stream. this must not be called from outside.
	MAXON_METHOD Result<void> SetSelectedFormat(const Data& formatId);

	/// used by reader implementations to add formats to the stream. this must not be called from outside.
	MAXON_METHOD Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref);

	//----------------------------------------------------------------------------------------
	/// Subscribes to the stream. So if the media converter finds the data in the stream it triggers the specific callbacks defined by the inherited specialized interface.
	/// this allows to read data directly to the place where it needs to by without additional memory copy.
	/// @param[in] formatId						The selected format to subscribe.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SubscribeStream(const Data& formatId);

	//----------------------------------------------------------------------------------------
	/// Unsubscribes from the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> UnsubscribeStream();

	//----------------------------------------------------------------------------------------
	/// Returns true if the stream is subscribed by a media converter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsSubscribed() const;

};


class MediaStreamExifDataRef;
class ExifRef;
//----------------------------------------------------------------------------------------
/// Stream which delivers EXIF data.
//----------------------------------------------------------------------------------------
class MediaStreamExifDataInterface : MAXON_INTERFACE_BASES(MediaStreamInterface)
{
	MAXON_INTERFACE(MediaStreamExifDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamexifdata");

public:
	using ExifDataHandler = Delegate<Result<void>(const MediaStreamExifDataRef& stream, const ExifRef& exifData)>;

	//----------------------------------------------------------------------------------------
	/// Subscribes to the Exif data stream. So if the media converter triggers the callback as soon as the exif data is available.
	/// @param[in] handleExifData			A handler which is called from the input media converter to signal that the exif data is
	/// 															available for this stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData);

	// called by the input media converter implementation before loading a stream.
	MAXON_METHOD Result<void> HandleExifData(const ExifRef& exifData);

	// called by the input media converter implementation when loading the stream is completed.
	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props);
};


//----------------------------------------------------------------------------------------
/// Base class for stream which delivers image data.
//----------------------------------------------------------------------------------------
class MediaStreamImageBaseInterface : MAXON_INTERFACE_BASES(MediaStreamInterface)
{
	MAXON_INTERFACE(MediaStreamImageBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamimagebase");

public:
};


class MediaStreamImageDataImportRef;
//----------------------------------------------------------------------------------------
/// Stream which represents full image data.
//----------------------------------------------------------------------------------------
class MediaStreamImageDataImportInterface : MAXON_INTERFACE_BASES(MediaStreamImageBaseInterface)
{
	MAXON_INTERFACE(MediaStreamImageDataImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamimagedataimport");

public:
	using InitHandler = Delegate<Result<void>(const MediaStreamImageDataImportRef& stream, const MediaStreamProperties& props)>;
	using SetPixelHandler = Delegate<Result<SetPixelHandlerStruct>(const MediaStreamImageDataImportRef& stream, const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffset, SETPIXELHANDLERFLAGS setPixelFlags)>;
	using FinishHandler = Delegate<Result<void>(const MediaStreamImageDataImportRef& stream, const MediaStreamProperties& props)>;

	//----------------------------------------------------------------------------------------
	/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
	/// this allows to read data directly to the place where it needs to by without additional memory copy.
	/// @param[in] initHandler				A handler which is called from the input media converter to signal that data is
	/// 															available for this frame of the stream.
	/// @param[in] setPixelHandler		A handler which is called for each thread that needs a valid SetPixelHandlerStruct
	/// 															which will be used by the input converter to set the pixel data.
	/// @param[in] finishHandler			A handler which is called from the input media converter to signal that data loading
	/// 															the data from this stream is finished for this frame of the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler,
																							 const FinishHandler& finishHandler);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the source image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitStream(const MediaStreamProperties& props);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the source image stream.
	/// @param[in] srcChannelOffsets	Source channel offsets of the data that will be set using this set pixel handler.
	/// @param[in] setPixelFlags			Flags which control the set pixel operation. See also SETPIXELHANDLERFLAGS.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation when loading the stream is completed.
	/// @param[in] props							Properties of the source image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props);
};


class MediaStreamImageDataExportRef;
//----------------------------------------------------------------------------------------
/// Stream which represents full image data.
//----------------------------------------------------------------------------------------
class MediaStreamImageDataExportInterface : MAXON_INTERFACE_BASES(MediaStreamImageBaseInterface)
{
	MAXON_INTERFACE(MediaStreamImageDataExportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamimagedataexport");

public:
	using InitHandler = Delegate<Result<void>(const MediaStreamImageDataExportRef& stream, MediaStreamProperties& props)>;
	using GetPixelHandler = Delegate<Result<GetPixelHandlerStruct>(const MediaStreamImageDataExportRef& stream, const MediaStreamProperties& props,
		const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet)>;
	using FinishHandler = Delegate<Result<void>(const MediaStreamImageDataExportRef& stream, const MediaStreamProperties& props)>;

	//----------------------------------------------------------------------------------------
	/// Subscribes to the stream. So if the media converter loads the stream the setPixelHandler callback is triggered.
	/// this allows to read data directly to the place where it needs to by without additional memory copy.
	/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
	/// 															required for this frame of the stream.
	/// @param[in] getPixelHandler		A handler which is called for each thread that needs a valid GetPixelHandlerStruct
	/// 															which will be used by the output converter to get the pixel data.
	/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
	/// 															the data from this stream is finished for this frame of the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler,
																							 const FinishHandler& finishHandler);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the image stream.
	/// @param[in] dstFormat					Destination pixel format.
	/// @param[in] channelOffsets			Channel offset that is needed in the destination.
	/// @param[in] dstColorProfile		Destination color profile.
	/// @param[in] flags							See GETPIXELHANDLERFLAGS flags.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat,
		const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation when loading the stream is completed.
	/// @param[in] props							Properties of the image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props);
};


class MediaStreamImageDataForwardImportInterface : MAXON_INTERFACE_BASES(MediaStreamImageDataImportInterface)
{
	MAXON_INTERFACE(MediaStreamImageDataForwardImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamimagedataforwardimport");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] sourceStream				Stream that should be forwarded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream);
};




class MediaStreamAudioDataImportRef;
//----------------------------------------------------------------------------------------
/// Stream which represents full image data.
//----------------------------------------------------------------------------------------
class MediaStreamAudioDataImportInterface : MAXON_INTERFACE_BASES(MediaStreamInterface)
{
	MAXON_INTERFACE(MediaStreamAudioDataImportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamaudiodataimport");

public:
	using SetAudioDataCallbackType = Delegate<Result<void>(const Block<Char>&)>;

	using InitHandler = Delegate<Result<void>(const MediaStreamAudioDataImportRef& stream, MediaStreamProperties& props)>;
	using SetAudioDataHandler = Delegate<Result<SetAudioDataCallbackType>(const MediaStreamAudioDataImportRef& stream, MediaStreamProperties& props)>;
	using FinishHandler = Delegate<Result<void>(const MediaStreamAudioDataImportRef& stream, const MediaStreamProperties& props)>;

	//----------------------------------------------------------------------------------------
	/// SetCallbackHandler description.
	/// @param[in] initHandler				A handler which is called from the output media converter to signal that data is
	/// 															required for this frame of the stream.
	/// @param[in] getAudioDataHandler	A handler which is called for each thread that needs a valid SetAudioHandlerDataCallback.
	/// @param[in] finishHandler			A handler which is called from the output media converter to signal that data writing
	/// 															the data from this stream is finished for this frame of the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props);

	//----------------------------------------------------------------------------------------
	/// SetAudioDataCallback description.
	/// @param[in] props							Properties of the audio stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation when loading the stream is completed.
	/// @param[in] props							Properties of the audio stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props);
};


// include auto generated header file here
#include "mediasession_stream1.hxx"

MAXON_DECLARATION(Class<MediaStreamRef>, MediaStreamBaseClass, "net.maxon.image.class.mediastreambase");
MAXON_DECLARATION(Class<MediaStreamExifDataRef>, MediaStreamExifDataClass, "net.maxon.image.class.mediastreamexifdata");
MAXON_DECLARATION(Class<MediaStreamImageBaseRef>, MediaStreamImageBaseClass, "net.maxon.image.class.mediastreamimagebase");
MAXON_DECLARATION(Class<MediaStreamImageDataImportRef>, MediaStreamImageDataImportClass, "net.maxon.image.class.mediastreamimagedataimport");
MAXON_DECLARATION(Class<MediaStreamImageDataExportRef>, MediaStreamImageDataExportClass, "net.maxon.image.class.mediastreamimagedataexport");
MAXON_DECLARATION(Class<MediaStreamAudioDataImportRef>, MediaStreamAudioDataImportClass, "net.maxon.image.class.mediastreamaudiodataimport");

// special interface that forwards all streams to the destination stream
MAXON_DECLARATION(Class<MediaStreamImageDataForwardImportRef>, MediaStreamForwardImageDataStreamsImportClass, "net.maxon.image.class.mediastreamforwardimagedatastreamsimport");

// include auto generated header file here
#include "mediasession_stream2.hxx"



//----------------------------------------------------------------------------------------
/// GetSelectedFormatPreferAspectRatio_1_1 tries to find a format with a 1:1 aspect ratio.
/// @param[in] stream							Stream to determine.
/// @param[in] resFormat					Returns the MediaStreamFormat of the preferred format.
/// @return												Returns the preferred format.
//----------------------------------------------------------------------------------------
inline Result<Data> GetSelectedFormatPreferAspectRatio_1_1(const MediaStreamRef& stream, MediaStreamFormat& resFormat)
{
	iferr_scope;

	Data selectedFormatId = stream.GetSelectedFormat().GetCopy() iferr_return;

	resFormat = stream.GetFormat(selectedFormatId);

	ifnoerr (Float aspectRatio = resFormat.Get(MEDIAFORMAT::IMAGE::ASPECTRATIO))
	{
		if (aspectRatio != 1.0)
		{
			// look for a format with a pixelRatio == 1.0
			BaseArray<Data> formats = stream.GetFormats() iferr_return;
			for (const Data& formatId : formats)
			{
				if (formatId == selectedFormatId)
					continue;

				MediaStreamFormat formatI = stream.GetFormat(formatId);
				aspectRatio = formatI.GetOrDefault(MEDIAFORMAT::IMAGE::ASPECTRATIO);

				if (aspectRatio == 1.0)
				{
					selectedFormatId = formatId.GetCopy() iferr_return;
					resFormat = std::move(formatI);
					break;
				}
			}
		}
	}

	return std::move(selectedFormatId);
}



} // namespace maxon


#endif // MEDIASESSION_STREAM_H__
