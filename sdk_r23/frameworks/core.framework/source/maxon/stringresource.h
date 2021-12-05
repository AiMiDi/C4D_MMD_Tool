#ifndef STRINGRESOURCE_H__
#define STRINGRESOURCE_H__

#include "maxon/string.h"
#include "maxon/error.h"
#include "maxon/basearray.h"
#include "maxon/observable.h"

namespace maxon
{

class LanguageRef;

//----------------------------------------------------------------------------------------
/// Class that handles string resources.
//----------------------------------------------------------------------------------------
class LanguageInterface
{
	MAXON_INTERFACE_NONVIRTUAL(LanguageInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.language");

public:
	//----------------------------------------------------------------------------------------
	/// Allocator for common use.
	/// @param[in] allocLocation			Source location.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LanguageInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Loads a string from the resource.
	/// @param[in] scope							The resource scope of a resource symbol.
	/// @param[in] keyValue						The value of a resource symbol.
	/// @return												String.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String LoadResourceString(const Id& scope, const InternedId& keyValue);

	//----------------------------------------------------------------------------------------
	/// Returns the real (country-specific) name of a language.
	/// @return												The name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of a language.
	/// @return												The name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Id GetIdentifier() const;

	//----------------------------------------------------------------------------------------
	/// Returns the fallback language of this language.
	/// @return												Nullptr if the language has no fallback language (e.g. "en-US" has none because it's the root of all languages).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD LanguageRef GetFallbackLanguage() const;

	//----------------------------------------------------------------------------------------
	/// @copydoc DefaultDoc::ToString
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const maxon::FormatStatement* fs) const;
};

#define LANGUAGE_ENGLISH_CHR "en-US"
#define LANGUAGE_ENGLISH_STR MAXON_CONCAT(LANGUAGE_ENGLISH_CHR, _s)
static const Id LANGUAGE_ENGLISH_ID = Id(LANGUAGE_ENGLISH_CHR);

//----------------------------------------------------------------------------------------
/// Class that handles resources.
//----------------------------------------------------------------------------------------
class Resource
{
	MAXON_INTERFACE_NONVIRTUAL(Resource, MAXON_REFERENCE_NONE, "net.maxon.interface.resource");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the default language (normally english).
	/// @return												The language.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LanguageRef GetDefaultLanguage();

	//----------------------------------------------------------------------------------------
	/// Returns the language that is currently used.
	/// @return												The language.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LanguageRef GetCurrentLanguage();

	//----------------------------------------------------------------------------------------
	/// Finds for a given identifier (e.g. en-US) the language.
	/// @param[in] identifier					The language Id.
	/// @return												The language.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD LanguageRef FindLanguage(const Id& identifier);

	//----------------------------------------------------------------------------------------
	/// Sets the current language.
	/// @param[in] language						The language.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetCurrentLanguage(const LanguageRef& language);

	//----------------------------------------------------------------------------------------
	/// Retrieves an array of all available languages.
	/// @return												Array with all languages on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<LanguageRef>> GetAllLanguages();

	//----------------------------------------------------------------------------------------
	/// Loads a string from the resource. Other than the member of LanguageRef this
	/// routine tries to load it from the current language first and -if that fails-
	/// from the default language.
	/// @param[in] scope							The resource scope of a resource symbol.
	/// @param[in] keyValue						The value of a resource symbol.
	/// @return												String.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String LoadResourceString(const Id& scope, const InternedId& keyValue);

	MAXON_OBSERVABLE_STATIC(void, ObservableLanguageChanged, (const LanguageRef& oldLanguage, const LanguageRef& newLanguage), ObservableCombinerRunAllComponent);
};

#include "stringresource1.hxx"
#include "stringresource2.hxx"

/// @}

} // namespace maxon

#endif // STRINGRESOURCE_H__
