#include "datadictionary.h"
#include "maxon/datadescriptiondatabase.h"


namespace maxon
{

Result<Data> GetDataDescriptionValueI(const Id& databaseScope, const InternedId& attributeData, const ConstDataPtr& keyPtr)
{
	iferr_scope;
	DataDescription dataBaseRef = DataDescriptionDatabaseInterface::LoadDescription(DATADESCRIPTION_CATEGORY_DATA, LanguageRef(), databaseScope) iferr_return;
	DataDictionary dataTypeDesc = dataBaseRef.GetEntry(attributeData) iferr_return;
	return dataTypeDesc.GetData(keyPtr);
}

Result<void> MergeDataDictionaries(DataDictionary& base, const DataDictionary& other, Bool mergeSubContainers)
{
	iferr_scope;

	if (base.IsEmpty())
	{
		base = other;
	}
	else
	{
		for (const Tuple<const Data&, const Data&>& d : other)
		{
			const Data& key = d.GetKey();
			const Data& value = d.GetValue();

			if (mergeSubContainers && value.GetType().Is<DataDictionary>())
			{
				DataDictionary dict = base.Get<DataDictionary>(key, DataDictionary());
				MergeDataDictionaries(dict, value.Get<DataDictionary>(DataDictionary()), true) iferr_return;
				base.Set(key, Data(std::move(dict))) iferr_return;
			}
			else
			{
				base.Set(key, value) iferr_return;
			}
		}
	}

	return OK;
}

Result<void> MergeDataDictionariesPreferBase(DataDictionary& base, const DataDictionary& other, Bool mergeSubContainers)
{
	iferr_scope;

	if (base.IsEmpty())
	{
		base = other;
	}
	else
	{
		for (const Tuple<const Data&, const Data&>& d : other)
		{
			const Data& key = d.GetKey();
			const Data& value = d.GetValue();

			if (!base.Existing(key))
			{
				if (mergeSubContainers && value.GetType().Is<DataDictionary>())
				{
					DataDictionary dict = base.Get<DataDictionary>(key, DataDictionary());
					MergeDataDictionariesPreferBase(dict, value.Get<DataDictionary>(DataDictionary()), true) iferr_return;
					base.Set(key, Data(std::move(dict))) iferr_return;
				}
				else
				{
					base.Set(key, value) iferr_return;
				}
			}
		}
	}

	return OK;
}

}
