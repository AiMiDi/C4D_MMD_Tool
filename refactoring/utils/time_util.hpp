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

//  HashTime
class HashTime : BaseTime
{
public:
	[[nodiscard]] maxon::HashInt GetHashCode() const
    {
        return MAXON_HASHCODE(this->GetNumerator(), this->GetDenominator());
    }

	explicit HashTime(const BaseTime& time)
    {
        this->SetDenominator(time.GetDenominator());
        this->SetNumerator(time.GetNumerator());
    }
};

#endif // !_TIME_UTIL_H_