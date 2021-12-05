#ifndef MEDIASESSION_MOVIE_EXPORT_AVI_H__
#define MEDIASESSION_MOVIE_EXPORT_AVI_H__

#include "maxon/mediasession_image_export.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MEDIASESSION
{
	namespace AVI
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.avi.export");

			// supports MAXON::MEDIASESSION::EXPORT::QUALITY
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION

			/// COMPVARS::fccType
			MAXON_ATTRIBUTE(maxon::Int32, AVITYPE, "net.maxon.mediasession.avi.export.avitype");

			/// COMPVARS::fccHandler
			MAXON_ATTRIBUTE(maxon::Int32, AVIHANDLER, "net.maxon.mediasession.avi.export.avihandler");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#ifdef MAXON_TARGET_WINDOWS

namespace ImageSaverClasses
{
	MAXON_DECLARATION(ImageSaverClasses::EntryType, Avi, MEDIASESSION::AVI::EXPORT::GetId());	///< AVI movie saver.
}

#endif

#include "mediasession_movie_export_avi1.hxx"
#include "mediasession_movie_export_avi2.hxx"

}

#endif // MEDIASESSION_MOVIE_EXPORT_AVI_H__
