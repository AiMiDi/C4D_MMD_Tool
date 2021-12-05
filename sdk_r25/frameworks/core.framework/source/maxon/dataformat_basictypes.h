#ifndef DATAFORMAT_BASICTYPES_H__
#define DATAFORMAT_BASICTYPES_H__


#include "maxon/dataformat_base.h"
#include "maxon/factory.h"
#include "maxon/fid.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Binary format implementation of DataSerializeReaderInterface.
//----------------------------------------------------------------------------------------
namespace DataFormatBaseReader
{
	MAXON_DECLARATION(Factory<DataFormatBaseReaderRef(const Url&)>, FromUrl, "net.maxon.dataformatbasereader.fromurl");
	MAXON_DECLARATION(Factory<DataFormatBaseReaderRef(const InputStreamRef&)>, FromStream, "net.maxon.dataformatbasereader.fromstream");
	MAXON_DECLARATION(Factory<DataFormatBaseReaderRef(const String&)>, FromString, "net.maxon.dataformatbasereader.fromstring");
}

//----------------------------------------------------------------------------------------
/// Binary format implementation of DataSerializeWriterInterface.
//----------------------------------------------------------------------------------------
namespace DataFormatBaseWriter
{
	MAXON_DECLARATION(Factory<DataFormatBaseWriterRef(const Url&)>, ToUrl, "net.maxon.dataformatbasewriter.tourl");
	MAXON_DECLARATION(Factory<DataFormatBaseWriterRef(const OutputStreamRef&)>, ToStream, "net.maxon.dataformatbasewriter.tostream");
	MAXON_DECLARATION(Factory<DataFormatBaseWriterRef(String&)>, ToString, "net.maxon.dataformatbasewriter.tostring");
}

}



#endif // DATAFORMAT_BASICTYPES_H__
