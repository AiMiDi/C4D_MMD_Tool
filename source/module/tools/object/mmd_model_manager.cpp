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
#include "module/tools/material/mmd_redshift_toon_material.h"
#include "module/tools/material/mmd_material_morph_binding.h"
#include "utils/cmt_pmx_export_scale.hpp"
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
#include "utils/cmt_motion_validation.hpp"
#include "utils/string_util.hpp"
#include "utils/cmt_runtime_profile.hpp"
#include "utils/cmt_anim_flow_debug.hpp"
#include "libMMD/Model/MMD/MMDIkSolver.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "libMMD/Model/MMD/SjisToUnicode.h"
#include "libMMD/Model/MMD/VMDInterpolation.h"



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

			if (morph.GetType() == MMDMorphType::MATERIAL)
			{
				const auto& material_morph = static_cast<const MaterialMorph&>(morph);
				pmx_morph.m_materialMorph.clear();
				pmx_morph.m_materialMorph.reserve(static_cast<size_t>(material_morph.GetOffsetCount()));
				for (const auto& offset : material_morph.GetOffsets())
				{
					libmmd::PMXFileMorph::MaterialMorph pmx_offset;
					offset.ToPMX(pmx_offset);
					// 目标索引 -1（全部材质）按原值保留，保证 round-trip。
					pmx_morph.m_materialMorph.push_back(pmx_offset);
				}
				continue;
			}

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
		std::int32_t result = 0;
		return cmt_motion_validation::TryAnimationFrame(frame, time_offset, result) ? result : 0;
	}

	Bool TryDocumentAnimationFrame(const BaseTime& time, Int32& result)
	{
		return cmt_motion_validation::TryDocumentFrame(time.GetNumerator(), time.GetDenominator(), kModelAnimationFps, result);
	}

	Int32 GetDocumentAnimationFrame(const BaseTime& time)
	{
		Int32 frame = 0;
		return TryDocumentAnimationFrame(time, frame) ? frame : 0;
	}

	UInt32 ToExportFrame(const Int32 source_frame, const Float offset)
	{
		std::uint32_t frame = 0;
		return cmt_motion_validation::TryExportFrame(source_frame, offset, frame) ? frame : 0;
	}

	Bool ValidateCurveExportFrames(CCurve* curve, const Float offset)
	{
		if (!curve)
			return true;
		for (Int32 index = 0; index < curve->GetKeyCount(); ++index)
		{
			const CKey* const key = curve->GetKey(index);
			Int32 source_frame = 0;
			std::uint32_t output_frame = 0;
			if (key && (!TryDocumentAnimationFrame(key->GetTime(), source_frame)
				|| !cmt_motion_validation::TryExportFrame(source_frame, offset, output_frame)))
				return false;
		}
		return true;
	}

	Bool ValidateMotionImport(const libmmd::VMDFile& file, const CMTToolsSetting::MotionImport& setting, const Float model_scale)
	{
		if (!cmt_motion_validation::IsFrameOffsetValid(setting.time_offset))
			return false;
		std::int32_t frame = 0;
		if (setting.import_motion)
		{
			const double ratio = setting.position_multiple / model_scale;
			for (const auto& key : file.m_motions)
			{
				if (!cmt_motion_validation::TryAnimationFrame(key.m_frame, setting.time_offset, frame)
					|| !cmt_motion_validation::IsPositionValid({key.m_translate.x(), key.m_translate.y(), key.m_translate.z()}, ratio)
					|| !cmt_motion_validation::IsQuaternionValid({key.m_quaternion.x(), key.m_quaternion.y(), key.m_quaternion.z(), key.m_quaternion.w()}))
					return false;
			}
		}
		if (setting.import_morph)
			for (const auto& key : file.m_morphs)
				if (!std::isfinite(key.m_weight) || !cmt_motion_validation::TryAnimationFrame(key.m_frame, setting.time_offset, frame))
					return false;
		if (setting.import_model_info)
			for (const auto& key : file.m_iks)
				if (!cmt_motion_validation::TryAnimationFrame(key.m_frame, setting.time_offset, frame))
					return false;
		return true;
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

	BoneAnimationKeyframeData ConvertMotionToBoneKeyframe(const libmmd::VMDMotion& motion, const CMTToolsSetting::MotionImport& setting, const Float model_scale)
	{
		BoneAnimationKeyframeData keyframe;
		keyframe.frame = ToAnimationFrame(motion.m_frame, setting.time_offset);
		keyframe.translation = Vector32(
			static_cast<Float32>(motion.m_translate.x() * setting.position_multiple / model_scale),
			static_cast<Float32>(motion.m_translate.y() * setting.position_multiple / model_scale),
			static_cast<Float32>(motion.m_translate.z() * setting.position_multiple / model_scale));
		const Eigen::Quaternionf rotation = motion.m_quaternion.cast<double>().normalized().cast<float>();
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

	libmmd::VMDMotion ConvertBoneKeyframeToMotion(const String& bone_name, const BoneAnimationKeyframeData& keyframe, const CMTToolsSetting::MotionExport& setting, const Float model_scale)
	{
		libmmd::VMDMotion motion;
		const std::string sjis_name = ConvertStringToSjis(bone_name);
		motion.m_boneName.Set(sjis_name.c_str());
		motion.m_frame = ToExportFrame(keyframe.frame, setting.time_offset);
		motion.m_translate = static_cast<float>(model_scale / setting.position_multiple) * Eigen::Vector3f(
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
		if (setting.import_model_info)
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
				morph_key.m_frame = ToExportFrame(GetDocumentAnimationFrame(key->GetTime()), setting.time_offset);
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
			morph_key.m_frame = ToExportFrame(keyframe.frame, setting.time_offset);
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

	Bool ReadStepKeys(HyperFile* hf, mmd_model_info::StepKeys& keys)
	{
		Int64 count = 0;
		if (!hf->ReadInt64(&count) || count < 0 || count > 10000000)
			return false;
		keys.clear();
		for (Int64 i = 0; i < count; ++i)
		{
			Int32 frame = 0;
			Bool value = true;
			if (!hf->ReadInt32(&frame) || frame < 0 || !hf->ReadBool(&value))
				return false;
			keys[frame] = value;
		}
		return true;
	}

	Bool WriteStepKeys(HyperFile* hf, const mmd_model_info::StepKeys& keys)
	{
		if (!hf->WriteInt64(static_cast<Int64>(keys.size())))
			return false;
		for (const auto& key : keys)
			if (!hf->WriteInt32(key.first) || !hf->WriteBool(key.second))
				return false;
		return true;
	}

	Bool ReadModelInfoSlot(HyperFile* hf, mmd_model_info::AnimationSlot& slot)
	{
		if (!ReadStepKeys(hf, slot.visibility))
			return false;
		Int64 count = 0;
		if (!hf->ReadInt64(&count) || count < 0 || count > 10000)
			return false;
		for (Int64 i = 0; i < count; ++i)
		{
			String name;
			Bool enabled = true;
			if (!hf->ReadString(&name) || !hf->ReadBool(&enabled))
				return false;
			slot.ik_defaults[string_util::GetStdString(name)] = enabled;
		}
		if (!hf->ReadInt64(&count) || count < 0 || count > 10000)
			return false;
		for (Int64 i = 0; i < count; ++i)
		{
			String name;
			if (!hf->ReadString(&name) || !ReadStepKeys(hf, slot.ik_channels[string_util::GetStdString(name)]))
				return false;
		}
		return true;
	}

	Bool WriteModelInfoSlot(HyperFile* hf, const mmd_model_info::AnimationSlot& slot)
	{
		if (!WriteStepKeys(hf, slot.visibility) || !hf->WriteInt64(static_cast<Int64>(slot.ik_defaults.size())))
			return false;
		for (const auto& state : slot.ik_defaults)
			if (!hf->WriteString(String(state.first.c_str())) || !hf->WriteBool(state.second))
				return false;
		if (!hf->WriteInt64(static_cast<Int64>(slot.ik_channels.size())))
			return false;
		for (const auto& channel : slot.ik_channels)
			if (!hf->WriteString(String(channel.first.c_str())) || !WriteStepKeys(hf, channel.second))
				return false;
		return true;
	}

	BaseObject* GetBoneControlObject(BaseTag* tag)
	{
		GeData link;
		return tag && tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_CONTROL_LINK)), link, DESCFLAGS_GET::NONE)
			? static_cast<BaseObject*>(link.GetLink(tag->GetDocument(), Obase)) : nullptr;
	}

	CCurve* GetTransformCurve(BaseObject* object, const Int32 parameter, const Int32 axis)
	{
		CTrack* const track = object ? object->FindCTrack(CreateDescID(DescLevel(parameter, DTYPE_VECTOR, 0), DescLevel(axis, DTYPE_REAL, 0))) : nullptr;
		return track ? track->GetCurve() : nullptr;
	}

	Bool HasControlTransformKeys(BaseObject* control)
	{
		for (const Int32 parameter : { ID_BASEOBJECT_REL_POSITION, ID_BASEOBJECT_REL_ROTATION })
			for (const Int32 axis : { VECTOR_X, VECTOR_Y, VECTOR_Z })
				if (const CCurve* const curve = GetTransformCurve(control, parameter, axis))
					if (curve->GetKeyCount() > 0)
						return true;
		return false;
	}

	BoneAnimationBezierData GetControlRotationInterpolation(BaseObject* control, const Int32 axis,
		const Int32 previous_frame, const Int32 frame)
	{
		BoneAnimationBezierData result;
		CCurve* const curve = GetTransformCurve(control, ID_BASEOBJECT_REL_ROTATION, VECTOR_X + std::clamp(axis, 0, 2));
		if (!curve || previous_frame < 0)
			return result;
		Int32 previous_index = 0;
		Int32 index = 0;
		const CKey* const previous = curve->FindKey(BaseTime(static_cast<Float>(previous_frame), kModelAnimationFps), &previous_index);
		const CKey* const current = curve->FindKey(BaseTime(static_cast<Float>(frame), kModelAnimationFps), &index);
		if (!previous || !current || index != previous_index + 1)
			return result;
		const Float64 duration = current->GetTime().Get() - previous->GetTime().Get();
		const Float64 difference = current->GetValue() - previous->GetValue();
		if (duration <= 0.0 || std::abs(difference) < 1e-9 || previous->GetInterpolation() != CINTERPOLATION::SPLINE)
			return result;
		Float64 left_value = 0.0, right_value = 0.0, left_time = 0.0, right_time = 0.0;
		curve->GetTangents(previous_index, &left_value, &right_value, &left_time, &right_time);
		const auto quantize = [](const Float64 value) { return static_cast<UChar>(std::lround(std::clamp(value, 0.0, 1.0) * 127.0)); };
		result.ax = quantize(right_time / duration);
		result.ay = quantize(right_value / difference);
		curve->GetTangents(index, &left_value, &right_value, &left_time, &right_time);
		result.bx = quantize(1.0 + left_time / duration);
		result.by = quantize(1.0 + left_value / difference);
		return result;
	}

	template<typename Key, typename NameOf>
	void CanonicalizeVmdKeys(std::vector<Key>& keys, NameOf name_of)
	{
		// Negative export offsets can clamp several keys onto frame zero. Keep the
		// latest source value deterministically, just as merged import slots do.
		std::map<std::pair<std::string, UInt32>, Key> unique;
		for (auto& key : keys)
			unique[{ name_of(key), key.m_frame }] = std::move(key);
		keys.clear();
		keys.reserve(unique.size());
		for (auto& key : unique)
			keys.push_back(std::move(key.second));
	}

}

Bool AnimationSlotMetadata::Read(HyperFile* hf)
{
	runtime_identity = cmt_runtime_identity::Next();
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
	dest.runtime_identity = runtime_identity;
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
	bc->SetInt32(MODEL_CONTROLS_DISPLAY, MODEL_CONTROLS_DISPLAY_PRIMARY);
	bc->SetFloat(MODEL_CONTROLS_SIZE, 1.0);
	bc->SetBool(MODEL_CONTROLS_OCCLUDED, true);
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
	material_preview_enabled_ = false;
	material_preview_weights_.clear();
	material_binding_diagnostic_ = String();
	model_info_animation_slots_.clear();
	migrate_legacy_model_info_tracks_ = level < 5;
	migrate_legacy_morph_tracks_ = level < 5;
	has_visibility_baseline_ = false;
	visibility_override_active_ = false;
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

	if (!ReadMorph(hf, level))
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

	// Level 5 appends named IK/visibility slots; all level 0-4 fields stay intact.
	if (level >= 5)
	{
		Int64 count = 0;
		if (!hf->ReadBool(&has_visibility_baseline_) || !hf->ReadBool(&visibility_override_active_)
			|| !hf->ReadInt32(&visibility_editor_baseline_)
			|| !hf->ReadInt32(&visibility_render_baseline_)
			|| !hf->ReadInt64(&count) || count < 0 || count > 10000)
			return false;
		model_info_animation_slots_.resize(static_cast<size_t>(count));
		for (auto& slot : model_info_animation_slots_)
			if (!ReadModelInfoSlot(hf, slot))
				return false;
	}
	model_info_animation_slots_.resize(static_cast<size_t>(animation_slot_metadata_.GetCount()));

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
		if (bc->GetData(MODEL_CONTROLS_SIZE).GetType() == DA_NIL)
			bc->SetFloat(MODEL_CONTROLS_SIZE, 1.0);
		if (bc->GetData(MODEL_CONTROLS_OCCLUDED).GetType() == DA_NIL)
			bc->SetBool(MODEL_CONTROLS_OCCLUDED, true);
	}
	else
	{
		model_mode_ = NormalizeModelMode(model_mode_);
	}
	RefreshAnimationSlotItems();
	ConfigureModelManagerExecutionPriority(node);

	InvalidateStandaloneRuntime();

	return true;
}
SDK2024_Write(MMDModelManagerObject) {
	auto* mutable_self = const_cast<MMDModelManagerObject*>(this);
	if (model_mode_ != MODEL_MODE_EDIT && !mutable_self->CaptureMorphAnimationSlotFromTracks(animation_index_))
		return false;
	if (!mutable_self->CaptureModelInfoAnimationSlotFromTracks(animation_index_))
		return false;

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

	if (!hf->WriteInt64(static_cast<Int64>(morph_animation_slots_.GetCount())))
		return false;
	for (const auto& slot : morph_animation_slots_)
		if (!io_util::WriteData(hf, slot))
			return false;
	if (!hf->WriteBool(has_visibility_baseline_) || !hf->WriteBool(visibility_override_active_)
		|| !hf->WriteInt32(visibility_editor_baseline_)
		|| !hf->WriteInt32(visibility_render_baseline_)
		|| !hf->WriteInt64(static_cast<Int64>(model_info_animation_slots_.size())))
		return false;
	for (const auto& slot : model_info_animation_slots_)
		if (!WriteModelInfoSlot(hf, slot))
			return false;

	return true;
}
SDK2024_CopyTo(MMDModelManagerObject)
{
	const auto destObject = reinterpret_cast<MMDModelManagerObject*>(dest);
	// Undo can restore into an existing NodeData while replacing its children.
	// These pointers belong to the old subtree, even when the translated links
	// now refer to valid restored managers. Never retain them across CopyTo.
	destObject->bone_manager_data_ = nullptr;
	destObject->mesh_manager_data_ = nullptr;
	destObject->rigid_manager_data_ = nullptr;
	destObject->joint_manager_data_ = nullptr;
	destObject->model_mode_ = model_mode_;
	// Copy transient values by value for render documents and Undo. HyperFile
	// deliberately omits them and Read() always resets preview on disk reload.
	destObject->material_preview_enabled_ = material_preview_enabled_;
	destObject->material_preview_weights_ = material_preview_weights_;
	destObject->material_preview_selection_ = material_preview_selection_;
	destObject->material_runtime_checksum_.Reset();
	destObject->model_info_animation_slots_ = model_info_animation_slots_;
	destObject->has_visibility_baseline_ = has_visibility_baseline_;
	destObject->visibility_override_active_ = visibility_override_active_;
	destObject->visibility_editor_baseline_ = visibility_editor_baseline_;
	destObject->visibility_render_baseline_ = visibility_render_baseline_;
	destObject->migrate_legacy_model_info_tracks_ = migrate_legacy_model_info_tracks_;
	destObject->migrate_legacy_morph_tracks_ = migrate_legacy_morph_tracks_;
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
	for (Int i = 0; i < morph_data_.GetCount(); ++i)
	{
		if (morph_data_[i].GetType() != MMDMorphType::IMPULSE)
			continue;
		const auto& source_offsets = static_cast<const ImpulseMorph&>(morph_data_[i]).GetOffsets();
		auto& copied_offsets = static_cast<ImpulseMorph&>(destObject->morph_data_[i]).GetOffsetsWritable();
		for (Int j = 0; j < source_offsets.GetCount(); ++j)
			if (source_offsets[j].rigid_link && *source_offsets[j].rigid_link)
				if (!(*source_offsets[j].rigid_link)->CopyTo(*copied_offsets[j].rigid_link, flags, trn))
					return false;
	}
	iferr(destObject->material_list_.Resize(0))
		return false;
	destObject->material_selection_index_ = material_selection_index_;
	for (Int32 i = 0; i < material_list_.GetCount(); ++i)
	{
		MMDMaterialData copy;
		if (!material_list_[i].CopyTo(copy))
			return false;
		// MMDMaterialData::CopyTo also serves detached runtime snapshots. Here we
		// are cloning scene data, so register both links with the scene translator.
		// Otherwise a bake clone could still write material morphs to its source.
		const auto& material = material_list_[i];
		if (material.material_link && *material.material_link && copy.material_link && *copy.material_link)
			if (!(*material.material_link)->CopyTo(*copy.material_link, flags, trn))
				return false;
		if (material.mesh_link && *material.mesh_link && copy.mesh_link && *copy.mesh_link)
			if (!(*material.mesh_link)->CopyTo(*copy.mesh_link, flags, trn))
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
	// AliasTrans may still refer to source nodes here. Reset only owned caches;
	// scene-facing invalidation must wait until the copied links are translated.
	destObject->ResetStandaloneRuntimeCaches();
	return true;
}
Bool MMDModelManagerObject::ReadMorph(HyperFile* hf, Int32 level)
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
		if (!morph->Read(hf, level))
			return false;
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
	dst->morph_data_.Reset();
	dst->morph_name_.Reset();
	dst->morph_named_number_ = morph_named_number_;
	for (const auto& morph : morph_data_)
	{
		const auto& new_morph_name = morph.GetName();
		const auto new_morph_index = dst->AddMorph(morph.GetType(), new_morph_name, false, morph.GetPanel());
		if (new_morph_index < 0)
			return false;
		const auto new_morph = &dst->morph_data_[new_morph_index];
		if (!morph.CopyTo(new_morph))
			return false;
		// C4D clones the dynamic description, parameter values and CTracks.
		// Retain their DescIDs: allocating UI here would give the copied morph a
		// different strength ID from its already cloned animation track.
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
		model_info_animation_slots_.clear();
		if (!EnsureMorphAnimationSlotCount(0))
			return false;
		animation_index_ = -1;
		RefreshAnimationSlotItems();
		return true;
	}

	model_info_animation_slots_.resize(static_cast<size_t>(slot_count));
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
	if (slot_index >= animation_slot_metadata_.GetCount() && !EnsureAnimationSlotCount(slot_index + 1))
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
	auto* mesh_manager = GetMeshManagerData();
	auto* bone_manager = GetBoneManagerData();
	std::map<std::string, MMDMorphType> available;
	if (mesh_manager)
	{
		const auto& uv_names = mesh_manager->GetUVMorphNames();
		for (const auto& name : mesh_manager->GetMeshMorphData().GetKeys())
			available[string_util::GetStdString(name)] = uv_names.Find(name) ? MMDMorphType::UV : MMDMorphType::MESH;
	}
	if (bone_manager)
		for (const auto& name : bone_manager->GetBoneMorphMap().GetKeys())
			available[string_util::GetStdString(name)] = MMDMorphType::BONE;

	// Tag discovery only owns mesh/UV/bone morphs. Group/flip/material/impulse
	// definitions are authored model data and must survive refresh and scene load.
	// Keep existing tag-derived entries too: rebuilding an unchanged entry would
	// delete its CTracks, strength DescID, and references from authored groups.
	for (auto it = maxon::Iterable::EraseIterator(morph_data_); it; ++it)
	{
		const IMorph& morph = *it;
		const MMDMorphType type = morph.GetType();
		const Bool mesh_owned = type == MMDMorphType::MESH || type == MMDMorphType::UV;
		const Bool bone_owned = type == MMDMorphType::BONE;
		if ((!mesh_owned && !bone_owned) || (mesh_owned && !mesh_manager) || (bone_owned && !bone_manager))
			continue;
		const auto entry = available.find(string_util::GetStdString(morph.GetName()));
		if (entry == available.end() || entry->second != type)
			DeleteMorph(it);
	}
	for (const auto& entry : available)
	{
		const String name(entry.first.c_str());
		if (!morph_name_.Find(name))
			AddMorph(entry.second, name);
	}
	ApplyMorphRuntimeStrengths();
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

	cmt_runtime::FrameMetrics metrics(cmt::debug::IsRuntimeProfileEnabled());
	cmt_runtime::ScopedFrameMetrics metrics_guard(metrics);

	if (BaseContainer* const bc = op->GetDataInstance())
		model_mode_ = NormalizeModelMode(bc->GetInt32(MODEL_MODE));

	if (priority == kExternalPoseSolvePriority && !HasExternalBonePoses())
		return EXECUTIONRESULT::OK;
	if (priority == EXECUTIONPRIORITY_EXPRESSION && HasExternalBonePoses())
		return EXECUTIONRESULT::OK;

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

	ApplyModelInfoVisibility(op, doc);
	if (priority == kExternalPosePreparePriority)
	{
		PrepareExternalBonePoses(doc);
		return EXECUTIONRESULT::OK;
	}
	if (priority == kExternalPoseSolvePriority)
		CaptureExternalBonePoses();
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
		const UInt64 bone_morph_state_checksum = GetBoneMorphStateChecksum();
		const Bool bone_morph_state_changed = bone_morph_pose_dirty_ || !has_bone_morph_state_checksum_
			|| bone_morph_state_checksum != bone_morph_state_checksum_;
		if (time_changed || control_state_changed || control_delta_active || bone_morph_state_changed || external_pose_refresh_)
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
			if ((bone_morph_state_changed || control_state_changed) && !time_changed)
				PrepareSameFrameReevaluation(doc);
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
				else if (bone_morph_state_changed || control_state_changed || external_pose_refresh_)
				{
					// Reapply the existing physical pose after invalidating same-frame
					// IK results. Control and morph edits must not advance Bullet time.
					cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Physics);
					ApplyStandalonePhysicsResults();
				}
			}
			else
			{
				is_animation_initialized_ = false;
			}
			// PMX after-deform is an evaluation phase, not a physics-only phase.
			// Keep these bones and their IK chains active when Bullet is disabled.
			RunLayeredBonePass(doc, true);
			if (bone_manager_data_)
				mmd_bone_control_util::SyncControlsToCurrentPose(*bone_manager_data_);
			control_state_checksum_ = bone_manager_data_ ? mmd_bone_control_util::GetControlStateChecksum(*bone_manager_data_) : 0;
			bone_morph_state_checksum_ = bone_morph_state_checksum;
			has_bone_morph_state_checksum_ = true;
			bone_morph_pose_dirty_ = false;
			external_pose_refresh_ = false;
			if (time_changed)
				prev_time_ = now_time;
		}
	}
	if (metrics.enabled)
	{
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC,
			"[CMT][RuntimeProfile] frame=@ rebuildMs=@ animationMs=@ ikMs=@ physicsMs=@ morphMs=@ materialMs=@ planRebuilds=@",
			doc->GetTime().GetFrame(kModelAnimationFps),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::Rebuild),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::Animation),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::IK),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::Physics),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::Morph),
			metrics.Milliseconds(cmt_runtime::RuntimeStage::MaterialSync),
			bone_manager_data_ ? bone_manager_data_->GetPlaybackPlanRebuildCount() : 0);
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
		break;
	}
	case libmmd::PMXMorphType::Flip:
	{
		morph_id = AddMorph(MMDMorphType::FLIP, String(pmx_morph.m_name.c_str()), true, panel);
		break;
	}
	default:
		break;
	}
	// PMX child indices belong to the original file order. Resolve them once all
	// authored and tag-derived definitions exist, including forward references.
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
			RemoveParameterTrack(reinterpret_cast<BaseObject*>(Get()), it->GetKey());
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
	if (migrate_legacy_model_info_tracks_)
	{
		std::ignore = CaptureModelInfoAnimationSlotFromTracks(animation_index_);
		migrate_legacy_model_info_tracks_ = false;
	}
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
		applying_model_info_parameters_ = true;
		Get()->SetParameter(id, GeData(true), DESCFLAGS_SET::NONE);
		applying_model_info_parameters_ = false;
	}
	ApplyIKSolverStates();
	std::ignore = RebuildModelInfoTracksFromAnimationSlot(animation_index_);
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
		{
			applying_model_info_parameters_ = true;
			node->SetParameter(p.first, GeData(enabled), DESCFLAGS_SET::NONE);
			applying_model_info_parameters_ = false;
		}
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
			CTrack* const track = op->FindCTrack(p.first);
			CCurve* const curve = track ? track->GetCurve() : nullptr;
			const Bool enabled = curve && op->GetDocument()
				? curve->GetValue(op->GetDocument()->GetTime()) >= 0.5 : value.GetBool();
			if (auto* solver = ik_manager->GetMMDIKSolver(static_cast<size_t>(p.second)))
				solver->Enable(enabled);
		}
	}
}

Bool MMDModelManagerObject::ImportVMDModelInfo(const libmmd::VMDFile& vmd_file,
	const CMTToolsSetting::MotionImport& setting, const Int32 slot_index)
{
	if (slot_index < 0 || static_cast<size_t>(slot_index) >= model_info_animation_slots_.size())
		return false;
	auto& slot = model_info_animation_slots_[static_cast<size_t>(slot_index)];
	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	if (!vmd_file.m_iks.empty() && object && !has_visibility_baseline_)
	{
		visibility_editor_baseline_ = object->GetEditorMode();
		visibility_render_baseline_ = object->GetRenderMode();
		has_visibility_baseline_ = true;
	}
	for (const auto& ik : vmd_file.m_iks)
	{
		const Int32 frame = ToAnimationFrame(ik.m_frame, setting.time_offset);
		slot.visibility[frame] = ik.m_show != 0;
		for (const auto& info : ik.m_ikInfos)
		{
			const std::string name = info.m_name.ToUtf8String();
			if (slot.ik_channels.find(name) == slot.ik_channels.end())
				slot.ik_defaults[name] = true;
			slot.ik_channels[name][frame] = info.m_enable != 0;
		}
	}
	return true;
}

Bool MMDModelManagerObject::CaptureModelInfoAnimationSlotFromTracks(const Int32 slot_index)
{
	if (slot_index < 0 || static_cast<size_t>(slot_index) >= model_info_animation_slots_.size() || !ik_manager_own_)
		return true;
	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	if (!object)
		return false;
	auto& slot = model_info_animation_slots_[static_cast<size_t>(slot_index)];
	for (const auto& param : ik_solver_dynamic_params_)
	{
		const auto* solver = ik_manager_own_->GetMMDIKSolver(static_cast<size_t>(param.second));
		if (!solver)
			continue;
		CTrack* const track = object->FindCTrack(param.first);
		CCurve* const curve = track ? track->GetCurve() : nullptr;
		// No track can mean an all-enabled imported channel; keep its exact sparse
		// records for a faithful round-trip. Defaults are separate from evaluated UI.
		if (!curve)
			continue;
		mmd_model_info::StepKeys captured;
		for (Int32 i = 0; i < curve->GetKeyCount(); ++i)
		{
			if (const CKey* const key = curve->GetKey(i))
			{
				Int32 frame = 0;
				if (!TryDocumentAnimationFrame(key->GetTime(), frame))
					return false;
				captured[std::max(0, frame)] = key->GetValue() >= 0.5;
			}
		}
		slot.ik_channels[solver->GetName()] = std::move(captured);
	}
	return true;
}

Bool MMDModelManagerObject::RebuildModelInfoTracksFromAnimationSlot(const Int32 slot_index)
{
	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	if (!object || !ik_manager_own_)
		return true;
	const mmd_model_info::AnimationSlot* const slot = slot_index >= 0 && static_cast<size_t>(slot_index) < model_info_animation_slots_.size()
		? &model_info_animation_slots_[static_cast<size_t>(slot_index)] : nullptr;
	for (const auto& param : ik_solver_dynamic_params_)
	{
		auto* solver = ik_manager_own_->GetMMDIKSolver(static_cast<size_t>(param.second));
		if (!solver)
			continue;
		RemoveParameterTrack(object, param.first);
		const auto* default_entry = ik_solver_enable_states_.Find(String(solver->GetName().c_str()));
		const Bool global_default = default_entry ? default_entry->GetValue() : true;
		const Int32 frame = object->GetDocument() ? object->GetDocument()->GetTime().GetFrame(kModelAnimationFps) : 0;
		const Bool enabled = slot ? mmd_model_info::EvaluateIK(*slot, solver->GetName(), frame, global_default) : global_default;
		applying_model_info_parameters_ = true;
		object->SetParameter(param.first, GeData(enabled), DESCFLAGS_SET::NONE);
		applying_model_info_parameters_ = false;
		solver->Enable(enabled);
		if (!slot)
			continue;
		const auto channel = slot->ik_channels.find(solver->GetName());
		if (channel == slot->ik_channels.end() || channel->second.empty())
			continue;
		const Bool default_state = mmd_model_info::EvaluateIK(*slot, solver->GetName(), -1, global_default);
		const Bool needs_track = !default_state || std::any_of(channel->second.begin(), channel->second.end(),
			[](const auto& key) { return !key.second; });
		if (!needs_track)
			continue;
		CTrack* const track = CTrack::Alloc(object, param.first);
		if (!track)
			return false;
		object->InsertTrackSorted(track);
		CCurve* const curve = track->GetCurve(CCURVE::CURVE, true);
		if (!curve)
			return false;
		// C4D clamps before the first key, whereas VMD defaults to enabled.
		// Insert frame zero for an initial later disable without changing stored data.
		if (channel->second.begin()->first > 0)
		{
			CKey* const initial = curve->AddKey(BaseTime());
			if (!initial)
				return false;
			initial->SetValue(curve, mmd_model_info::EvaluateIK(*slot, solver->GetName(), 0, global_default) ? 1.0 : 0.0);
			initial->SetInterpolation(curve, CINTERPOLATION::STEP);
		}
		for (const auto& keyframe : channel->second)
		{
			CKey* const key = curve->AddKey(BaseTime(static_cast<Float>(keyframe.first), kModelAnimationFps));
			if (!key)
				return false;
			key->SetValue(curve, keyframe.second ? 1.0 : 0.0);
			key->SetInterpolation(curve, CINTERPOLATION::STEP);
		}
	}
	return true;
}

void MMDModelManagerObject::ApplyModelInfoVisibility(BaseObject* object, BaseDocument* doc)
{
	if (!object || !has_visibility_baseline_)
		return;
	Bool show = true;
	if (model_mode_ == MODEL_MODE_ANIM && animation_index_ >= 0 && static_cast<size_t>(animation_index_) < model_info_animation_slots_.size())
		show = mmd_model_info::Evaluate(model_info_animation_slots_[static_cast<size_t>(animation_index_)].visibility,
			doc ? doc->GetTime().GetFrame(kModelAnimationFps) : 0, true);
	if (show && !visibility_override_active_)
		return;
	if (!show && !visibility_override_active_)
	{
		// Capture the most recent artist modes when the first hidden frame starts.
		visibility_editor_baseline_ = object->GetEditorMode();
		visibility_render_baseline_ = object->GetRenderMode();
	}
	const Int32 editor_mode = show ? visibility_editor_baseline_ : MODE_OFF;
	const Int32 render_mode = show ? visibility_render_baseline_ : MODE_OFF;
	if (object->GetEditorMode() != editor_mode)
		object->SetEditorMode(editor_mode);
	if (object->GetRenderMode() != render_mode)
		object->SetRenderMode(render_mode);
	visibility_override_active_ = !show;
}

void MMDModelManagerObject::AppendModelInfoToVmd(const CMTToolsSetting::MotionExport& setting,
	libmmd::VMDFile& motion, const Bool /*baked*/) const
{
	if (!setting.export_model_info || animation_index_ < 0 || static_cast<size_t>(animation_index_) >= model_info_animation_slots_.size())
		return;
	const auto& slot = model_info_animation_slots_[static_cast<size_t>(animation_index_)];
	std::set<Int32> frames;
	for (const auto& key : slot.visibility)
		frames.insert(key.first);
	for (const auto& channel : slot.ik_channels)
		for (const auto& key : channel.second)
			frames.insert(key.first);
	// Static per-slot checkbox choices must survive export as well.
	if (!slot.ik_defaults.empty())
		frames.insert(0);
	for (const Int32 frame : frames)
	{
		libmmd::VMDIk key;
		key.m_frame = ToExportFrame(frame, setting.time_offset);
		key.m_show = mmd_model_info::Evaluate(slot.visibility, frame, true) ? 1 : 0;
		std::set<std::string> names;
		for (const auto& channel : slot.ik_channels)
			names.insert(channel.first);
		for (const auto& state : slot.ik_defaults)
			names.insert(state.first);
		for (const auto& name : names)
		{
			libmmd::VMDIkInfo info;
			info.m_name.Set(ConvertUtf8ToSjis(name).c_str());
			// Retain unknown IK states verbatim. Baked export disables only solvers
			// present in this model, which actually contributed to the baked pose.
			info.m_enable = mmd_model_info::EvaluateIK(slot, name, frame, true) ? 1 : 0;
			key.m_ikInfos.push_back(std::move(info));
		}
		motion.m_iks.push_back(std::move(key));
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

Bool MMDModelManagerObject::SelectAutomationAnimationSlot(const UInt64 identity)
{
	if (!Get() || !GeIsMainThread())
		return false;
	for (Int32 index = 0; index < animation_slot_metadata_.GetCount(); ++index)
	{
		if (animation_slot_metadata_[index].runtime_identity == identity)
			return Get()->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), GeData(index), DESCFLAGS_SET::NONE);
	}
	return false;
}

Bool MMDModelManagerObject::SetAutomationMorphStrength(const UInt64 identity, const Float strength)
{
	if (!Get() || !GeIsMainThread() || !std::isfinite(strength))
		return false;
	for (auto& morph : morph_data_)
	{
		if (morph.GetRuntimeIdentity() != identity)
			continue;
		if (!morph.SetStrength(Get(), strength))
			return false;
		ApplyMorphRuntimeStrengths();
		return true;
	}
	return false;
}

#if defined(CMT_ENABLE_RUNTIME_REGRESSION)
Bool MMDModelManagerObject::SetMorphStrengthForRegression(const Int index, const Float strength)
{
	if (index < 0 || index >= morph_data_.GetCount() || !std::isfinite(strength))
		return false;
	if (!Get() || !morph_data_[index].SetStrength(Get(), strength))
		return false;
	ApplyMorphRuntimeStrengths();
	return true;
}

Bool MMDModelManagerObject::DeleteMorphForRegression(const Int index)
{
	if (index < 0 || index >= morph_data_.GetCount())
		return false;
	const Int count = morph_data_.GetCount();
	DeleteMorph(index);
	ApplyMorphRuntimeStrengths();
	return morph_data_.GetCount() == count - 1;
}
#endif

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

void MMDModelManagerObject::RemapDisplayFrameBoneIndices(const std::unordered_map<Int32, Int32>& previous_to_current)
{
	Bool changed = false;
	for (auto& frame : display_frame_list_)
	{
		for (Int i = frame.targets.GetCount() - 1; i >= 0; --i)
		{
			auto& target = frame.targets[i];
			if (target.type != DisplayFrameTargetType::Bone)
				continue;
			const auto found = previous_to_current.find(target.index);
			if (found == previous_to_current.end())
			{
				// A deleted bone must not silently become a different bone at its old index.
				iferr(frame.targets.Erase(i)) return;
				changed = true;
			}
			else if (target.index != found->second)
			{
				target.index = found->second;
				changed = true;
			}
		}
	}
	if (changed)
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
	Bool uses_additional_uv = false;
	for (const auto& morph : pmx_file.m_morphs)
	{
		if (morph.m_morphType >= libmmd::PMXMorphType::AddUV1 && morph.m_morphType <= libmmd::PMXMorphType::AddUV4)
			uses_additional_uv = true;
	}
	BaseObject* const model_object = static_cast<BaseObject*>(Get());
	BaseContainer source_info = model_object->GetDataInstance()->GetContainer(g_mmd_material_texture_morph_shader_id);
	source_info.SetBool(mmd_material_binding::AdditionalUvUsage, uses_additional_uv);
	model_object->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, source_info);
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
	std::unordered_map<Int32, Int32> imported_to_current;
	if (bone_manager_data_)
	{
		for (Int i = 0; i < bone_list.GetCount(); ++i)
		{
			if (BaseTag* const tag = bone_list[i]->GetTag(g_mmd_bone_tag_id))
			{
				const Int32 current = bone_manager_data_->FindBoneIndex(tag);
				if (current >= 0)
					imported_to_current.emplace(static_cast<Int32>(i), current);
			}
		}
	}
	RemapDisplayFrameBoneIndices(imported_to_current);

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
				if (ImportGroupAndFlipMorph(pmx_morph, panel) < 0)
					return false;
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Material)
			{
				const Int material_morph_id = AddMorph(MMDMorphType::MATERIAL, String(pmx_morph.m_name.c_str()), true, panel);
				if (material_morph_id >= 0 && material_morph_id < morph_data_.GetCount())
				{
					if (auto* const material_morph = static_cast<MaterialMorph*>(&morph_data_[material_morph_id]);
						material_morph->GetType() == MMDMorphType::MATERIAL)
					{
						auto& offsets = material_morph->GetOffsetsWritable();
						offsets.Reset();
						iferr(offsets.EnsureCapacity(static_cast<Int>(pmx_morph.m_materialMorph.size())))
						{ /* 容量预留失败时继续逐项 Append */ }
						for (const auto& pmx_offset : pmx_morph.m_materialMorph)
						{
							MMDMaterialMorphOffset offset;
							offset.FromPMX(pmx_offset);
							iferr(offsets.Append(offset))
								break;
						}
					}
				}
			}
			else if (morph_offset_type == libmmd::PMXMorphType::Impluse)
			{
				const Int impulse_id = AddMorph(MMDMorphType::IMPULSE, String(pmx_morph.m_name.c_str()), true, panel);
				if (impulse_id < 0 || impulse_id >= morph_data_.GetCount()
					|| morph_data_[impulse_id].GetType() != MMDMorphType::IMPULSE)
					return false;
				auto& offsets = static_cast<ImpulseMorph&>(morph_data_[impulse_id]).GetOffsetsWritable();
				offsets.Reset();
				for (const auto& source : pmx_morph.m_impulseMorph)
				{
					MMDImpulseMorphOffset offset;
					offset.FromPMX(source);
					iferr(offset.rigid_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create())
						return false;
					(*offset.rigid_link)->SetLink(rigid_manager_data_->FindRigid(offset.rigid_index));
					iferr(offsets.Append(offset))
						return false;
				}
			}
		}
	}
	// Finish discovery before converting PMX morph references. Derived morphs are
	// built from tags, whereas authored definitions above are built in file order;
	// their runtime indices therefore cannot be inferred from the PMX array index.
	if (mesh_manager_data_ && GetMeshManagerObject())
		mesh_manager_data_->ForceRefreshMorphData(GetMeshManagerObject());
	RefreshMorph();
	std::vector<Int> imported_morph_indices(pmx_file.m_morphs.size(), NOTOK);
	if (setting.import_expression)
	{
		for (size_t index = 0; index < pmx_file.m_morphs.size(); ++index)
		{
			const auto* entry = morph_name_.Find(String(pmx_file.m_morphs[index].m_name.c_str()));
			if (entry && entry->GetValue() >= 0 && entry->GetValue() < morph_data_.GetCount())
				imported_morph_indices[index] = entry->GetValue();
		}
		for (size_t index = 0; index < pmx_file.m_morphs.size(); ++index)
		{
			const auto& imported = pmx_file.m_morphs[index];
			if (imported.m_morphType != libmmd::PMXMorphType::Group && imported.m_morphType != libmmd::PMXMorphType::Flip)
				continue;
			const Int runtime_index = imported_morph_indices[index];
			if (runtime_index < 0)
				continue;
			auto* offsets = morph_data_[runtime_index].GetSubMorphDataWritable();
			if (!offsets)
				continue;
			offsets->Reset();
			const auto remap_offsets = [&imported_morph_indices, offsets, runtime_index](const auto& imported_offsets) -> Bool
			{
				for (const auto& [source_index, weight] : imported_offsets)
				{
					if (source_index < 0 || static_cast<size_t>(source_index) >= imported_morph_indices.size())
						continue;
					const Int target = imported_morph_indices[static_cast<size_t>(source_index)];
					if (target < 0 || target == runtime_index)
						continue;
					iferr(offsets->Insert(target, weight))
						return false;
				}
				return true;
			};
			if (imported.m_morphType == libmmd::PMXMorphType::Group)
			{
				if (!remap_offsets(imported.m_groupMorph))
					return false;
			}
			else if (!remap_offsets(imported.m_flipMorph))
				return false;
		}
	}
	for (auto& frame : display_frame_list_)
	{
		for (Int index = frame.targets.GetCount() - 1; index >= 0; --index)
		{
			auto& target = frame.targets[index];
			if (target.type != DisplayFrameTargetType::Morph)
				continue;
			const Int runtime_index = target.index >= 0 && static_cast<size_t>(target.index) < imported_morph_indices.size()
				? imported_morph_indices[static_cast<size_t>(target.index)] : NOTOK;
			if (runtime_index < 0)
			{
				iferr(frame.targets.Erase(index))
					return false;
			}
			else
				target.index = static_cast<Int32>(runtime_index);
		}
	}
	RefreshDisplayFrameUI();
	if (!PrepareMaterialMorphBindings(false)) return false;
	return true;
}

Bool MMDModelManagerObject::AddMaterial(const libmmd::PMXMaterial& pmx_material, BaseMaterial* c4d_material,
                                        BaseObject* mesh_object, const String& selection_name,
                                        const maxon::BaseArray<Filename>& texture_paths)
{
	iferr_scope_handler { return false; };
	MMDMaterialData mat;
	ResolvePMXMaterialData(pmx_material, texture_paths, mat);
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

void MMDModelManagerObject::AdjustMaterialMorphIndicesAfterMaterialRemoval(const Int32 removed_index)
{
	if (removed_index < 0)
		return;
	for (auto& morph : morph_data_)
	{
		if (morph.GetType() != MMDMorphType::MATERIAL)
			continue;
		auto& material_morph = static_cast<MaterialMorph&>(morph);
		auto& offsets = material_morph.GetOffsetsWritable();
		for (Int i = offsets.GetCount() - 1; i >= 0; --i)
		{
			Int32& index = offsets[i].material_index;
			if (index == -1)
				continue; // 全部材质，不受单材质删除影响
			if (index == removed_index)
				offsets.Erase(i) iferr_ignore("erase dangling material morph offset failed"_s);
			else if (index > removed_index)
				--index;
		}
	}
}

void MMDModelManagerObject::AdjustMaterialMorphIndicesAfterMaterialSwap(const Int32 first_index, const Int32 second_index)
{
	if (first_index < 0 || second_index < 0 || first_index == second_index)
		return;
	for (auto& morph : morph_data_)
	{
		if (morph.GetType() != MMDMorphType::MATERIAL)
			continue;
		auto& material_morph = static_cast<MaterialMorph&>(morph);
		for (auto& offset : material_morph.GetOffsetsWritable())
		{
			Int32& index = offset.material_index;
			if (index == first_index)
				index = second_index;
			else if (index == second_index)
				index = first_index;
		}
	}
}

Bool MMDModelManagerObject::ValidateMaterialMorphIndices(const Bool drop_invalid)
{
	const Int material_count = material_list_.GetCount();
	Bool has_invalid = false;
	for (auto& morph : morph_data_)
	{
		if (morph.GetType() != MMDMorphType::MATERIAL)
			continue;
		auto& material_morph = static_cast<MaterialMorph&>(morph);
		if (material_morph.ValidateMaterialIndices(material_count, drop_invalid))
			has_invalid = true;
	}
	return has_invalid;
}

MaterialMorph* MMDModelManagerObject::GetSelectedMaterialMorph()
{
	if (material_morph_selection_index_ < 0 || material_morph_selection_index_ >= morph_data_.GetCount())
		return nullptr;
	IMorph& morph = morph_data_[material_morph_selection_index_];
	if (morph.GetType() != MMDMorphType::MATERIAL)
		return nullptr;
	return static_cast<MaterialMorph*>(&morph);
}

const MaterialMorph* MMDModelManagerObject::GetSelectedMaterialMorph() const
{
	if (material_morph_selection_index_ < 0 || material_morph_selection_index_ >= morph_data_.GetCount())
		return nullptr;
	const IMorph& morph = morph_data_[material_morph_selection_index_];
	if (morph.GetType() != MMDMorphType::MATERIAL)
		return nullptr;
	return static_cast<const MaterialMorph*>(&morph);
}

MMDMaterialMorphOffset* MMDModelManagerObject::GetSelectedMaterialMorphOffset()
{
	MaterialMorph* const morph = GetSelectedMaterialMorph();
	if (!morph)
		return nullptr;
	auto& offsets = morph->GetOffsetsWritable();
	if (material_morph_offset_selection_index_ < 0 || material_morph_offset_selection_index_ >= offsets.GetCount())
		return nullptr;
	return &offsets[material_morph_offset_selection_index_];
}

const MMDMaterialMorphOffset* MMDModelManagerObject::GetSelectedMaterialMorphOffset() const
{
	const MaterialMorph* const morph = GetSelectedMaterialMorph();
	if (!morph)
		return nullptr;
	const auto& offsets = morph->GetOffsets();
	if (material_morph_offset_selection_index_ < 0 || material_morph_offset_selection_index_ >= offsets.GetCount())
		return nullptr;
	return &offsets[material_morph_offset_selection_index_];
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
	double export_length_scale = 1.0;
	if (!cmt_export::TryPMXLengthScale(bc->GetFloat(MODEL_POSITION_MULTIPLE, 8.5),
		setting.position_multiple, export_length_scale))
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

	if (setting.export_expression)
	{
		for (auto& exported_morph : pmx_file.m_morphs)
		{
			if (exported_morph.m_morphType != libmmd::PMXMorphType::Impluse)
				continue;
			const auto* entry = morph_name_.Find(String(exported_morph.m_name.c_str()));
			if (!entry || entry->GetValue() < 0 || entry->GetValue() >= morph_data_.GetCount())
				return false;
			const auto& morph = morph_data_[entry->GetValue()];
			if (morph.GetType() != MMDMorphType::IMPULSE)
				return false;
			for (const auto& offset : static_cast<const ImpulseMorph&>(morph).GetOffsets())
			{
				BaseObject* const rigid = offset.rigid_link && *offset.rigid_link
					? static_cast<BaseObject*>((*offset.rigid_link)->ForceGetLink()) : nullptr;
				if (!rigid || rigid->GetUp() != io_util::ResolveObjectLink(rigid_manager_))
					return false;
				GeData current_index;
				if (!rigid->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), current_index, DESCFLAGS_GET::NONE))
					return false;
				const Int32 index = current_index.GetType() == DA_LONG
					? current_index.GetInt32() : current_index.GetString().ToInt32(nullptr);
				const auto target = rigid_index_remap.find(index);
				// A deleted target must fail export, rather than silently losing an offset.
				if (target == rigid_index_remap.end())
					return false;
				libmmd::PMXFileMorph::ImpulseMorph exported_offset;
				offset.ToPMX(exported_offset);
				exported_offset.m_rigidbodyIndex = target->second;
				exported_morph.m_impulseMorph.push_back(exported_offset);
			}
			pmx_file.m_header.m_version = std::max(pmx_file.m_header.m_version, 2.1f);
		}
	}

	ClearUnsupportedPmxSections(pmx_file);
	FinalizePmxHeaderIndexSizes(pmx_file);
	return cmt_export::ScalePMXLengths(pmx_file, export_length_scale);
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
			if (!TryDocumentAnimationFrame(key->GetTime(), data.frame))
				return false;
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
	if (!UpdateManagers(reinterpret_cast<BaseObject*>(Get())))
		return false;
	bone_manager_data_ = GetBoneManagerData();
	rigid_manager_data_ = GetRigidManagerData();
	BaseObject* const rigid_manager_object = io_util::ResolveObjectLink(rigid_manager_);

	BaseObject* const object = reinterpret_cast<BaseObject*>(Get());
	const Float model_scale = object ? object->GetDataInstance()->GetFloat(MODEL_POSITION_MULTIPLE, 8.5) : 8.5;
	if (!object || !std::isfinite(model_scale) || model_scale <= 0.0
		|| !std::isfinite(setting.position_multiple) || setting.position_multiple <= 0.0)
		return false;
	// Reject all invalid enabled sections before capturing tracks, resizing slots,
	// clearing the previous animation, or constructing replacement CTracks.
	if (!ValidateMotionImport(vmd_file, setting, model_scale))
		return false;
	if (model_mode_ != MODEL_MODE_EDIT && !CaptureMorphAnimationSlotFromTracks(animation_index_))
		return false;
	if (!CaptureModelInfoAnimationSlotFromTracks(animation_index_))
		return false;
	const Bool has_active_slot = animation_index_ >= 0 && animation_index_ < animation_slot_metadata_.GetCount();
	const Bool merge_into_existing = merge && has_active_slot;
	const Bool replace_existing = !merge && setting.delete_previous_animation && has_active_slot;
	const Int32 target_slot = merge_into_existing || replace_existing
		? animation_index_ : static_cast<Int32>(animation_slot_metadata_.GetCount());
	const Int32 slot_count = std::max(target_slot + 1, static_cast<Int32>(animation_slot_metadata_.GetCount()));
	if (!EnsureAnimationSlotCount(slot_count))
		return false;
	if (bone_manager_data_ && !bone_manager_data_->EnsureAllAnimationSlotCount(slot_count))
		return false;
	// Prepare complete replacement data before removing prior tracks or keys.
	// Allocation during the final C4D commit still requires an undo transaction.
	MorphAnimationSlotData prepared_morph_slot;
	mmd_model_info::AnimationSlot prepared_model_info;
	std::map<MMDBoneTag*, maxon::BaseArray<BoneAnimationKeyframeData>> prepared_bone_slots;
	if (merge_into_existing)
	{
		prepared_morph_slot = morph_animation_slots_[target_slot];
		prepared_model_info = model_info_animation_slots_[static_cast<size_t>(target_slot)];
	}

	if (setting.import_morph)
	{
		std::map<std::pair<std::string, Int32>, MorphAnimationKeyframeData> keys;
		if (merge_into_existing)
			for (const auto& key : prepared_morph_slot.keyframes)
				keys[{ string_util::GetStdString(key.morph_name), key.frame }] = key;
		std::set<std::string> unmatched;
		for (const auto& morph : vmd_file.m_morphs)
		{
			const std::string name = morph.m_blendShapeName.ToUtf8String();
			if (!morph_name_.Find(String(name.c_str())))
			{
				unmatched.insert(name);
				continue;
			}
			MorphAnimationKeyframeData key;
			key.morph_name = String(name.c_str());
			key.frame = ToAnimationFrame(morph.m_frame, setting.time_offset);
			key.weight = morph.m_weight;
			keys[{ name, key.frame }] = key;
		}
		auto& slot = prepared_morph_slot;
		iferr(slot.keyframes.Resize(0))
			return false;
		for (const auto& key : keys)
		{
			iferr(slot.keyframes.Append(key.second))
				return false;
		}
		for (const auto& name : unmatched)
		{
			log.not_find_morph_name_list.Append(String(name.c_str())) iferr_return;
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

			imported_motion_map[target_tag].push_back(ConvertMotionToBoneKeyframe(motion, setting, model_scale));
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
			prepared_bone_slots.emplace(bone_tag, std::move(merged_keys));
		}
	}

	if (setting.import_model_info)
		for (const auto& key : vmd_file.m_iks)
		{
			const Int32 frame = ToAnimationFrame(key.m_frame, setting.time_offset);
			prepared_model_info.visibility[frame] = key.m_show != 0;
			for (const auto& info : key.m_ikInfos)
			{
				const std::string name = info.m_name.ToUtf8String();
				if (prepared_model_info.ik_channels.find(name) == prepared_model_info.ik_channels.end())
					prepared_model_info.ik_defaults[name] = true;
				prepared_model_info.ik_channels[name][frame] = info.m_enable != 0;
			}
		}

	// Commit only after conversion, name matching, and merged-key allocation.
	if (replace_existing && bone_manager_data_)
		for (const auto& entry : bone_manager_data_->bone_list_)
			if (BaseTag* const tag = bone_manager_data_->FindBone(static_cast<Int32>(entry.GetKey())))
				if (auto* const data = tag->GetNodeData<MMDBoneTag>())
					data->ClearAnimationSlot(target_slot);
	morph_animation_slots_[target_slot] = std::move(prepared_morph_slot);
	model_info_animation_slots_[static_cast<size_t>(target_slot)] = std::move(prepared_model_info);
	for (const auto& pending : prepared_bone_slots)
		if (!pending.first->ReplaceAnimationSlot(target_slot, pending.second))
			return false;
	if (setting.import_model_info && !vmd_file.m_iks.empty() && !has_visibility_baseline_)
	{
		visibility_editor_baseline_ = object->GetEditorMode();
		visibility_render_baseline_ = object->GetRenderMode();
		has_visibility_baseline_ = true;
	}

	log.imported_bone_count = setting.import_motion ? vmd_file.m_motions.size() : 0;
	log.imported_morph_count = setting.import_morph ? vmd_file.m_morphs.size() : 0;
	log.imported_motion_count = setting.import_model_info ? vmd_file.m_iks.size() : 0;

	const String slot_name = merge_into_existing && !animation_slot_metadata_[target_slot].name.IsEmpty()
		? animation_slot_metadata_[target_slot].name
		: animation_name;
	const Int32 max_frame = merge_into_existing
		? std::max(GetAnimationSlotMaxFrame(target_slot), GetVmdFileMaxFrame(vmd_file, setting))
		: GetVmdFileMaxFrame(vmd_file, setting);
	if (!SetAnimationSlotMetadata(target_slot, slot_name, max_frame))
		return false;

	animation_index_ = target_slot;
	if (model_mode_ != MODEL_MODE_EDIT && !RebuildMorphTracksFromAnimationSlot(target_slot))
		return false;
	if (!RebuildModelInfoTracksFromAnimationSlot(target_slot))
		return false;
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

Bool MMDModelManagerObject::BakeVMDMotion(libmmd::VMDFile& motion, const CMTToolsSetting::MotionExport& setting, const Bool controls_only) const
{
	BaseObject* const source_object = reinterpret_cast<BaseObject*>(const_cast<MMDModelManagerObject*>(this)->Get());
	BaseDocument* const source_doc = source_object ? source_object->GetDocument() : nullptr;
	if (!source_doc || !GeIsMainThread())
		return false;
	// Evaluate an independent document so export cannot change the artist's time,
	// controllers, morph materials, mode, or the live Bullet simulation state.
	std::vector<Int32> object_path;
	for (BaseObject* object = source_object; object; object = object->GetUp())
	{
		Int32 index = 0;
		for (BaseObject* previous = object->GetPred(); previous; previous = previous->GetPred())
			++index;
		object_path.push_back(index);
	}
	AutoAlloc<AliasTrans> translator;
	if (!translator || !translator->Init(source_doc))
		return false;
	std::unique_ptr<BaseDocument, void(*)(BaseDocument*)> doc(
		static_cast<BaseDocument*>(source_doc->GetClone(COPYFLAGS::NONE, translator)),
		[](BaseDocument* document) { BaseDocument::Free(document); });
	if (!doc)
		return false;
	translator->Translate(true);
	BaseObject* object = doc->GetFirstObject();
	for (auto path = object_path.rbegin(); path != object_path.rend(); ++path)
	{
		for (Int32 index = 0; object && index < *path; ++index)
			object = object->GetNext();
		if (!object)
			return false;
		if (std::next(path) != object_path.rend())
			object = object->GetDown();
	}
	auto* const model = object ? object->GetNodeData<MMDModelManagerObject>() : nullptr;
	if (!model)
		return false;
	model->model_mode_ = MODEL_MODE_ANIM;
	object->GetDataInstance()->SetInt32(MODEL_MODE, MODEL_MODE_ANIM);
	if (auto* const bones = model->GetBoneManagerData())
		bones->SetAllBoneMode(BONE_MODE_ANIM, model->GetBoneManagerObject());
	if (model_mode_ == MODEL_MODE_EDIT && !model->RebuildMorphTracksFromAnimationSlot(animation_index_))
		return false;
	doc->SetFps(static_cast<Int32>(kModelAnimationFps));
	doc->SetMinTime(BaseTime());
	Int32 document_max_frame = 0;
	std::uint32_t last_output_frame = 0;
	if (!controls_only && !TryDocumentAnimationFrame(source_doc->GetMaxTime(), document_max_frame))
		return false;
	const Int32 last_frame = std::max(GetAnimationSlotMaxFrame(animation_index_), document_max_frame);
	if (!controls_only && !cmt_motion_validation::TryExportFrame(last_frame, setting.time_offset, last_output_frame))
		return false;
	const Float model_scale = object->GetDataInstance()->GetFloat(MODEL_POSITION_MULTIPLE, 8.5);
	std::set<Int32> sample_frames;
	std::set<Int32> controlled_bones;
	if (controls_only)
	{
		object->GetDataInstance()->SetBool(MODEL_PHYSICS_ENABLED, false);
		auto& slot = model->model_info_animation_slots_[static_cast<size_t>(animation_index_)];
		slot.ik_channels.clear();
		if (auto* const bones = model->GetBoneManagerData())
			for (const auto& entry : bones->bone_list_)
			{
				const Int32 bone_index = static_cast<Int32>(entry.GetKey());
				BaseTag* const tag = bones->FindBone(bone_index);
				if (tag && tag->GetDataInstance()->GetBool(PMX_BONE_IS_IK))
					slot.ik_defaults[string_util::GetStdString(GetBoneTagName(tag, true))] = false;
				BaseObject* const control = GetBoneControlObject(tag);
				if (!HasControlTransformKeys(control))
					continue;
				controlled_bones.insert(bone_index);
				if (auto* const data = tag->GetNodeData<MMDBoneTag>())
				{
					maxon::BaseArray<BoneAnimationKeyframeData> keys;
					if (!data->CopyAnimationSlot(animation_index_, keys))
						return false;
					for (const auto& key : keys)
						sample_frames.insert(key.frame);
				}
				for (const Int32 parameter : { ID_BASEOBJECT_REL_POSITION, ID_BASEOBJECT_REL_ROTATION })
					for (const Int32 axis : { VECTOR_X, VECTOR_Y, VECTOR_Z })
						if (CCurve* const curve = GetTransformCurve(control, parameter, axis))
							for (Int32 key = 0; key < curve->GetKeyCount(); ++key)
								sample_frames.insert(std::max(0, GetDocumentAnimationFrame(curve->GetKey(key)->GetTime())));
				const std::string name = ConvertStringToSjis(GetBoneTagName(tag, true));
				motion.m_motions.erase(std::remove_if(motion.m_motions.begin(), motion.m_motions.end(), [&name](const auto& key)
				{
					return key.m_boneName.ToString() == name;
				}), motion.m_motions.end());
			}
		sample_frames.insert(0);
	}
	else
	{
		for (Int64 frame = 0; frame <= last_frame; ++frame)
			sample_frames.insert(static_cast<Int32>(frame));
	}
	if (controls_only)
	{
		// The clone still has the source IK CTracks. Remove them before invalidation
		// so their capture cannot re-enable the solver channels prepared above.
		for (const auto& param : model->ik_solver_dynamic_params_)
			RemoveParameterTrack(object, param.first);
	}
	model->InvalidateStandaloneRuntime();
	Int32 previous_frame = -1;
	for (const Int32 frame : sample_frames)
	{
		doc->SetTime(BaseTime(static_cast<Float>(frame), kModelAnimationFps));
		if (!doc->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE) || !*model->is_runtime_initialized_.Read())
			return false;
		if (setting.export_motion)
		{
			auto* const bones = model->GetBoneManagerData();
			if (!bones)
				return false;
			for (const auto& entry : bones->bone_list_)
			{
				if (controls_only && controlled_bones.find(static_cast<Int32>(entry.GetKey())) == controlled_bones.end())
					continue;
				BaseTag* const tag = bones->FindBone(static_cast<Int32>(entry.GetKey()));
				BaseObject* const bone = tag ? tag->GetObject() : nullptr;
				if (!bone)
					continue;
				String name = GetBoneTagName(tag, true);
				if (name.IsEmpty())
					name = GetBoneTagName(tag, false);
				const Matrix relative = bone->GetRelMl();
				auto key = MakeBoneKeyframe(frame, relative.off, ToBoneRotationArray(ExtractVpdQuaternion(relative)));
				if (controls_only)
					key.rotation = GetControlRotationInterpolation(GetBoneControlObject(tag), setting.use_rotation, previous_frame, frame);
				motion.m_motions.push_back(ConvertBoneKeyframeToMotion(name, key, setting, model_scale));
			}
		}
		if (setting.export_morph && !controls_only)
		{
			for (const auto& morph : model->morph_data_)
			{
				libmmd::VMDMorph key;
				key.m_blendShapeName.Set(ConvertStringToSjis(morph.GetName()).c_str());
				key.m_frame = ToExportFrame(frame, setting.time_offset);
				key.m_weight = static_cast<float>(const_cast<IMorph&>(morph).GetStrength(object));
				motion.m_morphs.push_back(std::move(key));
			}
		}
		previous_frame = frame;
	}
	return true;
}

Bool MMDModelManagerObject::SaveVMDMotion(libmmd::VMDFile& vmd_motion, const CMTToolsSetting::MotionExport& setting) const
{
	if (animation_index_ < 0 || animation_index_ >= animation_slot_metadata_.GetCount()
		|| !std::isfinite(setting.position_multiple) || setting.position_multiple <= 0.0
		|| !cmt_motion_validation::IsFrameOffsetValid(setting.time_offset))
		return false;
	auto* const self = const_cast<MMDModelManagerObject*>(this);
	BaseObject* const object = reinterpret_cast<BaseObject*>(self->Get());
	if (!object)
		return false;
	const Float model_scale = object->GetDataInstance()->GetFloat(MODEL_POSITION_MULTIPLE, 8.5);
	if (!std::isfinite(model_scale) || model_scale <= 0.0)
		return false;
	const auto valid_frame = [&setting](const Int32 frame)
	{
		std::uint32_t output_frame = 0;
		return cmt_motion_validation::TryExportFrame(frame, setting.time_offset, output_frame);
	};
	// Validate every enabled output timeline before evaluating a clone or
	// converting a signed frame plus offset into VMD's unsigned frame field.
	if (setting.export_model_info)
	{
		if (!valid_frame(0))
			return false;
		const auto& slot = model_info_animation_slots_[static_cast<size_t>(animation_index_)];
		for (const auto& key : slot.visibility)
			if (!valid_frame(key.first))
				return false;
		for (const auto& channel : slot.ik_channels)
			for (const auto& key : channel.second)
				if (!valid_frame(key.first))
					return false;
		for (const auto& param : ik_solver_dynamic_params_)
		{
			CTrack* const track = object->FindCTrack(param.first);
			if (!ValidateCurveExportFrames(track ? track->GetCurve() : nullptr, setting.time_offset))
				return false;
		}
	}
	if (setting.export_morph && !setting.use_bake)
	{
		if (model_mode_ == MODEL_MODE_EDIT)
		{
			for (const auto& key : morph_animation_slots_[animation_index_].keyframes)
				if (!valid_frame(key.frame))
					return false;
		}
		else
		{
			for (auto& morph : self->morph_data_)
			{
				CTrack* const track = object->FindCTrack(morph.GetStrengthDescID());
				if (!ValidateCurveExportFrames(track ? track->GetCurve() : nullptr, setting.time_offset))
					return false;
			}
		}
	}
	if (setting.export_motion && !setting.use_bake)
	{
		if (const auto* const bones = self->GetBoneManagerData())
			for (const auto& entry : bones->bone_list_)
			{
				BaseTag* const tag = bones->FindBone(static_cast<Int32>(entry.GetKey()));
				if (auto* const data = tag ? tag->GetNodeData<MMDBoneTag>() : nullptr)
				{
					maxon::BaseArray<BoneAnimationKeyframeData> keys;
					if (!data->CopyAnimationSlot(animation_index_, keys))
						return false;
					for (const auto& key : keys)
						if (!valid_frame(key.frame))
							return false;
				}
				BaseObject* const control = GetBoneControlObject(tag);
				for (const Int32 parameter : { ID_BASEOBJECT_REL_POSITION, ID_BASEOBJECT_REL_ROTATION })
					for (const Int32 axis : { VECTOR_X, VECTOR_Y, VECTOR_Z })
						if (!ValidateCurveExportFrames(GetTransformCurve(control, parameter, axis), setting.time_offset))
							return false;
			}
	}
	if (setting.use_bake && (setting.export_motion || setting.export_morph))
	{
		BaseDocument* const doc = object->GetDocument();
		Int32 max_frame = 0;
		if (!doc || !TryDocumentAnimationFrame(doc->GetMaxTime(), max_frame)
			|| !valid_frame(std::max(max_frame, GetAnimationSlotMaxFrame(animation_index_))))
			return false;
	}
	if (!self->CaptureModelInfoAnimationSlotFromTracks(animation_index_))
		return false;

	libmmd::VMDFile result;
	result.m_header.m_header.Set("Vocaloid Motion Data 0002");
	result.m_header.m_modelName.Set(ConvertStringToSjis(GetModelManagerName(object)).c_str());
	AppendModelInfoToVmd(setting, result, setting.use_bake);
	if (setting.use_bake)
	{
		if ((setting.export_motion || setting.export_morph) && !BakeVMDMotion(result, setting))
			return false;
		if (setting.export_model_info && setting.export_motion)
		{
			std::set<std::string> solved_ik_names;
			if (auto* const bones = self->GetBoneManagerData())
				for (const auto& entry : bones->bone_list_)
				{
					BaseTag* const tag = bones->FindBone(static_cast<Int32>(entry.GetKey()));
					if (!tag || !tag->GetDataInstance()->GetBool(PMX_BONE_IS_IK))
						continue;
					String name = GetBoneTagName(tag, true);
					if (name.IsEmpty())
						name = GetBoneTagName(tag, false);
					solved_ik_names.insert(ConvertStringToSjis(name));
				}
			if (!solved_ik_names.empty())
			{
				const UInt32 first_frame = ToExportFrame(0, setting.time_offset);
				const Bool has_first_frame = std::any_of(result.m_iks.begin(), result.m_iks.end(), [first_frame](const auto& key)
				{
					return key.m_frame == first_frame;
				});
				if (!has_first_frame)
				{
					libmmd::VMDIk initial;
					initial.m_frame = first_frame;
					initial.m_show = mmd_model_info::Evaluate(model_info_animation_slots_[static_cast<size_t>(animation_index_)].visibility, 0, true) ? 1 : 0;
					result.m_iks.push_back(std::move(initial));
				}
				// Solved IK is already present in the bone poses. Disable every known
				// solver in every record, while preserving unknown names and visibility.
				for (auto& key : result.m_iks)
					for (const auto& name : solved_ik_names)
					{
						auto existing = std::find_if(key.m_ikInfos.begin(), key.m_ikInfos.end(), [&name](const auto& info)
						{
							return info.m_name.ToString() == name;
						});
						if (existing != key.m_ikInfos.end())
							existing->m_enable = 0;
						else
						{
							libmmd::VMDIkInfo info;
							info.m_name.Set(name.c_str());
							info.m_enable = 0;
							key.m_ikInfos.push_back(std::move(info));
						}
					}
			}

		}
	}
	else
	{
		if (model_mode_ == MODEL_MODE_EDIT)
			AppendMorphSlotToVmd(&morph_animation_slots_[animation_index_], morph_name_, setting, result);
		else
			AppendMorphTracksToVmd(object, morph_data_, setting, result);
		if (setting.export_motion)
		{
			const auto* const bones = self->GetBoneManagerData();
			if (bones)
				for (const auto& entry : bones->bone_list_)
				{
					BaseTag* const tag = bones->FindBone(static_cast<Int32>(entry.GetKey()));
					auto* const data = tag ? tag->GetNodeData<MMDBoneTag>() : nullptr;
					if (!data)
						continue;
					maxon::BaseArray<BoneAnimationKeyframeData> keys;
					if (!data->CopyAnimationSlot(animation_index_, keys))
						return false;
					String name = GetBoneTagName(tag, true);
					if (name.IsEmpty())
						name = GetBoneTagName(tag, false);
					for (const auto& key : keys)
						result.m_motions.push_back(ConvertBoneKeyframeToMotion(name, key, setting, model_scale));
				}
			Bool has_control_keys = false;
			if (bones)
				for (const auto& entry : bones->bone_list_)
					if (HasControlTransformKeys(GetBoneControlObject(bones->FindBone(static_cast<Int32>(entry.GetKey())))))
						has_control_keys = true;
			if (has_control_keys && !BakeVMDMotion(result, setting, true))
				return false;
		}
	}
	CanonicalizeVmdKeys(result.m_motions, [](const auto& key) { return key.m_boneName.ToString(); });
	CanonicalizeVmdKeys(result.m_morphs, [](const auto& key) { return key.m_blendShapeName.ToString(); });
	CanonicalizeVmdKeys(result.m_iks, [](const auto&) { return std::string(); });
	vmd_motion = std::move(result);
	return true;
}

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
			const Bool authored_fk_rotation = mmd_bone_control_util::HasActiveControlRotation(bone_tag_base)
				&& !bone_tag_base->GetDataInstance()->GetBool(PMX_BONE_IS_IK);
			if (model_mode_ == MODEL_MODE_ANIM && IsTransientVPDBone(bone_index))
			{
				from_transient_vpd_pose = true;
				should_register = bone_tag->GetPlaybackRuntimeOverride(translation, rotation);
			}
			else if (model_mode_ == MODEL_MODE_ANIM)
			{
				Vector control_translation;
				std::array<Float32, 4> control_rotation { 0.F, 0.F, 0.F, 1.F };
				if (mmd_bone_control_util::GetControlDeltaInBoneSpace(bone_tag_base, bone_object, control_translation, control_rotation, base_rotation))
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
				from_transient_vpd_pose || authored_fk_rotation
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
		// Authored FK keys are already persistent pose overrides. Do not also
		// retain a transient copy that can capture subsequent controller edits.
		if (model_mode_ == MODEL_MODE_ANIM && !pending.static_pose)
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
	if (static_cast<size_t>(animation_index_) < model_info_animation_slots_.size())
	{
		auto& slot = model_info_animation_slots_[static_cast<size_t>(animation_index_)];
		changed = slot.visibility.erase(frame) != 0;
		for (auto& channel : slot.ik_channels)
			changed = channel.second.erase(frame) != 0 || changed;
	}

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
	model_info_animation_slots_.erase(model_info_animation_slots_.begin() + animation_index_);
	std::swap(animation_slot_metadata_, new_slot_metadata);
	std::swap(morph_animation_slots_, new_morph_slots);
	if (animation_slot_metadata_.IsEmpty())
		animation_index_ = -1;
	else
		animation_index_ = std::min(animation_index_, static_cast<Int32>(animation_slot_metadata_.GetCount() - 1));
	RefreshAnimationSlotItems();
	if (model_mode_ != MODEL_MODE_EDIT && !RebuildMorphTracksFromAnimationSlot(animation_index_))
		return false;
	if (!RebuildModelInfoTracksFromAnimationSlot(animation_index_))
		return false;
	InvalidateStandaloneRuntime();
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
	list->Add(op, kExternalPosePreparePriority, EXECUTIONFLAGS::EXPRESSION);
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	list->Add(op, kExternalPoseSolvePriority, EXECUTIONFLAGS::EXPRESSION);
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

	BaseContainer preview_items;
	preview_items.SetString(-1, GeLoadString(IDS_MODEL_MATERIAL_NONE));
	for (Int32 i = 0; i < morph_data_.GetCount(); ++i)
		if (IsMaterialPreviewMorph(i)) preview_items.SetString(i, morph_data_[i].GetName());
	if (BaseContainer* settings = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATMORPH_PREVIEW_LIST)), nullptr))
		settings->SetContainer(DESC_CYCLE, preview_items);

	// 材质表情：动态填充表情列表 / 偏移项列表 / 目标材质列表。
	{
		// 校正选中的材质表情索引；无效时尝试定位首个材质表情。
		Bool selection_valid = material_morph_selection_index_ >= 0
			&& material_morph_selection_index_ < morph_data_.GetCount()
			&& morph_data_[material_morph_selection_index_].GetType() == MMDMorphType::MATERIAL;
		if (!selection_valid)
		{
			material_morph_selection_index_ = -1;
			for (Int32 i = 0; i < morph_data_.GetCount(); ++i)
			{
				if (morph_data_[i].GetType() == MMDMorphType::MATERIAL)
				{
					material_morph_selection_index_ = i;
					break;
				}
			}
			material_morph_offset_selection_index_ = -1;
		}

		// 材质表情列表：有条目时重建（动态名），无条目时保留静态占位（NONE）。
		matmorph_list_items_.FlushAll();
		Bool has_material_morph = false;
		for (Int32 i = 0; i < morph_data_.GetCount(); ++i)
		{
			if (morph_data_[i].GetType() != MMDMorphType::MATERIAL)
				continue;
			matmorph_list_items_.SetString(i, FormatString("@: @", i, morph_data_[i].GetName()));
			has_material_morph = true;
		}
		if (has_material_morph)
		{
			if (BaseContainer* s = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATMORPH_LIST)), nullptr))
				s->SetContainer(DESC_CYCLE, matmorph_list_items_);
		}

		// 目标材质列表：保留静态 "全部材质"(id 0) 的本地化标签，追加各材质名(id = index+1)。
		String all_materials_label = "All Materials"_s;
		if (BaseContainer* s = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATMORPH_TARGET)), nullptr))
		{
			const BaseContainer src_cycle = s->GetContainer(DESC_CYCLE);
			all_materials_label = src_cycle.GetString(MODEL_MATMORPH_TARGET_ALL, all_materials_label);
			matmorph_target_items_.FlushAll();
			matmorph_target_items_.SetString(MODEL_MATMORPH_TARGET_ALL, all_materials_label);
			for (Int32 i = 0; i < material_list_.GetCount(); ++i)
				matmorph_target_items_.SetString(i + 1, FormatString("@: @", i, material_list_[i].name_local));
			s->SetContainer(DESC_CYCLE, matmorph_target_items_);
		}

		// 偏移项列表：有 offset 时重建（目标材质名 / 全部材质 / 无效提示）。
		matmorph_offset_items_.FlushAll();
		const MaterialMorph* const sel_morph = GetSelectedMaterialMorph();
		if (sel_morph && sel_morph->GetOffsetCount() > 0)
		{
			const auto& offsets = sel_morph->GetOffsets();
			for (Int32 i = 0; i < offsets.GetCount(); ++i)
			{
				const Int32 mi = offsets[i].material_index;
				String label;
				if (mi == -1)
					label = all_materials_label;
				else if (mi >= 0 && mi < material_list_.GetCount())
					label = material_list_[mi].name_local;
				else
					label = FormatString("(invalid @)", mi);
				matmorph_offset_items_.SetString(i, FormatString("@: @", i, label));
			}
			if (!(material_morph_offset_selection_index_ >= 0 && material_morph_offset_selection_index_ < offsets.GetCount()))
				material_morph_offset_selection_index_ = 0;
			if (BaseContainer* s = description->GetParameterI(ConstDescID(DescLevel(MODEL_MATMORPH_OFFSET_LIST)), nullptr))
				s->SetContainer(DESC_CYCLE, matmorph_offset_items_);
		}
		else
		{
			material_morph_offset_selection_index_ = -1;
		}
	}

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
						BaseDocument* doc = node->GetDocument();
						if (!doc) break;
						doc->StartUndo();
						doc->AddUndo(UNDOTYPE::CHANGE, node);
						DeleteMorph(morph_index);
						doc->EndUndo();
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
			case MODEL_CONTROLS_CREATE:
				if (bone_manager_data_)
					bone_manager_data_->CreateOrRefreshControls(GetBoneManagerObject());
				break;
			case MODEL_CONTROLS_SELECT:
				if (bone_manager_data_)
					mmd_bone_control_util::SelectVisibleControls(*bone_manager_data_, GetBoneManagerObject());
				break;
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
			case MODEL_MATMORPH_PREVIEW_RESET:
				material_preview_weights_.clear();
				RefreshMaterialMorphPreview();
				break;
			case MODEL_MATMORPH_UPGRADE:
				if (model_mode_ == MODEL_MODE_EDIT) PrepareMaterialMorphBindings(true);
				RefreshMaterialMorphPreview();
				break;
			case MODEL_MATMORPH_REPAIR:
				if (model_mode_ == MODEL_MODE_EDIT) RepairSelectedMaterialBinding();
				RefreshMaterialMorphPreview();
				break;
			case MODEL_MATMORPH_INDEPENDENT:
				if (model_mode_ == MODEL_MODE_EDIT) CreateIndependentMaterialBinding();
				RefreshMaterialMorphPreview();
				break;
			case MODEL_MATMORPH_RESET_NEUTRAL:
				if (auto* offset = GetSelectedMaterialMorphOffset())
				{
					BaseDocument* doc = node->GetDocument();
					if (!doc) break;
					doc->StartUndo();
					doc->AddUndo(UNDOTYPE::CHANGE, node);
					offset->ResetNeutral();
					doc->EndUndo();
					RefreshMaterialMorphPreview();
				}
				break;
			case MODEL_MATMORPH_OFFSET_ADD_BUTTON:
			{
				if (MaterialMorph* mm = GetSelectedMaterialMorph())
				{
					BaseDocument* doc = node->GetDocument();
					if (!doc) break;
					MMDMaterialMorphOffset offset;
					if (const auto* selected = GetSelectedMaterialMorphOffset()) offset.op_type = selected->op_type;
					offset.ResetNeutral();
					doc->StartUndo();
					doc->AddUndo(UNDOTYPE::CHANGE, node);
					iferr(mm->GetOffsetsWritable().Append(offset))
					{ doc->EndUndo(); break; }
					material_morph_offset_selection_index_ = static_cast<Int32>(mm->GetOffsetCount()) - 1;
					doc->EndUndo();
					RefreshMaterialMorphPreview();
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATMORPH_DELETE_BUTTON:
			{
				MaterialMorph* morph = GetSelectedMaterialMorph();
				BaseDocument* doc = node->GetDocument();
				if (model_mode_ != MODEL_MODE_EDIT || !morph || !doc)
					break;
				if (!QuestionDialog(FormatString("@: @?", GeLoadString(IDS_MORPH_DELETE), morph->GetName())))
					break;
				doc->StartUndo();
				doc->AddUndo(UNDOTYPE::CHANGE, node);
				DeleteMorph(material_morph_selection_index_);
				doc->EndUndo();
				break;
			}
			case MODEL_MATMORPH_OFFSET_DELETE_BUTTON:
			{
				if (MaterialMorph* mm = GetSelectedMaterialMorph())
				{
					auto& offs = mm->GetOffsetsWritable();
					if (material_morph_offset_selection_index_ >= 0 && material_morph_offset_selection_index_ < offs.GetCount())
					{
						BaseDocument* doc = node->GetDocument();
						if (!doc) break;
						doc->StartUndo();
						doc->AddUndo(UNDOTYPE::CHANGE, node);
						offs.Erase(material_morph_offset_selection_index_) iferr_ignore("erase material morph offset failed"_s);
						if (material_morph_offset_selection_index_ >= offs.GetCount())
							material_morph_offset_selection_index_ = static_cast<Int32>(offs.GetCount()) - 1;
						doc->EndUndo();
						RefreshMaterialMorphPreview();
						::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
						EventAdd();
					}
				}
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
			case MODEL_MATERIAL_CONVERT_TOON:
				ConvertSelectedMaterialToon();
				break;
			case MODEL_MATERIAL_CREATE_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					GeData type_data;
					node->GetParameter(ConstDescID(DescLevel(MODEL_MATERIAL_CREATE_TYPE)), type_data, DESCFLAGS_GET::NONE);
					const MMDRendererMaterialType rt = MaterialTypeFromSelection(type_data.GetInt32());
					if (rt == MMDRendererMaterialType::RedShiftToon)
					{
						// This newly introduced choice has no legacy create behavior.
						// Use the same assignment transaction as the explicit action.
						ConvertSelectedMaterialToon();
						break;
					}
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
							if (auto adapter = MMDMaterialAdapter::CreateFor(new_mat))
							{
								BaseObject* mesh = mat.mesh_link && *mat.mesh_link ? static_cast<BaseObject*>((*mat.mesh_link)->GetLink(doc)) : nullptr;
								adapter->PrepareMorphBinding(mat, new_mat, static_cast<BaseObject*>(node), mesh, material_binding_diagnostic_);
							}
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
				if (model_mode_ != MODEL_MODE_EDIT || material_preview_enabled_) break;
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount())
				{
					auto& mat = material_list_[material_selection_index_];
					BaseDocument* doc = node->GetDocument();
					if (doc && mat.material_link && *mat.material_link)
					{
						BaseMaterial* linked_mat = static_cast<BaseMaterial*>((*mat.material_link)->GetLink(doc));
						if (linked_mat && mmd_material_binding::IsBound(linked_mat))
							material_binding_diagnostic_ = "Managed shader outputs use the base fields; reverse sync has no independent values to import"_s;
						else if (linked_mat)
						{
							doc->StartUndo();
							doc->AddUndo(UNDOTYPE::CHANGE, node);
							ReadFromMaterial(linked_mat, mat);
							doc->EndUndo();
						}
						EventAdd();
					}
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_UP_BUTTON:
			{
				if (material_selection_index_ > 0 && material_selection_index_ < material_list_.GetCount())
				{
					BaseDocument* doc = node->GetDocument();
					if (!doc) break;
					doc->StartUndo();
					doc->AddUndo(UNDOTYPE::CHANGE, node);
					const Int32 old_index = material_selection_index_;
					const Int32 new_index = material_selection_index_ - 1;
					std::swap(material_list_[old_index], material_list_[new_index]);
					AdjustMaterialMorphIndicesAfterMaterialSwap(old_index, new_index);
					material_runtime_checksum_.Reset();
					material_selection_index_--;
					doc->EndUndo();
					RefreshMaterialMorphPreview();
					::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
					EventAdd();
				}
				break;
			}
			case MODEL_MATERIAL_MOVE_DOWN_BUTTON:
			{
				if (material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount() - 1)
				{
					BaseDocument* doc = node->GetDocument();
					if (!doc) break;
					doc->StartUndo();
					doc->AddUndo(UNDOTYPE::CHANGE, node);
					const Int32 old_index = material_selection_index_;
					const Int32 new_index = material_selection_index_ + 1;
					std::swap(material_list_[old_index], material_list_[new_index]);
					AdjustMaterialMorphIndicesAfterMaterialSwap(old_index, new_index);
					material_runtime_checksum_.Reset();
					material_selection_index_++;
					doc->EndUndo();
					RefreshMaterialMorphPreview();
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
					const Int32 removed_material_index = material_selection_index_;
					material_list_.Erase(material_selection_index_) iferr_ignore("erase failed"_s);
					AdjustMaterialMorphIndicesAfterMaterialRemoval(removed_material_index);
					material_runtime_checksum_.Reset();
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
				const MMDRendererMaterialType create_type = MaterialTypeFromSelection(type_data.GetInt32());
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
	case MODEL_MATMORPH_PREVIEW_ENABLED:
		t_data = GeData(material_preview_enabled_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATMORPH_PREVIEW_LIST:
		t_data.SetInt32(material_preview_selection_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATMORPH_PREVIEW_WEIGHT:
		t_data.SetFloat(GetMaterialPreviewWeight());
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATERIAL_TOON_STATUS:
	case MODEL_MATMORPH_STATUS:
		if (material_binding_diagnostic_.IsEmpty()
			&& static_cast<const BaseObject*>(node)->GetDataInstance()->GetInt32(MODEL_MATERIAL_CREATE_TYPE) == MODEL_MATERIAL_CREATE_TYPE_REDSHIFT_TOON)
		{
			String availability;
			MMDRedShiftToonMaterialAdapter::AvailabilityForUi(availability);
			t_data.SetString(availability);
			flags |= DESCFLAGS_GET::PARAM_GET;
			return true;
		}
		t_data.SetString(material_binding_diagnostic_.IsPopulated() ? material_binding_diagnostic_
			: String("Diffuse / Alpha / Specular / Roughness supported; Toon / Sphere / Ambient / Edge: data only"));
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
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
	case MODEL_MATMORPH_LIST:
		t_data.SetInt32(material_morph_selection_index_);
		flags |= DESCFLAGS_GET::PARAM_GET;
		return true;
	case MODEL_MATMORPH_OFFSET_LIST:
		t_data.SetInt32(material_morph_offset_selection_index_);
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

	// 材质表情 offset 字段读取。
	if (const MMDMaterialMorphOffset* off = GetSelectedMaterialMorphOffset())
	{
		switch (id[0].id)
		{
		case MODEL_MATMORPH_TARGET:
			t_data.SetInt32(off->material_index == -1 ? MODEL_MATMORPH_TARGET_ALL : off->material_index + 1);
			flags |= DESCFLAGS_GET::PARAM_GET;
			return true;
		case MODEL_MATMORPH_OP_TYPE:
			t_data.SetInt32(off->op_type);
			flags |= DESCFLAGS_GET::PARAM_GET;
			return true;
		case MODEL_MATMORPH_DIFFUSE_COLOR: HandleDescGetVector(id, off->diffuse_rgb, t_data, flags); return true;
		case MODEL_MATMORPH_DIFFUSE_ALPHA: t_data.SetFloat(off->diffuse_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_SPECULAR_COLOR: HandleDescGetVector(id, off->specular, t_data, flags); return true;
		case MODEL_MATMORPH_SPECULAR_POWER: t_data.SetFloat(off->specular_power); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_AMBIENT_COLOR: HandleDescGetVector(id, off->ambient, t_data, flags); return true;
		case MODEL_MATMORPH_EDGE_COLOR: HandleDescGetVector(id, off->edge_color_rgb, t_data, flags); return true;
		case MODEL_MATMORPH_EDGE_ALPHA: t_data.SetFloat(off->edge_color_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_EDGE_SIZE: t_data.SetFloat(off->edge_size); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_TEXTURE_FACTOR_COLOR: HandleDescGetVector(id, off->texture_factor_rgb, t_data, flags); return true;
		case MODEL_MATMORPH_TEXTURE_FACTOR_ALPHA: t_data.SetFloat(off->texture_factor_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_SPHERE_FACTOR_COLOR: HandleDescGetVector(id, off->sphere_texture_factor_rgb, t_data, flags); return true;
		case MODEL_MATMORPH_SPHERE_FACTOR_ALPHA: t_data.SetFloat(off->sphere_texture_factor_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		case MODEL_MATMORPH_TOON_FACTOR_COLOR: HandleDescGetVector(id, off->toon_texture_factor_rgb, t_data, flags); return true;
		case MODEL_MATMORPH_TOON_FACTOR_ALPHA: t_data.SetFloat(off->toon_texture_factor_alpha); flags |= DESCFLAGS_GET::PARAM_GET; return true;
		default: break;
		}
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
		case MODEL_CONTROLS_DISPLAY:
		case MODEL_CONTROLS_SIZE:
		case MODEL_CONTROLS_OCCLUDED:
		{
			const GeData value = t_data;
			BaseContainer* const bc = static_cast<BaseList2D*>(node)->GetDataInstance();
			if (id[0].id == MODEL_CONTROLS_SIZE)
				bc->SetFloat(MODEL_CONTROLS_SIZE, std::isfinite(value.GetFloat()) ? std::clamp(value.GetFloat(), 0.25, 3.0) : 1.0);
			else if (id[0].id == MODEL_CONTROLS_DISPLAY)
				bc->SetInt32(MODEL_CONTROLS_DISPLAY, std::clamp(value.GetInt32(), Int32(MODEL_CONTROLS_DISPLAY_PRIMARY), Int32(MODEL_CONTROLS_DISPLAY_HIDDEN)));
			else
				bc->SetBool(MODEL_CONTROLS_OCCLUDED, value.GetBool());
			if (bone_manager_data_)
				bone_manager_data_->SynchronizeControlPresentation(GetBoneManagerObject());
			flags |= DESCFLAGS_SET::PARAM_SET;
			if (GeIsMainThread()) EventAdd();
			return true;
		}
		case MODEL_POSITION_MULTIPLE:
		{
			SyncSubManagerScale(t_data.GetFloat());
			break;
		}
		case MODEL_MATMORPH_PREVIEW_ENABLED:
			material_preview_enabled_ = model_mode_ == MODEL_MODE_EDIT && t_data.GetBool();
			RefreshMaterialMorphPreview();
			flags |= DESCFLAGS_SET::PARAM_SET;
			return true;
		case MODEL_MATMORPH_PREVIEW_LIST:
			material_preview_selection_ = IsMaterialPreviewMorph(t_data.GetInt32()) ? t_data.GetInt32() : -1;
			node->SetDirty(DIRTYFLAGS::DESCRIPTION);
			flags |= DESCFLAGS_SET::PARAM_SET;
			return true;
		case MODEL_MATMORPH_PREVIEW_WEIGHT:
			if (model_mode_ == MODEL_MODE_EDIT && IsMaterialPreviewMorph(material_preview_selection_) && std::isfinite(t_data.GetFloat()))
			{
				material_preview_weights_[morph_data_[material_preview_selection_].GetRuntimeIdentity()] = maxon::Clamp01(t_data.GetFloat());
				RefreshMaterialMorphPreview();
			}
			flags |= DESCFLAGS_SET::PARAM_SET;
			return true;
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

			if (next_mode == MODEL_MODE_ANIM)
			{
				material_preview_enabled_ = false;
				material_preview_weights_.clear();
			}
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
				std::ignore = EnsureStandaloneRuntimeManagers();
			}
			return result;
		}
		case MODEL_ANIM_LIST:
		{
			if (model_mode_ != MODEL_MODE_EDIT && !CaptureMorphAnimationSlotFromTracks(animation_index_))
				return false;
			if (!CaptureModelInfoAnimationSlotFromTracks(animation_index_))
				return false;
			animation_index_ = t_data.GetInt32();
			if (model_mode_ != MODEL_MODE_EDIT && !RebuildMorphTracksFromAnimationSlot(animation_index_))
				return false;
			if (!RebuildModelInfoTracksFromAnimationSlot(animation_index_))
				return false;
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
		case MODEL_MATMORPH_LIST:
			material_morph_selection_index_ = t_data.GetInt32();
			material_morph_offset_selection_index_ = -1;
			node->SetDirty(DIRTYFLAGS::DESCRIPTION);
			::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
			EventAdd();
			break;
		case MODEL_MATMORPH_OFFSET_LIST:
			material_morph_offset_selection_index_ = t_data.GetInt32();
			node->SetDirty(DIRTYFLAGS::DESCRIPTION);
			::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
			EventAdd();
			break;
		case MODEL_MATMORPH_TARGET:
		case MODEL_MATMORPH_OP_TYPE:
		case MODEL_MATMORPH_DIFFUSE_COLOR:
		case MODEL_MATMORPH_DIFFUSE_ALPHA:
		case MODEL_MATMORPH_SPECULAR_COLOR:
		case MODEL_MATMORPH_SPECULAR_POWER:
		case MODEL_MATMORPH_AMBIENT_COLOR:
		case MODEL_MATMORPH_EDGE_COLOR:
		case MODEL_MATMORPH_EDGE_ALPHA:
		case MODEL_MATMORPH_EDGE_SIZE:
		case MODEL_MATMORPH_TEXTURE_FACTOR_COLOR:
		case MODEL_MATMORPH_TEXTURE_FACTOR_ALPHA:
		case MODEL_MATMORPH_SPHERE_FACTOR_COLOR:
		case MODEL_MATMORPH_SPHERE_FACTOR_ALPHA:
		case MODEL_MATMORPH_TOON_FACTOR_COLOR:
		case MODEL_MATMORPH_TOON_FACTOR_ALPHA:
		{
			MMDMaterialMorphOffset* const off = GetSelectedMaterialMorphOffset();
			if (!off)
				break;
			Bool target_changed = false;
			switch (id[0].id)
			{
			case MODEL_MATMORPH_TARGET:
			{
				const Int32 v = t_data.GetInt32();
				off->material_index = (v <= MODEL_MATMORPH_TARGET_ALL) ? -1 : v - 1;
				target_changed = true;
				break;
			}
			case MODEL_MATMORPH_OP_TYPE: off->op_type = t_data.GetInt32(); break;
			case MODEL_MATMORPH_DIFFUSE_COLOR: off->diffuse_rgb = t_data.GetVector(); break;
			case MODEL_MATMORPH_DIFFUSE_ALPHA: off->diffuse_alpha = t_data.GetFloat(); break;
			case MODEL_MATMORPH_SPECULAR_COLOR: off->specular = t_data.GetVector(); break;
			case MODEL_MATMORPH_SPECULAR_POWER: off->specular_power = t_data.GetFloat(); break;
			case MODEL_MATMORPH_AMBIENT_COLOR: off->ambient = t_data.GetVector(); break;
			case MODEL_MATMORPH_EDGE_COLOR: off->edge_color_rgb = t_data.GetVector(); break;
			case MODEL_MATMORPH_EDGE_ALPHA: off->edge_color_alpha = t_data.GetFloat(); break;
			case MODEL_MATMORPH_EDGE_SIZE: off->edge_size = t_data.GetFloat(); break;
			case MODEL_MATMORPH_TEXTURE_FACTOR_COLOR: off->texture_factor_rgb = t_data.GetVector(); break;
			case MODEL_MATMORPH_TEXTURE_FACTOR_ALPHA: off->texture_factor_alpha = t_data.GetFloat(); break;
			case MODEL_MATMORPH_SPHERE_FACTOR_COLOR: off->sphere_texture_factor_rgb = t_data.GetVector(); break;
			case MODEL_MATMORPH_SPHERE_FACTOR_ALPHA: off->sphere_texture_factor_alpha = t_data.GetFloat(); break;
			case MODEL_MATMORPH_TOON_FACTOR_COLOR: off->toon_texture_factor_rgb = t_data.GetVector(); break;
			case MODEL_MATMORPH_TOON_FACTOR_ALPHA: off->toon_texture_factor_alpha = t_data.GetFloat(); break;
			default: break;
			}
			// 改变目标会影响偏移项列表的显示标签，需要刷新属性页。
			if (target_changed)
			{
				node->SetDirty(DIRTYFLAGS::DESCRIPTION);
				::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
			}
			// 触发视口刷新，使下一次 Execute 重新合成材质表情运行时状态。
			RefreshMaterialMorphPreview();
			EventAdd();
			flags |= DESCFLAGS_SET::PARAM_SET;
			return true;
		}
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
							if (!applying_model_info_parameters_ && !reinterpret_cast<BaseObject*>(node)->FindCTrack(id))
							{
								const std::string name = solver->GetName();
								if (animation_index_ >= 0 && static_cast<size_t>(animation_index_) < model_info_animation_slots_.size())
								{
									model_info_animation_slots_[static_cast<size_t>(animation_index_)].ik_defaults[name] = enabled;
								}
								else
								{
									iferr(ik_solver_enable_states_.Insert(String(name.c_str()), enabled)) {}
								}
							}
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
				case MODEL_MATERIAL_TEXTURE_PATH:
					if (!UpdateSelectedMaterialTexture(t_data.GetString()))
					{
						// The virtual parameter handled the request and kept the old
						// value. Do not let C4D store a rejected path in its container.
						flags |= DESCFLAGS_SET::PARAM_SET;
						return true;
					}
					material_handled = true;
					break;
				case MODEL_MATERIAL_SPHERE_TEXTURE_PATH:
				case MODEL_MATERIAL_SPHERE_MODE:
					if (!UpdateSelectedMaterialSphere(
						id[0].id == MODEL_MATERIAL_SPHERE_MODE ? t_data.GetInt32() : mat.sphere_mode,
						id[0].id == MODEL_MATERIAL_SPHERE_TEXTURE_PATH ? t_data.GetString() : mat.sphere_texture_path))
					{
						flags |= DESCFLAGS_SET::PARAM_SET;
						return true;
					}
					material_handled = true;
					break;
				case MODEL_MATERIAL_TOON_MODE:
				{
					const Int32 mode = t_data.GetInt32();
					const Int32 index = mode == 0 && mat.toon_mode == 1 ? -1 : mat.toon_texture_index;
					UpdateSelectedMaterialToon(mode, index, mat.toon_texture_path);
					material_handled = true;
					break;
				}
				case MODEL_MATERIAL_TOON_TEXTURE_INDEX:
					UpdateSelectedMaterialToon(mat.toon_mode, t_data.GetInt32(), mat.toon_texture_path);
					material_handled = true;
					break;
				case MODEL_MATERIAL_TOON_TEXTURE_PATH:
					if (mat.toon_texture_index == -1)
						UpdateSelectedMaterialToon(mat.toon_mode, mat.toon_texture_index, t_data.GetString());
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
					if (linked_mat && (!mmd_material_binding::IsBound(linked_mat)
						|| (mmd_material_binding::IsOwner(linked_mat, static_cast<BaseObject*>(node), doc)
							&& HasUniqueMaterialBinding(linked_mat))))
					{
						// Join the editor's parameter undo so the material name and RS
						// preview defaults restore with the authoritative MMD values.
						if (GeIsMainThread()) doc->AddUndo(UNDOTYPE::CHANGE, linked_mat);
						SyncToMaterial(mat, linked_mat);
					}
					RefreshMaterialMorphPreview();
					flags |= DESCFLAGS_SET::PARAM_SET;
					return true;
				}
			}
			if (material_handled)
				return true;
			break;
		}
	}
	const Bool result = ObjectData::SetDParameter(node, id, t_data, flags);
	if (result && id[0].id == ID_USERDATA && GeIsMainThread())
	{
		const auto* entry = desc_id_map_.Find(id);
		if (entry && entry->GetValue().first == MMDModelRootDynamicDescriptionType::MORPH_STRENGTH)
			RefreshMaterialMorphPreview();
	}
	return result;
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
	if (id[0].id == MODEL_MATERIAL_REVERSE_SYNC_BUTTON)
		return model_mode_ == MODEL_MODE_EDIT && !material_preview_enabled_
			&& material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	if (id[0].id == MODEL_MATMORPH_PREVIEW_ENABLED || id[0].id == MODEL_MATMORPH_UPGRADE)
		return model_mode_ == MODEL_MODE_EDIT;
	if (id[0].id == MODEL_MATMORPH_REPAIR || id[0].id == MODEL_MATMORPH_INDEPENDENT)
		return model_mode_ == MODEL_MODE_EDIT && material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	if (id[0].id == MODEL_MATMORPH_PREVIEW_LIST || id[0].id == MODEL_MATMORPH_PREVIEW_RESET)
		return model_mode_ == MODEL_MODE_EDIT && material_preview_enabled_;
	if (id[0].id == MODEL_MATMORPH_PREVIEW_WEIGHT)
		return model_mode_ == MODEL_MODE_EDIT && material_preview_enabled_ && IsMaterialPreviewMorph(material_preview_selection_);
	if (id[0].id == MODEL_MATMORPH_DELETE_BUTTON)
		return model_mode_ == MODEL_MODE_EDIT && GetSelectedMaterialMorph() != nullptr;
	if (id[0].id == MODEL_MATMORPH_RESET_NEUTRAL)
		return GetSelectedMaterialMorphOffset() != nullptr;
	if (id[0].id >= MODEL_MATERIAL_NAME_LOCAL && id[0].id < MODEL_MATERIAL_ADD_BUTTON)
	{
		return material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount();
	}
	switch (id[0].id)
	{
	case MODEL_MATMORPH_OFFSET_LIST:
	case MODEL_MATMORPH_OFFSET_ADD_BUTTON:
		return GetSelectedMaterialMorph() != nullptr;
	case MODEL_MATMORPH_OFFSET_DELETE_BUTTON:
	case MODEL_MATMORPH_TARGET:
	case MODEL_MATMORPH_OP_TYPE:
	case MODEL_MATMORPH_DIFFUSE_COLOR:
	case MODEL_MATMORPH_DIFFUSE_ALPHA:
	case MODEL_MATMORPH_SPECULAR_COLOR:
	case MODEL_MATMORPH_SPECULAR_POWER:
	case MODEL_MATMORPH_AMBIENT_COLOR:
	case MODEL_MATMORPH_EDGE_COLOR:
	case MODEL_MATMORPH_EDGE_ALPHA:
	case MODEL_MATMORPH_EDGE_SIZE:
	case MODEL_MATMORPH_TEXTURE_FACTOR_COLOR:
	case MODEL_MATMORPH_TEXTURE_FACTOR_ALPHA:
	case MODEL_MATMORPH_SPHERE_FACTOR_COLOR:
	case MODEL_MATMORPH_SPHERE_FACTOR_ALPHA:
	case MODEL_MATMORPH_TOON_FACTOR_COLOR:
	case MODEL_MATMORPH_TOON_FACTOR_ALPHA:
		return GetSelectedMaterialMorphOffset() != nullptr;
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
	case MODEL_MATERIAL_CONVERT_TOON:
	{
		String reason;
		return model_mode_ == MODEL_MODE_EDIT && !material_preview_enabled_
			&& material_selection_index_ >= 0 && material_selection_index_ < material_list_.GetCount()
			&& MMDRedShiftToonMaterialAdapter::AvailabilityForUi(reason);
	}
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

void MMDModelManagerObject::DeleteMorph(const Int morph_index)
{
	if (auto& morph = morph_data_[morph_index]; !DeleteMorphImpl(morph, morph_index))
		return;
	std::ignore = morph_data_.Erase(morph_index);
	// The erased entry may have been the final material morph. Re-evaluate even
	// when the collection is now empty so linked materials return to base state.
	ApplyMorphRuntimeStrengths();
	RefreshMaterialMorphPreview();
}

bool MMDModelManagerObject::DeleteMorphImpl(IMorph& morph, const Int morph_index)
{
	iferr_scope_handler{ return false; };
	// References use collection indices. Prepare all remaps before removing a
	// definition so surviving Group/Flip entries cannot silently target a new
	// morph (or themselves) when the collection closes the erased slot.
	maxon::BaseArray<maxon::HashMap<Int, Float>> references;
	references.Resize(morph_data_.GetCount()) iferr_return;
	for (Int index = 0; index < morph_data_.GetCount(); ++index)
	{
		const auto* source = morph_data_[index].GetSubMorphDataWritable();
		if (!source || index == morph_index) continue;
		for (const auto& entry : *source)
		{
			const Int target = entry.GetKey();
			if (target == morph_index) continue;
			references[index].Insert(target > morph_index ? target - 1 : target, entry.GetValue()) iferr_return;
		}
	}
	for (Int index = 0; index < morph_data_.GetCount(); ++index)
		if (auto* target = morph_data_[index].GetSubMorphDataWritable())
			*target = std::move(references[index]);
	for (auto& frame : display_frame_list_)
	{
		for (Int index = frame.targets.GetCount() - 1; index >= 0; --index)
		{
			auto& target = frame.targets[index];
			if (target.type != DisplayFrameTargetType::Morph) continue;
			if (target.index == morph_index)
			{
				frame.targets.Erase(index) iferr_return;
			}
			else if (target.index > morph_index) --target.index;
		}
	}
	material_preview_weights_.erase(morph.GetRuntimeIdentity());
	if (material_preview_selection_ == morph_index) material_preview_selection_ = -1;
	else if (material_preview_selection_ > morph_index) --material_preview_selection_;
	if (material_morph_selection_index_ == morph_index)
	{
		material_morph_selection_index_ = -1;
		material_morph_offset_selection_index_ = -1;
	}
	else if (material_morph_selection_index_ > morph_index) --material_morph_selection_index_;
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
			AdjustMaterialMorphIndicesAfterMaterialRemoval(i);
			material_runtime_checksum_.Reset();
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
			material_runtime_checksum_.Reset();
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
