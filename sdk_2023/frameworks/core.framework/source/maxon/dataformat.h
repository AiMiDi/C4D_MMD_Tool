#ifndef DATAFORMAT_H__
#define DATAFORMAT_H__

#include "maxon/dataserialize.h"
#include "maxon/dataformat_base.h"
#include "maxon/factory.h"

namespace maxon
{


//----------------------------------------------------------------------------------------
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
//----------------------------------------------------------------------------------------
class DataFormatReaderInterface : MAXON_INTERFACE_BASES(DataFormatBaseReaderInterface, DataSerializeReaderInterface)
{
	MAXON_INTERFACE(DataFormatReaderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataformatreader");
public:
};

//----------------------------------------------------------------------------------------
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
//----------------------------------------------------------------------------------------
class DataFormatWriterInterface : MAXON_INTERFACE_BASES(DataFormatBaseWriterInterface, DataSerializeWriterInterface)
{
	MAXON_INTERFACE(DataFormatWriterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataformatwriter");
public:
};


#include "dataformat1.hxx"


using DataFormatReaderFactory = Factory<DataFormatReaderRef(UrlOrInputStream&&)>;

//----------------------------------------------------------------------------------------
/// Registry to register/iterate all available DataSerialize Reader implementations.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(DataFormatReaderFactory, DataFormatReaderFactories, "net.maxon.registry.dataformatreaderfactories");


using DataFormatWriterFactory = Factory<DataFormatWriterRef(UrlOrOutputStream&&)>;

//----------------------------------------------------------------------------------------
/// Registry to register/iterate all available DataSerialize Writer implementations.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(DataFormatWriterFactory, DataFormatWriterFactories, "net.maxon.registry.dataformatwriterfactories");


#include "dataformat2.hxx"

}

#endif // DATAFORMAT_H__
