#ifndef DATADESCRIPTIONOBJECT_H__
#define DATADESCRIPTIONOBJECT_H__

#include "maxon/datadescription.h"
#include "maxon/object.h"
#include "maxon/stringresource.h"


namespace maxon
{

class DataDictionaryObjectRef;

//----------------------------------------------------------------------------------------
/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
/// the data description data bases.
//----------------------------------------------------------------------------------------
class DataDescriptionObjectInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DataDescriptionObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.datadescriptionobject");

public:
	//----------------------------------------------------------------------------------------
	/// GetObjectDescription returns the description of the object.
	/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] objectData					Data of the object to use for evaluation.
	/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const;

	//----------------------------------------------------------------------------------------
	/// GetObjectName returns the localized name of the description (OBJECT::BASE::NAME).
	/// @param[in] classId						Id of the class to determine.
	/// @param[in] language						Language to use. "nullptr" for current language.
	/// @return												String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetObjectName(const Id& classId, const LanguageRef& language);
};

#include "datadescriptionobject1.hxx"

MAXON_DECLARATION(Class<DataDescriptionObjectRef>, DataDescriptionObjectClass, "net.maxon.class.datadescriptionobject");

#include "datadescriptionobject2.hxx"

}

#endif // DATADESCRIPTIONOBJECT_H__
