/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_model.h
Description:	MMD model object

**************************************************************************/

#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "cmt_tools_manager.h"
#include "mmd_morph.h"
#include "module/tools/material/mmd_material.h"
#include "module/tools/tag/mmd_bone.h"
#include "mmd_bone_manager.h"
#include "mmd_joint_manager.h"
#include "mmd_mesh_manager.h"
#include "mmd_rigid_manager.h"
#include "customgui_priority.h"
#include "description/OMMDModelManager.h"
#include "description/OMMDRigid.h"
#include "description/TMMDBone.h"
#include "maxon/queue.h"
#include "utils/filename_util.hpp"
#include "utils/mmd_bone_control_util.hpp"
#include "utils/string_util.hpp"
#include "libMMD/Model/MMD/MMDIkSolver.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "libMMD/Model/MMD/SjisToUnicode.h"
#include "libMMD/Model/MMD/VMDInterpolation.h"


#include <btBulletDynamicsCommon.h>

#include <Eigen/Geometry>

#include <algorithm>
#include <cmath>
#include <codecvt>
#include <locale>
#include <map>
#include <limits>
#include <set>
#include <unordered_map>

#define COL_NAME 'name'

namespace
{
	constexpr Float32 kModelAnimationFps = 30.0f;
	constexpr Int32 kModelManagerPriorityOffset = 5000;

	Int32 NormalizeModelMode(const Int32 mode)
	{
		constexpr Int32 kLegacyModelModeVmd = 2;
		return mode == kLegacyModelModeVmd ? MODEL_MODE_ANIM : mode;
	}

	void ConfigureModelManagerExecutionPriority(GeListNode* node)
	{
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
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, kModelManagerPriorityOffset);
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
		}
	}

	uint8_t PmxIndexSizeForCount(const int count)
	{
		const int max_index = count > 0 ? count - 1 : 0;
		if (max_index <= 0xFF)
			return 1;
		if (max_index <= 0xFFFF)
			return 2;
		return 4;
	}

	void WritePmxHeaderAndInfo(libmmd::PMXFile& pmx_file, const BaseContainer& bc)
	{
		libmmd::PMXHeader& header = pmx_file.m_header;
		header.m_magic.Set("PMX ");
		header.m_version = bc.GetFloat(PMX_VERSION, 2.0f);
		header.m_dataSize = 8;
		header.m_encode = 1;
		header.m_addUVNum = 0;

		libmmd::PMXInfo& info = pmx_file.m_info;
		info.m_modelName = string_util::GetStdString(bc.GetString(MODEL_NAME_LOCAL));
		info.m_englishModelName = string_util::GetStdString(bc.GetString(MODEL_NAME_UNIVERSAL));
		info.m_comment = string_util::GetStdString(bc.GetString(COMMENTS_LOCAL));
		info.m_englishComment = string_util::GetStdString(bc.GetString(COMMENTS_UNIVERSAL));
	}

	void FinalizePmxHeaderIndexSizes(libmmd::PMXFile& pmx_file)
	{
		libmmd::PMXHeader& header = pmx_file.m_header;
		header.m_vertexIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_vertices.size()));
		header.m_textureIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_textures.size()));
		header.m_materialIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_materials.size()));
		header.m_boneIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_bones.size()));
		header.m_morphIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_morphs.size()));
		header.m_rigidbodyIndexSize = PmxIndexSizeForCount(static_cast<int>(pmx_file.m_rigidbodies.size()));
	}

	libmmd::PMXMorphType MorphTypeToPmx(const MMDMorphType type)
	{
		switch (type)
		{
		case MMDMorphType::GROUP: return libmmd::PMXMorphType::Group;
		case MMDMorphType::FLIP: return libmmd::PMXMorphType::Flip;
		case MMDMorphType::MESH: return libmmd::PMXMorphType::Position;
		case MMDMorphType::UV: return libmmd::PMXMorphType::UV;
		case MMDMorphType::BONE: return libmmd::PMXMorphType::Bone;
		case MMDMorphType::MATERIAL: return libmmd::PMXMorphType::Material;
		case MMDMorphType::IMPULSE: return libmmd::PMXMorphType::Impluse;
		default: return libmmd::PMXMorphType::Position;
		}
	}

	Bool ExportMorphStubs(const maxon::PointerArray<IMorph>& morph_data, libmmd::PMXFile& pmx_file)
	{
		pmx_file.m_morphs.clear();
		if (morph_data.IsEmpty())
			return true;

		pmx_file.m_morphs.resize(static_cast<size_t>(morph_data.GetCount()));
		for (Int32 morph_index = 0; morph_index < morph_data.GetCount(); ++morph_index)
		{
			IMorph& morph = const_cast<IMorph&>(morph_data[morph_index]);
			libmmd::PMXFileMorph& pmx_morph = pmx_file.m_morphs[static_cast<size_t>(morph_index)];
			pmx_morph.m_name = string_util::GetStdString(morph.GetName());
			pmx_morph.m_englishName = pmx_morph.m_name;
			pmx_morph.m_controlPanel = static_cast<uint8_t>(morph.GetPanel());
			pmx_morph.m_morphType = MorphTypeToPmx(morph.GetType());

			maxon::HashMap<Int, Float>* const sub_morphs = morph.GetSubMorphDataWritable();
			if (!sub_morphs)
				continue;

			if (morph.GetType() == MMDMorphType::GROUP)
			{
				for (const auto& entry : *sub_morphs)
				{
					libmmd::PMXFileMorph::GroupMorph group_morph;
					group_morph.m_morphIndex = static_cast<int32_t>(entry.GetKey());
					group_morph.m_weight = entry.GetValue();
					pmx_morph.m_groupMorph.push_back(group_morph);
				}
			}
			else if (morph.GetType() == MMDMorphType::FLIP)
			{
				for (const auto& entry : *sub_morphs)
				{
					libmmd::PMXFileMorph::FlipMorph flip_morph;
					flip_morph.m_morphIndex = static_cast<int32_t>(entry.GetKey());
					flip_morph.m_weight = entry.GetValue();
					pmx_morph.m_flipMorph.push_back(flip_morph);
				}
			}
		}
		return true;
	}

	void BuildPmxTextureTable(const maxon::BaseArray<MMDMaterialData>& materials,
	                          std::vector<libmmd::PMXTexture>& textures,
	                          std::unordered_map<std::string, Int32>& path_to_index)
	{
		textures.clear();
		path_to_index.clear();

		const auto add_path = [&](const String& path)
		{
			if (path.IsEmpty())
				return;
			const std::string key = string_util::GetStdString(path);
			if (path_to_index.find(key) != path_to_index.end())
				return;
			const Int32 index = static_cast<Int32>(textures.size());
			libmmd::PMXTexture texture;
			texture.m_textureName = key;
			textures.push_back(std::move(texture));
			path_to_index.emplace(key, index);
		};

		for (const auto& material : materials)
		{
			add_path(material.texture_path);
			add_path(material.sphere_texture_path);
			// Common toon (toon_mode == 1) uses PMX slot 0..9, not the texture table.
			if (material.toon_mode == static_cast<Int32>(libmmd::PMXToonMode::Separate))
				add_path(material.toon_texture_path);
		}
	}

	Int32 ResolveTextureIndex(const std::unordered_map<std::string, Int32>& path_to_index, const String& path)
	{
		if (path.IsEmpty())
			return -1;
		const auto it = path_to_index.find(string_util::GetStdString(path));
		return it != path_to_index.end() ? it->second : -1;
	}

	Int32 ResolveToonTextureIndex(const MMDMaterialData& material,
	                                const std::unordered_map<std::string, Int32>& path_to_index)
	{
		if (material.toon_mode == static_cast<Int32>(libmmd::PMXToonMode::Common))
			return material.toon_texture_index;
		return ResolveTextureIndex(path_to_index, material.toon_texture_path);
	}

	void AppendDefaultPmxMaterialForMesh(libmmd::PMXFile& pmx_file)
	{
		if (pmx_file.m_faces.empty() || !pmx_file.m_materials.empty())
			return;

		libmmd::PMXMaterial mat{};
		mat.m_name = "default";
		mat.m_englishName = "default";
		mat.m_diffuse = Eigen::Vector4f(1.0f, 1.0f, 1.0f, 1.0f);
		mat.m_specularPower = 1.0f;
		mat.m_ambient = Eigen::Vector3f(0.2f, 0.2f, 0.2f);
		mat.m_textureIndex = -1;
		mat.m_sphereTextureIndex = -1;
		mat.m_sphereMode = libmmd::PMXSphereMode::None;
		mat.m_toonMode = libmmd::PMXToonMode::Common;
		mat.m_toonTextureIndex = 0;
		mat.m_numFaceVertices = static_cast<int32_t>(pmx_file.m_faces.size() * 3);
		pmx_file.m_materials.push_back(std::move(mat));
	}

	class MaterialExportStateGuard
	{
	public:
		explicit MaterialExportStateGuard(maxon::BaseArray<MMDMaterialData>& materials)
			: materials_(materials), original_count_(static_cast<Int32>(materials.GetCount()))
		{
			face_counts_.reserve(static_cast<size_t>(original_count_));
			for (Int32 i = 0; i < original_count_; ++i)
				face_counts_.push_back(materials_[i].num_face_vertices);
		}

		~MaterialExportStateGuard()
		{
			iferr(materials_.Resize(original_count_)) {}
			const Int32 restore_count = std::min(original_count_, static_cast<Int32>(materials_.GetCount()));
			for (Int32 i = 0; i < restore_count; ++i)
				materials_[i].num_face_vertices = face_counts_[static_cast<size_t>(i)];
		}

	private:
		maxon::BaseArray<MMDMaterialData>& materials_;
		Int32 original_count_;
		std::vector<Int32> face_counts_;
	};

	void RemoveEmptyBoneMorphStubs(libmmd::PMXFile& pmx_file)
	{
		auto& morphs = pmx_file.m_morphs;
		const size_t original_size = morphs.size();
		std::vector<int32_t> remap(original_size, -1);
		size_t write = 0;
		for (size_t read = 0; read < original_size; ++read)
		{
			if (morphs[read].m_morphType == libmmd::PMXMorphType::Bone && morphs[read].m_boneMorph.empty())
				continue;
			remap[read] = static_cast<int32_t>(write);
			if (write != read)
				morphs[write] = std::move(morphs[read]);
			++write;
		}
		if (write == original_size)
			return;
		morphs.resize(write);

		for (auto& morph : morphs)
		{
			for (auto& gm : morph.m_groupMorph)
				if (gm.m_morphIndex >= 0 && static_cast<size_t>(gm.m_morphIndex) < original_size)
					gm.m_morphIndex = remap[static_cast<size_t>(gm.m_morphIndex)];
			for (auto& fm : morph.m_flipMorph)
				if (fm.m_morphIndex >= 0 && static_cast<size_t>(fm.m_morphIndex) < original_size)
					fm.m_morphIndex = remap[static_cast<size_t>(fm.m_morphIndex)];
		}
	}

	void ExportDisplayFrames(const maxon::BaseArray<DisplayFrameData>& display_frames,
	                         libmmd::PMXFile& pmx_file, const Int32 bone_count, const Int32 morph_count)
	{
		pmx_file.m_displayFrames.clear();
		for (const auto& frame : display_frames)
		{
			libmmd::PMXDisplayFrame pmx_frame;
			pmx_frame.m_name = string_util::GetStdString(frame.name);
			pmx_frame.m_englishName = string_util::GetStdString(frame.name_universal);
			pmx_frame.m_flag = frame.is_special
				? libmmd::PMXDisplayFrame::FrameType::SpecialFrame
				: libmmd::PMXDisplayFrame::FrameType::DefaultFrame;

			for (const auto& target : frame.targets)
			{
				if (target.type == DisplayFrameTargetType::Bone)
				{
					if (target.index < 0 || target.index >= bone_count)
						continue;
				}
				else if (target.index < 0 || target.index >= morph_count)
				{
					continue;
				}

				libmmd::PMXDisplayFrame::Target pmx_target;
				pmx_target.m_type = (target.type == DisplayFrameTargetType::Bone)
					? libmmd::PMXDisplayFrame::TargetType::BoneIndex
					: libmmd::PMXDisplayFrame::TargetType::MorphIndex;
				pmx_target.m_index = target.index;
				pmx_frame.m_targets.push_back(pmx_target);
			}
			pmx_file.m_displayFrames.push_back(std::move(pmx_frame));
		}
	}

	void ClearUnsupportedPmxSections(libmmd::PMXFile& pmx_file)
	{
		// v1 export does not reconstruct PMX softbodies or unknown extension blobs.
		pmx_file.m_softbodies.clear();
	}

	Int32 ToAnimationFrame(const UInt32 frame, const Float time_offset)
	{
		return static_cast<Int32>(frame) + static_cast<Int32>(time_offset);
	}

	String GetBoneTagName(const BaseTag* tag, const Bool use_local_name)
	{
		if (!tag)
			return ""_s;

		GeData data;
		const Int32 param_id = use_local_name ? PMX_BONE_NAME_LOCAL : PMX_BONE_NAME_UNIVERSAL;
		if (GetAtomParameter(tag, CreateDescID(DescLevel(param_id)), data, DESCFLAGS_GET::NONE))
		{
			const String name = data.GetString();
			if (!name.IsEmpty())
				return name;
		}

		if (BaseObject* object = const_cast<BaseTag*>(tag)->GetObject())
			return object->GetName();

		return ""_s;
	}

	String GetModelManagerName(const BaseObject* object)
	{
		if (!object)
			return ""_s;

		if (const BaseContainer* const bc = object->GetDataInstance())
		{
			const String local_name = bc->GetString(MODEL_NAME_LOCAL);
			if (!local_name.IsEmpty())
				return local_name;

			const String universal_name = bc->GetString(MODEL_NAME_UNIVERSAL);
			if (!universal_name.IsEmpty())
				return universal_name;
		}

		return object->GetName();
	}

	void MarkSceneNodeDirty(BaseList2D* node)
	{
		if (!node)
			return;

		node->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
	}

	void MarkMeshHierarchyDirty(BaseObject* mesh_manager_object)
	{
		if (!mesh_manager_object)
			return;

		for (BaseObject* mesh_object = mesh_manager_object->GetDown(); mesh_object; mesh_object = mesh_object->GetNext())
		{
			MarkSceneNodeDirty(mesh_object);

			for (BaseTag* tag = mesh_object->GetFirstTag(); tag; tag = tag->GetNext())
			{
				if (tag->GetType() == Tweights)
					MarkSceneNodeDirty(tag);
			}

			for (BaseObject* child = mesh_object->GetDown(); child; child = child->GetNext())
				MarkSceneNodeDirty(child);
		}
	}

	void RemoveParameterTrack(BaseList2D* node, const DescID& id)
	{
		if (!node)
			return;

		CTrack* track = node->FindCTrack(id);
		if (!track)
			return;

		track->Remove();
		CTrack::Free(track);
		MarkSceneNodeDirty(node);
	}

	BaseObject* FindFirstMeshObject(BaseObject* mesh_manager_object)
	{
		if (!mesh_manager_object)
			return nullptr;

		for (BaseObject* child = mesh_manager_object->GetDown(); child; child = child->GetNext())
		{
			if (child->IsInstanceOf(Opolygon))
				return child;
		}

		return nullptr;
	}

	BaseObject* GetMeshDeformedCache(BaseObject* mesh_object)
	{
		if (!mesh_object)
			return nullptr;

		for (BaseObject* cache = mesh_object->GetDeformCache(); cache; cache = cache->GetCache())
		{
			if (cache->IsInstanceOf(Opolygon))
				return cache;
		}

		return nullptr;
	}

	std::string ConvertUtf8ToSjis(const std::string& utf8)
	{
		if (utf8.empty())
			return {};

		try
		{
			std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> converter;
			return libmmd::ConvertU16ToSjisString(converter.from_bytes(utf8));
		}
		catch (...)
		{
			return utf8;
		}
	}

	std::string ConvertStringToSjis(const String& value)
	{
		return ConvertUtf8ToSjis(string_util::GetStdString(value));
	}

	BoneAnimationBezierData ReadInterpolationChannel(const std::array<uint8_t, 64>& interpolation, const Int32 channel)
	{
		const Int32 offset = std::clamp(channel, 0, 3);
		BoneAnimationBezierData bezier;
		bezier.ax = interpolation[offset];
		bezier.ay = interpolation[offset + 4];
		bezier.bx = interpolation[offset + 8];
		bezier.by = interpolation[offset + 12];
		return bezier;
	}

	void WriteInterpolationChannel(std::array<uint8_t, 64>& interpolation, const Int32 channel, const BoneAnimationBezierData& bezier)
	{
		const Int32 offset = std::clamp(channel, 0, 3);
		interpolation[offset] = bezier.ax;
		interpolation[offset + 4] = bezier.ay;
		interpolation[offset + 8] = bezier.bx;
		interpolation[offset + 12] = bezier.by;
	}

	BoneAnimationKeyframeData ConvertMotionToBoneKeyframe(const libmmd::VMDMotion& motion, const CMTToolsSetting::MotionImport& setting)
	{
		BoneAnimationKeyframeData keyframe;
		keyframe.frame = ToAnimationFrame(motion.m_frame, setting.time_offset);
		keyframe.translation = Vector32(
			motion.m_translate.x(),
			motion.m_translate.y(),
			motion.m_translate.z());
		const Eigen::Quaternionf rotation = motion.m_quaternion.normalized();
		keyframe.rotation_x = rotation.x();
		keyframe.rotation_y = rotation.y();
		keyframe.rotation_z = rotation.z();
		keyframe.rotation_w = rotation.w();
		keyframe.translate_x = ReadInterpolationChannel(motion.m_interpolation, 0);
		keyframe.translate_y = ReadInterpolationChannel(motion.m_interpolation, 1);
		keyframe.translate_z = ReadInterpolationChannel(motion.m_interpolation, 2);
		keyframe.rotation = ReadInterpolationChannel(motion.m_interpolation, 3);
		return keyframe;
	}

	libmmd::VMDMotion ConvertBoneKeyframeToMotion(const String& bone_name, const BoneAnimationKeyframeData& keyframe, const CMTToolsSetting::MotionExport& setting)
	{
		libmmd::VMDMotion motion;
		const std::string sjis_name = ConvertStringToSjis(bone_name);
		motion.m_boneName.Set(sjis_name.c_str());
		motion.m_frame = static_cast<UInt32>(std::max(0, keyframe.frame + static_cast<Int32>(setting.time_offset)));
		motion.m_translate = Eigen::Vector3f(
			keyframe.translation.x,
			keyframe.translation.y,
			keyframe.translation.z);
		motion.m_quaternion = Eigen::Quaternionf(
			keyframe.rotation_w,
			keyframe.rotation_x,
			keyframe.rotation_y,
			keyframe.rotation_z).normalized();
		motion.m_interpolation.fill(0);
		WriteInterpolationChannel(motion.m_interpolation, 0, keyframe.translate_x);
		WriteInterpolationChannel(motion.m_interpolation, 1, keyframe.translate_y);
		WriteInterpolationChannel(motion.m_interpolation, 2, keyframe.translate_z);
		WriteInterpolationChannel(motion.m_interpolation, 3, keyframe.rotation);
		return motion;
	}

	Eigen::Vector3f ToVpdVector(const Vector& value)
	{
		return Eigen::Vector3f(
			maxon::SafeConvert<float>(value.x),
			maxon::SafeConvert<float>(value.y),
			maxon::SafeConvert<float>(value.z));
	}

	Eigen::Quaternionf ToVpdQuaternion(const std::array<Float32, 4>& rotation)
	{
		return Eigen::Quaternionf(rotation[3], rotation[0], rotation[1], rotation[2]).normalized();
	}

	Eigen::Quaternionf ExtractVpdQuaternion(const Matrix& matrix)
	{
		Matrix normalized = matrix;
		normalized.sqmat = normalized.sqmat.GetNormalized();

		Eigen::Matrix3f basis = Eigen::Matrix3f::Identity();
		basis(0, 0) = maxon::SafeConvert<float>(normalized.sqmat.v1.x);
		basis(1, 0) = maxon::SafeConvert<float>(normalized.sqmat.v1.y);
		basis(2, 0) = maxon::SafeConvert<float>(normalized.sqmat.v1.z);
		basis(0, 1) = maxon::SafeConvert<float>(normalized.sqmat.v2.x);
		basis(1, 1) = maxon::SafeConvert<float>(normalized.sqmat.v2.y);
		basis(2, 1) = maxon::SafeConvert<float>(normalized.sqmat.v2.z);
		basis(0, 2) = maxon::SafeConvert<float>(normalized.sqmat.v3.x);
		basis(1, 2) = maxon::SafeConvert<float>(normalized.sqmat.v3.y);
		basis(2, 2) = maxon::SafeConvert<float>(normalized.sqmat.v3.z);
		return Eigen::Quaternionf(basis).normalized();
	}

	std::array<Float32, 4> ToBoneRotationArray(const Eigen::Quaternionf& rotation)
	{
		const Eigen::Quaternionf normalized = rotation.normalized();
		return {
			maxon::SafeConvert<Float32>(normalized.x()),
			maxon::SafeConvert<Float32>(normalized.y()),
			maxon::SafeConvert<Float32>(normalized.z()),
			maxon::SafeConvert<Float32>(normalized.w())
		};
	}

	constexpr Float kPoseRegisterEpsilon = 1.0e-5;

	Bool IsTranslationDifferent(const Vector& lhs, const Vector& rhs)
	{
		return (lhs - rhs).GetLength() > kPoseRegisterEpsilon;
	}

	Bool IsQuaternionDifferent(const std::array<Float32, 4>& lhs, const std::array<Float32, 4>& rhs)
	{
		const Eigen::Quaternionf left(lhs[3], lhs[0], lhs[1], lhs[2]);
		const Eigen::Quaternionf right(rhs[3], rhs[0], rhs[1], rhs[2]);
		const Float32 dot = std::abs(left.normalized().dot(right.normalized()));
		return 1.0F - dot > maxon::SafeConvert<Float32>(kPoseRegisterEpsilon);
	}

	Bool IsPoseDifferent(
		const Vector& lhs_translation,
		const std::array<Float32, 4>& lhs_rotation,
		const Vector& rhs_translation,
		const std::array<Float32, 4>& rhs_rotation)
	{
		return IsTranslationDifferent(lhs_translation, rhs_translation) || IsQuaternionDifferent(lhs_rotation, rhs_rotation);
	}

	libmmd::VMDBezier ToLibMMDBezierForSampling(const BoneAnimationBezierData& bezier)
	{
		libmmd::VMDBezier result;
		result.m_cp1 = Eigen::Vector2f(static_cast<float>(bezier.ax) / 127.0f, static_cast<float>(bezier.ay) / 127.0f);
		result.m_cp2 = Eigen::Vector2f(static_cast<float>(bezier.bx) / 127.0f, static_cast<float>(bezier.by) / 127.0f);
		return result;
	}

	libmmd::VMDBoneKeyframe ToLibMMDKeyframeForSampling(const BoneAnimationKeyframeData& keyframe)
	{
		libmmd::VMDBoneKeyframe result;
		result.frame = keyframe.frame;
		result.translate = Eigen::Vector3f(keyframe.translation.x, keyframe.translation.y, keyframe.translation.z);
		result.rotate = Eigen::Quaternionf(keyframe.rotation_w, keyframe.rotation_x, keyframe.rotation_y, keyframe.rotation_z).normalized();
		result.txBezier = ToLibMMDBezierForSampling(keyframe.translate_x);
		result.tyBezier = ToLibMMDBezierForSampling(keyframe.translate_y);
		result.tzBezier = ToLibMMDBezierForSampling(keyframe.translate_z);
		result.rotBezier = ToLibMMDBezierForSampling(keyframe.rotation);
		return result;
	}

	void EvaluateBoneAnimationKeyframes(
		const maxon::BaseArray<BoneAnimationKeyframeData>& keyframes,
		const Float current_frame,
		Vector& translation,
		std::array<Float32, 4>& rotation)
	{
		translation = Vector();
		rotation = { 0.F, 0.F, 0.F, 1.F };
		if (keyframes.IsEmpty())
			return;

		if (keyframes.GetCount() == 1 || current_frame <= keyframes[0].frame)
		{
			const auto& key = keyframes[0];
			translation = Vector(key.translation.x, key.translation.y, key.translation.z);
			rotation = { key.rotation_x, key.rotation_y, key.rotation_z, key.rotation_w };
			return;
		}

		if (current_frame >= keyframes[keyframes.GetCount() - 1].frame)
		{
			const auto& key = keyframes[keyframes.GetCount() - 1];
			translation = Vector(key.translation.x, key.translation.y, key.translation.z);
			rotation = { key.rotation_x, key.rotation_y, key.rotation_z, key.rotation_w };
			return;
		}

		Int upper_index = 1;
		while (upper_index < keyframes.GetCount() && keyframes[upper_index].frame <= current_frame)
			++upper_index;

		const auto interpolated = libmmd::InterpolateBoneKeys(
			ToLibMMDKeyframeForSampling(keyframes[upper_index - 1]),
			ToLibMMDKeyframeForSampling(keyframes[upper_index]),
			current_frame);
		translation = Vector(interpolated.translate.x(), interpolated.translate.y(), interpolated.translate.z());
		rotation = ToBoneRotationArray(interpolated.rotate);
	}

	Bool ContainsBoneIndex(const std::vector<Int32>& indices, const Int32 bone_index)
	{
		return std::find(indices.begin(), indices.end(), bone_index) != indices.end();
	}

	Bool ContainsMorphName(const std::vector<String>& names, const String& morph_name)
	{
		return std::find(names.begin(), names.end(), morph_name) != names.end();
	}

	void AppendUniqueBoneIndex(std::vector<Int32>& indices, const Int32 bone_index)
	{
		if (!ContainsBoneIndex(indices, bone_index))
			indices.push_back(bone_index);
	}

	void AppendUniqueMorphName(std::vector<String>& names, const String& morph_name)
	{
		if (!ContainsMorphName(names, morph_name))
			names.push_back(morph_name);
	}

	Int32 FindKeyframeIndex(const maxon::BaseArray<BoneAnimationKeyframeData>& keyframes, const Int32 frame)
	{
		for (Int32 index = 0; index < keyframes.GetCount(); ++index)
		{
			if (keyframes[index].frame == frame)
				return index;
		}
		return NOTOK;
	}

	BoneAnimationKeyframeData MakeBoneKeyframe(
		const Int32 frame,
		const Vector& translation,
		const std::array<Float32, 4>& rotation,
		const Bool static_pose = false)
	{
		BoneAnimationKeyframeData keyframe;
		keyframe.frame = frame;
		keyframe.translation = Vector32(
			maxon::SafeConvert<Float32>(translation.x),
			maxon::SafeConvert<Float32>(translation.y),
			maxon::SafeConvert<Float32>(translation.z));
		keyframe.rotation_x = rotation[0];
		keyframe.rotation_y = rotation[1];
		keyframe.rotation_z = rotation[2];
		keyframe.rotation_w = rotation[3];
		keyframe.static_pose = static_pose;
		return keyframe;
	}

	libmmd::VPDBone ConvertCurrentBoneToVpd(
		const BaseTag* bone_tag,
		BaseObject* bone_object,
		const Vector* runtime_translation,
		const std::array<Float32, 4>* runtime_rotation)
	{
		libmmd::VPDBone vpd_bone;
		String bone_name = GetBoneTagName(bone_tag, true);
		if (bone_name.IsEmpty())
			bone_name = GetBoneTagName(bone_tag, false);
		vpd_bone.m_boneName = string_util::GetStdString(bone_name);

		if (runtime_translation && runtime_rotation)
		{
			vpd_bone.m_translate = ToVpdVector(*runtime_translation);
			vpd_bone.m_quaternion = ToVpdQuaternion(*runtime_rotation);
			return vpd_bone;
		}

		const Matrix rel_matrix = bone_object ? bone_object->GetRelMl() : Matrix();
		vpd_bone.m_translate = ToVpdVector(rel_matrix.off);
		vpd_bone.m_quaternion = ExtractVpdQuaternion(rel_matrix);
		return vpd_bone;
	}

	Int32 GetVmdFileMaxFrame(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting)
	{
		Int32 max_frame = 0;
		if (setting.import_motion)
		{
			for (const auto& motion : vmd_file.m_motions)
				max_frame = std::max(max_frame, ToAnimationFrame(motion.m_frame, setting.time_offset));
		}
		if (setting.import_morph)
		{
			for (const auto& morph : vmd_file.m_morphs)
				max_frame = std::max(max_frame, ToAnimationFrame(morph.m_frame, setting.time_offset));
		}
		for (const auto& ik : vmd_file.m_iks)
			max_frame = std::max(max_frame, ToAnimationFrame(ik.m_frame, setting.time_offset));
		return max_frame;
	}

	Bool IsBoneDrivenByDynamicPhysics(const BaseObject* rigid_manager_object, const Int32 bone_index)
	{
		if (!rigid_manager_object || bone_index < 0)
			return false;

		for (BaseObject* child = const_cast<BaseObject*>(rigid_manager_object)->GetDown(); child; child = child->GetNext())
		{
			if (!child->IsInstanceOf(g_mmd_rigid_object_id))
				continue;

			const BaseContainer* const bc = child->GetDataInstance();
			if (!bc)
				continue;

			if (bc->GetInt32(RIGID_RELATED_BONE_INDEX) != bone_index)
				continue;

			const auto op_mode = static_cast<libmmd::PMXRigidbody::Operation>(bc->GetInt32(RIGID_PHYSICS_MODE));
			if (op_mode == libmmd::PMXRigidbody::Operation::Dynamic)
				return true;
		}

		return false;
	}

	void AppendMorphTracksToVmd(BaseObject* object, const maxon::PointerArray<IMorph>& morphs, const CMTToolsSetting::MotionExport& setting, libmmd::VMDFile& vmd_motion)
	{
		if (!object || !setting.export_morph)
		{
			vmd_motion.m_morphs.clear();
			return;
		}

		for (Int32 i = 0; i < morphs.GetCount(); ++i)
		{
			auto& morph = const_cast<IMorph&>(morphs[i]);
			CTrack* const track = object->FindCTrack(morph.GetStrengthDescID());
			if (!track)
				continue;

			CCurve* const curve = track->GetCurve();
			if (!curve)
				continue;

			const std::string sjis_name = ConvertStringToSjis(morph.GetName());
			const Int32 key_count = curve->GetKeyCount();
			for (Int32 key_index = 0; key_index < key_count; ++key_index)
			{
				const CKey* const key = curve->GetKey(key_index);
				if (!key)
					continue;

				libmmd::VMDMorph morph_key;
				morph_key.m_blendShapeName.Set(sjis_name.c_str());
				morph_key.m_frame = static_cast<UInt32>(std::max(0, key->GetTime().GetFrame(kModelAnimationFps) + static_cast<Int32>(setting.time_offset)));
				morph_key.m_weight = static_cast<float>(key->GetValue());
				vmd_motion.m_morphs.push_back(std::move(morph_key));
			}
		}

		std::sort(vmd_motion.m_morphs.begin(), vmd_motion.m_morphs.end(), [](const libmmd::VMDMorph& lhs, const libmmd::VMDMorph& rhs)
		{
			if (lhs.m_blendShapeName.ToString() == rhs.m_blendShapeName.ToString())
				return lhs.m_frame < rhs.m_frame;
			return lhs.m_blendShapeName.ToString() < rhs.m_blendShapeName.ToString();
		});
	}

	void AppendMorphSlotToVmd(const MorphAnimationSlotData* slot, const maxon::HashMap<String, Int>& morph_lookup, const CMTToolsSetting::MotionExport& setting, libmmd::VMDFile& vmd_motion)
	{
		if (!slot || !setting.export_morph)
		{
			vmd_motion.m_morphs.clear();
			return;
		}

		for (const auto& keyframe : slot->keyframes)
		{
			if (!morph_lookup.Find(keyframe.morph_name))
				continue;

			libmmd::VMDMorph morph_key;
			morph_key.m_blendShapeName.Set(ConvertStringToSjis(keyframe.morph_name).c_str());
			morph_key.m_frame = static_cast<UInt32>(std::max(0, keyframe.frame + static_cast<Int32>(setting.time_offset)));
			morph_key.m_weight = keyframe.weight;
			vmd_motion.m_morphs.push_back(std::move(morph_key));
		}

		std::sort(vmd_motion.m_morphs.begin(), vmd_motion.m_morphs.end(), [](const libmmd::VMDMorph& lhs, const libmmd::VMDMorph& rhs)
		{
			if (lhs.m_blendShapeName.ToString() == rhs.m_blendShapeName.ToString())
				return lhs.m_frame < rhs.m_frame;
			return lhs.m_blendShapeName.ToString() < rhs.m_blendShapeName.ToString();
		});
	}

	void AppendIKTracksToVmd(BaseObject* object, const StandaloneIKManager* ik_manager, const maxon::BaseArray<maxon::Pair<DescID, Int>>& dynamic_params, const CMTToolsSetting::MotionExport& setting, libmmd::VMDFile& vmd_motion)
	{
		if (!object || !ik_manager)
		{
			vmd_motion.m_iks.clear();
			return;
		}

		std::map<UInt32, std::map<std::string, uint8_t>> ik_frames;
		for (const auto& param : dynamic_params)
		{
			const auto solver_index = static_cast<size_t>(param.second);
			libmmd::MMDIkSolver* const solver = ik_manager->GetMMDIKSolver(solver_index);
			if (!solver)
				continue;

			CTrack* const track = object->FindCTrack(param.first);
			if (!track)
				continue;

			CCurve* const curve = track->GetCurve(CCURVE::CURVE, false);
			if (!curve)
				continue;

			const Int32 key_count = curve->GetKeyCount();
			for (Int32 key_index = 0; key_index < key_count; ++key_index)
			{
				const CKey* const key = curve->GetKey(key_index);
				if (!key)
					continue;

				const UInt32 frame = static_cast<UInt32>(std::max(0, key->GetTime().GetFrame(kModelAnimationFps) + static_cast<Int32>(setting.time_offset)));
				ik_frames[frame][ConvertUtf8ToSjis(solver->GetName())] = key->GetValue() >= 0.5 ? 1 : 0;
			}
		}

		vmd_motion.m_iks.clear();
		for (const auto& [frame, infos] : ik_frames)
		{
			libmmd::VMDIk ik;
			ik.m_frame = frame;
			ik.m_show = 1;
			for (const auto& [name, enabled] : infos)
			{
				libmmd::VMDIkInfo info;
				info.m_name.Set(name.c_str());
				info.m_enable = enabled;
				ik.m_ikInfos.push_back(std::move(info));
			}
			vmd_motion.m_iks.push_back(std::move(ik));
		}
	}
}

Bool AnimationSlotMetadata::Read(HyperFile* hf)
{
	return hf->ReadString(&name) && hf->ReadInt32(&max_frame);
}

Bool AnimationSlotMetadata::Write(HyperFile* hf) const
{
	return hf->WriteString(name) && hf->WriteInt32(max_frame);
}

Bool AnimationSlotMetadata::CopyTo(AnimationSlotMetadata& dest) const
{
	dest.name = name;
	dest.max_frame = max_frame;
	return true;
}

Bool MorphAnimationKeyframeData::Read(HyperFile* hf)
{
	IOReadField(morph_name);
	IOReadField(frame);
	IOReadField(weight);
	return true;
}

Bool MorphAnimationKeyframeData::Write(HyperFile* hf) SDK2024_Const
{
	IOWriteField(morph_name);
	IOWriteField(frame);
	IOWriteField(weight);
	return true;
}

Bool MorphAnimationSlotData::Read(HyperFile* hf)
{
	return io_util::ReadLinearContainer(hf, keyframes);
}

Bool MorphAnimationSlotData::Write(HyperFile* hf) SDK2024_Const
{
	return io_util::WriteLinearContainer(hf, keyframes);
}

MorphAnimationSlotData::MorphAnimationSlotData(const MorphAnimationSlotData& other)
{
	iferr(keyframes.CopyFrom(other.keyframes)) {}
}

MorphAnimationSlotData& MorphAnimationSlotData::operator=(const MorphAnimationSlotData& other)
{
	if (this == &other)
		return *this;

	iferr(keyframes.CopyFrom(other.keyframes))
	{
		iferr(keyframes.Resize(0)) {}
	}
	return *this;
}

Bool EditorSubMorphDialog::CreateLayout()
{
	iferr_scope_handler{
		return false;
	};

	SetTitle(GeLoadString(IDS_MORPH_EDITOR));
	m_images = ImagesUserAreaRef::Create("mmd_tool_title.png"_s, 300, 95) iferr_return;
	if (C4DGadget* user_area_gadget = AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(95));
		user_area_gadget != nullptr)
		AttachUserArea(*m_images, user_area_gadget);
	GroupBegin(1000, BFH_CENTER, 3, 1, ""_s, 0, 0, 150);
		AddListView(10004, BFH_LEFT, 350, 150);
		m_listview.AttachListView(this, 10004);
		AddButton(10005, BFH_LEFT, 30, 10, ">>"_s);
		m_id = 20000;
		auto* sub_morph_data = m_morph->GetSubMorphDataWritable();
		if (sub_morph_data == nullptr) {
			Close();
			return false;
		}
		ScrollGroupBegin(1002, BFH_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 350, 150);
			GroupBegin(1003, BFH_CENTER, 1, 0, ""_s, 0, 350, 150);
				for (auto& data : *sub_morph_data)
				{
					const auto sub_morph_id = data.GetKey();
					if(const auto morph_count = m_model->GetMorphNum(); morph_count >= sub_morph_id)
						continue;
					GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
					AddStaticText(m_id++, BFH_LEFT, 150, 10, m_model->GetMorphData()[sub_morph_id].GetName(), BORDER_NONE);
					AddEditNumber(m_id, BFH_LEFT, 150, 10);
					SetFloat(m_id++, data.GetValue());
					AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
					iferr(m_delete_button_id.Insert(m_id++))
						return false;
					GroupEnd();

				}
			GroupEnd();
		GroupEnd();
	GroupEnd();
	GroupBegin(1004, BFH_CENTER, 2, 1, ""_s, 0, 0, 20);
		GroupSpace(50, 0);
		AddButton(10002, BFH_LEFT, 80, 20, GeLoadString(IDS_MSG_RENAME_OK));
		AddButton(10003, BFH_RIGHT, 80, 20, GeLoadString(IDS_MSG_RENAME_CANCEL));
	GroupEnd();
	return true;
}

Bool EditorSubMorphDialog::InitValues()
{
	BaseContainer layout;
	layout.SetInt32(COL_NAME, LV_COLUMN_TEXT);
	m_listview.SetLayout(1, layout);
	m_listview.SetProperty(SLV_MULTIPLESELECTION, true);
	Int32 line = 0;
	const auto& morph_data = m_model->GetMorphData();
	for (const auto& data : morph_data)
	{
		if (const String& name = data.GetName(); name != m_morph->GetName()) {
			BaseContainer bc;
			bc.SetString(COL_NAME, name);
			m_listview.SetItem(line++, bc);
		}
	}
	m_listview.DataChanged();
	return true;
}

Bool EditorSubMorphDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
	// RENAME_OK
	case 10002:
	{
		auto* sub_morph_data = m_morph->GetSubMorphDataWritable();
		if (sub_morph_data == nullptr) {
			Close();
			return false;
		}
		sub_morph_data->Reset();
		for (auto& delete_button_id : m_delete_button_id)
		{
			String name;
			Float weight = 0;
			GetString(delete_button_id - 2, name);
			GetFloat(delete_button_id - 1, weight);
			if(const auto id_ptr = m_model->GetMorphNameMap().Find(name); id_ptr)
				m_morph->AddSubMorph(m_model, id_ptr->GetValue(), weight);
		}
		Close();
		break;
	}
	// RENAME_CANCEL
	case 10003:
	{
		Close();
		break;
	}
	case 10005:
	{
		BaseSelect* select = BaseSelect::Alloc();
		m_listview.GetSelection(select);
		BaseContainer bc;
		Int32 seg = 0, a, b;
		maxon::BaseList<maxon::Pair<String, Float>> tmp;
		for (auto& delete_button_id : m_delete_button_id)
		{
			auto& tmp_data = tmp.Append().GetValue();
			GetString(delete_button_id - 2, tmp_data.first);
			GetFloat(delete_button_id - 1, tmp_data.second);
		}
		m_delete_button_id.Reset();
		// begin layout change and store data
		UpdateDialogHelper update_dialog = BeginLayoutChange(1003, true);
		for (auto& tmp_data : tmp)
		{
			GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
			AddStaticText(m_id++, BFH_LEFT, 150, 10, tmp_data.first, BORDER_NONE);
			AddEditNumber(m_id, BFH_LEFT, 150, 10);
			SetFloat(m_id++, tmp_data.second);
			AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
			iferr(m_delete_button_id.Insert(m_id++))
			{
				GroupEnd();
				return false;
			}
			GroupEnd();
		}
		while (select->GetRange(seg++, LIMIT<Int32>::MAX, &a, &b))
		{
			for (Int32 item = a; item <= b; ++item)
			{
				if (m_listview.GetItem(item, &bc) == false)
					continue;
				GroupBegin(m_id++, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
				AddStaticText(m_id++, BFH_LEFT, 150, 10, bc.GetString(COL_NAME), BORDER_NONE);
				AddEditNumber(m_id, BFH_LEFT, 150, 10);
				SetFloat(m_id++, 1.0);
				AddButton(m_id, BFH_LEFT, 32, 10, GeLoadString(IDS_DELETE));
				if (m_listview.RemoveItem(item) == false)
				{
					GroupEnd();
					continue;
				}
				iferr(m_delete_button_id.Insert(m_id++))
					return false;
				GroupEnd();
			}
		}
		// update group
		update_dialog.CommitChanges();
		//LayoutChanged(1003);
		m_listview.DataChanged();
		break;
	}
	default:
		if (m_delete_button_id.Find(id) != nullptr)
		{
			String name;
			RemoveElement(id);
			RemoveElement(id - 1);
			GetString(id - 2, name);
			RemoveElement(id - 2);
			RemoveElement(id - 3);
			BaseContainer data;
			data.SetString(10000, name);
			m_listview.SetItem(m_listview.GetItemCount(), data);
			m_listview.DataChanged();
			LayoutChanged(1003);
			m_delete_button_id.Erase(id);
		}
		break;
	}
	return true;
}

MMDModelManagerObject::AddMorphHelper::AddMorphHelper(MMDModelManagerObject* model):m_model(model)
{
	*m_model->update_morph_.Write() = false;
	*m_model->is_morph_initialized_.Write() = false;
}

MMDModelManagerObject::AddMorphHelper::~AddMorphHelper()
{
	*m_model->update_morph_.Write() = true;
}

SDK2024_Init(MMDModelManagerObject)
{
	if (node == nullptr)
		return false;
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
		return false;
	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_O_MMD_MODEL_MANAGER));
	bc->SetFloat(PMX_VERSION, 2.0);
	bc->SetString(MODEL_NAME_LOCAL, "model"_s);
	bc->SetString(MODEL_NAME_UNIVERSAL, "model"_s);
	bc->SetString(COMMENTS_LOCAL, "description"_s);
	bc->SetString(COMMENTS_UNIVERSAL, "description"_s);
	bc->SetFloat(MODEL_POSITION_MULTIPLE, 8.5);
	bc->SetInt32(MODEL_MODE, model_mode_);
	bc->SetBool(MODEL_PHYSICS_ENABLED, true);
	bc->SetFloat(MODEL_PHYSICS_GRAVITY_STRENGTH, 98.0);
	bc->SetVector(MODEL_PHYSICS_GRAVITY_DIRECTION, Vector(0, -1, 0));
	bc->SetBool(MODEL_PHYSICS_RESET_ON_SEEK, true);
	bc->SetInt32(MODEL_ANIM_LIST, -1);
	bc->SetInt32(MODEL_MATERIAL_LIST, MODEL_MATERIAL_NONE);
	iferr(animation_slot_metadata_.Resize(0))
		return false;
	RefreshAnimationSlotItems();
	ConfigureModelManagerExecutionPriority(node);
	return true;
}

template<>
bool inline io_util::ReadData<maxon::Pair<MMDModelRootDynamicDescriptionType, Int>>(HyperFile* hf, maxon::Pair<MMDModelRootDynamicDescriptionType, Int>& data)
{
	UChar type = 0;
	if (!ReadData(hf, type))
		return false;
	data.first = static_cast<MMDModelRootDynamicDescriptionType>(type);

	if (!ReadData(hf, data.second))
		return false;
	return true;
}

template<>
bool inline io_util::WriteData<maxon::Pair<MMDModelRootDynamicDescriptionType, Int>>(HyperFile* hf, const maxon::Pair<MMDModelRootDynamicDescriptionType, Int>& data)
{
	if (!WriteData(hf, static_cast<UChar>(data.first)))
		return false;
	if (!WriteData(hf, data.second))
		return false;
	return true;
}

Bool MMDModelManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level) {
	iferr_scope_handler
	{
		return false;
	};
	IOReadField(bone_manager_);
	IOReadField(mesh_manager_);
	IOReadField(rigid_manager_);
	IOReadField(joint_manager_);

	*is_manager_read_.Write() = true;

	IOReadField(morph_named_number_);

	if (!io_util::ReadHashMap(hf, desc_id_map_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at desc_id_map_");
		return false;
	}

	if (!io_util::ReadHashMap(hf, morph_name_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at morph_name_");
		return false;
	}

	if (!ReadMorph(hf))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at ReadMorph");
		return false;
	}
	Int64 mat_count = 0;
	if (hf->ReadInt64(&mat_count) && mat_count >= 0 && mat_count <= 10000)
	{
		iferr(material_list_.Resize(0))
			return false;
		for (Int64 i = 0; i < mat_count; ++i)
		{
			MMDMaterialData mat;
			if (!mat.Read(hf))
			{
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at material @", i);
				return false;
			}
			iferr(material_list_.Append(std::move(mat)))
				return false;
		}
	}
	else
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: mat_count read failed or invalid (@)", mat_count);
	}

	Int64 df_count = 0;
	if (hf->ReadInt64(&df_count) && df_count >= 0 && df_count <= 10000)
	{
		iferr(display_frame_list_.Resize(0))
			return false;
		for (Int64 i = 0; i < df_count; ++i)
		{
			DisplayFrameData df;
			if (!df.Read(hf))
			{
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at display frame @", i);
				return false;
			}
			iferr(display_frame_list_.Append(std::move(df)))
				return false;
		}
	}
	else
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: df_count read failed or invalid (@)", df_count);
	}

	if (!io_util::ReadHashMap(hf, ik_solver_enable_states_))
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: FAILED at ik_solver_enable_states_");
		return false;
	}

	animation_items_.FlushAll();
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	animation_index_ = -1;
	iferr(animation_slot_metadata_.Resize(0))
		return false;

	Int32 anim_idx = -1;
	if (hf->ReadInt32(&anim_idx))
	{
		Int64 anim_count = 0;
		if (hf->ReadInt64(&anim_count) && anim_count >= 0 && anim_count <= 10000)
		{
			if (!EnsureAnimationSlotCount(static_cast<Int32>(anim_count)))
				return false;
			if (anim_idx >= static_cast<Int32>(anim_count))
				anim_idx = -1;
			animation_index_ = anim_idx;

			for (Int64 i = 0; i < anim_count; ++i)
			{
				String name;
				if (!hf->ReadString(&name))
				{
					DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read name at index @", i);
					break;
				}

				Int64 size = 0;
				if (!hf->ReadInt64(&size))
				{
					DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read size at index @", i);
					break;
				}

				if (size > 0)
				{
					void* mem = nullptr;
					Int mem_size = 0;
					if (!hf->ReadMemory(&mem, &mem_size))
					{
						DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Read: failed to read memory at index @, expected size=@", i, size);
						break;
					}
					DeleteMem(mem);
				}

				animation_slot_metadata_[static_cast<Int32>(i)].name = name;
				animation_slot_metadata_[static_cast<Int32>(i)].max_frame = 0;
			}
		}
	}

	*is_morph_initialized_.Write() = true;

	// Level 1: IK dynamic DescID list (parallel to desc_id_map_; level 0 files rebuild from map).
	if (level >= 1)
	{
		Int64 ik_cnt = 0;
		if (!hf->ReadInt64(&ik_cnt) || ik_cnt < 0 || ik_cnt > 10000)
			return false;
		iferr(ik_solver_dynamic_params_.Resize(0)) {}
		for (Int64 i = 0; i < ik_cnt; ++i)
		{
			DescID did;
			if (!did.Read(hf))
				return false;
			Int32 idx = 0;
			if (!hf->ReadInt32(&idx))
				return false;
			iferr(ik_solver_dynamic_params_.Append(maxon::Pair<DescID, Int>(std::move(did), idx))) {}
		}
	}
	else
	{
		SyncIKSolverDynamicParamsFromDescMap();
	}

	if (level >= 2)
	{
		Int64 slot_count = 0;
		if (!hf->ReadInt64(&slot_count) || slot_count < 0 || slot_count > 10000)
			return false;
		if (!EnsureAnimationSlotCount(static_cast<Int32>(slot_count)))
			return false;
		for (Int64 i = 0; i < slot_count; ++i)
		{
			AnimationSlotMetadata metadata;
			if (!metadata.Read(hf))
				return false;
			animation_slot_metadata_[static_cast<Int32>(i)] = std::move(metadata);
		}
	}

	if (level >= 3)
	{
		Int64 morph_slot_count = 0;
		if (!hf->ReadInt64(&morph_slot_count) || morph_slot_count < 0 || morph_slot_count > 10000)
			return false;
		if (!EnsureMorphAnimationSlotCount(static_cast<Int32>(morph_slot_count)))
			return false;
		for (Int64 i = 0; i < morph_slot_count; ++i)
		{
			if (!morph_animation_slots_[static_cast<Int32>(i)].Read(hf))
				return false;
		}
	}

	if (!EnsureMorphAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount())))
		return false;

	if (animation_slot_metadata_.IsEmpty())
		animation_index_ = -1;
	else if (animation_index_ < -1)
		animation_index_ = -1;
	else if (animation_index_ >= animation_slot_metadata_.GetCount())
		animation_index_ = static_cast<Int32>(animation_slot_metadata_.GetCount() - 1);
	if (BaseContainer* const bc = node ? reinterpret_cast<BaseList2D*>(node)->GetDataInstance() : nullptr)
	{
		model_mode_ = NormalizeModelMode(bc->GetInt32(MODEL_MODE));
		bc->SetInt32(MODEL_MODE, model_mode_);
	}
	else
	{
		model_mode_ = NormalizeModelMode(model_mode_);
	}
	if (model_mode_ != MODEL_MODE_EDIT)
		ClearMorphAnimationSlots();
	RefreshAnimationSlotItems();
	ConfigureModelManagerExecutionPriority(node);

	InvalidateStandaloneRuntime();

	return true;
}
SDK2024_Write(MMDModelManagerObject) {

	IOWriteField(bone_manager_);
	IOWriteField(mesh_manager_);
	IOWriteField(rigid_manager_);
	IOWriteField(joint_manager_);
	IOWriteField(morph_named_number_);

	if (!io_util::WriteHashMap(hf, desc_id_map_))
		return false;

	if (!io_util::WriteHashMap(hf, morph_name_))
		return false;

	if (!WriteMorph(hf))
		return false;
	if (!hf->WriteInt64(material_list_.GetCount()))
		return false;
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		if (!material_list_[i].Write(hf))
			return false;
	if (!hf->WriteInt64(display_frame_list_.GetCount()))
		return false;
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
		if (!display_frame_list_[i].Write(hf))
			return false;

	if (!io_util::WriteHashMap(hf, ik_solver_enable_states_))
		return false;

	if (!hf->WriteInt32(animation_index_))
		return false;
	const auto anim_count = static_cast<Int64>(animation_slot_metadata_.GetCount());
	if (!hf->WriteInt64(anim_count))
		return false;
	for (Int32 i = 0; i < animation_slot_metadata_.GetCount(); ++i)
	{
		const String name = animation_slot_metadata_[i].name;
		if (!hf->WriteString(name))
			return false;

		if (!hf->WriteInt64(0))
			return false;
	}

	// Level 1 IK block; Read when @p level >= 1 (matches RegisterObjectPlugin disklevel 1).
	if (!hf->WriteInt64(static_cast<Int64>(ik_solver_dynamic_params_.GetCount())))
		return false;
	for (const auto& p : ik_solver_dynamic_params_)
	{
		if (!const_cast<DescID&>(p.first).Write(hf))
			return false;
		if (!hf->WriteInt32(static_cast<Int32>(p.second)))
			return false;
	}

	if (!hf->WriteInt64(static_cast<Int64>(animation_slot_metadata_.GetCount())))
		return false;
	for (const auto& slot : animation_slot_metadata_)
	{
		if (!slot.Write(hf))
			return false;
	}

	const auto* self = this;
	if (model_mode_ == MODEL_MODE_EDIT)
	{
		if (!const_cast<MMDModelManagerObject*>(self)->EnsureMorphAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount())))
			return false;
		if (!hf->WriteInt64(static_cast<Int64>(morph_animation_slots_.GetCount())))
			return false;
		for (const auto& slot : morph_animation_slots_)
		{
			if (!io_util::WriteData(hf, slot))
				return false;
		}
	}
	else
	{
		if (!hf->WriteInt64(0))
			return false;
	}

	return true;
}
SDK2024_CopyTo(MMDModelManagerObject)
{
	const auto destObject = reinterpret_cast<MMDModelManagerObject*>(dest);
	destObject->model_mode_ = model_mode_;
	if (bone_manager_)
		bone_manager_->CopyTo(destObject->bone_manager_, flags, trn);
	if (joint_manager_)
		joint_manager_->CopyTo(destObject->joint_manager_, flags, trn);
	if (rigid_manager_)
		rigid_manager_->CopyTo(destObject->rigid_manager_, flags, trn);
	if (mesh_manager_)
		mesh_manager_->CopyTo(destObject->mesh_manager_, flags, trn);
	iferr(destObject->desc_id_map_.CopyFrom(desc_id_map_))
		return false;
	iferr(destObject->ik_solver_dynamic_params_.CopyFrom(ik_solver_dynamic_params_))
		return false;
	iferr(destObject->morph_name_.CopyFrom(morph_name_))
		return false;
	if (!CopyMorph(destObject))
		return false;
	iferr(destObject->material_list_.Resize(0))
		return false;
	destObject->material_selection_index_ = material_selection_index_;
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
	{
		MMDMaterialData copy;
		if (!material_list_[i].CopyTo(copy))
			return false;
		iferr(destObject->material_list_.Append(std::move(copy)))
			return false;
	}
	iferr(destObject->display_frame_list_.Resize(0))
		return false;
	destObject->display_frame_selection_index_ = display_frame_selection_index_;
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
	{
		DisplayFrameData copy;
		if (!display_frame_list_[i].CopyTo(copy))
			return false;
		iferr(destObject->display_frame_list_.Append(std::move(copy)))
			return false;
	}

	iferr(destObject->ik_solver_enable_states_.CopyFrom(ik_solver_enable_states_))
		return false;

	destObject->animation_index_ = animation_index_;
	destObject->animation_items_ = animation_items_;
	if (!destObject->EnsureAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount())))
		return false;
	for (Int32 i = 0; i < animation_slot_metadata_.GetCount(); ++i)
	{
		if (!animation_slot_metadata_[i].CopyTo(destObject->animation_slot_metadata_[i]))
			return false;
	}
	if (!destObject->EnsureMorphAnimationSlotCount(static_cast<Int32>(morph_animation_slots_.GetCount())))
		return false;
	for (Int32 i = 0; i < morph_animation_slots_.GetCount(); ++i)
		destObject->morph_animation_slots_[i] = morph_animation_slots_[i];
	destObject->InvalidateStandaloneRuntime();
	return true;
}
Bool MMDModelManagerObject::ReadMorph(HyperFile* hf)
{
	iferr_scope_handler{ return false; };
	auto morph_change_helper = BeginMorphChange();
	Int data_count = 0;
	if (!hf->ReadInt64(&data_count))
		return false;
	for (Int i = 0; i < data_count; ++i)
	{
		MMDMorphType type;
		if (!hf->ReadUChar(reinterpret_cast<UChar*>(&type)))
			return false;

		IMorph* morph = nullptr;
		switch (type)
		{
		case MMDMorphType::GROUP:    morph = NewObj(GroupMorph) iferr_return; break;
		case MMDMorphType::FLIP:     morph = NewObj(FlipMorph) iferr_return; break;
		case MMDMorphType::MESH:     morph = NewObj(MeshMorph) iferr_return; break;
		case MMDMorphType::UV:       morph = NewObj(UVMorph) iferr_return; break;
		case MMDMorphType::BONE:     morph = NewObj(BoneMorph) iferr_return; break;
		case MMDMorphType::MATERIAL: morph = NewObj(MaterialMorph) iferr_return; break;
		case MMDMorphType::IMPULSE:  morph = NewObj(ImpulseMorph) iferr_return; break;
		default: return false;
		}
		morph_data_.AppendPtr(morph) iferr_return;
		morph->Read(hf);
	}

	return true;
}
Bool MMDModelManagerObject::WriteMorph(HyperFile* hf) SDK2024_Const
{
	if (!hf->WriteInt64(morph_data_.GetCount()))
		return false;
	if(!std::all_of(morph_data_.Begin(), morph_data_.End(), [&](SDK2024_Const IMorph& i)
	{
			// Write morph type
		return hf->WriteUChar(static_cast<UChar>(i.GetType()))
			// Write morph data
			&& i.Write(hf);
	}))
		return false;

	return true;
}
Bool MMDModelManagerObject::CopyMorph(MMDModelManagerObject* dst) const
{
	if(!dst)
		return false;
	iferr_scope_handler{ return false; };
	for (const auto& morph : morph_data_)
	{
		const auto& new_morph_name = morph.GetName();
		const auto new_morph_index = dst->AddMorph(morph.GetType(), new_morph_name, false);
		const auto new_morph = &dst->morph_data_[new_morph_index];
		if (!morph.CopyTo(new_morph))
			return true;
		new_morph->AddMorphUI(*dst, new_morph_index);
		if (GeListNode* const dst_node = dst->Get())
		{
			Float src_strength = 0.0;
			if (GeListNode* const src_node = const_cast<MMDModelManagerObject*>(this)->Get())
				src_strength = morph.GetStrength(src_node);
			new_morph->SetStrength(dst_node, src_strength);
		}
	}
	return true;
}

MMDModelManagerObject::AddMorphHelper MMDModelManagerObject::BeginMorphChange()
{
	return AddMorphHelper{this};
}

MMDModelManagerObject::MMDModelManagerObject() : update_morph_(true), is_morph_initialized_(false), is_manager_read_(false), is_runtime_initialized_(false)
{
}

Bool MMDModelManagerObject::EnsureMorphAnimationSlotCount(const Int32 slot_count)
{
	iferr_scope_handler
	{
		return false;
	};

	if (slot_count <= 0)
	{
		iferr(morph_animation_slots_.Resize(0))
			return false;
		return true;
	}

	iferr(morph_animation_slots_.Resize(slot_count))
		return false;
	return true;
}

void MMDModelManagerObject::ClearMorphAnimationSlots()
{
	iferr(morph_animation_slots_.Resize(0)) {}
}

Bool MMDModelManagerObject::EnsureAnimationSlotCount(const Int32 slot_count)
{
	iferr_scope_handler
	{
		return false;
	};

	if (slot_count <= 0)
	{
		iferr(animation_slot_metadata_.Resize(0))
			return false;
		if (!EnsureMorphAnimationSlotCount(0))
			return false;
		animation_index_ = -1;
		RefreshAnimationSlotItems();
		return true;
	}

	iferr(animation_slot_metadata_.Resize(slot_count))
		return false;
	if (!EnsureMorphAnimationSlotCount(slot_count))
		return false;

	if (animation_index_ >= slot_count)
		animation_index_ = slot_count - 1;
	return true;
}

Bool MMDModelManagerObject::SetAnimationSlotMetadata(const Int32 slot_index, const String& name, const Int32 max_frame)
{
	if (slot_index < 0)
		return false;
	if (!EnsureAnimationSlotCount(slot_index + 1))
		return false;

	animation_slot_metadata_[slot_index].name = name;
	animation_slot_metadata_[slot_index].max_frame = std::max(0, max_frame);
	RefreshAnimationSlotItems();
	return true;
}

void MMDModelManagerObject::RefreshAnimationSlotItems()
{
	animation_items_.FlushAll();
	animation_items_.SetString(-1, GeLoadString(IDS_CMT_VMD_ANIM_NONE));
	for (Int32 i = 0; i < animation_slot_metadata_.GetCount(); ++i)
	{
		const String label = animation_slot_metadata_[i].name.IsEmpty()
			? FormatString("Animation @", i)
			: animation_slot_metadata_[i].name;
		animation_items_.SetString(i, label);
	}
}

Int32 MMDModelManagerObject::GetAnimationSlotMaxFrame(const Int32 slot_index) const
{
	if (slot_index < 0 || slot_index >= animation_slot_metadata_.GetCount())
		return 0;
	return std::max(0, animation_slot_metadata_[slot_index].max_frame);
}

void MMDModelManagerObject::ApplyAnimationSlotSelection(BaseDocument* doc)
{
	if (animation_slot_metadata_.IsEmpty())
	{
		animation_index_ = -1;
	}
	else if (animation_index_ < -1)
	{
		animation_index_ = -1;
	}
	else if (animation_index_ >= animation_slot_metadata_.GetCount())
	{
		animation_index_ = static_cast<Int32>(animation_slot_metadata_.GetCount() - 1);
	}

	if (!bone_manager_data_)
		bone_manager_data_ = GetBoneManagerData();

	if (GeListNode* const node = Get())
	{
		MMDModelManagerObjectMsg msg(MMDModelManagerObjectMsgType::ACTIVE_ANIMATION_SLOT_CHANGE, nullptr, model_mode_, animation_index_);
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_model_manager_object_id, &msg);
	}

	if (bone_manager_data_)
	{
		bone_manager_data_->SetAllActiveAnimationSlot(animation_index_);
	}

	if (doc)
	{
		doc->SetTime(BaseTime());
		if (animation_index_ >= 0)
		{
			const BaseTime max_time(static_cast<Float>(GetAnimationSlotMaxFrame(animation_index_)), kModelAnimationFps);
			doc->SetMaxTime(max_time);
			doc->SetLoopMaxTime(max_time);
		}
		else
		{
			doc->SetMaxTime(BaseTime());
			doc->SetLoopMaxTime(BaseTime());
		}
	}

	if (GeListNode* const node = Get())
		node->SetDirty(DIRTYFLAGS::DESCRIPTION);

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

void MMDModelManagerObject::RefreshMorph()
{
	for (auto it = maxon::Iterable::EraseIterator(morph_data_); it; ++it)
	{
		DeleteMorph(it);
	}
	auto* mesh_mgr = io_util::ResolveObjectLink(mesh_manager_);
	if (!mesh_mgr) return;
	auto* mesh_manager_data = mesh_mgr->GetNodeData<MMDMeshManagerObject>();
	auto& mesh_morph_map = mesh_manager_data->GetMeshMorphData();
	const auto& uv_morph_names = mesh_manager_data->GetUVMorphNames();
	for (auto& name : mesh_morph_map.GetKeys())
	{
		const auto morph_type = uv_morph_names.Find(name) ? MMDMorphType::UV : MMDMorphType::MESH;
		AddMorph(morph_type, name);
	}
	if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
	{
		auto& bone_morph_map = bone_mgr->GetNodeData<MMDBoneManagerObject>()->GetBoneMorphMap();
		for (auto& name : bone_morph_map.GetKeys())
		{
			AddMorph(MMDMorphType::BONE, name);
		}
	}
}

void MMDModelManagerObject::SyncMorphSlidersFromTags()
{
	if (!mesh_manager_data_)
		return;
	GeListNode* node = Get();
	if (!node)
		return;
	for (auto& morph : morph_data_)
	{
		const auto type = morph.GetType();
		if (type != MMDMorphType::MESH && type != MMDMorphType::UV)
			continue;
		Float tag_strength = 0.0;
		if (mesh_manager_data_->GetMorphStrength(morph.GetName(), tag_strength))
			morph.SetStrength(node, tag_strength);
	}
}

void MMDModelManagerObject::CaptureAndClearPMXExportMorphState(BaseDocument* doc)
{
	BaseObject* const self = reinterpret_cast<BaseObject*>(Get());
	if (!self)
		return;

	pmx_export_morph_strength_snapshot_.clear();
	pmx_export_morph_strength_snapshot_.reserve(static_cast<size_t>(morph_data_.GetCount()));
	for (auto& morph : morph_data_)
		pmx_export_morph_strength_snapshot_.push_back(morph.GetStrength(self));
	pmx_export_has_morph_state_snapshot_ = true;

	for (auto& morph : morph_data_)
		morph.SetStrength(self, 0.0);

	if (mesh_manager_data_ || GetMeshManagerData())
		mesh_manager_data_->ResetMorphStrengths(io_util::ResolveObjectLink(mesh_manager_));
	if (bone_manager_data_ || GetBoneManagerData())
		bone_manager_data_->ResetMorphStrengths();

	ApplyMorphRuntimeStrengths();

	*update_morph_.Write() = true;
	MarkMeshHierarchyDirty(GetMeshManagerObject());
	self->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
	self->Message(MSG_UPDATE);
	(void)doc;
}

void MMDModelManagerObject::RestorePMXExportMorphState(BaseDocument* doc)
{
	BaseObject* const self = reinterpret_cast<BaseObject*>(Get());
	if (!self || !pmx_export_has_morph_state_snapshot_)
		return;

	if (mesh_manager_data_ || GetMeshManagerData())
		mesh_manager_data_->ResetMorphStrengths(io_util::ResolveObjectLink(mesh_manager_));
	if (bone_manager_data_ || GetBoneManagerData())
		bone_manager_data_->ResetMorphStrengths();

	const Int32 restore_count = std::min<Int32>(
		static_cast<Int32>(pmx_export_morph_strength_snapshot_.size()),
		static_cast<Int32>(morph_data_.GetCount()));
	for (Int32 i = 0; i < restore_count; ++i)
		morph_data_[i].SetStrength(self, pmx_export_morph_strength_snapshot_[static_cast<size_t>(i)]);

	ApplyMorphRuntimeStrengths();

	pmx_export_morph_strength_snapshot_.clear();
	pmx_export_has_morph_state_snapshot_ = false;
	*update_morph_.Write() = true;
	MarkMeshHierarchyDirty(GetMeshManagerObject());
	self->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
	self->Message(MSG_UPDATE);
	(void)doc;
}

void MMDModelManagerObject::ClearMorphRuntimeForEdit()
{
	BaseObject* const self = reinterpret_cast<BaseObject*>(Get());
	if (!self)
		return;

	if (model_mode_ == MODEL_MODE_ANIM && animation_index_ >= 0)
	{
		if (!CaptureMorphAnimationSlotFromTracks(animation_index_))
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Failed to cache morph animation slot before entering edit mode.");
			return;
		}
	}

	for (auto& morph : morph_data_)
	{
		morph.SetStrength(self, 0.0);
		RemoveParameterTrack(self, morph.GetStrengthDescID());
	}

	ApplyMorphRuntimeStrengths();

	if (mesh_manager_data_)
	{
		mesh_manager_data_->ResetMorphStrengths(io_util::ResolveObjectLink(mesh_manager_));
	}

	if (bone_manager_data_)
		bone_manager_data_->ResetMorphStrengths();

	*update_morph_.Write() = true;
	*is_morph_initialized_.Write() = true;
	self->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA);
	self->Message(MSG_UPDATE);

	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

static void SendObjectUpdateMessage(BaseObject* dst, BaseObject* obj)
{
	MMDModelManagerObjectMsg msg(MMDModelManagerObjectMsgType::MANAGER_OBJECT_UPDATE, obj);
	dst->Message(g_mmd_model_manager_object_id, &msg);
}

Bool MMDModelManagerObject::UpdateManagers(BaseObject* op)
{
	if (!op)
		op = reinterpret_cast<BaseObject*>(Get());
	BaseObject* mesh_manager = nullptr;
	BaseObject* bone_manager = nullptr;
	BaseObject* rigid_manager = nullptr;
	BaseObject* joint_manager = nullptr;
	maxon::Queue<BaseObject*> nodes;
	iferr(nodes.Push(op->GetDown())) return false;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		if (node != nullptr)
		{
			if (node->IsInstanceOf(g_mmd_joint_manager_object_id))
				joint_manager = node;
			else if (node->IsInstanceOf(g_mmd_rigid_manager_object_id))
				rigid_manager = node;
			else if (node->IsInstanceOf(g_mmd_bone_manager_object_id))
				bone_manager = node;
			else if (node->IsInstanceOf(g_mmd_mesh_manager_object_id))
				mesh_manager = node;
			iferr(nodes.Push(node->GetNext())) return false;
		}
	}
	nodes.Reset();
	Bool send_message = false;
	if (!io_util::ResolveObjectLink(bone_manager_)) {
		if (!bone_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			tmp->InsertUnder(op);
			bone_manager_->SetLink(tmp);
		}
		else {
			bone_manager_->SetLink(bone_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(mesh_manager_)) {
		if (!mesh_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			tmp->InsertUnder(op);
			mesh_manager_->SetLink(tmp);
		}
		else {
			mesh_manager_->SetLink(mesh_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(rigid_manager_)) {
		if (!rigid_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			tmp->InsertUnder(op);
			rigid_manager_->SetLink(tmp);
		}
		else {
			rigid_manager_->SetLink(rigid_manager);
		}
		send_message = true;
	}
	if (!io_util::ResolveObjectLink(joint_manager_)) {
		if (!joint_manager)
		{
			BaseObject* tmp = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			tmp->InsertUnder(op);
			joint_manager_->SetLink(tmp);
		}
		else {
			joint_manager_->SetLink(joint_manager);
		}
		send_message = true;
	}
	auto* bone_mgr_obj = io_util::ResolveObjectLink(bone_manager_);
	auto* mesh_mgr_obj = io_util::ResolveObjectLink(mesh_manager_);
	auto* rigid_mgr_obj = io_util::ResolveObjectLink(rigid_manager_);
	auto* joint_mgr_obj = io_util::ResolveObjectLink(joint_manager_);
	bone_manager_data_ = bone_mgr_obj ? bone_mgr_obj->GetNodeData<MMDBoneManagerObject>() : nullptr;
	mesh_manager_data_ = mesh_mgr_obj ? mesh_mgr_obj->GetNodeData<MMDMeshManagerObject>() : nullptr;
	rigid_manager_data_ = rigid_mgr_obj ? rigid_mgr_obj->GetNodeData<MMDRigidManagerObject>() : nullptr;
	joint_manager_data_ = joint_mgr_obj ? joint_mgr_obj->GetNodeData<MMDJointManagerObject>() : nullptr;
	if (send_message)
	{
		if (bone_mgr_obj) SendObjectUpdateMessage(bone_mgr_obj, op);
		if (mesh_mgr_obj) SendObjectUpdateMessage(mesh_mgr_obj, op);
	}
	if (rigid_manager_data_)
	{
		rigid_manager_data_->bone_manager_data_ = bone_manager_data_;
		if (bone_mgr_obj)
			rigid_manager_data_->bone_manager_link_->SetLink(bone_mgr_obj);
	}
	if (joint_manager_data_)
	{
		joint_manager_data_->bone_manager_data_ = bone_manager_data_;
		joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
		if (bone_mgr_obj)
			joint_manager_data_->bone_manager_link_->SetLink(bone_mgr_obj);
		if (auto* rigid_obj = io_util::ResolveObjectLink(rigid_manager_))
			joint_manager_data_->rigid_manager_link_->SetLink(rigid_obj);
	}

	return true;
}

EXECUTIONRESULT MMDModelManagerObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	iferr_scope_handler
	{
		return EXECUTIONRESULT::OK;
	};

	if (op == nullptr || doc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	if (BaseContainer* const bc = op->GetDataInstance())
		model_mode_ = NormalizeModelMode(bc->GetInt32(MODEL_MODE));

	const auto manager_read = *is_manager_read_.Read();

	if (!UpdateManagers(op))
		return EXECUTIONRESULT::OK;

	if (!*is_runtime_initialized_.Read())
	{
		if (bone_manager_data_)
			bone_manager_data_->HandleBoneIndexChangeMessage(io_util::ResolveObjectLink(bone_manager_));

		const Bool runtime_ready = EnsureStandaloneRuntimeManagers();
		if (!runtime_ready)
		{
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] Execute: EnsureStandaloneRuntimeManagers FAILED");
			StatusSetText(GeLoadString(IDS_CMT_VMD_REBUILD_FAILED));
		}
		*is_runtime_initialized_.Write() = runtime_ready;

		if (manager_read)
			*is_manager_read_.Write() = false;
	}
	else if(manager_read)
	{
		if (bone_manager_data_)
			bone_manager_data_->HandleBoneIndexChangeMessage(io_util::ResolveObjectLink(bone_manager_));
		*is_manager_read_.Write() = false;
	}

	if (!*is_morph_initialized_.Read())
	{
		if (mesh_manager_data_)
		{
			if (auto* mesh_mgr_obj = io_util::ResolveObjectLink(mesh_manager_))
				mesh_manager_data_->ForceRefreshMorphData(mesh_mgr_obj);
		}
		RefreshMorph();
		SyncMorphSlidersFromTags();
		*is_morph_initialized_.Write() = true;
	}

	if (*update_morph_.Read())
	{
		ApplyMorphRuntimeStrengths();
	}

	if (model_mode_ == MODEL_MODE_ANIM)
	{
		const auto now_time = doc->GetTime();
		bone_manager_data_ = GetBoneManagerData();
		if (has_transient_vpd_pose_ && now_time != transient_vpd_pose_time_)
			ClearTransientVPDPoseState(doc);
		const Bool time_changed = prev_time_ != now_time;
		const UInt32 control_state_checksum = bone_manager_data_ ? mmd_bone_control_util::GetControlStateChecksum(*bone_manager_data_) : 0;
		const Bool control_state_changed = control_state_checksum != control_state_checksum_;
		const Bool control_delta_active = bone_manager_data_ && mmd_bone_control_util::HasActiveControlDelta(*bone_manager_data_);
		if (time_changed || control_state_changed || control_delta_active)
		{
			fps_ = static_cast<Float32>(doc->GetFps());

			const Float64 time_diff = now_time.Get() - prev_time_.Get();
			const Float64 frame_time = 1.0 / static_cast<Float64>(fps_);
			const Bool reset_on_seek = ShouldResetPhysicsOnSeek(op);
			const Bool needs_physics_reset = !is_animation_initialized_ || now_time == doc->GetMinTime()
				|| (reset_on_seek && (time_diff < frame_time * 0.5 || time_diff > frame_time * 1.5));

			if (!EnsureStandaloneRuntimeManagers())
				return EXECUTIONRESULT::OK;

			ApplyIKSolverFromParameters(op);
			ApplyPhysicsConfigToRuntime(op);
			RunLayeredBonePass(doc, false);

			const Bool physics_enabled = IsPhysicsEnabled(op);
			if (physics_enabled)
			{
				if (time_changed || !is_animation_initialized_)
				{
					if (needs_physics_reset)
						ResetStandalonePhysics();
					else
						StepStandalonePhysics(1.f / fps_);
					is_animation_initialized_ = true;
				}
				RunLayeredBonePass(doc, true);
			}
			else
			{
				is_animation_initialized_ = false;
			}
			if (bone_manager_data_)
				mmd_bone_control_util::SyncControlsToCurrentPose(*bone_manager_data_);
			control_state_checksum_ = bone_manager_data_ ? mmd_bone_control_util::GetControlStateChecksum(*bone_manager_data_) : 0;
			if (time_changed)
				prev_time_ = now_time;
		}
	}
	return EXECUTIONRESULT::OK;
}

Int MMDModelManagerObject::ImportGroupAndFlipMorph(const libmmd::PMXFileMorph& pmx_morph, Int32 panel)
{
	Int morph_id = -1;
	iferr_scope_handler{ return morph_id; };
	switch (pmx_morph.m_morphType)
	{
	case libmmd::PMXMorphType::Group:
	{
		morph_id = AddMorph(MMDMorphType::GROUP, String(pmx_morph.m_name.c_str()), true, panel);
		auto& morph = morph_data_[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_groupMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	case libmmd::PMXMorphType::Flip:
	{
		morph_id = AddMorph(MMDMorphType::FLIP, String(pmx_morph.m_name.c_str()), true, panel);
		auto& morph = morph_data_[morph_id];
		for (const auto& [morph_index, weight] : pmx_morph.m_flipMorph)
		{
			morph.AddSubMorphNoCheck(morph_index, weight);
		}
		break;
	}
	default:
		break;
	}
	return morph_id;
}

DescID MMDModelManagerObject::AddDynamicDescription(const BaseContainer& bc, const MMDModelRootDynamicDescriptionType& type, Int index)
{
	DescID id{};
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return id;
	id = dynamic_description->Alloc(bc);
	iferr(desc_id_map_.Insert(id, { type, index }))
		return id;
	return id;
}

void MMDModelManagerObject::DeleteDynamicDescription(const DescID& id)
{
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return;
	dynamic_description->Remove(id);
	std::ignore = desc_id_map_.Erase(id);
}

void MMDModelManagerObject::StripIKSolverDynamicUI()
{
	DynamicDescription* const dd = Get()->GetDynamicDescriptionWritable();
	if (!dd)
		return;
	for (auto it = desc_id_map_.Begin(); it != desc_id_map_.End(); )
	{
		if (it->GetValue().first == MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
		{
			dd->Remove(it->GetKey());
			it = desc_id_map_.Erase(it);
		}
		else
		{
			++it;
		}
	}
	iferr(ik_solver_dynamic_params_.Resize(0)) {}
}

void MMDModelManagerObject::SyncIKSolverDynamicParamsFromDescMap()
{
	iferr(ik_solver_dynamic_params_.Resize(0)) {}
	for (const auto& entry : desc_id_map_)
	{
		if (entry.GetValue().first != MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE)
			continue;
		iferr(ik_solver_dynamic_params_.Append(maxon::Pair<DescID, Int>(entry.GetKey(), entry.GetValue().second))) {}
	}
}

void MMDModelManagerObject::BuildIKSolverUI()
{
	if (!ik_manager_own_)
		return;
	auto* ik_manager = ik_manager_own_.get();
	if (!ik_manager)
		return;
	StripIKSolverDynamicUI();
	const auto solver_count = ik_manager->GetIKSolverCount();
	for (size_t i = 0; i < solver_count; ++i)
	{
		auto* solver = ik_manager->GetMMDIKSolver(i);
		if (!solver)
			continue;
		const String solver_name(solver->GetName().c_str());
		BaseContainer bc = GetCustomDataTypeDefault(DTYPE_BOOL);
		bc.SetString(DESC_NAME, solver_name);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(ConstDescID(DescLevel(MODEL_IK_GRP))));
		const DescID id = AddDynamicDescription(bc, MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE, static_cast<Int>(i));
		iferr(ik_solver_dynamic_params_.Append(maxon::Pair<DescID, Int>(id, static_cast<Int>(i)))) {}
		Get()->SetParameter(id, GeData(true), DESCFLAGS_SET::NONE);
	}
	ApplyIKSolverStates();
}

void MMDModelManagerObject::ApplyIKSolverStates()
{
	if (!ik_manager_own_)
		return;
	auto* ik_manager = ik_manager_own_.get();
	if (!ik_manager)
		return;
	auto* node = Get();
	for (const auto& p : ik_solver_dynamic_params_)
	{
		auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(p.second));
		if (!solver)
			continue;
		const auto* state_entry = ik_solver_enable_states_.Find(String(solver->GetName().c_str()));
		if (!state_entry)
			continue;
		const Bool enabled = state_entry->GetValue();
		solver->Enable(enabled);
		if (node)
			node->SetParameter(p.first, GeData(enabled), DESCFLAGS_SET::NONE);
	}
}

void MMDModelManagerObject::ApplyIKSolverFromParameters(BaseObject* op)
{
	if (!ik_manager_own_ || !op)
		return;
	auto* ik_manager = ik_manager_own_.get();
	if (!ik_manager)
		return;
	for (const auto& p : ik_solver_dynamic_params_)
	{
		GeData value;
		if (op->GetParameter(p.first, value, DESCFLAGS_GET::NONE))
		{
			if (auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(p.second)))
				solver->Enable(value.GetBool());
		}
	}
}

void MMDModelManagerObject::ImportVMDIKKeyframes(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting)
{
	if (!ik_manager_own_ || vmd_file.m_iks.empty())
		return;
	auto* ik_manager = ik_manager_own_.get();
	if (!ik_manager)
		return;
	auto* op = static_cast<BaseObject*>(Get());
	if (!op)
		return;

	SyncIKSolverDynamicParamsFromDescMap();

	maxon::HashMap<String, DescID> ik_name_to_desc_id;
	for (const auto& p : ik_solver_dynamic_params_)
	{
		if (auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(p.second)))
		{
			iferr(ik_name_to_desc_id.Insert(String(solver->GetName().c_str()), p.first)) {}
		}
	}

	BaseDocument* const doc = op->GetDocument();

	for (const auto& ik : vmd_file.m_iks)
	{
		for (const auto& ik_info : ik.m_ikInfos)
		{
			const String ik_name(ik_info.m_name.ToUtf8String().c_str());
			const auto* entry = ik_name_to_desc_id.Find(ik_name);
			if (!entry)
				continue;
			const DescID& desc_id = entry->GetValue();

			CTrack* track = op->FindCTrack(desc_id);
			if (!track)
			{
				track = CTrack::Alloc(op, desc_id);
				if (!track)
					continue;
				op->InsertTrackSorted(track);
			}
			CCurve* curve = track->GetCurve(CCURVE::CURVE, true);
			if (!curve)
				continue;

			const BaseTime frame_time(static_cast<Float>(ik.m_frame) + setting.time_offset, 30.0);
			CKey* key = curve->FindKey(frame_time);
			if (!key)
				key = curve->AddKey(frame_time);
			if (!key)
				continue;
			key->SetValue(curve, ik_info.m_enable ? 1.0 : 0.0);
			key->SetInterpolation(curve, CINTERPOLATION::STEP);
			if (doc)
				track->FillKey(doc, op, key);
		}
	}
}

Int MMDModelManagerObject::GetMorphNum() const
{
	return morph_data_.GetCount();
}

const maxon::PointerArray<IMorph>& MMDModelManagerObject::GetMorphData()
{
	return morph_data_;
}

const maxon::HashMap<String, Int>& MMDModelManagerObject::GetMorphNameMap()
{
	return morph_name_;
}

libmmd::MMDIkSolver* MMDModelManagerObject::GetStandaloneIKSolver(const Int32 bone_index) const
{
	if (!ik_manager_own_ || bone_index < 0)
		return nullptr;

	auto* bone_manager = const_cast<MMDModelManagerObject*>(this)->GetBoneManagerData();
	if (!bone_manager)
		return nullptr;

	BaseTag* const bone_tag = bone_manager->FindBone(bone_index);
	if (!bone_tag)
		return nullptr;

	String solver_name = GetBoneTagName(bone_tag, true);
	if (solver_name.IsEmpty())
		solver_name = GetBoneTagName(bone_tag, false);
	if (solver_name.IsEmpty())
		return nullptr;

	const size_t solver_index = ik_manager_own_->FindIKSolverIndex(string_util::GetStdString(solver_name));
	if (solver_index == static_cast<size_t>(-1))
		return nullptr;
	return ik_manager_own_->GetMMDIKSolver(solver_index);
}

C4DIKChainNodeAdapter* MMDModelManagerObject::GetBoneAdapter(const Int32 bone_index) const
{
	if (const auto* const entry = physics_bone_adapters_.Find(bone_index))
		return entry->GetValue();
	return nullptr;
}

void MMDModelManagerObject::SyncStandaloneBoneAdaptersFromScene(const Bool reset_ik_rotation)
{
	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter)
			adapter->SyncCurrentTransformsFromBoneObject(reset_ik_rotation);
	}

	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter && adapter->GetParent() == nullptr)
			adapter->UpdateGlobalTransform();
	}
}

void MMDModelManagerObject::SyncStandaloneBoneAdaptersLocalFromGlobal(const maxon::BaseArray<Int32>& bone_indices) const
{
	for (const Int32 bone_index : bone_indices)
	{
		if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			adapter->SyncLocalTransformFromGlobal();
	}

	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter && adapter->GetParent() == nullptr)
			adapter->UpdateGlobalTransform();
	}
}

Bool MMDModelManagerObject::SolveStandaloneIKBeforePhysics(const Bool include_after_physics_bones)
{
	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return false;

	Bool solved = false;
	const Int32 max_layer = bone_manager_data_->GetMaxBoneLayer();
	for (Int32 layer = 0; layer <= max_layer; ++layer)
	{
		solved = SolveStandaloneIKForLayer(layer, false) > 0 || solved;
		if (include_after_physics_bones)
			solved = SolveStandaloneIKForLayer(layer, true) > 0 || solved;
	}
	return solved;
}

Int32 MMDModelManagerObject::SolveStandaloneIKForLayer(const Int32 layer, const Bool after_physics, const Bool sync_from_scene)
{
	if (!ik_manager_own_)
		return 0;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return 0;

	auto has_static_pose_keyframe_at_time = [](MMDBoneTag* bone_tag, const BaseDocument* doc) -> Bool
	{
		return bone_tag && bone_tag->HasStaticPoseAnimationSegmentAtTime(doc);
	};

	auto ik_chain_has_static_pose_override = [this, &has_static_pose_keyframe_at_time](MMDBoneTag* ik_bone_tag, const BaseDocument* doc) -> Bool
	{
		if (!ik_bone_tag || !doc)
			return false;

		maxon::BaseArray<Int32> affected_indices;
		ik_bone_tag->CollectIKAffectedBoneIndices(affected_indices);
		for (const Int32 affected_index : affected_indices)
		{
			BaseTag* const affected_tag = bone_manager_data_ ? bone_manager_data_->FindBone(affected_index) : nullptr;
			auto* const affected_tag_node = affected_tag ? affected_tag->GetNodeData<MMDBoneTag>() : nullptr;
			if (affected_tag_node && (affected_tag_node->HasStaticPoseRuntimeOverride(doc) || has_static_pose_keyframe_at_time(affected_tag_node, doc)))
				return true;
		}
		return false;
	};

	std::vector<Int32> sorted_indices;
	sorted_indices.reserve(bone_manager_data_->bone_list_.GetCount());
	for (const auto& entry : bone_manager_data_->bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	std::vector<Int32> ik_indices;
	ik_indices.reserve(sorted_indices.size());
	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		auto* const bone_tag_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		const BaseContainer* const bc = bone_tag ? bone_tag->GetDataInstance() : nullptr;
		if (!bone_tag_node || !bone_object || !bc || !bc->GetBool(PMX_BONE_IS_IK))
			continue;
		if (std::max(0, bc->GetInt32(PMX_BONE_LAYER)) != layer)
			continue;
		if (bc->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM) != after_physics)
			continue;

		libmmd::MMDIkSolver* const ik_solver = GetStandaloneIKSolver(bone_index);
		if (!ik_solver || !ik_solver->Enabled() || !ik_solver->GetIKNode() || !ik_solver->GetTargetNode())
			continue;
		if (ik_chain_has_static_pose_override(bone_tag_node, bone_object->GetDocument()))
			continue;
		ik_indices.emplace_back(bone_index);
	}
	if (ik_indices.empty())
		return 0;

	if (sync_from_scene)
		SyncStandaloneBoneAdaptersFromScene(true);

	Int32 solved_count = 0;
	for (const Int32 bone_index : ik_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		auto* const bone_tag_node = bone_tag ? bone_tag->GetNodeData<MMDBoneTag>() : nullptr;
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		if (!bone_tag_node || !bone_object)
			continue;

		libmmd::MMDIkSolver* const ik_solver = GetStandaloneIKSolver(bone_index);
		if (!ik_solver || !ik_solver->Enabled() || !ik_solver->GetIKNode() || !ik_solver->GetTargetNode())
			continue;
		if (ik_chain_has_static_pose_override(bone_tag_node, bone_object->GetDocument()))
			continue;

		bone_tag_node->BuildStandaloneIKChains();

		ik_solver->Solve();

		maxon::BaseArray<Int32> affected_indices;
		bone_tag_node->CollectIKAffectedBoneIndices(affected_indices);
		ApplyStandaloneBoneAdaptersToScene(affected_indices);

		if (BaseDocument* const doc = bone_object->GetDocument())
		{
			bone_tag_node->last_ik_solve_time_ = doc->GetTime();
			bone_tag_node->CacheIKSolveRuntimeOverrides(doc);
			bone_tag_node->MarkPrephysicsIKChainUpdated(doc);
		}
		++solved_count;
	}

	return solved_count;
}

Bool MMDModelManagerObject::RunLayeredBonePass(BaseDocument* doc, const Bool after_physics)
{
	if (!doc)
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return false;

	Bool touched = false;
	const Int32 max_layer = bone_manager_data_->GetMaxBoneLayer();
	for (Int32 layer = 0; layer <= max_layer; ++layer)
	{
		const Int32 anim_count = bone_manager_data_->PrepareSceneForPhysicsPlaybackLayer(doc, layer, after_physics);
		SyncStandaloneBoneAdaptersFromScene(true);
		const Int32 ik_count = SolveStandaloneIKForLayer(layer, after_physics, false);
		touched = touched || anim_count > 0 || ik_count > 0;
	}
	return touched;
}

void MMDModelManagerObject::ApplyStandaloneBoneAdaptersToScene() const
{
	for (const auto& adapter : physics_bone_pool_)
	{
		if (adapter)
			adapter->ApplyLocalToBoneObject();
	}
}

void MMDModelManagerObject::ApplyStandaloneBoneAdaptersToScene(const maxon::BaseArray<Int32>& bone_indices) const
{
	for (const Int32 bone_index : bone_indices)
	{
		if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			adapter->ApplyLocalToBoneObject();
	}
}

void MMDModelManagerObject::InvalidateStandaloneRuntime()
{
	ik_manager_own_.reset();
	physics_manager_own_.reset();
	physics_bone_pool_.clear();
	physics_bone_adapters_.Reset();
	iferr(physics_dynamic_bone_indices_.Resize(0)) {}
	*is_runtime_initialized_.Write() = false;
	is_animation_initialized_ = false;
	prev_time_ = BaseTime(-1.);
}

Bool MMDModelManagerObject::BuildStandaloneBoneAdapters()
{
	iferr_scope_handler{ return false; };

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return true;

	if (BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_))
		bone_manager_data_->HandleBoneIndexChangeMessage(bone_manager_object);

	physics_bone_pool_.clear();
	physics_bone_adapters_.Reset();

	std::vector<Int32> sorted_indices;
	for (const auto& entry : bone_manager_data_->bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	physics_bone_pool_.reserve(sorted_indices.size());
	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		if (!bone_tag || !bone_tag->GetObject())
			continue;

		auto* const bone_tag_node = bone_tag->GetNodeData<MMDBoneTag>();
		if (!bone_tag_node)
			continue;

		String bone_name = GetBoneTagName(bone_tag, true);
		if (bone_name.IsEmpty())
			bone_name = GetBoneTagName(bone_tag, false);

		auto adapter = std::make_unique<C4DIKChainNodeAdapter>();
		adapter->SetupFromBone(bone_tag->GetObject(), bone_tag_node, string_util::GetStdString(bone_name));

		C4DIKChainNodeAdapter* const adapter_ptr = adapter.get();
		physics_bone_pool_.push_back(std::move(adapter));
		physics_bone_adapters_.Insert(bone_index, adapter_ptr)iferr_return;
	}

	for (const Int32 bone_index : sorted_indices)
	{
		C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index);
		if (!adapter)
			continue;

		adapter->ClearChildren();
		adapter->SetParentAdapter(nullptr);

		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		if (!bone_object)
			continue;

		if (BaseObject* const parent_object = bone_object->GetUp())
		{
			if (BaseTag* const parent_tag = parent_object->GetTag(g_mmd_bone_tag_id))
			{
				const Int32 parent_index = bone_manager_data_->FindBoneIndex(parent_tag);
				if (C4DIKChainNodeAdapter* const parent_adapter = GetBoneAdapter(parent_index))
				{
					adapter->SetParentAdapter(parent_adapter);
					parent_adapter->AddChildAdapter(adapter);
				}
			}
		}
	}

	for (const Int32 bone_index : sorted_indices)
	{
		C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index);
		if (adapter && adapter->GetParent() == nullptr)
		{
			adapter->UpdateInitialGlobalTransform();
			adapter->ResetCurrentTransformToInitial();
		}
	}

	return true;
}

Bool MMDModelManagerObject::BuildStandaloneIKManager()
{
	iferr_scope_handler{ return false; };

	ik_manager_own_ = std::make_unique<StandaloneIKManager>();
	if (!ik_manager_own_)
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (!bone_manager_data_)
		return true;

	std::vector<Int32> sorted_indices;
	for (const auto& entry : bone_manager_data_->bone_list_)
		sorted_indices.emplace_back(static_cast<Int32>(entry.GetKey()));
	std::sort(sorted_indices.begin(), sorted_indices.end());

	for (const Int32 bone_index : sorted_indices)
	{
		BaseTag* const bone_tag = bone_manager_data_->FindBone(bone_index);
		if (!bone_tag)
			continue;

		const BaseContainer* const bc = bone_tag->GetDataInstance();
		if (!bc || !bc->GetBool(PMX_BONE_IS_IK))
			continue;

		C4DIKChainNodeAdapter* const control_adapter = GetBoneAdapter(bone_index);
		if (!control_adapter)
			continue;

		auto* const solver = ik_manager_own_->AddIKSolver();
		String solver_name = GetBoneTagName(bone_tag, true);
		if (solver_name.IsEmpty())
			solver_name = GetBoneTagName(bone_tag, false);
		solver->SetName(string_util::GetStdString(solver_name));
		solver->SetIKNode(control_adapter);

		// PMX convention (matches libMMD PMXModel loader):
		//   - IK node    = the control/goal bone (external, position stays fixed)
		//   - target node = the effector bone at the end of the chain (descendant)
		// SolveCore reads m_ikNode position once (must be stable); m_ikTarget
		// is re-read per chain (moves with rotation).  BuildChainPath walks
		// from m_ikTarget upward to find chain nodes.
		// PMX_BONE_IK_TARGET_BONE_* stores the effector bone, not the control IK
		// bone itself. Resolve that effector via the stable BaseLink instead of
		// the stale PMX-file index.
		Int32 effector_index = -1;
		C4DIKChainNodeAdapter* effector_adapter = nullptr;
		BaseDocument* const tag_doc = bone_tag->GetDocument();
		if (GeData link_data; bone_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_IK_TARGET_BONE_LINK)), link_data, DESCFLAGS_GET::NONE))
		{
			BaseList2D* linked = nullptr;
			if (tag_doc)
				linked = const_cast<BaseList2D*>(link_data.GetLink(tag_doc));
			if (!linked)
			{
				if (const BaseLink* const raw_link = link_data.GetBaseLink())
					linked = static_cast<BaseList2D*>(raw_link->ForceGetLink());
			}
			if (linked && linked->IsInstanceOf(Obase))
			{
				if (BaseTag* const target_tag = static_cast<BaseObject*>(linked)->GetTag(g_mmd_bone_tag_id))
				{
					const Int32 resolved = bone_manager_data_->FindBoneIndex(target_tag);
					if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(resolved))
					{
						effector_index = resolved;
						effector_adapter = adapter;
					}
				}
			}
		}
		// Legacy fallback: older scenes/cases without the link may still carry
		// a usable DFS index in the container.
		if (!effector_adapter)
		{
			const Int32 legacy = bc->GetInt32(PMX_BONE_IK_TARGET_BONE_INDEX);
			if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(legacy))
			{
				effector_index = legacy;
				effector_adapter = adapter;
			}
		}

		if (effector_adapter)
			solver->SetTargetNode(effector_adapter);
		const Int32 iter_count = bc->GetInt32(PMX_BONE_IK_ITERATION);
		const Float unit_angle = bc->GetFloat(PMX_BONE_IK_UNIT_ANGLE);
		solver->SetIterateCount(static_cast<uint32_t>(iter_count <= 0 ? 4 : iter_count));
		solver->SetLimitAngle(static_cast<float>(unit_angle));

		const auto* const enabled_state = ik_solver_enable_states_.Find(solver_name);
		const Bool enabled = enabled_state ? enabled_state->GetValue() : bc->GetBool(PMX_BONE_IS_IK);
		solver->Enable(enabled);
	}

	return true;
}

Bool MMDModelManagerObject::BuildStandalonePhysics()
{
	iferr_scope_handler{ return false; };

	physics_manager_own_ = std::make_unique<libmmd::MMDPhysicsManager>();
	if (!physics_manager_own_ || !physics_manager_own_->Create())
		return false;

	iferr(physics_dynamic_bone_indices_.Resize(0))
		return false;

	if (rigid_manager_data_)
	{
		rigid_manager_data_->mmd_physics_manager_ = physics_manager_own_.get();
		if (!rigid_manager_data_->BuildStandaloneRigidBodies(physics_manager_own_.get(), [this](const Int32 bone_index) -> libmmd::IMMDNode*
		{
			return GetBoneAdapter(bone_index);
		}))
		{
			return false;
		}

		auto* const physics = physics_manager_own_->GetMMDPhysics();
		auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
		if (physics && rigid_bodies)
		{
			for (const auto& rigid_body : *rigid_bodies)
				physics->AddRigidBody(rigid_body.get());
		}

		if (BaseObject* const rigid_manager_object = io_util::ResolveObjectLink(rigid_manager_))
		{
			for (BaseObject* child = rigid_manager_object->GetDown(); child; child = child->GetNext())
			{
				if (!child->IsInstanceOf(g_mmd_rigid_object_id))
					continue;

				const BaseContainer* const bc = child->GetDataInstance();
				if (!bc)
					continue;

				const auto op_mode = static_cast<libmmd::PMXRigidbody::Operation>(bc->GetInt32(RIGID_PHYSICS_MODE));
				if (op_mode == libmmd::PMXRigidbody::Operation::Static)
					continue;

				const Int32 bone_index = bc->GetInt32(RIGID_RELATED_BONE_INDEX);
				if (bone_index < 0)
					continue;

				iferr(physics_dynamic_bone_indices_.Append(bone_index)) {}
			}
		}

	}

	if (joint_manager_data_)
	{
		joint_manager_data_->mmd_physics_manager_ = physics_manager_own_.get();
		if (!joint_manager_data_->BuildStandaloneJoints(physics_manager_own_.get()))
			return false;

		auto* const physics = physics_manager_own_->GetMMDPhysics();
		auto* const joints = physics_manager_own_->GetJoints();
		if (physics && joints)
		{
			for (const auto& joint : *joints)
				physics->AddJoint(joint.get());
		}
	}

	if (rigid_manager_data_)
		rigid_manager_data_->ReconnectRigidBodyPointers(physics_manager_own_.get());
	if (joint_manager_data_)
		joint_manager_data_->ReconnectJointPointers(physics_manager_own_.get());

	return true;
}

Bool MMDModelManagerObject::EnsureStandaloneRuntimeManagers()
{
	iferr_scope_handler{ return false; };

	if (*is_runtime_initialized_.Read() && ik_manager_own_ && physics_manager_own_)
		return true;

	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
	{
		if (!UpdateManagers(op))
			return false;
	}

	if (!BuildStandaloneBoneAdapters())
		return false;
	if (!BuildStandaloneIKManager())
		return false;
	if (!BuildStandalonePhysics())
		return false;

	BuildIKSolverUI();
	ApplyIKSolverStates();
	if (bone_manager_data_)
	{
		if (animation_slot_metadata_.GetCount() > 0)
			bone_manager_data_->EnsureAllAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount()));
		if (animation_index_ >= 0 && animation_index_ < animation_slot_metadata_.GetCount())
		{
			bone_manager_data_->SetAllActiveAnimationSlot(animation_index_);
			if (model_mode_ == MODEL_MODE_ANIM)
				bone_manager_data_->SetAllBoneMode(BONE_MODE_ANIM);
		}
	}

	ApplyPhysicsConfigToRuntime(reinterpret_cast<BaseObject*>(Get()));
	ResetStandalonePhysics();
	*is_runtime_initialized_.Write() = true;
	return true;
}

void MMDModelManagerObject::ResetStandalonePhysics()
{
	if (!physics_manager_own_)
		return;

	auto* const physics = physics_manager_own_->GetMMDPhysics();
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!physics || !rigid_bodies)
		return;

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->ResetTransform();

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->Reset(physics);

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->SetActivation(true);
}

void MMDModelManagerObject::StepStandalonePhysics(const Float elapsed)
{
	if (!physics_manager_own_)
		return;

	bone_manager_data_ = GetBoneManagerData();
	auto* const physics = physics_manager_own_->GetMMDPhysics();
	auto* const rigid_bodies = physics_manager_own_->GetRigidBodys();
	if (!physics || !rigid_bodies)
		return;

	BaseObject* const model_object = reinterpret_cast<BaseObject*>(Get());
	BaseDocument* const doc = model_object ? model_object->GetDocument() : nullptr;

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->SyncBonePositionToPhysics(elapsed);

	physics->Update(elapsed);

	for (const auto& rigid_body : *rigid_bodies)
		rigid_body->ReflectGlobalTransform();

	SyncStandaloneBoneAdaptersLocalFromGlobal(physics_dynamic_bone_indices_);

	if (bone_manager_data_)
	{
		for (const Int32 bone_index : physics_dynamic_bone_indices_)
		{
			if (C4DIKChainNodeAdapter* const adapter = GetBoneAdapter(bone_index))
			{
				Vector translation;
				std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
				adapter->GetCurrentRelativeState(translation, rotation);
				bone_manager_data_->SetPhysicsOverride(bone_index, doc, translation, rotation);
			}
		}
	}

	ApplyPhysicsResultsToBoneObjects();
}

void MMDModelManagerObject::ApplyPhysicsResultsToBoneObjects() const
{
	ApplyStandaloneBoneAdaptersToScene(physics_dynamic_bone_indices_);
	MarkMeshHierarchyDirty(GetMeshManagerObject());
}

void MMDModelManagerObject::CommitEditModeBindState(BaseDocument* doc)
{
	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
		std::ignore = UpdateManagers(op);

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
		bone_manager_data_->CommitEditModeBindState(io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(joint_manager_));
	if (mesh_manager_data_ || GetMeshManagerData())
		mesh_manager_data_->RefreshWeightBindPoses(GetMeshManagerObject(), doc);
	if (bone_manager_data_)
		bone_manager_data_->SetAllBoneMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->SetAllRigidMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->SetAllJointMode(MODEL_MODE_ANIM, io_util::ResolveObjectLink(joint_manager_));

	MarkMeshHierarchyDirty(GetMeshManagerObject());
	*is_morph_initialized_.Write() = true;
	*update_morph_.Write() = true;
}

void MMDModelManagerObject::RestoreBindStateForEdit(BaseDocument* doc)
{
	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
		std::ignore = UpdateManagers(op);

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
		bone_manager_data_->RestoreBindStateForEdit(io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->RestoreEditorTransforms(io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->RestoreEditorTransforms(io_util::ResolveObjectLink(joint_manager_));
	if (bone_manager_data_)
		bone_manager_data_->SetAllBoneMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(bone_manager_));
	if (rigid_manager_data_ || GetRigidManagerData())
		rigid_manager_data_->SetAllRigidMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(rigid_manager_));
	if (joint_manager_data_ || GetJointManagerData())
		joint_manager_data_->SetAllJointMode(MODEL_MODE_EDIT, io_util::ResolveObjectLink(joint_manager_));
	ClearMorphRuntimeForEdit();
	MarkMeshHierarchyDirty(GetMeshManagerObject());

	(void)doc;
}

Bool MMDModelManagerObject::IsPhysicsEnabled(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	return bc ? bc->GetBool(MODEL_PHYSICS_ENABLED) : true;
}

Bool MMDModelManagerObject::ShouldResetPhysicsOnSeek(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	return bc ? bc->GetBool(MODEL_PHYSICS_RESET_ON_SEEK) : true;
}

Vector MMDModelManagerObject::GetPhysicsGravity(const BaseObject* op) const
{
	const BaseContainer* const bc = op ? op->GetDataInstance() : nullptr;
	const Float strength = bc ? bc->GetFloat(MODEL_PHYSICS_GRAVITY_STRENGTH, 98.0) : 98.0;
	Vector direction = bc ? bc->GetVector(MODEL_PHYSICS_GRAVITY_DIRECTION, Vector(0, -1, 0)) : Vector(0, -1, 0);
	const Float64 length_sq = static_cast<Float64>(direction.x) * direction.x
		+ static_cast<Float64>(direction.y) * direction.y
		+ static_cast<Float64>(direction.z) * direction.z;
	if (length_sq <= std::numeric_limits<Float64>::epsilon())
		direction = Vector(0, -1, 0);
	else
		direction = direction.GetNormalized();
	return direction * strength;
}

void MMDModelManagerObject::ApplyPhysicsConfigToRuntime(const BaseObject* op)
{
	if (!physics_manager_own_)
		return;

	auto* const physics = physics_manager_own_->GetMMDPhysics();
	if (!physics)
		return;

	if (auto* const world = physics->GetDynamicsWorld())
	{
		const Vector gravity = IsPhysicsEnabled(op) ? GetPhysicsGravity(op) : Vector(0);
		world->setGravity(btVector3(
			static_cast<btScalar>(gravity.x),
			static_cast<btScalar>(gravity.y),
			static_cast<btScalar>(gravity.z)));
	}
}

void MMDModelManagerObject::SyncSubManagerScale(const Float pm)
{
	if (auto* op = reinterpret_cast<BaseObject*>(Get()))
		op->SetAbsScale(Vector(pm, pm, pm));
}

Bool MMDModelManagerObject::CreateManagers()
{
	const BaseDocument* doc = GetActiveDocument();
	if (const auto op = reinterpret_cast<BaseObject*>(Get()); op != nullptr && doc != nullptr)
	{
		if (!io_util::ResolveObjectLink(bone_manager_))
		{
			BaseObject* bone_root_object = BaseObject::Alloc(g_mmd_bone_manager_object_id);
			bone_root_object->InsertUnder(op);
			bone_manager_->SetLink(bone_root_object);
			bone_manager_data_ = bone_root_object->GetNodeData<MMDBoneManagerObject>();
			bone_manager_data_->model_manager_->SetLink(op);
		}
		if (!io_util::ResolveObjectLink(mesh_manager_))
		{
			BaseObject* mesh_root_object = BaseObject::Alloc(g_mmd_mesh_manager_object_id);
			mesh_root_object->InsertUnder(op);
			mesh_manager_->SetLink(mesh_root_object);
			mesh_manager_data_ = mesh_root_object->GetNodeData<MMDMeshManagerObject>();
			mesh_manager_data_->model_manager_->SetLink(op);
		}
		if (!io_util::ResolveObjectLink(rigid_manager_))
		{
			BaseObject* rigid_root_object = BaseObject::Alloc(g_mmd_rigid_manager_object_id);
			rigid_root_object->InsertUnder(op);
			rigid_manager_->SetLink(rigid_root_object);
			rigid_manager_data_ = rigid_root_object->GetNodeData<MMDRigidManagerObject>();
			rigid_manager_data_->bone_manager_data_ = bone_manager_data_;
			if (auto* bone_obj = io_util::ResolveObjectLink(bone_manager_))
				rigid_manager_data_->bone_manager_link_->SetLink(bone_obj);
		}
		if (!io_util::ResolveObjectLink(joint_manager_))
		{
			BaseObject* joint_root_object = BaseObject::Alloc(g_mmd_joint_manager_object_id);
			joint_root_object->InsertUnder(op);
			joint_manager_->SetLink(joint_root_object);
			joint_manager_data_ = joint_root_object->GetNodeData<MMDJointManagerObject>();
			joint_manager_data_->bone_manager_data_ = bone_manager_data_;
			joint_manager_data_->rigid_manager_data_ = rigid_manager_data_;
			if (auto* bone_obj = io_util::ResolveObjectLink(bone_manager_))
				joint_manager_data_->bone_manager_link_->SetLink(bone_obj);
			if (auto* rigid_obj = io_util::ResolveObjectLink(rigid_manager_))
				joint_manager_data_->rigid_manager_link_->SetLink(rigid_obj);
		}
		return true;
	}
	return false;
}

void MMDModelManagerObject::ImportDisplayFrames(const libmmd::PMXFile& pmx_file)
{
	iferr(display_frame_list_.Resize(0)) return;
	for (const auto& frame : pmx_file.m_displayFrames)
	{
		DisplayFrameData df;
		df.FromPMX(frame);
		iferr(display_frame_list_.Append(std::move(df))) return;
	}
	display_frame_selection_index_ = display_frame_list_.GetCount() > 0 ? 0 : -1;
	RefreshDisplayFrameUI();
}

void MMDModelManagerObject::RefreshDisplayFrameUI()
{
	DynamicDescription* const dd = Get()->GetDynamicDescriptionWritable();
	if (!dd) return;

	const DescID entries_grp_id = ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_ENTRIES_GRP));

	for (auto it = desc_id_map_.Begin(); it != desc_id_map_.End();)
	{
		const auto& dtype = it->GetValue().first;
		if (dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON ||
			dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON ||
			dtype == MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON)
		{
			dd->Remove(it->GetKey());
			it = desc_id_map_.Erase(it);
		}
		else
			++it;
	}

	{
		void* handle = dd->BrowseInit();
		DescID browse_id;
		const BaseContainer* browse_bc = nullptr;
		maxon::BaseArray<DescID> to_remove;
		while (dd->BrowseGetNext(handle, &browse_id, &browse_bc))
		{
			if (!browse_bc) continue;
			const DescID* parent_id_ptr = GetContainerCustomDataType<DescID>(*browse_bc, DESC_PARENTGROUP, CUSTOMDATATYPE_DESCID);
			if (parent_id_ptr && *parent_id_ptr == entries_grp_id)
				to_remove.Append(browse_id) iferr_ignore("append failed"_s);
		}
		dd->BrowseFree(handle);
		for (const auto& rid : to_remove)
		{
			maxon::BaseArray<DescID> children;
			handle = dd->BrowseInit();
			while (dd->BrowseGetNext(handle, &browse_id, &browse_bc))
			{
				if (!browse_bc) continue;
				const DescID* pid = GetContainerCustomDataType<DescID>(*browse_bc, DESC_PARENTGROUP, CUSTOMDATATYPE_DESCID);
				if (pid && *pid == rid)
					children.Append(browse_id) iferr_ignore("append failed"_s);
			}
			dd->BrowseFree(handle);
			for (const auto& cid : children)
				dd->Remove(cid);
			dd->Remove(rid);
		}
	}

	const Int32 sel = display_frame_selection_index_;
	if (sel < 0 || sel >= display_frame_list_.GetCount())
		return;

	const auto& frame = display_frame_list_[sel];
	BaseContainer bc;

	for (Int32 i = 0; i < frame.targets.GetCount(); ++i)
	{
		const auto& target = frame.targets[i];
		const String type_label = (target.type == DisplayFrameTargetType::Bone)
			? "[Bone] "_s : "[Morph] "_s;
		String target_name = String::IntToString(target.index);
		const MMDBoneManagerObject* bmd_ui = bone_manager_data_;
		if (!bmd_ui)
		{
			if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
				bmd_ui = bone_mgr->GetNodeData<MMDBoneManagerObject>();
			if (!bmd_ui)
			{
				auto* op = static_cast<BaseObject*>(Get());
				for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
				{
					if (child->IsInstanceOf(g_mmd_bone_manager_object_id))
					{
						bmd_ui = child->GetNodeData<MMDBoneManagerObject>();
						break;
					}
				}
			}
		}
		if (target.type == DisplayFrameTargetType::Bone && bmd_ui)
		{
			target_name = bmd_ui->GetBoneItems().GetString(target.index, target_name);
		}
		else if (target.type == DisplayFrameTargetType::Morph)
		{
			for (const auto& entry : morph_name_)
			{
				if (entry.GetValue() == static_cast<Int>(target.index))
				{
					target_name = entry.GetKey();
					break;
				}
			}
		}

		bc = GetCustomDataTypeDefault(DTYPE_GROUP);
		bc.SetInt32(DESC_COLUMNS, 4);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(entries_grp_id));
		const auto row_grp = dd->Alloc(bc);

		bc = GetCustomDataTypeDefault(DTYPE_STATICTEXT);
		bc.SetString(DESC_NAME, type_label + target_name);
		bc.SetBool(DESC_SCALEH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		dd->Alloc(bc);

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "\u2191"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID up_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(up_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON, i})) {}

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "\u2193"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID down_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(down_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON, i})) {}

		bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
		bc.SetString(DESC_NAME, "-"_s);
		bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
		bc.SetBool(DESC_FITH, true);
		bc.SetData(DESC_PARENTGROUP, MakeDescIDGeData(row_grp));
		const DescID del_id = dd->Alloc(bc);
		iferr(desc_id_map_.Insert(del_id, {MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON, i})) {}
	}

	Get()->SetDirty(DIRTYFLAGS::DESCRIPTION);
	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
		::EventAdd();
}

Bool MMDModelManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelImport& setting)
{
	InvalidateStandaloneRuntime();
	iferr(material_list_.Resize(0))
		return false;
	material_selection_index_ = -1;

	if (BaseContainer* bc = reinterpret_cast<BaseList2D*>(Get())->GetDataInstance())
	{
		bc->SetString(MODEL_NAME_LOCAL, maxon::String{ pmx_file.m_info.m_modelName.c_str() });
		bc->SetString(MODEL_NAME_UNIVERSAL, maxon::String{ pmx_file.m_info.m_englishModelName.c_str() });
		bc->SetString(COMMENTS_LOCAL, maxon::String{ pmx_file.m_info.m_comment.c_str() });
		bc->SetString(COMMENTS_UNIVERSAL, maxon::String{ pmx_file.m_info.m_englishComment.c_str() });
		bc->SetFloat(PMX_VERSION, pmx_file.m_header.m_version);
		bc->SetFloat(MODEL_POSITION_MULTIPLE, setting.position_multiple);
		bc->SetInt32(MODEL_MATERIAL_CREATE_TYPE, static_cast<Int32>(setting.import_material_type));
	}

	SyncSubManagerScale(setting.position_multiple);

	maxon::BaseArray<BaseObject*> bone_list;
	auto morph_change_helper = BeginMorphChange();

	if (setting.import_bone)
		if(!bone_manager_data_ || !bone_manager_data_->LoadPMX(pmx_file, bone_list, setting))
			return false;

	if (setting.import_polygon)
		if(!mesh_manager_data_ || !mesh_manager_data_->LoadPMX(pmx_file, bone_list, setting))
			return false;

	if(!rigid_manager_data_ || !rigid_manager_data_->LoadPMX(pmx_file, bone_list, setting))
		return false;

	if(!joint_manager_data_ || !joint_manager_data_->LoadPMX(pmx_file, setting))
		return false;

	if (!EnsureStandaloneRuntimeManagers())
		return false;

	if (setting.import_bone && bone_manager_data_)
		bone_manager_data_->CreateOrRefreshControls(io_util::ResolveObjectLink(bone_manager_));

	ImportDisplayFrames(pmx_file);

	if (setting.import_expression)
	{
		const auto& pmx_morph_array = pmx_file.m_morphs;
		const auto pmx_morph_num = pmx_morph_array.size();
		for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
		{
			const auto& pmx_morph = pmx_morph_array[morph_index];
			const auto& morph_offset_type = pmx_morph.m_morphType;
			const auto panel = static_cast<Int32>(pmx_morph.m_controlPanel);
			if (morph_offset_type == libmmd::PMXMorphType::Group || morph_offset_type == libmmd::PMXMorphType::Flip)
			{
				ImportGroupAndFlipMorph(pmx_morph, panel);
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Material)
			{
				AddMorph(MMDMorphType::MATERIAL, String(pmx_morph.m_name.c_str()), true, panel);
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Impluse)
			{
				AddMorph(MMDMorphType::IMPULSE, String(pmx_morph.m_name.c_str()), true, panel);
			}
		}
	}
	return true;
}

Bool MMDModelManagerObject::AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
                                        BaseObject* mesh_object, const String& selection_name,
                                        const maxon::BaseArray<Filename>& texture_paths)
{
	iferr_scope_handler { return false; };
	MMDMaterialData mat;
	mat.FromPMX(pmx_material);
	const auto tex_idx = pmx_material.m_textureIndex;
	if (tex_idx >= 0 && tex_idx < texture_paths.GetCount())
		mat.texture_path = texture_paths[tex_idx].GetString();
	const auto sphere_idx = pmx_material.m_sphereTextureIndex;
	if (sphere_idx >= 0 && sphere_idx < texture_paths.GetCount())
		mat.sphere_texture_path = texture_paths[sphere_idx].GetString();
	if (mat.toon_texture_index >= 0)
	{
		if (mat.toon_mode == 1)
		{
			Char buf[20];
			snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
			mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
		}
		else if (mat.toon_texture_index < texture_paths.GetCount())
			mat.toon_texture_path = texture_paths[mat.toon_texture_index].GetString();
	}
	if (c4d_material)
	{
		auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
		if (link_result == maxon::FAILED)
			return false;
		mat.material_link = link_result.GetValue();
		if (mat.material_link && *mat.material_link)
			(*mat.material_link)->SetLink(c4d_material);
	}
	if (mesh_object)
	{
		auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
		if (link_result == maxon::FAILED)
			return false;
		mat.mesh_link = link_result.GetValue();
		if (mat.mesh_link && *mat.mesh_link)
			(*mat.mesh_link)->SetLink(mesh_object);
	}
	mat.selection_name = selection_name;
	material_list_.Append(std::move(mat)) iferr_return;
	return true;
}

Bool MMDModelManagerObject::PreparePMXExportState(BaseDocument* doc)
{
	if (!doc)
		return false;

	if (BaseObject* const op = reinterpret_cast<BaseObject*>(Get()))
		std::ignore = UpdateManagers(op);

	Bool restore_edit_mode = false;
	if (model_mode_ == MODEL_MODE_EDIT)
	{
		CommitEditModeBindState(doc);
		restore_edit_mode = true;
	}
	else
	{
		bone_manager_data_ = GetBoneManagerData();
		if (bone_manager_data_)
			bone_manager_data_->SynchronizeBoneHierarchy(io_util::ResolveObjectLink(bone_manager_), false);

		if (rigid_manager_data_ || GetRigidManagerData())
			rigid_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(rigid_manager_));
		if (joint_manager_data_ || GetJointManagerData())
			joint_manager_data_->CommitEditorTransforms(io_util::ResolveObjectLink(joint_manager_));
	}

	CaptureAndClearPMXExportMorphState(doc);
	return restore_edit_mode;
}

void MMDModelManagerObject::FinishPMXExportState(BaseDocument* doc, const Bool restore_edit_mode)
{
	if (restore_edit_mode && doc)
		RestoreBindStateForEdit(doc);
	RestorePMXExportMorphState(doc);
}

Bool MMDModelManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting)
{
	const BaseContainer* const bc = reinterpret_cast<const BaseList2D*>(Get())->GetDataInstance();
	if (!bc)
		return false;

	WritePmxHeaderAndInfo(pmx_file, *bc);

	MMDBoneManagerObject* bone_manager = nullptr;
	if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
		bone_manager = bone_mgr->GetNodeData<MMDBoneManagerObject>();

	if (setting.export_bone && bone_manager && !bone_manager->SavePMX(pmx_file, setting))
		return false;

	if (!setting.export_bone && setting.export_polygon && pmx_file.m_bones.empty())
	{
		libmmd::PMXBone dummy;
		dummy.m_name = "root";
		dummy.m_englishName = "root";
		dummy.m_position = Eigen::Vector3f::Zero();
		dummy.m_parentBoneIndex = -1;
		dummy.m_deformDepth = 0;
		dummy.m_boneFlag = libmmd::PMXBoneFlags{};
		pmx_file.m_bones.push_back(std::move(dummy));
	}

	if (setting.export_expression)
	{
		if (!ExportMorphStubs(morph_data_, pmx_file))
			return false;
		if (setting.export_bone && bone_manager && !bone_manager->ExportBoneMorphsToPMX(pmx_file, morph_name_))
			return false;
	}
	else
	{
		pmx_file.m_morphs.clear();
	}

	MaterialExportStateGuard material_export_guard(material_list_);

	if (!setting.export_polygon)
	{
		pmx_file.m_vertices.clear();
		pmx_file.m_faces.clear();
	}
	else if (auto* mesh_mgr = io_util::ResolveObjectLink(mesh_manager_))
	{
		if (const auto mmd = mesh_mgr->GetNodeData<MMDMeshManagerObject>(); mmd && !mmd->SavePMX(pmx_file, setting))
			return false;
	}

	std::unordered_map<std::string, Int32> texture_path_to_index;
	if (setting.export_material)
	{
		BuildPmxTextureTable(material_list_, pmx_file.m_textures, texture_path_to_index);

		const Int32 mat_count = static_cast<Int32>(material_list_.GetCount());
		pmx_file.m_materials.resize(static_cast<size_t>(mat_count));
		for (Int32 i = 0; i < mat_count; ++i)
		{
			const auto& material = material_list_[i];
			material.ToPMX(
				pmx_file.m_materials[static_cast<size_t>(i)],
				ResolveTextureIndex(texture_path_to_index, material.texture_path),
				ResolveTextureIndex(texture_path_to_index, material.sphere_texture_path),
				ResolveToonTextureIndex(material, texture_path_to_index));
			if (!setting.export_polygon)
				pmx_file.m_materials[static_cast<size_t>(i)].m_numFaceVertices = 0;
		}
	}
	else
	{
		pmx_file.m_textures.clear();
		pmx_file.m_materials.clear();
		if (setting.export_polygon)
			AppendDefaultPmxMaterialForMesh(pmx_file);
	}

	if (!setting.export_bone && setting.export_expression)
		RemoveEmptyBoneMorphStubs(pmx_file);

	const Int32 bone_count = static_cast<Int32>(pmx_file.m_bones.size());
	const Int32 morph_count = static_cast<Int32>(pmx_file.m_morphs.size());
	const Int32 exported_reference_bone_count = setting.export_bone ? bone_count : 0;
	ExportDisplayFrames(display_frame_list_, pmx_file, exported_reference_bone_count, morph_count);

	std::unordered_map<Int32, Int32> rigid_index_remap;
	if (auto* rigid_mgr = io_util::ResolveObjectLink(rigid_manager_))
		if (const auto rmd = rigid_mgr->GetNodeData<MMDRigidManagerObject>(); rmd && !rmd->SavePMX(pmx_file, &rigid_index_remap, exported_reference_bone_count))
			return false;

	if (auto* joint_mgr = io_util::ResolveObjectLink(joint_manager_))
		if (const auto jmd = joint_mgr->GetNodeData<MMDJointManagerObject>(); jmd && !jmd->SavePMX(pmx_file, &rigid_index_remap))
			return false;

	ClearUnsupportedPmxSections(pmx_file);
	FinalizePmxHeaderIndexSizes(pmx_file);
	return true;
}

Bool MMDModelManagerObject::AddMorphStrengthKeyframe(const String& morph_name, const BaseTime& key_time, Float weight)
{
	const auto* name_entry = morph_name_.Find(morph_name);
	if (!name_entry)
		return false;
	const Int morph_index = name_entry->GetValue();
	if (morph_index < 0 || morph_index >= morph_data_.GetCount())
		return false;
	auto* object = reinterpret_cast<BaseObject*>(Get());
	if (!object)
		return false;
	const DescID& track_id = morph_data_[morph_index].GetStrengthDescID();
	CTrack* track = object->FindCTrack(track_id);
	if (!track)
	{
		track = CTrack::Alloc(object, track_id);
		if (!track)
			return false;
		object->InsertTrackSorted(track);
	}
	CCurve* curve = track->GetCurve();
	if (!curve)
		return false;
	CKey* key = curve->FindKey(key_time);
	if (!key)
		key = curve->AddKey(key_time);
	if (!key)
		return false;
	key->SetValue(curve, weight);
	key->SetInterpolation(curve, CINTERPOLATION::LINEAR);
	return true;
}

Bool MMDModelManagerObject::CaptureMorphAnimationSlotFromTracks(const Int32 slot_index)
{
	if (slot_index < 0 || slot_index >= animation_slot_metadata_.GetCount())
		return true;
	if (!EnsureMorphAnimationSlotCount(static_cast<Int32>(animation_slot_metadata_.GetCount())))
		return false;

	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	if (!object)
		return false;

	auto& slot = morph_animation_slots_[slot_index];
	iferr(slot.keyframes.Resize(0))
		return false;

	for (auto& morph : morph_data_)
	{
		CTrack* const track = object->FindCTrack(morph.GetStrengthDescID());
		if (!track)
			continue;
		CCurve* const curve = track->GetCurve();
		if (!curve)
			continue;

		const Int32 key_count = curve->GetKeyCount();
		for (Int32 key_index = 0; key_index < key_count; ++key_index)
		{
			const CKey* const key = curve->GetKey(key_index);
			if (!key)
				continue;

			MorphAnimationKeyframeData data;
			data.morph_name = morph.GetName();
			data.frame = key->GetTime().GetFrame(kModelAnimationFps);
			data.weight = static_cast<Float32>(key->GetValue());
			iferr(slot.keyframes.Append(std::move(data)))
				return false;
		}
	}

	return true;
}

Bool MMDModelManagerObject::RebuildMorphTracksFromAnimationSlot(const Int32 slot_index)
{
	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	if (!object)
		return false;

	for (auto& morph : morph_data_)
	{
		RemoveParameterTrack(object, morph.GetStrengthDescID());
		morph.SetStrength(object, 0.0);
	}

	if (slot_index >= 0 && slot_index < morph_animation_slots_.GetCount())
	{
		const auto& slot = morph_animation_slots_[slot_index];
		for (const auto& keyframe : slot.keyframes)
		{
			if (!morph_name_.Find(keyframe.morph_name))
				continue;
			const BaseTime key_time(static_cast<Float>(keyframe.frame), kModelAnimationFps);
			if (!AddMorphStrengthKeyframe(keyframe.morph_name, key_time, keyframe.weight))
				return false;
		}
	}

	object->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA);
	object->Message(MSG_UPDATE);
	return true;
}

Bool MMDModelManagerObject::LoadVMDMotion(const libmmd::VMDFile& vmd_file, const CMTToolsSetting::MotionImport& setting, LoadVmdMotionLog& log, const Bool merge)
{
	iferr_scope_handler
	{
		return false;
	};
	log.not_find_bone_name_list.Reset();
	log.not_find_morph_name_list.Reset();
	const auto animation_name = setting.fn.GetFileString();
	bone_manager_data_ = GetBoneManagerData();
	rigid_manager_data_ = GetRigidManagerData();
	BaseObject* const rigid_manager_object = io_util::ResolveObjectLink(rigid_manager_);

	const Bool merge_into_existing = merge
		&& animation_index_ >= 0
		&& animation_index_ < animation_slot_metadata_.GetCount();
	const Int32 target_slot = merge_into_existing
		? animation_index_
		: static_cast<Int32>(animation_slot_metadata_.GetCount());
	if (!EnsureAnimationSlotCount(target_slot + 1))
		return false;
	if (bone_manager_data_ && !bone_manager_data_->EnsureAllAnimationSlotCount(target_slot + 1))
		return false;

	if (!vmd_file.m_iks.empty())
		ImportVMDIKKeyframes(vmd_file, setting);

	if (setting.import_morph)
	{
		std::set<std::string> unmatched_morph_utf8;
		for (const auto& morph : vmd_file.m_morphs)
		{
			const String morph_name(morph.m_blendShapeName.ToUtf8String().c_str());
			const BaseTime key_time(static_cast<Float>(morph.m_frame) + setting.time_offset, kModelAnimationFps);
			if (!AddMorphStrengthKeyframe(morph_name, key_time, morph.m_weight))
				unmatched_morph_utf8.insert(morph.m_blendShapeName.ToUtf8String());
		}
		for (const auto& utf8 : unmatched_morph_utf8)
		{
			log.not_find_morph_name_list.Append(String(utf8.c_str())) iferr_return;
		}
	}

	if (setting.import_motion && bone_manager_data_)
	{
		struct BoneImportTarget
		{
			BaseTag* tag = nullptr;
			Int32 bone_index = -1;
		};

		std::unordered_map<std::string, BoneImportTarget> bone_lookup;
		for (const auto& entry : bone_manager_data_->bone_list_)
		{
			BaseTag* bone_tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
			if (!bone_tag)
				continue;

			const String bone_name = GetBoneTagName(bone_tag, setting.import_by_local_name);
			const std::string utf8_name = string_util::GetStdString(bone_name);
			if (!utf8_name.empty())
				bone_lookup.emplace(utf8_name, BoneImportTarget{ bone_tag, static_cast<Int32>(entry.GetKey()) });
		}

		std::unordered_map<BaseTag*, std::vector<BoneAnimationKeyframeData>> imported_motion_map;
		std::set<std::string> unmatched_bone_utf8;
		for (const auto& motion : vmd_file.m_motions)
		{
			const std::string bone_name_utf8 = motion.m_boneName.ToUtf8String();
			const auto bone_it = bone_lookup.find(bone_name_utf8);
			if (bone_it == bone_lookup.end())
			{
				unmatched_bone_utf8.insert(bone_name_utf8);
				continue;
			}

			BaseTag* const target_tag = bone_it->second.tag;
			const BaseContainer* const target_bc = target_tag ? target_tag->GetDataInstance() : nullptr;
			const Bool is_inherit = target_bc && (target_bc->GetBool(PMX_BONE_INHERIT_TRANSLATION) || target_bc->GetBool(PMX_BONE_INHERIT_ROTATION));
			const Bool is_dynamic_physics_bone = setting.ignore_physical
				&& IsBoneDrivenByDynamicPhysics(rigid_manager_object, bone_it->second.bone_index);
			if (is_inherit || is_dynamic_physics_bone)
				continue;

			imported_motion_map[target_tag].push_back(ConvertMotionToBoneKeyframe(motion, setting));
		}

		for (const auto& utf8 : unmatched_bone_utf8)
		{
			log.not_find_bone_name_list.Append(String(utf8.c_str())) iferr_return;
		}

		for (const auto& imported_entry : imported_motion_map)
		{
			auto* bone_tag = imported_entry.first->GetNodeData<MMDBoneTag>();
			if (!bone_tag)
				continue;

			std::map<Int32, BoneAnimationKeyframeData> merged_by_frame;
			if (merge_into_existing)
			{
				maxon::BaseArray<BoneAnimationKeyframeData> existing_keys;
				if (!bone_tag->CopyAnimationSlot(target_slot, existing_keys))
					return false;
				for (const auto& keyframe : existing_keys)
					merged_by_frame[keyframe.frame] = keyframe;
			}
			for (const auto& keyframe : imported_entry.second)
				merged_by_frame[keyframe.frame] = keyframe;

			maxon::BaseArray<BoneAnimationKeyframeData> merged_keys;
			for (const auto& [_, keyframe] : merged_by_frame)
			{
				iferr(merged_keys.Append(keyframe))
					return false;
			}
			if (!bone_tag->ReplaceAnimationSlot(target_slot, merged_keys))
				return false;
		}
	}

	log.imported_bone_count = vmd_file.m_motions.size();
	log.imported_morph_count = vmd_file.m_morphs.size();
	log.imported_motion_count = vmd_file.m_iks.size();

	const String slot_name = merge_into_existing && !animation_slot_metadata_[target_slot].name.IsEmpty()
		? animation_slot_metadata_[target_slot].name
		: animation_name;
	const Int32 max_frame = merge_into_existing
		? std::max(GetAnimationSlotMaxFrame(target_slot), GetVmdFileMaxFrame(vmd_file, setting))
		: GetVmdFileMaxFrame(vmd_file, setting);
	if (!SetAnimationSlotMetadata(target_slot, slot_name, max_frame))
		return false;

	animation_index_ = target_slot;
	ApplyAnimationSlotSelection(setting.doc);
	InvalidateStandaloneRuntime();
	const auto node = Get();
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index_, DESCFLAGS_SET::NONE);
	node->SetParameter(ConstDescID(DescLevel(MODEL_MODE)), MODEL_MODE_ANIM, DESCFLAGS_SET::NONE);
	if (bone_manager_data_)
	{
		BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_);
		bone_manager_data_->SetAllActiveAnimationSlot(animation_index_);
		bone_manager_data_->SetAllBoneMode(BONE_MODE_ANIM, bone_manager_object);
		bone_manager_data_->SetBoneDisplayType(BONE_DISPLAY_TYPE_OFF, bone_manager_object);
	}
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);

	EventAdd();
	return true;
}

Bool MMDModelManagerObject::IsTransientVPDBone(const Int32 bone_index) const
{
	return has_transient_vpd_pose_ && ContainsBoneIndex(transient_vpd_bone_indices_, bone_index);
}

Float MMDModelManagerObject::EvaluateMorphAnimationStrength(
	const String& morph_name,
	BaseObject* object,
	const BaseTime& time)
{
	if (!object)
		return 0.0;

	const auto* name_entry = morph_name_.Find(morph_name);
	if (!name_entry)
		return 0.0;
	const Int morph_index = name_entry->GetValue();
	if (morph_index < 0 || morph_index >= morph_data_.GetCount())
		return 0.0;

	CTrack* const track = object->FindCTrack(morph_data_[morph_index].GetStrengthDescID());
	CCurve* const curve = track ? track->GetCurve() : nullptr;
	return curve ? curve->GetValue(time) : 0.0;
}

void MMDModelManagerObject::ClearTransientVPDPoseState(BaseDocument* doc)
{
	if (!has_transient_vpd_pose_ && transient_vpd_bone_indices_.empty() && transient_vpd_morph_names_.empty())
		return;

	BaseObject* const node = reinterpret_cast<BaseObject*>(Get());
	if (!doc && node)
		doc = node->GetDocument();

	Bool changed = false;
	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
	{
		for (const Int32 bone_index : transient_vpd_bone_indices_)
		{
			BaseTag* const bone_tag_base = bone_manager_data_->FindBone(bone_index);
			auto* const bone_tag = bone_tag_base ? bone_tag_base->GetNodeData<MMDBoneTag>() : nullptr;
			if (!bone_tag)
				continue;

			bone_tag->ClearPlaybackRuntimeOverride();
			MarkSceneNodeDirty(bone_tag_base);
			if (BaseObject* const bone_object = bone_tag_base->GetObject())
				MarkSceneNodeDirty(bone_object);
			changed = true;
		}
	}

	if (node)
	{
		const BaseTime time = doc ? doc->GetTime() : BaseTime(-1.);
		for (const String& morph_name : transient_vpd_morph_names_)
		{
			const auto* name_entry = morph_name_.Find(morph_name);
			if (!name_entry)
				continue;
			const Int morph_index = name_entry->GetValue();
			if (morph_index < 0 || morph_index >= morph_data_.GetCount())
				continue;

			const Float strength = EvaluateMorphAnimationStrength(morph_name, node, time);
			if (std::abs(morph_data_[morph_index].GetStrength(node) - strength) > kPoseRegisterEpsilon)
			{
				morph_data_[morph_index].SetStrength(node, strength);
				changed = true;
			}
		}
	}

	transient_vpd_bone_indices_.clear();
	transient_vpd_morph_names_.clear();
	has_transient_vpd_pose_ = false;
	transient_vpd_pose_time_ = BaseTime(-1.);

	if (!changed)
		return;

	ApplyMorphRuntimeStrengths();
	*update_morph_.Write() = true;
	*is_morph_initialized_.Write() = true;
	is_animation_initialized_ = false;
	prev_time_ = BaseTime(-1.);
	InvalidateStandaloneRuntime();
	if (bone_manager_data_)
		bone_manager_data_->MarkAppendExecutionOrderDirty();
	MarkMeshHierarchyDirty(GetMeshManagerObject());
	if (node)
	{
		node->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
	}
}

Bool MMDModelManagerObject::LoadVPDPose(const libmmd::VPDFile& vpd_file, const CMTToolsSetting::PoseImport& setting, LoadVpdPoseLog& log)
{
	iferr_scope_handler
	{
		return false;
	};

	BaseObject* const self = reinterpret_cast<BaseObject*>(Get());
	if (!self)
		return false;

	log.imported_bone_count = vpd_file.m_bones.size();
	log.imported_morph_count = vpd_file.m_morphs.size();
	log.matched_bone_count = 0;
	log.matched_morph_count = 0;
	log.not_find_bone_name_list.Reset();
	log.not_find_morph_name_list.Reset();

	if (!UpdateManagers(self))
		return false;

	bone_manager_data_ = GetBoneManagerData();
	mesh_manager_data_ = GetMeshManagerData();
	ClearTransientVPDPoseState(setting.doc);

	struct VpdBoneTarget
	{
		BaseTag* tag = nullptr;
		BaseObject* object = nullptr;
		Int32 bone_index = -1;
		Vector translation;
		std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
	};

	std::unordered_map<std::string, VpdBoneTarget> bone_lookup;
	if (bone_manager_data_)
	{
		for (const auto& entry : bone_manager_data_->bone_list_)
		{
			BaseTag* bone_tag = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
			if (!bone_tag)
				continue;

			const String bone_name = GetBoneTagName(bone_tag, true);
			const std::string utf8_name = string_util::GetStdString(bone_name);
			if (utf8_name.empty())
				continue;

			bone_lookup.emplace(utf8_name, VpdBoneTarget{
				bone_tag,
				bone_tag->GetObject(),
				static_cast<Int32>(entry.GetKey()),
				Vector(),
				{ 0.F, 0.F, 0.F, 1.F }
			});
		}
	}

	std::vector<VpdBoneTarget> matched_bones;
	matched_bones.reserve(vpd_file.m_bones.size());
	std::set<std::string> unmatched_bone_utf8;
	for (const auto& bone : vpd_file.m_bones)
	{
		const auto target_it = bone_lookup.find(bone.m_boneName);
		if (target_it == bone_lookup.end())
		{
			unmatched_bone_utf8.insert(bone.m_boneName);
			continue;
		}

		VpdBoneTarget target = target_it->second;
		target.translation = Vector(bone.m_translate.x(), bone.m_translate.y(), bone.m_translate.z());
		target.rotation = {
			bone.m_quaternion.x(),
			bone.m_quaternion.y(),
			bone.m_quaternion.z(),
			bone.m_quaternion.w()
		};
		matched_bones.push_back(target);
	}

	std::sort(matched_bones.begin(), matched_bones.end(), [](const VpdBoneTarget& lhs, const VpdBoneTarget& rhs)
	{
		return lhs.bone_index < rhs.bone_index;
	});

	for (const VpdBoneTarget& target : matched_bones)
	{
		auto* const bone_tag = target.tag ? target.tag->GetNodeData<MMDBoneTag>() : nullptr;
		if (!bone_tag || !target.object)
			continue;
		if (bone_tag->ApplyStaticPose(target.object, target.translation, target.rotation))
		{
			if (model_mode_ == MODEL_MODE_ANIM)
			{
				bone_tag->SetPlaybackRuntimeOverride(setting.doc, target.translation, target.rotation, true);
				AppendUniqueBoneIndex(transient_vpd_bone_indices_, target.bone_index);
			}
			++log.matched_bone_count;
		}
	}

	for (const auto& utf8 : unmatched_bone_utf8)
	{
		log.not_find_bone_name_list.Append(String(utf8.c_str())) iferr_return;
	}

	std::set<std::string> unmatched_morph_utf8;
	for (const auto& morph : vpd_file.m_morphs)
	{
		const String morph_name(morph.m_morphName.c_str());
		const auto* name_entry = morph_name_.Find(morph_name);
		if (!name_entry)
		{
			unmatched_morph_utf8.insert(morph.m_morphName);
			continue;
		}

		const Int morph_index = name_entry->GetValue();
		if (morph_index < 0 || morph_index >= morph_data_.GetCount())
		{
			unmatched_morph_utf8.insert(morph.m_morphName);
			continue;
		}

		if (morph_data_[morph_index].SetStrength(self, morph.m_weight))
		{
			if (model_mode_ == MODEL_MODE_ANIM)
				AppendUniqueMorphName(transient_vpd_morph_names_, morph_name);
			++log.matched_morph_count;
		}
		else
			unmatched_morph_utf8.insert(morph.m_morphName);
	}

	for (const auto& utf8 : unmatched_morph_utf8)
	{
		log.not_find_morph_name_list.Append(String(utf8.c_str())) iferr_return;
	}

	ApplyMorphRuntimeStrengths();
	*update_morph_.Write() = true;
	*is_morph_initialized_.Write() = true;
	is_animation_initialized_ = false;
	prev_time_ = BaseTime(-1.);
	has_transient_vpd_pose_ = model_mode_ == MODEL_MODE_ANIM
		&& (!transient_vpd_bone_indices_.empty() || !transient_vpd_morph_names_.empty());
	transient_vpd_pose_time_ = has_transient_vpd_pose_ && setting.doc ? setting.doc->GetTime() : BaseTime(-1.);
	InvalidateStandaloneRuntime();

	if (bone_manager_data_)
	{
		if (model_mode_ != MODEL_MODE_ANIM)
			mmd_bone_control_util::SyncControlsToCurrentPose(*bone_manager_data_);
		bone_manager_data_->MarkAppendExecutionOrderDirty();
		if (BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_))
			MarkSceneNodeDirty(bone_manager_object);
	}

	MarkMeshHierarchyDirty(GetMeshManagerObject());
	self->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
	self->Message(MSG_UPDATE);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
	return true;
}

Bool MMDModelManagerObject::SaveVPDPose(libmmd::VPDFile& vpd_pose, const CMTToolsSetting::PoseExport& setting) const
{
	(void)setting;
	iferr_scope_handler
	{
		return false;
	};

	auto* const self = const_cast<MMDModelManagerObject*>(this);
	BaseObject* const object = reinterpret_cast<BaseObject*>(self->Get());
	if (!object)
		return false;

	vpd_pose = libmmd::VPDFile();

	const auto* const bone_manager = self->GetBoneManagerData();
	if (bone_manager)
	{
		struct BoneExportEntry
		{
			Int32 index = -1;
			BaseTag* tag = nullptr;
			BaseObject* object = nullptr;
		};

		std::vector<BoneExportEntry> bones;
		bones.reserve(static_cast<size_t>(bone_manager->bone_list_.GetCount()));
		for (const auto& entry : bone_manager->bone_list_)
		{
			BaseTag* const bone_tag = entry.GetValue() && *entry.GetValue()
				? static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink())
				: nullptr;
			if (!bone_tag)
				continue;
			BaseObject* const bone_object = bone_tag->GetObject();
			if (!bone_object)
				continue;
			bones.push_back(BoneExportEntry{
				static_cast<Int32>(entry.GetKey()),
				bone_tag,
				bone_object
			});
		}

		std::sort(bones.begin(), bones.end(), [](const BoneExportEntry& lhs, const BoneExportEntry& rhs)
		{
			return lhs.index < rhs.index;
		});

		vpd_pose.m_bones.reserve(bones.size());
		for (const BoneExportEntry& bone : bones)
		{
			Vector runtime_translation;
			std::array<Float32, 4> runtime_rotation { 0.F, 0.F, 0.F, 1.F };
			const Vector* runtime_translation_ptr = nullptr;
			const std::array<Float32, 4>* runtime_rotation_ptr = nullptr;
			if (model_mode_ == MODEL_MODE_ANIM)
			{
				auto* const bone_tag_data = bone.tag->GetNodeData<MMDBoneTag>();
				if (bone_tag_data && bone_tag_data->GetPlaybackRuntimeOverride(runtime_translation, runtime_rotation))
				{
					runtime_translation_ptr = &runtime_translation;
					runtime_rotation_ptr = &runtime_rotation;
				}
			}
			vpd_pose.m_bones.push_back(ConvertCurrentBoneToVpd(
				bone.tag,
				bone.object,
				runtime_translation_ptr,
				runtime_rotation_ptr));
		}
	}

	vpd_pose.m_morphs.reserve(static_cast<size_t>(morph_data_.GetCount()));
	for (const auto& morph : morph_data_)
	{
		libmmd::VPDMorph vpd_morph;
		vpd_morph.m_morphName = string_util::GetStdString(morph.GetName());
		vpd_morph.m_weight = maxon::SafeConvert<float>(morph.GetStrength(object));
		vpd_pose.m_morphs.push_back(std::move(vpd_morph));
	}

	return true;
}

Bool MMDModelManagerObject::SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const
{
	if (animation_index_ < 0 || animation_index_ >= animation_slot_metadata_.GetCount())
		return false;

	auto* const self = const_cast<MMDModelManagerObject*>(this);
	BaseObject* const object = reinterpret_cast<BaseObject*>(self->Get());

	vmd_motion = libmmd::VMDFile();
	vmd_motion.m_header.m_header.Set("Vocaloid Motion Data 0002");
	vmd_motion.m_header.m_modelName.Set(ConvertStringToSjis(GetModelManagerName(object)).c_str());

	if (self->EnsureStandaloneRuntimeManagers())
		AppendIKTracksToVmd(object, self->ik_manager_own_.get(), ik_solver_dynamic_params_, setting, vmd_motion);
	else
		vmd_motion.m_iks.clear();
	if (model_mode_ == MODEL_MODE_EDIT && animation_index_ >= 0 && animation_index_ < morph_animation_slots_.GetCount())
		AppendMorphSlotToVmd(&morph_animation_slots_[animation_index_], morph_name_, setting, vmd_motion);
	else
		AppendMorphTracksToVmd(object, morph_data_, setting, vmd_motion);

	if (!setting.export_motion)
	{
		vmd_motion.m_motions.clear();
		return true;
	}

	vmd_motion.m_motions.clear();
	const auto* bone_manager = const_cast<MMDModelManagerObject*>(this)->GetBoneManagerData();
	if (!bone_manager)
		return true;

	for (const auto& entry : bone_manager->bone_list_)
	{
		BaseTag* bone_tag_base = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
		if (!bone_tag_base)
			continue;

		auto* bone_tag = bone_tag_base->GetNodeData<MMDBoneTag>();
		if (!bone_tag)
			continue;

		maxon::BaseArray<BoneAnimationKeyframeData> keyframes;
		if (!bone_tag->CopyAnimationSlot(animation_index_, keyframes))
			return false;

		String bone_name = GetBoneTagName(bone_tag_base, true);
		if (bone_name.IsEmpty())
			bone_name = GetBoneTagName(bone_tag_base, false);
		for (const auto& keyframe : keyframes)
			vmd_motion.m_motions.push_back(ConvertBoneKeyframeToMotion(bone_name, keyframe, setting));
	}

	std::sort(vmd_motion.m_motions.begin(), vmd_motion.m_motions.end(), [](const libmmd::VMDMotion& lhs, const libmmd::VMDMotion& rhs)
	{
		if (lhs.m_boneName.ToString() == rhs.m_boneName.ToString())
			return lhs.m_frame < rhs.m_frame;
		return lhs.m_boneName.ToString() < rhs.m_boneName.ToString();
	});
	return true;
}

// TODO: VMD model-info / visibility / per-frame IK controller → CTrack (see removed SetModelControllerAnimation draft).

Bool MMDModelManagerObject::EnsureCurrentAnimationSlot(BaseDocument* doc, const Int32 frame)
{
	iferr_scope_handler{ return false; };

	BaseObject* const node = reinterpret_cast<BaseObject*>(Get());
	if (!node)
		return false;

	if (!UpdateManagers(node))
		return false;

	Int32 target_slot = animation_index_;
	if (target_slot < 0 || target_slot >= animation_slot_metadata_.GetCount())
	{
		target_slot = static_cast<Int32>(animation_slot_metadata_.GetCount());
		if (!SetAnimationSlotMetadata(target_slot, FormatString("Animation @", target_slot), frame))
			return false;
		animation_index_ = target_slot;
	}
	else if (frame > animation_slot_metadata_[target_slot].max_frame)
	{
		animation_slot_metadata_[target_slot].max_frame = frame;
		RefreshAnimationSlotItems();
	}

	const Int32 slot_count = static_cast<Int32>(animation_slot_metadata_.GetCount());
	if (!EnsureMorphAnimationSlotCount(slot_count))
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
	{
		if (!bone_manager_data_->EnsureAllAnimationSlotCount(slot_count))
			return false;
		bone_manager_data_->SetAllActiveAnimationSlot(animation_index_);
	}

	if (BaseContainer* const bc = node->GetDataInstance())
		bc->SetInt32(MODEL_ANIM_LIST, animation_index_);

	if (doc && animation_index_ >= 0)
	{
		const BaseTime max_time(static_cast<Float>(GetAnimationSlotMaxFrame(animation_index_)), kModelAnimationFps);
		if (doc->GetMaxTime() < max_time)
			doc->SetMaxTime(max_time);
		if (doc->GetLoopMaxTime() < max_time)
			doc->SetLoopMaxTime(max_time);
	}

	node->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA);
	return true;
}

Bool MMDModelManagerObject::RegisterCurrentStateKeyframe(BaseDocument* doc)
{
	iferr_scope_handler{ return false; };

	BaseObject* const node = reinterpret_cast<BaseObject*>(Get());
	if (!node)
		return false;
	if (!doc)
		doc = node->GetDocument();

	const Int32 frame = doc ? doc->GetTime().GetFrame(kModelAnimationFps) : 0;
	const Float current_frame = doc
		? maxon::SafeConvert<Float>(doc->GetTime().Get() * static_cast<Float64>(kModelAnimationFps))
		: static_cast<Float>(frame);
	const BaseTime key_time(static_cast<Float>(frame), kModelAnimationFps);

	struct PendingBoneState
	{
		Int32 bone_index = NOTOK;
		BaseTag* tag_base = nullptr;
		MMDBoneTag* tag = nullptr;
		Vector translation;
		std::array<Float32, 4> rotation { 0.F, 0.F, 0.F, 1.F };
		Bool reset_control = false;
		Bool static_pose = false;
	};

	struct PendingMorphState
	{
		String name;
		Float strength = 0.0;
	};

	std::vector<PendingBoneState> pending_bones;
	std::vector<PendingMorphState> pending_morphs;

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
	{
		for (const auto& entry : bone_manager_data_->bone_list_)
		{
			const Int32 bone_index = static_cast<Int32>(entry.GetKey());
			BaseTag* const bone_tag_base = entry.GetValue() && *entry.GetValue()
				? static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink())
				: nullptr;
			auto* const bone_tag = bone_tag_base ? bone_tag_base->GetNodeData<MMDBoneTag>() : nullptr;
			BaseObject* const bone_object = bone_tag_base ? bone_tag_base->GetObject() : nullptr;
			if (!bone_tag || !bone_object)
				continue;

			maxon::BaseArray<BoneAnimationKeyframeData> keyframes;
			if (!bone_tag->CopyAnimationSlot(animation_index_, keyframes))
				return false;

			Vector base_translation;
			std::array<Float32, 4> base_rotation { 0.F, 0.F, 0.F, 1.F };
			EvaluateBoneAnimationKeyframes(keyframes, current_frame, base_translation, base_rotation);

			Vector translation = base_translation;
			std::array<Float32, 4> rotation = base_rotation;
			Bool should_register = false;
			Bool reset_control = false;
			Bool from_transient_vpd_pose = false;
			if (model_mode_ == MODEL_MODE_ANIM && IsTransientVPDBone(bone_index))
			{
				from_transient_vpd_pose = true;
				should_register = bone_tag->GetPlaybackRuntimeOverride(translation, rotation);
			}
			else if (model_mode_ == MODEL_MODE_ANIM)
			{
				Vector control_translation;
				std::array<Float32, 4> control_rotation { 0.F, 0.F, 0.F, 1.F };
				if (mmd_bone_control_util::GetControlDeltaInBoneSpace(bone_tag_base, bone_object, control_translation, control_rotation))
				{
					const BaseContainer* const bc = bone_tag_base->GetDataInstance();
					if (!bc || bc->GetBool(PMX_BONE_TRANSLATABLE))
						translation += control_translation;
					if (!bc || bc->GetBool(PMX_BONE_ROTATABLE))
					{
						const Eigen::Quaternionf base_quat(rotation[3], rotation[0], rotation[1], rotation[2]);
						const Eigen::Quaternionf control_quat(control_rotation[3], control_rotation[0], control_rotation[1], control_rotation[2]);
						rotation = ToBoneRotationArray(base_quat.normalized() * control_quat.normalized());
					}
					should_register = IsPoseDifferent(translation, rotation, base_translation, base_rotation);
					reset_control = should_register;
				}
			}
			else
			{
				const Matrix rel_matrix = bone_object->GetRelMl();
				translation = rel_matrix.off;
				rotation = ToBoneRotationArray(ExtractVpdQuaternion(rel_matrix));
				should_register = IsPoseDifferent(translation, rotation, base_translation, base_rotation);
			}

			if (!should_register || !IsPoseDifferent(translation, rotation, base_translation, base_rotation))
				continue;

			pending_bones.push_back(PendingBoneState{
				bone_index,
				bone_tag_base,
				bone_tag,
				translation,
				rotation,
				reset_control,
				from_transient_vpd_pose
			});
		}
	}

	for (auto& morph : morph_data_)
	{
		const String morph_name = morph.GetName();
		const Float current_strength = morph.GetStrength(node);
		const Float animated_strength = EvaluateMorphAnimationStrength(morph_name, node, key_time);
		if (std::abs(current_strength - animated_strength) <= kPoseRegisterEpsilon)
			continue;

		pending_morphs.push_back(PendingMorphState{
			morph_name,
			current_strength
		});
	}

	if (pending_bones.empty() && pending_morphs.empty())
	{
		return true;
	}

	if (!EnsureCurrentAnimationSlot(doc, frame))
		return false;

	for (const PendingBoneState& pending : pending_bones)
	{
		if (!pending.tag)
			continue;

		maxon::BaseArray<BoneAnimationKeyframeData> keyframes;
		if (!pending.tag->CopyAnimationSlot(animation_index_, keyframes))
			return false;

		BoneAnimationKeyframeData keyframe = MakeBoneKeyframe(frame, pending.translation, pending.rotation, pending.static_pose);
		const Int32 existing_index = FindKeyframeIndex(keyframes, frame);
		if (existing_index == NOTOK)
		{
			keyframes.Append(std::move(keyframe)) iferr_return;
		}
		else
		{
			keyframes[existing_index] = keyframe;
		}

		if (!pending.tag->ReplaceAnimationSlot(animation_index_, keyframes))
			return false;

		if (pending.reset_control)
			mmd_bone_control_util::ResetControlRelativeTransform(pending.tag_base);
		if (model_mode_ == MODEL_MODE_ANIM)
		{
			pending.tag->SetPlaybackRuntimeOverride(doc, pending.translation, pending.rotation, true);
			AppendUniqueBoneIndex(transient_vpd_bone_indices_, pending.bone_index);
		}
	}

	for (const PendingMorphState& pending : pending_morphs)
	{
		if (!AddMorphStrengthKeyframe(pending.name, key_time, pending.strength))
			return false;
		if (model_mode_ == MODEL_MODE_ANIM)
			AppendUniqueMorphName(transient_vpd_morph_names_, pending.name);
	}
	if (animation_index_ >= 0)
	{
		if (!CaptureMorphAnimationSlotFromTracks(animation_index_))
			return false;
	}

	has_transient_vpd_pose_ = model_mode_ == MODEL_MODE_ANIM
		&& (!transient_vpd_bone_indices_.empty() || !transient_vpd_morph_names_.empty());
	transient_vpd_pose_time_ = has_transient_vpd_pose_ && doc ? doc->GetTime() : BaseTime(-1.);
	is_animation_initialized_ = false;
	prev_time_ = BaseTime(-1.);
	InvalidateStandaloneRuntime();
	node->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
	node->Message(MSG_UPDATE);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
	return true;
}

Bool MMDModelManagerObject::DeleteCurrentFrameKeyframes(BaseDocument* doc)
{
	iferr_scope_handler{ return false; };

	BaseObject* const node = reinterpret_cast<BaseObject*>(Get());
	if (!node)
		return false;
	if (!doc)
		doc = node->GetDocument();
	if (animation_index_ < 0 || animation_index_ >= animation_slot_metadata_.GetCount())
		return false;

	const Int32 frame = doc ? doc->GetTime().GetFrame(kModelAnimationFps) : 0;
	Bool changed = false;

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
	{
		for (const auto& entry : bone_manager_data_->bone_list_)
		{
			BaseTag* const bone_tag_base = entry.GetValue() && *entry.GetValue()
				? static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink())
				: nullptr;
			auto* const bone_tag = bone_tag_base ? bone_tag_base->GetNodeData<MMDBoneTag>() : nullptr;
			if (!bone_tag)
				continue;

			maxon::BaseArray<BoneAnimationKeyframeData> keyframes;
			if (!bone_tag->CopyAnimationSlot(animation_index_, keyframes))
				return false;

			const Int32 keyframe_index = FindKeyframeIndex(keyframes, frame);
			if (keyframe_index == NOTOK)
				continue;

			keyframes.Erase(keyframe_index) iferr_return;
			if (!bone_tag->ReplaceAnimationSlot(animation_index_, keyframes))
				return false;
			changed = true;
		}
	}

	const BaseTime key_time(static_cast<Float>(frame), kModelAnimationFps);
	for (auto& morph : morph_data_)
	{
		const DescID track_id = morph.GetStrengthDescID();
		CTrack* const track = node->FindCTrack(track_id);
		CCurve* const curve = track ? track->GetCurve() : nullptr;
		if (!curve)
			continue;

		Int32 key_index = NOTOK;
		if (!curve->FindKey(key_time, &key_index) || key_index == NOTOK)
			continue;

		if (!curve->DelKey(key_index))
			return false;
		if (curve->GetKeyCount() == 0)
			RemoveParameterTrack(node, track_id);
		changed = true;
	}

	SyncIKSolverDynamicParamsFromDescMap();
	for (const auto& param : ik_solver_dynamic_params_)
	{
		CTrack* const track = node->FindCTrack(param.first);
		CCurve* const curve = track ? track->GetCurve() : nullptr;
		if (!curve)
			continue;

		Int32 key_index = NOTOK;
		if (!curve->FindKey(key_time, &key_index) || key_index == NOTOK)
			continue;

		if (!curve->DelKey(key_index))
			return false;
		if (curve->GetKeyCount() == 0)
			RemoveParameterTrack(node, param.first);
		changed = true;
	}

	if (animation_index_ >= 0 && !CaptureMorphAnimationSlotFromTracks(animation_index_))
		return false;

	if (changed)
	{
		is_animation_initialized_ = false;
		prev_time_ = BaseTime(-1.);
		InvalidateStandaloneRuntime();
		node->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
		if (GeIsMainThread())
			EventAdd();
	}
	return true;
}

Bool MMDModelManagerObject::DeleteVMDAnimation()
{
	iferr_scope_handler{ return false; };
	if (animation_index_ < 0 || animation_index_ >= animation_slot_metadata_.GetCount())
		return false;

	bone_manager_data_ = GetBoneManagerData();
	if (bone_manager_data_)
	{
		for (const auto& entry : bone_manager_data_->bone_list_)
		{
			BaseTag* bone_tag_base = static_cast<BaseTag*>((*entry.GetValue())->ForceGetLink());
			if (!bone_tag_base)
				continue;

			auto* bone_tag = bone_tag_base->GetNodeData<MMDBoneTag>();
			if (!bone_tag)
				continue;

			std::vector<maxon::BaseArray<BoneAnimationKeyframeData>> remaining_slots;
			for (Int32 slot_index = 0; slot_index < animation_slot_metadata_.GetCount(); ++slot_index)
			{
				if (slot_index == animation_index_)
					continue;
				maxon::BaseArray<BoneAnimationKeyframeData> slot_keys;
				if (!bone_tag->CopyAnimationSlot(slot_index, slot_keys))
					return false;
				remaining_slots.push_back(std::move(slot_keys));
			}

			bone_tag->ClearAllAnimationSlots();
			if (!bone_tag->EnsureAnimationSlotCount(static_cast<Int32>(remaining_slots.size())))
				return false;
			for (Int32 slot_index = 0; slot_index < static_cast<Int32>(remaining_slots.size()); ++slot_index)
			{
				if (!bone_tag->ReplaceAnimationSlot(slot_index, remaining_slots[static_cast<size_t>(slot_index)]))
					return false;
			}
		}
	}

	maxon::BaseArray<AnimationSlotMetadata> new_slot_metadata;
	maxon::BaseArray<MorphAnimationSlotData> new_morph_slots;
	for (Int32 i = 0; i < animation_slot_metadata_.GetCount(); ++i)
	{
		if (i == animation_index_)
			continue;
		AnimationSlotMetadata metadata;
		if (!animation_slot_metadata_[i].CopyTo(metadata))
			return false;
		iferr(new_slot_metadata.Append(std::move(metadata)))
			return false;
		if (i < morph_animation_slots_.GetCount())
		{
			MorphAnimationSlotData slot;
			slot = morph_animation_slots_[i];
			iferr(new_morph_slots.Append(std::move(slot)))
				return false;
		}
	}
	std::swap(animation_slot_metadata_, new_slot_metadata);
	std::swap(morph_animation_slots_, new_morph_slots);
	if (animation_slot_metadata_.IsEmpty())
		animation_index_ = -1;
	else
		animation_index_ = std::min(animation_index_, static_cast<Int32>(animation_slot_metadata_.GetCount() - 1));
	if (model_mode_ != MODEL_MODE_EDIT)
		ClearMorphAnimationSlots();
	RefreshAnimationSlotItems();
	ApplyAnimationSlotSelection(Get() ? Get()->GetDocument() : nullptr);
	const auto node = Get();
	node->SetDirty(DIRTYFLAGS::DESCRIPTION);
	node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), animation_index_, DESCFLAGS_SET::NONE);
	return true;
}

Int32 MMDModelManagerObject::GetMorphNamedNumber()
{
	return morph_named_number_++;
}

MMDBoneManagerObject* MMDModelManagerObject::GetBoneManagerData()
{
	if (!bone_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(bone_manager_))
			bone_manager_data_ = obj->GetNodeData<MMDBoneManagerObject>();
	return bone_manager_data_;
}

MMDMeshManagerObject* MMDModelManagerObject::GetMeshManagerData()
{
	if (!mesh_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(mesh_manager_))
			mesh_manager_data_ = obj->GetNodeData<MMDMeshManagerObject>();
	return mesh_manager_data_;
}

MMDRigidManagerObject* MMDModelManagerObject::GetRigidManagerData()
{
	if (!rigid_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(rigid_manager_))
			rigid_manager_data_ = obj->GetNodeData<MMDRigidManagerObject>();
	return rigid_manager_data_;
}

MMDJointManagerObject* MMDModelManagerObject::GetJointManagerData()
{
	if (!joint_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(joint_manager_))
			joint_manager_data_ = obj->GetNodeData<MMDJointManagerObject>();
	return joint_manager_data_;
}

NodeData* MMDModelManagerObject::Alloc()
{
	return NewObjClear(MMDModelManagerObject);
}

Bool MMDModelManagerObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	return true;
}
SDK2024_GetDDescription(MMDModelManagerObject)
{
	if (!description->LoadDescription(node->GetType()))
		return false;
	if (BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_ANIM_LIST)), nullptr))
		settings->SetContainer(DESC_CYCLE, animation_items_);
	material_list_items_.FlushAll();
	material_list_items_.SetString(MODEL_MATERIAL_NONE, GeLoadString(IDS_MODEL_MATERIAL_NONE));
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		material_list_items_.SetString(i, FormatString("@: @", i, material_list_[i].name_local));
	if (BaseContainer* mat_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATERIAL_LIST)), nullptr))
		mat_settings->SetContainer(DESC_CYCLE, material_list_items_);

	display_frame_items_.FlushAll();
	display_frame_items_.SetString(MODEL_DISPLAY_FRAME_NONE, GeLoadString(IDS_MODEL_DISPLAY_FRAME_NONE));
	for (Int32 i = 0; i < display_frame_list_.GetCount(); ++i)
		display_frame_items_.SetString(i, FormatString("@: @", i, display_frame_list_[i].name));
	if (BaseContainer* df_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_LIST)), nullptr))
		df_settings->SetContainer(DESC_CYCLE, display_frame_items_);

	if (BaseContainer* add_target_settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_ADD_TARGET)), nullptr))
	{
		BaseContainer target_cycle;
		const Int32 add_type = display_frame_add_type_;
		BaseContainer used_bones;
		BaseContainer used_morphs;
		for (const auto& frame : display_frame_list_)
		{
			for (const auto& t : frame.targets)
			{
				if (t.type == DisplayFrameTargetType::Bone)
					used_bones.SetBool(t.index, true);
				else
					used_morphs.SetBool(t.index, true);
			}
		}
		const MMDBoneManagerObject* bmd = bone_manager_data_;
		if (!bmd)
		{
			if (auto* bone_mgr = io_util::ResolveObjectLink(bone_manager_))
				bmd = bone_mgr->GetNodeData<MMDBoneManagerObject>();
			if (!bmd)
			{
				for (SDK2024_Const BaseObject* child = reinterpret_cast<SDK2024_Const BaseObject*>(node)->GetDown(); child; child = child->GetNext())
				{
					if (child->IsInstanceOf(g_mmd_bone_manager_object_id))
					{
						bmd = child->GetNodeData<MMDBoneManagerObject>();
						break;
					}
				}
			}
		}
		if (add_type == MODEL_DISPLAY_FRAME_ADD_TYPE_BONE && bmd)
		{
			SDK2024_Const BaseDocument* bone_doc = bmd->Get()->GetDocument();
			if (!bone_doc) bone_doc = reinterpret_cast<SDK2024_Const BaseObject*>(node)->GetDocument();
			for (const auto& entry : bmd->bone_list_)
			{
				const Int32 bone_index = static_cast<Int32>(entry.GetKey());
				if (bone_index >= 0 && !used_bones.GetBool(bone_index))
				{
					String bone_name = String::IntToString(bone_index);
					if (entry.GetValue() && *entry.GetValue())
					{
						if (const BaseTag* tag = static_cast<const BaseTag*>((*entry.GetValue())->GetLink(bone_doc)))
							if (const BaseObject* obj = const_cast<BaseTag*>(tag)->GetObject())
								bone_name = obj->GetName();
					}
					target_cycle.SetString(bone_index, bone_name);
				}
			}
		}
		else if (add_type == MODEL_DISPLAY_FRAME_ADD_TYPE_MORPH)
		{
			for (const auto& entry : morph_name_)
			{
				const Int32 morph_index = static_cast<Int32>(entry.GetValue());
				if (!used_morphs.GetBool(morph_index))
					target_cycle.SetString(morph_index, entry.GetKey());
			}
		}
		const Int32 first_id = target_cycle.GetIndexId(0);
		display_frame_add_target_empty_ = (first_id == NOTOK);
		if (!display_frame_add_target_empty_)
		{
			Bool found = false;
			for (Int32 idx = 0; ; ++idx)
			{
				const Int32 cid = target_cycle.GetIndexId(idx);
				if (cid == NOTOK) break;
				if (cid == display_frame_add_target_) { found = true; break; }
			}
			if (!found)
				display_frame_add_target_ = first_id;
		}
		add_target_settings->SetContainer(DESC_CYCLE, target_cycle);
	}

	if (model_mode_ != MODEL_MODE_EDIT)
	{
		constexpr Int32 morph_add_ids[] = {
			MODEL_MORPH_GROUP_ADD_NAME, MODEL_MORPH_GROUP_ADD_BUTTON,
			MODEL_MORPH_FLIP_ADD_NAME, MODEL_MORPH_FLIP_ADD_BUTTON,
			MODEL_MORPH_MATERIAL_ADD_NAME, MODEL_MORPH_MATERIAL_ADD_BUTTON,
			MODEL_MORPH_IMPULSE_ADD_NAME, MODEL_MORPH_IMPULSE_ADD_BUTTON
		};
		for (const auto desc_id : morph_add_ids)
		{
			if (BaseContainer* settings = description->GetParameterI(CreateDescID(DescLevel(desc_id)), nullptr))
				settings->SetBool(DESC_HIDE, true);
		}
	}

	const DescID* single_id = description->GetSingleDescID();
	if (const auto cid = ConstDescID(DescLevel(MODEL_INFO_GRP)); single_id == nullptr || cid.IsPartOf(*single_id, nullptr))
	{
		if (BaseContainer* settings = description->GetParameterI(cid, nullptr))
			settings->SetBool(DESC_GROUPSCALEV, true);
	}
	flags |= DESCFLAGS_DESC::LOADED;

	return SUPER::GetDDescription(node, description, flags);
}
Bool MMDModelManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{ return SUPER::Message(node,type,data); };
	switch (type)
	{
	case g_mmd_mesh_manager_object_id:
	{
		if (static_cast<MMDMeshManagerObjectMsg*>(data)->type == MMDMeshManagerObjectMsgType::MESH_MORPH_CHANGE)
		{
			*is_morph_initialized_.Write() = false;
		}
		break;
	}
	case g_mmd_bone_manager_object_id:
	{
		if (static_cast<MMDBoneManagerObjectMsg*>(data)->type == MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE)
		{
			*is_morph_initialized_.Write() = false;
		}
		break;
	}
	case MSG_DESCRIPTION_COMMAND:
	{
		/* check if it is a user data button */
		if (const auto* dc = static_cast<DescriptionCommand*>(data); dc->_descId[0].id == ID_USERDATA)
		{
			if (const auto desc_id_ptr = desc_id_map_.Find(dc->_descId); desc_id_ptr != nullptr)
			{
				const auto& [desc_type, morph_index] = desc_id_ptr->GetValue();
				auto& morph = morph_data_[morph_index];
				switch (desc_type)
				{
				case MMDModelRootDynamicDescriptionType::MORPH_EDITOR_BUTTON:
				{
					EditorSubMorphDialog dlg(this, &morph);
					dlg.Open(DLG_TYPE::MODAL, 100000, -1, -1, 0, 0);
					break;
				}
				case  MMDModelRootDynamicDescriptionType::MORPH_DELETE_BUTTON:
				{
					if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph.GetName()))
					{
						DeleteMorph(morph_index);
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::MORPH_RENAME_BUTTON:
				{
					auto new_name = morph.GetName();
					if (RenameDialog(&new_name))
					{
						RenameMorph(new_name);
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::MORPH_STRENGTH:
				case MMDModelRootDynamicDescriptionType::MORPH_GRP:
				case MMDModelRootDynamicDescriptionType::IK_BONE_LINK:
				case MMDModelRootDynamicDescriptionType::IK_SOLVER_ENABLE:
					break;
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_DELETE_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index >= 0 && entry_index < static_cast<Int>(targets.GetCount()))
						{
							targets.Erase(entry_index)iferr_ignore("erase failed");
							RefreshDisplayFrameUI();
						}
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_UP_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index > 0 && entry_index < static_cast<Int>(targets.GetCount()))
						{
							std::swap(targets[entry_index], targets[entry_index - 1]);
							RefreshDisplayFrameUI();
						}
					}
					break;
				}
				case MMDModelRootDynamicDescriptionType::DISPLAY_FRAME_MOVE_DOWN_BUTTON:
				{
					const Int entry_index = desc_id_ptr->GetValue().second;
					if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
					{
						auto& targets = display_frame_list_[display_frame_selection_index_].targets;
						if (entry_index >= 0 && entry_index < static_cast<Int>(targets.GetCount()) - 1)
						{
							std::swap(targets[entry_index], targets[entry_index + 1]);
							RefreshDisplayFrameUI();
						}
					}
					break;
				}
				}
			}
		}
		else {
			switch (const auto id = dc->_descId[0].id)
			{
			case MODEL_MORPH_GROUP_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_GROUP_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::GROUP, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_FLIP_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_FLIP_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::FLIP, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_MATERIAL_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_MATERIAL_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::MATERIAL, ge_data.GetString());
				break;
			}
			case MODEL_MORPH_IMPULSE_ADD_BUTTON:
			{
				GeData ge_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MORPH_IMPULSE_ADD_NAME)), ge_data, DESCFLAGS_GET::NONE);
				AddMorph(MMDMorphType::IMPULSE, ge_data.GetString());
				break;
			}
			case MODEL_DISPLAY_FRAME_ADD_BUTTON:
			{
				if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount()
				&& !display_frame_add_target_empty_)
				{
				DisplayFrameTargetData td;
				td.type = (display_frame_add_type_ == MODEL_DISPLAY_FRAME_ADD_TYPE_BONE)
					? DisplayFrameTargetType::Bone : DisplayFrameTargetType::Morph;
				td.index = display_frame_add_target_;
				iferr(display_frame_list_[display_frame_selection_index_].targets.Append(td)) break;
					RefreshDisplayFrameUI();
				}
				break;
			}
			case MODEL_DISPLAY_FRAME_NEW_BUTTON:
			{
				GeData name_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_DISPLAY_FRAME_NEW_NAME)), name_data, DESCFLAGS_GET::NONE);
				DisplayFrameData df;
				df.name = name_data.GetString();
				if (df.name.IsEmpty())
					df.name = FormatString("Frame @", display_frame_list_.GetCount());
				iferr(display_frame_list_.Append(std::move(df))) break;
				display_frame_selection_index_ = static_cast<Int32>(display_frame_list_.GetCount()) - 1;
				RefreshDisplayFrameUI();
				break;
			}
			case MODEL_DISPLAY_FRAME_DELETE_BUTTON:
			{
				if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
				{
					display_frame_list_.Erase(display_frame_selection_index_)iferr_ignore("erase failed");
					if (display_frame_selection_index_ >= display_frame_list_.GetCount())
						display_frame_selection_index_ = static_cast<Int32>(display_frame_list_.GetCount()) - 1;
					RefreshDisplayFrameUI();
				}
				break;
			}
			case MODEL_ANIM_MERGE_VMD_BUTTON: [[fallthrough]];
			case MODEL_ANIM_LOAD_VMD_BUTTON:
			{
			CMTToolsSetting::MotionImport setting(GetActiveDocument());
			if(!filename_util::SelectSuffixImportFile(setting.fn, "vmd"_s))
			{
				break;
			}
			{
				const auto* bc = reinterpret_cast<BaseList2D*>(Get())->GetDataInstance();
				if (bc)
					setting.position_multiple = bc->GetFloat(MODEL_POSITION_MULTIPLE, 8.5);
			}
				LoadVmdMotionLog logger;
				std::vector<uint8_t> file_data;
				if (!filename_util::ReadFileData(setting.fn, file_data))
				{
					LoadVmdMotionLog::LogReadFileErr();
					break;
				}
				libmmd::VMDFile vmd_file;
				if (!ReadVMDFile(&vmd_file, file_data.data(), file_data.size()))
				{
					LoadVmdMotionLog::LogReadFileErr();
					break;
				}
				if (!LoadVMDMotion(vmd_file, setting, logger, id == MODEL_ANIM_MERGE_VMD_BUTTON))
				{
					break;
				}
				setting.doc->SetTime(BaseTime(1, 30.));
				setting.doc->SetTime(BaseTime(0, 30.));
				EventAdd();
				logger.LogOK(setting.detail_report);
				break;
			}
			case MODEL_ANIM_DElETE_BUTTON:
			{
				DeleteVMDAnimation();
				break;
			}
			case MODEL_ANIM_IMPORT_VPD_BUTTON:
			{
				CMTToolsSetting::PoseImport setting(GetActiveDocument());
				if (!filename_util::SelectSuffixImportFile(setting.fn, "vpd"_s))
					break;

				CMTToolsManager::ImportVPDPose(setting, reinterpret_cast<BaseObject*>(node));
				break;
			}
			case MODEL_ANIM_EXPORT_VPD_BUTTON:
			{
				CMTToolsSetting::PoseExport setting(GetActiveDocument());
				if (!filename_util::SelectSuffixExportFile(setting.fn, "vpd"_s))
					break;

				CMTToolsManager::ExportVPDPose(setting, reinterpret_cast<BaseObject*>(node));
				break;
			}
			case MODEL_ANIM_REGISTER_CURRENT_BUTTON:
			{
				RegisterCurrentStateKeyframe(GetActiveDocument());
				break;
			}
			case MODEL_ANIM_DELETE_CURRENT_FRAME_BUTTON:
			{
				DeleteCurrentFrameKeyframes(GetActiveDocument());
				break;
			}
			case MODEL_MATERIAL_CREATE_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					GeData type_data;
					node->GetParameter(ConstDescID(DescLevel(MODEL_MATERIAL_CREATE_TYPE)), type_data, DESCFLAGS_GET::NONE);
					constexpr MMDRendererMaterialType type_map[] = {
						MMDRendererMaterialType::Standard, MMDRendererMaterialType::RedShift,
						MMDRendererMaterialType::Octane,   MMDRendererMaterialType::Corona
					};
					const Int32 type_idx = type_data.GetInt32();
					const MMDRendererMaterialType rt = (type_idx >= 0 && type_idx < 4) ? type_map[type_idx] : MMDRendererMaterialType::Standard;
					BaseMaterial* new_mat = CreateMaterialFromData(mat, rt);
					if (new_mat)
					{
						BaseDocument* doc = node->GetDocument();
						if (doc)
						{
							doc->InsertMaterial(new_mat);
							if (!mat.material_link)
								mat.material_link = NewObj(AutoAlloc<BaseLink>).GetValue();
							if (mat.material_link && *mat.material_link)
								(*mat.material_link)->SetLink(new_mat);
							EventAdd();
						}
					}
				}
				break;
			}
			case MODEL_MATERIAL_SYNC_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc && mat.material_link && *mat.material_link)
					{
						BaseMaterial* linked_mat = static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc));
						if (linked_mat)
							SyncToMaterial(mat, linked_mat);
						EventAdd();
					}
				}
				break;
			}
			case MODEL_MATERIAL_REVERSE_SYNC_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc && mat.material_link && *mat.material_link)
					{
						BaseMaterial* linked_mat = static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc));
						if (linked_mat)
							ReadFromMaterial(linked_mat, mat);
						EventAdd();
					}
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_UP_BUTTON:
			{
				if (material_selection_index_ > 0 && material_selection_index_ < material_list_.GetCount())
				{
					std::swap(material_list_[material_selection_index_], material_list_[material_selection_index_ - 1]);
					material_selection_index_--;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_DOWN_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount() - 1)
				{
					std::swap(material_list_[material_selection_index_], material_list_[material_selection_index_ + 1]);
					material_selection_index_++;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATERIAL_DELETE_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					if (!QuestionDialog(IDS_MES_MATERIAL_DELETE_CONFIRM))
						break;
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc)
					{
						doc->StartUndo();
						doc->AddUndo(UNDOTYPE::CHANGE, node);
						if (mat.mesh_link && *mat.mesh_link)
						{
							BaseObject* mesh_obj = static_cast<BaseObject*>((*mat.mesh_link)->GetLink(doc));
							if (mesh_obj)
							{
								if (mat.selection_name.IsPopulated())
								{
									SelectionTag* sel_tag = nullptr;
									for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
									{
										if (tag->GetType() == Tpolygonselection
											&& tag->GetName().Compare(mat.selection_name) == maxon::COMPARERESULT::EQUAL)
										{
											sel_tag = static_cast<SelectionTag*>(tag);
											break;
										}
									}
									if (sel_tag)
									{
										PolygonObject* poly_obj = ToPoly(mesh_obj);
										if (poly_obj)
										{
											doc->AddUndo(UNDOTYPE::CHANGE, mesh_obj);
											const BaseSelect* poly_sel_const = poly_obj->GetPolygonS();
											BaseSelect* poly_sel = const_cast<BaseSelect*>(poly_sel_const);
											if (poly_sel)
											{
												poly_sel->DeselectAll();
												const_cast<BaseSelect*>(sel_tag->GetBaseSelect())->CopyTo(poly_sel);
												ModelingCommandData mcd;
												mcd.doc = doc;
												mcd.op = mesh_obj;
												mcd.mode = MODELINGCOMMANDMODE::POLYGONSELECTION;
												if (SendModelingCommand(MCOMMAND_DELETE, mcd))
												{
													BaseContainer opt;
													opt.SetBool(MDATA_OPTIMIZE_UNUSEDPOINTS, true);
													mcd.bc = &opt;
													mcd.mode = MODELINGCOMMANDMODE::ALL;
													SendModelingCommand(MCOMMAND_OPTIMIZE, mcd);
												}
											}
										}
										doc->AddUndo(UNDOTYPE::DELETEOBJ, sel_tag);
										sel_tag->Remove();
										BaseTag* tmp_sel_tag = sel_tag;
										BaseTag::Free(tmp_sel_tag);
									}
									for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
									{
										if (tag->GetType() == Ttexture)
										{
											GeData sel_data;
											tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
											if (sel_data.GetString().Compare(mat.selection_name) == maxon::COMPARERESULT::EQUAL)
											{
												doc->AddUndo(UNDOTYPE::DELETEOBJ, tag);
												tag->Remove();
												BaseTag::Free(tag);
												break;
											}
										}
									}
								}
								else
								{
									doc->AddUndo(UNDOTYPE::DELETEOBJ, mesh_obj);
									mesh_obj->Remove();
									BaseObject::Free(mesh_obj);
								}
							}
						}
					}
					material_list_.Erase(material_selection_index_) iferr_ignore("erase failed"_s);
					if (material_selection_index_ >= material_list_.GetCount())
						material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
					if (mesh_manager_data_)
					{
						mesh_manager_data_->RequestMorphDataRefresh();
						*is_morph_initialized_.Write() = false;
					}
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
					if (doc)
						doc->EndUndo();
				}
				break;
			}
			case MODEL_MATERIAL_ADD_BUTTON:
			{
				BaseDocument* doc = node->GetDocument();
				BaseObject* mesh_mgr_obj = GetMeshManagerObject();
				if (!doc || !mesh_mgr_obj)
					break;
				auto HasMaterialEntry = [this, doc](BaseObject* mesh_obj, const String& sel_name) -> Bool
				{
					for (const auto& m : material_list_)
					{
						if (!m.mesh_link || !*m.mesh_link)
							continue;
						if (static_cast<BaseObject*>((*m.mesh_link)->GetLink(doc)) != mesh_obj)
							continue;
						if ((sel_name.IsEmpty() && m.selection_name.IsEmpty()) ||
							(sel_name.IsPopulated() && m.selection_name == sel_name))
							return true;
					}
					return false;
				};
				auto FindExistingMaterial = [doc](BaseObject* mesh_obj, const String& sel_name) -> BaseMaterial*
				{
					for (BaseTag* tag = mesh_obj->GetFirstTag(); tag; tag = tag->GetNext())
					{
						if (tag->GetType() != Ttexture)
							continue;
						GeData sel_data;
						tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
						if (sel_data.GetString() != sel_name)
							continue;
						GeData mat_data;
						tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), mat_data, DESCFLAGS_GET::NONE);
						BaseMaterial* mat = static_cast<BaseMaterial*>(mat_data.GetLink(doc));
						if (mat)
							return mat;
					}
					return nullptr;
				};
				GeData type_data;
				node->GetParameter(ConstDescID(DescLevel(MODEL_MATERIAL_CREATE_TYPE)), type_data, DESCFLAGS_GET::NONE);
				constexpr MMDRendererMaterialType type_map[] = {
					MMDRendererMaterialType::Standard, MMDRendererMaterialType::RedShift,
					MMDRendererMaterialType::Octane,   MMDRendererMaterialType::Corona
				};
				const Int32 type_idx = type_data.GetInt32();
				const MMDRendererMaterialType create_type = (type_idx >= 0 && type_idx < 4) ? type_map[type_idx] : MMDRendererMaterialType::Standard;
				auto AddMaterialEntry = [&](BaseObject* child, const String& sel_name, const String& display_name) -> Bool
				{
					MMDMaterialData new_mat;
					new_mat.name_local = new_mat.name_universal = display_name;
					new_mat.mesh_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
					if (new_mat.mesh_link && *new_mat.mesh_link)
						(*new_mat.mesh_link)->SetLink(child);
					new_mat.selection_name = sel_name;
					BaseMaterial* existing_mat = FindExistingMaterial(child, sel_name);
					if (existing_mat)
					{
						ReadFromMaterial(existing_mat, new_mat);
						new_mat.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
						if (new_mat.material_link && *new_mat.material_link)
							(*new_mat.material_link)->SetLink(existing_mat);
					}
					else
					{
						BaseMaterial* c4d_mat = CreateMaterialFromData(new_mat, create_type);
						if (c4d_mat)
						{
							doc->InsertMaterial(c4d_mat);
							doc->AddUndo(UNDOTYPE::NEWOBJ, c4d_mat);
							new_mat.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create().GetValue();
							if (new_mat.material_link && *new_mat.material_link)
								(*new_mat.material_link)->SetLink(c4d_mat);
							TextureTag* tex_tag = TextureTag::Alloc();
							if (tex_tag)
							{
								tex_tag->SetName(display_name);
								tex_tag->SetMaterial(c4d_mat);
								tex_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_PROJECTION)), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
								if (sel_name.IsPopulated())
									tex_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_name, DESCFLAGS_SET::NONE);
								child->InsertTag(tex_tag);
								doc->AddUndo(UNDOTYPE::NEWOBJ, tex_tag);
							}
						}
					}
					iferr(material_list_.Append(std::move(new_mat)))
						return false;
					return true;
				};
				Bool added = false;
				doc->StartUndo();
				doc->AddUndo(UNDOTYPE::CHANGE, node);
				for (BaseObject* child = mesh_mgr_obj->GetDown(); child; child = child->GetNext())
				{
					if (child->GetType() != Opolygon)
						continue;
					Bool has_sel_tags = false;
					for (BaseTag* tag = child->GetFirstTag(); tag; tag = tag->GetNext())
					{
						if (tag->GetType() == Tpolygonselection)
						{
							has_sel_tags = true;
							const String tag_name = tag->GetName();
							if (!HasMaterialEntry(child, tag_name))
							{
								if (AddMaterialEntry(child, tag_name, tag_name))
									added = true;
							}
						}
					}
					if (!has_sel_tags && !HasMaterialEntry(child, ""_s))
					{
						if (AddMaterialEntry(child, ""_s, child->GetName()))
							added = true;
					}
				}
				if (added)
				{
					material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				doc->EndUndo();
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case MSG_MENUPREPARE:
	{
		CreateManagers();
		InvalidateStandaloneRuntime();
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

SDK2024_GetDParameter(MMDModelManagerObject)
{
#if API_VERSION < 2024000
	GeListNode* paramNode = node;
#else
	const GeListNode* paramNode = node;
#endif

	switch (id[0].id)
	{
	case MODEL_MODE:
		t_data.SetInt32(model_mode_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_ANIM_LIST:
		t_data.SetInt32(animation_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATERIAL_LIST:
		t_data.SetInt32(material_selection_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_LIST:
		t_data.SetInt32(display_frame_selection_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_NAME_LOCAL:
		if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			t_data.SetString(display_frame_list_[display_frame_selection_index_].name);
		else
			t_data.SetString(""_s);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
		if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			t_data.SetString(display_frame_list_[display_frame_selection_index_].name_universal);
		else
			t_data.SetString(""_s);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_ADD_TYPE:
		t_data.SetInt32(display_frame_add_type_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_DISPLAY_FRAME_ADD_TARGET:
		t_data.SetInt32(display_frame_add_target_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	default:
		break;
	}

	const Int32 sel = material_selection_index_;
	if (sel < 0 || sel >= material_list_.GetCount())
	{
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	}
	const MMDMaterialData& m = material_list_[sel];
	switch (id[0].id)
	{
	case MODEL_MATERIAL_LINK:
		if (m.material_link && *m.material_link)
		{
			const BaseDocument* doc = paramNode->GetDocument();
			t_data.SetBaseList2D(const_cast<BaseList2D*>(doc ? (*m.material_link)->GetLink(doc) : nullptr));
		}
		else
			t_data.SetBaseList2D(nullptr);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	case MODEL_MATERIAL_NAME_LOCAL: t_data.SetString(m.name_local); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_NAME_UNIVERSAL: t_data.SetString(m.name_universal); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DIFFUSE_COLOR: HandleDescGetVector(id, m.diffuse_rgb, t_data, flags); return true;
	case MODEL_MATERIAL_DIFFUSE_ALPHA: t_data.SetFloat(m.diffuse_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPECULAR_COLOR: HandleDescGetVector(id, m.specular, t_data, flags); return true;
	case MODEL_MATERIAL_SPECULAR_POWER: t_data.SetFloat(m.specular_power); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_AMBIENT_COLOR: HandleDescGetVector(id, m.ambient, t_data, flags); return true;
	case MODEL_MATERIAL_DRAW_BOTH_FACE: t_data.SetInt32(m.draw_both_face ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_GROUND_SHADOW: t_data.SetInt32(m.draw_ground_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_CAST_SELF_SHADOW: t_data.SetInt32(m.draw_cast_self_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_RECEIVE_SELF_SHADOW: t_data.SetInt32(m.draw_receive_self_shadow ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_DRAW_VERTEX_COLOR: t_data.SetInt32(m.draw_vertex_color ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_ENABLED: t_data.SetInt32(m.edge_enabled ? 1 : 0); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_SIZE: t_data.SetFloat(m.edge_size); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_EDGE_COLOR: HandleDescGetVector(id, m.edge_color_rgb, t_data, flags); return true;
	case MODEL_MATERIAL_EDGE_ALPHA: t_data.SetFloat(m.edge_color_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TEXTURE_PATH: t_data.SetString(m.texture_path); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPHERE_TEXTURE_PATH: t_data.SetString(m.sphere_texture_path); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_SPHERE_MODE: t_data.SetInt32(m.sphere_mode); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_MODE: t_data.SetInt32(m.toon_mode); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_TEXTURE_INDEX: t_data.SetInt32(m.toon_texture_index); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_TOON_TEXTURE_PATH:
		if (m.toon_texture_index >= 0 && m.toon_texture_path.IsEmpty())
		{
			Char buf[20];
			snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(m.toon_texture_index + 1));
			t_data.SetString((GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString());
		}
		else
			t_data.SetString(m.toon_texture_path);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATERIAL_MEMO: t_data.SetString(m.memo); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_FACE_COUNT: t_data.SetString(String::IntToString(m.num_face_vertices / 3)); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	case MODEL_MATERIAL_MESH_LINK:
		if (m.mesh_link && *m.mesh_link)
		{
			const BaseDocument* doc = paramNode->GetDocument();
			t_data.SetBaseList2D(const_cast<BaseList2D*>(doc ? (*m.mesh_link)->GetLink(doc) : nullptr));
		}
		else
			t_data.SetBaseList2D(nullptr);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return SUPER::GetDParameter(paramNode, id, t_data, flags);
	case MODEL_MATERIAL_SELECTION: t_data.SetString(m.selection_name); flags |= DESCFLAGS_GET::PARAM_GET; return true;
	default:
		break;
	}
	return SUPER::GetDParameter(paramNode, id, t_data, flags);
}

Bool MMDModelManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
		case MODEL_POSITION_MULTIPLE:
		{
			SyncSubManagerScale(t_data.GetFloat());
			break;
		}
		case MODEL_MODE:
		{
			const GeData normalized_mode(NormalizeModelMode(t_data.GetInt32()));
			const Int32 previous_mode = model_mode_;
			const Int32 next_mode = normalized_mode.GetInt32();
			BaseDocument* const doc = reinterpret_cast<BaseList2D*>(node)->GetDocument();
			if (previous_mode != next_mode)
				ClearTransientVPDPoseState(doc);
			if (previous_mode == MODEL_MODE_EDIT && next_mode == MODEL_MODE_ANIM)
				CommitEditModeBindState(doc);
			else if (previous_mode == MODEL_MODE_ANIM && next_mode == MODEL_MODE_EDIT)
				RestoreBindStateForEdit(doc);

			model_mode_ = normalized_mode.GetInt32();
			bone_manager_data_ = GetBoneManagerData();
			is_animation_initialized_ = false;
			prev_time_ = BaseTime(-1.);
			InvalidateStandaloneRuntime();
			MMDModelManagerObjectMsg msg(MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE, nullptr, model_mode_);
			node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_model_manager_object_id, &msg);
			if (bone_manager_data_)
			{
				BaseObject* const bone_manager_object = io_util::ResolveObjectLink(bone_manager_);
				bone_manager_data_->SetAllBoneMode(model_mode_, bone_manager_object);
				if (model_mode_ == MODEL_MODE_EDIT)
					bone_manager_data_->SetBoneDisplayType(BONE_DISPLAY_TYPE_ON, bone_manager_object);
				else if (model_mode_ == MODEL_MODE_ANIM)
					bone_manager_data_->SetBoneDisplayType(BONE_DISPLAY_TYPE_OFF, bone_manager_object);
			}
			if (rigid_manager_data_ || GetRigidManagerData())
				rigid_manager_data_->SetAllRigidMode(model_mode_, io_util::ResolveObjectLink(rigid_manager_));
			if (joint_manager_data_ || GetJointManagerData())
				joint_manager_data_->SetAllJointMode(model_mode_, io_util::ResolveObjectLink(joint_manager_));
			const Bool result = SUPER::SetDParameter(node, id, normalized_mode, flags);
			if (previous_mode == MODEL_MODE_EDIT && model_mode_ == MODEL_MODE_ANIM)
			{
				if (!RebuildMorphTracksFromAnimationSlot(animation_index_))
					return false;
				ClearMorphAnimationSlots();
				std::ignore = EnsureStandaloneRuntimeManagers();
			}
			return result;
		}
		case MODEL_ANIM_LIST:
		{
			animation_index_ = t_data.GetInt32();
			is_animation_initialized_ = false;
			prev_time_ = BaseTime(-1.);
			const auto doc = node->GetDocument();
			ApplyAnimationSlotSelection(doc);
			InvalidateStandaloneRuntime();
			break;
		}
		case MODEL_PHYSICS_ENABLED:
		case MODEL_PHYSICS_GRAVITY_STRENGTH:
		case MODEL_PHYSICS_GRAVITY_DIRECTION:
		case MODEL_PHYSICS_RESET_ON_SEEK:
		{
			prev_time_ = BaseTime(-1.);
			is_animation_initialized_ = false;
			const Bool result = SUPER::SetDParameter(node, id, t_data, flags);
			ApplyPhysicsConfigToRuntime(reinterpret_cast<BaseObject*>(node));
			return result;
		}
		case MODEL_MATERIAL_LIST:
			material_selection_index_ = t_data.GetInt32();
			break;
		case MODEL_DISPLAY_FRAME_LIST:
			display_frame_selection_index_ = t_data.GetInt32();
			RefreshDisplayFrameUI();
			break;
		case MODEL_DISPLAY_FRAME_NAME_LOCAL:
			if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			{
				display_frame_list_[display_frame_selection_index_].name = t_data.GetString();
				flags |= DESCFLAGS_SET::PARAM_SET;
				return true;
			}
			break;
		case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
			if (display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount())
			{
				display_frame_list_[display_frame_selection_index_].name_universal = t_data.GetString();
				flags |= DESCFLAGS_SET::PARAM_SET;
				return true;
			}
			break;
		case MODEL_DISPLAY_FRAME_ADD_TYPE:
			display_frame_add_type_ = t_data.GetInt32();
			node->SetDirty(DIRTYFLAGS::DESCRIPTION);
			::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
			EventAdd();
			break;
		case MODEL_DISPLAY_FRAME_ADD_TARGET:
			display_frame_add_target_ = t_data.GetInt32();
			break;
		default:
		{
			if (id[0].id == ID_USERDATA)
			{
				for (const auto& p : ik_solver_dynamic_params_)
				{
					if (p.first != id)
						continue;
					const Bool enabled = t_data.GetBool();
					if (ik_manager_own_)
					{
						if (auto* solver = ik_manager_own_->GetMMDIKSolver(static_cast<size_t>(p.second)))
						{
							solver->Enable(enabled);
							iferr(ik_solver_enable_states_.Insert(String(solver->GetName().c_str()), enabled)) {}
						}
					}
					prev_time_ = BaseTime(-1.);
					return SUPER::SetDParameter(node, id, t_data, flags);
				}
			}

			Bool material_handled = false;
			if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			{
				MMDMaterialData& mat = material_list_[material_selection_index_];
				switch (id[0].id)
				{
				case MODEL_MATERIAL_LINK:
				{
					BaseDocument* doc = node->GetDocument();
					BaseMaterial* link_mat = static_cast<BaseMaterial*>(t_data.GetLink(doc));
					if (!mat.material_link || !*mat.material_link)
					{
						auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
						if (link_result == maxon::FAILED)
							break;
						mat.material_link = link_result.GetValue();
						if (mat.material_link && *mat.material_link)
							(*mat.material_link)->SetLink(link_mat);
					}
					else
						(*mat.material_link)->SetLink(link_mat);
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_NAME_LOCAL: mat.name_local = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_NAME_UNIVERSAL: mat.name_universal = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_DIFFUSE_COLOR: mat.diffuse_rgb = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_DIFFUSE_ALPHA: mat.diffuse_alpha = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_SPECULAR_COLOR: mat.specular = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_SPECULAR_POWER: mat.specular_power = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_AMBIENT_COLOR: mat.ambient = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_BOTH_FACE: mat.draw_both_face = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_GROUND_SHADOW: mat.draw_ground_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_CAST_SELF_SHADOW: mat.draw_cast_self_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_RECEIVE_SELF_SHADOW: mat.draw_receive_self_shadow = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_DRAW_VERTEX_COLOR: mat.draw_vertex_color = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_ENABLED: mat.edge_enabled = t_data.GetBool(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_SIZE: mat.edge_size = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_COLOR: mat.edge_color_rgb = t_data.GetVector(); material_handled = true; break;
				case MODEL_MATERIAL_EDGE_ALPHA: mat.edge_color_alpha = t_data.GetFloat(); material_handled = true; break;
				case MODEL_MATERIAL_TEXTURE_PATH: mat.texture_path = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_SPHERE_TEXTURE_PATH: mat.sphere_texture_path = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_SPHERE_MODE: mat.sphere_mode = t_data.GetInt32(); material_handled = true; break;
				case MODEL_MATERIAL_TOON_MODE:
				{
					mat.toon_mode = t_data.GetInt32();
					if (mat.toon_mode == 1 && mat.toon_texture_index >= 0)
					{
						Char buf[20];
						snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
						mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
					}
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_TOON_TEXTURE_INDEX:
				{
					mat.toon_texture_index = t_data.GetInt32();
					if (mat.toon_mode == 1 && mat.toon_texture_index >= 0)
					{
						Char buf[20];
						snprintf(buf, sizeof(buf), "toon%02d.bmp", static_cast<int>(mat.toon_texture_index + 1));
						mat.toon_texture_path = (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(buf)).GetString();
					}
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_TOON_TEXTURE_PATH:
					if (mat.toon_texture_index == -1)
						mat.toon_texture_path = t_data.GetString();
					material_handled = true;
					break;
				case MODEL_MATERIAL_MEMO: mat.memo = t_data.GetString(); material_handled = true; break;
				case MODEL_MATERIAL_MESH_LINK:
				{
					BaseDocument* doc = node->GetDocument();
					BaseObject* link_obj = static_cast<BaseObject*>(t_data.GetLink(doc));
					if (!mat.mesh_link || !*mat.mesh_link)
					{
						auto link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
						if (link_result == maxon::FAILED)
							break;
						mat.mesh_link = link_result.GetValue();
						if (mat.mesh_link && *mat.mesh_link)
							(*mat.mesh_link)->SetLink(link_obj);
					}
					else
						(*mat.mesh_link)->SetLink(link_obj);
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_SELECTION: mat.selection_name = t_data.GetString(); material_handled = true; break;
				default: break;
				}
				if (material_handled)
				{
					BaseDocument* doc = node->GetDocument();
					BaseMaterial* linked_mat = doc && mat.material_link && *mat.material_link
						? static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc))
						: nullptr;
					if (linked_mat)
						SyncToMaterial(mat, linked_mat);
					flags |= DESCFLAGS_SET::PARAM_SET;
					return true;
				}
			}
			if (material_handled)
				return true;
			break;
		}
	}
	return ObjectData::SetDParameter(node, id, t_data, flags);
}

SDK2024_GetDEnabling(MMDModelManagerObject)
{
	if (id[0].id == ID_USERDATA)
	{
		for (const auto& p : ik_solver_dynamic_params_)
		{
			if (p.first == id)
				return true;
		}
	}
	if (id[0].id >= MODEL_MATERIAL_NAME_LOCAL && id[0].id < MODEL_MATERIAL_ADD_BUTTON)
	{
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	}
	switch (id[0].id)
	{
	case MODEL_DISPLAY_FRAME_NAME_LOCAL:
	case MODEL_DISPLAY_FRAME_NAME_UNIVERSAL:
	case MODEL_DISPLAY_FRAME_ADD_TYPE:
	case MODEL_DISPLAY_FRAME_ADD_TARGET:
	case MODEL_DISPLAY_FRAME_DELETE_BUTTON:
		return display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount();
	case MODEL_DISPLAY_FRAME_ADD_BUTTON:
		return display_frame_selection_index_ >= 0 && display_frame_selection_index_ < display_frame_list_.GetCount()
			&& !display_frame_add_target_empty_;
	case MODEL_MATERIAL_EDGE_SIZE:
	case MODEL_MATERIAL_EDGE_COLOR:
	case MODEL_MATERIAL_EDGE_ALPHA:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			return material_list_[material_selection_index_].edge_enabled;
		return false;
	case MODEL_MATERIAL_TOON_TEXTURE_INDEX:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
			return material_list_[material_selection_index_].toon_mode == 1;
		return false;
	case MODEL_MATERIAL_CREATE_BUTTON:
	case MODEL_MATERIAL_CREATE_TYPE:
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	case MODEL_MATERIAL_MOVE_UP_BUTTON:
		return material_selection_index_ > 0;
	case MODEL_MATERIAL_MOVE_DOWN_BUTTON:
		return material_selection_index_ >= 0 && material_selection_index_ < static_cast<Int32>(material_list_.GetCount()) - 1;
	case MODEL_MATERIAL_DELETE_BUTTON:
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	case MODEL_MATERIAL_SYNC_BUTTON:
	case MODEL_MATERIAL_REVERSE_SYNC_BUTTON:
		if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
		{
			const auto& mat = material_list_[material_selection_index_];
			if (mat.material_link && *mat.material_link)
			{
				SDK2024_Const BaseDocument* doc = node->GetDocument();
				return doc && (*mat.material_link)->GetLink(doc) != nullptr;
			}
		}
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

Int MMDModelManagerObject::AddMorph(const MMDMorphType& morph_type, String morph_name, bool is_add_morph_ui, Int32 panel)
{
	Int index = -1;
	iferr_scope_handler{ return index; };
	IMorph* morph = nullptr;
	switch (morph_type)
	{
	case MMDMorphType::GROUP:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Group morph @", GetMorphNamedNumber());
		}
		morph = NewObj(GroupMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::FLIP:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Flip morph @", GetMorphNamedNumber());
		}
		morph = NewObj(FlipMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::MESH:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Mesh morph @", GetMorphNamedNumber());
		}
		morph = NewObj(MeshMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::UV:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("UV morph @", GetMorphNamedNumber());
		}
		morph = NewObj(UVMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::BONE:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Bone morph @", GetMorphNamedNumber());
		}
		morph = NewObj(BoneMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::MATERIAL:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Material morph @", GetMorphNamedNumber());
		}
		morph = NewObj(MaterialMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::IMPULSE:
		if (morph_name.IsEmpty())
		{
			morph_name = FormatString("Impulse morph @", GetMorphNamedNumber());
		}
		morph = NewObj(ImpulseMorph, morph_name)iferr_return;
		break;
	case MMDMorphType::DEFAULT:
		break;
	}
	if(!morph)
		return index;
	morph->SetPanel(panel);
	morph_data_.AppendPtr(morph)iferr_return;
	index = morph_data_.GetIndex(*morph);
	iferr(morph_name_.Insert(morph_name, index))
	{
		morph_data_.Erase(index)iferr_return;
		index = -1;
		return index;
	}
	if (is_add_morph_ui)
	{
		morph->AddMorphUI(*this, index);
		// Dynamic DTYPE_REAL defaults to 1.0; MMD morph weight is 0 until posed.
		if (GeListNode* const self = Get())
			morph->SetStrength(self, 0.0);
	}
	return index;
}

void MMDModelManagerObject::RenameMorph(const String& name)
{
	DynamicDescription* const dynamic_description = Get()->GetDynamicDescriptionWritable();
	if (dynamic_description == nullptr)
		return;
	if(const auto morph_id_ptr = morph_name_.Find(name); morph_id_ptr)
	{
		if (const auto& index = morph_id_ptr->GetValue(); index < GetMorphNum())
		{
			iferr(morph_name_.Insert(name, index))
				return;
			iferr(morph_name_.Erase(morph_id_ptr))
				return;
			auto& morph = morph_data_[index];
			const DescID& strength_id = morph.GetStrengthDescID();
			BaseContainer description_bc = *dynamic_description->Find(strength_id);
			description_bc.SetString(DESC_NAME, name);
			dynamic_description->Set(strength_id, description_bc, nullptr);
			morph.RenameMorph(name);
		}
	}

	::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (::GeIsMainThread())
	{
		::EventAdd();
	}
}

void MMDModelManagerObject::ApplyMorphRuntimeStrengths()
{
	GeListNode* const node = Get();
	const Int morph_count = morph_data_.GetCount();
	if (!node || morph_count <= 0)
		return;

	std::vector<Float> strengths(static_cast<size_t>(morph_count), 0.0);
	for (Int i = 0; i < morph_count; ++i)
		strengths[static_cast<size_t>(i)] = morph_data_[i].GetStrength(node);

	struct MorphStackEntry
	{
		Int index = -1;
		Float strength = 0.0;
		Int depth = 0;
	};

	std::vector<MorphStackEntry> stack;
	stack.reserve(static_cast<size_t>(morph_count));
	for (Int i = 0; i < morph_count; ++i)
	{
		const MMDMorphType type = morph_data_[i].GetType();
		if ((type == MMDMorphType::GROUP || type == MMDMorphType::FLIP) && strengths[static_cast<size_t>(i)] != 0.0)
			stack.push_back({ i, strengths[static_cast<size_t>(i)], 0 });
	}

	while (!stack.empty())
	{
		const MorphStackEntry entry = stack.back();
		stack.pop_back();
		if (entry.index < 0 || entry.index >= morph_count || entry.depth > morph_count)
			continue;

		IMorph& morph = morph_data_[entry.index];
		const MMDMorphType type = morph.GetType();
		if (type != MMDMorphType::GROUP && type != MMDMorphType::FLIP)
			continue;

		maxon::HashMap<Int, Float>* const sub_morphs = morph.GetSubMorphDataWritable();
		if (!sub_morphs)
			continue;

		const Float source_strength = (type == MMDMorphType::FLIP)
			? (entry.strength >= 0.5 ? 1.0 : 0.0)
			: entry.strength;
		if (source_strength == 0.0)
			continue;

		for (const auto& sub_morph : *sub_morphs)
		{
			const Int sub_index = sub_morph.GetKey();
			if (sub_index < 0 || sub_index >= morph_count || sub_index == entry.index)
				continue;

			const Float contribution = source_strength * sub_morph.GetValue();
			if (contribution == 0.0)
				continue;

			const MMDMorphType sub_type = morph_data_[sub_index].GetType();
			if (sub_type == MMDMorphType::GROUP || sub_type == MMDMorphType::FLIP)
				stack.push_back({ sub_index, contribution, entry.depth + 1 });
			else
				strengths[static_cast<size_t>(sub_index)] += contribution;
		}
	}

	for (Int i = 0; i < morph_count; ++i)
	{
		const MMDMorphType type = morph_data_[i].GetType();
		if (type == MMDMorphType::GROUP || type == MMDMorphType::FLIP)
			continue;
		ApplyMorphRuntimeStrength(morph_data_[i], strengths[static_cast<size_t>(i)]);
	}
}

void MMDModelManagerObject::ApplyMorphRuntimeStrength(IMorph& morph, const Float strength)
{
	switch (morph.GetType())
	{
	case MMDMorphType::MESH:
	case MMDMorphType::UV:
		if (mesh_manager_data_ || GetMeshManagerData())
			mesh_manager_data_->SetMorphStrength(morph.GetName(), strength);
		break;
	case MMDMorphType::BONE:
	{
		if (!(bone_manager_data_ || GetBoneManagerData()))
			break;
		auto& bone_morph_map = bone_manager_data_->GetBoneMorphMap();
		if (auto* entry = bone_morph_map.Find(morph.GetName()))
		{
			for (const auto& hub : entry->GetValue())
				hub.SetStrength(strength);
		}
		break;
	}
	default:
		break;
	}
}

void MMDModelManagerObject::DeleteMorph(const Int morph_index)
{
	if (auto& morph = morph_data_[morph_index]; !DeleteMorphImpl(morph, morph_index))
		return;
	std::ignore = morph_data_.Erase(morph_index);
}

bool MMDModelManagerObject::DeleteMorphImpl(IMorph& morph, const Int morph_index)
{
	iferr_scope_handler{ return false; };
	morph.DeleteMorphUI(*this);
	for (auto it = desc_id_map_.Begin(); it != desc_id_map_.End(); ++it)
	{
		auto& val = it->GetValue();
		switch (val.first)
		{
		case MMDModelRootDynamicDescriptionType::MORPH_GRP:
		case MMDModelRootDynamicDescriptionType::MORPH_STRENGTH:
		case MMDModelRootDynamicDescriptionType::MORPH_EDITOR_BUTTON:
		case MMDModelRootDynamicDescriptionType::MORPH_DELETE_BUTTON:
		case MMDModelRootDynamicDescriptionType::MORPH_RENAME_BUTTON:
			if (val.second > morph_index)
				val.second--;
			break;
		default:
			break;
		}
	}
	morph_name_.Erase(morph.GetName())iferr_return;
	for (auto& i : morph_name_.GetKeys())
	{
#if API_VERSION >= 24000
		if (auto* index = morph_name_.FindValue(i).ToPointer(); *index > morph_index)
#else
		if (auto* index = morph_name_.FindValue(i); index && *index > morph_index)
#endif
		{
			(*index)--;
		}
	}
	return true;
}

void MMDModelManagerObject::DeleteMorph(maxon::EraseIterator<maxon::PointerArray<IMorph>, false>& it)
{
	auto& morph = *it;
	if (const Int morph_index = it.FindIndex(morph); !DeleteMorphImpl(morph, morph_index))
		return;
	it.Erase();
}

void MMDModelManagerObject::SyncMaterialsList()
{
	BaseObject* mesh_mgr = GetMeshManagerObject();
	if (!mesh_mgr) return;

	BaseDocument* doc = mesh_mgr->GetDocument();
	if (!doc) return;

	struct MatRef {
		BaseMaterial* mat = nullptr;
		BaseObject* mesh = nullptr;
		String selection;
	};
	maxon::BaseArray<MatRef> active_refs;

	for (BaseObject* child = mesh_mgr->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(Opolygon))
			continue;
		for (BaseTag* tag = child->GetFirstTag(); tag; tag = tag->GetNext())
		{
			if (tag->GetType() == Ttexture)
			{
				GeData mat_data;
				tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), mat_data, DESCFLAGS_GET::NONE);
				BaseMaterial* mat = static_cast<BaseMaterial*>(mat_data.GetLink(doc));
				if (mat)
				{
					GeData sel_data;
					tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), sel_data, DESCFLAGS_GET::NONE);
					MatRef ref;
					ref.mat = mat;
					ref.mesh = child;
					ref.selection = sel_data.GetString();
					active_refs.Append(ref) iferr_ignore("append failed");
				}
			}
		}
	}

	Bool changed = false;

	// Remove unreferenced materials
	for (Int32 i = static_cast<Int32>(material_list_.GetCount()) - 1; i >= 0; --i)
	{
		auto& mmd_mat = material_list_[i];
		BaseMaterial* linked_mat = (mmd_mat.material_link && *mmd_mat.material_link) ? static_cast<BaseMaterial*>((*mmd_mat.material_link)->GetLink(doc)) : nullptr;
		BaseObject* linked_mesh = (mmd_mat.mesh_link && *mmd_mat.mesh_link) ? static_cast<BaseObject*>((*mmd_mat.mesh_link)->GetLink(doc)) : nullptr;
		
		Bool found = false;
		for (const auto& ref : active_refs)
		{
			if (ref.mat == linked_mat && ref.mesh == linked_mesh
				&& ref.selection.Compare(mmd_mat.selection_name) == maxon::COMPARERESULT::EQUAL)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			material_list_.Erase(i) iferr_ignore("erase failed");
			changed = true;
		}
	}

	// Add new materials
	for (const auto& ref : active_refs)
	{
		Bool found = false;
		for (Int32 i = 0; i < material_list_.GetCount(); ++i)
		{
			auto& mmd_mat = material_list_[i];
			BaseMaterial* linked_mat = (mmd_mat.material_link && *mmd_mat.material_link) ? static_cast<BaseMaterial*>((*mmd_mat.material_link)->GetLink(doc)) : nullptr;
			BaseObject* linked_mesh = (mmd_mat.mesh_link && *mmd_mat.mesh_link) ? static_cast<BaseObject*>((*mmd_mat.mesh_link)->GetLink(doc)) : nullptr;
			
			if (ref.mat == linked_mat && ref.mesh == linked_mesh
				&& ref.selection.Compare(mmd_mat.selection_name) == maxon::COMPARERESULT::EQUAL)
			{
				found = true;
				break;
			}
		}

		if (!found)
		{
			MMDMaterialData new_mat;
			new_mat.name_local = ref.mat->GetName();
			new_mat.name_universal = ref.mat->GetName();
			
			auto mat_link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
			if (mat_link_result == maxon::OK)
			{
				new_mat.material_link = mat_link_result.GetValue();
				if (new_mat.material_link && *new_mat.material_link)
					(*new_mat.material_link)->SetLink(ref.mat);
			}

			auto mesh_link_result = maxon::StrongRef<AutoAlloc<BaseLink>>::Create();
			if (mesh_link_result == maxon::OK)
			{
				new_mat.mesh_link = mesh_link_result.GetValue();
				if (new_mat.mesh_link && *new_mat.mesh_link)
					(*new_mat.mesh_link)->SetLink(ref.mesh);
			}
			
			new_mat.selection_name = ref.selection;
			
			new_mat.diffuse_rgb = Vector(1, 1, 1);
			new_mat.diffuse_alpha = 1.0;
			new_mat.ambient = Vector(0.5, 0.5, 0.5);
			new_mat.specular = Vector(0, 0, 0);
			new_mat.specular_power = 5.0;

			material_list_.Append(std::move(new_mat)) iferr_ignore("append failed");
			changed = true;
		}
	}

	if (changed)
	{
		if (material_selection_index_ >= material_list_.GetCount())
			material_selection_index_ = static_cast<Int32>(material_list_.GetCount()) - 1;
		if (material_selection_index_ < 0 && material_list_.GetCount() > 0)
			material_selection_index_ = 0;
			
		Get()->SetDirty(DIRTYFLAGS::DESCRIPTION);
		::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
		if (::GeIsMainThread())
			::EventAdd();
	}
}
