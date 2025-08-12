// This file contains decorator implementations for the interfaces of datadictionaryobject.h. They are intended for copy&paste usage only.

class DataDictionaryObjectDecoratorImpl : public maxon::Component<DataDictionaryObjectDecoratorImpl, DataDictionaryObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, Data&& data)
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	}

	MAXON_METHOD Result<Data> GetData(const ConstDataPtr& key) const
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).GetData(key);
	}

	MAXON_METHOD Result<void> EraseData(const ConstDataPtr& key)
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).EraseData(key);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).Reset();
	}

	MAXON_METHOD Bool IsEmpty() const
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).IsEmpty();
	}

	MAXON_METHOD void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const
	{
		return maxon::Cast<DataDictionaryObjectRef>(self.GetDecoratedObject()).InitIterator(iterator, end);
	}

};

class DataDictionaryReferenceObjectDecoratorImpl : public maxon::Component<DataDictionaryReferenceObjectDecoratorImpl, DataDictionaryReferenceObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(DataDictionary* reference)
	{
		return maxon::Cast<DataDictionaryReferenceObjectRef>(self.GetDecoratedObject()).Init(reference);
	}

	MAXON_METHOD Result<void> Init(const DataDictionary* reference)
	{
		return maxon::Cast<DataDictionaryReferenceObjectRef>(self.GetDecoratedObject()).Init(reference);
	}

	MAXON_METHOD const DataDictionary& GetDataContainer() const
	{
		return maxon::Cast<DataDictionaryReferenceObjectRef>(self.GetDecoratedObject()).GetDataContainer();
	}

};
