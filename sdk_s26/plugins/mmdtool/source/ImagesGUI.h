#ifndef __IMAGESGUI_H__
#define __IMAGESGUI_H__
#include "c4d.h"
class ImagesGUI : public GeUserArea
{
	String	bitmap;
	Int32	w, h;
	INSTANCEOF(ImagesGUI, GeUserArea)
public:
	ImagesGUI(String bitmap_, Int32 w_, Int32 h_) : bitmap(bitmap_), w(w_), h(h_){}
	~ImagesGUI(){}
	virtual void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg);
};

#endif __IMAGESGUI_H__