/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/1
File:			time_util.hpp
Description:	Time Utils with hash

**************************************************************************/

#ifndef _TIME_UTIL_H_
#define _TIME_UTIL_H_

#include "pch.h"

#if API_VERSION < 23000
namespace maxon {
    using HashInt = UInt;
}
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

#endif // !_TIME_UTIL_H_
