#include "lib_datetimeparser.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

DateTimeParserLibrary* datetimeparser_lib_cache = nullptr;

static DateTimeParserLibrary* CheckDateTimeParserLib(Int32 offset)
{
	return CheckLib<DateTimeParserLibrary>(C4D_DATETIMEPARSER_LIBRARY_ID, offset, datetimeparser_lib_cache);
}

DateTimeParser *DateTimeParser::Alloc()
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, Alloc));
	if (!lib || !lib->Alloc) return nullptr;
	return (DateTimeParser*)lib->Alloc();
}

void DateTimeParser::Free(DateTimeParser *&data)
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, Free));
	if (!lib || !lib->Free) return;
	iDateTimeParser *tmp = (iDateTimeParser*)data;
	lib->Free(tmp);
	data = nullptr;
}

Bool DateTimeParser::ParseString(const String &str, DateTime &result, DATETIMEPARSERMODE mode)
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, ParseString));
	if (!lib || !lib->ParseString) return false;
	return (reinterpret_cast<iDateTimeParser*>(this)->*(lib->ParseString))(str, result, mode);
}

String DateTimeParser::MakeString(const DateTime &dt, DATETIMEPARSERMODE mode)
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, MakeString));
	if (!lib || !lib->MakeString) return String();
	return (reinterpret_cast<iDateTimeParser*>(this)->*(lib->MakeString))(dt, mode);
}

void DateTimeParser::SetFormatString(const String &sFormat, DATETIMEPARSERMODE mode)
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, SetFormatString));
	if (!lib || !lib->SetFormatString) return;
	return (reinterpret_cast<iDateTimeParser*>(this)->*(lib->SetFormatString))(sFormat, mode);
}

String DateTimeParser::GetFormatString(DATETIMEPARSERMODE mode)
{
	DateTimeParserLibrary *lib = CheckDateTimeParserLib(LIBOFFSET(DateTimeParserLibrary, GetFormatString));
	if (!lib || !lib->GetFormatString) return String();
	return (reinterpret_cast<iDateTimeParser*>(this)->*(lib->GetFormatString))(mode);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
