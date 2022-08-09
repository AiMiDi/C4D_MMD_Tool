/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/9
File:			pmx_weight.cpp
Description:	pmx weight data

**************************************************************************/

#include "pch.h"
#include "pmx_weight.h"
#include "pmx_reader.hpp"

PMXWeight* PMXWeight::Alloc(const int& type)
{
	switch (type)
	{
	case 0:
		return NewObj(PMXWeight_BDEF1).GetValue();
	case 1:
		return NewObj(PMXWeight_BDEF2).GetValue();
	case 2:
		return NewObj(PMXWeight_BDEF4).GetValue();
	case 3:
		return NewObj(PMXWeight_SDEF).GetValue();
	case 4:
		return NewObj(PMXWeight_QDEF).GetValue();
	default:
	{
		DebugStop("PMXWeight::Alloc type error!"_s);
		return nullptr;
	}
	}
}

inline Bool PMXWeight_BDEF1::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
	this->bone = ReadPMXIndex(file, bone_index_size);
	return true;
}
inline Bool PMXWeight_BDEF2::ReadFromFile(BaseFile* file, const Char& bone_index_size) {
	this->bone[0] = ReadPMXIndex(file, bone_index_size);
	this->bone[1] = ReadPMXIndex(file, bone_index_size);
	if (!file->ReadFloat32(&(this->weight)))
		return false;
	return true;
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
