/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FALLOFFPLUGIN_H__
#define C4D_FALLOFFPLUGIN_H__

#ifdef __API_INTERN__
abc def xyz
#endif

#include "c4d_falloffdata.h"
#include "c4d_baseplugin.h"
#include "c4d_library.h"
#include "customgui_field.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct FALLOFFPLUGIN : public STATICPLUGIN
{
	FalloffDataAllocator* allocator;

	Bool									(FalloffData::* Init						 )(FalloffDataData& falldata, BaseContainer* bc);
	Bool									(FalloffData::* InitFalloff			 )(BaseContainer* bc, FalloffDataData& falldata);
	void									(FalloffData::* Sample					 )(const Vector& p, const FalloffDataData& data, Float* res);
	void									(FalloffData::* FreeFalloff			 )(FalloffDataData& falldata);
	Bool									(FalloffData::* CheckDirty			 )(BaseContainer* bc);
	Bool									(FalloffData::* GetDVisible			 )(DescID& id, BaseContainer* bc, BaseContainer* desc_bc);
	Int32									(FalloffData::* GetHandleCount	 )(BaseContainer* bc, const FalloffDataData& data);
	void									(FalloffData::* SetHandle				 )(BaseContainer* bc, Int32 i, Vector p, const FalloffDataData& data);
	DRAWRESULT						(FalloffData::* Draw						 )(const FalloffDataData& data, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
	Bool									(FalloffData::* Message					 )(Int32 type, BaseContainer* bc, void* m_data);
	void									(FalloffData::* GetHandle				 )(BaseContainer* bc, Int32 i, HandleInfo& info, const FalloffDataData& data);

	void*									reserved[(32 - 11) * C4DPL_MEMBERMULTIPLIER - 1];
};

class iC4D_Falloff;

struct FalloffControlLib : public C4DLibrary
{
	BaseContainer*			(iC4D_Falloff::* GetContainerInstance		 )();
	void						(iC4D_Falloff::* SetDirty								 )();
	Int32						(iC4D_Falloff::* GetDirty								 )(BaseDocument* doc, BaseContainer* bc);
	void						(iC4D_Falloff::* SetMg									 )(Matrix mg);
	Matrix					(iC4D_Falloff::* GetMg									 )();
	void						(iC4D_Falloff::* SetData								 )(FalloffDataData falldata);
	FalloffDataData	(iC4D_Falloff::* GetData								 )();
	Bool						(iC4D_Falloff::* SetMode								 )(Int32 type, BaseContainer* bc);
	Int32						(iC4D_Falloff::* GetMode								 )();
	void						(iC4D_Falloff::* SetTime								 )(BaseTime time, BaseContainer* bc);
	Bool						(iC4D_Falloff::* InitFalloff						 )(BaseContainer* bc, BaseDocument* doc, BaseObject* op);
	Bool						(iC4D_Falloff::* Message								 )(Int32 id, BaseContainer* bc, void* m_data);
	Int32						(iC4D_Falloff::* GetHandleCount					 )(BaseContainer* bc);
	DRAWRESULT			(iC4D_Falloff::* Draw										 )(BaseDraw* bd, BaseDrawHelp* bh, DRAWPASS drawpass, BaseContainer* bc);
	Bool						(iC4D_Falloff::* CopyTo									 )(iC4D_Falloff* dest);
	iC4D_Falloff*		(* Alloc)(Int cType);
	void						(* Free)(iC4D_Falloff*& node);
	void						(iC4D_Falloff::* GetHandle							 )(Int32 i, BaseContainer* bc, HandleInfo& info);
	void						(iC4D_Falloff::* SetHandle							 )(Int32 i, Vector p, BaseContainer* bc, const HandleInfo& info);
	Bool						(iC4D_Falloff::* AddFalloffToDescription )(Description* description, BaseContainer* bc, DESCFLAGS_DESC flags, Bool showValue, Bool showColor, Bool showDirection, Bool showRotation);
	Bool						(iC4D_Falloff::* GetDEnabling						 )(const DescID& id, const BaseContainer& bc, Bool& enabled);

	Bool						(iC4D_Falloff::* PreSample							 )(BaseDocument* doc, BaseList2D* op, const FieldInput& inputs, FIELDSAMPLE_FLAG flags);
	const FieldOutput*	(iC4D_Falloff::* GetSamples					 )();
	void						(iC4D_Falloff::* Sample									 )(const Vector& p, Float* result, Bool usespline, Float weight, BaseList2D* op, Int index);
	void						(iC4D_Falloff::* MultiSample						 )(const Vector* p, Float* result, Int count, Bool usespline, Float weight, BaseList2D* op);

	Bool						(iC4D_Falloff::* HasContent							 )(BaseContainer* bc) const;
	Bool						(iC4D_Falloff::* IsFields								 )() const;

	FIELDLIST_FLAGS (iC4D_Falloff::*GetChannelFlags						)() const;
	void						(iC4D_Falloff::*SetChannelFlags						)(FIELDLIST_FLAGS flags, BaseContainer* bc);

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_FALLOFFPLUGIN_H__
