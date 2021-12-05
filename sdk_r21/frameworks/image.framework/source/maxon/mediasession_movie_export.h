#ifndef MEDIASESSION_MOVIE_EXPORT_H__
#define MEDIASESSION_MOVIE_EXPORT_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MEDIASESSION
{
	namespace ASF
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.asf.export");

			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION
			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::MF::EXPORT::SAMPLERATE
			// supports MAXON::MEDIASESSION::MF::EXPORT::KILOBITRATE
		}
	}

	namespace GP3
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.gp3.export");

			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION
			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::MF::EXPORT::SAMPLERATE
			// supports MAXON::MEDIASESSION::MF::EXPORT::KILOBITRATE
		}
	}

	namespace MF
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.mf.export");

			MAXON_ATTRIBUTE(maxon::Id, CODEC, "net.maxon.mediasession.mf.export.codec",
				RESOURCE_DEFINE(ENUM_H_264, maxon::Id("H.264"))
				RESOURCE_DEFINE(ENUM_WMV1, maxon::Id("WMV1"))
				RESOURCE_DEFINE(ENUM_WMV2, maxon::Id("WMV2"))
				RESOURCE_DEFINE(ENUM_WMV3, maxon::Id("WMV3"))
				RESOURCE_DEFINE(ENUM_PRORES422, maxon::Id("ProRes422"))
				RESOURCE_DEFINE(ENUM_PRORES4444, maxon::Id("ProRes4444"))
				RESOURCE_DEFINE(ENUM_JPEG, maxon::Id("JPEG")));

			// supports MAXON::MEDIASESSION::EXPORT::QUALITY
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION

			MAXON_ATTRIBUTE(maxon::Id, AUDIO_CODEC, "net.maxon.mediasession.mf.export.audio.codec",
				RESOURCE_DEFINE(ENUM_AAC, maxon::Id("aac"))
				RESOURCE_DEFINE(ENUM_MP3, maxon::Id("mp3")));

			MAXON_ATTRIBUTE(maxon::Int, AUDIO_SAMPLERATE, "net.maxon.mediasession.mf.export.audio.samplerate",
				RESOURCE_DEFINE(ENUM_32000, 32000)
				RESOURCE_DEFINE(ENUM_44100, 44100)
				RESOURCE_DEFINE(ENUM_48000, 48000)
				RESOURCE_DEFINE(ENUM_96000, 96000));

			MAXON_ATTRIBUTE(maxon::Int, AUDIO_KILOBITRATE, "net.maxon.mediasession.mf.export.audio.kilobitrate",
				RESOURCE_DEFINE(ENUM_96, 96)
				RESOURCE_DEFINE(ENUM_112, 112)
				RESOURCE_DEFINE(ENUM_128, 128)
				RESOURCE_DEFINE(ENUM_160, 160)
				RESOURCE_DEFINE(ENUM_192, 192)
				RESOURCE_DEFINE(ENUM_224, 224)
				RESOURCE_DEFINE(ENUM_256, 256)
				RESOURCE_DEFINE(ENUM_320, 320));
		}
	}

	namespace MOV
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.mov.export");

			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION
			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::MF::EXPORT::SAMPLERATE
			// supports MAXON::MEDIASESSION::MF::EXPORT::KILOBITRATE
		}
	}

	namespace MP4
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.mp4.export");

			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION
			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::MF::EXPORT::SAMPLERATE
			// supports MAXON::MEDIASESSION::MF::EXPORT::KILOBITRATE
		}
	}

	namespace WMV
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.wmv.export");

			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::EXPORT::DATARATE
			// supports MAXON::MEDIASESSION::EXPORT::KEYFRAMES
			// supports MAXON::MEDIASESSION::EXPORT::DISABLESRGBCONVERSION
			// supports MAXON::MEDIASESSION::MF::EXPORT::CODEC
			// supports MAXON::MEDIASESSION::MF::EXPORT::SAMPLERATE
			// supports MAXON::MEDIASESSION::MF::EXPORT::KILOBITRATE
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------



#include "mediasession_movie_export1.hxx"
#include "mediasession_movie_export2.hxx"

#endif // MEDIASESSION_MOVIE_EXPORT_H__
