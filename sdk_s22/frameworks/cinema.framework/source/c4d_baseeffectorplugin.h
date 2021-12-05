/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEEFFECTORPLUGIN_H__
#define C4D_BASEEFFECTORPLUGIN_H__

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_baseeffectordata.h"
#include "c4d_objectplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct EFFECTORPLUGIN : public OBJECTPLUGIN
{
	EffectorDataStruct*	(EffectorData::*GetEffectorData				)();
	C4D_Falloff*				(EffectorData::*GetFalloff						)();
	void								(EffectorData::*AddEffectorDependence	)(BaseObject* op);
	Int32								(EffectorData::*GetEffectorFlags			)();
	Bool								(EffectorData::*ModifyDDescription		)(GeListNode* node, Description* description, AtomArray* ar);
	Bool								(EffectorData::*ExecuteEffector				)(BaseObject* op, BaseDocument* doc, BaseObject* gen, MoData* md, Float strength, BaseThread* thread);
	void								(EffectorData::*InitPoints						)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, MoData* md, BaseThread* thread);
	void								(EffectorData::*ModifyPoints					)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, MoData* md, BaseThread* thread);
	void								(EffectorData::*FreePoints						)();
	void								(EffectorData::*CalcPlacebo						)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight);
	void								(EffectorData::*CalcPointValue				)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight);
	Vector							(EffectorData::*CalcPointColor				)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight);
	Bool								(EffectorData::*InitEffector					)(GeListNode* node);
	void								(EffectorData::*FreeEffector					)(GeListNode* node);

	void* reserved[(32 - 14) * C4DPL_MEMBERMULTIPLIER];
};

struct EffectorDataLib : public C4DLibrary
{
	Bool								(*Effector_Init									)(GeListNode* node);
	void								(*Effector_Free									)(GeListNode* node);
	Bool								(*Effector_GetDDescription			)(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
	Bool								(*Effector_Draw									)(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
	void								(*Effector_GetDimension					)(BaseObject* op, Vector* mp, Vector* rad);
	EXECUTIONRESULT			(*Effector_Execute							)(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
	Bool								(*Effector_ModifyObject					)(BaseObject* mod, BaseDocument* doc, BaseObject* op, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread);
	Bool								(*Effector_Message							)(GeListNode* node, Int32 type, void* t_data);
	Int32								(*Effector_GetHandleCount				)(BaseObject* op);

	EffectorDataStruct*	(*Effector_GetEffectorData			)(GeListNode* node);
	C4D_Falloff*				(*Effector_GetFalloff						)(GeListNode* node);
	void								(*Effector_AddEffectorDependence)(GeListNode* node, BaseObject* op);
	Bool								(*Effector_ExecuteEffector			)(BaseObject* op, BaseDocument* doc, BaseObject* gen, MoData* md, Float strength, BaseThread* thread);
	maxon::Result<void>	(*Effector_ModifyPoints					)(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, MoData* md, BaseThread* thread);
	Bool								(*Effector_CopyTo								)(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
	void								(*Effector_GetHandle						)(BaseObject* op, Int32 i, HandleInfo& info);
	void								(*Effector_SetHandle						)(BaseObject* op, Int32 i, Vector p, const HandleInfo& info);

	Bool								(*Effector_GetDEnabling					)(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc);

	FieldOutput*				(*Effector_GetFieldResult				)(GeListNode* node, BaseDocument* doc, BaseObject* generatorObject, MoData* md, FIELDSAMPLE_FLAG flags);
};

class iMoData;

struct MoDataLib : public C4DLibrary
{
	UInt32							(iMoData::*GetDirty							)(MDDIRTY mask) const;
	void								(iMoData::*SetDirty							)(MDDIRTY mask);
	Bool								(iMoData::*SetWithEx						)(const MoDataEx& md);
	void								(iMoData::*Clear								)(Bool reset);
	Bool								(iMoData::*Read									)(HyperFile* hf);
	Bool								(iMoData::*Write								)(HyperFile* hf);
	Int									(iMoData::*GetMemorySize				)();
	Bool								(iMoData::*SetCount							)(Int cnt);
	Int									(iMoData::*GetCount							)() const;
	Int32								(iMoData::*GetArrayCount				)();
	DescID							(iMoData::*GetArrayDescID				)(Int32 index) const;
	Int32								(iMoData::*GetArrayID						)(Int32 index) const;
	Int32								(iMoData::*GetArrayIndexType		)(Int32 index);
	Int32								(iMoData::*GetArrayType					)(Int32 id);
	Int									(iMoData::*GetArrayIndex1				)(const DescID& id);
	Int									(iMoData::*GetArrayIndex2				)(Int32 id);
	BaseContainer*			(iMoData::*GetDataInstance1			)(const DescID& id);
	BaseContainer*			(iMoData::*GetDataInstance2			)(Int32 id);
	BaseContainer*			(iMoData::*GetDataIndexInstance	)(Int32 id);
	BaseContainer				(iMoData::*GetData							)(Int32 id);
	void								(iMoData::*SetData							)(const BaseContainer& bc, Int32 id);
	AutoLock&						(iMoData::*GetAutoLock					)();
	Int32								(iMoData::*AddArray1						)(const DescID& id, const maxon::String& name, Int32 default_flags);
	Int32								(iMoData::*AddArray2						)(Int32 id, Int32 type, const maxon::String& name, Int32 default_flags);
	Bool								(iMoData::*RemoveArray1					)(const DescID& id);
	Bool								(iMoData::*RemoveArray2					)(Int32 id);
	Int32								(iMoData::*GetFlags1						)(const DescID& id);
	Int32								(iMoData::*GetFlags2						)(Int32 id);
	Int32								(iMoData::*GetIndexFlags				)(Int32 index);
	void								(iMoData::*SetFlags1						)(const DescID& id, Int32 flags);
	void								(iMoData::*SetFlags2						)(Int32 id, Int32 flags);
	void								(iMoData::*SetIndexFlags				)(Int32 index, Int32 flags);
	void								(iMoData::*SetFlag1							)(const DescID& id, Int32 flag);
	void								(iMoData::*SetFlag2							)(Int32 id, Int32 flag);
	void								(iMoData::*SetIndexFlag					)(Int32 index, Int32 flag);
	void								(iMoData::*DelFlag1							)(const DescID& id, Int32 flag);
	void								(iMoData::*DelFlag2							)(Int32 id, Int32 flag);
	void								(iMoData::*DelIndexFlag					)(Int32 index, Int32 flag);
	void								(iMoData::*SetName1							)(const DescID& id, const maxon::String& name);
	void								(iMoData::*SetName2							)(Int32 id, const maxon::String& name);
	void								(iMoData::*SetIndexName					)(Int32 index, const maxon::String& name);
	String							(iMoData::*GetName1							)(const DescID& id);
	String							(iMoData::*GetName2							)(Int32 id);
	String							(iMoData::*GetIndexName					)(Int32 index);

	void*								(iMoData::*GetArray1						)(const DescID& id) const;
	MDArray<Char>				(iMoData::*GetCharArray1				)(const DescID& id, Char default_value) const;
	MDArray<UChar>			(iMoData::*GetUCharArray1				)(const DescID& id, UChar default_value) const;
	MDArray<Int32>			(iMoData::*GetLongArray1				)(const DescID& id, Int32 default_value) const;
	MDArray<UInt32>			(iMoData::*GetULongArray1				)(const DescID& id, UInt32 default_value) const;
	MDArray<Bool>				(iMoData::*GetBoolArray1				)(const DescID& id, Bool default_value) const;
	MDArray<Int64>			(iMoData::*GetLLongArray1				)(const DescID& id, Int64 default_value) const;
	MDArray<Float>			(iMoData::*GetRealArray1				)(const DescID& id, Float default_value) const;
	MDArray<Matrix>			(iMoData::*GetMatrixArray1			)(const DescID& id, Matrix default_value) const;
	MDArray<Vector>			(iMoData::*GetVectorArray1			)(const DescID& id, Vector default_value) const;

	void*								(iMoData::*GetArray2						)(Int32 index, MD_TYPE type) const;
	MDArray<Char>				(iMoData::*GetCharArray2				)(Int32 id, Char default_value) const;
	MDArray<UChar>			(iMoData::*GetUCharArray2				)(Int32 id, UChar default_value) const;
	MDArray<Int32>			(iMoData::*GetLongArray2				)(Int32 id, Int32 default_value) const;
	MDArray<UInt32>			(iMoData::*GetULongArray2				)(Int32 id, UInt32 default_value) const;
	MDArray<Bool>				(iMoData::*GetBoolArray2				)(Int32 id, Bool default_value) const;
	MDArray<Int64>			(iMoData::*GetLLongArray2				)(Int32 id, Int64 default_value) const;
	MDArray<Float>			(iMoData::*GetRealArray2				)(Int32 id, Float default_value) const;
	MDArray<Matrix>			(iMoData::*GetMatrixArray2			)(Int32 id, Matrix default_value) const;
	MDArray<Vector>			(iMoData::*GetVectorArray2			)(Int32 id, Vector default_value) const;

	void*								(iMoData::*GetIndexArray				)(Int32 index) const;
	MDArray<Char>				(iMoData::*GetCharIndexArray		)(Int32 index) const;
	MDArray<UChar>			(iMoData::*GetUCharIndexArray		)(Int32 index) const;
	MDArray<Int32>			(iMoData::*GetLongIndexArray		)(Int32 index) const;
	MDArray<UInt32>			(iMoData::*GetULongIndexArray		)(Int32 index) const;
	MDArray<Bool>				(iMoData::*GetBoolIndexArray		)(Int32 index) const;
	MDArray<Int64>			(iMoData::*GetLLongIndexArray		)(Int32 index) const;
	MDArray<Float>			(iMoData::*GetRealIndexArray		)(Int32 index) const;
	MDArray<Matrix>			(iMoData::*GetMatrixIndexArray	)(Int32 index) const;
	MDArray<Vector>			(iMoData::*GetVectorIndexArray	)(Int32 index) const;

	Bool								(iMoData::*CopyTo								)(iMoData* dest, Bool merge_data, Int max_count);
	Bool								(iMoData::*MergeData						)(iMoData* source, Float percent);
	void								(iMoData::*Flush								)();
	void								(iMoData::*SetOffset						)(Int offset);
	void								(iMoData::*SetLimit							)(Int limit);

	iMoData*						(*Alloc)												();
	void								(*Free)													(iMoData*& d);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_BASEEFFECTORPLUGIN_H__
