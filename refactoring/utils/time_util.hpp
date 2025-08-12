/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/1
File:			time_util.hpp
Description:	Time Utils with hash

**************************************************************************/

#pragma once

#if API_VERSION < 23000
namespace maxon {
    using HashInt = UInt;
}
#endif

#if API_VERSION >= 2024900
using namespace cinema;
#endif

//  HashTime
class HashTime : public BaseTime
{
public:
	[[nodiscard]] maxon::HashInt GetHashCode() const
    {
        return MAXON_HASHCODE(this->GetNumerator(), this->GetDenominator());
    }

	HashTime() = default;

	HashTime(const BaseTime& time) : BaseTime(time) {}
};

