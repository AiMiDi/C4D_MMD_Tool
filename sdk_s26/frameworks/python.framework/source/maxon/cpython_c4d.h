#include "maxon/datatype.h"

namespace maxon
{

namespace specialtype
{

class BaseList2D { };
class BaseObject { };
class BaseMaterial { };
class BaseTag { };
class BaseDocument { };
class PolygonObject { };
class BaseDraw { };
class BaseDrawHelp { };
class SplineData { };
class FieldList { };
class DescID { };
class BaseContainer { };
class Description { };
class BaseBitmap { };
class GeListNode { };
class C4DAtom { };

class BaseList2DMove { };
class BaseObjectMove { };
class BaseMaterialMove { };
class BaseTagMove { };
class PolygonObjectMove { };
class BaseDocumentMove { };
class BaseDrawMove { };
class BaseDrawHelpMove { };
class BaseBitmapMove { };
class GeListNodeMove { };
class C4DAtomMove { };

MAXON_DATATYPE(BaseList2D, "converter.python.c4d.BaseList2D");
MAXON_DATATYPE(BaseObject, "converter.python.c4d.BaseObject");
MAXON_DATATYPE(BaseMaterial, "converter.python.c4d.BaseMaterial");
MAXON_DATATYPE(BaseTag, "converter.python.c4d.BaseTag");
MAXON_DATATYPE(BaseDocument, "converter.python.c4d.documents.BaseDocument");
MAXON_DATATYPE(PolygonObject, "converter.python.c4d.PolygonObject");
MAXON_DATATYPE(BaseDraw, "converter.python.c4d.BaseDraw");
MAXON_DATATYPE(BaseDrawHelp, "converter.python.c4d.plugins.BaseDrawHelp");
MAXON_DATATYPE(SplineData, "converter.python.c4d.SplineData");
MAXON_DATATYPE(FieldList, "converter.python.c4d.FieldList");
MAXON_DATATYPE(DescID, "converter.python.c4d.DescID");
MAXON_DATATYPE(BaseContainer, "converter.python.c4d.BaseContainer");
MAXON_DATATYPE(Description, "converter.python.c4d.Description");
MAXON_DATATYPE(BaseBitmap, "converter.python.c4d.bitmaps.BaseBitmap");
MAXON_DATATYPE(GeListNode, "converter.python.c4d.GeListNode");
MAXON_DATATYPE(C4DAtom, "converter.python.c4d.C4DAtom");

MAXON_DATATYPE(BaseList2DMove, "converter.python.c4d.move.BaseList2D");
MAXON_DATATYPE(BaseObjectMove, "converter.python.c4d.move.BaseObject");
MAXON_DATATYPE(BaseMaterialMove, "converter.python.c4d.move.BaseMaterial");
MAXON_DATATYPE(BaseTagMove, "converter.python.c4d.move.BaseTag");
MAXON_DATATYPE(PolygonObjectMove, "converter.python.c4d.move.PolygonObject");
MAXON_DATATYPE(BaseDocumentMove, "converter.python.c4d.documents.move.BaseDocument");
MAXON_DATATYPE(BaseDrawMove, "converter.python.c4d.move.BaseDraw");
MAXON_DATATYPE(BaseDrawHelpMove, "converter.python.c4d.plugins.move.BaseDrawHelp");
MAXON_DATATYPE(BaseBitmapMove, "converter.python.c4d.bitmaps.move.BaseBitmap");
MAXON_DATATYPE(GeListNodeMove, "converter.python.c4d.move.GeListNode");
MAXON_DATATYPE(C4DAtomMove, "converter.python.c4d.move.C4DAtom");
} // namespace specialtype

#include "cpython_c4d1.hxx"
#include "cpython_c4d2.hxx"

}
