/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef MATRIX4_H__
#define MATRIX4_H__

#include "vector4.h"
#include "maxon/matrix4d.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

using Matrix4d32 = maxon::SqrMat4<Vector4d32>;			///< Single-precision Matrix4
using Matrix4d64 = maxon::SqrMat4<Vector4d64>;			///< Double-precision Matrix4
using Matrix4d = maxon::SqrMat4<Vector4d>;				///< Matrix4 for double-precision @C4D versions.

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // MATRIX4_H__
