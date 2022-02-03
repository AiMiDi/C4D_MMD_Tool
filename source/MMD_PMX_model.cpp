#include "MMD_PMX_model.h"
#undef GetObject

namespace mmd {
	inline maxon::Result<PMXWeight_BDEF1*> PMXWeight_BDEF1::Alloc()
	{
		iferr_scope;
		PMXWeight_BDEF1* res = NewObj(PMXWeight_BDEF1) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXWeight_BDEF1::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
		this->bone = ReadPMXIndex(file, bone_index_size);
		return true;
	}
	inline maxon::Result<PMXWeight_BDEF2*> PMXWeight_BDEF2::Alloc()
	{
		iferr_scope;
		PMXWeight_BDEF2* res = NewObj(PMXWeight_BDEF2) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXWeight_BDEF2::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
		this->bone[0] = ReadPMXIndex(file, bone_index_size);
		this->bone[1] = ReadPMXIndex(file, bone_index_size);
		if (!file->ReadFloat32(&(this->weight)))
			return false;
		return true;
	}
	inline maxon::Result<PMXWeight_BDEF4*> PMXWeight_BDEF4::Alloc()
	{
		iferr_scope;
		PMXWeight_BDEF4* res = NewObj(PMXWeight_BDEF4) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXWeight_BDEF4::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
		this->bone[0] = ReadPMXIndex(file, bone_index_size);
		this->bone[1] = ReadPMXIndex(file, bone_index_size);
		this->bone[2] = ReadPMXIndex(file, bone_index_size);
		this->bone[3] = ReadPMXIndex(file, bone_index_size);
		if (!file->ReadFloat32(&(this->weight[0])))
			return false;
		if (!file->ReadFloat32(&(this->weight[1])))
			return false;
		if (!file->ReadFloat32(&(this->weight[2])))
			return false;
		if (!file->ReadFloat32(&(this->weight[3])))
			return false;
		return true;
	}
	inline maxon::Result<PMXWeight_SDEF*> PMXWeight_SDEF::Alloc()
	{
		iferr_scope;
		PMXWeight_SDEF* res = NewObj(PMXWeight_SDEF) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXWeight_SDEF::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
		this->bone[0] = ReadPMXIndex(file, bone_index_size);
		this->bone[1] = ReadPMXIndex(file, bone_index_size);
		if (!file->ReadFloat32(&(this->weight)))
			return false;
		if (!file->ReadVector32(&(this->R0)))
			return false;
		if (!file->ReadVector32(&(this->R1)))
			return false;
		if (!file->ReadVector32(&(this->C)))
			return false;
		return true;
	}
	inline maxon::Result<PMXWeight_QDEF*> PMXWeight_QDEF::Alloc()
	{
		iferr_scope;
		PMXWeight_QDEF* res = NewObj(PMXWeight_QDEF) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXWeight_QDEF::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
		this->bone[0] = ReadPMXIndex(file, bone_index_size);
		this->bone[1] = ReadPMXIndex(file, bone_index_size);
		this->bone[2] = ReadPMXIndex(file, bone_index_size);
		this->bone[3] = ReadPMXIndex(file, bone_index_size);
		if (!file->ReadFloat32(&(this->weight[0])))
			return false;
		if (!file->ReadFloat32(&(this->weight[1])))
			return false;
		if (!file->ReadFloat32(&(this->weight[2])))
			return false;
		if (!file->ReadFloat32(&(this->weight[3])))
			return false;
		return true;
	}

	inline maxon::Result<PMXMorph_Group*> PMXMorph_Group::Alloc()
	{
		iferr_scope;
		PMXMorph_Group* res = NewObj(PMXMorph_Group) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Group::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->morph_index = ReadPMXIndex(file, index_size);
		if (!file->ReadFloat32(&(this->influence)))
			return false;
		return true;
	}
	inline maxon::Result<PMXMorph_Vertex*> PMXMorph_Vertex::Alloc()
	{
		iferr_scope;
		PMXMorph_Vertex* res = NewObj(PMXMorph_Vertex) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Vertex::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->vertex_index = ReadPMXUIndex(file, index_size);
		if (!file->ReadVector32(&(this->translation)))
			return false;
		return true;
	}
	inline maxon::Result<PMXMorph_Bone*> PMXMorph_Bone::Alloc()
	{
		iferr_scope;
		PMXMorph_Bone* res = NewObj(PMXMorph_Bone) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Bone::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->bone_index = ReadPMXIndex(file, index_size);
		if (!file->ReadVector32(&(this->translation)))
			return false;
		Vector4d32 q_rotation;
		if (!file->ReadBytes(&q_rotation, sizeof(Vector4d32)))
			return false;
		this->rotation = (Vector32)QuaternionToEuler(q_rotation);
		return true;
	}
	inline maxon::Result<PMXMorph_UV*> PMXMorph_UV::Alloc()
	{
		iferr_scope;
		PMXMorph_UV* res = NewObj(PMXMorph_UV) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_UV::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->vertex_index = ReadPMXIndex(file, index_size);
		if (!file->ReadBytes(&(this->floats), sizeof(Vector4d32)))
			return false;
		return true;
	}
	inline maxon::Result<PMXMorph_Material*> PMXMorph_Material::Alloc()
	{
		iferr_scope;
		PMXMorph_Material* res = NewObj(PMXMorph_Material) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Material::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->material_index = ReadPMXIndex(file, index_size);
		if (!file->ReadChar(&(this->blend_mode)))
			return false;
		if (!file->ReadBytes(&(this->diffuse), sizeof(Vector4d32)))
			return false;
		if (!file->ReadVector32(&(this->specular)))
			return false;
		if (!file->ReadFloat32(&(this->specularity)))
			return false;
		if (!file->ReadVector32(&(this->ambient)))
			return false;
		if (!file->ReadBytes(&(this->edge_colour), sizeof(Vector4d32)))
			return false;
		if (!file->ReadFloat32(&(this->edge_size)))
			return false;
		if (!file->ReadBytes(&(this->texture_tint), sizeof(Vector4d32)))
			return false;
		if (!file->ReadBytes(&(this->environment_tint), sizeof(Vector4d32)))
			return false;
		if (!file->ReadBytes(&(this->toon_tint), sizeof(Vector4d32)))
			return false;
		return true;
	}
	inline maxon::Result<PMXMorph_Flip*> PMXMorph_Flip::Alloc()
	{
		iferr_scope;
		PMXMorph_Flip* res = NewObj(PMXMorph_Flip) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Flip::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->morph_index = ReadPMXIndex(file, index_size);
		if (!file->ReadFloat32(&(this->influence)))
			return false;
		return true;
	}
	inline maxon::Result<PMXMorph_Impulse*> PMXMorph_Impulse::Alloc()
	{
		iferr_scope;
		PMXMorph_Impulse* res = NewObj(PMXMorph_Impulse) iferr_return;
		if (res == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
		}
		return res;
	}
	inline Bool PMXMorph_Impulse::ReadFromFile(BaseFile* file, const Char& index_size) {
		this->rigid_body_index = ReadPMXIndex(file, index_size);
		if (!file->ReadChar(&(this->local_flag)))
			return false;
		if (!file->ReadVector32(&(this->movement_speed)))
			return false;
		if (!file->ReadVector32(&(this->rotation_torque)))
			return false;
		return true;
	}

	maxon::Result<void> PMXModel::LoadFromFile(Filename& fn)
	{
		iferr_scope_handler{
#ifdef _DEBUG
			MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
			return err;
		};
		AutoAlloc<BaseFile>	file;
		SelectSuffixImportFile(fn, file, "pmx"_s)iferr_return;
		PMXModelInformation	model_info_;
		PMXDataCount		model_data_count_;
		Char			signature[5]{ 0 };     /* 签名,值为"PMX " */
		if (!file->ReadBytes(signature, 4))
			return(maxon::Error());                /* 读取签名 */
		if (strncmp(signature, "PMX", 3))
		{
			GePrint("Is not a PMX file!"_s);
		}
		if (!file->ReadFloat32(&(model_info_.version)))
			return(maxon::Error());                /* 读取版本号 */
		Char globals_count;                             /* 全局信息数量,PMX2.0有8条全局信息 */
		if (!file->ReadChar(&globals_count))
			return(maxon::Error());                /* 读取全局信息数量 */
		if (globals_count != 8)
		{
			GePrint("PMX file corruption!"_s);
		}
		if (!file->ReadChar(&(model_info_.text_encoding)))
			return(maxon::Error());                /* 读取字符串编码 */
		if (!file->ReadChar(&(model_info_.additional_Vector4d32_count)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.vertex_index_size)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.texture_index_size)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.material_index_size)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.bone_index_size)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.morph_index_size)))
			return(maxon::Error());
		if (!file->ReadChar(&(model_info_.rigidbody_index_size)))
			return(maxon::Error());
		if (!ReadPMXText(file, model_info_.text_encoding, model_info_.model_name_local))
			return(maxon::Error());
		if (!ReadPMXText(file, model_info_.text_encoding, model_info_.model_name_universal))
			return(maxon::Error());
		if (!ReadPMXText(file, model_info_.text_encoding, model_info_.comments_local))
			return(maxon::Error());
		if (!ReadPMXText(file, model_info_.text_encoding, model_info_.comments_universal))
			return(maxon::Error());
		this->m_model_info = model_info_;
		if (!file->ReadInt32(&(model_data_count_.vertex_data_count)))
			return(maxon::Error());
		for (Int32 i = 0; i < model_data_count_.vertex_data_count; i++)
		{
			PMXVertexData* vertex_data_ = NewObj(PMXVertexData) iferr_return;
			if (vertex_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!file->ReadVector32(&(vertex_data_->position)))
				return(maxon::Error());
			if (!file->ReadVector32(&(vertex_data_->normal)))
				return(maxon::Error());
			if (!file->ReadBytes(&(vertex_data_->UV), sizeof(Vector2d32)))
				return(maxon::Error());
			if (!file->Seek(16 * model_info_.additional_Vector4d32_count))
				return(maxon::Error());
			if (!file->ReadChar(&(vertex_data_->weight_deform_type)))
				return(maxon::Error());
			switch (vertex_data_->weight_deform_type)
			{
			case 0:
				vertex_data_->weight_deform = PMXWeight_BDEF1::Alloc()iferr_return;
				break;
			case 1:
				vertex_data_->weight_deform = PMXWeight_BDEF2::Alloc()iferr_return;
				break;
			case 2:
				vertex_data_->weight_deform = PMXWeight_BDEF4::Alloc()iferr_return;
				break;
			case 3:	
				vertex_data_->weight_deform = PMXWeight_SDEF::Alloc()iferr_return;		
				break;
			case 4:
				vertex_data_->weight_deform = PMXWeight_QDEF::Alloc()iferr_return;					
				break;
			}
			vertex_data_->weight_deform->ReadFromFile(file, model_info_.bone_index_size);		
			if (!file->ReadFloat32(&(vertex_data_->edge_scale)))
				return(maxon::Error());
			this->m_vertex_data.AppendPtr(vertex_data_) iferr_return;
		}
		if (!file->ReadInt32(&(model_data_count_.surface_data_count)))
			return(maxon::Error());
		model_data_count_.surface_data_count /= 3;
		for (Int32 i = 0; i < model_data_count_.surface_data_count; i++)
		{
			CPolygon* surface = NewObj(CPolygon, (Int32)ReadPMXUIndex(file, model_info_.vertex_index_size), (Int32)ReadPMXUIndex(file, model_info_.vertex_index_size), (Int32)ReadPMXUIndex(file, model_info_.vertex_index_size)) iferr_return;
			if (surface == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			this->m_surface_data.AppendPtr(surface) iferr_return;
		}
		if (!file->ReadInt32(&(model_data_count_.texture_data_count)))
			return(maxon::Error());
		for (Int32 i = 0; i < model_data_count_.texture_data_count; i++)
		{
			String tmp;
			if (!ReadPMXText(file, model_info_.text_encoding, tmp))
				return(maxon::Error());
			this->m_texture_data.Append(tmp) iferr_return;
		}
		if (!file->ReadInt32(&(model_data_count_.material_data_count)))
			return(maxon::Error());
		for (Int32 i = 0; i < model_data_count_.material_data_count; i++)
		{
			PMXMaterialData* material_data_ = NewObj(PMXMaterialData) iferr_return;
			if (material_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, material_data_->material_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, material_data_->material_name_universal))
				return(maxon::Error());
			if (!file->ReadBytes(&(material_data_->diffuse_colour), sizeof(Vector4d32)))
				return(maxon::Error());
			if (!file->ReadVector32(&(material_data_->specular_colour)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(material_data_->specular_strength)))
				return(maxon::Error());
			if (!file->ReadVector32(&(material_data_->ambient_colour)))
				return(maxon::Error());
			if (!file->ReadBytes(&(material_data_->drawing_flags), sizeof(PMXMaterialFlags)))
				return(maxon::Error());
			if (!file->ReadBytes(&(material_data_->edge_colour), sizeof(Vector4d32)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(material_data_->edge_scale)))
				return(maxon::Error());
			material_data_->texture_index = ReadPMXIndex(file, model_info_.texture_index_size);
			material_data_->environment_index = ReadPMXIndex(file, model_info_.texture_index_size);
			if (!file->ReadChar(&(material_data_->environment_blend_mode)))
				return(maxon::Error());
			if (!file->ReadChar(&(material_data_->toon_reference)))
				return(maxon::Error());
			if (material_data_->toon_reference == 0)
			{
				material_data_->toon_part = ReadPMXIndex(file, model_info_.texture_index_size);
			}
			else if (material_data_->toon_reference == 1)
			{
				if (!file->ReadChar(&(material_data_->toon_internal)))
					return(maxon::Error());
			}
			if (!ReadPMXText(file, model_info_.text_encoding, material_data_->meta_data))
				return(maxon::Error());
			if (!file->ReadInt32(&(material_data_->surface_count)))
				return(maxon::Error());
			material_data_->surface_count /= 3;
			this->m_material_data.AppendPtr(material_data_) iferr_return;
		}
		if (!file->ReadInt32(&(model_data_count_.bone_data_count)))
			return(maxon::Error());
		for (Int32 i = 0; i < model_data_count_.bone_data_count; i++)
		{
			PMXBoneData* bone_data_ = NewObj(PMXBoneData) iferr_return;
			if (bone_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, bone_data_->bone_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, bone_data_->bone_name_universal))
				return(maxon::Error());
			if (!file->ReadVector32(&(bone_data_->position)))
				return(maxon::Error());
			bone_data_->parent_bone_index = ReadPMXIndex(file, model_info_.bone_index_size);
			if (!file->ReadInt32(&(bone_data_->layer)))
				return(maxon::Error());
			if (!file->ReadBytes(&(bone_data_->bone_flags), sizeof(PMXBoneFlags)))
				return(maxon::Error());
			if (bone_data_->bone_flags.indexed_tail_position == 0)
			{
				if (!file->ReadVector32(&(bone_data_->tail_position)))
					return(maxon::Error());
			}
			else if (bone_data_->bone_flags.indexed_tail_position == 1)
			{
				bone_data_->tail_index = ReadPMXIndex(file, model_info_.bone_index_size);
			}
			if (bone_data_->bone_flags.Inherit_rotation || bone_data_->bone_flags.Inherit_translation)
			{
				bone_data_->inherit_bone_parent_index = ReadPMXIndex(file, model_info_.bone_index_size);
				if (!file->ReadFloat32(&(bone_data_->inherit_bone_parent_influence)))
					return(maxon::Error());
			}
			if (bone_data_->bone_flags.Fixed_axis)
			{
				if (!file->ReadVector32(&(bone_data_->bone_fixed_axis)))
					return(maxon::Error());
			}
			if (bone_data_->bone_flags.Local_coordinate)
			{
				if (!file->ReadVector32(&(bone_data_->bone_local_X)))
					return(maxon::Error());
				if (!file->ReadVector32(&(bone_data_->bone_local_Z)))
					return(maxon::Error());
			}
			if (bone_data_->bone_flags.External_parent_deform)
			{
				file->Seek(4);
			}
			if (bone_data_->bone_flags.IK)
			{
				bone_data_->IK_target_index = ReadPMXIndex(file, model_info_.bone_index_size);
				if (!file->ReadInt32(&(bone_data_->IK_loop_count)))
					return(maxon::Error());
				if (!file->ReadFloat32(&(bone_data_->IK_limit_radian)))
					return(maxon::Error());
				if (!file->ReadInt32(&(bone_data_->IK_link_count)))
					return(maxon::Error());
				for (Int32 j = 0; j < bone_data_->IK_link_count; j++)
				{
					PMXIKLinks* IK_link = NewObj(PMXIKLinks) iferr_return;
					if (IK_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					IK_link->bone_index = ReadPMXIndex(file, model_info_.bone_index_size);
					if (!file->ReadBool(&(IK_link->has_limits)))
						return(maxon::Error());
					if (IK_link->has_limits)
					{
						if (!file->ReadVector32(&(IK_link->limit_min)))
							return(maxon::Error());
						if (!file->ReadVector32(&(IK_link->limit_max)))
							return(maxon::Error());
					}
					bone_data_->IK_links.AppendPtr(IK_link) iferr_return;
				}
			}
			this->m_bone_data.AppendPtr(bone_data_) iferr_return;
		}
		if (!file->ReadInt32(&(model_data_count_.morph_data_count)))
			return(maxon::Error());
		for (Int32 i = 0; i < model_data_count_.morph_data_count; i++)
		{
			PMXMorphData* morph_data_ = NewObj(PMXMorphData) iferr_return;
			if (morph_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, morph_data_->morph_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, morph_data_->morph_name_universal))
				return(maxon::Error());
			if (!file->ReadChar(&(morph_data_->panel_type)))
				return(maxon::Error());
			if (!file->ReadChar(&(morph_data_->morph_type)))
				return(maxon::Error());
			if (!file->ReadInt32(&(morph_data_->offset_count)))
				return(maxon::Error());
			for (Int32 j = 0; j < morph_data_->offset_count; j++)
			{
				switch (morph_data_->morph_type)
				{
				case PMXMorphData::GROUP:
					morph_data_->offset_data.Append(PMXMorph_Group::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.morph_index_size);
					break;
				case PMXMorphData::VERTEX:
					morph_data_->offset_data.Append(PMXMorph_Vertex::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.vertex_index_size);
					if (!m_model_info.have_vertex_morph)
						m_model_info.have_vertex_morph = true;
					break;
				case PMXMorphData::BONE:
					morph_data_->offset_data.Append(PMXMorph_Bone::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.bone_index_size);
					break;
				case PMXMorphData::UV:
					morph_data_->offset_data.Append(PMXMorph_UV::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.vertex_index_size);
					if (!m_model_info.have_UV_morph)
						m_model_info.have_UV_morph = true;
					break;
				case PMXMorphData::UV1:
					if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
						return(maxon::Error());
					break;
				case PMXMorphData::UV2:
					if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
						return(maxon::Error());
					break;
				case PMXMorphData::UV3:
					if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
						return(maxon::Error());
					break;
				case PMXMorphData::UV4:
					if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
						return(maxon::Error());
					break;
				case PMXMorphData::MATERIAL:
					morph_data_->offset_data.Append(PMXMorph_Material::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.material_index_size);
					break;
				case PMXMorphData::FLIP:
					morph_data_->offset_data.Append(PMXMorph_Flip::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.morph_index_size);
					break;
				case PMXMorphData::IMPULSE:
					morph_data_->offset_data.Append(PMXMorph_Impulse::Alloc().GetValue()).GetValue()
						->ReadFromFile(file, model_info_.rigidbody_index_size);
					break;
				default:
					break;
				}
			}
			this->m_morph_data.AppendPtr(morph_data_) iferr_return;
		}
		file->ReadInt32(&(model_data_count_.display_data_count));
		for (Int32 i = 0; i < model_data_count_.display_data_count; i++)
		{
			PMXDisplayData* display_data_ = NewObj(PMXDisplayData) iferr_return;
			if (display_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, display_data_->display_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, display_data_->display_name_universal))
				return(maxon::Error());
			if (!file->ReadChar(&(display_data_->special_flag)))
				return(maxon::Error());
			if (!file->ReadInt32(&(display_data_->frame_count)))
				return(maxon::Error());
			for (Int32 j = 0; j < display_data_->frame_count; j++)
			{
				PMXFrameData* Frame = NewObj(PMXFrameData) iferr_return;
				if (!file->ReadChar(&(Frame->frame_type)))
					return(maxon::Error());
				if (Frame->frame_type == 1)           /* 1:索引 - 变形 */
				{
					Frame->frame_data = ReadPMXIndex(file, model_info_.morph_index_size);
				}
				else if (Frame->frame_type == 0)     /* 0:索引-骨骼 */
				{
					Frame->frame_data = ReadPMXIndex(file, model_info_.bone_index_size);
				}
				display_data_->Frames.AppendPtr(Frame) iferr_return;
			}
			this->m_display_data.AppendPtr(display_data_) iferr_return;
		}
		file->ReadInt32(&(model_data_count_.rigid_body_data_count));
		for (Int32 i = 0; i < model_data_count_.rigid_body_data_count; i++)
		{
			PMXRigidBodyData* rigid_body_data_ = NewObj(PMXRigidBodyData) iferr_return;
			if (rigid_body_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, rigid_body_data_->rigid_body_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, rigid_body_data_->rigid_body_name_universal))
				return(maxon::Error());
			rigid_body_data_->related_bone_index = ReadPMXIndex(file, model_info_.bone_index_size);
			if (!file->ReadChar(&(rigid_body_data_->group_id)))
				return(maxon::Error());
			if (!file->ReadBytes(&(rigid_body_data_->non_collision_group), sizeof(PMXRigidBodyNonCollisionGroup)))
				return(maxon::Error());
			if (!file->ReadChar(&(rigid_body_data_->shape_type)))
				return(maxon::Error());
			if (!file->ReadVector32(&(rigid_body_data_->shape_size)))
				return(maxon::Error());
			if (!file->ReadVector32(&(rigid_body_data_->shape_position)))
				return(maxon::Error());
			if (!file->ReadVector32(&(rigid_body_data_->shape_rotation)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(rigid_body_data_->mass)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(rigid_body_data_->move_attenuation)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(rigid_body_data_->rotation_damping)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(rigid_body_data_->repulsion_force)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(rigid_body_data_->friction_force)))
				return(maxon::Error());
			if (!file->ReadChar(&(rigid_body_data_->physics_mode)))
				return(maxon::Error());
			this->m_rigid_body_data.AppendPtr(rigid_body_data_) iferr_return;
		}
		file->ReadInt32(&(model_data_count_.joint_data_count));
		for (Int32 i = 0; i < model_data_count_.joint_data_count; i++)
		{
			PMXJointData* joint_data_ = NewObj(PMXJointData) iferr_return;
			if (joint_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			if (!ReadPMXText(file, model_info_.text_encoding, joint_data_->joint_name_local))
				return(maxon::Error());
			if (!ReadPMXText(file, model_info_.text_encoding, joint_data_->joint_name_universal))
				return(maxon::Error());
			if (!file->ReadChar(&(joint_data_->joint_type)))
				return(maxon::Error());
			joint_data_->rigid_body_index_A = ReadPMXIndex(file, model_info_.rigidbody_index_size);
			joint_data_->rigid_body_index_B = ReadPMXIndex(file, model_info_.rigidbody_index_size);
			if (!file->ReadVector32(&(joint_data_->position)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->rotation)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->position_minimum)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->position_maximum)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->rotation_minimum)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->rotation_maximum)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->position_spring)))
				return(maxon::Error());
			if (!file->ReadVector32(&(joint_data_->rotation_spring)))
				return(maxon::Error());
			this->m_joint_data.AppendPtr(joint_data_) iferr_return;
		}
		this->m_model_data_count = model_data_count_;
		return(maxon::OK);
	}
	maxon::Result<void> PMXModel::SaveToFile(Filename& fn)
	{
		return(maxon::OK);
	}
	maxon::Result<void> PMXModel::ImportBone(CAWeightTag* weight_tag) 
	{
		iferr_scope;
		NameConversion	name_conversion;
		const Int32 kBoneDataCount = this->m_model_data_count.bone_data_count;
		/*Create a bone object and initialize the English name conversion.*/
		for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
		{
			PMXBoneData& bone_data_ = this->m_bone_data[bone_index];
			BaseObject* bone = BaseObject::Alloc(Ojoint);
			if (bone == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			name_conversion.InitConver(bone_data_.bone_name_local);
			bone_map.Insert(bone_index, bone) iferr_return;
		}
		EventAdd();
		if (this->import_settings.import_english_check)
		{
			name_conversion.CheckUpdata();
		}
		else {
			name_conversion.AutoUpdata();
		}
		/*Sets the parent-child relationship and position of the bone.*/
		for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
		{
			PMXBoneData& bone_data_ = this->m_bone_data[bone_index];
			auto bone_ptr = bone_map.Find(bone_index);
			if (bone_ptr == nullptr)
			{
				return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
			}
			BaseObject* bone = bone_ptr->GetValue();
			if (weight_tag != nullptr && this->import_settings.import_weights) {
				weight_tag->AddJoint(bone);
			}
			if (bone_data_.parent_bone_index == -1)
			{
				bone->SetFrozenPos(Vector(bone_data_.position) * this->import_settings.position_multiple);
				doc->InsertObject(bone, m_bone_root, nullptr);
			}
			else {
				bone->SetFrozenPos(Vector(bone_data_.position - this->m_bone_data[bone_data_.parent_bone_index].position) * this->import_settings.position_multiple);
				auto parent_bone_ptr = bone_map.Find(bone_data_.parent_bone_index);
				if (parent_bone_ptr != nullptr)
				{
					doc->InsertObject(bone, parent_bone_ptr->GetValue(), nullptr);
				}
			}
		}
		EventAdd();
		// Create tag and import data.
		for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
		{
			PMXBoneData& bone_data_ = this->m_bone_data[bone_index];
			auto bone_ptr = bone_map.Find(bone_index);
			if (bone_ptr == nullptr)
			{
				return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
			}
			BaseObject* bone = bone_ptr->GetValue();
			/*Change the English name.*/
			if (bone_data_.bone_name_universal == ""_s)
			{
				name_conversion.Conver(bone_data_.bone_name_local, bone_data_.bone_name_universal);
			}
			BaseTag* PMX_bone_tag = bone->MakeTag(ID_T_MMD_BONE);
			if (PMX_bone_tag == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			TMMDBone* bone_tag_data = PMX_bone_tag->GetNodeData<TMMDBone>();
			bone_tag_data->SetObj(bone);
			bone_tag_data->SetRootObject(m_bone_root);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_INDEX), String::IntToString(bone_index), DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(ID_BASELIST_NAME), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_LOCAL), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), bone_data_.bone_name_universal, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_IS), this->import_settings.import_english, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_POSITION), (Vector)bone_data_.position * this->import_settings.position_multiple, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_ROTATABLE), bone_data_.bone_flags.Rotatable, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_TRANSLATABLE), bone_data_.bone_flags.Translatable, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_VISIBLE), bone_data_.bone_flags.Is_visible, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_ENABLED), bone_data_.bone_flags.Enabled, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_IS_IK), bone_data_.bone_flags.IK, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_LAYER), bone_data_.layer, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_PHYSICS_AFTER_DEFORM), bone_data_.bone_flags.Physics_after_deform, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_INDEXED_TAIL_POSITION), bone_data_.bone_flags.indexed_tail_position, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_ROTATION), bone_data_.bone_flags.Inherit_rotation, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_TRANSLATION), bone_data_.bone_flags.Inherit_translation, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_IS_FIXED_AXIS), bone_data_.bone_flags.Fixed_axis, DESCFLAGS_SET::NONE);
			PMX_bone_tag->SetParameter(DescID(PMX_BONE_LOCAL_IS_COORDINATE), bone_data_.bone_flags.Local_coordinate, DESCFLAGS_SET::NONE);
			if (bone_data_.bone_flags.indexed_tail_position == 1)
			{
				PMX_bone_tag->SetParameter(PMX_BONE_TAIL_INDEX, bone_data_.tail_index, DESCFLAGS_SET::NONE);
			}
			else {
				PMX_bone_tag->SetParameter(PMX_BONE_TAIL_POSITION, (Vector)bone_data_.position * this->import_settings.position_multiple, DESCFLAGS_SET::NONE);
			}
			if (bone_data_.bone_flags.Local_coordinate)
			{
				PMX_bone_tag->SetParameter(PMX_BONE_LOCAL_X, (Vector)bone_data_.bone_local_X, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(PMX_BONE_LOCAL_Z, (Vector)bone_data_.bone_local_Z, DESCFLAGS_SET::NONE);
			}
			if (bone_data_.bone_flags.Fixed_axis == 1)
			{
				PMX_bone_tag->SetParameter(PMX_BONE_FIXED_AXIS, (Vector)bone_data_.bone_fixed_axis, DESCFLAGS_SET::NONE);
			}
			if (this->import_settings.import_inherit)
			{
				if (bone_data_.bone_flags.Inherit_translation == 1)
				{
					BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
					if (inherit_bone_parent_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_.inherit_bone_parent_index);
					if (inherit_bone_parent_link_ptr != nullptr)
						inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
					PMX_bone_tag->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_LINK, inherit_bone_parent_link, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
				}
				if (bone_data_.bone_flags.Inherit_rotation == 1)
				{
					BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
					if (inherit_bone_parent_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_.inherit_bone_parent_index);
					if (inherit_bone_parent_link_ptr != nullptr)
						inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
					PMX_bone_tag->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_LINK, inherit_bone_parent_link, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
				}
			}
			if (this->import_settings.import_ik)
			{
				if (bone_data_.bone_flags.IK == 1)
				{
					if (bone_data_.IK_links.Begin() == bone_data_.IK_links.End()) {
						continue;
					}
					BaseObject* IK_beging_bone = bone_map.Find((bone_data_.IK_links.End() - 1)->bone_index)->GetValue();
					if (IK_beging_bone == nullptr) {
						continue;
					}
					BaseTag* IK_tag = IK_beging_bone->MakeTag(1019561); /* Ik Tag ID : 1019561 */
					if (this->import_settings.import_english)
					{
						IK_tag->SetName(bone_data_.bone_name_universal);
					}
					else {
						IK_tag->SetName(bone_data_.bone_name_local);
					}
					IK_tag->SetParameter(ID_CA_IK_TAG_SOLVER, ID_CA_IK_TAG_SOLVER_3D, DESCFLAGS_SET::NONE);
					IK_tag->SetParameter(ID_CA_IK_TAG_PREFERRED_WEIGHT, 1, DESCFLAGS_SET::NONE);
					BaseLink* target_link = BaseLink::Alloc();
					if (target_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					target_link->SetLink(bone);
					IK_tag->SetParameter(ID_CA_IK_TAG_TARGET, target_link, DESCFLAGS_SET::NONE);
					BaseLink* tip_link = BaseLink::Alloc();
					if (tip_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					tip_link->SetLink(bone_map.Find(bone_data_.IK_target_index)->GetValue());
					IK_tag->SetParameter(ID_CA_IK_TAG_TIP, tip_link, DESCFLAGS_SET::NONE);
					DynamicDescription* const ddesc = m_model_root->GetDynamicDescription();
					if (ddesc == nullptr)
						return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION));
					DescID ik_link_id;
					MAXON_SCOPE
					{
						BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
						bc.SetString(DESC_NAME, bone_data_.bone_name_local);
						bc.SetData(DESC_PARENTGROUP, GeData { CUSTOMDATATYPE_DESCID, DescID(MODEL_IK_GRP) });
						ik_link_id = ddesc->Alloc(bc);
					}
					BaseLink* ik_link = BaseLink::Alloc();
					if (ik_link == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					ik_link->SetLink(IK_tag);
					m_model_root->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
					for (mmd::PMXIKLinks& IK_link : bone_data_.IK_links)
					{
						BaseObject* IK_link_bone = bone_map.Find(IK_link.bone_index)->GetValue();
						if (IK_link_bone == nullptr)
							continue;
						IK_link_bone->SetParameter(ID_CA_JOINT_OBJECT_JOINT_IK_PREFERRED_ROT_LINK, 0, DESCFLAGS_SET::NONE);
						if (IK_link.has_limits != true)
							continue;
						IK_link_bone->SetParameter(ID_CA_JOINT_OBJECT_JOINT_IK_MIN_ROT,
							Vector(IK_link.limit_min.x, IK_link.limit_min.y, IK_link.limit_min.z), DESCFLAGS_SET::NONE);
						IK_link_bone->SetParameter(ID_CA_JOINT_OBJECT_JOINT_IK_MAX_ROT,
							Vector(IK_link.limit_max.x, IK_link.limit_max.y, IK_link.limit_max.z), DESCFLAGS_SET::NONE);
						IK_link_bone->SetParameter(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_B, 1, DESCFLAGS_SET::NONE);
					}
				}
			}
		}
		m_bone_root->Message(ID_T_MMD_BONE);
		DescriptionCheckUpdate* msg_data = NewObj(DescriptionCheckUpdate)iferr_return;
		msg_data->descid = NewObj(DescID, PMX_BONE_INHERIT_BONE_PARENT_LINK)iferr_return;
		m_bone_root->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, msg_data);
		for (PMXRigidBodyData& rigid_body_data : this->m_rigid_body_data)
		{
			const Int32 bone_index = rigid_body_data.related_bone_index;
			if (bone_index != -1)
			{
				auto bone_ptr = bone_map.Find(bone_index);
				if (bone_ptr == nullptr)
				{
					return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
				}
				BaseObject* bone = bone_ptr->GetValue();
				if (bone != nullptr)
				{
					BaseTag* bone_tag = bone->GetTag(ID_T_MMD_BONE);
					if (bone_tag != nullptr)
					{
						TMMDBone* bone_tag_data = bone_tag->GetNodeData<TMMDBone>();
						if (bone_tag_data != nullptr)
						{
							if (rigid_body_data.physics_mode == 1)
								bone_tag_data->SetPhysical(true);
						}
					}
				}
			}
		}
		return maxon::OK;
	}
	maxon::Result<void> PMXModel::ImportWeight(CAWeightTag* weight_tag,BaseObject* obj,const tag_info* const morph_tag_info) {
		iferr_scope;
		weight_tag = CAWeightTag::Alloc();
		if (weight_tag == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		obj->InsertTag(weight_tag);
		maxon::HashMap<Int32, Int32>	joint_bone_map;
		maxon::HashMap<Int32, maxon::UniqueRef<maxon::HashMap<Int32, Float32>>> weight_data_map;
		Int32 vertex_count = ToPoint(obj)->GetPointCount();
		if (morph_tag_info != nullptr)
		{
			vertex_count = Int32(morph_tag_info->vertex_index_arr.GetCount());
		}
		//TODO: Optimize.
		for (Int32 part_vertex_index = 0; part_vertex_index < vertex_count; part_vertex_index++)
		{
			PMXVertexData* vertex_data = &this->m_vertex_data[part_vertex_index];
			if (morph_tag_info != nullptr)
			{
				vertex_data = &this->m_vertex_data[morph_tag_info->vertex_index_arr[part_vertex_index]];
			}
			switch (vertex_data->weight_deform_type)
			{
			case PMXVertexData::BDEF1:
			{
				Int32 weight_bone = 0;
				auto* weight_deform = static_cast<PMXWeight_BDEF1*>(vertex_data->weight_deform);
				auto joint_bone_ptr = joint_bone_map.Find(weight_deform->bone);
				if (joint_bone_ptr)
				{
					weight_bone = joint_bone_ptr->GetValue();
				}
				else {
					weight_bone = weight_tag->AddJoint(bone_map.Find(weight_deform->bone)->GetValue());
					joint_bone_map.Insert(weight_deform->bone, weight_bone)iferr_return;
				}
				auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
				maxon::HashMap<Int32, Float32>* weight_data = nullptr;
				if (weight_data_ptr != nullptr) {
					weight_data = weight_data_ptr->GetValue();
				}
				else
				{	
					weight_data = weight_data_map.Insert(part_vertex_index, 
						std::move(maxon::UniqueRef<maxon::HashMap<Int32, Float32>>(maxon::NewObjT<maxon::HashMap<Int32, Float32>>().GetValue()))).GetValue().GetValue();
				}
				weight_data->Insert(weight_bone, 1.0f)iferr_return;
				break;
			}
			case PMXVertexData::BDEF2:
			{
				Int32 weight_bone1 = 0;
				auto* weight_deform = static_cast<PMXWeight_BDEF2*>(vertex_data->weight_deform);
				auto joint_bone1_ptr = joint_bone_map.Find(weight_deform->bone[0]);
				if (joint_bone1_ptr)
				{
					weight_bone1 = joint_bone1_ptr->GetValue();
				}
				else {
					weight_bone1 = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[0])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[0], weight_bone1) iferr_return;
				}
				Int32 weight_bone2 = 0;
				auto joint_bone2_ptr = joint_bone_map.Find(weight_deform->bone[1]);
				if (joint_bone2_ptr)
				{
					weight_bone2 = joint_bone2_ptr->GetValue();
				}
				else {
					weight_bone2 = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[1])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[1], weight_bone2) iferr_return;
				}
				auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
				maxon::HashMap<Int32, Float32>* weight_data = nullptr;
				if (weight_data_ptr != nullptr) {
					weight_data = weight_data_ptr->GetValue();
				}
				else
				{
					weight_data = weight_data_map.Insert(part_vertex_index,
						std::move(maxon::UniqueRef<maxon::HashMap<Int32, Float32>>(maxon::NewObjT<maxon::HashMap<Int32, Float32>>().GetValue()))).GetValue().GetValue();
				}
				auto weight_data1_ptr = weight_data->Find(weight_bone1);
				if (weight_data1_ptr != nullptr) {
					weight_data1_ptr->GetValue() += weight_deform->weight;
				}
				else {
					weight_data->Insert(weight_bone1, weight_deform->weight)iferr_return;
				}
				auto weight_data2_ptr = weight_data->Find(weight_bone2);
				if (weight_data2_ptr != nullptr) {
					weight_data2_ptr->GetValue() += 1.f - weight_deform->weight;
				}
				else {
					weight_data->Insert(weight_bone2, 1.f - weight_deform->weight)iferr_return;
				}
				break;
			}
			case PMXVertexData::BDEF4:
			{
				Int32 weight_bone[4] = { 0 };
				auto* weight_deform = static_cast<PMXWeight_BDEF4*>(vertex_data->weight_deform);
				auto joint_bone1_ptr = joint_bone_map.Find(weight_deform->bone[0]);
				if (joint_bone1_ptr)
				{
					weight_bone[0] = joint_bone1_ptr->GetValue();
				}
				else {
					weight_bone[0] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[0])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[0], weight_bone[0]) iferr_return;
				}
				auto joint_bone2_ptr = joint_bone_map.Find(weight_deform->bone[1]);
				if (joint_bone2_ptr)
				{
					weight_bone[1] = joint_bone2_ptr->GetValue();
				}
				else {
					weight_bone[1] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[1])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[1], weight_bone[1]) iferr_return;
				}
				auto joint_bone3_ptr = joint_bone_map.Find(weight_deform->bone[2]);
				if (joint_bone3_ptr)
				{
					weight_bone[2] = joint_bone3_ptr->GetValue();
				}
				else {
					weight_bone[2] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[2])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[2], weight_bone[2])iferr_return;
				}
				auto joint_bone4_ptr = joint_bone_map.Find(weight_deform->bone[3]);
				if (joint_bone4_ptr)
				{
					weight_bone[3] = joint_bone4_ptr->GetValue();
				}
				else {
					weight_bone[3] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[3])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[3], weight_bone[3]) iferr_return;
				}
				auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
				maxon::HashMap<Int32, Float32>* weight_data = nullptr;
				if (weight_data_ptr != nullptr) {
					weight_data = weight_data_ptr->GetValue();
				}
				else
				{
					weight_data = weight_data_map.Insert(part_vertex_index,
						std::move(maxon::UniqueRef<maxon::HashMap<Int32, Float32>>(maxon::NewObjT<maxon::HashMap<Int32, Float32>>().GetValue()))).GetValue().GetValue();
				}
				for (Int32 i = 0; i < 4; i++) {
					Int32& weight_bone_index = weight_bone[i];
					auto weight_data_ptr = weight_data->Find(weight_bone_index);
					if (weight_data_ptr != nullptr) {
						weight_data_ptr->GetValue() += weight_deform->weight[i];
					}
					else {
						weight_data->Insert(weight_bone_index, weight_deform->weight[i])iferr_return;
					}
				}
				break;
			}
			case PMXVertexData::SDEF:
			{
				Int32 weight_bone1 = 0;
				auto* weight_deform = static_cast<PMXWeight_SDEF*>(vertex_data->weight_deform);
				auto joint_bone1_ptr = joint_bone_map.Find(weight_deform->bone[0]);
				if (joint_bone1_ptr)
				{
					weight_bone1 = joint_bone1_ptr->GetValue();
				}
				else {
					weight_bone1 = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[0])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[0], weight_bone1) iferr_return;
				}
				Int32 weight_bone2 = 0;
				auto joint_bone2_ptr = joint_bone_map.Find(weight_deform->bone[1]);
				if (joint_bone2_ptr)
				{
					weight_bone2 = joint_bone2_ptr->GetValue();
				}
				else {
					weight_bone2 = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[1])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[1], weight_bone2) iferr_return;
				}
				auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
				maxon::HashMap<Int32, Float32>* weight_data = nullptr;
				if (weight_data_ptr != nullptr) {
					weight_data = weight_data_ptr->GetValue();
				}
				else
				{
					weight_data = weight_data_map.Insert(part_vertex_index,
						std::move(maxon::UniqueRef<maxon::HashMap<Int32, Float32>>(maxon::NewObjT<maxon::HashMap<Int32, Float32>>().GetValue()))).GetValue().GetValue();
				}
				auto weight_data1_ptr = weight_data->Find(weight_bone1);
				if (weight_data1_ptr != nullptr) {
					weight_data1_ptr->GetValue() += weight_deform->weight;
				}
				else {
					weight_data->Insert(weight_bone1, weight_deform->weight)iferr_return;
				}
				auto weight_data2_ptr = weight_data->Find(weight_bone2);
				if (weight_data2_ptr != nullptr) {
					weight_data2_ptr->GetValue() += 1.f - weight_deform->weight;
				}
				else {
					weight_data->Insert(weight_bone2, 1.f - weight_deform->weight)iferr_return;
				}
				break;
			}
			case PMXVertexData::QDEF:
			{
				Int32 weight_bone[4] = { 0 };
				auto* weight_deform = static_cast<PMXWeight_QDEF*>(vertex_data->weight_deform);
				auto joint_bone1_ptr = joint_bone_map.Find(weight_deform->bone[0]);
				if (joint_bone1_ptr)
				{
					weight_bone[0] = joint_bone1_ptr->GetValue();
				}
				else {
					weight_bone[0] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[0])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[0], weight_bone[0]) iferr_return;
				}
				auto joint_bone2_ptr = joint_bone_map.Find(weight_deform->bone[1]);
				if (joint_bone2_ptr)
				{
					weight_bone[1] = joint_bone2_ptr->GetValue();
				}
				else {
					weight_bone[1] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[1])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[1], weight_bone[1]) iferr_return;
				}
				auto joint_bone3_ptr = joint_bone_map.Find(weight_deform->bone[2]);
				if (joint_bone3_ptr)
				{
					weight_bone[2] = joint_bone3_ptr->GetValue();
				}
				else {
					weight_bone[2] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[2])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[2], weight_bone[2])iferr_return;
				}
				auto joint_bone4_ptr = joint_bone_map.Find(weight_deform->bone[3]);
				if (joint_bone4_ptr)
				{
					weight_bone[3] = joint_bone4_ptr->GetValue();
				}
				else {
					weight_bone[3] = weight_tag->AddJoint(bone_map.Find(weight_deform->bone[3])->GetValue());
					joint_bone_map.Insert(weight_deform->bone[3], weight_bone[3]) iferr_return;
				}
				auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
				maxon::HashMap<Int32, Float32>* weight_data = nullptr;
				if (weight_data_ptr != nullptr) {
					weight_data = weight_data_ptr->GetValue();
				}
				else
				{
					weight_data = weight_data_map.Insert(part_vertex_index,
						std::move(maxon::UniqueRef<maxon::HashMap<Int32, Float32>>(maxon::NewObjT<maxon::HashMap<Int32, Float32>>().GetValue()))).GetValue().GetValue();
				}
				for (Int32 i = 0; i < 4; i++) {
					Int32& weight_bone_index = weight_bone[i];
					auto weight_data_ptr = weight_data->Find(weight_bone_index);
					if (weight_data_ptr != nullptr) {
						weight_data_ptr->GetValue() += weight_deform->weight[i];
					}
					else {
						weight_data->Insert(weight_bone_index, weight_deform->weight[i])iferr_return;
					}
				}
				break;
			}
			}
		}
		Int32 insideCount = 0;
		maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, vertex_count, [](LocalData& context)
			{
				context.localCount = 0;
			}, [this, &weight_tag, &weight_data_map, &morph_tag_info](const Int32 vertex_index, LocalData& context)->maxon::Result<void>
			{
				auto weight_data_ptr = weight_data_map.Find(vertex_index);
				if (weight_data_ptr != nullptr) {
					auto& weight_data = weight_data_ptr->GetValue();
					for (auto& i : weight_data->GetKeys()) {
						auto weight_ptr = weight_data->Find(i);
						if (weight_ptr != nullptr) {
							if (!weight_tag->SetWeight(i, vertex_index, weight_ptr->GetValue())) {
								return maxon::Error();
							}
						}
					}
				}
				context.localCount++;
				if (GeIsMainThread())
				{
					StatusSetSpin();
				}
				return(maxon::OK);
			}, [&insideCount, &vertex_count](LocalData& context)
			{
				insideCount += context.localCount;
				if (GeIsMainThread())
					StatusSetText("Import vertex weight " + String::IntToString(insideCount) + " of " + String::IntToString(vertex_count));
			}) iferr_return;
		joint_bone_map.Reset();
		// 添加蒙皮变形器
		BaseObject* morphdeformer = BaseObject::Alloc(Oskin);
		if (morphdeformer == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		doc->InsertObject(morphdeformer, obj, nullptr);
		// 正规化权重
		CAWeightMgr::NormalizeWeights(doc);
		// 设置绑定默认姿势
#if API_VERSION >= 21000
		weight_tag->SetBindPose(doc, false);
#else		
		DescriptionCommand dc;
		dc._descId = DescID(ID_CA_WEIGHT_TAG_SET);
		weight_tag->Message(MSG_DESCRIPTION_COMMAND, &dc);
#endif					
		return maxon::OK;
	}
	maxon::Result<void> PMXModel::ImportMaterial(const String& path, const Int32& material_index, TextureTag* const texture_tag)
	{
		iferr_scope;
		PMXMaterialData& material_data = this->m_material_data[material_index];
		Material* material = Material::Alloc();
		if (material == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (this->import_settings.import_english)
		{
			material->SetName("Material_" + String::IntToString(material_index));
		}
		else {
			material->SetName(material_data.material_name_local);
		}
		BaseChannel* basecolor_channel = material->GetChannel(CHANNEL_COLOR);
		if (basecolor_channel == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		material->SetChannelState(CHANNEL_ALPHA, true);
		BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
		if (alpha_channel == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}

		if (material_data.texture_index == -1)
		{
			BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
			if (alpha_shader == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
			alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data.diffuse_colour.w, DESCFLAGS_SET::NONE);
			material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(alpha_shader);
			BaseShader* basecolor_shader = BaseShader::Alloc(Xcolor);
			if (basecolor_shader == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			basecolor_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(material_data.diffuse_colour), DESCFLAGS_SET::NONE);
			basecolor_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data.diffuse_colour.w, DESCFLAGS_SET::NONE);
			material->SetParameter(DescID(MATERIAL_COLOR_SHADER), basecolor_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(basecolor_shader);
		}
		else {
			String			texture = this->m_texture_data[material_data.texture_index];
			Filename		texture_file(texture);
			AutoAlloc<BaseBitmap> bm;
			if (bm == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			bm->Init(path + texture);
			// 确认图片有透明通道
			if (bm->GetChannelCount() && 
				(texture_file.GetSuffix().ToLower().Compare("png"_s) != maxon::COMPARERESULT::EQUAL || 
				texture_file.GetSuffix().ToLower().Compare("tga"_s) != maxon::COMPARERESULT::EQUAL))
			{
				BaseContainer bc;
				bc = basecolor_channel->GetData();
				material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data.diffuse_colour), DESCFLAGS_SET::NONE);
				bc.SetString(BASECHANNEL_TEXTURE, path + texture);
				basecolor_channel->SetData(bc);
				bc = alpha_channel->GetData();
				bc.SetString(BASECHANNEL_TEXTURE, path + texture);
				alpha_channel->SetData(bc);
			}
			else {
				BaseContainer bc;
				bc = basecolor_channel->GetData();
				material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data.diffuse_colour), DESCFLAGS_SET::NONE);
				bc.SetString(BASECHANNEL_TEXTURE, path + texture);
				basecolor_channel->SetData(bc);
				BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
				alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
				alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data.diffuse_colour.w, DESCFLAGS_SET::NONE);
				material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
				material->InsertShader(alpha_shader);
			}
		}
		doc->InsertMaterial(material);
		if (texture_tag != nullptr)
		{
			texture_tag->SetMaterial(material);
			texture_tag->SetName(material_data.material_name_local);
			texture_tag->SetParameter(DescID(TEXTURETAG_PROJECTION), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
			// 不是多部分导入的设置选集
			if(!this->import_settings.import_multipart)
				texture_tag->SetParameter(DescID(TEXTURETAG_RESTRICTION), material_data.material_name_local, DESCFLAGS_SET::NONE);
		}
		return maxon::OK;
	}
	maxon::Result<void> PMXModel::FromFileImportMultipartModel()
	{
		iferr_scope_handler{
#ifdef _DEBUG
		MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
			return err;
		};

		doc = GetActiveDocument();
		if (doc == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
		Filename		fn;	
		this->LoadFromFile(fn) iferr_return;
		maxon::TimeValue timing = maxon::TimeValue::GetTime();
		String path = fn.GetString();
		path.Delete(path.GetLength() - fn.GetFileString().GetLength(), fn.GetFileString().GetLength());

		Int insideCount = 0;
		m_model_root = BaseObject::Alloc(ID_O_MMD_MODEL);
		if (m_model_root == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (this->import_settings.import_english)
		{
			m_model_root->SetName("Model"_s);
		}
		else {
			m_model_root->SetName(this->m_model_info.model_name_local);
		}
		OMMDModel* ModelRootData = m_model_root->GetNodeData<OMMDModel>();
		if (!ModelRootData->CreateRoot())
			return(maxon::Error());
		doc->InsertObject(m_model_root, nullptr, nullptr);
		m_mesh_root = nullptr;
		if (this->import_settings.import_polygon)
		{
			m_mesh_root = ModelRootData->GetRootObject(OMMDModel_Root_type::MeshRoot);
			if (m_mesh_root == nullptr)
			{
				m_mesh_root = BaseObject::Alloc(Onull);
				if (m_mesh_root == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				m_mesh_root->SetName("Meshes"_s);
				doc->InsertObject(m_mesh_root, m_model_root, nullptr);
			}
		}
		m_bone_root = nullptr;
		if (this->import_settings.import_bone)
		{
			m_bone_root = ModelRootData->GetRootObject(OMMDModel_Root_type::BoneRoot);
			if (m_bone_root == nullptr)
			{
				m_bone_root = BaseObject::Alloc(Onull);
				if (m_bone_root == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				m_bone_root->SetName("Bones"_s);
				doc->InsertObject(m_bone_root, m_model_root, nullptr);
			}
		}
		m_model_root->SetParameter(DescID(ID_BASELIST_NAME), this->m_model_info.model_name_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(PMX_VERSION), this->m_model_info.version, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(MODEL_NAME_LOCAL), this->m_model_info.model_name_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(MODEL_NAME_UNIVERSAL), this->m_model_info.model_name_universal, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(COMMENTS_LOCAL), this->m_model_info.comments_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(COMMENTS_UNIVERSAL), this->m_model_info.comments_universal, DESCFLAGS_SET::NONE);
		if (this->import_settings.import_bone)
			ImportBone(nullptr)iferr_return;
		struct point_info
		{
			BaseObject* object;
			CAPoseMorphTag* morph_tag;            /* The tag where it is. */
			Int32		point_index;            /* Point converted index. */
			maxon::HashInt GetHashCode() const
			{
				return MAXON_HASHCODE(this->object, this->morph_tag, this->point_index);
			}
		};
		
		maxon::HashMap<Int32, point_info>	vertex_info_map;
		maxon::BaseList<tag_info>		morph_tag_list;

		Int32		part_surface_end = 0;
		const Int32	material_data_count = this->m_model_data_count.material_data_count;
		for (Int32 material_index = 0; material_index < material_data_count; material_index++)
		{
			PMXMaterialData& material_data = this->m_material_data[material_index];
			PolygonObject* part = nullptr;
			CAWeightTag* weight_tag = nullptr;
			if (this->import_settings.import_polygon)
			{
				const Int32	surface_data_count = material_data.surface_count;
				const Int32	vertex_data_count = surface_data_count * 3;
				if (surface_data_count == 0 || vertex_data_count == 0) {
					continue;
				}
				part = PolygonObject::Alloc(vertex_data_count, surface_data_count);
				if (part == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				if (this->import_settings.import_english)
				{
					part->SetName("Material_" + String::IntToString(material_index));
				}
				else {
					part->SetName(material_data.material_name_local);
				}			
				PointObject* part_point_obj = ToPoint(part);
				Vector* part_points = part_point_obj->GetPointW();
				if (part_points == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				CPolygon* part_polygon;
				PolygonObject* part_polygon_obj = ToPoly(part);
				part_polygon = part_polygon_obj->GetPolygonW();
				if (part_polygon == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				CAPoseMorphTag* morph_tag = nullptr;
				if (this->import_settings.import_expression)
				{
					/* Initialization morph tag. */
					morph_tag = CAPoseMorphTag::Alloc();
					morph_tag->SetName("Morph_" + material_data.material_name_local);
					if (morph_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					part->InsertTag(morph_tag);
					morph_tag->InitMorphs();
				}
				tag_info& morph_tag_info = morph_tag_list.Append(std::move(tag_info()))iferr_return;
				morph_tag_info.morph_tag = morph_tag;

				Int32			new_index = 0;
				for (Int32 surface_index = 0; surface_index < surface_data_count; surface_index++)
				{
					CPolygon& surface = this->m_surface_data[surface_index + part_surface_end];
					auto			vertex_info_map_a_ptr = vertex_info_map.Find(surface.a);
					if (vertex_info_map_a_ptr == nullptr)
					{
						morph_tag_info.vertex_index_arr.Append(surface.a) iferr_return;
						auto& res = vertex_info_map.InsertMultiEntry(surface.a).GetValue().GetValue();
						res.object = part;
						res.morph_tag = morph_tag;
						res.point_index = new_index;
						new_index++;
					}
					else {
						point_info& point_a = vertex_info_map_a_ptr->GetValue();
						if (point_a.object != part)
						{
							morph_tag_info.vertex_index_arr.Append(surface.a)iferr_return;
							auto& res = vertex_info_map.InsertMultiEntry(surface.a).GetValue().GetValue();
							res.object = part;
							res.morph_tag = morph_tag;
							res.point_index = new_index;
							new_index++;
						}
					}
					auto vertex_info_map_b_ptr = vertex_info_map.Find(surface.b);
					if (vertex_info_map_b_ptr == nullptr)
					{
						morph_tag_info.vertex_index_arr.Append(surface.b) iferr_return;
						auto& res = vertex_info_map.InsertMultiEntry(surface.b).GetValue().GetValue();
						res.object = part;
						res.morph_tag = morph_tag;
						res.point_index = new_index;
						new_index++;
					}
					else {
						point_info& point_b = vertex_info_map_b_ptr->GetValue();
						if (point_b.object != part)
						{
							morph_tag_info.vertex_index_arr.Append(surface.b) iferr_return;
							auto& res = vertex_info_map.InsertMultiEntry(surface.b).GetValue().GetValue();
							res.object = part;
							res.morph_tag = morph_tag;
							res.point_index = new_index;
							new_index++;
						}
					}
					auto vertex_info_map_c_ptr = vertex_info_map.Find(surface.c);
					if (vertex_info_map_c_ptr == nullptr)
					{
						morph_tag_info.vertex_index_arr.Append(surface.c) iferr_return;
						auto& res = vertex_info_map.InsertMultiEntry(surface.c).GetValue().GetValue();
						res.object = part;
						res.morph_tag = morph_tag;
						res.point_index = new_index;
						new_index++;
					}
					else {
						point_info& point_c = vertex_info_map_c_ptr->GetValue();
						if (point_c.object != part)
						{
							morph_tag_info.vertex_index_arr.Append(surface.c) iferr_return;
							auto& res = vertex_info_map.InsertMultiEntry(surface.c).GetValue().GetValue();
							res.object = part;
							res.morph_tag = morph_tag;
							res.point_index = new_index;
							new_index++;
						}
					}
				}
				// 导入顶点位置
				Int32 vertex_count = Int32(morph_tag_info.vertex_index_arr.GetCount());
				maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, vertex_count, [](LocalData& context)
					{
						context.localCount = 0;
					}, [this, &morph_tag_info, &part_points](const Int32 vertex_index, LocalData& context)->maxon::Result<void>
					{
						PMXVertexData& vertex_data = this->m_vertex_data[morph_tag_info.vertex_index_arr[vertex_index]];
						part_points[vertex_index] = Vector(vertex_data.position * this->import_settings.position_multiple);					
						context.localCount++;
						if (GeIsMainThread())
						{
							StatusSetSpin();
						}
						return(maxon::OK);
					}, [&insideCount, &vertex_count](LocalData& context)
					{
						insideCount += context.localCount;
						if (GeIsMainThread())
							StatusSetText("Import vertex position " + String::IntToString(insideCount) + " of " + String::IntToString(vertex_count));
					}) iferr_return;
				part_point_obj->Message(MSG_UPDATE);
				// 导入顶点权重
				if (this->import_settings.import_weights)
					this->ImportWeight(weight_tag, part, &morph_tag_info)iferr_return;

				NormalTag* normal_tag = nullptr;
				NormalHandle normal_handle;
				if (this->import_settings.import_normal)
				{
					normal_tag = NormalTag::Alloc(material_data.surface_count);
					if (normal_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					normal_handle = normal_tag->GetDataAddressW();
					part->InsertTag(normal_tag);
				}
				UVWTag* uvw_tag = nullptr;
				UVWHandle	uvw_handle;
				if (this->import_settings.import_uv)
				{
					uvw_tag = UVWTag::Alloc(material_data.surface_count);
					if (uvw_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					uvw_handle = uvw_tag->GetDataAddressW();
					part->InsertTag(uvw_tag);
				}
				insideCount = 0;
				maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, surface_data_count, [](LocalData& context)
					{
						context.localCount = 0;
					}, [this, &part_surface_end, &part_polygon, &normal_handle, &uvw_handle, &vertex_info_map, &part](const Int32 surface_index, LocalData& context)->maxon::Result<void>
					{
						iferr_scope_handler{
							MessageDialog(err.ToString(nullptr));
							return err;
						};
						CPolygon & surface = this->m_surface_data[surface_index + part_surface_end];
						PMXVertexData & vertex0 = this->m_vertex_data[surface.a];
						PMXVertexData & vertex1 = this->m_vertex_data[surface.b];
						PMXVertexData & vertex2 = this->m_vertex_data[surface.c];
						Int32 vertex_a_index = 0;
						auto vertex_a_ptr = vertex_info_map.Find(surface.a);
						// 找到对应该part的对应的点a新顶点索引。
						while (vertex_a_ptr != nullptr)
						{
							const auto& vertex_a_info = vertex_a_ptr->GetValue();
							if (vertex_a_info.object == part)
							{
								vertex_a_index = vertex_a_info.point_index;
								break;
							}
							vertex_a_ptr = vertex_a_ptr->GetNextWithSameKey();
						}
						Int32 vertex_b_index = 0;
						auto vertex_b_ptr = vertex_info_map.Find(surface.b);
						// 找到对应该part的对应的点b新顶点索引。
						while (vertex_b_ptr != nullptr)
						{
							const auto& vertex_b_info = vertex_b_ptr->GetValue();
							if (vertex_b_info.object == part)
							{
								vertex_b_index = vertex_b_info.point_index;
								break;
							}
							vertex_b_ptr = vertex_b_ptr->GetNextWithSameKey();
						}
						Int32 vertex_c_index = 0;
						auto vertex_c_ptr = vertex_info_map.Find(surface.c);
						// 找到对应该part的对应的点c新顶点索引。
						while (vertex_c_ptr != nullptr)
						{
							const auto& vertex_c_info = vertex_c_ptr->GetValue();
							if (vertex_c_info.object == part)
							{
								vertex_c_index = vertex_c_info.point_index;
								break;
							}
							vertex_c_ptr = vertex_c_ptr->GetNextWithSameKey();
						}
						g_spinlock.Lock();
						part_polygon[surface_index] = CPolygon(vertex_a_index, vertex_b_index, vertex_c_index);
						g_spinlock.Unlock();
						if (this->import_settings.import_normal)
						{
							Vector normal0 = (Vector)vertex0.normal;
							Vector normal1 = (Vector)vertex1.normal;
							Vector normal2 = (Vector)vertex2.normal;
							Vector normal3(0, 0, 0);
							normal0.Normalize();
							normal1.Normalize();
							normal2.Normalize();
							normal3.Normalize();
							g_spinlock.Lock();
							NormalTag::Set(normal_handle, surface_index, NormalStruct(normal0, normal1, normal2, normal3));
							g_spinlock.Unlock();
						}
						if (this->import_settings.import_uv)
						{
							g_spinlock.Lock();
							UVWTag::Set(uvw_handle, surface_index, UVWStruct(Vector(vertex0.UV.x, vertex0.UV.y, 0), Vector(vertex1.UV.x, vertex1.UV.y, 0), Vector(vertex2.UV.x, vertex2.UV.y, 0)));
							g_spinlock.Unlock();
						}
						context.localCount++;
						if (GeIsMainThread())
						{
							StatusSetSpin();
						}
						return(maxon::OK);
					}, [&insideCount, &surface_data_count](LocalData& context)
					{
						insideCount += context.localCount;
						if (GeIsMainThread())
							StatusSetText("Import surface " + String::IntToString(insideCount) + " of " + String::IntToString(surface_data_count));
					}) iferr_return;
				part_polygon_obj->Message(MSG_UPDATE);
				part->SetPhong(true, true, 0.7853982);
				doc->InsertObject(part, m_mesh_root, nullptr);
				EventAdd();
				doc->SetSelection(part);
				/*
				 * ModelingCommandData cd;
				 * cd.doc = doc;
				 * cd.op = part;
				 * cd.mode = MODELINGCOMMANDMODE::POLYGONSELECTION;
				 * if (!SendModelingCommand(MCOMMAND_SELECTALL, cd)) return maxon::FAILED;
				 * if (!SendModelingCommand(MCOMMAND_SELECTPOLYTOPOINT, cd)) return maxon::FAILED;
				 * cd.mode = MODELINGCOMMANDMODE::POINTSELECTION;
				 * if (!SendModelingCommand(MCOMMAND_SELECTINVERSE, cd)) return maxon::FAILED;
				 * if (!SendModelingCommand(MCOMMAND_DELETE, cd)) return maxon::FAILED;
				 */
				if (this->import_settings.import_expression)
				{
					/* Add base morph to the tag. */
					if (this->m_model_info.have_vertex_morph)
					{
						morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
					}
					if (this->m_model_info.have_UV_morph)
					{
						morph_tag->SetParameter(ID_CA_POSE_UV, true, DESCFLAGS_SET::NONE);
					}
					morph_tag->ExitEdit(doc, true);
					CAMorph* base_morph = morph_tag->AddMorph();
					if (base_morph == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					base_morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
					morph_tag->UpdateMorphs();
				}
				part_surface_end += material_data.surface_count;
			}
			if (this->import_settings.import_material)
			{
				TextureTag* texture_tag = nullptr;
				if (this->import_settings.import_polygon)
				{
					texture_tag = static_cast<TextureTag*>(part->MakeTag(Ttexture));
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}				
				}
				this->ImportMaterial(path, material_index, texture_tag)iferr_return;
			}
		}

		if (this->import_settings.import_expression)
		{
			// Get the morph data count.
			Int32 morph_data_count = this->m_model_data_count.morph_data_count;
			// 记录每个Morph标签所有的CMorph对象，并且可以通过名字来查找它
			maxon::HashMap<BaseObject*, CAPoseMorphTag*> bone_tag_map;
			maxon::HashMap<CAPoseMorphTag*, maxon::UniqueRef<maxon::HashMap<String, CAMorph*>>>	tag_morph_map;
			// 遍历每个表情
			for (Int32 morph_index = 0; morph_index < morph_data_count; morph_index++)
			{
				// 读取对应表情数据
				PMXMorphData& morph_data = this->m_morph_data[morph_index];
				switch (morph_data.morph_type)
				{
					// 顶点表情
				case PMXMorphData::VERTEX:
				{
					// 表情数据储存的变换信息个数
					Int32 offset_count = morph_data.offset_count;
					for (Int32 offset_count_index = 0; offset_count_index < offset_count; offset_count_index++)
					{
						// 对应变换信息
						UInt32	vertex_index = static_cast<PMXMorph_Vertex*>(morph_data.offset_data[offset_count_index])->vertex_index;
						// 在vertex_info_map里查找原顶点在该部分中的对应顶点信息
						auto	point_info_ptr = vertex_info_map.Find(vertex_index);
						if (point_info_ptr == nullptr)
							continue;
						const point_info& point_info_ = point_info_ptr->GetValue();
						point_info_.morph_tag->ExitEdit(doc, true);
						auto vertex_morph_ptr = tag_morph_map.Find(point_info_.morph_tag);
						// 若找不到Morph标签对应的CMorph对象的信息，则创建CMorph对象信息
						if (vertex_morph_ptr == nullptr)
						{
							maxon::UniqueRef<maxon::HashMap<String, CAMorph*>> name_morph_map = maxon::NewObjT<maxon::HashMap<String, CAMorph*>>() iferr_return;
							CAMorph* morph = point_info_.morph_tag->AddMorph();
							if (morph == nullptr)
							{
								GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
								MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
								return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
							}
							morph->SetName(morph_data.morph_name_local);
							morph->Store(doc, point_info_.morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
							morph->SetMode(doc, point_info_.morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
							name_morph_map->Insert(morph_data.morph_name_local, morph) iferr_return;
							tag_morph_map.Insert(point_info_.morph_tag, std::move(name_morph_map)) iferr_return;
						}
						else {
							maxon::HashMap<String, CAMorph*>* name_morph_map = vertex_morph_ptr->GetValue();
							auto				name_morph_ptr = name_morph_map->Find(morph_data.morph_name_local);
							if (name_morph_ptr == nullptr)
							{
								CAMorph* morph = point_info_.morph_tag->AddMorph();
								if (morph == nullptr)
								{
									GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
								morph->SetName(morph_data.morph_name_local);
								morph->Store(doc, point_info_.morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
								morph->SetMode(doc, point_info_.morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
								name_morph_map->Insert(morph_data.morph_name_local, morph) iferr_return;
							}
						}
					}
					maxon::ParallelFor::Dynamic(0, offset_count, [&vertex_info_map, &tag_morph_map, &morph_data, this](const Int32 offset_count_index)->maxon::Result<void>
						{
							iferr_scope_handler{
								MessageDialog(err.ToString(nullptr));
								return err;
							};
							PMXMorph_Vertex * vertex_morph_data = static_cast<PMXMorph_Vertex*>(morph_data.offset_data[offset_count_index]);
							// 对应变换信息
							UInt32 vertex_index = vertex_morph_data->vertex_index;
							// 在vertex_info_map里查找原顶点在该部分中的对应顶点信息
							auto point_info_ptr = vertex_info_map.Find(vertex_index);
							if (point_info_ptr == nullptr)
								return maxon::OK;
							while (point_info_ptr != nullptr)
							{
								const point_info& point_info_ = point_info_ptr->GetValue();
								point_info_.morph_tag->ExitEdit(doc, true);
								auto vertex_morph_ptr = tag_morph_map.Find(point_info_.morph_tag);
								if (vertex_morph_ptr == nullptr) {
									point_info_ptr = point_info_ptr->GetNextWithSameKey();
									continue;
								}
								auto name_morph_ptr = vertex_morph_ptr->GetValue()->Find(morph_data.morph_name_local);
								if (name_morph_ptr == nullptr) {
									point_info_ptr = point_info_ptr->GetNextWithSameKey();
									continue;
								}							
								CAMorph* morph = name_morph_ptr->GetValue();
								CAMorphNode* morph_node = morph->GetFirst();
								while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node != nullptr)
								{
									morph_node = morph_node->GetNext();
								}
								morph_node->SetPoint(point_info_.point_index, Vector(vertex_morph_data->translation * this->import_settings.position_multiple));
								point_info_ptr = point_info_ptr->GetNextWithSameKey();
							}
							return(maxon::OK);
						}) iferr_return;
					break;
				}
				// 骨骼表情
				case PMXMorphData::BONE: {
					if (this->import_settings.import_bone)
					{
						Int32					offset_count = morph_data.offset_count;                                      /* 读取表情数据储存的变换信息个数 */
						maxon::ParallelFor::Dynamic(0, offset_count, [this, &bone_tag_map, &morph_data](const Int32 offset_count_index)->maxon::Result<void>
							{
								iferr_scope_handler{
									MessageDialog(err.ToString(nullptr));
									return err;
								};
								PMXMorph_Bone * bone_morph_data = static_cast<PMXMorph_Bone*>(morph_data.offset_data[offset_count_index]);
								auto bone_ptr = bone_map.Find(bone_morph_data->bone_index);
								if (bone_ptr == nullptr)
									return maxon::OK;
								BaseObject* bone = bone_ptr->GetValue();
								if (bone == nullptr)
									return maxon::OK;
								BaseTag* pmx_bone_tag = bone->GetTag(ID_T_MMD_BONE);
								if (pmx_bone_tag == nullptr)
									return maxon::OK;
								TMMDBone* pmx_bone_tag_data = pmx_bone_tag->GetNodeData<TMMDBone>();
								Int32 bone_morph_data_index = pmx_bone_tag_data->AddBondMorph(morph_data.morph_name_local);
								if (bone_morph_data_index == -1)
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								if (!pmx_bone_tag_data->SetBondMorphTranslation(bone_morph_data_index, Vector(bone_morph_data->translation * this->import_settings.position_multiple)))
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								if (!pmx_bone_tag_data->SetBondMorphRotation(bone_morph_data_index, Vector(bone_morph_data->rotation)))
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								return maxon::OK;
							}) iferr_return;
					}
					break;
				}
					  // UV表情
				case PMXMorphData::UV:
				{
					maxon::HashMap<Int32, Vector>		vertex_floats_map;
					for (PMXMorph* data : morph_data.offset_data)
					{
						PMXMorph_UV* UV_morph_data = static_cast<PMXMorph_UV*>(data);
						vertex_floats_map.Insert(UV_morph_data->vertex_index, Vector(UV_morph_data->floats.x, UV_morph_data->floats.y, 0)) iferr_return;
					}
					for (tag_info& tag_info_ : morph_tag_list)
					{
						tag_info_.morph_tag->ExitEdit(doc, true);
						CAMorph* morph = tag_info_.morph_tag->AddMorph();
						if (morph == nullptr)
						{
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
						}
						morph->SetName(morph_data.morph_name_local);
						morph->Store(doc, tag_info_.morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
						CAMorphNode* morph_node = morph->GetFirst();
						while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::UV) && morph_node != nullptr)
						{
							morph_node = morph_node->GetNext();
						}
						morph->SetMode(doc, tag_info_.morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
						Int32 surface_data_count = morph_node->GetUVCount(0);
						maxon::ParallelFor::Dynamic(0, surface_data_count, [&morph_node, this, &vertex_floats_map, &vertex_info_map, &tag_info_](const Int32 surface_index)
							{
								const CPolygon& surface = ToPoly(tag_info_.morph_tag->GetObject())->GetPolygonR()[surface_index];
								UVWStruct uvw;
								morph_node->GetUV(0, surface_index, uvw);
								auto vertex_a_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr[surface.a]);
								if (vertex_a_ptr != nullptr)
								{
									uvw.c = vertex_a_ptr->GetValue();
								}
								auto vertex_b_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr[surface.b]);
								if (vertex_b_ptr != nullptr)
								{
									uvw.b = vertex_b_ptr->GetValue();
								}
								auto vertex_c_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr[surface.c]);
								if (vertex_c_ptr != nullptr)
								{
									uvw.a = vertex_c_ptr->GetValue();
								}
								morph_node->SetUV(0, surface_index, uvw);
							});
						morph->SetMode(doc, tag_info_.morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
						tag_info_.morph_tag->UpdateMorphs();
						tag_info_.morph_tag->Message(MSG_UPDATE);
						morph->SetStrength(0);
						tag_info_.morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
					}
					break;
				}
				default:
					break;
				}
			}
			// 清除没有表情的变形标签，初始化表情强度，发送更新信息。
			for (tag_info& tag_info_ : morph_tag_list)
			{
				if (tag_info_.morph_tag->GetMorphCount() == 1)
				{
					CAPoseMorphTag::Free(tag_info_.morph_tag);
					continue;
				}
				tag_info_.morph_tag->UpdateMorphs();
				tag_info_.morph_tag->Message(MSG_UPDATE);
				const Int32 morph_count = tag_info_.morph_tag->GetMorphCount();
				for (Int32 morph_index = 1; morph_index < morph_count; morph_index++)
				{
					CAMorph* morph = tag_info_.morph_tag->GetMorph(morph_index);
					morph->SetStrength(0);
					morph->SetMode(doc, tag_info_.morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
				}
				/* Set "ID_CA_POSE_MODE" parameter to animation. */
				tag_info_.morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
			}
			tag_morph_map.Reset();
			bone_tag_map.Reset();
		}
		morph_tag_list.Reset();
		bone_map.Reset();
		vertex_info_map.Reset();
		doc->SetMode(Mmodel);
		doc->SetSelection(nullptr);
		timing.Stop();
		GePrint(String::FloatToString(timing.GetMilliseconds()));
		StatusClear();
		return maxon::OK;
	}
	maxon::Result<void> PMXModel::FromFileImportOneModel()
	{
		iferr_scope_handler{
#ifdef _DEBUG
		MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
			return err;
		};
		doc = GetActiveDocument();
		if (doc == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
			return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
		}
		Filename fn;
		this->LoadFromFile(fn) iferr_return;
		maxon::TimeValue timing = maxon::TimeValue::GetTime();
		String path = fn.GetString();
		path.Delete(path.GetLength() - fn.GetFileString().GetLength(), fn.GetFileString().GetLength());
		Int insideCount = 0;
		m_model_root = BaseObject::Alloc(ID_O_MMD_MODEL);
		if (m_model_root == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		m_model_root->SetName(this->m_model_info.model_name_local);
		OMMDModel* ModelRootData = m_model_root->GetNodeData<OMMDModel>();
		if (!ModelRootData->CreateRoot())
			return(maxon::Error());
		doc->InsertObject(m_model_root, nullptr, nullptr);
		m_model_root->SetParameter(DescID(ID_BASELIST_NAME), this->m_model_info.model_name_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(PMX_VERSION), this->m_model_info.version, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(MODEL_NAME_LOCAL), this->m_model_info.model_name_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(MODEL_NAME_UNIVERSAL), this->m_model_info.model_name_universal, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(COMMENTS_LOCAL), this->m_model_info.comments_local, DESCFLAGS_SET::NONE);
		m_model_root->SetParameter(DescID(COMMENTS_UNIVERSAL), this->m_model_info.comments_universal, DESCFLAGS_SET::NONE);
		if (this->import_settings.import_bone)
		{
			m_bone_root = ModelRootData->GetRootObject(OMMDModel_Root_type::BoneRoot);
			if (m_bone_root == nullptr)
			{
				m_bone_root = BaseObject::Alloc(Onull);
				if (m_bone_root == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				m_bone_root->SetName("Bones"_s);
				doc->InsertObject(m_bone_root, m_model_root, nullptr);
			}
		}
		PolygonObject* model = nullptr;
		PointObject* model_point_obj = nullptr;
		Vector* model_points;
		PolygonObject* model_polygon_obj = nullptr;
		CPolygon* model_polygon;
		BaseSelect* select = nullptr;
		Int32		select_end = 0;
		const Int32	vertex_data_count = this->m_model_data_count.vertex_data_count;
		const Int32	surface_data_count = this->m_model_data_count.surface_data_count;
		if (this->import_settings.import_polygon)
		{
			model = PolygonObject::Alloc(vertex_data_count, surface_data_count);
			if (model == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			model->SetName("Mesh"_s);
			model_point_obj = ToPoint(model);
			model_points = model_point_obj->GetPointW();
			model_polygon_obj = ToPoly(model);
			model_polygon = model_polygon_obj->GetPolygonW();
		}
		CAWeightTag* weight_tag = nullptr;
		if (this->import_settings.import_weights)
		{
			weight_tag = CAWeightTag::Alloc();
			if (weight_tag == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			model->InsertTag(weight_tag);
		}
		if (this->import_settings.import_bone)
			ImportBone(weight_tag)iferr_return;
		if (this->import_settings.import_polygon)
		{
			maxon::HashMap<Int32, maxon::UniqueRef<maxon::HashMap<Int32, Float32>>> weight_data_map;
			if (this->import_settings.import_weights) {
				for (Int32 vertex_index = 0; vertex_index < vertex_data_count; vertex_index++) {
					PMXVertexData& vertex_data_ = this->m_vertex_data[vertex_index];
					switch (vertex_data_.weight_deform_type)
					{
					case 0:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						weight_data->Insert(static_cast<PMXWeight_BDEF1*>(vertex_data_.weight_deform)->bone, 1.0f)iferr_return;
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 1:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						auto* weight_deform = static_cast<PMXWeight_BDEF2*>(vertex_data_.weight_deform);
						for (Int32 i = 0; i < 2; i++) {
							Int32& weight_bone_index = weight_deform->bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								if (i == 0) {
									weight_data_ptr->GetValue() += weight_deform->weight;
								}
								else {
									weight_data_ptr->GetValue() += 1.f - weight_deform->weight;
								}
							}
							else {
								if (i == 0) {
									weight_data->Insert(weight_bone_index, weight_deform->weight)iferr_return;
								}
								else {
									weight_data->Insert(weight_bone_index, 1.f - weight_deform->weight)iferr_return;
								}
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 2:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						auto* weight_deform = static_cast<PMXWeight_BDEF4*>(vertex_data_.weight_deform);
						for (Int32 i = 0; i < 4; i++) {
							Int32& weight_bone_index = weight_deform->bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								weight_data_ptr->GetValue() += weight_deform->weight[i];
							}
							else {
								weight_data->Insert(weight_bone_index, weight_deform->weight[i])iferr_return;
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 3:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						auto* weight_deform = static_cast<PMXWeight_SDEF*>(vertex_data_.weight_deform);
						for (Int32 i = 0; i < 2; i++) {
							Int32& weight_bone_index = weight_deform->bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								if (i == 0) {
									weight_data_ptr->GetValue() += weight_deform->weight;
								}
								else {
									weight_data_ptr->GetValue() += 1.f - weight_deform->weight;
								}
							}
							else {
								if (i == 0) {
									weight_data->Insert(weight_bone_index, weight_deform->weight)iferr_return;
								}
								else {
									weight_data->Insert(weight_bone_index, 1.f - weight_deform->weight)iferr_return;
								}
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 4:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						auto* weight_deform = static_cast<PMXWeight_QDEF*>(vertex_data_.weight_deform);
						for (Int32 i = 0; i < 4; i++) {
							Int32& weight_bone_index = weight_deform->bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								weight_data_ptr->GetValue() += weight_deform->weight[i];
							}
							else {
								weight_data->Insert(weight_bone_index, weight_deform->weight[i])iferr_return;
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					}
				}
			}
			insideCount = 0;
			maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, vertex_data_count, [](LocalData& context)
				{
					context.localCount = 0;
				}, [&vertex_data_count, this, &model_points, &weight_tag, &weight_data_map](const Int32 vertex_index, LocalData& context)->maxon::Result<void>
				{
					PMXVertexData& vertex_data_ = this->m_vertex_data[vertex_index];
					g_spinlock.Lock();
					model_points[vertex_index] = Vector(vertex_data_.position * this->import_settings.position_multiple);
					g_spinlock.Unlock();
					if (this->import_settings.import_weights)
					{
						auto weight_data_ptr = weight_data_map.Find(vertex_index);
						if (weight_data_ptr) {
							auto& weight_data = weight_data_ptr->GetValue();
							for (auto& i : weight_data->GetKeys()) {
								auto weight_ptr = weight_data->Find(i);
								if (weight_ptr) {
									if (!weight_tag->SetWeight(i, vertex_index, weight_ptr->GetValue())) {
										return maxon::Error();
									}
								}
							}
						}
					}
					context.localCount++;
					if (GeIsMainThread())
					{
						StatusSetSpin();
					}
					return(maxon::OK);
				}, [&insideCount, &vertex_data_count](LocalData& context)
				{
					insideCount += context.localCount;
					if (GeIsMainThread())
						StatusSetText("Import vertex " + String::IntToString(insideCount) + " of " + String::IntToString(vertex_data_count));
				}) iferr_return;

			model_point_obj->Message(MSG_UPDATE);
			NormalTag* normal_tag = nullptr;
			NormalHandle	normal_handle;
			if (this->import_settings.import_normal)
			{
				normal_tag = NormalTag::Alloc(this->m_model_data_count.surface_data_count);
				if (normal_tag == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				normal_handle = normal_tag->GetDataAddressW();
				model->InsertTag(normal_tag);
			}
			UVWTag* uvw_tag = nullptr;
			UVWHandle	uvw_handle;
			if (this->import_settings.import_uv)
			{
				uvw_tag = UVWTag::Alloc(this->m_model_data_count.surface_data_count);
				if (uvw_tag == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				uvw_handle = uvw_tag->GetDataAddressW();
				model->InsertTag(uvw_tag);
			}
			insideCount = 0;
			maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, surface_data_count, [](LocalData& context)
				{
					context.localCount = 0;
				}, [this, &model_polygon, &surface_data_count, &normal_handle, &uvw_handle](const Int32 surface_index, LocalData& context)->maxon::Result<void>
				{
					iferr_scope_handler{
						MessageDialog(err.ToString(nullptr));
						return err;
					};
					CPolygon & surface = this->m_surface_data[surface_index];
					PMXVertexData & vertex0 = this->m_vertex_data[surface.a];
					PMXVertexData & vertex1 = this->m_vertex_data[surface.b];
					PMXVertexData & vertex2 = this->m_vertex_data[surface.c];
					g_spinlock.Lock();
					model_polygon[surface_index] = CPolygon(surface.a, surface.b, surface.c);
					g_spinlock.Unlock();
					if (this->import_settings.import_normal)
					{
						Vector normal0 = (Vector)vertex0.normal;
						Vector normal1 = (Vector)vertex1.normal;
						Vector normal2 = (Vector)vertex2.normal;
						Vector normal3(0, 0, 0);
						normal0.Normalize();
						normal1.Normalize();
						normal2.Normalize();
						normal3.Normalize();
						g_spinlock.Lock();
						NormalTag::Set(normal_handle, surface_index, NormalStruct(normal0, normal1, normal2, normal3));
						g_spinlock.Unlock();
					}
					if (this->import_settings.import_uv)
					{
						g_spinlock.Lock();
						UVWTag::Set(uvw_handle, surface_index, UVWStruct(Vector(vertex0.UV.x, vertex0.UV.y, 0), Vector(vertex1.UV.x, vertex1.UV.y, 0), Vector(vertex2.UV.x, vertex2.UV.y, 0)));
						g_spinlock.Unlock();
					}
					context.localCount++;
					if (GeIsMainThread())
					{
						StatusSetSpin();
					}
					return(maxon::OK);
				}, [&insideCount, &surface_data_count](LocalData& context)
				{
					insideCount += context.localCount;
					if (GeIsMainThread())
						StatusSetText("Import surface " + String::IntToString(insideCount) + " of " + String::IntToString(surface_data_count));
				}) iferr_return;
			model->SetPhong(true, true, 0.7853982);
			m_mesh_root = ModelRootData->GetRootObject(OMMDModel_Root_type::MeshRoot);
			if (m_mesh_root != nullptr)
			{
				doc->InsertObject(model, m_mesh_root, nullptr);
			}
			else {
				doc->InsertObject(model, m_model_root, nullptr);
			}
			if (this->import_settings.import_weights)
			{
				BaseObject* morphdeformer = BaseObject::Alloc(Oskin);
				if (morphdeformer == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				doc->InsertObject(morphdeformer, model, nullptr);
			}
			EventAdd();
			doc->SetMode(Mpolygons);
			select = model->GetPolygonS();
		}
		if (this->import_settings.import_expression)
		{
			maxon::HashMap<BaseObject*, CAPoseMorphTag*> bone_tag_map;
			/* Initialization morph tag. */
			CAPoseMorphTag* morph_tag = CAPoseMorphTag::Alloc();
			if (morph_tag == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			model->InsertTag(morph_tag);
			morph_tag->InitMorphs();
			if (this->m_model_info.have_vertex_morph)
			{
				morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
			}
			if (this->m_model_info.have_UV_morph)
			{
				morph_tag->SetParameter(ID_CA_POSE_UV, true, DESCFLAGS_SET::NONE);
			}
			/* Add base morph to the tag. */
			morph_tag->ExitEdit(doc, true);
			CAMorph* base_morph = morph_tag->AddMorph();
			if (base_morph == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			base_morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
			morph_tag->UpdateMorphs();
			morph_tag->Message(MSG_UPDATE);

			/* Get the morph data count. */
			Int32 morph_data_count = this->m_model_data_count.morph_data_count;

			for (Int32 morph_index = 0; morph_index < morph_data_count; morph_index++)
			{
				StatusSetText("Import morphs..."_s);
				StatusSetBar(morph_index * 100 / morph_data_count);
				PMXMorphData& morph_data = this->m_morph_data[morph_index];
				switch (morph_data.morph_type)
				{
					// 顶点表情
				case PMXMorphData::VERTEX: {
					morph_data.offset_data;
					Int32					offset_count = morph_data.offset_count;
					morph_tag->ExitEdit(doc, true);
					CAMorph* morph = morph_tag->AddMorph();
					if (morph == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					morph->SetName(morph_data.morph_name_local);
					morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
					CAMorphNode* morph_node;
					morph_node = morph->GetFirst();
					while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node != nullptr)
					{
						morph_node = morph_node->GetNext();
					}
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
					maxon::ParallelFor::Dynamic(0, offset_count, [&morph_data, &morph_node, this](const Int32 pointIndex)
						{
							mmd::PMXMorph_Vertex* vertex_morph_data = static_cast<PMXMorph_Vertex*>(morph_data.offset_data[pointIndex]);
							morph_node->SetPoint(vertex_morph_data->vertex_index,
								Vector(vertex_morph_data->translation * this->import_settings.position_multiple));
						});
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
					break;
				}
					  // 骨骼表情
				case PMXMorphData::BONE: {
					if (this->import_settings.import_bone)
					{
						// 表情数据储存的变换信息个数
						Int32 offset_count = morph_data.offset_count;
						maxon::ParallelFor::Dynamic(0, offset_count, [this, &bone_tag_map, &morph_data](const Int32 offset_count_index)->maxon::Result<void>
							{
								iferr_scope_handler{
									MessageDialog(err.ToString(nullptr));
									return err;
								};
								mmd::PMXMorph_Bone * bone_morph_data = static_cast<PMXMorph_Bone*>(morph_data.offset_data[offset_count_index]);
								auto bone_ptr = bone_map.Find(bone_morph_data->bone_index);
								if (bone_ptr == nullptr)
									return maxon::OK;
								BaseObject* bone = bone_ptr->GetValue();
								if (bone == nullptr)
									return maxon::OK;
								BaseTag* pmx_bone_tag = bone->GetTag(ID_T_MMD_BONE);
								if (pmx_bone_tag == nullptr)
									return maxon::OK;
								TMMDBone* pmx_bone_tag_data = pmx_bone_tag->GetNodeData<TMMDBone>();
								Int32 bone_morph_data_index = pmx_bone_tag_data->AddBondMorph(morph_data.morph_name_local);
								if (bone_morph_data_index == -1)
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								if (!pmx_bone_tag_data->SetBondMorphTranslation(bone_morph_data_index, Vector(bone_morph_data->translation * this->import_settings.position_multiple)))
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								if (!pmx_bone_tag_data->SetBondMorphRotation(bone_morph_data_index, Vector(bone_morph_data->rotation)))
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								return maxon::OK;
							}) iferr_return;
					}
					break;
				}
					  // UV表情
				case PMXMorphData::UV:
				{

					maxon::HashMap<Int32, Vector>		vertex_floats_map;
					for (PMXMorph* data : morph_data.offset_data)
					{
						PMXMorph_UV* UV_morph_data = static_cast<PMXMorph_UV*>(data);
						vertex_floats_map.Insert(UV_morph_data->vertex_index, Vector(UV_morph_data->floats.x, UV_morph_data->floats.y, 0)) iferr_return;
					}
					morph_tag->ExitEdit(doc, true);
					CAMorph* morph = morph_tag->AddMorph();
					if (morph == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					morph->SetName(morph_data.morph_name_local);
					morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
					CAMorphNode* morph_node = morph->GetFirst();
					while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::UV) && morph_node != nullptr)
					{
						morph_node = morph_node->GetNext();
					}
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
					maxon::ParallelFor::Dynamic(0, surface_data_count, [&morph_node, this, &vertex_floats_map](const Int32 surface_index)
						{
							CPolygon& surface = this->m_surface_data[surface_index];
							UVWStruct uvw;
							morph_node->GetUV(0, surface_index, uvw);
							auto vertex_a_ptr = vertex_floats_map.Find(surface.a);
							if (vertex_a_ptr != nullptr)
							{
								uvw.c = vertex_a_ptr->GetValue();
							}
							auto vertex_b_ptr = vertex_floats_map.Find(surface.b);
							if (vertex_b_ptr != nullptr)
							{
								uvw.b = vertex_b_ptr->GetValue();
							}
							auto vertex_c_ptr = vertex_floats_map.Find(surface.c);
							if (vertex_c_ptr != nullptr)
							{
								uvw.a = vertex_c_ptr->GetValue();
							}
							morph_node->SetUV(0, surface_index, uvw);
						});
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
					break;
				}
				default:
					break;
				}
			}
			bone_tag_map.Reset();
		}
		bone_map.Reset();
		if (this->import_settings.import_material)
		{
			Int32 material_data_count = this->m_model_data_count.material_data_count;
			for (Int32 material_index = 0; material_index < material_data_count; material_index++)
			{
				StatusSetText("Import materials..."_s);
				StatusSetBar(material_index * 100 / material_data_count);
				TextureTag* texture_tag = nullptr;
				if (this->import_settings.import_polygon)
				{
					PMXMaterialData& material_data = this->m_material_data[material_index];
					doc->SetSelection(model);
					select->SelectAll(select_end, select_end + material_data.surface_count - 1);
					select_end += material_data.surface_count;
					CallCommand(12552);
					doc->GetActiveTag()->SetName(material_data.material_name_local);
					texture_tag = static_cast<TextureTag*>(model->MakeTag(Ttexture, doc->GetActiveTag()));
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
				}
				this->ImportMaterial(path, material_index, texture_tag)iferr_return;
			}
		}
		EventAdd();
		if (this->import_settings.import_polygon)
		{
			doc->SetSelection(model);
			ModelingCommandData cd;
			cd.doc = doc;
			cd.op = model;
			cd.mode = MODELINGCOMMANDMODE::POLYGONSELECTION;
			if (!SendModelingCommand(MCOMMAND_SELECTALL, cd))
				return maxon::Error();
			if (!SendModelingCommand(MCOMMAND_SELECTPOLYTOPOINT, cd))
				return maxon::Error();
			cd.mode = MODELINGCOMMANDMODE::POINTSELECTION;
			if (!SendModelingCommand(MCOMMAND_SELECTINVERSE, cd))
				return maxon::Error();
			if (!SendModelingCommand(MCOMMAND_DELETE, cd))
				return maxon::Error();
		}
		if (this->import_settings.import_weights)
		{
			CAWeightMgr::NormalizeWeights(doc);
#if API_VERSION >= 21000
			weight_tag->SetBindPose(doc, false);
#else		
			DescriptionCommand dc;
			dc._descId = DescID(ID_CA_WEIGHT_TAG_SET);
			weight_tag->Message(MSG_DESCRIPTION_COMMAND, &dc);
#endif
		}

		doc->SetMode(Mmodel);
		doc->SetSelection(nullptr);
		timing.Stop();
		GePrint(String::FloatToString(timing.GetMilliseconds()));
		StatusClear();
		return maxon::OK;
	}
	maxon::Result<void> PMXModel::FromDocumentExportModel(PMX_Model_export_settings& settings)
	{
		return(maxon::OK);
	}
}