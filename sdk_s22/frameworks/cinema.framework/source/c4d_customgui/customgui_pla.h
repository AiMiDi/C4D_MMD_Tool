/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_PLA_H__
#define CUSTOMGUI_PLA_H__

#ifdef _INTERNAL_PLA_
	#define _INTERNAL_BASECUSTOM_
#endif

#include "customgui_base.h"
#include "c4d_customguidata.h"
#include "c4d_basecontainer.h"
#include "c4d_customdatatype.h"
#include "c4d_nodedata.h"
#include "lib_ca.h"

/// PLA custom data type ID.
#define CUSTOMDATATYPE_PLA		100004811

/// @markPrivate
#define CUSTOMDATATYPE_MT_TAG	100004838

//----------------------------------------------------------------------------------------
/// PLA custom data type (@ref CUSTOMDATATYPE_PLA) for PLA tracks.
//----------------------------------------------------------------------------------------
class PLAData : public CustomDataType
{
private:
	PLAData();
	~PLAData();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the data of a PLA key.
	/// @param[out] ptag							Assigned a PointTag containing the points of the PLA key, or @formatConstant{nullptr} in case of an error.\n
	/// 															The tag contains the same number of points as the object, though this should be always checked.
	/// @param[out] htag							Assigned a TangentTag with the Hermite tangents of each point, or @formatConstant{nullptr} in case of an error.\n
	/// 															The tag contains the same number of tangents as the object, though this should be always checked.
	//----------------------------------------------------------------------------------------
	void GetVariableTags(PointTag *&ptag, TangentTag *&htag);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class mttag_data : public NodeData
{
private:
	mttag_data();
	~mttag_data();

public:
	GeListHead* GetLayerHead(void);
};

class mtlayer_data : public NodeData
{
private:
	mtlayer_data();
	~mtlayer_data();

public:
	Bool IsAnimationLayer(void);
	GeListHead* GetAnimationHead(void);
	GeListHead* GetClipHead(void);

	void SetQuaternionInterpolation(Bool quatInterp, Bool bUndo);
	Bool IsQuaternionInterpolation();
};

class iPLAData;
class MT_TagData;
class MT_LayerData;

Bool AnimateNLA(BaseDocument *doc, BaseObject *op, const BaseTime &time, ANIMATEFLAGS flags);

struct PLALib : public BaseCustomGuiLib
{
	void				(iPLAData::*GetVariableTags )(PointTag *&ptag, TangentTag *&htag);
	GeListHead*	(*xGetLayerHead)(MT_TagData*);
	Bool				(*xIsAnimationLayer)(MT_LayerData*);
	GeListHead*	(*xGetAnimationHead)(MT_LayerData*);
	GeListHead*	(*xGetClipHead)(MT_LayerData*);

	Bool				(*xAnimateNLA)(BaseDocument *doc, BaseObject *op, const BaseTime &time, ANIMATEFLAGS flags);

	void				(*xSetQuaternionInterpolation)(MT_LayerData*, Bool quatInterp, Bool bUndo);
	Bool				(*xIsQuaternionInterpolation)(MT_LayerData*);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_PLA_H__
