#ifndef GFX_IMAGE_VECTOR_H__
#define GFX_IMAGE_VECTOR_H__

#include "maxon/forwardref.h"
#include "maxon/gfx_image.h"


namespace maxon
{
class SVGDocument;
#ifndef SVG_BASE_H__
template <> class DefaultValueFunctions<SVGDocument>
{
public:
	static const SVGDocument& DefaultValueRef()
	{
		return GetPtrSizedZeroRef<SVGDocument>();
	}
};
#endif

/// @addtogroup Graphics
/// @{

//----------------------------------------------------------------------------------------
/// The VectorImageInterface represents a vector image (internally SVG).
/// This class wraps the vector image into a ImageBaseRef. The draw functions then extract 
/// that and draw the image as vector image.
//----------------------------------------------------------------------------------------
class VectorImageInterface : MAXON_INTERFACE_BASES(ImageBaseInterface)
{
	MAXON_INTERFACE(VectorImageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.vectorimage", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));

public:
	//----------------------------------------------------------------------------------------
	/// Initialized the Vector image with the given url of an svg image.
	/// @param[in] url								Url of a svg file to load.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Initializes the image with a SVGDocument.
	/// @param[in] svgDocument				The image.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const SVGDocument& svgDocument);

	//----------------------------------------------------------------------------------------
	/// GetUrl returns the url of the image.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// GetSVGDocument returns the SVGDocument connected to this image (read only).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const SVGDocument& GetSVGDocument() const;

	//----------------------------------------------------------------------------------------
	/// GetSVGDocument returns the SVGDocument connected to this image (read and write).
	/// Note: image must be marked as dirty after modifying the SVGDocument in order to draw the changes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SVGDocument& GetSVGDocument();
};

#include "gfx_image_vector1.hxx"

MAXON_REGISTRY(Class<VectorImageRef>, VectorImageClasses, "net.maxon.image.registry.vectorimageclasses");

namespace VectorImageClasses
{
	MAXON_DECLARATION(VectorImageClasses::EntryType, BASE, "net.maxon.image.vectorimageclass.base", MAXON_IMPLEMENTATION_MODULE("net.maxon.image"));
}

#include "gfx_image_vector2.hxx"

/// @}

} // namespace maxon

#endif // GFX_IMAGE_VECTOR_H__
