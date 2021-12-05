#if 1
namespace maxon
{
	namespace DATAFORMAT
	{
		COMPRESSION_PrivateAttribute COMPRESSION;
		NO_REFERENCES_PrivateAttribute NO_REFERENCES;
		ALLOW_DUPLICATES_PrivateAttribute ALLOW_DUPLICATES;
		SORTED_PrivateAttribute SORTED;
	}
	namespace DataFormatWriterFactories
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Binary, , "net.maxon.dataformatwriterfactory.binary");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Json, , "net.maxon.dataformatwriterfactory.json");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Xml, , "net.maxon.dataformatwriterfactory.xml");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatWriterBinaryClass, , "net.maxon.class.dataformatwriterbinary");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatWriterJsonClass, , "net.maxon.class.dataformatwriterjson");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatWriterXmlClass, , "net.maxon.class.dataformatwriterxml");
	namespace DataFormatReaderFactories
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Binary, , "net.maxon.dataformatreaderfactory.binary");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Json, , "net.maxon.dataformatreaderfactory.json");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Xml, , "net.maxon.dataformatreaderfactory.xml");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatReaderBinaryClass, , "net.maxon.class.dataformatreaderbinary");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatReaderJsonClass, , "net.maxon.class.dataformatreaderjson");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataFormatReaderXmlClass, , "net.maxon.class.dataformatreaderxml");
}
#endif
