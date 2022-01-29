#ifndef __MMD_VMD_MODEl_H__
#define __MMD_VMD_MODEl_H__

#include "MMD_utility.h"
#include "NameConversion.h"
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
		MAXON_DISALLOW_COPY_AND_ASSIGN(PMXModel);
	private:
		PMXModelInformation				model_info;             /* 模型信息 */
		PMXDataCount					model_data_count;       /* 模型数据计数 */
		maxon::PointerArray<PMXVertexData>		vertex_data;            /* 顶点数据 */
		maxon::PointerArray<CPolygon>			surface_data;           /* 面数据 */
		maxon::PointerArray<String>			texture_data;           /* 贴图数据 */
		maxon::PointerArray<PMXMaterialData>		material_data;          /* 材质数据 */
		maxon::PointerArray<PMXBoneData>		bone_data;              /* 骨骼数据 */
		maxon::PointerArray<PMXMorphData>		morph_data;             /* 变形数据 */
		maxon::PointerArray<PMXDisplayData>		display_data;           /* 表示枠数据 */
		maxon::PointerArray<PMXRigidBodyData>	rigid_body_data;        /* 刚体数据 */
		maxon::PointerArray<PMXJointData>		joint_data;             /* J点数据 */

	public:
		PMXModel(){}
		~PMXModel(){}
		maxon::Result<void> LoadFromFile(BaseFile* const file);
		maxon::Result<void> SaveToFile(BaseFile* const file);
		maxon::Result<void> FromFileImportModel(PMX_Model_import_settings& settings);
		maxon::Result<void> FromDocumentExportModel(PMX_Model_export_settings& settings);
	};
}
#endif /* __MMD_VMD_MODEl_H__ */