#ifndef __NAME_CONVERSION_H__
#define __NAME_CONVERSION_H__

#include "main.h"

class NameConversion {
public:			
		NameConversion();
		~NameConversion();
		Bool Init();
		String Load_word(BaseFile*& file, Bool& OK);	
		Bool InitConver(String& str, Bool op = true);
		Bool Conver(String& str, String& res, Bool op = true);
		Bool Add(String& str1, String& str2);
		Bool CheckUpdata();
		Bool AutoUpdata();
		
		BaseFile* file;	
		Int updata_name_conversion_count;
		maxon::BaseArray<String> updata_name_conversion_arr;
		maxon::HashMap<String, String>name_L_to_U_map;
		maxon::HashMap<String, String>name_U_to_L_map;	
};

class UpdataNameConversionDialog : public GeDialog
{
private:
	NameConversion* name_conversion;
	Int& updata_name_conversion_count;
	maxon::BaseArray<String>& updata_name_conversion_arr;
	maxon::HashMap<String, String>& name_L_to_U_map;
	maxon::HashMap<String, String>& name_U_to_L_map;
public:
	UpdataNameConversionDialog(NameConversion* name_conversion_) : updata_name_conversion_count(name_conversion_->updata_name_conversion_count), updata_name_conversion_arr(name_conversion_->updata_name_conversion_arr), name_L_to_U_map(name_conversion_->name_L_to_U_map), name_U_to_L_map(name_conversion_->name_U_to_L_map) { name_conversion = name_conversion_; }
	~UpdataNameConversionDialog() {}

	virtual Bool CreateLayout(void)
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
		for (Int i = 0; i < updata_name_conversion_count; i++) {
			GroupBegin(100004 + 2 * updata_name_conversion_count, BFH_CENTER, 2,1, ""_s, 0, 300, 10);
			AddEditText(100004 + i, BFH_LEFT,400, 10, 0);
			AddEditText(100004 + i + updata_name_conversion_count, BFH_LEFT, 400, 10, 0);
			GroupEnd();
		}
		GroupEnd();
		GroupEnd();
		AddButton(100001,BFH_CENTER, 500, 30, "OK"_s);
		return true;
	}

	virtual Bool InitValues(void)
	{
		for (Int i = 0; i < updata_name_conversion_count; i++) {
			SetString(100004 + i, updata_name_conversion_arr[i], 0);
			SetString(100004 + i + updata_name_conversion_count, ""_s, 0);
		}
		return true;
	}


	virtual Bool Command(Int32 id, const BaseContainer &msg)
	{
		switch (id)
		{
		case (100001):
		{		
			for (Int i = 0; i < updata_name_conversion_count; i++) {
				String str1 = updata_name_conversion_arr[i],str2;
				GetString(100004 + i + updata_name_conversion_count, str2);
				if (str2 == ""_s) {
					iferr(name_L_to_U_map.Insert(str1, "bone_" + String::IntToString(i)))return false;
					iferr(name_U_to_L_map.Insert("bone_" + String::IntToString(i), str1))return false;
				}
				else {
					if(!name_conversion->Add(str1, str2))return false;
				}
			}
			this->Close();
			break;	
		}
		}
		return true;
	}
};

#endif __NAME_CONVERSION_H__