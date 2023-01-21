/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/24
File:			pmx_bone.h
Description:	pmx bone data

**************************************************************************/

#ifndef _PMX_BONE_H_
#define _PMX_BONE_H_

#include "pch.h"
#include "pmx_element.hpp"
#include "pmx_model_info.h"

/* Bone flags(2bytes) */
struct PMXBoneFlags
{
	// The position of the tail (tip) of the bone, 0 is the relative position of the connection, and 1 is the connection sub bone 
	Bool	indexed_tail_position : 1;
	// Enable rotation 
	Bool	rotatable : 1;
	// Enable move 
	Bool	translatable : 1;
	// Enable display 
	Bool	is_visible : 1;
	// Enable action 
	Bool	enabled : 1;
	// Enable IK bone 
	Bool	is_IK : 1;
	// seize a seat 
	Bool : 2;
	// Turn on inherit bone rotation 
	Bool	inherit_rotation : 1;
	// Enable inherited bone movement 
	Bool	inherit_translation : 1;
	// Enable axis limit 
	Bool	fixed_axis : 1;
	// Enable local axis 
	Bool	local_coordinate : 1;
	// First deform, then calculate physics 
	Bool	physics_after_deform : 1;
	// External bony deformation 
	Bool	external_parent_deform : 1;
	// seize a seat 
	Bool : 2;

	// ReSharper disable once CppPossiblyUninitializedMember
	PMXBoneFlags()
	{
		indexed_tail_position = false;
		rotatable = true;
		translatable = false;
		is_visible = true;
		enabled = true;
		is_IK = false;
		inherit_rotation = false;
		inherit_translation = false;
		fixed_axis = false;
		local_coordinate = false;
		physics_after_deform = false;
		external_parent_deform = false;
	}
};

struct PMXIKLinks
{
	// Bone index
	Int32		bone_index = 0;
	// When the value is 1, the angle limit is used
	Bool		has_limits = false;
	// IK angle limit minimum angle (radians)
	Vector32	limit_min = {};
	// IK angle limit maximum angle (radians)
	Vector32	limit_max = {};
};

struct PMXBoneData
{
	// The local name of the skeleton, usually Japanese. 
	String			bone_name_local = {};
	// The common name of bones is usually English. 
	String			bone_name_universal = {};
	// Bone position 
	Vector32		position = {};
	// Bone affinity index, special: the bone affinity of the operation center is - 1 
	Int32			parent_bone_index = 0;
	// Deformation stratum 
	Int32			layer = 0;
	// Bone flags 
	PMXBoneFlags	bone_flags = {};
	// Bone tail coordinates (valid when relative on) 
	Vector32		tail_position = {};
	// Bone tail index (valid when it is relatively unopened) 
	Int32			tail_index = 0;
	/* 尾部位置,相对位置或连接子骨骼 */
	// Bone inheritance - bone affinity index 
	Int32			inherit_bone_parent_index = 0;
	// Bone inheritance - influence weights 
	Float32			inherit_bone_parent_influence = 0.f;
	// Bone fixed axis - axis direction 
	Vector32		bone_fixed_axis = Vector32();
	// Bone local coordinates - x vector 
	Vector32		bone_local_X = Vector32();
	// Bone local coordinates - Z vector 
	Vector32		bone_local_Z = Vector32();
	/* 跳过外亲骨(index) */
	// IK bone - target bone index 
	Int32			IK_target_index = 0;
	// IK bone - cycle count 
	Int32			IK_loop_count = 0;
	// IK bone - unit angle 
	Float32			IK_limit_radian = 0.f;
	// IK bone IK chain count 
	Int32			IK_link_count = 0;
	maxon::BaseArray<PMXIKLinks>	IK_links;
};

class PMXBone final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXBone, PMXBoneData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXBone(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>()){}
	/**
	 * \brief Destructor function
	 */
	~PMXBone() override = default;
	/**
	 * \brief Read PMX bone data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_BONE_H_
