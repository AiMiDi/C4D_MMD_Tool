#ifndef __MMD_VMD_MODEl_H__
#define __MMD_VMD_MODEl_H__

#include "main.h"
#include "MMD_PMX_tag.h"

namespace mmd {

	class PMXModel
	{
	private:
		PMX_Model_information model_info;//模型信息
		PMX_Data_count model_data_count;//模型数据计数
		maxon::BaseArray<PMX_Vertex_Data*> vertex_data;//顶点数据
		maxon::BaseArray<CPolygon*> surface_data;//面数据
		maxon::PointerArray<String> texture_data;//贴图数据
		maxon::BaseArray<PMX_Material_Data*> material_data;//材质数据
		maxon::BaseArray<PMX_Bone_Data*> bone_data;//骨骼数据
		maxon::BaseArray<PMX_Morph_Data*> morph_data;//变形数据
		maxon::BaseArray<PMX_Display_Data*> display_data;//表示枠数据
		maxon::BaseArray<PMX_Rigid_Body_Data*> rigid_body_data;//刚体数据
		maxon::BaseArray<PMX_Joint_Data*> joint_data;//J点数据
		
		inline String ReadText(BaseFile* const file, Char& text_encoding);
		inline Int32 ReadIndex(BaseFile* const file, Char& index_size);
		inline UInt32 ReadUIndex(BaseFile* const file, Char& index_size);

	public:
		PMXModel();
		~PMXModel();
		maxon::Result<void> LoadFromFile(BaseFile* const file);
		maxon::Result<void> WriteToFile(BaseFile* const file);
		static maxon::Result<void> FromFileImportModel(Float &PositionMultiple, PMX_Model_import_settings& settings);
		static maxon::Result<void> FromDocumentExportModel(Float& PositionMultiple, PMX_Model_export_settings& settings);
	};
}
#endif __MMD_VMD_MODEl_H__