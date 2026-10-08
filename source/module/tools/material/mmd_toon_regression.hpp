#pragma once

// Fault controls exist only in explicit regression builds. They are scoped to
// a private document/model container and never read by shipping binaries.
namespace mmd_toon_regression
{
enum class Fault : Int32
{
	Unavailable = 1, BindingAttributes, AfterBinding, AfterAssignment, AfterLink
};
inline Bool Injected(BaseList2D* target, const Fault fault)
{
#if defined(CMT_ENABLE_RUNTIME_REGRESSION)
	const Bool matched = target && target->GetDataInstance()->GetContainer(g_mmd_material_texture_morph_shader_id)
		.GetInt32(9001) == static_cast<Int32>(fault);
	if (matched)
	{
		// The document is outside the object/mesh Undo snapshots. This marker
		// proves the injected branch executed even when Undo replaces node data.
		if (auto* doc = target->GetDocument())
		{
			BaseContainer receipt = doc->GetDataInstance()->GetContainer(g_mmd_material_texture_morph_shader_id);
			receipt.SetInt32(9002, static_cast<Int32>(fault));
			doc->GetDataInstance()->SetContainer(g_mmd_material_texture_morph_shader_id, receipt);
		}
	}
	return matched;
#else
	(void)target;
	(void)fault;
	return false;
#endif
}
}
