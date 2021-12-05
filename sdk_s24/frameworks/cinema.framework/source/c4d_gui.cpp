#include "c4d_gui.h"
#include "c4d_resource.h"
#include "customgui_base.h"
#include "c4d_customguiplugin.h"
#include "c4d_colors.h"
#include "maxon/job.h"
#include "maxon/jobqueue.h"
#include "maxon/thread.h"

#ifndef __API_INTERN__
	#include "c4d_memory.h"
	#include "c4d_basebitmap.h"
	#include "c4d_general.h"
	#include "c4d_tools.h"
	#include "c4d_basedocument.h"
	#include "lib_description.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

	enum
	{
		CM_DISABLED													= 'disb',
		CM_TYPE_BUTTON											= 'bttn',
			CM_TYPE_STRING											= 'strg',
				CM_STRING													= 'strg',
			CM_TYPE_DATA												= 'vdat',
			CM_TYPE_INT													= 'vint',
			CM_TYPE_FLOAT												= 'vflt',
				CM_VALUE_VAL											= 'valu',	// necessary
				CM_VALUE_MIN											= 'mini',	// unnecessary
				CM_VALUE_MAX											= 'maxi',	// unnecessary
				CM_VALUE_MIN2											= 'min2', // for second range of slider with ints
				CM_VALUE_MAX2											= 'max2', // for second range of slider with ints
				CM_VALUE_STEP											= 'step',	// unnecessary
				CM_VALUE_FORMAT										= 'frmt',	// unnecessary
				CM_VALUE_QUADSCALE								= 'quad',	// quadscale of the slider
				CM_VALUE_TRISTATE									= 'tris',	// 0 == off, 1 == enabled/even values 2 == enabled/different values
				CM_VALUE_FPS											= 'ffps'	// for FORMAT_FRAMES, FORMAT_SECONDS, FORMAT_SMPTE
	};

Bool GeIsTabletMode()
{
	return C4DOS.Ge->IsTabletMode();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#else
	#include "basereq.h"
	#include "basevar.h"
	#include "ge_basebitmap.h"
	#include "basedocument.h"
	#include "world.h"
	#include "ge_event.h"

	#define StopAllThreads StopEditorThreads
	#undef Lock


#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static volatile Bool g_bakeStatus = false;

Float GetMouseMoveDelta()
{
	return GeIsTabletMode() ? MOUSEMOVE_DELTA_TABLET : MOUSEMOVE_DELTA_MOUSE;
}

void SetBakeStatus(Bool state)
{
	g_bakeStatus = state;
}

Bool GetBakeStatus()
{
	return g_bakeStatus;
}

static Int32 CDialogCallBack(CDialog* cd, CUserArea* cu, BaseContainer* msg)
{
	Int32					res = 0;
	BaseContainer result;
	if (cu)
	{
		// UserAreaMessage
		GeUserArea* usr = (GeUserArea*)C4DOS.Cu->GetUserData(cu);
		if (!usr)
			return false;
		res = usr->Message(*msg, result);
	}
	else
	{
		// DialogMessage
		GeDialog* dlg = (GeDialog*)C4DOS.Cd->GetUserData(cd);
		if (!dlg)
			return false;
		res = dlg->Message(*msg, result);
	}

	if (result.GetId() != NOTOK)
		C4DOS.Cd->SetMessageResult(cd, &result);

	return res;
}

Bool GeDialog::GetFolding(void)
{
	return !IsVisible() || _folding;
}

void GeDialog::SetFolding(Bool allowClose)
{
	Bool zeroSize = true;
	C4DOS.Cd->AddGadget(Get(), DIALOG_HIDEOREXPAND, C4DGUIWINDOWID, nullptr, (Int32)FOLDMODE::HIDEMYSELF, zeroSize, allowClose, 0, nullptr, nullptr);
}

Int32 GeDialog::Message(const BaseContainer& msg, BaseContainer& result)
{
	Int32 id;
	Int32 res;

	switch (msg.GetId())
	{
		case BFM_VISIBLE_OFF:
			_folding = true;
			break;

		case BFM_VISIBLE_ON:
			_folding = false;
			break;
	
		case BFM_INTERACTSTART:	// interact stop
			StopAllThreads();
			break;

		case BFM_INIT:
			if (createlayout)
				return true;
			createlayout = true;
			return CreateLayout();

		case BFM_DESTROY:
			DestroyWindow();
			createlayout = false;
			break;

		case BFM_INITVALUES:
			if (!createlayout)
				return true;
			return InitValues();

		case BFM_SYNC_MESSAGE:
			id = msg.GetInt32(BFM_CORE_ID);
			return CoreMessage(id, msg);

		case BFM_CORE_MESSAGE:
			id = msg.GetInt32(BFM_CORE_ID);
			return CoreMessage(id, msg);

		case BFM_ACTION:
			id	= msg.GetInt32(BFM_ACTION_ID);
			res = Command(id, msg);
			return res;

		case BFM_CHECKCLOSE:
			return AskClose();
			break;

		case BFM_TIMER_MESSAGE:
			Timer(msg);
			return true;
	}
	return false;
}

GeDialog::GeDialog(void)
{
	cd						= C4DOS.Cd->Alloc(CDialogCallBack, this);
	t_lastcoremsg	= 0;
	createlayout	= false;
#ifdef __API_INTERN__
	dontfree			= false;
#endif
}

GeDialog::~GeDialog(void)
{
#ifdef __API_INTERN__
	if (!dontfree)
#endif
	if (cd)
		C4DOS.Cd->Free(cd);
	cd = nullptr;
}

#ifdef __API_INTERN__
void GeDialog::Set(CDialog* set)
{
	if (cd && !dontfree)
		C4DOS.Cd->Free(cd);

	cd = set;
	dontfree = true;
}
#endif

void* GeDialog::GetWindowHandle()
{
	return C4DOS.Cd->CBF_GetWindowHandle((CBaseFrame*)cd);
}

Bool GeDialog::SendParentMessage(const BaseContainer& msg, Bool receiveSelf)
{
	return C4DOS.Cd->SendParentMessage(cd, &msg, receiveSelf);
}

Int32 GeDialog::GetId(void)
{
	return C4DOS.Cd->GetID(Get());
}

Bool GeDialog::IsOpen()
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ISOPEN, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::IsVisible()
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ISVISIBLE, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

void* GeDialog::FindCustomGui(Int32 id, Int32 pluginid)
{
	return C4DOS.Cd->FindCustomGui(Get(), id);
}

void* GeDialog::AddCustomGui(Int32 id, Int32 pluginid, const maxon::String& name, Int32 flags, Int32 minw, Int32 minh, const BaseContainer& t_customdata)
{
	BaseContainer customdata = t_customdata;
	customdata.SetInt32(DROLDWIN_SDK, pluginid);
	void* r = nullptr;
	C4DOS.Cd->AddGadget(Get(), DIALOG_SDK, id, &name, flags, minw, minh, 0, &customdata, &r);
	return r;
}

Bool GeDialog::ReleaseLink()
{
	return C4DOS.Cd->ReleaseLink(Get());
}

Bool GeDialog::Open(DLG_TYPE dlgtype, Int32 pluginid, Int32 xpos, Int32 ypos, Int32 defaultw, Int32 defaulth, Int32 subid, OPENDIALOGFLAGS flags)
{
	if (!cd)
		return false;
	C4DOS.Cd->AddGadget(cd, DIALOG_SETIDS, pluginid, nullptr, subid, 0, 0, 0, nullptr, nullptr);
	return C4DOS.Cd->Open(cd, dlgtype, nullptr, xpos, ypos, defaultw, defaulth, flags);
}

Bool GeDialog::Close(void)
{
	if (!cd)
		return false;
	return C4DOS.Cd->Close(cd);
}

Bool GeDialog::Close(Bool dummy)
{
	return Close();
}

GeData GeDialog::SendMessage(const GadgetPtr& id, const BaseContainer& msg)
{
	if (!cd)
		return false;
	return C4DOS.Cd->SendUserAreaMessage(cd, id.Id(), (BaseContainer*)&msg, id.Ptr());
}

void GeDialog::SetTimer(Int32 timer)
{
	C4DOS.Cd->SetTimer(cd, timer);
}

void GeDialog::SetTitle(const maxon::String& title)
{
	if (!cd)
		return;
	C4DOS.Cd->AddGadget(cd, DIALOG_SETTITLE, 0, (String*)&title, 0, 0, 0, 0, nullptr, nullptr);
}

maxon::String GeDialog::GetTitle()
{
	maxon::String title;
	GetString(-1, title);
	return title;
}

Bool GeDialog::Enable(const GadgetPtr& id, Bool enabled)
{
	if (!cd)
		return false;
	return C4DOS.Cd->Enable(cd, id.Id(), enabled, id.Ptr());
}

Bool GeDialog::IsEnabled(const GadgetPtr& id)
{
	if (!cd)
		return false;
	return C4DOS.Cd->IsEnabled(cd, id.Id(), id.Ptr());
}

Bool GeDialog::SetPopup(const GadgetPtr& id, const BaseContainer& bc)
{
	if (!cd)
		return false;
	return C4DOS.Cd->SetPopup(cd, id.Id(), (BaseContainer*)&bc, id.Ptr());
}

Float GeDialog::GetPixelRatio() const
{
	if (!cd)
		return 1.0;
	return C4DOS.Cu->GetPixelRatio((const CBaseFrame*)cd);
}

Bool GeDialog::Local2Global(Int32* x, Int32* y)
{
	if (!cd)
		return false;
	return C4DOS.Cu->Local2Global((CBaseFrame*)cd, x, y);
}

Bool GeDialog::Global2Local(Int32* x, Int32* y)
{
	if (!cd)
		return false;
	return C4DOS.Cu->Global2Local((CBaseFrame*)cd, x, y);
}

Bool GeDialog::Screen2Local(Int32* x, Int32* y)
{
	if (!cd)
		return false;
	return C4DOS.Cu->Screen2Local((CBaseFrame*)cd, x, y);
}

Bool GeDialog::Local2Screen(Int32* x, Int32* y)
{
	if (!cd)
		return false;
	return C4DOS.Cu->Local2Screen((CBaseFrame*)cd, x, y);
}

Bool GeDialog::SetBool(const GadgetPtr& id, Int32 value, Int32 tristate)
{
	return SetInt32(id, value, 0, !tristate ? 1 : 2, 0, tristate);
}

Bool GeDialog::SetInt32(const GadgetPtr& id, Int32 value, Int32 min, Int32 max, Int32 step, Int32 tristate, Int32 min2, Int32 max2)
{
	BaseContainer msg(CM_TYPE_INT);

	msg.SetInt32(CM_VALUE_VAL, value);
	msg.SetInt32(CM_VALUE_FORMAT, FORMAT_INT);
	msg.SetInt32(CM_VALUE_MIN, min);
	msg.SetInt32(CM_VALUE_MAX, max);
	msg.SetInt32(CM_VALUE_STEP, step);
	msg.SetInt32(CM_VALUE_TRISTATE, tristate);
	if (min2 != LIMIT<Int32>::MIN || max2 != LIMIT<Int32>::MAX)
	{
		msg.SetInt32(CM_VALUE_MIN2, min2);
		msg.SetInt32(CM_VALUE_MAX2, max2);
	}

	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetFloat(const GadgetPtr& id, Float value, Float min, Float max, Float step, Int32 format, Float min2, Float max2, Bool quadscale, Int32 tristate)
{
	BaseContainer msg(CM_TYPE_FLOAT);

	msg.SetFloat(CM_VALUE_VAL, value);
	msg.SetInt32(CM_VALUE_FORMAT, format);
	msg.SetFloat(CM_VALUE_MIN, min);
	msg.SetFloat(CM_VALUE_MAX, max);
	msg.SetFloat(CM_VALUE_STEP, step);
	msg.SetInt32(CM_VALUE_TRISTATE, tristate);

	if (min2 != 0.0 || max2 != 0.0)
	{
		msg.SetFloat(CM_VALUE_MIN2, min2);
		msg.SetFloat(CM_VALUE_MAX2, max2);
	}
	msg.SetInt32(CM_VALUE_QUADSCALE, quadscale);

	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetMultiLinePos(const GadgetPtr& id, Int32 line, Int32 pos)
{
	BaseContainer msg(BFM_SPECIALSETRANGE);
	msg.SetData(1, line);
	msg.SetData(2, pos);
	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetMultiLineMode(const GadgetPtr& id, SCRIPTMODE mode)
{
	BaseContainer msg(BFM_SPECIALMODE);
	msg.SetInt32(1, (Int32)mode);
	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetMultiLineLock(const GadgetPtr& id, Bool lock)
{
	BaseContainer msg(lock ? BFM_SETSPECIALMULTI : BFM_SETSPECIALMULTID);
	msg.SetInt32(msg.GetId(), DR_MULTILINE_READONLY);
	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetString(const GadgetPtr& id, const maxon::String& text, Int32 tristate, Int32 flags)
{
	BaseContainer msg(BFM_TITLECHNG);
	msg.SetString(BFM_TITLECHNG, text);
	msg.SetInt32(CM_VALUE_TRISTATE, tristate);
	msg.SetInt32(CM_VALUE_VAL, flags);
	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::SetFilename(const GadgetPtr& id, const Filename& fn, Int32 tristate)
{
	return SetString(id, fn.GetString(), tristate);
}

Bool GeDialog::SetMeter(const GadgetPtr& id, Float value, Float min, Float max, Float step, Int32 tristate)
{
	return SetFloat(id, value, min, max, step, FORMAT_METER, 0.0, 0.0, false, tristate);
}

Bool GeDialog::SetDegree(const GadgetPtr& id, Float radians_value, Float min, Float max, Float step, Int32 tristate)
{
	return SetFloat(id, radians_value, min == MINVALUE_FLOAT ? min : DegToRad(min), max == MAXVALUE_FLOAT ? max : DegToRad(max), DegToRad(step), FORMAT_DEGREE, 0.0, 0.0, false, tristate);
}

Bool GeDialog::SetPercent(const GadgetPtr& id, Float value, Float min, Float max, Float step, Int32 tristate)
{
	return SetFloat(id, value, min / 100.0_f, max / 100.0_f, step / 100.0_f, FORMAT_PERCENT, 0.0, 0.0, false, tristate);
}

Bool GeDialog::SetColorField(const GadgetPtr& id, const Vector& color, Float brightness, Float maxbrightness, Int32 flags)
{
	if (!cd)
		return false;
	return C4DOS.Cd->SetColorField(cd, id.Id(), color, brightness, maxbrightness, flags, id.Ptr());
}


Bool GeDialog::GetBool(const GadgetPtr& id, Bool& value) const
{
	if (!cd)
		return false;
	Int32 val;
	Bool	ok = C4DOS.Cd->GetInt32(cd, id.Id(), val, id.Ptr());
	value = val != 0;
	return ok;
}

Bool GeDialog::GetInt32(const GadgetPtr& id, Int32& value) const
{
	if (!cd)
		return false;
	return C4DOS.Cd->GetInt32(cd, id.Id(), value, id.Ptr());
}

Bool GeDialog::GetFloat(const GadgetPtr& id, Float& value) const
{
	if (!cd)
		return false;
	return C4DOS.Cd->GetFloat(cd, id.Id(), value, id.Ptr());
}

Bool GeDialog::GetVector(const GadgetPtr& id_x, const GadgetPtr& id_y, const GadgetPtr& id_z, Vector& value) const
{
	if (!GetFloat(id_x, value.x))
		return false;
	if (!GetFloat(id_y, value.y))
		return false;
	if (!GetFloat(id_z, value.z))
		return false;
	return true;
}

Bool GeDialog::GetString(const GadgetPtr& id, maxon::String& text) const
{
	if (!cd)
		return false;
	Bool		res = C4DOS.Cd->GetString(cd, id.Id(), text, id.Ptr());
	return res;
}

Bool GeDialog::GetFilename(const GadgetPtr& id, Filename& fn) const
{
	String str;
	Bool	 res = GetString(id, str);
	if (!res)
		return false;
	fn.SetString(str);
	return res;
}

Bool GeDialog::GetColorField(const GadgetPtr& id, Vector& color, Float& brightness) const
{
	if (!cd)
		return false;
	return C4DOS.Cd->GetColorField(cd, id.Id(), color, brightness, id.Ptr());
}

Bool GeDialog::GetBool(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const
{
	Bool b	= false;
	Bool ok = GetBool(id, b);
	bc->SetBool(bcid, b);
	return ok;
}

Bool GeDialog::GetInt32(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const
{
	Int32 b;
	Bool	ok = GetInt32(id, b);
	bc->SetInt32(bcid, b);
	return ok;
}

Bool GeDialog::GetFloat(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const
{
	Float b;
	Bool	ok = GetFloat(id, b);
	bc->SetFloat(bcid, b);
	return ok;
}

Bool GeDialog::GetVector(const GadgetPtr& id_x, const GadgetPtr& id_y, const GadgetPtr& id_z, BaseContainer* bc, Int32 bcid) const
{
	Vector v;
	if (!GetFloat(id_x, v.x))
		return false;
	if (!GetFloat(id_y, v.y))
		return false;
	if (!GetFloat(id_z, v.z))
		return false;
	bc->SetVector(bcid, v);
	return true;
}

Bool GeDialog::GetString(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const
{
	String b;
	Bool	 ok = GetString(id, b);
	bc->SetString(bcid, b);
	return ok;
}

Bool GeDialog::GetFilename(const GadgetPtr& id, BaseContainer* bc, Int32 bcid) const
{
	Filename b;
	Bool		 ok = GetFilename(id, b);
	bc->SetFilename(bcid, b);
	return ok;
}

Bool GeDialog::GetColorField(const GadgetPtr& id, BaseContainer* bc, Int32 bc_colid, Int32 bc_brightnessid) const
{
	Vector c;
	Float	 b;
	Bool	 ok = GetColorField(id, c, b);
	if (bc_colid != NOTOK)
		bc->SetVector(bc_colid, c);
	if (bc_brightnessid != NOTOK)
		bc->SetFloat(bc_brightnessid, b);
	return ok;
}

Bool GeDialog::SetBool(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid)
{
	return SetBool(id, bc->GetBool(bcid));
}

Bool GeDialog::SetInt32(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Int32 min, Int32 max, Int32 step, Int32 min2, Int32 max2)
{
	return SetInt32(id, bc->GetInt32(bcid), min, max, step, 0, min2, max2);
}

Bool GeDialog::SetFloat(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min, Float max, Float step, Int32 format, Float min2, Float max2, Bool quadscale)
{
	return SetFloat(id, bc->GetFloat(bcid), min, max, step, format, min2, max2, quadscale);
}

Bool GeDialog::SetMeter(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min, Float max, Float step)
{
	return SetMeter(id, bc->GetFloat(bcid), min, max, step);
}

Bool GeDialog::SetDegree(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min, Float max, Float step)
{
	return SetDegree(id, bc->GetFloat(bcid), min, max, step);
}

Bool GeDialog::SetPercent(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Float min, Float max, Float step)
{
	return SetPercent(id, bc->GetFloat(bcid), min, max, step);
}

Bool GeDialog::SetString(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid, Int32 flags)
{
	return SetString(id, bc->GetString(bcid), 0, flags);
}

Bool GeDialog::SetFilename(const GadgetPtr& id, const BaseContainer* bc, Int32 bcid)
{
	return SetFilename(id, bc->GetFilename(bcid));
}

Bool GeDialog::SetColorField(const GadgetPtr& id, const BaseContainer* bc, Int32 bc_colid, Int32 bc_brightnessid, Float maxbrightness, Int32 flags)
{
	Float bright = 1.0;
	if (bc_brightnessid != -1)
		bright = bc->GetFloat(bc_brightnessid);
	return SetColorField(id, bc->GetVector(bc_colid), bright, maxbrightness, flags);
}

Bool GeDialog::SetTime(const GadgetPtr& id, const BaseDocument* doc, const BaseTime& value, const BaseTime& min, const BaseTime& max, Int32 stepframes, Int32 tristate)
{
	if (!doc)
		doc = C4DOS.Ge->GetActiveDocument();
	if (!doc)
		return false;
#ifndef __API_INTERN__
	Int32 fps = doc->GetFps();
#else
	Int32 fps = doc->docpref.GetFps();
#endif

	BaseContainer msg(CM_TYPE_FLOAT);

	msg.SetFloat(CM_VALUE_VAL, Floor(value.GetNumerator() * fps) / Floor(value.GetDenominator()));
	msg.SetInt32(CM_VALUE_FORMAT, FORMAT_FRAMES);
	msg.SetFloat(CM_VALUE_MIN, Floor(min.GetNumerator() * fps) / Floor(min.GetDenominator()));
	msg.SetFloat(CM_VALUE_MAX, Floor(max.GetNumerator() * fps) / Floor(max.GetDenominator()));
	msg.SetFloat(CM_VALUE_STEP, 1.0);
	msg.SetInt32(CM_VALUE_QUADSCALE, false);
	msg.SetInt32(CM_VALUE_FPS, fps);
	msg.SetInt32(CM_VALUE_TRISTATE, tristate);
	/*
		if (min2.Get() != 0.0 || max2 != 0.0)
		{
			msg.SetFloat(CM_VALUE_MIN2, min2);
			msg.SetFloat(CM_VALUE_MAX2, max2);
		}
	*/
	return SendMessage(id, msg).GetInt32() != 0;
}

Bool GeDialog::GetTime(const GadgetPtr& id, const BaseDocument* doc, BaseTime& time) const
{
	if (!doc)
		doc = C4DOS.Ge->GetActiveDocument();
	if (!doc)
		return false;
#ifndef __API_INTERN__
	Int32 fps = doc->GetFps();
#else
	Int32 fps = doc->docpref.GetFps();
#endif

	Float b;
	Bool	ok = GetFloat(id, b);
	time = BaseTime(b * 1000.0_f, fps * 1000.0_f);
	return ok;
}

Bool GeDialog::SetTime(const GadgetPtr& id, const BaseDocument* doc, const BaseContainer* bc, Int32 bcid, const BaseTime& min, const BaseTime& max, Int32 stepframes)
{
	return SetTime(id, doc, bc->GetTime(bcid), min, max, stepframes);
}

Bool GeDialog::GetTime(const GadgetPtr& id, const BaseDocument* doc, BaseContainer* bc, Int32 bcid) const
{
	BaseTime time;
	Bool		 ok = GetTime(id, doc, time);
	bc->SetTime(bcid, time);
	return ok;
}

Bool GeDialog::CheckTristateChange(const GadgetPtr& id)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_GETTRISTATE, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

C4DGadget* GeDialog::AddCheckbox(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_CHECKBOX, id, (String*)&name, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::MenuSetResource(Int32 id)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_MENURESOURCE, id, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

C4DGadget* GeDialog::AddSeparatorH(Int32 initw, Int32 flags)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_SEPARATOR, 0, nullptr, flags, initw, 0, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddSeparatorV(Int32 initw, Int32 flags)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_SEPARATOR, 0, nullptr, flags, 0, initw, 0, nullptr, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::AddSubDialog(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_SUBDIALOG, id, nullptr, flags, initw, inith, 0, nullptr, nullptr);
}

C4DGadget* GeDialog::AddRadioButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_RADIOBUTTON, id, (String*)&name, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddRadioText(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_RADIOTEXT, id, (String*)&name, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_BUTTON, id, (String*)&name, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddStaticText(Int32 id, Int32 flags, Int32 initw, Int32 inith, const maxon::String& name, Int32 borderstyle)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_STATICTEXT, id, (String*)&name, flags, initw, inith, borderstyle, nullptr, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::AddListView(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_LISTVIEW, id, nullptr, flags, initw, inith, 0, nullptr, nullptr);
}

C4DGadget* GeDialog::AddArrowButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 arrowtype)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_ARROWBUTTON, id, nullptr, flags, initw, inith, arrowtype, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddEditShortcut(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 shortcutflags)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_EDITSHORTCUT, id, nullptr, flags, initw, inith, shortcutflags, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddEditText(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 editflags)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_EDITTEXT, id, nullptr, flags, initw, inith, editflags, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddMultiLineEditText(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 style)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_MULTILINEEDITTEXT, id, nullptr, flags, initw, inith, style, nullptr, &r);
	return (C4DGadget*)r;
}


C4DGadget* GeDialog::AddEditNumber(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_EDITNUMBER, id, nullptr, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddEditNumberArrows(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_EDITNUMBERUD, id, nullptr, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddEditSlider(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_EDITSLIDER, id, nullptr, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddSlider(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_SLIDER, id, nullptr, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddColorField(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 colorflags)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_COLORFIELD, id, nullptr, flags, initw, inith, colorflags, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddColorChooser(Int32 id, Int32 flags, Int32 initw, Int32 inith, Int32 layoutflags, const BaseContainer& settings)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_COLORCHOOSER, id, nullptr, flags, initw, inith, layoutflags, &settings, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::AddRadioGroup(Int32 id, Int32 flags, Int32 columns, Int32 rows)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_RADIOGROUP, id, nullptr, flags, columns, rows, 0, nullptr, nullptr);
}

C4DGadget* GeDialog::AddComboBox(Int32 id, Int32 flags, Int32 initw, Int32 inith, Bool specialalign, Bool allowFiltering)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	Int32 xflags = 0;
	if (specialalign)
		xflags |= 1;
	if (allowFiltering)
		xflags |= 2;
	C4DOS.Cd->AddGadget(cd, DIALOG_COMBOBOX, id, nullptr, flags, initw, inith, xflags, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddComboButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, Bool specialalign, Bool allowFiltering)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	Int32 xflags = 0;
	if (specialalign)
		xflags |= 1;
	if (allowFiltering)
		xflags |= 2;	
	C4DOS.Cd->AddGadget(cd, DIALOG_COMBOBUTTON, id, nullptr, flags, initw, inith, xflags, nullptr, &r);
	return (C4DGadget*)r;
}

C4DGadget* GeDialog::AddPopupButton(Int32 id, Int32 flags, Int32 initw, Int32 inith, Bool allowFiltering)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	Int32 xflags = 0;
	if (allowFiltering)
		xflags |= 1;
	C4DOS.Cd->AddGadget(cd, DIALOG_POPUPBUTTON, id, nullptr, flags, initw, inith, xflags, nullptr, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::AddChild(const GadgetPtr& id, Int32 subid, const maxon::String& child)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_CHILD, id.Id(), (String*)&child, subid, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::AddChildren(const GadgetPtr& id, const BaseContainer& bc)
{
	BrowseContainer br(&bc);
	Int32		sid;
	GeData* dat;
	while (br.GetNext(&sid, &dat))
	{
		if (!dat)
			continue;
		if (!AddChild(id, sid, dat->GetString()))
			return false;
	}
	return true;
}

Bool GeDialog::FreeChildren(const GadgetPtr& id)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_FREECHILDREN, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

C4DGadget* GeDialog::AddUserArea(Int32 id, Int32 flags, Int32 initw, Int32 inith)
{
	if (!cd)
		return nullptr;
	void* r = nullptr;
	C4DOS.Cd->AddGadget(cd, DIALOG_USERAREA, id, nullptr, flags, initw, inith, 0, nullptr, &r);
	return (C4DGadget*)r;
}

Bool GeDialog::TabGroupBegin(Int32 id, Int32 flags, Int32 tabtype)
{
	if (!cd)
		return false;
	return C4DOS.Cd->TabGroupBegin(cd, id, flags, tabtype);
}

Bool GeDialog::GroupBegin(Int32 id, Int32 flags, Int32 cols, Int32 rows, const maxon::String& title, Int32 groupflags, Int32 initw, Int32 inith)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupBegin(cd, id, flags, cols, rows, (String*)&title, groupflags, initw, inith);
}

Bool GeDialog::GroupEnd(void)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupEnd(cd);
}

Bool GeDialog::GroupSpace(Int32 spacex, Int32 spacey)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupSpace(cd, spacex, spacey);
}

Bool GeDialog::GroupBorder(UInt32 borderstyle)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupBorder(cd, borderstyle | BORDER_WITH_TITLE);
}

Bool GeDialog::GroupBorderNoTitle(UInt32 borderstyle)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupBorder(cd, borderstyle);
}

Bool GeDialog::GroupBorderSpace(Int32 left, Int32 top, Int32 right, Int32 bottom)
{
	if (!cd)
		return false;
	return C4DOS.Cd->GroupBorderSize(cd, left, top, right, bottom);
}

Bool GeDialog::AttachUserArea(GeUserArea& ua, const GadgetPtr& id, USERAREAFLAGS userareaflags)
{
	C4DOS.Cu->Free(ua.cu);
	ua.cu	 = nullptr;
	ua.dlg = this;
	ua.cu	 = C4DOS.Cd->AttachUserArea(cd, id.Id(), &ua, userareaflags, id.Ptr());
	return ua.cu != nullptr;
}

Bool GeDialog::AddDlgGroup(Int32 type)
{
	if (!cd)
		return false;
	return C4DOS.Cd->AddGadget(cd, DIALOG_DLGGROUP, 0, nullptr, type, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::AttachSubDialog(SubDialog* userdlg, Int32 id)
{
	if (!userdlg)
		return false;

	userdlg->createlayout = false;

	return C4DOS.Cd->AttachSubDialog(Get(), id, userdlg->Get());
}

Bool GeDialog::CheckClose(void)
{
	return C4DOS.Cd->AddGadget(Get(), DIALOG_CHECKCLOSE, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::LoadDialogResource(Int32 id, GeResource* lr, Int32 flags)
{
#ifndef __API_INTERN__
	if (!lr)
		lr = &g_resource;
	return C4DOS.Cd->LoadDialogResource(cd, id, lr->Get(), flags);
#else
	return C4DOS.Cd->LoadDialogResource(cd, id, nullptr, flags);
#endif
}

Bool GeDialog::SetVisibleArea(Int32 scrollgroupid, Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	return C4DOS.Cd->SetVisibleArea(cd, scrollgroupid, x1, y1, x2, y2);
}

Bool GeDialog::GetVisibleArea(Int32 scrollgroupid, Int32* x1, Int32* y1, Int32* x2, Int32* y2)
{
	return C4DOS.Cd->GetVisibleArea(cd, scrollgroupid, x1, y1, x2, y2);
}

Bool GeDialog::GetItemDim(const GadgetPtr& id, Int32* x, Int32* y, Int32* w, Int32* h) const
{
	return C4DOS.Cd->GetItemDim(cd, id.Id(), x, y, w, h, id.Ptr());
}

Bool GeDialog::LayoutChanged(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_LAYOUTCHANGED, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::LayoutChangedNoRedraw(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_LAYOUTCHANGED, id.Id(), nullptr, true, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::Activate(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ACTIVATE, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::IsActive(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ISACTIVE, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

UpdateDialogHelper GeDialog::BeginLayoutChange(const GadgetPtr& gadget, Bool disableRedraws, Bool doNotFlush)
{
	return UpdateDialogHelper::BeginLayoutChange(this, gadget, disableRedraws, doNotFlush);
}

Bool GeDialog::GroupWeightsSave(const GadgetPtr& id, BaseContainer& weights)
{
	BaseContainer storehere;
	Bool ret = C4DOS.Cd->AddGadget(cd, DIALOG_SAVEWEIGHTS, id.Id(), nullptr, 0, 0, 0, 0, &storehere, (void**)id.Ptr());
	if (ret)
		weights = storehere;
	return ret;
}

Bool GeDialog::GroupWeightsLoad(const GadgetPtr& id, const BaseContainer& weights)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_LOADWEIGHTS, id.Id(), nullptr, 0, 0, 0, 0, &weights, (void**)id.Ptr());
}

Bool GeDialog::LayoutFlushGroup(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_FLUSHGROUP, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::LayoutFlushDisableRedraw(const GadgetPtr& id, Bool disable)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_DISABLEREDRAW, id.Id(), nullptr, disable, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::RemoveElement(const GadgetPtr& id)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_REMOVEGADGET, id.Id(), nullptr, 0, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::HideElement(const GadgetPtr& id, Bool hide)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_HIDEELEMENT, id.Id(), nullptr, hide, 0, 0, 0, nullptr, (void**)id.Ptr());
}

Bool GeDialog::ScrollGroupBegin(Int32 id, Int32 flags, Int32 scrollflags, Int32 initw, Int32 inith)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_SCROLLGROUP, id, nullptr, flags, initw, inith, scrollflags, nullptr, nullptr);
}

Bool GeDialog::RestoreLayout(Int32 pluginid, Int32 subid, void* secret)
{
	C4DOS.Cd->AddGadget(cd, DIALOG_SETIDS, pluginid, nullptr, subid, 0, 0, 0, nullptr, nullptr);
	return C4DOS.Cd->RestoreLayout(cd, secret);
}

Bool GeDialog::MenuSubBegin(const maxon::String& string)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ADDSUBMENU, 0, (String*)&string, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuSubEnd(void)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ENDSUBMENU, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuAddCommand(Int32 cmdid)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ADDMENUCMD, cmdid, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuAddSeparator(void)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ADDMENUSEP, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuAddString(Int32 id, const maxon::String& string)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_ADDMENUSTR, id, (String*)&string, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuInitString(Int32 id, Bool enabled, Bool checked)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_INITMENUSTR, id, nullptr, enabled, checked, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuFlushAll(void)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_FLUSHMENU, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::MenuFinished(void)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_SETMENU, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

Bool GeDialog::GetDragPosition(const BaseContainer& msg, Int32* x, Int32* y)
{
	if (x)
		*x = msg.GetInt32(BFM_DRAG_SCREENX);
	if (y)
		*y = msg.GetInt32(BFM_DRAG_SCREENY);
	return C4DOS.Cd->Screen2Local(cd, x, y);
}

Bool GeDialog::GetDragObject(const BaseContainer& msg, Int32* type, void** object)
{
	return C4DOS.Cd->GetDragObject(cd, (BaseContainer*)&msg, type, object);
}


Bool GeDialog::CheckValueRanges(void)
{
	return C4DOS.Cd->AddGadget(cd, DIALOG_CHECKNUMBERS, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}


// to override
Bool GeDialog::CreateLayout(void)
{
	return true;
}

Bool GeDialog::InitValues(void)
{
	return true;
}

void GeDialog::DestroyWindow(void)
{
}

Bool GeDialog::CoreMessage(Int32 id, const BaseContainer& msg)
{
	return true;
}

Bool GeDialog::Command(Int32 id, const BaseContainer& msg)
{
	// esc when focus in userareas did not worked!
	return false;
}

Bool GeDialog::AskClose(void)
{
	return false;
}

void GeDialog::Timer(const BaseContainer& msg)
{
}

#ifdef __API_INTERN__
Bool GeDialog::OpenPopUpMenu(Int32 menuid, Int32 localx, Int32 localy, Int32 watchhotkey)
{
	if (localx != -1 && localy != -1)
	{
		C4DOS.Cu->Local2Screen(cd, &localx, &localy);
	}
	return CDialog_OpenPopUp(cd, menuid, localx, localy, watchhotkey);
}

Bool GeUserArea::OpenPopUpMenu(Int32 menuid, Int32 localx, Int32 localy, Int32 watchhotkey)
{
	if (!dlg)
		return false;
	if (localx != -1 && localy != -1)
	{
		C4DOS.Cu->Local2Screen(cu, &localx, &localy);
	}
	return CDialog_OpenPopUp(dlg->cd, menuid, localx, localy, watchhotkey);
}
#endif

GeModalDialog::GeModalDialog(void)
{
	close = true;
	dlg_result = false;
}

GeModalDialog::~GeModalDialog(void)
{
}

Bool GeModalDialog::Open(Int32 xpos, Int32 ypos, Int32 defaultw, Int32 defaulth, Bool resizable)
{
	dlg_result = false;
	return GeDialog::Open(resizable ? DLG_TYPE::MODAL_RESIZEABLE : DLG_TYPE::MODAL, 0, xpos, ypos, defaultw, defaulth) && dlg_result;
}

Bool GeModalDialog::Close(Bool result)
{
	dlg_result = result;
	return GeDialog::Close();
}

Int32 GeModalDialog::Message(const BaseContainer& msg, BaseContainer& result)
{
	Int32 id, res;

	switch (msg.GetId())
	{
		case BFM_INTERACTSTART:	// interact stop
			return false;

		case BFM_CHECKCLOSE:
			if (dlg_result && CheckValueRanges())
			{
				dlg_result = false;
				return true;
			}
			return false;

		case BFM_ASKCLOSE:
			if (dlg_result)
			{
				return AskClose();
			}
			return false;

		case BFM_ACTION:
			id = msg.GetInt32(BFM_ACTION_ID);
			close = true;
			res = Command(id, msg);

			if ((close && id == IDC_OK) || id == IDC_CANCEL)
			{
				Close(id == IDC_OK);
			}
			return res;
	}
	return GeDialog::Message(msg, result);
}

void GeModalDialog::CheckLong(Int32 id, CHECKVALUERANGE type, Int32 val, Int32 x, Int32 y)
{
	if (!close)
		return;
	switch (type)
	{
		case CHECKVALUERANGE::GREATER:
			if (val > x)
				return;
			break;
		case CHECKVALUERANGE::GREATEROREQUAL:
			if (val >= x)
				return;
			break;
		case CHECKVALUERANGE::LESS:
			if (val < x)
				return;
			break;
		case CHECKVALUERANGE::LESSOREQUAL:
			if (val <= x)
				return;
			break;
		case CHECKVALUERANGE::BETWEEN:
			if (val > x && val < y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUAL:
			if (val >= x && val <= y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUALX:
			if (val >= x && val < y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUALY:
			if (val > x && val <= y)
				return;
			break;
		case CHECKVALUERANGE::DIFFERENT:
			if (val != x)
				return;
			break;
	}

	Activate(id);
	ErrorStringDialog(type, (Float)x, (Float)y, CHECKVALUEFORMAT::INT);
	close = false;
}

void GeModalDialog::CheckReal(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y, CHECKVALUEFORMAT format)
{
	if (!close)
		return;
	switch (type)
	{
		case CHECKVALUERANGE::GREATER:
			if (val > x)
				return;
			break;
		case CHECKVALUERANGE::GREATEROREQUAL:
			if (val >= x)
				return;
			break;
		case CHECKVALUERANGE::LESS:
			if (val < x)
				return;
			break;
		case CHECKVALUERANGE::LESSOREQUAL:
			if (val <= x)
				return;
			break;
		case CHECKVALUERANGE::BETWEEN:
			if (val > x && val < y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUAL:
			if (val >= x && val <= y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUALX:
			if (val >= x && val < y)
				return;
			break;
		case CHECKVALUERANGE::BETWEENOREQUALY:
			if (val > x && val <= y)
				return;
			break;
		case CHECKVALUERANGE::DIFFERENT:
			if (val != x)
				return;
			break;
	}

	Activate(id);
	ErrorStringDialog(type, x, y, format);
	close = false;
}

void GeModalDialog::CheckMeter(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y)
{
	CheckReal(id, type, val, x, y, CHECKVALUEFORMAT::METER);
}

void GeModalDialog::CheckPercent(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y)
{
	CheckReal(id, type, val, x, y, CHECKVALUEFORMAT::PERCENT);
}

void GeModalDialog::CheckDegree(Int32 id, CHECKVALUERANGE type, Float val, Float x, Float y)
{
	CheckReal(id, type, val, x, y, CHECKVALUEFORMAT::DEGREE);
}

GeUserArea::GeUserArea(void)
{
	dlg = nullptr;
	cu	= nullptr;
	owncu = false;
}

GeUserArea::~GeUserArea(void)
{
	if (!owncu)
		C4DOS.Cu->Free(cu);

	dlg = nullptr;
	cu	= nullptr;
}

Bool GeUserArea::SetDragDestination(Int32 cursor)
{
	return C4DOS.Cu->SetDragDestination(cu, cursor);
}

Bool GeDialog::SetDragDestination(Int32 cursor, Int32 gadgetid)
{
	if (gadgetid)
	{
		CBaseFrame* cbf = C4DOS.Cd->CBF_FindBaseFrame(Get(), gadgetid);
		return C4DOS.Cd->CBF_SetDragDestination(cbf, cursor);
	}
	return C4DOS.Cd->SetDragDestination(cd, cursor);
}



Int32 GeUserArea::GetWidth() const
{
	return C4DOS.Cu->GetWidth(cu);
}

Int32 GeUserArea::GetHeight() const
{
	return C4DOS.Cu->GetHeight(cu);
}

Int32 GeUserArea::GetId() const
{
	return C4DOS.Cu->GetID(cu);
}

Bool GeUserArea::IsEnabled() const
{
	return C4DOS.Cu->IsEnabled(cu);
}

Bool GeUserArea::HasFocus() const
{
	return C4DOS.Cu->HasFocus(cu);
}

void GeUserArea::DrawBezierLine(const Vector2d& startPoint, const maxon::Block<const BezierPoint>& bezierPoints, Bool closed, Float lineWidth, LINESTYLE lineStyle)
{
	C4DOS.Cu->DrawBezierLine(cu, startPoint, bezierPoints, closed, lineWidth, lineStyle);
}

void GeUserArea::DrawBezierFill(const Vector2d& startPoint, const maxon::Block<const BezierPoint>& bezierPoints, Bool closed)
{
	C4DOS.Cu->DrawBezierFill(cu, startPoint, bezierPoints, closed);
}

void GeUserArea::DrawPolyLine(const maxon::Block<const Vector2d>& p, Bool closed, Float lineWidth, LINESTYLE lineStyle)
{
	C4DOS.Cu->DrawPolyLine(cu, p, closed, lineWidth, lineStyle);
}

void GeUserArea::DrawPolyFill(const maxon::Block<const Vector2d>& p, Bool closed)
{
	C4DOS.Cu->DrawPolyFill(cu, p, closed);
}

void GeUserArea::DrawEllipseLine(const Vector2d& centerPoint, const Vector2d& radius, Float lineWidth, LINESTYLE lineStyle)
{
	C4DOS.Cu->DrawEllipseLine(cu, centerPoint, radius, lineWidth, lineStyle);
}

void GeUserArea::DrawEllipseFill(const Vector2d& centerPoint, const Vector2d& radius)
{
	C4DOS.Cu->DrawEllipseFill(cu, centerPoint, radius);
}

void GeUserArea::DrawLine(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Float lineWidth, LINESTYLE lineStyle)
{
	C4DOS.Cu->DrawLine(cu, x1, y1, x2, y2, lineWidth, lineStyle);
}

void GeUserArea::DrawRectangle(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	C4DOS.Cu->DrawRectangle(cu, x1, y1, x2, y2);
}

void GeUserArea::DrawFrame(Int32 x1, Int32 y1, Int32 x2, Int32 y2, Float lineWidth, LINESTYLE lineStyle)
{
	C4DOS.Cu->DrawFrame(cu, x1, y1, x2, y2, lineWidth, lineStyle);
}

void GeUserArea::DrawSetPen(const GeData& d)
{
	if (d.GetType() == DA_VECTOR)
		DrawSetPen(d.GetVector());
	else if (d.GetType() == DA_LONG)
		DrawSetPen(d.GetInt32());
	else
		CriticalStop();
}

void GeUserArea::DrawSetPen(const Vector& color)
{
	C4DOS.Cu->DrawSetPenV(cu, color);
}

void GeUserArea::DrawSetPen(Int32 id)
{
	C4DOS.Cu->DrawSetPenI(cu, id);
}

void GeUserArea::DrawSetOpacity(Float opacity)
{
	C4DOS.Cu->DrawSetOpacity(cu, opacity);
}

Bool GeUserArea::GetColorRGB(Int32 colorid, Int32& r, Int32& g, Int32& b) const
{
	return C4DOS.Cd->CBF_GetColorRGB((CBaseFrame*)cu, colorid, r, g, b);
}

void GeUserArea::ActivateFading(Int32 milliseconds)
{
	C4DOS.Cd->CBF_ActivateFading((CBaseFrame*)cu, milliseconds);
}

void GeUserArea::AdjustColor(Int32 colorid, Int32 highlightid, Float percent)
{
	C4DOS.Cd->CBF_AdjustColor((CBaseFrame*)cu, colorid, highlightid, percent);
}

HOTKEYFLAGS GeUserArea::IsHotkeyDown(Int32 id) const
{
	return C4DOS.Cu->IsHotkeyDown(cu, id);
}

void GeUserArea::GetBorderSize(Int32 type, Int32* l, Int32* t, Int32* r, Int32* b) const
{
	C4DOS.Cu->GetBorderSize(cu, type, l, t, r, b);
}

void GeUserArea::DrawBorder(Int32 type, Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	C4DOS.Cu->DrawBorder(cu, type, x1, y1, x2, y2);
}

void GeUserArea::SetTimer(Int32 timer)
{
	C4DOS.Cu->SetTimer(cu, timer);
}

Bool GeUserArea::GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res) const
{
	return C4DOS.Cu->GetInputState((CBaseFrame*)cu, askdevice, askchannel, &res);
}

Bool GeUserArea::GetInputEvent(Int32 askdevice, BaseContainer& res) const
{
	return C4DOS.Cu->GetInputEvent((CBaseFrame*)cu, askdevice, &res);
}

void GeUserArea::KillEvents(void)
{
	C4DOS.Cu->KillEvents((CBaseFrame*)cu);
}

Bool GeUserArea::CheckDropArea(const BaseContainer& msg, Bool horiz, Bool vert) const
{
	Int32 x = 0, y = 0, w, h, dx, dy;

	dlg->GetDragPosition(msg, &dx, &dy);
	dlg->GetItemDim(GetId(), &x, &y, &w, &h);

	if (horiz && vert)
		return dx > x && dx < x + w && dy > y && dy < y + h;
	else if (vert)
		return dy > y && dy < y + h;
	return dx > x && dx < x + w;
}

void GeUserArea::DrawSetFont(Int32 fontid)
{
	C4DOS.Cu->DrawSetFont(cu, fontid);
}

Int32 GeUserArea::DrawGetTextWidth(const maxon::String& text) const
{
	return C4DOS.Cu->DrawGetTextWidth(cu, (String*)&text);
}

Int32 GeUserArea::DrawGetTextWidth_ListNodeName(BaseList2D* node, Int32 fontid) const
{
	return C4DOS.Cu->DrawGetTextWidth_ListNodeName(cu, node, fontid);
}

void GeUserArea::DrawSetTextRotation(Float textrotation)
{
	C4DOS.Cu->DrawSetTextRotation(cu, textrotation);
}

Int32 GeUserArea::DrawGetFontHeight() const
{
	return C4DOS.Cu->DrawGetFontHeight(cu);
}

Int32 GeUserArea::DrawGetFontBaseLine() const
{
	return C4DOS.Cu->DrawGetFontBaseLine(cu);
}

void GeUserArea::DrawSetTextCol(Int32 fg, Int32 bg)
{
	C4DOS.Cu->DrawSetTextColII(cu, fg, bg);
}

void GeUserArea::DrawSetTextCol(const Vector& fg, Int32 bg)
{
	C4DOS.Cu->DrawSetTextColVI(cu, fg, bg);
}

void GeUserArea::DrawSetTextCol(Int32 fg, const Vector& bg)
{
	C4DOS.Cu->DrawSetTextColIV(cu, fg, bg);
}

void GeUserArea::DrawSetTextCol(const Vector& fg, const Vector& bg)
{
	C4DOS.Cu->DrawSetTextColVV(cu, fg, bg);
}

void GeUserArea::DrawSetTextCol(const GeData& fg, const GeData& bg)
{
	if (fg.GetType() == DA_VECTOR)
	{
		if (bg.GetType() == DA_VECTOR)
			C4DOS.Cu->DrawSetTextColVV(cu, fg.GetVector(), bg.GetVector());
		else if (bg.GetType() == DA_LONG)
			C4DOS.Cu->DrawSetTextColVI(cu, fg.GetVector(), bg.GetInt32());
		else
			CriticalStop();
	}
	else if (fg.GetType() == DA_LONG)
	{
		if (bg.GetType() == DA_VECTOR)
			C4DOS.Cu->DrawSetTextColIV(cu, fg.GetInt32(), bg.GetVector());
		else if (bg.GetType() == DA_LONG)
			C4DOS.Cu->DrawSetTextColII(cu, fg.GetInt32(), bg.GetInt32());
		else
			CriticalStop();
	}
	else
	{
		CriticalStop();
	}
}

void GeUserArea::DrawText(const maxon::String& txt, Int32 x, Int32 y, Int32 flags)
{
	C4DOS.Cu->DrawText(cu, txt, x, y, flags);
}

void GeUserArea::DrawBitmap(BaseBitmap* bmp, Int32 wx, Int32 wy, Int32 ww, Int32 wh, Int32 x, Int32 y, Int32 w, Int32 h, Int32 mode)
{
	C4DOS.Cu->DrawBitmap(cu, bmp, wx, wy, ww, wh, x, y, w, h, mode);
}

void GeUserArea::DrawImageRef(maxon::ImageBaseRef& imageRef, Float wx, Float wy, Float ww, Float wh, Float opacity, maxon::IMAGEINTERPOLATIONMODE mode)
{
	C4DOS.Cu->DrawImageRef(cu, imageRef, wx, wy, ww, wh, opacity, mode);
}

//	Int32 iDEF_L_W, Int32 iDEF_M_W, Int32 iDEF_R_W,
//	Int32 iDEF_T_H, Int32 iDEF_M_H, Int32 iDEF_B_H,
//	Int32 iDEF_TL_X, Int32 iDEF_TM_X, Int32 iDEF_TR_X, Int32 iDEF_TL_Y, Int32 iDEF_TM_Y, Int32 iDEF_TR_Y, 
//	Int32 iDEF_ML_X, Int32 iDEF_MM_X, Int32 iDEF_MR_X, Int32 iDEF_ML_Y, Int32 iDEF_MM_Y, Int32 iDEF_MR_Y,
//	Int32 iDEF_BL_X, Int32 iDEF_BM_X, Int32 iDEF_BR_X, Int32 iDEF_BL_Y, Int32 iDEF_BM_Y, Int32 iDEF_BR_Y
void GeUserArea::DrawCustomButton(Int32 x, Int32 y, Int32 w, Int32 h, const Int32* ids, Bool nofill, Bool focus)
{
	C4DOS.Cu->DrawCustomButton(cu, x, y, w, h, ids, nofill, focus);
}

void GeUserArea::SetClippingRegion(Int32 x, Int32 y, Int32 w, Int32 h)
{
	C4DOS.Cu->SetClippingRegion(cu, x, y, w, h);
}

void GeUserArea::ClearClippingRegion(void)
{
	C4DOS.Cu->ClearClippingRegion(cu);
}

Bool GeUserArea::OffScreenOn()
{
	return C4DOS.Cu->OffScreenOn(cu);
}

Bool GeUserArea::OffScreenOn(Int32 x, Int32 y, Int32 w, Int32 h)
{
	return C4DOS.Cu->OffScreenOnRect(cu, x, y, w, h);
}

void GeUserArea::ScrollArea(Int32 xdiff, Int32 ydiff, Int32 x, Int32 y, Int32 w, Int32 h)
{
	C4DOS.Cu->ScrollArea(cu, xdiff, ydiff, x, y, w, h);
}

Float GeUserArea::GetPixelRatio() const
{
	if (!cu)
		return 1.0;
	return C4DOS.Cu->GetPixelRatio((const CBaseFrame*)cu);
}

Bool GeUserArea::Global2Local(Int32* x, Int32* y) const
{
	return C4DOS.Cu->Global2Local((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Local2Global(Int32* x, Int32* y) const
{
	return C4DOS.Cu->Local2Global((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Local2Screen(Int32* x, Int32* y) const
{
	return C4DOS.Cu->Local2Screen((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Screen2Local(Int32* x, Int32* y) const
{
	return C4DOS.Cu->Screen2Local((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Global2Local(Float& x, Float& y) const
{
	return C4DOS.Cu->Global2LocalF((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Local2Global(Float& x, Float& y) const
{
	return C4DOS.Cu->Local2GlobalF((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Local2Screen(Float& x, Float& y) const
{
	return C4DOS.Cu->Local2ScreenF((CBaseFrame*)cu, x, y);
}

Bool GeUserArea::Screen2Local(Float& x, Float& y) const
{
	return C4DOS.Cu->Screen2LocalF((CBaseFrame*)cu, x, y);
}

void GeUserArea::Redraw(Bool threaded)
{
	if (dlg)
	{
		DebugAssert(!(GeIsMainThread() == false && threaded == false), "Enable threaded redraw when not calling from the main thread. Otherwise this will crash.");
		if (threaded)
		{
			C4DOS.Cd->SendRedrawThread(dlg->Get(), GetId());
		}
		else
		{
			dlg->SendMessage(GetId(), BaseContainer(BFM_DRAW));
		}
	}
}

Bool GeUserArea::SendParentMessage(const BaseContainer& msg)
{
	C4DOS.Cu->SendParentMessage(cu, &msg);
	return true;
}

GeData GeUserArea::SendParentMessageResult(const BaseContainer& msg)
{
	return C4DOS.Cu->SendParentMessageResult(cu, &msg);
}

void GeUserArea::MouseDragStart(Int32 button, Float mx, Float my, MOUSEDRAGFLAGS flag)
{
	C4DOS.Cu->MouseDragStart(cu, button, mx, my, flag);
}

MOUSEDRAGRESULT GeUserArea::MouseDrag(Float* mx, Float* my, BaseContainer* channels)
{
	return C4DOS.Cu->MouseDrag(cu, mx, my, channels);
}

MOUSEDRAGRESULT GeUserArea::MouseDragEnd(void)
{
	return C4DOS.Cu->MouseDragEnd(cu);
}

Bool GeUserArea::IsR2L() const
{
	return C4DOS.Cu->IsR2L(cu);
}

Bool GeUserArea::Init(void)
{
	return true;
}

Bool GeUserArea::InitValues(void)
{
	return true;
}

OBSOLETE GeUserArea::Draw(Int32 x1, Int32 y1, Int32 x2, Int32 y2)
{
	DrawSetPen(COLOR_BG);
	DrawRectangle(x1, y1, x2, y2);
	return 0;
}

void GeUserArea::DrawMsg(Int32 x1, Int32 y1, Int32 x2, Int32 y2, const BaseContainer& msg)
{
	Draw(x1, y1, x2, y2);
}

Bool GeUserArea::CoreMessage(Int32 id, const BaseContainer& msg)
{
	return true;
}

Bool GeUserArea::GetMinSize(Int32& w, Int32& h)
{
	return false;
}

void GeUserArea::Sized(Int32 w, Int32 h)
{
}

Bool GeUserArea::InputEvent(const BaseContainer& msg)
{
	return false;
}

void GeUserArea::Timer(const BaseContainer& msg)
{
}

Bool GeUserArea::HandleMouseDrag(const BaseContainer& msg, Int32 type, void* data, Int32 dragflags)
{
	return C4DOS.Cu->HandleMouseDrag(cu, &msg, type, data, dragflags);
}

Bool GeUserArea::GetDragObject(const BaseContainer& msg, Int32* type, void** object) const
{
	return dlg->GetDragObject(msg, type, object);
}

Bool GeUserArea::GetDragPosition(const BaseContainer& msg, Int32* x, Int32* y) const
{
	if (x)
		*x = msg.GetInt32(BFM_DRAG_SCREENX);
	if (y)
		*y = msg.GetInt32(BFM_DRAG_SCREENY);
	return C4DOS.Cu->Screen2Local((CBaseFrame*)cu, x, y);
}

Int32 GeUserArea::Message(const BaseContainer& msg, BaseContainer& result)
{
	Int32 id;
	Int32 res = 0;

	switch (msg.GetId())
	{
		case BFM_INIT:
			Init();
			res = true;
			break;

		case BFM_INITVALUES:
			InitValues();
			res = true;
			break;

		case BFM_CALCSIZE:
		{
			Int32 w = 0, h = 0;
			if (GetMinSize(w, h))
				C4DOS.Cu->SetMinSize(cu, w, h);
			res = true;
			break;
		}

		case BFM_SIZED:
			Sized(GetWidth(), GetHeight());
			res = true;
			break;

		case BFM_DRAW:
		{
			Int32 xr1 = msg.GetInt32(BFM_DRAW_LEFT);
			Int32 yr1 = msg.GetInt32(BFM_DRAW_TOP);
			Int32 xr2 = msg.GetInt32(BFM_DRAW_RIGHT);
			Int32 yr2 = msg.GetInt32(BFM_DRAW_BOTTOM);
			DrawMsg(xr1, yr1, xr2, yr2, msg);
			res = true;
			break;
		}

		case BFM_INPUT:
			return InputEvent(msg);

		case BFM_TIMER_MESSAGE:
			Timer(msg);
			res = true;
			break;

		case BFM_SYNC_MESSAGE:
		case BFM_CORE_MESSAGE:
			id = msg.GetInt32(BFM_CORE_ID);
			return CoreMessage(id, msg);
	}
	return res;
}

void GeUserArea::FillBitmapBackground(BaseBitmap* bmp, Int32 offsetx, Int32 offsety)
{
	DrawBitmap(bmp, -0x12345, -0x12345, -0x12345, -0x12345, offsetx, offsety, -0x12345, -0x12345, -0x12345);
}

void GeUserArea::LayoutChanged(void)
{
	SendParentMessage(BaseContainer(BFM_LAYOUT_CHANGED));
}

SubDialog::SubDialog(void)
{
	dlg_result = true;
}

SubDialog::~SubDialog(void)
{
}

Int32 SubDialog::Message(const BaseContainer& msg, BaseContainer& result)
{
	switch (msg.GetId())
	{
		case BFM_CHECKCLOSE:
			dlg_result = true;
			if (CheckValueRanges())
			{
				dlg_result = false;
				return true;
			}
			return false;

		case BFM_ASKCLOSE:
			if (dlg_result)
			{
				return AskClose();
			}
			return false;
	}
	return GeDialog::Message(msg, result);
}

Int32 ShowPopupMenu(CDialog* parent, Int32 screenx, Int32 screeny, const BaseContainer& bc, Int32 flags, Int32* res_mainid)
{
	return C4DOS.Ge->ShowPopupMenu(parent, screenx, screeny, (BaseContainer*)&bc, flags, res_mainid);
}

Bool RemoveLastCursorInfo(LASTCURSORINFOFUNC func)
{
	return C4DOS.Cd->RemoveLastCursorInfo(func);
}

String Shortcut2String(Int32 shortqual, Int32 shortkey)
{
	return C4DOS.Cd->Shortcut2String(shortqual, shortkey);
}

String Shortcut2String(const BaseContainer& sc)
{
	String t;
	Int32	 i;
	for (i = 0; true; i++)
	{
		Int32 qual = sc.GetInt32(i * 10 + 0);
		Int32 key	 = sc.GetInt32(i * 10 + 1);
		if (!key)
			break;
		if (i > 0)
			t += "~";
		t += Shortcut2String(qual, key);
	}
	return t;
}

#ifndef __API_INTERN__
Bool GetIconCoordInfo(Int32& id, const Char* ident)
{
	return C4DOS.Cd->GetIconCoordInfo(id, ident);
}

Bool GetInterfaceIcon(Int32 type, Int32 id_x, Int32 id_y, Int32 id_w, Int32 id_h, IconData& d)
{
	return C4DOS.Cd->GetInterfaceIcon(type, id_x, id_y, id_w, id_h, d);
}

void MessageDialog(const maxon::String& str)
{
	GeOutString(str, GEMB::OK | GEMB::ICONEXCLAMATION);
}

void MessageDialog(Int32 id)
{
	GeOutString(GeLoadString(id), GEMB::OK | GEMB::ICONEXCLAMATION);
}

void MessageDialog(Int32 id, const maxon::String& p1)
{
	GeOutString(GeLoadString(id, p1), GEMB::OK | GEMB::ICONEXCLAMATION);
}

void MessageDialog(Int32 id, const maxon::String& p1, const maxon::String& p2)
{
	GeOutString(GeLoadString(id, p1, p2), GEMB::OK | GEMB::ICONEXCLAMATION);
}

Bool QuestionDialog(const maxon::String& str)
{
	return GeOutString(str, GEMB::YESNO | GEMB::ICONQUESTION) == GEMB_R::V_YES;
}

Bool QuestionDialog(Int32 id)
{
	return GeOutString(GeLoadString(id), GEMB::YESNO | GEMB::ICONQUESTION) == GEMB_R::V_YES;
}

Bool QuestionDialog(Int32 id, const maxon::String& p1)
{
	return GeOutString(GeLoadString(id, p1), GEMB::YESNO | GEMB::ICONQUESTION) == GEMB_R::V_YES;
}

Bool QuestionDialog(Int32 id, const maxon::String& p1, const maxon::String& p2)
{
	return GeOutString(GeLoadString(id, p1, p2), GEMB::YESNO | GEMB::ICONQUESTION) == GEMB_R::V_YES;
}

Bool GetInputEvent(Int32 askdevice, BaseContainer& res)
{
	return C4DOS.Ge->EwBfGetInputEvent(nullptr, askdevice, &res);
}

Bool GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res)
{
	return C4DOS.Ge->EwBfGetInputState(nullptr, askdevice, askchannel, &res);
}
#endif



Bool GeDialog::GetInputState(Int32 askdevice, Int32 askchannel, BaseContainer& res)
{
	return C4DOS.Cu->GetInputState((CBaseFrame*)cd, askdevice, askchannel, &res);
}

Bool GeDialog::GetInputEvent(Int32 askdevice, BaseContainer& res)
{
	return C4DOS.Cu->GetInputEvent((CBaseFrame*)cd, askdevice, &res);
}

void GeDialog::KillEvents(void)
{
	C4DOS.Cu->KillEvents((CBaseFrame*)cd);
}

// Tristate functions
Bool GeDialog::SetBool(const GadgetPtr& id, const TriState<Bool>& tri)
{
	Int32 v = tri.GetValue();
	Bool t = tri.GetTri();
	if (t)
		v = 2;
	return SetBool(id, v, t);
}

Bool GeDialog::SetInt32(const GadgetPtr& id, const TriState<Int32>& tri, Int32 min, Int32 max, Int32 step, Int32 min2, Int32 max2)
{
	return SetInt32(id, tri.GetValue(), min, max, step, tri.GetTri(), min2, max2);
}

Bool GeDialog::SetFloat(const GadgetPtr& id, const TriState<Float>& tri, Float min, Float max, Float step, Int32 format, Float min2, Float max2, Bool quadscale)
{
	return SetFloat(id, tri.GetValue(), min, max, step, format, min2, max2, quadscale, tri.GetTri());
}

Bool GeDialog::SetMeter(const GadgetPtr& id, const TriState<Float>& tri, Float min, Float max, Float step)
{
	return SetMeter(id, tri.GetValue(), min, max, step, tri.GetTri());
}

Bool GeDialog::SetDegree(const GadgetPtr& id, const TriState<Float>& tri, Float min, Float max, Float step)
{
	return SetDegree(id, tri.GetValue(), min, max, step, tri.GetTri());
}

Bool GeDialog::SetPercent(const GadgetPtr& id, const TriState<Float>& tri, Float min, Float max, Float step)
{
	return SetPercent(id, tri.GetValue(), min, max, step, tri.GetTri());
}

Bool GeDialog::SetTime(const GadgetPtr& id, const BaseDocument* doc, const TriState<BaseTime>& tri, const BaseTime& min, const BaseTime& max, Int32 stepframes)
{
	return SetTime(id, doc, tri.GetValue(), min, max, stepframes, tri.GetTri());
}

Bool GeDialog::SetString(const GadgetPtr& id, const TriState<String>& tri, Int32 flags)
{
	return SetString(id, tri.GetValue(), tri.GetTri(), flags);
}

Bool GeDialog::SetColorField(const GadgetPtr& id, const TriState<Vector>& tri, Float brightness, Float maxbrightness, Int32 flags)
{
	return SetColorField(id, tri.GetValue(), brightness, maxbrightness, flags);
}

Bool GeDialog::CheckDropArea(const GadgetPtr& id, const BaseContainer& msg, Bool horiz, Bool vert)
{
	Int32 x, y, w, h, dx, dy;
	GetDragPosition(msg, &dx, &dy);
	GetItemDim(id, &x, &y, &w, &h);
	if (horiz && vert)
		return dx > x && dx < x + w && dy > y && dy < y + h;
	else if (vert)
		return dy > y && dy < y + h;
	return dx > x && dx < x + w;
}

Bool GeDialog::CheckCoreMessage(const BaseContainer& msg, Int32* ownlastcoremsg)
{
	Int32* storage = ownlastcoremsg;
	if (!storage)
		storage = &t_lastcoremsg;

	Int32 coremsg = msg.GetInt32(BFM_CORE_UNIQUEID);
	if (!coremsg)
		return true;
	if (coremsg == *storage)
		return false;
	if (coremsg == msg.GetInt32(BFM_CORE_ID) && ((UInt)msg.GetVoid(BFM_CORE_PAR1) & (UInt)EVENT::GLHACK))
		return false;
	*storage = coremsg;
	return true;
}

void GeDialog::HandleHelpString(const BaseContainer& msg, BaseContainer& result, const maxon::String& sym)
{
	const BaseContainer* bc = msg.GetContainerInstance(BFM_GETCURSORINFO);
	if (bc && bc->GetDataPointer(RESULT_HELP1) != nullptr)
		return;
	result = msg.GetContainer(BFM_GETCURSORINFO);
	if (result.GetId() == -1 || result.GetId() == 0)
		result.SetId(BFM_GETCURSORINFO);
	result.SetString(RESULT_HELP1, sym);
}

Bool GeDialog::GetColorRGB(Int32 colorid, Int32& r, Int32& g, Int32& b)
{
	return C4DOS.Cd->CBF_GetColorRGB((CBaseFrame*)Get(), colorid, r, g, b);
}

void GeDialog::SetDefaultColor(const GadgetPtr& id, Int32 colorid, Int32 mapid)
{
	C4DOS.Cd->AddGadget(cd, DIALOG_SETDEFAULTCOLOR, id.Id(), nullptr, colorid, mapid, 0, 0, nullptr, (void**)id.Ptr());
}

void GeDialog::SetDefaultColor(const GadgetPtr& id, Int32 colorid, const Vector& color)
{
	C4DOS.Cd->AddGadget(cd, DIALOG_SETDEFAULTCOLOR, id.Id(), nullptr, colorid, NOTOK, 0, 0, (BaseContainer*)&color, (void**)id.Ptr());
}


Bool GeDialog::GroupBeginInMenuLine()
{
	return C4DOS.Cd->AddGadget(Get(), DIALOG_MENUGROUPBEGIN, 0, nullptr, 0, 0, 0, 0, nullptr, nullptr);
}

template <> void TriState<Int32>::Add(BaseContainer* bc, Int32 id)
{
	Int32 val;
	val = bc->GetInt32(id);
	Add(val);
}

template <> void TriState<Float>::Add(BaseContainer* bc, Int32 id)
{
	Float val;
	val = bc->GetFloat(id);
	Add(val);
}

template <> void TriState<Vector>::Add(BaseContainer* bc, Int32 id)
{
	Vector val;
	val = bc->GetVector(id);
	Add(val);
}

template <> void TriState<BaseTime>::Add(BaseContainer* bc, Int32 id)
{
	BaseTime val;
	val = bc->GetTime(id);
	Add(val);
}

template <> void TriState<String>::Add(BaseContainer* bc, Int32 id)
{
	String val;
	val = bc->GetString(id);
	Add(val);
}


template <> Int32 TriState<Int32>::Check(GeDialog* dlg, const BaseContainer& msg, Int32 cid, Int32 gid)
{
	if (cid != gid || msg.GetInt32(BFM_ACTION_STRCHG) || msg.GetInt32(BFM_ACTION_INDRAG))
		return 0;
	Int32 val = 0;
	if (!dlg->GetInt32(cid, val))
		return 0;
	Add(val);
	return 1;
}

template <> Int32 TriState<Float>::Check(GeDialog* dlg, const BaseContainer& msg, Int32 cid, Int32 gid)
{
	if (cid != gid || msg.GetInt32(BFM_ACTION_STRCHG) || msg.GetInt32(BFM_ACTION_INDRAG))
		return 0;
	Float val = 0.0;
	if (!dlg->GetFloat(cid, val))
		return 0;
	Add(val);
	return 1;
}

template <> Int32 TriState<Vector>::CheckVector(GeDialog* dlg, const BaseContainer& msg, Int32 cid, Int32 gidx, Int32 gidy, Int32 gidz)
{
	if (cid != gidx && cid != gidy && cid != gidz)
		return 0;
	if (msg.GetInt32(BFM_ACTION_STRCHG) || msg.GetInt32(BFM_ACTION_INDRAG))
		return 0;

	Vector val = Vector(0.0);
	if (!dlg->GetVector(gidx, gidy, gidz, val))
		return 0;
	Add(val);
	return true;
}

template <> Int32 TriState<BaseTime>::CheckBaseTime(GeDialog* dlg, const BaseContainer& msg, BaseDocument* doc, Int32 cid, Int32 gid)
{
	if (cid != gid || msg.GetInt32(BFM_ACTION_STRCHG) || msg.GetInt32(BFM_ACTION_INDRAG))
		return 0;
	BaseTime val;
	if (!dlg->GetTime(cid, doc, val))
		return 0;
	Add(val);
	return true;
}

template <> Int32 TriState<String>::Check(GeDialog* dlg, const BaseContainer& msg, Int32 cid, Int32 gid)
{
	if (cid != gid || msg.GetInt32(BFM_ACTION_STRCHG) || msg.GetInt32(BFM_ACTION_INDRAG))
		return 0;
	String val;
	if (!dlg->GetString(cid, val))
		return 0;
	Add(val);
	return true;
}


iCustomGui::iCustomGui(const BaseContainer& settings, CUSTOMGUIPLUGIN* t_plugin)
{
	plugin = t_plugin;

	layoutmode = settings.GetInt32(CUSTOMGUI_LAYOUTMODE);
	if (layoutmode != LAYOUTMODE_MINIMIZED && layoutmode != LAYOUTMODE_MAXIMIZED)
		layoutmode = LAYOUTMODE_NONE;

	editheight = settings.GetInt32(CUSTOMGUI_DEFAULTEDITHEIGHT, 10/*EDITH*/);
}

Int32 iCustomGui::Message(const BaseContainer& msg, BaseContainer& result)
{
	switch (msg.GetId())
	{
		case MSG_DESCRIPTION_GETOBJECTS:
		{
			DescriptionGetObjects dgo;
			BaseContainer m(msg);
			if (m.GetInt32(BFM_ACTION_VALUE) == MSG_DESCRIPTION_GETOBJECTS)
			{
				m.SetInt32(BFM_ACTION_ID, GetId());
				return SendParentMessage(m);
			}
			break;
		}
			
		case BFM_DESTROY:
			ReleaseLink();
			DestroyWindow();
			return true;
	}
	return SubDialog::Message(msg, result);
}

Int32 iCustomGui::CustomGuiWidth()
{
	return 0;
}

Int32 iCustomGui::CustomGuiHeight()
{
	return 0;
}

void iCustomGui::CustomGuiRedraw()
{
}

Bool iCustomGui::CustomGuiLayoutChanged()
{
	return false;
}

Bool iCustomGui::CustomGuiActivate()
{
	return false;
}

Bool iCustomGui::SetDefaultForResEdit()
{
	return false;
}

Bool iCustomGui::SetData(const TriState<GeData>& tristate)
{
	return false;
}

TriState<GeData> iCustomGui::GetData()
{
	TriState<GeData> tri;
	return tri;
}

void iCustomGui::SetLayoutMode(Int32 mode)
{
	if (SupportLayoutSwitch() && layoutmode != mode)
	{
		layoutmode = mode;
		LayoutModeChanged();
	}
}

Int32 iCustomGui::GetLayoutMode()
{
	return layoutmode;
}

Bool iCustomGui::SupportLayoutSwitch()
{
	if (!plugin)
		return false;
	return (plugin->info & CUSTOMGUI_SUPPORT_LAYOUTSWITCH) != 0;
}

void iCustomGui::LayoutModeChanged()
{
}

//-------------------------------------------------------------------------------------------------

const Char* ProgressThread::GetThreadName(void) { return "Progress Thread"; }

#define IDC_CACHE_TEXT 1000
#define IDC_CACHE_AREA 1001

ProgressDialog* ProgressThread::AcquireAndLock()
{
	ProgressDialog* unlocked = (ProgressDialog*)(UInt(dlg.LoadRelaxed()) & ~UInt(3));
	ProgressDialog* locked = (ProgressDialog*)(UInt(unlocked) | 1);
	while (dlg.TryCompareAndSwap(locked, unlocked) == false)
	{
		UInt value = UInt(dlg.LoadRelaxed());

		// If the pointer has been locked for closing the dialog and this is being called from the main thread return a nullptr (this prevents a deadlock due to the GeModalDialog::Close()).
		if ((value & 2) && maxon::ThreadRef::IsMainThread())
			return nullptr;

		unlocked = (ProgressDialog*)(value & ~UInt(3));
		locked = (ProgressDialog*)(UInt(unlocked) | 1);
	}
	return unlocked;
}

void ProgressThread::AcquireAndClearLock()
{
	ProgressDialog* unlocked = (ProgressDialog*)(UInt(dlg.LoadRelaxed()) & ~UInt(3));
	while (dlg.TryCompareAndSwap(nullptr, unlocked) == false)
	{
		UInt value = UInt(dlg.LoadRelaxed());

		// If the pointer has been locked for closing the dialog and this is being called from the main thread return a nullptr (this prevents a deadlock due to the GeModalDialog::Close()).
		if ((value & 2) && maxon::ThreadRef::IsMainThread())
			return;

		unlocked = (ProgressDialog*)(value & ~UInt(3));
	}
}

// Indicates that the job to close the dialog is being executed on the main thread.
void ProgressThread::MarkAsInClose(ProgressDialog* pdlg)
{
	UInt value = UInt(pdlg) | 3;
	dlg.StoreRelease((ProgressDialog*) value);
}

void ProgressThread::ReleaseLock(ProgressDialog* pdlg)
{
	dlg.StoreRelease(pdlg);
}

Bool ProgressThread::Start(ProgressDialog* pdlg)
{
	AcquireAndLock();
	ReleaseLock(pdlg);

	return C4DThread::Start();
}

void ProgressThread::End()
{
	// Ensure Main() does not access dlg and clear it - now it's safe to close or delete it.
	AcquireAndClearLock();

	C4DThread::End();
}

void ProgressThread::Main(void)
{
	ProgressDialog* pdlg = AcquireAndLock();
	ReleaseLock(pdlg);
	
	if (pdlg)
	{
		// This assumes that the caller ensures the dialog is alive long enough that ProgressDialog::Main() can be called.
		pdlg->SetPercent(0.0);
		pdlg->Main(this);
		
		// Ensure dlg is valid until ReleaseLock().
		pdlg = AcquireAndLock();
		if (pdlg)
		{
			// ITEM#306059 Using HDRI Studio Hang when trying to export alembic files
			maxon::JobRef::Enqueue([this, pdlg]()
			{
				// Set flag to indicate that we're about to close the dialog from the main thread (this is a sick recursive lock).
				MarkAsInClose(pdlg);

				BaseContainer m(BFM_SETSTATUSBAR);
				m.SetBool(BFM_STATUSBAR_PROGRESSON, false);
				pdlg->SendMessage(IDC_CACHE_AREA, m);
				pdlg->Close(true);

				// From now on the thread doesn't care about the dialog anymore.
				ReleaseLock(nullptr);
			}, maxon::JobQueueRef::GetMainThreadQueue()) iferr_ignore("In worst case the user has to close the progress dialog via the closer");
		}
		else
		{
			// From now on the thread doesn't care about the dialog anymore.
			ReleaseLock(nullptr);
		}
	}
}

void ProgressDialog::SetPercent(Float p) { percent = p; }

Bool ProgressDialog::CreateLayout(void)
{
	SetTitle(GetTitle());

	GroupBegin(0, BFH_SCALEFIT | BFV_SCALEFIT, 2, 0, String(), 0);
	if (!AddStaticText(IDC_CACHE_TEXT, BFH_LEFT, SizePix(40), 0, String(), BORDER_NONE))
		return false;
	GroupBegin(0, BFH_SCALEFIT, 0, 0, String(), 0);
	GroupBorderNoTitle(BORDER_THIN_IN);
	AddCustomGui(IDC_CACHE_AREA, CUSTOMGUI_PROGRESSBAR, String(), BFH_SCALEFIT | BFV_FIT, SizePix(300), SizePix(12), BaseContainer());
	GroupEnd();
	GroupEnd();

	AddDlgGroup(DLG_CANCEL);

	return true;
}

Bool ProgressDialog::InitValues(void)
{
	thread.End();

	percent = 0.0;
	SetTimer(200);
	SetString(IDC_CACHE_TEXT, "0%"_s);
	SetBakeStatus(true);

	return thread.Start(this) != 0;
}

C4DThread* ProgressDialog::GetThread(void)
{
	return &thread;
}

void ProgressDialog::Timer(const BaseContainer& msg)
{
	SetString(IDC_CACHE_TEXT, String::IntToString(Int32(percent * 100.0)) + "%");

	BaseContainer m(BFM_SETSTATUSBAR);
	m.SetBool(BFM_STATUSBAR_PROGRESSON, true);
	m.SetFloat(BFM_STATUSBAR_PROGRESS, percent);
	SendMessage(IDC_CACHE_AREA, m);
}

Int32 ProgressDialog::Message(const BaseContainer& msg, BaseContainer& result)
{
	switch (msg.GetId())
	{
		case BFM_GETCURSORINFO:
			result = BaseContainer(1);
			result.SetInt32(RESULT_CURSOR, MOUSE_BUSY);
			return true;
			break;

		case BFM_CHECKCLOSE:
			if (!AskClose())
				return false;

			return true;
			break;
	}
	return GeModalDialog::Message(msg, result);
}

Bool ProgressDialog::Command(Int32 id, const BaseContainer& msg)
{
	switch (id)
	{
		case IDC_CANCEL:
			thread.End();
			Close(false);
			return true;
			break;
	}

	return GeDialog::Command(id, msg);
}

Bool ProgressDialog::AskClose()
{
	// thread MUST be killed
	SetBakeStatus(false);
	thread.End();
	return false;
}



UpdateDialogHelper::UpdateDialogHelper(GeDialog* dialog, Int32 id) : _dialog(dialog), _gadget(id)
{

}

UpdateDialogHelper::UpdateDialogHelper(GeDialog* dialog, C4DGadget* gad) : _dialog(dialog), _gadget(gad)
{

}

UpdateDialogHelper::UpdateDialogHelper(UpdateDialogHelper&& src) : MAXON_MOVE_MEMBERS(_dialog, _gadget, _committed, _redrawDisabled)
{
	src._dialog = nullptr;
	src._gadget = GadgetPtr(Int32(0));
	src._committed = false;
	src._redrawDisabled = false;
}

UpdateDialogHelper::~UpdateDialogHelper()
{
	if (_dialog)
	{
		ReenableRedraw();
	}
}

void UpdateDialogHelper::CommitChanges()
{
	if (_dialog)
	{
		ReenableRedraw();
		if (_committed == false)
		{
			_dialog->LayoutChanged(_gadget);
			_committed = true;
		}
	}
}

UpdateDialogHelper UpdateDialogHelper::BeginLayoutChange(GeDialog* dialog, const GadgetPtr& gadget, Bool disableRedraws, Bool doNotFlush)
{
	UpdateDialogHelper obj = gadget.Id() ? UpdateDialogHelper(dialog, gadget.Id()) : UpdateDialogHelper(dialog, gadget.Ptr());

	
	if (C4DOS.Cd->AddGadget(dialog->Get(), DIALOG_FLUSHGROUP, obj._gadget.Id(), nullptr, doNotFlush, 0, 0, 0, nullptr, (void**)obj._gadget.Ptr()))
	{
		if (disableRedraws)
		{
			obj._dialog->LayoutFlushDisableRedraw(gadget, true);
			obj._redrawDisabled = true;
		}
	}

	return obj;
}

void UpdateDialogHelper::ReenableRedraw()
{
	if (_redrawDisabled)
	{
		_dialog->LayoutFlushDisableRedraw(_gadget, false);
		_redrawDisabled = false;
	}
}

Filename GetDnDFilename(const BaseContainer& msg, Int32 dragType, const void* dragObj, Bool texturesOnly, Bool updateUsage, Bool loadUrl)
{
	return C4DOS.Cd->GetDnDFilename(msg, dragType, dragObj, texturesOnly, updateUsage, loadUrl);
}

AutoWaitPointer::AutoWaitPointer(Bool setBusy /*= false*/)
{
	if (setBusy)
		SetBusy();
}

AutoWaitPointer::~AutoWaitPointer()
{
	SetNormal();
}

void AutoWaitPointer::SetBusy()
{
	if (!_set)
	{
		maxon::ExecuteOnMainThread(
			[]()
			{
				GeShowMouse(MOUSE_BUSY);
			}, false);

		_set = true;
	}
}

void AutoWaitPointer::SetNormal()
{
	if (_set)
	{
		maxon::ExecuteOnMainThread(
			[]()
			{
				GeShowMouse(MOUSE_NORMAL);
			}, false);

		_set = false;
	}
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

