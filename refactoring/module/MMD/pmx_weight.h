/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/9
File:			pmx_weight.h
Description:	pmx weight data

**************************************************************************/

#ifndef _PMX_WEIGHT_H_
#define _PMX_WEIGHT_H_

class PMXWeight
{
public:
	virtual ~PMXWeight() = default;
	static void Free(PMXWeight*& m)
	{
		DeleteObj(m);
		m = nullptr;
	}
	virtual Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) = 0;
};
/* Weight type BDEF1
* weight==1 */
class PMXWeight_BDEF1 final : public PMXWeight
{

public:
	~PMXWeight_BDEF1() override = default;
	Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
	// Bone index. 
	Int32 bone = 0;

};
/* Weight type BDEF2
* Bone 2 weight = 1 - (Bone 1 weight) */
class PMXWeight_BDEF2 final : public PMXWeight
{
public:
	~PMXWeight_BDEF2() override = default;
	Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
	Int32	bone[2] = { 0 };                               /* Bone index. */
	Float32 weight = 0.f;                                      /* Bone 1 weight */
};
/* Weight type BDEF4
* The sum of four weights is not guaranteed to equal 1 */
class PMXWeight_BDEF4 final : public PMXWeight
{
public:
	~PMXWeight_BDEF4() override = default;
	Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
	Int32	bone[4] = { 0 };                   /* Bone index. */
	Float32 weight[4] = { 0.f };    /* Bone 1~4 weight */
};
/* Weight type SDEF
* Bone 2 weight = 1 - (Bone 1 weight) */
class PMXWeight_SDEF final : public PMXWeight
{
public:
	~PMXWeight_SDEF() override = default;
	Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
	Int32		bone[2] = { 0 };                             /* Bone index. */
	Float32		weight = 0.f;                                    /* Bone 1 weight */
	Vector32	R0 = Vector32(), R1 = Vector32(), C = Vector32(); /* R0,R1,C */
};
/* Weight type QDEF
* The sum of four weights is not guaranteed to equal 1 */
class PMXWeight_QDEF final : public PMXWeight
{
public:
	~PMXWeight_QDEF() override = default;
	Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
	Int32	bone[4] = { 0 };                /* Bone index. */
	Float32 weight[4] = { 0.f }; /* Bone 1~4 weight */
};

#endif
