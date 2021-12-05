/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASESOUND_H__
#define C4D_BASESOUND_H__

#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "ge_math.h"
#include "c4d_basetime.h"
#include "c4d_baselist.h"

class Filename;
class BaseBitmap;
class GeSndInfo;

//----------------------------------------------------------------------------------------
/// Sound sample data.
//----------------------------------------------------------------------------------------
struct SDataEx
{
	Int16 l;			///< Left sound sample.
	Int16 r;			///< Right sound sample.
};

//----------------------------------------------------------------------------------------
/// @C4D sound object.\n
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseSound : public C4DAtom
{
private:
	BaseSound();
	~BaseSound();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{sound object}
	/// @return												@allocReturn{sound object}
	//----------------------------------------------------------------------------------------
	static BaseSound* Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{sound objects}
	/// @param[in] v									@theToDestruct{sound object}
	//----------------------------------------------------------------------------------------
	static void Free(BaseSound*& v);

	/// @}

	/// @name Clone/Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a copy of a BaseSound object.
	/// @return												The cloned sound object, or @formatConstant{nullptr} if failed. @callerOwnsPointed{sound object}
	//----------------------------------------------------------------------------------------
	BaseSound* GetClone(void);

	//----------------------------------------------------------------------------------------
	/// Clones a part of the sound object.
	/// @param[in] start							The start time of the cloned part.
	/// @param[in] stop								The end time of the cloned part.
	/// @param[in] reverse						@formatConstant{true} to revert the cloned part.
	/// @return												The cloned part of the sound object, or @formatConstant{nullptr} if failed. @callerOwnsPointed{sound object}
	//----------------------------------------------------------------------------------------
	BaseSound* GetClonePart(const BaseTime& start, const BaseTime& stop, Bool reverse);

	//----------------------------------------------------------------------------------------
	/// Copy the settings from the object to another BaseSound object.
	/// @param[out] dest							The sound object to copy to. @callerOwnsPointed{sound object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(BaseSound* dest);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates a sound object and allocates memory for it from the given parameters.
	/// @param[in] sample_cnt					The number of samples.
	/// @param[in] frequency					The sample frequency.
	/// @param[in] channel_cnt				The number of sound channels.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(Int sample_cnt, Float frequency, Int32 channel_cnt);

	//----------------------------------------------------------------------------------------
	/// Frees all resources allocated for the sound object and sets the state to the same as after Alloc().
	//----------------------------------------------------------------------------------------
	void FlushAll(void);

	//----------------------------------------------------------------------------------------
	/// Gets the bitmap with the graph of the sound.
	/// @param[in] width							The number of pixels wide to create the bitmap.
	/// @param[in] height							The number of pixels high to create the bitmap.
	/// @param[in] start							The starting time for the leftmost position in the graph.
	/// @param[in] stop								The end time that should be displayed at the rightmost position in the graph.
	/// @return												The bitmap of the sounds graph, or @formatConstant{nullptr} if failed. @callerOwnsPointed{bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop);

	//----------------------------------------------------------------------------------------
	/// Gets the bitmap with the graph of the sound.
	/// @param[in] width							The number of pixels wide to create the bitmap.
	/// @param[in] height							The number of pixels high to create the bitmap.
	/// @param[in] start							The starting time for the leftmost position in the graph.
	/// @param[in] stop								The end time that should be displayed at the rightmost position in the graph.
	/// @param[in] draw_col						The draw color.
	/// @param[in] back_col						The background color.
	/// @return												The bitmap of the sounds graph, or @formatConstant{nullptr} if failed. @callerOwnsPointed{bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetBitmap(Int32 width, Int32 height, const BaseTime& start, const BaseTime& stop, const Vector& draw_col, const Vector& back_col);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	GeListHead* GetMarkerRoot(void);

	//----------------------------------------------------------------------------------------
	/// Retrieves the sound information data of the sound object.
	/// @param[out] info							Assigned the sound information. @callerOwnsPointed{sound information}
	//----------------------------------------------------------------------------------------
	void GetSoundInfo(GeSndInfo* info) const;

	/// @}

	/// @name Load/Save
	/// @{

	//----------------------------------------------------------------------------------------
	/// Loads an audio file.
	/// @note Currently only the @em WAV file format is supported.
	/// @param[in] fn									The name of the file to load.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Load(const Filename& fn);

	//----------------------------------------------------------------------------------------
	/// Saves a sound to an audio file.
	/// @note Currently only the @em WAV file format is supported.
	/// @param[in] fn									The name of the file to save.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Save(const Filename& fn);

	/// @}

	/// @name Get/Set Sample
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a sample at a given sample offset.
	/// @note If the sound is mono then SDataEx::r will be set to the same value as SDataEx::l.\n
	///				If the sound is <i>8</i>-bit then the samples will be scaled to <i>16</i>-bit so the values are always in the range @em -32768 to @em +32767.
	/// @param[in] i									The sample position to get the sample from.
	/// @param[out] data							Assigned the sample data. @callerOwnsPointed{sample data}
	//----------------------------------------------------------------------------------------
	void GetSampleEx(Int32 i, SDataEx* data);

	//----------------------------------------------------------------------------------------
	/// Sets a sample at a given position in the sound.
	/// @note If the sound is mono then the sample is set to the average value of the left and right samples set in SDataEx, (@ref SDataEx::l+@ref SDataEx::r)/@em 2.\n
	///				If the sound is <i>8</i>-bit then the values will be scaled from the <i>16</i>-bit values set in SDataEx.
	/// @param[in] i									The sample position to set.
	/// @param[in] data								The sample data to put into the sound.
	//----------------------------------------------------------------------------------------
	void SetSampleEx(Int32 i, const SDataEx& data);

	/// @}

	/// @name Write/Read
	/// @{

	//----------------------------------------------------------------------------------------
	/// Writes the sound to a hyper file.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WriteIt(HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// Reads the sound from a hyper file.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{hyper file}
	/// @param[in] level							The disklevel of the sound to read.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReadIt(HyperFile* hf, Int32 level);

	/// @}
};

#endif // C4D_BASESOUND_H__
