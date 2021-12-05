#ifndef ASK_PASSWORD_H__
#define ASK_PASSWORD_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"

namespace maxon
{

class AskPasswordRef;

//----------------------------------------------------------------------------------------
/// TODO: (Thomas) please document.
//----------------------------------------------------------------------------------------
class AskPasswordInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(AskPasswordInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.askpassword");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] text								TODO: (Thomas) please document.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> AskPasswordFromUser(const String& text) const;
};

//----------------------------------------------------------------------------------------
/// TODO: (Thomas) please document.
/// @MAXON_ANNOTATION{nullimpl=true}
//----------------------------------------------------------------------------------------
class AskPasswordMethod
{
	MAXON_INTERFACE_NONVIRTUAL(AskPasswordMethod, MAXON_REFERENCE_NONE, "net.maxon.interface.askpasswordmethod");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] method							TODO: (Thomas) please document.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void Set(const AskPasswordRef& method);

	//----------------------------------------------------------------------------------------
	/// TODO: (Thomas) please document.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const AskPasswordRef& Get();
};

#include "ask_password1.hxx"
#include "ask_password2.hxx"

} // namespace maxon

#endif // ASK_PASSWORD_H__
