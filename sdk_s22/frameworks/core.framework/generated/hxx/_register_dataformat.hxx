#if 1
namespace maxon
{
	const maxon::Char* const DataFormatReaderInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatReaderInterface, DataFormatReaderInterface, , , "net.maxon.interface.dataformatreader", "maxon.DataFormatReaderInterface", (&DataFormatBaseReaderInterface::_interface), (&DataSerializeReaderInterface::_interface), nullptr);
	const maxon::Char* const DataFormatWriterInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatWriterInterface, DataFormatWriterInterface, , , "net.maxon.interface.dataformatwriter", "maxon.DataFormatWriterInterface", (&DataFormatBaseWriterInterface::_interface), (&DataSerializeWriterInterface::_interface), nullptr);
	MAXON_REGISTRY_REGISTER(DataFormatReaderFactories);
	MAXON_REGISTRY_REGISTER(DataFormatWriterFactories);
}
#endif
