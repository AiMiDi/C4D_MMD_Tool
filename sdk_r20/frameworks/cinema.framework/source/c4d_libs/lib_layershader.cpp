#include "c4d_string.h"
#include "lib_layershader.h"

LayerShaderLib* lib_layershader = nullptr;

static LayerShaderLib *CheckLayerShaderLib(Int32 offset)
{
	return (LayerShaderLib*)CheckLib(LAYER_SHADER_LIB, offset, (C4DLibrary**)&lib_layershader);
}

#define LayerShaderLibCall(b) 		LayerShaderLib *lib = CheckLayerShaderLib(LIBOFFSET(LayerShaderLib, b)); \
															if (!lib || !lib->b) return; \
															(((BlendLayer*)this)->*(lib->b))

#define LayerShaderLibCallR(a, b)  LayerShaderLib *lib = CheckLayerShaderLib(LIBOFFSET(LayerShaderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((BlendLayer*)this)->*(lib->b))

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
	LayerShaderLibCallR(false, GetParameter)(id, d);
}

Bool LayerShaderLayer::SetParameter(Int32 id, const GeData &d)
{
	LayerShaderLibCallR(false, SetParameter)(id, d);
}

LayerShaderLayer* LayerShader::GetFirstLayer()
{
	LayerShaderLib *lib = CheckLayerShaderLib(LIBOFFSET(LayerShaderLib, GetNext));
	if (!lib) return nullptr;
	return lib->GetFirstLayer((BaseShader*)this);
}
