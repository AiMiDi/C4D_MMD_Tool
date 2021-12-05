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

			/// Translated string.
			MAXON_ATTRIBUTE(maxon::String, TRANSLATEDSTRING, "net.maxon.description.string.base.translatedstring");

			/// String of the reference string.
			MAXON_ATTRIBUTE(maxon::String, REFERENCESTRING, "net.maxon.description.string.base.referencestring");

			/// Original reference string of the translated string at the time of the last translation.
			MAXON_ATTRIBUTE(maxon::String, TRANSLATEDREFERENCESTRING, "net.maxon.description.string.base.translatedreferencestring");

			/// Translated children strings. 
			/// Each entry in the dictionary contains a Tuple<String, String>.
			/// Get<0>(): translated string
			/// Get<1>(): reference string (of translation)
			MAXON_ATTRIBUTE(maxon::DataDictionary, TRANSLATEDCHILDREN, "net.maxon.description.string.base.translatedchildren");

			MAXON_ATTRIBUTE(Group, COMMANDSGROUP, "net.maxon.description.string.base.commandsgroup");

			MAXON_ATTRIBUTE(void, GOTONEXT, "net.maxon.description.string.base.gotonext");

			MAXON_ATTRIBUTE(void, SUGGESTIONS, "net.maxon.description.string.base.suggestions");

			MAXON_ATTRIBUTE(void, OPENEXTERNALCOMPARETOOL, "net.maxon.description.string.base.openexternalcomparetool");

			MAXON_ATTRIBUTE(void, APPROVECOMMAND, "net.maxon.description.string.base.approvecommand");
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

		MAXON_ATTRIBUTE(maxon::String, NAME, "net.maxon.object.base.name");

		MAXON_ATTRIBUTE(maxon::String, TAGS, "net.maxon.object.base.tags");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_string1.hxx"
#include "datadescription_string2.hxx"

#endif // DATADESCRIPTION_STRING_H__
