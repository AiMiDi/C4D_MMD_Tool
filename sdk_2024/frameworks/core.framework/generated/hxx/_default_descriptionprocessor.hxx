// This file contains default implementations for the interfaces of descriptionprocessor.h. They are intended for copy&paste usage only.

class MyDescriptionProcessorImpl : public maxon::Component<MyDescriptionProcessorImpl, DescriptionProcessorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<GenericData> Process(const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription) const
	{
		return HXXRET1(NULLIMPL);
	}

};
