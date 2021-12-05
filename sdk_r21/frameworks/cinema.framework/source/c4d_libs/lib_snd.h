/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SND_H__
#define LIB_SND_H__

#include "c4d_library.h"
#include "c4d_baseplugin.h"

/// @addtogroup group_soundlibrary Sound
/// @ingroup group_library
/// @{

#ifndef _INTERNAL_DEF_SND_

class BaseSound;

//-------------------------------------------------------------------------------------------------
/// A class that describes a sound.
/// @see BaseSound::GetSoundInfo
//-------------------------------------------------------------------------------------------------
class GeSndInfo
{
private:
	Int32	channel_cnt;
	Int32	bits_per_channel;
	Float	sample_rate;
	Int32	sample_cnt;
	Char	*data;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GeSndInfo()
	{
		channel_cnt = 0;
		bits_per_channel = 0;
		sample_rate = 0.0;
		sample_cnt = 0;
		data = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Constructs with a BaseSound.
	/// @param[in] bs									The sound to initialize from.
	//----------------------------------------------------------------------------------------
	explicit GeSndInfo(BaseSound *bs);

	//----------------------------------------------------------------------------------------
	/// Gets the the number of channels.
	/// @return												The number of channels.
	//----------------------------------------------------------------------------------------
	Int32 GetChannelCount(void) const
	{
		return channel_cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of bits per channel.
	/// @return												The number of bits per channel.
	//----------------------------------------------------------------------------------------
	Int32 GetBitsPerChannel(void) const
	{
		return bits_per_channel;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the sample rate.
	/// @return												The sample rate in Hz.
	//----------------------------------------------------------------------------------------
	Float GetSampleRate(void) const
	{
		return sample_rate;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the the duration/length of the sound in samples.
	/// @return												The length of the sound in samples.
	//----------------------------------------------------------------------------------------
	Int32 GetSampleCount(void) const
	{
		return sample_cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the length of the sound as BaseTime.
	/// @return												The length of the sound.
	//----------------------------------------------------------------------------------------
	BaseTime GetLength(void) const
	{
		return BaseTime(GetSampleRate() != 0.0 ? (Float) sample_cnt / GetSampleRate() : 0.0);
	}
};

//----------------------------------------------------------------------------------------
/// A class for playing sounds.
/// @addAllocFreeAutoAllocNote
///
/// Normally one want to use the BaseSound class for the actual sound, as in this example:
/// @code
/// Filename fn;
/// if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, "Load Sound"))
/// 	return false;
///
/// AutoAlloc<BaseSound> sound;
/// if (!sound) return false;
///
/// if (!sound->Load(fn)) return false;
///
/// GeSndInfo sndinfo(sound);
///
/// AutoAlloc<GePlaySnd> playsound;
/// if (!playsound) return false;
///
/// playsound->Open(sound);
/// playsound->Scrub(0, sndinfo.GetLength().Get());
///
/// while(playsound->IsPlaying())
/// {
/// 	GePrint("pos: " + String::FloatToString(playsound->GetPositionEstimate()));
/// }
///
/// playsound->Close();
/// @endcode
//----------------------------------------------------------------------------------------
class GePlaySnd
{

	private:
		GePlaySnd();
		~GePlaySnd();

	public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{GePlaySnd instance}
	/// @return												@allocReturn{GePlaySnd instance}
	//----------------------------------------------------------------------------------------
		static GePlaySnd* Alloc();

		//----------------------------------------------------------------------------------------
		/// @destructsAlloc{GePlaySnd instances}
		/// @param[in,out] data						@theToDestruct{GePlaySnd instance}
		//----------------------------------------------------------------------------------------
		static void Free(GePlaySnd *&data);

	/// @}

	/// @name Miscellaneous
	/// @{

		//----------------------------------------------------------------------------------------
		// Opens an audio device with a single BaseSound.
		//----------------------------------------------------------------------------------------
		/// The audio data referenced by the BaseSound will be kept in memory until Close() is called.
		/// @param[in] snd								The sound to use for playback. @callerOwnsPointed{sound}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Open(const BaseSound *snd);

		//----------------------------------------------------------------------------------------
		/// Opens an audio device with multiple BaseSounds that will be mixed.
		/// The audio data referenced by the BaseSounds will be kept in memory until Close() is called.
		/// @param[in] stream_cnt					The number of sounds to be mixed.
		/// @param[in] streams						The array with the sounds.
		/// @param[in] start_offsets			The array with start time offsets in seconds (this is the audible sound data when @c StartAt(0) is called).
		/// @param[in] max_length					The maximum length of the audio data in seconds (relative to @c StartAt(0)).
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Open(Int32 stream_cnt, const BaseSound** streams, const Float* start_offsets, Float max_length);

		//----------------------------------------------------------------------------------------
		/// Closes the audio device.
		/// @note If the sounds used for Open() have been deleted in the meantime, their audio data will be released.
		//----------------------------------------------------------------------------------------
		void Close(void);

		//----------------------------------------------------------------------------------------
		/// Starts audio output.
		/// @param[in] start							The position relative to the start of the audio data in seconds.
		//----------------------------------------------------------------------------------------
		void StartAt(Float64 start);

		//----------------------------------------------------------------------------------------
		// Starts audio scrubbing (this will automatically stop audio device after duration).
		//----------------------------------------------------------------------------------------
		/// @param[in] start							The position relative to the start of the audio data in seconds.
		/// @param[in] duration						The scrub duration in seconds after which the audio device will be stopped.
		//----------------------------------------------------------------------------------------
		void Scrub(Float64 start, Float64 duration);

		//----------------------------------------------------------------------------------------
		/// Stops audio output.
		//----------------------------------------------------------------------------------------
		void Stop(void);

		//----------------------------------------------------------------------------------------
		/// Checks if the audio device is running
		/// @return												@trueIfOtherwiseFalse{if audio is playing}
		//----------------------------------------------------------------------------------------
		Bool IsPlaying(void);

		//----------------------------------------------------------------------------------------
		/// Gets an estimate audio position.
		/// @return												The currently audible position in seconds.
		//----------------------------------------------------------------------------------------
		Float64 GetPositionEstimate(void);

		//----------------------------------------------------------------------------------------
		/// Sets the playback time scale.
		/// @param[in] scale							The playback scale value: @em 1.0 means real time, @em 2.0 means twice as fast, @em 0.5 means half the speed, @em 0.0 is invalid.
		//----------------------------------------------------------------------------------------
		void SetScale(Float64 scale);

		//----------------------------------------------------------------------------------------
		/// Gets the current playback time scale.
		/// @return												The playback scale value: @em 1.0 means real time, @em 2.0 means twice as fast, @em 0.5 means half the speed, @em 0.0 is invalid.
		//----------------------------------------------------------------------------------------
		Float64 GetScale(void);

};

#else

#define GePlaySnd		GeSndOut

#endif

/// Sound library ID.
#define LIB_SND 1000496

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct GeSndLib : public C4DLibrary
{
		GePlaySnd*	(*Alloc)									();
		void				(*Free)										(GePlaySnd *&data);

		// New audio stuff
		Bool				(GePlaySnd::*Open)				(Int32 stream_cnt, const BaseSound **streams, const Float *start_offsets, Float max_length);
		void				(GePlaySnd::*Close)				();
		void				(GePlaySnd::*StartAt)			(Float64 start);
		void				(GePlaySnd::*Scrub)				(Float64 start, Float64 duration);
		void				(GePlaySnd::*Stop)				();
		Bool				(GePlaySnd::*IsPlaying)		();
		Float64			(GePlaySnd::*GetPositionEstimate)	();

		void				(GePlaySnd::*SetScale)		(Float64 scale);
		Float64			(GePlaySnd::*GetScale)		(void);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_SND_H__
