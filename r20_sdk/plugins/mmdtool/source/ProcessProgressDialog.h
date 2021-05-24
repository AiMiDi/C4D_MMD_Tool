#ifndef __PROGRESS_DIALOG_H__
#define __PROGRESS_DIALOG_H__

#include "c4d.h"
#include "maxon/thread.h"
#include "ImagesGUI.h"

#define ID_PROGRESS_DIALOG 1057317

class ProgressBarGUI : public GeUserArea
{
	Float _percentage = 0.;
	INSTANCEOF(ProgressBarGUI, GeUserArea)
public:
	ProgressBarGUI() {}
	~ProgressBarGUI() {}
	void SetPercentage(Float percentage) {
		_percentage = percentage;
	}
	void DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg) {
		OffScreenOn();
		DrawSetPen(Vector(0.1f));
		DrawRectangle(x1, y1, x2, y2);
		DrawSetPen(Vector(0.3f));
		DrawRectangle(x1 + 1, y1 + 1, x2 - 2, y2 - 2);
		if (_percentage < 0) {
			DrawSetPen(Vector(133, 163, 204) / 255);
			DrawRectangle(x1 + 1, y1 + 1, x2 * _percentage - 2, y2 - 2);
		}
		else {
			DrawSetPen(Vector(133, 163, 204) / 255);
			DrawRectangle(x1 + 1, y1 + 1, x1 + 1, y2 - 2);
		}
	}
};

class ProcessProgressDialog : public GeDialog
{
	ImagesGUI* Images = nullptr;
	ProgressBarGUI* ProgressBar = nullptr;
	Int _process_end = 0;
	String _text = ""_s;
public:
	ProcessProgressDialog() {}
	~ProcessProgressDialog() {
		if (Images != nullptr) { 
			delete Images; 
		}
		if (ProgressBar != nullptr) {
			delete ProgressBar;
		}
	}
	Bool CreateLayout();
	Bool Command(Int32 id, const BaseContainer& msg);
	Bool CoreMessage(Int32 id, const BaseContainer& msg);

	void SetText(String& text) {
		this->_text = text;
		LayoutFlushGroup(1000);
		C4DGadget* userAreaGadget = this->AddUserArea(10000, BFH_CENTER, SizePix(64), SizePix(64));
		if (userAreaGadget != nullptr)
			this->AttachUserArea((*Images), userAreaGadget);
		AddStaticText(10002, BFH_SCALEFIT, 350, 15, _text, 0);
		LayoutChanged(1000);
	}
};

class ProcessProgressThread : public maxon::ThreadInterfaceTemplate<ProcessProgressThread>
{
public:

	maxon::Result<void> operator ()()
	{

		return maxon::OK;
	}
	const maxon::Char* GetName() const { return "ProcessProgressThread"; }
};

#endif