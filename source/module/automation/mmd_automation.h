#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"

namespace cmt { namespace automation
{

// Called by SceneHook::Message(MSG_BASECONTAINER) with a qualified caller-owned
// packet. Request/result fields never enter the document's persistent container.
// Owns document resolution, input validation and serial dispatch.
// It does not depend on CMT_ENABLE_RUNTIME_REGRESSION or open a network listener.
Bool Dispatch(BaseDocument* owner, BaseContainer* storage);

} }
