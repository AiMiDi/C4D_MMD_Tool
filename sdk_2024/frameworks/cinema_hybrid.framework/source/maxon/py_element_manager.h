#ifndef PY_ELEMENT_MANAGER_H__
#define PY_ELEMENT_MANAGER_H__

#include "maxon/object.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/hierarchyobject.h"
#include "maxon/weakrawptr.h"
#include "maxon/factory.h"
#include "maxon/errorbase.h"

#include "maxon/assets.h"
#include "maxon/base_preset_asset.h"
#include "maxon/matrix.h"

#include "maxon/py_element.h"


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

//----------------------------------------------------------------------------------------
/// Manage Python Elements representing various python elements available in Cinema 4D. 
/// Provides a unified way of dealing with any python elements regardless of their implementation.
//----------------------------------------------------------------------------------------
class PyElementManagerInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(PyElementManagerInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.py_element_manager");

public:
	//----------------------------------------------------------------------------------------
	/// Notify a new object being created and triggers ObservableNewEmbeddedElement after it is inserted in the tree.
	/// @param[in] pyElem The Python Embedded Element to add into the tree.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EmbeddedElementAdded(PythonElementEmbeddedRef pyElem);

	//----------------------------------------------------------------------------------------
	/// Notify a python object being deleted and triggers ObservableDeletedEmbeddedElement before it is removed from the tree.
	/// @param[in] pyElem The Python Embedded Element to add to the tree.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EmbeddedElementRemoved(PythonElementEmbeddedRef pyElem);

	//----------------------------------------------------------------------------------------
	/// Notify a python script being created and triggers ObservableNewScriptElement after it is inserted in the tree.
	/// @param[in] pyElem The Python Script Element to add into the tree.
	/// @param[in] parent An optional parent from the tree for the new Python Script Element added.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ScriptElementAdded(PythonElementBaseRef pyElem, PythonElementBaseRef parent = PythonElementBaseRef::DefaultValue());

	//----------------------------------------------------------------------------------------
	/// Notify a python script being deleted and triggers ObservableDeletedScriptElement before it is removed from the tree.
	/// @param[in] pyElem The Python Script Element to add to the tree.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ScriptElementRemoved(PythonElementBaseRef pyElem);

	//----------------------------------------------------------------------------------------
	/// Find a given Python Element, from a Path (can be a file path, or an URL with a c4dfs scheme)
	/// @param[in] path		The path to search for.
	/// @retun An optional Python Element if found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<PythonElementBaseRef>> FindPyElementByPath(const String path) const;
	
	//----------------------------------------------------------------------------------------
	/// Find a given Python Embedded Element, from a given BaseList2D (can be a ScriptObject, or a regular Python object, like the Python Generator
	/// @param[in] obj		The BaseList2D to search in the tree.
	/// @retun An optional Python Embedded Element if found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<PythonElementBaseRef>> FindPyElementByBaseList2D(const BaseList2D * obj) const;
	
	//----------------------------------------------------------------------------------------
	/// Retrieves the root of the tree, there is always a root. This root contains 2 children PythonElementBasRef, Scripts and Embedded.
	/// @retun The root of all Python Elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PythonElementBaseRef GetRoot() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the root of the tree containing all Python Element representing a Script in the Script Manager.
	/// @retun The Script root of all Python Script Elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD WeakRef<PythonElementBaseRef> GetScriptsRoot() const;
	
	//----------------------------------------------------------------------------------------
	/// Retrieves the root of the tree containing all Python Embedded representing an object in the scene containing some python.
	/// @retun The Script root of all Python Embedded Elements.
	//----------------------------------------------------------------------------------------	
	MAXON_METHOD WeakRef<PythonElementBaseRef> GetEmbeddedRoot() const;

	//----------------------------------------------------------------------------------------
	/// Fired when EmbeddedElementAdded() is called once the python element is inserted into the tree.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableNewEmbeddedElement, (PythonElementEmbeddedRef bl2D), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Fired when NewBaseList2DAdded() is called before the python element is deleted from the tree.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableDeletedEmbeddedElement, (PythonElementEmbeddedRef bl2D), ObservableCombinerRunAllComponent);
	
	//----------------------------------------------------------------------------------------
	/// Fired when ScriptElementAdded() is called once the python script is inserted into the tree.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableNewScriptElement, (PythonElementScriptRef bl2D), ObservableCombinerRunAllComponent);
	
	//----------------------------------------------------------------------------------------
	/// Fired when ScriptElementRemoved() is called before the python script is deleted from the tree.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableDeletedScriptElement, (PythonElementScriptRef bl2D), ObservableCombinerRunAllComponent);
};

#include "py_element_manager1.hxx"

MAXON_DECLARATION(Class<PyElementManagerRef>, PyElementManager, "net.maxon.py_element_manager_interface");

#include "py_element_manager2.hxx"

}
#endif
