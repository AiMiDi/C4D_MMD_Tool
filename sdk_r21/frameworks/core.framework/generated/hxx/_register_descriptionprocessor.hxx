#if 1
namespace maxon
{
	const maxon::Char* const DescriptionProcessorInterface::MTable::_ids = 
		"Process@b9ef841f069c3fc4\0" // Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DescriptionProcessorInterface, , "net.maxon.interface.descriptionprocessor", "maxon.DescriptionProcessorInterface", (&ObjectInterface::_interface));
	MAXON_REGISTRY_REGISTER(DescriptionProcessors);
}
#endif
