#ifndef NODES_SCRIPT_H__
#define NODES_SCRIPT_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace SCRIPT
	{
		namespace FORMULA
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.script.formula");

			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
			// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
			// supports MAXON::NODE::BASE::NAME
			// supports MAXON::NODE::BASE::ASSETVERSION
			// supports MAXON::NODE::BASE::COLOR
			// supports MAXON::NODE::BASE::PORTDISPLAY
			// supports MAXON::NODE::BASE::DISPLAYPREVIEW
			// supports MAXON::NODE::BASE::DISPLAYCOMMENT
			// supports MAXON::NODE::BASE::COMMENT
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED

			MAXON_ATTRIBUTE(Data, VAR, "var");

			/// Enter the formula with variables used to calculate the output.
			/// See DataDescriptionUIInterface::EvaluateCondition and FormulaParserInterface in API for supported functions and operators.
			/// Variable names should match the identifier of the corresponding input port ("var1", "var2", ...).
			MAXON_ATTRIBUTE(String, FORMULAIN, "formulain");

			/// Result of the formula's evaluation.
			MAXON_ATTRIBUTE(void, RESULTOUT, "resultout");

			/// Used for debugging the formula processing errors.
			MAXON_ATTRIBUTE(String, ERRORMSGOUT, "errormsgout");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_script1.hxx"
#include "nodes_script2.hxx"

#endif // NODES_SCRIPT_H__
