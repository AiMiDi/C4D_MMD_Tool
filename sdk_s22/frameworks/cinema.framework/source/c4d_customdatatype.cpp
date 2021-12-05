#include "operatingsystem.h"
#include "c4d_graphview.h"
#ifndef __API_INTERN__
	#include "c4d_general.h"
#else
	#include "ge_registry.h"
#endif

CUSTOMDATATYPEPLUGIN* FindCustomDataTypePlugin(Int32 type)
{
	return C4DOS.Ge->FindCustomDataTypePlugin(type);
}

RESOURCEDATATYPEPLUGIN* FindResourceDataTypePlugin(Int32 type)
{
	return C4DOS.Ge->FindResourceDataTypePlugin(type);
}

BaseContainer GetCustomDataTypeDefault(Int32 type)
{
	BaseContainer bc(type);
	RESOURCEDATATYPEPLUGIN* plug = FindResourceDataTypePlugin(type);
	if (plug)
		CallResourceDataType(plug, GetDefaultProperties) (bc);
	return bc;
}

Int32 GetDataType(Int32 resourcetype)
{
	if (!resourcetype)
		return 0;

	RESOURCEDATATYPEPLUGIN* r = FindResourceDataTypePlugin(resourcetype);
	if (!r)
	{
		return 0;
	}
	CUSTOMDATATYPEPLUGIN* c = CallResourceDataType(r, GetCustomDataTypePlugin) ();
	if (!c)
	{
		CriticalStop();
		return 0;
	}
	return CallCustomDataType(c, GetDataID) ();
}

CustomProperty* CustomDataTypeClass::GetProperties()
{
	return nullptr;
}

Int32 CustomDataTypeClass::GetDataID()
{
	return GetId();
}

Int32 CustomDataTypeClass::GetValueID()
{
	return GetId();
}

void CustomDataTypeClass::GetDefaultProperties(BaseContainer& data)
{
}

Int32 CustomDataTypeClass::GetConversionsFrom(Int32*& table)
{
	defaultconversiontype = GetValueID();
	table = &defaultconversiontype;
	return 1;
}

Int32 CustomDataTypeClass::GetConversionsTo(Int32*& table)
{
	defaultconversiontype = GetValueID();
	table = &defaultconversiontype;
	return 1;
}

GvError CustomDataTypeClass::ConvertFromGv(Int32 type, const void* const src, Int32 cpu_id, CustomDataType* dst)
{
	return GV_CALC_ERR_UNDEFINED;
}

GvError CustomDataTypeClass::ConvertToGv(Int32 type, const CustomDataType* src, void* dst, Int32 cpu_id)
{
	return GV_CALC_ERR_UNDEFINED;
}

GvValueFlags CustomDataTypeClass::GetCalculationFlags()
{
	return GV_CALC_NOP;
}

GvError CustomDataTypeClass::Calculate(Int32 calculation, const CustomDataType* src1, const CustomDataType* src2, CustomDataType* dst, Float parm1)
{
	return GV_CALC_ERR_UNDEFINED;
}

struct Helper
{
	CustomDataType** data;
};

Bool CustomDataTypeClass::ConvertGeDataToGv(const GeData& src, void* t_dst, Int32 cpu_id)
{
	Helper* dst = (Helper*)t_dst;
	if (!dst || !dst->data || !dst->data[cpu_id])
		return false;
	const CustomDataType* s = src.GetCustomDataType(GetValueID());
	if (!CopyData(s, dst->data[cpu_id], nullptr))
		return false;
	return true;
}

Bool CustomDataTypeClass::ConvertGvToGeData(const void* const t_src, Int32 cpu_id, GeData& dst)
{
	Helper* src = (Helper*)t_src;
	if (!src || !src->data || !src->data[cpu_id])
		return false;
	dst = GeData(GetValueID(), *src->data[cpu_id]);

	return true;
}

GV_VALUE_HANDLER* CustomDataTypeClass::GetGvValueHandler()
{
	if (valuehandler == (GV_VALUE_HANDLER*)-1)
		return nullptr;
	if (valuehandler)
		return valuehandler;

	GV_VALUE_HANDLER* val;

	Registry* reg = nullptr;
	for (reg = GeRegistryGetFirst(REGISTRYTYPE::GV_VALUE); reg; reg = reg->GetNext())
	{
		val = (GV_VALUE_HANDLER*)reg->GetData();
		if (val->value_id == GetValueID())
		{
			valuehandler = val;
			return val;
		}
	}
	CriticalStop();

	valuehandler = (GV_VALUE_HANDLER*)-1;
	return nullptr;
}

GvError CustomDataTypeClass::ConvertToGeData(Int32 dst_type, const CustomDataType* src, GeData& dst)
{
	if (dst_type != GetId() || !src)
		return GV_CALC_ERR_UNDEFINED;

	dst = GeData(dst_type, *src);
	if (dst.GetType() != DA_NIL)
		return (GvError)0;
	return GV_CALC_ERR_UNDEFINED;
}

Bool CustomDataTypeClass::_GetDescription(const CustomDataType* data, Description& res, DESCFLAGS_DESC& flags, const BaseContainer& parentdescription, DescID* singledescid)
{
	return (flags & DESCFLAGS_DESC::LOADED) != DESCFLAGS_DESC::NONE;
}

Bool CustomDataTypeClass::GetParameter(const CustomDataType* data, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags)
{
	return (flags & DESCFLAGS_GET::PARAM_GET) != DESCFLAGS_GET::NONE;
}

Bool CustomDataTypeClass::SetDParameter(CustomDataType* data, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	return (flags & DESCFLAGS_SET::PARAM_SET) != DESCFLAGS_SET::NONE;
}

Bool CustomDataTypeClass::GetEnabling(const CustomDataType* data, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE& flags, const BaseContainer* itemdesc)
{
	return true;
}

Bool CustomDataTypeClass::InterpolateKeys(GeData& res, const GeData& t_data1, const GeData& t_data2, Float mix, Int32 flags)
{
	return false;
}

void CustomDataTypeClass::CheckData(const BaseContainer& bc, GeData& data)
{
}

Bool RegisterCustomDataTypePlugin(const maxon::String& str, Int32 info, CustomDataTypeClass* dat, Int32 disclevel)
{
	if (!dat)
		return false;

	Int32 id = dat->GetId();

	CUSTOMDATATYPEPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.info	= info;
	np.Destructor	= &BaseData::Destructor;

	np.disclevel = disclevel;
	np.AllocData = &CustomDataTypeClass::AllocData;
	np.FreeData	 = &CustomDataTypeClass::FreeData;
	np.CopyData	 = &CustomDataTypeClass::CopyData;
	np.Compare = &CustomDataTypeClass::Compare;
	np.WriteData = &CustomDataTypeClass::WriteData;
	np.ReadData	 = &CustomDataTypeClass::ReadData;
	np.GetResourceSym	= &CustomDataTypeClass::GetResourceSym;
	np.GetProperties	= &CustomDataTypeClass::GetProperties;
	np.GetDefaultProperties = &CustomDataTypeClass::GetDefaultProperties;

	np.GetConversionsFrom	= &CustomDataTypeClass::GetConversionsFrom;
	np.ConvertFromGv = &CustomDataTypeClass::ConvertFromGv;

	np.GetConversionsTo	= &CustomDataTypeClass::GetConversionsTo;
	np.ConvertToGv = &CustomDataTypeClass::ConvertToGv;
	np.ConvertToGeData = &CustomDataTypeClass::ConvertToGeData;

	np.GetCalculationFlags = &CustomDataTypeClass::GetCalculationFlags;
	np.Calculate = &CustomDataTypeClass::Calculate;

	np.GetGvValueHandler = &CustomDataTypeClass::GetGvValueHandler;

	np.ConvertGeDataToGv = &CustomDataTypeClass::ConvertGeDataToGv;
	np.ConvertGvToGeData = &CustomDataTypeClass::ConvertGvToGeData;

	np.GetValueID	= &CustomDataTypeClass::GetValueID;
	np.GetDataID	= &CustomDataTypeClass::GetDataID;

	np._GetDescription = &CustomDataTypeClass::_GetDescription;
	np.GetParameter	 = &CustomDataTypeClass::GetParameter;
	np.SetDParameter = &CustomDataTypeClass::SetDParameter;
	np.GetEnabling = &CustomDataTypeClass::GetEnabling;
	np.CheckData = &CustomDataTypeClass::CheckData;
	np.InterpolateKeys = &CustomDataTypeClass::InterpolateKeys;

	return GeRegisterPlugin(PLUGINTYPE::CUSTOMDATATYPE, id, str, &np, sizeof(np));
}



ResourceDataTypeClass::ResourceDataTypeClass(Int32 t_datatypeid, CUSTOMDATATYPEPLUGIN* t_datatype)
{
	datatypeid = t_datatypeid;
	datatype = t_datatype;
}

CustomProperty* ResourceDataTypeClass::GetProperties()
{
	return CallCustomDataType(datatype, GetProperties) ();
}

const Char* ResourceDataTypeClass::GetResourceSym()
{
	return CallCustomDataType(datatype, GetResourceSym) ();
}

void ResourceDataTypeClass::GetDefaultProperties(BaseContainer& data)
{
	CallCustomDataType(datatype, GetDefaultProperties) (data);
}

Int32 ResourceDataTypeClass::GetCustomDataType()
{
	return datatypeid;
}

CUSTOMDATATYPEPLUGIN* ResourceDataTypeClass::GetCustomDataTypePlugin()
{
	return datatype;
}

Bool ResourceDataTypeClass::GetDescription(const CustomDataType* data, Description& res, DESCFLAGS_DESC& flags, const BaseContainer& parentdescription, DescID* singledescid)
{
	return CallCustomDataType(datatype, _GetDescription) (data, res, flags, parentdescription, singledescid);
}

void ResourceDataTypeClass::CheckData(const BaseContainer& bc, GeData& data)
{
	CallCustomDataType(datatype, CheckData) (bc, data);
}


Bool RegisterResourceDataTypePlugin(const maxon::String& str, Int32 info, ResourceDataTypeClass* dat, Int32 disclevel)
{
	if (!dat)
		return false;

	Int32 id = dat->GetId();

	RESOURCEDATATYPEPLUGIN np;
	ClearMem(&np, sizeof(np));

	np.adr	= dat;
	np.info	= info;
	np.Destructor	= &BaseData::Destructor;

	np.disclevel = disclevel;

	np.GetResourceSym	= &ResourceDataTypeClass::GetResourceSym;
	np.GetProperties	= &ResourceDataTypeClass::GetProperties;
	np.GetDefaultProperties	= &ResourceDataTypeClass::GetDefaultProperties;
	np.GetCustomDataTypePlugin = &ResourceDataTypeClass::GetCustomDataTypePlugin;
	np.GetDescription	= &ResourceDataTypeClass::GetDescription;
	np.CheckData = &ResourceDataTypeClass::CheckData;

	return GeRegisterPlugin(PLUGINTYPE::RESOURCEDATATYPE, id, str, &np, sizeof(np));
}
