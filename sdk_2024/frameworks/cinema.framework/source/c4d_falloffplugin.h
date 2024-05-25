/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FALLOFFPLUGIN_H__
#define C4D_FALLOFFPLUGIN_H__

#include "c4d_falloffdata.h"
#include "c4d_baseplugin.h"
#include "c4d_library.h"
#include "customgui_field.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct FALLOFFPLUGIN : public STATICPLUGIN
{
	FalloffDataAllocator* allocator;

	Bool									(FalloffData::* Init						 )(BaseContainer* bc);
	Bool									(FalloffData::* InitFalloff			 )(const BaseDocument* doc, const BaseContainer* bc, FalloffDataData& falldata) const;
	void									(FalloffData::* Sample					 )(const Vector& p, const FalloffDataData& data, Float* res) const;
	Bool									(FalloffData::* CheckDirty			 )(const BaseDocument* doc, const BaseContainer* bc);
	Bool									(FalloffData::* GetDVisible			 )(const DescID& id, const BaseContainer* bc, BaseContainer* desc_bc) const;
	Int32									(FalloffData::* GetHandleCount	 )(BaseContainer* bc, const FalloffDataData& data);
	void									(FalloffData::* SetHandle				 )(BaseContainer* bc, Int32 i, Vector p, const FalloffDataData& data);
	DRAWRESULT						(FalloffData::* Draw						 )(const FalloffDataData& data, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
	Bool									(FalloffData::* Message					 )(Int32 type, BaseContainer* bc, void* m_data);
	void									(FalloffData::* GetHandle				 )(BaseContainer* bc, Int32 i, HandleInfo& info, const FalloffDataData& data);
	maxon::Result<Bool>		(FalloffData::*GetAccessedObjects)(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const;

	void*									reserved[(32 - 11) * C4DPL_MEMBERMULTIPLIER - 1];
};

class iC4D_Falloff;

struct FalloffControlLib : public C4DLibrary
{
	BaseContainer*			(iC4D_Falloff::* GetContainerInstance		 )();
	void						(iC4D_Falloff::* SetDirty								 )();
	Int32						(iC4D_Falloff::* GetDirty								 )(BaseList2D* op, const BaseDocument* doc);
	void						(iC4D_Falloff::* SetMg									 )(const Matrix& mg);
	const Matrix&		(iC4D_Falloff::* GetMg									 )() const;
	Bool						(iC4D_Falloff::* SetMode								 )(Int32 type);
	Int32						(iC4D_Falloff::* GetMode								 )() const;
	void						(iC4D_Falloff::* SetTime								 )(BaseTime time);
	Bool						(iC4D_Falloff::* InitFalloff						 )(BaseDocument* doc, BaseObject* op);
	Bool						(iC4D_Falloff::* InitFalloff2						 )(const BaseDocument* doc, const BaseObject* op, FalloffDataData& data) const;
	Bool						(iC4D_Falloff::* Message								 )(BaseList2D* op, Int32 id, void* m_data);
	Int32						(iC4D_Falloff::* GetHandleCount					 )() const;
	DRAWRESULT			(iC4D_Falloff::* Draw										 )(BaseList2D* op, BaseDraw* bd, BaseDrawHelp* bh, DRAWPASS drawpass);
	Bool						(iC4D_Falloff::* CopyTo									 )(iC4D_Falloff* dest, BaseList2D* destObj) const;
	iC4D_Falloff*		(*Alloc                                  )(BaseContainer* parentBc, Int cType);
	void						(*Free                                   )(iC4D_Falloff*& node);
	void						(iC4D_Falloff::* GetHandle							 )(Int32 i, HandleInfo& info) const;
	void						(iC4D_Falloff::* SetHandle							 )(Int32 i, Vector p, const HandleInfo& info);
	Bool						(iC4D_Falloff::* AddFalloffToDescription )(const BaseList2D* op, Description* description, DESCFLAGS_DESC flags, Bool showValue, Bool showColor, Bool showDirection, Bool showRotation) const;
	Bool						(iC4D_Falloff::* GetDEnabling						 )(const DescID& id, Bool& enabled)  const;

	Bool						(iC4D_Falloff::* PreSample							 )(const BaseList2D* op, const BaseDocument* doc, const FieldInput& inputs, FieldOutput& result, const FalloffDataData& data, FIELDSAMPLE_FLAG flags) const;
	void						(iC4D_Falloff::* Sample									 )(const BaseList2D* op, const Vector& p, Float* result, const FieldOutput* fieldSamples, const FalloffDataData& data, Bool usespline, Float weight, Int index) const;
	void						(iC4D_Falloff::* MultiSample						 )(const BaseList2D* op, const Vector* p, Float* result, Int count, const FalloffDataData& data, Bool usespline, Float weight) const;

	Bool						(iC4D_Falloff::* HasContent							 )() const;
	Bool						(iC4D_Falloff::* IsFields								 )() const;

	FIELDLIST_FLAGS (iC4D_Falloff::*GetChannelFlags						)() const;
	void						(iC4D_Falloff::*SetChannelFlags						)(FIELDLIST_FLAGS flags);

	maxon::Result<Bool> (iC4D_Falloff::*GetAccessedObjects		)(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_FALLOFFPLUGIN_H__
