#if 1
namespace maxon
{
#ifndef SVG_BASE_H__
#endif
	const maxon::Char* const VectorImageInterface::MTable::_ids = 
		"Init@1db4eca46d9225b9\0" // Result<void> Init(const Url& url)
		"Init@d584185136fcfd0b\0" // Result<void> Init(const SVGDocument& svgDocument)
		"GetUrl@dd23129f046419ec\0" // const Url& GetUrl() const
		"GetSVGDocument@819c4f9281e5c316\0" // const SVGDocument& GetSVGDocument() const
		"GetSVGDocument@5a62b7f92911991b\0" // SVGDocument& GetSVGDocument()
	"";
	const maxon::METHOD_FLAGS VectorImageInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VectorImageInterface, , "net.maxon.image.interface.vectorimage", (ImageBaseInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int VectorImageInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<const SVGDocument&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(VectorImageClasses);
	namespace VectorImageClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BASE, , "net.maxon.image.vectorimageclass.base");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_gfx_image_vector(0
	| maxon::VectorImageInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
