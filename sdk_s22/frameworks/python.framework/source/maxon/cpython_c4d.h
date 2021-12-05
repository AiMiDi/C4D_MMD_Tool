#include "maxon/apibase.h"
#include "maxon/datatype.h"

namespace maxon
{

namespace specialtype
{

class BaseList2D { };
class BaseObject { };
class BaseTag { };
class BaseDocument { };
class PolygonObject { };
class BaseDraw { };
class BaseDrawHelp { };
class SplineData { };
class FieldList { };

class BaseList2DMove { };
class BaseObjectMove { };
class BaseTagMove { };
class PolygonObjectMove { };
class BaseDocumentMove { };
class BaseDrawMove { };
class BaseDrawHelpMove { };

MAXON_DATATYPE(BaseList2D, "converter.python.c4d.BaseList2D");
MAXON_DATATYPE(BaseObject, "converter.python.c4d.BaseObject");
MAXON_DATATYPE(BaseTag, "converter.python.c4d.BaseTag");
MAXON_DATATYPE(BaseDocument, "converter.python.c4d.documents.BaseDocument");
MAXON_DATATYPE(PolygonObject, "converter.python.c4d.PolygonObject");
MAXON_DATATYPE(BaseDraw, "converter.python.c4d.BaseDraw");
MAXON_DATATYPE(BaseDrawHelp, "converter.python.c4d.plugins.BaseDrawHelp");
MAXON_DATATYPE(SplineData, "converter.python.c4d.SplineData");
MAXON_DATATYPE(FieldList, "converter.python.c4d.FieldList");

MAXON_DATATYPE(BaseList2DMove, "converter.python.c4d.move.BaseList2D");
MAXON_DATATYPE(BaseObjectMove, "converter.python.c4d.move.BaseObject");
MAXON_DATATYPE(BaseTagMove, "converter.python.c4d.move.BaseTag");
MAXON_DATATYPE(PolygonObjectMove, "converter.python.c4d.move.PolygonObject");
MAXON_DATATYPE(BaseDocumentMove, "converter.python.c4d.documents.move.BaseDocument");
MAXON_DATATYPE(BaseDrawMove, "converter.python.c4d.move.BaseDraw");
MAXON_DATATYPE(BaseDrawHelpMove, "converter.python.c4d.plugins.move.BaseDrawHelp");
} // namespace specialtype

}
