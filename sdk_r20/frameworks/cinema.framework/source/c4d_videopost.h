/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_VIDEOPOST_H__
#define C4D_VIDEOPOST_H__

#include "c4d_baselist.h"
#include "c4d_videopostplugin.h"

//----------------------------------------------------------------------------------------
/// Represents a videopost node.
/// @addAllocFreeAutoAllocNote
///
/// To check if a videopost node is enabled use !@link BaseVideoPost pvp@endlink->@link BaseList2D::GetBit GetBit@endlink(@ref BIT_VPDISABLED).
//----------------------------------------------------------------------------------------
class BaseVideoPost : public BaseList2D
{
private:
	BaseVideoPost();
	~BaseVideoPost();

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{videopost}
	/// @param[in] type								The videopost ID.
	/// @return												@allocReturn{videopost}
	//----------------------------------------------------------------------------------------
	static BaseVideoPost* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{videoposts}
	/// @param[in] bl									@theToDestruct{videopost}
	//----------------------------------------------------------------------------------------
	static void Free(BaseVideoPost*& bl);

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next videopost in the list. Convenience version of GeListNode::GetNext().
	/// @return												The next videopost, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{videopost}
	//----------------------------------------------------------------------------------------
	BaseVideoPost* GetNext(void) { return (BaseVideoPost*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous videopost in the list. Convenience version of GeListNode::GetPred().
	/// @return												The previous videopost, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{videopost}
	//----------------------------------------------------------------------------------------
	BaseVideoPost* GetPred(void) { return (BaseVideoPost*)AtCall(GetPred) (); }

	/// @}

	/// @name Stereoscopic
	/// @{

	//----------------------------------------------------------------------------------------
	/// Merges stereoscopic images for rendering.
	/// @param[out] dest							The destination bitmap to be filled with the merged stereoscopic image. @callerOwnsPointed{bitmap}
	/// @param[in] source							An array containing the stereoscopic images.
	/// @param[in] cnt								The number of stereoscopic images in @formatParam{source}.
	/// @param[in] settings						The stereoscopic render settings. See @ref RDATA_STEREO.
	/// @param[in] transform					The color space transformation mode: @enumerateEnum{COLORSPACETRANSFORMATION}
	/// @return												@trueIfOtherwiseFalse{the stereo images were merged}
	//----------------------------------------------------------------------------------------
	Bool StereoMergeImages(BaseBitmap* dest, const BaseBitmap* const* source, Int32 cnt, const BaseContainer& settings, COLORSPACETRANSFORMATION transform);

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of stereoscopic editor cameras.
	/// @param[in] doc								The current document. @callerOwnsPointed{document}
	/// @param[in] bd									The current view. @callerOwnsPointed{view}
	/// @return												The number of stereoscopic cameras.
	//----------------------------------------------------------------------------------------
	Int32 StereoGetCameraCountEditor(BaseDocument* doc, BaseDraw* bd);

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of stereoscopic cameras used for rendering.
	/// @param[in] doc								The current document. @callerOwnsPointed{document}
	/// @param[in] rd									The current render settings. @callerOwnsPointed{render settings}
	/// @return												The number of stereoscopic cameras.
	//----------------------------------------------------------------------------------------
	Int32 StereoGetCameraCountRenderer(BaseDocument* doc, RenderData* rd);

	//----------------------------------------------------------------------------------------
	/// Retrieves the information structure for a stereoscopic camera.
	/// @param[in] doc								The current document. @callerOwnsPointed{document}
	/// @param[in] bd									The current view. @callerOwnsPointed{view}
	/// @param[in] rd									The current render settings. @callerOwnsPointed{render settings}
	/// @param[in] index							The index of the stereoscopic camera: @em 0 <= @formatParam{index} < StereoGetCameraCountRenderer()
	/// @param[out] info							Filled with the stereoscopic camera information.
	/// @return												@trueIfOtherwiseFalse{the stereoscopic camera information was retrieved}
	//----------------------------------------------------------------------------------------
	Bool StereoGetCameraInfo(BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 index, StereoCameraInfo& info);

	/// @}

	/// @name RenderEngineCheck
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if a videopost is available for a certain render engine.
	/// @param[in] id									The ID of the render engine.
	/// @return												@trueIfOtherwiseFalse{the videopost is available for the specified render engine}
	//----------------------------------------------------------------------------------------
	Bool RenderEngineCheck(Int32 id);

	/// @}
};

#endif // C4D_VIDEOPOST_H__
