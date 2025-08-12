#if 1
namespace maxon
{
	const maxon::Char* const DataFormatReaderInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DataFormatReaderInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatReaderInterface, DataFormatReaderInterface, , , "net.maxon.interface.dataformatreader", (DataFormatBaseReaderInterface::PrivateGetInterface()), (DataSerializeReaderInterface::PrivateGetInterface()), nullptr);
	const maxon::Char* const DataFormatWriterInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DataFormatWriterInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatWriterInterface, DataFormatWriterInterface, , , "net.maxon.interface.dataformatwriter", (DataFormatBaseWriterInterface::PrivateGetInterface()), (DataSerializeWriterInterface::PrivateGetInterface()), nullptr);
	MAXON_REGISTRY_REGISTER(DataFormatReaderFactories);
	MAXON_REGISTRY_REGISTER(DataFormatWriterFactories);
}
#endif
