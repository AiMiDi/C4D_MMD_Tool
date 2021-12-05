/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef MATRIX4_H__
#define MATRIX4_H__

#include "vector4.h"
#include "maxon/matrix4d.h"

using Matrix4d32 = maxon::SqMat4<Vector4d32>;			///< Single-precision Matrix4
using Matrix4d64 = maxon::SqMat4<Vector4d64>;			///< Double-precision Matrix4
using Matrix4d = maxon::SqMat4<Vector4d>;				///< Matrix4 for double-precision @C4D versions.

#endif // MATRIX4_H__
