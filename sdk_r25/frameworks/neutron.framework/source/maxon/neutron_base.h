#ifndef NEUTRON_BASE_H__
#define NEUTRON_BASE_H__

#include "maxon/lib_math.h"
#include "maxon/nodesystem_class.h"

namespace maxon
{

namespace neutron
{

//----------------------------------------------------------------------------------------
/// This is the class of Neutron scene nodes.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(nodes::NodeSystemClass, NeutronNodeSystemClass, "net.maxon.neutron.nodesystemclass");


enum class OBJECT_FLAGS
{
	NONE = 0,
	VIEWPORT_VISIBLE = 1,
	RENDER_VISIBLE = 2,

	DEFAULT = VIEWPORT_VISIBLE | RENDER_VISIBLE,

	VISIBLE_MASK = VIEWPORT_VISIBLE | RENDER_VISIBLE
} MAXON_ENUM_FLAGS(OBJECT_FLAGS, "net.maxon.neutron.datatype.objectflags");

enum class TRANSFORM_MODE
{
	DISTRIBUTION = 0,
	CLONE = 1,
	CLONED_MESH = 2,
	MESH = 3
} MAXON_ENUM_LIST(TRANSFORM_MODE, "net.maxon.neutron.datatype.transformmode");

enum class INSTANCE_MATRIX_MODE
{
	NONE,
	LOCAL,
	GLOBAL
} MAXON_ENUM_LIST(INSTANCE_MATRIX_MODE, "net.maxon.neutron.datatype.instancematrixmode");


struct PRSMatrix
{
	static constexpr ROTATIONORDER DEFAULT_ORDER = ROTATIONORDER::YXZLOCAL;

	Vector					position;														///< The position.
	Vector					rotation;														///< The rotation.
	Vector					scale = Vector(1);									///< The scale.
	Vector					shear;															///< The shear.
	ROTATIONORDER		order = DEFAULT_ORDER;							///< The order.

	Matrix GetMatrix() const;

	void SetMatrix(const Matrix& matrix, ROTATIONORDER order = DEFAULT_ORDER);

	static PRSMatrix FromMatrix(const Matrix& matrix, ROTATIONORDER order = DEFAULT_ORDER)
	{
		PRSMatrix m;
		m.SetMatrix(matrix, order);
		return m;
	}

	MAXON_OPERATOR_STRUCT(PRSMatrix, position, rotation, scale, shear, order);
};

MAXON_DATATYPE(PRSMatrix, "net.maxon.neutron.datatype.psrmatrix");

#include "neutron_base1.hxx"
#include "neutron_base2.hxx"

}

}

#endif // NEUTRON_BASE_H__
