#ifndef DESCTRANSLATION_H__

// When there's a #define DESCTRANSLATION_FORWARD in front of the #include for this file,
// only a forward declaration for DescTranslation is made.
#ifndef DESCTRANSLATION_FORWARD

#define DESCTRANSLATION_H__

#ifndef LIB_DESCRIPTION_H__
#error "Please include lib_description.h first"
#endif

#endif

#include "maxon/hashmap.h"
#include "maxon/basearray.h"
#include "maxon/datadictionary.h"

namespace maxon
{

#ifndef DESCTRANSLATION_PART
#define DESCTRANSLATION_PART

class DescEntryStruct
{
public:
	DescEntryStruct() = default;

	Result<void> CopyFrom(const DescEntryStruct& src)
	{
		iferr_scope;
		MAXON_COPYFROM_MEMBERS(_id, _dataTypeId, _guiTypeId, _commandId, _dataEntry, _guiEntry);
		return OK;
	}

	BaseArray<InternedId> _id;
	Id										_dataTypeId;
	Id										_guiTypeId;
	Id										_commandId;
	DataDictionary				_dataEntry;
	DataDictionary				_guiEntry;
};

class DescTranslation;
using DescTranslationRef = StrongCOWRef<DescTranslation>;
template <> struct StrongRefHandler::HasRemoveReference<DescTranslation> : public std::false_type
{
};

#endif

#ifdef DESCTRANSLATION_FORWARD
	#undef DESCTRANSLATION_FORWARD
#else

class DescTranslation
{
public:

	using DescEntryMap = HashMap<DescID, DescEntryStruct>;
	using GroupIdMap = HashMap<InternedId, DescID>;

	DescTranslation() {}

	Result<void> CopyFrom(const DescTranslation& src)
	{
		iferr_scope;
		MAXON_COPYFROM_MEMBERS(_descIdMap, _groupIdMap, _conditionalIds);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the translation structure matching the given DescID. 
	/// @note Would be best to have a reverse HashMap<BaseArray<InternedId>, DescID> for a fast reverse mapping, when we can edit DescTranslation content.
	/// @param[in] id									The description identifier to search for.
	/// @return												Entry pointer on success, nullptr otherwise.
	//----------------------------------------------------------------------------------------
	const DescEntryStruct* FindTranslationDescID(const DescID& id) const
	{
		return _descIdMap.FindValue(id);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the legacy DescID corresponding to the given identifier.
	/// This is a reverse search in regards of FindTranslationDescID;
	/// @param[in] emulKey						The emulation key to search for.
	/// @return												Entry pointer on success, nullptr otherwise.
	//----------------------------------------------------------------------------------------
	const DescEntryMap::Entry* ReverseFindTranslationDescID(const Block<const InternedId>& emulKey) const
	{
		for (auto& transEntry : _descIdMap)
		{
			if (transEntry.GetValue()._id.ContainsAll(emulKey))
			{
				return &transEntry;
			}
		}

		return nullptr;
	}

	DescEntryMap _descIdMap;
	GroupIdMap _groupIdMap;
	HashSet<InternedId> _conditionalIds;
};

#endif

} // namespace maxon

#endif // DESCTRANSLATION_H__
