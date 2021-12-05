#ifndef MEDIASESSION_OUTPUT_H__
#define MEDIASESSION_OUTPUT_H__

#include "maxon/fileformat_handler.h"
#include "maxon/mediasession_converter.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// Result type of the MediaOutputSelectionHandler.
//----------------------------------------------------------------------------------------
enum class SELECTIONHANDLERRESULT
{
	NONE = 0,																						 // nothing to load
	STRUCTURE = (1 << 0),																 ///< load the image structure (e.g. layers, folders) but create only the layers.
	CONTENT_FLAG = (1 << 1),														 ///< load the image/layer data.
	STRUCTURE_WITH_CONTENT = (CONTENT_FLAG | STRUCTURE), ///< load the image structure and load the image/layer data.
	ALL = STRUCTURE_WITH_CONTENT,												 ///< load all (e.g. like no filter would be set).
} MAXON_ENUM_FLAGS(SELECTIONHANDLERRESULT);

//----------------------------------------------------------------------------------------
/// The selection handler will be called for every stream which is detected in output texture.
//----------------------------------------------------------------------------------------
using MediaOutputSelectionHandler = Delegate<Result<SELECTIONHANDLERRESULT>(const MediaStreamRef& stream, const MediaStreamFormat& props)>;


//----------------------------------------------------------------------------------------
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
//----------------------------------------------------------------------------------------
class MediaOutputInterface : MAXON_INTERFACE_BASES(MediaConverterInterface)
{
	MAXON_INTERFACE(MediaOutputInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediaoutput");

public:
	//----------------------------------------------------------------------------------------
	/// Resets the converter to default state.
	/// This function will be called if the converter is reused and needs to be reinitialized.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ResetConverter();

	//----------------------------------------------------------------------------------------
	/// Sets a selection handler to be called as soon as a new stream is recognized.
	/// @param[in] selectionHandler		Handler to be called.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler);

	//----------------------------------------------------------------------------------------
	/// Sets a selection handler to be called as soon as a new stream is recognized.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const MediaOutputSelectionHandler& GetSelectionHandler() const;

	//----------------------------------------------------------------------------------------
	/// Called by the input media converter implementation before loading a stream.
	/// This function triggers the execution of the MediaOutputSelectionHandler set with SetSelectionHandler.
	/// @param[in] stream							Stream to check for filtering.
	/// @param[in] props							Properties of the stream. This can be used to filter for names or special formats etc.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props);
};



//----------------------------------------------------------------------------------------
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
//----------------------------------------------------------------------------------------
class MediaOutputTextureInterface : MAXON_INTERFACE_BASES(MediaOutputInterface)
{
	MAXON_INTERFACE(MediaOutputTextureInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediaoutputtexture");

public:
	//----------------------------------------------------------------------------------------
	/// Sets the output texture link.
	/// @param[in] textureRef					Target texture to load the media data into.
	/// @param[in] pixelStorageClass	Defines the storage class how newly created layers/images should store their pixel data (e.g.
	///																ImagePixelStorageClasses::Voxel).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass);
};


namespace MEDIAOUTPUTURLPROPERTIES
{
	/// Returns if the format can write video data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_IMAGE, "net.maxon.media.output.supports_image");

	/// Returns if the format can write video data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_VIDEO, "net.maxon.media.output.supports_video");

	/// Returns if the format can write audio data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_AUDIO, "net.maxon.media.output.supports_audio");

	/// Returns if the handler supports the options settings dialog
	/// see MediaOutputUrlInterface::EditSystemOptions
	MAXON_ATTRIBUTE(Bool, SUPPORTS_SYSTEMOPTIONS, "net.maxon.media.output.supports_systemoptions");

	/// RESOURCE_MIN(0), Returns the maximal supported alpha channels (return 0 if alpha channels are unsupported)
	MAXON_ATTRIBUTE(Int, MAXIMALALPHACHANNELS, "net.maxon.media.output.maximalalphachannels");

	/// RESOURCE_MIN(0), Returns the maximal supported resolution for images
	MAXON_ATTRIBUTE(Int, MAXIMALIMAGERESOLUTION, "net.maxon.media.output.maximalimageresolution");

	/// RESOURCE_MIN(0), Returns the maximal supported resolution for layers (return 0 if layers are unsupported)
	MAXON_ATTRIBUTE(Int, MAXIMALLAYERRESOLUTION, "net.maxon.media.output.maximallayerresolution");

	/// Returns the supported bit depths for the image resource of that format
	MAXON_ATTRIBUTE(Block<BitDepthConfig>, BITDEPTHSIMAGE, "net.maxon.media.output.bitdepthsimage");

	/// Returns the supported bit depths for layers of that format
	MAXON_ATTRIBUTE(Block<BitDepthConfig>, BITDEPTHSLAYER, "net.maxon.media.output.bitdepthslayer");

	/// Returns if the format can embed color profiles
	MAXON_ATTRIBUTE(Bool, EMBED_COLORPROFILE, "net.maxon.media.output.embed_colorprofile");
}

//----------------------------------------------------------------------------------------
/// The MediaOutputInterface class provides an specific implementation to provide output data to a given destination.
//----------------------------------------------------------------------------------------
class MediaOutputUrlInterface : MAXON_INTERFACE_BASES(MediaOutputInterface)
{
	MAXON_INTERFACE(MediaOutputUrlInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediaoutputurl");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the output url.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetOutputUrl() const;

	//----------------------------------------------------------------------------------------
	/// Sets the url to which this output converter should write it's data.
	/// @param[in] url								Url to write to.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetOutputUrl(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding file format.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const FileFormat& GetFileFormat() const;

	//----------------------------------------------------------------------------------------
	/// EditSystemOptions opens a system compressor options dialog to allow the user to choose compressor settings for a specific codec.
	/// @param[in,out] settings				Settings to be displayed and modified. After calling the function the DataDictionary contains the new settings.
	/// @param[in] getParentwindowHandle	Callback to return the parent window handle. Windows: return the HWND for the parent.
	/// @return												True if the user pressed OK, false if the user cancelled the action. FunctionNotImplementedError if the
	///																output handler doesn't support a dialog.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle);

	//----------------------------------------------------------------------------------------
	/// Verifies the given resolution for the save format (e.g. mp4 quantizes the width to the next 16 boundary).
	/// @param[in] settings						Save Settings.
	/// @param[in] bitmapSize					Given input bitmap size.
	/// @return												Corrected bitmap size if the save cannot handle the given size, otherwise the given size.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const;
};



// include auto generated header file here
#include "mediasession_output1.hxx"

MAXON_DECLARATION(Class<MediaOutputRef>, MediaOutputBaseClass, "net.maxon.image.class.mediaoutputbase");
MAXON_DECLARATION(Class<MediaOutputTextureRef>, MediaOutputTextureClass, "net.maxon.image.class.mediaoutputtexture");
MAXON_DECLARATION(Class<MediaOutputUrlRef>, MediaOutputUrlBaseClass, "net.maxon.image.class.mediaoutputurlbase");

// include auto generated header file here
#include "mediasession_output2.hxx"


using MediaSessionProgressCallback = Delegate<void(const MediaSessionProgressRef& progress, Float percent, const TimeValue& duration, const TimeValue& expectedTotalTime)>;

//----------------------------------------------------------------------------------------
/// Helper function to load a image or movie into any MediaOutputRef.
/// this allows to load images/movies directly to the place it belongs to (e.g. directly to any opengl buffer).
/// @param[in] fileName						Url to load.
/// @param[in] targetTime					Frame to load from a stream. TimeValue() will load the first frame.
/// @param[in] flags							See MEDIASESSIONFLAGS for details.
/// @param[in] outputConverter		MediaOutputRef which is setup to load the data in.
/// @param[in] selectionHandler		Optional handler which is called to filter which elements should be loaded.
/// @param[in] progressCallback		Optional callback to receive the progress of the loader.
/// @param[in] preferredHandler		This is a optional parameter which allows to give a preferred handler (which could be already detected before).
/// @return												A valid MediaSessionRef on success. This session can optionally be used to load subsequent images into the same buffers be calling session.Convert(time) again.
//----------------------------------------------------------------------------------------
Result<MediaSessionRef> MediaSessionImport(const Url& fileName, const TimeValue& targetTime, MEDIASESSIONFLAGS flags,
	const MediaOutputRef& outputConverter, const MediaOutputSelectionHandler& selectionHandler,
	const MediaSessionProgressCallback& progressCallback, const FileFormatHandler& preferredHandler);



} // namespace maxon


#endif // MEDIASESSION_OUTPUT_H__
