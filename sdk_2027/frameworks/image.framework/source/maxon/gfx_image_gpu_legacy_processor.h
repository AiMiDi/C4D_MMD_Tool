#ifndef GFX_IMAGE_GPU_LEGACY_PROCESSOR_H__
#define GFX_IMAGE_GPU_LEGACY_PROCESSOR_H__

#include "maxon/object.h"
#include "maxon/forwardref.h"

namespace maxon
{

class ColorProfileGpuHandlerRef;
class ColorProfile;

enum class COLORCONVERSIONFLAGS_GPU;
enum class COLORCONVERSION_OPTIMIZATION_GPU_FLAGS;

/// @addtogroup Drawport
/// @{

class ColorProfileLegacyProcessorInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ColorProfileLegacyProcessorInterface, MAXON_REFERENCE_ALWAYS_COPY_ON_WRITE, "net.maxon.image.interface.legacygpuprocessor");

public:
	static MAXON_METHOD Result<ForwardRef<ColorProfileGpuHandlerRef>> CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
};

#include "gfx_image_gpu_legacy_processor1.hxx"
#include "gfx_image_gpu_legacy_processor2.hxx"

/// @}

} // namespace maxon

#endif // GFX_IMAGE_GPU_LEGACY_PROCESSOR_H__
