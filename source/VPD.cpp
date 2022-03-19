#include "VPD.h"

maxon::Result<void> mmd::VPD_pose::LoadFromFile(Filename& fn) {
	iferr_scope;
	AutoAlloc<BaseFile> file;
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
	const Int64 all_char_length = file->GetLength();
	/* 申请文件长度的内存 */
	maxon::AutoMem<maxon::Char> all_char_mem = NewMemClear(maxon::Char, all_char_length) iferr_return;
	/* 将整个文件读取到申请的内存 */
	file->ReadBytes(all_char_mem, all_char_length);
	String all_char = String();
	/* 将读取的字符转为UTF8 */
	SJIStoUTF8(all_char_mem, all_char, all_char_length);
	/* file_length用于判断是否到达文件尾 */
	const Int64 file_length = all_char.GetLength();
	Int64 is_read = 0;
	Int32 read_pos = 0;
	maxon::BaseArray<String> lines;
	while (is_read < file_length)
	{
		String line = String();
		/* 遇到 /r /n 截断字符串为一行并跳过 /r /n。 */
		if (all_char.FindFirst('\r', &read_pos, is_read))
		{
			line = all_char.SubStr(is_read, read_pos - is_read);
			is_read = read_pos + 2;
		}
		/* 遇到 /n 截断字符串为一行并跳过 /n。 */
		else if (all_char.FindFirst('\n', &read_pos, is_read))
		{
			line = all_char.SubStr(is_read, read_pos - is_read);
			is_read = read_pos + 1;

		}
		/* 如果非空则插入结果 */
		if (!line.IsEmpty())
		{
			lines.Append(line)iferr_return;
		}
	}
	if (lines.IsEmpty() || lines[0].ComparePart("Vocaloid Pose Data file"_s, 24, 0) != 0)
	{
		MessageDialog("VPD File Format Error."_s);
		return maxon::Error();
	}
	/* remove comment */
	for (String& line : lines) {
		Int32 comment_pos;
		if (line.FindFirst("//"_s, &comment_pos)) {
			line = line.SubStr(0, comment_pos);
		}
	}
	Int32 semicolon_pos = 0;  /* ; */
	/* get model name */
	lines[1].FindFirst(';', &semicolon_pos);
	this->model_name = lines[1].SubStr(0, semicolon_pos);
	/* get bone number */
	lines[2].FindFirst(';', &semicolon_pos);
	Bool is_error = false;
	if (is_error) 
	{
		return maxon::Error();
	}
	Int32 curly_braces_pos = 0; /* { */
	Int32 comma_pos = 0;        /* , */
	Int32 prec_comma_pos = 0;
	const Int64 line_count = lines.GetCount();
	for (Int64 i = 3; i < line_count; i += 4)
	{
		VPDBoneData* bone_post = NewObj(VPDBoneData)iferr_return;
		lines[i].FindFirst('{', &curly_braces_pos);
		bone_post->name = lines[i].SubStr(curly_braces_pos + 1, lines[i].GetLength() - curly_braces_pos);		
		lines[i + 1].FindFirst(',', &comma_pos);
		bone_post->translate.x = maxon::SafeConvert<Float32>(lines[i + 1].SubStr(1, comma_pos - 1).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = comma_pos + 1;
		lines[i + 1].FindFirst(',', &comma_pos, prec_comma_pos);
		bone_post->translate.y = maxon::SafeConvert<Float32>(lines[i + 1].SubStr(prec_comma_pos, comma_pos - prec_comma_pos).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = comma_pos + 1;
		lines[i + 1].FindFirst(';', &semicolon_pos, prec_comma_pos);
		bone_post->translate.z = maxon::SafeConvert<Float32>(lines[i + 1].SubStr(prec_comma_pos, semicolon_pos - prec_comma_pos).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = 0;
		lines[i + 2].FindFirst(',', &comma_pos);
		bone_post->rotation.x = maxon::SafeConvert<Float32>(lines[i + 2].SubStr(1, comma_pos - 1).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = comma_pos + 1;
		lines[i + 2].FindFirst(',', &comma_pos, prec_comma_pos);
		bone_post->rotation.y = maxon::SafeConvert<Float32>(lines[i + 2].SubStr(prec_comma_pos, comma_pos - prec_comma_pos).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = comma_pos + 1;
		lines[i + 2].FindFirst(',', &comma_pos, prec_comma_pos);
		bone_post->rotation.z = maxon::SafeConvert<Float32>(lines[i + 2].SubStr(prec_comma_pos, comma_pos - prec_comma_pos).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = comma_pos + 1;
		lines[i + 2].FindFirst(';', &semicolon_pos, prec_comma_pos);
		bone_post->rotation.w = maxon::SafeConvert<Float32>(lines[i + 2].SubStr(prec_comma_pos, semicolon_pos - prec_comma_pos).ToFloat(&is_error));
		if (is_error)
		{
			return maxon::Error();
		}
		prec_comma_pos = 0;
		this->bones.AppendPtr(bone_post)iferr_return;
	}
	return maxon::OK;
}
maxon::Result<void> mmd::VPD_pose::SaveToFile(Filename& fn) {
	return maxon::OK;
}
maxon::Result<void> mmd::VPD_pose::FromFileImportPose(mmd::VPD_pose_import_settings setting) {
	iferr_scope;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	Filename fn;
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE)))
	{
		return(maxon::NullptrError(MAXON_SOURCE_LOCATION));
	}
	if (!(fn.CheckSuffix("vpd"_s) || (fn.CheckSuffix("VPD"_s))))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		return(maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR)));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	iferr(this->LoadFromFile(fn))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		return(maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR)));
	}
	maxon::HashMap<String, maxon::BaseList<BaseObject*>*>	bone_name_map;
	maxon::Queue<BaseObject*> nodes;
	nodes.Push(SelectObject) iferr_return;
	GeData data;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *(nodes.Pop());
		while (node != nullptr)
		{
			if (node->GetType() == Ojoint)
			{
				BaseTag* node_bone_tag = node->GetTag(ID_T_MMD_BONE);
				if (node_bone_tag != nullptr)
				{			
					node_bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
					String	bone_name = data.GetString();
					auto	bone_arr_ptr = bone_name_map.Find(bone_name);
					if (bone_arr_ptr == nullptr)
					{
						maxon::BaseList<BaseObject*>* bone_arr = NewObj(maxon::BaseList<BaseObject*>)iferr_return;
						bone_arr->Append(node) iferr_return;
						bone_name_map.Insert(bone_name, bone_arr) iferr_return;
					}
					else {
						bone_arr_ptr->GetValue()->Append(node) iferr_return;
					}
				}
				else {
					String	bone_name = node->GetName();
					auto	bone_arr_ptr = bone_name_map.Find(bone_name);
					if (bone_arr_ptr == nullptr)
					{
						maxon::BaseList<BaseObject*>* bone_arr = NewObj(maxon::BaseList<BaseObject*>)iferr_return;;
						bone_arr->Append(node) iferr_return;
						bone_name_map.Insert(bone_name, bone_arr) iferr_return;
					}
					else {
						bone_arr_ptr->GetValue()->Append(node) iferr_return;
					}
				}
			}
			nodes.Push(node->GetDown()) iferr_return;
			if (node != SelectObject)
			{
				node = node->GetNext();
			}
			else {
				break;
			}
		}
	}
	nodes.Reset();
	for (VPDBoneData& bone_data : this->bones) {
		auto bone_tag_list_ptr = bone_name_map.Find(bone_data.name);
		if (bone_tag_list_ptr != nullptr) {
			maxon::BaseList<BaseObject*>* bone_tag_list = bone_tag_list_ptr->GetValue();
			for (BaseObject* bone : *bone_tag_list) {
				bone->SetRelPos(Vector(bone_data.translate));
				bone->SetRelRot(QuaternionToEuler(bone_data.rotation));
			}
		}
	}
	EventAdd(EVENT::NONE);
	return maxon::OK;
}
maxon::Result<void> mmd::VPD_pose::FromDocumentExportPose(mmd::VPD_post_export_settings setting) {
	return maxon::OK;
}
