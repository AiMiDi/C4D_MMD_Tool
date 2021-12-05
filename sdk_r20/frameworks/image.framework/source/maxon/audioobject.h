#ifndef AUDIOOBJECT_H__
#define AUDIOOBJECT_H__

#include "maxon/datadictionaryobject.h"
#include "maxon/timevalue.h"


namespace maxon
{

class AudioObjectInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(AudioObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.audioobject");
public:

	//----------------------------------------------------------------------------------------
	/// Initializes the object with some sound data.
	/// @param[in] channelCount				Number of sound channels to set.
	/// @param[in] bitsPerChannel			Bits per channel (e.g. 16).
	/// @param[in] sampleRate					Sample Rate.
	/// @param[in] sampleCount				Number of Samples.
	/// @param[in] length							Sound length in Time units.
	/// @param[in] data								Block with the sound data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data);

	//----------------------------------------------------------------------------------------
	/// Return the number of channels.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChannelCount() const;

	//----------------------------------------------------------------------------------------
	/// Return the number of bits per channel.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBitsPerChannel() const;

	//----------------------------------------------------------------------------------------
	/// Return the sample rate in Hz.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Float GetSampleRate() const;

	//----------------------------------------------------------------------------------------
	/// Return the duration/length of the sound in samples.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetSampleCount() const;

	//----------------------------------------------------------------------------------------
	/// Return the length as BaseTime
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TimeValue GetLength() const;

	//----------------------------------------------------------------------------------------
	/// Read only data buffer access
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Char> GetDataPtr() const;
};

#include "audioobject1.hxx"

MAXON_DECLARATION(Class<AudioObjectRef>, AudioObjectClass, "net.maxon.image.class.audioobject");

#include "audioobject2.hxx"


}

#endif // AUDIOOBJECT_H__
