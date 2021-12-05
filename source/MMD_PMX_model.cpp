#include "MMD_PMX_model.h"
#undef GetObject


inline Bool mmd::PMXModel::ReadText(BaseFile* const file, Char& text_encoding, String& out_string)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		out_string = String();
		return false;
	};
	Int32 text_len; /* text字符串最大长度 */
	file->ReadInt32(&text_len);
	if (text_encoding == 0)
	{
		maxon::AutoMem<maxon::Utf16Char> tmp_wStr = NewMemClear(maxon::Utf16Char, text_len + 1) iferr_return;
		file->ReadBytes(tmp_wStr, text_len);
		out_string = String(tmp_wStr);
		return true;
	}
	else if (text_encoding == 1)
	{
		maxon::AutoMem<maxon::Char> tmp_Str = NewMemClear(maxon::Char, text_len + 1) iferr_return;
		file->ReadBytes(tmp_Str, text_len);
		out_string.SetCString(tmp_Str, -1, STRINGENCODING::UTF8);
		return true;
	}
	out_string = String();
	return false;
}


inline Int32 mmd::PMXModel::ReadIndex(BaseFile* const file, Char& index_size)
{
	switch (index_size) /* 3种长度不同的Index */
	{
	case 1:
	{
		Char index;
		file->ReadChar(&index);
		return(index);
	}
	case 2:
	{
		Int16 index;
		file->ReadInt16(&index);
		return(index);
	}
	case 4:
	{
		Int32 index;
		file->ReadInt32(&index);
		return(index);
	}
	default:
		return(-1);
	}
}


inline UInt32 mmd::PMXModel::ReadUIndex(BaseFile* const file, Char& index_size)
{
	switch (index_size) /* 3种长度不同的Index */
	{
	case 1:
	{
		UChar index;
		file->ReadUChar(&index);
		return(index);
	}
	case 2:
	{
		UInt16 index;
		file->ReadUInt16(&index);
		return(index);
	}
	case 4:
	{
		UInt32 index;
		file->ReadUInt32(&index);
		return(index);
	}
	default:
		return(0);
	}
}


maxon::Result<void> mmd::PMXModel::LoadFromFile(BaseFile* const file)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return err;
	};
	PMX_Model_information	model_info_;
	PMX_Data_count		model_data_count_;
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
	if (!ReadText(file, model_info_.text_encoding,model_info_.model_name_local))
		return(maxon::Error());
	if (!ReadText(file, model_info_.text_encoding,model_info_.model_name_universal))
	 return(maxon::Error());
	if (!ReadText(file, model_info_.text_encoding,model_info_.comments_local))
	 return(maxon::Error());
	if (!ReadText(file, model_info_.text_encoding,model_info_.comments_universal))
	 return(maxon::Error());
	this->model_info = model_info_;
	if (!file->ReadInt32(&(model_data_count_.vertex_data_count)))
		return(maxon::Error());
	for (Int32 i = 0; i < model_data_count_.vertex_data_count; i++)
	{
		PMX_Vertex_Data* vertex_data_ = NewObj(PMX_Vertex_Data) iferr_return;
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
		{
			BDEF1 weight;
			weight.bone = ReadIndex(file, model_info_.bone_index_size);
			vertex_data_->weight_deform_B1 = weight;
			break;
		}
		case 1:
		{
			BDEF2 weight;
			weight.bone[0] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[1] = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight)))
				return(maxon::Error());
			vertex_data_->weight_deform_B2 = weight;
			break;
		}
		case 2:
		{
			BDEF4 weight;
			weight.bone[0] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[1] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[2] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[3] = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight[0])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[1])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[2])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[3])))
				return(maxon::Error());
			vertex_data_->weight_deform_B4 = weight;
			break;
		}
		case 3:
		{
			SDEF weight;
			weight.bone[0] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[1] = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight)))
				return(maxon::Error());
			if (!file->ReadVector32(&(weight.R0)))
				return(maxon::Error());
			if (!file->ReadVector32(&(weight.R1)))
				return(maxon::Error());
			if (!file->ReadVector32(&(weight.C)))
				return(maxon::Error());
			vertex_data_->weight_deform_S = weight;
			break;
		}
		case 4:
		{
			QDEF weight;
			weight.bone[0] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[1] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[2] = ReadIndex(file, model_info_.bone_index_size);
			weight.bone[3] = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight[0])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[1])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[2])))
				return(maxon::Error());
			if (!file->ReadFloat32(&(weight.weight[3])))
				return(maxon::Error());
			vertex_data_->weight_deform_Q = weight;
			break;
		}
		}
		if (!file->ReadFloat32(&(vertex_data_->edge_scale)))
			return(maxon::Error());
		this->vertex_data.AppendPtr(vertex_data_) iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.surface_data_count)))
		return(maxon::Error());
	model_data_count_.surface_data_count /= 3;
	for (Int32 i = 0; i < model_data_count_.surface_data_count; i++)
	{
		CPolygon* surface = NewObj(CPolygon, (Int32)ReadUIndex(file, model_info_.vertex_index_size), (Int32)ReadUIndex(file, model_info_.vertex_index_size), (Int32)ReadUIndex(file, model_info_.vertex_index_size)) iferr_return;
		if (surface == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		this->surface_data.AppendPtr(surface) iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.texture_data_count)))
		return(maxon::Error());
	for (Int32 i = 0; i < model_data_count_.texture_data_count; i++)
	{
		String tmp;
		if (!ReadText(file, model_info_.text_encoding, tmp))
			return(maxon::Error());
		this->texture_data.Append(tmp) iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.material_data_count)))
		return(maxon::Error());
	for (Int32 i = 0; i < model_data_count_.material_data_count; i++)
	{
		PMX_Material_Data* material_data_ = NewObj(PMX_Material_Data) iferr_return;
		if (material_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding,material_data_->material_name_local))
		 return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding,material_data_->material_name_universal))
		 return(maxon::Error());
		if (!file->ReadBytes(&(material_data_->diffuse_colour), sizeof(Vector4d32)))
			return(maxon::Error());
		if (!file->ReadVector32(&(material_data_->specular_colour)))
			return(maxon::Error());
		if (!file->ReadFloat32(&(material_data_->specular_strength)))
			return(maxon::Error());
		if (!file->ReadVector32(&(material_data_->ambient_colour)))
			return(maxon::Error());
		if (!file->ReadBytes(&(material_data_->drawing_flags), sizeof(PMX_Material_Flags)))
			return(maxon::Error());
		if (!file->ReadBytes(&(material_data_->edge_colour), sizeof(Vector4d32)))
			return(maxon::Error());
		if (!file->ReadFloat32(&(material_data_->edge_scale)))
			return(maxon::Error());
		material_data_->texture_index = ReadIndex(file, model_info_.texture_index_size);
		material_data_->environment_index = ReadIndex(file, model_info_.texture_index_size);
		if (!file->ReadChar(&(material_data_->environment_blend_mode)))
			return(maxon::Error());
		if (!file->ReadChar(&(material_data_->toon_reference)))
			return(maxon::Error());
		if (material_data_->toon_reference == 0)
		{
			material_data_->toon_part = ReadIndex(file, model_info_.texture_index_size);
		}
		else if (material_data_->toon_reference == 1)
		{
			if (!file->ReadChar(&(material_data_->toon_internal)))
				return(maxon::Error());
		}
		if (!ReadText(file, model_info_.text_encoding,material_data_->meta_data))
		 return(maxon::Error());
		if (!file->ReadInt32(&(material_data_->surface_count)))
			return(maxon::Error());
		material_data_->surface_count /= 3;
		this->material_data.AppendPtr(material_data_) iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.bone_data_count)))
		return(maxon::Error());
	for (Int32 i = 0; i < model_data_count_.bone_data_count; i++)
	{
		PMX_Bone_Data* bone_data_ = NewObj(PMX_Bone_Data) iferr_return;
		if (bone_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding, bone_data_->bone_name_local))
			return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding, bone_data_->bone_name_universal))
			return(maxon::Error());
		if (!file->ReadVector32(&(bone_data_->position)))
			return(maxon::Error());
		bone_data_->parent_bone_index = ReadIndex(file, model_info_.bone_index_size);
		if (!file->ReadInt32(&(bone_data_->layer)))
			return(maxon::Error());
		if (!file->ReadBytes(&(bone_data_->bone_flags), sizeof(PMX_Bone_Flags)))
			return(maxon::Error());
		if (bone_data_->bone_flags.indexed_tail_position == 0)
		{
			if (!file->ReadVector32(&(bone_data_->tail_position)))
				return(maxon::Error());
		}
		else if (bone_data_->bone_flags.indexed_tail_position == 1)
		{
			bone_data_->tail_index = ReadIndex(file, model_info_.bone_index_size);
		}
		if (bone_data_->bone_flags.Inherit_rotation || bone_data_->bone_flags.Inherit_translation)
		{
			bone_data_->inherit_bone_parent_index = ReadIndex(file, model_info_.bone_index_size);
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
			if (!file->Seek(model_info_.bone_index_size))
				return(maxon::Error());
		}
		if (bone_data_->bone_flags.IK)
		{
			bone_data_->IK_target_index = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadInt32(&(bone_data_->IK_loop_count)))
				return(maxon::Error());
			if (!file->ReadFloat32(&(bone_data_->IK_limit_radian)))
				return(maxon::Error());
			if (!file->ReadInt32(&(bone_data_->IK_link_count)))
				return(maxon::Error());
			for (Int32 j = 0; j < bone_data_->IK_link_count; j++)
			{
				PMX_IK_links* IK_link = NewObj(PMX_IK_links) iferr_return;
				if (IK_link == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				IK_link->bone_index = ReadIndex(file, model_info_.bone_index_size);
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
		this->bone_data.AppendPtr(bone_data_) iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.morph_data_count)))
		return(maxon::Error());
	for (Int32 i = 0; i < model_data_count_.morph_data_count; i++)
	{
		PMX_Morph_Data* morph_data_ = NewObj(PMX_Morph_Data) iferr_return;
		if (morph_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding,morph_data_->morph_name_local))
			return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding,morph_data_->morph_name_universal))
		 return(maxon::Error());
		if (!file->ReadChar(&(morph_data_->panel_type)))
			return(maxon::Error());
		if (!file->ReadChar(&(morph_data_->morph_type)))
			return(maxon::Error());
		void* offset_data_ = nullptr;
		switch (morph_data_->morph_type)
		{
		case 0:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_group>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 1:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_vertex>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			model_info.have_vertex_morph = true;
			break;
		}
		case 2:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_bone>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 3:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_UV>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			model_info.have_UV_morph = true;
			break;
		}
		case 8:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_material>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 9:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_flip>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 10:
		{
			offset_data_ = NewObj(maxon::PointerArray<PMX_Morph_impulse>) iferr_return;
			if (offset_data_ == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		default:
			break;
		}
		if (!file->ReadInt32(&(morph_data_->offset_count)))
			return(maxon::Error());
		for (Int32 j = 0; j < morph_data_->offset_count; j++)
		{
			switch (morph_data_->morph_type)
			{
			case 0:
			{
				maxon::PointerArray<PMX_Morph_group>* offset_data_groups = (maxon::PointerArray<PMX_Morph_group>*)offset_data_;
				PMX_Morph_group* offset_data_group_ = NewObj(PMX_Morph_group) iferr_return;
				if (offset_data_group_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_group_->morph_index = ReadIndex(file, model_info_.morph_index_size);
				if (!file->ReadFloat32(&(offset_data_group_->influence)))
					return(maxon::Error());
				offset_data_groups->AppendPtr(offset_data_group_) iferr_return;
				break;
			}
			case 1:
			{
				maxon::PointerArray<PMX_Morph_vertex>* offset_data_vertexs = (maxon::PointerArray<PMX_Morph_vertex>*)offset_data_;
				PMX_Morph_vertex* offset_data_vertex_ = NewObj(PMX_Morph_vertex) iferr_return;
				if (offset_data_vertex_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_vertex_->vertex_index = ReadUIndex(file, model_info_.vertex_index_size);
				if (!file->ReadVector32(&(offset_data_vertex_->translation)))
					return(maxon::Error());
				offset_data_vertexs->AppendPtr(offset_data_vertex_) iferr_return;
				break;
			}
			case 2:
			{
				maxon::PointerArray<PMX_Morph_bone>* offset_data_bones = (maxon::PointerArray<PMX_Morph_bone>*)offset_data_;
				PMX_Morph_bone* offset_data_bone_ = NewObj(PMX_Morph_bone) iferr_return;
				if (offset_data_bone_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_bone_->bone_index = ReadIndex(file, model_info_.bone_index_size);
				if (!file->ReadVector32(&(offset_data_bone_->translation)))
					return(maxon::Error());
				Vector4d32 q_rotation;
				if (!file->ReadBytes(&q_rotation, sizeof(Vector4d32)))
					return(maxon::Error());
				Vector32 rotation;
				rotation.x = -maxon::ATan2(2 * q_rotation.y * q_rotation.w + 2 * q_rotation.x * q_rotation.z, 1 - 2 * (q_rotation.x * q_rotation.x + q_rotation.y * q_rotation.y));
				rotation.y = -maxon::ASin(2 * (q_rotation.x * q_rotation.w - q_rotation.y * q_rotation.z));
				rotation.z = -maxon::ATan2(2 * q_rotation.z * q_rotation.w + 2 * q_rotation.x * q_rotation.y, 1 - 2 * (q_rotation.x * q_rotation.x + q_rotation.z * q_rotation.z));
				offset_data_bone_->rotation = rotation;
				offset_data_bones->AppendPtr(offset_data_bone_) iferr_return;
				break;
			}
			case 3:
			{
				maxon::PointerArray<PMX_Morph_UV>* offset_data_UVs = (maxon::PointerArray<PMX_Morph_UV>*)offset_data_;
				PMX_Morph_UV* offset_data_UV_ = NewObj(PMX_Morph_UV) iferr_return;
				if (offset_data_UV_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_UV_->vertex_index = ReadIndex(file, model_info_.vertex_index_size);
				if (!file->ReadBytes(&(offset_data_UV_->floats), sizeof(Vector4d32)))
					return(maxon::Error());
				offset_data_UVs->AppendPtr(offset_data_UV_) iferr_return;
				break;
			}
			case 4:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
					return(maxon::Error());
				break;
			}
			case 5:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
					return(maxon::Error());
				break;
			}
			case 6:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
					return(maxon::Error());
				break;
			}
			case 7:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(Vector4d32)))
					return(maxon::Error());
				break;
			}
			case 8:
			{
				maxon::PointerArray<PMX_Morph_material>* offset_data_materials = (maxon::PointerArray<PMX_Morph_material>*)offset_data_;
				PMX_Morph_material* offset_data_material_ = NewObj(PMX_Morph_material) iferr_return;
				if (offset_data_material_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_material_->material_index = ReadIndex(file, model_info_.material_index_size);
				if (!file->ReadChar(&(offset_data_material_->blend_mode)))
					return(maxon::Error());
				if (!file->ReadBytes(&(offset_data_material_->diffuse), sizeof(Vector4d32)))
					return(maxon::Error());
				if (!file->ReadVector32(&(offset_data_material_->specular)))
					return(maxon::Error());
				if (!file->ReadFloat32(&(offset_data_material_->specularity)))
					return(maxon::Error());
				if (!file->ReadVector32(&(offset_data_material_->ambient)))
					return(maxon::Error());
				if (!file->ReadBytes(&(offset_data_material_->edge_colour), sizeof(Vector4d32)))
					return(maxon::Error());
				if (!file->ReadFloat32(&(offset_data_material_->edge_size)))
					return(maxon::Error());
				if (!file->ReadBytes(&(offset_data_material_->texture_tint), sizeof(Vector4d32)))
					return(maxon::Error());
				if (!file->ReadBytes(&(offset_data_material_->environment_tint), sizeof(Vector4d32)))
					return(maxon::Error());
				if (!file->ReadBytes(&(offset_data_material_->toon_tint), sizeof(Vector4d32)))
					return(maxon::Error());
				offset_data_materials->AppendPtr(offset_data_material_) iferr_return;
				break;
			}
			case 9:
			{
				maxon::PointerArray<PMX_Morph_flip>* offset_data_flips = (maxon::PointerArray<PMX_Morph_flip>*)offset_data_;
				PMX_Morph_flip* offset_data_flip_ = NewObj(PMX_Morph_flip) iferr_return;
				if (offset_data_flip_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_flip_->morph_index = ReadIndex(file, model_info_.morph_index_size);
				if (!file->ReadFloat32(&(offset_data_flip_->influence)))
					return(maxon::Error());
				offset_data_flips->AppendPtr(offset_data_flip_) iferr_return;
				break;
			}
			case 10:
			{
				maxon::PointerArray<PMX_Morph_impulse>* offset_data_impulses = (maxon::PointerArray<PMX_Morph_impulse>*)offset_data_;
				PMX_Morph_impulse* offset_data_impulse_ = NewObj(PMX_Morph_impulse) iferr_return;
				if (offset_data_impulse_ == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				offset_data_impulse_->rigid_body_index = ReadIndex(file, model_info_.rigidbody_index_size);
				if (!file->ReadChar(&(offset_data_impulse_->local_flag)))
					return(maxon::Error());
				if (!file->ReadVector32(&(offset_data_impulse_->movement_speed)))
					return(maxon::Error());
				if (!file->ReadVector32(&(offset_data_impulse_->rotation_torque)))
					return(maxon::Error());
				offset_data_impulses->AppendPtr(offset_data_impulse_) iferr_return;
				break;
			}
			default:
				break;
			}
		}
		this->morph_data.AppendPtr(morph_data_) iferr_return;
	}
	file->ReadInt32(&(model_data_count_.display_data_count));
	for (Int32 i = 0; i < model_data_count_.display_data_count; i++)
	{
		PMX_Display_Data* display_data_ = NewObj(PMX_Display_Data) iferr_return;
		if (display_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding,display_data_->display_name_local))
		 return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding,display_data_->display_name_universal))
		 return(maxon::Error());
		if (!file->ReadChar(&(display_data_->special_flag)))
			return(maxon::Error());
		if (!file->ReadInt32(&(display_data_->frame_count)))
			return(maxon::Error());
		for (Int32 j = 0; j < display_data_->frame_count; j++)
		{
			PMX_Frame_data* Frame = NewObj(PMX_Frame_data) iferr_return;
			if (!file->ReadChar(&(Frame->frame_type)))
				return(maxon::Error());
			if (Frame->frame_type == 1)           /* 1:索引 - 变形 */
			{
				Frame->frame_data = ReadIndex(file, model_info_.morph_index_size);
			}
			else if (Frame->frame_type == 0)     /* 0:索引-骨骼 */
			{
				Frame->frame_data = ReadIndex(file, model_info_.bone_index_size);
			}
			display_data_->Frames.AppendPtr(Frame) iferr_return;
		}
		this->display_data.AppendPtr(display_data_) iferr_return;
	}
	file->ReadInt32(&(model_data_count_.rigid_body_data_count));
	for (Int32 i = 0; i < model_data_count_.rigid_body_data_count; i++)
	{
		PMX_Rigid_Body_Data* rigid_body_data_ = NewObj(PMX_Rigid_Body_Data) iferr_return;
		if (rigid_body_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding,rigid_body_data_->rigid_body_name_local))
		 return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding,rigid_body_data_->rigid_body_name_universal))
		 return(maxon::Error());
		rigid_body_data_->related_bone_index = ReadIndex(file, model_info_.bone_index_size);
		if (!file->ReadChar(&(rigid_body_data_->group_id)))
			return(maxon::Error());
		if (!file->ReadBytes(&(rigid_body_data_->non_collision_group), sizeof(PMX_Rigid_body_non_collision_group)))
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
		this->rigid_body_data.AppendPtr(rigid_body_data_) iferr_return;
	}
	file->ReadInt32(&(model_data_count_.joint_data_count));
	for (Int32 i = 0; i < model_data_count_.joint_data_count; i++)
	{
		PMX_Joint_Data* joint_data_ = NewObj(PMX_Joint_Data) iferr_return;
		if (joint_data_ == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (!ReadText(file, model_info_.text_encoding, joint_data_->joint_name_local))
			return(maxon::Error());
		if (!ReadText(file, model_info_.text_encoding, joint_data_->joint_name_universal))
			return(maxon::Error());
		if (!file->ReadChar(&(joint_data_->joint_type)))
			return(maxon::Error());
		joint_data_->rigid_body_index_A = ReadIndex(file, model_info_.rigidbody_index_size);
		joint_data_->rigid_body_index_B = ReadIndex(file, model_info_.rigidbody_index_size);
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
		this->joint_data.AppendPtr(joint_data_) iferr_return;
	}
	this->model_data_count = model_data_count_;
	return(maxon::OK);
}


maxon::Result<void> mmd::PMXModel::SaveToFile(BaseFile* const file)
{
	return(maxon::OK);
}

maxon::Result<void> mmd::PMXModel::FromFileImportModel(PMX_Model_import_settings& settings)
{
	iferr_scope_handler{
		MessageDialog(err.ToString(nullptr));
		return err;
	};
	Filename		fn;
	AutoAlloc<BaseFile>	file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
	{
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	if (file == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR)));
	}
	if (!(fn.CheckSuffix("pmx"_s) || (fn.CheckSuffix("PMX"_s))))
	{
		GePrint("Is not a PMX file!"_s);
		MessageDialog("Is not a PMX file!"_s);
		return(maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, "not a PMX file"_s));
	}
	
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	this->LoadFromFile(file) iferr_return;
	String path = fn.GetString();
	path.Delete(path.GetLength() - fn.GetFileString().GetLength(), fn.GetFileString().GetLength());
	file->Close();

	Int insideCount = 0;
	if (settings.import_multipart)
	{
		NameConversion	name_conversion;
		BaseObject* ModelRoot = BaseObject::Alloc(ID_O_MMD_MODEL);
		if (ModelRoot == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		if (settings.import_english)
		{
			ModelRoot->SetName("Model"_s);
		}
		else {
			ModelRoot->SetName(this->model_info.model_name_local);
		}
		OMMDModel* ModelRootData = ModelRoot->GetNodeData<OMMDModel>();
		if (!ModelRootData->CreateRoot())
			return(maxon::Error());
		doc->InsertObject(ModelRoot, nullptr, nullptr);
		BaseObject* MesheRoot = nullptr;
		if (settings.import_polygon)
		{
			MesheRoot = ModelRootData->GetRootObject(OMMDModel_Root_type::MeshRoot);
			if (MesheRoot == nullptr)
			{
				MesheRoot = BaseObject::Alloc(Onull);
				if (MesheRoot == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				MesheRoot->SetName("Meshes"_s);
				doc->InsertObject(MesheRoot, ModelRoot, nullptr);
			}
		}
		BaseObject* BoneRoot = nullptr;
		if (settings.import_bone)
		{
			BoneRoot = ModelRootData->GetRootObject(OMMDModel_Root_type::BoneRoot);
			if (BoneRoot == nullptr)
			{
				BoneRoot = BaseObject::Alloc(Onull);
				if (BoneRoot == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				BoneRoot->SetName("Bones"_s);
				doc->InsertObject(BoneRoot, ModelRoot, nullptr);
			}
		}
		ModelRoot->SetParameter(DescID(ID_BASELIST_NAME), this->model_info.model_name_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(PMX_VERSION), this->model_info.version, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(MODEL_NAME_LOCAL), this->model_info.model_name_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(MODEL_NAME_UNIVERSAL), this->model_info.model_name_universal, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(COMMENTS_LOCAL), this->model_info.comments_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(COMMENTS_UNIVERSAL), this->model_info.comments_universal, DESCFLAGS_SET::NONE);
		maxon::HashMap<Int32, BaseObject*> bone_map;
		if (settings.import_bone)
		{
			const Int32 kBoneDataCount = this->model_data_count.bone_data_count;
			/*Create a bone object and initialize the English name conversion.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
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
			if (settings.import_english_check)
			{
				name_conversion.CheckUpdata();
			}
			else {
				name_conversion.AutoUpdata();
			}
			/*Sets the parent-child relationship and position of the bone.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
				auto bone_ptr = bone_map.Find(bone_index);
				if (bone_ptr == nullptr)
				{
					return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
				}
				BaseObject* bone = bone_ptr->GetValue();
				if (bone_data_.parent_bone_index == -1)
				{
					bone->SetFrozenPos(Vector(bone_data_.position) * settings.position_multiple);
					doc->InsertObject(bone, BoneRoot, nullptr);
				}
				else {
					bone->SetFrozenPos(Vector(bone_data_.position - this->bone_data[bone_data_.parent_bone_index].position) * settings.position_multiple);
					auto parent_bone_ptr = bone_map.Find(bone_data_.parent_bone_index);
					if (parent_bone_ptr != nullptr)
					{
						doc->InsertObject(bone, parent_bone_ptr->GetValue(), nullptr);
					}
				}
			}	
			EventAdd();
			/*Create tag and import data.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
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
				bone_tag_data->SetRootObject(BoneRoot);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_INDEX), String::IntToString(bone_index), DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ID_BASELIST_NAME), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_LOCAL), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), bone_data_.bone_name_universal, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_IS), settings.import_english, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_POSITION), (Vector)bone_data_.position * settings.position_multiple, DESCFLAGS_SET::NONE);
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
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_TAIL_INDEX), bone_data_.tail_index, DESCFLAGS_SET::NONE);
				}
				else {
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_TAIL_POSITION), (Vector)bone_data_.position * settings.position_multiple, DESCFLAGS_SET::NONE);
				}
				if (bone_data_.bone_flags.Local_coordinate)
				{
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_LOCAL_X), (Vector)bone_data_.bone_local_X, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_LOCAL_Z), (Vector)bone_data_.bone_local_Z, DESCFLAGS_SET::NONE);
				}
				if (bone_data_.bone_flags.Fixed_axis == 1)
				{
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_FIXED_AXIS), (Vector)bone_data_.bone_fixed_axis, DESCFLAGS_SET::NONE);
				}
				if (settings.import_inherit)
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
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
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
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
				}
				if (settings.import_ik)
				{
					if (bone_data_.bone_flags.IK == 1)
					{
						if (bone_data_.IK_links.Begin() != bone_data_.IK_links.End()) {
							BaseObject* IK_beging_bone = bone_map.Find((bone_data_.IK_links.End() - 1)->bone_index)->GetValue();
							if (IK_beging_bone != nullptr) {
								BaseTag* IK_tag = IK_beging_bone->MakeTag(1019561); /* Ik Tag ID : 1019561 */
								if (settings.import_english)
								{
									IK_tag->SetName(bone_data_.bone_name_universal);
								}
								else {
									IK_tag->SetName(bone_data_.bone_name_local);
								}
								/*Sets the rotation handle of the IK pole vector.*/
								if (bone_data_.bone_name_local.Find(L"\u8db3\uff29\uff2b"_s, nullptr)) /*L"\u8db3\uff29\uff2b" is 足IK*/
								{
									BaseObject* IK_beging_bone_up_a = IK_beging_bone->GetUp();
									if (IK_beging_bone_up_a != nullptr) {
										BaseObject* IK_beging_bone_up_b = IK_beging_bone_up_a->GetUp();
										if (IK_beging_bone_up_b != nullptr) {
											BaseObject* polar_vector = BaseObject::Alloc(Onull);
											/*TODO:Localized naming*/
											polar_vector->SetName(bone_data_.bone_name_local + ".Rotating handle");
											polar_vector->SetFrozenPos(IK_beging_bone_up_a->GetFrozenPos() + Vector(0.0, 0.0, -settings.position_multiple));
											doc->InsertObject(polar_vector, IK_beging_bone_up_b, IK_beging_bone_up_a);
											BaseLink* polar_vector_link = BaseLink::Alloc();
											if (polar_vector_link == nullptr)
											{
												GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
												MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
											}
											polar_vector_link->SetLink(polar_vector);
											IK_tag->SetParameter(DescID(ID_CA_IK_TAG_POLE), polar_vector_link, DESCFLAGS_SET::NONE);
										}
									}
								}
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_PREFERRED_WEIGHT), 1, DESCFLAGS_SET::NONE);
								BaseLink* target_link = BaseLink::Alloc();
								if (target_link == nullptr)
								{
									GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
								target_link->SetLink(bone);
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TARGET), target_link, DESCFLAGS_SET::NONE);
								BaseLink* tip_link = BaseLink::Alloc();
								if (tip_link == nullptr)
								{
									GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
								tip_link->SetLink(bone_map.Find(bone_data_.IK_target_index)->GetValue());
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TIP), tip_link, DESCFLAGS_SET::NONE);
								DynamicDescription* const ddesc = ModelRoot->GetDynamicDescription();
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
								ModelRoot->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
								for (mmd::PMX_IK_links& IK_link : bone_data_.IK_links)
								{
									if (IK_link.has_limits == 1)
									{
										BaseObject* IK_link_bone = bone_map.Find(IK_link.bone_index)->GetValue();
										if (IK_link_bone != nullptr)
										{
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_MAX_ROT), Vector(-IK_link.limit_min.x, -IK_link.limit_min.y, IK_link.limit_min.z), DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_MIN_ROT), Vector(-IK_link.limit_max.x, -IK_link.limit_max.y, IK_link.limit_max.z), DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_H), true, DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_P), true, DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_B), true, DESCFLAGS_SET::NONE);
										}
									}
								}
							}
						}
					}
				}
			}
			BoneRoot->Message(ID_T_MMD_BONE);
			DescriptionCheckUpdate* msg_data = NewObj(DescriptionCheckUpdate)iferr_return;
			msg_data->descid = NewObj(DescID,PMX_BONE_INHERIT_BONE_PARENT_LINK)iferr_return;
			BoneRoot->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, msg_data);
			for (PMX_Rigid_Body_Data& rigid_body_data : this->rigid_body_data)
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
		}
		struct point_info
		{
			BaseObject* object;
			CAPoseMorphTag* morph_tag;            /* The tag where it is. */
			Int32		point_index;            /* Point converted index. */
			maxon::HashInt GetHashCode() const
			{
				return MAXON_HASHCODE(this->object, this->morph_tag,this->point_index);
			}
		};
		struct tag_info

		{
			CAPoseMorphTag* morph_tag;    /* The tag where it is. */
			maxon::BaseArray<Int32>* vertex_index_arr;
			maxon::HashInt GetHashCode() const
			{
				return MAXON_HASHCODE(this->morph_tag, this->vertex_index_arr);
			}
		}; 
		maxon::HashMap<Int32, point_info>	vertex_info_map;
		maxon::BaseList<tag_info>		morph_tag_list;

		Int32		part_surface_end = 0;
		const Int32	material_data_count = this->model_data_count.material_data_count;
		for (Int32 material_index = 0; material_index < material_data_count; material_index++)
		{
			PMX_Material_Data& material_data = this->material_data[material_index];
			PolygonObject* part = nullptr;
			CAWeightTag* weight_tag = nullptr;
			if (settings.import_polygon)
			{
				const Int32	surface_count = material_data.surface_count;
				const Int32	vertex_data_count = surface_count * 3;
				if (surface_count == 0 || vertex_data_count == 0) {
					continue;
				}
				part = PolygonObject::Alloc(vertex_data_count, surface_count);
				if (part == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				if (settings.import_english)
				{
					part->SetName("Material_" + String::IntToString(material_index));
				}
				else {
					part->SetName(material_data.material_name_local);
				}
				Vector* part_points;
				PointObject* part_point_obj = ToPoint(part);
				part_points = part_point_obj->GetPointW();
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
				if (settings.import_weights)
				{
					weight_tag = CAWeightTag::Alloc();
					if (weight_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					part->InsertTag(weight_tag);
				}
				CAPoseMorphTag* morph_tag = nullptr;
				if (settings.import_expression)
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
				maxon::BaseArray<Int32>* vertex_index_arr = NewObj(maxon::BaseArray<Int32>) iferr_return;
				Int32			new_index = 0;
				for (Int32 surface_index = 0; surface_index < surface_count; surface_index++)
				{
					CPolygon& surface = this->surface_data[surface_index + part_surface_end];
					auto			vertex_info_map_a_ptr = vertex_info_map.Find(surface.a);
					if (vertex_info_map_a_ptr == nullptr)
					{
						vertex_index_arr->Append(surface.a) iferr_return;
						vertex_info_map.Insert(surface.a, point_info{ part, morph_tag, new_index }) iferr_return;
						new_index++;
					}
					else {
						point_info& point_a = vertex_info_map_a_ptr->GetValue();
						if (point_a.object != part)
						{
							vertex_index_arr->Append(surface.a) iferr_return;
							vertex_info_map.Insert(surface.a, point_info{ part, morph_tag, new_index }) iferr_return;
							new_index++;
						}
					}
					auto vertex_info_map_b_ptr = vertex_info_map.Find(surface.b);
					if (vertex_info_map_b_ptr == nullptr)
					{
						vertex_index_arr->Append(surface.b) iferr_return;
						vertex_info_map.Insert(surface.b, point_info{ part, morph_tag, new_index }) iferr_return;
						new_index++;
					}
					else {
						point_info& point_b = vertex_info_map_b_ptr->GetValue();
						if (point_b.object != part)
						{
							vertex_index_arr->Append(surface.b) iferr_return;
							vertex_info_map.Insert(surface.b, point_info{ part, morph_tag, new_index }) iferr_return;
							new_index++;
						}
					}
					auto vertex_info_map_c_ptr = vertex_info_map.Find(surface.c);
					if (vertex_info_map_c_ptr == nullptr)
					{
						vertex_index_arr->Append(surface.c) iferr_return;
						vertex_info_map.Insert(surface.c, point_info{ part, morph_tag, new_index }) iferr_return;
						new_index++;
					}
					else {
						point_info& point_c = vertex_info_map_c_ptr->GetValue();
						if (point_c.object != part)
						{
							vertex_index_arr->Append(surface.c) iferr_return;
							vertex_info_map.Insert(surface.c, point_info{ part, morph_tag, new_index }) iferr_return;
							new_index++;
						}
					}
				}
				maxon::HashMap<Int32, Int32>	joint_bone_map;
				maxon::HashMap<Int32, maxon::UniqueRef<maxon::HashMap<Int32, Float32>>> weight_data_map;
				const Int32			vertex_index_arr_count = vertex_index_arr->GetCount();
				if (settings.import_weights)
				{					
					for (Int32 part_vertex_index = 0; part_vertex_index < vertex_index_arr_count; part_vertex_index++) 
					{
						PMX_Vertex_Data& vertex_data_ = this->vertex_data[vertex_index_arr->operator[](part_vertex_index)];
						switch (vertex_data_.weight_deform_type)
						{
						case 0:
						{	
							Int32 weight_bone = 0;
							auto joint_bone_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B1.bone);
							if (joint_bone_ptr)
							{
								weight_bone = joint_bone_ptr->GetValue();
							}
							else {
								weight_bone = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B1.bone)->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B1.bone, weight_bone) iferr_return;
							}
							maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
							weight_data->Insert(weight_bone, 1.0f)iferr_return;
							weight_data_map.Insert(part_vertex_index, std::move(weight_data))iferr_return;
							break;
						}
						case 1:
						{
							Int32 weight_bone1 = 0;
							auto joint_bone1_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B2.bone[0]);
							if (joint_bone1_ptr)
							{
								weight_bone1 = joint_bone1_ptr->GetValue();
							}
							else {
								weight_bone1 = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B2.bone[0])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B2.bone[0], weight_bone1) iferr_return;
							}
							Int32 weight_bone2 = 0;
							auto joint_bone2_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B2.bone[1]);
							if (joint_bone2_ptr)
							{
								weight_bone2 = joint_bone2_ptr->GetValue();
							}
							else {
								weight_bone2 = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B2.bone[1])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B2.bone[1], weight_bone2) iferr_return;
							}
							maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
							auto weight_data1_ptr = weight_data->Find(weight_bone1);
							if (weight_data1_ptr != nullptr) {
								weight_data1_ptr->GetValue() += vertex_data_.weight_deform_B2.weight;
							}
							else {
								weight_data->Insert(weight_bone1, vertex_data_.weight_deform_B2.weight)iferr_return;
							}
							auto weight_data2_ptr = weight_data->Find(weight_bone2);
							if (weight_data2_ptr != nullptr) {
								weight_data2_ptr->GetValue() += 1.f - vertex_data_.weight_deform_B2.weight;
							}
							else {
								weight_data->Insert(weight_bone2, 1.f - vertex_data_.weight_deform_B2.weight)iferr_return;
							}				
							weight_data_map.Insert(part_vertex_index, std::move(weight_data))iferr_return;
							break;
						}
						case 2:
						{
							Int32 weight_bone[4] = { 0 };
							auto joint_bone1_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B4.bone[0]);
							if (joint_bone1_ptr)
							{
								weight_bone[0] = joint_bone1_ptr->GetValue();
							}
							else {
								weight_bone[0] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B4.bone[0])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B4.bone[0], weight_bone[0]) iferr_return;
							}
							auto joint_bone2_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B4.bone[1]);
							if (joint_bone2_ptr)
							{
								weight_bone[1] = joint_bone2_ptr->GetValue();
							}
							else {
								weight_bone[1] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B4.bone[1])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B4.bone[1], weight_bone[1]) iferr_return;
							}
							auto joint_bone3_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B4.bone[2]);
							if (joint_bone3_ptr)
							{
								weight_bone[2] = joint_bone3_ptr->GetValue();
							}
							else {
								weight_bone[2] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B4.bone[2])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B4.bone[2], weight_bone[2])iferr_return;
							}
							auto joint_bone4_ptr = joint_bone_map.Find(vertex_data_.weight_deform_B4.bone[3]);
							if (joint_bone4_ptr)
							{
								weight_bone[3] = joint_bone4_ptr->GetValue();								
							}
							else {
								weight_bone[3] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_B4.bone[3])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_B4.bone[3], weight_bone[3]) iferr_return;
							}
							maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
							for (Int32 i = 0; i < 4; i++) {
								Int32& weight_bone_index = weight_bone[i];
								auto weight_data_ptr = weight_data->Find(weight_bone_index);
								if (weight_data_ptr != nullptr) {
									weight_data_ptr->GetValue() += vertex_data_.weight_deform_B4.weight[i];
								}
								else {
									weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_B4.weight[i])iferr_return;
								}
							}
							weight_data_map.Insert(part_vertex_index, std::move(weight_data))iferr_return;
							break;
						}
						case 3:
						{
							Int32 weight_bone1 = 0;
							auto joint_bone1_ptr = joint_bone_map.Find(vertex_data_.weight_deform_S.bone[0]);
							if (joint_bone1_ptr)
							{
								weight_bone1 = joint_bone1_ptr->GetValue();
							}
							else {
								weight_bone1 = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_S.bone[0])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_S.bone[0], weight_bone1) iferr_return;
							}
							Int32 weight_bone2 = 0;
							auto joint_bone2_ptr = joint_bone_map.Find(vertex_data_.weight_deform_S.bone[1]);
							if (joint_bone2_ptr)
							{
								weight_bone2 = joint_bone2_ptr->GetValue();
							}
							else {
								weight_bone2 = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_S.bone[1])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_S.bone[1], weight_bone2) iferr_return;
							}
							maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
							auto weight_data1_ptr = weight_data->Find(weight_bone1);
							if (weight_data1_ptr != nullptr) {
								weight_data1_ptr->GetValue() += vertex_data_.weight_deform_S.weight;
							}
							else {
								weight_data->Insert(weight_bone1, vertex_data_.weight_deform_S.weight)iferr_return;
							}
							auto weight_data2_ptr = weight_data->Find(weight_bone2);
							if (weight_data2_ptr != nullptr) {
								weight_data2_ptr->GetValue() += 1.f - vertex_data_.weight_deform_S.weight;
							}
							else {
								weight_data->Insert(weight_bone2, 1.f - vertex_data_.weight_deform_S.weight)iferr_return;
							}
							weight_data_map.Insert(part_vertex_index, std::move(weight_data))iferr_return;
							break;
						}
						case 4:
						{
							Int32 weight_bone[4] = { 0 };
							auto joint_bone1_ptr = joint_bone_map.Find(vertex_data_.weight_deform_Q.bone[0]);
							if (joint_bone1_ptr)
							{
								weight_bone[0] = joint_bone1_ptr->GetValue();
							}
							else {
								weight_bone[0] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_Q.bone[0])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_Q.bone[0], weight_bone[0]) iferr_return;
							}
							auto joint_bone2_ptr = joint_bone_map.Find(vertex_data_.weight_deform_Q.bone[1]);
							if (joint_bone2_ptr)
							{
								weight_bone[1] = joint_bone2_ptr->GetValue();
							}
							else {
								weight_bone[1] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_Q.bone[1])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_Q.bone[1], weight_bone[1]) iferr_return;
							}
							auto joint_bone3_ptr = joint_bone_map.Find(vertex_data_.weight_deform_Q.bone[2]);
							if (joint_bone3_ptr)
							{
								weight_bone[2] = joint_bone3_ptr->GetValue();
							}
							else {
								weight_bone[2] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_Q.bone[2])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_Q.bone[2], weight_bone[2])iferr_return;
							}
							auto joint_bone4_ptr = joint_bone_map.Find(vertex_data_.weight_deform_Q.bone[3]);
							if (joint_bone4_ptr)
							{
								weight_bone[3] = joint_bone4_ptr->GetValue();
							}
							else {
								weight_bone[3] = weight_tag->AddJoint(bone_map.Find(vertex_data_.weight_deform_Q.bone[3])->GetValue());
								joint_bone_map.Insert(vertex_data_.weight_deform_Q.bone[3], weight_bone[3]) iferr_return;
							}
							maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
							for (Int32 i = 0; i < 4; i++) {
								Int32& weight_bone_index = weight_bone[i];
								auto weight_data_ptr = weight_data->Find(weight_bone_index);
								if (weight_data_ptr != nullptr) {
									weight_data_ptr->GetValue() += vertex_data_.weight_deform_Q.weight[i];
								}
								else {
									weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_Q.weight[i])iferr_return;
								}
							}
							weight_data_map.Insert(part_vertex_index, std::move(weight_data))iferr_return;
							break;
						}
						}
					}
				}
				insideCount = 0;
				maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, vertex_index_arr_count, [](LocalData& context)
				{
					context.localCount = 0;
				}, [this, &part_points, &settings, &weight_tag, &vertex_index_arr, &joint_bone_map, &material_data,&weight_data_map](const Int32 part_vertex_index, LocalData& context)->maxon::Result<void>
				{
					PMX_Vertex_Data& vertex_data_ = this->vertex_data[vertex_index_arr->operator[](part_vertex_index)];
					part_points[part_vertex_index] = Vector(vertex_data_.position * settings.position_multiple);
					auto weight_data_ptr = weight_data_map.Find(part_vertex_index);
					if (weight_data_ptr) {
						auto& weight_data = weight_data_ptr->GetValue();
						for (auto& i : weight_data->GetKeys()) {
							auto weight_ptr = weight_data->Find(i);
							if (weight_ptr) {
								if (!weight_tag->SetWeight(i, part_vertex_index, weight_ptr->GetValue())) {
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
				}, [&insideCount, &vertex_index_arr_count](LocalData& context)
				{
					insideCount += context.localCount;
					if (GeIsMainThread())
						StatusSetText("Import vertex " + String::IntToString(insideCount) + " of " + String::IntToString(vertex_index_arr_count));
				}) iferr_return;
				part_point_obj->Message(MSG_UPDATE);
				joint_bone_map.Reset();
				NormalTag* normal_tag = nullptr;
				NormalHandle	normal_handle;
				if (settings.import_normal)
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
				if (settings.import_uv)
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
				maxon::ParallelFor::Dynamic<LocalData, maxon::PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, surface_count, [](LocalData& context)
				{
					context.localCount = 0;
				}, [this, &part_surface_end, &part_polygon, &settings, &normal_handle, &uvw_handle, &vertex_info_map](const Int32 surface_index, LocalData& context)->maxon::Result<void>
				{
					iferr_scope_handler{
						MessageDialog(err.ToString(nullptr));
						return err;
					};
                    CPolygon& surface = this->surface_data[surface_index + part_surface_end];
					PMX_Vertex_Data& vertex0 = this->vertex_data[surface.c];
					PMX_Vertex_Data& vertex1 = this->vertex_data[surface.b];
					PMX_Vertex_Data& vertex2 = this->vertex_data[surface.a];
					g_spinlock.Lock();
					part_polygon[surface_index] = CPolygon(vertex_info_map.Find(surface.c)->GetValue().point_index, vertex_info_map.Find(surface.b)->GetValue().point_index, vertex_info_map.Find(surface.a)->GetValue().point_index);
					g_spinlock.Unlock();
					if (settings.import_normal)
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
					if (settings.import_uv)
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
				}, [&insideCount, &surface_count](LocalData& context)
				{
					insideCount += context.localCount;
					if (GeIsMainThread())
						StatusSetText("Import surface " + String::IntToString(insideCount) + " of " + String::IntToString(surface_count));
				}) iferr_return;
				part_polygon_obj->Message(MSG_UPDATE);
				part->SetPhong(true, true, 0.7853982);
				doc->InsertObject(part, MesheRoot, nullptr);
				if (settings.import_weights)
				{
					BaseObject* morphdeformer = BaseObject::Alloc(Oskin);
					if (morphdeformer == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					doc->InsertObject(morphdeformer, part, nullptr);
				}
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
				morph_tag_list.Append(tag_info{ morph_tag, vertex_index_arr }) iferr_return;
				if (settings.import_expression)
				{
					/* Add base morph to the tag. */
					if (this->model_info.have_vertex_morph)
					{
						morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
					}
					if (this->model_info.have_UV_morph)
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
			Material* material = nullptr;
			if (settings.import_material)
			{
				material = Material::Alloc();
				if (material == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				if (settings.import_english)
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
					String			texture = this->texture_data[material_data.texture_index];
					Filename		texture_file(texture);
					AutoAlloc<BaseBitmap> bm;
					if (bm == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					bm->Init(path + texture);
					if (bm->GetChannelCount() && (texture_file.CheckSuffix("png"_s) || texture_file.CheckSuffix("PNG"_s) || texture_file.CheckSuffix("Png"_s) || texture_file.CheckSuffix("pNg"_s) || texture_file.CheckSuffix("pnG"_s) || texture_file.CheckSuffix("PNg"_s) || texture_file.CheckSuffix("pNG"_s) || texture_file.CheckSuffix("tga"_s) || texture_file.CheckSuffix("TGA"_s) || texture_file.CheckSuffix("Tga"_s) || texture_file.CheckSuffix("tGA"_s) || texture_file.CheckSuffix("tgA"_s) || texture_file.CheckSuffix("TGa"_s) || texture_file.CheckSuffix("tGA"_s)))
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
				if (settings.import_polygon)
				{
					TextureTag* const texture_tag = static_cast<TextureTag*>(part->MakeTag(Ttexture));
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					texture_tag->SetMaterial(material);
					texture_tag->SetName(material_data.material_name_local);
					texture_tag->SetParameter(DescID(TEXTURETAG_PROJECTION), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
				}
			}

			if (settings.import_weights)
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
		}

		if (settings.import_expression)
		{
			Int32									morph_data_count = this->model_data_count.morph_data_count;                /* Get the morph data count. */
			maxon::HashMap<BaseObject*, CAPoseMorphTag*>				bone_tag_map;
			maxon::HashMap<CAPoseMorphTag*, maxon::HashMap<String, CAMorph*>*>	tag_morph_map;                                                                  /* 记录每个Morph标签所有的CMorph对象，并且可以通过名字来查找它 */
			for (Int32 morph_index = 0; morph_index < morph_data_count; morph_index++)                                                                            /* 遍历每个表情 */
			{
				PMX_Morph_Data& morph_data = this->morph_data[morph_index];                                                                               /* 读取对应表情数据 */
				switch (morph_data.morph_type)
				{
				case 1:                                                                                                                                         /* 该表情为顶点表情 */
				{
					maxon::PointerArray<PMX_Morph_vertex>* vertex_morph_data_arr = (maxon::PointerArray<PMX_Morph_vertex>*)morph_data.offset_data;       /* 读取表情数据储存的变换信息 */
					Int32					offset_count = morph_data.offset_count;                                              /* 读取表情数据储存的变换信息个数 */
					for (Int32 offset_count_index = 0; offset_count_index < offset_count; offset_count_index++)
					{
						UInt32	vertex_index = vertex_morph_data_arr->operator[](offset_count_index).vertex_index;                                 /* 读取对应变换信息 */
						auto	point_info_ptr = vertex_info_map.Find(vertex_index);                                                                 /* 在vertex_info_map里查找原顶点在该部分中的对应顶点信息 */
						if (point_info_ptr != nullptr)
						{
							point_info point_info_ = point_info_ptr->GetValue();
							point_info_.morph_tag->ExitEdit(doc, true);
							auto vertex_morph_ptr = tag_morph_map.Find(point_info_.morph_tag);
							if (vertex_morph_ptr == nullptr)                                                                                      /* 若找不到Morph标签对应的CMorph对象的信息，则创建CMorph对象信息 */
							{
								maxon::HashMap<String, CAMorph*>* name_morph_map = maxon::NewObjT<maxon::HashMap<String, CAMorph*> >() iferr_return;
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
								tag_morph_map.Insert(point_info_.morph_tag, name_morph_map) iferr_return;
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
					}
					maxon::ParallelFor::Dynamic(0, offset_count, [&vertex_info_map, &vertex_morph_data_arr, &tag_morph_map, &doc, &morph_data, &settings](const Int32 offset_count_index)->maxon::Result<void>
					{
							iferr_scope_handler{
								MessageDialog(err.ToString(nullptr));
								return err;
						};		
						UInt32 vertex_index = vertex_morph_data_arr->operator[](offset_count_index).vertex_index;        /* 读取对应变换信息 */
						auto point_info_ptr = vertex_info_map.Find(vertex_index);                                        /* 在vertex_info_map里查找原顶点在该部分中的对应顶点信息 */
						if (point_info_ptr != nullptr)
						{
							point_info point_info_ = point_info_ptr->GetValue();
							point_info_.morph_tag->ExitEdit(doc, true);
							auto vertex_morph_ptr = tag_morph_map.Find(point_info_.morph_tag);
							if (vertex_morph_ptr != nullptr)                                                         /* 若找不到Morph标签对应的CMorph对象的信息，则创建CMorph对象信息 */
							{
								auto name_morph_ptr = vertex_morph_ptr->GetValue()->Find(morph_data.morph_name_local);
								if (name_morph_ptr != nullptr)
								{
									CAMorph* morph = name_morph_ptr->GetValue();
									CAMorphNode* morph_node = morph->GetFirst();
									while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node != nullptr)
									{
										morph_node = morph_node->GetNext();
									}
									morph_node->SetPoint(point_info_.point_index, Vector(vertex_morph_data_arr->operator[](offset_count_index).translation * settings.position_multiple));
								}
							}
						}
						return(maxon::OK);
					}) iferr_return;
					break;
				}
				case 2: {
					if (settings.import_bone)
					{
						maxon::PointerArray<PMX_Morph_bone>* bone_morph_data_arr = (maxon::PointerArray<PMX_Morph_bone>*)morph_data.offset_data; /* 读取表情数据储存的变换信息 */
						Int32					offset_count = morph_data.offset_count;                                      /* 读取表情数据储存的变换信息个数 */
						maxon::ParallelFor::Dynamic(0, offset_count, [&bone_map, &bone_morph_data_arr, &bone_tag_map, &doc, &morph_data, &settings](const Int32 offset_count_index)->maxon::Result<void>
						{
							iferr_scope_handler{
								MessageDialog(err.ToString(nullptr));
								return err;
							};
							mmd::PMX_Morph_bone bone_morph_data = bone_morph_data_arr->operator[](offset_count_index);
							auto bone_ptr = bone_map.Find(bone_morph_data.bone_index);
							if (bone_ptr != nullptr)
							{
								BaseObject* bone = bone_ptr->GetValue();
								BaseTag* pmx_bone_tag = bone->GetTag(ID_T_MMD_BONE);
								if (pmx_bone_tag != nullptr)
								{
									TMMDBone* pmx_bone_tag_data = pmx_bone_tag->GetNodeData<TMMDBone>();
									Int32 bone_morph_data_index = pmx_bone_tag_data->AddBondMorph(morph_data.morph_name_local);
									if (bone_morph_data_index == -1)
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
									if (!pmx_bone_tag_data->SetBondMorphTranslation(bone_morph_data_index, Vector(bone_morph_data.translation * settings.position_multiple)))
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
									if (!pmx_bone_tag_data->SetBondMorphRotation(bone_morph_data_index, Vector(bone_morph_data.rotation)))
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
							}
							return(maxon::OK);
						}) iferr_return;
					}
					break;
				}
				case 3:
				{
					maxon::PointerArray<PMX_Morph_UV>* UV_morph_data_arr = (maxon::PointerArray<PMX_Morph_UV>*)morph_data.offset_data;
					Int32					offset_count = morph_data.offset_count;
					maxon::HashMap<Int32, Vector>		vertex_floats_map;
					for (PMX_Morph_UV& UV_morph_data : (*UV_morph_data_arr))
					{
						vertex_floats_map.Insert(UV_morph_data.vertex_index, Vector(UV_morph_data.floats.x, UV_morph_data.floats.y, 0)) iferr_return;
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
						maxon::ParallelFor::Dynamic(0, surface_data_count, [&morph_node, this, &UV_morph_data_arr, &vertex_floats_map, &vertex_info_map, &tag_info_](const Int32 surface_index)
						{
							const CPolygon& surface = ToPoly(tag_info_.morph_tag->GetObject())->GetPolygonR()[surface_index];
							UVWStruct uvw;
							morph_node->GetUV(0, surface_index, uvw);
							auto vertex_a_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr->operator[](surface.a));
							if (vertex_a_ptr != nullptr)
							{
								uvw.c = vertex_a_ptr->GetValue();
							}
							auto vertex_b_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr->operator[](surface.b));
							if (vertex_b_ptr != nullptr)
							{
								uvw.b = vertex_b_ptr->GetValue();
							}
							auto vertex_c_ptr = vertex_floats_map.Find(tag_info_.vertex_index_arr->operator[](surface.c));
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
			for (tag_info tag_info_ : morph_tag_list)
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
			for (auto name_morph_map : tag_morph_map.GetValues())
			{
				DeleteObj(name_morph_map);
			}
			tag_morph_map.Reset();
			bone_tag_map.Reset();
		}
		for (tag_info tag_info_ : morph_tag_list)
		{
			DeleteObj(tag_info_.vertex_index_arr);
		}
		morph_tag_list.Reset();
		bone_map.Reset();
		vertex_info_map.Reset();
	}
	else {
		NameConversion	name_conversion;
		BaseObject* ModelRoot = BaseObject::Alloc(ID_O_MMD_MODEL);
		if (ModelRoot == nullptr)
		{
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
		}
		ModelRoot->SetName(this->model_info.model_name_local);
		OMMDModel* ModelRootData = ModelRoot->GetNodeData<OMMDModel>();
		if (!ModelRootData->CreateRoot())
			return(maxon::Error());
		doc->InsertObject(ModelRoot, nullptr, nullptr);
		ModelRoot->SetParameter(DescID(ID_BASELIST_NAME), this->model_info.model_name_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(PMX_VERSION), this->model_info.version, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(MODEL_NAME_LOCAL), this->model_info.model_name_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(MODEL_NAME_UNIVERSAL), this->model_info.model_name_universal, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(COMMENTS_LOCAL), this->model_info.comments_local, DESCFLAGS_SET::NONE);
		ModelRoot->SetParameter(DescID(COMMENTS_UNIVERSAL), this->model_info.comments_universal, DESCFLAGS_SET::NONE);
		BaseObject* BoneRoot = nullptr;
		if (settings.import_bone)
		{
			BoneRoot = ModelRootData->GetRootObject(OMMDModel_Root_type::BoneRoot);
			if (BoneRoot == nullptr)
			{
				BoneRoot = BaseObject::Alloc(Onull);
				if (BoneRoot == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				BoneRoot->SetName("Bones"_s);
				doc->InsertObject(BoneRoot, ModelRoot, nullptr);
			}
		}
		PolygonObject* model = nullptr;
		PointObject* model_point_obj = nullptr;
		Vector* model_points;
		PolygonObject* model_polygon_obj = nullptr;
		CPolygon* model_polygon;
		BaseSelect* select = nullptr;
		Int32		select_end = 0;
		const Int32	vertex_data_count = this->model_data_count.vertex_data_count;
		const Int32	surface_data_count = this->model_data_count.surface_data_count;
		if (settings.import_polygon)
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
		if (settings.import_weights)
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
		maxon::HashMap<Int32, BaseObject*> bone_map; 
		if (settings.import_bone)
		{
			const Int32 kBoneDataCount = this->model_data_count.bone_data_count;
			/*Create a bone object and initialize the English name conversion.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
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
			if (settings.import_english_check)
			{
				name_conversion.CheckUpdata();
			}
			else {
				name_conversion.AutoUpdata();
			}
			/*Sets the parent-child relationship and position of the bone.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
				auto bone_ptr = bone_map.Find(bone_index);
				if (bone_ptr == nullptr)
				{
					return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
				}
				BaseObject* bone = bone_ptr->GetValue();
				if (settings.import_weights) {
					Int32 joint_index = weight_tag->AddJoint(bone);
				}
				if (bone_data_.parent_bone_index == -1)
				{
					bone->SetFrozenPos(Vector(bone_data_.position) * settings.position_multiple);
					doc->InsertObject(bone, BoneRoot, nullptr);
				}
				else {
					bone->SetFrozenPos(Vector(bone_data_.position - this->bone_data[bone_data_.parent_bone_index].position) * settings.position_multiple);
					auto parent_bone_ptr = bone_map.Find(bone_data_.parent_bone_index);
					if (parent_bone_ptr != nullptr)
					{
						doc->InsertObject(bone, parent_bone_ptr->GetValue(), nullptr);
					}
				}
			}
			EventAdd();
			/*Create tag and import data.*/
			for (Int32 bone_index = 0; bone_index < kBoneDataCount; bone_index++)
			{
				PMX_Bone_Data& bone_data_ = this->bone_data[bone_index];
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
				bone_tag_data->SetRootObject(BoneRoot);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_INDEX), String::IntToString(bone_index), DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ID_BASELIST_NAME), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_LOCAL), bone_data_.bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_UNIVERSAL), bone_data_.bone_name_universal, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_NAME_IS), settings.import_english, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PMX_BONE_POSITION), (Vector)bone_data_.position * settings.position_multiple, DESCFLAGS_SET::NONE);
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
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_TAIL_INDEX), bone_data_.tail_index, DESCFLAGS_SET::NONE);
				}
				else {
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_TAIL_POSITION), (Vector)bone_data_.position * settings.position_multiple, DESCFLAGS_SET::NONE);
				}
				if (bone_data_.bone_flags.Local_coordinate)
				{
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_LOCAL_X), (Vector)bone_data_.bone_local_X, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_LOCAL_Z), (Vector)bone_data_.bone_local_Z, DESCFLAGS_SET::NONE);
				}
				if (bone_data_.bone_flags.Fixed_axis == 1)
				{
					PMX_bone_tag->SetParameter(DescID(PMX_BONE_FIXED_AXIS), (Vector)bone_data_.bone_fixed_axis, DESCFLAGS_SET::NONE);
				}
				if (settings.import_inherit)
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
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
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
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE), bone_data_.inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
				}
				if (settings.import_ik)
				{
					if (bone_data_.bone_flags.IK == 1)
					{
						if (bone_data_.IK_links.Begin() != bone_data_.IK_links.End()) {
							BaseObject* IK_beging_bone = bone_map.Find((bone_data_.IK_links.End() - 1)->bone_index)->GetValue();
							if (IK_beging_bone != nullptr) {
								BaseTag* IK_tag = IK_beging_bone->MakeTag(1019561); /* Ik Tag ID : 1019561 */
								if (settings.import_english)
								{
									IK_tag->SetName(bone_data_.bone_name_universal);
								}
								else {
									IK_tag->SetName(bone_data_.bone_name_local);
								}
								/*Sets the rotation handle of the IK pole vector.*/
								if (bone_data_.bone_name_local.Find(L"\u8db3\uff29\uff2b"_s, nullptr)) /*L"\u8db3\uff29\uff2b" is 足IK*/
								{
									BaseObject* IK_beging_bone_up_a = IK_beging_bone->GetUp();
									if (IK_beging_bone_up_a != nullptr) {
										BaseObject* IK_beging_bone_up_b = IK_beging_bone_up_a->GetUp();
										if (IK_beging_bone_up_b != nullptr) {
											BaseObject* polar_vector = BaseObject::Alloc(Onull);
											/*TODO:Localized naming*/
											polar_vector->SetName(bone_data_.bone_name_local + ".Rotating handle");
											polar_vector->SetFrozenPos(IK_beging_bone_up_a->GetFrozenPos() + Vector(0.0, 0.0, -settings.position_multiple));
											doc->InsertObject(polar_vector, IK_beging_bone_up_b, IK_beging_bone_up_a);
											BaseLink* polar_vector_link = BaseLink::Alloc();
											if (polar_vector_link == nullptr)
											{
												GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
												MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
												return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
											}
											polar_vector_link->SetLink(polar_vector);
											IK_tag->SetParameter(DescID(ID_CA_IK_TAG_POLE), polar_vector_link, DESCFLAGS_SET::NONE);
										}
									}
								}
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_PREFERRED_WEIGHT), 1, DESCFLAGS_SET::NONE);
								BaseLink* target_link = BaseLink::Alloc();
								if (target_link == nullptr)
								{
									GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
								target_link->SetLink(bone);
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TARGET), target_link, DESCFLAGS_SET::NONE);
								BaseLink* tip_link = BaseLink::Alloc();
								if (tip_link == nullptr)
								{
									GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
								tip_link->SetLink(bone_map.Find(bone_data_.IK_target_index)->GetValue());
								IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TIP), tip_link, DESCFLAGS_SET::NONE);
								DynamicDescription* const ddesc = ModelRoot->GetDynamicDescription();
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
								ModelRoot->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
								for (mmd::PMX_IK_links& IK_link : bone_data_.IK_links)
								{
									if (IK_link.has_limits == 1)
									{
										BaseObject* IK_link_bone = bone_map.Find(IK_link.bone_index)->GetValue();
										if (IK_link_bone != nullptr)
										{
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_MAX_ROT), Vector(-IK_link.limit_min.x, -IK_link.limit_min.y, IK_link.limit_min.z), DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_MIN_ROT), Vector(-IK_link.limit_max.x, -IK_link.limit_max.y, IK_link.limit_max.z), DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_H), true, DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_P), true, DESCFLAGS_SET::NONE);
											IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_USE_ROT_B), true, DESCFLAGS_SET::NONE);
										}
									}
								}
							}
						}
					}
				}
			}
			BoneRoot->Message(ID_T_MMD_BONE);
			DescriptionCheckUpdate* msg_data = NewObj(DescriptionCheckUpdate)iferr_return;
			msg_data->descid = NewObj(DescID, PMX_BONE_INHERIT_BONE_PARENT_LINK)iferr_return;
			BoneRoot->MultiMessage(MULTIMSG_ROUTE::BROADCAST, MSG_DESCRIPTION_CHECKUPDATE, msg_data);
			for (PMX_Rigid_Body_Data& rigid_body_data : this->rigid_body_data)
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
		}
		if (settings.import_polygon)
		{
			maxon::HashMap<Int32, maxon::UniqueRef<maxon::HashMap<Int32,Float32>>> weight_data_map;
			if (settings.import_weights) {
				for (Int32 vertex_index = 0; vertex_index < vertex_data_count; vertex_index++) {
					PMX_Vertex_Data& vertex_data_ = this->vertex_data[vertex_index];
					switch (vertex_data_.weight_deform_type)
					{
					case 0:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						weight_data->Insert(vertex_data_.weight_deform_B1.bone, 1.0f)iferr_return;
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 1:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						for (Int32 i = 0; i < 2; i++) {
							Int32& weight_bone_index = vertex_data_.weight_deform_B2.bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								if (i == 0) {
									weight_data_ptr->GetValue() += vertex_data_.weight_deform_B2.weight;
								}
								else {
									weight_data_ptr->GetValue() += 1.f - vertex_data_.weight_deform_B2.weight;
								}
							}
							else {
								if (i == 0) {
									weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_B2.weight)iferr_return;
								}
								else {
									weight_data->Insert(weight_bone_index, 1.f - vertex_data_.weight_deform_B2.weight)iferr_return;
								}
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 2:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						for (Int32 i = 0; i < 4; i++) {
							Int32& weight_bone_index = vertex_data_.weight_deform_B4.bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								weight_data_ptr->GetValue() += vertex_data_.weight_deform_B4.weight[i];
							}
							else {
								weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_B4.weight[i])iferr_return;
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 3:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						for (Int32 i = 0; i < 2; i++) {
							Int32& weight_bone_index = vertex_data_.weight_deform_S.bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								if (i == 0) {
									weight_data_ptr->GetValue() += vertex_data_.weight_deform_S.weight;
								}
								else {
									weight_data_ptr->GetValue() += 1.f - vertex_data_.weight_deform_S.weight;
								}
							}
							else {
								if (i == 0) {
									weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_S.weight)iferr_return;
								}
								else {
									weight_data->Insert(weight_bone_index, 1.f - vertex_data_.weight_deform_S.weight)iferr_return;
								}
							}
						}
						weight_data_map.Insert(vertex_index, std::move(weight_data))iferr_return;
						break;
					}
					case 4:
					{
						maxon::UniqueRef<maxon::HashMap<Int32, Float32>> weight_data = maxon::NewObjT<maxon::HashMap<Int32, Float32>>()iferr_return;
						for (Int32 i = 0; i < 4; i++) {
							Int32& weight_bone_index = vertex_data_.weight_deform_Q.bone[i];
							auto weight_data_ptr = weight_data->Find(weight_bone_index);
							if (weight_data_ptr != nullptr) {
								weight_data_ptr->GetValue() += vertex_data_.weight_deform_Q.weight[i];
							}
							else {
								weight_data->Insert(weight_bone_index, vertex_data_.weight_deform_Q.weight[i])iferr_return;
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
			}, [&vertex_data_count, this, &model_points, &settings, &weight_tag, &weight_data_map](const Int32 vertex_index, LocalData& context)->maxon::Result<void>
			{
				PMX_Vertex_Data& vertex_data_ = this->vertex_data[vertex_index];
				g_spinlock.Lock();
				model_points[vertex_index] = Vector(vertex_data_.position * settings.position_multiple);
				g_spinlock.Unlock();
				if (settings.import_weights)
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
			if (settings.import_normal)
			{
				normal_tag = NormalTag::Alloc(this->model_data_count.surface_data_count);
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
			if (settings.import_uv)
			{
				uvw_tag = UVWTag::Alloc(this->model_data_count.surface_data_count);
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
			}, [this, &model_polygon, &settings, &surface_data_count, &normal_handle, &uvw_handle](const Int32 surface_index, LocalData& context)->maxon::Result<void>
			{
				iferr_scope_handler{
					MessageDialog(err.ToString(nullptr));
					return err;
				};
				CPolygon& surface = this->surface_data[surface_index];
				PMX_Vertex_Data& vertex0 = this->vertex_data[surface.c];
				PMX_Vertex_Data& vertex1 = this->vertex_data[surface.b];
				PMX_Vertex_Data& vertex2 = this->vertex_data[surface.a];
				g_spinlock.Lock();
				model_polygon[surface_index] = CPolygon(surface.c, surface.b, surface.a);
				g_spinlock.Unlock();
				if (settings.import_normal)
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
				if (settings.import_uv)
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
			BaseObject* MesheRoot = ModelRootData->GetRootObject(OMMDModel_Root_type::MeshRoot);
			if (MesheRoot != nullptr)
			{
				doc->InsertObject(model, MesheRoot, nullptr);
			}
			else {
				doc->InsertObject(model, ModelRoot, nullptr);
			}
			if (settings.import_weights)
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
		if (settings.import_expression)
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
			if (this->model_info.have_vertex_morph)
			{
				morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
			}
			if (this->model_info.have_UV_morph)
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
			Int32 morph_data_count = this->model_data_count.morph_data_count;

			for (Int32 morph_index = 0; morph_index < morph_data_count; morph_index++)
			{
				StatusSetText("Import morphs..."_s);
				StatusSetBar(morph_index * 100 / morph_data_count);
				PMX_Morph_Data& morph_data = this->morph_data[morph_index];
				switch (morph_data.morph_type)
				{
				case 1: {
					maxon::PointerArray<PMX_Morph_vertex>* vertex_morph_data_arr = (maxon::PointerArray<PMX_Morph_vertex>*)morph_data.offset_data;
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
					maxon::ParallelFor::Dynamic(0, offset_count, [&morph_node, &vertex_morph_data_arr, &settings](const Int32 pointIndex)
					{
						morph_node->SetPoint(vertex_morph_data_arr->operator									[](pointIndex).vertex_index, Vector(vertex_morph_data_arr->operator[](pointIndex).translation * settings.position_multiple));
					});
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
					break;
				}
				case 2: {
					if (settings.import_bone)
					{
						maxon::PointerArray<PMX_Morph_bone>* bone_morph_data_arr = (maxon::PointerArray<PMX_Morph_bone>*)morph_data.offset_data; /* 读取表情数据储存的变换信息 */
						Int32					offset_count = morph_data.offset_count;                                      /* 读取表情数据储存的变换信息个数 */
						maxon::ParallelFor::Dynamic(0, offset_count, [&bone_map, &bone_morph_data_arr, &bone_tag_map, &doc, &morph_data, &settings](const Int32 offset_count_index)->maxon::Result<void>
						{
								iferr_scope_handler{
									MessageDialog(err.ToString(nullptr));
									return err;
								};
							mmd::PMX_Morph_bone bone_morph_data = bone_morph_data_arr->operator[](offset_count_index);
							auto bone_ptr = bone_map.Find(bone_morph_data.bone_index);
							if (bone_ptr != nullptr)
							{
								BaseObject* bone = bone_ptr->GetValue();
								BaseTag* pmx_bone_tag = bone->GetTag(ID_T_MMD_BONE);
								if (pmx_bone_tag != nullptr)
								{
									TMMDBone* pmx_bone_tag_data = pmx_bone_tag->GetNodeData<TMMDBone>();
									Int32 bone_morph_data_index = pmx_bone_tag_data->AddBondMorph(morph_data.morph_name_local);
									if (bone_morph_data_index == -1)
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
									if (!pmx_bone_tag_data->SetBondMorphTranslation(bone_morph_data_index, Vector(bone_morph_data.translation * settings.position_multiple)))
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
									if (!pmx_bone_tag_data->SetBondMorphRotation(bone_morph_data_index, Vector(bone_morph_data.rotation)))
										return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
								}
							}
							return(maxon::OK);
						}) iferr_return;
					}
					break;
				}
				case 3:
				{
					maxon::PointerArray<PMX_Morph_UV>* UV_morph_data_arr = (maxon::PointerArray<PMX_Morph_UV>*)morph_data.offset_data;
					Int32					offset_count = morph_data.offset_count;
					maxon::HashMap<Int32, Vector>		vertex_floats_map;
					for (PMX_Morph_UV& UV_morph_data : (*UV_morph_data_arr))
					{
						vertex_floats_map.Insert(UV_morph_data.vertex_index, Vector(UV_morph_data.floats.x, UV_morph_data.floats.y, 0)) iferr_return;
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
					maxon::ParallelFor::Dynamic(0, surface_data_count, [&morph_node, this, &UV_morph_data_arr, &vertex_floats_map](const Int32 surface_index)
					{
						CPolygon& surface = this->surface_data[surface_index];
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
		if (settings.import_material)
		{
			Int32 material_data_count = this->model_data_count.material_data_count;
			for (Int32 material_index = 0; material_index < material_data_count; material_index++)
			{
				StatusSetText("Import materials..."_s);
				StatusSetBar(material_index * 100 / material_data_count);
				PMX_Material_Data& material_data = this->material_data[material_index];
				Material* material = Material::Alloc();
				if (material == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				material->SetName(material_data.material_name_local);
				BaseChannel* basecolor_channel = material->GetChannel(CHANNEL_COLOR);
				if (basecolor_channel == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
				}
				material->SetChannelState(CHANNEL_ALPHA, true);
				BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
				if (basecolor_channel == nullptr)
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
					String			texture = this->texture_data[material_data.texture_index];
					Filename		texture_file(texture);
					AutoAlloc<BaseBitmap> bm;
					if (bm == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					bm->Init(path + texture);
					if (bm->GetChannelCount() && (texture_file.CheckSuffix("png"_s) || texture_file.CheckSuffix("PNG"_s) || texture_file.CheckSuffix("Png"_s) || texture_file.CheckSuffix("pNg"_s) || texture_file.CheckSuffix("pnG"_s) || texture_file.CheckSuffix("PNg"_s) || texture_file.CheckSuffix("pNG"_s) || texture_file.CheckSuffix("tga"_s) || texture_file.CheckSuffix("TGA"_s) || texture_file.CheckSuffix("Tga"_s) || texture_file.CheckSuffix("tGA"_s) || texture_file.CheckSuffix("tgA"_s) || texture_file.CheckSuffix("TGa"_s) || texture_file.CheckSuffix("tGA"_s)))
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
				if (settings.import_polygon)
				{
					doc->SetSelection(model);
					select->SelectAll(select_end, select_end + material_data.surface_count - 1);
					select_end += material_data.surface_count;
					CallCommand(12552);
					doc->GetActiveTag()->SetName(material_data.material_name_local);
					TextureTag* const texture_tag = static_cast<TextureTag*>(model->MakeTag(Ttexture,doc->GetActiveTag()));
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR)));
					}
					texture_tag->SetMaterial(material);
					texture_tag->SetName(material_data.material_name_local);
					texture_tag->SetParameter(DescID(TEXTURETAG_RESTRICTION), material_data.material_name_local, DESCFLAGS_SET::NONE);
					texture_tag->SetParameter(DescID(TEXTURETAG_PROJECTION), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
				}
			}
		}
		EventAdd();
		if (settings.import_polygon)
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
		if (settings.import_weights)
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
	}
	doc->SetMode(Mmodel);
	doc->SetSelection(nullptr);
	timing.Stop();
	GePrint(String::FloatToString(timing.GetMilliseconds()));
	StatusClear();
	return(maxon::OK);
}


maxon::Result<void> mmd::PMXModel::FromDocumentExportModel(PMX_Model_export_settings& settings)
{
	return(maxon::OK);
}
