#if 1
namespace maxon
{
	const maxon::Char* const DescriptionProcessorInterface::MTable::_ids = 
		"Process@a7f58f5edc3d0fe3\0" // Result<GenericData> Process(const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription) const
	"";
	const maxon::METHOD_FLAGS DescriptionProcessorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DescriptionProcessorInterface, , "net.maxon.interface.descriptionprocessor", (ObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(DescriptionProcessors);
}
#endif
