#ifndef MEDIASESSION_IMAGE_EXPORT_TIFF_H__
#define MEDIASESSION_IMAGE_EXPORT_TIFF_H__


#include "maxon/mediasession_image_export.h"

#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
	// TODO: (Seb) don't know why
	#include "maxon/fileformat_handler.h"
#endif

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MEDIASESSION
{
	namespace TIFF
	{
		namespace EXPORT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.mediasession.tiff.export");

			/// Byte order to save
			/// - ibmpc mode (little endian)
			/// - motorola mode (big endian)
			MAXON_ATTRIBUTE(Id, BYTEORDER, "net.maxon.mediasession.tiff.export.byteorder",
				RESOURCE_DEFINE(ENUM_IBMPC, Id("ibmpc"))
				RESOURCE_DEFINE(ENUM_MOTOROLA, Id("motorola")));

			MAXON_ATTRIBUTE(Id, COMPRESSION, "net.maxon.mediasession.tiff.export.compression",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_PACKBITS, Id("packbits"))
				RESOURCE_DEFINE(ENUM_LZW, Id("lzw"))
				RESOURCE_DEFINE(ENUM_JPEG, Id("jpeg")));
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon
{

namespace ImageSaverClasses
{
	MAXON_DECLARATION(ImageSaverClasses::EntryType, Tif, MEDIASESSION::TIFF::EXPORT::GetId());	///< TIF image saver.
}

// include autogenerated headerfile here
#include "mediasession_image_export_tiff1.hxx"
#include "mediasession_image_export_tiff2.hxx"

} // namespace maxon

#endif // MEDIASESSION_IMAGE_EXPORT_TIFF_H__
