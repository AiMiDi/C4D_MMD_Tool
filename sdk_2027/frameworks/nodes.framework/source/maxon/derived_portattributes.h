#ifndef DERIVED_PORTATTRIBUTES_H__
#define DERIVED_PORTATTRIBUTES_H__

#include "maxon/fid.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// Type of the PortFlags attribute.
//----------------------------------------------------------------------------------------
enum class PORT_FLAGS
{
	/// No flag set.
	NONE = 0,

	/// The port shall be hidden.
	HIDDEN = 1 << 0,

	/// The port is used for an argument for a TemplateParameter of a node template.
	USED_FOR_TEMPLATE_ARGUMENT = 1 << 1,

	/// The port's type is used to deduce an argument for a TypeTemplateParameter of a downstream input port of a node template.
	USED_FOR_INPUTPORTTYPE_TEMPLATE_ARGUMENT = 1 << 2,

	/// It is required that the port has a constant value.
	CONSTANT = 1 << 3,

	/// The port is a variadic port, possibly with a fixed count (don't confuse with a variadic port instance).
	VARIADIC = 1 << 4,

	/// The port is a true variadic port (don't confuse with a variadic port instance). Set in addition to VARIADIC.
	VARIADIC_TEMPLATE = 1 << 5,

	/// The port inherits nested ports from upstream ports, see InheritNestedPorts.
	INHERITS_NESTED_PORTS = 1 << 6,

	/// The port synthesizes nested ports from downstream ports, see SynthesizeNestedPorts.
	SYNTHESIZES_NESTED_PORTS = 1 << 7,

	/// The port has children (so it's a port bundle or a variadic port).
	HAS_CHILDREN = 1 << 8,

	/// The port is used for an argument for an BundleTemplateParameter of an input port of a node template.
	USED_FOR_INPUTBUNDLE_TEMPLATE_ARGUMENT = 1 << 9,

	/// The port belongs to a chain.
	CHAIN = 1 << 10,

	/// The port is marked with the Dynamic or TransientDynamic attribute.
	DYNAMIC = 1 << 11,

	/// There's a downstream port with dynamic type (see DynamicTypeConstraint) where this port's type may have an influence on.
	USED_FOR_DYNAMIC_TYPE = 1 << 12,

	/// There's a downstream port which has some dependency on the type of the current port, for example a component access input bundle.
	USED_FOR_PORTTYPE_DEPENDENCY = 1 << 13,

	/// Combination of USED_FOR_INPUTPORTTYPE_TEMPLATE_ARGUMENT and USED_FOR_PORTTYPE_DEPENDENCY.
	/// When any of the flags of this mask are set, this means that the type of the current port has an influence on some downstream port.
	/// Then the template argument matching algorithm makes sure that the deduced type of the current port is propagated to inner groups/templates.
	USED_FOR_PORTTYPE_DEPENDENCY_MASK = USED_FOR_INPUTPORTTYPE_TEMPLATE_ARGUMENT | USED_FOR_PORTTYPE_DEPENDENCY,
	
	/// The port's synthesized type is derived from a FixedPortType at the port or one of its downstream ports.
	HAS_FIXED_TYPE = 1 << 14,

	/// The port's value mode is used to deduce an argument for a ValueModeTemplateParameter of a downstream port of a node template.
	USED_FOR_VALUE_MODE_TEMPLATE_ARGUMENT = 1 << 15,

	/// @markPrivate.
	INTERNAL_TYPE_DERIVATION_FLAG1 = 1 << 16

} MAXON_ENUM_FLAGS(PORT_FLAGS);

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the synthesized type of an input or output port.
/// The type is derived from right to left. For ports which have a FixedPortType,
/// the synthesized type is the same as that type. For ports with a variable type
/// such as input ports with a TypeTemplateParameter or a DynamicTypeConstraint
/// the synthesized type is a constraint which defines the minimal requirements for the actual port type.
///
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, SynthesizedType, "synthesizedtype", MAXON_ATTRIBUTE_READONLY);

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the type constraint of an output port.
/// This is only needed in the context of TypeTemplateParameter output ports.
/// The type constraint is derived from left to right. For ports which have a FixedPortType,
/// the type constraint is the same as that type. Otherwise, for ports with a variable type
/// such as output ports with a TypeTemplateParameter the constraint defines the minimal requirements
/// for the actual port type.
///
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, OutputTypeConstraint, "outputtypeconstraint", MAXON_ATTRIBUTE_READONLY);

//----------------------------------------------------------------------------------------
/// This derived attribute tells about the effective type of an input or output port.
/// The value of this attribute is set automatically during validation depending on the port and its connections.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataType, PortType, "type", MAXON_ATTRIBUTE_READONLY);

//----------------------------------------------------------------------------------------
/// The PortFlags attribute is a derived attribute which can be queried at a port to get
/// some information about the port, see PORT_FLAGS.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(PORT_FLAGS, PortFlags, "portflags", MAXON_ATTRIBUTE_READONLY);

} // namespace nodes

} // namespace maxon

#endif // DERIVED_PORTATTRIBUTES_H__
