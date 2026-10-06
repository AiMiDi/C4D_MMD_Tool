#include "libMMD/Model/MMD/PMXFile.h"
#include "libMMD/Model/MMD/VMDFile.h"
#include "libMMD/Model/MMD/VMDCameraAnimation.h"

#include <cmath>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

namespace
{
void Require(bool condition, const char* message)
{
	if (!condition)
		throw std::runtime_error(message);
}
}

int main(int argc, char** argv)
{
	try
	{
		Require(argc == 2, "Expected fixture directory argument");
		const std::filesystem::path directory(argv[1]);
		libmmd::PMXFile model;
		Require(libmmd::ReadPMXFile(&model, (directory / "model.pmx").string().c_str()), "PMX parser rejected fixture");
		Require(model.m_vertices.size() == 3 && model.m_faces.size() == 1, "Unexpected mesh");
		Require(model.m_bones.size() == 4, "Unexpected bone count");
		Require(model.m_bones[0].m_linkBoneIndex == 1, "Root indexed tail must refer to hinge");
		Require(model.m_bones[2].m_parentBoneIndex == 1, "Tip must be child of hinge");
		Require(model.m_bones[3].m_ikTargetBoneIndex == 2 && model.m_bones[3].m_ikLinks.size() == 1,
			"IK chain must target tip through hinge");
		Require(model.m_materials.size() == 1 && model.m_morphs.size() == 1, "Unexpected material/morph count");
		Require(model.m_morphs[0].m_materialMorph.size() == 1 &&
			std::abs(model.m_morphs[0].m_materialMorph[0].m_diffuse.x() - .25f) < 1e-6f,
			"Material tint offset must add red");
		Require(model.m_rigidbodies.size() == 2 && model.m_joints.size() == 1, "Missing physics fixture");
		libmmd::PMXFile mixed;
		Require(libmmd::ReadPMXFile(&mixed, (directory / "mixed_morphs.pmx").string().c_str()),
			"PMX parser rejected mixed morph fixture");
		Require(mixed.m_morphs.size() == 3 && mixed.m_morphs[0].m_morphType == libmmd::PMXMorphType::Bone
			&& mixed.m_morphs[1].m_morphType == libmmd::PMXMorphType::Group
			&& mixed.m_morphs[2].m_morphType == libmmd::PMXMorphType::Material,
			"Mixed fixture must expose a runtime morph ordering change");
		Require(mixed.m_morphs[1].m_groupMorph.size() == 1 && mixed.m_morphs[1].m_groupMorph[0].m_morphIndex == 2,
			"Group must forward-reference the tint material morph");
		Require(mixed.m_morphs[0].m_boneMorph.size() == 1, "Missing bone morph offset");
		const auto& bone_morph = mixed.m_morphs[0].m_boneMorph[0];
		Require(bone_morph.m_boneIndex == 0 && std::abs(bone_morph.m_position.x() - .3f) < 1e-6f,
			"Bone morph must translate the root of the skinned triangle");
		Require(std::abs(bone_morph.m_quaternion.norm() - 1.f) < 1e-6f
			&& std::abs(bone_morph.m_quaternion.z() - .258819045f) < 1e-6f
			&& std::abs(bone_morph.m_quaternion.w() - .965925826f) < 1e-6f,
			"Bone morph must include a normalized 30-degree rotation");

		libmmd::PMXFile toon;
		Require(libmmd::ReadPMXFile(&toon, (directory / "toon_material.pmx").string().c_str()),
			"PMX parser rejected toon material fixture");
		Require(toon.m_materials.size() == 1 && toon.m_textures.size() == 1,
			"Toon fixture must have one material and one generated texture");
		Require(toon.m_materials[0].m_toonMode == libmmd::PMXToonMode::Separate
			&& toon.m_materials[0].m_toonTextureIndex == 0
			&& toon.m_textures[0].m_textureName == "toon_white.bmp",
			"Separate toon must resolve to the generated white bitmap");
		Require(toon.m_materials[0].m_textureIndex == -1 && toon.m_materials[0].m_sphereTextureIndex == -1,
			"Toon fixture must not reuse the shadow ramp as diffuse or sphere texture");
		Require(toon.m_morphs.size() == 1 && toon.m_morphs[0].m_morphType == libmmd::PMXMorphType::Material
			&& toon.m_morphs[0].m_materialMorph.size() == 1,
			"Toon fixture must exercise material-morph synchronization");
		const auto& toon_morph = toon.m_morphs[0].m_materialMorph[0];
		Require(toon_morph.m_materialIndex == 0 && toon_morph.m_opType == libmmd::PMXFileMorph::MaterialMorph::OpType::Add,
			"Toon factor offset must add to the fixture material");
		Require((toon_morph.m_toonTextureFactor - Eigen::Vector4f(.2f, .3f, .4f, .1f)).norm() < 1e-6f,
			"Toon factor offset must be non-identity to expose incorrect emission synchronization");

		libmmd::VMDFile first, second;
		Require(libmmd::ReadVMDFile(&first, (directory / "motion_a.vmd").string().c_str()), "Motion A parser failure");
		Require(libmmd::ReadVMDFile(&second, (directory / "motion_b.vmd").string().c_str()), "Motion B parser failure");
		Require(first.m_motions.size() == 2 && first.m_morphs.size() == 2, "Missing motion channels");
		Require(first.m_motions[1].m_frame == 2 && first.m_motions[1].m_translate.x() == 1.f,
			"Motion A expected final translation");
		Require(second.m_motions[1].m_translate.x() == 3.f, "Slots must have distinguishable poses");
		Require(first.m_iks.size() == 1 && second.m_iks.size() == 1 && first.m_iks[0].m_show && !second.m_iks[0].m_show,
			"Visibility states must differ");
		Require(first.m_iks[0].m_ikInfos[0].m_enable == 0 && second.m_iks[0].m_ikInfos[0].m_enable == 1,
			"IK enable states must differ");

		libmmd::VMDFile camera;
		Require(libmmd::ReadVMDFile(&camera, (directory / "camera.vmd").string().c_str()), "Camera parser failure");
		libmmd::VMDCameraAnimation animation;
		Require(animation.Create(camera), "Camera animation creation failure");
		animation.Evaluate(1.f);
		Require(std::abs(animation.GetCamera().m_interest.x() - 1.f) < 1e-4f,
			"Camera middle frame must interpolate to x=1");
		std::cout << "Generated PMX/VMD fixtures parsed and semantic assertions passed\n";
		return 0;
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << '\n';
		return 1;
	}
}
