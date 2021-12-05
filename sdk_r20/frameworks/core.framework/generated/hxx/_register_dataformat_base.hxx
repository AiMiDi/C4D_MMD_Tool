#if 1
namespace maxon
{
	namespace DATAFORMATBASEIDS
	{
		STREAM_PrivateAttribute STREAM;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseReaderInterface, "net.maxon.interface.dataformatbasereader", "maxon.DataFormatBaseReaderInterface", , &DataDictionaryObjectInterface::_interface);
	const maxon::Char* const DataFormatBaseReaderInterface::MTable::_ids = 
		"CloseInput@a54f4799cbe1a498\0" // CloseInput()
		"ReadDataEOS@e5cd6d7469186087\0" // ReadDataEOS(void* data, Int dataSize, Int elementCount)
	"";
	template <typename DUMMY> maxon::Int DataFormatBaseReaderInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataFormatBaseWriterInterface, "net.maxon.interface.dataformatbasewriter", "maxon.DataFormatBaseWriterInterface", , &DataDictionaryObjectInterface::_interface);
	const maxon::Char* const DataFormatBaseWriterInterface::MTable::_ids = 
		"CloseOutput@a54f4799cbe1a498\0" // CloseOutput()
		"WriteData@09b8fad873644847\0" // WriteData(const void* data, Int dataSize, Int elementCount)
		"Flush@a54f4799cbe1a498\0" // Flush()
	"";
	template <typename DUMMY> maxon::Int DataFormatBaseWriterInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_dataformat_base(0
	| maxon::DataFormatBaseReaderInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::DataFormatBaseWriterInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
