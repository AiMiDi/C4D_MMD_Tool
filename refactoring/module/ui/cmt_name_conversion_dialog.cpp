#include "pch.h"
#include "cmt_name_conversion_dialog.h"
#include "c4d_symbols.h"

template<>
struct YAML::convert<String> {
	static bool decode(const Node& node, String& rhs)
	{
		const auto str = node.as<std::string>();
		rhs.SetCString(str.c_str(), -1, STRINGENCODING::UTF8);
		return true;
	}
};

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

UpdateNameConversionDialog::UpdateNameConversionDialog(NameConversion& name_conversion) : name_conversion_(name_conversion)
{
	AutoAlloc<BrowseFiles> bf;
	bf->Init(name_mapping_config_dirname_, BROWSEFILES_CALCSIZE);
	while (bf->GetNext())
	{
		if (auto filename = bf->GetFilename(); !bf->IsDir() && filename.CheckSuffix("yaml"_s))
		{
			iferr(name_mapping_config_.Append(std::move(filename))) continue;
		}
	}
	default_name_mapping_config_index_ = name_mapping_config_.FindIndex("default.yaml"_s);
	default_name_mapping_config_index_ = default_name_mapping_config_index_ == NOTOK ? 0 : default_name_mapping_config_index_;
	name_conversion_.LoadConfig(name_mapping_config_dirname_ + name_mapping_config_[default_name_mapping_config_index_]);
}

Bool UpdateNameConversionDialog::CreateLayout()
{
	SetTitle(GeLoadString(IDS_NAME_CONVER_UPDATA_TITLE));
	images_.Assign(new ImagesUserArea("mmd_tool_title.png"_s, 300, 78));
	if (C4DGadget* user_area_gadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(78)); user_area_gadget != nullptr)
		AttachUserArea(*images_, user_area_gadget);

	/* tab */
	ScrollGroupBegin(1000, BFH_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 0, 300);
	GroupBegin(1001, BFH_CENTER, 1, 1, ""_s, 0, 0, 300);
	unregulated_name_.Reset();
	for (String i : name_conversion_.updata_name_conversion_)
	{
		auto i_ptr = name_conversion_.local_to_universal_name_lookup_table_.Find(i);
		if (i_ptr == nullptr && !i.IsEmpty())
		{
			iferr(unregulated_name_.Append(i)) return false;
		}
	}
	const Int32 conversion_count = static_cast<Int32>(unregulated_name_.GetCount());
	for (Int32 i = 0; i < conversion_count; i++)
	{
		GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);

		AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
		SetString(100000 + i, unregulated_name_[i], 0);

		AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
		SetString(100000 + i + conversion_count, ""_s, 0);

		GroupEnd();
	}
	GroupEnd();
	GroupEnd();

	GroupBegin(1002, BFH_LEFT, 4, 1, ""_s, 0, 0, 10);
	AddStaticText(DLG_NAME_CONVER_NAMEMAP_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_NAME_CONVER_UPDATA_TITLE), BORDER_NONE);
	AddComboButton(DLG_NAME_CONVER_NAMEMAP, BFH_LEFT, 483, 10);
	AddButton(DLG_NAME_CONVER_NEW_DELETE, BFH_CENTER, 100, 10, GeLoadString(IDS_NAME_CONVER_NEW_DELETE));
	AddCheckbox(DLG_NAME_CONVER_IGNORE, BFH_LEFT, 100, 10, GeLoadString(IDS_NAME_CONVER_IGNORE));
	GroupEnd();
	Int32 fnCount = 0;
	for (Filename fn : name_mapping_config_)
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
	return true;
}


Bool UpdateNameConversionDialog::InitValues()
{
	SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(default_name_mapping_config_index_));
	SetString(DLG_NAME_CONVER_NEW, "New"_s);
	SetBool(DLG_NAME_CONVER_IGNORE, true);
	return true;
}


bool UpdateNameConversionDialog::LoadNameMappingConfig()
{
	Int32 config_index = 0;
	GetInt32(DLG_NAME_CONVER_NAMEMAP, config_index);
	name_conversion_.LoadConfig(name_mapping_config_dirname_ + name_mapping_config_[config_index]);
	unregulated_name_.Reset();
	for (const String& item : name_conversion_.updata_name_conversion_)
	{
		if (!name_conversion_.local_to_universal_name_lookup_table_.Contains(item))
		{
			iferr(unregulated_name_.Append(item))
				return false;
		}
	}
	const auto conversion_count = static_cast<Int32>(unregulated_name_.GetCount());
	LayoutFlushGroup(1001);
	for (Int32 item_index = 0; item_index < conversion_count; item_index++)
	{
		GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);

		AddEditText(100000 + item_index, BFH_LEFT, 400, 10, 0);
		SetString(100000 + item_index, unregulated_name_[item_index], 0);

		AddEditText(100000 + item_index + conversion_count, BFH_LEFT, 400, 10, 0);
		SetString(100000 + item_index + conversion_count, ""_s, 0);

		GroupEnd();
	}
	LayoutChanged(1001);
	return true;
}

Bool UpdateNameConversionDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
	case  DLG_NAME_CONVER_OK:
	{
		maxon::HashMap<String, String>& local_to_universal_name_lookup_table = name_conversion_.local_to_universal_name_lookup_table_;
		maxon::HashMap<String, String>& universal_to_local_name_lookup_table = name_conversion_.universal_to_local_name_lookup_table_;
		Int32 fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		std::ofstream file_out(string_util::GetStdString((name_mapping_config_dirname_ + name_mapping_config_[fn_index]).GetString()), std::ios_base::app);
		const Int32	conversion_count = static_cast<Int32>(unregulated_name_.GetCount());
		YAML::Node	config;
		for (Int32 i = 0; i < conversion_count; i++)
		{
			const String& key = unregulated_name_[i];
			String value;
			GetString(100000 + i + conversion_count, value);
			if (value.IsEmpty())
			{
				iferr(local_to_universal_name_lookup_table.Insert(key, FormatString("bone_@", i))) return false;
				iferr(universal_to_local_name_lookup_table.Insert(FormatString("ボーン_@", i), key)) return false;
			}
			else {
				iferr(local_to_universal_name_lookup_table.Insert(key, value)) return false;
				iferr(universal_to_local_name_lookup_table.Insert(value, key)) return false;
				config[string_util::GetStdString(key)] = string_util::GetStdString(value);
			}
		}
		file_out << '\n' << config;
		file_out.close();
		Close();
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
		if (Filename fn = name_mapping_config_dirname_ + name_mapping_config_[fn_index];
			QuestionDialog(IDS_MES_CONFIRM_DELETE_FILE, fn.GetFileString()))
		{
			if (fn_index == default_name_mapping_config_index_)
			{
				MessageDialog(IDS_MES_CANNOT_DELETE_DEFAULT);
			}
			else {
				GeFKill(fn);
				name_mapping_config_.Reset();
				AutoAlloc<BrowseFiles> bf;
				bf->Init(GeGetPluginResourcePath() + Filename("name_conversion"), BROWSEFILES_CALCSIZE);
				while (bf->GetNext())
				{
					if (!bf->IsDir())
					{
						iferr(name_mapping_config_.Append(bf->GetFilename())) continue;
					}
				}
				default_name_mapping_config_index_ = name_mapping_config_.FindIndex("default.yaml"_s);
				default_name_mapping_config_index_ = default_name_mapping_config_index_ == NOTOK ? 0 : default_name_mapping_config_index_;
				FreeChildren(DLG_NAME_CONVER_NAMEMAP);
				Int32 fnCount = 0;
				for (const Filename& i_fn : name_mapping_config_)
				{
					AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
					fnCount++;
				}
				SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(default_name_mapping_config_index_));
				LoadNameMappingConfig();
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
			name_conversion_.LoadConfig(name_mapping_config_dirname_ + name_mapping_config_[fn_index]);
			unregulated_name_.Reset();
			for (const String& i : name_conversion_.updata_name_conversion_)
			{
				if (auto i_ptr = name_conversion_.local_to_universal_name_lookup_table_.Find(i); i_ptr == nullptr && !i.IsEmpty())
				{
					iferr(unregulated_name_.Append(i)) return false;
				}
			}
			const Int32 conversion_count = static_cast<Int32>(unregulated_name_.GetCount());
			LayoutFlushGroup(1001);
			for (Int32 i = 0; i < conversion_count; i++)
			{
				GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);

				AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
				SetString(100000 + i, unregulated_name_[i], 0);

				AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
				SetString(100000 + i + conversion_count, ""_s, 0);

				GroupEnd();
			}
			LayoutChanged(1001);
		}
		else {
			LayoutFlushGroup(1001);
			const Int32 conversion_count = static_cast<Int32>(name_conversion_.updata_name_conversion_.GetCount());
			unregulated_name_.Reset();
			iferr(unregulated_name_.CopyFrom(name_conversion_.updata_name_conversion_)) return false;
			for (Int32 i = 0; i < conversion_count; i++)
			{
				GroupBegin(100000 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
				AddEditText(100000 + i, BFH_LEFT, 400, 10, 0);
				AddEditText(100000 + i + conversion_count, BFH_LEFT, 400, 10, 0);
				GroupEnd();
			}
			LayoutChanged(1001);
			for (Int32 i = 0; i < conversion_count; i++)
			{
				String str1 = name_conversion_.updata_name_conversion_[i];
				SetString(100000 + i, str1, 0);
				if (auto str2_ptr = name_conversion_.local_to_universal_name_lookup_table_.Find(str1); str2_ptr == nullptr)
				{
					SetString(100000 + i + conversion_count, ""_s, 0);
				}
				else
				{
					SetString(100000 + i + conversion_count, str2_ptr->GetValue(), 0);
				}
			}
		}
		break;
	}
	case DLG_NAME_CONVER_NAMEMAP:
	{
		LoadNameMappingConfig();
		break;
	}
	case DLG_NAME_CONVER_NEW_ADD:
	{
		String fn_s;
		GetString(DLG_NAME_CONVER_NEW, fn_s);
		Filename fn = name_mapping_config_dirname_ + Filename(fn_s + ".yaml");
		if (GeFExist(fn))
		{
			if (!QuestionDialog(IDS_MES_INQUIRY_OVERWRITING_FILE))
			{
				auto add_fn_index = name_mapping_config_.FindIndex(fn_s + ".yaml");
				add_fn_index = add_fn_index == NOTOK ? add_fn_index : default_name_mapping_config_index_;
				SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(add_fn_index));
				LoadNameMappingConfig();
				break;
			}
		}
		AutoAlloc<BaseFile> file;
		if (!file->Open(fn, FILEOPEN::WRITE))
			return false;
		file->Close();
		name_mapping_config_.Reset();
		AutoAlloc<BrowseFiles> bf;
		bf->Init(GeGetPluginResourcePath() + Filename("name_conversion"), BROWSEFILES_CALCSIZE);
		while (bf->GetNext())
		{
			if (!bf->IsDir())
			{
				iferr(name_mapping_config_.Append(bf->GetFilename())) continue;
			}
		}
		default_name_mapping_config_index_ = name_mapping_config_.FindIndex("default.yaml"_s);
		default_name_mapping_config_index_ = default_name_mapping_config_index_ == NOTOK ? 0 : default_name_mapping_config_index_;
		auto add_fn_index = name_mapping_config_.FindIndex(fn_s + ".yaml");
		default_name_mapping_config_index_ = add_fn_index == NOTOK ? add_fn_index : default_name_mapping_config_index_;
		FreeChildren(DLG_NAME_CONVER_NAMEMAP);
		Int32 fnCount = 0;
		for (const Filename& i_fn : name_mapping_config_)
		{
			AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
			fnCount++;
		}
		SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(add_fn_index));
		LoadNameMappingConfig();
		break;
	}
	case DLG_NAME_CONVER_NEW_INCREMENT_ADD:
	{
		String fn_s;
		GetString(DLG_NAME_CONVER_NEW, fn_s);
		Filename fn = name_mapping_config_dirname_ + Filename(fn_s + ".yaml");
		if (GeFExist(fn))
		{
			if (!QuestionDialog(IDS_MES_INQUIRY_OVERWRITING_FILE))
			{
				auto increment_fn_index = name_mapping_config_.FindIndex(fn_s + ".yaml");
				increment_fn_index = increment_fn_index == NOTOK ? increment_fn_index : default_name_mapping_config_index_;
				SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(increment_fn_index));
				LoadNameMappingConfig();
				break;
			}
		}
		Int32 fn_index = 0;
		GetInt32(DLG_NAME_CONVER_NAMEMAP, fn_index);
		GeFCopyFile(name_mapping_config_dirname_ + name_mapping_config_[fn_index], fn, GE_FCOPY_OVERWRITE);
		name_mapping_config_.Reset();
		AutoAlloc<BrowseFiles> bf;
		bf->Init(GeGetPluginResourcePath() + Filename("name_conversion"), BROWSEFILES_CALCSIZE);
		while (bf->GetNext())
		{
			if (!bf->IsDir())
			{
				iferr(name_mapping_config_.Append(bf->GetFilename())) continue;
			}
		}
		default_name_mapping_config_index_ = name_mapping_config_.FindIndex("default.yaml"_s);
		default_name_mapping_config_index_ = default_name_mapping_config_index_ == NOTOK ? 0 : default_name_mapping_config_index_;
		auto increment_fn_index = name_mapping_config_.FindIndex(fn_s + ".yaml");
		increment_fn_index = increment_fn_index == NOTOK ? increment_fn_index : default_name_mapping_config_index_;
		FreeChildren(DLG_NAME_CONVER_NAMEMAP);
		Int32 fnCount = 0;
		for (const Filename& i_fn : name_mapping_config_)
		{
			AddChild(DLG_NAME_CONVER_NAMEMAP, fnCount, i_fn.GetFileString());
			fnCount++;
		}
		SetInt32(DLG_NAME_CONVER_NAMEMAP, static_cast<Int32>(increment_fn_index));
		LoadNameMappingConfig();
		break;
	}
	default:
		break;
	}
	return true;
}


NameConversion::~NameConversion()
{
	local_to_universal_name_lookup_table_.Reset();
	universal_to_local_name_lookup_table_.Reset();
	updata_name_conversion_.Reset();
};

Bool NameConversion::LoadConfig(const Filename& filename)
{
	local_to_universal_name_lookup_table_.Reset();
	universal_to_local_name_lookup_table_.Reset();
	try {
		YAML::Node config = YAML::LoadFile(string_util::GetStdString(filename.GetString()));
		for (YAML::const_iterator it = config.begin(); it != config.end(); ++it)
		{
			iferr(local_to_universal_name_lookup_table_.Insert(it->first.as<String>(), it->second.as<String>())) return false;
			iferr(local_to_universal_name_lookup_table_.Insert(it->second.as<String>(), it->first.as<String>())) return false;
		}
	}
	catch (YAML::BadFile&) {
		GePrint("Failed to load the YAML file!"_s);
		//std::ofstream file_out(string_util::GetStdString(fn.GetString()));
	}
	return true;
}


Bool NameConversion::InitConver(String& str, const Bool op)
{
	if (op)
	{
		Bool not_english = true;
		for (const auto chr : str)
		{
			not_english = maxon::IsAlphanumeric(chr);
			if (not_english == false && chr != '-' && chr != '+' && chr != '_' && chr != ' ')
				break;
			not_english = true;
		}
		if (not_english)
		{
			iferr(local_to_universal_name_lookup_table_.Insert(str, str)) return false;
			iferr(universal_to_local_name_lookup_table_.Insert(str, str)) return false;
		}
		iferr(updata_name_conversion_.Append(str)) return false;
		return true;
	}
	if (const auto converted_ptr = universal_to_local_name_lookup_table_.Find(str); converted_ptr == nullptr)
	{
		return false;
	}
	return true;
}


String NameConversion::Conver(const String& src, const Bool use_universal)
{
	if (const auto converted_ptr = (use_universal ? local_to_universal_name_lookup_table_ : universal_to_local_name_lookup_table_).Find(src);
		converted_ptr != nullptr)
	{
		return converted_ptr->GetValue();
	}
	return FormatString("@_@", use_universal ? "bone" : "ボーン",updata_name_conversion_.FindIndex(src));
}


Bool NameConversion::CheckUpdate()
{
	UpdateNameConversionDialog dialog(*this);
	dialog.Open(DLG_TYPE::MODAL, ID_COMMAND_CMT_TOOL, -1, -1, 0, 0, 1);
	return true;
}


Bool NameConversion::AutoUpdate()
{
	const Int conversion_count = updata_name_conversion_.GetCount();
	for (Int item_index = 0; item_index < conversion_count; item_index++)
	{
		const String& str = updata_name_conversion_[item_index];
		iferr(local_to_universal_name_lookup_table_.Insert(str, FormatString("bone_@", item_index)))
			return false;
		iferr(universal_to_local_name_lookup_table_.Insert(FormatString("ボーン_@" , item_index), str))
			return false;
	}
	return true;
}
