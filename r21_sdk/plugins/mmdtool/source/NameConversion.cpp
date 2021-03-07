#include "NameConversion.h"


Bool NameConversion::UpdataNameConversionDialog::CreateLayout()
{

	SetTitle(GeLoadString(IDS_UPDATA_NAME_CONVERSION_TITLE));
	BaseContainer settings;
	settings.SetBool(BITMAPBUTTON_BUTTON, false);
	void* const customGUI = AddCustomGui(100000, CUSTOMGUI_BITMAPBUTTON, ""_s, BFH_SCALE, SizePix(300), SizePix(78), settings);
	BitmapButtonCustomGui* const bitmapButtonGUI = static_cast<BitmapButtonCustomGui*>(customGUI);
	if (bitmapButtonGUI)
	{
		bitmapButtonGUI->SetImage(AutoBitmap("mmd_tool_title.png"_s), true, false);
	}

	ScrollGroupBegin(100002, BFH_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 0, 300);
	GroupBegin(100003, BFH_CENTER, 1, 1, ""_s, 0, 0, 300);
	const Int conversion_count = name_conversion->updata_name_conversion_count;
	for (Int i = 0; i < conversion_count; i++) {
		GroupBegin(100004 + 2 * conversion_count, BFH_CENTER, 2, 1, ""_s, 0, 300, 10);
		AddEditText(100004 + i, BFH_LEFT, 400, 10, 0);
		AddEditText(100004 + i + conversion_count, BFH_LEFT, 400, 10, 0);
		GroupEnd();
	}
	GroupEnd();
	GroupEnd();
	AddButton(100001, BFH_CENTER, 500, 30, "OK"_s);
	return true;
}

Bool NameConversion::UpdataNameConversionDialog::InitValues()
{
	const Int conversion_count = name_conversion->updata_name_conversion_count;
	for (Int i = 0; i < conversion_count; i++) {
		SetString(100004 + i, name_conversion->updata_name_conversion_arr[i], 0);
		SetString(100004 + i + conversion_count, ""_s, 0);
	}
	return true;
}

Bool NameConversion::UpdataNameConversionDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
	case (100001):
	{
		const Int conversion_count = name_conversion->updata_name_conversion_count;
		maxon::HashMap<String, String>& name_L_to_U_map_ = name_conversion->name_L_to_U_map;
		maxon::HashMap<String, String>& name_U_to_L_map_ = name_conversion->name_U_to_L_map;
		for (Int i = 0; i < conversion_count; i++) {
			String str1 = name_conversion->updata_name_conversion_arr[i], str2;
			GetString(100004 + i + conversion_count, str2);
			if (str2 == ""_s) {
				iferr(name_L_to_U_map_.Insert(str1, "bone_" + String::IntToString(i)))return false;
				iferr(name_U_to_L_map_.Insert("bone_" + String::IntToString(i), str1))return false;
			}
			else {
				if (!name_conversion->Add(str1, str2))return false;
			}
		}
		this->Close();
		break;
	}
	}
	return true;
}

NameConversion::NameConversion()
{
	file = BaseFile::Alloc();
	updata_name_conversion_count = 0;
	Init();
};
NameConversion::~NameConversion()
{
	name_L_to_U_map.Reset();
	name_U_to_L_map.Reset();
	updata_name_conversion_arr.Reset();
	BaseFile::Free(file);
};

String NameConversion::Load_word(BaseFile*& file,Bool& OK) {
	Char tmp_c ;
	Char* tmp_s = new Char[1024]{ 0 };
	String res;
	for (Int32 i = 0; i < 1024; i++) {
		OK = file->ReadChar(&tmp_c);
		if (tmp_c == ',' || tmp_c == ';' || !OK)
		{
			break;
		}
		tmp_s[i] = tmp_c;
	}
	res.SetCString(tmp_s, -1, STRINGENCODING::UTF8);
	iferr(res.Trim())return false;
	return res;
}

Bool NameConversion::Init() {
	if (file == nullptr)return false;
	Filename Name_conversion_file = GeGetPluginResourcePath();	
	Name_conversion_file += Filename("Name_conversion.txt");
	file->Close();
	if (!file->Open(Name_conversion_file, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		return false;		
	}
	name_L_to_U_map.Reset();
	name_U_to_L_map.Reset();
	Bool name_local_OK, name_universal_OK;
	String name_local, name_universal;
	while(true) {
		name_local_OK = false, name_universal_OK = false;
		name_local = Load_word(file, name_local_OK);
		name_universal = Load_word(file, name_universal_OK);
		if (!name_local_OK || !name_universal_OK)break;
		iferr(name_L_to_U_map.Insert(name_local,name_universal))return false;
		iferr(name_U_to_L_map.Insert(name_universal,name_local))return false;
	}
	file->Close();
	if (!file->Open(Name_conversion_file, FILEOPEN::APPEND, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		return false;
	}
	return true;
}

Bool NameConversion::InitConver(String& str, Bool op) {
	if (op) {
		Bool Not_english = true;
		for (auto i : str) {
			Not_english = maxon::IsAlphanumeric(i);
			if (Not_english == false && i != '-'&& i != '+'&&  i != '_'&&  i != ' ')break;
			else Not_english = true;
		}
		if (Not_english) {
			iferr(name_L_to_U_map.Insert(str, str))return false;
			iferr(name_U_to_L_map.Insert(str, str))return false;
			return true;
		}
		auto converted_ptr = name_L_to_U_map.Find(str);
		if (converted_ptr == nullptr) {
			iferr(updata_name_conversion_arr.Append(str))return false;
			updata_name_conversion_count++;
			return true;
		}
	}
	else {
		auto converted_ptr = name_U_to_L_map.Find(str);
		if (converted_ptr == nullptr) {
			return false;
		}
	}
	return true;
}

Bool NameConversion::Conver(String& str, String& res, Bool op) {
	if (op) {
		auto converted_ptr = name_L_to_U_map.Find(str);
		if (converted_ptr == nullptr) {
			res = "bone_" + String::IntToString(updata_name_conversion_arr.FindIndex(str));
		}
		else {
			res = converted_ptr->GetValue();
		}
	}
	else {
		auto converted_ptr = name_U_to_L_map.Find(str);
		if (converted_ptr == nullptr) {
			res = "ボーン_" + String::IntToString(updata_name_conversion_arr.FindIndex(str));
		}
		else {
			res = converted_ptr->GetValue();
		}
	}
	return true;
}

Bool NameConversion::Add(String& str1, String& str2) {
	if (file == nullptr)return false;
	String Str_w(str1 + "," + str2 + ";\n");
	Int Strlen_w = static_cast<Int>(Str_w.GetCStringLen(STRINGENCODING::UTF8))+1;
	Char* CStr_w = new Char[Strlen_w]{ 0 };
	Str_w.GetCString(CStr_w, Strlen_w, STRINGENCODING::UTF8);
	for (Int i = 0; i < Strlen_w - 1;i++) {
		if (!file->WriteChar(CStr_w[i]))return false;
	}	
	iferr(name_L_to_U_map.Insert(str1, str2))return false;
	iferr(name_U_to_L_map.Insert(str2, str1))return false;
	return true;
}

Bool NameConversion::CheckUpdata() {
	UpdataNameConversionDialog dialog(this);
	dialog.Open(DLG_TYPE::MODAL, ID_MMD_TOOL,-1,-1,0,0,1);                                                                                                                             
	return true;
}

Bool NameConversion::AutoUpdata() {
	for (Int i = 0; i < updata_name_conversion_count; i++)
	{
		String str = updata_name_conversion_arr[i];
		iferr(name_L_to_U_map.Insert(str, "bone_" + String::IntToString(i)))return false;
		iferr(name_U_to_L_map.Insert("bone_" + String::IntToString(i), str))return false;		
	}
	return true;
}