#ifndef DATAFORMAT_BINARY_H__
#define DATAFORMAT_BINARY_H__


#include "maxon/dataformat.h"
#include "maxon/factory.h"

namespace maxon
{


#include "dataformat_binary1.hxx"

//----------------------------------------------------------------------------------------
/// Parameters for DataFormatReader/Writer.
//----------------------------------------------------------------------------------------
namespace DATAFORMAT
{
	MAXON_ATTRIBUTE(Id, COMPRESSION, "net.maxon.dataformat.compression");						///< Enable compression during write for binary format. The performance hit is modest.
	MAXON_ATTRIBUTE(Bool, NO_REFERENCES, "net.maxon.dataformat.no_references");				///< Write all references directly as non-referenced objects (text formats only).
																							///< It does not support writing of WeakRefs to COW objects. Can increase the file size a lot.
	MAXON_ATTRIBUTE(Bool, ALLOW_DUPLICATES, "net.maxon.dataformat.allow_duplicates");		///< If false, all identical Id/InternedId/CString/String objects will only be written once (binary format only).
																							///< Decreases the file size. It slightly increases memory usage and decreases performance while writing.
	MAXON_ATTRIBUTE(Bool, SORTED, "net.maxon.dataformat.sorted");							///< Sort all maps and sets when writing (text formats only). This slightly increases memory usage and decreases performance while writing.
}

namespace DataFormatWriterFactories
{
	MAXON_DECLARATION(DataFormatWriterFactory, Binary, "net.maxon.dataformatwriterfactory.binary");

	MAXON_DECLARATION(DataFormatWriterFactory, Json, "net.maxon.dataformatwriterfactory.json");

	MAXON_DECLARATION(DataFormatWriterFactory, Xml, "net.maxon.dataformatwriterfactory.xml");
}

MAXON_DECLARATION(Class<DataFormatWriterRef>, DataFormatWriterBinaryClass, "net.maxon.class.dataformatwriterbinary");
MAXON_DECLARATION(Class<DataFormatWriterRef>, DataFormatWriterJsonClass, "net.maxon.class.dataformatwriterjson");
MAXON_DECLARATION(Class<DataFormatWriterRef>, DataFormatWriterXmlClass, "net.maxon.class.dataformatwriterxml");

namespace DataFormatReaderFactories
{
	MAXON_DECLARATION(DataFormatReaderFactory, Binary, "net.maxon.dataformatreaderfactory.binary");

	MAXON_DECLARATION(DataFormatReaderFactory, Json, "net.maxon.dataformatreaderfactory.json");

	MAXON_DECLARATION(DataFormatReaderFactory, Xml, "net.maxon.dataformatreaderfactory.xml");
}

MAXON_DECLARATION(Class<DataFormatReaderRef>, DataFormatReaderBinaryClass, "net.maxon.class.dataformatreaderbinary");
MAXON_DECLARATION(Class<DataFormatReaderRef>, DataFormatReaderJsonClass, "net.maxon.class.dataformatreaderjson");
MAXON_DECLARATION(Class<DataFormatReaderRef>, DataFormatReaderXmlClass, "net.maxon.class.dataformatreaderxml");

#include "dataformat_binary2.hxx"

}


#endif // DATAFORMAT_BINARY_H__
