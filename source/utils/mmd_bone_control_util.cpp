/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2026/5/15
File:			mmd_bone_control_util.cpp
Description:	MMD bone control utilities

**************************************************************************/

#include "module/core/cmt_old_sdk_stl_preload.h"
#include "utils/mmd_bone_control_util.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

#include <Eigen/Geometry>

#include "module/core/cmt_marco.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "ospline.h"
#include "plugin_resource.h"
#include "tprotection.h"
#include "description/TMMDBone.h"
#include "utils/io_util.hpp"

namespace
{
	constexpr Float kControlMediumRadius = 0.58;
	constexpr Int32 kCircleControlPointCount = 48;
	constexpr Float kTwoPi = 6.28318530717958647692;

	enum class ControlShape
	{
		Circle,
		Square,
		Diamond,
		Oval,
		Triangle
	};

	struct ControlVisualSpec
	{
		ControlShape shape = ControlShape::Circle;
		Float radius = kControlMediumRadius;
		Float aspect = 1.0;
	};

	Matrix MakeIdentityMatrix()
	{
		return Matrix{
			Vector(0.0),
			Vector(1.0, 0.0, 0.0),
			Vector(0.0, 1.0, 0.0),
			Vector(0.0, 0.0, 1.0)
		};
	}

	Matrix NormalizeMatrixBasis(const Matrix& matrix)
	{
		Matrix normalized = matrix;
		normalized.sqmat = normalized.sqmat.GetNormalized();
		return normalized;
	}

	Eigen::Matrix4f MatrixToEigen(const Matrix& matrix)
	{
		Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
		result(0, 0) = static_cast<float>(matrix.sqmat.v1.x);
		result(1, 0) = static_cast<float>(matrix.sqmat.v1.y);
		result(2, 0) = static_cast<float>(matrix.sqmat.v1.z);
		result(0, 1) = static_cast<float>(matrix.sqmat.v2.x);
		result(1, 1) = static_cast<float>(matrix.sqmat.v2.y);
		result(2, 1) = static_cast<float>(matrix.sqmat.v2.z);
		result(0, 2) = static_cast<float>(matrix.sqmat.v3.x);
		result(1, 2) = static_cast<float>(matrix.sqmat.v3.y);
		result(2, 2) = static_cast<float>(matrix.sqmat.v3.z);
		result(0, 3) = static_cast<float>(matrix.off.x);
		result(1, 3) = static_cast<float>(matrix.off.y);
		result(2, 3) = static_cast<float>(matrix.off.z);
		return result;
	}

	Matrix EigenToMatrix(const Eigen::Matrix4f& matrix)
	{
		Matrix result;
		result.sqmat.v1 = Vector(matrix(0, 0), matrix(1, 0), matrix(2, 0));
		result.sqmat.v2 = Vector(matrix(0, 1), matrix(1, 1), matrix(2, 1));
		result.sqmat.v3 = Vector(matrix(0, 2), matrix(1, 2), matrix(2, 2));
		result.off = Vector(matrix(0, 3), matrix(1, 3), matrix(2, 3));
		return NormalizeMatrixBasis(result);
	}

	std::array<Float32, 4> ToQuaternionArray(const Eigen::Quaternionf& rotation)
	{
		const Eigen::Quaternionf normalized = rotation.normalized();
		return { normalized.x(), normalized.y(), normalized.z(), normalized.w() };
	}

	Eigen::Quaternionf ExtractRotation(const Eigen::Matrix4f& matrix)
	{
		return Eigen::Quaternionf(matrix.block<3, 3>(0, 0)).normalized();
	}

	ROTATIONORDER GetObjectRotationOrder(BaseObject* object)
	{
		GeData rotation_order;
		if (object && object->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_ROTATION_ORDER)), rotation_order, DESCFLAGS_GET::NONE))
			return static_cast<ROTATIONORDER>(rotation_order.GetInt32());
		return ROTATIONORDER::DEFAULT;
	}

	void MarkSceneNodeDirty(BaseList2D* node)
	{
		if (!node)
			return;

		node->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
	}

	void MarkControlTransformDirty(BaseObject* object)
	{
		if (!object)
			return;

		object->Touch();
		object->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		object->Message(MSG_UPDATE);
		for (BaseTag* tag = object->GetFirstTag(); tag; tag = tag->GetNext())
			tag->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
	}

	Matrix BuildCurrentBoneGlobalMatrix(BaseObject* bone_object)
	{
		return bone_object ? NormalizeMatrixBasis(bone_object->GetMg()) : MakeIdentityMatrix();
	}

	Matrix BuildFrozenBoneGlobalMatrix(BaseObject* bone_object)
	{
		std::vector<BaseObject*> chain;
		BaseObject* current = bone_object;
		for (; current && current->GetTag(g_mmd_bone_tag_id); current = current->GetUp())
			chain.push_back(current);

		Matrix global = current ? NormalizeMatrixBasis(current->GetMg()) : MakeIdentityMatrix();
		for (auto it = chain.rbegin(); it != chain.rend(); ++it)
			global = NormalizeMatrixBasis(global * (*it)->GetFrozenMln());
		return global;
	}

	Vector TransformRestDirectionToCurrent(const Matrix& rest_matrix, const Matrix& current_matrix, const Vector& direction)
	{
		Vector normalized_direction = direction;
		if (normalized_direction.GetLength() <= EPSILON)
			return direction;
		normalized_direction.Normalize();

		const Eigen::Matrix3f rest_basis = MatrixToEigen(NormalizeMatrixBasis(rest_matrix)).block<3, 3>(0, 0);
		const Eigen::Matrix3f current_basis = MatrixToEigen(NormalizeMatrixBasis(current_matrix)).block<3, 3>(0, 0);
		const Eigen::Vector3f rest_direction(
			static_cast<float>(normalized_direction.x),
			static_cast<float>(normalized_direction.y),
			static_cast<float>(normalized_direction.z));
		const Eigen::Vector3f current_direction = current_basis * rest_basis.transpose() * rest_direction;
		Vector result(current_direction.x(), current_direction.y(), current_direction.z());
		if (result.GetLength() <= EPSILON)
			return normalized_direction;
		result.Normalize();
		return result;
	}

	Matrix BuildControlBaseGlobalMatrix(BaseObject* control)
	{
		if (!control)
			return MakeIdentityMatrix();

		BaseObject* const parent = control->GetUp();
		const Matrix parent_current = parent ? NormalizeMatrixBasis(parent->GetMg()) : MakeIdentityMatrix();
		return NormalizeMatrixBasis(parent_current * control->GetFrozenMln());
	}

	BaseObject* GetControlSiblingParent(BaseObject* bone_object, BaseObject* bone_manager_object)
	{
		BaseObject* const parent = bone_object ? bone_object->GetUp() : nullptr;
		return parent ? parent : bone_manager_object;
	}

	bool TryNormalize(Vector& vector)
	{
		if (vector.GetLength() <= EPSILON)
			return false;
		vector.Normalize();
		return true;
	}

	bool GetFixedAxis(const BaseContainer* bc, Vector& axis)
	{
		if (!bc || !bc->GetBool(PMX_BONE_IS_FIXED_AXIS))
			return false;
		axis = bc->GetVector(PMX_BONE_FIXED_AXIS);
		return TryNormalize(axis);
	}

	bool GetLocalBoneAxis(const BaseContainer* bc, Vector& axis)
	{
		if (!bc || !bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE))
			return false;
		axis = bc->GetVector(PMX_BONE_LOCAL_X);
		return TryNormalize(axis);
	}

	bool IsBoneControlEligible(const BaseContainer* bc)
	{
		return bc && (bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE) || bc->GetBool(PMX_BONE_IS_FIXED_AXIS));
	}

	bool ShouldUseTailPosition(const BaseContainer* bc)
	{
		if (!bc)
			return false;

		const Vector tail_position = bc->GetVector(PMX_BONE_TAIL_POSITION);
		const Int32 tail_mode = bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION);
		if (tail_mode == PMX_BONE_TAIL_IS_POSITION)
			return !tail_position.IsZero();

		// Older imported scenes can have PMX_BONE_INDEXED_TAIL_POSITION left at its
		// description default while PMX_BONE_TAIL_POSITION was still written.
		return tail_mode == PMX_BONE_TAIL_IS_INDEX &&
			bc->GetInt32(PMX_BONE_TAIL_INDEX) <= 0 &&
			!tail_position.IsZero();
	}

	bool GetTailBonePoint(MMDBoneManagerObject& bone_manager, const BaseContainer* bc, const Matrix& rest_matrix, const Matrix& current_matrix, BaseObject* bone_object, Vector& point)
	{
		if (bc)
		{
			if (!ShouldUseTailPosition(bc) && bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
			{
				const Int32 tail_index = bc->GetInt32(PMX_BONE_TAIL_INDEX);
				if (BaseTag* const tail_tag = bone_manager.FindBone(tail_index))
				{
					if (BaseObject* const tail_object = tail_tag->GetObject())
					{
						const Matrix tail_matrix = BuildCurrentBoneGlobalMatrix(tail_object);
						if ((tail_matrix.off - current_matrix.off).GetLength() > EPSILON)
						{
							point = tail_matrix.off;
							return true;
						}
					}
				}
			}
			if (ShouldUseTailPosition(bc))
			{
				const Vector tail_offset = TransformRestDirectionToCurrent(rest_matrix, current_matrix, bc->GetVector(PMX_BONE_TAIL_POSITION));
				if (tail_offset.GetLength() > EPSILON)
				{
					point = current_matrix.off + tail_offset;
					return true;
				}
			}
		}

		for (BaseObject* child = bone_object ? bone_object->GetDown() : nullptr; child; child = child->GetNext())
		{
			if (!child->GetTag(g_mmd_bone_tag_id))
				continue;
			const Matrix child_matrix = BuildCurrentBoneGlobalMatrix(child);
			if ((child_matrix.off - current_matrix.off).GetLength() > EPSILON)
			{
				point = child_matrix.off;
				return true;
			}
		}
		return false;
	}

	bool GetTailBoneAxis(MMDBoneManagerObject& bone_manager, const BaseContainer* bc, const Matrix& rest_matrix, const Matrix& current_matrix, BaseObject* bone_object, Vector& axis)
	{
		Vector tail_point;
		if (GetTailBonePoint(bone_manager, bc, rest_matrix, current_matrix, bone_object, tail_point))
		{
			axis = tail_point - current_matrix.off;
			if (TryNormalize(axis))
				return true;
		}
		return false;
	}

	Vector GetFallbackReference(const Matrix& rest, const Vector& normal)
	{
		Vector reference = rest.sqmat.v2;
		if ((reference - normal * Dot(reference, normal)).GetLength() > EPSILON)
			return reference;

		reference = rest.sqmat.v1;
		if ((reference - normal * Dot(reference, normal)).GetLength() > EPSILON)
			return reference;

		return std::abs(normal.y) < 0.95 ? Vector(0.0, 1.0, 0.0) : Vector(1.0, 0.0, 0.0);
	}

	Matrix BuildBasisFromNormal(const Matrix& fallback, Vector normal, Vector reference)
	{
		if (!TryNormalize(normal))
			normal = fallback.sqmat.v3;
		if (!TryNormalize(normal))
			normal = Vector(0.0, 0.0, 1.0);

		reference -= normal * Dot(reference, normal);
		if (!TryNormalize(reference))
			reference = GetFallbackReference(fallback, normal);
		reference -= normal * Dot(reference, normal);
		if (!TryNormalize(reference))
			reference = std::abs(normal.y) < 0.95 ? Vector(0.0, 1.0, 0.0) : Vector(1.0, 0.0, 0.0);

		Vector binormal = Cross(normal, reference);
		if (!TryNormalize(binormal))
			binormal = Vector(0.0, 1.0, 0.0);

		Matrix result = fallback;
		result.sqmat.v1 = reference;
		result.sqmat.v2 = binormal;
		result.sqmat.v3 = normal;
		return NormalizeMatrixBasis(result);
	}

	Int32 GetBoneHierarchyDepth(BaseObject* bone_object)
	{
		Int32 depth = 0;
		for (BaseObject* parent = bone_object ? bone_object->GetUp() : nullptr;
			parent && parent->GetTag(g_mmd_bone_tag_id);
			parent = parent->GetUp())
		{
			++depth;
		}
		return depth;
	}

	Float GetHierarchyRadiusScale(const Int32 depth)
	{
		return std::clamp(1.0 - static_cast<Float>(std::min(depth, 8)) * 0.025, 0.8, 1.0);
	}

	ControlVisualSpec GetControlVisualSpec(const BaseContainer* bc, BaseObject* bone_object)
	{
		const Float hierarchy_scale = GetHierarchyRadiusScale(GetBoneHierarchyDepth(bone_object));
		if (bc && bc->GetBool(PMX_BONE_IS_FIXED_AXIS) && !bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE))
			return { ControlShape::Diamond, kControlMediumRadius * hierarchy_scale, 1.0 };
		return { ControlShape::Circle, kControlMediumRadius * hierarchy_scale, 1.0 };
	}

	Vector GetControlColor(const String& local_name)
	{
		Int position = NOTOK;
		if (local_name.IsPopulated() && local_name.Find(String("左"), &position))
			return Vector(0.18, 0.45, 1.0);
		if (local_name.IsPopulated() && local_name.Find(String("右"), &position))
			return Vector(1.0, 0.24, 0.2);
		return Vector(0.2, 0.85, 0.42);
	}

	BaseObject* ResolveLinkedObjectParameter(BaseList2D* owner, const Int32 parameter_id)
	{
		if (!owner)
			return nullptr;

		GeData data;
		if (!owner->GetParameter(CreateDescID(DescLevel(parameter_id)), data, DESCFLAGS_GET::NONE))
			return nullptr;
		const BaseLink* const link = data.GetBaseLink();
		if (!link)
			return nullptr;

		const BaseDocument* const doc = owner->GetDocument();
		const BaseList2D* linked = doc ? link->GetLink(doc) : link->ForceGetLink();
		BaseList2D* const mutable_linked = const_cast<BaseList2D*>(linked);
		return mutable_linked && mutable_linked->IsInstanceOf(Obase) ? static_cast<BaseObject*>(mutable_linked) : nullptr;
	}

	void SetLinkedObjectParameter(BaseList2D* owner, const Int32 parameter_id, BaseObject* object)
	{
		if (!owner)
			return;

		BaseLink* const link = BaseLink::Alloc();
		if (!link)
			return;
		link->SetLink(object);
		owner->SetParameter(CreateDescID(DescLevel(parameter_id)), GeData(link), DESCFLAGS_SET::NONE);
	}

	void ClearLinkedObjectParameter(BaseList2D* owner, const Int32 parameter_id)
	{
		if (owner)
			owner->SetParameter(CreateDescID(DescLevel(parameter_id)), GeData(), DESCFLAGS_SET::NONE);
	}

	BaseObject* FindDescendantByName(BaseObject* parent, const String& name)
	{
		if (!parent || name.IsEmpty())
			return nullptr;
		for (BaseObject* child = parent->GetDown(); child; child = child->GetNext())
		{
			if (child->GetName() == name)
				return child;
			if (BaseObject* const descendant = FindDescendantByName(child, name))
				return descendant;
		}
		return nullptr;
	}

	bool IsSameOrDescendantOf(BaseObject* object, BaseObject* ancestor)
	{
		for (BaseObject* current = object; current != nullptr; current = current->GetUp())
		{
			if (current == ancestor)
				return true;
		}
		return false;
	}

	String GetControlBaseName(const BaseTag* bone_tag, const Int32 bone_index)
	{
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		const String local_name = bc ? bc->GetString(PMX_BONE_NAME_LOCAL) : String();
		const String universal_name = bc ? bc->GetString(PMX_BONE_NAME_UNIVERSAL) : String();
		const Bool use_local_name = !bc || bc->GetInt32(PMX_BONE_NAME_IS) == PMX_BONE_NAME_IS_LOCAL;

		String base_name;
		if (use_local_name)
		{
			base_name = local_name;
			if (base_name.IsEmpty())
				base_name = universal_name;
		}
		else
		{
			base_name = universal_name;
			if (base_name.IsEmpty())
				base_name = local_name;
		}

		if (base_name.IsEmpty())
			base_name = FormatString("bone_@", bone_index);
		return base_name;
	}

	String GetControlObjectName(const BaseTag* bone_tag, const Int32 bone_index)
	{
		return FormatString("@_ctrl", GetControlBaseName(bone_tag, bone_index));
	}

	Matrix BuildControlMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object)
	{
		const Matrix rest = BuildFrozenBoneGlobalMatrix(bone_object);
		const Matrix current = BuildCurrentBoneGlobalMatrix(bone_object);
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		Vector normal;
		if (GetFixedAxis(bc, normal) || GetLocalBoneAxis(bc, normal))
			normal = TransformRestDirectionToCurrent(rest, current, normal);
		else if (!GetTailBoneAxis(bone_manager, bc, rest, current, bone_object, normal))
			normal = current.sqmat.v3;

		Vector reference = GetFallbackReference(current, normal);
		if (bc && bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE))
			reference = TransformRestDirectionToCurrent(rest, current, bc->GetVector(PMX_BONE_LOCAL_Z));

		Matrix control = BuildBasisFromNormal(current, normal, reference);
		control.off = current.off;
		return control;
	}

	Matrix BuildControlRestMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object)
	{
		return BuildControlMatrix(bone_manager, bone_tag, bone_object);
	}

	Matrix BuildControlCurrentMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object)
	{
		return BuildControlMatrix(bone_manager, bone_tag, bone_object);
	}

	void CommitObjectLocalToFrozen(BaseObject* object)
	{
		if (!object)
			return;

		const Matrix current_local = object->GetMl();
		const Matrix normalized_local = NormalizeMatrixBasis(current_local);
		object->SetFrozenPos(current_local.off);
		object->SetFrozenScale(Vector(1.0));
		object->SetFrozenRot(MatrixToHPB(normalized_local, GetObjectRotationOrder(object)));
		object->SetRelMl(MakeIdentityMatrix());
		MarkSceneNodeDirty(object);
	}

	void ApplyGlobalFrozenMatrix(BaseObject* object, const Matrix& matrix)
	{
		if (!object)
			return;

		object->SetMg(NormalizeMatrixBasis(matrix));
		CommitObjectLocalToFrozen(object);
	}

	void MoveControlUnder(BaseObject* control, BaseObject* parent)
	{
		if (!control || !parent || control->GetUp() == parent)
			return;

		control->Remove();
		control->InsertUnderLast(parent);
		MarkSceneNodeDirty(control);
		MarkSceneNodeDirty(parent);
	}

	std::vector<Vector> BuildControlShapePoints(const ControlVisualSpec& spec)
	{
		std::vector<Vector> points;
		const Float r = spec.radius;
		switch (spec.shape)
		{
		case ControlShape::Square:
			points = {
				Vector(-r, -r, 0.0),
				Vector(r, -r, 0.0),
				Vector(r, r, 0.0),
				Vector(-r, r, 0.0)
			};
			break;
		case ControlShape::Diamond:
			points = {
				Vector(0.0, r, 0.0),
				Vector(r, 0.0, 0.0),
				Vector(0.0, -r, 0.0),
				Vector(-r, 0.0, 0.0)
			};
			break;
		case ControlShape::Triangle:
			points = {
				Vector(0.0, r, 0.0),
				Vector(r * 0.92, -r * 0.58, 0.0),
				Vector(-r * 0.92, -r * 0.58, 0.0)
			};
			break;
		case ControlShape::Oval:
		case ControlShape::Circle:
		default:
			points.reserve(kCircleControlPointCount);
			for (Int32 i = 0; i < kCircleControlPointCount; ++i)
			{
				const Float angle = kTwoPi * static_cast<Float>(i) / static_cast<Float>(kCircleControlPointCount);
				const Float aspect = spec.shape == ControlShape::Oval ? spec.aspect : 1.0;
				points.emplace_back(std::cos(angle) * r * aspect, std::sin(angle) * r, 0.0);
			}
			break;
		}
		return points;
	}

	void ApplyControlSplineShape(SplineObject* spline, const ControlVisualSpec& spec)
	{
		if (!spline)
			return;

		const std::vector<Vector> points = BuildControlShapePoints(spec);
		const Int32 point_count = static_cast<Int32>(points.size());
		if (point_count <= 0)
			return;

		if (spline->GetPointCount() != point_count || spline->GetSegmentCount() != 1)
			spline->ResizeObject(point_count, 1);
		if (Segment* const segment = spline->GetSegmentW())
		{
			segment[0].cnt = point_count;
			segment[0].closed = true;
		}
		if (Vector* const point_data = spline->GetPointW())
		{
			for (Int32 i = 0; i < point_count; ++i)
				point_data[i] = points[static_cast<std::size_t>(i)];
		}
		spline->SetParameter(ConstDescID(DescLevel(SPLINEOBJECT_CLOSED)), true, DESCFLAGS_SET::NONE);
		spline->SetDefaultCoeff();
		spline->Message(MSG_UPDATE);
	}

	void ApplyControlSplineShape(BaseObject* control, const ControlVisualSpec& spec)
	{
		if (!control || !(control->GetInfo() & OBJECT_ISSPLINE))
			return;
		ApplyControlSplineShape(ToSpline(control), spec);
	}

	SplineObject* CreateControlSpline(const ControlVisualSpec& spec)
	{
		const std::vector<Vector> points = BuildControlShapePoints(spec);
		const Int32 point_count = static_cast<Int32>(points.size());
		SplineObject* const spline = SplineObject::Alloc(point_count, SPLINETYPE::LINEAR);
		if (!spline)
			return nullptr;

		ApplyControlSplineShape(spline, spec);
		return spline;
	}

	void SetControlObjectColor(BaseObject* object, const Vector& color)
	{
		if (!object)
			return;

		ObjectColorProperties properties = MakeObjectColorProperties(color, ID_BASEOBJECT_USECOLOR_ALWAYS, false);
		object->SetColorProperties(&properties);
	}

	bool IsMatrixIdentityLike(const Matrix& matrix)
	{
		const Matrix identity = MakeIdentityMatrix();
		return (matrix.off - identity.off).GetLength() <= 1.0e-5 &&
			(matrix.sqmat.v1 - identity.sqmat.v1).GetLength() <= 1.0e-5 &&
			(matrix.sqmat.v2 - identity.sqmat.v2).GetLength() <= 1.0e-5 &&
			(matrix.sqmat.v3 - identity.sqmat.v3).GetLength() <= 1.0e-5;
	}

	UInt32 MixHash(UInt32 hash, const UInt32 value)
	{
		hash ^= value;
		hash *= 16777619u;
		return hash;
	}

	UInt32 HashFloat(const Float value)
	{
		return static_cast<UInt32>(static_cast<Int32>(std::llround(value * 100000.0)));
	}

	UInt32 HashMatrix(UInt32 hash, const Matrix& matrix)
	{
		hash = MixHash(hash, HashFloat(matrix.off.x));
		hash = MixHash(hash, HashFloat(matrix.off.y));
		hash = MixHash(hash, HashFloat(matrix.off.z));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v1.x));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v1.y));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v1.z));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v2.x));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v2.y));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v2.z));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v3.x));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v3.y));
		hash = MixHash(hash, HashFloat(matrix.sqmat.v3.z));
		return hash;
	}

	BaseTag* FindOrCreateControlProtectionTag(BaseObject* control)
	{
		if (!control)
			return nullptr;
		for (BaseTag* tag = control->GetFirstTag(); tag; tag = tag->GetNext())
		{
			if (tag->IsInstanceOf(Tprotection))
				return tag;
		}
		return control->MakeTag(Tprotection);
	}

	void SetProtectionAxis(BaseTag* tag, const Int32 parameter_id, const Bool locked)
	{
		if (tag)
			tag->SetParameter(CreateDescID(DescLevel(parameter_id)), locked, DESCFLAGS_SET::NONE);
	}

	void ConfigureControlProtection(BaseObject* control, const BaseContainer* bc)
	{
		BaseTag* const protection = FindOrCreateControlProtectionTag(control);
		if (!protection)
			return;

		const Bool translatable = bc && bc->GetBool(PMX_BONE_TRANSLATABLE);
		const Bool rotatable = !bc || bc->GetBool(PMX_BONE_ROTATABLE);
		const Bool fixed_axis = bc && bc->GetBool(PMX_BONE_IS_FIXED_AXIS);

		SetProtectionAxis(protection, PROTECTION_P_X, !translatable);
		SetProtectionAxis(protection, PROTECTION_P_Y, !translatable);
		SetProtectionAxis(protection, PROTECTION_P_Z, !translatable);
		SetProtectionAxis(protection, PROTECTION_S_X, true);
		SetProtectionAxis(protection, PROTECTION_S_Y, true);
		SetProtectionAxis(protection, PROTECTION_S_Z, true);
		SetProtectionAxis(protection, PROTECTION_R_X, !rotatable || fixed_axis);
		SetProtectionAxis(protection, PROTECTION_R_Y, !rotatable || fixed_axis);
		SetProtectionAxis(protection, PROTECTION_R_Z, !rotatable);
		protection->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	}

	Eigen::Quaternionf ProjectRotationToAxis(const Eigen::Quaternionf& rotation, Vector fixed_axis)
	{
		if (!TryNormalize(fixed_axis))
			return rotation.normalized();

		const Eigen::Vector3f axis(
			static_cast<float>(fixed_axis.x),
			static_cast<float>(fixed_axis.y),
			static_cast<float>(fixed_axis.z));
		const Eigen::Quaternionf normalized = rotation.normalized();
		const Eigen::Vector3f vector_part(normalized.x(), normalized.y(), normalized.z());
		const Eigen::Vector3f projected = axis * vector_part.dot(axis);
		Eigen::Quaternionf twist(normalized.w(), projected.x(), projected.y(), projected.z());
		if (twist.norm() <= 1.0e-6f)
			return Eigen::Quaternionf::Identity();
		return twist.normalized();
	}
}

Bool mmd_bone_control_util::CreateOrRefreshControls(MMDBoneManagerObject& bone_manager, BaseObject* bone_manager_object)
{
	iferr_scope_handler
	{
		return false;
	};

	if (!bone_manager_object)
		bone_manager_object = reinterpret_cast<BaseObject*>(bone_manager.Get());
	if (!bone_manager_object)
		return false;

	BaseObject* model_manager_object = io_util::ResolveObjectLink(bone_manager.model_manager_);
	if (!model_manager_object)
	{
		if (BaseObject* const parent = bone_manager_object->GetUp(); parent && parent->IsInstanceOf(g_mmd_model_manager_object_id))
		{
			bone_manager.model_manager_->SetLink(parent);
			model_manager_object = parent;
		}
	}
	if (!model_manager_object)
		return false;

	BaseObject* const controls_root = bone_manager_object;
	bone_manager.controls_root_link_->SetLink(controls_root);

	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_manager.bone_list_.GetCount());
	for (const auto& entry : bone_manager.bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	struct ControlEntry
	{
		Int32 bone_index = NOTOK;
		BaseTag* bone_tag = nullptr;
		BaseObject* bone_object = nullptr;
		BaseObject* control = nullptr;
		const BaseContainer* bc = nullptr;
		Matrix global_rest;
		String name;
		Bool created = false;
		Bool managed = false;
	};

	std::vector<ControlEntry> controls;
	controls.reserve(sorted_indices.size());

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager.FindBone(bone_index);
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!bone_tag || !bone_object || !bc)
			continue;

		const String local_name = bc->GetString(PMX_BONE_NAME_LOCAL);
		if (!IsBoneControlEligible(bc))
		{
			ClearLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
			continue;
		}

		const String control_name = GetControlObjectName(bone_tag, bone_index);
		const ControlVisualSpec visual_spec = GetControlVisualSpec(bc, bone_object);
		BaseObject* control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
		if (!control)
			control = FindDescendantByName(controls_root, control_name);

		const Bool created_control = control == nullptr;
		const Matrix control_global_rest = BuildControlRestMatrix(bone_manager, bone_tag, bone_object);
		if (created_control)
		{
			control = CreateControlSpline(visual_spec);
			if (!control)
				continue;
			control->InsertUnderLast(controls_root);
			SetControlObjectColor(control, GetControlColor(local_name));
		}

		const Bool managed_control = created_control || IsSameOrDescendantOf(control, controls_root);
		if (managed_control)
			control->SetName(control_name);
		if (managed_control)
			ApplyControlSplineShape(control, visual_spec);
		ConfigureControlProtection(control, bc);
		SetLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK, control);
		MarkSceneNodeDirty(control);

		ControlEntry entry;
		entry.bone_index = bone_index;
		entry.bone_tag = bone_tag;
		entry.bone_object = bone_object;
		entry.control = control;
		entry.bc = bc;
		entry.global_rest = control_global_rest;
		entry.name = control_name;
		entry.created = created_control;
		entry.managed = managed_control;
		controls.emplace_back(entry);
	}

	for (ControlEntry& entry : controls)
	{
		if (!entry.control || !entry.managed)
			continue;

		BaseObject* desired_parent = GetControlSiblingParent(entry.bone_object, bone_manager_object);
		if (!desired_parent || desired_parent == entry.control || IsSameOrDescendantOf(desired_parent, entry.control))
			desired_parent = controls_root;

		MoveControlUnder(entry.control, desired_parent);
		if (!entry.control->GetFirstCTrack())
			ApplyGlobalFrozenMatrix(entry.control, entry.global_rest);
		MarkSceneNodeDirty(entry.control);
	}

	bone_manager_object->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::DESCRIPTION);
	controls_root->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::MATRIX);
	if (GeIsMainThread())
		EventAdd();
	return true;
}

Bool mmd_bone_control_util::HasActiveControlDelta(MMDBoneManagerObject& bone_manager)
{
	for (const auto& entry : bone_manager.bone_list_)
	{
		BaseTag* const bone_tag = bone_manager.FindBone(static_cast<Int32>(entry.GetKey()));
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!IsBoneControlEligible(bc))
			continue;
		BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
		if (control && !IsMatrixIdentityLike(control->GetRelMl()))
			return true;
	}
	return false;
}

UInt32 mmd_bone_control_util::GetControlStateChecksum(MMDBoneManagerObject& bone_manager)
{
	UInt32 hash = 2166136261u;
	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_manager.bone_list_.GetCount());
	for (const auto& entry : bone_manager.bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager.FindBone(bone_index);
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!IsBoneControlEligible(bc))
			continue;
		BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
		if (!control)
			continue;

		hash = MixHash(hash, static_cast<UInt32>(bone_index));
		hash = HashMatrix(hash, NormalizeMatrixBasis(control->GetRelMl()));
	}
	return hash;
}

void mmd_bone_control_util::SyncControlsToCurrentPose(MMDBoneManagerObject& bone_manager)
{
	BaseObject* controls_root = io_util::ResolveObjectLink(bone_manager.controls_root_link_);
	if (!controls_root)
		controls_root = reinterpret_cast<BaseObject*>(bone_manager.Get());
	if (!controls_root)
		return;

	struct SyncControlEntry
	{
		Int32 bone_index = NOTOK;
		BaseObject* bone_object = nullptr;
		BaseObject* control = nullptr;
		Matrix global_pose;
		Bool managed = false;
	};

	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_manager.bone_list_.GetCount());
	for (const auto& entry : bone_manager.bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	std::vector<SyncControlEntry> controls;
	controls.reserve(sorted_indices.size());

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager.FindBone(bone_index);
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!bone_tag || !bone_object || !control || !IsBoneControlEligible(bc))
			continue;

		SyncControlEntry entry;
		entry.bone_index = bone_index;
		entry.bone_object = bone_object;
		entry.control = control;
		entry.global_pose = BuildControlCurrentMatrix(bone_manager, bone_tag, bone_object);
		entry.managed = IsSameOrDescendantOf(control, controls_root);
		controls.emplace_back(entry);
	}

	for (SyncControlEntry& entry : controls)
	{
		if (!entry.control || !entry.managed || !IsMatrixIdentityLike(entry.control->GetRelMl()))
			continue;

		BaseObject* desired_parent = GetControlSiblingParent(entry.bone_object, controls_root);
		if (!desired_parent || desired_parent == entry.control || IsSameOrDescendantOf(desired_parent, entry.control))
			desired_parent = controls_root;
		MoveControlUnder(entry.control, desired_parent);
		ApplyGlobalFrozenMatrix(entry.control, entry.global_pose);
	}
}

Bool mmd_bone_control_util::GetControlDeltaInBoneSpace(BaseTag* bone_tag, BaseObject* bone_object, Vector& translation, std::array<Float32, 4>& rotation)
{
	const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
	if (!IsBoneControlEligible(bc))
		return false;

	BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
	if (!control || !bone_object)
		return false;

	const Eigen::Matrix4f control_rest = MatrixToEigen(BuildControlBaseGlobalMatrix(control));
	const Eigen::Matrix4f bone_rest = MatrixToEigen(BuildCurrentBoneGlobalMatrix(bone_object));
	const Eigen::Matrix4f control_delta = MatrixToEigen(NormalizeMatrixBasis(control->GetRelMl()));

	const Eigen::Matrix3f control_basis = control_rest.block<3, 3>(0, 0);
	const Eigen::Matrix3f bone_basis = bone_rest.block<3, 3>(0, 0);
	const Eigen::Vector3f control_translation = control_delta.block<3, 1>(0, 3);
	const Eigen::Vector3f bone_translation = bone_basis.transpose() * control_basis * control_translation;

	const Eigen::Quaternionf control_rotation = ExtractRotation(control_delta);
	const Eigen::Matrix3f parent_rotation = control_basis * control_rotation.toRotationMatrix() * control_basis.transpose();
	const Eigen::Matrix3f bone_rotation = bone_basis.transpose() * parent_rotation * bone_basis;

	translation = Vector(bone_translation.x(), bone_translation.y(), bone_translation.z());
	Eigen::Quaternionf projected_rotation = Eigen::Quaternionf(bone_rotation).normalized();
	if (bc->GetBool(PMX_BONE_IS_FIXED_AXIS))
		projected_rotation = ProjectRotationToAxis(projected_rotation, bc->GetVector(PMX_BONE_FIXED_AXIS));
	rotation = ToQuaternionArray(projected_rotation);
	return true;
}

void mmd_bone_control_util::ResetControlRelativeTransform(BaseTag* bone_tag)
{
	BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
	if (!control)
		return;

	control->SetRelMl(MakeIdentityMatrix());
	MarkControlTransformDirty(control);
}
