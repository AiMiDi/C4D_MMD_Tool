#pragma once

// std
#include <optional>
#include <variant>
#include <fstream>
#include <tuple>
#include <vector>
#include <cassert>

// C4D
#include <c4d.h>
#include <c4d_basetime.h>
#include <c4d_filterdata.h>
#include <c4d_gui.h>
#include <c4d_string.h>
#include "maxon/pointerarray.h"
#include "maxon/sortedarray.h"
#include "tprotection.h"

// The third party
#include "yaml-cpp/yaml.h"
#include "iconv.h"

// symbols
#include "c4d_symbols.h"
#include "plugin_resource.h"

// utils
#include "utils/time_util.hpp"
#include "utils/images_user_area_util.hpp"
#include "utils/code_conversion_util.hpp"
#include "utils/filename_util.hpp"

#include "module/core/cmt_marco.h"

