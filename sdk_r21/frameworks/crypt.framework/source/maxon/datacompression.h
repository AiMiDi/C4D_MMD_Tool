#ifndef DATACOMPRESSION_H__
#define DATACOMPRESSION_H__

#include "maxon/object.h"
#include "maxon/datadictionary.h"
#include "maxon/array.h"
#include "maxon/streamconversion.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace STREAMCONVERSION
{
	namespace GZIP
	{
		//----------------------------------------------------------------------------------------
		/// Options for "gzip" decoder
		//----------------------------------------------------------------------------------------
		namespace DECODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.gzip.decoder");
		}

		//----------------------------------------------------------------------------------------
		/// Options for "gzip" compression
		//----------------------------------------------------------------------------------------
		namespace ENCODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.gzip.encoder");

			/// Compression strength, 0: less compression (faster), 9: best compression (slower). Default is 5.
			MAXON_ATTRIBUTE(maxon::Int, COMPRESSION, "net.maxon.streamconversion.gzip.encoder.compression",
				RESOURCE_DEFINE(ENUM_FAST, 0)
				RESOURCE_DEFINE(ENUM_DEFAULT, 5)
				RESOURCE_DEFINE(ENUM_BEST, 9));
		}
	}

	namespace LC4D
	{
		//----------------------------------------------------------------------------------------
		/// Options for "lc4d" decoder
		//----------------------------------------------------------------------------------------
		namespace DECODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.lc4d.decoder");
		}

		//----------------------------------------------------------------------------------------
		/// Options for "lc4d" encoder
		//----------------------------------------------------------------------------------------
		namespace ENCODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.lc4d.encoder");
		}
	}

	namespace LZ4
	{
		//----------------------------------------------------------------------------------------
		/// Options for "lz4" decoder
		//----------------------------------------------------------------------------------------
		namespace DECODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.lz4.decoder");

			/// Specify if more then one cpu should be used. Default is true (= faster).
			MAXON_ATTRIBUTE(maxon::Bool, MULTITHREADING, "net.maxon.streamconversion.lz4.decoder.multithreading");
		}

		//----------------------------------------------------------------------------------------
		/// Options for "lz4" compression
		//----------------------------------------------------------------------------------------
		namespace ENCODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.lz4.encoder");

			/// Compression strength, 0 - 2: less compression (fastest), 3- 16: better compression (slower). Default is 0.
			MAXON_ATTRIBUTE(maxon::Int, COMPRESSION, "net.maxon.streamconversion.lz4.encoder.compression",
				RESOURCE_DEFINE(ENUM_DEFAULT, 0)
				RESOURCE_DEFINE(ENUM_FAST, 2)
				RESOURCE_DEFINE(ENUM_BEST, 16));

			/// True if additional checksum chunks are generated when encoding. Default is false.
			MAXON_ATTRIBUTE(maxon::Bool, STREAMCHECKSUM, "net.maxon.streamconversion.lz4.encoder.streamchecksum");

			/// Specify if more then one cpu should be used. Default is true (= faster).
			MAXON_ATTRIBUTE(maxon::Bool, MULTITHREADING, "net.maxon.streamconversion.lz4.encoder.multithreading");
		}
	}

	namespace RLE
	{
		//----------------------------------------------------------------------------------------
		/// Options for "rle" decoder
		//----------------------------------------------------------------------------------------
		namespace DECODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.rle.decoder");
		}

		//----------------------------------------------------------------------------------------
		/// Options for "rle" encoder
		//----------------------------------------------------------------------------------------
		namespace ENCODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.rle.encoder");
		}
	}

	namespace ZIP
	{
		//----------------------------------------------------------------------------------------
		/// Options for "zip" decoder
		//----------------------------------------------------------------------------------------
		namespace DECODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.zip.decoder");
		}

		//----------------------------------------------------------------------------------------
		/// Options for "zip" compression
		//----------------------------------------------------------------------------------------
		namespace ENCODER
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.streamconversion.zip.encoder");

			/// Compression strength, 0: less compression (faster), 9: best compression (slower). Default is 5.
			MAXON_ATTRIBUTE(maxon::Int, COMPRESSION, "net.maxon.streamconversion.zip.encoder.compression",
				RESOURCE_DEFINE(ENUM_FAST, 0)
				RESOURCE_DEFINE(ENUM_DEFAULT, 5)
				RESOURCE_DEFINE(ENUM_BEST, 9));

			/// True if the size of the block should be written to the first 4 byte or read from the 4 byte. Default is false.
			MAXON_ATTRIBUTE(maxon::Bool, WRITESIZE, "net.maxon.streamconversion.zip.encoder.writesize");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon
{

/// @addtogroup Data Compression
/// @{

#include "datacompression1.hxx"

namespace StreamConversions
{
	/// Zip compression (see StreamConversions::ZipEncoderOptions for options).<br>
	MAXON_DECLARATION(StreamConversionFactory, ZipEncoder, STREAMCONVERSION::ZIP::ENCODER::GetId());
	MAXON_DECLARATION(StreamConversionFactory, ZipDecoder, STREAMCONVERSION::ZIP::DECODER::GetId());

	/// GZip compression with gzip header (e.g. used by gzip http encoding).<br>
	MAXON_DECLARATION(StreamConversionFactory, GZipEncoder, STREAMCONVERSION::GZIP::ENCODER::GetId());
	MAXON_DECLARATION(StreamConversionFactory, GZipDecoder, STREAMCONVERSION::GZIP::DECODER::GetId());

	/// Run Length Encoding.<br>
	MAXON_DECLARATION(StreamConversionFactory, RleEncoder, STREAMCONVERSION::RLE::ENCODER::GetId());
	MAXON_DECLARATION(StreamConversionFactory, RleDecoder, STREAMCONVERSION::RLE::DECODER::GetId());

	/// LZ4 compression.<br>
	MAXON_DECLARATION(StreamConversionFactory, Lz4Encoder, STREAMCONVERSION::LZ4::ENCODER::GetId());
	MAXON_DECLARATION(StreamConversionFactory, Lz4Decoder, STREAMCONVERSION::LZ4::DECODER::GetId());

	/// LZ4 compression.<br>
	MAXON_DECLARATION(StreamConversionFactory, Lc4dEncoder, STREAMCONVERSION::LC4D::ENCODER::GetId());
	MAXON_DECLARATION(StreamConversionFactory, Lc4dDecoder, STREAMCONVERSION::LC4D::DECODER::GetId());

}

#include "datacompression2.hxx"

/// @}

} // namespace maxon


#endif // DATACOMPRESSION_H__
