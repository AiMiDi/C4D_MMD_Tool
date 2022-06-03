#ifndef CODE_EXCHANGE_H__
#define CODE_EXCHANGE_H__

#include "maxon/interface.h"
#include "maxon/datadictionary.h"
#include "maxon/registrybase.h"
#include "maxon/objectbase.h"

namespace maxon
{

class PythonElementScriptRef;


//----------------------------------------------------------------------------------------
/// Contains supported language by the Code Exchange
//----------------------------------------------------------------------------------------
namespace CodeExchangeLanguageId
{
	// Python language for Code Exchange
	MAXON_ATTRIBUTE(Id, Python, "net.maxon.python.codeexchangelanguageid.python");
}

//----------------------------------------------------------------------------------------
/// Manages communication to exchange code from Cinema 4D to IDE
//----------------------------------------------------------------------------------------
class CodeExchangeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CodeExchangeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.codeexchange");
public:

	//----------------------------------------------------------------------------------------
	/// Called when the Code Exchange is enabled in the preference or during the startup of Cinema 4D
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// Called when the Code Exchange is disabled in the preference or during the ending of Cinema 4D
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Stop();

	//----------------------------------------------------------------------------------------
	/// Send the given Python Script to all IDE
	/// @param[in] script						The Python script to send
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendScriptToIDE(const PythonElementScriptRef& script) const;

	//----------------------------------------------------------------------------------------
	/// Send the Python Console to all IDE
	/// @param[in] content						The new line in the Python logger
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendConsoleOutput(const String& content) const;

	//----------------------------------------------------------------------------------------
	/// Defines which language the code exchange should be used
	/// @return The ID representing the used language, see maxon::CodeExchangeLanguageId
	//----------------------------------------------------------------------------------------
	MAXON_METHOD InternedId GetLanguage() const;

	//----------------------------------------------------------------------------------------
	/// Names of the Code Exchange, this will be used in the Cinema 4D preference under the extension entry.
	/// @return The name of the current implementation
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;
};

#include "code_exchange1.hxx"

// Registry containing all Code Exchange classes
MAXON_REGISTRY(Class<CodeExchangeRef>, CodeExchanges, "net.maxon.registry.codeexchange");

// Registry containing all enabled Code Exchange classes. This registry is updated according the user preference.
MAXON_REGISTRY(Class<CodeExchangeRef>, CodeExchangesEnabled, "net.maxon.registry.codeexchange_enabled");

#include "code_exchange2.hxx"
}


#endif // CODE_EXCHANGE_H__