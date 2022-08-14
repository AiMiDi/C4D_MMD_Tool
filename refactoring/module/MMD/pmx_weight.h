/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/9
File:			pmx_weight.h
Description:	pmx weight data

**************************************************************************/

#ifndef _PMX_WEIGHT_H_
#define _PMX_WEIGHT_H_
#include "mmd_base.hpp"
#include "utils/pmx_util.hpp"

class PMXWeight : public MMDDataBase
{
protected:
	const PMXIndexReader& m_bone_index_reader;
	explicit PMXWeight(const PMXIndexReader& index_reader) : m_bone_index_reader(index_reader) {}
public:
	~PMXWeight() override = default;
	static PMXWeight* Alloc(const Char& type, const PMXIndexReader& index_reader);
};
/**
 * \brief Weight type BDEF1 (weight==1)
 */
class PMXWeight_BDEF1 final : public PMXWeight
{
	// Bone index. 
	Int32 bone = 0;
public:
	explicit PMXWeight_BDEF1(const PMXIndexReader& index_reader): PMXWeight(index_reader){}
	~PMXWeight_BDEF1() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};
/**
 * \brief Weight type BDEF2 (Bone2 weight = 1 - Bone1 weight)
 */
class PMXWeight_BDEF2 final : public PMXWeight
{
	// Bone index
	Int32	bone[2] = { 0 };
	// Bone 1 weight
	Float32 weight = 0.f;      
public:
	explicit PMXWeight_BDEF2(const PMXIndexReader& index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF2() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};
/**
 * \brief Weight type BDEF4 (The sum of four weights is not guaranteed to equal 1)
 */
class PMXWeight_BDEF4 final : public PMXWeight
{
	// Bone index
	Int32	bone[4] = { 0 };
	// Bone 1~4 weight
	Float32 weight[4] = { 0.f };
public:

	explicit PMXWeight_BDEF4(const PMXIndexReader& index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF4() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};
/**
 * \brief Weight type SDEF (Bone2 weight = 1 - Bone1 weight)
 */
class PMXWeight_SDEF final : public PMXWeight
{
	// Bone index
	Int32		bone[2] = { 0 };
	// Bone 1 weight
	Float32		weight = 0.f;
	// R0,R1,C
	Vector32	R0{}, R1{}, C{};
public:
	explicit PMXWeight_SDEF(const PMXIndexReader& index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_SDEF() override = default;
	Bool ReadFromFile(BaseFile* file) override;

};
/**
 * \brief Weight type QDEF (The sum of four weights is not guaranteed to equal 1)
 */
class PMXWeight_QDEF final : public PMXWeight
{
	// Bone index
	Int32	bone[4] = { 0 };
	// Bone 1~4 weight
	Float32 weight[4] = { 0.f };
public:
	explicit PMXWeight_QDEF(const PMXIndexReader& index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_QDEF() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};

#endif
