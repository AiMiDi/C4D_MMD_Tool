/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/1
File:			images_user_area_util.hpp
Description:	UserArea Utils for images

**************************************************************************/

#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"

class ImagesUserArea final : public GeUserArea
{
	AutoBitmap	m_bitmap;
	Int32 m_width, m_high;
	Bool m_preserve_aspect;
	INSTANCEOF(ImagesUserArea, GeUserArea)
public:
	ImagesUserArea(const String& bitmap, const Int32 w, const Int32 h, const Bool preserve_aspect = false)
		: m_bitmap(bitmap), m_width(w), m_high(h), m_preserve_aspect(preserve_aspect) {}
	~ImagesUserArea() override = default;

	void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg) override
	{
		// 防止屏幕闪烁
		OffScreenOn();
		if (m_preserve_aspect)
		{
			// DrawMsg receives a dirty rectangle, not the full control size.
			// Always fit the complete bitmap to the actual area on resize.
			const Int32 width = GetWidth(), height = GetHeight();
			DrawSetPen(COLOR_BG);
			DrawRectangle(0, 0, width - 1, height - 1);
			const Float scale = Min(Float(width) / m_width, Float(height) / m_high);
			const Int32 draw_width = Max(1, Int32(m_width * scale));
			const Int32 draw_height = Max(1, Int32(m_high * scale));
			DrawBitmap(m_bitmap, (width - draw_width) / 2, (height - draw_height) / 2,
				draw_width, draw_height, 0, 0, m_width, m_high, BMP_NORMALSCALED | BMP_ALLOWALPHA);
			return;
		}
		DrawBitmap(m_bitmap, x1, y1, x2, y2, 0, 0, m_width, m_high, BMP_NORMALSCALED | BMP_ALLOWALPHA);
	}
};
