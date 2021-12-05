#ifndef MEDIASESSION_ERRORS_H__
#define MEDIASESSION_ERRORS_H__


#include "maxon/objectbase.h"



namespace maxon
{



//----------------------------------------------------------------------------------------
/// Wrong image type error.
/// This error is returned if the file structure of an image is corrupted.
//----------------------------------------------------------------------------------------
class MediaSessionWrongTypeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(MediaSessionWrongTypeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.mediasessionwrongtypeerror");
};

//----------------------------------------------------------------------------------------
/// End of Media Stream is reached.
//----------------------------------------------------------------------------------------
class MediaStreamEOFErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(MediaStreamEOFErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.mediastreameoferror");
};



// include auto generated header file here
#include "mediasession_errors1.hxx"

// include auto generated header file here
#include "mediasession_errors2.hxx"


} // namespace maxon


#endif // MEDIASESSION_ERRORS_H__
