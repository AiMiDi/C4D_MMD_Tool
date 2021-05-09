#include "MMD_PMX_model.h"

mmd::PMXModel::~PMXModel() {
	for (auto i : vertex_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : surface_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : material_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : bone_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : morph_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : rigid_body_data) {
		if (i != nullptr)delete i;
	}
	for (auto i : joint_data) {
		if (i != nullptr)delete i;
	}
}

String mmd::PMXModel::ReadText(BaseFile* const file, Char& text_encoding)
{
	Int32 text_len;//text字符串最大长度
	file->ReadInt32(&text_len);
	if (text_encoding == 0)
	{
		Utf16Char* tmp_wStr = new Utf16Char[text_len + 1]{ 0 };
		if (!tmp_wStr)
		{
			delete[] tmp_wStr;
		}
		file->ReadBytes(tmp_wStr, text_len);
		return String(tmp_wStr);
	}
	else if (text_encoding == 1)
	{
		char* tmp_Str = new char[text_len + 1]{ 0 };
		if (!tmp_Str)
		{
			delete[] tmp_Str;
		}
		file->ReadBytes(tmp_Str, text_len);
		String str;
		str.SetCString(tmp_Str, -1, STRINGENCODING::UTF8);
		return str;
	}
	return nullptr;
}

Int32 mmd::PMXModel::ReadIndex(BaseFile* const file, Char& index_size)
{
	switch (index_size)//3种长度不同的Index
	{
	case 1:
	{
		Char index;
		file->ReadChar(&index);
		return index;
	}
	case 2:
	{
		Int16 index;
		file->ReadInt16(&index);
		return index;
	}
	case 4:
	{
		Int32 index;
		file->ReadInt32(&index);
		return index;
	}
	default:
		return -1;
	}
}

UInt32 mmd::PMXModel::ReadUIndex(BaseFile* const file, Char& index_size)
{
	switch (index_size)//3种长度不同的Index
	{
	case 1:
	{
		UChar index;
		file->ReadUChar(&index);
		return index;
	}
	case 2:
	{
		UInt16 index;
		file->ReadUInt16(&index);
		return index;
	}
	case 4:
	{
		UInt32 index;
		file->ReadUInt32(&index);
		return index;
	}
	default:
		return 0;
	}
}

maxon::Result<void> mmd::PMXModel::LoadFromFile(BaseFile* const file) {
	iferr_scope;
	PMX_Model_information model_info_;
	PMX_Data_count model_data_count_;
	Char signature[5]{ 0 };//签名,值为"PMX "
	if (!file->ReadBytes(signature, 4))return maxon::Error();//读取签名
	if (strncmp(signature, "PMX", 3))
	{
		GePrint("Is not a PMX file!"_s);
	}
	if (!file->ReadFloat32(&(model_info_.version)))return maxon::Error();//读取版本号								  
	Char globals_count;//全局信息数量,PMX2.0有8条全局信息
	if (!file->ReadChar(&globals_count))return maxon::Error();//读取全局信息数量
	if (globals_count != 8) {
		GePrint("PMX file corruption!"_s);
	}
	if (!file->ReadChar(&(model_info_.text_encoding)))return maxon::Error();//读取字符串编码
	if (!file->ReadChar(&(model_info_.additional_vec4_count)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.vertex_index_size)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.texture_index_size)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.material_index_size)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.bone_index_size)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.morph_index_size)))return maxon::Error();
	if (!file->ReadChar(&(model_info_.rigidbody_index_size)))return maxon::Error();
	model_info_.model_name_local = ReadText(file, model_info_.text_encoding);
	model_info_.model_name_universal = ReadText(file, model_info_.text_encoding);
	model_info_.comments_local = ReadText(file, model_info_.text_encoding);
	model_info_.comments_universal = ReadText(file, model_info_.text_encoding);
	this->model_info = model_info_;
	if (!file->ReadInt32(&(model_data_count_.vertex_data_count)))return maxon::Error();
	for (Int32 i = 0; i < model_data_count_.vertex_data_count; i++)
	{
		PMX_Vertex_Data* vertex_data_ = new PMX_Vertex_Data;
		if (vertex_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		if (!file->ReadVector32(&(vertex_data_->position)))return maxon::Error();
		if (!file->ReadVector32(&(vertex_data_->normal)))return maxon::Error();
		if (!file->ReadBytes(&(vertex_data_->UV), sizeof(vec2)))return maxon::Error();
		if (!file->Seek(16 * model_info_.additional_vec4_count))return maxon::Error();
		if (!file->ReadChar(&(vertex_data_->weight_deform_type)))return maxon::Error();
		switch (vertex_data_->weight_deform_type)
		{
		case 0:
		{
			BDEF1 weight;
			weight.bone1 = ReadIndex(file, model_info_.bone_index_size);
			vertex_data_->weight_deform_B1 = weight;
			break;
		}
		case 1:
		{
			BDEF2 weight;
			weight.bone1 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone2 = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight1)))return maxon::Error();
			vertex_data_->weight_deform_B2 = weight;
			break;
		}
		case 2:
		{
			BDEF4 weight;
			weight.bone1 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone2 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone3 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone4 = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight1)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight2)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight3)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight4)))return maxon::Error();
			vertex_data_->weight_deform_B4 = weight;
			break;
		}
		case 3:
		{
			SDEF weight;
			weight.bone1 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone2 = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight1)))return maxon::Error();
			if (!file->ReadVector32(&(weight.R0)))return maxon::Error();
			if (!file->ReadVector32(&(weight.R1)))return maxon::Error();
			if (!file->ReadVector32(&(weight.C)))return maxon::Error();
			vertex_data_->weight_deform_S = weight;
			break;
		}
		case 4:
		{
			QDEF weight;
			weight.bone1 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone2 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone3 = ReadIndex(file, model_info_.bone_index_size);
			weight.bone4 = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(weight.weight1)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight2)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight3)))return maxon::Error();
			if (!file->ReadFloat32(&(weight.weight4)))return maxon::Error();
			vertex_data_->weight_deform_Q = weight;
			break;
		}
		}
		if (!file->ReadFloat32(&(vertex_data_->edge_scale)))return maxon::Error();
		this->vertex_data.Append(vertex_data_)iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.surface_data_count)))return maxon::Error();
	model_data_count_.surface_data_count /= 3;
	for (Int32 i = 0; i < model_data_count_.surface_data_count; i++)
	{
		this->surface_data.Append(new CPolygon(ReadUIndex(file, model_info_.vertex_index_size), ReadUIndex(file, model_info_.vertex_index_size), ReadUIndex(file, model_info_.vertex_index_size)))iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.texture_data_count)))return maxon::Error();
	for (Int32 i = 0; i < model_data_count_.texture_data_count; i++)
	{
		this->texture_data.Append(ReadText(file, model_info_.text_encoding))iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.material_data_count)))return maxon::Error();
	for (Int32 i = 0; i < model_data_count_.material_data_count; i++)
	{
		PMX_Material_Data* material_data_ = new PMX_Material_Data;
		if (material_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		material_data_->material_name_local = ReadText(file, model_info_.text_encoding);
		material_data_->material_name_universal = ReadText(file, model_info_.text_encoding);
		if (!file->ReadBytes(&(material_data_->diffuse_colour), sizeof(vec4)))return maxon::Error();
		if (!file->ReadVector32(&(material_data_->specular_colour)))return maxon::Error();
		if (!file->ReadFloat32(&(material_data_->specular_strength)))return maxon::Error();
		if (!file->ReadVector32(&(material_data_->ambient_colour)))return maxon::Error();
		if (!file->ReadBytes(&(material_data_->drawing_flags), sizeof(PMX_Material_Flags)))return maxon::Error();
		if (!file->ReadBytes(&(material_data_->edge_colour), sizeof(vec4)))return maxon::Error();
		if (!file->ReadFloat32(&(material_data_->edge_scale)))return maxon::Error();
		material_data_->texture_index = ReadIndex(file, model_info_.texture_index_size);
		material_data_->environment_index = ReadIndex(file, model_info_.texture_index_size);
		if (!file->ReadChar(&(material_data_->environment_blend_mode)))return maxon::Error();
		if (!file->ReadChar(&(material_data_->toon_reference)))return maxon::Error();
		if (material_data_->toon_reference == 0)
		{
			material_data_->toon_part = ReadIndex(file, model_info_.texture_index_size);
		}
		else if (material_data_->toon_reference == 1)
		{
			if (!file->ReadChar(&(material_data_->toon_internal)))return maxon::Error();
		}
		material_data_->meta_data = ReadText(file, model_info_.text_encoding);
		if (!file->ReadInt32(&(material_data_->surface_count)))return maxon::Error();
		material_data_->surface_count /= 3;
		this->material_data.Append(material_data_)iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.bone_data_count)))return maxon::Error();
	for (Int32 i = 0; i < model_data_count_.bone_data_count; i++)
	{
		PMX_Bone_Data* bone_data_ = new PMX_Bone_Data;
		if (bone_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		bone_data_->bone_name_local = ReadText(file, model_info_.text_encoding);
		bone_data_->bone_name_universal = ReadText(file, model_info_.text_encoding);
		if (!file->ReadVector32(&(bone_data_->position)))return maxon::Error();
		bone_data_->parent_bone_index = ReadIndex(file, model_info_.bone_index_size);
		if (!file->ReadInt32(&(bone_data_->layer)))return maxon::Error();
		if (!file->ReadBytes(&(bone_data_->bone_flags), sizeof(PMX_Bone_Flags)))return maxon::Error();
		if (bone_data_->bone_flags.indexed_tail_position == 0)
		{
			if (!file->ReadVector32(&(bone_data_->tail_position)))return maxon::Error();
		}
		else if (bone_data_->bone_flags.indexed_tail_position == 1)
		{
			bone_data_->tail_index = ReadIndex(file, model_info_.bone_index_size);
		}
		if (bone_data_->bone_flags.Inherit_rotation || bone_data_->bone_flags.Inherit_translation)
		{
			bone_data_->inherit_bone_parent_index = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadFloat32(&(bone_data_->inherit_bone_parent_influence)))return maxon::Error();
		}
		if (bone_data_->bone_flags.Fixed_axis)
		{
			if (!file->ReadVector32(&(bone_data_->bone_fixed_axis)))return maxon::Error();
		}
		if (bone_data_->bone_flags.Local_coordinate)
		{
			if (!file->ReadVector32(&(bone_data_->bone_local_X)))return maxon::Error();
			if (!file->ReadVector32(&(bone_data_->bone_local_Z)))return maxon::Error();
		}
		if (bone_data_->bone_flags.External_parent_deform) {
			if (!file->Seek(model_info_.bone_index_size))return maxon::Error();
		}
		if (bone_data_->bone_flags.IK)
		{
			bone_data_->IK_target_index = ReadIndex(file, model_info_.bone_index_size);
			if (!file->ReadInt32(&(bone_data_->IK_loop_count)))return maxon::Error();
			if (!file->ReadFloat32(&(bone_data_->IK_limit_radian)))return maxon::Error();
			if (!file->ReadInt32(&(bone_data_->IK_link_count)))return maxon::Error();
			for (Int32 j = 0; j < bone_data_->IK_link_count; j++)
			{
				PMX_IK_links* IK_link = new PMX_IK_links;
				if (IK_link == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				IK_link->bone_index = ReadIndex(file, model_info_.bone_index_size);
				if (!file->ReadBool(&(IK_link->has_limits)))return maxon::Error();
				if (IK_link->has_limits)
				{
					if (!file->ReadVector32(&(IK_link->limit_min)))return maxon::Error();
					if (!file->ReadVector32(&(IK_link->limit_max)))return maxon::Error();
				}
				bone_data_->IK_links.Append(IK_link)iferr_return;
			}
		}
		this->bone_data.Append(bone_data_)iferr_return;
	}
	if (!file->ReadInt32(&(model_data_count_.morph_data_count)))return maxon::Error();
	for (Int32 i = 0; i < model_data_count_.morph_data_count; i++)
	{
		PMX_Morph_Data* morph_data_ = new PMX_Morph_Data;
		if (morph_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		morph_data_->morph_name_local = ReadText(file, model_info_.text_encoding);
		morph_data_->morph_name_universal = ReadText(file, model_info_.text_encoding);
		if (!file->ReadChar(&(morph_data_->panel_type)))return maxon::Error();
		if (!file->ReadChar(&(morph_data_->morph_type)))return maxon::Error();
		void* offset_data_ = nullptr;
		switch (morph_data_->morph_type)
		{
		case 0:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_group>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 1:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_vertex>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 2:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_bone>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 3:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_UV>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 8:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_material>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 9:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_flip>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		case 10:
		{
			offset_data_ = new maxon::PointerArray<PMX_Morph_impulse>;
			if (offset_data_ == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			morph_data_->offset_data = offset_data_;
			break;
		}
		default:
			break;
		}
		if (!file->ReadInt32(&(morph_data_->offset_count)))return maxon::Error();
		for (Int32 j = 0; j < morph_data_->offset_count; j++)
		{
			switch (morph_data_->morph_type)
			{
			case 0:
			{
				maxon::PointerArray<PMX_Morph_group>* offset_data_groups = (maxon::PointerArray<PMX_Morph_group>*)offset_data_;
				PMX_Morph_group* offset_data_group_ = new PMX_Morph_group;
				if (offset_data_group_== nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_group_->morph_index = ReadIndex(file, model_info_.morph_index_size);
				if (!file->ReadFloat32(&(offset_data_group_->influence)))return maxon::Error();
				offset_data_groups->AppendPtr(offset_data_group_)iferr_return;
				break;
			}
			case 1:
			{
				maxon::PointerArray<PMX_Morph_vertex>* offset_data_vertexs = (maxon::PointerArray<PMX_Morph_vertex>*)offset_data_;
				PMX_Morph_vertex* offset_data_vertex_ = new PMX_Morph_vertex;
				if (offset_data_vertex_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_vertex_->vertex_index = ReadIndex(file, model_info_.vertex_index_size);
				if (!file->ReadVector32(&(offset_data_vertex_->translation)))return maxon::Error();
				offset_data_vertexs->AppendPtr(offset_data_vertex_)iferr_return;
				break;
			}
			case 2:
			{
				maxon::PointerArray<PMX_Morph_bone>* offset_data_bones = (maxon::PointerArray<PMX_Morph_bone>*)offset_data_;
				PMX_Morph_bone* offset_data_bone_ = new PMX_Morph_bone;
				if (offset_data_bone_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_bone_->bone_index = ReadIndex(file, model_info_.bone_index_size);
				if (!file->ReadVector32(&(offset_data_bone_->translation)))return maxon::Error();
				vec4 q_rotation;
				if (!file->ReadBytes(&q_rotation, sizeof(vec4)))return maxon::Error();
				vec3 rotation;
				rotation.x = -maxon::ATan2(2 * q_rotation.y * q_rotation.w + 2 * q_rotation.x * q_rotation.z, 1 - 2 * (q_rotation.x * q_rotation.x + q_rotation.y * q_rotation.y));
				rotation.y = -maxon::ASin(2 * (q_rotation.x * q_rotation.w - q_rotation.y * q_rotation.z));
				rotation.z = -maxon::ATan2(2 * q_rotation.z * q_rotation.w + 2 * q_rotation.x * q_rotation.y, 1 - 2 * (q_rotation.x * q_rotation.x + q_rotation.z * q_rotation.z));
				offset_data_bone_->rotation = rotation;
				offset_data_bones->AppendPtr(offset_data_bone_)iferr_return;
				break;
			}
			case 3:
			{
				maxon::PointerArray<PMX_Morph_UV>* offset_data_UVs = (maxon::PointerArray<PMX_Morph_UV>*)offset_data_;
				PMX_Morph_UV* offset_data_UV_ = new PMX_Morph_UV;
				if (offset_data_UV_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_UV_->vertex_index = ReadIndex(file, model_info_.vertex_index_size);
				if (!file->ReadBytes(&(offset_data_UV_->floats), sizeof(vec4)))return maxon::Error();
				offset_data_UVs->AppendPtr(offset_data_UV_)iferr_return;
				break;
			}
			case 4:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(vec4)))return maxon::Error();
				break;
			}
			case 5:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(vec4)))return maxon::Error();
				break;
			}
			case 6:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(vec4)))return maxon::Error();
				break;
			}
			case 7:
			{
				if (!file->Seek(model_info_.vertex_index_size + sizeof(vec4)))return maxon::Error();
				break;
			}
			case 8:
			{
				maxon::PointerArray<PMX_Morph_material>* offset_data_materials = (maxon::PointerArray<PMX_Morph_material>*)offset_data_;
				PMX_Morph_material* offset_data_material_ = new PMX_Morph_material;
				if (offset_data_material_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_material_->material_index = ReadIndex(file, model_info_.material_index_size);
				if (!file->ReadChar(&(offset_data_material_->blend_mode)))return maxon::Error();
				if (!file->ReadBytes(&(offset_data_material_->diffuse), sizeof(vec4)))return maxon::Error();
				if (!file->ReadVector32(&(offset_data_material_->specular)))return maxon::Error();
				if (!file->ReadFloat32(&(offset_data_material_->specularity)))return maxon::Error();
				if (!file->ReadVector32(&(offset_data_material_->ambient)))return maxon::Error();
				if (!file->ReadBytes(&(offset_data_material_->edge_colour), sizeof(vec4)))return maxon::Error();
				if (!file->ReadFloat32(&(offset_data_material_->edge_size)))return maxon::Error();
				if (!file->ReadBytes(&(offset_data_material_->texture_tint), sizeof(vec4)))return maxon::Error();
				if (!file->ReadBytes(&(offset_data_material_->environment_tint), sizeof(vec4)))return maxon::Error();
				if (!file->ReadBytes(&(offset_data_material_->toon_tint), sizeof(vec4)))return maxon::Error();
				offset_data_materials->AppendPtr(offset_data_material_)iferr_return;
				break;
			}
			case 9:
			{
				maxon::PointerArray<PMX_Morph_flip>* offset_data_flips = (maxon::PointerArray<PMX_Morph_flip>*)offset_data_;
				PMX_Morph_flip* offset_data_flip_ = new PMX_Morph_flip;
				if (offset_data_flip_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_flip_->morph_index = ReadIndex(file, model_info_.morph_index_size);
				if (!file->ReadFloat32(&(offset_data_flip_->influence)))return maxon::Error();
				offset_data_flips->AppendPtr(offset_data_flip_)iferr_return;
				break;
			}
			case 10:
			{
				maxon::PointerArray<PMX_Morph_impulse>* offset_data_impulses = (maxon::PointerArray<PMX_Morph_impulse>*)offset_data_;
				PMX_Morph_impulse* offset_data_impulse_ = new PMX_Morph_impulse;
				if (offset_data_impulse_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				offset_data_impulse_->rigid_body_index = ReadIndex(file, model_info_.rigidbody_index_size);
				if (!file->ReadChar(&(offset_data_impulse_->local_flag)))return maxon::Error();
				if (!file->ReadVector32(&(offset_data_impulse_->movement_speed)))return maxon::Error();
				if (!file->ReadVector32(&(offset_data_impulse_->rotation_torque)))return maxon::Error();
				offset_data_impulses->AppendPtr(offset_data_impulse_)iferr_return;
				break;
			}
			default:
			break;
			}
		}
		this->morph_data.Append(morph_data_)iferr_return;
	}
	file->ReadInt32(&(model_data_count_.display_data_count));
	for (Int32 i = 0; i < model_data_count_.display_data_count; i++)
	{
		PMX_Display_Data* display_data_ = new PMX_Display_Data;
		if (display_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		display_data_->display_name_local = ReadText(file, model_info_.text_encoding);
		display_data_->display_name_universal = ReadText(file, model_info_.text_encoding);
		if (!file->ReadChar(&(display_data_->special_flag)))return maxon::Error();
		if (!file->ReadInt32(&(display_data_->frame_count)))return maxon::Error();
		for (Int32 j = 0; j < display_data_->frame_count; j++)
		{
			PMX_Frame_data* Frame = new PMX_Frame_data;
			if (!file->ReadChar(&(Frame->frame_type)))return maxon::Error();
			if (Frame->frame_type == 1)//1:索引 - 变形
			{
				Frame->frame_data = ReadIndex(file, model_info_.morph_index_size);
			}
			else if (Frame->frame_type == 0)//0:索引-骨骼
			{
				Frame->frame_data = ReadIndex(file, model_info_.bone_index_size);
			}
			display_data_->Frames.Append(Frame)iferr_return;
		}
		this->display_data.Append(display_data_)iferr_return;
	}
	file->ReadInt32(&(model_data_count_.rigid_body_data_count));
	for (Int32 i = 0; i < model_data_count_.rigid_body_data_count; i++)
	{
		PMX_Rigid_Body_Data* rigid_body_data_ = new PMX_Rigid_Body_Data;
		if (rigid_body_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		rigid_body_data_->rigid_body_name_local = ReadText(file, model_info_.text_encoding);
		rigid_body_data_->rigid_body_name_universal = ReadText(file, model_info_.text_encoding);
		rigid_body_data_->related_bone_index = ReadIndex(file, model_info_.bone_index_size);
		if (!file->ReadChar(&(rigid_body_data_->group_id)))return maxon::Error();
		if (!file->ReadBytes(&(rigid_body_data_->non_collision_group), sizeof(PMX_Rigid_body_non_collision_group)))return maxon::Error();
		if (!file->ReadChar(&(rigid_body_data_->shape_type)))return maxon::Error();
		if (!file->ReadVector32(&(rigid_body_data_->shape_size)))return maxon::Error();
		if (!file->ReadVector32(&(rigid_body_data_->shape_position)))return maxon::Error();
		if (!file->ReadVector32(&(rigid_body_data_->shape_rotation)))return maxon::Error();
		if (!file->ReadFloat32(&(rigid_body_data_->mass)))return maxon::Error();
		if (!file->ReadFloat32(&(rigid_body_data_->move_attenuation)))return maxon::Error();
		if (!file->ReadFloat32(&(rigid_body_data_->rotation_damping)))return maxon::Error();
		if (!file->ReadFloat32(&(rigid_body_data_->repulsion)))return maxon::Error();
		if (!file->ReadFloat32(&(rigid_body_data_->friction_force)))return maxon::Error();
		if (!file->ReadChar(&(rigid_body_data_->physics_mode)))return maxon::Error();
		this->rigid_body_data.Append(rigid_body_data_)iferr_return;
	}
	file->ReadInt32(&(model_data_count_.joint_data_count));
	for (Int32 i = 0; i < model_data_count_.joint_data_count; i++)
	{
		PMX_Joint_Data* joint_data_ = new PMX_Joint_Data;
		if (joint_data_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		joint_data_->joint_name_local = ReadText(file, model_info_.text_encoding);
		joint_data_->joint_name_universal = ReadText(file, model_info_.text_encoding);
		if (!file->ReadChar(&(joint_data_->joint_type)))return maxon::Error();
		joint_data_->rigid_body_index_A = ReadIndex(file, model_info_.rigidbody_index_size);
		joint_data_->rigid_body_index_B = ReadIndex(file, model_info_.rigidbody_index_size);
		if (!file->ReadVector32(&(joint_data_->position)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->rotation)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->position_minimum)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->position_maximum)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->rotation_minimum)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->rotation_maximum)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->position_spring)))return maxon::Error();
		if (!file->ReadVector32(&(joint_data_->rotation_spring)))return maxon::Error();
		this->joint_data.Append(joint_data_)iferr_return;
	}
	this->model_data_count = model_data_count_;
	return maxon::OK;
}

maxon::Result<void> mmd::PMXModel::WriteToFile(BaseFile* const file) {
	return maxon::OK;
}

maxon::Result<void> mmd::PMXModel::FromFileImportModel(Float& PositionMultiple, PMX_Model_import_settings& settings) {
	iferr_scope;
	Filename fn;
	AutoAlloc<BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE))) {
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	if (!(fn.CheckSuffix("pmx"_s) || (fn.CheckSuffix("PMX"_s)))) {
		GePrint("Is not a PMX file!"_s);
		MessageDialog("Is not a PMX file!"_s);
		file.Free();
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, "not a PMX file"_s);
	}
	std::unique_ptr<PMXModel> pmx_model(new PMXModel);
	if (pmx_model == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	pmx_model->LoadFromFile(file)iferr_return;
	String path = fn.GetString();
	path.Delete(path.GetLength() - fn.GetFileString().GetLength(), fn.GetFileString().GetLength());
	file->Close();
	file.Free();
	if (settings.Import_multipart) {
		StatusSetText("Import..."_s);
		NameConversion name_conversion;
		BaseObject* model_ = BaseObject::Alloc(Onull);
		if (model_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		if (settings.Import_english) {
			model_->SetName("Model"_s);
		}
		else {
			model_->SetName(pmx_model->model_info.model_name_local);
		}
		doc->InsertObject(model_, nullptr, nullptr);
		BaseObject* meshes = nullptr;
		if (settings.Import_polygon) {
			meshes = BaseObject::Alloc(Onull);
			if (meshes == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			meshes->SetName("Meshes"_s);
			doc->InsertObject(meshes, model_, nullptr);
		}
		BaseObject* bones = nullptr;
		if (settings.Import_bone) {
			bones = BaseObject::Alloc(Onull);
			if (bones == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			bones->SetName("Bones"_s);
			doc->InsertObject(bones, model_, nullptr);
		}
		BaseTag* PMX_model_tag = model_->MakeTag(ID_PMX_MODEL_TAG);
		if (PMX_model_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		PMX_model_tag->SetParameter(DescID(ID_BASELIST_NAME), pmx_model->model_info.model_name_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(PMX_VERSION), pmx_model->model_info.version, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(MODEL_NAME_LOCAL), pmx_model->model_info.model_name_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(MODEL_NAME_UNIVERSAL), pmx_model->model_info.model_name_universal, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(COMMENTS_LOCAL), pmx_model->model_info.comments_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(COMMENTS_UNIVERSAL), pmx_model->model_info.comments_universal, DESCFLAGS_SET::NONE);
		maxon::HashMap<Int32, BaseObject*> bone_map;
		if (settings.Import_bone) {
			Int32 bone_data_count = pmx_model->model_data_count.bone_data_count;
			for (Int32 i = 0; i < bone_data_count; i++)
			{
				PMX_Bone_Data* bone_data_ = pmx_model->bone_data[i];
				BaseObject* bone = BaseObject::Alloc(Ojoint);
				if (bone == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				name_conversion.InitConver(bone_data_->bone_name_local);
				bone_map.Insert(i, bone)iferr_return;
			}
			EventAdd();
			if (settings.Import_english_check) {
				name_conversion.CheckUpdata();
			}
			else {
				name_conversion.AutoUpdata();
			}
			for (Int32 i = 0; i < bone_data_count; i++)
			{
				PMX_Bone_Data* bone_data_ = pmx_model->bone_data[i];
				if (bone_data_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (bone_data_->bone_name_universal == ""_s) {
					name_conversion.Conver(bone_data_->bone_name_local, bone_data_->bone_name_universal);
				}
				BaseObject* bone = bone_map.Find(i)->GetValue();
				if (bone == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (bone_data_->parent_bone_index == -1)
				{
					bone->SetFrozenPos((Vector)bone_data_->position * PositionMultiple);
					doc->InsertObject(bone, bones, nullptr);
				}
				else {
					bone->SetFrozenPos((Vector)(bone_data_->position - pmx_model->bone_data[bone_data_->parent_bone_index]->position) * PositionMultiple);
					auto parent_bone_ptr = bone_map.Find(bone_data_->parent_bone_index);
					if (parent_bone_ptr != nullptr) {
						doc->InsertObject(bone, parent_bone_ptr->GetValue(), nullptr);
					}
				}
				BaseTag* PMX_bone_tag = bone->MakeTag(ID_PMX_BONE_TAG);
				if (PMX_bone_tag == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				PMX_bone_tag->SetParameter(DescID(BONE_INDEX), String::IntToString(i), DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ID_BASELIST_NAME), bone_data_->bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_LOCAL), bone_data_->bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_UNIVERSAL), bone_data_->bone_name_universal, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_IS), settings.Import_english, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(POSITION), (Vector)bone_data_->position * PositionMultiple, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ROTATABLE), bone_data_->bone_flags.Rotatable, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(TRANSLATABLE), bone_data_->bone_flags.Translatable, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(VISIBLE), bone_data_->bone_flags.Is_visible, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ENABLED), bone_data_->bone_flags.Enabled, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(IS_IK), bone_data_->bone_flags.IK, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(LAYER), bone_data_->layer, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PHYSICS_AFTER_DEFORM), bone_data_->bone_flags.Physics_after_deform, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INDEXED_TAIL_POSITION), bone_data_->bone_flags.indexed_tail_position, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INHERIT_ROTATION), bone_data_->bone_flags.Inherit_rotation, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INHERIT_TRANSLATION), bone_data_->bone_flags.Inherit_translation, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(FIXED_AXIS), bone_data_->bone_flags.Fixed_axis, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(LOCAL_COORDINATE), bone_data_->bone_flags.Local_coordinate, DESCFLAGS_SET::NONE);
				if (bone_data_->bone_flags.indexed_tail_position == 1) {
					PMX_bone_tag->SetParameter(DescID(TAIL_INDEX), bone_data_->tail_index, DESCFLAGS_SET::NONE);
				}
				else
				{
					PMX_bone_tag->SetParameter(DescID(TAIL_POSITION), (Vector)bone_data_->position * PositionMultiple, DESCFLAGS_SET::NONE);
				}
				if (bone_data_->bone_flags.Local_coordinate) {
					PMX_bone_tag->SetParameter(DescID(BONE_LOCAL_X), (Vector)bone_data_->bone_local_X, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(DescID(BONE_LOCAL_Z), (Vector)bone_data_->bone_local_Z, DESCFLAGS_SET::NONE);
				}
				if (bone_data_->bone_flags.Fixed_axis == 1) {
					PMX_bone_tag->SetParameter(DescID(BONE_FIXED_AXIS), (Vector)bone_data_->bone_fixed_axis, DESCFLAGS_SET::NONE);
				}
				if (settings.Import_inherit) {
					if (bone_data_->bone_flags.Inherit_translation == 1)
					{
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), bone_data_->inherit_bone_parent_index, DESCFLAGS_SET::NONE);
						BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
						if (inherit_bone_parent_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_->inherit_bone_parent_index);
						if (inherit_bone_parent_link_ptr != nullptr)inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), bone_data_->inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
					if (bone_data_->bone_flags.Inherit_rotation == 1)
					{
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), bone_data_->inherit_bone_parent_index, DESCFLAGS_SET::NONE);
						BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
						if (inherit_bone_parent_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_->inherit_bone_parent_index);
						if (inherit_bone_parent_link_ptr != nullptr)inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), bone_data_->inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
				}
				if (settings.Import_ik) {
					if (bone_data_->bone_flags.IK == 1)
					{
						BaseTag* IK_tag = bone_map.Find((*(bone_data_->IK_links.End() - 1))->bone_index)->GetValue()->MakeTag(1019561);//Ik Tag ID : 1019561	
						if (settings.Import_english) {
							IK_tag->SetName(bone_data_->bone_name_universal);
						}
						else {
							IK_tag->SetName(bone_data_->bone_name_local);
						}
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_PREFERRED_WEIGHT), 1, DESCFLAGS_SET::NONE);
						BaseLink* target_link = BaseLink::Alloc();
						if (target_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						target_link->SetLink(bone);
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TARGET), target_link, DESCFLAGS_SET::NONE);
						BaseLink* tip_link = BaseLink::Alloc();
						if (tip_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						tip_link->SetLink(bone_map.Find(bone_data_->IK_target_index)->GetValue());
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TIP), tip_link, DESCFLAGS_SET::NONE);
						DynamicDescription* const ddesc = PMX_model_tag->GetDynamicDescription();
						if (ddesc == nullptr)return maxon::UnexpectedError(MAXON_SOURCE_LOCATION);
						DescID ik_link_id;
						MAXON_SCOPE
						{
						BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
						bc.SetString(DESC_NAME, bone_data_->bone_name_local);
						bc.SetData(DESC_PARENTGROUP, GeData { CUSTOMDATATYPE_DESCID, DescID(MODEL_IK_GRP) });
						ik_link_id = ddesc->Alloc(bc);
						}
						BaseLink* ik_link = BaseLink::Alloc();
						if (ik_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						ik_link->SetLink(IK_tag);
						PMX_model_tag->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
						for (auto IK_link : bone_data_->IK_links) {
							if (IK_link->has_limits == 1) {
								BaseObject* IK_link_bone = bone_map.Find(IK_link->bone_index)->GetValue();
								if (IK_link_bone != nullptr) {
									IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_PREFERRED_ROT), Vector(0, PI05,0), DESCFLAGS_SET::NONE);
								}
							}
						}
					}
				}
			}
		}
		/*struct point_info
		{
			CAPoseMorphTag* morph_tag;//The tag where it is.
			Int32 point_index;//Point converted index.
		};
		maxon::HashMap<Int32, point_info> vertex_info_map;*/
		Int32 part_surface_end = 0;
		Int32 material_data_count = pmx_model->model_data_count.material_data_count;
		for (Int32 j = 0; j < material_data_count; j++)
		{
			PMX_Material_Data* material_data = pmx_model->material_data[j];
			if (material_data == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			PolygonObject* part = nullptr;
			CAWeightTag* weight_tag = nullptr;
			if (settings.Import_polygon) {
				part = PolygonObject::Alloc(material_data->surface_count * 3, material_data->surface_count);
				if (part == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (settings.Import_english) {
					part->SetName("Material_" + String::IntToString(j));
				}
				else {
					part->SetName(material_data->material_name_local);
				}
				/*CAPoseMorphTag* morph_tag = nullptr;
				if (settings.Import_expression) {
					//Initialization morph tag.
					morph_tag = CAPoseMorphTag::Alloc();
					if (morph_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					part->InsertTag(morph_tag);
					morph_tag->InitMorphs();
				}*/
				Vector* part_points = part->GetPointW();
				if (part_points == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				CPolygon* part_polygon = part->GetPolygonW();
				if (part_polygon == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (settings.Import_weights) {
					weight_tag = CAWeightTag::Alloc();
					if (weight_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					part->InsertTag(weight_tag);
				}
				maxon::BaseArray<Int32> vertex_index;
				maxon::PointerArray<CPolygon> surfaces;
				Int32 surface_count = material_data->surface_count;
				for (Int32 i = 0, c = 0; i < surface_count; i++, c += 3)
				{
					CPolygon* surface = pmx_model->surface_data[i + part_surface_end];
					vertex_index.Append(surface->a)iferr_return;
					vertex_index.Append(surface->b)iferr_return;
					vertex_index.Append(surface->c)iferr_return;
					/*if (settings.Import_expression) {

						vertex_info_map.Insert(surface->a,point_info{ morph_tag, c })iferr_return;
						vertex_info_map.Insert(surface->b,point_info{ morph_tag, c + 1 })iferr_return;
						vertex_info_map.Insert(surface->c,point_info{ morph_tag, c + 2 })iferr_return;
					}*/
				}
				Int32 vertex_data_count = surface_count * 3;
				maxon::HashMap<Int32, Int32> bone_index_map;
				if (settings.Import_weights) {
					for (Int32 i = 0; i < vertex_data_count; i++) {
						PMX_Vertex_Data* vertex_data_ = pmx_model->vertex_data[vertex_index[i]];
						switch (vertex_data_->weight_deform_type)
						{
						case 0:
						{
							if (bone_index_map.Find(vertex_data_->weight_deform_B1.bone1) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B1.bone1, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B1.bone1)->GetValue()))iferr_return;
							}
							break;
						}
						case 1:
						{
							if (bone_index_map.Find(vertex_data_->weight_deform_B2.bone1) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B2.bone1, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B2.bone1)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_B2.bone2) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B2.bone2, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B2.bone2)->GetValue()))iferr_return;
							}
							break;
						}
						case 2:
						{
							if (bone_index_map.Find(vertex_data_->weight_deform_B4.bone1) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B4.bone1, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B4.bone1)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_B4.bone2) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B4.bone2, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B4.bone2)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_B4.bone3) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B4.bone3, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B4.bone3)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_B4.bone4) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_B4.bone4, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_B4.bone4)->GetValue()))iferr_return;
							}
							break;
						}
						case 3:
						{
							if (bone_index_map.Find(vertex_data_->weight_deform_S.bone1) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_S.bone1, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_S.bone1)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_S.bone2) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_S.bone2, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_S.bone2)->GetValue()))iferr_return;
							}
							break;
						}
						case 4:
						{
							if (bone_index_map.Find(vertex_data_->weight_deform_Q.bone1) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_Q.bone1, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_Q.bone1)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_Q.bone2) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_Q.bone2, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_Q.bone2)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_Q.bone3) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_Q.bone3, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_Q.bone3)->GetValue()))iferr_return;
							}
							if (bone_index_map.Find(vertex_data_->weight_deform_Q.bone4) == nullptr)
							{
								bone_index_map.Insert(vertex_data_->weight_deform_Q.bone4, weight_tag->AddJoint(bone_map.Find(vertex_data_->weight_deform_Q.bone4)->GetValue()))iferr_return;
							}
							break;
						}
						}
					}
				}

				maxon::ParallelFor::Dynamic(0, vertex_data_count, [&pmx_model, &part_points, &settings, &PositionMultiple, &weight_tag, &vertex_index, &bone_index_map](const Int32 i)->maxon::Result<void>
				{
					StatusSetSpin();
					if (settings.Import_weights) {
						PMX_Vertex_Data* vertex_data_ = pmx_model->vertex_data[vertex_index[i]];
						if (vertex_data_ == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						part_points[i] = (Vector)vertex_data_->position * PositionMultiple;
						switch (vertex_data_->weight_deform_type)
						{
						case 0:
						{
							if (!weight_tag->SetWeight(bone_index_map.Find(vertex_data_->weight_deform_B1.bone1)->GetValue(), i, 1))return maxon::Error();
							break;
						}
						case 1:
						{
							if (!weight_tag->SetWeight(bone_index_map.Find(vertex_data_->weight_deform_B2.bone1)->GetValue(), i, vertex_data_->weight_deform_B2.weight1))return maxon::Error();
							auto bone2_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_B2.bone2);
							if (!weight_tag->SetWeight(bone2_Index_ptr->GetValue(), i, 1 - vertex_data_->weight_deform_B2.weight1 + weight_tag->GetWeight(bone2_Index_ptr->GetValue(), i)))return maxon::Error();
							break;
						}
						case 2:
						{
							if (!weight_tag->SetWeight(bone_index_map.Find(vertex_data_->weight_deform_B4.bone1)->GetValue(), i, vertex_data_->weight_deform_B4.weight1))return maxon::Error();
							auto bone2_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_B4.bone2);
							if (!weight_tag->SetWeight(bone2_Index_ptr->GetValue(), i, vertex_data_->weight_deform_B4.weight2 + weight_tag->GetWeight(bone2_Index_ptr->GetValue(), i)))return maxon::Error();
							auto bone3_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_B4.bone3);
							if (!weight_tag->SetWeight(bone3_Index_ptr->GetValue(), i, vertex_data_->weight_deform_B4.weight3 + weight_tag->GetWeight(bone3_Index_ptr->GetValue(), i)))return maxon::Error();
							auto bone4_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_B4.bone4);
							if (vertex_data_->weight_deform_B4.weight4 > 0) {
								if (!weight_tag->SetWeight(bone4_Index_ptr->GetValue(), i, vertex_data_->weight_deform_B4.weight4 + weight_tag->GetWeight(bone4_Index_ptr->GetValue(), i)))return maxon::Error();
							}
							break;
						}
						case 3:
						{
							if (!weight_tag->SetWeight(bone_index_map.Find(vertex_data_->weight_deform_S.bone1)->GetValue(), i, vertex_data_->weight_deform_S.weight1))return maxon::Error();
							auto bone2_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_S.bone2);
							if (!weight_tag->SetWeight(bone2_Index_ptr->GetValue(), i, 1 - vertex_data_->weight_deform_S.weight1 + weight_tag->GetWeight(bone2_Index_ptr->GetValue(), i)))return maxon::Error();
							break;
						}
						case 4:
						{
							auto bone1_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_Q.bone1);
							if (!weight_tag->SetWeight(bone1_Index_ptr->GetValue(), i, vertex_data_->weight_deform_Q.weight1))return maxon::Error();
							auto bone2_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_Q.bone2);
							if (!weight_tag->SetWeight(bone2_Index_ptr->GetValue(), i, vertex_data_->weight_deform_Q.weight2 + weight_tag->GetWeight(bone2_Index_ptr->GetValue(), i)))return maxon::Error();
							auto bone3_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_Q.bone3);
							if (!weight_tag->SetWeight(bone3_Index_ptr->GetValue(), i, vertex_data_->weight_deform_Q.weight3 + weight_tag->GetWeight(bone3_Index_ptr->GetValue(), i)))return maxon::Error();
							auto bone4_Index_ptr = bone_index_map.Find(vertex_data_->weight_deform_Q.bone4);
							if (vertex_data_->weight_deform_Q.weight4 > 0) {
								if (!weight_tag->SetWeight(bone4_Index_ptr->GetValue(), i, vertex_data_->weight_deform_Q.weight4 + weight_tag->GetWeight(bone4_Index_ptr->GetValue(), i)))return maxon::Error();
							}
							break;
						}
						}
					}
					else {
						PMX_Vertex_Data* vertex_data_ = pmx_model->vertex_data[vertex_index[i]];
						if (vertex_data_ == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						part_points[i] = (Vector)vertex_data_->position * PositionMultiple;
					}
					StatusClear();
					return maxon::OK;
				})iferr_return;

				for (Int32 i = 0; i < vertex_data_count; i += 3) {
					CPolygon surface(i + 2, i + 1, i);
					surfaces.Append(surface)iferr_return;
				}
				part->Message(MSG_UPDATE);
				NormalTag* normal_tag = nullptr;
				NormalHandle normal_handle = nullptr;
				if (settings.Import_normal) {
					normal_tag = NormalTag::Alloc(material_data->surface_count);
					if (normal_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					normal_handle = normal_tag->GetDataAddressW();
					part->InsertTag(normal_tag);
				}
				UVWHandle uvw_handle = nullptr;
				UVWTag* uvw_tag = nullptr;
				if (settings.Import_uv) {
					uvw_tag = UVWTag::Alloc(material_data->surface_count);
					if (uvw_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					uvw_handle = uvw_tag->GetDataAddressW();
					part->InsertTag(uvw_tag);
				}
				maxon::ParallelFor::Dynamic(0, surface_count, [&pmx_model, &part_surface_end, &part_polygon, &settings, &surfaces, &normal_handle, &uvw_handle](const Int32 i)->maxon::Result<void>
				{
					iferr_scope;
					StatusSetSpin();
					CPolygon* surface = pmx_model->surface_data[i + part_surface_end];
					PMX_Vertex_Data* vertex0 = pmx_model->vertex_data[surface->c];
					PMX_Vertex_Data* vertex1 = pmx_model->vertex_data[surface->b];
					PMX_Vertex_Data* vertex2 = pmx_model->vertex_data[surface->a];
					if (vertex0 == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					if (vertex1 == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					if (vertex2 == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					part_polygon[i] = surfaces[i];
					if (settings.Import_normal) {
						Vector normal0 = (Vector)vertex0->normal;
						Vector normal1 = (Vector)vertex1->normal;
						Vector normal2 = (Vector)vertex2->normal;
						Vector normal3(0, 0, 0);
						normal0.Normalize();
						normal1.Normalize();
						normal2.Normalize();
						normal3.Normalize();
						NormalTag::Set(normal_handle, i, NormalStruct(normal0, normal1, normal2, normal3));
					}
					if (settings.Import_uv) {
						UVWTag::Set(uvw_handle, i, UVWStruct(Vector(vertex0->UV.x, vertex0->UV.y, 0), Vector(vertex1->UV.x, vertex1->UV.y, 0), Vector(vertex2->UV.x, vertex2->UV.y, 0)));
					}
					StatusClear();
					return maxon::OK;
				})iferr_return;
				surfaces.Reset();
				part->Message(MSG_UPDATE);
				part_surface_end += material_data->surface_count;
				part->SetPhong(true, true, 0.7853982);
				doc->InsertObject(part, meshes, nullptr);
				BaseObject* morphdeformer = BaseObject::Alloc(Oskin);
				if (morphdeformer == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				doc->InsertObject(morphdeformer, part, nullptr);
				EventAdd();
				doc->SetSelection(part);
				doc->SetMode(Mpolygons);
				BaseSelect* all_select = part->GetPolygonS();
				if (all_select == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				all_select->SelectAll(0, material_data->surface_count - 1);
				if (IsCommandEnabled(14039))CallCommand(14039);
				all_select->DeselectAll();
				doc->SetMode(Mmodel);
				doc->SetSelection(nullptr);
				EventAdd();
				/*if (settings.Import_expression) {
					//Add base morph to the tag.
					morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
					morph_tag->ExitEdit(doc, true);
					CAMorph* base_morph = morph_tag->AddMorph();
					if (base_morph == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					base_morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::POINTS);
					morph_tag->UpdateMorphs();
				}*/
			}
			Material* material = nullptr;
			if (settings.Import_material) {
				material = Material::Alloc();
				if (material == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (settings.Import_english) {
					material->SetName("Material_" + String::IntToString(j));
				}
				else {
					material->SetName(material_data->material_name_local);
				}
				BaseChannel* basecolor_channel = material->GetChannel(CHANNEL_COLOR);
				if (basecolor_channel == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				material->SetChannelState(CHANNEL_ALPHA, true);
				BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
				if (alpha_channel == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}

				if (material_data->texture_index == -1)
				{
					BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
					if (alpha_shader == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
					alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
					material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
					material->InsertShader(alpha_shader);
					BaseShader* basecolor_shader = BaseShader::Alloc(Xcolor);
					if (basecolor_shader == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					basecolor_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
					basecolor_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
					material->SetParameter(DescID(MATERIAL_COLOR_SHADER), basecolor_shader, DESCFLAGS_SET::NONE);
					material->InsertShader(basecolor_shader);
				}
				else {
					String texture = pmx_model->texture_data[material_data->texture_index];
					Filename texture_file(texture);
					AutoAlloc<BaseBitmap> bm;
					if (bm == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					bm->Init(path + texture);
					if (bm->GetChannelCount()&&(texture_file.CheckSuffix("png"_s) || texture_file.CheckSuffix("PNG"_s) || texture_file.CheckSuffix("Png"_s) || texture_file.CheckSuffix("pNg"_s) || texture_file.CheckSuffix("pnG"_s) || texture_file.CheckSuffix("PNg"_s) || texture_file.CheckSuffix("pNG"_s) || texture_file.CheckSuffix("tga"_s) || texture_file.CheckSuffix("TGA"_s) || texture_file.CheckSuffix("Tga"_s) || texture_file.CheckSuffix("tGA"_s) || texture_file.CheckSuffix("tgA"_s) || texture_file.CheckSuffix("TGa"_s) || texture_file.CheckSuffix("tGA"_s)))
					{
						BaseContainer bc;
						bc = basecolor_channel->GetData();
						material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						basecolor_channel->SetData(bc);
						bc = alpha_channel->GetData();
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						alpha_channel->SetData(bc);
					}
					else {
						BaseContainer bc;
						bc = basecolor_channel->GetData();
						material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						basecolor_channel->SetData(bc);
						BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
						alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
						alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
						material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
						material->InsertShader(alpha_shader);
					}
				}
				doc->InsertMaterial(material);
				if (settings.Import_polygon) {
					TextureTag* texture_tag = TextureTag::Alloc();
					if (texture_tag == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					texture_tag->SetMaterial(material);
					texture_tag->SetName(material_data->material_name_local);
					texture_tag->SetParameter(DescID(TEXTURETAG_PROJECTION), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
					part->InsertTag(texture_tag);
				}
			}
			/*if (settings.Import_expression) {

				//Get the morph data count.
				Int32 morph_data_count = pmx_model->model_data_count.morph_data_count;

				maxon::HashMap<CAPoseMorphTag*, maxon::HashMap<String, CAMorph*>*> tag_morph_map;
				for (Int32 i = 0; i < morph_data_count; i++)
				{
					PMX_Morph_Data* morph_data = pmx_model->morph_data[i];
					if (morph_data->morph_type == 1) {
						maxon::PointerArray<PMX_Morph_vertex>* vertex_morph_data_arr = (maxon::PointerArray<PMX_Morph_vertex>*)morph_data->offset_data;
						Int32 offset_count = morph_data->offset_count;
						for (Int32 j = 0; j < offset_count; j++)
						{
							Int32 vertex_index = vertex_morph_data_arr->operator[](j).vertex_index;
							auto point_info_ptr = vertex_info_map.Find(vertex_index);
							if (point_info_ptr != nullptr) {
								point_info point_info_ = point_info_ptr->GetValue();

								auto vertex_morph_ptr = tag_morph_map.Find(point_info_.morph_tag);
								if (vertex_morph_ptr == nullptr) {
									maxon::HashMap<String, CAMorph*>* name_morph_map = new maxon::HashMap<String, CAMorph*>;
									CAMorph* morph = point_info_.morph_tag->AddMorph();
									if (morph == nullptr)
									{
										GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
										MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
										return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
									}
									morph->SetName(morph_data->morph_name_local);
									morph->Store(doc, point_info_.morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
									name_morph_map->Insert(morph_data->morph_name_local, morph)iferr_return;
									tag_morph_map.Insert(point_info_.morph_tag, name_morph_map)iferr_return;
								}
								else {
									maxon::HashMap<String, CAMorph*>* name_morph_map = vertex_morph_ptr->GetValue();
									auto name_morph_ptr = name_morph_map->Find(morph_data->morph_name_local);
									if (name_morph_ptr == nullptr) {
										CAMorph* morph = point_info_.morph_tag->AddMorph();
										if (morph == nullptr)
										{
											GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
											MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
											return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
										}
										morph->SetName(morph_data->morph_name_local);
										morph->Store(doc, point_info_.morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
										name_morph_map->Insert(morph_data->morph_name_local, morph)iferr_return;
									}
								}
							}
						}
					}
				}


				for (auto i : tag_morph_map.GetValues()) {
					delete i;
				}
			}*/
			if (settings.Import_weights) {
				weight_tag->SetBindPose(doc, false);
			}
		}
	}
	else {
		NameConversion name_conversion;
		BaseObject* model_ = BaseObject::Alloc(Onull);
		if (model_ == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		model_->SetName(pmx_model->model_info.model_name_local);
		doc->InsertObject(model_, nullptr, nullptr);
		BaseTag* PMX_model_tag = model_->MakeTag(ID_PMX_MODEL_TAG);
		if (PMX_model_tag == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		PMX_model_tag->SetParameter(DescID(ID_BASELIST_NAME), pmx_model->model_info.model_name_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(PMX_VERSION), pmx_model->model_info.version, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(MODEL_NAME_LOCAL), pmx_model->model_info.model_name_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(MODEL_NAME_UNIVERSAL), pmx_model->model_info.model_name_universal, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(COMMENTS_LOCAL), pmx_model->model_info.comments_local, DESCFLAGS_SET::NONE);
		PMX_model_tag->SetParameter(DescID(COMMENTS_UNIVERSAL), pmx_model->model_info.comments_universal, DESCFLAGS_SET::NONE);
		BaseObject* bones = nullptr;
		if (settings.Import_bone) {
			bones = BaseObject::Alloc(Onull);
			if (bones == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			bones->SetName("Bones"_s);
			doc->InsertObject(bones, model_, nullptr);
		}
		PolygonObject* model = nullptr;
		PointObject* model_point_obj = nullptr;
		Vector* model_points = nullptr;
		PolygonObject* model_polygon_obj = nullptr;
		CPolygon* model_polygon = nullptr;
		BaseSelect* select = nullptr;
		Int32 select_end = 0;
		if (settings.Import_polygon) {
			model = PolygonObject::Alloc(pmx_model->model_data_count.vertex_data_count, pmx_model->model_data_count.surface_data_count);
			if (model == nullptr) {
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			model->SetName("Mesh"_s);
			model_point_obj = ToPoint(model);
			model_points = model_point_obj->GetPointW();
			model_polygon_obj = ToPoly(model);
			model_polygon = model_polygon_obj->GetPolygonW();
		}
		CAWeightTag* weight_tag = nullptr;
		if (settings.Import_weights) {
			weight_tag = CAWeightTag::Alloc();
			if (weight_tag == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			model->InsertTag(weight_tag);
		}
		maxon::HashMap<Int32, BaseObject*> bone_map;
		if (settings.Import_bone) {
			for (Int32 i = 0; i < pmx_model->model_data_count.bone_data_count; i++)
			{
				PMX_Bone_Data* bone_data_ = pmx_model->bone_data[i];
				if (bone_data_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				BaseObject* bone = BaseObject::Alloc(Ojoint);
				if (bone == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				name_conversion.InitConver(bone_data_->bone_name_local);

				if (settings.Import_weights) {
					weight_tag->AddJoint(bone);
				}
				bone_map.Insert(i, bone)iferr_return;
			}
			EventAdd();
			if (settings.Import_english_check) {
				name_conversion.CheckUpdata();
			}
			else {
				name_conversion.AutoUpdata();
			}
			Int32 bone_data_count = pmx_model->model_data_count.bone_data_count;
			for (Int32 i = 0; i < bone_data_count; i++)
			{
				PMX_Bone_Data* bone_data_ = pmx_model->bone_data[i];
				if (bone_data_ == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (bone_data_->bone_name_universal == ""_s) {
					name_conversion.Conver(bone_data_->bone_name_local, bone_data_->bone_name_universal);
				}
				BaseObject* bone = bone_map.Find(i)->GetValue();
				if (bone == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (bone_data_->parent_bone_index == -1)
				{
					bone->SetFrozenPos((Vector)bone_data_->position * PositionMultiple);
					doc->InsertObject(bone, bones, nullptr);
				}
				else {
					bone->SetFrozenPos((Vector)(bone_data_->position - pmx_model->bone_data[bone_data_->parent_bone_index]->position) * PositionMultiple);
					auto parent_bone_ptr = bone_map.Find(bone_data_->parent_bone_index);
					if (parent_bone_ptr != nullptr) {
						doc->InsertObject(bone, parent_bone_ptr->GetValue(), nullptr);
					}
				}
				BaseTag* PMX_bone_tag = bone->MakeTag(ID_PMX_BONE_TAG);
				if (PMX_bone_tag == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				PMX_bone_tag->SetParameter(DescID(BONE_INDEX), String::IntToString(i), DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ID_BASELIST_NAME), bone_data_->bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_LOCAL), bone_data_->bone_name_local, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_UNIVERSAL), bone_data_->bone_name_universal, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(BONE_NAME_IS), settings.Import_english, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(POSITION), (Vector)bone_data_->position * PositionMultiple, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ROTATABLE), bone_data_->bone_flags.Rotatable, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(TRANSLATABLE), bone_data_->bone_flags.Translatable, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(VISIBLE), bone_data_->bone_flags.Is_visible, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(ENABLED), bone_data_->bone_flags.Enabled, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(IS_IK), bone_data_->bone_flags.IK, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(LAYER), bone_data_->layer, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(PHYSICS_AFTER_DEFORM), bone_data_->bone_flags.Physics_after_deform, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INDEXED_TAIL_POSITION), bone_data_->bone_flags.indexed_tail_position, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INHERIT_ROTATION), bone_data_->bone_flags.Inherit_rotation, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(INHERIT_TRANSLATION), bone_data_->bone_flags.Inherit_translation, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(FIXED_AXIS), bone_data_->bone_flags.Fixed_axis, DESCFLAGS_SET::NONE);
				PMX_bone_tag->SetParameter(DescID(LOCAL_COORDINATE), bone_data_->bone_flags.Local_coordinate, DESCFLAGS_SET::NONE);
				if (bone_data_->bone_flags.indexed_tail_position == 1) {
					PMX_bone_tag->SetParameter(DescID(TAIL_INDEX), bone_data_->tail_index, DESCFLAGS_SET::NONE);
				}
				else
				{
					PMX_bone_tag->SetParameter(DescID(TAIL_POSITION), (Vector)bone_data_->position * PositionMultiple, DESCFLAGS_SET::NONE);
				}
				if (bone_data_->bone_flags.Local_coordinate) {
					PMX_bone_tag->SetParameter(DescID(BONE_LOCAL_X), (Vector)bone_data_->bone_local_X, DESCFLAGS_SET::NONE);
					PMX_bone_tag->SetParameter(DescID(BONE_LOCAL_Z), (Vector)bone_data_->bone_local_Z, DESCFLAGS_SET::NONE);
				}
				if (bone_data_->bone_flags.Fixed_axis == 1) {
					PMX_bone_tag->SetParameter(DescID(BONE_FIXED_AXIS), (Vector)bone_data_->bone_fixed_axis, DESCFLAGS_SET::NONE);
				}
				if (settings.Import_inherit) {
					if (bone_data_->bone_flags.Inherit_translation == 1)
					{
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), bone_data_->inherit_bone_parent_index, DESCFLAGS_SET::NONE);
						BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
						if (inherit_bone_parent_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_->inherit_bone_parent_index);
						if (inherit_bone_parent_link_ptr != nullptr)inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), bone_data_->inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
					if (bone_data_->bone_flags.Inherit_rotation == 1)
					{
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INDEX), bone_data_->inherit_bone_parent_index, DESCFLAGS_SET::NONE);
						BaseLink* inherit_bone_parent_link = BaseLink::Alloc();
						if (inherit_bone_parent_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						auto inherit_bone_parent_link_ptr = bone_map.Find(bone_data_->inherit_bone_parent_index);
						if (inherit_bone_parent_link_ptr != nullptr)inherit_bone_parent_link->SetLink(inherit_bone_parent_link_ptr->GetValue());
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_LINK), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
						PMX_bone_tag->SetParameter(DescID(INHERIT_BONE_PARENT_INFLUENCE), bone_data_->inherit_bone_parent_influence, DESCFLAGS_SET::NONE);
					}
				}
				if (settings.Import_ik) {
					if (bone_data_->bone_flags.IK == 1)
					{
						BaseTag* IK_tag = bone_map.Find((*(bone_data_->IK_links.End() - 1))->bone_index)->GetValue()->MakeTag(1019561);//Ik Tag ID : 1019561	
						if (IK_tag == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						if (settings.Import_english) {
							IK_tag->SetName(bone_data_->bone_name_universal);
						}
						else {
							IK_tag->SetName(bone_data_->bone_name_local);
						}
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_PREFERRED_WEIGHT), 1, DESCFLAGS_SET::NONE);
						BaseLink* target_link = BaseLink::Alloc();
						if (target_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						target_link->SetLink(bone);
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TARGET), target_link, DESCFLAGS_SET::NONE);
						BaseLink* tip_link = BaseLink::Alloc();
						if (tip_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						tip_link->SetLink(bone_map.Find(bone_data_->IK_target_index)->GetValue());
						IK_tag->SetParameter(DescID(ID_CA_IK_TAG_TIP), tip_link, DESCFLAGS_SET::NONE);
						DynamicDescription* const ddesc = PMX_model_tag->GetDynamicDescription();
						if (ddesc == nullptr)return maxon::UnexpectedError(MAXON_SOURCE_LOCATION);
						DescID ik_link_id;
						MAXON_SCOPE
						{
						BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BASELISTLINK);
						bc.SetString(DESC_NAME, bone_data_->bone_name_local);
						bc.SetData(DESC_PARENTGROUP, GeData { CUSTOMDATATYPE_DESCID, DescID(MODEL_IK_GRP) });
						ik_link_id = ddesc->Alloc(bc);
						}
						BaseLink* ik_link = BaseLink::Alloc();
						if (ik_link == nullptr) {
							GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
							return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						}
						ik_link->SetLink(IK_tag);
						PMX_model_tag->SetParameter(ik_link_id, ik_link, DESCFLAGS_SET::NONE);
						for (auto IK_link : bone_data_->IK_links) {
							if (IK_link->has_limits == 1) {
								BaseObject* IK_link_bone = bone_map.Find(IK_link->bone_index)->GetValue();
								if (IK_link_bone != nullptr) {
									IK_link_bone->SetParameter(DescID(ID_CA_JOINT_OBJECT_JOINT_IK_PREFERRED_ROT), Vector(0, PI05, 0), DESCFLAGS_SET::NONE);
								}
							}
						}
					}
				}
			}
		}
		bone_map.Reset();
		if (settings.Import_polygon) {
			Int32 vertex_data_count = pmx_model->model_data_count.vertex_data_count;
			maxon::ParallelFor::Dynamic(0, vertex_data_count, [&vertex_data_count, &pmx_model, &model_points, &settings, &PositionMultiple, &weight_tag](const Int32 i)->maxon::Result<void>
			{
				StatusSetSpin();
				if (settings.Import_weights) {
					PMX_Vertex_Data* vertex_data_ = pmx_model->vertex_data[i];
					if (vertex_data_ == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					model_points[i] = (Vector)vertex_data_->position * PositionMultiple;
					switch (vertex_data_->weight_deform_type)
					{
					case 0:
					{
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B1.bone1, i, 1))return maxon::Error();
						break;
					}
					case 1:
					{
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B2.bone1, i, vertex_data_->weight_deform_B2.weight1))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B2.bone2, i, 1 - vertex_data_->weight_deform_B2.weight1 + weight_tag->GetWeight(vertex_data_->weight_deform_B2.bone2, i)))return maxon::Error();
						break;
					}
					case 2:
					{
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B4.bone1, i, vertex_data_->weight_deform_B4.weight1))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B4.bone2, i, vertex_data_->weight_deform_B4.weight2 + weight_tag->GetWeight(vertex_data_->weight_deform_B4.bone2, i)))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_B4.bone3, i, vertex_data_->weight_deform_B4.weight3 + weight_tag->GetWeight(vertex_data_->weight_deform_B4.bone3, i)))return maxon::Error();
						if (vertex_data_->weight_deform_B4.weight4 > 0.0) {
							if (!weight_tag->SetWeight(vertex_data_->weight_deform_B4.bone4, i, vertex_data_->weight_deform_B4.weight4 + weight_tag->GetWeight(vertex_data_->weight_deform_B4.bone4, i)))return maxon::Error();
						}
						break;
					}
					case 3:
					{
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_S.bone1, i, vertex_data_->weight_deform_S.weight1))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_S.bone2, i, 1 - vertex_data_->weight_deform_S.weight1 + weight_tag->GetWeight(vertex_data_->weight_deform_S.bone2, i)))return maxon::Error();
						break;
					}
					case 4:
					{
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_Q.bone1, i, vertex_data_->weight_deform_Q.weight1))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_Q.bone2, i, vertex_data_->weight_deform_Q.weight2 + weight_tag->GetWeight(vertex_data_->weight_deform_Q.bone2, i)))return maxon::Error();
						if (!weight_tag->SetWeight(vertex_data_->weight_deform_Q.bone3, i, vertex_data_->weight_deform_Q.weight3 + weight_tag->GetWeight(vertex_data_->weight_deform_Q.bone3, i)))return maxon::Error();
						if (vertex_data_->weight_deform_Q.weight4 > 0.0) {
							if (!weight_tag->SetWeight(vertex_data_->weight_deform_Q.bone4, i, vertex_data_->weight_deform_Q.weight4 + weight_tag->GetWeight(vertex_data_->weight_deform_Q.bone4, i)))return maxon::Error();
						}
						break;
					}
					}
				}
				else {
					PMX_Vertex_Data* vertex_data_ = pmx_model->vertex_data[i];
					if (vertex_data_ == nullptr) {
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					model_points[i] = (Vector)vertex_data_->position * PositionMultiple;
				}
				StatusClear();
				return maxon::OK;
			})iferr_return;

			model_point_obj->Message(MSG_UPDATE);
			NormalTag* normal_tag = nullptr;
			NormalHandle normal_handle = nullptr;
			if (settings.Import_normal) {
				normal_tag = NormalTag::Alloc(pmx_model->model_data_count.surface_data_count);
				if (normal_tag == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				normal_handle = normal_tag->GetDataAddressW();
				model->InsertTag(normal_tag);
			}
			UVWTag* uvw_tag = nullptr;
			UVWHandle uvw_handle = nullptr;
			if (settings.Import_uv) {
				uvw_tag = UVWTag::Alloc(pmx_model->model_data_count.surface_data_count);
				if (uvw_tag == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				uvw_handle = uvw_tag->GetDataAddressW();
				model->InsertTag(uvw_tag);
			}
			Int32 surface_data_count = pmx_model->model_data_count.surface_data_count;
			maxon::ParallelFor::Dynamic(0, surface_data_count, [&pmx_model, &model_polygon, &settings, &surface_data_count, &normal_handle, &uvw_handle](const Int32 i)->maxon::Result<void>
			{
				iferr_scope;
				StatusSetSpin();
				CPolygon* surface = pmx_model->surface_data[i];
				PMX_Vertex_Data* vertex0 = pmx_model->vertex_data[surface->c];
				PMX_Vertex_Data* vertex1 = pmx_model->vertex_data[surface->b];
				PMX_Vertex_Data* vertex2 = pmx_model->vertex_data[surface->a];
				if (vertex0 == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (vertex1 == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (vertex2 == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				model_polygon[i] = CPolygon(surface->c, surface->b, surface->a);
				if (settings.Import_normal) {
					Vector normal0 = (Vector)vertex0->normal;
					Vector normal1 = (Vector)vertex1->normal;
					Vector normal2 = (Vector)vertex2->normal;
					Vector normal3(0, 0, 0);
					normal0.Normalize();
					normal1.Normalize();
					normal2.Normalize();
					normal3.Normalize();
					NormalTag::Set(normal_handle, i, NormalStruct(normal0, normal1, normal2, normal3));
				}
				if (settings.Import_uv) {
					UVWTag::Set(uvw_handle, i, UVWStruct(Vector(vertex0->UV.x, vertex0->UV.y, 0), Vector(vertex1->UV.x, vertex1->UV.y, 0), Vector(vertex2->UV.x, vertex2->UV.y, 0)));
				}
				StatusClear();
				return maxon::OK;
			})iferr_return;
			model->SetPhong(true, true, 0.7853982);
			doc->InsertObject(model, model_, nullptr);
			BaseObject* morphdeformer = BaseObject::Alloc(Oskin);
			if (morphdeformer == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			doc->InsertObject(morphdeformer, model, nullptr);
			EventAdd();
			doc->SetMode(Mpolygons);
			select = model->GetPolygonS();
		}
		if (settings.Import_expression) {
			//Initialization morph tag.
			CAPoseMorphTag* morph_tag = CAPoseMorphTag::Alloc();
			if (morph_tag == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			model->InsertTag(morph_tag);
			morph_tag->InitMorphs();

			//Add base morph to the tag.
			morph_tag->SetParameter(ID_CA_POSE_POINTS, true, DESCFLAGS_SET::NONE);
			morph_tag->ExitEdit(doc, true);
			CAMorph* base_morph = morph_tag->AddMorph();
			if (base_morph == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			}
			base_morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::POINTS);
			morph_tag->UpdateMorphs();

			//Get the morph data count.
			Int32 morph_data_count = pmx_model->model_data_count.morph_data_count;

			for (Int32 i = 0; i < morph_data_count; i++)
			{
				StatusSetText("Import morphs..."_s);
				StatusSetBar(i * 100 / morph_data_count);
				PMX_Morph_Data* morph_data = pmx_model->morph_data[i];
				if (morph_data->morph_type == 1) {
					maxon::PointerArray<PMX_Morph_vertex>* vertex_morph_data_arr = (maxon::PointerArray<PMX_Morph_vertex>*)morph_data->offset_data;
					Int32 offset_count = morph_data->offset_count;

					morph_tag->ExitEdit(doc, true);
					CAMorph* morph = morph_tag->AddMorph();
					if (morph == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					morph->SetName(morph_data->morph_name_local);
					morph->Store(doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
					CAMorphNode* morp_node = morph->GetFirst();
					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
					//Set the position of the deformed point.
					//Move the point.
					maxon::ParallelFor::Dynamic(0, offset_count, [&morp_node, &vertex_morph_data_arr, &PositionMultiple](const Int32 pointIndex)
					{
						Vector point_translation = (Vector)vertex_morph_data_arr->operator[](pointIndex).translation * PositionMultiple;
						morp_node->SetPoint(vertex_morph_data_arr->operator[](pointIndex).vertex_index, point_translation);
					});

					morph->SetMode(doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					//Update point data.
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
				}
			}
			//Set "ID_CA_POSE_MODE" parameter to animation.
			morph_tag->SetParameter(DescID(ID_CA_POSE_MODE), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
		}

		if (settings.Import_material) {
			Int32 material_data_count = pmx_model->model_data_count.material_data_count;
			for (Int32 i = 0; i < material_data_count; i++)
			{
				StatusSetText("Import materials..."_s);
				StatusSetBar(i * 100 / material_data_count);
				PMX_Material_Data* material_data = pmx_model->material_data[i];
				if (material_data == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				Material* material = Material::Alloc();
				if (material == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				material->SetName(material_data->material_name_local);
				BaseChannel* basecolor_channel = material->GetChannel(CHANNEL_COLOR);
				if (basecolor_channel == nullptr)
				{
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				material->SetChannelState(CHANNEL_ALPHA, true);
				BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
				if (basecolor_channel == nullptr) {
					GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
				}
				if (material_data->texture_index == -1)
				{
					BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
					if (alpha_shader == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
					alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
					material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
					material->InsertShader(alpha_shader);
					BaseShader* basecolor_shader = BaseShader::Alloc(Xcolor);
					if (basecolor_shader == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					basecolor_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
					basecolor_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
					material->SetParameter(DescID(MATERIAL_COLOR_SHADER), basecolor_shader, DESCFLAGS_SET::NONE);
					material->InsertShader(basecolor_shader);
				}
				else
				{
					String texture = pmx_model->texture_data[material_data->texture_index];
					Filename texture_file(texture);
					AutoAlloc<BaseBitmap> bm;
					bm->Init(path + texture);
					if (bm->GetChannelCount() && (texture_file.CheckSuffix("png"_s) || texture_file.CheckSuffix("PNG"_s) || texture_file.CheckSuffix("Png"_s) || texture_file.CheckSuffix("pNg"_s) || texture_file.CheckSuffix("pnG"_s) || texture_file.CheckSuffix("PNg"_s) || texture_file.CheckSuffix("pNG"_s) || texture_file.CheckSuffix("tga"_s) || texture_file.CheckSuffix("TGA"_s) || texture_file.CheckSuffix("Tga"_s) || texture_file.CheckSuffix("tGA"_s) || texture_file.CheckSuffix("tgA"_s) || texture_file.CheckSuffix("TGa"_s) || texture_file.CheckSuffix("tGA"_s)))
					{
						BaseContainer bc;
						bc = basecolor_channel->GetData();
						material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						basecolor_channel->SetData(bc);
						bc = alpha_channel->GetData();
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						alpha_channel->SetData(bc);
					}
					else {
						BaseContainer bc;
						bc = basecolor_channel->GetData();
						material->SetParameter(DescID(MATERIAL_COLOR_COLOR), Vector(material_data->diffuse_colour), DESCFLAGS_SET::NONE);
						bc.SetString(BASECHANNEL_TEXTURE, path + texture);
						basecolor_channel->SetData(bc);
						BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
						alpha_shader->SetParameter(DescID(COLORSHADER_COLOR), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
						alpha_shader->SetParameter(DescID(COLORSHADER_BRIGHTNESS), material_data->diffuse_colour.w, DESCFLAGS_SET::NONE);
						material->SetParameter(DescID(MATERIAL_ALPHA_SHADER), alpha_shader, DESCFLAGS_SET::NONE);
						material->InsertShader(alpha_shader);
					}
				}
				doc->InsertMaterial(material);
				if (settings.Import_polygon) {
					doc->SetSelection(model);
					select->SelectAll(select_end, select_end + material_data->surface_count - 1);
					select_end += material_data->surface_count;
					CallCommand(12552);
					doc->GetActiveTag()->SetName(material_data->material_name_local);
					TextureTag* texture_tag = TextureTag::Alloc();
					if (texture_tag == nullptr)
					{
						GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
					}
					texture_tag->SetMaterial(material);
					texture_tag->SetName(material_data->material_name_local);
					texture_tag->SetParameter(DescID(TEXTURETAG_RESTRICTION), material_data->material_name_local, DESCFLAGS_SET::NONE);
					texture_tag->SetParameter(DescID(TEXTURETAG_PROJECTION), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
					model->InsertTag(texture_tag, doc->GetActiveTag());
				}
			}
		}
		EventAdd();
		if (settings.Import_polygon) {
			select->SelectAll(0, model->GetPolygonCount() - 1);
			//CallCommand(14039);
			select->DeselectAll();
			doc->SetMode(Mmodel);
			doc->SetSelection(nullptr);
		}
		if (settings.Import_weights) {
			weight_tag->SetBindPose(doc, false);
			CAWeightMgr::NormalizeWeights(doc);
		}
	}
	StatusClear();
	return maxon::OK;
}

maxon::Result<void> mmd::PMXModel::FromDocumentExportModel(Float& PositionMultiple, PMX_Model_export_settings& settings) {
	return maxon::OK;
}