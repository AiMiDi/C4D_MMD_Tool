#include "NameConversion.h"

namespace YAML {
	template<>
	struct convert<String> {
		static bool decode(const Node& node, String& rhs)
		{
			std::string str = node.as<std::string>();
			rhs.SetCString(str.c_str(), -1, STRINGENCODING::UTF8);
			return(true);
		}
	};
}

enum
{
	DLG_NAME_CONVER_NAMEMAP_NAME = 10000,
	DLG_NAME_CONVER_NAMEMAP,
	DLG_NAME_CONVER_NEW_DELETE,
	DLG_NAME_CONVER_IGNORE,
	DLG_NAME_CONVER_NEW_NAME,
	DLG_NAME_CONVER_NEW,
	DLG_NAME_CONVER_NEW_ADD,
	DLG_NAME_CONVER_NEW_INCREMENT_ADD,
	DLG_NAME_CONVER_OK,
	DLG_NAME_CONVER_CANCEL,
};

NameConversion::UpdataNameConversionDialog::UpdataNameConversionDialog(NameConversion* name_conversion_) : name_conversion(name_conversion_)
{
	name_conversion = name_conversion_;
	AutoAlloc<BrowseFiles> bf;
	bf->Init(GeGetPluginResourcePath() + Filename("Name_conversion"), BROWSEFILES_CALCSIZE);
	while (bf->GetNext())
	{
		if (!bf->IsDir())
		{
			iferr(NameMapArray.Append(bf->GetFilename())) continue;
		}
	}
	DefaultNameMap = NameMapArray.FindIndex("Name_conversion.yaml"_s);
	DefaultNameMap == -1 ? 0 : DefaultNameMap;
	name_conversion->LoadConfig(GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[DefaultNameMap]);
}


Bool NameConversion::UpdataNameConversionDialog::CreateLayout()
{
	SetTitle(GeLoadString(IDS_UPDATA_NAME_CONVERSION_TITLE));
	Images = new ImagesGUI("mmd_tool_title.png"_s, 300, 78);
	C4DGadget* userAreaGadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(78));
	if (userAreaGadget != nullptr)
		this->AttachUserArea((*Images), userAreaGadget);

	/* tab */
	ScrollGroupBegin(1000, BFH_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 0, 300);
	GroupBegin(1001, BFH_CENTER, 1, 1, ""_s, 0, 0, 300);
	unregulated_array.Reset();
	for (String i : name_conversion->updata_name_conversion_arr)
	{
		auto i_ptr = name_conversion->name_L_to_U_map.Find(i);
		if (i_ptr == nullptr && !i.IsEmpty())
		{
			iferr(unregulated_array.Append(i)) return(false);
		}
	}
	const Int conversion_count = unregulated_array.GetCount();
	for (Int i = 0; i < conversion_count; i++)
	{
		GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
		AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
		AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
		GroupEnd();
	}
	for (Int i = 0; i < conversion_count; i++)
	{
		SetString(100000 + i, unregulated_array[i], 0);
		SetString(100000 + i + conversion_count, ""_s, 0);
	}

	GroupEnd();
	GroupEnd();

	GroupBegin(1002, BFH_LEFT, 4, 1, ""_s, 0, 0, 10);
	AddStaticText(DLG_NAME_CONVER_NAMEMAP_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_NAME_CONVER_NAMEMAP_NAME), BORDER_NONE);
	AddComboButton(DLG_NAME_CONVER_NAMEMAP, BFH_LEFT, 483, 10);
	AddButton(DLG_NAME_CONVER_NEW_DELETE, BFH_CENTER, 100, 10, GeLoadString(IDS_NAME_CONVER_NEW_DELETE));
	AddCheckbox(DLG_NAME_CONVER_IGNORE, BFH_LEFT, 100, 10, GeLoadString(IDS_NAME_CONVER_IGNORE));
	GroupEnd();
	Int32 fnCount = 0;
	for (Filename fn : NameMapArray)
	{
		AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, fn.GetFileString());
		fnCount++;
	}

	GroupBegin(1003, BFH_CENTER, 4, 1, ""_s, 0, 0, 10);
	AddStaticText(DLG_NAME_CONVER_NEW_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_NAME_CONVER_NEW_NAME), BORDER_NONE);
	AddEditText(DLG_NAME_CONVER_NEW, BFH_LEFT, 500, 10, 0);
	AddButton(DLG_NAME_CONVER_NEW_ADD, BFH_CENTER, 100, 10, GeLoadString(IDS_NAME_CONVER_NEW_ADD));
	AddButton(DLG_NAME_CONVER_NEW_INCREMENT_ADD, BFH_CENTER, 100, 10, GeLoadString(IDS_NAME_CONVER_NEW_INCREMENT_ADD));
	GroupEnd();

	GroupBegin(1004, BFH_CENTER, 2, 1, ""_s, 0, 0, 30);
	GroupSpace(10, 0);
	AddButton(DLG_NAME_CONVER_OK, BFH_CENTER, 400, 30, GeLoadString(IDS_NAME_CONVER_OK));
	AddButton(DLG_NAME_CONVER_CANCEL, BFH_CENTER, 400, 30, GeLoadString(IDS_NAME_CONVER_CANCEL));
	GroupEnd();
	return(true);
}


Bool NameConversion::UpdataNameConversionDialog::InitValues()
{
	SetInt32(DLG_NAME_CONVER_NAMEMAP, DefaultNameMap);
	SetString(DLG_NAME_CONVER_NEW, "New"_s);
	SetBool(DLG_NAME_CONVER_IGNORE, true);
	return(true);
}


Bool NameConversion::UpdataNameConversionDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
	case  DLG_NAME_CONVER_OK:
	{
		maxon::HashMap<String, String>& name_L_to_U_map_ = name_conversion->name_L_to_U_map;
		maxon::HashMap<String, String>& name_U_to_L_map_ = name_conversion->name_U_to_L_map;
		Int32					fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		std::ofstream	fout((GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[fn_index]).GetString().GetCStringCopy(STRINGENCODING::UTF8), std::ios_base::app);
		const Int	conversion_count = unregulated_array.GetCount();
		YAML::Node	config;
		for (Int i = 0; i < conversion_count; i++)
		{
			String str1 = unregulated_array[i], str2;
			GetString(100000 + i + conversion_count, str2);
			if (str2 == ""_s)
			{
				iferr(name_L_to_U_map_.Insert(str1, "bone_" + String::IntToString(i))) return(false);
				iferr(name_U_to_L_map_.Insert("ボーン_" + String::IntToString(i), str1)) return(false);
			}
			else {
				iferr(name_L_to_U_map_.Insert(str1, str2)) return(false);
				iferr(name_U_to_L_map_.Insert(str2, str1)) return(false);
				config[std::string(str1.GetCStringCopy(STRINGENCODING::UTF8))] = std::string(str2.GetCStringCopy(STRINGENCODING::UTF8));
			}
		}
		fout << '\n' << config;
		fout.close();
		this->Close();
		break;
	}
	case DLG_NAME_CONVER_CANCEL:
	{
		this->Close();
		break;
	}
	case DLG_NAME_CONVER_NEW_DELETE:
	{
		Int32 fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		Filename fn = GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[fn_index];
		if (QuestionDialog(IDS_MES_CONFIRM_DELETE_FILE, fn.GetFileString()))
		{
			if (fn_index == DefaultNameMap)
			{
				MessageDialog(IDS_MES_CANNOT_DELETE_DEFAULT);
			}
			else {
				GeFKill(fn);
				NameMapArray.Reset();
				AutoAlloc<BrowseFiles> bf;
				bf->Init(GeGetPluginResourcePath() + Filename("Name_conversion"), BROWSEFILES_CALCSIZE);
				while (bf->GetNext())
				{
					if (!bf->IsDir())
					{
						iferr(NameMapArray.Append(bf->GetFilename())) continue;
					}
				}
				DefaultNameMap = NameMapArray.FindIndex("Name_conversion.yaml"_s);
				DefaultNameMap == -1 ? 0 : DefaultNameMap;
				FreeChildren(DLG_NAME_CONVER_NAMEMAP);
				Int32 fnCount = 0;
				for (Filename i_fn : NameMapArray)
				{
					AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
					fnCount++;
				}
				SetInt32(DLG_NAME_CONVER_NAMEMAP, DefaultNameMap);
				goto DLG_NAME_CONVER_NAMEMAP;
			}
		}
		break;
	}
	case DLG_NAME_CONVER_IGNORE:
	{
		Bool ignore = true;
		GetBool(DLG_NAME_CONVER_IGNORE, ignore);
		if (ignore)
		{
			Int32 fn_index = 0;
			GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
			name_conversion->LoadConfig(GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[fn_index]);
			unregulated_array.Reset();
			for (String i : name_conversion->updata_name_conversion_arr)
			{
				auto i_ptr = name_conversion->name_L_to_U_map.Find(i);
				if (i_ptr == nullptr && !i.IsEmpty())
				{
					iferr(unregulated_array.Append(i)) return(false);
				}
			}
			const Int conversion_count = unregulated_array.GetCount();
			LayoutFlushGroup(1001);
			for (Int i = 0; i < conversion_count; i++)
			{
				GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
				AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
				AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
				GroupEnd();
			}
			LayoutChanged(1001);
			for (Int i = 0; i < conversion_count; i++)
			{
				SetString(100000 + i, unregulated_array[i], 0);
				SetString(100000 + i + conversion_count, ""_s, 0);
			}
		}
		else {
			LayoutFlushGroup(1001);
			const Int conversion_count = name_conversion->updata_name_conversion_arr.GetCount();
			unregulated_array.Reset();
			iferr(unregulated_array.CopyFrom(name_conversion->updata_name_conversion_arr)) return(false);
			for (Int i = 0; i < conversion_count; i++)
			{
				GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
				AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
				AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
				GroupEnd();
			}
			LayoutChanged(1001);
			for (Int i = 0; i < conversion_count; i++)
			{
				String str1 = name_conversion->updata_name_conversion_arr[i];
				SetString(100000 + i, str1, 0);
				auto str2_ptr = name_conversion->name_L_to_U_map.Find(str1);
				if (str2_ptr == nullptr)
				{
					SetString(100000 + i + conversion_count, ""_s, 0);
				}
				else {
					SetString(100000 + i + conversion_count, str2_ptr->GetValue(), 0);
				}
			}
		}
		break;
	}
	case DLG_NAME_CONVER_NAMEMAP:
	{
	DLG_NAME_CONVER_NAMEMAP: {
		Int32 fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		name_conversion->LoadConfig(GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[fn_index]);
		unregulated_array.Reset();
		for (String i : name_conversion->updata_name_conversion_arr)
		{
			auto i_ptr = name_conversion->name_L_to_U_map.Find(i);
			if (i_ptr == nullptr)
			{
				iferr(unregulated_array.Append(i)) return(false);
			}
		}
		const Int conversion_count = unregulated_array.GetCount();
		LayoutFlushGroup(1001);
		for (Int i = 0; i < conversion_count; i++)
		{
			GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
			AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
			AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
			GroupEnd();
		}
		LayoutChanged(1001);
		for (Int i = 0; i < conversion_count; i++)
		{
			SetString(100000 + i, unregulated_array[i], 0);
			SetString(100000 + i + conversion_count, ""_s, 0);
		}
		}
	break;
	}
	case (DLG_NAME_CONVER_NEW_ADD):
	{
		String fn_s;
		GetString(DLG_NAME_CONVER_NEW, fn_s);
		Filename fn = GeGetPluginResourcePath() + Filename("Name_conversion\\") + Filename(fn_s + ".yaml");
		if (GeFExist(fn))
		{
			if (!QuestionDialog(IDS_MES_INQUIRY_OVERWRITING_FILE))
			{
				const Int32 add_fn_index = NameMapArray.FindIndex(fn_s + ".yaml");
				add_fn_index == -1 ? add_fn_index : DefaultNameMap;
				SetInt32(DLG_NAME_CONVER_NAMEMAP, add_fn_index);
				goto DLG_NAME_CONVER_NAMEMAP;
				break;
			}
		}
		AutoAlloc<BaseFile> file;
		if (!file->Open(fn, FILEOPEN::WRITE))
			return(false);
		file->Close();
		NameMapArray.Reset();
		AutoAlloc<BrowseFiles> bf;
		bf->Init(GeGetPluginResourcePath() + Filename("Name_conversion"), BROWSEFILES_CALCSIZE);
		while (bf->GetNext())
		{
			if (!bf->IsDir())
			{
				iferr(NameMapArray.Append(bf->GetFilename())) continue;
			}
		}
		DefaultNameMap = NameMapArray.FindIndex("Name_conversion.yaml"_s);
		DefaultNameMap == -1 ? 0 : DefaultNameMap;
		const Int32 add_fn_index = NameMapArray.FindIndex(fn_s + ".yaml");
		add_fn_index == -1 ? add_fn_index : DefaultNameMap;
		FreeChildren(DLG_NAME_CONVER_NAMEMAP);
		Int32 fnCount = 0;
		for (Filename i_fn : NameMapArray)
		{
			AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
			fnCount++;
		}
		SetInt32(DLG_NAME_CONVER_NAMEMAP, add_fn_index);
		goto DLG_NAME_CONVER_NAMEMAP;
		break;
	}
	case (DLG_NAME_CONVER_NEW_INCREMENT_ADD):
	{
		String fn_s;
		GetString(DLG_NAME_CONVER_NEW, fn_s);
		Filename fn = GeGetPluginResourcePath() + Filename("Name_conversion\\") + Filename(fn_s + ".yaml");
		if (GeFExist(fn))
		{
			if (!QuestionDialog(IDS_MES_INQUIRY_OVERWRITING_FILE))
			{
				const Int32 increment_fn_index = NameMapArray.FindIndex(fn_s + ".yaml");
				increment_fn_index == -1 ? increment_fn_index : DefaultNameMap;
				SetInt32(DLG_NAME_CONVER_NAMEMAP, increment_fn_index);
				goto DLG_NAME_CONVER_NAMEMAP;
				break;
			}
		}
		Int32 fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		GeFCopyFile(GeGetPluginResourcePath() + Filename("Name_conversion\\") + NameMapArray[fn_index], fn, GE_FCOPY_OVERWRITE);
		NameMapArray.Reset();
		AutoAlloc<BrowseFiles> bf;
		bf->Init(GeGetPluginResourcePath() + Filename("Name_conversion"), BROWSEFILES_CALCSIZE);
		while (bf->GetNext())
		{
			if (!bf->IsDir())
			{
				iferr(NameMapArray.Append(bf->GetFilename())) continue;
			}
		}
		DefaultNameMap = NameMapArray.FindIndex("Name_conversion.yaml"_s);
		DefaultNameMap == -1 ? 0 : DefaultNameMap;
		const Int32 increment_fn_index = NameMapArray.FindIndex(fn_s + ".yaml");
		increment_fn_index == -1 ? increment_fn_index : DefaultNameMap;
		FreeChildren(DLG_NAME_CONVER_NAMEMAP);
		Int32 fnCount = 0;
		for (Filename i_fn : NameMapArray)
		{
			AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
			fnCount++;
		}
		SetInt32(DLG_NAME_CONVER_NAMEMAP, increment_fn_index);
		goto DLG_NAME_CONVER_NAMEMAP;
		break;
	}
	default:
		break;
	}
	return(true);
}


NameConversion::~NameConversion()
{
	name_L_to_U_map.Reset();
	name_U_to_L_map.Reset();
	updata_name_conversion_arr.Reset();
};

Bool NameConversion::LoadConfig(Filename fn)
{
	name_L_to_U_map.Reset();
	name_U_to_L_map.Reset();
	try {
		YAML::Node doc = YAML::LoadFile(fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
		for (YAML::const_iterator it = doc.begin(); it != doc.end(); ++it)
		{
			iferr(name_L_to_U_map.Insert(it->first.as<String>(), it->second.as<String>())) return(false);
			iferr(name_L_to_U_map.Insert(it->second.as<String>(), it->first.as<String>())) return(false);
		}
	}
	catch (YAML::BadFile) {
		GePrint("Failed to load the YAML file!"_s);
		std::ofstream fout(fn.GetString().GetCStringCopy(STRINGENCODING::UTF8));
	}
	return(true);
}


Bool NameConversion::InitConver(String& str, Bool op)
{
	if (op)
	{
		Bool Not_english = true;
		for (auto i : str)
		{
			Not_english = maxon::IsAlphanumeric(i);
			if (Not_english == false && i != '-' && i != '+' && i != '_' && i != ' ')
				break;
			else Not_english = true;
		}
		if (Not_english)
		{
			iferr(name_L_to_U_map.Insert(str, str)) return(false);
			iferr(name_U_to_L_map.Insert(str, str)) return(false);
		}
		iferr(updata_name_conversion_arr.Append(str)) return(false);
		return(true);
	}
	else {
		auto converted_ptr = name_U_to_L_map.Find(str);
		if (converted_ptr == nullptr)
		{
			return(false);
		}
	}
	return(true);
}


Bool NameConversion::Conver(String& str, String& res, Bool op)
{
	if (op)
	{
		auto converted_ptr = name_L_to_U_map.Find(str);
		if (converted_ptr == nullptr)
		{
			res = "bone_" + String::IntToString(updata_name_conversion_arr.FindIndex(str));
		}
		else {
			res = converted_ptr->GetValue();
		}
	}
	else {
		auto converted_ptr = name_U_to_L_map.Find(str);
		if (converted_ptr == nullptr)
		{
			res = "ボーン_" + String::IntToString(updata_name_conversion_arr.FindIndex(str));
		}
		else {
			res = converted_ptr->GetValue();
		}
	}
	return(true);
}


Bool NameConversion::CheckUpdata()
{
	UpdataNameConversionDialog dialog(this);
	dialog.Open(DLG_TYPE::MODAL, ID_MMD_TOOL, -1, -1, 0, 0, 1);
	return(true);
}


Bool NameConversion::AutoUpdata()
{
	const Int conversion_count = updata_name_conversion_arr.GetCount();
	for (Int i = 0; i < conversion_count; i++)
	{
		String str = updata_name_conversion_arr[i];
		iferr(name_L_to_U_map.Insert(str, "bone_" + String::IntToString(i))) return(false);
		iferr(name_U_to_L_map.Insert("ボーン_" + String::IntToString(i), str)) return(false);
	}
	return(true);
}