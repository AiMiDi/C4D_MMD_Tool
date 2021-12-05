/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_DATETIMEPARSER_H__
#define LIB_DATETIMEPARSER_H__

#ifdef __API_INTERN__
#include "customgui_datetime.h"
#include "ge_string.h"
#else
#include "c4d_library.h"
#include "customgui_datetime.h"
#endif

/// @addtogroup group_datetimeparserlibrary DateTime Parser
/// @ingroup group_library
/// @{

/// DateTime parser library ID.
#define C4D_DATETIMEPARSER_LIBRARY_ID		1025589

/// @addtogroup DATETIMEPARSERMODE
/// @{
enum class DATETIMEPARSERMODE
{
	DATE,			///< Date.
	TIME				///< Time
} MAXON_ENUM_LIST(DATETIMEPARSERMODE);
/// @}

//----------------------------------------------------------------------------------------
/// Class to parse and create date time strings.
/// @addAllocFreeAutoAllocNote
///
/// @b Example:
/// @code
/// AutoAlloc<DateTimeParser> dtp;
///
/// dtp->SetFormatString("YYYY-MM-DD", DATETIMEPARSERMODE::DATE);
/// dtp->SetFormatString("HH:MM:SS", DATETIMEPARSERMODE::TIME);
///
/// String sDateFormat = dtp->GetFormatString(DATETIMEPARSERMODE::DATE);
/// String sTimeFormat = dtp->GetFormatString(DATETIMEPARSERMODE::TIME);
///
/// GePrint(sDateFormat + " " + sTimeFormat);
///
/// DateTime dt;
///
/// dtp->ParseString("110325", dt, DATETIMEPARSERMODE::DATE);
/// dtp->ParseString("54321", dt, DATETIMEPARSERMODE::TIME);
///
/// String sDate = dtp->MakeString(dt, DATETIMEPARSERMODE::DATE);
/// String sTime = dtp->MakeString(dt, DATETIMEPARSERMODE::TIME);
/// GePrint(sDate + " " + sTime);
/// @endcode
//----------------------------------------------------------------------------------------
class DateTimeParser
{
private:
	DateTimeParser() {}
	~DateTimeParser() {}

public:
	// Maybe we need an empty constructor, but we leave them out for now

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{date time parser}
	/// @return												@allocReturn{date time parser}
	//----------------------------------------------------------------------------------------
	static DateTimeParser *Alloc(void);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{date time parsers}
	/// @param[in,out] dtp						@theToDestruct{date time parser}
	//----------------------------------------------------------------------------------------
	static void Free(DateTimeParser *&dtp);

	/// @}

	/// @name Parse/Make String
	/// @{

	//----------------------------------------------------------------------------------------
	/// Parses a date time string.
	/// @param[in] str								The string to parse.
	/// @param[in] result							Assigned the parsed result.
	/// @param[in] mode								The date time mode: @enumerateEnum{DATETIMEPARSERMODE}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ParseString(const String &str, DateTime &result, DATETIMEPARSERMODE mode);

	//----------------------------------------------------------------------------------------
	/// Creates a date time string, e.g. @em "12:24:05" or @em "2011-08-23".
	/// @param[in] dt									The date time to create the string from.
	/// @param[in] mode								The date time mode: @enumerateEnum{DATETIMEPARSERMODE}
	/// @return												The date time string.
	//----------------------------------------------------------------------------------------
	String MakeString(const DateTime &dt, DATETIMEPARSERMODE mode);

	/// @}

	/// @name Format String
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the formating of the time string.
	/// @param[in] sFormat						The formating string, e.g. @em "HH:MM:SS" for time and @em "YYYY-MM-DD" for the date.
	/// @param[in] mode								The date time mode: @enumerateEnum{DATETIMEPARSERMODE}
	//----------------------------------------------------------------------------------------
	void SetFormatString(const String &sFormat, DATETIMEPARSERMODE mode);

	//----------------------------------------------------------------------------------------
	/// Retrieves the current date time formating string.
	/// @param[in] mode								The date time mode: @enumerateEnum{DATETIMEPARSERMODE}
	/// @return												The formating string, e.g. @em "HH:MM:SS" for time and @em "YYYY-MM-DD" for the date.
	//----------------------------------------------------------------------------------------
	String GetFormatString(DATETIMEPARSERMODE mode);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iDateTimeParser;

struct DateTimeParserLibrary : public C4DLibrary
{
//DateTimeParser		(iDateTimeParser::*DateTimeParser)	(void);

	Bool							(iDateTimeParser::*ParseString)			(const String &str, DateTime &result, DATETIMEPARSERMODE mode);
	String						(iDateTimeParser::*MakeString)			(const DateTime &dt, DATETIMEPARSERMODE mode);

	void							(iDateTimeParser::*SetFormatString)	(const String &sFormat, DATETIMEPARSERMODE mode);
	String						(iDateTimeParser::*GetFormatString)	(DATETIMEPARSERMODE mode);

	iDateTimeParser*	(*Alloc)														(void);
	void							(*Free)															(iDateTimeParser *&dtp);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_DATETIMEPARSER_H__
