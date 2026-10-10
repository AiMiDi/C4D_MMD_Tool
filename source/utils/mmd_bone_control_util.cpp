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
#include "module/tools/object/mmd_model_manager.h"
#include "ospline.h"
#include "plugin_resource.h"
#include "tprotection.h"
#include "description/TMMDBone.h"
#include "description/OMMDModelManager.h"
#include "description/OMMDBoneManager.h"
#include "utils/io_util.hpp"
#include "utils/string_util.hpp"
#include "utils/cmt_control_role.hpp"
#include "utils/mmd_control_workflow.hpp"
#include "utils/cmt_control_hit_test.hpp"

namespace
{
	constexpr Float kControlMediumRadius = 0.58;
	constexpr Int32 kCircleControlPointCount = 48;
	constexpr Float kTwoPi = 6.28318530717958647692;

	enum class ControlShape
	{
		Circle,
		Square,
		Box,
		ShoulderFrame,
		Pelvis,
		Diamond,
		Oval,
		Triangle,
		Foot,
		RingTicks,
		Groove,
		Bowl,
		Visor,
		RoundedSquare
	};

	struct ControlVisualSpec
	{
		ControlShape shape = ControlShape::Circle;
		Float radius = kControlMediumRadius;
		Float aspect = 1.0;
		Float axis_offset = 0.0;
		Bool model_aligned = false;
		Vector model_offset;
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

	Matrix BuildFrozenLocalTransform(BaseObject* object)
	{
		Matrix matrix = object->GetFrozenMln();
		const Vector scale = object->GetFrozenScale();
		matrix.sqmat.v1 *= scale.x;
		matrix.sqmat.v2 *= scale.y;
		matrix.sqmat.v3 *= scale.z;
		return matrix;
	}

	Matrix BuildFrozenBoneGlobalTransform(BaseObject* bone_object)
	{
		std::vector<BaseObject*> chain;
		BaseObject* current = bone_object;
		for (; current && current->GetTag(g_mmd_bone_tag_id); current = current->GetUp())
			chain.push_back(current);

		// Import sets frozen bone transforms before C4D updates GetMg(). Compose
		// those authored transforms directly, retaining model scale for positions.
		Matrix global = current ? current->GetMg() : MakeIdentityMatrix();
		for (auto it = chain.rbegin(); it != chain.rend(); ++it)
			global = global * BuildFrozenLocalTransform(*it);
		return global;
	}

	Matrix BuildFrozenBoneGlobalMatrix(BaseObject* bone_object)
	{
		return NormalizeMatrixBasis(BuildFrozenBoneGlobalTransform(bone_object));
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

	cmt::controls::NamedRole GetNamedControlRole(const BaseContainer* bc)
	{
		if (!bc) return {};
		auto role = cmt::controls::ClassifyName(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_LOCAL)));
		if (role.role == cmt::controls::Role::None)
			role = cmt::controls::ClassifyName(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_UNIVERSAL)));
		return role;
	}

	cmt::controls::Role GetControlRole(const BaseContainer* bc)
	{
		const auto role = GetNamedControlRole(bc).role;
		if (bc && bc->GetBool(PMX_BONE_IS_IK))
			return role == cmt::controls::Role::ToeIk ? role : cmt::controls::Role::IkGoal;
		// IK-like names alone must not create a solver or a fake IK target.
		if (role == cmt::controls::Role::IkGoal || role == cmt::controls::Role::ToeIk)
			return cmt::controls::Role::None;
		return role;
	}

	bool IsBoneControlEligible(const BaseContainer* bc)
	{
        if (!bc) return false;
        const auto kind = mmd_control_workflow::ClassifyBone(bc);
        return bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE) || bc->GetBool(PMX_BONE_IS_FIXED_AXIS) ||
            GetControlRole(bc) != cmt::controls::Role::None ||
            (!kind.secondary && kind.part != cmt::controls::Part::Other);
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

	bool GetTailBonePoint(MMDBoneManagerObject& bone_manager, const BaseContainer* bc, const Matrix& rest_matrix, const Matrix& current_matrix, BaseObject* bone_object, Vector& point, const Bool rest_pose)
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
						const Matrix tail_matrix = rest_pose ? BuildFrozenBoneGlobalMatrix(tail_object) : BuildCurrentBoneGlobalMatrix(tail_object);
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
			const Matrix child_matrix = rest_pose ? BuildFrozenBoneGlobalMatrix(child) : BuildCurrentBoneGlobalMatrix(child);
			if ((child_matrix.off - current_matrix.off).GetLength() > EPSILON)
			{
				point = child_matrix.off;
				return true;
			}
		}
		return false;
	}

	bool GetTailBoneAxis(MMDBoneManagerObject& bone_manager, const BaseContainer* bc, const Matrix& rest_matrix, const Matrix& current_matrix, BaseObject* bone_object, Vector& axis, const Bool rest_pose)
	{
		Vector tail_point;
		if (GetTailBonePoint(bone_manager, bc, rest_matrix, current_matrix, bone_object, tail_point, rest_pose))
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

	Float GetSkeletonSpan(MMDBoneManagerObject& manager, BaseObject* model)
	{
		maxon::BaseArray<BaseObject*> bones;
		manager.BuildOrderedBoneObjectList(bones);
		Vector low, high;
		Bool first = true;
		const Matrix inverse_model = model ? ~model->GetMg() : Matrix();
		for (BaseObject* bone : bones)
		{
			const Vector point = inverse_model * BuildFrozenBoneGlobalMatrix(bone).off;
			if (first) { low = high = point; first = false; }
			low.x = std::min(low.x, point.x); low.y = std::min(low.y, point.y); low.z = std::min(low.z, point.z);
			high.x = std::max(high.x, point.x); high.y = std::max(high.y, point.y); high.z = std::max(high.z, point.z);
		}
		const Float span = std::max({high.x - low.x, high.y - low.y, high.z - low.z});
		return std::isfinite(span) && span > EPSILON ? span : 20.0;
	}

	cmt::controls::Purpose GetControlPurpose(const BaseContainer* bc)
	{
		using namespace cmt::controls;
		if (!bc) return Purpose::Unknown;
		const auto local = ClassifyPurpose(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_LOCAL)));
		const auto universal = ClassifyPurpose(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_UNIVERSAL)));
		// Explicit auxiliary/twist metadata wins even if the other alias is a
		// standard joint name. Unknown names retain the existing presentation.
		if (IsSecondaryPurpose(local)) return local;
		if (IsSecondaryPurpose(universal)) return universal;
		return local != Purpose::Unknown ? local : universal;
	}

	Bool IsPrimaryControl(const BaseContainer* bc)
	{
		return bc && bc->GetBool(PMX_BONE_VISIBLE) && bc->GetBool(PMX_BONE_ENABLED) &&
			!cmt::controls::IsSecondaryPurpose(GetControlPurpose(bc));
	}

	BaseObject* GetControlModel(BaseObject* manager);
	BaseObject* FindDescendantByName(BaseObject* parent, const String& name);

	ControlVisualSpec GetControlVisualSpec(const BaseContainer* bc, BaseObject* bone_object, const Float span, const Float size)
	{
		const Float hierarchy_scale = std::clamp(1.0 - Float(GetBoneHierarchyDepth(bone_object)) * 0.025, 0.65, 1.0);
		const auto purpose = GetControlPurpose(bc);
		const Bool finger = mmd_control_workflow::ClassifyBone(bc).finger;
		const Float radius = (finger ? 0.18 : 1.0) * span * 0.033 * hierarchy_scale * size * cmt::controls::PurposeRadiusScale(purpose);
		// Explicit PMX axes take precedence over an anatomical name, including
		// knees authored as hinges in models other than the validation sample.
		if (bc && bc->GetBool(PMX_BONE_IS_FIXED_AXIS))
			return { ControlShape::Diamond, radius * 0.7, 1.0, radius * 0.8 };
		if (cmt::controls::IsSecondaryPurpose(purpose))
			return { ControlShape::Diamond, radius, 1.0 };
		if (purpose == cmt::controls::Purpose::Shoulder)
		{
			ControlVisualSpec visual{ ControlShape::ShoulderFrame, radius, 1.0 };
			visual.model_aligned = true;
			const auto named = cmt::controls::ClassifyName(string_util::GetStdString(bc->GetString(PMX_BONE_NAME_LOCAL)));
			Int right_position = NOTOK;
			const Bool right = named.side == cmt::controls::Side::Right || bc->GetString(PMX_BONE_NAME_LOCAL).Find(String("右"), &right_position);
			visual.model_offset = Vector((right ? -1 : 1) * span * 0.14, span * 0.045, -span * 0.025);
			return visual;
		}
		if (purpose == cmt::controls::Purpose::Eye || purpose == cmt::controls::Purpose::Eyes)
		{
			ControlVisualSpec visual{ ControlShape::Oval, radius, 1.3 };
			visual.model_aligned = true;
			visual.model_offset = Vector(0, 0, -span * 0.12);
			// The shared MMD eye pivot is often above the head. Place its outline
			// by the actual eye pair while keeping that authored pivot untouched.
			if (purpose == cmt::controls::Purpose::Eyes && bone_object)
			{
				BaseObject* const parent = bone_object->GetUp();
				BaseObject* const left = FindDescendantByName(parent, String("左目"));
				BaseObject* const right = FindDescendantByName(parent, String("右目"));
				BaseObject* const model = GetControlModel(bone_object);
				if (left && right && model)
				{
					const Vector midpoint = (BuildFrozenBoneGlobalMatrix(left).off + BuildFrozenBoneGlobalMatrix(right).off) * 0.5;
					const Matrix inverse_model = ~model->GetMg();
					visual.model_offset += inverse_model.sqmat * (midpoint - BuildFrozenBoneGlobalMatrix(bone_object).off);
				}
			}
			return visual;
		}
		if (purpose == cmt::controls::Purpose::Wrist)
			return { ControlShape::Circle, radius, 1.0, 0.0, false };
		switch (GetControlRole(bc))
		{
		case cmt::controls::Role::Root: return { ControlShape::Circle, radius * 3.5, 1.0 };
		case cmt::controls::Role::Center: return { ControlShape::RingTicks, radius * 2.15, 1.0 };
		case cmt::controls::Role::Groove: return { ControlShape::Groove, radius * 1.05, 1.0 };
		case cmt::controls::Role::Waist: return { ControlShape::Triangle, radius * 1.15, 1.0 };
		case cmt::controls::Role::Pelvis: return { ControlShape::Pelvis, radius * 1.35, 1.0 };
		case cmt::controls::Role::Spine: return { ControlShape::Circle, radius * 1.5, 1.0 };
		case cmt::controls::Role::Neck: return { ControlShape::Circle, radius * 0.65, 1.0 };
		case cmt::controls::Role::Head: return { ControlShape::Circle, radius * 1.1, 1.0, span * 0.16 };
		case cmt::controls::Role::IkGoal: return { ControlShape::Foot, radius * 0.9, 0.8 };
		case cmt::controls::Role::ToeIk: return { ControlShape::Visor, radius * 0.55, 1.0 };
		case cmt::controls::Role::IkParent: return { ControlShape::Bowl, radius * 1.3, 0.5 };
		case cmt::controls::Role::Leg: return { ControlShape::Circle, radius * 0.85, 1.0 };
		case cmt::controls::Role::Knee: return { ControlShape::Circle, radius * 0.65, 1.0 };
		case cmt::controls::Role::Ankle: return { ControlShape::Circle, radius * 0.6, 1.0 };
		case cmt::controls::Role::Toe: return { ControlShape::Circle, radius * 0.4, 1.0 };
		default: break;
		}
		if (finger) return { ControlShape::Circle, radius, 1.0, 0.0, false };
		if (!IsPrimaryControl(bc))
			return { ControlShape::Circle, radius * 0.55, 1.0 };
		if (bc && bc->GetBool(PMX_BONE_TRANSLATABLE))
			return { ControlShape::RoundedSquare, radius, 1.0 };
		if (bc && bc->GetBool(PMX_BONE_INHERIT_ROTATION))
			return { ControlShape::Circle, radius * 0.55, 1.0 };
		return { ControlShape::Circle, radius, 1.0 };
	}

	Vector GetControlColor(const String& local_name)
	{
		Int position = NOTOK;
		if (local_name.IsPopulated() && local_name.Find(String("左"), &position))
			return Vector(0.20, 0.48, 1.0);
		if (local_name.IsPopulated() && local_name.Find(String("右"), &position))
			return Vector(1.0, 0.28, 0.24);
		const auto side = cmt::controls::ClassifyName(string_util::GetStdString(local_name)).side;
		if (side == cmt::controls::Side::Left) return Vector(0.20, 0.48, 1.0);
		if (side == cmt::controls::Side::Right) return Vector(1.0, 0.28, 0.24);
		return Vector(1.0, 0.88, 0.18);
	}

	BaseObject* GetControlModel(BaseObject* manager)
	{
		for (BaseObject* parent = manager ? manager->GetUp() : nullptr; parent; parent = parent->GetUp())
			if (parent->IsInstanceOf(g_mmd_model_manager_object_id))
				return parent;
		return nullptr;
	}

	Float GetControlSize(BaseObject* model)
	{
		const Float size = model ? model->GetDataInstance()->GetFloat(MODEL_CONTROLS_SIZE, 1.0) : 1.0;
		return std::isfinite(size) ? std::clamp(size, 0.25, 3.0) : 1.0;
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

	bool UsesHorizontalControlPlane(const BaseContainer* bc)
	{
		using cmt::controls::Role;
		const auto role = GetControlRole(bc);
		return (bc && bc->GetBool(PMX_BONE_IS_IK)) || role == Role::IkParent ||
			role == Role::Root || role == Role::Center || role == Role::Groove || role == Role::Waist || role == Role::Spine || role == Role::Pelvis || role == Role::Neck || role == Role::Head;
	}

	Matrix BuildControlMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object, const Bool rest_pose)
	{
		const Matrix rest = BuildFrozenBoneGlobalMatrix(bone_object);
		const Matrix current = rest_pose ? rest : BuildCurrentBoneGlobalMatrix(bone_object);
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		Vector normal;
		if (GetFixedAxis(bc, normal) || GetLocalBoneAxis(bc, normal))
			normal = TransformRestDirectionToCurrent(rest, current, normal);
		else if (UsesHorizontalControlPlane(bc))
			normal = TransformRestDirectionToCurrent(rest, current, Vector(0, 1, 0));
		else if (!GetTailBoneAxis(bone_manager, bc, rest, current, bone_object, normal, rest_pose))
			normal = current.sqmat.v3;

		Vector reference = GetFallbackReference(current, normal);
		if (bc && !bc->GetBool(PMX_BONE_IS_FIXED_AXIS) &&
			UsesHorizontalControlPlane(bc))
			reference = TransformRestDirectionToCurrent(rest, current, Vector(1, 0, 0));
		if (bc && bc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE))
			reference = TransformRestDirectionToCurrent(rest, current, bc->GetVector(PMX_BONE_LOCAL_Z));

		Matrix control = BuildBasisFromNormal(current, normal, reference);
		control.off = current.off;
		return control;
	}

	Matrix BuildControlRestMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object)
	{
		return BuildControlMatrix(bone_manager, bone_tag, bone_object, true);
	}

	Matrix BuildControlCurrentMatrix(MMDBoneManagerObject& bone_manager, BaseTag* bone_tag, BaseObject* bone_object)
	{
		return BuildControlMatrix(bone_manager, bone_tag, bone_object, false);
	}

	void ApplyGlobalFrozenMatrix(BaseObject* object, const Matrix& matrix, const Bool rest_pose = false)
	{
		if (!object)
			return;

		BaseObject* const parent = object->GetUp();
		const Matrix parent_matrix = parent
			? (rest_pose ? BuildFrozenBoneGlobalTransform(parent) : parent->GetMg()) : MakeIdentityMatrix();
		const Matrix current_local = ~parent_matrix * matrix;
		const Matrix normalized_local = NormalizeMatrixBasis(current_local);
		object->SetFrozenPos(current_local.off);
		object->SetFrozenScale(Vector(1.0));
		object->SetFrozenRot(MatrixToHPB(normalized_local, GetObjectRotationOrder(object)));
		object->SetRelMl(MakeIdentityMatrix());
		MarkSceneNodeDirty(object);
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
        case ControlShape::Groove:
            for (Int32 i=0; i<kCircleControlPointCount; ++i)
            {
                const Float angle=kTwoPi*Float(i)/kCircleControlPointCount;
                points.emplace_back(r*2.5+std::cos(angle)*r*0.55,std::sin(angle)*r*0.55,0);
            }
            break;
        case ControlShape::Bowl:
            // A shallow saddle outline identifies the shared foot IK parent.
            for (Int32 i=0; i<32; ++i)
            {
                const Float angle=kTwoPi*Float(i)/32;
                points.emplace_back(std::cos(angle)*r,std::sin(angle)*r,std::sin(angle)*std::sin(angle)*r*0.35);
            }
            break;
        case ControlShape::Visor:
            // Rounded open-ended toe visor, closed as one narrow ribbon.
            for (Int32 i=0; i<=12; ++i)
            {
                const Float angle=kTwoPi*(Float(i)/24+0.5);
                points.emplace_back(std::cos(angle)*r*1.4,std::sin(angle)*r,0);
            }
            for (Int32 i=12; i>=0; --i)
            {
                const Float angle=kTwoPi*(Float(i)/24+0.5);
                points.emplace_back(std::cos(angle)*r*1.18,std::sin(angle)*r*.78,0);
            }
            break;
		case ControlShape::Foot:
			points = { Vector(-r * 0.55, -r * 0.65, 0), Vector(r * 0.55, -r * 0.65, 0),
				Vector(r * 0.7, r * 0.95, 0), Vector(r * 0.4, r * 1.65, 0),
				Vector(-r * 0.4, r * 1.65, 0), Vector(-r * 0.7, r * 0.95, 0) };
			break;
		case ControlShape::RoundedSquare:
			for (Int32 corner = 0; corner < 4; ++corner)
			{
				const Float center_angle = kTwoPi * (Float(corner) + 0.5) / 4.0;
				const Vector center(std::cos(center_angle) > 0 ? r * 0.65 : -r * 0.65,
					std::sin(center_angle) > 0 ? r * 0.65 : -r * 0.65, 0);
				for (Int32 step = 0; step <= 5; ++step)
				{
					const Float angle = kTwoPi * (Float(corner) + Float(step) / 5.0) / 4.0;
					points.push_back(center + Vector(std::cos(angle), std::sin(angle), 0) * r * 0.35);
				}
			}
			break;
		case ControlShape::ShoulderFrame:
			points = { Vector(-r * 0.65, -r * 0.65, 0), Vector(r * 0.65, -r * 0.65, 0),
				Vector(r * 0.65, r * 0.65, 0), Vector(-r * 0.65, r * 0.65, 0) };
			break;
		case ControlShape::Pelvis:
			// Hip basket points down along the horizontal control plane normal.
			points = { Vector(-r, 0, 0), Vector(r, 0, 0), Vector(0, 0, -r * 0.8) };
			break;
		case ControlShape::Box:
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
		case ControlShape::RingTicks:
		case ControlShape::Oval:
		case ControlShape::Circle:
		default:
			points.reserve(kCircleControlPointCount);
			for (Int32 i = 0; i < kCircleControlPointCount; ++i)
			{
				const Float angle = kTwoPi * static_cast<Float>(i) / static_cast<Float>(kCircleControlPointCount);
				const Float aspect = spec.shape == ControlShape::Oval ? spec.aspect : 1.0;
                const Float ring_radius=spec.shape==ControlShape::RingTicks?r*0.56:r;
				points.emplace_back(std::cos(angle) * ring_radius * aspect, std::sin(angle) * ring_radius, 0.0);
			}
			break;
		}
		for (Vector& point : points)
		{
			if (spec.shape == ControlShape::Foot || spec.shape == ControlShape::RoundedSquare)
				point.x *= spec.aspect;
			point.z += spec.axis_offset;
		}
		return points;
	}

	void ApplyControlSplineShape(SplineObject* spline, const ControlVisualSpec& spec)
	{
		if (!spline)
			return;

		const std::vector<Vector> points = BuildControlShapePoints(spec);
		const Int32 outline_count = static_cast<Int32>(points.size());
		if (outline_count <= 0)
			return;
		// Explicit endpoints give native splines and foreground drawing identical
		// topology. The global Closed flag must not connect unrelated segments.
		std::vector<std::vector<Vector>> contours{ points };
		contours.front().push_back(points.front());
		if (spec.shape == ControlShape::ShoulderFrame)
		{
			contours.push_back({ -spec.model_offset, Vector(0, -spec.radius * 0.65, 0) });
		}
		else if (spec.shape == ControlShape::Box)
		{
			// A shallow wire cage distinguishes hand controls from FK rings.
			const Vector depth(0, 0, spec.radius * 0.8);
			std::vector<Vector> top = contours.front();
			for (Vector& point : top) point += depth;
			contours.push_back(top);
			for (const Vector& point : points) contours.push_back({ point, point + depth });
		}
        else if (spec.shape == ControlShape::RingTicks)
        {
            // Four separated curved pads identify the centre without covering
            // it in concentric rings. All geometry remains independently authored.
            for (Int32 quadrant=0; quadrant<4; ++quadrant)
            {
                std::vector<Vector> arc;
                for (Int32 step=0; step<=6; ++step)
                {
                    const Float angle=kTwoPi*(Float(quadrant)/4+(Float(step)/6-.5)*.16);
                    arc.emplace_back(std::cos(angle)*spec.radius,std::sin(angle)*spec.radius,0);
                }
                for (Int32 step=6; step>=0; --step)
                {
                    const Float angle=kTwoPi*(Float(quadrant)/4+(Float(step)/6-.5)*.16);
                    arc.emplace_back(std::cos(angle)*spec.radius*.89,std::sin(angle)*spec.radius*.89,0);
                }
                arc.push_back(arc.front());
                contours.push_back(std::move(arc));
            }
        }
        else if (spec.shape==ControlShape::Groove)
        {
            for (const Float direction : {Float(-1),Float(1)})
            {
                const Float r=spec.radius;
                const Vector offset(r*2.5,0,0);
                contours.push_back({offset+Vector(-r*.12,direction*r*.5,0),offset+Vector(-r*.12,direction*r*.82,0),
                    offset+Vector(-r*.32,direction*r*.82,0),offset+Vector(0,direction*r*1.12,0),
                    offset+Vector(r*.32,direction*r*.82,0),offset+Vector(r*.12,direction*r*.82,0),
                    offset+Vector(r*.12,direction*r*.5,0),offset+Vector(-r*.12,direction*r*.5,0)});
            }
        }
		Int32 point_count = 0;
		for (const auto& contour : contours) point_count += static_cast<Int32>(contour.size());
		const Int32 segment_count = static_cast<Int32>(contours.size());
		if (spline->GetPointCount() != point_count || spline->GetSegmentCount() != segment_count)
		{
			if (!spline->ResizeObject(point_count, segment_count)) return;
		}
		Segment* const segments = spline->GetSegmentW();
		Vector* const point_data = spline->GetPointW();
		if (!segments || !point_data) return;
		Int32 offset = 0;
		for (Int32 i = 0; i < segment_count; ++i)
		{
			const auto& contour = contours[static_cast<std::size_t>(i)];
			segments[i].cnt = static_cast<Int32>(contour.size());
			segments[i].closed = false;
			for (const Vector& point : contour) point_data[offset++] = point;
		}
		spline->SetParameter(ConstDescID(DescLevel(SPLINEOBJECT_CLOSED)), false, DESCFLAGS_SET::NONE);
		spline->SetDefaultCoeff();
		spline->Message(MSG_UPDATE);
	}

	void ApplyControlSplineShape(BaseObject* control, const ControlVisualSpec& spec, BaseObject* bone = nullptr)
	{
		if (!control || !(control->GetInfo() & OBJECT_ISSPLINE))
			return;
		SplineObject* const spline = ToSpline(control);
		ApplyControlSplineShape(spline, spec);
		BaseObject* const model = bone ? GetControlModel(bone) : nullptr;
		if (spec.model_aligned && model)
		{
			// Convert the model-space display layout into the frozen control frame.
			// Relative animation inputs are deliberately excluded from this mapping.
			BaseObject* const parent = control->GetUp();
			const Matrix parent_rest = parent ? BuildFrozenBoneGlobalTransform(parent) : MakeIdentityMatrix();
			const Matrix control_rest = parent_rest * BuildFrozenLocalTransform(control);
			Matrix layout = ~control_rest * model->GetMg();
			layout.off = Vector(0);
			if (Vector* const points = spline->GetPointW())
				for (Int32 i = 0; i < spline->GetPointCount(); ++i)
					points[i] = layout * (points[i] + spec.model_offset);
			spline->Message(MSG_UPDATE);
		}
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
	const Float skeleton_span = GetSkeletonSpan(bone_manager, model_manager_object);
	const Float size = GetControlSize(model_manager_object);

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
		const ControlVisualSpec visual_spec = GetControlVisualSpec(bc, bone_object, skeleton_span, size);
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
		{
			control->SetName(control_name);
			ApplyControlSplineShape(control, visual_spec, bone_object);
			SetControlObjectColor(control, GetControlColor(local_name));
			ConfigureControlProtection(control, bc);
		}
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
		// An unkeyed relative transform is still authored input. Refreshing the
		// presentation must not zero it or change the controller's frozen basis.
		if (entry.created)
			ApplyGlobalFrozenMatrix(entry.control, entry.global_rest, true);
		ApplyControlSplineShape(entry.control, GetControlVisualSpec(entry.bc, entry.bone_object, skeleton_span, size), entry.bone_object);
		MarkSceneNodeDirty(entry.control);
	}

	mmd_control_workflow::CreateArmControls(bone_manager, controls_root);
	bone_manager_object->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::DESCRIPTION);
	controls_root->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::MATRIX);
	if (GeIsMainThread())
		EventAdd();
	return true;
}

void mmd_bone_control_util::RefreshControlVisuals(MMDBoneManagerObject& bone_manager, BaseObject* manager)
{
	if (!manager)
		return;
	BaseObject* const model = GetControlModel(manager);
	const Float span = GetSkeletonSpan(bone_manager, model);
	const Float size = GetControlSize(model);
	maxon::BaseArray<BaseObject*> bones;
	bone_manager.BuildOrderedBoneObjectList(bones);
	for (BaseObject* bone : bones)
	{
		BaseTag* const tag = bone->GetTag(g_mmd_bone_tag_id);
		const BaseContainer* const bc = tag ? tag->GetDataInstance() : nullptr;
		BaseObject* const control = ResolveLinkedObjectParameter(tag, PMX_BONE_CONTROL_LINK);
		if (!IsBoneControlEligible(bc) || !control || !IsSameOrDescendantOf(control, manager))
			continue;
		ApplyControlSplineShape(control, GetControlVisualSpec(bc, bone, span, size), bone);
		SetControlObjectColor(control, GetControlColor(bc->GetString(PMX_BONE_NAME_LOCAL)));
	}
    if (BaseObject* root = io_util::ResolveObjectLink(bone_manager.controls_root_link_))
        mmd_control_workflow::CreateArmControls(bone_manager, root);
}

Bool mmd_bone_control_util::IsControlVisible(BaseTag* bone_tag, BaseObject* manager, const Int32 bone_display_type)
{
	if (bone_display_type == BONE_DISPLAY_TYPE_OFF)
		return false;
	BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
	// Artist-linked external objects retain the established bone display behavior.
	if (!control || !IsSameOrDescendantOf(control, manager))
		return true;
	BaseObject* const model = GetControlModel(manager);
	if (model && model->GetDataInstance()->GetInt32(MODEL_MODE) == MODEL_MODE_EDIT)
		return false;
	const Int32 display = model ? model->GetDataInstance()->GetInt32(MODEL_CONTROLS_DISPLAY) : MODEL_CONTROLS_DISPLAY_PRIMARY;
	return display != MODEL_CONTROLS_DISPLAY_HIDDEN &&
        mmd_control_workflow::IsVisible(bone_tag, manager) &&
		(display == MODEL_CONTROLS_DISPLAY_ALL || IsPrimaryControl(bone_tag->GetDataInstance()));
}

void mmd_bone_control_util::SelectVisibleControls(MMDBoneManagerObject& bone_manager, BaseObject* manager)
{
	BaseDocument* const doc = manager ? manager->GetDocument() : nullptr;
	if (!doc)
		return;
	const Int32 display = manager->GetDataInstance()->GetInt32(BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF);
	maxon::BaseArray<BaseObject*> bones;
	bone_manager.BuildOrderedBoneObjectList(bones);
	Bool first = true;
	doc->SetActiveObject(nullptr, SELECTION_NEW);
	for (BaseObject* bone : bones)
	{
		BaseTag* const tag = bone->GetTag(g_mmd_bone_tag_id);
		BaseObject* const control = ResolveLinkedObjectParameter(tag, PMX_BONE_CONTROL_LINK);
		if (!control || control->GetEditorMode() == MODE_OFF || !IsSameOrDescendantOf(control, manager)
			|| !IsControlVisible(tag, manager, display))
			continue;
		doc->SetActiveObject(control, first ? SELECTION_NEW : SELECTION_ADD);
		first = false;
	}
    std::vector<mmd_control_workflow::ExtraControl> extras;
    mmd_control_workflow::CollectExtraControls(bone_manager, extras);
    for (const auto& extra : extras)
        if (extra.object->GetEditorMode() != MODE_OFF)
        {
            doc->SetActiveObject(extra.object, first ? SELECTION_NEW : SELECTION_ADD);
            first = false;
        }
	EventAdd();
}

DRAWRESULT mmd_bone_control_util::DrawControls(MMDBoneManagerObject& bone_manager, BaseObject* op,
	const DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (!op || !bd || !(bd->GetDisplayFilter() & DISPLAYFILTER::SPLINE))
		return DRAWRESULT::OK;
	if (drawpass == DRAWPASS::OBJECT)
	{
		bd->AddToPostPass(op, bh);
		return DRAWRESULT::OK;
	}
	if (drawpass != DRAWPASS::XRAY)
		return DRAWRESULT::OK;
	BaseObject* const model = GetControlModel(op);
	if (!model || !model->GetDataInstance()->GetBool(MODEL_CONTROLS_OCCLUDED, true))
		return DRAWRESULT::OK;
	const Int32 display = op->GetDataInstance()->GetInt32(BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF);
	maxon::BaseArray<BaseObject*> bones;
	bone_manager.BuildOrderedBoneObjectList(bones);
	const GeData previous_z = bd->GetDrawParam(DRAW_PARAMETER_SETZ);
	const GeData previous_width = bd->GetDrawParam(DRAW_PARAMETER_LINEWIDTH);
	// A continuous foreground silhouette remains readable over both dark clothes
	// and light skin. A narrow dark under-stroke separates it from the material;
	// these viewport strokes never change native spline geometry or rig input.
	bd->SetDrawParam(DRAW_PARAMETER_SETZ, GeData(DRAW_Z_ALWAYS));
	std::vector<std::pair<BaseTag*, BaseObject*>> handles;
	for (BaseObject* bone : bones)
	{
		BaseTag* tag = bone->GetTag(g_mmd_bone_tag_id);
		if (IsControlVisible(tag, op, display)) handles.emplace_back(tag, ResolveLinkedObjectParameter(tag, PMX_BONE_CONTROL_LINK));
	}
	std::vector<mmd_control_workflow::ExtraControl> extras;
	mmd_control_workflow::CollectExtraControls(bone_manager, extras);
	for (const auto& extra : extras) if (extra.object->GetEditorMode() != MODE_OFF) handles.emplace_back(extra.owner, extra.object);
	for (const auto& handle : handles)
	{
		BaseTag* const tag = handle.first;
		BaseObject* const control = handle.second;
		if (!control || control->GetEditorMode() == MODE_OFF || !control->IsInstanceOf(Ospline) || !IsSameOrDescendantOf(control, op))
			continue;
		SplineObject* const spline = ToSpline(control);
		const Vector* const points = spline->GetPointR();
		const Segment* const segments = spline->GetSegmentR();
		if (!points || !segments)
			continue;
		const Bool selected = control->GetBit(BIT_ACTIVE);
		const Vector color = GetControlColor(tag->GetDataInstance()->GetString(PMX_BONE_NAME_LOCAL));
		bd->SetMatrix_Matrix(control, control->GetMg());
		for (Int32 stroke = 0; stroke < 2; ++stroke)
		{
			const Bool border = stroke == 0;
			bd->SetPen(border ? Vector(0.055) : (selected ? color * 0.75 + Vector(0.25) : color));
			bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, GeData(border ? (selected ? 4.2 : 3.0) : (selected ? 2.4 : 1.5)));
			Int32 offset = 0;
			for (Int32 segment_index = 0; segment_index < spline->GetSegmentCount(); ++segment_index)
			{
				const Segment& segment = segments[segment_index];
				const Int32 edge_count = segment.closed ? segment.cnt : segment.cnt - 1;
				for (Int32 edge = 0; edge < edge_count; ++edge)
					bd->DrawLine(points[offset + edge], points[offset + (edge + 1) % segment.cnt], 0);
				offset += segment.cnt;
			}
		}
	}
	bd->SetDrawParam(DRAW_PARAMETER_SETZ, previous_z);
	bd->SetDrawParam(DRAW_PARAMETER_LINEWIDTH, previous_width);
	bd->SetMatrix_Matrix(nullptr, Matrix());
	return DRAWRESULT::OK;
}

String mmd_bone_control_util::GetHoveredControlName(BaseDocument* doc, BaseDraw* bd, const Float x, const Float y)
{
	if (!doc || !bd || !(bd->GetDisplayFilter() & DISPLAYFILTER::SPLINE))
		return String();
	Float nearest_distance = 6.0 * 6.0;
	String name;
	std::vector<BaseObject*> pending;
	if (doc->GetFirstObject()) pending.push_back(doc->GetFirstObject());
	while (!pending.empty())
	{
		BaseObject* const object = pending.back();
		pending.pop_back();
		if (object->GetNext()) pending.push_back(object->GetNext());
		// A hidden ancestor suppresses its complete hierarchy, including hints.
		if (object->GetEditorMode() == MODE_OFF) continue;
		if (object->GetDown()) pending.push_back(object->GetDown());
		if (!object->IsInstanceOf(g_mmd_bone_manager_object_id)) continue;
		auto* manager = object->GetNodeData<MMDBoneManagerObject>();
		if (!manager) continue;
		const Int32 display = object->GetDataInstance()->GetInt32(BONE_DISPLAY_TYPE, BONE_DISPLAY_TYPE_OFF);
		maxon::BaseArray<BaseObject*> bones;
		manager->BuildOrderedBoneObjectList(bones);
		std::vector<std::pair<BaseTag*, BaseObject*>> handles;
		for (BaseObject* bone : bones)
		{
			BaseTag* tag = bone->GetTag(g_mmd_bone_tag_id);
			if (IsControlVisible(tag, object, display)) handles.emplace_back(tag, ResolveLinkedObjectParameter(tag, PMX_BONE_CONTROL_LINK));
		}
		std::vector<mmd_control_workflow::ExtraControl> extras;
		mmd_control_workflow::CollectExtraControls(*manager, extras);
		for (const auto& extra : extras) if (extra.object->GetEditorMode() != MODE_OFF) handles.emplace_back(extra.owner, extra.object);
		for (const auto& handle : handles)
		{
			BaseTag* const tag = handle.first;
			BaseObject* const control = handle.second;
			if (!control || !control->IsInstanceOf(Ospline) || !IsSameOrDescendantOf(control, object)) continue;
			Bool hidden = false;
			for (BaseObject* ancestor = control; ancestor && ancestor != object; ancestor = ancestor->GetUp())
				if (ancestor->GetEditorMode() == MODE_OFF) { hidden = true; break; }
			if (hidden) continue;
			SplineObject* const spline = ToSpline(control);
			const Vector* const points = spline->GetPointR();
			const Segment* const segments = spline->GetSegmentR();
			if (!points || !segments) continue;
			const Matrix global = control->GetMg();
			Int32 offset = 0;
			for (Int32 segment_index = 0; segment_index < spline->GetSegmentCount(); ++segment_index)
			{
				const Segment& segment = segments[segment_index];
				if (segment.cnt < 0 || offset + segment.cnt > spline->GetPointCount()) break;
				const Int32 edge_count = segment.closed ? segment.cnt : segment.cnt - 1;
				for (Int32 edge = 0; edge < edge_count; ++edge)
				{
					Vector a = bd->WC(global * points[offset + edge]);
					Vector b = bd->WC(global * points[offset + (edge + 1) % segment.cnt]);
					if (!bd->ClipLineZ(&a, &b)) continue;
					a = bd->WS(bd->CW(a));
					b = bd->WS(bd->CW(b));
					const Float distance = cmt::controls::SegmentDistanceSquared(x, y, a.x, a.y, b.x, b.y);
					if (distance < nearest_distance)
					{
						nearest_distance = distance;
						name = control == ResolveLinkedObjectParameter(tag, PMX_BONE_CONTROL_LINK)
                            ? GetControlBaseName(tag, manager->FindBoneIndex(tag)) : control->GetName();
					}
				}
				offset += segment.cnt;
			}
		}
	}
	return name;
}

Bool mmd_bone_control_util::HasActiveControlDelta(MMDBoneManagerObject& bone_manager)
{
    std::vector<mmd_control_workflow::ExtraControl> extras;
    mmd_control_workflow::CollectExtraControls(bone_manager, extras);
    for (const auto& extra : extras) if (mmd_control_workflow::IsForcedIK(extra.owner)) return true;

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

Bool mmd_bone_control_util::HasActiveControlRotation(BaseTag* bone_tag)
{
    if (mmd_control_workflow::IsForcedFK(bone_tag)) return true;
    const auto kind = mmd_control_workflow::ClassifyBone(bone_tag ? bone_tag->GetDataInstance() : nullptr);
    if (mmd_control_workflow::IsForcedIK(bone_tag))
        return kind.limb_fk;
	if (!bone_tag || !bone_tag->GetDataInstance()->GetBool(PMX_BONE_ROTATABLE))
		return false;
	Vector translation;
	std::array<Float32, 4> rotation{};
	return GetControlDeltaInBoneSpace(bone_tag, bone_tag->GetObject(), translation, rotation)
		&& (std::abs(rotation[0]) + std::abs(rotation[1]) + std::abs(rotation[2]) > 1.0e-6f);
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
    BaseObject* model = GetControlModel(reinterpret_cast<BaseObject*>(bone_manager.Get()));
    hash = MixHash(hash, mmd_control_workflow::RuntimeChecksum(model));
    std::vector<mmd_control_workflow::ExtraControl> extras;
    mmd_control_workflow::CollectExtraControls(bone_manager, extras);
    for (const auto& extra : extras) hash = HashMatrix(hash, NormalizeMatrixBasis(extra.object->GetRelMl()));
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

        if (mmd_control_workflow::IsForcedIK(bone_tag) && mmd_control_workflow::ClassifyBone(bc).limb_ik) continue;
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

Bool mmd_bone_control_util::GetControlDeltaInBoneSpace(BaseTag* bone_tag, BaseObject* bone_object, Vector& translation, std::array<Float32, 4>& rotation,
	const std::array<Float32, 4>& animation_rotation, const Vector& animation_translation)
{
	const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
	if (!IsBoneControlEligible(bc))
		return false;

	BaseObject* const control = ResolveLinkedObjectParameter(bone_tag, PMX_BONE_CONTROL_LINK);
	if (!control || !bone_object)
		return false;

    if (mmd_control_workflow::GetDirectGoalDelta(bone_tag,bone_object,animation_translation,animation_rotation,translation,rotation)) return true;
    if (!mmd_control_workflow::IsInputEnabled(bone_tag)) return false;

	// An inactive control contributes no animation delta. Projecting identity
	// through float bases can introduce a rotation that depends on the last
	// synchronized control pose and perturb a cold physics replay.
	if (IsMatrixIdentityLike(control->GetRelMl()))
		return false;

	const Eigen::Matrix4f control_rest = MatrixToEigen(BuildControlBaseGlobalMatrix(control));
	// Use the deterministic animation basis, never the previous solved pose.
	// Feeding last-frame IK/FK back into this conversion makes a held control drift.
	BaseObject* const bone_parent = bone_object->GetUp();
	const Matrix parent_matrix = bone_parent ? bone_parent->GetMg() : Matrix();
	const Eigen::Matrix4f bone_rest = MatrixToEigen(NormalizeMatrixBasis(parent_matrix * bone_object->GetFrozenMln()));
	const Eigen::Matrix4f control_delta = MatrixToEigen(NormalizeMatrixBasis(control->GetRelMl()));

	const Eigen::Matrix3f control_basis = control_rest.block<3, 3>(0, 0);
	const Eigen::Matrix3f bone_basis = bone_rest.block<3, 3>(0, 0);
	const Eigen::Vector3f control_translation = control_delta.block<3, 1>(0, 3);
	const Eigen::Vector3f bone_translation = bone_basis.transpose() * control_basis * control_translation;

	const Eigen::Quaternionf control_rotation = ExtractRotation(control_delta);
	const Eigen::Matrix3f parent_rotation = control_basis * control_rotation.toRotationMatrix() * control_basis.transpose();
	const Eigen::Quaternionf animation_quaternion(animation_rotation[3], animation_rotation[0], animation_rotation[1], animation_rotation[2]);
	const Eigen::Matrix3f animation_basis = bone_basis * animation_quaternion.normalized().toRotationMatrix();
	const Eigen::Matrix3f bone_rotation = animation_basis.transpose() * parent_rotation * animation_basis;

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
