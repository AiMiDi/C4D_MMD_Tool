#ifndef C4D_DATA_DATATYPE_H__
#define C4D_DATA_DATATYPE_H__

#include "maxon/datatype.h"

#ifdef __API_INTERN__
	#include "ge_container.h"
#else
	#include "c4d_gedata.h"
#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

MAXON_DATATYPE(GeData, "net.maxon.data.gedata");

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

namespace maxon
{

// helper template to wrap c4d pointer types in maxon::Data
template <typename LEGACYTYPE> class ClassicObjectWrapper
{
public:
	using SelfType = ClassicObjectWrapper<LEGACYTYPE>;

	ClassicObjectWrapper() = default;
	MAXON_IMPLICIT ClassicObjectWrapper(LEGACYTYPE* ptr) : _ptr(ptr) {	}
	ClassicObjectWrapper(const ClassicObjectWrapper& src)
	{
		_ptr = src._ptr;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(SelfType, _ptr);

	LEGACYTYPE* _ptr = nullptr;
};

using C4DBaseDocumentType = ClassicObjectWrapper<CINEWARE_NAMESPACE::BaseDocument>;
MAXON_DATATYPE(C4DBaseDocumentType, "net.maxon.datatype.c4dbasedocument");

using C4DBaseObjectType = ClassicObjectWrapper<CINEWARE_NAMESPACE::BaseObject>;
MAXON_DATATYPE(C4DBaseObjectType, "net.maxon.datatype.c4dbaseobject");

class C4DPolyObjectType
{
public:
	C4DPolyObjectType() = default;
	MAXON_IMPLICIT C4DPolyObjectType(CINEWARE_NAMESPACE::PointObject* ptr) : _ptr(ptr) {	}
	MAXON_IMPLICIT C4DPolyObjectType(CINEWARE_NAMESPACE::PolygonObject* ptr) : _ptr((CINEWARE_NAMESPACE::PointObject*)ptr) {	}
	C4DPolyObjectType(const C4DPolyObjectType& src)
	{
		_ptr = src._ptr;
	}

	CINEWARE_NAMESPACE::PointObject* _ptr = nullptr;
};

MAXON_DATATYPE(C4DPolyObjectType, "net.maxon.datatype.c4dpolyobject");

class C4DPolyLineObjectType : public C4DPolyObjectType
{
public:
	C4DPolyLineObjectType() = default;
	MAXON_IMPLICIT C4DPolyLineObjectType(CINEWARE_NAMESPACE::PointObject* ptr) : C4DPolyObjectType(ptr) {	}
	MAXON_IMPLICIT C4DPolyLineObjectType(CINEWARE_NAMESPACE::PolygonObject* ptr) : C4DPolyObjectType((CINEWARE_NAMESPACE::PointObject*)ptr) {	}
	C4DPolyLineObjectType(const C4DPolyLineObjectType& src)
	{
		_ptr = src._ptr;
	}
};

MAXON_DATATYPE(C4DPolyLineObjectType, "net.maxon.datatype.c4dpolylineobject");

class C4DSplineObjectType : public C4DPolyLineObjectType
{
public:
	C4DSplineObjectType() = default;
	MAXON_IMPLICIT C4DSplineObjectType(CINEWARE_NAMESPACE::PointObject* ptr) : C4DPolyLineObjectType(ptr) {	}
	C4DSplineObjectType(const C4DSplineObjectType& src)
	{
		_ptr = src._ptr;
	}
};

MAXON_DATATYPE(C4DSplineObjectType, "net.maxon.datatype.c4dsplineobject");

} // namespace maxon

// Hack: cinema.framework doesn't have the generated/hxx folder in its include paths yet, so include the content of the hxx files manually.
#if 1
constexpr inline const maxon::Char* DT_GeData_CppName() { return "GeData"; }

namespace maxon
{

constexpr inline const maxon::Char* DT_C4DBaseDocumentType_CppName() { return "C4DBaseDocumentType"; }
constexpr inline const maxon::Char* DT_C4DBaseObjectType_CppName() { return "C4DBaseObjectType"; }
constexpr inline const maxon::Char* DT_C4DPolyObjectType_CppName() { return "C4DPolyObjectType"; }
constexpr inline const maxon::Char* DT_C4DPolyLineObjectType_CppName() { return "C4DPolyLineObjectType"; }
constexpr inline const maxon::Char* DT_C4DSplineObjectType_CppName() { return "C4DSplineObjectType"; }

} // namespace maxon
#else
#include "c4d_data_datatype1.hxx"
#include "c4d_data_datatype2.hxx"
#endif

#endif // C4D_DATA_DATATYPE_H__
