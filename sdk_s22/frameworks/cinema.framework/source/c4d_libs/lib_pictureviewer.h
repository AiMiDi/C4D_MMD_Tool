/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

//---------------------------------------------------
#ifndef LIB_PICTUREVIEWER_H__
#define LIB_PICTUREVIEWER_H__

#ifdef __API_INTERN__
#include "c4d_basetime.h"
#include "ge_string.h"
#include "c4d_library.h"
#include "c4d_gui.h"
#else
#include "c4d_string.h"
#include "c4d_library.h"
#endif

class GeListNode;
class Filename;
class BaseBitmap;
class BaseDocument;
class String;
class BaseSound;

#define C4D_PICTUREVIEWER_LIBRARY_ID		430000795

#define PICTUREVIEWER_INIT_ACTIVE		(-1)
#define PICTUREVIEWER_INIT_RENDER		(-2)

struct PvForceShowStatusBar
{
	GeListNode* _pv_folder;
	Bool _forceShowStatusBar;
	String _statusBarText;

	PvForceShowStatusBar() : _pv_folder(nullptr), _forceShowStatusBar(false) { }
};

#define MSG_PICTUREVIEWER_OVERWRITEIMAGE			300001064
#define MSG_PICTUREVIEWER_FORCESHOWSTATUSBAR	300001065

enum class STEREOTYPE
{
	REGULAR	=	0,
	STREAM		= 1,
	COMBINED	= 2
} MAXON_ENUM_LIST(STEREOTYPE);

enum class PVFRAME_FINISH
{
	DESTROY_NODE						= 0,
	KEEP_NODE_AND_COPYBMP		= 1,
	KEEP_NODE_AND_USEBMP		= 2
} MAXON_ENUM_LIST(PVFRAME_FINISH);

struct FinalizeTmpData
{
	PVFRAME_FINISH				mode;
	Int32									realdepth;
	Bool									dithering;
	const BaseContainer*	rdata;
	COLORMODE							colormode;

	FinalizeTmpData() : mode(PVFRAME_FINISH::KEEP_NODE_AND_COPYBMP), realdepth(0), dithering(false), rdata(nullptr), colormode(COLORMODE::ILLEGAL) { }
};

typedef Bool PVFinalizeImage(BaseBitmap *bmp, void *userdata);

class PictureViewer
{
	private:
		PictureViewer();
		~PictureViewer();
	public:
		Bool Open(void);

		Bool ShowFile(const Filename &File);
		Bool ShowImage(BaseBitmap *Bmp, const String &Name);
		GeListNode* OpenRendering(const String &Name, Float Fps, Int32 lStart, Int32 lEnd, BaseContainer* bcrender);
		Bool AddSound(GeListNode *pNode, const BaseTime &from, const BaseTime &to, BaseSound *snd);
		// private required for the renderer and the netrenderer
		Bool Message(Int32 id, void *t_data);

		Bool AddRenderingEx(GeListNode *pNode, BaseBitmap *Bmp, const String &Name, const BaseTime &Time, Int32 Frame,
			const Filename &savename, Bool fully_saved, Filename **filename_list, Int32 filename_count, Bool bAlwaysCopy, Int32 lStream, STEREOTYPE lStereoType);
		Bool CloseRenderingEx(GeListNode *&pNode, Int32 action, Bool bAlwaysCopy);

		GeListNode *BeginRendering(GeListNode *pNode, BaseBitmap *Bmp, const String &Name, const BaseTime &Time, Int32 Frame, const Filename &savename, Bool fully_saved, const Filename &dispname, Int32 lStream, STEREOTYPE lStereoType);
		Bool OverwriteBitmap(GeListNode *node, BaseBitmap* bmp, STEREOTYPE stereotype, Int32 lLastStream);
		Bool EndRendering(GeListNode *beginNode, PVFRAME_FINISH finish, Bool incomplete, PVFinalizeImage *callback, void *userdata);
		Bool CloseRendering(GeListNode *&pNode);

		void SetIsNet(GeListNode *pNode, Bool isNet);

		Bool CheckHDMemory();
};

PictureViewer* CreatePictureViewer(Int32 type);

//---------------------------------------------------
//	---INTERNAL STUFF

class iPictureViewer;

struct PictureViewLibrary : public C4DLibrary
{
	iPictureViewer*	(*CreatePictureViewer)(Int32 type);

	Bool					(iPictureViewer::*Open)								();

	Bool					(iPictureViewer::*ShowFile)						(const Filename &File);
	Bool					(iPictureViewer::*ShowImage)					(BaseBitmap *Bmp, const String &Name);
	GeListNode*		(iPictureViewer::*OpenRendering)			(const String &Name, Float Fps, Int32 lStart, Int32 lEnd, BaseContainer* bcrender);
	Bool					(iPictureViewer::*AddSound)						(GeListNode *pNode, const BaseTime &from, const BaseTime &to, BaseSound *snd);
	Bool					(iPictureViewer::*Message)						(Int32 id, void *t_data);

	Bool					(iPictureViewer::*CheckHDMemory)							();

	GeListNode*		(iPictureViewer::*BeginRendering)			(GeListNode *pNode, BaseBitmap *Bmp, const String &Name, const BaseTime &Time, Int32 Frame, const Filename &savename, Bool fully_saved, const Filename &dispname, Int32 lStream, STEREOTYPE lStereoType);
	Bool					(iPictureViewer::*EndRendering)				(GeListNode *pNode, PVFRAME_FINISH finish, Bool incomplete, PVFinalizeImage *callback, void *userdata);
	Bool					(iPictureViewer::*CloseRendering)		  (GeListNode *&pNode);

	Bool					(iPictureViewer::*OverwriteBitmap)		(GeListNode *node, BaseBitmap* bmp, STEREOTYPE stereotype, Int32 lLastStream);
	void					(iPictureViewer::*SetIsNet)						(GeListNode *pNode, Bool isNet);
};

#endif // LIB_PICTUREVIEWER_H__

