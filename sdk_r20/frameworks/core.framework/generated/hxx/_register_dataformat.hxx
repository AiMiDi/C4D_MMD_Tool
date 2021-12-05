#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatReaderInterface, "net.maxon.interface.dataformatreader", "maxon.DataFormatReaderInterface", , &DataFormatBaseReaderInterface::_interface, &DataSerializeReaderInterface::_interface, nullptr);
	const maxon::Char* const DataFormatReaderInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int DataFormatReaderInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_INTERFACE_REGISTER_VIRTUAL(DataFormatWriterInterface, "net.maxon.interface.dataformatwriter", "maxon.DataFormatWriterInterface", , &DataFormatBaseWriterInterface::_interface, &DataSerializeWriterInterface::_interface, nullptr);
	const maxon::Char* const DataFormatWriterInterface::MTable::_ids = 
	"";
	template <typename DUMMY> maxon::Int DataFormatWriterInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	MAXON_REGISTRY_REGISTER(DataFormatReaderFactories);
	MAXON_REGISTRY_REGISTER(DataFormatWriterFactories);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_dataformat(0
	| maxon::DataFormatReaderInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::DataFormatWriterInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
