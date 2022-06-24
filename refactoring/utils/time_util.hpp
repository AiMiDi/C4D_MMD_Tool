/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white
Date:			2022/6/21
File:			time_util.hpp
Description:	Time Utils with hash

**************************************************************************/

#ifndef _TIME_UTIL_H_
#define _TIME_UTIL_H_

#include <c4d.h>
#include <c4d_basetime.h>

//  HashTime
class HashTime : BaseTime
{
public:
    maxon::HashInt GetHashCode() const
    {
        return MAXON_HASHCODE(this->GetNumerator(), this->GetDenominator());
    }

    HashTime(const BaseTime& time)
    {
        this->SetDenominator(time.GetDenominator());
        this->SetNumerator(time.GetNumerator());
    }
};

#endif // !_TIME_UTIL_H_