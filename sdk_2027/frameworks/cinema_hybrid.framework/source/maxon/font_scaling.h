#ifndef FONT_SCALING_H__
#define FONT_SCALING_H__

#include "maxon/object.h"
#include "maxon/optional.h"

namespace maxon
{

class OSFontDefinition;

//----------------------------------------------------------------------------------------
/// Provides utilities for querying and scaling font dimensions across platforms.
/// All methods are static and operate on reference font sizes and scale factors.
//----------------------------------------------------------------------------------------
class FontScaling
{
	MAXON_INTERFACE_NONVIRTUAL(FontScaling, MAXON_REFERENCE_STATIC, "net.maxon.interface.fontscaling");

public:
  //----------------------------------------------------------------------------------------
  /// Returns the reference font size used as the baseline for scaling calculations.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Float GetReferenceFontSize();

  //----------------------------------------------------------------------------------------
  /// Returns the reference font height in pixels.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Float GetReferenceFontHeight();

  //----------------------------------------------------------------------------------------
  /// Returns the font height in pixels for the given OS font definition.
  /// @param fontDef            The OS font definition to measure.
  /// @return                   The font height in pixels as an Int32.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Int32 GetFontHeight(const OSFontDefinition& fontDef);

	//----------------------------------------------------------------------------------------
  /// Computes the font scale multiplier based on the optional font size parameter.
  /// @param fontSize           Optional font size override; if omitted, uses the font size defined in preferences.
  /// @return                   The computed scale factor as a Float.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Float GetFontScale(Opt<Float> fontSize = {});

  //----------------------------------------------------------------------------------------
  /// Scales a floating-point dimension value by the computed font scale factor.
  /// @param dimension          The dimension value to scale.
  /// @param fontSize           Optional font size override; if omitted, uses the font size defined in preferences.
  /// @return                   The scaled dimension as a Float.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Float ScaleDimension(Float dimension, Opt<Float> fontSize = {});

  //----------------------------------------------------------------------------------------
  /// Scales an integer dimension value by the computed font scale factor.
  /// @param dimension          The integer dimension value to scale.
  /// @param fontSize           Optional font size override; if omitted, uses the font size defined in preferences.
  /// @return                   The scaled dimension as an Int32.
  //----------------------------------------------------------------------------------------
  static MAXON_METHOD Int32 ScaleDimension(Int32 dimension, Opt<Float> fontSize = {});
};

#include "font_scaling1.hxx"
#include "font_scaling2.hxx"

} // namespace maxon

#endif // FONT_SCALING_H__
