#ifndef DERIVED_PORTATTRIBUTES_H__
#define DERIVED_PORTATTRIBUTES_H__

#include "maxon/fid.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the synthesized type of an input or output port.
/// The type is derived from right to left. For ports which have a FixedType,
/// the synthesized type is the same as that type. For ports with a variable type
/// such as input ports with a TypeTemplateParameter or a DynamicTypeConstraint
/// the synthesized type is a constraint which defines the minimal requirements for the actual port type.
///
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, SynthesizedType, "synthesizedtype");

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the type constraint of an output port.
/// This is only needed in the context of TypeTemplateParameter output ports.
/// The type constraint is derived from left to right. For ports which have a FixedType,
/// the type constraint is the same as that type. Otherwise, for ports with a variable type
/// such as output ports with a TypeTemplateParameter the constraint defines the minimal requirements
/// for the actual port type.
///
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, OutputTypeConstraint, "outputtypeconstraint");

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the effective type of an input or output port.
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, PortType, "type");

} // namespace nodes

} // namespace maxon

#endif // DERIVED_PORTATTRIBUTES_H__
