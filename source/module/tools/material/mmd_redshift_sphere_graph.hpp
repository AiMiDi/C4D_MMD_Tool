#pragma once

#include "mmd_redshift_graph_util.hpp"
#include "mmd_material_morph_binding.h"
#include <vector>
#include <cstring>

#if CMT_SDK_HAS_REDSHIFT_NODE_API
namespace mmd_rs_sphere
{
struct Role { const char* id; const char* asset; Int32 operation; };
inline constexpr Role Roles[] = {
	{"cmt_sphere_texture", "texturesampler", 0}, {"cmt_sphere_matcap", "matcap", 0},
	{"cmt_sphere_bias", "rsmathaddvector", 3}, {"cmt_sphere_clamp", "rsmathsaturatevector", 19},
	{"cmt_sphere_add", "rsmathaddvector", 3}, {"cmt_sphere_combine_mul", "rsmathmulvector", 5},
	{"cmt_sphere_combine_add", "rsmathaddvector", 3}
};
inline constexpr const char* Readers[] = {"cmt_morph_sphere_scale", "cmt_morph_sphere_bias", "cmt_morph_sphere_add"};
using Graph = maxon::nodes::NodesGraphModelRef;
struct Wire { maxon::GraphNode source; maxon::GraphNode destination; };

inline maxon::Result<maxon::GraphNode> Node(const Graph& graph, const char* id)
{
	iferr_scope;
	const auto node = graph.GetNode(maxon::NodePath()).FindChild(maxon::Id(id)) iferr_return;
	if (!node.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return node;
}

inline maxon::Result<maxon::GraphNode> Path(const Graph& graph)
{
	iferr_scope;
	const auto sampler = Node(graph, "cmt_sphere_texture") iferr_return;
	const auto bundle = mmd_rs::Input(sampler, mmd_rs::CoreId("texturesampler.tex0")) iferr_return;
	const auto path = bundle.FindChild(maxon::Id("path")) iferr_return;
	if (!path.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return path;
}

inline void Metadata(BaseContainer& metadata, const MMDMaterialData& data)
{
	using namespace mmd_material_binding;
	metadata.SetInt32(Profile, StandardSphereProfile);
	metadata.SetInt32(GraphRevision, StandardSphereGraphRevision);
	metadata.SetString(SphereTexturePath, data.sphere_texture_path);
	metadata.SetInt32(SphereMode, data.sphere_mode);
	metadata.SetBool(SphereHasTexture, data.sphere_texture_path.IsPopulated()
		&& GeFExist(Filename(data.sphere_texture_path)) && (data.sphere_mode == 1 || data.sphere_mode == 2));
	metadata.SetString(ProfileDiagnostic, data.sphere_mode == 3
		? "Sphere SubTexture (Additional UV) is not mapped"_s : "Matcap Sphere Multiply/Add supported"_s);
}

inline maxon::Result<void> Prepare(const Graph& graph, const MMDMaterialData& data)
{
	iferr_scope;
	for (const auto& role : Roles)
	{
		const auto node = graph.AddChild(maxon::Id(role.id), mmd_rs::CoreId(role.asset)) iferr_return;
		if (!node.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	}
	const auto sampler = Node(graph, "cmt_sphere_texture") iferr_return;
	const auto path = Path(graph) iferr_return;
	path.SetPortValue(MaxonConvert(Filename(data.sphere_texture_path), MAXONCONVERTMODE::READ)) iferr_return;
	mmd_rs::Set(sampler, "texturesampler.alpha_is_luminance", false) iferr_return;
	mmd_rs::Set(sampler, "texturesampler.color_multiplier", maxon::Color64(1.0)) iferr_return;
	const auto bundle = mmd_rs::Input(sampler, mmd_rs::CoreId("texturesampler.tex0")) iferr_return;
	const auto colorspace = bundle.FindChild(maxon::Id("colorspace")) iferr_return;
	colorspace.SetPortValue(maxon::String("Auto")) iferr_return;
	const auto matcap = Node(graph, "cmt_sphere_matcap") iferr_return;
	mmd_rs::Set(matcap, "matcap.space", Int32(0)) iferr_return;
	for (const auto& id : {"cmt_sphere_bias", "cmt_sphere_add"})
	{
		const auto node = Node(graph, id) iferr_return;
		mmd_rs::Set(node, "rsmathaddvector.input2", maxon::Color64(0.0)) iferr_return;
	}
	return maxon::OK;
}

inline maxon::Result<void> Validate(const Graph& graph, const BaseContainer& metadata)
{
	iferr_scope;
	for (const auto& role : Roles)
	{
		const auto node = Node(graph, role.id) iferr_return;
		Bool found = false;
		maxon::GraphModelHelper::FindNodesByAssetId(graph, mmd_rs::CoreId(role.asset), true,
			[&](const maxon::GraphNode& candidate) -> maxon::Result<Bool> { if (candidate == node) found = true; return true; }) iferr_return;
		if (!found) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
		if (role.operation)
		{
			const std::string suffix = std::string(role.asset) + ".math_op";
			const auto port = mmd_rs::Input(node, mmd_rs::CoreId(suffix.c_str())) iferr_return;
			const auto operation = port.GetPortValue<Int64>() iferr_return;
			if (!operation || *operation != role.operation) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
		}
	}
	const auto matcap = Node(graph, "cmt_sphere_matcap") iferr_return;
	const auto space = mmd_rs::Input(matcap, mmd_rs::CoreId("matcap.space")) iferr_return;
	const auto value = space.GetPortValue<Int32>() iferr_return;
	if (!value || *value != 0) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	const auto path = Path(graph) iferr_return;
	const auto url = path.GetPortValue<maxon::Url>() iferr_return;
	if (!url || Filename(MaxonConvert(*url).GetString()) != Filename(metadata.GetString(mmd_material_binding::SphereTexturePath)))
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return maxon::OK;
}

inline maxon::Result<std::vector<Wire>> Wires(const Graph& graph, const BaseContainer& metadata,
	const maxon::GraphNode& base, const maxon::GraphNode& surface_input, const Bool bound)
{
	iferr_scope;
	std::vector<Wire> wires;
	auto append = [&](const char* source, const char* output, const char* destination, const char* input) -> maxon::Result<void>
	{
		iferr_scope;
		const auto from = Node(graph, source) iferr_return;
		const auto to = Node(graph, destination) iferr_return;
		const auto out = mmd_rs::Output(from, mmd_rs::CoreId(output)) iferr_return;
		const auto in = mmd_rs::Input(to, mmd_rs::CoreId(input)) iferr_return;
		wires.push_back({out, in});
		return maxon::OK;
	};
	append("cmt_sphere_texture", "texturesampler.outcolor", "cmt_sphere_matcap", "matcap.color") iferr_return;
	append("cmt_sphere_matcap", "matcap.outcolor", "cmt_sphere_bias", "rsmathaddvector.input1") iferr_return;
	append("cmt_sphere_bias", "rsmathaddvector.out", "cmt_sphere_clamp", "rsmathsaturatevector.input") iferr_return;
	append("cmt_sphere_clamp", "rsmathsaturatevector.out", "cmt_sphere_add", "rsmathaddvector.input1") iferr_return;
	if (bound)
	{
		append(Readers[0], "rsuserdatacolor.out", "cmt_sphere_texture", "texturesampler.color_multiplier") iferr_return;
		append(Readers[1], "rsuserdatacolor.out", "cmt_sphere_bias", "rsmathaddvector.input2") iferr_return;
		append(Readers[2], "rsuserdatacolor.out", "cmt_sphere_add", "rsmathaddvector.input2") iferr_return;
	}
	if (metadata.GetBool(mmd_material_binding::SphereHasTexture))
	{
		const Bool multiply = metadata.GetInt32(mmd_material_binding::SphereMode) == 1;
		const char* id = multiply ? "cmt_sphere_combine_mul" : "cmt_sphere_combine_add";
		const char* first = multiply ? "rsmathmulvector.input1" : "rsmathaddvector.input1";
		const char* second = multiply ? "rsmathmulvector.input2" : "rsmathaddvector.input2";
		const char* output = multiply ? "rsmathmulvector.out" : "rsmathaddvector.out";
		const auto combine = Node(graph, id) iferr_return;
		const auto input = mmd_rs::Input(combine, mmd_rs::CoreId(first)) iferr_return;
		wires.push_back({base, input});
		append("cmt_sphere_add", "rsmathaddvector.out", id, second) iferr_return;
		const auto out = mmd_rs::Output(combine, mmd_rs::CoreId(output)) iferr_return;
		wires.push_back({out, surface_input});
	}
	else wires.push_back({base, surface_input});
	return wires;
}
}
#endif
