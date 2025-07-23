#ifndef MEDIASESSION_STREAMFORMAT_H__
#define MEDIASESSION_STREAMFORMAT_H__


#include "maxon/mediasession_base.h"
#include "maxon/datadictionaryobject.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// Single Stream within a MediaConverterInterface.
//----------------------------------------------------------------------------------------
class MediaStreamFormatInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(MediaStreamFormatInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.mediastreamformat", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

public:
	using RESTRICT_DICTIONARY_PROPS = MEDIAFORMAT::RESTRICT;
};



class MediaStreamFormat;
class MediaStreamRef;

//----------------------------------------------------------------------------------------
/// Single Stream within a MediaConverterInterface.
//----------------------------------------------------------------------------------------
class MediaStreamPropertiesInterface : MAXON_INTERFACE_BASES(MediaStreamFormatInterface)
{
	MAXON_INTERFACE(MediaStreamPropertiesInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.mediastreamproperties", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

public:
	using RESTRICT_DICTIONARY_PROPS = MEDIAPROPERTIES::RESTRICT;

	/// @MAXON_ANNOTATION{returnsThis}
	MAXON_METHOD Result<void> Init(const MediaStreamFormat& withFormat);

	/// @MAXON_ANNOTATION{returnsThis}
	MAXON_METHOD Result<void> Init(const MediaStreamRef& withStream);
};


// include auto generated header file here
#include "mediasession_streamformat1.hxx"

MAXON_DECLARATION(Class<MediaStreamFormat>, MediaStreamFormatClass, "net.maxon.image.class.mediastreamformat", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
MAXON_DECLARATION(Class<MediaStreamProperties>, MediaStreamPropertiesClass, "net.maxon.image.class.mediastreamproperties", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

// include auto generated header file here
#include "mediasession_streamformat2.hxx"


} // namespace maxon


#endif // MEDIASESSION_STREAMFORMAT_H__
