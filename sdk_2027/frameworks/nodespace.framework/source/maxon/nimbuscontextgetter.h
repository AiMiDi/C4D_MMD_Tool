#ifndef NIMBUSCONTEXTGETTER_H__
#define NIMBUSCONTEXTGETTER_H__

#include "maxon/nimbusbase.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Function type for NimbusContextGetters. Such a function has to compute the new value for a global context value.
/// It mustn't modify the graph except for user-state attributes.
/// @param[in] nimbus							The nimbus object which defines the context.
/// @param[in] currentValue				The current context value.
/// @param[in] uniqueOrigin				Empty for the usual global context case, but when the context is a unique global context
///																(see nodes::GNODE_FLAGS::UNIQUE_GLOBAL_CONTEXT_PORT), then this is set to the path of the port
///																which asks for the context.
/// @return												The context value derived from the nimbus object. If an empty Data object is returned,
/// 															the context value will be left at its current value.
//----------------------------------------------------------------------------------------
using NimbusContextGetter = Result<Data>(*)(const NimbusBaseRef& nimbus, const Data& currentValue, const NodePath& uniqueOrigin);

//----------------------------------------------------------------------------------------
/// This registry collects functions used by NimbusBaseInterface::UpdateGlobalContext.
/// For any nested port of the GlobalContext port, the port's value is set up by the
/// function registered under the id of the port (except for unique global context ports,
/// see NimbusUniqueContextGetter).
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(NimbusContextGetter, NimbusContextGetters, "net.maxon.registry.nimbuscontextgetters");

namespace NimbusContextGetters
{
	/// @brief [Int32] The color management setting (DOCUMENT_COLOR_MANAGEMENT)
	MAXON_DECLARATION(NimbusContextGetter, ColorManagement, "net.maxon.nimbuscontextgetter.colormanagement");
	/// @brief [Int32] The input color profile if basic color management (DOCUMENT_COLORPROFILE)
	MAXON_DECLARATION(NimbusContextGetter, ColorManagementBasicColorProfile, "net.maxon.nimbuscontextgetter.colormanagement.colorprofile");
	/// @brief [OcioConfig] Document OCIO configuration if ocio color management
	MAXON_DECLARATION(NimbusContextGetter, OCIOConfig, "net.maxon.nimbuscontextgetter.colormanagement.ocioconfig");

	/// @brief [CString] Colorspace names Render/Display/ViewTransform/ViewTransformThumbnails if ocio color management
	MAXON_DECLARATION(NimbusContextGetter, ColorspaceName_Render, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.render");
	MAXON_DECLARATION(NimbusContextGetter, ColorspaceName_Display, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.display");
	MAXON_DECLARATION(NimbusContextGetter, ColorspaceName_ViewTransform, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.viewtransform");
	MAXON_DECLARATION(NimbusContextGetter, ColorspaceName_ViewTransformThumbnails, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.viewtransformthumbnails");

	MAXON_DECLARATION(NimbusContextGetter, DocumentUnitScaleData, "net.maxon.nimbuscontextgetter.docunitscaledata");
}

//----------------------------------------------------------------------------------------
/// For a unique global context port (see nodes::GNODE_FLAGS::UNIQUE_GLOBAL_CONTEXT_PORT),
/// this attribute has to be set at the port (in addition to the UNIQUE_GLOBAL_CONTEXT_PORT flag).
/// The value is a callback function pointer which will be called by the method NimbusBaseInterface::UpdateGlobalContext.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(NimbusContextGetter, NimbusUniqueContextGetter, "net.maxon.nimbuscontextgetter.unique");

} // namespace maxon

#endif // NIMBUSCONTEXTGETTER_H__
