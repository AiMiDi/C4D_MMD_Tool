#ifndef MEDIASESSION_MOVIE_IMPORT_WINMF_H__
#define MEDIASESSION_MOVIE_IMPORT_WINMF_H__

#include "maxon/mediasession_image_export.h"
#include "maxon/mediasession_fileformats.h"

namespace maxon
{


// system specific implementations
#ifdef MAXON_TARGET_WINDOWS

// This definition needs to be separated in it's own header file, otherwise we will end up in a circular dependency
namespace FileFormats
{
	MAXON_DECLARATION(FileFormat, MovieWinMF, "net.maxon.fileformat.moviewinmf");		// Windows Media Foundation file format
	MAXON_DECLARATION(FileFormat, MovieMP4, "net.maxon.fileformat.moviemp4");				// MP4 file format
	MAXON_DECLARATION(FileFormat, MovieWMV, "net.maxon.fileformat.moviewmv");				// WMV file format
	MAXON_DECLARATION(FileFormat, MovieASF, "net.maxon.fileformat.movieasf");				// ASF file format
	MAXON_DECLARATION(FileFormat, Movie3GP, "net.maxon.fileformat.movie3gp");				// 3GP file format
	MAXON_DECLARATION(FileFormat, MovieAVI, "net.maxon.fileformat.movieavi");				// MP4 file format

	MAXON_DECLARATION(FileFormat, AudioWinMF, "net.maxon.fileformat.audiowinmf");		// Windows Media Foundation file format
}

namespace FileFormatHandlers
{
	MAXON_DECLARATION(FileFormatHandler, MovieWinMF, "net.maxon.fileformathandler.moviewinmf");	// Windows Media Foundation
	MAXON_DECLARATION(FileFormatHandler, AudioWinMF, "net.maxon.fileformathandler.audiowinmf");	// Windows Media Foundation
};

#endif

// we need to process everything in LONGLONG timestamps as windows uses it. Otherwise we get rounding errors and missing frames.
inline Int64 ToWindowsTime(const TimeValue& time)
{
	return Int64(time.GetMicroseconds() * 10.0 + 0.5);
}

inline TimeValue ToMaxonTime(Int64 time)
{
	return Nanoseconds(time * 100.0);
}

inline Vec2<Int> FpsToInt(Float fps)
{
	Int fpsDen = 1000000;
	Int fpsNom = Seconds(fps).GetFrame(Float(fpsDen));
	while ((fpsNom != 0) && (fpsNom % 10) == 0 && (fpsDen != 0) && (fpsDen % 10) == 0)
	{
		fpsDen /= 10;
		fpsNom /= 10;
	}
	return Vec2<Int>(fpsNom, fpsDen);
}

} // namespace maxon


#endif // MEDIASESSION_MOVIE_IMPORT_WINMF_H__
