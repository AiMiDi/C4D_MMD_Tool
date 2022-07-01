/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white
/Date:			2022/6/30
File:			images.h
Description:	

**************************************************************************/

#ifndef _C4D_MMD_IMAGES_H_
#define _C4D_MMD_IMAGES_H_

#include <c4d.h>

class GUIImages : public GeUserArea
{
	INSTANCEOF(GUIImages, GeUserArea)

public:
	GUIImages() = default;

	GUIImages(const String &bitmap, const Int32& width, const Int32& height) : 
		m_sBitmap{ bitmap }, m_iWidth{ width }, m_iHeight{ height } {}

	virtual ~GUIImages() = default;

	virtual void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg)
	{
		OffScreenOn(); /* ∑¿÷π∆¡ƒª…¡À∏ */
		DrawBitmap(AutoBitmap(m_sBitmap), x1, y1, x2, y2, 0, 0, m_iWidth, m_iHeight, BMP_NORMALSCALED | BMP_ALLOWALPHA);
	}
private:
	String m_sBitmap;
	Int32 m_iWidth;
	Int32 m_iHeight;
	


};

#endif // !_C4D_MMD_IMAGES_H_
