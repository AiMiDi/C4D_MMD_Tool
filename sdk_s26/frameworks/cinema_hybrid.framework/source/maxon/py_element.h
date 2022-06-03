#ifndef PY_ELEMENT_H__
#define PY_ELEMENT_H__

#include "maxon/object.h"
#include "maxon/url.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/hierarchyobject.h"
#include "maxon/weakrawptr.h"
#include "maxon/factory.h"
#include "maxon/errorbase.h"

#include "maxon/assets.h"
#include "maxon/base_preset_asset.h"
#include "maxon/matrix.h"


#ifdef __CINEMA_HYBRID_REFLECTION_INCLUDE__
#include "lib_description.h"
#include "c4d_baselist.h"
#include "c4d_baselist.h"
#include "maxon/desctranslation.h"
#endif

class Description;
class DescID;
class BaseList2D;
class BaseLink;


namespace maxon
{
class PythonElementBaseRef;

//----------------------------------------------------------------------------------------
/// Represents a elements of any Python part in Cinema 4D
//----------------------------------------------------------------------------------------
class PythonElementBaseInterface : MAXON_INTERFACE_BASES(HierarchyObjectInterface)
{
	MAXON_INTERFACE(PythonElementBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.python_element.base");

public:

	//----------------------------------------------------------------------------------------
	/// Define a custom Name, overriding the name retrieved by default. 
	/// This does not change the actual name of the Python element, only the displayed one.
	/// @param[in] name		The new name. Pass an empty string if you want the default behavior for the Python element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetDisplayedName(const String name);

	//----------------------------------------------------------------------------------------
	/// Retrieve the name to use for displaying this element in the interface. 
	/// This may not be the actual a name of the underlying Python element. 
	/// @return The name to use in the interface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetDisplayedName() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the path of the current python element from the Python Element Tree.
	/// Path is built from current Python Element, looking recursively at parents.
	/// @param[in] stopAt		Element where the path should stop.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetPath(Opt<const PythonElementBaseRef&> stopAt = {}) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the Unique Identifier of the underlying Python Element.
	/// @return The UUID of the Python Element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetUUID() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the python script from the underlying Python Element.
	/// @return The python script.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetScript();

	//----------------------------------------------------------------------------------------
	/// Defines the python script of the underlying Python Element.
	/// @param[in] newScript	The new python script.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetScript(const String& newScript);

	//----------------------------------------------------------------------------------------
	/// Executes the current the underlying Python Element.
	/// @param[in] debug	true if the execution should be done wit python debugging enabled.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute(const Bool debug);
};

//----------------------------------------------------------------------------------------
/// Represents an element embedded in a Cinema 4D scene making use of Python.
//----------------------------------------------------------------------------------------
class PythonElementEmbeddedInterface : MAXON_INTERFACE_BASES(PythonElementBaseInterface)
{
	MAXON_INTERFACE(PythonElementEmbeddedInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.python_element.embedded");

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the BaseLink of the BaseList2D element represented by the current Python element.
	/// @return BaseLink of the represented BaseList2D.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD BaseLink* GetBaseLink();

	//----------------------------------------------------------------------------------------
	/// Retrieves the parameter description of the Python script, the current element is representing
	/// @param[out] param		The parameter description ID of the Python script.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void GetDescID(DescID& param);
};

//----------------------------------------------------------------------------------------
/// Represents a Python script loaded in the Script Manager in Cinema 4D.
//----------------------------------------------------------------------------------------
class PythonElementScriptInterface : MAXON_INTERFACE_BASES(PythonElementBaseInterface)
{
	MAXON_INTERFACE(PythonElementScriptInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.python_element.script");

public:
	//----------------------------------------------------------------------------------------
	/// Display the current script within Cinema 4D Script Manager
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ShowInScriptManager();
};

#include "py_element1.hxx"

Result<PythonElementBaseRef> GetPyElemFromNode(FactoryInterface::ConstPtr factory, BaseList2D* bl);

MAXON_DECLARATION(Class<PythonElementBaseRef>, PythonElementBaseClass, "net.maxon.class.python_element.base");
using PyBaseElementFactoryType = Factory<PythonElementBaseRef(BaseList2D* bl)>;
MAXON_DECLARATION(PyBaseElementFactoryType, PyBaseElementFactory, "net.maxon.factory.python_element.base");

MAXON_DECLARATION(Class<PythonElementEmbeddedRef>, PythonEmbeddedClass, "net.maxon.class.python_element.embedded");
using PyEmbeddedElementFactoryType = Factory<PythonElementEmbeddedRef(BaseList2D* bl, const DescID& parameter)>;
MAXON_DECLARATION(PyEmbeddedElementFactoryType, PyEmbeddedElementFactory, "net.maxon.factory.python_element.embedded");

MAXON_DECLARATION(Class<PythonElementBaseRef>, PythonDirectoryClass, "net.maxon.class.python_element.directory");
using PyDirectoryElementFactoryType = Factory<PythonElementBaseRef(Url dir)>;
MAXON_DECLARATION(PyDirectoryElementFactoryType, PyDirectoryElementFactory, "net.maxon.factory.python_element.directory");

MAXON_DECLARATION(Class<PythonElementScriptRef>, PythonScriptClass, "net.maxon.class.python_element.script");
using PyScriptElementFactoryType = Factory<PythonElementScriptRef(BaseList2D* bl)>;
MAXON_DECLARATION(PyScriptElementFactoryType, PyScriptElementFactory, "net.maxon.factory.python_element.script");

#include "py_element2.hxx"
}
#endif