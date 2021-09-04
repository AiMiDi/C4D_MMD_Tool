﻿#ifndef __MMD_VMD_MODEl_H__
#define __MMD_VMD_MODEl_H__

#include "main.h"
#include "NameConversion.h"
#include "EncodingConversion.h"
#include "MMD_PMX_Control.h"

namespace mmd {
	struct PMX_Model_import_settings
	{
		Float	position_multiple;
		Bool	import_polygon;
		Bool	import_normal;
		Bool	import_uv;
		Bool	import_material;
		Bool	import_bone;
		Bool	import_weights;
		Bool	import_ik;
		Bool	import_inherit;
		Bool	import_expression;
		Bool	import_english;
		Bool	import_english_check;
		Bool	import_multipart;
	};

	struct PMX_Model_export_settings {
		Float	position_multiple;
		Bool	export_polygon;
		Bool	export_normal;
		Bool	export_uv;
		Bool	export_material;
		Bool	export_bone;
		Bool	export_weights;
		Bool	export_ik;
		Bool	export_inherit;
		Bool	export_expression;
	};

	class PMXModel
	{
	private:
		PMX_Model_information				model_info;             /* 模型信息 */
		PMX_Data_count					model_data_count;       /* 模型数据计数 */
		maxon::PointerArray<PMX_Vertex_Data>		vertex_data;            /* 顶点数据 */
		maxon::PointerArray<CPolygon>			surface_data;           /* 面数据 */
		maxon::PointerArray<String>			texture_data;           /* 贴图数据 */
		maxon::PointerArray<PMX_Material_Data>		material_data;          /* 材质数据 */
		maxon::PointerArray<PMX_Bone_Data>		bone_data;              /* 骨骼数据 */
		maxon::PointerArray<PMX_Morph_Data>		morph_data;             /* 变形数据 */
		maxon::PointerArray<PMX_Display_Data>		display_data;           /* 表示枠数据 */
		maxon::PointerArray<PMX_Rigid_Body_Data>	rigid_body_data;        /* 刚体数据 */
		maxon::PointerArray<PMX_Joint_Data>		joint_data;             /* J点数据 */


		Bool ReadText(BaseFile* const file, Char& text_encoding , String& out_string);


		Int32 ReadIndex(BaseFile* const file, Char& index_size);


		UInt32 ReadUIndex(BaseFile* const file, Char& index_size);


	public:
		PMXModel()
		{
		}


		~PMXModel()
		{
		}


		maxon::Result<void> LoadFromFile(BaseFile* const file);


		maxon::Result<void> SaveToFile(BaseFile* const file);


		static maxon::Result<void> FromFileImportModel(PMX_Model_import_settings& settings);


		static maxon::Result<void> FromDocumentExportModel(PMX_Model_export_settings& settings);
	};
}
#endif /* __MMD_VMD_MODEl_H__ */