#ifndef __NAME_CONVERSION_H__
#define __NAME_CONVERSION_H__

#include "main.h"

class NameConversion {
private:
	BaseFile* file;
	Int updata_name_conversion_count;
	maxon::BaseArray<String> updata_name_conversion_arr;
	maxon::HashMap<String, String> name_L_to_U_map;
	maxon::HashMap<String, String> name_U_to_L_map;
	String Load_word(BaseFile*& file, Bool& OK);

	class UpdataNameConversionDialog : public GeDialog
	{
		NameConversion* name_conversion;	
		Bool CreateLayout();
		Bool InitValues();
		Bool Command(Int32 id, const BaseContainer& msg);
	public:
		UpdataNameConversionDialog(NameConversion* name_conversion_) : name_conversion(name_conversion_) {}
	};
public:


	NameConversion();
	~NameConversion();

	Bool Init();	
	Bool InitConver(String& str, Bool op = true);

	Bool Conver(String& str, String& res, Bool op = true);
	Bool Add(String& str1, String& str2);

	Bool CheckUpdata();
	Bool AutoUpdata();

};

#endif __NAME_CONVERSION_H__