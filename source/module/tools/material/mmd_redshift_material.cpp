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
	const maxon::Id k_textureSamplerAssetId("com.redshift3d.redshift4c4d.nodes.core.texturesampler");
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.standardmaterial.base_color", rs_base_color);
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.standardmaterial.opacity_color", rs_opacity_color);
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.texturesampler.tex0", rs_tex0);
	MAXON_INTERNED_ID_LOCAL("path", rs_tex0_path);
	MAXON_INTERNED_ID_LOCAL("com.redshift3d.redshift4c4d.nodes.core.texturesampler.outcolor", rs_tex_outcolor);

	static Bool IsRedShiftMaterial(const BaseMaterial* mat)
	{
		if (!mat)
			return false;
		if (mat->GetType() == ID_REDSHIFT_MATERIAL)
			return true;
		auto* node_mat = static_cast<NodeMaterial*>(const_cast<BaseMaterial*>(mat));
		return node_mat->HasSpace(g_redshiftId);
	}

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

	template<typename T>
	static maxon::Result<void> SetPortValue(const maxon::GraphNode& node, const maxon::InternedId& portId, const T& value)
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

	static maxon::Result<void> ConnectOutputToInput(
		const maxon::GraphNode& srcNode, const maxon::InternedId& outputPortId,
		const maxon::GraphNode& dstNode, const maxon::InternedId& inputPortId)
	{
		iferr_scope;
		const auto srcOutputs = srcNode.GetOutputs() iferr_return;
		const auto srcPort = srcOutputs.FindChild(outputPortId) iferr_return;
		const auto dstInputs = dstNode.GetInputs() iferr_return;
		const auto dstPort = dstInputs.FindChild(inputPortId) iferr_return;
		if (srcPort.IsValid() && dstPort.IsValid())
		{
			srcPort.Connect(dstPort) iferr_return;
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

BaseMaterial* MMDRedShiftMaterialAdapter::CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
#if API_VERSION >= 2024000
	bool has_texture = false;
	bool has_alpha_channel = false;
	const auto texture_index = pmx_material.m_textureIndex;
	if (texture_index != -1 && texture_index < texture_paths.GetCount())
	{
		const auto& texture_path = texture_paths[texture_index];
		if (GeFExist(texture_path))
		{
			has_texture = true;
			AutoAlloc<BaseBitmap> bitmap;
			if (bitmap && bitmap->Init(texture_path) == IMAGERESULT::OK)
			{
				if (bitmap->GetChannelCount() > 0)
				{
					BaseBitmap* alpha_bmp = bitmap->GetInternalChannel();
					if (alpha_bmp)
					{
						const Int32 w = bitmap->GetBw();
						const Int32 h = bitmap->GetBh();
						constexpr Int32 step = 4;
						for (Int32 y = 0; y < h && !has_alpha_channel; y += step)
						{
							for (Int32 x = 0; x < w && !has_alpha_channel; x += step)
							{
								UInt16 val = 0;
								bitmap->GetAlphaPixel(alpha_bmp, x, y, &val);
								if (val < 255)
									has_alpha_channel = true;
							}
						}
					}
				}
			}
		}
	}

	BaseMaterial* material = BaseMaterial::Alloc(Mmaterial);
	if (!material)
		return nullptr;

	iferr_scope_handler
	{
		GePrint("[MMD] RS material error: "_s + err.GetMessage());
		BaseMaterial::Free(material);
		return nullptr;
	};

	auto* node_mat = static_cast<NodeMaterial*>(material);
	node_mat->CreateDefaultGraph(g_redshiftId) iferr_return;
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		auto transaction = graph.BeginTransaction() iferr_return;

		if (has_texture)
		{
			auto texNode = graph.AddChild(maxon::Id(), k_textureSamplerAssetId) iferr_return;

			const maxon::Url textureUrl = MaxonConvert(texture_paths[texture_index], MAXONCONVERTMODE::READ);
			const auto texInputs = texNode.GetInputs() iferr_return;
			const auto tex0Port = texInputs.FindChild(rs_tex0) iferr_return;
			if (tex0Port.IsValid())
			{
				const auto pathPort = tex0Port.FindChild(rs_tex0_path) iferr_return;
				if (pathPort.IsValid())
				{
					pathPort.SetPortValue(textureUrl) iferr_return;
				}
			}

			ConnectOutputToInput(texNode, rs_tex_outcolor, matNode, rs_base_color) iferr_return;

			if (has_alpha_channel)
			{
				ConnectOutputToInput(texNode, rs_tex_outcolor, matNode, rs_opacity_color) iferr_return;
			}
		}
		else
		{
			const auto& color = pmx_material.m_diffuse;
			const maxon::Color64 baseColor(color.x(), color.y(), color.z());
			SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

			const Float64 alpha = static_cast<Float64>(color.w());
			const maxon::Color64 opacityColor(alpha, alpha, alpha);
			SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;
		}

		transaction.Commit() iferr_return;
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

BaseMaterial* MMDRedShiftMaterialAdapter::CreateFromData(const MMDMaterialData& data)
{
#if API_VERSION >= 2024000
	bool has_texture = false;
	bool has_alpha_channel = false;
	const Filename texture_path(data.texture_path);
	if (texture_path.IsPopulated() && GeFExist(texture_path))
	{
		has_texture = true;
		AutoAlloc<BaseBitmap> bitmap;
		if (bitmap && bitmap->Init(texture_path) == IMAGERESULT::OK)
		{
			if (bitmap->GetChannelCount() > 0)
			{
				BaseBitmap* alpha_bmp = bitmap->GetInternalChannel();
				if (alpha_bmp)
				{
					const Int32 w = bitmap->GetBw();
					const Int32 h = bitmap->GetBh();
					for (Int32 y = 0; y < h && !has_alpha_channel; ++y)
					{
						for (Int32 x = 0; x < w && !has_alpha_channel; ++x)
						{
							UInt16 val = 0;
							bitmap->GetAlphaPixel(alpha_bmp, x, y, &val);
							if (val < 255)
								has_alpha_channel = true;
						}
					}
				}
			}
		}
	}

	BaseMaterial* material = BaseMaterial::Alloc(Mmaterial);
	if (!material)
		return nullptr;

	iferr_scope_handler
	{
		GePrint("[MMD] RS material error: "_s + err.GetMessage());
		BaseMaterial::Free(material);
		return nullptr;
	};

	auto* node_mat = static_cast<NodeMaterial*>(material);
	node_mat->CreateDefaultGraph(g_redshiftId) iferr_return;
	const maxon::nodes::NodesGraphModelRef& graph = node_mat->GetGraph(g_redshiftId) iferr_return;

	auto matNode = FindStandardMaterialNode(graph) iferr_return;
	if (matNode.IsValid())
	{
		auto transaction = graph.BeginTransaction() iferr_return;

		if (has_texture)
		{
			auto texNode = graph.AddChild(maxon::Id(), k_textureSamplerAssetId) iferr_return;

			const maxon::Url textureUrl = MaxonConvert(texture_path, MAXONCONVERTMODE::READ);
			const auto texInputs = texNode.GetInputs() iferr_return;
			const auto tex0Port = texInputs.FindChild(rs_tex0) iferr_return;
			if (tex0Port.IsValid())
			{
				const auto pathPort = tex0Port.FindChild(rs_tex0_path) iferr_return;
				if (pathPort.IsValid())
				{
					pathPort.SetPortValue(textureUrl) iferr_return;
				}
			}

			ConnectOutputToInput(texNode, rs_tex_outcolor, matNode, rs_base_color) iferr_return;

			if (has_alpha_channel)
			{
				ConnectOutputToInput(texNode, rs_tex_outcolor, matNode, rs_opacity_color) iferr_return;
			}
		}
		else
		{
			const maxon::Color64 baseColor(data.diffuse_rgb.x, data.diffuse_rgb.y, data.diffuse_rgb.z);
			SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

			const Float64 alpha = static_cast<Float64>(data.diffuse_alpha);
			const maxon::Color64 opacityColor(alpha, alpha, alpha);
			SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;
		}

		transaction.Commit() iferr_return;
	}

	material->SetName(data.name_local);
	return material;
#else
	(void)data;
	return nullptr;
#endif
}

void MMDRedShiftMaterialAdapter::SyncTo(const MMDMaterialData& data, BaseMaterial* material)
{
#if API_VERSION >= 2024000
	if (!IsRedShiftMaterial(material))
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
		auto transaction = graph.BeginTransaction() iferr_return;

		const maxon::Color64 baseColor(data.diffuse_rgb.x, data.diffuse_rgb.y, data.diffuse_rgb.z);
		SetPortValue(matNode, rs_base_color, baseColor) iferr_return;

		const Float64 alpha = static_cast<Float64>(data.diffuse_alpha);
		const maxon::Color64 opacityColor(alpha, alpha, alpha);
		SetPortValue(matNode, rs_opacity_color, opacityColor) iferr_return;

		transaction.Commit() iferr_return;
	}
#else
	(void)data;
	(void)material;
#endif
}

void MMDRedShiftMaterialAdapter::ReadFrom(const BaseMaterial* material, MMDMaterialData& data)
{
#if API_VERSION >= 2024000
	if (!IsRedShiftMaterial(material))
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
