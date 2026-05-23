#pragma once

// Preload the STL before old Windows C4D SDK headers force _HAS_EXCEPTIONS=0.
// This keeps later transitive standard-library includes from hitting MSVC's
// _RAISE/_Doraise incompatibilities in R20/R21 builds.
#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <functional>
#include <ios>
#include <iosfwd>
#include <istream>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <system_error>
#include <typeinfo>
#include <utility>
#include <vector>
