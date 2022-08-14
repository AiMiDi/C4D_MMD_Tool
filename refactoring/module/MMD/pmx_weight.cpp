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

PMXWeight* PMXWeight::Alloc(const Char& type, const PMXIndexReader& index_reader)
{
	switch (type)
	{
	case 0:
		return NewObj(PMXWeight_BDEF1, index_reader).GetValue();
	case 1:
		return NewObj(PMXWeight_BDEF2, index_reader).GetValue();
	case 2:
		return NewObj(PMXWeight_BDEF4, index_reader).GetValue();
	case 3:
		return NewObj(PMXWeight_SDEF, index_reader).GetValue();
	case 4:
		return NewObj(PMXWeight_QDEF, index_reader).GetValue();
	default:
	{
		DebugStop("PMXWeight::Alloc type error!"_s);
		return nullptr;
	}
	}
}

inline Bool PMXWeight_BDEF1::ReadFromFile(BaseFile* file) {
	this->bone = m_index_reader(file);
	return true;
}
inline Bool PMXWeight_BDEF2::ReadFromFile(BaseFile* file) {
	this->bone[0] = m_index_reader(file);
	this->bone[1] = m_index_reader(file);
	if (!file->ReadFloat32(&(this->weight)))
		return false;
	return true;
}
inline Bool PMXWeight_BDEF4::ReadFromFile(BaseFile* file) {
	this->bone[0] = m_index_reader(file);
	this->bone[1] = m_index_reader(file);
	this->bone[2] = m_index_reader(file);
	this->bone[3] = m_index_reader(file);
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
inline Bool PMXWeight_SDEF::ReadFromFile(BaseFile* file) {
	this->bone[0] = m_index_reader(file);
	this->bone[1] = m_index_reader(file);
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
inline Bool PMXWeight_QDEF::ReadFromFile(BaseFile* file) {
	this->bone[0] = m_index_reader(file);
	this->bone[1] = m_index_reader(file);
	this->bone[2] = m_index_reader(file);
	this->bone[3] = m_index_reader(file);
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
