#include "datadictionaryobject.h"

namespace maxon
{

Result<DataDictionaryObjectRef> CreateDataDictionaryReferenceObject(DataDictionary* reference)
{
	iferr_scope;
	DataDictionaryReferenceObjectRef d = DataDictionaryObjectReferenceClass().Create().Init(reference) iferr_return;
	return Cast<DataDictionaryObjectRef>(d);
}

Result<DataDictionaryObjectRef> CreateDataDictionaryReferenceObject(const DataDictionary* reference)
{
	iferr_scope;
	DataDictionaryReferenceObjectRef d = DataDictionaryObjectReferenceClass().Create().Init(reference) iferr_return;
	return Cast<DataDictionaryObjectRef>(d);
}

Result<DataDictionary> GetDataDictionaryFromDataDictionaryObjectRef(const DataDictionaryObjectRef& settings)
{
	iferr_scope;
	DataDictionary newSettings;
	if (Cast<DataDictionaryReferenceObjectRef>(settings))
	{
		newSettings = Cast<DataDictionaryReferenceObjectRef>(settings).GetDataContainer();
	}
	else
	{
		for (auto d : settings)
		{
			const Data& key = d.GetKey();
			const Data& value = d.GetValue();
			newSettings.SetData(ConstDataPtr(key), value) iferr_return;
		}
	}
	return newSettings;
}

}
