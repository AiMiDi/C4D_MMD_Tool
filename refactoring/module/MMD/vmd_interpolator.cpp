/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/11
File:			vmd_interpolator.cpp
Description:	MMD style animation interpolator

**************************************************************************/

#include "pch.h"
#include "vmd_interpolator.h"

UChar VMDInterpolator::GetValue(const PartType& part) const
{
	switch (part)
	{
	case PartType::ax:
		return this->m_ax;
	case PartType::bx:
		return this->m_bx;
	case PartType::ay:
		return this->m_ay;
	case PartType::by:
		return this->m_by;
	}
	return static_cast<UChar>(-1);
}

Bool VMDInterpolator::ReadBoneInterpolator(BaseFile* const file)
{
	if (!file->ReadUChar(&this->m_ax))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_ay))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_bx))
		return false;
	file->Seek(3);
	if (!file->ReadUChar(&this->m_by))
		return false;
	file->Seek(3);
	m_isLinear = m_ax == m_ay && m_bx == m_by;
	return true;
}

Bool VMDInterpolator::ReadCameraInterpolator(BaseFile* const file)
{
	UInt32 tmp = 0;
	if (!file->ReadUInt32(&tmp))
		return false;
	this->m_ax = static_cast<UChar>(((tmp & 0xFF) ^ 0x80) - 0x80);
	this->m_bx = static_cast<UChar>(((tmp & 0xFF00) >> 8 ^ 0x80) - 0x80);
	this->m_ay = static_cast<UChar>(((tmp & 0xFF0000) >> 16 ^ 0x80) - 0x80);
	this->m_by = static_cast<UChar>(((tmp & 0xFF000000) >> 24 ^ 0x80) - 0x80);
	m_isLinear = m_ax == m_ay && m_bx == m_by;
	return true;
}

Bool VMDInterpolator::WriteBoneInterpolator(BaseFile* const file) const
{
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	return true;
}

Bool VMDInterpolator::WriteCameraInterpolator(BaseFile* const file) const
{
	if (!file->WriteUChar(m_ax))
		return false;
	if (!file->WriteUChar(m_bx))
		return false;
	if (!file->WriteUChar(m_ay))
		return false;
	if (!file->WriteUChar(m_by))
		return false;
	return true;
}