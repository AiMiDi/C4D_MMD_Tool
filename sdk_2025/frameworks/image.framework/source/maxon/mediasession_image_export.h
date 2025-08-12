#ifndef MEDIASESSION_IMAGE_EXPORT_H__
#define MEDIASESSION_IMAGE_EXPORT_H__

#include "maxon/mediasession_output.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Registry to register all image saver.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Class<MediaOutputUrlRef>, ImageSaverClasses, "net.maxon.image.registry.imagesaverclasses");

} // namespace maxon


#endif // MEDIASESSION_IMAGE_EXPORT_H__
