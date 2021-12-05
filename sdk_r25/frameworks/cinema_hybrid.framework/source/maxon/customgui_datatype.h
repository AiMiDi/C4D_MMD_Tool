/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_DATATYPE_H__
#define CUSTOMGUI_DATATYPE_H__

#include "maxon/datadescription.h"
#include "maxon/assets.h"
#include "maxon/datadictionary.h"
#include "maxon/fid.h"

namespace maxon
{

namespace CUSTOMGUI_DATATYPE
{
	constexpr Int DESC_BASECONTAINER_ID = 123453653;
	constexpr Int32 PLUGIN_ID = 1055220;

	MAXON_ATTRIBUTE(Data, DATA, "data");
	MAXON_ATTRIBUTE(DataDictionary, DATAENTRY, "dataentry");
	MAXON_ATTRIBUTE(DataDictionary, GUIENTRY, "guientry");
	MAXON_ATTRIBUTE(DataDescription, STRINGDESCRIPTION, "stringdescription");
	MAXON_ATTRIBUTE(AssetRepositoryRef, REPOSITORY, "repository");
}

#include "customgui_datatype1.hxx"
#include "customgui_datatype2.hxx"

}

#endif // CUSTOMGUI_DATATYPE_H__
