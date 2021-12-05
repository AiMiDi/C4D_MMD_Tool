/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_COLORCHOOSER_H__
#define LIB_COLORCHOOSER_H__

#include "c4d_library.h"
#include "lib_browser.h"

/// @addtogroup group_colorchooserlibrary ColorChooser Library
/// @ingroup group_library
/// @{

/// ColorChooser library ID.
#define LIB_COLORCHOOSER				1036596

/// ColorSwatchData library ID.
#define LIB_COLORSWATCHDATA			1036600

/// ColorSwatchGroup library ID.
#define LIB_COLORSWATCHGROUP		1036601

enum class SWATCH_CATEGORY
{
	GLOBAL = 0,
	DOCUMENT = 1
} MAXON_ENUM_LIST(SWATCH_CATEGORY);

using ColorAlphaArray = maxon::BaseArray<maxon::ColorA>;

//----------------------------------------------------------------------------------------
/// Converts a RGB @formatParam{color} to string formatted based on the color range defined in @C4D preferences: @ref WPREF_COLOR_RGBRANGE
/// Example: The string result for the color @c Vector(0.45, 0.32, 1.0) will be @em "115, 82, 255" if @ref WPREF_COLOR_RGBRANGE is configured to @ref COLORSYSTEM_RANGE_255.
/// @since R18
/// @param[in] color							The RGB color to convert to string. Its components must be in range [0.0, 1.0].
/// @return												The string representation of the color.
//----------------------------------------------------------------------------------------
String ColorRGBToString(const Vector& color);

//----------------------------------------------------------------------------------------
/// Converts a HSV @formatParam{color} to string.
/// Example: The string result for the color @c Vector(0.45, 0.32, 1.0) will be @em "251.471 &deg;, 68 %, 100 %"
/// @since R18
/// @param[in] color							The HSV color to convert to string. Its components must be in range [0.0, 1.0]. @see RGBToHSV() / HSVToRGB()
/// @return												The string representation of the color.
//----------------------------------------------------------------------------------------
String ColorHSVToString(const Vector& color);

//----------------------------------------------------------------------------------------
/// Converts a RGB float color component in range [0.0, 1.0] to 8-bit (range [0, 255]).
/// @since R18
/// @param[in] colorComponent			The color component to be converted. Must be in range [0.0, 1.0].
/// @return												The converted 8bit color component.
//----------------------------------------------------------------------------------------
Int ColorComponentFloatTo8Bit(Float colorComponent);

//----------------------------------------------------------------------------------------
/// Converts a RGB 8bit color component (range [0, 255]) to float in range [0.0, 1.0].
/// @since R18
/// @param[in] colorComponent			The 8-bit color component to be converted. Must be in range [0, 255].
/// @return												The converted color component in range [0.0, 1.0].
//----------------------------------------------------------------------------------------
Float ColorComponent8BitToFloat(Int colorComponent);

//----------------------------------------------------------------------------------------
/// Converts a RGB float color in range [0.0, 1.0] to 8-bit color (range [0, 255]).
/// @since R18
/// @param[in] floatColor					The color to be converted. Must be in range [0.0, 1.0].
/// @param[out] red								The converted 8-bit red color component.
/// @param[out] green							The converted 8-bit green color component.
/// @param[out] blue							The converted 8-bit blue color component.
//----------------------------------------------------------------------------------------
void ColorFloatTo8Bit(const Vector& floatColor, Int& red, Int& green, Int& blue);

//----------------------------------------------------------------------------------------
/// Converts a RGB 8-bit color (range [0, 255]) to float color in range [0.0, 1.0].
/// @since R18
/// @param[in] red								The 8-bit color component to be converted. Must be in range [0, 255].
/// @param[in] green							The 8-bit color component to be converted. Must be in range [0, 255].
/// @param[in] blue								The 8-bit color component to be converted. Must be in range [0, 255].
/// @return												The converted float color.
//----------------------------------------------------------------------------------------
Vector Color8BitToFloat(Int red, Int green, Int blue);

//----------------------------------------------------------------------------------------
/// Converts a RGB float color component in range [0.0, 1.0] to 16-bit (range [0, 65535]).
/// @since R18
/// @param[in] colorComponent			The color component to be converted. Must be in range [0.0, 1.0].
/// @return												The converted 16-bit color component.
//----------------------------------------------------------------------------------------
Int ColorComponentFloatTo16Bit(Float colorComponent);

//----------------------------------------------------------------------------------------
/// Converts a RGB 16-bit color component (range [0, 65535]) to float in range [0.0, 1.0].
/// @since R18
/// @param[in] colorComponent			The 16-bit color component to be converted. Must be in range [0, 65535].
/// @return												The converted color component in range [0.0, 1.0].
//----------------------------------------------------------------------------------------
Float ColorComponent16BitToFloat(Int colorComponent);

//----------------------------------------------------------------------------------------
/// Converts a RGB float color in range [0.0, 1.0] to 16-bit color (range [0, 65535]).
/// @since R18
/// @param[in] floatColor					The color to be converted. Must be in range [0.0, 1.0].
/// @param[out] red								The converted 16-bit red color component.
/// @param[out] green							The converted 16-bit green color component.
/// @param[out] blue							The converted 16-bit blue color component.
//----------------------------------------------------------------------------------------
void ColorFloatTo16Bit(const Vector& floatColor, Int& red, Int& green, Int& blue);

//----------------------------------------------------------------------------------------
/// Converts a RGB 16-bit color (range [0, 65535]) to float color in range [0.0, 1.0].
/// @since R18
/// @param[in] red								The 8-bit color component to be converted. Must be in range [0, 65535].
/// @param[in] green							The 8-bit color component to be converted. Must be in range [0, 65535].
/// @param[in] blue								The 8-bit color component to be converted. Must be in range [0, 65535].
/// @return												The converted float color.
//----------------------------------------------------------------------------------------
Vector Color16BitToFloat(Int red, Int green, Int blue);

//----------------------------------------------------------------------------------------
/// Converts color Kelvin temperature to RGB value.
/// @since R18
/// @param[in] kelvinDegrees			The Kelvin temperature value in Kelvin degrees. Useful range: [1000.0, 10000.0] &deg;K
/// @param[in] tint								Offsets the color temperature from green (negative value) to magenta (positive value). Set to 0.0 to disable tinting. Value will be clamped to range [-1.0, 1.0].
/// @return												The converted RGB color value.
//----------------------------------------------------------------------------------------
Vector ColorKelvinTemperatureToRGB(Float kelvinDegrees, Float tint = 0.0);

//----------------------------------------------------------------------------------------
/// Generates a Complementary Color Harmony palette from @formatParam{color}. Contains the input color and its opposite color in a Color Wheel.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to false to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyGetComplementary(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates a Split Complementary Color Harmony palette from @formatParam{color}. Contains the input color and the two analogous colors to its complementary color The complementary color is calculated rotating 180&deg; the hue of the original color in HSV space.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyGetSplitComplementary(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates a Tetradric Color Harmony palette. The rectangle or tetradic color scheme uses four colors arranged into two complementary pairs.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyGetTetradic(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates an Analogous Color Harmony palette. Analogous color schemes use colors that are next to each other on the color wheel, i.e. 30&deg; far away.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] colorCount					Number of colors to generate. Because of input color is added as well, the resulting palette will have @formatParam{colorCount} + 1 colors.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyGetAnalogous(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates an Equiangular Color Harmony palette. All colors are evenly arranged around the color wheel.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] colorCount					Number of colors to generate. Because of input color is added as well, the resulting palette will have @formatParam{colorCount} + 1 colors.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyGetEquiangular(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates a palette composed by a defined amount of colors whose hue is separated by a defined angle in HSV color space.
/// @since R18
/// @param[in] color							The color to generate the palette. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] colorCount					Number of colors to generate. Because of input color is added as well, the resulting palette will have @formatParam{colorCount} + 1 colors.
/// @param[in] angle							Rotation angle in radians. @see DegToRad()
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyRotateColor(const Vector& color, Int colorCount, Float angle, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// Generates a palette composed by a defined amount of colors interpolated between @formatParam{color1} and @formatParam{color2} in HSV color space. All 3 HSV values will be interpolated.
/// @since R18
/// @param[in] color1							The first generator color. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] color2							The second generator color. This color will be added to the resulting palette as well, and converted to RYB space if enabled.
/// @param[in] colorCount					Number of colors to generate. Because of the two input colors are added as well, the resulting palette will have @formatParam{colorCount} + 2 colors.
/// @param[in] ryb								Set to @formatConstant{true} to use RYB (red-yellow-blue) HSV space, set to @formatConstant{false} to use RGB (red-green-blue) HSV space. RYB generates visually more nicer palettes, but is less accurate because is smaller that RGB space. This means different RGB values could be converted to the same RYB value.
/// @param[out] palette						List to add generated colors to. Data is preserved.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ColorHarmonyInterpolateColors(const Vector& color1, const Vector& color2, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);

//----------------------------------------------------------------------------------------
/// This class represents a Color Swatch Group.
/// @since R18
//----------------------------------------------------------------------------------------
class ColorSwatchGroup
{
private:
	ColorSwatchGroup() { };
	~ColorSwatchGroup() { };

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{swatch group}
	/// @param[in] name								The name of the group.
	/// @param[in] selected						The selection state of the group.
	/// @param[in] colors							Colors to fill the group with.
	/// @return												@allocReturn{swatch group}
	//----------------------------------------------------------------------------------------
	static ColorSwatchGroup* Alloc(const String& name = String(), Bool selected = false, const ColorAlphaArray& colors = ColorAlphaArray());

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{swatch group}
	/// @param[in] p									@theToDestruct{swatch group}
	//----------------------------------------------------------------------------------------
	static void Free(ColorSwatchGroup *&p);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Merges colors from @formatParam{group}.
	/// @param[in] group							The group to merge colors from.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Merge(ColorSwatchGroup* group);

	//----------------------------------------------------------------------------------------
	/// Copies a group.
	/// @param[in] group							The group to copy from.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(ColorSwatchGroup* group);

	//----------------------------------------------------------------------------------------
	/// Returns the group name.
	/// @return												The group name.
	//----------------------------------------------------------------------------------------
	String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Sets the group name.
	/// @param[in] name								The new group name.
	//----------------------------------------------------------------------------------------
	void SetName(String name);

	//----------------------------------------------------------------------------------------
	/// Returns the number of colors stored in the group.
	/// @return												The number of colors stored in the group.
	//----------------------------------------------------------------------------------------
	Int GetColorCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns the color at the given @formatParam{index}.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @param[out] color							The color value.
	/// @param[out] selected					Optionally this gets the selection status of the color. Set to @formatConstant{nullptr} to ignore.
	/// @return												@trueIfOtherwiseFalse{the color could be accessed}
	//----------------------------------------------------------------------------------------
	Bool GetColor(Int index, maxon::ColorA& color, Bool* selected = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Returns the color at the given @formatParam{index}.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @param[out] selected					Optionally this gets the selection status of the color. Set to @formatConstant{nullptr} to ignore.
	/// @return												A pointer to the color value or @formatConstant{nullptr}. Can be edited without side effects.
	//----------------------------------------------------------------------------------------
	maxon::ColorA* GetColorEditable(Int index, Bool* selected = nullptr);

	//----------------------------------------------------------------------------------------
	/// Gets the colors stored in this group.
	/// @param[in] colors							The list to add the colors to. Stored data is preserved.
	/// @param[in] selectedOnly				Set to @formatConstant{true} to get only the selected colors, set to @formatConstant{false} to get all colors.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetColors(ColorAlphaArray& colors, Bool selectedOnly = false) const;

	//----------------------------------------------------------------------------------------
	/// Edits the color at the given @formatParam{index}.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @param[in] color							The new color value.
	/// @param[in] selected						The new selection status. Possible values are: -1 = keep current selection status unchanged, 0 = unselect, 1 = select.
	/// @return												@trueIfOtherwiseFalse{the color could be changed}
	//----------------------------------------------------------------------------------------
	Bool SetColor(Int index, const maxon::ColorA& color, Int selected = -1);

	//----------------------------------------------------------------------------------------
	/// Adds a new @formatParam{color} to the group.
	/// @param[in] color							The color value.
	/// @param[in] selected						The initial selection state of color.
	/// @param[in] insertAt						The index of the new color (the list size will increase and the existing elements are moved) or -1 to add it to the end of the list.
	/// @return												The index of the new color or -1 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int AddColor(const maxon::ColorA& color, Bool selected = false, Int insertAt = -1);

	//----------------------------------------------------------------------------------------
	/// Adds colors to this group.
	/// @param[in] colors							The list with colors to add to.
	/// @param[in] selected						The initial selection state of added colors.
	/// @param[in] merge							Set to @formatConstant{true} to merge the colors with current group colors. Use @formatParam{insertAt} to define the insertion position. Set to @formatConstant{false} to replace the content of the group.
	/// @param[in] insertAt						If @formatParam{merge} is set to @formatConstant{true}, this is the index to insert the new colors.
	/// @return												The index of the new color or -1 if error.
	//----------------------------------------------------------------------------------------
	Int AddColors(const ColorAlphaArray& colors, Bool selected = false, Bool merge = true, Int insertAt = -1);

	//----------------------------------------------------------------------------------------
	/// Removes all colors in this group.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Removes the color at the given @formatParam{index}.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @param[in] removeCount				Number of colors to be removed. If @formatParam{removeCnt} is higher than what is available at position RemoveColor() will succeed, but will remove only the number of available colors.
	/// @return												@trueIfOtherwiseFalse{the color was successfully removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveColor(Int index, Int removeCount = 1);

	//----------------------------------------------------------------------------------------
	/// Removes all selected colors in the group.
	/// @return												@trueIfOtherwiseFalse{selected colors were successfully removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveSelectedColors();

	//----------------------------------------------------------------------------------------
	/// Checks if the group has duplicated colors.
	/// @return												@trueIfOtherwiseFalse{duplicated colors were found}
	//----------------------------------------------------------------------------------------
	Bool HasDuplicatedColors() const;

	//----------------------------------------------------------------------------------------
	/// Removes duplicated colors in the group.
	/// @return												@trueIfOtherwiseFalse{duplicated colors were found and removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveDuplicatedColors();

	//----------------------------------------------------------------------------------------
	/// Inverts the selected colors, so the currently selected colors will be unselected and vice-versa.
	//----------------------------------------------------------------------------------------
	void InvertSelection();

	//----------------------------------------------------------------------------------------
	/// Selects/unselects the color at the given @formatParam{index}.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @param[in] selected						The new selection status.
	/// @return												@trueIfOtherwiseFalse{the color selection status was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SelectColor(Int index, Bool selected);

	//----------------------------------------------------------------------------------------
	/// Checks if the color at the given @formatParam{index} is selected.
	/// @param[in] index							The index of the color. Must be 0 <= @formatParam{index} < GetColorCount().
	/// @return												@formatConstant{true} if the color is selected, @formatConstant{false} if it is unselected or @formatParam{index} is invalid.
	//----------------------------------------------------------------------------------------
	Bool IsColorSelected(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Selects the group. This will select/unselect the group icon and all colors in the group.
	/// @param[in] select							The new selection status.
	//----------------------------------------------------------------------------------------
	void SelectGroup(Bool select);

	//----------------------------------------------------------------------------------------
	/// Checks if the group is selected.
	/// @return												@trueIfOtherwiseFalse{the group is selected}
	//----------------------------------------------------------------------------------------
	Bool IsGroupSelected() const;

	//----------------------------------------------------------------------------------------
	/// Sorts colors in the group based in their HSV values.
	//----------------------------------------------------------------------------------------
	void SortColors();
};

//----------------------------------------------------------------------------------------
/// This class handles the Swatch Data stored globally, in a BaseDocument or a preset. It holds 2 kinds of groups:
/// - A global color group that is shared between all @C4D documents and has special methods to handle it.
/// - Document-based color groups stored in a @C4D document.
///
/// @since R18
//----------------------------------------------------------------------------------------
class ColorSwatchData
{
private:
	ColorSwatchData() { };
	~ColorSwatchData() { };

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{swatch data}
	/// @param[in] doc								Optional document to load swatches from.
	/// @param[in] global							If @formatConstant{true} the Global Swatch Group will be loaded.
	/// @return												@allocReturn{swatch data}
	//----------------------------------------------------------------------------------------
	static ColorSwatchData* Alloc(BaseDocument* doc = nullptr, Bool global = false);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{swatch data}
	/// @param[in] p									@theToDestruct{swatch data}
	//----------------------------------------------------------------------------------------
	static void Free(ColorSwatchData *&p);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Loads color groups from the given document and/or global colors.
	/// @param[in] doc								The given document. Can be nullptr if only global colors must be loaded.
	/// @param[in] merge							If @formatConstant{true} the colors are merged with the stored colors. Otherwise the
	/// @param[in] loadGlobalColors		If @formatConstant{true} the global colors are loaded.existing colors are discarded.
	/// @return												@trueIfOtherwiseFalse{success}
	//----------------------------------------------------------------------------------------
	Bool Load(BaseDocument* doc, Bool merge = false, Bool loadGlobalColors = false);

	//----------------------------------------------------------------------------------------
	/// Saves the color groups to the given document and/or the global colors.
	/// @param[in] doc								The document to store the color groups. Can be nullptr if only global colors must be saved.
	/// @param[in] saveGlobalColors		If @formatConstant{true} the global colors are saved.
	/// @return												@trueIfOtherwiseFalse{success}
	//----------------------------------------------------------------------------------------
	Bool Save(BaseDocument* doc, Bool saveGlobalColors = false);

	//----------------------------------------------------------------------------------------
	/// Loads the document-based swatch groups of the first preset with given name found in the user's Color Swatch Preset directory, including subdirectories.
	/// @see GetPresetDirectory()
	/// @param[in] name								The preset name to load.
	/// @param[in] merge							Set to @formatConstant{true} to merge the preset data with current data, set to @formatConstant{false} to replace data.
	/// @return												@trueIfOtherwiseFalse{success}
	//----------------------------------------------------------------------------------------
	Bool LoadPreset(const String& name, Bool merge = true);

	//----------------------------------------------------------------------------------------
	/// Loads the document-based swatch groups of the given preset.
	/// @param[in] url								The preset url.
	/// @param[in] merge							Set to @formatConstant{true} to merge the preset data with current data, set to @formatConstant{false} to replace data.
	/// @return												@trueIfOtherwiseFalse{success}
	//----------------------------------------------------------------------------------------
	Bool LoadPreset(const SDKBrowserURL& url, Bool merge = true);

	//----------------------------------------------------------------------------------------
	/// Saves the document-based groups as a Color Swatch preset.
	/// @param[in] name								The preset name.
	/// @param[in] author							The preset author.
	/// @param[in] info								Preset additional info.
	/// @param[in] forceOverwrite			Set to @formatConstant{true} to force overwriting the preset in case it already exists.
	/// @return												@trueIfOtherwiseFalse{data was saved}
	//----------------------------------------------------------------------------------------
	Bool SavePreset(const String& name, const String& author = String(), const String& info = String(), Bool forceOverwrite = false);

	//----------------------------------------------------------------------------------------
	/// Saves the document-based groups as a Color Swatch preset.
	/// @param[in] url								The url to save preset to. Must include the preset name and must point to an existing library. Example: <tt>SDKBrowserURL presetToSaveURL = ColorSwatchData::GetPresetDirectory() + "MyPreset"</tt>
	/// @param[in] author							The preset author.
	/// @param[in] info								Preset additional info.
	/// @param[in] forceOverwrite			Set to @formatConstant{true} to force overwrite the preset in case it already exists.
	/// @return												@trueIfOtherwiseFalse{data was saved}
	//----------------------------------------------------------------------------------------
	Bool SavePreset(const SDKBrowserURL& url, const String& author = String(), const String& info = String(), Bool forceOverwrite = false);

	//----------------------------------------------------------------------------------------
	/// Checks if any preset with given name exists at user's Color Swatch Preset directory, including subdirectories.
	/// @param[in] name								The preset name.
	/// @param[in] urls								Optionally set here a pointer to an array that will be filled with all urls pointing to a Color Swatch preset with the given name.
	/// @return												@trueIfOtherwiseFalse{any preset with the given name found}
	//----------------------------------------------------------------------------------------
	static Bool PresetExists(const String& name, maxon::BaseArray<SDKBrowserURL>* urls = nullptr);

	//----------------------------------------------------------------------------------------
	/// Checks if the given URL points to a valid Color Swatch preset.
	/// @param[in] url								The url to check.
	/// @return												@trueIfOtherwiseFalse{the URL points to a valid Color Swatch preset}
	//----------------------------------------------------------------------------------------
	static Bool ValidPreset(const SDKBrowserURL& url);

	//----------------------------------------------------------------------------------------
	/// Gets the user's default Color Swatch Preset directory.
	/// @return												The preset directory.
	//----------------------------------------------------------------------------------------
	static SDKBrowserURL GetPresetDirectory();

	//----------------------------------------------------------------------------------------
	/// Merges groups from @formatParam{data}.
	/// @param[in] data								The data to merge groups from.
	/// @param[in] mergeGlobalColors	If @formatConstant{true} the global colors will be merged inside the global group.
	/// @return												@trueIfOtherwiseFalse{successfull}
	//----------------------------------------------------------------------------------------
	Bool Merge(ColorSwatchData* data, Bool mergeGlobalColors = false);

	//----------------------------------------------------------------------------------------
	/// Copies color swatch data.
	/// @param[in] data								Swatch data to copy from.
	/// @return												@trueIfOtherwiseFalse{successfull}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(ColorSwatchData* data);

	//----------------------------------------------------------------------------------------
	/// Returns the number of groups stored in @formatParam{category}.
	/// @param[in] category						The group category.
	/// @return												The number of color groups.
	//----------------------------------------------------------------------------------------
	Int GetGroupCount(SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT) const;

	//----------------------------------------------------------------------------------------
	/// Returns the document-based group at the given @formatParam{index}.
	/// @param[in] index							The @formatParam{index} of the color group. Must be 0 <= @formatParam{index} < GetGroupCount().
	/// @param[in] category						The group category.
	/// @return												The Swatch group or @formatConstant{nullptr}. Swatch data owns the pointed object.
	//----------------------------------------------------------------------------------------
	ColorSwatchGroup* GetGroupAtIndex(Int index, SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT);

	//----------------------------------------------------------------------------------------
	/// Replaces the group at given @formatParam{index}.
	/// @param[in] index							The index of the color group. Must be 0 <= @formatParam{index} < GetGroupCount().
	/// @param[in] group							The group to copy from.
	/// @param[in] category						The group category.
	/// @return												@trueIfOtherwiseFalse{successfull}
	//----------------------------------------------------------------------------------------
	Bool SetGroupAtIndex(Int index, ColorSwatchGroup* group, SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT);

	//----------------------------------------------------------------------------------------
	/// Adds a new document-based group.
	/// @param[in] category						The category where the group will be inserted.
	/// @param[in] name								The name of the new group. If empty the default string "Untitled" will be used.
	/// @param[in] selected						The initial selection state of the new group.
	/// @param[in] insertAt						The index of the new group (the list size will increase and the existing elements are moved) or -1 to add it to the end of the list.
	/// @param[in] colors							Colors to fill the group with.
	/// @return												The new Swatch Group or @formatConstant{nullptr}. @theOwnsPointed{Swatch Data,Swatch Group}
	//----------------------------------------------------------------------------------------
	ColorSwatchGroup* AddGroup(SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT, const String& name = String(), Bool selected = false, Int insertAt = -1, const ColorAlphaArray& colors = ColorAlphaArray());

	//----------------------------------------------------------------------------------------
	/// Adds a group.
	/// @param[in] group							The group to copy from.
	/// @param[in] insertAt						The index of the new group (the list size will increase and the existing elements are moved) or -1 to add it to the end of the list.
	/// @param[in] category						The group category.
	/// @return												@trueIfOtherwiseFalse{successfull}
	//----------------------------------------------------------------------------------------
	Bool InsertGroup(ColorSwatchGroup* group, Int insertAt = -1, SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT);

	//----------------------------------------------------------------------------------------
	/// Removes the group from @formatParam{category} at the given @formatParam{index}.
	/// @param[in] index							The index of the color group. Must be 0 <= @formatParam{index} < GetGroupCount().
	/// @param[in] category						The group category.
	/// @return												@trueIfOtherwiseFalse{the group was successfully removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveGroup(Int index, SWATCH_CATEGORY category = SWATCH_CATEGORY::DOCUMENT);

	//----------------------------------------------------------------------------------------
	/// Removes all selected groups and colors, including selected global colors.
	/// @return												@trueIfOtherwiseFalse{any item was successfully removed}
	//----------------------------------------------------------------------------------------
	Bool RemoveSelectedItems();

	//----------------------------------------------------------------------------------------
	/// Removes all groups and colors, including globals.
	//----------------------------------------------------------------------------------------
	void Reset();

public:
	static const Int32 browserPresetType = 1032074; ///< Color Swatch Browser Preset ID. @see SDKBrowserPluginInterface::GetPluginID()
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iColorSwatchGroup;
struct ColorSwatchGroupLibrary : public C4DLibrary
{
	ColorSwatchGroup*		(*Alloc)(const String& name, Bool selected, const ColorAlphaArray& colors);
	void								(*Free)(ColorSwatchGroup *&p);
	Bool								(iColorSwatchGroup::*Merge)(ColorSwatchGroup* group);
	Bool								(iColorSwatchGroup::*CopyFrom)(ColorSwatchGroup* group);
	String							(iColorSwatchGroup::*GetName)() const;
	void								(iColorSwatchGroup::*SetName)(String name);
	Int									(iColorSwatchGroup::*GetColorCount)() const;
	Bool								(iColorSwatchGroup::*GetColor)(Int index, maxon::ColorA& color, Bool* selected) const;
	maxon::ColorA*			(iColorSwatchGroup::*GetColorEditable)(Int index, Bool* selected);
	Bool								(iColorSwatchGroup::*GetColors)(ColorAlphaArray& colors, Bool selectedOnly) const;
	Bool								(iColorSwatchGroup::*SetColor)(Int index, const maxon::ColorA& color, Int selected);
	Int									(iColorSwatchGroup::*AddColor)(const maxon::ColorA& color, Bool selected, Int insertAt);
	Int									(iColorSwatchGroup::*AddColors)(const ColorAlphaArray& colors, Bool selected, Bool merge, Int insertAt);
	void								(iColorSwatchGroup::*Reset)();
	Bool								(iColorSwatchGroup::*RemoveColor)(Int index, Int removeCount);
	Bool								(iColorSwatchGroup::*RemoveSelectedColors)();
	Bool								(iColorSwatchGroup::*HasDuplicatedColors)() const;
	Bool								(iColorSwatchGroup::*RemoveDuplicatedColors)();
	void								(iColorSwatchGroup::*InvertSelection)();
	Bool								(iColorSwatchGroup::*SelectColor)(Int index, Bool selected);
	Bool								(iColorSwatchGroup::*IsColorSelected)(Int index) const;
	void								(iColorSwatchGroup::*SelectGroup)(Bool select);
	Bool								(iColorSwatchGroup::*IsGroupSelected)() const;
	void								(iColorSwatchGroup::*SortColors)();
};

class iColorSwatchData;
struct ColorSwatchDataLibrary : public C4DLibrary
{
	ColorSwatchData*		(*Alloc)(BaseDocument* doc, Bool global);
	void								(*Free)(ColorSwatchData *&p);
	Bool								(iColorSwatchData::*Load)(BaseDocument* doc, Bool merge, Bool loadGlobalColors);
	Bool								(iColorSwatchData::*Save)(BaseDocument* doc, Bool saveGlobalColors);
	Bool								(iColorSwatchData::*LoadPresetByName)(const String& name, Bool merge);
	Bool								(iColorSwatchData::*LoadPresetByURL)(const SDKBrowserURL& url, Bool merge);
	Bool								(iColorSwatchData::*SavePresetByName)(const String& name, const String& author, const String& info, Bool forceOverwrite);
	Bool								(iColorSwatchData::*SavePresetByURL)(const SDKBrowserURL& url, const String& author, const String& info, Bool forceOverwrite);
	Bool								(*PresetExists)(const String& name, maxon::BaseArray<SDKBrowserURL>* urls);
	Bool								(*ValidPreset)(const SDKBrowserURL& url);
	SDKBrowserURL				(*GetPresetDirectory)();
	Bool								(iColorSwatchData::*Merge)(ColorSwatchData* data, Bool mergeGlobalColors);
	Bool								(iColorSwatchData::*CopyFrom)(ColorSwatchData* data);
	Int									(iColorSwatchData::*GetGroupCount)(Int category) const;
	ColorSwatchGroup*		(iColorSwatchData::*GetGroupAtIndex)(Int index, Int category);
	Bool								(iColorSwatchData::*SetGroupAtIndex)(Int index, ColorSwatchGroup* group, Int category);
	ColorSwatchGroup*		(iColorSwatchData::*AddGroup)(Int category, const String& name, Bool selected, Int insertAt, const ColorAlphaArray& colors);
	Bool								(iColorSwatchData::*InsertGroup)(ColorSwatchGroup* group, Int insertAt, Int category);
	Bool								(iColorSwatchData::*RemoveGroup)(Int index, Int category);
	Bool								(iColorSwatchData::*RemoveSelectedItems)();
	void								(iColorSwatchData::*Reset)();
};

struct ColorUtilsLibrary : public C4DLibrary
{
	String		(*ColorRGBToString)(const Vector& color);
	String		(*ColorHSVToString)(const Vector& color);
	Int				(*ColorComponentFloatTo8Bit)(Float colorComponent);
	Float			(*ColorComponent8BitToFloat)(Int colorComponent);
	void			(*ColorFloatTo8Bit)(const Vector& floatColor, Int& red, Int& green, Int& blue);
	Vector		(*Color8BitToFloat)(Int red, Int green, Int blue);
	Int				(*ColorComponentFloatTo16Bit)(Float colorComponent);
	Float			(*ColorComponent16BitToFloat)(Int colorComponent);
	void			(*ColorFloatTo16Bit)(const Vector& floatColor, Int& red, Int& green, Int& blue);
	Vector		(*Color16BitToFloat)(Int red, Int green, Int blue);
	Vector		(*ColorKelvinTemperatureToRGB)(Float kelvinDegrees, Float tint);
	Bool			(*ColorHarmonyGetComplementary)(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyGetSplitComplementary)(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyGetTetrad)(const Vector& color, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyGetAnalogous)(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyGetEquiangular)(const Vector& color, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyRotateColor)(const Vector& color, Int colorCount, Float angle, Bool ryb, maxon::BaseArray<Vector>& palette);
	Bool			(*ColorHarmonyInterpolateColors)(const Vector& color1, const Vector& color2, Int colorCount, Bool ryb, maxon::BaseArray<Vector>& palette);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_COLORCHOOSER_H__
