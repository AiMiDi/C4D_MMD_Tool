#include "ProcessProgressDialog.h"


Bool ProcessProgressDialog::CreateLayout() {
	SetTitle(""_s);
	GroupBegin(1000, BFH_CENTER, 1, 2, ""_s, 0);
	Images = new ImagesGUI("MMDIcon.png"_s, 64, 64);
	C4DGadget* userAreaGadget = this->AddUserArea(10000,  BFH_CENTER, SizePix(64), SizePix(64));
	if (userAreaGadget != nullptr)
		this->AttachUserArea((*Images), userAreaGadget);
	AddStaticText(10002, BFH_SCALEFIT, 350, 15, _text, 0);
	GroupEnd();
	ProgressBar = new ProgressBarGUI();
	userAreaGadget = this->AddUserArea(10001, BFH_SCALE, 450, 25);
	if (userAreaGadget != nullptr)
		this->AttachUserArea((*ProgressBar), userAreaGadget);	
	AddButton(10003, BFH_CENTER, 10, 20, ""_s);
	return true;
}
Bool ProcessProgressDialog::CoreMessage(Int32 id, const BaseContainer& msg) {
	if (id == ID_PROGRESS_DIALOG) {
		ProgressBar->SetPercentage((Float)((UInt)msg.GetVoid(BFM_CORE_PAR1)) / (Float)((UInt)msg.GetVoid(BFM_CORE_PAR2)));
		ProgressBar->Redraw();
	}
	return true;
}
Bool ProcessProgressDialog::Command(Int32 id, const BaseContainer& msg) {
	if (id == 10003) {

	}
	return true;
}