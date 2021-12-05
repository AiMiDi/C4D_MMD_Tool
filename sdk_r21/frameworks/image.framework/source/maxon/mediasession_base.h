#ifndef MEDIASESSION_BASE_H__
#define MEDIASESSION_BASE_H__

#include "maxon/bytesvalue.h"
#include "maxon/datadescriptionobject.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/gfx_image_pixelformat.h"
#include "maxon/mediasession_session.h"
#include "maxon/object.h"
#include "maxon/timevalue.h"


//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MEDIASESSION
{
	namespace EXPORT
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.export");

		/// Quality factor 0 .. worst, 1.0 best quality, unit percent.
		MAXON_ATTRIBUTE(maxon::Float, QUALITY, "net.maxon.mediasession.export.quality");

		/// Average data rate in bytes
		MAXON_ATTRIBUTE(maxon::BytesValue, DATARATE, "net.maxon.mediasession.export.datarate");

		/// Key frame every X frames
		MAXON_ATTRIBUTE(maxon::Int32, KEYFRAMES, "net.maxon.mediasession.export.keyframes");

		/// True if image data should not be converted to srgb if the file format doesn't support color profiles.
		MAXON_ATTRIBUTE(maxon::Bool, DISABLESRGBCONVERSION, "net.maxon.mediasession.export.disablesrgbconversion");

		/// Custom compressor settings
		MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Char>, CUSTOMDATA, "net.maxon.mediasession.export.customdata");

		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.export.base");

			MAXON_ATTRIBUTE(Group, MF_EXPORT_GROUP_PRESETS, "net.maxon.mediasession.mf.export.group.presets");

			MAXON_ATTRIBUTE(Group, MF_EXPORT_GROUP_OPTIONS, "net.maxon.mediasession.mf.export.group.options");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon
{

class ColorProfile;
class DataDescription;
class ImagePixelBlend;


namespace MEDIASTREAM
{
	MAXON_ATTRIBUTE(Bool, DUMMY, "net.maxon.mediastream.dummy");				///< Dummy Entry can be removed as soon as one useful entry is defined
}



//----------------------------------------------------------------------------------------
/// MEDIAFORMAT::IMAGE::TYPE specifies the meaning of the stream.
//----------------------------------------------------------------------------------------
enum class MEDIAFORMATTYPE
{
	UNDEFINED,				///< Must never happen! This value should not be used and should never appear.

	IMAGE,						///< This is the image resource of the stream. This could be the only one in the stream.
	ALPHA,						///< Declares the stream to be interpreted as the alpha channel of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE.
	LAYERFOLDER,			///< Declares the stream to be interpreted as a group layer of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE or another MEDIAFORMATTYPE::LAYERFOLDER.
	LAYER,						///< Declares the stream to be interpreted as a layer of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE or another MEDIAFORMATTYPE::LAYERGROUP.
	LAYERADJUSTMENT,	///< Declares the stream to be interpreted as a adjustment layer of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE or another MEDIAFORMATTYPE::LAYERFOLDER.
	LAYERMASK,				///< Declares the stream to be interpreted as a layer mask of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::LAYER, MEDIAFORMATTYPE::LAYERADJUSTMENT or MEDIAFORMATTYPE::LAYERFOLDER.
	MIPMAP,						///< Declares the stream to be interpreted as mipmap of the parent stream. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE.
	DEEPIMAGEDATA,		///< Declares the stream to be interpreted as a deep image data. This stream must be inserted under a MEDIAFORMATTYPE::IMAGE.
} MAXON_ENUM_LIST(MEDIAFORMATTYPE);



//----------------------------------------------------------------------------------------
/// MEDIAFORMAT::IMAGE::ALPHATYPE specifies the meaning of the stream.
//----------------------------------------------------------------------------------------
enum class MEDIAALPHATYPE
{
	UNDEFINED,			///< Undefined.
	PREMULTIPLIED,	///< The alpha is related to premultiplied rgb data.
	STRAIGHT,				///< The alpha is related to straight rgb data.
} MAXON_ENUM_LIST(MEDIAALPHATYPE);



//----------------------------------------------------------------------------------------
/// Properties for MediaStreamFormatInterface Set()/Get().
/// This are all properties that needs to be set in the Analyze() pass of the media stream conversion.
//----------------------------------------------------------------------------------------
namespace MEDIAFORMAT
{
	namespace IMAGE
	{
		MAXON_ATTRIBUTE(MEDIAFORMATTYPE, TYPE, "net.maxon.mediaformat.type");											///< Sub type of the image stream. see MEDIAFORMATTYPE.
		MAXON_ATTRIBUTE(Int, SUBIMAGEINDEX, "net.maxon.mediaformat.subimageindex");												///< index of the subimage, this value is necessary for MEDIAFORMATTYPE::IMAGE, for all other types optional/n.a. The index start counting at 0.
		MAXON_ATTRIBUTE(PixelFormat, PIXELFORMAT, "net.maxon.mediaformat.pixelformat");									///< Pixel format
		MAXON_ATTRIBUTE(ColorProfile, COLORPROFILE, "net.maxon.mediaformat.colorprofile");								///< Color profile
		MAXON_ATTRIBUTE(Int, WIDTH, "net.maxon.mediaformat.width");																///< Image width
		MAXON_ATTRIBUTE(Int, HEIGHT, "net.maxon.mediaformat.height");																///< Image height
		MAXON_ATTRIBUTE(Float, ASPECTRATIO, "net.maxon.mediaformat.aspectratio", RESOURCE_DEFAULT(1.0));	///< Optional: Pixel aspect ratio.
		MAXON_ATTRIBUTE(Float, DPI, "net.maxon.mediaformat.dpi");																///< Optional: DPI (dots per inch) value.
		MAXON_ATTRIBUTE(String, STREAMNAME, "net.maxon.mediaformat.streamname");												///< Optional: stream/layer name
		MAXON_ATTRIBUTE(String, ALPHANAME, "net.maxon.mediaformat.alphaname");													///< Optional: alpha name
		MAXON_ATTRIBUTE(MEDIAALPHATYPE, ALPHATYPE, "net.maxon.mediaformat.alphatype");									///< Optional: Defines the interpretation of the Alpha Channel (see MEDIAALPHATYPE).
		MAXON_ATTRIBUTE(Bool, LAYERALPHA, "net.maxon.mediaformat.layeralpha", RESOURCE_DEFAULT(false));	///< Optional: MEDIAFORMATTYPE::IMAGE might have an alpha channel in the pixelformat which us a automatic generated alpha from the image layers.
		MAXON_ATTRIBUTE(Bool, DEEPIMAGE, "net.maxon.mediaformat.deepimage");														///< Optional: True if this image contains deep image data (0...n samples per pixel)
		MAXON_ATTRIBUTE(Int, HOTSPOTX, "net.maxon.mediaformat.hotspotx");															///< Hotspot x coordinate of a pointer/cursor.
		MAXON_ATTRIBUTE(Int, HOTSPOTY, "net.maxon.mediaformat.hotspoty");															///< Hotspot y coordinate of a pointer/cursor.
	}
	namespace IMAGELAYER
	{
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_X, "net.maxon.mediaformat.layer.boundingbox_x");								///< top left corner of the region filled with pixel data.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_Y, "net.maxon.mediaformat.layer.boundingbox_y");								///< top left corner of the region filled with pixel data.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_W, "net.maxon.mediaformat.layer.boundingbox_w");								///< width of the region filled with pixel data.
		MAXON_ATTRIBUTE(Int, BOUNDINGBOX_H, "net.maxon.mediaformat.layer.boundingbox_h");								///< height of the region filled with pixel data.
		MAXON_ATTRIBUTE(Bool, ENABLED, "net.maxon.mediaformat.layer.enabled");											///< true if layer is enabled
		MAXON_ATTRIBUTE(Bool, TRANSPARENCYPROTECTED, "net.maxon.mediaformat.layer.transparencyprotected");				///< true if layer transparency is protected
		MAXON_ATTRIBUTE(Float, OPACITY, "net.maxon.mediaformat.layer.opacity");										///< layer opacity 0.0 ... 1.0
		MAXON_ATTRIBUTE(Float, FILLOPACITY, "net.maxon.mediaformat.layer.fillopacity");								///< layer fill opacity 0.0 ... 1.0
		MAXON_ATTRIBUTE(ImagePixelBlend, BLENDMODE, "net.maxon.mediaformat.layer.blendmode");				///< layer blend mode see ImagePixelBlend.
		MAXON_ATTRIBUTE(Int, LAYERGROUP, "net.maxon.mediaformat.layer.layergroup");										///< group id for grouped layers
		MAXON_ATTRIBUTE(Pix8u, MASKDEFCOLOR, "net.maxon.mediaformat.layer.maskdefcolor");								///< default mask color 0..255
		namespace FOLDER
		{
			MAXON_ATTRIBUTE(Bool, ISOPEN, "net.maxon.mediaformat.layer.isopen");										///< true if the layer folder is opened in the ui
		}
		namespace ADJUSTMENT
		{
			MAXON_ATTRIBUTE(Int, PSD_FILTERID, "net.maxon.mediaformat.layer.psd_filterid");								///< adjustment layer filter id
			MAXON_ATTRIBUTE(BaseArray<Char>, PSD_DATA, "net.maxon.mediaformat.layer.psd_data");				///< adjustment layer data
		}
	}
	namespace VIDEO
	{
		MAXON_ATTRIBUTE(Float, FPS, "net.maxon.mediaformat.video.fps");													///< Video: Average frames per second of the stream

		static const Float UNKNOWNFPS = LIMIT<Float>::Max();
		MAXON_ATTRIBUTE(TimeValue, STARTTIME, "net.maxon.mediaformat.video.starttime");								///< Video: Start time of the the stream. TIMEVALUE_INVALID is returned to indicate an unknown start time (assume 0).
		MAXON_ATTRIBUTE(TimeValue, DURATION, "net.maxon.mediaformat.video.duration");									///< Video: Duration of the stream, TIMEVALUE_INFINITE is set if the stream length is infinite/unknown. If STARTTIME and DURATION are valid the video track ends at STARTTIME + DURATION.
	}
	namespace AUDIO
	{
		MAXON_ATTRIBUTE(Int, CHANNELCOUNT, "net.maxon.mediaformat.audio.channelcount");													///< Number of channels
		MAXON_ATTRIBUTE(Int, BITSPERCHANNEL, "net.maxon.mediaformat.audio.bitsperchannel");												///< Bits per single channel
		MAXON_ATTRIBUTE(Float, SAMPLERATE, "net.maxon.mediaformat.audio.samplerate");													///< sample rate
		MAXON_ATTRIBUTE(BaseArray<DataDictionary>, MARKERARRAY, "net.maxon.mediaformat.audio.markerarray");		///< Array of marker DataDictionaries see MEDIAFORMAT::AUDIO::MARKERS.
		namespace MARKER
		{
			MAXON_ATTRIBUTE(Int, IDENTIFIER, "net.maxon.mediaformat.audio.marker.identifier");
			MAXON_ATTRIBUTE(TimeValue, POSITION, "net.maxon.mediaformat.audio.marker.position");
			MAXON_ATTRIBUTE(String, LABEL, "net.maxon.mediaformat.audio.marker.label");
			MAXON_ATTRIBUTE(String, NOTE, "net.maxon.mediaformat.audio.marker.note");
		}
	}

	MAXON_ATTRIBUTE(DataDictionary, EXPORTSETTINGS, "net.maxon.mediaformat.exportsettings");						///< Export: Custom export settings (see MEDIAEXPORTOPTIONS).
}

using BitDepthConfig = const DataType;



//----------------------------------------------------------------------------------------
/// Properties for MediaStreamPropertiesInterface Set()/Get()
/// This are all properties that are available in the Execute() pass of the media stream conversion.
//----------------------------------------------------------------------------------------
namespace MEDIAPROPERTIES
{
	namespace VIDEO
	{
		MAXON_ATTRIBUTE(TimeValue, SAMPLETIME, "net.maxon.mediaproperty.sampletime");						///< Movie: Time when the stream should be (dis-)played.
		MAXON_ATTRIBUTE(TimeValue, SAMPLEDURATION, "net.maxon.mediaproperty.sampleduration");				///< Movie: Length of the sample.
		MAXON_ATTRIBUTE(Int, SKIPPEDFRAMES, "net.maxon.mediaproperty.skippedframes");							///< Movie: Number of skipped frames since last call.
	}
}



//----------------------------------------------------------------------------------------
/// MediaSession Base Interface. This interface is the common base for all media converter classes.
//----------------------------------------------------------------------------------------
class MediaBaseInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface, DataDescriptionObjectInterface)
{
	MAXON_INTERFACE(MediaBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediabase");

public:
	//----------------------------------------------------------------------------------------
	/// PRIVATE
	/// @param[in] session						MediaSession to be used with this connection.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConnectToSession(const MediaSessionRef& session);

	//----------------------------------------------------------------------------------------
	/// Returns the connected essionRef of this connection.
	/// @return												If successful a valid MediaSessionRef will be returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MediaSessionRef GetSession() const;
};


// include auto generated header file here
#include "mediasession_base1.hxx"

MAXON_DECLARATION(Class<MediaBaseRef>, MediaBaseClass, "net.maxon.image.class.mediabase");

// include auto generated header file here
#include "mediasession_base2.hxx"

} // namespace maxon


#endif // MEDIASESSION_BASE_H__
