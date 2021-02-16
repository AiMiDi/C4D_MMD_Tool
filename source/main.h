#ifndef MAIN_H__
#define MAIN_H__

#include <memory>
#include "c4d.h"
#include "c4d_plugin.h"
#include "ge_prepass.h"
#include "c4d_symbols.h"
#include "maxon/sortedarray.h"
#include "maxon/pointerarray.h"
#include "maxon/queue.h"
#include "operatingsystem.h"
#include "customgui_priority.h"
#include "xcolor.h"
#include "ocajoint.h"
#include "tcaik.h"
#include "tcaconstraint.h"
#include "tcaweight.h"
#include "lib_ca.h"
#include "lib_modeling.h"
#include "lib_ngon.h"
#include "c4d_baseobject.h"
#include "tprotection.h"
#include "undef_win_macros.h"
#include "EncodingConversion.h"

class MMDTool;

Bool RegisterMMDTool();

#endif // MAIN_H__
