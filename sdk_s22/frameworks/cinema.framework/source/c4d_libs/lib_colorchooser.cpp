#include "lib_colorchooser.h"

ColorUtilsLibrary* lib_colorchooser = nullptr;
ColorSwatchDataLibrary* lib_colorswatchdata = nullptr;
ColorSwatchGroupLibrary* lib_colorswatchgroup = nullptr;


//----------------------------------------------------------------------------------------
/// Color Utils Library
//----------------------------------------------------------------------------------------

static ColorUtilsLibrary *CheckColorUtilsLib(Int32 offset)
{
	return (ColorUtilsLibrary*)CheckLib(LIB_COLORCHOOSER, offset, (C4DLibrary**)&lib_colorchooser);
}

#define ColorUtilsCall(b)         ColorUtilsLibrary *lib = CheckColorUtilsLib(LIBOFFSET(ColorUtilsLibrary, b)); \
																															if (!lib || !lib->b) return; \
																															(lib->b)

#define ColorUtilsCallR(a, b)			ColorUtilsLibrary *lib = CheckColorUtilsLib(LIBOFFSET(ColorUtilsLibrary, b)); \
																															if (!lib || !lib->b) return a; \
																															return (lib->b)

String ColorRGBToString(const Vector& color)
{
	ColorUtilsCallR(String(), ColorRGBToString)(color);
}

String ColorHSVToString(const Vector& color)
{
	ColorUtilsCallR(String(), ColorHSVToString)(color);
}

Int ColorComponentFloatTo8Bit(Float colorComponent)
{
	ColorUtilsCallR(0, ColorComponentFloatTo8Bit)(colorComponent);
}

Float ColorComponent8BitToFloat(Int colorComponent)
{
	ColorUtilsCallR(0.0, ColorComponent8BitToFloat)(colorComponent);
}

void ColorFloatTo8Bit(const Vector& floatColor, Int& red, Int& green, Int& blue)
{
	ColorUtilsCall(ColorFloatTo8Bit)(floatColor, red, green, blue);
}

Vector Color8BitToFloat(Int red, Int green, Int blue)
{
	ColorUtilsCallR(Vector(0.0), Color8BitToFloat)(red, green, blue);
}

Int ColorComponentFloatTo16Bit(Float colorComponent)
{
	ColorUtilsCallR(0, ColorComponentFloatTo16Bit)(colorComponent);
}

Float ColorComponent16BitToFloat(Int colorComponent)
{
	ColorUtilsCallR(0.0, ColorComponent16BitToFloat)(colorComponent);
}

void ColorFloatTo16Bit(const Vector& floatColor, Int& red, Int& green, Int& blue)
{
	ColorUtilsCall(ColorFloatTo16Bit)(floatColor, red, green, blue);
}

Vector Color16BitToFloat(Int red, Int green, Int blue)
{
	ColorUtilsCallR(Vector(0.0), Color16BitToFloat)(red, green, blue);
}

Vector ColorKelvinTemperatureToRGB(Float kelvinDegrees, Float tint)
{
	ColorUtilsCallR(Vector(0.0), ColorKelvinTemperatureToRGB)(kelvinDegrees, tint);
}

Bool ColorHarmonyGetComplementary(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyGetComplementary)(color, ryb, palette);
}

Bool ColorHarmonyGetSplitComplementary(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyGetSplitComplementary)(color, ryb, palette);
}

Bool ColorHarmonyGetTetradic(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyGetTetrad)(color, ryb, palette);
}

Bool ColorHarmonyGetAnalogous(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyGetAnalogous)(color, colorCount, ryb, palette);
}

Bool ColorHarmonyGetEquiangular(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyGetEquiangular)(color, colorCount, ryb, palette);
}

Bool ColorHarmonyRotateColor(const Vector& color, Int colorCount, Float angle, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyRotateColor)(color, colorCount, angle, ryb, palette);
}

Bool ColorHarmonyInterpolateColors(const Vector& color1, const Vector& color2, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette)
{
	ColorUtilsCallR(false, ColorHarmonyInterpolateColors)(color1, color2, colorCount, ryb, palette);
}


//----------------------------------------------------------------------------------------
/// Color Swatch Data Library
//----------------------------------------------------------------------------------------

static ColorSwatchDataLibrary* CheckColorSwatchDataLibrary(Int32 offset)
{
	return (ColorSwatchDataLibrary*)CheckLib(LIB_COLORSWATCHDATA, offset, (C4DLibrary**)&lib_colorswatchdata);
}

#define ColorSwatchDataCall(b)					ColorSwatchDataLibrary *lib = CheckColorSwatchDataLibrary(LIBOFFSET(ColorSwatchDataLibrary, b)); \
																																					if (!lib || !lib->b) return; \
																																					(((iColorSwatchData*)this)->*lib->b)

#define ColorSwatchDataCallR(a, b)			ColorSwatchDataLibrary *lib = CheckColorSwatchDataLibrary(LIBOFFSET(ColorSwatchDataLibrary, b)); \
																																					if (!lib || !lib->b) return a; \
																																					return (((iColorSwatchData*)this)->*lib->b)

#define ColorSwatchDataCallS(b)					ColorSwatchDataLibrary* lib = CheckColorSwatchDataLibrary(LIBOFFSET(ColorSwatchDataLibrary, b)); \
																																					if (!lib || !lib->b) return; \
																																					(lib->b)

#define ColorSwatchDataCallSR(a, b)			ColorSwatchDataLibrary* lib = CheckColorSwatchDataLibrary(LIBOFFSET(ColorSwatchDataLibrary, b)); \
																																					if (!lib || !lib->b) return a; \
																																					return (lib->b)

ColorSwatchData* ColorSwatchData::Alloc(BaseDocument* doc, Bool global)
{
	ColorSwatchDataCallSR(nullptr, Alloc)(doc, global);
}

void ColorSwatchData::Free(ColorSwatchData *&p)
{
	if (!p)
		return;

	ColorSwatchDataCallS(Free)(p);
	p = nullptr;
}

Bool ColorSwatchData::Load(BaseDocument* doc, Bool merge, Bool loadGlobalColors)
{
	ColorSwatchDataCallR(false, Load)(doc, merge, loadGlobalColors);
}

Bool ColorSwatchData::Save(BaseDocument* doc, Bool saveGlobalColors)
{
	ColorSwatchDataCallR(false, Save)(doc, saveGlobalColors);
}

Bool ColorSwatchData::LoadPreset(const String& name, Bool merge)
{
	ColorSwatchDataCallR(false, LoadPresetByName)(name, merge);
}

Bool ColorSwatchData::LoadPreset(const SDKBrowserURL& url, Bool merge)
{
	ColorSwatchDataCallR(false, LoadPresetByURL)(url, merge);
}

Bool ColorSwatchData::SavePreset(const String& name, const String& author, const String& info, Bool forceOverwrite)
{
	ColorSwatchDataCallR(false, SavePresetByName)(name, author, info, forceOverwrite);
}

Bool ColorSwatchData::SavePreset(const SDKBrowserURL& url, const String& author, const String& info, Bool forceOverwrite)
{
	ColorSwatchDataCallR(false, SavePresetByURL)(url, author, info, forceOverwrite);
}

Bool ColorSwatchData::PresetExists(const String& name, maxon::BaseArray<SDKBrowserURL>* urls)
{
	ColorSwatchDataCallSR(false, PresetExists)(name, urls);
}

Bool ColorSwatchData::ValidPreset(const SDKBrowserURL& url)
{
	ColorSwatchDataCallSR(false, ValidPreset)(url);
}

SDKBrowserURL ColorSwatchData::GetPresetDirectory()
{
	ColorSwatchDataCallSR(SDKBrowserURL(), GetPresetDirectory)();
}

Bool ColorSwatchData::Merge(ColorSwatchData* data, Bool mergeGlobalColors)
{
	ColorSwatchDataCallR(false, Merge)(data, mergeGlobalColors);
}

Bool ColorSwatchData::CopyFrom(ColorSwatchData* data)
{
	ColorSwatchDataCallR(false, CopyFrom)(data);
}

Int ColorSwatchData::GetGroupCount(SWATCH_CATEGORY category) const
{
	ColorSwatchDataCallR(0, GetGroupCount)((Int)category);
}

ColorSwatchGroup* ColorSwatchData::GetGroupAtIndex(Int index, SWATCH_CATEGORY category)
{
	ColorSwatchDataCallR(nullptr, GetGroupAtIndex)(index, (Int)category);
}

Bool ColorSwatchData::SetGroupAtIndex(Int index, ColorSwatchGroup* group, SWATCH_CATEGORY category)
{
	ColorSwatchDataCallR(false, SetGroupAtIndex)(index, group, (Int)category);
}

ColorSwatchGroup* ColorSwatchData::AddGroup(SWATCH_CATEGORY category, const String& name, Bool selected, Int insertAt, const ColorAlphaArray& colors)
{
	ColorSwatchDataCallR(nullptr, AddGroup)((Int)category, name, selected, insertAt, colors);
}

Bool ColorSwatchData::InsertGroup(ColorSwatchGroup* group, Int insertAt, SWATCH_CATEGORY category)
{
	ColorSwatchDataCallR(false, InsertGroup)(group, insertAt, (Int)category);
}

Bool ColorSwatchData::RemoveGroup(Int index, SWATCH_CATEGORY category)
{
	ColorSwatchDataCallR(false, RemoveGroup)(index, (Int)category);
}

Bool ColorSwatchData::RemoveSelectedItems()
{
	ColorSwatchDataCallR(false, RemoveSelectedItems)();
}

void ColorSwatchData::Reset()
{
	ColorSwatchDataCall(Reset)();
}


//----------------------------------------------------------------------------------------
/// Color Swatch Group Library
//----------------------------------------------------------------------------------------

static ColorSwatchGroupLibrary* CheckColorSwatchGroupLibrary(Int32 offset)
{
	return (ColorSwatchGroupLibrary*)CheckLib(LIB_COLORSWATCHGROUP, offset, (C4DLibrary**)&lib_colorswatchgroup);
}

#define ColorSwatchGroupCall(b)         ColorSwatchGroupLibrary *lib = CheckColorSwatchGroupLibrary(LIBOFFSET(ColorSwatchGroupLibrary, b)); \
																																						if (!lib || !lib->b) return; \
																																						(((iColorSwatchGroup*)this)->*lib->b)

#define ColorSwatchGroupCallR(a, b)			ColorSwatchGroupLibrary *lib = CheckColorSwatchGroupLibrary(LIBOFFSET(ColorSwatchGroupLibrary, b)); \
																																						if (!lib || !lib->b) return a; \
																																						return (((iColorSwatchGroup*)this)->*lib->b)

ColorSwatchGroup* ColorSwatchGroup::Alloc(const String& name, Bool selected, const ColorAlphaArray& colors)
{
	ColorSwatchGroupLibrary* lib = CheckColorSwatchGroupLibrary(LIBOFFSET(ColorSwatchGroupLibrary, Alloc));
	if (!lib)
		return nullptr;
	return lib->Alloc(name, selected, colors);
}

void ColorSwatchGroup::Free(ColorSwatchGroup *&p)
{
	if (!p)
		return;
	ColorSwatchGroupLibrary* lib = CheckColorSwatchGroupLibrary(LIBOFFSET(ColorSwatchGroupLibrary, Free));
	if (!lib)
		return;
	lib->Free(p);
	p = nullptr;
}

Bool ColorSwatchGroup::Merge(ColorSwatchGroup* group)
{
	ColorSwatchGroupCallR(false, Merge)(group);
}

Bool ColorSwatchGroup::CopyFrom(ColorSwatchGroup* group)
{
	ColorSwatchGroupCallR(false, CopyFrom)(group);
}

String ColorSwatchGroup::GetName() const
{
	ColorSwatchGroupCallR(nullptr, GetName)();
}

void ColorSwatchGroup::SetName(String name)
{
	ColorSwatchGroupCall(SetName)(name);
}

Int ColorSwatchGroup::GetColorCount() const
{
	ColorSwatchGroupCallR(0, GetColorCount)();
}

Bool ColorSwatchGroup::GetColor(Int index, maxon::ColorA& color, Bool* selected) const
{
	ColorSwatchGroupCallR(false, GetColor)(index, color, selected);
}

maxon::ColorA* ColorSwatchGroup::GetColorEditable(Int index, Bool* selected)
{
	ColorSwatchGroupCallR(nullptr, GetColorEditable)(index, selected);
}

Bool ColorSwatchGroup::GetColors(ColorAlphaArray& colors, Bool selectedOnly) const
{
	ColorSwatchGroupCallR(false, GetColors)(colors, selectedOnly);
}

Bool ColorSwatchGroup::SetColor(Int index, const maxon::ColorA& color, Int selected)
{
	ColorSwatchGroupCallR(false, SetColor)(index, color, selected);
}

Int ColorSwatchGroup::AddColor(const maxon::ColorA& color, Bool active, Int insertAt)
{
	ColorSwatchGroupCallR(-1, AddColor)(color, active, insertAt);
}

Int ColorSwatchGroup::AddColors(const ColorAlphaArray& colors, Bool active, Bool merge, Int insertAt)
{
	ColorSwatchGroupCallR(-1, AddColors)(colors, active, merge, insertAt);
}

Bool ColorSwatchGroup::RemoveColor(Int index, Int removeCount)
{
	ColorSwatchGroupCallR(false, RemoveColor)(index, removeCount);
}

Bool ColorSwatchGroup::RemoveSelectedColors()
{
	ColorSwatchGroupCallR(false, RemoveSelectedColors)();
}

Bool ColorSwatchGroup::HasDuplicatedColors() const
{
	ColorSwatchGroupCallR(false, HasDuplicatedColors)();
}

Bool ColorSwatchGroup::RemoveDuplicatedColors()
{
	ColorSwatchGroupCallR(false, RemoveDuplicatedColors)();
}

void ColorSwatchGroup::InvertSelection()
{
	ColorSwatchGroupCall(InvertSelection)();
}

Bool ColorSwatchGroup::SelectColor(Int index, Bool selected)
{
	ColorSwatchGroupCallR(false, SelectColor)(index, selected);
}

Bool ColorSwatchGroup::IsColorSelected(Int index) const
{
	ColorSwatchGroupCallR(false, IsColorSelected)(index);
}

void ColorSwatchGroup::SelectGroup(Bool select)
{
	ColorSwatchGroupCall(SelectGroup)(select);
}

Bool ColorSwatchGroup::IsGroupSelected() const
{
	ColorSwatchGroupCallR(false, IsGroupSelected)();
}

void ColorSwatchGroup::Reset()
{
	ColorSwatchGroupCall(Reset)();
}

void ColorSwatchGroup::SortColors()
{
	ColorSwatchGroupCall(SortColors)();
}
