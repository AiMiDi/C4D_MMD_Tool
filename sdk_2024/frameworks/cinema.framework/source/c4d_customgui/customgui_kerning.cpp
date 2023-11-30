#include "customgui_kerning.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_tools.h"
#include "lib_description.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

KerningLib *lib_kerning = nullptr;

static KerningLib *CheckKerningLib(Int32 offset)
{
	return CheckLib<KerningLib>(CUSTOMGUI_KERNING, offset, lib_kerning);
}


#define KerningDataLibCall(b)			KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return; \
	(reinterpret_cast<iKerningData*>(this)->*lib->b)

#define KerningDataLibCallR(a, b)	KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<iKerningData*>(this)->*lib->b)

#define KerningDataLibCallRC(a, b)	KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<const iKerningData*>(this)->*lib->b)

#define KerningVpGuiHelperLibCall(b)			KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return; \
	(reinterpret_cast<iKerningVpGuiHelper*>(this)->*lib->b)

#define KerningVpGuiHelperLibCallR(a, b)		KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<iKerningVpGuiHelper*>(this)->*lib->b)

#define KerningVpGuiHelperLibCallRC(a, b)		KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<const iKerningVpGuiHelper*>(this)->*lib->b)

#define KerningLibCall(b)			KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define KerningLibCallR(a, b)	KerningLib *lib = CheckKerningLib(LIBOFFSET(KerningLib, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)


KerningData* KerningData::Alloc()
{
	KerningLibCallR(nullptr, KerningData_Alloc)();
}

void KerningData::Free(KerningData *&pData)
{
	KerningLibCall(KerningData_Free)(pData);
}

Kerning KerningData::GetKerning(Int32 index) const
{
	KerningDataLibCallRC(Kerning(), GetKerning)(index);
}

Kerning KerningData::CalculateKerning(Int32 index, const maxon::String& s) const
{
	KerningDataLibCallRC(Kerning(), CalculateKerning)(index, s);
}

Bool KerningData::SetKerning(Int32 index, const Kerning& kerning, Bool combine)
{
	KerningDataLibCallR(false, SetKerning1)(index, kerning, combine);
}

Bool KerningData::SetKerning(Int32 index_start, Int32 index_end, const Kerning& kerning, Bool combine)
{
	KerningDataLibCallR(false, SetKerning2)(index_start, index_end, kerning, combine);
}

Bool KerningData::SetKerning(Int32 index_start, Int32 index_end, const KerningTriState& tristate)
{
	KerningDataLibCallR(false, SetKerning3)(index_start, index_end, tristate);
}

void KerningData::ResetKerning(Int32 index)
{
	KerningDataLibCall(ResetKerning1)(index);
}

void KerningData::ResetKerning()
{
	KerningDataLibCall(ResetKerning2)();
}

Bool KerningData::Init(const maxon::String& string, Bool preserve)
{
	KerningDataLibCallR(false, Init1)(string, preserve);
}

Bool KerningData::Init(Int32 count, Bool preserve)
{
	KerningDataLibCallR(false, Init2)(count, preserve);
}

Int32 KerningData::GetCount() const
{
	KerningDataLibCallRC(0, GetCount)();
}

void KerningData::Clear()
{
	KerningDataLibCall(Clear)();
}

Bool KerningData::CopyTo(KerningData* pDest) const
{
	KerningDataLibCallRC(false, CopyTo)(reinterpret_cast<iKerningData*>(pDest));
}

String KerningData::GetString() const
{
	KerningDataLibCallRC(String(), GetString)();
}

void KerningData::SetSelectionStart(Int32 start)
{
	KerningDataLibCall(SetSelectionStart)(start);
}

Int32 KerningData::GetSelectionStart() const
{
	KerningDataLibCallRC(NOTOK, GetSelectionStart)();
}

void KerningData::SetSelectionEnd(Int32 end)
{
	KerningDataLibCall(SetSelectionEnd)(end);
}

Int32 KerningData::GetSelectionEnd() const
{
	KerningDataLibCallRC(NOTOK, GetSelectionEnd)();
}

void KerningData::SetSelection(Int32 start, Int32 end)
{
	KerningDataLibCall(SetSelection)(start, end);
}

Int32 KerningData::GetSelectionLength() const
{
	KerningDataLibCallRC(NOTOK, GetSelectionLength)();
}

Bool KerningData::GetEditmode() const
{
	KerningDataLibCallRC(false, GetEditmode)();
}

void KerningData::SetEditmode(Bool editmode)
{
	KerningDataLibCall(SetEditmode)(editmode);
}


Bool KerningVpGuiHelper::Init(const maxon::String& s, BaseContainer* generationresults, const KerningData* kd, Int32 plane)
{
	KerningVpGuiHelperLibCallR(false, VpGuiHelper_Init)(s, generationresults, kd, plane);
}

DRAWRESULT KerningVpGuiHelper::Draw(BaseObject *op, BaseDraw *bd, BaseDrawHelp *bh)
{
	KerningVpGuiHelperLibCallR(DRAWRESULT::FAILURE, VpGuiHelper_Draw)(op, bd, bh);
}

Int32 KerningVpGuiHelper::DetectHandle(BaseObject *op, BaseDraw *bd, Int32 x, Int32 y, QUALIFIER qualifier)
{
	KerningVpGuiHelperLibCallR(NOTOK, VpGuiHelper_DetectHandle)(op, bd, x, y, qualifier);
}

Bool KerningVpGuiHelper::MoveHandle(BaseObject *op, BaseObject *undo, const Vector &mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw *bd)
{
	KerningVpGuiHelperLibCallR(false, VpGuiHelper_MoveHandle)(op, undo, mouse_pos, hit_id, qualifier, bd);
}

void KerningVpGuiHelper::GetHandle(BaseObject *op, Int32 i, HandleInfo &info)
{
	KerningVpGuiHelperLibCall(VpGuiHelper_GetHandle)(op, i, info);
}

Bool KerningVpGuiHelper::ClickHandle(Bool release, BaseObject* op)
{
	KerningVpGuiHelperLibCallR(false, VpGuiHelper_ClickHandle)(release, op);
}

void KerningVpGuiHelper::SetZeroSize()
{
	KerningVpGuiHelperLibCall(VpGuiHelper_SetZeroSize)();
}

Bool KerningVpGuiHelper::CopyTo(KerningVpGuiHelper* dest) const
{
	KerningVpGuiHelperLibCallRC(false, VpGuiHelper_CopyTo)(reinterpret_cast<iKerningVpGuiHelper*>(dest));
}

KerningVpGuiHelper* KerningVpGuiHelper::Alloc()
{
	KerningLibCallR(nullptr, VpGuiHelper_Alloc)();
}

void KerningVpGuiHelper::Free(KerningVpGuiHelper*& pData)
{
	KerningLibCall(VpGuiHelper_Free)(pData);
}


Bool Kerning::ReadHF(HyperFile* hf, Int32 level)
{
	KerningLibCallR(false, Kerning_ReadHF)(this, hf, level);
}

Bool Kerning::WriteHF(HyperFile* hf) const
{
	KerningLibCallR(false, Kerning_WriteHF)(this, hf);
}

Vector Kerning::GetOffsetVector() const
{
	return Vector(_kerning + _tracking, _baselineShift, 0.0_f);
}

Vector Kerning::GetScaleVector() const
{
	return Vector(_scale * _scaleH, _scale * _scaleV, 1.0_f);
}

String Kerning::ToString() const
{
	return "[kerning=" + String::FloatToString(_kerning) + ";tracking=" + String::FloatToString(_tracking) + ";baselineShift=" + String::FloatToString(_baselineShift) + ";scale=" + String::FloatToString(_scale) + ";scaleH=" + String::FloatToString(_scaleH) + ";scaleV=" + String::FloatToString(_scaleV) + ";leading=" + String::FloatToString(_leading)+"]";
}


Kerning BlendKerning(const Kerning& k1, const Kerning& k2, Float mix)
{
	KerningLibCallR(Kerning(), BlendKerning)(k1, k2, mix);
}

Bool HandleKerningMessages(GeListNode *node, Int32 msgId, Int32 kerningDescID, Int32 textDescID, void* msgData, KerningVpGuiHelper* guihelper)
{
	KerningLibCallR(false, HandleKerningMessages)(node, msgId, kerningDescID, textDescID, msgData, guihelper);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
