#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_redshift_toon_material.h"
#include "mmd_redshift_graph_util.hpp"
#include "mmd_material_morph_binding.h"
#include "plugin_resource.h"
#include "mmd_toon_regression.hpp"
#include "utils/cmt_toon_fallback.hpp"
#include "maxon/uuid.h"
#include "maxon/vector2d.h"
#include <cstring>

namespace
{
Bool ReadableTexture(const String& path)
{
	if (path.IsEmpty() || !GeFExist(Filename(path))) return false;
	AutoAlloc<BaseBitmap> bitmap;
	return bitmap && bitmap->Init(Filename(path)) == IMAGERESULT::OK;
}

Float64 BrightEndpointV(const String& path)
{
	AutoAlloc<BaseBitmap> bitmap;
	if (bitmap && path.IsPopulated() && bitmap->Init(Filename(path)) == IMAGERESULT::OK && bitmap->GetBh() > 0)
		return 1.0 - 0.5 / static_cast<Float64>(bitmap->GetBh());
	return 0.5;
}
}

#if CMT_SDK_HAS_REDSHIFT_NODE_API
namespace
{
using namespace mmd_material_binding;
MAXON_INTERNED_ID_LOCAL("none", k_stepInterpolation);

struct ToonAvailability
{
	Bool checked = false;
	Bool available = false;
	Bool probing = false;
	String diagnostic;
};

// Accessed on the main thread. Capability checks belong to explicit import /
// conversion operations, never a status read or an attribute enabling callback.
ToonAvailability& AvailabilityCache()
{
	static ToonAvailability cache;
	return cache;
}

struct NodeRole
{
	const char* id;
	const char* asset;
};

const NodeRole k_roles[] = {
	{"cmt_toon_surface", "toonmaterial"}, {"cmt_toon_contour", "contour"},
	{"cmt_toon_ramp", "rsramp"}, {"cmt_diffuse_texture", "texturesampler"},
	{"cmt_opacity_splitter", "rscolorsplitter"}, {"cmt_texture_bias", "rsmathaddvector"},
	{"cmt_texture_clamp", "rsmathsaturatevector"}, {"cmt_texture_add", "rsmathaddvector"},
	{"cmt_texture_diffuse", "rsmathmulvector"}, {"cmt_toon_texture", "texturesampler"},
	{"cmt_toon_scale", "rsmathmulvector"}, {"cmt_toon_bias", "rsmathaddvector"},
	{"cmt_toon_clamp", "rsmathsaturatevector"}, {"cmt_toon_add", "rsmathaddvector"},
	{"cmt_toon_border_texture", "texturesampler"},
	{"cmt_specular_mask", "rsramp"},
	{"cmt_sphere_texture", "texturesampler"}, {"cmt_sphere_matcap", "matcap"},
	{"cmt_sphere_bias", "rsmathaddvector"}, {"cmt_sphere_clamp", "rsmathsaturatevector"},
	{"cmt_sphere_add", "rsmathaddvector"},
	{"cmt_sphere_combine_add", "rsmathaddvector"}, {"cmt_sphere_combine_mul", "rsmathmulvector"}
};

const char* const k_readers[] = {
	"cmt_morph_diffuse", "cmt_morph_opacity", "cmt_morph_specular", "cmt_morph_roughness",
	"cmt_morph_texture_scale", "cmt_morph_texture_bias", "cmt_morph_texture_add",
	"cmt_morph_toon_scale", "cmt_morph_toon_bias", "cmt_morph_toon_add",
	"cmt_morph_edge_color", "cmt_morph_edge_alpha", "cmt_morph_edge_width",
	"cmt_morph_sphere_scale", "cmt_morph_sphere_bias", "cmt_morph_sphere_add"
};
static_assert(sizeof(k_readers) / sizeof(k_readers[0]) == ToonFieldCount, "Toon reader table must cover every role");

struct Wire
{
	maxon::GraphNode source;
	maxon::GraphNode destination;
};

struct BindingRestore
{
	BaseMaterial* material;
	BaseObject* mesh;
	BaseContainer previous;
	Bool allocated = false;
	Bool committed = false;
	~BindingRestore()
	{
		if (committed) return;
		if (allocated) RemoveUserData(mesh, Metadata(material));
		material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, previous);
	}
};

Bool SnapshotOwnedAttributes(BaseObject* mesh, const BaseContainer& previous,
	BaseContainer& cleanup, String& diagnostic)
{
	using namespace mmd_material_binding;
	const String token = previous.GetString(Token);
	if (token.IsEmpty())
	{
		diagnostic = "RS Toon binding identity is missing; create an independent material"_s;
		return false;
	}
	DynamicDescription* description = mesh->GetDynamicDescriptionWritable();
	if (!description) return false;
	Int32 attributes[ToonFieldCount] = {};
	Bool ambiguous = false;
	Bool edited_type = false;
	void* handle = description->BrowseInit();
	DescID id;
	const BaseContainer* entry = nullptr;
	while (description->BrowseGetNext(handle, &id, &entry))
	{
		if (!entry || id.GetDepth() != 2) continue;
		for (Int32 field = 0; field < ToonFieldCount; ++field)
		{
			if (entry->GetString(DESC_NAME) != AttributeName(token, static_cast<Field>(field))) continue;
			if (id[1].dtype != (IsColorField(field) ? DTYPE_VECTOR : DTYPE_REAL)) edited_type = true;
			if (attributes[field] && attributes[field] != id[1].id) ambiguous = true;
			attributes[field] = id[1].id;
		}
	}
	description->BrowseFree(handle);
	if (ambiguous || edited_type)
	{
		diagnostic = "RS Toon attribute identity or type is ambiguous; create an independent material"_s;
		return false;
	}
	cleanup = previous;
	for (Int32 field = 0; field < ToonFieldCount; ++field)
		cleanup.SetInt32(UserDataKey(previous, field), attributes[field]);
	return true;
}

maxon::Result<maxon::GraphNode> Node(const maxon::nodes::NodesGraphModelRef& graph, const char* id)
{
	iferr_scope;
	const auto node = graph.GetNode(maxon::NodePath()).FindChild(maxon::Id(id)) iferr_return;
	if (!node.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return node;
}

maxon::Result<maxon::GraphNode> ReaderOutput(const maxon::nodes::NodesGraphModelRef& graph, const Int32 field)
{
	iferr_scope;
	const auto reader = Node(graph, k_readers[field]) iferr_return;
	return mmd_rs::Output(reader, mmd_rs::CoreId(IsColorField(field) ? "rsuserdatacolor.out" : "rsuserdatascalar.out"));
}

maxon::Result<maxon::GraphNode> TexturePathPort(const maxon::GraphNode& sampler)
{
	iferr_scope;
	const auto bundle = mmd_rs::Input(sampler, mmd_rs::CoreId("texturesampler.tex0")) iferr_return;
	const auto path = bundle.FindChild(maxon::Id("path")) iferr_return;
	if (!path.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return path;
}

maxon::Result<void> SetTexturePath(const maxon::GraphNode& sampler, const String& path)
{
	iferr_scope;
	const auto input = TexturePathPort(sampler) iferr_return;
	input.SetPortValue(MaxonConvert(Filename(path), MAXONCONVERTMODE::READ)) iferr_return;
	return maxon::OK;
}

maxon::Result<void> SetReaderDefaults(const maxon::nodes::NodesGraphModelRef& graph,
	const MMDMaterialRuntimeState& state, const Bool textured)
{
	iferr_scope;
	for (Int32 field = 0; field < ToonFieldCount; ++field)
	{
		const auto reader = Node(graph, k_readers[field]) iferr_return;
		if (IsColorField(field))
		{
			mmd_rs::Set(reader, "rsuserdatacolor.default", mmd_rs::Color(Color(state, static_cast<Field>(field), textured))) iferr_return;
		}
		else
		{
			mmd_rs::Set(reader, "rsuserdatascalar.default", static_cast<Float64>(Scalar(state, static_cast<Field>(field), textured))) iferr_return;
		}
	}
	return maxon::OK;
}

maxon::Result<std::vector<Wire>> Wires(const maxon::nodes::NodesGraphModelRef& graph, const BaseContainer& metadata)
{
	iferr_scope;
	std::vector<Wire> wires;
	const auto surface = Node(graph, "cmt_toon_surface") iferr_return;
	const auto output = Node(graph, "cmt_toon_output") iferr_return;
	const auto contour = Node(graph, "cmt_toon_contour") iferr_return;
	const auto texture = Node(graph, "cmt_diffuse_texture") iferr_return;
	const auto splitter = Node(graph, "cmt_opacity_splitter") iferr_return;
	const auto bias = Node(graph, "cmt_texture_bias") iferr_return;
	const auto clamp = Node(graph, "cmt_texture_clamp") iferr_return;
	const auto add = Node(graph, "cmt_texture_add") iferr_return;
	const auto diffuse = Node(graph, "cmt_texture_diffuse") iferr_return;
	const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
	const auto toon_texture = Node(graph, "cmt_toon_texture") iferr_return;
	const auto toon_border = Node(graph, "cmt_toon_border_texture") iferr_return;
	const auto toon_scale = Node(graph, "cmt_toon_scale") iferr_return;
	const auto toon_bias = Node(graph, "cmt_toon_bias") iferr_return;
	const auto toon_clamp = Node(graph, "cmt_toon_clamp") iferr_return;
	const auto toon_add = Node(graph, "cmt_toon_add") iferr_return;
	const auto specular_mask = Node(graph, "cmt_specular_mask") iferr_return;
	const auto sphere_texture = Node(graph, "cmt_sphere_texture") iferr_return;
	const auto sphere_matcap = Node(graph, "cmt_sphere_matcap") iferr_return;
	const auto sphere_bias = Node(graph, "cmt_sphere_bias") iferr_return;
	const auto sphere_clamp = Node(graph, "cmt_sphere_clamp") iferr_return;
	const auto sphere_add = Node(graph, "cmt_sphere_add") iferr_return;
	const auto sphere_combine = Node(graph, metadata.GetInt32(SphereMode) == 1
		? "cmt_sphere_combine_mul" : "cmt_sphere_combine_add") iferr_return;

	const auto append = [&](const maxon::GraphNode& source, const char* source_port,
		const maxon::GraphNode& target, const char* target_port) -> maxon::Result<void>
	{
		iferr_scope;
		const auto from = mmd_rs::Output(source, mmd_rs::CoreId(source_port)) iferr_return;
		const auto to = mmd_rs::Input(target, mmd_rs::CoreId(target_port)) iferr_return;
		wires.push_back({from, to});
		return maxon::OK;
	};
	const auto reader = [&](const Int32 field, const maxon::GraphNode& target,
		const char* target_port) -> maxon::Result<void>
	{
		iferr_scope;
		const auto from = ReaderOutput(graph, field) iferr_return;
		const auto to = mmd_rs::Input(target, mmd_rs::CoreId(target_port)) iferr_return;
		wires.push_back({from, to});
		return maxon::OK;
	};

	reader(2, surface, "toonmaterial.refl_color") iferr_return;
	reader(3, surface, "toonmaterial.refl_roughness") iferr_return;
	append(specular_mask, "rsramp.outcolor", surface, "toonmaterial.refl_mask_tone_map") iferr_return;
	reader(4, texture, "texturesampler.color_multiplier") iferr_return;
	reader(1, texture, "texturesampler.alpha_multiplier") iferr_return;
	reader(5, bias, "rsmathaddvector.input2") iferr_return;
	reader(6, add, "rsmathaddvector.input2") iferr_return;
	reader(0, diffuse, "rsmathmulvector.input2") iferr_return;
	append(texture, "texturesampler.outcolor", splitter, "rscolorsplitter.input") iferr_return;
	append(texture, "texturesampler.outcolor", bias, "rsmathaddvector.input1") iferr_return;
	append(bias, "rsmathaddvector.out", clamp, "rsmathsaturatevector.input") iferr_return;
	append(clamp, "rsmathsaturatevector.out", add, "rsmathaddvector.input1") iferr_return;
	append(add, "rsmathaddvector.out", diffuse, "rsmathmulvector.input1") iferr_return;
	maxon::GraphNode base_color;
	if (metadata.GetBool(Texture))
	{
		base_color = mmd_rs::Output(diffuse, mmd_rs::CoreId("rsmathmulvector.out")) iferr_return;
	}
	else
	{
		base_color = ReaderOutput(graph, 0) iferr_return;
	}
	const auto surface_color = mmd_rs::Input(surface, mmd_rs::CoreId("toonmaterial.base_color")) iferr_return;
	reader(13, sphere_texture, "texturesampler.color_multiplier") iferr_return;
	reader(14, sphere_bias, "rsmathaddvector.input2") iferr_return;
	reader(15, sphere_add, "rsmathaddvector.input2") iferr_return;
	append(sphere_texture, "texturesampler.outcolor", sphere_matcap, "matcap.color") iferr_return;
	append(sphere_matcap, "matcap.outcolor", sphere_bias, "rsmathaddvector.input1") iferr_return;
	append(sphere_bias, "rsmathaddvector.out", sphere_clamp, "rsmathsaturatevector.input") iferr_return;
	append(sphere_clamp, "rsmathsaturatevector.out", sphere_add, "rsmathaddvector.input1") iferr_return;
	if (metadata.GetBool(SphereHasTexture))
	{
		const char* combine_asset = metadata.GetInt32(SphereMode) == 1 ? "rsmathmulvector" : "rsmathaddvector";
		const std::string input = std::string(combine_asset) + ".input1";
		const std::string sphere_input = std::string(combine_asset) + ".input2";
		const std::string output = std::string(combine_asset) + ".out";
		const auto destination = mmd_rs::Input(sphere_combine, mmd_rs::CoreId(input.c_str())) iferr_return;
		wires.push_back({base_color, destination});
		append(sphere_add, "rsmathaddvector.out", sphere_combine, sphere_input.c_str()) iferr_return;
		const auto combined = mmd_rs::Output(sphere_combine, mmd_rs::CoreId(output.c_str())) iferr_return;
		wires.push_back({combined, surface_color});
	}
	else wires.push_back({base_color, surface_color});
	if (metadata.GetBool(Texture))
	{
		append(splitter, "rscolorsplitter.outa", surface, "toonmaterial.opacity_color") iferr_return;
	}
	else
	{
		reader(1, surface, "toonmaterial.opacity_color") iferr_return;
	}
	reader(7, toon_scale, "rsmathmulvector.input2") iferr_return;
	reader(8, toon_bias, "rsmathaddvector.input2") iferr_return;
	reader(9, toon_add, "rsmathaddvector.input2") iferr_return;
	append(toon_border, "texturesampler.outcolor", toon_texture, "texturesampler.invalid_color") iferr_return;
	append(metadata.GetBool(ToonHasTexture) ? toon_texture : ramp,
		metadata.GetBool(ToonHasTexture) ? "texturesampler.outcolor" : "rsramp.outcolor",
		toon_scale, "rsmathmulvector.input1") iferr_return;
	append(toon_scale, "rsmathmulvector.out", toon_bias, "rsmathaddvector.input1") iferr_return;
	append(toon_bias, "rsmathaddvector.out", toon_clamp, "rsmathsaturatevector.input") iferr_return;
	append(toon_clamp, "rsmathsaturatevector.out", toon_add, "rsmathaddvector.input1") iferr_return;
	// An unassigned Toon reference also skips Toon Morph multiplication.
	append(metadata.GetBool(ToonNeutralFallback) ? ramp : toon_add,
		metadata.GetBool(ToonNeutralFallback) ? "rsramp.outcolor" : "rsmathaddvector.out",
		surface, "toonmaterial.base_tone_map") iferr_return;
	reader(10, contour, "contour.externalcolor") iferr_return;
	reader(11, contour, "contour.externalopacity") iferr_return;
	reader(12, contour, "contour.externalthicknessmodifier") iferr_return;
	const auto surface_out = mmd_rs::Output(surface, mmd_rs::CoreId("toonmaterial.outcolor")) iferr_return;
	const auto contour_out = mmd_rs::Output(contour, mmd_rs::CoreId("contour.outcolor")) iferr_return;
	const auto output_surface = mmd_rs::Input(output, maxon::Id("com.redshift3d.redshift4c4d.node.output.surface")) iferr_return;
	const auto output_contour = mmd_rs::Input(output, maxon::Id("com.redshift3d.redshift4c4d.node.output.contour")) iferr_return;
	wires.push_back({surface_out, output_surface});
	wires.push_back({contour_out, output_contour});
	return wires;
}

maxon::Result<void> ConnectWires(const std::vector<Wire>& wires)
{
	iferr_scope;
	for (const auto& wire : wires)
	{
		wire.source.Connect(wire.destination) iferr_return;
	}
	return maxon::OK;
}

maxon::Result<void> ReplaceValidatedWires(const std::vector<Wire>& previous,
	const std::vector<Wire>& next)
{
	iferr_scope;
	for (const auto& old : previous)
	{
		Bool retained = false;
		for (const auto& wire : next)
			if (old.source == wire.source && old.destination == wire.destination) retained = true;
		if (!retained)
		{
			old.source.Connect(old.destination, maxon::WIRE_MODE::REMOVE) iferr_return;
		}
	}
	ConnectWires(next) iferr_return;
	return maxon::OK;
}

maxon::Result<Bool> ValidateWires(const std::vector<Wire>& wires)
{
	iferr_scope;
	for (const auto& wire : wires)
	{
		if (!maxon::GraphModelHelper::IsConnected(wire.source, wire.destination)) return false;
		Bool conflict = false;
		maxon::GraphModelHelper::GetDirectPredecessors(wire.destination, maxon::NODE_KIND::PORT_MASK,
			[&](const maxon::GraphNode& from) -> maxon::Result<Bool>
			{
				if (from != wire.source) conflict = true;
				return true;
			}) iferr_return;
		if (conflict) return false;
	}
	return true;
}

maxon::Result<void> ValidateRoles(const maxon::nodes::NodesGraphModelRef& graph)
{
	iferr_scope;
	// A profile identifies one complete output recipe. Multiple native Toon
	// surfaces or outputs require the artist to resolve the graph explicitly.
	for (const auto& asset : {mmd_rs::CoreId("toonmaterial"), maxon::Id(mmd_rs::OutputAsset)})
	{
		Int count = 0;
		maxon::GraphModelHelper::FindNodesByAssetId(graph, asset, true,
			[&](const maxon::GraphNode&) -> maxon::Result<Bool> { ++count; return true; }) iferr_return;
		if (count != 1) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	}
	for (const auto& role : k_roles)
	{
		const auto node = Node(graph, role.id) iferr_return;
		Bool match = false;
		maxon::GraphModelHelper::FindNodesByAssetId(graph, mmd_rs::CoreId(role.asset), true,
			[&](const maxon::GraphNode& candidate) -> maxon::Result<Bool>
			{
				if (candidate == node) match = true;
				return true;
			}) iferr_return;
		if (!match) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
		Int64 expected = 0;
		if (std::strcmp(role.asset, "rsmathaddvector") == 0) expected = 3;
		else if (std::strcmp(role.asset, "rsmathmulvector") == 0) expected = 5;
		else if (std::strcmp(role.asset, "rsmathsaturatevector") == 0) expected = 19;
		if (expected)
		{
			const std::string operation_port = std::string(role.asset) + ".math_op";
			const auto input = mmd_rs::Input(node, mmd_rs::CoreId(operation_port.c_str())) iferr_return;
			const auto operation = input.GetPortValue<Int64>() iferr_return;
			if (!operation || *operation != expected) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
		}
	}
	return maxon::OK;
}

maxon::Result<void> ValidateCriticalSettings(const maxon::nodes::NodesGraphModelRef& graph, const BaseContainer& metadata)
{
	iferr_scope;
	const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
	const auto knots = mmd_rs::Input(ramp, mmd_rs::CoreId("rsramp.ramp")) iferr_return;
	for (Int32 index = 0; index < 2; ++index)
	{
		const auto knot = knots.FindChild(maxon::Id(index == 0 ? "_0" : "_1")) iferr_return;
		const auto color = knot.FindChild(maxon::Id("color")) iferr_return;
		const auto value = color.GetPortValue<maxon::Color64>() iferr_return;
		const Float64 expected = index == 0 && !metadata.GetBool(ToonNeutralFallback) ? 0.3 : 1.0;
		if (!value || Abs(value->r - expected) > 1e-6 || Abs(value->g - expected) > 1e-6
			|| Abs(value->b - expected) > 1e-6)
			return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	}
	const auto texture = Node(graph, "cmt_diffuse_texture") iferr_return;
	const auto toon = Node(graph, "cmt_toon_texture") iferr_return;
	const auto contour = Node(graph, "cmt_toon_contour") iferr_return;
	const auto border = Node(graph, "cmt_toon_border_texture") iferr_return;
	const auto alpha = mmd_rs::Input(texture, mmd_rs::CoreId("texturesampler.alpha_is_luminance")) iferr_return;
	const auto domain = mmd_rs::Input(toon, mmd_rs::CoreId("texturesampler.tone_map_enable")) iferr_return;
	const auto thickness = mmd_rs::Input(contour, mmd_rs::CoreId("contour.externalthickness")) iferr_return;
	const auto luminance = alpha.GetPortValue<Bool>() iferr_return;
	const auto tone_map = domain.GetPortValue<Bool>() iferr_return;
	const auto width = thickness.GetPortValue<Float64>() iferr_return;
	if (!luminance || *luminance || !tone_map || !*tone_map || !width || *width != 1024.0)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	const auto scale_port = mmd_rs::Input(border, mmd_rs::CoreId("texturesampler.scale")) iferr_return;
	const auto offset_port = mmd_rs::Input(border, mmd_rs::CoreId("texturesampler.offset")) iferr_return;
	const auto scale = scale_port.GetPortValue<maxon::Vector2d64>() iferr_return;
	const auto offset = offset_port.GetPortValue<maxon::Vector2d64>() iferr_return;
	if (!scale || !offset || scale->x != 0.0 || scale->y != 0.0 || offset->x != 0.5
		|| offset->y != metadata.GetFloat(mmd_material_binding::ToonBoundaryV))
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return maxon::OK;
}

maxon::Result<void> ConfigureRamp(const maxon::GraphNode& ramp, const Bool neutral)
{
	iferr_scope;
	const auto knots = mmd_rs::Input(ramp, mmd_rs::CoreId("rsramp.ramp")) iferr_return;
	for (Int32 index = 0; index < 2; ++index)
	{
		const auto knot = knots.FindChild(maxon::Id(index == 0 ? "_0" : "_1")) iferr_return;
		const auto position = knot.FindChild(maxon::Id("position")) iferr_return;
		const auto color = knot.FindChild(maxon::Id("color")) iferr_return;
		const auto interpolation = knot.FindChild(maxon::Id("interpolation")) iferr_return;
		position.SetPortValue(index == 0 ? 0.0 : 0.5) iferr_return;
		color.SetPortValue(maxon::Color64(index == 0 && !neutral ? 0.3 : 1.0)) iferr_return;
		interpolation.SetPortValue(k_stepInterpolation) iferr_return;
	}
	mmd_rs::Set(ramp, "rsramp.ramp_interp", Int32(0)) iferr_return;
	return maxon::OK;
}

maxon::Result<void> SetContourFlags(const maxon::nodes::NodesGraphModelRef& graph, const Bool enabled)
{
	iferr_scope;
	const auto contour = Node(graph, "cmt_toon_contour") iferr_return;
	mmd_rs::Set(contour, "contour.externalenable", enabled) iferr_return;
	mmd_rs::Set(contour, "contour.internalenable", false) iferr_return;
	mmd_rs::Set(contour, "contour.backfacingenable", false) iferr_return;
	return maxon::OK;
}

maxon::Result<void> ConfigureSpecularMask(const maxon::GraphNode& ramp)
{
	iferr_scope;
	// Without Fresnel, Toon reflection can cover the diffuse layer even in
	// weakly lit parts of the lobe. Its native tonemap mask restores a smooth
	// fade to the base. Use the specular lighting domain, not the mesh UVs or
	// the stepped diffuse ramp; Power still controls the lobe's roughness.
	const auto knots = mmd_rs::Input(ramp, mmd_rs::CoreId("rsramp.ramp")) iferr_return;
	for (Int32 index = 0; index < 2; ++index)
	{
		const auto knot = knots.FindChild(maxon::Id(index == 0 ? "_0" : "_1")) iferr_return;
		const auto position = knot.FindChild(maxon::Id("position")) iferr_return;
		const auto color = knot.FindChild(maxon::Id("color")) iferr_return;
		const auto interpolation = knot.FindChild(maxon::Id("interpolation")) iferr_return;
		position.SetPortValue(static_cast<Float64>(index)) iferr_return;
		color.SetPortValue(maxon::Color64(static_cast<Float64>(index))) iferr_return;
		// Gradient knots use "linearknot" (spline points use "linear"). An
		// unknown ID is accepted by the graph but renders as a hard step.
		interpolation.SetPortValue(maxon::Id("linearknot")) iferr_return;
	}
	mmd_rs::Set(ramp, "rsramp.ramp_interp", Int32(1)) iferr_return;
	return maxon::OK;
}

maxon::Result<BaseContainer> BuildGraph(BaseMaterial* material, const MMDMaterialData& data)
{
	iferr_scope;
	static_cast<NodeMaterial*>(material)->CreateEmptyGraph(mmd_rs::Space) iferr_return;
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	auto transaction = mmd_rs::Transaction(graph) iferr_return;
	for (const auto& role : k_roles)
	{
		graph.AddChild(maxon::Id(role.id), mmd_rs::CoreId(role.asset)) iferr_return;
	}
	graph.AddChild(maxon::Id("cmt_toon_output"), maxon::Id(mmd_rs::OutputAsset)) iferr_return;
	for (Int32 field = 0; field < ToonFieldCount; ++field)
	{
		graph.AddChild(maxon::Id(k_readers[field]), mmd_rs::CoreId(IsColorField(field) ? "rsuserdatacolor" : "rsuserdatascalar")) iferr_return;
	}
	const auto surface = Node(graph, "cmt_toon_surface") iferr_return;
	const auto texture = Node(graph, "cmt_diffuse_texture") iferr_return;
	const auto toon_texture = Node(graph, "cmt_toon_texture") iferr_return;
	const auto toon_border = Node(graph, "cmt_toon_border_texture") iferr_return;
	const auto contour = Node(graph, "cmt_toon_contour") iferr_return;
	const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
	const auto specular_mask = Node(graph, "cmt_specular_mask") iferr_return;
	BaseContainer metadata;
	metadata.SetBool(ImporterOwned, true);
	metadata.SetInt32(Profile, ToonProfile);
	metadata.SetInt32(GraphRevision, ToonGraphRevision);
	metadata.SetString(Surface, MaxonConvert(surface.GetPath().ToString()));
	metadata.SetBool(Texture, ReadableTexture(data.texture_path));
	metadata.SetBool(ToonHasTexture, ReadableTexture(data.toon_texture_path));
	metadata.SetString(TexturePath, data.texture_path);
	metadata.SetString(ToonTexturePath, data.toon_texture_path);
	metadata.SetString(SphereTexturePath, data.sphere_texture_path);
	metadata.SetInt32(SphereMode, data.sphere_mode);
	metadata.SetBool(SphereHasTexture, (data.sphere_mode == 1 || data.sphere_mode == 2)
		&& ReadableTexture(data.sphere_texture_path));
	metadata.SetFloat(ToonBoundaryV, BrightEndpointV(data.toon_texture_path));
	metadata.SetBool(ToonNeutralFallback, cmt_material::UseNeutralToonFallback(
		data.toon_mode, data.toon_texture_index, data.toon_texture_path.IsPopulated()));
	metadata.SetBool(EdgeEnabled, data.edge_enabled);
	metadata.SetString(ProfileDiagnostic, MMDRedShiftToonMaterialAdapter::SupportDiagnostic(data));
	SetTexturePath(texture, data.texture_path) iferr_return;
	SetTexturePath(toon_texture, data.toon_texture_path) iferr_return;
	SetTexturePath(toon_border, data.toon_texture_path) iferr_return;
	const auto sphere_texture = Node(graph, "cmt_sphere_texture") iferr_return;
	const auto sphere_matcap = Node(graph, "cmt_sphere_matcap") iferr_return;
	SetTexturePath(sphere_texture, data.sphere_texture_path) iferr_return;
	// Respect the document's automatic input-color rules for every texture.
	// A blanket Raw interpretation raises color-image midtones after the
	// display transform and makes the model appear brighter than intended.
	for (const auto& sampler : {texture, toon_texture, toon_border, sphere_texture})
	{
		const auto bundle = mmd_rs::Input(sampler, mmd_rs::CoreId("texturesampler.tex0")) iferr_return;
		const auto colorspace = bundle.FindChild(maxon::Id("colorspace")) iferr_return;
		if (!colorspace.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
		colorspace.SetPortValue(maxon::String("Auto")) iferr_return;
	}
	// PMX sphere coordinates use the camera-space normal without perspective
	// distortion. Matcap's World mode is camera-dependent and supplies that
	// mapping; the sphere contribution is combined before the Toon multiplier.
	mmd_rs::Set(sphere_matcap, "matcap.space", Int32(0)) iferr_return;
	mmd_rs::Set(sphere_texture, "texturesampler.alpha_is_luminance", false) iferr_return;
	// Unwrapped UVs outside the tone-map domain return Invalid Color. Use an
	// actual image sample at the bright endpoint, including its native color
	// management, rather than turning high-intensity lighting black.
	mmd_rs::Set(toon_border, "texturesampler.scale", maxon::Vector2d64(0.0)) iferr_return;
	mmd_rs::Set(toon_border, "texturesampler.offset", maxon::Vector2d64(0.5, metadata.GetFloat(ToonBoundaryV))) iferr_return;
	mmd_rs::Set(texture, "texturesampler.alpha_is_luminance", false) iferr_return;
	mmd_rs::Set(toon_texture, "texturesampler.tone_map_enable", true) iferr_return;
	// MMD Toon bitmaps use a vertical ramp; native RS tone mapping uses U.
	// Rotate the sampler domain by 90 degrees and clamp both texture axes.
	mmd_rs::Set(toon_texture, "texturesampler.rotate", Float64(90.0)) iferr_return;
	// Approximate the legacy N.L + 0.5 lighting bias in the native tone-map
	// domain. RS still owns light intensity and the treatment of backfaces.
	mmd_rs::Set(toon_texture, "texturesampler.offset", maxon::Vector2d64(0.0, 0.5)) iferr_return;
	mmd_rs::Set(toon_texture, "texturesampler.wrapu", false) iferr_return;
	mmd_rs::Set(toon_texture, "texturesampler.wrapv", false) iferr_return;
	mmd_rs::Set(surface, "toonmaterial.refl_use_fresnel", false) iferr_return;
	mmd_rs::Set(surface, "toonmaterial.refl_weight", Float64(1.0)) iferr_return;
	mmd_rs::Set(surface, "toonmaterial.refl_tone_map_mode", Int32(1)) iferr_return;
	mmd_rs::Set(surface, "toonmaterial.refl_indirect", Float64(0.0)) iferr_return;
	mmd_rs::Set(surface, "toonmaterial.base_tone_map_mode", Int32(1)) iferr_return;
	mmd_rs::Set(contour, "contour.externalthickness", Float64(1024.0)) iferr_return;
	ConfigureRamp(ramp, metadata.GetBool(ToonNeutralFallback)) iferr_return;
	ConfigureSpecularMask(specular_mask) iferr_return;
	SetContourFlags(graph, data.edge_enabled) iferr_return;
	SetReaderDefaults(graph, MMDMaterialRuntimeState::FromBase(data), metadata.GetBool(Texture)) iferr_return;
	const auto wires = Wires(graph, metadata) iferr_return;
	ConnectWires(wires) iferr_return;
	ValidateRoles(graph) iferr_return;
	transaction.Commit() iferr_return;
	return metadata;
}
}
#endif

Bool MMDRedShiftToonMaterialAdapter::IsAvailable(String& diagnostic)
{
	if (mmd_toon_regression::Injected(GetActiveDocument(), mmd_toon_regression::Fault::Unavailable))
	{ diagnostic = "Regression host has no required RS Toon assets"_s; return false; }
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	if (!GeIsMainThread()) { diagnostic = "RS Toon availability must be checked on the main thread"_s; return false; }
	auto& cache = AvailabilityCache();
	if (cache.checked) { diagnostic = cache.diagnostic; return cache.available; }
	if (cache.probing)
	{
		diagnostic = "RS Toon capability check is already running"_s;
		return false;
	}
	cache.probing = true;
	BaseMaterial* probe = BaseMaterial::Alloc(Mmaterial);
	cache.diagnostic = "RS Toon probe could not allocate a material"_s;
	if (probe)
	{
		iferr (BuildGraph(probe, MMDMaterialData()))
		{
			cache.diagnostic = String("RS Toon graph probe failed: ") + MaxonConvert(err.ToString(nullptr));
		}
		else
		{
			cache.available = true;
			cache.diagnostic = "RS Toon available"_s;
		}
		BaseMaterial::Free(probe);
	}
	cache.checked = true;
	cache.probing = false;
	diagnostic = cache.diagnostic;
	return cache.available;
#else
	diagnostic = "RS Toon requires a compatible node SDK and renderer"_s;
	return false;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::AvailabilityForUi(String& diagnostic)
{
	if (mmd_toon_regression::Injected(GetActiveDocument(), mmd_toon_regression::Fault::Unavailable))
	{ diagnostic = "Regression host has no required RS Toon assets"_s; return false; }
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	if (GeIsMainThread())
	{
		const auto& cache = AvailabilityCache();
		if (cache.checked) { diagnostic = cache.diagnostic; return cache.available; }
	}
	// A cold cache permits the action, which performs its own capability check.
	// Reading the page must remain safe before RS has initialized in this run.
	diagnostic = "RS Toon compatibility will be checked on import or conversion"_s;
	return true;
#else
	diagnostic = "RS Toon requires a compatible node SDK and renderer"_s;
	return false;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::IsToonMaterial(const BaseMaterial* material)
{
	return material && mmd_material_binding::Metadata(material).GetInt32(mmd_material_binding::Profile) == mmd_material_binding::ToonProfile;
}

String MMDRedShiftToonMaterialAdapter::SupportDiagnostic(const MMDMaterialData& data)
{
	String diagnostic = "RS Toon: stylized lighting; contour width approximated at 3px per edge-size unit (1080p)"_s;
	if (data.toon_texture_path.IsPopulated() && !ReadableTexture(data.toon_texture_path))
		diagnostic += "; Toon texture unavailable, default ramp used"_s;
	if (data.texture_path.IsPopulated() && !ReadableTexture(data.texture_path))
		diagnostic += "; Base texture unavailable, diffuse color used"_s;
	if (data.sphere_mode == 3)
		diagnostic += "; SubTexture/Additional UV shading is not mapped"_s;
	else if ((data.sphere_mode == 1 || data.sphere_mode == 2)
		&& data.sphere_texture_path.IsPopulated() && !ReadableTexture(data.sphere_texture_path))
		diagnostic += "; Sphere texture unavailable, sphere contribution bypassed"_s;
	if (data.ambient.x != 0.0 || data.ambient.y != 0.0 || data.ambient.z != 0.0)
		diagnostic += "; Independent Ambient shading is not mapped"_s;
	if (data.draw_ground_shadow || data.draw_cast_self_shadow || data.draw_receive_self_shadow || data.draw_vertex_color)
		diagnostic += "; PMX shadow/vertex-color flags are not independently mapped"_s;
	return diagnostic;
}

BaseMaterial* MMDRedShiftToonMaterialAdapter::CreateFromPMX(const libmmd::PMXMaterial& material,
	const maxon::BaseArray<Filename>& paths, const maxon::String& name)
{
	MMDMaterialData data;
	ResolvePMXMaterialData(material, paths, data);
	BaseMaterial* result = CreateFromData(data);
	if (result) result->SetName(name);
	return result;
}

BaseMaterial* MMDRedShiftToonMaterialAdapter::CreateFromData(const MMDMaterialData& data)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	if (!GeIsMainThread()) return nullptr;
	BaseMaterial* material = BaseMaterial::Alloc(Mmaterial);
	if (!material) return nullptr;
	iferr_scope_handler
	{
		GePrint("[MMD] RS Toon creation failed: "_s + err.GetMessage());
		BaseMaterial::Free(material);
		return nullptr;
	};
	const auto metadata = BuildGraph(material, data) iferr_return;
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	material->SetName(data.name_local);
	return material;
#else
	return nullptr;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::PrepareMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
	BaseObject* model, BaseObject* mesh, String& diagnostic)
{
	return Bind(data, material, model, mesh, false, diagnostic);
}

Bool MMDRedShiftToonMaterialAdapter::RepairMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
	BaseObject* model, BaseObject* mesh, String& diagnostic)
{
	return Bind(data, material, model, mesh, true, diagnostic);
}

Bool MMDRedShiftToonMaterialAdapter::Bind(const MMDMaterialData& data, BaseMaterial* material,
	BaseObject* model, BaseObject* mesh, const Bool repair, String& diagnostic)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || !IsToonMaterial(material) || !model || !mesh) return false;
	if (IsBound(material) && !repair) return ValidateMorphBinding(material, diagnostic);
	if (repair && !IsOwner(material, model, material->GetDocument())) return false;
	iferr_scope_handler { diagnostic = "RS Toon binding preparation failed; owned graph changes were rolled back"_s; return false; };
	const auto previous = Metadata(material);
	BaseContainer metadata = previous;
	BaseContainer cleanup = previous;
	if (repair && previous.GetInt32(GraphRevision) != 3
		&& previous.GetInt32(GraphRevision) != ToonGraphRevision)
	{
		diagnostic = "RS Toon graph revision is unsupported; convert an independent material"_s;
		return false;
	}
	// Resolve old owned IDs before allocating replacement fields. Missing metadata
	// must not leave a stale attribute behind, and ambiguous names are not safe
	// evidence of ownership. Unrelated or renamed artist attributes are retained.
	if (repair && !SnapshotOwnedAttributes(mesh, previous, cleanup, diagnostic)) return false;
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	ValidateRoles(graph) iferr_return;
	ValidateCriticalSettings(graph, metadata) iferr_return;
	auto transaction = mmd_rs::Transaction(graph) iferr_return;
	for (Int32 field = 0; field < ToonFieldCount; ++field)
	{
		const auto existing = graph.GetNode(maxon::NodePath()).FindChild(maxon::Id(k_readers[field])) iferr_return;
		if (!existing.IsValid())
		{
			if (!repair) return false;
			graph.AddChild(maxon::Id(k_readers[field]), mmd_rs::CoreId(IsColorField(field) ? "rsuserdatacolor" : "rsuserdatascalar")) iferr_return;
		}
	}
	const auto wires = Wires(graph, metadata) iferr_return;
	const Bool valid = ValidateWires(wires) iferr_return;
	if (!valid && !repair) { diagnostic = "RS Toon has an edited connection; create an independent material"_s; return false; }
	if (repair)
	{
		for (const auto& wire : wires)
		{
			Bool conflict = false;
			maxon::GraphModelHelper::GetDirectPredecessors(wire.destination, maxon::NODE_KIND::PORT_MASK,
				[&](const maxon::GraphNode& from) -> maxon::Result<Bool>
				{
					if (from != wire.source) conflict = true;
					return true;
				}) iferr_return;
			if (conflict) { diagnostic = "RS Toon input has an artist connection; create an independent material"_s; return false; }
		}
		ConnectWires(wires) iferr_return;
	}
	if (metadata.GetString(Token).IsEmpty())
	{
		maxon::Uuid uuid;
		uuid.CreateId() iferr_return;
		metadata.SetString(Token, MaxonConvert(uuid.ToString()));
	}
	metadata.SetLink(Model, model);
	metadata.SetInt32(Version, CurrentVersion);
	metadata.SetInt32(GraphRevision, ToonGraphRevision);
	metadata.SetBool(ToonNeutralFallback, cmt_material::UseNeutralToonFallback(
		data.toon_mode, data.toon_texture_index, data.toon_texture_path.IsPopulated()));
	const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
	ConfigureRamp(ramp, metadata.GetBool(ToonNeutralFallback)) iferr_return;
	const auto next_wires = Wires(graph, metadata) iferr_return;
	ReplaceValidatedWires(wires, next_wires) iferr_return;
	const BaseContainer source_info = model->GetDataInstance()->GetContainer(g_mmd_material_texture_morph_shader_id);
	metadata.SetBool(AdditionalUvUsage, source_info.GetBool(AdditionalUvUsage));
	metadata.SetString(ProfileDiagnostic, SupportDiagnostic(data));
	if (source_info.GetBool(AdditionalUvUsage))
		metadata.SetString(ProfileDiagnostic, metadata.GetString(ProfileDiagnostic) + String("; Additional UV Morph shading is not mapped"));
	BindingRestore restore{material, mesh, previous};
	SetReaderDefaults(graph, MMDMaterialRuntimeState::FromBase(data), metadata.GetBool(Texture)) iferr_return;
	for (Int32 field = 0; field < ToonFieldCount; ++field)
	{
		const auto reader = Node(graph, k_readers[field]) iferr_return;
		const maxon::String attribute = MaxonConvert(AttributeName(metadata.GetString(Token), static_cast<Field>(field)));
		mmd_rs::Set(reader, IsColorField(field) ? "rsuserdatacolor.attribute" : "rsuserdatascalar.attribute", attribute) iferr_return;
	}
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	const auto state = MMDMaterialRuntimeState::FromBase(data);
	if (!PrepareUserData(mesh, material, state))
	{
		material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, previous);
		diagnostic = "RS Toon mesh attributes could not be allocated"_s;
		return false;
	}
	restore.allocated = true;
	if (mmd_toon_regression::Injected(model, mmd_toon_regression::Fault::BindingAttributes))
	{ diagnostic = "Injected Toon binding failure after attribute allocation"_s; return false; }
	transaction.Commit() iferr_return;
	if (repair) RemoveUserData(mesh, cleanup);
	restore.committed = true;
	material->SetDirty(DIRTYFLAGS::DATA);
	material->Message(MSG_UPDATE);
	diagnostic = Metadata(material).GetString(ProfileDiagnostic);
	return true;
#else
	diagnostic = "RS Toon is unavailable for this SDK"_s;
	return false;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::ValidateMorphBinding(BaseMaterial* material, String& diagnostic) const
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	using namespace mmd_material_binding;
	if (!IsToonMaterial(material) || !IsBound(material)) return false;
	iferr_scope_handler { diagnostic = "RS Toon structure is incomplete or edited; explicit repair is required"_s; return false; };
	const BaseContainer metadata = Metadata(material);
	if (metadata.GetInt32(Version) != CurrentVersion || metadata.GetInt32(GraphRevision) != ToonGraphRevision)
	{ diagnostic = "RS Toon binding version requires explicit upgrade"_s; return false; }
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	ValidateRoles(graph) iferr_return;
	ValidateCriticalSettings(graph, metadata) iferr_return;
	const auto surface = Node(graph, "cmt_toon_surface") iferr_return;
	if (metadata.GetString(Surface) != MaxonConvert(surface.GetPath().ToString())) return false;
	const auto wires = Wires(graph, metadata) iferr_return;
	const Bool valid = ValidateWires(wires) iferr_return;
	if (!valid) { diagnostic = "RS Toon connection was edited; create an independent material"_s; return false; }
	for (Int32 field = 0; field < ToonFieldCount; ++field)
	{
		if (metadata.GetInt32(UserDataKey(metadata, field)) <= 0 || metadata.GetString(Token).IsEmpty())
		{
			diagnostic = "RS Toon attribute metadata is missing; explicit repair is required"_s;
			return false;
		}
		const auto reader = Node(graph, k_readers[field]) iferr_return;
		const auto input = mmd_rs::Input(reader, mmd_rs::CoreId(IsColorField(field) ? "rsuserdatacolor.attribute" : "rsuserdatascalar.attribute")) iferr_return;
		const auto value = input.GetPortValue<maxon::String>() iferr_return;
		const auto name = value.GetValue() iferr_return;
		if (name != MaxonConvert(AttributeName(metadata.GetString(Token), static_cast<Field>(field))))
		{ diagnostic = "RS Toon attribute identity was edited; explicit repair is required"_s; return false; }
	}
	diagnostic = metadata.GetString(ProfileDiagnostic);
	return true;
#else
	diagnostic = "RS Toon requires a compatible node SDK and renderer"_s;
	return false;
#endif
}

void MMDRedShiftToonMaterialAdapter::ReadFrom(const BaseMaterial*, MMDMaterialData&)
{
	// Managed output has no independent base value. UI already explains this.
}

void MMDRedShiftToonMaterialAdapter::SyncTo(const MMDMaterialData& data, BaseMaterial* material)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || !IsToonMaterial(material)) return;
	String diagnostic;
	if (IsBound(material) && !ValidateMorphBinding(material, diagnostic)) return;
	iferr_scope_handler { GePrint("[MMD] RS Toon sync failed: "_s + err.GetMessage()); return; };
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	BaseContainer metadata = Metadata(material);
	const auto previous_wires = Wires(graph, metadata) iferr_return;
	auto transaction = mmd_rs::Transaction(graph) iferr_return;
	SetContourFlags(graph, data.edge_enabled) iferr_return;
	const Bool neutral_toon = cmt_material::UseNeutralToonFallback(
		data.toon_mode, data.toon_texture_index, data.toon_texture_path.IsPopulated());
	metadata.SetBool(ToonNeutralFallback, neutral_toon);
	const auto next_wires = Wires(graph, metadata) iferr_return;
	ReplaceValidatedWires(previous_wires, next_wires) iferr_return;
	const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
	ConfigureRamp(ramp, neutral_toon) iferr_return;
	// Authoring updates the base fallback used by material previews; evaluated
	// Morph values remain on the mesh attributes and never overwrite this base.
	SetReaderDefaults(graph, MMDMaterialRuntimeState::FromBase(data), Metadata(material).GetBool(Texture)) iferr_return;
	transaction.Commit() iferr_return;
	material->SetName(data.name_local);
	metadata.SetBool(EdgeEnabled, data.edge_enabled);
	metadata.SetString(ProfileDiagnostic, SupportDiagnostic(data));
	if (metadata.GetBool(AdditionalUvUsage))
		metadata.SetString(ProfileDiagnostic, metadata.GetString(ProfileDiagnostic) + String("; Additional UV Morph shading is not mapped"));
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	material->SetDirty(DIRTYFLAGS::DATA);
	material->Message(MSG_UPDATE);
#endif
}

#if CMT_SDK_HAS_REDSHIFT_NODE_API
namespace
{
Bool UpdateTextureRole(MMDRedShiftToonMaterialAdapter& adapter, const MMDMaterialData& previous,
	const String& path, BaseMaterial* material, const Bool toon, String& diagnostic)
{
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || !adapter.ValidateMorphBinding(material, diagnostic)) return false;
	if (path.IsPopulated() && !ReadableTexture(path))
	{ diagnostic = "Texture file cannot be decoded; RS Toon binding was preserved"_s; return false; }
	iferr_scope_handler { diagnostic = "RS Toon texture edit failed; graph transaction was rolled back"_s; return false; };
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	BaseContainer metadata = Metadata(material);
	MMDMaterialData candidate;
	if (!previous.CopyTo(candidate)) return false;
	if (toon) candidate.toon_texture_path = path;
	else candidate.texture_path = path;
	const auto sampler = Node(graph, toon ? "cmt_toon_texture" : "cmt_diffuse_texture") iferr_return;
	const auto file = TexturePathPort(sampler) iferr_return;
	const auto current = file.GetPortValue<maxon::Url>() iferr_return;
	const auto url = current.GetValue() iferr_return;
	const Int32 path_key = toon ? ToonTexturePath : TexturePath;
	if (Filename(MaxonConvert(url).GetString()) != Filename(metadata.GetString(path_key)))
	{ diagnostic = "Owned RS Toon texture path was edited; create an independent material"_s; return false; }
	const auto old_wires = Wires(graph, metadata) iferr_return;
	maxon::GraphNode border;
	if (toon)
	{
		border = Node(graph, "cmt_toon_border_texture") iferr_return;
		const auto border_path = TexturePathPort(border) iferr_return;
		const auto old_border = border_path.GetPortValue<maxon::Url>() iferr_return;
		const auto old_border_url = old_border.GetValue() iferr_return;
		if (Filename(MaxonConvert(old_border_url).GetString()) != Filename(metadata.GetString(ToonTexturePath)))
		{ diagnostic = "Owned Toon endpoint path was edited; create an independent material"_s; return false; }
		metadata.SetFloat(ToonBoundaryV, BrightEndpointV(path));
		metadata.SetBool(ToonNeutralFallback, cmt_material::UseNeutralToonFallback(
			candidate.toon_mode, candidate.toon_texture_index, path.IsPopulated()));
	}
	metadata.SetBool(toon ? ToonHasTexture : Texture, path.IsPopulated());
	metadata.SetString(path_key, path);
	const auto new_wires = Wires(graph, metadata) iferr_return;
	auto transaction = mmd_rs::Transaction(graph) iferr_return;
	// Only remove exact validated edges whose source changes. All other branches,
	// including artist consumers of a dormant sampler, retain their connections.
	for (const auto& old : old_wires)
	{
		Bool retained = false;
		for (const auto& next : new_wires)
			if (old.source == next.source && old.destination == next.destination) retained = true;
		if (!retained)
		{
			old.source.Connect(old.destination, maxon::WIRE_MODE::REMOVE) iferr_return;
		}
	}
	SetTexturePath(sampler, path) iferr_return;
	if (toon)
	{
		SetTexturePath(border, path) iferr_return;
		const auto ramp = Node(graph, "cmt_toon_ramp") iferr_return;
		ConfigureRamp(ramp, metadata.GetBool(ToonNeutralFallback)) iferr_return;
		mmd_rs::Set(border, "texturesampler.offset", maxon::Vector2d64(0.5, metadata.GetFloat(ToonBoundaryV))) iferr_return;
	}
	ConnectWires(new_wires) iferr_return;
	transaction.Commit() iferr_return;
	metadata.SetString(ProfileDiagnostic, MMDRedShiftToonMaterialAdapter::SupportDiagnostic(candidate));
	if (metadata.GetBool(AdditionalUvUsage))
		metadata.SetString(ProfileDiagnostic, metadata.GetString(ProfileDiagnostic) + String("; Additional UV Morph shading is not mapped"));
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	material->SetDirty(DIRTYFLAGS::DATA);
	material->Message(MSG_UPDATE);
	diagnostic = metadata.GetString(ProfileDiagnostic);
	return true;
}
}
#endif

Bool MMDRedShiftToonMaterialAdapter::UpdateMorphTexture(const MMDMaterialData& previous, const String& path,
	BaseMaterial* material, String& diagnostic)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	return UpdateTextureRole(*this, previous, path, material, false, diagnostic);
#else
	return false;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::UpdateToonTexture(const MMDMaterialData& previous, const String& path,
	BaseMaterial* material, String& diagnostic)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	return UpdateTextureRole(*this, previous, path, material, true, diagnostic);
#else
	return false;
#endif
}

Bool MMDRedShiftToonMaterialAdapter::UpdateSphereTexture(const MMDMaterialData& previous,
	const String& path, const Int32 mode, BaseMaterial* material, String& diagnostic)
{
#if CMT_SDK_HAS_REDSHIFT_NODE_API
	using namespace mmd_material_binding;
	if (!GeIsMainThread() || mode < 0 || mode > 3 || !ValidateMorphBinding(material, diagnostic)) return false;
	if (path.IsPopulated() && !ReadableTexture(path))
	{ diagnostic = "Sphere texture file cannot be decoded; RS Toon binding was preserved"_s; return false; }
	iferr_scope_handler { diagnostic = "Sphere texture edit failed; graph transaction was rolled back"_s; return false; };
	const auto graph = static_cast<NodeMaterial*>(material)->GetGraph(mmd_rs::Space) iferr_return;
	BaseContainer metadata = Metadata(material);
	const auto sampler = Node(graph, "cmt_sphere_texture") iferr_return;
	const auto file = TexturePathPort(sampler) iferr_return;
	const auto installed = file.GetPortValue<maxon::Url>() iferr_return;
	const auto installed_url = installed.GetValue() iferr_return;
	if (Filename(MaxonConvert(installed_url).GetString()) != Filename(metadata.GetString(SphereTexturePath)))
	{ diagnostic = "Owned sphere texture path was edited; create an independent material"_s; return false; }
	const auto previous_wires = Wires(graph, metadata) iferr_return;
	metadata.SetString(SphereTexturePath, path);
	metadata.SetInt32(SphereMode, mode);
	metadata.SetBool(SphereHasTexture, path.IsPopulated() && (mode == 1 || mode == 2));
	const auto next_wires = Wires(graph, metadata) iferr_return;
	// Mode changes can activate a previously dormant combine node. Preserve an
	// artist's connections there too instead of adding a second predecessor.
	for (const auto& next : next_wires)
	{
		Bool conflict = false;
		maxon::GraphModelHelper::GetDirectPredecessors(next.destination, maxon::NODE_KIND::PORT_MASK,
			[&](const maxon::GraphNode& from) -> maxon::Result<Bool>
			{
				Bool owned = from == next.source;
				for (const auto& old : previous_wires)
					if (old.destination == next.destination && old.source == from) owned = true;
				if (!owned) conflict = true;
				return true;
			}) iferr_return;
		if (conflict) { diagnostic = "Sphere input has an artist connection; create an independent material"_s; return false; }
	}
	MMDMaterialData candidate;
	if (!previous.CopyTo(candidate)) return false;
	candidate.sphere_texture_path = path;
	candidate.sphere_mode = mode;
	auto transaction = mmd_rs::Transaction(graph) iferr_return;
	SetTexturePath(sampler, path) iferr_return;
	ReplaceValidatedWires(previous_wires, next_wires) iferr_return;
	transaction.Commit() iferr_return;
	metadata.SetString(ProfileDiagnostic, SupportDiagnostic(candidate));
	if (metadata.GetBool(AdditionalUvUsage))
		metadata.SetString(ProfileDiagnostic, metadata.GetString(ProfileDiagnostic) + String("; Additional UV Morph shading is not mapped"));
	material->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, metadata);
	material->SetDirty(DIRTYFLAGS::DATA);
	material->Message(MSG_UPDATE);
	diagnostic = metadata.GetString(ProfileDiagnostic);
	return true;
#else
	return false;
#endif
}
