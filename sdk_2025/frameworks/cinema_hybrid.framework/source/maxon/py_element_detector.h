#ifndef PY_ELEMENT_DETECTOR_H__
#define PY_ELEMENT_DETECTOR_H__

#include "maxon/object.h"
#include "maxon/factory.h"
#include "maxon/errorbase.h"

#include "maxon/py_element.h"


#ifdef __CINEMA_HYBRID_REFLECTION_INCLUDE__
#include "lib_description.h"
#include "c4d_baselist.h"
#include "maxon/desctranslation.h"
#endif

namespace cinema
{

class DescID;
class BaseList2D;

} // namespace cinema


namespace maxon
{
//----------------------------------------------------------------------------------------
/// Creates PythonElementEmbeddedRef from a given BaseList2D
/// IsValid is first called to check, only if true is returned, 
/// CreatePythonEmbeddedRef will be called to create a new python embedded element to be inserted into the PythonElementManager.
//----------------------------------------------------------------------------------------
class PythonBaseList2DDetectorInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(PythonBaseList2DDetectorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interfaces.python_baselist2d_detector");

public:
	//----------------------------------------------------------------------------------------
	/// Checks that the passed BaseList2D could be interpreted as a PythonElementEmbeddedRef.
	/// @note This method is called for each object Addition/Suppression, so take performance in consideration. 
	/// @param[in] bl2D								The BaseList2D to scan if a Python embedded element can be built upon.
	/// @return												True if the BaseList2D can be interpreted as a PythonElementEmbeddedRef, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsValid(cinema::BaseList2D * bl2D) const;

	// Create one or multiple PythonElementEmbeddedInterface from a BaseList2D
	//----------------------------------------------------------------------------------------
	/// Create one or multiple PythonElementEmbeddedInterface from a BaseList2D.
	/// @param[in] bl2D								The BaseList2D to retrieve a Python embedded element from.
	/// @param[out] out								A ValueReceiver, that should be notified with each embedded python element created from the BaseList2D.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreatePythonEmbeddedRef(cinema::BaseList2D * bl2D, ValueReceiver<PythonElementEmbeddedRef&>& out) const;
};


#include "py_element_detector1.hxx"

MAXON_REGISTRY(PythonBaseList2DDetectorRef, PyBaseList2DDetectors, "net.maxon.registry.python_baselist2d_detector");

#include "py_element_detector2.hxx"

}
#endif // PY_ELEMENT_DETECTOR_H__
