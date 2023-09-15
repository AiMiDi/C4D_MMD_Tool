#ifndef DESCTRANSLATION_H__
#define DESCTRANSLATION_H__

#ifndef LIB_DESCRIPTION_H__
#error "Please include lib_description.h first"
#endif

#include "maxon/hashmap.h"
#include "maxon/basearray.h"
#include "maxon/datadictionary.h"
#include "maxon/datadescription_ui.h"

namespace maxon
{

class DescEntryStruct
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(DescEntryStruct);
public:
	DescEntryStruct() = default;
	DescEntryStruct(DescEntryStruct&& other) = default;
	
	MAXON_OPERATOR_MOVE_ASSIGNMENT(DescEntryStruct);
	
	BaseArray<InternedId> _id;
	Id										_dataTypeId;
	Id										_guiTypeId;
	Id										_commandId;
	DataDictionary				_dataEntry;
	DataDictionary				_guiEntry;
};

class DescTranslation
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(DescTranslation);

public:
	DescTranslation() {};
	DescTranslation(DescTranslation&& other) = default;

	MAXON_OPERATOR_MOVE_ASSIGNMENT(DescTranslation);
	
	HashMap<DescID, DescEntryStruct> _descIdMap;
	HashMap<InternedId, DescID>			 _groupIdMap;
};

} // namespace maxon

#endif // DESCTRANSLATION_H__
