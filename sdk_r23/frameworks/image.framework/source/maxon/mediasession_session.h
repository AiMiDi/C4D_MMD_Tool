#ifndef MEDIASESSION_SESSION_H__
#define MEDIASESSION_SESSION_H__

#include "maxon/interface.h"
#include "maxon/timevalue.h"
#include "maxon/mediasession_progress.h"

namespace maxon
{

class MediaConverterRef;
class MediaSessionRef;

enum class MEDIASESSIONFLAGS
{
	NONE = 0,
	RUNONLYANALYZE = 1 << 0, ///< run only the analyze but not the execute pass.
	FORCELOAD = 1 << 1,			 ///< loads the image even if it's already loaded.
} MAXON_ENUM_FLAGS(MEDIASESSIONFLAGS);

//----------------------------------------------------------------------------------------
/// The media session interface connects media inputs with media outputs.
/// For each output a MediaConnectionRef is handled.
/// @MAXON_ANNOTATION{nullimpl=true}
//----------------------------------------------------------------------------------------
class MediaSessionInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(MediaSessionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediasession");

public:
	//----------------------------------------------------------------------------------------
	/// Connects two MediaConverterRefs within a Media Session. Both converters must not be attached to another session.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output);

	//----------------------------------------------------------------------------------------
	/// Triggers the session to read the next frame from the stream.
	/// @param[in] targetTime					Target time to receive the media samples from.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Closes the session, finalizes all write operations and closes all handles.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close();

	//----------------------------------------------------------------------------------------
	/// Returns the progress object to set/get progress for implementors.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD MediaSessionProgressRef GetProgress() const;
};


// include auto generated header file here
#include "mediasession_session1.hxx"

MAXON_DECLARATION(Class<MediaSessionRef>, MediaSessionObject, "net.maxon.image.class.mediasessionobject");

// include auto generated header file here
#include "mediasession_session2.hxx"


} // namespace maxon


#endif // MEDIASESSION_SESSION_H__
