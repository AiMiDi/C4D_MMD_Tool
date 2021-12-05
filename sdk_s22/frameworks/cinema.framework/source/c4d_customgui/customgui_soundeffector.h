/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_SOUNDEFFECTOR_H__
#define CUSTOMGUI_SOUNDEFFECTOR_H__

#include "customgui_base.h"
#include "c4d_customdatatype.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "lib_description.h"
#include "customgui_gradient.h"
#include "c4d_objectdata.h"

/// SoundEffectorCustomGui ID. @since R19
#define CUSTOMGUI_SOUNDEFFECTOR				440000256

/// SoundData ID. @since R19
#define CUSTOMDATATYPE_SOUNDEFFECTOR	440000257

/// Sound probe ID. @since R19
#define CUSTOMDATATYPE_SOUNDPROBE			440000258

/// Maximum number of probes. @since R19
#define MAXPROBES 2000


//----------------------------------------------------------------------------------------
/// Represents a probe in a SoundData.
/// @since R19
//----------------------------------------------------------------------------------------
class Probe
{
public:

	/// @name Constructor/Destructor
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Probe() = default;
	
	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	virtual ~Probe() {}

	/// @}

	/// @name Right/left Bottom/Top Values
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the right value of probe in Hertz.
	/// @return												The probe right value in Hertz @em [1...22050].
	//----------------------------------------------------------------------------------------
	Float GetRight() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the left value of probe in Hertz.
	/// @return												The probe left value in Hertz @em [1...22050].
	//----------------------------------------------------------------------------------------
	Float GetLeft() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the bottom value of probe as normalized ratio.
	/// @return												The probe bottom value @em [0...1].
	//----------------------------------------------------------------------------------------
	Float GetBottom() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the top value of probe in normalized ratio.
	/// @return												The probe top value @em [0...1].
	//----------------------------------------------------------------------------------------
	Float GetTop() const;

	//----------------------------------------------------------------------------------------
	/// Sets the right value of probe in Hertz @em [1...22050].
	/// @param[in] right							The right value to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetRight(Float right);

	//----------------------------------------------------------------------------------------
	/// Sets the left value of probe in Hertz @em [1...22050].
	/// @param[in] left								The left value to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetLeft(Float left);

	//----------------------------------------------------------------------------------------
	/// Sets top value of probe as normalized ratio @em [0...1].
	/// @param[in] top								The top value to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetTop(Float top);

	//----------------------------------------------------------------------------------------
	/// Sets bottom value of probe as normalized ratio @em [0...1].
	/// @param[in] bottom							The bottom value to set.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetBottom(Float bottom);

	/// @}

	/// @name Validate
	/// @{

	//----------------------------------------------------------------------------------------
	/// Validates probe dimensions. Swaps Left/Right - Top/Bottom if values are inverted.
	//----------------------------------------------------------------------------------------
	void ValidateDimensions();

	/// @}

	/// @name Calculation Values
	/// @{

	Bool _clamp = true;													///< Set to @formatConstant{true} (default) to limit the output of the probe from @em 0.0 to @em 1.0 and ignore values outside of the range.
	Int32 _colorMode = 0;												///< The color mode.
	Int32 _samplingMode = 0;										///< The probe mode.
	Float _strength = 1.0;											///< Overall strength multiplier for the probe.
	Vector _color = Vector(1.0, 1.0, 1.0);			///< Color of the probe used when the probe's color mode is Custom Color.
	GeData _gradient;														///< Gradient of the probe used when the probe's color mode is Custom Gradient.
	Float _fadePercentage = 0.0; 								///< Fade percentage for decay.
	Bool _freeze = false;												///< Freeze state of the output.
	maxon::BaseArray<Float> _freezeArray;				///< Freeze values of the output.

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// Sound effector data type (@ref CUSTOMDATATYPE_SOUNDEFFECTOR) for SoundEffectorCustomGui.
/// @addAllocFreeAutoAllocNote
/// @since R19
//-------------------------------------------------------------------------------------------------
class SoundEffectorData : public CustomDataType
{
private:

	/// @name Private Constructor/Destructor
	/// @{

	SoundEffectorData();
	~SoundEffectorData();

	/// @}

	
 public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{SoundEffectorData}
	/// @return												@allocReturn{sound effector data}
	//----------------------------------------------------------------------------------------
	static SoundEffectorData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{SoundEffectorDatas}
	/// @param[in,out] pData					@theToDestruct{sound effector data}
	//----------------------------------------------------------------------------------------
	static void Free(SoundEffectorData*& pData);

	/// @}
	
	/// @name Init/Free Sampling
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the sampling functionality of the sound effector data.
	/// @warning Must be called before either Sample() of SampleArray() functions. FreeSampling() must be invoked afterwards.
	/// @param[in] doc								The document.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitSampling(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Frees the memory used for sampling.
	/// @warning Must be invoked after InitSampling() has been called.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FreeSampling();

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies the sound effector data values into the destination sound effector data.
	/// @param[in] pDest							The destination sound effector data data. @callerOwnsPointed{SoundEffectorData}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(SoundEffectorData* pDest);

	/// @}

	/// @name Sample
	/// @{

	//----------------------------------------------------------------------------------------
	/// Samples the sound file using the probes.
	/// @param[in] index							The index of the element to sample.
	/// @param[in] count							The number of elements in the array being sampled.
	/// @param[out] value							The output value.
	/// @param[out] color							The output color.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Sample(Int index, Int count, Float& value, Vector& color);

	//----------------------------------------------------------------------------------------
	/// Samples a subset portion or whole array of elements simultaneously.
	/// @param[in] offset							The offset from the start of the array that sampling start at.
	/// @param[in] count							The number of elements in this subset.
	/// @param[in] totalCount					The total number of elements being sampled.
	/// @param[out] values						The values, should be the same size as @formatParam{count}.
	/// @param[out] colors						The colors, should be the same size as @formatParam{count}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SampleArray(Int offset, Int count, Int totalCount, Float* values, Vector* colors);
	
	//----------------------------------------------------------------------------------------
	/// Samples a subset portion or whole array of elements simultaneously (const version).
	/// @param[in] offset							The offset from the start of the array that sampling start at.
	/// @param[in] count							The number of elements in this subset.
	/// @param[in] totalCount					The total number of elements being sampled.
	/// @param[out] values						The values, should be the same size as @formatParam{count}.
	/// @param[out] colors						The colors, should be the same size as @formatParam{count}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SampleArray(Int offset, Int count, Int totalCount, Float* values, Vector* colors) const;

	/// @}

	/// @name Probes
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a probe.
	/// @param[in] left								The left side of the probe in Hertz @em [1...22050].
	/// @param[in] right							The right side of the probe in Hertz @em [1...22050].
	/// @param[in] top								The top edge of the probe in the range @em [0...1].
	/// @param[in] bottom							The bottom edge of the probe in the range @em [0...1].
	/// @param[in] selected						pass @formatConstant{true} to select the created probe (other probes are not deselected in the operation).
	/// @return												The created probe's index.
	//----------------------------------------------------------------------------------------
	Int CreateProbe(Float left = 1.0, Float right = 22050.0, Float top = 1.0, Float bottom = 0.0, Bool selected = false);
	
	//----------------------------------------------------------------------------------------
	/// Create default probe
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateDefaultProbe();

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of probes owned by the sound effector data.
	/// @return												The probe count.
	//----------------------------------------------------------------------------------------
	Int GetProbeCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the probe at the specified @formatParam{index}.
	/// @param[in] index							The probe index.
	/// @return												The probe, or @formatConstant{nullptr} if the function fails. @theOwnsPointed{SoundEffectorData, probe}
	//----------------------------------------------------------------------------------------
	Probe* GetProbe(Int index) const;

	//----------------------------------------------------------------------------------------
	/// Deletes the probe at the specified @formatParam{index}.
	/// @param[in] index							The index of the probe to delete.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteProbe(Int index);

	//----------------------------------------------------------------------------------------
	/// Updates the probes.
	/// @note Must be called after adjusting any probes left or right values to update the order that the probes are calculated in.
	//----------------------------------------------------------------------------------------
	void UpdateProbeOrder();

	/// @}

	/// @name Range
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the range of the sound effector data.
	/// @warning Only valid if the sound effector data is shown in the sound data GUI.
	/// @param[out] xmin							Assigned the minimum X value.
	/// @param[out] xmax							Assigned the maximum X value.
	/// @param[out] ymin							Assigned the minimum Y value.
	/// @param[out] ymax							Assigned the maximum Y value.
	//----------------------------------------------------------------------------------------
	void GetRange(Float* xmin, Float* xmax, Float* ymin, Float* ymax) const;

	//----------------------------------------------------------------------------------------
	/// Sets the range of the sound effector data.
	/// @warning Only valid if the sound effector data is shown in the sound data GUI.
	/// @param[in] xmin								The minimum X value.
	/// @param[in] xmax								The maximum X value.
	/// @param[in] ymin								The minimum Y value.
	/// @param[in] ymax								The maximum Y value.
	//----------------------------------------------------------------------------------------
	void SetRange(Float xmin, Float xmax, Float ymin, Float ymax);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the blend value for the linear/logarithmic slider.
	/// @return												The blend percentage: @em 0% = linear, @em 100% = log10.
	//----------------------------------------------------------------------------------------
	Float GetLinLog() const;

	//----------------------------------------------------------------------------------------
	/// Sets the the blend value for the linear/logarithmic slider.
	/// @param[in] value							The blend percentage to set: @em 0% = linear, @em 100% = log10.
	//----------------------------------------------------------------------------------------
	void SetLinLog(Float value);

	//----------------------------------------------------------------------------------------
	/// Retrieves the freeze state.
	/// @return												@trueIfOtherwiseFalse{freeze is enabled}
	//----------------------------------------------------------------------------------------
	Bool GetFreeze() const;

	//----------------------------------------------------------------------------------------
	/// Sets the freeze state.
	/// @param[in] freeze							@trueOtherwiseFalse{to enable freeze}
	//----------------------------------------------------------------------------------------
	void SetFreeze(Bool freeze);

	//----------------------------------------------------------------------------------------
	/// Retrieves the global gradient.
	/// @return												The global gradient, or @formatConstant{nullptr} if the function fails. @theOwnsPointed{SoundEffectorData, gradient}
	//----------------------------------------------------------------------------------------
	Gradient* GetGradient() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the global gradient direction.
	/// @return												The global gradient direction: @em 0 for vertical (volume), @em 1 for horizontal (frequency).
	//----------------------------------------------------------------------------------------
	Int32 GetGradientDirection() const;

	//----------------------------------------------------------------------------------------
	/// Sets the global gradient direction.
	/// @param[in] direction					The global gradient direction to set: @em 0 for vertical (volume), @em 1 for horizontal (frequency).
	//----------------------------------------------------------------------------------------
	void SetGradientDirection(Int32 direction);

	//----------------------------------------------------------------------------------------
	/// Check if an FFT Cache is currently up to date.
	/// @param[in] doc								The document.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool IsFFTSamplingCacheDirty(BaseDocument& doc) const;
	/// @}

	/// @name SoundTrack
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the active sound track
	/// @param[in] track							Sound track.
	/// @param[in] doc								The document.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetActiveSoundTrack(CTrack* track, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Retrieves the active sound track.
	/// @param[in] doc								The document.
	/// @return												The active sound track, or @formatConstant{nullptr} if the function fails. @theOwnsPointed{SoundEffectorData, CTrack}
	//----------------------------------------------------------------------------------------
	CTrack* GetActiveSoundTrack(BaseDocument* doc);

	/// @}
};

//----------------------------------------------------------------------------------------
/// SoundData custom GUI (@ref CUSTOMGUI_SOUNDEFFECTOR) for SoundData.
/// @since R19
//----------------------------------------------------------------------------------------
class SoundEffectorCustomGui : public BaseCustomGui<CUSTOMGUI_SOUNDEFFECTOR>
{
private:

	/// @name Private Constructor/Destructor
	/// @{

	SoundEffectorCustomGui();
	~SoundEffectorCustomGui();

	/// @}

public:
	//----------------------------------------------------------------------------------------
	/// Sets the GUI owner that receives the sound track.
	/// @param[in] bl									The GUI owner.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetGUIOwnerOverride(BaseList2D* bl);

	//----------------------------------------------------------------------------------------
	/// Retrieves the GUI owner.
	/// @param[in] doc								The document.
	/// @return												The GUI owner, or @formatConstant{nullptr} if the function fails. @theOwnsPointed{SoundEffectorCustomGui, BaseList2D}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetGUIOwnerOverride(BaseDocument* doc) const;
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iSoundData;
class iSoundDataCustomGui;
class iProbe;

struct CustomGuiSoundDataLib : public BaseCustomGuiLib
{
	iSoundData*					(*SoundData_Alloc											)();
	void								(*SoundData_Free											)(iSoundData*& pData);

	Int									(iSoundData::*CreateProbe							)(Float left, Float right, Float top, Float bottom, Bool selected);
	
	Int									(iSoundData::*GetProbeCount						)() const;
	Probe*							(iSoundData::*GetProbe								)(Int index) const;
	Bool								(iSoundData::*DeleteProbe							)(Int index);
	void								(iSoundData::*UpdateProbeOrder)				();

	void								(iSoundData::*GetRange								)(Float* xmin, Float* xmax, Float* ymin, Float* ymax) const;
	void								(iSoundData::*SetRange								)(Float xmin, Float xmax, Float ymin, Float ymax);
	Bool								(iSoundData::*CopyTo									)(SoundEffectorData* pDest);

	Float								(iSoundData::*GetLinLog								)() const;
	void								(iSoundData::*SetLinLog								)(Float value);

	Bool								(iSoundData::*GetFreeze								)() const;
	void								(iSoundData::*SetFreeze								)(Bool freeze);

	Gradient*						(iSoundData::*GetGradient							)() const;

	Int32								(iSoundData::*GetGradientDirection		)() const;
	void								(iSoundData::*SetGradientDirection		)(Int32 direction);

	Bool								(iSoundData::*InitSampling						)(BaseDocument* doc);
	Bool								(iSoundData::*Sample									)(Int index, Int count, Float& value, Vector& color);
	Bool								(iSoundData::*SampleArray							)(Int offset, Int count, Int totalCount, Float* values, Vector* colors);
	Bool								(iSoundData::*FreeSampling						)();

	Bool								(iSoundData::*SetActiveSoundTrack			)(CTrack* track, BaseDocument* doc);
	CTrack*							(iSoundData::*GetActiveSoundTrack			)(BaseDocument* doc);

	Bool 								(iSoundDataCustomGui::*SetGUIOwnerOverride)(BaseList2D* bl);
	BaseList2D* 				(iSoundDataCustomGui::*GetGUIOwnerOverride)(BaseDocument* doc) const;

	Float								(iProbe::*GetRight)() const;
	Float								(iProbe::*GetLeft)() const;
	Float								(iProbe::*GetBottom)() const;
	Float								(iProbe::*GetTop)() const;

	Bool								(iProbe::*SetRight)(Float right);
	Bool								(iProbe::*SetLeft)(Float left);
	Bool								(iProbe::*SetTop)(Float top);
	Bool								(iProbe::*SetBottom)(Float bottom);
	void								(iProbe::*ValidateDimensions)();
	Bool								(iSoundData::*CreateDefaultProbe			)	(); // R19 SP2
	
	Bool								(iSoundData::*SampleArrayConst)(Int offset, Int count, Int totalCount, Float* values, Vector* colors) const; // R20
	Bool								(iSoundData::*IsFFTSamplingCacheDirty)(BaseDocument& doc) const; // R20
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_SOUNDEFFECTOR_H__
