/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_POLYGONREDUCTION_H__
#define LIB_POLYGONREDUCTION_H__

#include "c4d_library.h"

#ifdef __API_INTERN__
#include "basedocument.h"
#else
#include "c4d_basedocument.h"
#endif


/// @addtogroup group_polygonreductionlibrary Polygon Reduction
/// @ingroup group_library
/// @since R19
/// @{

/// Polygon Reduction library ID. @since R19
static const Int32 ID_POLYGONREDUCTION_LIB = 431000184;

//----------------------------------------------------------------------------------------
/// Stores information required for polygon reduction.
/// @since R19
//----------------------------------------------------------------------------------------
class PolygonReductionData
{
public:

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	PolygonReductionData() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] doc								The document. Must not be @formatConstant{nullptr}. @callerOwnsPointed{BaseDocument}
	/// @param[in] op									The polygon object to be reduced. @callerOwnsPointed{PolygonObject}
	/// @param[in] thread							The caller thread. Set to @formatConstant{nullptr} if synchronous pre-processing calculation is needed (e.g. during rendering). @callerOwnsPointed{BaseThread}
	//----------------------------------------------------------------------------------------
	PolygonReductionData(BaseDocument* doc, PolygonObject* op, BaseThread* thread) : _doc(doc), _op(op), _thread(thread) { }

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~PolygonReductionData() { _doc = nullptr; _op = nullptr; _thread = nullptr; }

	BaseDocument*		_doc = nullptr;					///< The document. Must not be @formatConstant{nullptr}.
	PolygonObject*	_op = nullptr;					///< The polygon object to be reduced.
	BaseThread*			_thread = nullptr;			///< The caller thread. Set to @formatConstant{nullptr} if synchronous pre-processing calculation is needed (e.g. during rendering).
	BaseContainer		_settings;							///< The reduction constraints settings. See opolyreduxgen.h
};

//----------------------------------------------------------------------------------------
/// Performs polygon reduction for a polygon object.
/// @since R19
//----------------------------------------------------------------------------------------
class PolygonReduction
{
private:
	PolygonReduction();
	~PolygonReduction();

public:
	
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{PolygonReduction}
	/// @return												@allocReturn{PolygonReduction}
	//----------------------------------------------------------------------------------------
	static PolygonReduction* Alloc();
	
	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{PolygonReductions}
	/// @param[in] node								@theToDestruct{PolygonReduction}
	//----------------------------------------------------------------------------------------
	static void Free(PolygonReduction*& node);

	/// @}

	/// @name Processing
	/// @{

	//----------------------------------------------------------------------------------------
	/// Starts the background or synchronous preprocessing that sets up the polygon reduction cache.
	/// @param[in] data								The data for the reduction.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool PreProcess(const PolygonReductionData& data);

	//----------------------------------------------------------------------------------------
	/// Checks whether the background preprocessing thread is still running.
	/// @return												@trueIfOtherwiseFalse{preprocessing is ongoing}
	//----------------------------------------------------------------------------------------
	Bool IsPreprocessing();

	//----------------------------------------------------------------------------------------
	/// Aborts preprocessing if it is running in the background. Resets the interactive settings values.
	//----------------------------------------------------------------------------------------
	void StopPreprocessing();

	//----------------------------------------------------------------------------------------
	/// Aborts preprocessing if it is running in the background and frees all temporary data.
	//----------------------------------------------------------------------------------------
	void Reset();

	/// @}

	/// @name Levels
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the reduction strength level if the desired level is different than the current one.
	/// @param[in] strengthLevel			The desired reduction strength level.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetReductionStrengthLevel(Float strengthLevel);

	//----------------------------------------------------------------------------------------
	/// Reduces or restores the mesh to the desired number of triangles.
	/// @note	If the desired level is different than the current level, at least one edge collapse or restore will be performed.
	/// 			The actual resulting number of triangles may be slightly different.
	/// @param[in] desiredLevel				The desired number of triangles on call.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetTriangleLevel(Int32 desiredLevel);

	//----------------------------------------------------------------------------------------
	/// Reduces or restores the mesh to the desired number of vertices.
	/// @note	If the desired level is different than the current level, at least one edge collapse or restore will be performed.
	/// 			The actual resulting number of vertices may be slightly different.
	/// @param[in] desiredLevel				The desired number of vertices on call.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetVertexLevel(Int32 desiredLevel);

	//----------------------------------------------------------------------------------------
	/// Reduces or restores the mesh to the desired number of edges remaining to collapse.
	/// @note	If the desired level is different than the current level, at least one edge collapse or restore will be performed.
	/// 			The actual resulting number of edges may be slightly different.
	/// @param[in] desiredLevel				The desired collapse stack index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetRemainingEdgesLevel(Int32 desiredLevel);

	//----------------------------------------------------------------------------------------
	/// Queries the current reduction strength level.
	/// @return												The reduction strength percentage: @em 0 means no reduction performed, @em 1 means maximum reduction performed.
	//----------------------------------------------------------------------------------------
	Float GetReductionStrengthLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the current triangle count.
	/// @return												The triangle count.
	//----------------------------------------------------------------------------------------
	Int32 GetTriangleLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the current vertex count.
	/// @return												The vertex count.
	//----------------------------------------------------------------------------------------
	Int32 GetVertexLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the current remaining number of edges available to collapse.
	/// @return												The remaining edges level.
	//----------------------------------------------------------------------------------------
	Int32 GetRemainingEdgesLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the maximum reduction strength percentage.
	/// @return												The maximum reduction strength percentage. Always @em 1.0.
	//----------------------------------------------------------------------------------------
	Float GetMaxReductionStrengthLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the triangle count when no reduction has been performed.
	/// @return												The maximum triangle count.
	//----------------------------------------------------------------------------------------
	Int32 GetMaxTriangleLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the vertex count when no reduction has been performed.
	/// @return												The maximum vertex count.
	//----------------------------------------------------------------------------------------
	Int32 GetMaxVertexLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the total number of possible edge collapses.
	/// @return												The maximum collapse count.
	//----------------------------------------------------------------------------------------
	Int32 GetMaxRemainingEdgesLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the triangle count when complete reduction has been performed.
	/// @return												The minimum triangle count. May be non-zero if border constraints are enabled.
	//----------------------------------------------------------------------------------------
	Int32 GetMinTriangleLevel() const;

	//----------------------------------------------------------------------------------------
	/// Queries the vertex count when complete reduction has been performed.
	/// @return												The minimum vertex count. May be non-zero if border constraints are enabled.
	//----------------------------------------------------------------------------------------
	Int32 GetMinVertexLevel() const;

	/// @}
	
	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the associated PolygonReductionData.
	/// @return												The polygon reduction data.
	//----------------------------------------------------------------------------------------
	const PolygonReductionData& GetData() const;

	//----------------------------------------------------------------------------------------
	/// Checks if a valid object and a valid document are associated with the PolygonReduction instance.
	/// @return												@trueIfOtherwiseFalse{the PolygonReduction instance is valid}
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class	iPolygonReduction;

struct PolygonReductionLibrary : public C4DLibrary
{
	PolygonReduction*							(*Alloc)																					();
	void													(*Free)																						(PolygonReduction*& node);
	Bool													(iPolygonReduction::*PreProcess)									(const PolygonReductionData& data);
	Bool													(iPolygonReduction::*IsPreprocessing)							();
	void													(iPolygonReduction::*StopPreprocessing)						();
	void													(iPolygonReduction::*Reset)												();
	Bool													(iPolygonReduction::*SetReductionStrengthLevel)		(Float strengthLevel);
	Bool													(iPolygonReduction::*SetTriangleLevel)						(Int32 desiredLevel);
	Bool													(iPolygonReduction::*SetVertexLevel)							(Int32 desiredLevel);
	Bool													(iPolygonReduction::*SetRemainingEdgesLevel)						(Int32 desiredLevel);
	Float													(iPolygonReduction::*GetReductionStrengthLevel)		() const;
	Int32													(iPolygonReduction::*GetTriangleLevel)						() const;
	Int32													(iPolygonReduction::*GetVertexLevel)							() const;
	Int32													(iPolygonReduction::*GetRemainingEdgesLevel)						() const;
	Float													(iPolygonReduction::*GetMaxReductionStrengthLevel)() const;
	Int32													(iPolygonReduction::*GetMaxTriangleLevel)					() const;
	Int32													(iPolygonReduction::*GetMaxVertexLevel)						() const;
	Int32													(iPolygonReduction::*GetMaxRemainingEdgesLevel)					() const;
	Int32													(iPolygonReduction::*GetMinTriangleLevel)					() const;
	Int32													(iPolygonReduction::*GetMinVertexLevel)						() const;

	const PolygonReductionData&		(iPolygonReduction::*GetData)											() const;
	Bool													(iPolygonReduction::*IsValid)											() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_POLYGONREDUCTION_H__
