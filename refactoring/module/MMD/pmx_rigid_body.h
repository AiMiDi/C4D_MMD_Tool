/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/24
File:			pmx_rigid_body.h
Description:	pmx rigid body data

**************************************************************************/

#ifndef _PMX_RIGID_BODY_H_
#define _PMX_RIGID_BODY_H_

#include "mmd_element.hpp"
#include "pmx_model_info.h"

struct PMXRigidBodyNonCollisionGroup
{
	Bool	G1 : 1;
	Bool	G2 : 1;
	Bool	G3 : 1;
	Bool	G4 : 1;
	Bool	G5 : 1;
	Bool	G6 : 1;
	Bool	G7 : 1;
	Bool	G8 : 1;
	Bool	G9 : 1;
	Bool	G10 : 1;
	Bool	G11 : 1;
	Bool	G12 : 1;
	Bool	G13 : 1;
	Bool	G14 : 1;
	Bool	G15 : 1;
	Bool	G16 : 1;

	explicit PMXRigidBodyNonCollisionGroup(
		const Bool G1_ =  false,
		const Bool G2_ =  false,
		const Bool G3_ =  false,
		const Bool G4_ =  false,
		const Bool G5_ =  false,
		const Bool G6_ =  false,
		const Bool G7_ =  false,
		const Bool G8_ =  false,
		const Bool G9_ =  false,
		const Bool G10_ = false,
		const Bool G11_ = false,
		const Bool G12_ = false,
		const Bool G13_ = false,
		const Bool G14_ = false,
		const Bool G15_ = false,
		const Bool G16_ = false):
		G1 (G1_ ),
		G2 (G2_ ),
		G3 (G3_ ),
		G4 (G4_ ),
		G5 (G5_ ),
		G6 (G6_ ),
		G7 (G7_ ),
		G8 (G8_ ),
		G9 (G9_ ),
		G10(G10_),
		G11(G11_),
		G12(G12_),
		G13(G13_),
		G14(G14_),
		G15(G15_),
		G16(G16_)
	{
		static_assert(sizeof PMXRigidBodyNonCollisionGroup == 2);
	}
};

struct PMXRigidBodyData
{
	// Rigid body local name 									
	String					rigid_body_name_local{};
	// Rigid body common name 
	String					rigid_body_name_universal{};
	// Associative bone index 
	Int32					related_bone_index = 0;
	// Group ID 
	Char					group_id = 0;
	// Collision exclusion group 
	PMXRigidBodyNonCollisionGroup	non_collision_group{};
	// Rigid body shape type
	enum
	{
		SPHERE,
		BOX,
		CAPSULE
	};
	Char		shape_type = SPHERE;
	// Shape size 
	Vector32	shape_size{};
	// Shape position   
	Vector32	shape_position{};
	// Shape rotation   
	Vector32	shape_rotation{};
	// mass   
	Float32		mass = 0.f;
	// Movement attenuation   
	Float32		move_attenuation = 0.f;
	// Rotation attenuation   
	Float32		rotation_damping = 0.f;
	// Reaction force   
	Float32		repulsion_force = 0.f;
	// friction force   
	Float32		friction_force = 0.f;
	// Physical mode
	enum
	{
		TRACKING_BONES,
		PHYSICAL_CALCULUS,
		PHYSICS_AND_BONE
	};
	Char physics_mode = TRACKING_BONES;
};

class PMXRigidBody final : MMDElement
{
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXRigidBody(const PMXModelInfo* model_info) : m_data(std::make_unique<data_type>()), m_model_info(model_info) {}
	/**
	 * \brief Destructor function
	 */
	~PMXRigidBody() override = default;
	/**
	 * \brief Move constructor
	 */
	PMXRigidBody(PMXRigidBody&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXRigidBody& operator =(PMXRigidBody&& src) noexcept
	{
		if (this != &src)
		{
			m_data = std::move(src.m_data);
			m_model_info = src.m_model_info;
		}
		return *this;
	}
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXRigidBody)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXRigidBodyData;
	std::unique_ptr<data_type> m_data;
	const PMXModelInfo* m_model_info;
};

#endif // !_PMX_RIGID_BODY_H_
