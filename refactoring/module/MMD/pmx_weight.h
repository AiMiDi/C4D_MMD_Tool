/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/9
File:			pmx_weight.h
Description:	pmx weight data

**************************************************************************/

#ifndef _PMX_WEIGHT_H_
#define _PMX_WEIGHT_H_

#include "pmx_element.hpp"
#include "pmx_model_info.h"

class PMXWeight : public PMXElement
{
protected:
	explicit PMXWeight(const PMXModelInfo* model_info) : PMXElement(model_info) {}
public:
	~PMXWeight() override = default;
	PMXWeight(PMXWeight&&) = delete;
	void operator =(PMXWeight&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight)
	static PMXWeight* Alloc(const Char& type, const PMXModelInfo* index_reader);
};
/**
 * \brief Weight type BDEF1 (weight==1)
 */
class PMXWeight_BDEF1 final : public PMXWeight
{
	// Bone index. 
	Int32 bone = 0;
public:
	explicit PMXWeight_BDEF1(const PMXModelInfo* index_reader): PMXWeight(index_reader){}
	~PMXWeight_BDEF1() override = default;
	PMXWeight_BDEF1(PMXWeight_BDEF1&&) = delete;
	void operator =(PMXWeight_BDEF1&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight_BDEF1)
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
	explicit PMXWeight_BDEF2(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF2() override = default;
	PMXWeight_BDEF2(PMXWeight_BDEF2&&) = delete;
	void operator =(PMXWeight_BDEF2&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight_BDEF2)
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

	explicit PMXWeight_BDEF4(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF4() override = default;
	PMXWeight_BDEF4(PMXWeight_BDEF4&&) = delete;
	void operator =(PMXWeight_BDEF4&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight_BDEF4)
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
	explicit PMXWeight_SDEF(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_SDEF() override = default;
	PMXWeight_SDEF(PMXWeight_SDEF&&) = delete;
	void operator =(PMXWeight_SDEF&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight_SDEF)
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
	explicit PMXWeight_QDEF(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_QDEF() override = default;
	PMXWeight_QDEF(PMXWeight_QDEF&&) = delete;
	void operator =(PMXWeight_QDEF&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXWeight_QDEF)
	Bool ReadFromFile(BaseFile* file) override;
};

#endif
