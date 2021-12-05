/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CUSTOMDATATYPEPLUGIN_H__
#define C4D_CUSTOMDATATYPEPLUGIN_H__

#include "ge_math.h"
#include "c4d_customdatatype.h"
#include "c4d_baseplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct CUSTOMDATATYPEPLUGIN : public STATICPLUGIN
{
	Int32							disclevel;

	CustomDataType*		(CustomDataTypeClass::*AllocData						)();
	void							(CustomDataTypeClass::*FreeData							)(CustomDataType* data);

	Bool							(CustomDataTypeClass::*CopyData							)(const CustomDataType* src, CustomDataType* dest, AliasTrans *aliastrans);
	Int32							(CustomDataTypeClass::*Compare							)(const CustomDataType* d1, const CustomDataType* d2);

	Bool							(CustomDataTypeClass::*WriteData						)(const CustomDataType *d, HyperFile *hf);
	Bool							(CustomDataTypeClass::*ReadData							)(CustomDataType *d, HyperFile *hf, Int32 level);

	const Char*				(CustomDataTypeClass::*GetResourceSym				)();

	CustomProperty*		(CustomDataTypeClass::*GetProperties				)();
	void							(CustomDataTypeClass::*GetDefaultProperties	)(BaseContainer &data);

	Int32							(CustomDataTypeClass::*GetConversionsFrom		)(Int32 *&table);
	GvError 					(CustomDataTypeClass::*ConvertFromGv				)(Int32 type, const void *const src, Int32 cpu_id, CustomDataType *dst);

	Int32							(CustomDataTypeClass::*GetConversionsTo			)(Int32 *&table);
	GvError 					(CustomDataTypeClass::*ConvertToGv					)(Int32 type, const CustomDataType *src, void *dst, Int32 cpu_id);
	GvError						(CustomDataTypeClass::*ConvertToGeData			)(Int32 type, const CustomDataType *src, GeData &dst);

	GvValueFlags			(CustomDataTypeClass::*GetCalculationFlags	)();
	GvError 					(CustomDataTypeClass::*Calculate						)(Int32 calculation, const CustomDataType *src1, const CustomDataType *src2, CustomDataType *dst, Float parm1);

	GV_VALUE_HANDLER*	(CustomDataTypeClass::*GetGvValueHandler		)();

	Bool							(CustomDataTypeClass::*ConvertGeDataToGv		)(const GeData &src, void *dst, Int32 cpu_id);
	Bool							(CustomDataTypeClass::*ConvertGvToGeData		)(const void *const src, Int32 cpu_id, GeData &dst);

	Int32							(CustomDataTypeClass::*GetValueID						)();
	Int32							(CustomDataTypeClass::*GetDataID						)();

	Bool							(CustomDataTypeClass::*_GetDescription			)(const CustomDataType *data, Description &res, DESCFLAGS_DESC &flags, const BaseContainer &parentdescription, DescID *singledescid);
	Bool							(CustomDataTypeClass::*GetParameter					)(const CustomDataType *data, const DescID &id, GeData &t_data, DESCFLAGS_GET &flags);
	Bool							(CustomDataTypeClass::*SetDParameter				)(CustomDataType *data, const DescID &id, const GeData &t_data, DESCFLAGS_SET &flags);
	Bool							(CustomDataTypeClass::*GetEnabling					)(const CustomDataType *data, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE &flags, const BaseContainer *itemdesc);
	void							(CustomDataTypeClass::*CheckData						)(const BaseContainer &bc, GeData &data);

	Bool							(CustomDataTypeClass::*InterpolateKeys			)(GeData &res, const GeData &t_data1, const GeData &t_data2, Float mix, Int32 flags);

	void* reserved[(64-27)*C4DPL_MEMBERMULTIPLIER-1];
};

struct RESOURCEDATATYPEPLUGIN : public STATICPLUGIN
{
	Int32									disclevel;

	const Char*						(ResourceDataTypeClass::*GetResourceSym					)();
	CustomProperty*				(ResourceDataTypeClass::*GetProperties					)();
	void									(ResourceDataTypeClass::*GetDefaultProperties		)(BaseContainer &data);
	CUSTOMDATATYPEPLUGIN* (ResourceDataTypeClass::*GetCustomDataTypePlugin)();
	Bool									(ResourceDataTypeClass::*GetDescription					)(const CustomDataType *data, Description &res, DESCFLAGS_DESC &flags, const BaseContainer &parentdescription, DescID *singledescid);
	void									(ResourceDataTypeClass::*CheckData							)(const BaseContainer &bc, GeData &data);

	void* reserved[(32-6)*C4DPL_MEMBERMULTIPLIER-1];
};

#define CallCustomDataTypePlugin(plug, fnc)		(((CustomDataTypeClass*)(((CUSTOMDATATYPEPLUGIN*)plug->GetPluginStructure())->adr))->*((CUSTOMDATATYPEPLUGIN*)plug->GetPluginStructure())->fnc)
#define CallResourceDataTypePlugin(plug, fnc)	(((ResourceDataTypeClass*)(((RESOURCEDATATYPEPLUGIN*)plug->GetPluginStructure())->adr))->*((RESOURCEDATATYPEPLUGIN*)plug->GetPluginStructure())->fnc)

#define CallCustomDataType(plug, fnc)		(((CustomDataTypeClass*)(plug->adr))->*plug->fnc)
#define CallResourceDataType(plug, fnc)	(((ResourceDataTypeClass*)(plug->adr))->*plug->fnc)

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

//----------------------------------------------------------------------------------------
/// Finds registered data type plugin structures from data type ID.
/// @param[in] type								The data type ID.
/// @return												The found plugin structure, or @formatConstant{nullptr}. @cinemaOwnsPointed{plugin structure}
//----------------------------------------------------------------------------------------
CUSTOMDATATYPEPLUGIN *FindCustomDataTypePlugin(Int32 type);

//----------------------------------------------------------------------------------------
/// Finds registered resource data type plugin structures from data type ID.
/// @param[in] type								The resource data type ID.
/// @return												The found plugin structure, or @formatConstant{nullptr}. @cinemaOwnsPointed{plugin structure}
//----------------------------------------------------------------------------------------
RESOURCEDATATYPEPLUGIN *FindResourceDataTypePlugin(Int32 type);

//----------------------------------------------------------------------------------------
/// Retrieves the data type ID from a resource data type ID.
/// @param[in] resourcetype				The resource data type ID.
/// @return												The data type ID.
//----------------------------------------------------------------------------------------
Int32 GetDataType(Int32 resourcetype);

//----------------------------------------------------------------------------------------
/// Retrieves the default settings for a data type.
/// @param[in] type								The data type ID.
/// @return												The default settings container.
//----------------------------------------------------------------------------------------
BaseContainer GetCustomDataTypeDefault(Int32 type);

#endif // C4D_CUSTOMDATATYPEPLUGIN_H__
