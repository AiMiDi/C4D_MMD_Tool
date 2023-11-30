/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2006 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

//---------------------------------------------------
// Spline Helper Class
// Routines to generate a full set of spline matrices
// incorporating a correct normal
// and accurate spline length to realworld length controls
//---------------------------------------------------
#include "lib_splinehelp.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

SplineHelpLibrary* splinehelplib_cache;

static SplineHelpLibrary* CheckSplineHelpLib(Int32 offset)
{
	return CheckLib<SplineHelpLibrary>(C4D_SPLINEHELP_LIBRARY_ID, offset, splinehelplib_cache);
}

SplineHelp *SplineHelp::Alloc()
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, Alloc));
	if (!shlib || !shlib->Alloc) return nullptr;

	return (SplineHelp*)shlib->Alloc();
}

void SplineHelp::Free(SplineHelp *&node)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, Free));
	if (!shlib || !shlib->Free) return;

	iSplineHelp *tmp = (iSplineHelp*)node;
	shlib->Free(tmp);
	node = nullptr;
}

Bool SplineHelp::InitSplineEx(const BaseObject* op, Vector upvector, const BaseObject* rail, Bool target_rail, Bool use_deformed_points, Bool force_update, Bool use_global_space)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, InitSplineEx));
	if (!shlib || !shlib->InitSplineEx) return false;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->InitSplineEx))(op, upvector, rail, target_rail, use_deformed_points, force_update, use_global_space);
}

//-------------------------
// Always call this to begin with before calling any other functions
// AutoAlloc<SplineHelp>sh;  FreeSpline will be called automatically
// sh->InitSpline(myspline);
// ... do stuff ...
Bool SplineHelp::InitSpline(const BaseObject* op, SPLINEHELPFLAGS flags)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, InitSpline));
	if (!shlib || !shlib->InitSpline) return false;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->InitSpline))(op, Vector(0.0), nullptr, flags);
}

Bool SplineHelp::InitSpline(const BaseObject* op, Vector upvector, SPLINEHELPFLAGS flags)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, InitSpline));
	if (!shlib || !shlib->InitSpline) return false;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->InitSpline))(op, upvector, nullptr, flags);
}

Bool SplineHelp::InitSpline(const BaseObject* op, const BaseObject* rail, SPLINEHELPFLAGS flags)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, InitSpline));
	if (!shlib || !shlib->InitSpline) return false;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->InitSpline))(op, Vector(0.0), rail, flags);
}

// must be called afterwards to free data
void SplineHelp::FreeSpline()
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, FreeSpline));
	if (!shlib || !shlib->FreeSpline) return;

	(reinterpret_cast<iSplineHelp*>(this)->*(shlib->FreeSpline))();
}

//-----------------------------------------------------
// helper routines

// Have we been inited properly?
Bool SplineHelp::Exists() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, Exists));
	if (!shlib || !shlib->Exists) return false;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->Exists))();
}

// Retrieve splines segment count
Int32 SplineHelp::GetSegmentCount() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSegmentCount));
	if (!shlib || !shlib->GetSegmentCount) return 0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetSegmentCount))();
}

// Get the total length of the spline
Float SplineHelp::GetSplineLength() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSplineLength));
	if (!shlib || !shlib->GetSplineLength) return 0.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetSplineLength))();
}

// Get the length of a single segment
Float SplineHelp::GetSegmentLength(Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSegmentLength));
	if (!shlib || !shlib->GetSegmentLength) return 0.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetSegmentLength))(segment);
}

// Get the length of a single segment
Matrix SplineHelp::GetVertexMatrix(Int32 index) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetVertexMatrix));
	if (!shlib || !shlib->GetVertexMatrix) return Matrix();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetVertexMatrix))(index);
}


// Get the real value along the segment
Float SplineHelp::GetPointValue(Float offset, Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetPointValue));
	if (!shlib || !shlib->GetPointValue) return 0.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetPointValue))(offset, segment);
}

// Retrieve the nearest points index from the lineobject
Int32 SplineHelp::GetPointIndex(Float offset, Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetPointIndex));
	if (!shlib || !shlib->GetPointIndex) return 0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetPointIndex))(offset, segment);
}

// Return the position at offset in global coordinates
Vector SplineHelp::GetPosition(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetPosition));
	if (!shlib || !shlib->GetPosition) return Vector();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetPosition))(offset, segment, smooth, realoffset);
}

// Get the size of the vertex (distance to the rail) if using a rail spline
Float SplineHelp::GetSize(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSize));
	if (!shlib || !shlib->GetSize) return 1.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetSize))(offset, segment, smooth, realoffset);
}
// Get the size of the vertex (distance to the rail) if using a rail spline
Float SplineHelp::GetVertexSize(Int32 index) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetVertexSize));
	if (!shlib || !shlib->GetVertexSize) return 1.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetVertexSize))(index);
}

// Returns the Tangent at offset in global coordinates
Vector SplineHelp::GetTangent(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetTangent));
	if (!shlib || !shlib->GetTangent) return Vector();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetTangent))(offset, segment, smooth, realoffset);
}

// Returns the Normal at offset in global coordinates
Vector SplineHelp::GetNormal(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetNormal));
	if (!shlib || !shlib->GetNormal) return Vector();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetNormal))(offset, segment, smooth, realoffset);
}

// Returns the CrossNormal at offset in global coordinates
Vector SplineHelp::GetCrossNormal(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetCrossNormal));
	if (!shlib || !shlib->GetCrossNormal) return Vector();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetCrossNormal))(offset, segment, smooth, realoffset);
}

// Calculates the offset using a real world unit length
Float SplineHelp::GetOffsetFromUnit(Float unitoffset, Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetOffsetFromUnit));
	if (!shlib || !shlib->GetOffsetFromUnit) return 0.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetOffsetFromUnit))(unitoffset, segment);
}

// Converts offset in % of points to offset in %of length
Float SplineHelp::GetOffsetFromReal(Float offset, Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetOffsetFromReal));
	if (!shlib || !shlib->GetOffsetFromReal) return 0.0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetOffsetFromReal))(offset, segment);
}

// Retrives a matrix for any point along the spline in world space
Matrix SplineHelp::GetMatrix(Float offset, Int32 segment, Bool smooth, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetMatrix));
	if (!shlib || !shlib->GetMatrix) return Matrix();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetMatrix))(offset, segment, smooth, realoffset);
}

// retrieves an offset, index and segment from a line objects point index, users own offset,ind and segment
void SplineHelp::GetLinePointSegment(Int32 index, Float *offset, Int32 *ind, Int32 *segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetLinePointSegment));
	if (!shlib || !shlib->GetLinePointSegment) return;

	(reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetLinePointSegment))(index, offset, ind, segment);
}

// retrieves an offse, index and segment from a spline objects point index, users own offset,ind and segment
void SplineHelp::GetSplinePointSegment(Int32 index, Float *offset, Int32 *ind, Int32 *segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSplinePointSegment));
	if (!shlib || !shlib->GetSplinePointSegment) return;

	(reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetSplinePointSegment))(index, offset, ind, segment);
}

// converts an offset in percent over the whole spline length to a real offset, and segment (user owns off and segment)
// realoffset determines if the space used is unit space, or point index space
void SplineHelp::GlobalToLocal(Float offset, Float *off, Int32 *segment, Bool realoffset) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GlobalToLocal));
	if (!shlib || !shlib->GlobalToLocal) return;

	(reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GlobalToLocal))(offset, off, segment, realoffset);
}

// Converts the splines vertex index to a comparable line object index (used in the splinehelp), returns NOTOK if out of bounds
Int32 SplineHelp::SplineToLineIndex(Int32 index) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, SplineToLineIndex));
	if (!shlib || !shlib->SplineToLineIndex) return NOTOK;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->SplineToLineIndex))(index);
}

// Converts the lines vertex index to a comparable spline object index (used in the splinehelp), returns NOTOK if out of bounds
Int32 SplineHelp::LineToSplineIndex(Int32 index) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, LineToSplineIndex));
	if (!shlib || !shlib->LineToSplineIndex) return NOTOK;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->LineToSplineIndex))(index);
}

// Gets the number of lineobject points in the passed spline, optionally just in a single segment, returns NOTOK if out of bounds
Int32 SplineHelp::GetVertexCount(Int32 segment /*= NOTOK*/) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetVertexCount));
	if (!shlib || !shlib->GetVertexCount) return NOTOK;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetVertexCount))(segment);
}

// Gets the number of lineobject points in the passed spline, optionally just in a single segment
Matrix SplineHelp::GetVertexMatrix(Int32 segment, Int32 index) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetVertexMatrix2));
	if (!shlib || !shlib->GetVertexMatrix2) return Matrix();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetVertexMatrix2))(segment, index);
}

Bool SplineHelp::IsClosed(Int32 segment) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, IsClosed));
	if (!shlib || !shlib->IsClosed) return false;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->IsClosed))(segment);
}

SPLINETYPE SplineHelp::GetType() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetType));
	if (!shlib || !shlib->GetType) return SPLINETYPE::LINEAR;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetType))();
}

Bool SplineHelp::CopyTo(SplineHelp *dest) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, CopyTo));
	if (!shlib || !shlib->CopyTo) return false;

	iSplineHelp *d = (iSplineHelp*)dest;
	if (!d) return false;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->CopyTo))(d);
}

// Retrieve spline original point (vertex) count rather than the line point count
Int32 SplineHelp::GetPointCount() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetPointCount));
	if (!shlib || !shlib->GetPointCount) return 0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetPointCount))();
}

void SplineHelp::SetOwner(BaseObject *op)
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, SetOwner));
	if (!shlib || !shlib->SetOwner) return;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->SetOwner))(op);
}

UInt32 SplineHelp::GetDirty() const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetDirty));
	if (!shlib || !shlib->GetDirty) return 0;

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetDirty))();
}

Matrix SplineHelp::GetPointMatrix(Int32 splineVertexIndex) const
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetPointMatrix));
	if (!shlib || !shlib->GetPointMatrix) return Matrix();

	return (reinterpret_cast<const iSplineHelp*>(this)->*(shlib->GetPointMatrix))(splineVertexIndex);
}

LineObject* SplineHelp::GetLineObject()
{
	SplineHelpLibrary *shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetLineObject));
	if (!shlib || !shlib->GetLineObject) return nullptr;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->GetLineObject))();
}

SplineObject* SplineHelp::GetSplineObjectCache()
{
	SplineHelpLibrary* shlib = CheckSplineHelpLib(LIBOFFSET(SplineHelpLibrary, GetSplineObjectCache));
	if (!shlib || !shlib->GetSplineObjectCache) return nullptr;

	return (reinterpret_cast<iSplineHelp*>(this)->*(shlib->GetSplineObjectCache))();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
