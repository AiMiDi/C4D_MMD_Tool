// This file contains default implementations for the interfaces of datadictionaryobject.h. They are intended for copy&paste usage only.

class MyDataDictionaryObjectImpl : public maxon::Component<MyDataDictionaryObjectImpl, DataDictionaryObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, Data&& data)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Data> GetData(const ConstDataPtr& key) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> EraseData(const ConstDataPtr& key)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool IsEmpty() const
	{
		return true;
	}

	MAXON_METHOD void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const
	{
		return maxon::PrivateLogNullptrError();
	}

};

class MyDataDictionaryReferenceObjectImpl : public maxon::Component<MyDataDictionaryReferenceObjectImpl, DataDictionaryReferenceObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(DataDictionary* reference)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const DataDictionary* reference)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const DataDictionary& GetDataContainer() const
	{
		return HXXRET3(NULLIMPL, const DataDictionary&);
	}

};
