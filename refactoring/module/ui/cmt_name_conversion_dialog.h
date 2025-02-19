#pragma once


class UpdateNameConversionDialog;

class NameConversion final
{
	maxon::BaseArray<String>	updata_name_conversion_;
	maxon::HashMap<String, String>	local_to_universal_name_lookup_table_;
	maxon::HashMap<String, String>	universal_to_local_name_lookup_table_;
	Bool LoadConfig(const Filename& filename);
	friend UpdateNameConversionDialog;
public:
	NameConversion() = default;
	~NameConversion();
	Bool InitConver(String& str, Bool op = true);
	String Conver(const String& src, Bool use_universal = true);
	Bool CheckUpdate();
	Bool AutoUpdate();
};

class UpdateNameConversionDialog final : public GeDialog
{
	AutoFree<ImagesUserArea> images_;
	NameConversion& name_conversion_;
	Int default_name_mapping_config_index_ = 0;
	maxon::BaseArray<String> unregulated_name_;
	maxon::BaseArray<Filename> name_mapping_config_;
	static Filename name_mapping_config_dirname_;

	bool LoadNameMappingConfig();
	Bool CreateLayout() override;
	Bool InitValues() override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
public:
	explicit UpdateNameConversionDialog(NameConversion& name_conversion);
	~UpdateNameConversionDialog() override = default;
};
