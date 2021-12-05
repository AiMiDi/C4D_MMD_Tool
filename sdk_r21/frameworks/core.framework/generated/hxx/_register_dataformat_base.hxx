#if 1
namespace maxon
{
	namespace DATAFORMATBASEIDS
	{
		STREAM_PrivateAttribute STREAM;
	}
	const maxon::Char* const DataFormatBaseReaderInterface::MTable::_ids = 
		"CloseInput@a54f4799cbe1a498\0" // Result<void> CloseInput()
		"ReadDataEOS@e5cd6d7469186087\0" // Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseReaderInterface, , "net.maxon.interface.dataformatbasereader", "maxon.DataFormatBaseReaderInterface", (&DataDictionaryObjectInterface::_interface));
	const maxon::Char* const DataFormatBaseWriterInterface::MTable::_ids = 
		"CloseOutput@a54f4799cbe1a498\0" // Result<void> CloseOutput()
		"WriteData@09b8fad873644847\0" // Result<void> WriteData(const void* data, Int dataSize, Int elementCount)
		"Flush@a54f4799cbe1a498\0" // Result<void> Flush()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseWriterInterface, , "net.maxon.interface.dataformatbasewriter", "maxon.DataFormatBaseWriterInterface", (&DataDictionaryObjectInterface::_interface));
}
#endif
