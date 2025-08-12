// This file contains decorator implementations for the interfaces of datadescriptionobject.h. They are intended for copy&paste usage only.

class DataDescriptionObjectDecoratorImpl : public maxon::Component<DataDescriptionObjectDecoratorImpl, DataDescriptionObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const
	{
		return maxon::Cast<DataDescriptionObjectRef>(self.GetDecoratedObject()).GetObjectDescription(category, language, objectData);
	}

};
