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
	CMT_DEFAULT_MOVE_BODY(PMXWeight)
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(PMXWeight)
protected:
	explicit PMXWeight(const PMXModelInfo* model_info) : PMXElement(model_info) {}
public:
	~PMXWeight() override = default;
	static PMXWeight* Alloc(const Char& type, const PMXModelInfo* index_reader);
};

struct PMXWeightData_BDEF1
{
	// Bone index. 
	Int32 bone = 0;
};
/**
 * \brief Weight type BDEF1 (weight==1)
 */
class PMXWeight_BDEF1 final : public PMXWeight
{
	GENERATE_MMD_CLASS_BODY(PMXWeight_BDEF1, PMXWeightData_BDEF1)
public:
	explicit PMXWeight_BDEF1(const PMXModelInfo* index_reader): PMXWeight(index_reader){}
	~PMXWeight_BDEF1() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};

struct PMXWeightData_BDEF2
{
	// Bone index
	Int32	bone[2] = { 0 };
	// Bone 1 weight
	Float32 weight = 0.f;  
};
/**
 * \brief Weight type BDEF2 (Bone2 weight = 1 - Bone1 weight)
 */
class PMXWeight_BDEF2 final : public PMXWeight
{
	GENERATE_MMD_CLASS_BODY(PMXWeight_BDEF2, PMXWeightData_BDEF2)
public:
	explicit PMXWeight_BDEF2(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF2() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};

struct PMXWeightData_BDEF4
{
	// Bone index
	Int32	bone[4] = { 0 };
	// Bone 1~4 weight
	Float32 weight[4] = { 0.f };
};
/**
 * \brief Weight type BDEF4 (The sum of four weights is not guaranteed to equal 1)
 */
class PMXWeight_BDEF4 final : public PMXWeight
{
	GENERATE_MMD_CLASS_BODY(PMXWeight_BDEF4, PMXWeightData_BDEF4)
public:
	explicit PMXWeight_BDEF4(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_BDEF4() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};

struct PMXWeightData_SDEF
{
	// Bone index
	Int32		bone[2] = { 0 };
	// Bone 1 weight
	Float32		weight = 0.f;
	// R0,R1,C
	Vector32	R0{}, R1{}, C{};
};
/**
 * \brief Weight type SDEF (Bone2 weight = 1 - Bone1 weight)
 */
class PMXWeight_SDEF final : public PMXWeight
{
	GENERATE_MMD_CLASS_BODY(PMXWeight_SDEF, PMXWeightData_SDEF)
public:
	explicit PMXWeight_SDEF(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_SDEF() override = default;
	Bool ReadFromFile(BaseFile* file) override;

};

struct PMXWeightData_QDEF
{
	// Bone index
	Int32	bone[4] = { 0 };
	// Bone 1~4 weight
	Float32 weight[4] = { 0.f };
};
/**
 * \brief Weight type QDEF (The sum of four weights is not guaranteed to equal 1)
 */
class PMXWeight_QDEF final : public PMXWeight
{
	GENERATE_MMD_CLASS_BODY(PMXWeight_QDEF, PMXWeightData_QDEF)
public:
	explicit PMXWeight_QDEF(const PMXModelInfo* index_reader) : PMXWeight(index_reader) {}
	~PMXWeight_QDEF() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};

#endif
