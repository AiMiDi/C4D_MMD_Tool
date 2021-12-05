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

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Url, DATABASEURLIN, "databaseurlin");

				MAXON_ATTRIBUTE(Url, INTERNALDATABASEURLIN, "internaldatabaseurlin");

				MAXON_ATTRIBUTE(Id, DATASETMODEIN, "datasetmodein",
					RESOURCE_DEFINE(ENUM_ALLDATASETS, Id("AllDataSets"))
					RESOURCE_DEFINE(ENUM_SINGLEDATASET, Id("SingleDataSet")));

				MAXON_ATTRIBUTE(Int, DATASETNUMBERIN, "datasetnumberin");

				MAXON_ATTRIBUTE(void, DATABASEDATAIN, "databasedatain");

				MAXON_ATTRIBUTE(void, DATABASEDATAOUT, "databasedataout");

				MAXON_ATTRIBUTE(Array<String>, HEADERSOUT, "headersout");

				MAXON_ATTRIBUTE(Id, DELIMITERMODEIN, "delimitermodein",
					RESOURCE_DEFINE(ENUM_AUTO, Id("Auto"))
					RESOURCE_DEFINE(ENUM_COMMA, Id("Comma"))
					RESOURCE_DEFINE(ENUM_SEMICOLON, Id("Semicolon"))
					RESOURCE_DEFINE(ENUM_COLON, Id("Colon"))
					RESOURCE_DEFINE(ENUM_TAB, Id("Tab"))
					RESOURCE_DEFINE(ENUM_SPACE, Id("Space"))
					RESOURCE_DEFINE(ENUM_CUSTOM, Id("Custom")));

				MAXON_ATTRIBUTE(String, DELIMITERIN, "delimiterin");

				MAXON_ATTRIBUTE(Bool, FIRSTROWASHEADERIN, "firstrowasheaderin");

				MAXON_ATTRIBUTE(Bool, HASHTAGASCOMMENTIN, "hashtagascommentin");

				MAXON_ATTRIBUTE(Bool, DOUBLEQUOTEIN, "doublequotein");

				MAXON_ATTRIBUTE(Int64, ROWLIMITIN, "rowlimitin");

				MAXON_ATTRIBUTE(Int64, RELOADHASHIN, "reloadhashin");

				MAXON_ATTRIBUTE(Id, FILETYPECACHEIN, "filetypecachein",
					RESOURCE_DEFINE(ENUM_UNSUPPORTED, Id("Unsupported"))
					RESOURCE_DEFINE(ENUM_CSV, Id("CSV")));

				MAXON_ATTRIBUTE(void, DATABASECACHEIN, "databasecachein");

				MAXON_ATTRIBUTE(Group, MAINGROUP, "maingroup");

				MAXON_ATTRIBUTE(Group, FILEGROUP, "filegroup");

				MAXON_ATTRIBUTE(Group, CSVGROUP, "csvgroup");

				MAXON_ATTRIBUTE(void, RELOAD, "reload");
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
