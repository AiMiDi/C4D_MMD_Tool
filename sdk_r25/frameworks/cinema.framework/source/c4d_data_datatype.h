#ifndef C4D_DATA_DATATYPE_H__
#define C4D_DATA_DATATYPE_H__

#include "maxon/datatype.h"

#ifdef __API_INTERN__
	#include "ge_container.h"
#else
	#include "c4d_gedata.h"
#endif

MAXON_DATATYPE(GeData, "net.maxon.data.gedata");

// Hack: cinema.framework doesn't have the generated/hxx folder in its inlude paths yet, so include the content of the hxx files manually.
#if 1
constexpr inline const maxon::Char* DT_GeData_CppName() { return "GeData"; }
#else
#include "c4d_data_datatype1.hxx"
#include "c4d_data_datatype2.hxx"
#endif

#endif // C4D_DATA_DATATYPE_H__
