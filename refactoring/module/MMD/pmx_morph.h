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
#include "pmx_element.hpp"
#include "pmx_model_info.h"

class PMXMorphOffsetBase : public PMXElement
{
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXMorphOffsetBase(const PMXModelInfo* model_info) : PMXElement(model_info){}
	/**
	 * \brief Destructor function
	 */
	~PMXMorphOffsetBase() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXMorphOffsetBase(PMXMorphOffsetBase&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXMorphOffsetBase& operator =(PMXMorphOffsetBase&& src) noexcept
	{
		if (this != &src)
		{
			m_model_info = src.m_model_info;
		}
		return *this;
	}
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXMorphOffsetBase)
public:
	Bool ReadFromFile(BaseFile* file) override = 0;
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXGroupMorphOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXGroupMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXGroupMorphOffset(PMXGroupMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXGroupMorphOffset& operator =(PMXGroupMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXVertexMorpOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXVertexMorpOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXVertexMorpOffset(PMXVertexMorpOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXVertexMorpOffset& operator =(PMXVertexMorpOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXBoneMorphOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXBoneMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXBoneMorphOffset(PMXBoneMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXBoneMorphOffset& operator =(PMXBoneMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXUVMorphOffset(const PMXModelInfo* model_info, const Int32& UV_type) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>(UV_type)) {}
	/**
	 * \brief Destructor function
	 */
	~PMXUVMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXUVMorphOffset(PMXUVMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXUVMorphOffset& operator =(PMXUVMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXMaterialMorphOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXMaterialMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXMaterialMorphOffset(PMXMaterialMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXMaterialMorphOffset& operator =(PMXMaterialMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXFlipMorphOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXFlipMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXFlipMorphOffset(PMXFlipMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXFlipMorphOffset& operator =(PMXFlipMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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
	/**
	 * \brief Default constructor function
	 */
	explicit PMXImpulseMorphOffset(const PMXModelInfo* model_info) :
	PMXMorphOffsetBase(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXImpulseMorphOffset() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXImpulseMorphOffset(PMXImpulseMorphOffset&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXImpulseMorphOffset& operator =(PMXImpulseMorphOffset&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
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

class PMXMorph final : public PMXElement
{
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXMorph(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXMorph() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXMorph(PMXMorph&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXMorph& operator =(PMXMorph&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXMorph)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXMorphData;
	std::unique_ptr<data_type> m_data;
};

#endif // !_PMX_MORPH_H_
