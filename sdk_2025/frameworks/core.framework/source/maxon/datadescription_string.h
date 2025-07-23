#ifndef DATADESCRIPTION_STRING_H__
#define DATADESCRIPTION_STRING_H__

#include "maxon/fid.h"
#include "maxon/string.h"
#include "maxon/datadictionary.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace DESCRIPTION
{
	namespace STRING
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.string.base");

			// supports MAXON::DESCRIPTION::BASE::COMMAND
			// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
			// supports MAXON::DESCRIPTION::BASE::DBVERSION

			/// Translated string.
			MAXON_ATTRIBUTE(String, TRANSLATEDSTRING, "net.maxon.description.string.base.translatedstring");

			/// Translated children strings.
			/// Each entry in the dictionary contains a Tuple<String, String>.
			/// Get<0>(): translated string
			/// Get<1>(): reference string of translation (not used)
			MAXON_ATTRIBUTE(DataDictionary, TRANSLATEDCHILDREN, "net.maxon.description.string.base.translatedchildren");
		}

		namespace INFO
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.string.info");
		}
	}
}

namespace OBJECT
{
	namespace BASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.object.base");

		MAXON_ATTRIBUTE(String, NAME, "net.maxon.object.base.name");

		MAXON_ATTRIBUTE(String, TAGS, "net.maxon.object.base.tags");

		MAXON_ATTRIBUTE(String, ANNOTATIONS, "net.maxon.object.base.annotations");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_string1.hxx"
#include "datadescription_string2.hxx"

#endif // DATADESCRIPTION_STRING_H__
