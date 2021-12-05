#ifndef MEDIASESSION_AUDIODATA_H__
#define MEDIASESSION_AUDIODATA_H__


#include "maxon/mediasession_stream.h"
#include "maxon/audioobject.h"


namespace maxon
{

class MediaStreamAudioDataExportRef;

//----------------------------------------------------------------------------------------
/// Stream which represents sound data.
//----------------------------------------------------------------------------------------
class MediaStreamAudioDataExportInterface : MAXON_INTERFACE_BASES(MediaStreamInterface)
{
	MAXON_INTERFACE(MediaStreamAudioDataExportInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediastreamaudiodataexport");

public:
	//----------------------------------------------------------------------------------------
	/// InitWithAudioData init with a given soundDataRef.
	/// @param[in] audioData					Audio data to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitWithAudioData(const AudioObjectRef& audioData);

	//----------------------------------------------------------------------------------------
	/// Returns the object given at Init.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AudioObjectRef GetAudioObject() const;

	//----------------------------------------------------------------------------------------
	/// Subscribes to the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetCallbackHandler();

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation before loading a stream.
	/// @param[in] props							Properties of the image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props);

	//----------------------------------------------------------------------------------------
	/// called by the input media converter implementation when loading the stream is completed.
	/// @param[in] props							Properties of the image stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props);
};



// include auto generated header file here
#include "mediasession_audiodata1.hxx"

MAXON_DECLARATION(Class<MediaStreamAudioDataExportRef>, MediaStreamAudioDataExportClass, "net.maxon.image.class.mediastreamaudiodataexport");

// include auto generated header file here
#include "mediasession_audiodata2.hxx"



} // namespace maxon


#endif // MEDIASESSION_AUDIODATA_H__
