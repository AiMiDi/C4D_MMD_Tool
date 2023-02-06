/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/24
File:			pmx_joint.h
Description:	pmx joint data

**************************************************************************/

#ifndef _PMX_JOINT_H_
#define _PMX_JOINT_H_

#include "pmx_element.hpp"
#include "pmx_model_info.h"

struct PMXJointData
{
	// Joint point local name 
	String	joint_name_local{};
	// Common name of joint point      
	String	joint_name_universal{};
	/*
	 * Joint point type
	 * 0 - Spring 6DOF
	 * 1 - 6DOF
	 * 2 - P2P - Point combination
	 * 3 - ConeTwist - Shaft rotation
	 * 4 - Slider - Axis movement
	 * 5 - Hinge - Shaft rotation
	 */
	enum
	{
		SPRING_6DOF,
		NON_SPRING_6DOF,
		P2P,
		CONE_TWIST,
		SLIDER,
		HINGE
	};
	Char		joint_type = SPRING_6DOF;
	// Rigid body index a
	Int32		rigid_body_index_A = 0;
	// Rigid body index b           
	Int32		rigid_body_index_B = 0;
	// Rigid body position           
	Vector32	position{};
	// rigid rotation           
	Vector32	rotation{};
	// Position min           
	Vector32	position_minimum{};
	// Position max            
	Vector32	position_maximum{};
	// Rotation min            
	Vector32	rotation_minimum{};
	// Rotation max            
	Vector32	rotation_maximum{};
	// Positioning spring            
	Vector32	position_spring{};
	// Rotating spring           
	Vector32	rotation_spring{};
};

class PMXJoint final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXJoint, PMXJointData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXJoint(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXJoint() override = default;
	/**
	 * \brief Read PMX joint data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_JOINT_H_
