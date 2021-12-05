#ifndef DESCRIPTIONPROCESSOR_H__
#define DESCRIPTIONPROCESSOR_H__

#include "maxon/datadescription.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// A DescriptionProcessor processes a resource description, usually in order to derive
/// some object from that description and register it at a registry. The processor to use
/// for a description is directly set in the description (DESCRIPTION::DATA::INFO::PROCESSOR).
//----------------------------------------------------------------------------------------
class DescriptionProcessorInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DescriptionProcessorInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.descriptionprocessor");
public:
	//----------------------------------------------------------------------------------------
	/// Processes a description for which this processor is set.
	/// @param[in] descriptionId			The description identifier.
	/// @param[in] dataDescription		The description.
	/// @return												Some object whose destructor will be called when the description database is unregistered.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const;
};


#include "descriptionprocessor1.hxx"

MAXON_REGISTRY(DescriptionProcessor, DescriptionProcessors, "net.maxon.registry.descriptionprocessors");

#include "descriptionprocessor2.hxx"

}

#endif // DESCRIPTIONPROCESSOR_H__
