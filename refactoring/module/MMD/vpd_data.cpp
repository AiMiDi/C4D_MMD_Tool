/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vpd_data.cpp
Description:	vpd file data

**************************************************************************/

#include "pch.h"
#include "vpd_data.h"


Bool VPDFile::LoadFromFile(const Filename& fn) {
	iferr_scope_handler
	{
		return FALSE;
	};
	AutoAlloc<BaseFile> file;
	if (file == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return FALSE;
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		return FALSE;
	}
	const Int64 file_length = file->GetLength();
	/* 申请文件长度的内存 */
	std::string file_string(file_length, '\0');
	/* 将整个文件读取到申请的内存 */
	file->ReadBytes(file_string.data(), file_length);
	/* 将读取的字符转为UTF8 */
	file_string = code_conversion::SJIStoUTF8(file_string);
	/* file_length用于判断是否到达文件尾 */
	size_t is_read = 0;
	size_t read_pos;
	const size_t file_length_size = file_string.length();
	maxon::BaseArray<std::string_view> lines;
	while (is_read < file_length_size)
	{
		std::string_view line;
		/* 遇到 /r /n 截断字符串为一行并跳过 \r \n。 */
		if ((read_pos = file_string.find_first_of('\r', is_read)))
		{
			line = std::string_view(file_string.data() + is_read, read_pos - is_read);
			is_read = read_pos + 2;
		}
		/* 遇到 /n 截断字符串为一行并跳过 \n。 */
		else if ((read_pos = file_string.find_first_of('\n', is_read)))
		{
			line = std::string_view(file_string.data() + is_read, read_pos - is_read);
			is_read = read_pos + 1;

		}
		/* 如果非空则插入结果 */
		if (!line.empty())
		{
			lines.Append(line)iferr_return;
		}
	}
	if (lines.IsEmpty() || lines[0].compare(0, 24,"Vocaloid Pose Data file") != 0)
	{
		MessageDialog("VPD File Format Error."_s);
		return FALSE;
	}
	/* remove comment */
	for (auto& line : lines) {
		size_t comment_pos;
		if ((comment_pos = line.find_first_of("//"))) {
			line = line.substr(0, comment_pos);
		}
	}
	/* get model name */
	size_t semicolon_pos = lines[1].find_first_of(';');
	this->model_name = lines[1].substr(0, semicolon_pos).data();
	const Int64 line_count = lines.GetCount();
	for (Int64 i = 3; i < line_count; i += 4)
	{
		VPDBoneData& bone_post = this->m_bones.Append()iferr_return;
		const size_t curly_braces_pos = lines[i].find_first_of('{');
		bone_post.name = lines[i].substr(curly_braces_pos + 1, lines[i].length() - curly_braces_pos).data();
		size_t comma_pos = lines[i + 1].find_first_of(',');
		bone_post.translate.x = std::stof(lines[i + 1].substr(1, comma_pos - 1).data());
		size_t prec_comma_pos = comma_pos + 1;
		comma_pos = lines[i + 1].find_first_of(',', prec_comma_pos);
		bone_post.translate.y = std::stof(lines[i + 1].substr(prec_comma_pos, comma_pos - prec_comma_pos).data());
		prec_comma_pos = comma_pos + 1;
		semicolon_pos = lines[i + 1].find_first_of(';', prec_comma_pos);
		bone_post.translate.z = std::stof(lines[i + 1].substr(prec_comma_pos, semicolon_pos - prec_comma_pos).data());
		comma_pos = lines[i + 2].find_first_of(',');
		bone_post.rotation.x = std::stof(lines[i + 2].substr(1, comma_pos - 1).data());
		prec_comma_pos = comma_pos + 1;
		comma_pos = lines[i + 2].find_first_of(',', prec_comma_pos);
		bone_post.rotation.y = std::stof(lines[i + 2].substr(prec_comma_pos, comma_pos - prec_comma_pos).data());
		prec_comma_pos = comma_pos + 1;
		comma_pos = lines[i + 2].find_first_of(',', prec_comma_pos);
		bone_post.rotation.z = std::stof(lines[i + 2].substr(prec_comma_pos, comma_pos - prec_comma_pos).data());
		prec_comma_pos = comma_pos + 1;
		semicolon_pos = lines[i + 2].find_first_of(';', prec_comma_pos);
		bone_post.rotation.w = std::stof(lines[i + 2].substr(prec_comma_pos, semicolon_pos - prec_comma_pos).data());
	}
	return TRUE;
}
Bool VPDFile::SaveToFile(const Filename& fn) const
{
	std::string file_string;
	AutoAlloc<BaseFile> file;
	if (file == nullptr)
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return FALSE;
	}
	if (!file->Open(fn, FILEOPEN::WRITE, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA))
	{
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));

	}
	file_string.append("Vocaloid Pose Data file\r\n");
	file->WriteBytes(file_string.data(), static_cast<Int>(file_string.length()));
	return TRUE;
}
