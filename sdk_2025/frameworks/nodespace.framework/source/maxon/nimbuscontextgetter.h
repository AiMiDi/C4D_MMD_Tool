#ifndef NIMBUSCONTEXTGETTER_H__
#define NIMBUSCONTEXTGETTER_H__

#include "maxon/nimbusbase.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Delegate type for NimbusContextGetters.
/// @param[in] nimbus							The nimbus object which defines the context.
/// @return												The context value derived from the nimbus object.
//----------------------------------------------------------------------------------------
using NimbusContextGetter = Delegate<Result<Data>(const NimbusBaseRef& nimbus)>;

//----------------------------------------------------------------------------------------
/// This registry collects delegates used by NimbusBaseInterface::UpdateGlobalContext.
/// For any nested port of the GlobalContext port, the port's value is set up by the
/// delegate registered under the id of the port.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(NimbusContextGetter, NimbusContextGetters, "net.maxon.registry.nimbuscontextgetters");

namespace NIMBUSCONTEXTGETTER
{
	/// @brief [Int32] The color management setting (DOCUMENT_COLOR_MANAGEMENT)
	MAXON_ATTRIBUTE(Data, ColorManagement, "net.maxon.nimbuscontextgetter.colormanagement");
	/// @brief [Int32] The input color profile if basic color management (DOCUMENT_COLORPROFILE)
	MAXON_ATTRIBUTE(Data, ColorManagementBasicColorProfile, "net.maxon.nimbuscontextgetter.colormanagement.colorprofile");
	/// @brief [OcioConfig] Document OCIO configuration if ocio color management
	MAXON_ATTRIBUTE(Data, OCIOConfig, "net.maxon.nimbuscontextgetter.colormanagement.ocioconfig");

	/// @brief [CString] Colorspace names Render/Display/ViewTransform/ViewTransformThumbnails if ocio color management
	MAXON_ATTRIBUTE(Data, ColorspaceName_Render, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.render");
	MAXON_ATTRIBUTE(Data, ColorspaceName_Display, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.display");
	MAXON_ATTRIBUTE(Data, ColorspaceName_ViewTransform, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.viewtransform");
	MAXON_ATTRIBUTE(Data, ColorspaceName_ViewTransformThumbnails, "net.maxon.nimbuscontextgetter.colormanagement.colorspacename.viewtransformthumbnails");
}

#include "nimbuscontextgetter1.hxx"
#include "nimbuscontextgetter2.hxx"


} // namespace maxon

#endif // NIMBUSCONTEXTGETTER_H__
