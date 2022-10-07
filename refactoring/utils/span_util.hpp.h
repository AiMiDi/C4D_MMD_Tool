/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/7
File:			span_util.hpp
Description:	span util

**************************************************************************/

#ifndef _SPAN_UTIL_H_
#define _SPAN_UTIL_H_

#ifdef __cpp_lib_span

#include <span>
namespace span_namespace = std;

#else

#include "span.hpp"
namespace span_namespace = tcb;

#endif

#endif // !_SPAN_UTIL_H_
