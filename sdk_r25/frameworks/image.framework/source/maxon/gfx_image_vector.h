#ifndef GFX_IMAGE_VECTOR_H__
#define GFX_IMAGE_VECTOR_H__

#include "maxon/forwardref.h"
#include "maxon/gfx_image.h"


namespace maxon
{

class SVGDocument;

/// @addtogroup Graphics
/// @{

//----------------------------------------------------------------------------------------
/// The ImageInterface represents a single image with a ImageTextureRef.
/// one or more Images can be part of a ImageTextureRef.
//----------------------------------------------------------------------------------------
class VectorImageInterface : MAXON_INTERFACE_BASES(ImageBaseInterface)
{
	MAXON_INTERFACE(VectorImageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.vectorimage");

public:
	MAXON_METHOD Result<void> Init(const Url& vectorIconUrl);
	MAXON_METHOD Result<void> Init(const SVGDocument& vectorIcon);

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetVectorIcon() const;
};

#include "gfx_image_vector1.hxx"

MAXON_REGISTRY(Class<VectorImageRef>, VectorImageClasses, "net.maxon.image.registry.vectorimageclasses");

namespace VectorImageClasses
{
	MAXON_DECLARATION(VectorImageClasses::EntryType, BASE, "net.maxon.image.vectorimageclass.base");
}

#include "gfx_image_vector2.hxx"

/// @}

} // namespace maxon

#endif // GFX_IMAGE_VECTOR_H__
