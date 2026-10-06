#include "utils/cmt_pmx_export_scale.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

namespace
{
void Require(const bool condition, const char* message)
{
	if (!condition) { std::cerr << message << '\n'; std::exit(1); }
}
void Near(const Eigen::Vector3f& actual, const Eigen::Vector3f& expected, const char* message)
{
	Require((actual - expected).cwiseAbs().maxCoeff() < 1e-5f, message);
}
libmmd::PMXFile Fixture()
{
	libmmd::PMXFile file{};
	libmmd::PMXVertex vertex{};
	vertex.m_position = {1.0f, -2.0f, 3.0f};
	vertex.m_normal = {0.0f, 1.0f, 0.0f};
	vertex.m_uv = {0.25f, 0.75f};
	vertex.m_weightType = libmmd::PMXVertexWeight::SDEF;
	vertex.m_sdefC = {2.0f, 3.0f, 4.0f};
	vertex.m_sdefR0 = {1.0f, 2.0f, 3.0f};
	vertex.m_sdefR1 = {-1.0f, -2.0f, -3.0f};
	vertex.m_boneIndices[0] = 0;
	vertex.m_boneWeights[0] = 0.4f;
	file.m_vertices.push_back(vertex);
	libmmd::PMXBone bone{};
	bone.m_position = {4.0f, 5.0f, 6.0f};
	bone.m_positionOffset = {0.0f, 1.0f, 0.0f};
	bone.m_fixedAxis = {1.0f, 0.0f, 0.0f};
	bone.m_ikLimit = 0.3f;
	file.m_bones.push_back(bone);
	libmmd::PMXFileMorph position{};
	position.m_morphType = libmmd::PMXMorphType::Position;
	position.m_positionMorph.push_back({0, {0.1f, 0.2f, 0.3f}});
	file.m_morphs.push_back(position);
	libmmd::PMXFileMorph pose{};
	pose.m_morphType = libmmd::PMXMorphType::Bone;
	pose.m_boneMorph.push_back({0, {0.2f, 0.4f, 0.6f}, Eigen::Quaternionf::Identity()});
	file.m_morphs.push_back(pose);
	libmmd::PMXFileMorph impulse{};
	impulse.m_morphType = libmmd::PMXMorphType::Impluse;
	impulse.m_impulseMorph.push_back({0, 0, {1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}});
	file.m_morphs.push_back(impulse);
	libmmd::PMXRigidbody rigid{};
	rigid.m_translate = {1.0f, 3.0f, 5.0f};
	rigid.m_shapeSize = {0.5f, 0.75f, 1.0f};
	rigid.m_rotate = {0.1f, 0.2f, 0.3f};
	rigid.m_mass = 2.0f;
	file.m_rigidbodies.push_back(rigid);
	libmmd::PMXJoint joint{};
	joint.m_translate = {2.0f, 4.0f, 6.0f};
	joint.m_translateLowerLimit = {-1.0f, -2.0f, -3.0f};
	joint.m_translateUpperLimit = {1.0f, 2.0f, 3.0f};
	joint.m_rotate = {0.2f, 0.3f, 0.4f};
	joint.m_springTranslateFactor = {1.0f, 2.0f, 3.0f};
	file.m_joints.push_back(joint);
	return file;
}
}

int main()
{
	double factor = -1.0;
	Require(cmt_export::TryPMXLengthScale(8.5, 17.0, factor) && factor == 0.5, "Inverse export-unit ratio");
	Require(!cmt_export::TryPMXLengthScale(8.5, 0.0, factor), "Reject zero export scale");
	Require(!cmt_export::TryPMXLengthScale(-1.0, 1.0, factor), "Reject invalid stored scale");
	Require(!cmt_export::TryPMXLengthScale(1.0, std::numeric_limits<double>::infinity(), factor), "Reject infinite scale");
	const auto original = Fixture();
	auto scaled = original;
	Require(cmt_export::ScalePMXLengths(scaled, 0.5), "Scale fixture");
	Near(scaled.m_vertices[0].m_position, {0.5f, -1.0f, 1.5f}, "Vertex positions");
	Near(scaled.m_vertices[0].m_sdefC, {1.0f, 1.5f, 2.0f}, "SDEF centers");
	Near(scaled.m_vertices[0].m_sdefR0, {0.5f, 1.0f, 1.5f}, "SDEF R0");
	Near(scaled.m_vertices[0].m_sdefR1, {-0.5f, -1.0f, -1.5f}, "SDEF R1");
	Near(scaled.m_bones[0].m_position, {2.0f, 2.5f, 3.0f}, "Bone positions");
	Near(scaled.m_bones[0].m_positionOffset, {0.0f, 0.5f, 0.0f}, "Tail offsets");
	Near(scaled.m_morphs[0].m_positionMorph[0].m_position, {0.05f, 0.1f, 0.15f}, "Vertex morph displacement");
	Near(scaled.m_morphs[1].m_boneMorph[0].m_position, {0.1f, 0.2f, 0.3f}, "Bone morph displacement");
	Near(scaled.m_morphs[2].m_impulseMorph[0].m_translateVelocity, {0.5f, 1.0f, 1.5f}, "Linear impulse velocity");
	Near(scaled.m_rigidbodies[0].m_translate, {0.5f, 1.5f, 2.5f}, "Rigid positions");
	Near(scaled.m_rigidbodies[0].m_shapeSize, {0.25f, 0.375f, 0.5f}, "Rigid dimensions");
	Near(scaled.m_joints[0].m_translate, {1.0f, 2.0f, 3.0f}, "Joint positions");
	Near(scaled.m_joints[0].m_translateLowerLimit, {-0.5f, -1.0f, -1.5f}, "Joint lower length limits");
	Near(scaled.m_joints[0].m_translateUpperLimit, {0.5f, 1.0f, 1.5f}, "Joint upper length limits");
	Require(scaled.m_vertices[0].m_uv == original.m_vertices[0].m_uv &&
		scaled.m_vertices[0].m_boneWeights[0] == original.m_vertices[0].m_boneWeights[0], "UV and weights unchanged");
	Near(scaled.m_vertices[0].m_normal, original.m_vertices[0].m_normal, "Normals unchanged");
	Near(scaled.m_rigidbodies[0].m_rotate, original.m_rigidbodies[0].m_rotate, "Rotation unchanged");
	Require(scaled.m_rigidbodies[0].m_mass == 2.0f && scaled.m_bones[0].m_ikLimit == 0.3f, "Mass and angle limits unchanged");
	Near(scaled.m_joints[0].m_springTranslateFactor, original.m_joints[0].m_springTranslateFactor, "Spring coefficients unchanged");
	Near(scaled.m_morphs[2].m_impulseMorph[0].m_rotateTorque, {4.0f, 5.0f, 6.0f}, "Angular impulse unchanged");
	Require(cmt_export::ScalePMXLengths(scaled, 2.0), "Inverse roundtrip");
	Near(scaled.m_vertices[0].m_position, original.m_vertices[0].m_position, "Roundtrip length preservation");
	Near(original.m_vertices[0].m_position, {1.0f, -2.0f, 3.0f}, "Source snapshot untouched");
	// A bad late section must not leave earlier sections partially scaled.
	auto invalid = original;
	invalid.m_joints[0].m_translate[2] = std::numeric_limits<float>::max();
	Require(!cmt_export::ScalePMXLengths(invalid, 2.0), "Reject overflow");
	Near(invalid.m_vertices[0].m_position, original.m_vertices[0].m_position, "Atomic preflight");
	Require(!cmt_export::ScalePMXLengths(invalid, 1e-100), "Reject coordinate underflow");
	auto optional = original;
	optional.m_vertices[0].m_weightType = libmmd::PMXVertexWeight::BDEF1;
	optional.m_vertices[0].m_sdefC.setConstant(std::numeric_limits<float>::quiet_NaN());
	optional.m_bones[0].m_boneFlag = libmmd::PMXBoneFlags::TargetShowMode;
	optional.m_bones[0].m_positionOffset.setConstant(std::numeric_limits<float>::quiet_NaN());
	Require(cmt_export::ScalePMXLengths(optional, 1.0), "Ignore inactive serialized fields");
	std::cout << "PMX export length scaling checks passed\n";
}
