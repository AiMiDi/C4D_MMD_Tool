#ifndef CODE_EXCHANGE_H__
#define CODE_EXCHANGE_H__

#include "maxon/interface.h"
#include "maxon/datadictionary.h"
#include "maxon/registrybase.h"
#include "maxon/objectbase.h"

class	SubDialog;

namespace maxon
{

class	PythonElementScriptRef;


//----------------------------------------------------------------------------------------
/// Contains supported language by the Code Exchanger
//----------------------------------------------------------------------------------------
namespace CodeExchangerLanguageId
{
	// Python language for Code Exchanger
	MAXON_ATTRIBUTE(Id, Python, "net.maxon.python.codeexchangerlanguageid.python");
}

//----------------------------------------------------------------------------------------
/// Handles communication of codes from Cinema 4D to IDE and vice versa.
//----------------------------------------------------------------------------------------
class CodeExchangerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CodeExchangerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.codeexchanger");
public:

	//----------------------------------------------------------------------------------------
	/// @brief Starts the service that send and receive code in Cinema 4D.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Start();

	//----------------------------------------------------------------------------------------
	/// @brief Stops the service that send and receive code in Cinema 4D.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Stop();

	//----------------------------------------------------------------------------------------
	/// @brief Returns the Code Exchanger running state.
	/// @return	true if the Code Exchanger is in a state that can send or receive code otherwise, false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsRunning();

	//----------------------------------------------------------------------------------------
	/// @brief Send the given Python Script to the IDE.
	/// @param[in] script						The Python script to send.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendScriptToIDE(const PythonElementScriptRef& script);

	//----------------------------------------------------------------------------------------
	/// @brief Send a string to be displayed in the IDE console.
	/// @param[in] content						The string to send in the IDE console.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendConsoleOutput(const String& content);

	//----------------------------------------------------------------------------------------
	/// @brief Defines which language the code exchanger should be used
	/// @return The ID representing the used language, see maxon::CodeExchangerLanguageId
	//----------------------------------------------------------------------------------------
	MAXON_METHOD InternedId GetLanguage() const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the names of the Code Exchanger.
	/// @note It is used in the Code Exchanger Settings.
	/// @return The name of the current implementation
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetName() const;

	//----------------------------------------------------------------------------------------
	/// @brief Returns the dialog to be displayed in the Code Exchanger Settings.
	/// @return The sub dialog that will handle settings for this code exchanger.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD SubDialog* GetSubDialogSetting() const;
};

#include "code_exchanger1.hxx"

//----------------------------------------------------------------------------------------
/// @brief Retrieves the Code Exchanger that should be used.
/// @detail By default the WebSocket Json Code Exchanger is used but the user can define which one to use 
/// in the Code Exchanger Settings located within the Script Manager menu.
/// @return The Code Exchanger that the user decided to to use.
//----------------------------------------------------------------------------------------
Result<CodeExchangerRef> GetActiveCE();

//----------------------------------------------------------------------------------------
/// @brief Defines the Code Exchanger that should be used.
/// @param[in] ce						The Code Exchanger that should be used.
//----------------------------------------------------------------------------------------
Result<void> StoreActiveCE(CodeExchangerRef ce);


// Registry containing all Code Exchanger classes
MAXON_REGISTRY(Class<CodeExchangerRef>, CodeExchangers, "net.maxon.registry.codeexchanger");

#include "code_exchanger2.hxx"
}


#endif // CODE_EXCHANGE_H__
