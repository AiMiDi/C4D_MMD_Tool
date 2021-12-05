/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VIEWPORT_H__
#define LIB_VIEWPORT_H__

#include "c4d_library.h"
#include "ge_math.h"
#include "c4d_string.h"

class BaseDocument;
class BaseDraw;
class C4DAtom;
class iViewportHUD;
class iViewportHighlight;
class ViewHUD;
class HUDGroupList;
class AtomArray;
class ViewportSelect;
class GeClipMap;

#define HIGHLIGHT_FLAG_REALTIME		(1 << 0)
#define HIGHLIGHT_FLAG_FREESELECT	(1 << 1)
#define HIGHLIGHT_FLAG_NOEDITSTATE	(1 << 2)
#define HIGHLIGHT_FLAG_FULLMESH		(1 << 3)
#define HIGHLIGHT_FLAG_CALLCURSOR	(1 << 4)
#define HIGHLIGHT_FLAG_HIDE			(1 << 5)
#define HIGHLIGHT_FLAG_SELECTIONS	(1 << 6)
#define HIGHLIGHT_FLAG_SNAPPING		(1 << 7)
#define HIGHLIGHT_FLAG_ACTIVEONLY	(1 << 8)
#define HIGHLIGHT_FLAG_FREE_SNAPPING		(1 << 9)
#define HIGHLIGHT_FLAG_ADDFLAGS		(1 << 31)

#define HUDCONTROL_TYPE_SLIDER		1
#define HUDCONTROL_TYPE_BUTTON		2
#define HUDCONTROL_TYPE_STATIC		3
#define HUDCONTROL_TYPE_CHECKBOX	4
#define HUDCONTROL_TYPE_EDITBOX		5
#define HUDCONTROL_TYPE_GROUP			6
#define HUDCONTROL_TYPE_INFO			7
#define HUDCONTROL_TYPE_COMBO			8
#define HUDCONTROL_TYPE_DATETIME	9
#define HUDCONTROL_TYPE_VECTOR2D	10
#define HUDCONTROL_TYPE_USER			-1

#define HUDCONTROL_FLAG_VERTICAL					(1 << 0)
#define HUDCONTROL_FLAG_ONECLICK					(1 << 1)
#define HUDCONTROL_FLAG_VISIBLE						(1 << 2)
#define HUDCONTROL_FLAG_DISABLE						(1 << 3)
#define HUDCONTROL_FLAG_SELECTED					(1 << 4)
#define HUDCONTROL_FLAG_ACTIVE						(1 << 5)
#define HUDCONTROL_FLAG_CLOSED						(1 << 6)
#define HUDCONTROL_FLAG_NOCLOSE						(1 << 7)
#define HUDCONTROL_FLAG_INTEGER						(1 << 8)
#define HUDCONTROL_FLAG_NODOC							(1 << 9)
#define HUDCONTROL_FLAG_MARKREMOVE				(1 << 10)
#define HUDCONTROL_FLAG_RELATIVE					(1 << 11)
#define HUDCONTROL_FLAG_TEXT							(1 << 12)
#define HUDCONTROL_FLAG_FOCUS							(1 << 13)
#define HUDCONTROL_FLAG_NOANIMATE					(1 << 14)
#define HUDCONTROL_FLAG_HASTRACK					(1 << 15)
#define HUDCONTROL_FLAG_ISKEY							(1 << 16)
#define HUDCONTROL_FLAG_CHECKED						(1 << 17)
#define HUDCONTROL_FLAG_REAL							(1 << 18)
#define HUDCONTROL_FLAG_GROUPSELECT				(1 << 19)
#define HUDCONTROL_FLAG_NOATTACH					(1 << 20)
#define HUDCONTROL_FLAG_EXDRAW						(1 << 21)
#define HUDCONTROL_FLAG_DRAGGING					(1 << 22)
#define HUDCONTROL_FLAG_HIDDEN						(1 << 23)
#define HUDCONTROL_FLAG_NOFRAME						(1 << 24)
#define HUDCONTROL_FLAG_USERPOS						(1 << 25)
#define HUDCONTROL_FLAG_COMMAND						(1 << 26)
#define HUDCONTROL_FLAG_USERSIZE					(1 << 27)
#define HUDCONTROL_FLAG_RENDER						(1 << 28)
#define HUDCONTROL_FLAG_ALLOWMOUSE				(1 << 29)
#define HUDCONTROL_FLAG_LOCKVIEW					(1 << 30)
#define HUDCONTROL_FLAG_ACTION						(1 << 31)
#define HUDCONTROL_FLAG_KEYVALUE_CHANGED	(1ULL << 32ULL)

#define HUDCONTROL_AMODE_OBJECTACTIVE			0
#define HUDCONTROL_AMODE_ALWAYS					1
#define HUDCONTROL_AMODE_PARENTACTIVE			2
#define HUDCONTROL_AMODE_ROOTHIERARCHYACTIVE	3
#define HUDCONTROL_AMODE_SAMEACTIVE				4

#define HUDCONTROL_AMODE_MASK							255
#define HUDCONTROL_AMODE_PARAMETER				(1 << 30)
#define HUDCONTROL_AMODE_PARAMETER_INV		(1 << 31)

#define HUDCONTROL_DFLAGS_OBJECTNAME	(1 << 0)
#define HUDCONTROL_DFLAGS_NAME			(1 << 1)
#define HUDCONTROL_DFLAGS_WIDGET		(1 << 2)
#define HUDCONTROL_DFLAGS_FRAME			(1 << 3)
#define HUDCONTROL_DFLAGS_KEY			(1 << 4)
#define HUDCONTROL_DFLAGS_ICON			(1 << 5)
#define HUDCONTROL_DFLAGS_USER_TEXTCOL		(1 << 6)
#define HUDCONTROL_DFLAGS_USER_BACKCOL		(1 << 7)
#define HUDCONTROL_DFLAGS_USER_SELECTCOL	(1 << 8)
#define HUDCONTROL_DFLAGS_AUTOFOLD			(1 << 9)

class ViewportHUDControl
{
private:

	ViewportHUDControl();
	~ViewportHUDControl();

public:

	void SetLabel(const String &label);
	String GetLabel();
	void RemoveFlag(Int32 flag);
	void SetFlag(Int32 flag);
	Int32 GetFlags();
	void SetFlags(Int32 flag);
	Int32 GetType();
	Float GetLeft();
	Float GetTop();
	String GetNameLabel();
	Int32 GetWidth();
	Int32 GetHeight();
	IconData *GetIconData();
	void SetActionID(Int32 id);
	void SetAction(const String &str);
	void SetTopLeft(Float left, Float top);
	void SetActiveMode(Int32 mode);
	void SetDisplayFlags(Int32 flags);
	Int32 GetDisplayFlags();
	void RemoveDisplayFlags(Int32 flags);
	void SetObjectPos(Int32 left, Int32 top);
	void SetUnits(Int32 units);
	void SetName(const String &name);
	String GetName();
	void SetControlID(Int32 id);
	Int32 GetControlID();
	Int32 GetControlCloneID();
	Int32 GetGroupID();
	void SetGroupID(Int32 id);
	void SetIconFile(BaseDocument *doc, const Filename &fname);
	Int32 GetActiveMode();
	Int32 GetActiveParamFlags();
	void SetActiveParamFlags(Int32 flags);
	void SetActiveParam(BaseDocument *doc, const String &param);
	String GetActiveParam();
};

enum class VIEWHUD_FLAG
{
	NOUPDATE = (1 << 20),	// private
	////////////////////////////////////////////////////////////
	NONE = 0
} MAXON_ENUM_FLAGS(VIEWHUD_FLAG);

class ViewportHUD
{
private:

	ViewportHUD();
	~ViewportHUD();

	ViewHUD *m_pHUD;
	HUDGroupList *m_pGroup;

public:

	static ViewportHUD *Alloc();
	static void Free(ViewportHUD *&p);

	ViewportHUDControl *AddDescID(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data);
	Bool BeginGroup();
	ViewportHUDControl *EndGroup();
	Bool SetElement(BaseDocument *doc, Int32 id, Bool state);
	Bool IsValidControl(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data);
	Bool DrawHUD(BaseDocument *doc, GeClipMap *clipmap, Int32 fps, BaseDraw *bd, Int32 flags);
	VIEWHUD_FLAG SetFlags(BaseDocument *doc, VIEWHUD_FLAG flags);
	VIEWHUD_FLAG GetFlags(BaseDocument *doc);
	void ValidateControls(BaseDocument *doc);
	void UpdateControls(BaseDocument *doc);
	void UpdateData(BaseDocument *doc, BaseList2D *bl);

	ViewportHUDControl *AddControl(Int32 type, BaseDocument *doc, BaseDraw *bd, BaseList2D *obj, const DescID &id, const BaseContainer &data, const GeData &t_data, Int32 datatype);
	ViewportHUDControl *FindControl(BaseDocument *doc, BaseDraw *bd, BaseList2D *bl, const DescID &id);
};

struct HighlightHitData
{
	Int32 m_HitEdge;
	Int32 m_HitPoint;
	Int32 m_HitPolygon;
	Float m_HitX;
	Float m_HitY;
	Vector m_HitPos;
	BaseObject *m_pHitObject;
	Matrix	m_HitMg;
	Matrix	m_HitInvMg;
	Float	m_EdgePos;

	HighlightHitData()
	{
		m_HitEdge = NOTOK;
		m_HitPoint = NOTOK;
		m_HitPolygon = NOTOK;
		m_HitX = 0;
		m_HitY = 0;
		m_pHitObject = nullptr;
		m_EdgePos = 0;
	}
};

class ViewportHighlight
{
private:

	ViewportHighlight();
	~ViewportHighlight();

public:

	static ViewportHighlight *Alloc();
	static void Free(ViewportHighlight *&p);

	Bool Update(BaseDocument *pDoc, BaseDraw *pDraw, Int32 x, Int32 y, Int32 max_radius = LIMIT<Int32>::MAX);
	Bool Draw(BaseDocument *pDoc, BaseDraw *pDraw);

	Bool Changed(BaseDocument *pDoc);
	void ResetChanged(BaseDocument *pDoc);

	Bool HasHit(BaseDocument *pDoc);
	void GetHit(BaseDocument *pDoc, HighlightHitData *hitdata);

	void SetMode(BaseDocument *pDoc, Int32 mode);
	void SetColor(BaseDocument *pDoc, Vector hcol);
	void SetFlags(BaseDocument *pDoc, Int32 flags);
	ViewportSelect *GetViewportSelect(BaseDocument *pDoc, BaseDraw *pDraw);
	AtomArray *GetObjects(BaseDocument *pDoc);
	Int32 GetFlags(BaseDocument *pDoc);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

//////////////////////////////////////////////////////////////////////////
#define LIBRARY_HUD	1016073
#define LIBRARY_HIGHLIGHT 1016132
#define LIBRARY_HUD_CONTROL	1022226

//////////////////////////////////////////////////////////////////////////

struct ViewportHUDControlLib : public C4DLibrary
{
	void (*SetLabel)(ViewportHUDControl *ctrl, const String &label);
	String (*GetLabel)(ViewportHUDControl *ctrl);
	void (*RemoveFlag)(ViewportHUDControl *ctrl, Int32 flag);
	void (*SetFlag)(ViewportHUDControl *ctrl, Int32 flag);
	Int32 (*GetFlags)(ViewportHUDControl *ctrl);
	void (*SetFlags)(ViewportHUDControl *ctrl, Int32 flag);
	Int32 (*GetType)(ViewportHUDControl *ctrl);
	Float (*GetLeft)(ViewportHUDControl *ctrl);
	Float (*GetTop)(ViewportHUDControl *ctrl);
	String (*GetNameLabel)(ViewportHUDControl *ctrl);
	Int32 (*GetWidth)(ViewportHUDControl *ctrl);
	Int32 (*GetHeight)(ViewportHUDControl *ctrl);
	IconData *(*GetIconData)(ViewportHUDControl *ctrl);
	void (*SetActionID)(ViewportHUDControl *ctrl, Int32 id);
	void (*SetAction)(ViewportHUDControl *ctrl, const String &str);
	void (*SetTopLeft)(ViewportHUDControl *ctrl, Float left, Float top);
	void (*SetActiveMode)(ViewportHUDControl *ctrl, Int32 mode);
	void (*SetDisplayFlags)(ViewportHUDControl *ctrl, Int32 flags);
	Int32 (*GetDisplayFlags)(ViewportHUDControl *ctrl);
	void (*RemoveDisplayFlags)(ViewportHUDControl *ctrl, Int32 flags);
	void (*SetObjectPos)(ViewportHUDControl *ctrl, Int32 left, Int32 top);
	void (*SetUnits)(ViewportHUDControl *ctrl, Int32 units);
	void (*SetName)(ViewportHUDControl *ctrl, const String &name);
	String (*GetName)(ViewportHUDControl *ctrl);
	void (*SetControlID)(ViewportHUDControl *ctrl, Int32 id);
	Int32 (*GetControlID)(ViewportHUDControl *ctrl);
	Int32 (*GetControlCloneID)(ViewportHUDControl *ctrl);
	Int32 (*GetGroupID)(ViewportHUDControl *ctrl);
	void (*SetGroupID)(ViewportHUDControl *ctrl, Int32 id);
	void (*SetIconFile)(ViewportHUDControl *ctrl, BaseDocument *doc, const Filename &fname);
	Int32 (*GetActiveMode)(ViewportHUDControl *ctrl);
	Int32 (*GetActiveParamFlags)(ViewportHUDControl *ctrl);
	void (*SetActiveParamFlags)(ViewportHUDControl *ctrl, Int32 flags);
	void (*SetActiveParam)(ViewportHUDControl *ctrl, BaseDocument *doc, const String &param);
	String (*GetActiveParam)(ViewportHUDControl *ctrl);
};

struct ViewportHUDLib : public C4DLibrary
{
	iViewportHUD *(*Alloc)();
	void (*Free)(iViewportHUD *&p);

	ViewportHUDControl *(iViewportHUD::*AddDescID)(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data);
	Bool (iViewportHUD::*BeginGroup)();
	ViewportHUDControl *(iViewportHUD::*EndGroup)();
	Bool (iViewportHUD::*SetElement)(BaseDocument *doc, Int32 id, Bool state);
	Bool (iViewportHUD::*IsValidControl)(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data);
	Bool (iViewportHUD::*DrawHUD)(BaseDocument *doc, GeClipMap *clipmap, Int32 fps, BaseDraw *bd, Int32 flags);
	ViewportHUDControl *(iViewportHUD::*AddControl)(Int32 type, BaseDocument *doc, BaseDraw *bd, BaseList2D *obj, const DescID &id, const BaseContainer &data, const GeData &t_data, Int32 datatype);
	VIEWHUD_FLAG (iViewportHUD::*SetFlags)(BaseDocument *doc, VIEWHUD_FLAG flags);
	VIEWHUD_FLAG (iViewportHUD::*GetFlags)(BaseDocument *doc);
	void (iViewportHUD::*ValidateControls)(BaseDocument *doc);
	void (iViewportHUD::*UpdateControls)(BaseDocument *doc);
	void (iViewportHUD::*UpdateData)(BaseDocument *doc, BaseList2D *bl);
	ViewportHUDControl *(iViewportHUD::*FindControl)(BaseDocument *doc, BaseDraw *bd, BaseList2D *bl, const DescID &id);
};

struct ViewportHighlightLib : public C4DLibrary
{
	iViewportHighlight *(*Alloc)();
	void (*Free)(iViewportHighlight *&p);

	Bool (iViewportHighlight::*UpdateEx)(BaseDocument *pDoc, BaseDraw *pDraw, Int32 x, Int32 y);
	Bool (iViewportHighlight::*Draw)(BaseDocument *pDoc, BaseDraw *pDraw);
	Bool (iViewportHighlight::*Changed)(BaseDocument *pDoc);
	void (iViewportHighlight::*ResetChanged)(BaseDocument *pDoc);
	Bool (iViewportHighlight::*HasHit)(BaseDocument *pDoc);
	void (iViewportHighlight::*GetHit)(BaseDocument *pDoc, HighlightHitData *hitdata);
	void (iViewportHighlight::*SetMode)(BaseDocument *pDoc, Int32 mode);
	void (iViewportHighlight::*SetColor)(BaseDocument *pDoc, Vector hcol);
	void (iViewportHighlight::*SetFlags)(BaseDocument *pDoc, Int32 flags);
	ViewportSelect *(iViewportHighlight::*GetViewportSelect)(BaseDocument *pDoc, BaseDraw *pDraw);
	AtomArray *(iViewportHighlight::*GetObjects)(BaseDocument *pDoc);
	Int32 (iViewportHighlight::*GetFlags)(BaseDocument *pDoc);
	Bool (iViewportHighlight::*Update)(BaseDocument *pDoc, BaseDraw *pDraw, Int32 x, Int32 y, Int32 maxradius);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#endif // LIB_VIEWPORT_H__
