/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SPLINEHELP_H__
#define LIB_SPLINEHELP_H__

#include "ge_math.h"
#include "c4d_library.h"

#ifndef __API_INTERN__
#include "c4d_baseobject.h"
#endif

/// @addtogroup group_splinehelplibrary SplineHelp Library
/// @ingroup group_library
/// @{

/// SplineHelp library ID.
#define C4D_SPLINEHELP_LIBRARY_ID		1019534

/// @addtogroup SPLINEHELPFLAGS
/// @{
/// Initialization flags for SplineHelp, use these to control the output returned from the class.
/// @since R17.032
enum class SPLINEHELPFLAGS
{
	NONE								=	0,						///< None.
	USERDEFORMERS				=	(1 << 0),			///< Use deformed splines.
	GLOBALSPACE					=	(1 << 1),			///< Generate results in global rather than spline local space.
	TARGETRAIL					=	(1 << 2),			///< Target the rail spline (if passed).
	CONTINUECURVE				=	(1 << 3),			///< Continue the curvature of an existing spline at the end points.
	FORCEUPDATE					=	(1 << 4),			///< Force the SplineHelp to recalculate regardless of spline dirtiness.
	RETAINLINEOBJECT		=	(1 << 5)			///< Retain a copy of the line object for user usage via SplineHelp::GetLineObject().
} MAXON_ENUM_FLAGS(SPLINEHELPFLAGS);
/// @}

//----------------------------------------------------------------------------------------
/// Class for helping to deal with splines. Defines routines to get positions along splines from real-world units, non flipping/non gimbal locked matrices and vectors from splines.\n
/// Must be initialized before use. All values returned are in global space. The slow part is the InitSpline() routine; other access is pretty fast.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SplineHelp
{
private:
	SplineHelp();
	~SplineHelp();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{spline help}
	/// @return												@allocReturn{spline help}
	//----------------------------------------------------------------------------------------
	static SplineHelp *Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{spline help instances}
	/// @param[in] node								@theToDestruct{spline help}
	//----------------------------------------------------------------------------------------
	static void Free(SplineHelp *&node);

	/// @}

	/// @name Init/Free Spline
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the spline data. @b Deprecated since R17.
	/// @warning Must be called before any other access.
	/// @param[in] op									The spline object to use. @callerOwnsPointed{spline object}
	/// @param[in] upvector						An optional up-vector for the spline normals generation. This is only used at the start of splines/segments; this way it avoids gimbal lock if at all possible.
	/// @param[in] rail								An optional rail spline object for the spline normals generation. @callerOwnsPointed{spline object}
	/// @param[in] target_rail				If @formatConstant{true} the optional rail spline is not only used as up-vector but also as target.\n
	/// 															This is used for instance in MoGraph's Rail options (Cloner, Spline effector, Spline Wrap etc.).
	/// @param[in] use_deformed_points	If @formatConstant{true} uses the deformed point positions of the spline.
	/// @param[in] force_update				If @formatConstant{true} forces a full initialization.\n
	/// 															The spline help class internally caches its own content. Thus it will be much faster if the same splines are used for initialization.\n.
	/// @param[in] use_global_space		If @formatConstant{false} the resulting matrices are in local space rather than in the spline objects' global space.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitSplineEx(BaseObject *op, Vector upvector = Vector(0.0), BaseObject *rail = nullptr, Bool target_rail = true, Bool use_deformed_points = false, Bool force_update = false, Bool use_global_space = true);

	//----------------------------------------------------------------------------------------
	/// Frees the spline data. Recalling InitSpline() or calling Free() will automatically call this.
	//----------------------------------------------------------------------------------------
	void FreeSpline(void);

	/// @}

	/// @name Count
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of segments in the spline.
	/// @note Unlike the way @C4D handles segments where a segment count of @em 0 means there is either no segments or @em 1 segment, this returns @em 1 segment if there is @em 1 and @em 0 if there are @em 0.
	/// @return												The segment count.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentCount(void);

	//----------------------------------------------------------------------------------------
	/// Gets the number of vertices for a spline segment.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The number of vertices.
	//----------------------------------------------------------------------------------------
	Int32 GetVertexCount(Int32 segment = NOTOK);

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of spline points.
	/// @return												The number of spline points.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount(void);

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the spline's real-world unit length including all segments.
	/// @return												The spline length.
	//----------------------------------------------------------------------------------------
	Float GetSplineLength(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves a specific segment's real-world unit length.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The length of the specified @formatParam{segment}.
	//----------------------------------------------------------------------------------------
	Float GetSegmentLength(Int32 segment);

	//----------------------------------------------------------------------------------------
	/// Retrieves a full matrix for a specific point of the line.
	/// @note This is not the spline vertex, but instead the line object's vertex. (Calculated with LOD = @em 1.0.)
	/// @param[in] index							The index of the line object vertex: @em 0 <= @formatParam{index} < @formatParam{op}->@link LineObject::GetPointCount GetPointCount()@endlink
	/// @return												The coordinate system matrix at @formatParam{index}.
	//----------------------------------------------------------------------------------------
	Matrix GetVertexMatrix(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Converts a natural offset value to a real percentage offset value.
	/// @note The percentage uses the real-world units for its offset, so regardless of how the spline's points and interpolation is set, a gap of @em 2% on a @em 100m long spline will always be @em 2m whereas normally in spline natural space, a gap of @em 2% can vary a great deal depending on the spline's interpolation etc.
	/// @param[in] offset							The offset given in spline space.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The real-world percentage offset.
	//----------------------------------------------------------------------------------------
	Float GetPointValue(Float offset, Int32 segment);

	//----------------------------------------------------------------------------------------
	/// Retrieves the nearest line point index to the given real @formatParam{offset}.
	/// @param[in] offset							The spline space offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The nearest line object point index, rounded down.
	//----------------------------------------------------------------------------------------
	Int32 GetPointIndex(Float offset, Int32 segment);

	//----------------------------------------------------------------------------------------
	/// Gets a position along the spline.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The position given by @formatParam{offset} in global space.
	//----------------------------------------------------------------------------------------
	Vector GetPosition(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Gets a tangent vector for any point along the spline.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The tangent given by @formatParam{offset} in global space.
	//----------------------------------------------------------------------------------------
	Vector GetTangent(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Gets a normal vector for any point along the spline.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The normal given by @formatParam{offset} in global space.
	//----------------------------------------------------------------------------------------
	Vector GetNormal(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Gets a cross normal vector (i.e. perpendicular to the normal and the tangent) for any point along the spline.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The cross normal given by @formatParam{offset} in global space.
	//----------------------------------------------------------------------------------------
	Vector GetCrossNormal(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Converts a percentage offset into a natural offset. Percentage offsets ignore spline interpolation etc and are always @em x% along the spline.
	/// @param[in] unitoffset					A percentage offset: @em 0 <= @formatParam{unitoffset} <= @em 1.0.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The natural offset.
	//----------------------------------------------------------------------------------------
	Float GetOffsetFromUnit(Float unitoffset, Int32 segment = 0);

	//----------------------------------------------------------------------------------------
	/// Retrieves an offset from a real-world unit.\n
	/// For example, if a spline is @em 50 units long, @em 25 would be @em 50% of the length, i.e. @em 0.5.
	/// @param[in] offset							The real unit offset to convert.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												The offset in spline space.
	//----------------------------------------------------------------------------------------
	Float GetOffsetFromReal(Float offset, Int32 segment = 0);

	//----------------------------------------------------------------------------------------
	/// Retrieves a full matrix for any point along the spline, constructed as a local coordinate system at that point.\n
	/// Optionally uses real-world percentage rather than spline natural space for the @formatParam{offset}.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The coordinate system matrix at @formatParam{offset}.
	//----------------------------------------------------------------------------------------
	Matrix GetMatrix(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Converts a global point @formatParam{index} in a line (i.e. from @em 0 to the number of points in the line object) to a local set of values within a single segment returning the segment the point is in, the offset along the segment and the point index within the segment (@em 0 to the segment point count).
	/// @param[in] index							The line object vertex index: @em 0 <= @formatParam{index} < @formatParam{op}->@link LineObject::GetPointCount GetPointCount()@endlink (Using LOD = @em 1.0 for the line object.)
	/// @param[out] offset						Assigned the offset along the segment.
	/// @param[out] ind								Assigned the point index within the segment.
	/// @param[out] segment						Assigned the segment index.
	//----------------------------------------------------------------------------------------
	void GetLinePointSegment(Int32 index, Float *offset, Int32 *ind, Int32 *segment);

	//----------------------------------------------------------------------------------------
	/// Converts a global point index in (i.e. from @em 0 to the number of points in the spline) to a local set of values within a single segment returning the segment the point is in, the offset along the segment and the point index within the segment (@em 0 0 to the segment point count).
	/// @note This is the same as GetLinePointSegment(), but uses the spline's set of indexes.
	/// @param[in] index							The global spline point index: @em 0 <= @formatParam{index} < @formatParam{op}->@link SplineObject::GetPointCount GetPointCount()@endlink
	/// @param[out] offset						Assigned the offset along the segment.
	/// @param[out] ind								Assigned the point index within the segment.
	/// @param[out] segment						Assigned the segment index.
	//----------------------------------------------------------------------------------------
	void GetSplinePointSegment(Int32 index, Float *offset, Int32 *ind, Int32 *segment);

	//----------------------------------------------------------------------------------------
	/// Turns a percentage along the whole spline to local segment info, offset along segment, the segment the point exists in.\n
	/// Optionally uses a real @em % offset rather than the spline natural offset.
	/// @param[in] offset							The percentage along the whole spline.
	/// @param[out] off								Assigned the offset along the segment.
	/// @param[out] segment						Assigned the segment index.
	/// @param[in] realoffset					If @formatConstant{true} a real-world percentage is used, rather than the natural spline space.
	//----------------------------------------------------------------------------------------
	void GlobalToLocal(Float offset, Float *off, Int32 *segment, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Converts a spline vertex @formatParam{index} to its corresponding line object vertex index.
	/// @param[in] index							The spline vertex index: @em 0 <= @formatParam{index} < @formatParam{op}->@link SplineObject::GetPointCount GetPointCount()@endlink
	/// @return												The line object vertex index: @em 0 <= @formatParam{index} < @formatParam{op}->@link LineObject::GetPointCount GetPointCount()@endlink
	//----------------------------------------------------------------------------------------
	Int32 SplineToLineIndex(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Converts a line object vertex @formatParam{index} to its corresponding spline vertex index.
	/// @param[in] index							The line object vertex index: @em 0 <= @formatParam{index} < @formatParam{op}->@link LineObject::GetPointCount GetPointCount()@endlink
	/// @return												The spline vertex index: @em 0 <= @formatParam{index} < @formatParam{op}->@link SplineObject::GetPointCount GetPointCount()@endlink
	//----------------------------------------------------------------------------------------
	Int32 LineToSplineIndex(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the distance to an existing rail spline for any point along the spline.
	/// @param[in] offset							The spline offset.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] smooth							If @formatConstant{true} the position is smoothed.
	/// @param[in] realoffset					If @formatConstant{true} uses uniform spline distribution.
	/// @return												The distance given by @formatParam{offset}.
	//----------------------------------------------------------------------------------------
	Float GetSize(Float offset, Int32 segment = 0, Bool smooth = true, Bool realoffset = false);

	//----------------------------------------------------------------------------------------
	/// Gets the distance to an existing rail spline for a spline vertex specified by @formatParam{index}.
	/// @param[in] index							The vertex index: @em 0 <= @formatParam{index} < GetVertexCount()
	/// @return												The distance given by @formatParam{index}.
	//----------------------------------------------------------------------------------------
	Float GetVertexSize(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the matrix for a spline vertex specified by @formatParam{segment} and @formatParam{index}.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @param[in] index							The vertex index: @em 0 <= @formatParam{index} < GetVertexCount()
	/// @return												The matrix given by @formatParam{segment} and @formatParam{index}.
	//----------------------------------------------------------------------------------------
	Matrix GetVertexMatrix(Int32 segment, Int32 index);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the spline helper data to another SplineHelp.
	/// @param[in,out] dest						The destination spline help. @callerOwnsPointed{spline help}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(SplineHelp *dest) const;

	//----------------------------------------------------------------------------------------
	/// Checks if the spline helper contains data and has been initialized.
	/// @return												@trueIfOtherwiseFalse{the spline helper is ready to use}
	//----------------------------------------------------------------------------------------
	Bool Exists(void);

	//----------------------------------------------------------------------------------------
	/// Checks if a spline segment is closed.
	/// @param[in] segment						The segment index: @em 0 <= @formatParam{segment} < GetSegmentCount()
	/// @return												@trueIfOtherwiseFalse{the spline segment is closed}
	//----------------------------------------------------------------------------------------
	Bool IsClosed(Int32 segment = 0);

	//----------------------------------------------------------------------------------------
	/// Retrieves the spline interpolation type.
	/// @return												The spline interpolation type: @enumerateEnum{SPLINETYPE}
	//----------------------------------------------------------------------------------------
	SPLINETYPE GetType(void);

	//----------------------------------------------------------------------------------------
	/// Prevents recursion lock crashes when SplineHelp needs to create the cache of the passed spline.\n
	/// This is the case if for instance the developer has no control over the placement of a spline object in relation to its node.\n
	/// For instance prevents infinite recursion in an object generator linking to itself using link fields.\n
	/// @b Example:
	/// @code
	/// class MyBaseObject : public ObjectData
	/// {
	/// 	INSTANCEOF(MyBaseObject, ObjectData)
	/// public:
	/// 	AutoAlloc<SplineHelp> shelp;
	///
	/// 	virtual Bool Init(GeListNode *node)
	/// 	{
	/// 		if (!shelp)
	/// 			return false;
	/// 		shelp->SetOwner((BaseObject*)node);		// Only needs to be set once so NodeData::Init is a good place
	///
	/// 		return true;
	/// 	}
	///
	/// 	...
	///
	/// 	// In some other function
	/// 	if (shelp->InitSpline(spline))		// etc.
	///
	/// 	...
	/// };
	/// @endcode
	/// It is also possible to call
	/// @code
	/// shelp->SetOwner(thisobject);
	/// shelp->InitSpline(spline);
	/// @endcode
	/// ObjectData::GetVirtualObjects() rather than in ObjectData::Init(). SetOwner() is not very costly to call.
	/// @warning Must be called before InitSpline().
	/// @param[in] op									The object owning the current node data.\n
	/// 															If called from within a tag plugin pass the tag's parent object:
	/// 															@code
	/// 															shelp->SetOwner(tag->GetObject())
	/// 															@endcode
	/// 															If called from within an object plugin use:
	/// 															@code
	/// 															shelp->SetOwner((BaseObject*)node->Get())
	/// 															@endcode
	//----------------------------------------------------------------------------------------
	void SetOwner(BaseObject *op);

	//----------------------------------------------------------------------------------------
	/// Gets the dirty value for the SplineHelp which indicates how often the help has been updated with new values.
	/// i.e. how often the source spline has changed, and or the spline has been cleared.
	/// @since R17.032
	/// @return												The dirty checksum.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty() const;

	//----------------------------------------------------------------------------------------
	/// Gets the matrix for a spline vertex.
	/// @since R17.032
	/// @param[in] splineVertexIndex	The zero-based index of the spline vertex.
	/// @return												The resulting @ref Matrix for that point along the spline.
	//----------------------------------------------------------------------------------------
	Matrix GetPointMatrix(Int32 splineVertexIndex);

	//----------------------------------------------------------------------------------------
	/// Gets a LineObject from SplineHelp functions.
	/// @warning Call InitSpline() with @ref SPLINEHELPFLAGS::RETAINLINEOBJECT for this method to return a line object.
	/// @since R17.032
	/// @return												The line object. @formatConstant{nullptr} if it fails or if the SplineHelp was not initialized with @ref SPLINEHELPFLAGS::RETAINLINEOBJECT.
	//----------------------------------------------------------------------------------------
	LineObject* GetLineObject();

	/// @}

	/// @name Init/Free Spline
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the SplineHelp with the passed spline @formatParam{op}, must be called before any other functions can be utilized.
	/// @warning Must be called before any other access.
	/// @since R17.032
	/// @param[in] op									The spline object to initialize from. @callerOwnsPointed{spline object}
	/// @param[in] flags							The optional flags used to control how the SplineHelp is setup: @enumerateEnum{SPLINEHELPFLAGS}
	/// @return												@trueIfOtherwiseFalse{the SplineHelp was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool InitSpline(BaseObject *op, SPLINEHELPFLAGS flags = SPLINEHELPFLAGS::GLOBALSPACE | SPLINEHELPFLAGS::CONTINUECURVE);

	//----------------------------------------------------------------------------------------
	/// Initializes the SplineHelp with the passed spline @formatParam{op}, must be called before any other functions can be utilized.
	/// @warning Must be called before any other access.
	/// @since R17.032
	/// @param[in] op									The spline object to initialize from. @callerOwnsPointed{spline object}
	/// @param[in] upvector						The initial up-vector for the spline if no rail spline is passed.
	/// @param[in] flags							The optional flags used to control how the SplineHelp is setup: @enumerateEnum{SPLINEHELPFLAGS}
	/// @return												@trueIfOtherwiseFalse{the SplineHelp was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool InitSpline(BaseObject *op, Vector upvector, SPLINEHELPFLAGS flags = SPLINEHELPFLAGS::GLOBALSPACE | SPLINEHELPFLAGS::CONTINUECURVE);

	//----------------------------------------------------------------------------------------
	/// Initializes the SplineHelp with the passed spline @formatParam{op}, must be called before any other functions can be utilized.
	/// @warning Must be called before any other access.
	/// @since R17.032
	/// @param[in] op									The SplineObject to initialize from. @callerOwnsPointed{spline object}
	/// @param[in] rail								The rail spline. @callerOwnsPointed{spline object}
	/// @param[in] flags							The optional flags used to control how the SplineHelp is setup: @enumerateEnum{SPLINEHELPFLAGS}
	/// @return												@trueIfOtherwiseFalse{the SplineHelp was successfully initialized}
	//----------------------------------------------------------------------------------------
	Bool InitSpline(BaseObject *op, BaseObject *rail, SPLINEHELPFLAGS flags = SPLINEHELPFLAGS::TARGETRAIL | SPLINEHELPFLAGS::GLOBALSPACE | SPLINEHELPFLAGS::CONTINUECURVE);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iSplineHelp;

struct SplineHelpLibrary : public C4DLibrary
{
	iSplineHelp*			(*Alloc)();
	void							(*Free)(iSplineHelp *&node);

	Bool							(iSplineHelp::*InitSplineEx2)(SplineObject *op, Vector upvector);

	void							(iSplineHelp::*FreeSpline)();
	Bool							(iSplineHelp::*Exists)();
	Int32							(iSplineHelp::*GetSegmentCount)();
	Float							(iSplineHelp::*GetSplineLength)();
	Float							(iSplineHelp::*GetSegmentLength)(Int32 segment);
	Float							(iSplineHelp::*GetPointValue)(Float offset, Int32 segment);
	Int32							(iSplineHelp::*GetPointIndex)(Float offset, Int32 segment);

	Vector						(iSplineHelp::*GetPositionEx)(Float offset, Int32 segment, Bool smooth);
	Vector						(iSplineHelp::*GetTangentEx)(Float offset, Int32 segment, Bool smooth);
	Vector						(iSplineHelp::*GetNormalEx)(Float offset, Int32 segment, Bool smooth);
	Vector						(iSplineHelp::*GetCrossNormalEx)(Float offset, Int32 segment, Bool smooth);

	Float							(iSplineHelp::*GetOffsetFromUnit)(Float unitoffset, Int32 segment);
	Float							(iSplineHelp::*GetOffsetFromReal)(Float offset, Int32 segment);

	Matrix						(iSplineHelp::*GetMatrix)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	void							(iSplineHelp::*GetLinePointSegment)(Int32 index, Float *offset, Int32 *ind, Int32 *segment);
	void							(iSplineHelp::*GetSplinePointSegment)(Int32 index, Float *offset, Int32 *ind, Int32 *segment);
	void							(iSplineHelp::*GlobalToLocal)(Float offset, Float *off, Int32 *segment, Bool realoffset);
	Matrix						(iSplineHelp::*GetVertexMatrix)(Int32 index);
	Int32							(iSplineHelp::*SplineToLineIndex)(Int32 index);

	// MoGraph 2 Updates
	Bool							(iSplineHelp::*InitSplineEx)(BaseObject *op, Vector upvector, BaseObject *rail, Bool target_rail, Bool use_deformed_points, Bool force_update, Bool use_global_space);
	Vector						(iSplineHelp::*GetPosition)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	Vector						(iSplineHelp::*GetTangent)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	Vector						(iSplineHelp::*GetNormal)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	Vector						(iSplineHelp::*GetCrossNormal)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	Float							(iSplineHelp::*GetSize)(Float offset, Int32 segment, Bool smooth, Bool realoffset);
	Float							(iSplineHelp::*GetVertexSize)(Int32 index);
	Int32							(iSplineHelp::*GetVertexCount)(Int32 segment);
	Matrix						(iSplineHelp::*GetVertexMatrix2)(Int32 segment, Int32 index);
	Bool							(iSplineHelp::*IsClosed)(Int32 segment);
	SPLINETYPE				(iSplineHelp::*GetType)();
	Bool							(iSplineHelp::*CopyTo)(iSplineHelp *dest) const;

	Int32							(iSplineHelp::*GetPointCount)();
	void							(iSplineHelp::*SetOwner)(BaseObject *op);

	Int32							(iSplineHelp::*LineToSplineIndex)(Int32 index);

	UInt32						(iSplineHelp::*GetDirty)();

	Matrix						(iSplineHelp::*GetPointMatrix)(Int32 index);

	Bool							(iSplineHelp::*InitSpline)(BaseObject *op, Vector upvector, BaseObject *rail, SPLINEHELPFLAGS flags);

	LineObject*				(iSplineHelp::*GetLineObject)();
};

#ifdef __API_INTERN__
#include "lib_splinehelp.cpp"
#endif

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_SPLINEHELP_H__
