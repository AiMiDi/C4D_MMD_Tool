#ifndef MODULEVERSIONINFO_H__
#define MODULEVERSIONINFO_H__

#include "maxon/datadictionaryobject.h"
#include "maxon/string.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MODULEVERSIONINFO
{
	MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.moduleversioninfo");

	/// Name of the module.
	MAXON_ATTRIBUTE(String, MODULENAME, "net.maxon.moduleversioninfo.modulename");

	/// Description of the module.
	MAXON_ATTRIBUTE(String, DESCRIPTION, "net.maxon.moduleversioninfo.description");

	/// Version number as string
	MAXON_ATTRIBUTE(String, VERSIONNUMBERSTRING, "net.maxon.moduleversioninfo.versionnumberstring");

	/// Date of the library/module as string
	MAXON_ATTRIBUTE(String, VERSIONDATE, "net.maxon.moduleversioninfo.versiondate");

	/// Copyright informations
	MAXON_ATTRIBUTE(String, COPYRIGHT, "net.maxon.moduleversioninfo.copyright");

	/// License informations
	MAXON_ATTRIBUTE(String, LICENSE, "net.maxon.moduleversioninfo.license");

	/// Automatically generated: Defines in which module the lib is used.
	MAXON_ATTRIBUTE(BaseArray<String>, USEDINMODULE, "net.maxon.moduleversioninfo.usedinmodule");
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon
{

//----------------------------------------------------------------------------------------
/// The new ModuleVersionInfos Interface allows to register informations about external libraries/modules and their versions and maybe
/// additional informations. The system automatically detects in which modules the library is used (see zip lib below). This will help in
/// the future to track the used versions of external libs and their licenses.
//----------------------------------------------------------------------------------------
class ModuleVersionInfoInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ModuleVersionInfoInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.moduleversioninfo");

private:
	//----------------------------------------------------------------------------------------
	/// Register allow to add module version informations to the registry. This is for internal use only. Use Register instead.
	/// @param[in] uniqueId						Unique id of the module info. So if it is registered multiple twice because it's used within a header
	///																file it will collect the module dependencies for that module under this id.
	/// @param[in] moduleInfo					Information to store. The dictionary should contains MODULEVERSIONINFO keys.
	/// @param[in] info								ModuleInfo provided by PRIVATE_MAXON_MODULE.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterIntern(const Id& uniqueId, const DataDictionary& moduleInfo, const ModuleInfo& info);

public:
	//----------------------------------------------------------------------------------------
	/// Register allow to add module version informations to the registry.
	/// @param[in] uniqueId						Unique id of the module info. So if it is registered multiple twice because it's used within a header
	///																file it will collect the module dependencies for that module under this id.
	/// @param[in] moduleInfo					Information to store. The dictionary should contains MODULEVERSIONINFO keys.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<void> Register(const Id& uniqueId, const DataDictionary& moduleInfo)
	{
		return RegisterIntern(uniqueId, moduleInfo, PRIVATE_MAXON_MODULE);
	}
};

#include "moduleversioninfo1.hxx"

MAXON_REGISTRY(DataDictionary, ModuleVersionInfos, "net.maxon.registry.moduleversioninfos");

//----------------------------------------------------------------------------------------
/// @brief			ReplaceModule registry allows to renamed dlls/modules.
/// @details		If a module is renamed compared to previous releases this extension point keep record of those changes.
/// For example the "zip" module was renamed to "zipio". So the new "zipio" module will register the zip module 
/// as replacement using this macro MAXON_REPLACE_MODULE("net.maxon.c4d.zip");
///	Please note that you have register the previous Id returned by PRIVATE_MAXON_MODULE.GetBase().GetId().
///	It's possible to register multiple replacements.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Id, ReplaceModule, "net.maxon.registry.replacemodule");

//----------------------------------------------------------------------------------------
/// @brief			Registry point to register renamed dlls/modules.
/// @details		@see ReplaceModule
//----------------------------------------------------------------------------------------
#define MAXON_REPLACE_MODULE(oldname) MAXON_DECLARATION_REGISTER(maxon::ReplaceModule, oldname) { return PRIVATE_MAXON_MODULE.GetBase().GetId(); }

#include "moduleversioninfo2.hxx"

}

#endif // MODULEVERSIONINFO_H__
