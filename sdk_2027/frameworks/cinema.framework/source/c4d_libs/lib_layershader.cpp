#include "c4d_string.h"
#include "lib_layershader.h"

namespace cinema
{

LayerShaderLib* lib_layershader = nullptr;

static LayerShaderLib *CheckLayerShaderLib(Int32 offset)
{
	return CheckLib<LayerShaderLib>(LAYER_SHADER_LIB, offset, lib_layershader);
}

#define LayerShaderLibCall(b) 		cinema::LayerShaderLib *lib = cinema::CheckLayerShaderLib(LIBOFFSET(cinema::LayerShaderLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::BlendLayer*>(this)->*(lib->b))

#define LayerShaderLibCallR(a, b)  cinema::LayerShaderLib *lib = cinema::CheckLayerShaderLib(LIBOFFSET(cinema::LayerShaderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::BlendLayer*>(this)->*(lib->b))

#define LayerShaderLibCallRC(a, b)  cinema::LayerShaderLib *lib = cinema::CheckLayerShaderLib(LIBOFFSET(cinema::LayerShaderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::BlendLayer*>(this)->*(lib->b))

LayerShaderLayer* LayerShaderLayer::GetNext()
{
	LayerShaderLibCallR(nullptr, GetNext)();
}

LayerType LayerShaderLayer::GetType()
{
	LayerShaderLibCallR(TypeUnknown, GetType)();
}

String LayerShaderLayer::GetName(BaseDocument* doc)
{
	LayerShaderLibCallR(String(), GetName)(doc);
}

BaseBitmap* LayerShaderLayer::GetPreview()
{
	LayerShaderLibCallR(nullptr, GetPreview)();
}

Bool LayerShaderLayer::GetParameter(Int32 id, GeData &d) const
{
	LayerShaderLibCallRC(false, GetParameter)(id, d);
}

Bool LayerShaderLayer::SetParameter(Int32 id, const GeData &d)
{
	LayerShaderLibCallR(false, SetParameter)(id, d);
}

LayerShaderLayer* LayerShader::GetFirstLayer()
{
	LayerShaderLib *lib = CheckLayerShaderLib(LIBOFFSET(LayerShaderLib, GetNext));
	if (!lib) return nullptr;
	return lib->GetFirstLayer(static_cast<BaseShader*>(this));
}

LayerShaderLayer* LayerShader::AddLayer(LayerType type, LayerShaderLayer* parent)
{
	LayerShaderLib* lib = CheckLayerShaderLib(LIBOFFSET(LayerShaderLib, GetNext));
	if (!lib)
		return nullptr;
	return lib->AddLayer((BaseShader*)this, type, parent);
}


} // namespace cinema
