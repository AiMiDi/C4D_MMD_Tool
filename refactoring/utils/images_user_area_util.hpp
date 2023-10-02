/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/1
File:			images_user_area_util.hpp
Description:	UserArea Utils for images 

**************************************************************************/

#ifndef _IMAGES_USER_AREA_UTIL_H_
#define _IMAGES_USER_AREA_UTIL_H_

#include "pch.h"

class ImagesUserArea final : public GeUserArea
{
	AutoBitmap	m_bitmap;
	Int32 m_width, m_high;
	INSTANCEOF(ImagesUserArea, GeUserArea)
public:
	ImagesUserArea(const String& bitmap, const Int32 w, const Int32 h) : m_bitmap(bitmap), m_width(w), m_high(h) {}
	~ImagesUserArea() override = default;

	void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg) override
	{
		// 防止屏幕闪烁 
		OffScreenOn(); 
		DrawBitmap(m_bitmap, x1, y1, x2, y2, 0, 0, m_width, m_high, BMP_NORMALSCALED | BMP_ALLOWALPHA);
	}
};

#endif // !_IMAGES_USER_AREA_UTIL_H_
