#include "ImagesGUI.h"

void ImagesGUI::DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg)
{
	OffScreenOn(); /* 防止屏幕闪烁 */
	DrawBitmap(AutoBitmap(bitmap), x1, y1, x2, y2, 0, 0, w, h, BMP_NORMALSCALED | BMP_ALLOWALPHA);
}