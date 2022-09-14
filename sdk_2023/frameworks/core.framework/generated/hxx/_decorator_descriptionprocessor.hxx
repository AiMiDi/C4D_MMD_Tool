// This file contains decorator implementations for the interfaces of descriptionprocessor.h. They are intended for copy&paste usage only.

class DescriptionProcessorDecoratorImpl : public maxon::Component<DescriptionProcessorDecoratorImpl, DescriptionProcessorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const
	{
		return maxon::Cast<DescriptionProcessor>(self.GetDecoratedObject()).Process(descriptionId, dataDescription);
	}

};
