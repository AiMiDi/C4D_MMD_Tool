#ifndef STRING_NODES_H__
#define STRING_NODES_H__

#include "maxon/fid.h"
#include "maxon/string.h"
#include "maxon/array.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace STRING
	{
		namespace CASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.case");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(InternedId, MODE, "mode");
			MAXON_ATTRIBUTE(void, MODE_ENUM_LOWERCASE, "lowercase");
			MAXON_ATTRIBUTE(void, MODE_ENUM_UPPERCASE, "uppercase");
			MAXON_ATTRIBUTE(void, MODE_ENUM_CAPITALIZE, "capitalize");

			MAXON_ATTRIBUTE(Int, RESULT, "result");
		}

		namespace CONCAT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.concat");

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

			MAXON_ATTRIBUTE(String, STRINGS, "strings");

			MAXON_ATTRIBUTE(String, RESULT, "result");
		}

		namespace JOIN
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.join");

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

			MAXON_ATTRIBUTE(String, DELIMITERIN, "delimiterin");

			MAXON_ATTRIBUTE(Array<String>, STRINGSIN, "stringsin");

			MAXON_ATTRIBUTE(Bool, IGNOREEMPTYIN, "ignoreemptyin");

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace LENGTH
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.length");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(Int, RESULT, "result");
		}

		namespace PREFIXSUFFIX
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.prefixsuffix");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(String, PREFIX, "prefix");

			MAXON_ATTRIBUTE(String, SUFFIX, "suffix");

			MAXON_ATTRIBUTE(String, RESULT, "result");
		}

		namespace PRINT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.print");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(String, PASSTHROUGH, "passthrough");
		}

		namespace RANDOM_STRING_FROM_SOURCE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.random_string_from_source");

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

			MAXON_ATTRIBUTE(String, SOURCEIN, "sourcein");

			MAXON_ATTRIBUTE(Int, LENGTHIN, "lengthin");

			MAXON_ATTRIBUTE(Int, SEEDIN, "seedin");

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace RANDOM_STRING_GENERATOR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.random_string_generator");

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

			MAXON_ATTRIBUTE(Int, LENGTHIN, "lengthin");

			MAXON_ATTRIBUTE(Int, SEEDIN, "seedin");

			MAXON_ATTRIBUTE(Bool, LOWERCASEIN, "lowercasein");

			MAXON_ATTRIBUTE(Bool, UPPERCASEIN, "uppercasein");

			MAXON_ATTRIBUTE(Bool, NUMBERSIN, "numbersin");

			MAXON_ATTRIBUTE(Bool, SYMBOLSIN, "symbolsin");

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace REPEAT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.repeat");

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

			MAXON_ATTRIBUTE(String, STRINGIN, "stringin");

			MAXON_ATTRIBUTE(Float, COUNTIN, "countin");

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace REVERSE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.reverse");

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

			MAXON_ATTRIBUTE(String, IN, "in");

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace SEARCHANDREPLACE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.searchandreplace");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(String, SEARCH, "search");

			MAXON_ATTRIBUTE(String, REPLACE, "replace");

			MAXON_ATTRIBUTE(String, RESULT, "result");
		}

		namespace SPLIT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.split");

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

			MAXON_ATTRIBUTE(String, DELIMITERIN, "delimiterin");

			MAXON_ATTRIBUTE(String, STRINGIN, "stringin");

			MAXON_ATTRIBUTE(Array<String>, OUT, "out");
		}

		namespace STRIP
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.strip");

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

			MAXON_ATTRIBUTE(String, STRINGIN, "stringin");

			MAXON_ATTRIBUTE(Id, MODEIN, "modein",
				RESOURCE_DEFINE(ENUM_START, LiteralId("start"))
				RESOURCE_DEFINE(ENUM_END, LiteralId("end"))
				RESOURCE_DEFINE(ENUM_START_END, LiteralId("start_end"))
				RESOURCE_DEFINE(ENUM_ALL, LiteralId("all")));

			MAXON_ATTRIBUTE(String, OUT, "out");
		}

		namespace SUBSTR
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.substr");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(Int, START, "start");

			MAXON_ATTRIBUTE(Int, COUNT, "count");

			MAXON_ATTRIBUTE(String, RESULT, "result");
		}

		namespace TRUNCATE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.string.truncate");

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

			MAXON_ATTRIBUTE(String, STRING, "string");

			MAXON_ATTRIBUTE(Int, COUNT, "count");

			MAXON_ATTRIBUTE(String, RESULT, "result");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_string1.hxx"
	
#include "nodes_string2.hxx"

#endif // STRING_NODES_H__
