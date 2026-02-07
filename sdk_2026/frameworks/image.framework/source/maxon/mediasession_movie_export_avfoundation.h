#ifndef MEDIASESSION_MOVIE_EXPORT_AVFOUNDATION_H__
#define MEDIASESSION_MOVIE_EXPORT_AVFOUNDATION_H__

#include "maxon/mediasession_image_export.h"
#include "maxon/mediasession_fileformats.h"

namespace maxon
{


// system specific implementations
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)

// This definition needs to be separated in it's own header file, otherwise we will end up in a circular dependency
namespace FileFormats
{
	MAXON_DECLARATION(FileFormat, MovieMP4, "net.maxon.fileformat.moviemp4");					// MP4 file format (H264 only)
	MAXON_DECLARATION(FileFormat, MovieMov, "net.maxon.fileformat.moviemov");					// MOV file format (ProRes422/4444, H264, M-JPEG)
}

#endif

} // namespace maxon


#endif // MEDIASESSION_MOVIE_EXPORT_AVFOUNDATION_H__
