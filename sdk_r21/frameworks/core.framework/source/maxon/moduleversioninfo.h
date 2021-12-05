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
	MAXON_ATTRIBUTE(maxon::String, MODULENAME, "net.maxon.moduleversioninfo.modulename");

	/// Description of the module.
	MAXON_ATTRIBUTE(maxon::String, DESCRIPTION, "net.maxon.moduleversioninfo.description");

	/// Version number as string
	MAXON_ATTRIBUTE(maxon::String, VERSIONNUMBERSTRING, "net.maxon.moduleversioninfo.versionnumberstring");

	/// Date of the library/module as string
	MAXON_ATTRIBUTE(maxon::String, VERSIONDATE, "net.maxon.moduleversioninfo.versiondate");

	/// Copyright informations
	MAXON_ATTRIBUTE(maxon::String, COPYRIGHT, "net.maxon.moduleversioninfo.copyright");

	/// License informations
	MAXON_ATTRIBUTE(maxon::String, LICENSE, "net.maxon.moduleversioninfo.license");

	/// Automatically generated: Defines in which module the lib is used.
	MAXON_ATTRIBUTE(maxon::BaseArray<maxon::String>, USEDINMODULE, "net.maxon.moduleversioninfo.usedinmodule");
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

#include "moduleversioninfo2.hxx"

}

#endif // MODULEVERSIONINFO_H__
