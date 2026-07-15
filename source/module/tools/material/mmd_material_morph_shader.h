/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Description:	通用 MMD 材质表情贴图系数 ShaderData。

包装一个原始贴图 child shader，对其采样结果应用 PMX texture/sphere/toon factor。
`Output()` 只读取 shader 自身参数（render-time 快照）与 child shader 采样结果，
不读取或修改任何可变场景状态（满足材质表情 ShaderData 的只读约束）。

**************************************************************************/

#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"

/**
 * @brief 在 Standard 材质贴图通道上包装原贴图 shader，应用材质表情贴图系数。
 *
 * child shader 通过 `InsertUnder` 挂在本 shader 之下（`GetDown()` 取得）。
 * 有效系数由材质表情运行时 evaluator 预计算并写入本 shader 的参数。
 */
class MMDMaterialTextureMorphShader final : public ShaderData
{
	Vector m_factor_rgb = Vector(1.0);
	Float m_factor_alpha = 1.0;
public:
	static NodeData* Alloc() { return NewObjClear(MMDMaterialTextureMorphShader); }

	SDK2024_InitOverride;
	INITRENDERRESULT InitRender(BaseShader* sh, const InitRenderStruct& irs) override;
	void FreeRender(BaseShader* sh) override;
	Vector Output(BaseShader* sh, ChannelData* cd) override;
};

namespace cmt_register
{
	Bool RegisterMMDMaterialTextureMorphShader();
}
