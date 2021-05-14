#ifndef __NAME_CONVERSION_H__
#define __NAME_CONVERSION_H__

#include "c4d.h"
#include "c4d_symbols.h"
#include "ImagesGUI.h"

#undef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 1
#include "yaml-cpp/yaml.h"

#define ID_MMD_TOOL 1056563

class NameConversion 
{
private:
	maxon::BaseArray<String> updata_name_conversion_arr;
	maxon::HashMap<String, String> name_L_to_U_map;
	maxon::HashMap<String, String> name_U_to_L_map;
	class UpdataNameConversionDialog : public GeDialog
	{
		Int32 DefaultNameMap = 0;
		maxon::BaseArray<String> unregulated_array;
		maxon::BaseArray<Filename> NameMapArray;
		ImagesGUI* Images = nullptr;
		NameConversion* name_conversion = nullptr;
		Bool CreateLayout();
		Bool InitValues();
		Bool Command(Int32 id, const BaseContainer& msg);
	public:
		UpdataNameConversionDialog(NameConversion* name_conversion_);
		~UpdataNameConversionDialog() {  
			delete Images;
			NameMapArray.Reset();
		}
	};
public:
	NameConversion(){}
	~NameConversion();
	Bool LoadConfig(Filename fn);
	Bool InitConver(String& str, Bool op = true);
	Bool Conver(String& str, String& res, Bool op = true);
	Bool CheckUpdata();
	Bool AutoUpdata();
};

#endif __NAME_CONVERSION_H__