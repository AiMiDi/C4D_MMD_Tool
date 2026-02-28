#include "mmd_redshift_material.h"
#include <c4d_symbols.h>
#include "module/core/cmt_marco.h"

namespace
{
	constexpr auto ID_REDSHIFT_MATERIAL = 1036224;
}

#if API_VERSION >= 2024000
#include "maxon/graph.h"
#include "maxon/graph_helper.h"
#include "maxon/nodesgraph.h"

namespace
{
	constexpr maxon::LiteralId g_redshiftId("com.redshift3d.redshift4c4d.class.nodespace");
	const maxon::Id k_standardMaterialAssetId("com.redshift3d.redshift4c4d.nodes.core.standardmaterial");
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.standardmaterial.base_color", rs_base_color);
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.standardmaterial.opacity_color", rs_opacity_color);

	static maxon::Result<maxon::GraphNode> FindStandardMaterialNode(const maxon::nodes::NodesGraphModelRef& graph)
	{
		iferr_scope;
		maxon::GraphNode matNode;
		Bool found = false;
		maxon::GraphModelHelper::FindNodesByAssetId(
			graph, k_standardMaterialAssetId, true,
			[&matNode, &found](const maxon::GraphNode& node) -> maxon::Result<Bool>
			{
				matNode = node;
				found = true;
				return false;
			}) iferr_return;
		if (!found)
			return maxon::GraphNode();
		return matNode;
	}

	static maxon::Result<void> SetPortValue(const maxon::GraphNode& node, const maxon::InternedId& portId, const maxon::Color64& value)
	{
		iferr_scope;
		const auto inputs = node.GetInputs() iferr_return;
		const auto port = inputs.FindChild(portId) iferr_return;
		if (port.IsValid())
		{
			port.SetPortValue(value) iferr_return;
		}
		return maxon::OK;
	}

	static maxon::Result<maxon::Opt<const maxon::Color64&>> GetPortValue(const maxon::GraphNode& node, const maxon::InternedId& portId)
	{
		iferr_scope;
		const auto inputs = node.GetInputs() iferr_return;
		const auto port = inputs.FindChild(portId) iferr_return;
		if (!port.IsValid())
			return maxon::Opt<const maxon::Color64&>();
		auto result = port.GetPortValue<maxon::Color64>() iferr_return;
		return result;
	}
}
#endif

BaseMaterial* CreateRedShiftMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
#if API_VERSION >= 2024000
	iferr_scope_handler { return nullptr; };

	BaseMaterial* material = BaseMaterial::Alloc(ID_REDSHIFT_MATERIAL);
	if (!material)
	{
		MessageDialog(GeLoadString(IDS_MES_RENDERER_NOT_INSTALLED, "RedShift"_s));
		return nullptr;
	}

	auto* node_mat = static_cast<NodeMaterial*>(material);
	if (!node_mat->HasSpace(g_redshiftId))
	{
		node_mat->CreateDefaultGraph(g_redshiftId) iferr_return;
	}
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		const auto& color = pmx_material.m_diffuse;
		const maxon::Color64 baseColor(color.x(), color.y(), color.z());
		SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

		const Float64 alpha = static_cast<Float64>(color.w());
		const maxon::Color64 opacityColor(alpha, alpha, alpha);
		SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;
	}

	material->SetName(material_name);
	return material;
#else
	(void)pmx_material;
	(void)texture_paths;
	(void)material_name;
	return nullptr;
#endif
}

BaseMaterial* CreateRedShiftMaterialFromData(const MMDMaterialData& data)
{
#if API_VERSION >= 2024000
	iferr_scope_handler { return nullptr; };

	BaseMaterial* material = BaseMaterial::Alloc(ID_REDSHIFT_MATERIAL);
	if (!material)
	{
		MessageDialog(GeLoadString(IDS_MES_RENDERER_NOT_INSTALLED, "RedShift"_s));
		return nullptr;
	}

	auto* node_mat = static_cast<NodeMaterial*>(material);
	if (!node_mat->HasSpace(g_redshiftId))
	{
		node_mat->CreateDefaultGraph(g_redshiftId) iferr_return;
	}
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		const maxon::Color64 baseColor(data.diffuse_rgb.x, data.diffuse_rgb.y, data.diffuse_rgb.z);
		SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

		const Float64 alpha = static_cast<Float64>(data.diffuse_alpha);
		const maxon::Color64 opacityColor(alpha, alpha, alpha);
		SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;
	}

	material->SetName(data.name_local);
	return material;
#else
	(void)data;
	return nullptr;
#endif
}

void SyncToRedShiftMaterial(const MMDMaterialData& data, BaseMaterial* material)
{
#if API_VERSION >= 2024000
	if (!material || material->GetType() != ID_REDSHIFT_MATERIAL)
		return;
	iferr_scope_handler { return; };

	material->SetName(data.name_local);

	auto* node_mat = static_cast<NodeMaterial*>(material);
	if (!node_mat->HasSpace(g_redshiftId))
		return;
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		const maxon::Color64 baseColor(data.diffuse_rgb.x, data.diffuse_rgb.y, data.diffuse_rgb.z);
		SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

		const Float64 alpha = static_cast<Float64>(data.diffuse_alpha);
		const maxon::Color64 opacityColor(alpha, alpha, alpha);
		SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;
	}
#else
	(void)data;
	(void)material;
#endif
}

void ReadFromRedShiftMaterial(const BaseMaterial* material, MMDMaterialData& data)
{
#if API_VERSION >= 2024000
	if (!material || material->GetType() != ID_REDSHIFT_MATERIAL)
		return;
	iferr_scope_handler { return; };

	data.name_local = material->GetName();

	auto* node_mat = static_cast<NodeMaterial*>(const_cast<BaseMaterial*>(material));
	if (!node_mat->HasSpace(g_redshiftId))
		return;
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		auto colorOpt = GetPortValue(matNode, rs_base_color) iferr_return;
		if (colorOpt)
		{
			data.diffuse_rgb.x = static_cast<Float>(colorOpt->r);
			data.diffuse_rgb.y = static_cast<Float>(colorOpt->g);
			data.diffuse_rgb.z = static_cast<Float>(colorOpt->b);
		}

		auto opacityOpt = GetPortValue(matNode, rs_opacity_color) iferr_return;
		if (opacityOpt)
			data.diffuse_alpha = static_cast<Float>(opacityOpt->r);
	}
#else
	(void)material;
	(void)data;
#endif
}
