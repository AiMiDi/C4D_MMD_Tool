#if 1
namespace maxon
{
	namespace DATAFORMATBASEIDS
	{
		STREAM_PrivateAttribute STREAM;
	}
	const maxon::Char* const DataFormatBaseReaderInterface::MTable::_ids = 
		"CloseInput@3008090429c5a175\0" // Result<void> CloseInput()
		"ReadDataEOS@f5a10529c7a59026\0" // Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount)
	"";
	const maxon::METHOD_FLAGS DataFormatBaseReaderInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseReaderInterface, , "net.maxon.interface.dataformatbasereader", "maxon.DataFormatBaseReaderInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataFormatBaseWriterInterface::MTable::_ids = 
		"CloseOutput@3008090429c5a175\0" // Result<void> CloseOutput()
		"WriteData@e6001f3e1127eb78\0" // Result<void> WriteData(const void* data, Int dataSize, Int elementCount)
		"Flush@3008090429c5a175\0" // Result<void> Flush()
	"";
	const maxon::METHOD_FLAGS DataFormatBaseWriterInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseWriterInterface, , "net.maxon.interface.dataformatbasewriter", "maxon.DataFormatBaseWriterInterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
}
#endif
