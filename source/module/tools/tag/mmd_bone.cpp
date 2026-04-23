/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_bone.h"

#include "customgui_priority.h"
#include "ocajoint.h"
#include "tprotection.h"
#include "maxon/quaternion.h"
#include "description/TMMDBone.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/object/mmd_model_manager.h"
#include "libMMD/Model/MMD/MMDIkSolver.h"
#include "libMMD/Model/MMD/VMDInterpolation.h"
#include "utils/math_util.hpp"
#include "utils/string_util.hpp"

namespace
{
	constexpr Float32 kBoneAnimationFps = 30.F;
	constexpr Float32 kBoneAnimationSplineMax = 127.F;

	Int32 NormalizeBoneMode(const Int32 mode)
	{
		constexpr Int32 kLegacyBoneModeVmd = 2;
		return mode == kLegacyBoneModeVmd ? BONE_MODE_ANIM : mode;
	}

	BaseObject* ResolveBoneManagerObjectFromHierarchy(BaseObject* bone_object)
	{
		for (BaseObject* current = bone_object; current != nullptr; current = current->GetUp())
		{
			if (current->IsInstanceOf(g_mmd_bone_manager_object_id))
				return current;
		}
		return nullptr;
	}

	SplineData* GetSplineDataWritable(GeData& data)
	{
#if API_VERSION < 2024000
		return static_cast<SplineData*>(data.GetCustomDataType(CUSTOMDATATYPE_SPLINE));
#else
		return data.GetCustomDataTypeWritable<SplineData>();
#endif
	}

	const SplineData* GetSplineData(const GeData& data)
	{
#if API_VERSION < 2024000
		return static_cast<const SplineData*>(const_cast<GeData&>(data).GetCustomDataType(CUSTOMDATATYPE_SPLINE));
#else
		return data.GetCustomDataType<SplineData>();
#endif
	}

	const CustomSplineKnot* GetSplineKnot(const SplineData* spline, const Int32 index)
	{
		if (!spline)
			return nullptr;
#if API_VERSION < 23000
		return const_cast<SplineData*>(spline)->GetKnot(index);
#else
		return spline->GetKnot(index);
#endif
	}

	Float32 ClampSplineCoordinate(const Float value)
	{
		return maxon::SafeConvert<Float32>(std::clamp(value, 0.0, static_cast<double>(kBoneAnimationSplineMax)));
	}

	std::array<Float32, 4> NormalizeQuaternion(std::array<Float32, 4> rotation)
	{
		const Float64 length = std::sqrt(
			static_cast<Float64>(rotation[0]) * rotation[0] +
			static_cast<Float64>(rotation[1]) * rotation[1] +
			static_cast<Float64>(rotation[2]) * rotation[2] +
			static_cast<Float64>(rotation[3]) * rotation[3]);
		if (length <= std::numeric_limits<Float64>::epsilon())
			return { 0.F, 0.F, 0.F, 1.F };

		for (Float32& component : rotation)
			component = maxon::SafeConvert<Float32>(component / length);
		return rotation;
	}

	std::array<Float32, 4> EulerToQuaternionArray(const Vector& euler)
	{
		const auto quaternion = math_util::EulerToQuaternion(euler);
		return NormalizeQuaternion({
			maxon::SafeConvert<Float32>(quaternion.x),
			maxon::SafeConvert<Float32>(quaternion.y),
			maxon::SafeConvert<Float32>(quaternion.z),
			maxon::SafeConvert<Float32>(quaternion.w)
		});
	}

	Vector QuaternionToEulerVector(const std::array<Float32, 4>& rotation)
	{
		const auto euler = math_util::QuaternionToEuler(rotation);
		return Vector(euler.x, euler.y, euler.z);
	}

	Eigen::Quaternionf ToEigenQuaternion(const std::array<Float32, 4>& rotation)
	{
		return Eigen::Quaternionf(rotation[3], rotation[0], rotation[1], rotation[2]).normalized();
	}

	std::array<Float32, 4> ToQuaternionArray(const Eigen::Quaternionf& rotation)
	{
		const Eigen::Quaternionf normalized = rotation.normalized();
		return NormalizeQuaternion({
			maxon::SafeConvert<Float32>(normalized.x()),
			maxon::SafeConvert<Float32>(normalized.y()),
			maxon::SafeConvert<Float32>(normalized.z()),
			maxon::SafeConvert<Float32>(normalized.w())
		});
	}

	void MarkBoneTransformDirty(BaseObject* object)
	{
		if (!object)
			return;

		object->Touch();
		object->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA);
		object->Message(MSG_UPDATE);
	}

	BaseObject* ResolveBoneObjectFromLinkData(const GeData& link_data, const BaseDocument* doc)
	{
		const BaseLink* const link = link_data.GetBaseLink();
		if (!link)
			return nullptr;

		const BaseList2D* linked = nullptr;
		if (doc)
			linked = link->GetLink(doc);
		else
			linked = link->ForceGetLink();
		if (!linked)
			return nullptr;

		BaseList2D* const linked_mutable = const_cast<BaseList2D*>(linked);
		if (linked_mutable->IsInstanceOf(Ojoint))
			return static_cast<BaseObject*>(linked_mutable);
		if (linked_mutable->IsInstanceOf(g_mmd_bone_tag_id))
			return static_cast<BaseTag*>(linked_mutable)->GetObject();
		return nullptr;
	}

	struct StandaloneIKChainEntry
	{
		Int32 bone_index = -1;
		BaseObject* linked_object = nullptr;
		Bool enable_limit = false;
		Vector limit_min;
		Vector limit_max;
	};

	bool DescItemHasParent(const BaseContainer& bc, const DescID& parent_id)
	{
		const DescID* const parent_id_ptr = GetContainerCustomDataType<DescID>(bc, DESC_PARENTGROUP, CUSTOMDATATYPE_DESCID);
		return parent_id_ptr != nullptr && *parent_id_ptr == parent_id;
	}

	bool CollectStandaloneIKChainEntries(BaseTag* tag, maxon::BaseArray<StandaloneIKChainEntry>& entries)
	{
		iferr_scope_handler{
			return false;
		};

		entries.Reset();
		if (!tag)
			return false;

		DynamicDescription* const dyn_desc = tag->GetDynamicDescriptionWritable();
		if (!dyn_desc)
			return false;

		BaseDocument* const tag_doc = tag->GetDocument();
		const DescID ik_links_root = ConstDescID(DescLevel(PMX_BONE_IK_LINKS_GRP));

		struct EntryFieldIds
		{
			DescID entry_group_id;
			DescID index_group_id;
			DescID bone_index_id;
			DescID bone_link_id;
			DescID enable_limit_id;
			DescID limit_min_id;
			DescID limit_max_id;
			Bool has_index_group = false;
			Bool has_bone_index = false;
			Bool has_bone_link = false;
			Bool has_enable_limit = false;
			Bool has_limit_min = false;
			Bool has_limit_max = false;
		};

		maxon::BaseArray<EntryFieldIds> entry_fields;
		void* browse_handle = dyn_desc->BrowseInit();
		DescID browse_id;
		const BaseContainer* browse_bc = nullptr;

		while (dyn_desc->BrowseGetNext(browse_handle, &browse_id, &browse_bc))
		{
			if (!browse_bc || !DescItemHasParent(*browse_bc, ik_links_root))
				continue;
			if (browse_id.GetDepth() < 1 || browse_id[0].dtype != DTYPE_GROUP)
				continue;

			auto& field_ids = entry_fields.Append()iferr_return;
			field_ids.entry_group_id = browse_id;
		}
		dyn_desc->BrowseFree(browse_handle);

		for (auto& field_ids : entry_fields)
		{
			browse_handle = dyn_desc->BrowseInit();
			while (dyn_desc->BrowseGetNext(browse_handle, &browse_id, &browse_bc))
			{
				if (!browse_bc || !DescItemHasParent(*browse_bc, field_ids.entry_group_id) || browse_id.GetDepth() < 1)
					continue;

				switch (browse_id[0].dtype)
				{
				case DTYPE_GROUP:
					field_ids.index_group_id = browse_id;
					field_ids.has_index_group = true;
					break;
				case DTYPE_BOOL:
					field_ids.enable_limit_id = browse_id;
					field_ids.has_enable_limit = true;
					break;
				case DTYPE_VECTOR:
					if (!field_ids.has_limit_min)
					{
						field_ids.limit_min_id = browse_id;
						field_ids.has_limit_min = true;
					}
					else if (!field_ids.has_limit_max)
					{
						field_ids.limit_max_id = browse_id;
						field_ids.has_limit_max = true;
					}
					break;
				default:
					break;
				}
			}
			dyn_desc->BrowseFree(browse_handle);

			if (field_ids.has_index_group)
			{
				browse_handle = dyn_desc->BrowseInit();
				while (dyn_desc->BrowseGetNext(browse_handle, &browse_id, &browse_bc))
				{
					if (!browse_bc || !DescItemHasParent(*browse_bc, field_ids.index_group_id) || browse_id.GetDepth() < 1)
						continue;

					switch (browse_id[0].dtype)
					{
					case DTYPE_LONG:
						field_ids.bone_index_id = browse_id;
						field_ids.has_bone_index = true;
						break;
					case DTYPE_BASELISTLINK:
						field_ids.bone_link_id = browse_id;
						field_ids.has_bone_link = true;
						break;
					default:
						break;
					}
				}
				dyn_desc->BrowseFree(browse_handle);
			}

			auto& entry = entries.Append()iferr_return;
			if (field_ids.has_bone_index)
			{
				GeData value;
				if (tag->GetParameter(field_ids.bone_index_id, value, DESCFLAGS_GET::NONE))
					entry.bone_index = value.GetInt32();
			}
			if (field_ids.has_bone_link)
			{
				GeData link_data;
				if (tag->GetParameter(field_ids.bone_link_id, link_data, DESCFLAGS_GET::NONE))
				{
					if (BaseObject* const linked_object = ResolveBoneObjectFromLinkData(link_data, tag_doc))
						entry.linked_object = linked_object;
				}
			}
			if (field_ids.has_enable_limit)
			{
				GeData value;
				if (tag->GetParameter(field_ids.enable_limit_id, value, DESCFLAGS_GET::NONE))
					entry.enable_limit = value.GetBool();
			}
			if (field_ids.has_limit_min)
			{
				GeData value;
				if (tag->GetParameter(field_ids.limit_min_id, value, DESCFLAGS_GET::NONE))
					entry.limit_min = value.GetVector();
			}
			if (field_ids.has_limit_max)
			{
				GeData value;
				if (tag->GetParameter(field_ids.limit_max_id, value, DESCFLAGS_GET::NONE))
					entry.limit_max = value.GetVector();
			}
		}

		if (!entries.IsEmpty())
			return true;

		// Fallback to the legacy browse-order parser. It is less robust to
		// description layout drift, but it preserves working IK behavior for
		// existing scenes if the structured parent-group walk cannot see the
		// dynamic link entries.
		const String name_ik_bone = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_BONE);
		const String name_enable_limit = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_ENABLE_LIMIT);
		const String name_limit_min = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MIN);
		const String name_limit_max = GeLoadString(IDS_CMT_MODEL_MANAGER_IK_LIMIT_MAX);

		void* legacy_handle = dyn_desc->BrowseInit();
		DescID legacy_id;
		const BaseContainer* legacy_bc = nullptr;

		while (dyn_desc->BrowseGetNext(legacy_handle, &legacy_id, &legacy_bc))
		{
			if (!legacy_bc)
				continue;

			const String name = legacy_bc->GetString(DESC_NAME);
			GeData value;

			if (name == name_ik_bone)
			{
				auto& entry = entries.Append()iferr_return;
				if (tag->GetParameter(legacy_id, value, DESCFLAGS_GET::NONE))
					entry.bone_index = value.GetInt32();
			}
			else if (!entries.IsEmpty())
			{
				auto& current = entries[entries.GetCount() - 1];
				if (name == name_enable_limit)
				{
					if (tag->GetParameter(legacy_id, value, DESCFLAGS_GET::NONE))
						current.enable_limit = value.GetBool();
				}
				else if (name == name_limit_min)
				{
					if (tag->GetParameter(legacy_id, value, DESCFLAGS_GET::NONE))
						current.limit_min = value.GetVector();
				}
				else if (name == name_limit_max)
				{
					if (tag->GetParameter(legacy_id, value, DESCFLAGS_GET::NONE))
						current.limit_max = value.GetVector();
				}
				else if (current.linked_object == nullptr && name.IsEmpty())
				{
					GeData link_data;
					if (tag->GetParameter(legacy_id, link_data, DESCFLAGS_GET::NONE))
					{
						if (BaseObject* const linked_object = ResolveBoneObjectFromLinkData(link_data, tag_doc))
							current.linked_object = linked_object;
					}
				}
			}
		}
		dyn_desc->BrowseFree(legacy_handle);

		return true;
	}

	Int32 ComputeBoneExecutionPriorityValue(const BaseContainer* bc, const Int32 append_depth)
	{
		const Int32 layer = bc ? std::max(0, bc->GetInt32(PMX_BONE_LAYER)) : 0;
		const Int32 depth = std::max(0, append_depth);
		return layer * 100 + depth;
	}

	GeData CreateDefaultAnimationSplineData()
	{
		GeData data(CUSTOMDATATYPE_SPLINE, DEFAULTVALUE);
		if (SplineData* const spline = GetSplineDataWritable(data))
		{
			spline->AdaptRange(0.0, kBoneAnimationSplineMax, kBoneAnimationSplineMax, 0.0, kBoneAnimationSplineMax, kBoneAnimationSplineMax);
			spline->InsertKnot(0.0, 0.0, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
			spline->InsertKnot(kBoneAnimationSplineMax, kBoneAnimationSplineMax, FLAG_KNOT_LOCK_X | FLAG_KNOT_LOCK_Y);
			spline->SetUserCallback(MMDBoneTag::SplineDataCallBack, nullptr);
			if (CustomSplineKnot* const a = spline->GetKnot(0))
			{
				a->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
				a->vTangentRight = Vector(20., 20., 0.);
			}
			if (CustomSplineKnot* const b = spline->GetKnot(spline->GetKnotCount() - 1))
			{
				b->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
				b->vTangentLeft = Vector(-20., -20., 0.);
			}
		}
		return data;
	}

	BoneAnimationBezierData ReadBezierFromSpline(const SplineData* spline)
	{
		BoneAnimationBezierData bezier;
		if (!spline || spline->GetKnotCount() < 2)
			return bezier;

		const CustomSplineKnot* const first = GetSplineKnot(spline, 0);
		const CustomSplineKnot* const last = GetSplineKnot(spline, spline->GetKnotCount() - 1);
		if (!first || !last)
			return bezier;

		const Vector first_right = first->vPos + first->vTangentRight;
		const Vector last_left = last->vPos + last->vTangentLeft;
		bezier.ax = maxon::SafeConvert<UChar>(ClampSplineCoordinate(first_right.x));
		bezier.ay = maxon::SafeConvert<UChar>(ClampSplineCoordinate(first_right.y));
		bezier.bx = maxon::SafeConvert<UChar>(ClampSplineCoordinate(last_left.x));
		bezier.by = maxon::SafeConvert<UChar>(ClampSplineCoordinate(last_left.y));
		return bezier;
	}

	void WriteBezierToSpline(const BoneAnimationBezierData& bezier, SplineData* spline)
	{
		if (!spline || spline->GetKnotCount() < 2)
			return;

		CustomSplineKnot* const first = spline->GetKnot(0);
		CustomSplineKnot* const last = spline->GetKnot(spline->GetKnotCount() - 1);
		if (!first || !last)
			return;

		first->vPos = Vector(0.);
		last->vPos = Vector(kBoneAnimationSplineMax, kBoneAnimationSplineMax, 0.);
		first->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		last->interpol = CustomSplineKnotInterpolation::CustomSplineKnotInterpolationBezier;
		first->vTangentLeft = Vector();
		first->vTangentRight = Vector(bezier.ax, bezier.ay, 0.);
		last->vTangentRight = Vector();
		last->vTangentLeft = Vector(
			static_cast<Float>(bezier.bx) - kBoneAnimationSplineMax,
			static_cast<Float>(bezier.by) - kBoneAnimationSplineMax,
			0.);
	}

	const BoneAnimationBezierData& SelectBezierChannel(const BoneAnimationKeyframeData& keyframe, const Int32 curve_type)
	{
		switch (curve_type)
		{
		case PMX_BONE_ANIM_CURVE_Y:
			return keyframe.translate_y;
		case PMX_BONE_ANIM_CURVE_Z:
			return keyframe.translate_z;
		case PMX_BONE_ANIM_CURVE_R:
			return keyframe.rotation;
		case PMX_BONE_ANIM_CURVE_A:
		case PMX_BONE_ANIM_CURVE_X:
		default:
			return keyframe.translate_x;
		}
	}

	void AssignBezierChannel(BoneAnimationKeyframeData& keyframe, const Int32 curve_type, const BoneAnimationBezierData& bezier)
	{
		switch (curve_type)
		{
		case PMX_BONE_ANIM_CURVE_Y:
			keyframe.translate_y = bezier;
			break;
		case PMX_BONE_ANIM_CURVE_Z:
			keyframe.translate_z = bezier;
			break;
		case PMX_BONE_ANIM_CURVE_R:
			keyframe.rotation = bezier;
			break;
		case PMX_BONE_ANIM_CURVE_A:
			keyframe.translate_x = bezier;
			keyframe.translate_y = bezier;
			keyframe.translate_z = bezier;
			keyframe.rotation = bezier;
			break;
		case PMX_BONE_ANIM_CURVE_X:
		default:
			keyframe.translate_x = bezier;
			break;
		}
	}

	libmmd::VMDBezier ToLibMMDBezier(const BoneAnimationBezierData& bezier)
	{
		std::array<uint8_t, 4> cp { bezier.ax, bezier.ay, bezier.bx, bezier.by };
		libmmd::VMDBezier result;
		libmmd::SetVMDBezier(result, cp.data());
		return result;
	}

	libmmd::VMDBoneKeyframe ToLibMMDKeyframe(const BoneAnimationKeyframeData& keyframe)
	{
		libmmd::VMDBoneKeyframe result;
		result.frame = keyframe.frame;
		result.translate = Eigen::Vector3f(keyframe.translation.x, keyframe.translation.y, keyframe.translation.z);
		result.rotate = Eigen::Quaternionf(keyframe.rotation_w, keyframe.rotation_x, keyframe.rotation_y, keyframe.rotation_z).normalized();
		result.txBezier = ToLibMMDBezier(keyframe.translate_x);
		result.tyBezier = ToLibMMDBezier(keyframe.translate_y);
		result.tzBezier = ToLibMMDBezier(keyframe.translate_z);
		result.rotBezier = ToLibMMDBezier(keyframe.rotation);
		return result;
	}

	Matrix BuildAnimationMatrix(const Vector& translation, const std::array<Float32, 4>& rotation)
	{
		const Eigen::Matrix3f rot = Eigen::Quaternionf(rotation[3], rotation[0], rotation[1], rotation[2]).normalized().toRotationMatrix();
		return Matrix{
			translation,
			Vector(rot(0, 0), rot(1, 0), rot(2, 0)),
			Vector(rot(0, 1), rot(1, 1), rot(2, 1)),
			Vector(rot(0, 2), rot(1, 2), rot(2, 2))
		};
	}

	Int32 GetAnimationFrameFromDocument(BaseDocument* doc)
	{
		return doc ? doc->GetTime().GetFrame(kBoneAnimationFps) : 0;
	}

	BaseTime GetDocumentTimeOrInvalid(const BaseDocument* doc)
	{
		return doc ? doc->GetTime() : BaseTime(-1.);
	}

	Float GetAnimationFrameFromDocumentContinuous(BaseDocument* doc)
	{
		if (!doc)
			return 0.0f;

		return maxon::SafeConvert<Float>(doc->GetTime().Get() * static_cast<Float64>(kBoneAnimationFps));
	}

	BaseTime GetAnimationFrameTime(const Int32 frame)
	{
		return BaseTime(static_cast<Float>(frame), kBoneAnimationFps);
	}

	Eigen::Matrix4f MatrixToEigen(const Matrix& matrix)
	{
		Eigen::Matrix4f eigen = Eigen::Matrix4f::Identity();
		eigen(0, 0) = static_cast<float>(matrix.sqmat.v1.x);
		eigen(1, 0) = static_cast<float>(matrix.sqmat.v1.y);
		eigen(2, 0) = static_cast<float>(matrix.sqmat.v1.z);
		eigen(0, 1) = static_cast<float>(matrix.sqmat.v2.x);
		eigen(1, 1) = static_cast<float>(matrix.sqmat.v2.y);
		eigen(2, 1) = static_cast<float>(matrix.sqmat.v2.z);
		eigen(0, 2) = static_cast<float>(matrix.sqmat.v3.x);
		eigen(1, 2) = static_cast<float>(matrix.sqmat.v3.y);
		eigen(2, 2) = static_cast<float>(matrix.sqmat.v3.z);
		eigen(0, 3) = static_cast<float>(matrix.off.x);
		eigen(1, 3) = static_cast<float>(matrix.off.y);
		eigen(2, 3) = static_cast<float>(matrix.off.z);
		return eigen;
	}

	Matrix NormalizeMatrixBasis(const Matrix& matrix)
	{
		Matrix normalized = matrix;
		normalized.sqmat = normalized.sqmat.GetNormalized();
		return normalized;
	}

	Matrix EigenToMatrix(const Eigen::Matrix4f& matrix)
	{
		return Matrix{
			Vector(matrix(0, 3), matrix(1, 3), matrix(2, 3)),
			Vector(matrix(0, 0), matrix(1, 0), matrix(2, 0)),
			Vector(matrix(0, 1), matrix(1, 1), matrix(2, 1)),
			Vector(matrix(0, 2), matrix(1, 2), matrix(2, 2))
		};
	}

	Matrix RelativeMatrixFromTranslationRotation(const Eigen::Vector3f& translation, const Eigen::Quaternionf& rotation)
	{
		const Eigen::Matrix3f basis = rotation.normalized().toRotationMatrix();
		return Matrix{
			Vector(translation.x(), translation.y(), translation.z()),
			Vector(basis(0, 0), basis(1, 0), basis(2, 0)),
			Vector(basis(0, 1), basis(1, 1), basis(2, 1)),
			Vector(basis(0, 2), basis(1, 2), basis(2, 2))
		};
	}

	Eigen::Quaternionf ExtractRotation(const Eigen::Matrix4f& matrix)
	{
		return Eigen::Quaternionf(matrix.block<3, 3>(0, 0)).normalized();
	}
}

void C4DIKChainNodeAdapter::SetupFromBone(BaseObject* bone_object, MMDBoneTag* bone_tag, std::string name)
{
	bone_object_ = bone_object;
	bone_tag_ = bone_tag;
	name_ = std::move(name);
	parent_ = nullptr;
	children_.clear();
	initial_local_transform_ = Eigen::Matrix4f::Identity();
	initial_global_transform_ = Eigen::Matrix4f::Identity();
	global_transform_ = Eigen::Matrix4f::Identity();
	local_transform_ = Eigen::Matrix4f::Identity();
	animate_translation_ = Eigen::Vector3f::Zero();
	animate_rotation_ = Eigen::Quaternionf::Identity();
	ik_rotation_ = Eigen::Quaternionf::Identity();
}

void C4DIKChainNodeAdapter::SetParentAdapter(C4DIKChainNodeAdapter* parent)
{
	parent_ = parent;
}

void C4DIKChainNodeAdapter::ClearChildren()
{
	children_.clear();
}

void C4DIKChainNodeAdapter::AddChildAdapter(C4DIKChainNodeAdapter* child)
{
	if (child)
		children_.push_back(child);
}

void C4DIKChainNodeAdapter::UpdateInitialGlobalTransform()
{
	std::vector<C4DIKChainNodeAdapter*> stack;
	stack.push_back(this);
	while (!stack.empty())
	{
		C4DIKChainNodeAdapter* const current = stack.back();
		stack.pop_back();
		if (!current)
			continue;

		if (current->bone_object_)
			current->initial_local_transform_ = MatrixToEigen(NormalizeMatrixBasis(current->bone_object_->GetFrozenMln()));
		else
			current->initial_local_transform_ = Eigen::Matrix4f::Identity();

		if (current->parent_ != nullptr)
			current->initial_global_transform_ = current->parent_->initial_global_transform_ * current->initial_local_transform_;
		else
			current->initial_global_transform_ = current->initial_local_transform_;

		for (auto it = current->children_.rbegin(); it != current->children_.rend(); ++it)
			stack.push_back(*it);
	}
}

void C4DIKChainNodeAdapter::SyncCurrentTransformsFromBoneObject(const Bool reset_ik_rotation)
{
	if (!bone_object_)
		return;

	// local_transform_ must always reflect the full GetMl() = frozen * relative,
	// because this function is called both during initial build (when
	// initial_local_transform_ is still Identity) and at runtime.
	const Matrix local_matrix = NormalizeMatrixBasis(bone_object_->GetMl());
	local_transform_ = MatrixToEigen(local_matrix);
	global_transform_ = local_transform_;

	// Extract the PURE animation rotation/translation from RelMl (excludes the
	// frozen rest-pose). The CCD solver's axis-limit check decomposes
	// (ik_rotation * animate_rotation) into Euler angles and clamps against PMX
	// limits that are defined relative to the rest pose. Mixing the frozen
	// rotation into animate_rotation_ would corrupt those angles.
	const Matrix relative_matrix = bone_object_->GetRelMl();
	const Eigen::Matrix4f relative_eigen = MatrixToEigen(relative_matrix);
	animate_rotation_ = ExtractRotation(relative_eigen);
	animate_translation_ = relative_eigen.block<3, 1>(0, 3);

	if (reset_ik_rotation)
		ik_rotation_ = Eigen::Quaternionf::Identity();
}

void C4DIKChainNodeAdapter::GetCurrentRelativeState(Vector& translation, std::array<Float32, 4>& rotation) const
{
	const Eigen::Matrix4f relative_local = initial_local_transform_.inverse() * local_transform_;
	const Eigen::Vector3f relative_translation = relative_local.block<3, 1>(0, 3);
	translation = Vector(relative_translation.x(), relative_translation.y(), relative_translation.z());
	rotation = ToQuaternionArray(ExtractRotation(relative_local));
}

void C4DIKChainNodeAdapter::ApplyLocalToBoneObject() const
{
	if (!bone_object_)
		return;

	const Eigen::Matrix4f relative_local = initial_local_transform_.inverse() * local_transform_;
	const Eigen::Vector3f relative_translation = relative_local.block<3, 1>(0, 3);
	bone_object_->SetRelMl(RelativeMatrixFromTranslationRotation(relative_translation, ExtractRotation(relative_local)));
	MarkBoneTransformDirty(bone_object_);
	if (bone_tag_)
		bone_tag_->evaluated_ik_rotation_ = ToQuaternionArray(ik_rotation_);
}

Int32 C4DIKChainNodeAdapter::GetBoneIndex() const
{
	return bone_tag_ ? bone_tag_->GetBoneIndex() : -1;
}

void C4DIKChainNodeAdapter::SetGlobalTransform(const Eigen::Matrix4f& m)
{
	global_transform_ = m;
	if (parent_ != nullptr)
		local_transform_ = parent_->GetGlobalTransform().inverse() * global_transform_;
	else
		local_transform_ = global_transform_;
}

void C4DIKChainNodeAdapter::SyncLocalTransformFromGlobal()
{
	if (parent_ != nullptr)
		local_transform_ = parent_->GetGlobalTransform().inverse() * global_transform_;
	else
		local_transform_ = global_transform_;
}

void C4DIKChainNodeAdapter::UpdateLocalTransform()
{
	// animate_rotation_ and animate_translation_ are the pure animation
	// components (from GetRelMl), so the relative rotation is ik * anim and
	// the full local = initial (frozen) * relative.
	const Eigen::Matrix3f relative_rotation = (ik_rotation_ * animate_rotation_).normalized().toRotationMatrix();
	local_transform_ = initial_local_transform_;
	local_transform_.block<3, 3>(0, 0) = initial_local_transform_.block<3, 3>(0, 0) * relative_rotation;
	local_transform_.block<3, 1>(0, 3) = initial_local_transform_.block<3, 1>(0, 3)
		+ initial_local_transform_.block<3, 3>(0, 0) * animate_translation_;
}

void C4DIKChainNodeAdapter::UpdateGlobalTransform()
{
	std::vector<C4DIKChainNodeAdapter*> stack;
	stack.push_back(this);
	while (!stack.empty())
	{
		C4DIKChainNodeAdapter* current = stack.back();
		stack.pop_back();
		if (!current)
			continue;

		if (current->parent_ != nullptr)
			current->global_transform_ = current->parent_->global_transform_ * current->local_transform_;
		else
			current->global_transform_ = current->local_transform_;

		for (auto it = current->children_.rbegin(); it != current->children_.rend(); ++it)
			stack.push_back(*it);
	}
}

Bool BoneMorphTagData::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(grp_id);
	IOWriteField(strength_id);
	IOWriteField(translation_id);
	IOWriteField(rotation_id);
	IOWriteField(button_grp_id);
	IOWriteField(button_delete_id);
	IOWriteField(button_rename_id);
	IOWriteField(name);
	return true;
}

Bool BoneMorphTagData::Read(HyperFile* hf)
{
	IOReadField(grp_id);
	IOReadField(strength_id);
	IOReadField(translation_id);
	IOReadField(rotation_id);
	IOReadField(button_grp_id);
	IOReadField(button_delete_id);
	IOReadField(button_rename_id);
	IOReadField(name);
	return true;
}

Bool BoneAnimationBezierData::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(ax);
	IOWriteField(ay);
	IOWriteField(bx);
	IOWriteField(by);
	return true;
}

Bool BoneAnimationBezierData::Read(HyperFile* hf)
{
	IOReadField(ax);
	IOReadField(ay);
	IOReadField(bx);
	IOReadField(by);
	return true;
}

Bool BoneAnimationKeyframeData::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(frame);
	IOWriteField(translation);
	IOWriteField(rotation_x);
	IOWriteField(rotation_y);
	IOWriteField(rotation_z);
	IOWriteField(rotation_w);
	IOWriteField(translate_x);
	IOWriteField(translate_y);
	IOWriteField(translate_z);
	IOWriteField(rotation);
	return true;
}

Bool BoneAnimationKeyframeData::Read(HyperFile* hf)
{
	IOReadField(frame);
	IOReadField(translation);
	IOReadField(rotation_x);
	IOReadField(rotation_y);
	IOReadField(rotation_z);
	IOReadField(rotation_w);
	IOReadField(translate_x);
	IOReadField(translate_y);
	IOReadField(translate_z);
	IOReadField(rotation);
	return true;
}

Bool BoneAnimationSlotData::Write(HyperFile* hf) SDK2024_Const
{
	return io_util::WriteLinearContainer(hf, keyframes);
}

Bool BoneAnimationSlotData::Read(HyperFile* hf)
{
	return io_util::ReadLinearContainer(hf, keyframes);
}

BoneAnimationSlotData::BoneAnimationSlotData(const BoneAnimationSlotData& other)
{
	iferr(keyframes.CopyFrom(other.keyframes)) {}
}

BoneAnimationSlotData& BoneAnimationSlotData::operator=(const BoneAnimationSlotData& other)
{
	if (this == &other)
		return *this;

	iferr(keyframes.CopyFrom(other.keyframes))
	{
		iferr(keyframes.Resize(0)) {}
	}
	return *this;
}

Int32 MMDBoneTag::AddBoneMorph(String morph_name)
{
	iferr_scope_handler{ return NOTOK; };

	if (morph_name.IsEmpty())
	{
		morph_name = "morph_" + String::IntToString(bone_morph_name_index_);
		bone_morph_name_index_++;
	}

	auto* tag = static_cast<BaseTag*>(Get());
	DynamicDescription* ddesc = tag->GetDynamicDescriptionWritable();
	if (!ddesc)
		return NOTOK;

	auto& data = bone_morph_data_arr_.Append()iferr_return;

	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(PMX_BONE_MORPH_GRP))));
	data.grp_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.grp_id));
	data.strength_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_TRANSLATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.grp_id));
	data.translation_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_ROTATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.grp_id));
	data.rotation_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 2);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.grp_id));
	data.button_grp_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.button_grp_id));
	data.button_delete_id = ddesc->Alloc(bc);

	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(data.button_grp_id));
	data.button_rename_id = ddesc->Alloc(bc);

	const Int32 index = static_cast<Int32>(bone_morph_data_arr_.GetCount() - 1);
	bone_morph_button_id_map_.Insert(data.button_delete_id, index)iferr_return;
	bone_morph_button_id_map_.Insert(data.button_rename_id, index)iferr_return;

	if (auto* mgr = GetBoneManager())
	{
		MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_MORPH_ADD, morph_name, data.strength_id, tag);
		reinterpret_cast<BaseObject*>(mgr->Get())->Message(g_mmd_bone_tag_id, &msg);
	}

	data.name = std::move(morph_name);

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();

	return index;
}

Bool MMDBoneTag::SetBoneMorphTranslationNoCheck(const Int32 id, const Vector translation)
{
	if (id < 0 || id >= bone_morph_data_arr_.GetCount())
		return false;
	return Get()->SetParameter(bone_morph_data_arr_[id].translation_id, translation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::SetBoneMorphRotationNoCheck(const Int32 id, const Vector rotation)
{
	if (id < 0 || id >= bone_morph_data_arr_.GetCount())
		return false;
	return Get()->SetParameter(bone_morph_data_arr_[id].rotation_id, rotation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::EnsureAnimationSlotCount(const Int32 slot_count)
{
	iferr_scope_handler{
		return false;
	};

	if (slot_count < 0)
		return false;

	if (slot_count == 0)
	{
		bone_animation_slots_.Resize(0)iferr_return;
		active_animation_slot_ = -1;
		return true;
	}

	if (bone_animation_slots_.GetCount() < slot_count)
	{
		bone_animation_slots_.Resize(slot_count)iferr_return;
	}

	if (active_animation_slot_ >= slot_count)
		active_animation_slot_ = slot_count - 1;
	return true;
}

BoneAnimationSlotData* MMDBoneTag::EnsureAnimationSlot(const Int32 slot_index)
{
	if (slot_index < 0)
		return nullptr;
	if (!EnsureAnimationSlotCount(slot_index + 1))
		return nullptr;
	return &bone_animation_slots_[slot_index];
}

BoneAnimationSlotData* MMDBoneTag::GetAnimationSlot(const Int32 slot_index)
{
	if (slot_index < 0 || slot_index >= bone_animation_slots_.GetCount())
		return nullptr;
	return &bone_animation_slots_[slot_index];
}

const BoneAnimationSlotData* MMDBoneTag::GetAnimationSlot(const Int32 slot_index) const
{
	if (slot_index < 0 || slot_index >= bone_animation_slots_.GetCount())
		return nullptr;
	return &bone_animation_slots_[slot_index];
}

BoneAnimationSlotData* MMDBoneTag::GetActiveAnimationSlotData()
{
	return GetAnimationSlot(active_animation_slot_);
}

const BoneAnimationSlotData* MMDBoneTag::GetActiveAnimationSlotData() const
{
	return GetAnimationSlot(active_animation_slot_);
}

Int32 MMDBoneTag::FindAnimationKeyframeIndex(const BoneAnimationSlotData& slot, const Int32 frame) const
{
	const Int key_count = slot.keyframes.GetCount();
	for (Int index = 0; index < key_count; ++index)
	{
		if (slot.keyframes[index].frame == frame)
			return static_cast<Int32>(index);
	}
	return NOTOK;
}

BoneAnimationKeyframeData* MMDBoneTag::FindAnimationKeyframe(BoneAnimationSlotData& slot, const Int32 frame)
{
	const Int32 index = FindAnimationKeyframeIndex(slot, frame);
	return index == NOTOK ? nullptr : &slot.keyframes[index];
}

const BoneAnimationKeyframeData* MMDBoneTag::FindAnimationKeyframe(const BoneAnimationSlotData& slot, const Int32 frame) const
{
	const Int32 index = FindAnimationKeyframeIndex(slot, frame);
	return index == NOTOK ? nullptr : &slot.keyframes[index];
}

void MMDBoneTag::ResetEvaluatedAnimationState()
{
	evaluated_animation_translation_ = Vector();
	evaluated_animation_rotation_ = { 0.F, 0.F, 0.F, 1.F };
	evaluated_append_animation_translation_ = Vector();
	evaluated_append_animation_rotation_ = { 0.F, 0.F, 0.F, 1.F };
	evaluated_ik_rotation_ = { 0.F, 0.F, 0.F, 1.F };
}

void MMDBoneTag::InvalidateAnimationUICache()
{
	ui_animation_frame_cache_ = NOTOK;
	ui_animation_curve_type_cache_ = NOTOK;
}

void MMDBoneTag::SetEvaluatedAnimationState(const Vector& translation, const std::array<Float32, 4>& rotation)
{
	evaluated_animation_translation_ = translation;
	evaluated_animation_rotation_ = NormalizeQuaternion(rotation);
}

void MMDBoneTag::GetEvaluatedAnimatedLocalState(Vector& translation, std::array<Float32, 4>& rotation) const
{
	translation = evaluated_animation_translation_ + evaluated_append_animation_translation_;
	rotation = ToQuaternionArray(
		ToEigenQuaternion(evaluated_animation_rotation_) * ToEigenQuaternion(evaluated_append_animation_rotation_));
}

void MMDBoneTag::BeginPrephysicsFrame(const BaseDocument* doc)
{
	const BaseTime current_time = GetDocumentTimeOrInvalid(doc);
	if (last_prephysics_time_ == current_time)
		return;

	last_prephysics_time_ = current_time;
	skip_prephysics_scene_write_ = false;
	ik_overridden_this_frame_ = false;
}

void MMDBoneTag::MarkPrephysicsSceneWriteSkipped(const BaseDocument* doc)
{
	last_prephysics_time_ = GetDocumentTimeOrInvalid(doc);
	skip_prephysics_scene_write_ = true;
	ik_overridden_this_frame_ = true;
}

Bool MMDBoneTag::ShouldSkipPrephysicsSceneWrite(const BaseDocument* doc) const
{
	return last_prephysics_time_ == GetDocumentTimeOrInvalid(doc) && skip_prephysics_scene_write_;
}

Bool MMDBoneTag::HasRecentPlaybackRuntimeOverride(const BaseDocument* doc) const
{
	if (!has_runtime_playback_override_)
		return false;

	// Keep same-frame physics/IK overrides from being clobbered by later tag
	// executions, but allow the next frame to restore the freshly sampled
	// animation before pre-physics / post-physics evaluation runs again.
	return runtime_playback_override_time_ == GetDocumentTimeOrInvalid(doc);
}

void MMDBoneTag::ClearPlaybackRuntimeOverride()
{
	has_runtime_playback_override_ = false;
	runtime_playback_override_time_ = BaseTime(-1.);
	runtime_playback_override_translation_ = Vector();
	runtime_playback_override_rotation_ = { 0.F, 0.F, 0.F, 1.F };
}

void MMDBoneTag::SetPlaybackRuntimeOverride(const BaseDocument* doc, const Vector& translation, const std::array<Float32, 4>& rotation)
{
	runtime_playback_override_time_ = GetDocumentTimeOrInvalid(doc);
	runtime_playback_override_translation_ = translation;
	runtime_playback_override_rotation_ = NormalizeQuaternion(rotation);
	has_runtime_playback_override_ = true;
}

Bool MMDBoneTag::GetPlaybackRuntimeOverride(Vector& translation, std::array<Float32, 4>& rotation) const
{
	if (!has_runtime_playback_override_)
		return false;

	const BaseTag* const self_tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get());
	const BaseDocument* const doc = self_tag ? self_tag->GetDocument() : nullptr;
	if (runtime_playback_override_time_ != GetDocumentTimeOrInvalid(doc))
		return false;

	translation = runtime_playback_override_translation_;
	rotation = runtime_playback_override_rotation_;
	return true;
}

Bool MMDBoneTag::HasPostPhysicsIKSolveAtTime(const BaseDocument* doc) const
{
	return doc != nullptr && last_postphysics_ik_solve_time_ == doc->GetTime();
}

void MMDBoneTag::MarkPostPhysicsIKSolvedAtTime(const BaseDocument* doc)
{
	last_postphysics_ik_solve_time_ = doc ? doc->GetTime() : BaseTime(-1.);
}

void MMDBoneTag::SetAppendRecursionDepth(const Int32 depth)
{
	append_recursion_depth_ = std::max(0, depth);
}

void MMDBoneTag::RefreshExecutionPriority(GeListNode* node)
{
	if (!node)
		node = Get();
	if (!node)
		return;

	BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return;

	if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
	{
		if (auto* pd = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA))
		{
			pd->SetPriorityValue(PRIORITYVALUE_MODE, CYCLE_EXPRESSION);
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, ComputeBoneExecutionPriorityValue(bc, append_recursion_depth_));
			bc->SetData(EXPRESSION_PRIORITY, priority);
		}
	}
}

BaseTag* MMDBoneTag::ResolveInheritSourceBoneTag() const
{
	BaseTag* const self_tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get());
	const BaseContainer* const bc = self_tag ? self_tag->GetDataInstance() : nullptr;
	if (!bc)
		return nullptr;

	const BaseDocument* const doc = self_tag ? self_tag->GetDocument() : nullptr;
	GeData link_data;
	if (self_tag && GetAtomParameter(self_tag, ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link_data, DESCFLAGS_GET::NONE))
	{
		if (BaseObject* const linked_object = ResolveBoneObjectFromLinkData(link_data, doc))
		{
			if (BaseTag* const linked_tag = linked_object->GetTag(g_mmd_bone_tag_id))
			{
				if (linked_tag != self_tag)
					return linked_tag;
			}
		}
	}

	const Int32 source_index = bc->GetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX);
	if (source_index < 0)
		return nullptr;

	if (MMDBoneManagerObject* const mgr = bone_manager_data_ ? bone_manager_data_ : const_cast<MMDBoneTag*>(this)->GetBoneManager())
	{
		if (BaseTag* const source_tag = mgr->FindBone(source_index))
		{
			if (source_tag != self_tag)
				return source_tag;
		}
	}

	return nullptr;
}

void MMDBoneTag::SyncInheritSourceIndexFromLink(GeListNode* node, const GeData& link_data)
{
	if (!node || is_syncing_inherit_source_)
		return;

	BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return;

	Int32 source_index = -1;
	if (BaseObject* const linked_object = ResolveBoneObjectFromLinkData(link_data, reinterpret_cast<BaseList2D*>(node)->GetDocument()))
	{
		if (BaseTag* const linked_tag = linked_object->GetTag(g_mmd_bone_tag_id))
		{
			if (const auto* linked_node = linked_tag->GetNodeData<MMDBoneTag>())
				source_index = linked_node->GetBoneIndex();
			else if (MMDBoneManagerObject* const mgr = GetBoneManager())
				source_index = mgr->FindBoneIndex(linked_tag);
		}
	}

	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, source_index);
}

void MMDBoneTag::SyncInheritSourceLinkFromIndex(GeListNode* node, const Int32 bone_index)
{
	if (!node || is_syncing_inherit_source_)
		return;

	BaseLink* const link = BaseLink::Alloc();
	if (!link)
		return;

	if (bone_index >= 0)
	{
		if (MMDBoneManagerObject* const mgr = GetBoneManager())
		{
			if (BaseTag* const source_tag = mgr->FindBone(bone_index))
				link->SetLink(source_tag->GetObject());
			else
				link->SetLink(nullptr);
		}
		else
		{
			link->SetLink(nullptr);
		}
	}
	else
	{
		link->SetLink(nullptr);
	}

	is_syncing_inherit_source_ = true;
	node->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), GeData(link), DESCFLAGS_SET::NONE);
	is_syncing_inherit_source_ = false;
}

void MMDBoneTag::RequestAppendExecutionOrderRefresh(GeListNode* node)
{
	if (MMDBoneManagerObject* const mgr = GetBoneManager())
	{
		mgr->MarkAppendExecutionOrderDirty();
		mgr->EnsureAppendExecutionOrder();
	}
	else
	{
		RefreshExecutionPriority(node);
	}
}

void MMDBoneTag::InvalidateStandaloneIKChainCache()
{
	standalone_ik_chain_dirty_ = true;
	standalone_ik_chain_solver_ = nullptr;
}

Bool MMDBoneTag::ReplaceAnimationSlot(const Int32 slot_index, const maxon::BaseArray<BoneAnimationKeyframeData>& keyframes)
{
	iferr_scope_handler{
		return false;
	};

	BoneAnimationSlotData* const slot = EnsureAnimationSlot(slot_index);
	if (!slot)
		return false;

	slot->keyframes.Resize(0)iferr_return;
	for (const auto& keyframe : keyframes)
	{
		slot->keyframes.Append(keyframe)iferr_return;
	}

	std::sort(slot->keyframes.Begin(), slot->keyframes.End(), [](const BoneAnimationKeyframeData& lhs, const BoneAnimationKeyframeData& rhs)
	{
		return lhs.frame < rhs.frame;
	});

	if (slot_index == active_animation_slot_)
	{
		InvalidateAnimationUICache();
		RefreshAnimationMarkerTracks(Get());
		SyncSplineFromSelection(Get());
	}
	return true;
}

void MMDBoneTag::ClearAnimationSlot(const Int32 slot_index)
{
	if (BoneAnimationSlotData* const slot = GetAnimationSlot(slot_index))
	{
		iferr(slot->keyframes.Resize(0)) {}
		if (slot_index == active_animation_slot_ && Get())
		{
			InvalidateAnimationUICache();
			RefreshAnimationMarkerTracks(Get());
			InitAnimationSpline(Get());
		}
	}
}

void MMDBoneTag::ClearAllAnimationSlots()
{
	iferr(bone_animation_slots_.Resize(0)) {}
	active_animation_slot_ = -1;
	if (Get())
	{
		InvalidateAnimationUICache();
		RefreshAnimationMarkerTracks(Get());
		InitAnimationSpline(Get());
	}
}

Bool MMDBoneTag::CopyAnimationSlot(const Int32 slot_index, maxon::BaseArray<BoneAnimationKeyframeData>& keyframes) const
{
	const BoneAnimationSlotData* const slot = GetAnimationSlot(slot_index);
	if (!slot)
	{
		iferr(keyframes.Resize(0))
			return false;
		return true;
	}

	iferr(keyframes.CopyFrom(slot->keyframes))
		return false;
	return true;
}

void MMDBoneTag::SetActiveAnimationSlot(const Int32 slot_index)
{
	if (slot_index < 0)
	{
		active_animation_slot_ = -1;
		if (GeListNode* const node = Get())
		{
			InvalidateAnimationUICache();
			RefreshAnimationMarkerTracks(node);
			InitAnimationSpline(node);
		}
		return;
	}
	if (!EnsureAnimationSlotCount(slot_index + 1))
		return;
	active_animation_slot_ = slot_index;
	if (GeListNode* const node = Get())
	{
		InvalidateAnimationUICache();
		RefreshAnimationMarkerTracks(node);
		SyncSplineFromSelection(node);
	}
}

Int32 MMDBoneTag::GetMaxAnimationFrame(const Int32 slot_index) const
{
	const BoneAnimationSlotData* const slot = GetAnimationSlot(slot_index);
	if (!slot || slot->keyframes.IsEmpty())
		return 0;
	return slot->keyframes[slot->keyframes.GetCount() - 1].frame;
}

void MMDBoneTag::HandleBoneMorphButtonCommand(const DescID& desc_id)
{
	iferr_scope_handler{ return; };

	auto* button_ptr = bone_morph_button_id_map_.Find(desc_id);
	if (!button_ptr)
		return;

	const Int32 morph_index = button_ptr->GetValue();
	if (morph_index < 0 || morph_index >= bone_morph_data_arr_.GetCount())
		return;

	auto& morph_data = bone_morph_data_arr_[morph_index];
	auto* tag = static_cast<BaseTag*>(Get());
	DynamicDescription* ddesc = tag->GetDynamicDescriptionWritable();
	if (!ddesc)
		return;

	if (desc_id == morph_data.button_delete_id)
	{
		if (!QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph_data.name))
			return;

		ddesc->Remove(morph_data.button_delete_id);
		ddesc->Remove(morph_data.button_rename_id);
		ddesc->Remove(morph_data.button_grp_id);
		ddesc->Remove(morph_data.rotation_id);
		ddesc->Remove(morph_data.translation_id);
		ddesc->Remove(morph_data.strength_id);
		ddesc->Remove(morph_data.grp_id);

		bone_morph_button_id_map_.Erase(morph_data.button_delete_id)iferr_return;
		bone_morph_button_id_map_.Erase(morph_data.button_rename_id)iferr_return;
		for (auto& entry : bone_morph_button_id_map_)
		{
			if (entry.GetValue() > morph_index)
				entry.GetValue()--;
		}

		if (auto* mgr = GetBoneManager())
		{
			MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_MORPH_DELETE, morph_data.name, morph_data.strength_id, tag);
			reinterpret_cast<BaseObject*>(mgr->Get())->Message(g_mmd_bone_tag_id, &msg);
		}

		bone_morph_data_arr_.Erase(morph_index)iferr_return;

		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
		if (GeIsMainThread())
			EventAdd();
	}
	else if (desc_id == morph_data.button_rename_id)
	{
		String new_name;
		if (!RenameDialog(&new_name))
			return;
		if (new_name.IsEmpty())
			return;

		BaseContainer descbc = *ddesc->Find(morph_data.grp_id);
		descbc.SetString(DESC_NAME, new_name);
		ddesc->Set(morph_data.grp_id, descbc, nullptr);

		descbc = *ddesc->Find(morph_data.strength_id);
		descbc.SetString(DESC_NAME, new_name);
		ddesc->Set(morph_data.strength_id, descbc, nullptr);

		if (auto* mgr = GetBoneManager())
		{
			MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_MORPH_RENAME, new_name, morph_data.strength_id, tag, morph_data.name);
			reinterpret_cast<BaseObject*>(mgr->Get())->Message(g_mmd_bone_tag_id, &msg);
		}

		morph_data.name = std::move(new_name);

		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
		if (GeIsMainThread())
			EventAdd();
	}
}

Bool MMDBoneTag::SplineDataCallBack(const Int32 cid, const void* data)
{
	if (cid != SPLINE_CALLBACK_CORE_MESSAGE || data == nullptr)
		return true;

	SplineData* const spline_data = static_cast<const SplineDataCallbackCoreMessage*>(data)->pGUI->GetSplineData();
	if (!spline_data)
		return true;

	for (Int32 i = 0; i < spline_data->GetKnotCount(); ++i)
	{
		if (CustomSplineKnot* const knot = spline_data->GetKnot(i))
		{
			Vector global_left = knot->vPos + knot->vTangentLeft;
			global_left.ClampMax(Vector(kBoneAnimationSplineMax, kBoneAnimationSplineMax, 0.));
			global_left.ClampMin(Vector(0.));
			Vector global_right = knot->vPos + knot->vTangentRight;
			global_right.ClampMax(Vector(kBoneAnimationSplineMax, kBoneAnimationSplineMax, 0.));
			global_right.ClampMin(Vector(0.));
			knot->vTangentLeft = global_left - knot->vPos;
			knot->vTangentRight = global_right - knot->vPos;
		}
	}
	return true;
}

Bool MMDBoneTag::InitAnimationSpline(GeListNode* node)
{
	if (!node)
		node = Get();
	if (!node)
		return false;

	if (BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		InvalidateAnimationUICache();
		bc->SetData(PMX_BONE_ANIM_SPLINE, CreateDefaultAnimationSplineData());
		return true;
	}
	return false;
}

Bool MMDBoneTag::SyncSplineFromSelection(GeListNode* node)
{
	if (!node)
		node = Get();
	if (!node)
		return false;

	BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return false;

	GeData spline_data = CreateDefaultAnimationSplineData();
	SplineData* const spline = GetSplineDataWritable(spline_data);
	if (!spline)
		return false;

	if (const BoneAnimationSlotData* const slot = GetActiveAnimationSlotData(); slot && !slot->keyframes.IsEmpty())
	{
		const Int32 selected_frame = bc->GetInt32(PMX_BONE_ANIM_FRAME_ON);
		if (const BoneAnimationKeyframeData* const keyframe = FindAnimationKeyframe(*slot, selected_frame))
			WriteBezierToSpline(SelectBezierChannel(*keyframe, bc->GetInt32(PMX_BONE_ANIM_CURVE_TYPE)), spline);
	}
	bc->SetData(PMX_BONE_ANIM_SPLINE, spline_data);
	ui_animation_frame_cache_ = bc->GetInt32(PMX_BONE_ANIM_FRAME_ON);
	ui_animation_curve_type_cache_ = bc->GetInt32(PMX_BONE_ANIM_CURVE_TYPE);
	return true;
}

Bool MMDBoneTag::SyncSplineFromCurrentParametersIfNeeded(GeListNode* node)
{
	if (!node)
		node = Get();
	if (!node)
		return false;

	BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return false;

	const Int32 frame = bc->GetInt32(PMX_BONE_ANIM_FRAME_ON);
	const Int32 curve_type = bc->GetInt32(PMX_BONE_ANIM_CURVE_TYPE);
	if (frame == ui_animation_frame_cache_ && curve_type == ui_animation_curve_type_cache_)
		return true;

	return SyncSplineFromSelection(node);
}

Bool MMDBoneTag::StoreSplineToSelection(GeListNode* node)
{
	if (!node)
		node = Get();
	if (!node)
		return false;

	BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return false;

	BoneAnimationSlotData* const slot = GetActiveAnimationSlotData();
	if (!slot || slot->keyframes.IsEmpty())
		return true;

	const Int32 selected_frame = bc->GetInt32(PMX_BONE_ANIM_FRAME_ON);
	BoneAnimationKeyframeData* const keyframe = FindAnimationKeyframe(*slot, selected_frame);
	if (!keyframe)
		return true;

	GeData spline_data;
	if (!node->GetParameter(ConstDescID(DescLevel(PMX_BONE_ANIM_SPLINE)), spline_data, DESCFLAGS_GET::NONE))
		return false;

	const SplineData* const spline = GetSplineData(spline_data);
	if (!spline)
		return false;

	AssignBezierChannel(*keyframe, bc->GetInt32(PMX_BONE_ANIM_CURVE_TYPE), ReadBezierFromSpline(spline));
	return true;
}

Bool MMDBoneTag::NavigateAnimationKeyframe(GeListNode* node, BaseDocument* doc, const Bool forward)
{
	if (!node)
		node = Get();
	if (!node)
		return false;

	const BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	const BoneAnimationSlotData* const slot = GetActiveAnimationSlotData();
	if (!bc || !slot || slot->keyframes.IsEmpty())
		return false;

	const Int32 selected_frame = bc->GetInt32(PMX_BONE_ANIM_FRAME_ON);
	Int32 target_frame = selected_frame;

	if (forward)
	{
		for (const auto& keyframe : slot->keyframes)
		{
			if (keyframe.frame > selected_frame)
			{
				target_frame = keyframe.frame;
				break;
			}
		}
	}
	else
	{
		for (Int index = slot->keyframes.GetCount() - 1; index >= 0; --index)
		{
			if (slot->keyframes[index].frame < selected_frame)
			{
				target_frame = slot->keyframes[index].frame;
				break;
			}
		}
	}

	if (target_frame == selected_frame)
		return true;

	node->SetParameter(ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)), target_frame, DESCFLAGS_SET::NONE);
	if (doc)
		doc->SetTime(GetAnimationFrameTime(target_frame));
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
	return true;
}

void MMDBoneTag::RefreshAnimationMarkerTracks(GeListNode* node)
{
	if (!node)
		node = Get();
	BaseTag* const tag = static_cast<BaseTag*>(node);
	if (!tag)
		return;

	const BoneAnimationSlotData* const slot = GetActiveAnimationSlotData();
	CTrack* frame_track = tag->FindCTrack(ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)));
	if (!frame_track && slot && !slot->keyframes.IsEmpty())
	{
		frame_track = CTrack::Alloc(tag, ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)));
		if (frame_track)
			tag->InsertTrackSorted(frame_track);
	}

	if (!frame_track)
		return;

	if (CCurve* const frame_curve = frame_track->GetCurve())
	{
		for (Int32 index = frame_curve->GetKeyCount() - 1; index >= 0; --index)
		{
			if (!frame_curve->DelKey(index))
				break;
		}

		if (slot && !slot->keyframes.IsEmpty())
		{
			for (const auto& keyframe : slot->keyframes)
			{
				if (CKey* const key = frame_curve->AddKey(GetAnimationFrameTime(keyframe.frame)))
				{
					key->SetInterpolation(frame_curve, CINTERPOLATION::STEP);
					key->SetValue(frame_curve, static_cast<Float>(keyframe.frame));
					key->ChangeNBit(NBIT::CKEY_LOCK_T, NBITCONTROL::SET);
					key->ChangeNBit(NBIT::CKEY_LOCK_V, NBITCONTROL::SET);
				}
			}
		}
	}
}

Bool MMDBoneTag::AddAnimationKeyframeFromCurrentPose(GeListNode* node, BaseDocument* doc)
{
	iferr_scope_handler{
		return false;
	};

	if (!node)
		node = Get();
	if (!node)
		return false;

	if (!bone_object_)
		bone_object_ = static_cast<BaseTag*>(node)->GetObject();
	if (!bone_object_)
		return false;

	BoneAnimationSlotData* const slot = EnsureAnimationSlot(active_animation_slot_);
	if (!slot)
		return false;

	const Int32 frame = GetAnimationFrameFromDocument(doc);
	Int32 keyframe_index = FindAnimationKeyframeIndex(*slot, frame);
	if (keyframe_index == NOTOK)
	{
		auto& keyframe = slot->keyframes.Append()iferr_return;
		keyframe.frame = frame;
		keyframe_index = static_cast<Int32>(slot->keyframes.GetCount() - 1);
	}

	BoneAnimationKeyframeData& keyframe = slot->keyframes[keyframe_index];
	const Vector rel_pos = bone_object_->GetRelPos();
	const std::array<Float32, 4> rotation = EulerToQuaternionArray(bone_object_->GetRelRot());
	keyframe.translation = Vector32(
		maxon::SafeConvert<Float32>(rel_pos.x),
		maxon::SafeConvert<Float32>(rel_pos.y),
		maxon::SafeConvert<Float32>(rel_pos.z));
	keyframe.rotation_x = rotation[0];
	keyframe.rotation_y = rotation[1];
	keyframe.rotation_z = rotation[2];
	keyframe.rotation_w = rotation[3];

	std::sort(slot->keyframes.Begin(), slot->keyframes.End(), [](const BoneAnimationKeyframeData& lhs, const BoneAnimationKeyframeData& rhs)
	{
		return lhs.frame < rhs.frame;
	});

	node->SetParameter(ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)), frame, DESCFLAGS_SET::NONE);
	StoreSplineToSelection(node);
	InvalidateAnimationUICache();
	RefreshAnimationMarkerTracks(node);
	SyncSplineFromSelection(node);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
	return true;
}

Bool MMDBoneTag::DeleteAnimationKeyframeAtCurrentFrame(GeListNode* node, BaseDocument* doc)
{
	iferr_scope_handler{
		return false;
	};

	if (!node)
		node = Get();
	if (!node)
		return false;

	BoneAnimationSlotData* const slot = GetActiveAnimationSlotData();
	if (!slot || slot->keyframes.IsEmpty())
		return false;

	const Int32 frame = GetAnimationFrameFromDocument(doc);
	const Int32 keyframe_index = FindAnimationKeyframeIndex(*slot, frame);
	if (keyframe_index == NOTOK)
		return false;

	slot->keyframes.Erase(keyframe_index)iferr_return;
	InvalidateAnimationUICache();
	RefreshAnimationMarkerTracks(node);
	if (!slot->keyframes.IsEmpty())
	{
		node->SetParameter(ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)), slot->keyframes[std::min<Int>(keyframe_index, slot->keyframes.GetCount() - 1)].frame, DESCFLAGS_SET::NONE);
		SyncSplineFromSelection(node);
	}
	else
	{
		node->SetParameter(ConstDescID(DescLevel(PMX_BONE_ANIM_FRAME_ON)), frame, DESCFLAGS_SET::NONE);
		InitAnimationSpline(node);
	}

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
	return true;
}

Bool MMDBoneTag::RefreshColor(GeListNode* node, BaseObject* op)
{
	if (!op)
	{
		op = bone_object_;
	}
	if (!node)
	{
		node = Get();
	}
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}
	// 存储方式由 CMT_STATIC_BONE_REFRESH_COLORS 控制（R20: static const，R21+: static constexpr）
	CMT_STATIC_BONE_REFRESH_COLORS Vector colors[6]
	{
		Vector(0.56640625, 0.78125, 1),       /* Is_rotatable == 1 */
		Vector(0.703125, 1, 0.546875),        /* Is_translatable == 1 */
		Vector(0.984375, 0.375, 0),           /* Is_IK == 1 */
		Vector(0.4, 0.4, 0.4),                /* Is_visible == 0 */
		Vector(0.7265625, 0.328125, 1),       /* Fixed_axis == 1 */
		Vector(0.682353, 0.64453125, 1),      /* Inherit_rotation == 1||Inherit_translation == 1 */
	};
	Int32 color = 0;

	if (bc->GetBool(PMX_BONE_ROTATABLE) == 1)
		color = 0;
	if (bc->GetBool(PMX_BONE_TRANSLATABLE) == 1)
		color = 1;
	if (bc->GetBool(PMX_BONE_IS_IK) == 1)
		color = 2;
	if (bc->GetBool(PMX_BONE_VISIBLE) == 0)
		color = 3;
	if (bc->GetBool(PMX_BONE_IS_FIXED_AXIS) == 1)
		color = 4;
	if (bc->GetBool(PMX_BONE_INHERIT_ROTATION) == 1 || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
		color = 5;
	if (node != nullptr)
	{
#if CMT_SDK_HAS_ICON_COLORIZE
		node->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLORIZE_MODE)), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		node->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLOR)), colors[color], DESCFLAGS_SET::NONE);
#endif
	}
	if (op != nullptr)
	{
#if CMT_SDK_HAS_ICON_COLORIZE
		op->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLORIZE_MODE)), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLOR)), colors[color], DESCFLAGS_SET::NONE);
#endif
		auto objColor = MakeObjectColorProperties(colors[color], ID_BASEOBJECT_USECOLOR_ALWAYS, true);
		op->SetColorProperties(&objColor);
	}
	return true;
}

MMDBoneManagerObject* MMDBoneTag::GetBoneManager()
{
	if (!bone_object_)
		if (auto* tag = static_cast<BaseTag*>(Get()))
			bone_object_ = tag->GetObject();

	BaseObject* manager_object = bone_object_
		? ResolveBoneManagerObjectFromHierarchy(bone_object_)
		: io_util::ResolveObjectLink(bone_manager_link_);

	if (manager_object)
	{
		bone_manager_data_ = manager_object->GetNodeData<MMDBoneManagerObject>();
		if (bone_manager_data_)
		{
			bone_manager_link_->SetLink(manager_object);
			hierarchy_manager_cache_ = manager_object;
		}
	}
	else
	{
		bone_manager_data_ = nullptr;
		hierarchy_manager_cache_ = nullptr;
		if (bone_manager_link_)
			bone_manager_link_->SetLink(nullptr);
	}
	return bone_manager_data_;
}

MMDModelManagerObject* MMDBoneTag::GetModelManager()
{
	if (MMDBoneManagerObject* const bone_manager = GetBoneManager())
		return bone_manager->GetModelManagerData();
	return nullptr;
}

bool MMDBoneTag::UpdateHierarchyTopologyCache(BaseObject* bone_object, const Bool notify_managers)
{
	if (!bone_object)
		return false;

	bone_object_ = bone_object;

	BaseObject* current_parent = bone_object->GetUp();
	BaseObject* current_pred = bone_object->GetPred();
	BaseObject* current_manager_object = ResolveBoneManagerObjectFromHierarchy(bone_object);
	BaseObject* previous_manager_object = hierarchy_manager_cache_;

	const Bool changed = current_parent != hierarchy_parent_cache_
		|| current_pred != hierarchy_pred_cache_
		|| current_manager_object != hierarchy_manager_cache_;

	hierarchy_parent_cache_ = current_parent;
	hierarchy_pred_cache_ = current_pred;
	hierarchy_manager_cache_ = current_manager_object;

	if (current_manager_object)
	{
		bone_manager_data_ = current_manager_object->GetNodeData<MMDBoneManagerObject>();
		if (bone_manager_link_)
			bone_manager_link_->SetLink(current_manager_object);
	}
	else
	{
		bone_manager_data_ = nullptr;
		if (bone_manager_link_)
			bone_manager_link_->SetLink(nullptr);
	}

	if (changed && notify_managers)
		NotifyHierarchyDirty(previous_manager_object, current_manager_object);

	return changed;
}

void MMDBoneTag::NotifyHierarchyDirty(BaseObject* previous_manager_object, BaseObject* current_manager_object) const
{
	auto send_dirty = [&](BaseObject* manager_object)
	{
		if (!manager_object || !manager_object->IsInstanceOf(g_mmd_bone_manager_object_id))
			return;

		MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_HIERARCHY_DIRTY);
		msg.bone_tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get());
		manager_object->Message(g_mmd_bone_tag_id, &msg);
	};

	if (previous_manager_object && previous_manager_object != current_manager_object)
		send_dirty(previous_manager_object);

	send_dirty(current_manager_object);
}

NodeData* MMDBoneTag::Alloc()
{
	return NewObj(MMDBoneTag).GetValue();
}

SDK2024_CopyTo(MMDBoneTag)
{
	iferr_scope_handler{
		return false;
	};

	auto* const dest_tag = reinterpret_cast<MMDBoneTag*>(dest);
	if (!dest_tag)
		return false;

	if (bone_manager_link_)
		bone_manager_link_->CopyTo(dest_tag->bone_manager_link_, flags, trn);
	if (bone_lock_protection_link_)
		bone_lock_protection_link_->CopyTo(dest_tag->bone_lock_protection_link_, flags, trn);

	dest_tag->bone_manager_data_ = nullptr;
	dest_tag->bone_object_ = nullptr;
	dest_tag->hierarchy_parent_cache_ = nullptr;
	dest_tag->hierarchy_pred_cache_ = nullptr;
	dest_tag->hierarchy_manager_cache_ = nullptr;
	dest_tag->bone_mode_ = bone_mode_;
	dest_tag->is_IK = is_IK;
	dest_tag->is_syncing_inherit_source_ = false;
	dest_tag->bone_morph_name_index_ = bone_morph_name_index_;
	dest_tag->prev_position_ = prev_position_;
	dest_tag->prev_rotation_ = prev_rotation_;
	dest_tag->active_animation_slot_ = active_animation_slot_;
	dest_tag->evaluated_animation_translation_ = evaluated_animation_translation_;
	dest_tag->evaluated_animation_rotation_ = evaluated_animation_rotation_;
	dest_tag->evaluated_append_animation_translation_ = evaluated_append_animation_translation_;
	dest_tag->evaluated_append_animation_rotation_ = evaluated_append_animation_rotation_;
	dest_tag->evaluated_ik_rotation_ = evaluated_ik_rotation_;
	dest_tag->runtime_playback_override_translation_ = Vector();
	dest_tag->runtime_playback_override_rotation_ = { 0.F, 0.F, 0.F, 1.F };
	dest_tag->has_runtime_playback_override_ = false;
	dest_tag->runtime_playback_override_time_ = BaseTime(-1.);
	dest_tag->last_prephysics_time_ = BaseTime(-1.);
	dest_tag->last_ik_solve_time_ = BaseTime(-1.);
	dest_tag->last_postphysics_ik_solve_time_ = BaseTime(-1.);
	dest_tag->standalone_ik_chain_dirty_ = true;
	dest_tag->standalone_ik_chain_solver_ = nullptr;
	dest_tag->skip_prephysics_scene_write_ = false;
	dest_tag->ik_overridden_this_frame_ = false;
	dest_tag->append_recursion_depth_ = append_recursion_depth_;

	iferr(dest_tag->bone_animation_slots_.CopyFrom(bone_animation_slots_))
		return false;

	dest_tag->bone_morph_data_arr_.Reset();
	dest_tag->bone_morph_button_id_map_.Reset();
	for (const auto& morph : bone_morph_data_arr_)
	{
		auto& copied = dest_tag->bone_morph_data_arr_.Append()iferr_return;
		copied.grp_id = morph.grp_id;
		copied.strength_id = morph.strength_id;
		copied.translation_id = morph.translation_id;
		copied.rotation_id = morph.rotation_id;
		copied.button_grp_id = morph.button_grp_id;
		copied.button_delete_id = morph.button_delete_id;
		copied.button_rename_id = morph.button_rename_id;
		copied.name = morph.name;
		const Int32 index = static_cast<Int32>(dest_tag->bone_morph_data_arr_.GetCount() - 1);
		dest_tag->bone_morph_button_id_map_.Insert(copied.button_delete_id, index)iferr_return;
		dest_tag->bone_morph_button_id_map_.Insert(copied.button_rename_id, index)iferr_return;
	}

	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

SDK2024_Init(MMDBoneTag)
{
	if (!node)
		return false;

	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return false;

	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_T_MMD_BONE));
	bc->SetString(PMX_BONE_NAME_LOCAL, "bone"_s);
	bc->SetInt32(PMX_BONE_NAME_IS_LOCAL, 2);
	bc->SetString(PMX_BONE_NAME_UNIVERSAL, "bone"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_INDEX, "-1"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_NAME, ""_s);
	bc->SetInt32(PMX_BONE_ROTATABLE, 1);
	bc->SetInt32(PMX_BONE_VISIBLE, 1);
	bc->SetInt32(PMX_BONE_ENABLED, 1);
	bc->SetInt32(PMX_BONE_TAIL_INDEX, 0);
	bc->SetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 0.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));
	bc->SetBool(PMX_BONE_INHERIT_LOCAL, false);
	bc->SetBool(PMX_BONE_OUTER_PARENT, false);
	bc->SetInt32(PMX_BONE_OUTER_PARENT_KEY, 0);
	bc->SetInt32(PMX_BONE_ANIM_FRAME_ON, 0);
	bc->SetInt32(PMX_BONE_ANIM_CURVE_TYPE, PMX_BONE_ANIM_CURVE_X);

	iferr(bone_animation_slots_.Resize(0))
		return false;
	active_animation_slot_ = -1;
	append_recursion_depth_ = 0;
	ResetEvaluatedAnimationState();
	RefreshExecutionPriority(node);
	if (!InitAnimationSpline(node))
		return false;

	return SDK2024_SuperInit;
}

void MMDBoneTag::HandleDescriptionUpdate(GeListNode* node, BaseContainer* const bc, const Int32 id)
{
	switch (id)
	{
	case PMX_BONE_ROTATABLE:
	{
		if (!bone_object_)
			return;
		if (!FindOrCreateBoneLockTag())
			break;
		SetRotationLock(!bc->GetBool(id));
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (!bone_object_)
			return;
		if (!FindOrCreateBoneLockTag())
			break;
		SetPositionLock(!bc->GetBool(id));
		RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (!bone_object_)
			return;
		if (!bc->GetBool(id))
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (!bone_object_)
			return;
		switch (bc->GetInt32(id))
		{
		case PMX_BONE_TAIL_IS_INDEX:
			{
				if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
				}
				break;
			}
		case PMX_BONE_TAIL_POSITION:
			{
				if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
				}
				break;
			}
		default:
			break;
		}
		break;
	}
	case PMX_BONE_TAIL_INDEX:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (bc->GetInt32(id) == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (bc->GetVector(id).IsZero())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(id))
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_IS_IK:
	case PMX_BONE_IS_FIXED_AXIS:
	case PMX_BONE_INHERIT_ROTATION:
	case PMX_BONE_INHERIT_TRANSLATION:
		{
			RefreshColor(node);
			RequestAppendExecutionOrderRefresh(node);
			break;
		}
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	{
		SyncInheritSourceLinkFromIndex(node, bc->GetInt32(id));
		RequestAppendExecutionOrderRefresh(node);
		break;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		GeData link_data;
		if (node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), link_data, DESCFLAGS_GET::NONE))
			SyncInheritSourceIndexFromLink(node, link_data);
		RequestAppendExecutionOrderRefresh(node);
		break;
	}
	case PMX_BONE_LAYER:
	case PMX_BONE_PHYSICS_AFTER_DEFORM:
		{
			RequestAppendExecutionOrderRefresh(node);
			break;
		}
	default:
		break;
	}
}

void MMDBoneTag::BuildStandaloneIKChains()
{
	if (!is_IK || !GetBoneManager())
		return;

	MMDModelManagerObject* const model_manager = GetModelManager();
	if (!model_manager)
		return;

	libmmd::MMDIkSolver* const ik_solver = model_manager->GetStandaloneIKSolver(GetBoneIndex());
	if (!ik_solver)
		return;

	if (standalone_ik_chain_solver_ != ik_solver)
		standalone_ik_chain_dirty_ = true;

	auto* tag = static_cast<BaseTag*>(Get());
	if (!tag)
		return;

	if (!standalone_ik_chain_dirty_)
		return;

	maxon::BaseArray<StandaloneIKChainEntry> entries;
	if (!CollectStandaloneIKChainEntries(tag, entries))
		return;

	BaseDocument* const tag_doc = tag->GetDocument();

	if (entries.IsEmpty())
	{
		ik_solver->ClearIKChains();
		ik_solver->BuildChainPath();
		standalone_ik_chain_dirty_ = false;
		standalone_ik_chain_solver_ = ik_solver;
		return;
	}

	ik_solver->ClearIKChains();
	std::vector<StandaloneIKChainEntry> ordered_entries;
	ordered_entries.reserve(entries.GetCount());
	for (const auto& entry : entries)
		ordered_entries.push_back(entry);

	for (const auto& entry : ordered_entries)
	{
		// Prefer the stable BaseLink reference over the PMX-order bone index.
		Int32 resolved_index = -1;
		BaseTag* chain_tag = nullptr;
		if (entry.linked_object)
		{
			if (BaseTag* const tag_via_link = entry.linked_object->GetTag(g_mmd_bone_tag_id))
			{
				const Int32 idx = GetBoneManager()->FindBoneIndex(tag_via_link);
				if (idx >= 0 && model_manager->GetBoneAdapter(idx))
				{
					resolved_index = idx;
					chain_tag = tag_via_link;
				}
			}
		}
		if (!chain_tag)
		{
			// Legacy fallback for scenes without the link resolvable (e.g. older files).
			if (BaseTag* const legacy_tag = GetBoneManager()->FindBone(entry.bone_index))
			{
				if (model_manager->GetBoneAdapter(entry.bone_index))
				{
					resolved_index = entry.bone_index;
					chain_tag = legacy_tag;
				}
			}
		}

		if (chain_tag && chain_tag->GetNodeData<MMDBoneTag>())
		{
			C4DIKChainNodeAdapter* const chain_adapter = model_manager->GetBoneAdapter(resolved_index);
			if (!chain_adapter)
				continue;

			if (entry.enable_limit)
			{
				const Eigen::Vector3f lmin(static_cast<float>(entry.limit_min.x), static_cast<float>(entry.limit_min.y), static_cast<float>(entry.limit_min.z));
				const Eigen::Vector3f lmax(static_cast<float>(entry.limit_max.x), static_cast<float>(entry.limit_max.y), static_cast<float>(entry.limit_max.z));
				ik_solver->AddIKChain(chain_adapter, true, lmin, lmax);
			}
			else
			{
				ik_solver->AddIKChain(chain_adapter);
			}
		}
	}
	ik_solver->BuildChainPath();
	standalone_ik_chain_dirty_ = false;
	standalone_ik_chain_solver_ = ik_solver;
}

void MMDBoneTag::MarkPrephysicsIKChainUpdated(const BaseDocument* doc)
{
	maxon::BaseArray<Int32> affected_indices;
	CollectIKAffectedBoneIndices(affected_indices);

	MMDBoneManagerObject* const bone_manager = GetBoneManager();
	if (!bone_manager)
		return;

	for (const Int32 bone_index : affected_indices)
	{
		BaseTag* const affected_tag = bone_manager->FindBone(bone_index);
		if (!affected_tag)
			continue;
		if (auto* const affected_node = affected_tag->GetNodeData<MMDBoneTag>())
			affected_node->MarkPrephysicsSceneWriteSkipped(doc);
	}
}

void MMDBoneTag::CollectIKAffectedBoneIndices(maxon::BaseArray<Int32>& affected_indices) const
{
	affected_indices.Reset();
	if (!is_IK)
		return;

	MMDBoneManagerObject* const bone_manager = const_cast<MMDBoneTag*>(this)->GetBoneManager();
	if (!bone_manager)
		return;

	const auto append_unique_index = [&affected_indices](const Int32 bone_index)
	{
		if (bone_index < 0)
			return;

		for (const Int32 existing_index : affected_indices)
		{
			if (existing_index == bone_index)
				return;
		}
		affected_indices.Append(bone_index)iferr_ignore("append ik affected bone"_s);
	};

	append_unique_index(GetBoneIndex());

	BaseTag* const tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get());
	if (!tag)
		return;

	BaseDocument* const tag_doc = tag->GetDocument();

	// The IK effector bone is not part of the editable IK-chain entry list, but
	// it still needs to be treated as affected by the solve. Otherwise
	// post-physics re-solve detection can miss physics-driven effectors, and the
	// effector itself may be overwritten later in the same evaluation pass.
	Int32 effector_index = NOTOK;
	if (GeData target_link_data; tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_IK_TARGET_BONE_LINK)), target_link_data, DESCFLAGS_GET::NONE))
	{
		if (BaseObject* const target_object = ResolveBoneObjectFromLinkData(target_link_data, tag_doc))
		{
			if (BaseTag* const target_tag = target_object->GetTag(g_mmd_bone_tag_id))
				effector_index = bone_manager->FindBoneIndex(target_tag);
		}
	}
	if (effector_index == NOTOK)
	{
		const Int32 legacy_effector_index = tag->GetDataInstanceRef().GetInt32(PMX_BONE_IK_TARGET_BONE_INDEX);
		if (bone_manager->FindBone(legacy_effector_index) != nullptr)
			effector_index = legacy_effector_index;
	}
	append_unique_index(effector_index);

	maxon::BaseArray<StandaloneIKChainEntry> entries;
	if (!CollectStandaloneIKChainEntries(tag, entries))
		return;

	for (const auto& entry : entries)
	{
		Int32 resolved_index = NOTOK;
		if (entry.linked_object)
		{
			if (BaseTag* const linked_tag = entry.linked_object->GetTag(g_mmd_bone_tag_id))
				resolved_index = bone_manager->FindBoneIndex(linked_tag);
		}
		if (resolved_index == NOTOK && entry.bone_index >= 0)
		{
			if (bone_manager->FindBone(entry.bone_index) != nullptr)
				resolved_index = entry.bone_index;
		}

		append_unique_index(resolved_index);
	}
}

void MMDBoneTag::CacheIKSolveRuntimeOverrides(const BaseDocument* doc)
{
	if (!doc)
		return;

	MMDModelManagerObject* const model_manager = GetModelManager();
	MMDBoneManagerObject* const bone_manager = GetBoneManager();
	if (!model_manager || !bone_manager)
		return;

	maxon::BaseArray<Int32> affected_indices;
	CollectIKAffectedBoneIndices(affected_indices);
	for (const Int32 bone_index : affected_indices)
	{
		if (bone_index < 0)
			continue;

		C4DIKChainNodeAdapter* const adapter = model_manager->GetBoneAdapter(bone_index);
		if (!adapter)
			continue;

		Vector translation;
		std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
		adapter->GetCurrentRelativeState(translation, rotation);
		bone_manager->SetPhysicsOverride(bone_index, doc, translation, rotation);
	}
}

Bool MMDBoneTag::RunIKSolveAnimMode(BaseObject* op, const Bool mark_prephysics_chain, const Bool allow_same_frame_resolve)
{
	if (!op || bone_mode_ != BONE_MODE_ANIM || !is_IK)
		return false;

	BaseDocument* const doc = op->GetDocument();
	const Int32 current_frame = GetAnimationFrameFromDocument(doc);
	const BaseTime current_time = GetDocumentTimeOrInvalid(doc);
	if (!allow_same_frame_resolve && last_ik_solve_time_ == current_time)
		return false;

	MMDModelManagerObject* const model_manager = GetModelManager();
	if (!model_manager || !model_manager->EnsureStandaloneRuntimeManagers())
		return false;

	libmmd::MMDIkSolver* const ik_solver = model_manager->GetStandaloneIKSolver(GetBoneIndex());
	if (!ik_solver || !ik_solver->Enabled() || !ik_solver->GetIKNode() || !ik_solver->GetTargetNode())
		return false;

	model_manager->SyncStandaloneBoneAdaptersFromScene(true);
	BuildStandaloneIKChains();
	ik_solver->Solve();
	last_ik_solve_time_ = current_time;
	model_manager->ApplyStandaloneBoneAdaptersToScene();
	CacheIKSolveRuntimeOverrides(doc);
	if (mark_prephysics_chain)
		MarkPrephysicsIKChainUpdated(doc);
	return true;
}

void MMDBoneTag::HandleBoneModeChange(const Int32 bone_mode)
{
	const Int32 normalized_mode = NormalizeBoneMode(bone_mode);
	if (bone_mode_ == normalized_mode)
		return;

	if (!bone_object_)
		if (BaseTag* tag = static_cast<BaseTag*>(Get()); tag)
			bone_object_ = tag->GetObject();

	if (normalized_mode == BONE_MODE_EDIT)
	{
		if (bone_object_)
			bone_object_->ChangeNBit(NBIT::NO_DD, NBITCONTROL::CLEAR);
		if (FindOrCreateBoneLockTag())
		{
			SetRotationLock(false);
			SetPositionLock(false);
		}
	}
	else
	{
		if (bone_mode_ == BONE_MODE_EDIT && is_IK)
			BuildStandaloneIKChains();

		if (bone_object_)
			bone_object_->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
		if (FindOrCreateBoneLockTag())
		{
			if (const BaseTag* tag = static_cast<BaseTag*>(Get()))
				if (const BaseContainer* bc = tag->GetDataInstance())
				{
					SetRotationLock(!bc->GetBool(PMX_BONE_ROTATABLE));
					SetPositionLock(!bc->GetBool(PMX_BONE_TRANSLATABLE));
				}
		}
	}

	bone_mode_ = normalized_mode;
	if (bone_mode_ == BONE_MODE_ANIM)
		SyncSplineFromSelection(Get());
}

void MMDBoneTag::SetBoneDisplay(const BaseContainer* const data_instance_bc, const MMDBoneManagerObjectMsg* msg) const
{
	switch (msg->display_type)
	{
	case BONE_DISPLAY_TYPE_MOVABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_TRANSLATABLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ROTATABLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_VISIBLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_VISIBLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ENABLED:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ENABLED))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_IK:
		{
			if (data_instance_bc->GetBool(PMX_BONE_IS_IK))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	default:
		bone_object_->SetEditorMode(MODE_UNDEF);
		bone_object_->SetRenderMode(MODE_UNDEF);
		break;
	}
}

Bool MMDBoneTag::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return true;
	};
	const auto bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return true;
	}
	if (!bone_object_)
		bone_object_ = static_cast<BaseTag*>(node)->GetObject();
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		const auto dc = static_cast<DescriptionCommand*>(data);
		const Int32 command_id = dc ? dc->_descId[0].id : NOTOK;
		BaseDocument* const doc = reinterpret_cast<BaseList2D*>(node)->GetDocument();
		if (command_id == PMX_BONE_ANIM_PREV_BTN)
		{
			NavigateAnimationKeyframe(node, doc, false);
		}
		else if (command_id == PMX_BONE_ANIM_NEXT_BTN)
		{
			NavigateAnimationKeyframe(node, doc, true);
		}
		else if (command_id == PMX_BONE_ANIM_ADD_BTN)
		{
			AddAnimationKeyframeFromCurrentPose(node, doc);
		}
		else if (command_id == PMX_BONE_ANIM_DEL_BTN)
		{
			DeleteAnimationKeyframeAtCurrentFrame(node, doc);
		}
		else if (command_id == PMX_BONE_MORPH_ADD_BUTTON)
		{
			GeData ge_data;
			node->GetParameter(ConstDescID(DescLevel(PMX_BONE_MORPH_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
			AddBoneMorph(ge_data.GetString());
		}
		else
		{
			HandleBoneMorphButtonCommand(dc->_descId);
		}
		break;
	}
	case MSG_DESCRIPTION_CHECKUPDATE:
		HandleDescriptionUpdate(node, bc, static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id);
		break;
	case MSG_DOCUMENTINFO:
#ifdef MSG_DOCUMENTINFO_TYPE_OBJECT_REMOVE
		if (const auto* doc_info = static_cast<DocumentInfoData*>(data);
			doc_info && doc_info->type == MSG_DOCUMENTINFO_TYPE_OBJECT_REMOVE && doc_info->bl == bone_object_)
		{
			NotifyHierarchyDirty(hierarchy_manager_cache_, nullptr);
			hierarchy_parent_cache_ = nullptr;
			hierarchy_pred_cache_ = nullptr;
			hierarchy_manager_cache_ = nullptr;
			bone_manager_data_ = nullptr;
			if (bone_manager_link_)
				bone_manager_link_->SetLink(nullptr);
		}
#endif
		break;
	case MSG_MENUPREPARE:
		if (const auto doc = static_cast<BaseDocument*>(data); doc)
		{
			if (BaseObject* op = doc->GetActiveObject(); op)
			{
				const String name = op->GetName();
				node->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), name, DESCFLAGS_SET::NONE);
				RefreshColor(node, op);
				SyncSplineFromSelection(node);
			}
		}
		break;
	case MSG_ANIMATE:
		SyncSplineFromCurrentParametersIfNeeded(node);
		break;
	case  g_mmd_bone_manager_object_id:
		if (const auto* msg = static_cast<MMDBoneManagerObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE:
				SetBoneDisplay(bc, msg);
				break;
			case MMDBoneManagerObjectMsgType::BONE_HIERARCHY_UPDATE:
				UpdateHierarchyTopologyCache(bone_object_ ? bone_object_ : static_cast<BaseTag*>(node)->GetObject(), false);
				break;
			case MMDBoneManagerObjectMsgType::BONE_MODE_CHANGE:
				HandleBoneModeChange(msg->bone_mode);
				break;
			case MMDBoneManagerObjectMsgType::DEFAULT:
			case MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE:
				break;
			}
		}
		break;
	default: ;
	}

	return SUPER::Message(node, type, data);
}

Bool MMDBoneTag::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return false;
	}

	const auto get_ik_solver = [this]() -> libmmd::MMDIkSolver*
	{
		if (MMDModelManagerObject* const model_manager = GetModelManager())
			return model_manager->GetStandaloneIKSolver(GetBoneIndex());
		return nullptr;
	};
	const auto invalidate_runtime = [this]()
	{
		if (MMDModelManagerObject* const model_manager = GetModelManager())
			model_manager->InvalidateStandaloneRuntime();
	};
	const auto invalidate_ik_chain_cache = [this]()
	{
		InvalidateStandaloneIKChainCache();
	};

	switch (id[0].id)
	{
	case PMX_BONE_PHYSICS_AFTER_DEFORM:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		RequestAppendExecutionOrderRefresh(node);
		return result;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		SyncInheritSourceLinkFromIndex(node, t_data.GetInt32());
		RequestAppendExecutionOrderRefresh(node);
		return result;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		SyncInheritSourceIndexFromLink(node, t_data);
		RequestAppendExecutionOrderRefresh(node);
		return result;
	}
	case PMX_BONE_ANIM_FRAME_ON:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		SyncSplineFromSelection(node);
		return result;
	}
	case PMX_BONE_ANIM_CURVE_TYPE:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		SyncSplineFromSelection(node);
		return result;
	}
	case PMX_BONE_ANIM_SPLINE:
	{
		GeData spline_data = t_data;
		if (SplineData* const spline = GetSplineDataWritable(spline_data))
			spline->SetUserCallback(MMDBoneTag::SplineDataCallBack, nullptr);
		const Bool result = SUPER::SetDParameter(node, id, spline_data, flags);
		StoreSplineToSelection(node);
		return result;
	}
	case PMX_BONE_IK_GRP:
		if (id.GetDepth() >= 2)
		{
			switch (id[1].id)
			{
			case PMX_BONE_IK_ITERATION:
				if (auto* const ik_solver = get_ik_solver())
					ik_solver->SetIterateCount(static_cast<uint32_t>(t_data.GetInt32()));
				return SUPER::SetDParameter(node, id, t_data, flags);
			case PMX_BONE_IK_UNIT_ANGLE:
				if (auto* const ik_solver = get_ik_solver())
					ik_solver->SetLimitAngle(static_cast<float>(t_data.GetFloat()));
				return SUPER::SetDParameter(node, id, t_data, flags);
			case PMX_BONE_IK_TARGET_BONE_INDEX:
				invalidate_ik_chain_cache();
				invalidate_runtime();
				return SUPER::SetDParameter(node, id, t_data, flags);
			default:
				invalidate_ik_chain_cache();
				break;
			}
		}
		else
		{
			invalidate_ik_chain_cache();
		}
		break;
	case PMX_BONE_ROTATABLE:
	{
		if (!bone_object_)
			break;
		if (!FindOrCreateBoneLockTag())
			break;
		SetRotationLock(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (!bone_object_)
			break;
		if (!FindOrCreateBoneLockTag())
			break;
		SetPositionLock(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (!bone_object_)
			break;
		if (!t_data.GetBool())
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (!bone_object_)
			break;
		switch (t_data.GetInt32())
		{
		case PMX_BONE_TAIL_IS_INDEX:
		{
			if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		case PMX_BONE_TAIL_POSITION:
		{
			if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case PMX_BONE_TAIL_INDEX:
	{
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (t_data.GetInt32() == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (t_data.GetVector().IsZero())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (!bone_object_)
			break;
		if (t_data.GetInt32())
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
case PMX_BONE_LAYER:
	{
		const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
		RequestAppendExecutionOrderRefresh(node);
		return result;
	}
	case PMX_BONE_IK_ITERATION:
	{
		if (auto* const ik_solver = get_ik_solver())
			ik_solver->SetIterateCount(static_cast<uint32_t>(t_data.GetInt32()));
		break;
	}
	case PMX_BONE_IK_UNIT_ANGLE:
	{
		if (auto* const ik_solver = get_ik_solver())
			ik_solver->SetLimitAngle(static_cast<float>(t_data.GetFloat()));
		break;
	}
	case PMX_BONE_IK_TARGET_BONE_INDEX:
	{
		invalidate_ik_chain_cache();
		invalidate_runtime();
		break;
	}
	case PMX_BONE_IK_TARGET_BONE_LINK:
	{
		invalidate_ik_chain_cache();
		invalidate_runtime();
		break;
	}
	case PMX_BONE_IS_IK:
	{
		is_IK = t_data.GetBool();
		if (auto* const ik_solver = get_ik_solver())
			ik_solver->Enable(is_IK);
		invalidate_ik_chain_cache();
		invalidate_runtime();
		const auto state = reinterpret_cast<BaseList2D*>(Get())->GetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), true);
		if (is_IK)
			reinterpret_cast<BaseList2D*>(Get())->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), ~DESCIDSTATE::HIDDEN & state);
		else
			reinterpret_cast<BaseList2D*>(Get())->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), DESCIDSTATE::HIDDEN | state);
		[[fallthrough]];
	}
	case PMX_BONE_IS_FIXED_AXIS: [[fallthrough]];
	case PMX_BONE_INHERIT_ROTATION: [[fallthrough]];
	case PMX_BONE_INHERIT_TRANSLATION:
	{
		RefreshColor(node);
		RequestAppendExecutionOrderRefresh(node);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

SDK2024_GetDEnabling(MMDBoneTag)
{
	switch (id[0].id)
	{
	case PMX_BONE_ANIM_GRP:
	case PMX_BONE_ANIM_FRAME_ON:
	case PMX_BONE_ANIM_PREV_BTN:
	case PMX_BONE_ANIM_NEXT_BTN:
	case PMX_BONE_ANIM_ADD_BTN:
	case PMX_BONE_ANIM_DEL_BTN:
	case PMX_BONE_ANIM_CURVE_TYPE:
	case PMX_BONE_ANIM_SPLINE:
		return bone_mode_ == BONE_MODE_ANIM;
	default:
		break;
	}

	if (bone_mode_ != BONE_MODE_EDIT)
		return false;

	GeData ge_data;
	switch (id[0].id)
	{
	case PMX_BONE_TAIL_INDEX:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEXED_TAIL_POSITION)), ge_data, DESCFLAGS_GET::NONE);
		if (const auto indexed_tail_position = ge_data.GetInt32();
			indexed_tail_position == PMX_BONE_TAIL_IS_POSITION)
		{
			return false;
		}
		return true;
	case PMX_BONE_TAIL_POSITION:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEXED_TAIL_POSITION)), ge_data, DESCFLAGS_GET::NONE);
		if (const auto indexed_tail_position = ge_data.GetInt32();
			indexed_tail_position == PMX_BONE_TAIL_IS_INDEX)
		{
			return false;
		}
		return true;
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	case PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE:
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_ROTATION)), ge_data, DESCFLAGS_GET::NONE);
		const auto inherit_rotation = ge_data.GetBool();
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_TRANSLATION)), ge_data, DESCFLAGS_GET::NONE);
		const auto inherit_translation = ge_data.GetBool();
		if (inherit_rotation || inherit_translation)
		{
			return true;
		}
		return false;
	}
	case PMX_BONE_FIXED_AXIS:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_IS_FIXED_AXIS)), ge_data, DESCFLAGS_GET::NONE);
		if (const Bool fixed_axis = ge_data.GetBool(); !fixed_axis)
		{
			return false;
		}
		return true;
	case PMX_BONE_LOCAL_X:
	case PMX_BONE_LOCAL_Z:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_IS_COORDINATE)), ge_data, DESCFLAGS_GET::NONE);
		if (const Bool local_coordinate = ge_data.GetBool(); !local_coordinate)
		{
			return false;
		}
		return true;
	default:;
	}
	return true;
}

Bool MMDBoneTag::ApplyActiveAnimation(BaseObject* op, BaseDocument* doc, const Bool apply_to_scene)
{
	if (!op)
		return false;

	if (MMDBoneManagerObject* const mgr = GetBoneManager())
		mgr->EnsureAppendExecutionOrder();

	const auto* const self_tag = static_cast<BaseTag*>(Get());
	const BaseContainer* const bc = self_tag ? self_tag->GetDataInstance() : nullptr;

	const BoneAnimationSlotData* const slot = GetActiveAnimationSlotData();
	Vector translation;
	std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };

	if (slot && !slot->keyframes.IsEmpty())
	{
		const Float current_frame = GetAnimationFrameFromDocumentContinuous(doc);
		if (slot->keyframes.GetCount() == 1 || current_frame <= slot->keyframes[0].frame)
		{
			const auto& key = slot->keyframes[0];
			translation = Vector(key.translation.x, key.translation.y, key.translation.z);
			rotation = NormalizeQuaternion({ key.rotation_x, key.rotation_y, key.rotation_z, key.rotation_w });
		}
		else if (current_frame >= slot->keyframes[slot->keyframes.GetCount() - 1].frame)
		{
			const auto& key = slot->keyframes[slot->keyframes.GetCount() - 1];
			translation = Vector(key.translation.x, key.translation.y, key.translation.z);
			rotation = NormalizeQuaternion({ key.rotation_x, key.rotation_y, key.rotation_z, key.rotation_w });
		}
		else
		{
			Int upper_index = 1;
			while (upper_index < slot->keyframes.GetCount() && slot->keyframes[upper_index].frame <= current_frame)
				++upper_index;

			const auto interpolated = libmmd::InterpolateBoneKeys(
				ToLibMMDKeyframe(slot->keyframes[upper_index - 1]),
				ToLibMMDKeyframe(slot->keyframes[upper_index]),
				current_frame);
			translation = Vector(interpolated.translate.x(), interpolated.translate.y(), interpolated.translate.z());
			rotation = NormalizeQuaternion({
				interpolated.rotate.x(),
				interpolated.rotate.y(),
				interpolated.rotate.z(),
				interpolated.rotate.w()
			});
		}
	}

	if (bc)
	{
		if (!bc->GetBool(PMX_BONE_TRANSLATABLE))
			translation = Vector();
		if (!bc->GetBool(PMX_BONE_ROTATABLE))
			rotation = { 0.F, 0.F, 0.F, 1.F };
	}

	SetEvaluatedAnimationState(translation, rotation);
	evaluated_append_animation_translation_ = Vector();
	evaluated_append_animation_rotation_ = { 0.F, 0.F, 0.F, 1.F };
	evaluated_ik_rotation_ = { 0.F, 0.F, 0.F, 1.F };

	if (bc && (bc->GetBool(PMX_BONE_INHERIT_ROTATION) || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION)))
	{
		const Float32 inherit_weight = maxon::SafeConvert<Float32>(bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE));
		if (BaseTag* const source_tag = ResolveInheritSourceBoneTag())
		{
			if (auto* const source_tag_node = source_tag->GetNodeData<MMDBoneTag>())
			{
				if (bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
				{
					Vector source_translation;
					std::array<Float32, 4> source_rotation { 0.F, 0.F, 0.F, 1.F };
					if (source_tag_node->GetPlaybackRuntimeOverride(source_translation, source_rotation))
					{
						evaluated_append_animation_translation_ = source_translation * inherit_weight;
					}
					else
					{
						const Bool inherit_local = bc->GetBool(PMX_BONE_INHERIT_LOCAL);
						const Bool source_has_append_source = source_tag_node->ResolveInheritSourceBoneTag() != nullptr;
						source_translation = (inherit_local || !source_has_append_source)
							? source_tag_node->evaluated_animation_translation_
							: source_tag_node->evaluated_append_animation_translation_;
						evaluated_append_animation_translation_ = source_translation * inherit_weight;
					}
				}

				if (bc->GetBool(PMX_BONE_INHERIT_ROTATION))
				{
					Vector source_translation;
					std::array<Float32, 4> source_rotation { 0.F, 0.F, 0.F, 1.F };
					Eigen::Quaternionf append_rotation = Eigen::Quaternionf::Identity();
					if (source_tag_node->GetPlaybackRuntimeOverride(source_translation, source_rotation))
					{
						append_rotation = ToEigenQuaternion(source_rotation);
					}
					else
					{
						const Bool inherit_local = bc->GetBool(PMX_BONE_INHERIT_LOCAL);
						const Bool source_has_append_source = source_tag_node->ResolveInheritSourceBoneTag() != nullptr;
						source_rotation = (inherit_local || !source_has_append_source)
							? source_tag_node->evaluated_animation_rotation_
							: source_tag_node->evaluated_append_animation_rotation_;
						append_rotation = ToEigenQuaternion(source_rotation);
						append_rotation = ToEigenQuaternion(source_tag_node->evaluated_ik_rotation_) * append_rotation;
					}
					evaluated_append_animation_rotation_ = ToQuaternionArray(Eigen::Quaternionf::Identity().slerp(inherit_weight, append_rotation));
				}
			}
		}
	}

	const Vector final_translation = evaluated_animation_translation_ + evaluated_append_animation_translation_;
	const std::array<Float32, 4> final_rotation = ToQuaternionArray(
		ToEigenQuaternion(evaluated_animation_rotation_) * ToEigenQuaternion(evaluated_append_animation_rotation_));
	if (apply_to_scene)
	{
		op->SetRelMl(BuildAnimationMatrix(final_translation, final_rotation));
		MarkBoneTransformDirty(op);
	}
	return true;
}

BaseTag* MMDBoneTag::GetBoneLockProtectionTag() const
{
	if (!bone_object_ || !bone_lock_protection_link_)
		return nullptr;
	BaseDocument* doc = nullptr;
	if (GeListNode* self = const_cast<MMDBoneTag*>(this)->Get())
		doc = static_cast<BaseList2D*>(self)->GetDocument();
	BaseTag* linked = nullptr;
	if (doc)
		linked = static_cast<BaseTag*>(bone_lock_protection_link_->GetLink(doc));
	else
		linked = static_cast<BaseTag*>(bone_lock_protection_link_->ForceGetLink());
	if (linked && linked->IsInstanceOf(Tprotection) && linked->GetObject() == bone_object_)
		return linked;
	return nullptr;
}

bool MMDBoneTag::FindOrCreateBoneLockTag()
{
	if (GetBoneLockProtectionTag())
		return true;

	if (bone_lock_protection_link_)
		bone_lock_protection_link_->SetLink(nullptr);

	if (!bone_object_)
		return false;

	// Legacy / multi-Protection: adopt last hidden Tprotection (MakeTag appends; matches plugin-created tag).
	BaseTag* legacy_hidden = nullptr;
	for (BaseTag* tag = bone_object_->GetFirstTag(); tag; tag = tag->GetNext())
	{
		if (tag->IsInstanceOf(Tprotection) && tag->GetNBit(NBIT::OHIDE))
			legacy_hidden = tag;
	}
	if (legacy_hidden)
	{
		bone_lock_protection_link_->SetLink(legacy_hidden);
		return true;
	}

	return CreateBoneLockTag();
}

bool MMDBoneTag::CreateBoneLockTag()
{
	if (!bone_object_ || !bone_lock_protection_link_)
		return false;
	BaseTag* new_tag = bone_object_->MakeTag(Tprotection);
	if (!new_tag)
		return false;
	new_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
	new_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	new_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	bone_lock_protection_link_->SetLink(new_tag);
	return true;
}

void MMDBoneTag::SetRotationLock(const bool flag) const
{
	if (BaseTag* pt = GetBoneLockProtectionTag())
	{
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), flag, DESCFLAGS_SET::NONE);
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), flag, DESCFLAGS_SET::NONE);
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), flag, DESCFLAGS_SET::NONE);
	}
}

void MMDBoneTag::SetPositionLock(const bool flag) const
{
	if (BaseTag* pt = GetBoneLockProtectionTag())
	{
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), flag, DESCFLAGS_SET::NONE);
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), flag, DESCFLAGS_SET::NONE);
		pt->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), flag, DESCFLAGS_SET::NONE);
	}
}

EXECUTIONRESULT MMDBoneTag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op)
		return EXECUTIONRESULT::OK;

	if(!bone_object_)
		bone_object_ = op;

	UpdateHierarchyTopologyCache(op, true);

	if (bone_mode_ == BONE_MODE_ANIM)
	{
		BeginPrephysicsFrame(doc);
		SyncSplineFromCurrentParametersIfNeeded(tag);
		const BaseContainer* const bc = tag ? tag->GetDataInstance() : nullptr;
		const Bool deform_after_physics = bc ? bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM) : false;
		const Bool apply_to_scene = !deform_after_physics
			&& !ShouldSkipPrephysicsSceneWrite(doc)
			&& !HasRecentPlaybackRuntimeOverride(doc);
		ApplyActiveAnimation(op, doc, apply_to_scene);
		if (!deform_after_physics && is_IK && GetModelManager() == nullptr)
			RunIKSolveAnimMode(op, true);
	}
	else
	{
		ResetEvaluatedAnimationState();
		ClearPlaybackRuntimeOverride();
	}

	if (bone_mode_ == BONE_MODE_ANIM && !bone_morph_data_arr_.IsEmpty())
	{
		GeData ge_data;
		op->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_POSITION)), ge_data, DESCFLAGS_GET::NONE);
		Vector op_position = ge_data.GetVector() - prev_position_;
		prev_position_ = Vector();
		op->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_ROTATION)), ge_data, DESCFLAGS_GET::NONE);
		Vector op_rotation = ge_data.GetVector() - prev_rotation_;
		prev_rotation_ = Vector();

		for (const auto& morph : bone_morph_data_arr_)
		{
			Float strength = 0;
			if (tag->GetParameter(morph.strength_id, ge_data, DESCFLAGS_GET::NONE))
				strength = ge_data.GetFloat();

			if (tag->GetParameter(morph.translation_id, ge_data, DESCFLAGS_GET::NONE))
				prev_position_ += ge_data.GetVector() * strength;

			if (tag->GetParameter(morph.rotation_id, ge_data, DESCFLAGS_GET::NONE))
				prev_rotation_ += ge_data.GetVector() * strength;
		}

		op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_POSITION)), op_position + prev_position_, DESCFLAGS_SET::NONE);
		op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_ROTATION)), op_rotation + prev_rotation_, DESCFLAGS_SET::NONE);
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDBoneTag::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{ return false; };
	IOReadField(bone_manager_link_);
	IOReadField(bone_morph_name_index_);
	if (!io_util::ReadLinearContainer(hf, bone_morph_data_arr_))
		return false;
	for (Int32 i = 0; i < bone_morph_data_arr_.GetCount(); i++)
	{
		auto& d = bone_morph_data_arr_[i];
		DescID del_id = d.button_delete_id;
		DescID ren_id = d.button_rename_id;
		bone_morph_button_id_map_.Insert(std::move(del_id), i)iferr_return;
		bone_morph_button_id_map_.Insert(std::move(ren_id), i)iferr_return;
	}
	if (level >= 1)
		IOReadField(bone_lock_protection_link_);
	if (level >= 2)
	{
		IOReadField(active_animation_slot_);
		if (!io_util::ReadLinearContainer(hf, bone_animation_slots_))
			return false;
	}
	else
	{
		iferr(bone_animation_slots_.Resize(0))
			return false;
		active_animation_slot_ = -1;
	}
	if (!bone_animation_slots_.IsEmpty())
		active_animation_slot_ = std::clamp(active_animation_slot_, -1, static_cast<Int32>(bone_animation_slots_.GetCount() - 1));
	else
		active_animation_slot_ = -1;
	bone_manager_data_ = nullptr;
	bone_object_ = nullptr;
	hierarchy_parent_cache_ = nullptr;
	hierarchy_pred_cache_ = nullptr;
	hierarchy_manager_cache_ = nullptr;
	is_syncing_inherit_source_ = false;
	append_recursion_depth_ = 0;
	last_prephysics_time_ = BaseTime(-1.);
	last_ik_solve_time_ = BaseTime(-1.);
	last_postphysics_ik_solve_time_ = BaseTime(-1.);
	standalone_ik_chain_dirty_ = true;
	standalone_ik_chain_solver_ = nullptr;
	skip_prephysics_scene_write_ = false;
	ik_overridden_this_frame_ = false;
	ClearPlaybackRuntimeOverride();
	ResetEvaluatedAnimationState();
	return SUPER::Read(node, hf, level);
}

SDK2024_Write(MMDBoneTag)
{
	IOWriteField(bone_manager_link_);
	IOWriteField(bone_morph_name_index_);
	const auto& morph_arr_ref = bone_morph_data_arr_;
	if (!io_util::WriteLinearContainer(hf, morph_arr_ref))
		return false;
	IOWriteField(bone_lock_protection_link_);
	IOWriteField(active_animation_slot_);
	const auto& animation_slots_ref = bone_animation_slots_;
	if (!io_util::WriteLinearContainer(hf, animation_slots_ref))
		return false;
	return SUPER::Write(node, hf);
}

Int32 MMDBoneTag::GetBoneIndex() const
{
	if (const auto* mgr = bone_manager_data_ ? bone_manager_data_ : const_cast<MMDBoneTag*>(this)->GetBoneManager())
	{
		if (const BaseTag* const tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get()))
			return mgr->FindBoneIndex(tag);
	}

	if (const BaseTag* const tag = static_cast<BaseTag*>(const_cast<MMDBoneTag*>(this)->Get()))
	{
		if (const BaseContainer* const bc = tag->GetDataInstance())
			return bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	}

	return -1;
}
