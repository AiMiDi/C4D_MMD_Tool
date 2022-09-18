/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/18
File:			pmx_morph.h
Description:	pmx morph data

**************************************************************************/

#ifndef _PMX_MORPH_H_
#define _PMX_MORPH_H_

#include "pch.h"
#include "mmd_base.hpp"
#include "pmx_model_info_data.h"

class PMXMorphOffsetBase : MMDDataBase
{
public:
	explicit PMXMorphOffsetBase(const PMXModelInfoData& model_info) : m_model_info(model_info){}
	~PMXMorphOffsetBase() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXMorphOffsetBase)
public:
	Bool ReadFromFile(BaseFile* file) override = 0;
protected:
	const PMXModelInfoData& m_model_info;
};

struct PMXGroupMorphOffsetData
{
	// Deformation index
	Int32	morph_index = 0;
	// Influence
	Float32 influence = 0.f;         
};

class PMXGroupMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXGroupMorphOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXGroupMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXGroupMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXGroupMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXVertexMorpOffsetData
{
	// Vertex index
	UInt32		vertex_index = 0;
	// Vertex position offset
	Vector32	position_offset{};       
};

class PMXVertexMorpOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXVertexMorpOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXVertexMorpOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXVertexMorpOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXVertexMorpOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXBoneMorphOffsetData
{
	// Bone index
	Int32		bone_index = 0;
	// Relative position of change
	Vector32	translation{};
	// Relative rotation quaternion (revolution Euler)
	Vector32	rotation{};          
};

class PMXBoneMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXBoneMorphOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXBoneMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXBoneMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXBoneMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXUVMorphOffsetData
{
	// UV type
	enum
	{
		UV, // UV
		UV1,// expansion UV1
		UV2,// expansion UV2
		UV3,// expansion UV3
		UV4 // expansion UV4
	};
	Int32 UV_type = UV;
	// Vertex index
	UInt32		vertex_index = 0;
	// Influence (only x and y are useful, Z and W are 0)
	Vector4d32	UV_offset;

	explicit PMXUVMorphOffsetData() = default;
	explicit PMXUVMorphOffsetData(const Int32& UV_type) : UV_type(UV_type){}
};

class PMXUVMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXUVMorphOffset(const PMXModelInfoData& model_info, const Int32& UV_type) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>(UV_type)) {}
	~PMXUVMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXUVMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXUVMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXMaterialMorphOffsetData
{
	// Material index
	Int32		material_index = 0;
	// Hybrid method
	Char		blend_mode = 0;
	// Diffuse (diffuse)
	Vector4d32	diffuse{};
	// Specular light (reflected color)
	Vector32	specular{};
	// Specular light intensity
	Float32		specularity = 0.f;
	// Ambient light (ambient color)
	Vector32	ambient{};
	// Edge color
	Vector4d32	edge_colour{};
	// Edge size
	Float32		edge_size = 0.f;
	// Texture tone
	Vector4d32	texture_tint{};
	// Environmental tone
	Vector4d32	environment_tint{};
	// Map hue
	Vector4d32	toon_tint{};
};

class PMXMaterialMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXMaterialMorphOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXMaterialMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXMaterialMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXMaterialMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXFlipMorphOffsetData
{
	// Deformation index
	Int32	morph_index = 0;
	// Influence
	Float32 influence = 0.f;
};

class PMXFlipMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXFlipMorphOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXFlipMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXFlipMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXFlipMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXImpulseMorphOffsetData
{
	// Rigid body index
	Int32		rigid_body_index = 0;
	// Local flag
	Char		local_flag = 0;
	// Moving speed
	Vector32	movement_speed{};
	// Rotational torque
	Vector32	rotation_torque{};
};

class PMXImpulseMorphOffset final : public PMXMorphOffsetBase
{
public:
	explicit PMXImpulseMorphOffset(const PMXModelInfoData& model_info) : PMXMorphOffsetBase(model_info) {}
	~PMXImpulseMorphOffset() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXImpulseMorphOffset)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXImpulseMorphOffsetData;
	std::unique_ptr<data_type> m_data;
};

struct PMXMorphData
{
	// Local deformation name
	String	morph_name_local{};
	// Generic deformation name
	String	morph_name_universal{};
	// Panel position, { 1,2,3,4 }，The position of the expression in the MMD panel
	Char	panel_type = 0;
	enum
	{
		GROUP,// 组合（Group）
		VERTEX,// 顶点（Vertex）
		BONE,// 骨骼（Bone）
		UV,// UV
		UV1,// expansion UV1
		UV2,// expansion UV2
		UV3,// expansion UV3
		UV4,// expansion UV4
		MATERIAL,// 材质（Material）
		FLIP,// 切换（Flip）
		IMPULSE// 脉冲（Impulse）
	};
	Char	morph_type = GROUP;
	// Number of offsets 
	Int32	offset_count = 0;
	// Offset data  
	maxon::BaseArray<std::unique_ptr<PMXMorphOffsetBase>> offset_data;
};

class PMXMorph final : MMDDataBase
{
public:
	explicit PMXMorph(PMXModelInfoData& model_info) : m_model_info(model_info) {}
	~PMXMorph() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXMorph)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXMorphData;
	std::unique_ptr<data_type> m_data;
	PMXModelInfoData& m_model_info;
};

#endif // !_PMX_MORPH_H_
