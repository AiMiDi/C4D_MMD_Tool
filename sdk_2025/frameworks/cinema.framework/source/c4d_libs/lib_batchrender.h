/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_BATCHRENDER_H__
#define LIB_BATCHRENDER_H__

#ifdef __API_INTERN__
#include "c4d_basetime.h"
#include "ge_string.h"
#include "c4d_library.h"
#include "c4d_gui.h"
#include "lib_py.h"
#else
#include "c4d_library.h"
#include "lib_py.h"
#endif

namespace cinema
{

/// @addtogroup group_batchrenderlibrary Batch Render
/// @ingroup group_library
/// @{

/// Batch %Render library ID.
#define C4D_BATCHRENDER_LIBRARY_ID		465003507

/// @addtogroup BR_RENDER
/// @ingroup group_enumeration
/// @{
#define BR_STOP		1			///< Stops rendering.
#define BR_START	2			///< Starts rendering.
/// @}

/// @addtogroup RM_RENDER
/// @ingroup group_enumeration
/// @{
enum
{
	RM_PROGRESS = 1000,						///< Is rendering.
	RM_FINISHED,									///< Finished rendering.
	RM_STOPPED,										///< Stopped rendering (canceled).
	RM_ERROR,											///< Error.
	RM_ERROR2,										///< Error.
	RM_PAUSED,										///< Rendering paused.
	RM_QUEUE,											///< Resides within the render queue but is not rendered yet.
	RM_PROGRESS_WITH_WARNING,			///< %Render in progress but with warning.

	RM_NONE,											///< None.
};
/// @}

//----------------------------------------------------------------------------------------
/// A class to access the %Render Queue.
//----------------------------------------------------------------------------------------
class BatchRender
{
	private:
		BatchRender();
		~BatchRender();
	public:

		//----------------------------------------------------------------------------------------
		/// Opens the %Render Queue window.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Open();

		//----------------------------------------------------------------------------------------
		/// Adds a @C4D file to the %Render Queue.
		/// @param[in] File								The filename of the @C4D file.
		/// @param[in] number							The position within the %Render Queue. If this is greater than the current number of entries it will be added at the end of the list.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool AddFile(const Filename &File, Int32 number);

		//----------------------------------------------------------------------------------------
		/// Removes a @C4D file from the %Render Queue.
		/// @param[in] File								The @C4D file to be removed from the list.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool DelFile(const Filename &File);

		//----------------------------------------------------------------------------------------
		/// Checks if the render Queue is rendering.
		/// @return												@trueIfOtherwiseFalse{the render Queue is rendering}
		//----------------------------------------------------------------------------------------
		Bool IsRendering();

		//----------------------------------------------------------------------------------------
		/// Sets the render status of the %Render Queue.
		/// @param[in] set								The render status: @enumerateEnum{BR_RENDER}
		//----------------------------------------------------------------------------------------
		void SetRendering(Int32 set);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		Bool SetNetError(Int32 n, const String& machineName, const String& errorString, Bool isWarning);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		Bool SetNetError(const C4DUuid& uuid, const String& machineName, const String& errorString, Bool isWarning);

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of @C4D scene files in the %Render Queue.
		/// @return												The number of @C4D scene files.
		//----------------------------------------------------------------------------------------
		Int32 GetElementCount();

		//----------------------------------------------------------------------------------------
		/// Retrieves the filename of the @C4D scene file with the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The filename of the @C4D scene file.
		//----------------------------------------------------------------------------------------
		Filename GetElement(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Enables or disables the @C4D scene file at the index @formatParam{n} for rendering.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[in] bSet								@formatConstant{true} to enable the scene file for rendering, @formatConstant{false} to disable it.
		//----------------------------------------------------------------------------------------
		void EnableElement(Int32 n, Bool bSet);

		//----------------------------------------------------------------------------------------
		/// Checks if a @C4D scene file from the %Render Queue is enabled for rendering.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												@trueIfOtherwiseFalse{the scene file is enabled for rendering}
		//----------------------------------------------------------------------------------------
		Bool GetEnableElement(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the current status of the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The status: @enumerateEnum{RM_RENDER}
		//----------------------------------------------------------------------------------------
		Int32 GetElementStatus(Int32 n);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		void GetJsonJobs(PyList* list);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		BaseBitmap* GetFrameBitmap(const C4DUuid& nodeUuid, const C4DUuid& frameUuid);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		void SetUseNet(Int32 n, Bool on);

		//----------------------------------------------------------------------------------------
		/// Checks if there is a texture error.
		/// @return												@trueIfOtherwiseFalse{there is a texture error}
		//----------------------------------------------------------------------------------------
		Bool GetTextureError();

		//----------------------------------------------------------------------------------------
		/// Sets the texture error state.
		/// @param[in] state								@formatConstant{true} to set a texture error, @formatConstant{false} to clear it.
		//----------------------------------------------------------------------------------------
		void SetTextureError(Bool state);

		//----------------------------------------------------------------------------------------
		/// Checks if texture checking is enabled.
		/// @return												@trueIfOtherwiseFalse{texture checking is enabled}
		//----------------------------------------------------------------------------------------
		Bool GetCheckTexture();

		//----------------------------------------------------------------------------------------
		/// Enables or disables texture checking.
		/// @param[in] state								@formatConstant{true} to enable texture checking, @formatConstant{false} to disable it.
		//----------------------------------------------------------------------------------------
		void SetCheckTexture(Bool state);

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of takes for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The number of takes.
		//----------------------------------------------------------------------------------------
		Int32 GetTakeCount(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the names of all takes for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[out] names							An array to store the names of all takes. Indexes can be used directly with SetActiveTakeIndex.
		//----------------------------------------------------------------------------------------
		void GetAllTakeNames(Int32 n, maxon::BaseArray<String>& names);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active take index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The active take index.
		//----------------------------------------------------------------------------------------
		Int32 GetActiveTakeIndex(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active take name for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The active take name.
		//----------------------------------------------------------------------------------------
		String GetActiveTakeName(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Sets the active take index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[in] index							The index of the take to set as active.
		/// @param[in] takeOnly					@formatConstant{true} to set only the take, @formatConstant{false} to also set the take and camera and render settings.
		//----------------------------------------------------------------------------------------
		void SetActiveTakeIndex(Int32 n, Int32 index, Bool takeOnly);

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of render settings for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The number of render settings.
		//----------------------------------------------------------------------------------------
		Int32 GetRenderSettingsCount(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the names of all render settings for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[out] names							An array to store the names of all render settings. Indexes can be used directly with SetActiveRenderSettingsIndex.
		//----------------------------------------------------------------------------------------
		void GetAllRenderSettingsNames(Int32 n, maxon::BaseArray<String>& names);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active render settings index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The active render settings index.
		//----------------------------------------------------------------------------------------
		Int32 GetActiveRenderSettingsIndex(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active render settings name for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The active render settings name.
		//----------------------------------------------------------------------------------------
		String GetActiveRenderSettingsName(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Sets the active render settings index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[in] index							The index of the render settings to set as active.
		//----------------------------------------------------------------------------------------
		void SetActiveRenderSettingsIndex(Int32 n, Int32 index);

		//----------------------------------------------------------------------------------------
		/// Retrieves the names of all cameras for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[out] names							An array to store the names of all cameras. Indexes can be used with SetActiveCameraIndex by adding 1.
		//----------------------------------------------------------------------------------------
		void GetAllCameraNames(Int32 n, maxon::BaseArray<String>& names);

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of cameras for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The number of cameras.
		//----------------------------------------------------------------------------------------
		Int32 GetCameraCount(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active camera index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @return												The active camera index.
		//----------------------------------------------------------------------------------------
		Int32 GetActiveCameraIndex(Int32 n);

		//----------------------------------------------------------------------------------------
		/// Retrieves the active camera name for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[in] filename					@formatConstant{true} to retrieve the filename, @formatConstant{false} to retrieve the camera name.
		/// @return												The active camera name.
		//----------------------------------------------------------------------------------------
		String GetActiveCameraName(Int32 n, Bool filename);

		//----------------------------------------------------------------------------------------
		/// Sets the active camera index for the @C4D scene file at the index @formatParam{n}.
		/// @param[in] n									The position within the %Render Queue: @em 0 < @formatParam{n} < GetElementCount()
		/// @param[in] index							The index of the camera to set as active.
		//----------------------------------------------------------------------------------------
		void SetActiveCameraIndex(Int32 n, Int32 index);
};

//----------------------------------------------------------------------------------------
/// Retrieves a pointer to the BatchRender to access the %Render Queue.
/// @return												The pointer to the BatchRender. @cinemaOwnsPointed{BatchRender}
//----------------------------------------------------------------------------------------
BatchRender* GetBatchRender();

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class CINEWARE_SINGLEINHERITANCE iBatchRender;

struct BatchRenderLibrary : public C4DLibrary
{
	iBatchRender*	(*GetBatchRender)();

	Bool					(iBatchRender::*Open)								();
	Bool					(iBatchRender::*AddFile)						(const Filename &File, Int32 number);
	Bool					(iBatchRender::*DelFile)						(const Filename &File);

	Bool					(iBatchRender::*IsRendering)				();
	void					(iBatchRender::*SetRendering)				(Int32 set);


	Int32					(iBatchRender::*GetElementCount)		();

	Filename			(iBatchRender::*GetElement)					(Int32 n);
	void					(iBatchRender::*EnableElement)			(Int32 n, Bool bSet);
	Bool					(iBatchRender::*GetEnableElement)		(Int32 n);

	Int32					(iBatchRender::*GetElementStatus)		(Int32 n);

	Bool					(iBatchRender::*SetNetErrorEx)			(Int32 n, const String& machineName, const String& errorString, Bool isWarning);
	void					(iBatchRender::*GetJsonJobs)				(PyList* list);
	BaseBitmap*		(iBatchRender::*GetFrameBitmap)			(const C4DUuid& nodeUuid, const C4DUuid& frameUuid);
	Bool					(iBatchRender::*SetNetError)				(const C4DUuid& uuid, const String& machineName, const String& errorString, Bool isWarning);
	void					(iBatchRender::*SetUseNet)					(Int32 n, Bool on);

	Bool					(iBatchRender::*GetTextureError)		();
	void					(iBatchRender::*SetTextureError)		(Bool state);
	Bool					(iBatchRender::*GetCheckTexture)		();
	void					(iBatchRender::*SetCheckTexture)		(Bool state);

	Int32					(iBatchRender::*GetTakeCount)					(Int32 n);
	void					(iBatchRender::*GetAllTakeNames)			(Int32 n, maxon::BaseArray<String>& names);
	Int32					(iBatchRender::*GetActiveTakeIndex)		(Int32 n);
	String				(iBatchRender::*GetActiveTakeName)		(Int32 n);
	void					(iBatchRender::*SetActiveTakeIndex)		(Int32 n, Int32 index, Bool takeOnly);
	
	Int32					(iBatchRender::*GetRenderSettingsCount)				(Int32 n);
	void					(iBatchRender::*GetAllRenderSettingsNames)		(Int32 n, maxon::BaseArray<String>& names);
	Int32					(iBatchRender::*GetActiveRenderSettingsIndex)	(Int32 n);
	String				(iBatchRender::*GetActiveRenderSettingsName)	(Int32 n);
	void					(iBatchRender::*SetActiveRenderSettingsIndex)	(Int32 n, Int32 index);

	Int32					(iBatchRender::*GetCameraCount)				(Int32 n);
	void					(iBatchRender::*GetAllCameraNames)		(Int32 n, maxon::BaseArray<String>& names);
	Int32					(iBatchRender::*GetActiveCameraIndex)	(Int32 n);
	String				(iBatchRender::*GetActiveCameraName)	(Int32 n, Bool filename);
	void					(iBatchRender::*SetActiveCameraIndex)	(Int32 n, Int32 index);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_BATCHRENDER_H__

