#ifndef MEDIASESSION_INPUT_H__
#define MEDIASESSION_INPUT_H__

#include "maxon/mediasession_converter.h"



namespace maxon
{

namespace MEDIAINPUTPROPERTIES
{
	/// Returns if the loader can read video data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_IMAGE, "net.maxon.media.input.supports_image");

	/// Returns if the loader can read video data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_VIDEO, "net.maxon.media.input.supports_video");

	/// Returns if the loader can read audio data
	MAXON_ATTRIBUTE(Bool, SUPPORTS_AUDIO, "net.maxon.media.input.supports_audio");
}

//----------------------------------------------------------------------------------------
/// The MediaInputInterface class provides an specific implementation to provide input data from a given source.
//----------------------------------------------------------------------------------------
class MediaInputInterface : MAXON_INTERFACE_BASES(MediaConverterInterface)
{
	MAXON_INTERFACE(MediaInputInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediainput");

public:
};


// include auto generated header file here
#include "mediasession_input1.hxx"

// include auto generated header file here
#include "mediasession_input2.hxx"


} // namespace maxon


#endif // MEDIASESSION_INPUT_H__
