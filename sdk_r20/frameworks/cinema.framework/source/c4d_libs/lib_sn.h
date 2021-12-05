/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SN_H__
#define LIB_SN_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"

/// @addtogroup group_snlibrary SN
/// @ingroup group_library
/// @{

/// @addtogroup SN_RESULT
/// @ingroup group_enumeration
/// @{
#define SN_OKAY					0					///< Values >= @em 0 means okay.
#define SN_WRONGNUMBER	-1				///< Wrong number.
#define SN_EXPIRED			-2				///< Expired.
#define SN_EXPIRE_14		-100			///< Will expire within @em x days. Set @em x by subtracting it from this constant, i.e. (SN_EXPIRE_14 - @em x).
#define SN_NET					-4				///< NET only serial.
/// @}

/// @addtogroup SNFLAG
/// @ingroup group_enumeration
/// @{
#define SNFLAG_OWN			1			///< Use own SN scheme.
#define SNFLAG_PRIV			2			///< @markPrivate
#define SNFLAG_CLIPID		4			///< @markPrivate
/// @}

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct SNHook
{
	void	*thisptr;
	Int32	flags;

	Int32 (*SN_Check)(SNHook *snhook, const String &c4dsn, const String &sn, Int32 regdate, Int32 curdate);
	const String& (*SN_GetTitle)(SNHook *snhook);
	const Char* (*SN_GetClipID)(SNHook *snhook);
};

//----------------------------------------------------------------------------------------
/// Allows to register a new serial number field in the @C4D serial dialog. @C4D will store the serial with its own.\n
/// Just derive a class and override the virtual functions as necessary. Then create an instance of the class and call Register().\n
/// @b Example:
/// @code
/// const Int32 MY_SERIAL_ID = 8564886;
///
/// class MySerial : public SNHookClass
/// {
/// private:
/// 	const String title;
///
/// public:
/// 	MySerial() : title("My Serial") {}
///
/// 	virtual Int32 SNCheck(const String &c4dsn,const String &sn,Int32 regdate,Int32 curdate)
/// 	{
/// 		// ...
/// 		return SN_WRONGNUMBER;
/// 	}
///
/// 	virtual const String& GetTitle()
/// 	{
/// 		return title;
/// 	}
/// };
///
/// static MySerial* serial = nullptr;
///
/// Bool RegisterMySerial()
/// {
/// 	serial = NewObj(MySerial);
/// 	return serial->Register(MY_SERIAL_ID, SNFLAG_OWN);
/// }
///
/// void FreeMySerial()
/// {
/// 	DeleteObj(serial);
/// }
///
/// // ...
///
/// Bool PluginMessage(Int32 id, void *data)
/// {
/// 	// Use the following lines to set a plugin priority
/// 	switch (id)
/// 	{
/// 	case C4DPL_INIT_SYS:
/// 		if (!g_resource.Init())
/// 			return false;
/// 		// ...
/// 		if (!RegisterMySerial())
/// 			return false;
/// 		return true;
///
/// 	case C4DPL_ENDACTIVITY:
/// 		FreeMySerial(); return true;
///
/// 		// ...
/// 	}
///
/// 	return false;
/// }
/// @endcode
/// @note It is very important to allocate during @ref C4DPL_INIT_SYS as above. Otherwise the serial checking phase is missed.
/// @warning Do not store this class as static.
//----------------------------------------------------------------------------------------
class SNHookClass
{
		SNHook hook;

	public:
		//----------------------------------------------------------------------------------------
		/// Constructor
		//----------------------------------------------------------------------------------------
		SNHookClass();

		//----------------------------------------------------------------------------------------
		/// Registers the serial number.
		/// @param[in] id									@uniquePluginID
		/// @param[in] flags							The flags: @enumerateEnum{SNFLAG}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Register(Int32 id, Int32 flags);

		//----------------------------------------------------------------------------------------
		/// Override and tell @C4D if a given serial number is valid.
		/// @param[in] c4dsn							The current @C4D serial, without the last part of course.
		/// @param[in] sn									The serial that was entered for the plugin.
		/// @param[in] regdate						The date of the registration, or @em 0 if the serial was entered for the first time.\n
		/// 															Given in days, calculated by <tt>date = 365 * (year - 1900) + day_in_year</tt> regardless of leap years.
		/// @param[in] curdate						The current date.
		/// @return												The serial number validity: @enumerateEnum{SN_RESULT}
		//----------------------------------------------------------------------------------------
		virtual Int32 SNCheck(const String &c4dsn, const String &sn, Int32 regdate, Int32 curdate);

		//----------------------------------------------------------------------------------------
		/// Override and return the name of the serial number. This will show up in the serial dialog.
		/// @return												The name of the serial number.
		//----------------------------------------------------------------------------------------
		virtual const String& GetTitle();

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		virtual const Char* GetClipID();
};

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
Bool SN_Register(Int32 id, SNHook *snhook);

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
SNHook *SN_FindHook(Int32 id);

/// SN library ID.
#define LIBRARY_SN	200000008

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SNLib : public C4DLibrary
{
	Bool		(*SN_Register		)(Int32 id, SNHook *snhook);
	SNHook*	(*SN_FindHook		)(Int32 id);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_SN_H__
