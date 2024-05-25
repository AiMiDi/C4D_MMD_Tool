#ifndef NODES_DATAIMPORT_H__
#define NODES_DATAIMPORT_H__

#include "maxon/fid.h"
#include "maxon/array.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NEUTRON
{
	namespace IMPORTER
	{
		namespace DATABASE
		{
			namespace PARSER
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.importer.database.parser");

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

				MAXON_ATTRIBUTE(Url, DATABASEURLIN, "databaseurlin");

				MAXON_ATTRIBUTE(DataType, DATABASEDATATYPEIN, "databasedatatypein");

				MAXON_ATTRIBUTE(Id, DATASETMODEIN, "datasetmodein",
					RESOURCE_DEFINE(ENUM_ALLDATASETS, LiteralId("AllDataSets"))
					RESOURCE_DEFINE(ENUM_SINGLEDATASET, LiteralId("SingleDataSet")));

				MAXON_ATTRIBUTE(Int, DATASETNUMBERIN, "datasetnumberin");

				MAXON_ATTRIBUTE(void, DATABASEDATAOUT, "databasedataout");

				MAXON_ATTRIBUTE(Array<String>, HEADERSOUT, "headersout");

				MAXON_ATTRIBUTE(Id, DELIMITERMODEIN, "delimitermodein",
					RESOURCE_DEFINE(ENUM_AUTO, LiteralId("Auto"))
					RESOURCE_DEFINE(ENUM_COMMA, LiteralId("Comma"))
					RESOURCE_DEFINE(ENUM_SEMICOLON, LiteralId("Semicolon"))
					RESOURCE_DEFINE(ENUM_COLON, LiteralId("Colon"))
					RESOURCE_DEFINE(ENUM_TAB, LiteralId("Tab"))
					RESOURCE_DEFINE(ENUM_SPACE, LiteralId("Space"))
					RESOURCE_DEFINE(ENUM_CUSTOM, LiteralId("Custom")));

				MAXON_ATTRIBUTE(String, DELIMITERIN, "delimiterin");

				MAXON_ATTRIBUTE(Bool, FIRSTROWASHEADERIN, "firstrowasheaderin");

				MAXON_ATTRIBUTE(Bool, HASHTAGASCOMMENTIN, "hashtagascommentin");

				MAXON_ATTRIBUTE(Bool, DOUBLEQUOTEIN, "doublequotein");

				MAXON_ATTRIBUTE(Int64, ROWLIMITIN, "rowlimitin");

				MAXON_ATTRIBUTE(Id, FILETYPECACHEIN, "filetypecachein",
					RESOURCE_DEFINE(ENUM_UNSUPPORTED, LiteralId("Unsupported"))
					RESOURCE_DEFINE(ENUM_CSV, LiteralId("CSV")));

				MAXON_ATTRIBUTE(void, DATABASECACHEIN, "databasecachein");

				MAXON_ATTRIBUTE(Group, MAINGROUP, "maingroup");

				MAXON_ATTRIBUTE(Group, FILEGROUP, "filegroup");

				MAXON_ATTRIBUTE(Group, CSVGROUP, "csvgroup");

				MAXON_ATTRIBUTE(Group, FILTERGROUP, "net.maxon.neutron.importer.database.parser.filtergroup");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_dataimport1.hxx"
#include "nodes_dataimport2.hxx"

#endif // NODES_DATAIMPORT_H__
