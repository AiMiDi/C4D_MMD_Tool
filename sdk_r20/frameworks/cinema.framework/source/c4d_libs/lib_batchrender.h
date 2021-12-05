/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
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

/// @addtogroup group_batchrenderlibrary Batch Render
/// @ingroup group_library
/// @{

class GeListNode;
class Filename;
class BaseBitmap;
class BaseDocument;
class String;
class BaseSound;

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
		Bool Open(void);

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

class iBatchRender;

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
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_BATCHRENDER_H__

