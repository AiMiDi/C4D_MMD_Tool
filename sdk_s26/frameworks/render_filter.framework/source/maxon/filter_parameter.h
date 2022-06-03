#ifndef FILTER_PARAMETER_H__
#define FILTER_PARAMETER_H__

#include "filter_image.h"

namespace maxon
{
namespace OIDNFilterParameter
{
	// Set to true if the input data is in high dynamic range.
	MAXON_ATTRIBUTE(Bool, HDR, "net.maxon.renderfilter.parameter.oidn.hdr");
	
	// Determines whether the color is encoded in sRGB or is linear. HDR is assumed to be linear
	MAXON_ATTRIBUTE(Bool, SRGB, "net.maxon.renderfilter.parameter.oidn.srgb");
	
	// Optional OIDN parameter.
	// You can set RDATA_DENOISER_ALBEDO_ID and RDATA_DENOISER_ALBEDO_SUBID to tell the denoiser videopost plugin what VpBuffer (from AllocateBuffers) it should use
	MAXON_ATTRIBUTE(FilterImageRef, ALBEDO, "net.maxon.renderfilter.parameter.oidn.albedo");
	
	// Optional OIDN parameter. Requires OIDNFilterParameter::ALBEDO to be set. Must be in [-inf,inf] range. World-space or view-space
	// You can set RDATA_DENOISER_NORMAL_ID and RDATA_DENOISER_NORMAL_SUBID to tell the denoiser videopost plugin what VpBuffer (from AllocateBuffers) it should use
	MAXON_ATTRIBUTE(FilterImageRef, NORMAL, "net.maxon.renderfilter.parameter.oidn.normal");
}

#include "filter_parameter1.hxx"
#include "filter_parameter2.hxx"
}

MAXON_DEPENDENCY_WEAK("maxon/filter_parameter.h"); // This is an optional component

#endif // FILTER_PARAMETER_H__
