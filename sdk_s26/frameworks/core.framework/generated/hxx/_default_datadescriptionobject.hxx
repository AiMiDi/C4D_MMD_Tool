// This file contains default implementations for the interfaces of datadescriptionobject.h. They are intended for copy&paste usage only.

class MyDataDescriptionObjectImpl : public maxon::Component<MyDataDescriptionObjectImpl, DataDescriptionObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
