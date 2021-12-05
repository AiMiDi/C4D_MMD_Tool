/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MESSAGEDATA_H__
#define C4D_MESSAGEDATA_H__

#include "c4d_basedata.h"

class String;
class BaseContainer;
class BaseDocument;
class BaseBitmap;

/// @addtogroup PLUGINFLAG_MESSAGE
/// @ingroup group_enumeration
/// @{
/// Message plugin flags.
#define PLUGINFLAG_MESSAGE_SYNCEVENT				(1 << 0)			///< Sync messages will also be received by the message plugin. @since R17.032
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating message plugins.\n
/// Use RegisterMessagePlugin() to register a message plugin.
///
/// Here is an example of a message plugin, which @ref CoreMessage() method is called each @em 100 ms:
/// @code
/// #include "c4d.h"
/// #include "c4d_symbols.h"
///
/// class TimerMessage : public MessageData
/// {
/// 	virtual Int32 GetTimer(void);
/// 	virtual Bool CoreMessage(Int32 id, const BaseContainer &bc);
/// };
///
/// Int32 TimerMessage::GetTimer()
/// {
/// 	return 100;
/// }
///
/// Bool TimerMessage::CoreMessage(Int32 id, const BaseContainer &bc)
/// {
/// 	if (id==MSG_TIMER)
/// 	{
/// 		// Do something
/// 	}
///
/// 	return true;
/// }
///
/// Bool RegisterTimerMessage(void)
/// {
/// 	return RegisterMessagePlugin(1234567, String(), 0, NewObj(TimerMessage));
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class MessageData : public BaseData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to return a time in milliseconds to receive timer messages (@ref MSG_TIMER) with that interval in @ref CoreMessage().\n
	/// This method is queried again after each message.
	/// @return												The timer interval in milliseconds, or @em 0 for no timer messages.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetTimer(void);

	//----------------------------------------------------------------------------------------
	/// Called to receive core messages.
	/// @see The article @link page_core_messages Core Messages@endlink for more information.
	/// @param[in] id									The core message ID: @enumerateEnum{EVMSG}
	/// @param[in] bc									The core message container.
	/// @return												Currently not used.
	//----------------------------------------------------------------------------------------
	virtual Bool CoreMessage(Int32 id, const BaseContainer& bc) = 0;
};

//----------------------------------------------------------------------------------------
/// Registers a message plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.
/// @param[in] info								The info flags: @enumerateEnum{PLUGINFLAG_MESSAGE} @enumerateEnum{PLUGINFLAG}
/// @param[in] dat								The message data instance for the plugin. @C4D takes over the ownership of the pointed message data.
/// @return												@trueIfOtherwiseFalse{the message plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterMessagePlugin(Int32 id, const maxon::String& str, Int32 info, MessageData* dat);

#endif // C4D_MESSAGEDATA_H__
