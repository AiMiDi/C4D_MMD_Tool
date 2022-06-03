#ifndef NODESYSTEM_DERIVATION_H__
#define NODESYSTEM_DERIVATION_H__

#include "maxon/nodesystem.h"

namespace maxon
{

namespace nodes
{

//----------------------------------------------------------------------------------------
/// A node system derivation handler defines a set of methods to customize the attribute derivation
/// behavior of node systems. Usually you don't have to bother about this because the default
/// handler is sufficient. However some node templates have to specialize the default behavior
/// for the node systems which they instantiate, for example to define a custom
/// constant value computation.
///
/// To change the handler of a node system a node template has to call MutableRoot::SetDerivationHandler().
//----------------------------------------------------------------------------------------
class NodeSystemDerivationHandlerInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSystemDerivationHandlerInterface, MAXON_REFERENCE_CONST, "net.maxon.node.interface.nodesystemderivationhandler");
public:
	//----------------------------------------------------------------------------------------
	/// Computes the value of the derived attribute attr at the port specified by nesting.
	/// This method is called during validation of derived attributes. The default implementation
	/// just calls attr.DeriveAttributeValue(), but implementations may override this default
	/// behavior.
	/// @param[in] nesting						The last element of nesting if the port for which the attribute value
	///																shall be computed, the previous elements are its enclosing ports
	///																up to the top-level port.
	/// @param[in] attr								The derived attribute whose value shall be computed.
	/// @return												The derived attribute value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Opt<Data>> DeriveAttributeValue(const Block<const Port>& nesting, const DerivedAttribute& attr) const;

	//----------------------------------------------------------------------------------------
	/// Computes the value of the ConstantValue attribute at the given port.
	/// This method is called during validation of derived attributes. The default implementation
	/// returns VALUEMODE::DYNAMIC to indicate that no constant value can be computed.
	/// Implementations may override this default behavior.
	/// @param[in] port								The port for which the constant value shall be computed.
	/// @return												The value of the ConstantValue attribute of the port.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<VALUEMODE, Data>> ComputeConstantValue(const Port& port) const;

	//----------------------------------------------------------------------------------------
	/// Checks if connections from src do dst shall be reported by
	/// PortFunctions::GetConnections when the GET_CONNECTIONS_MODE::DERIVATION_FILTER flag is set.
	/// This method is called by PortFunctions::GetConnections
	/// whenever the source port of a connection has GNODE_FLAGS::DERIVATION_FILTER_SOURCE set,
	/// the target port has GNODE_FLAGS::DERIVATION_FILTER_TARGET set and both ports belong to
	/// instantiations of the same template. Only if this method returns true the connection
	/// will be reported by PortFunctions::GetConnections. This allows to hide connections
	/// which aren't needed, for example because they transport constant values.
	/// @param[in] src								The source port of a connection.
	/// @param[in] dst								The target port of a connection.
	/// @return												True if the connection shall be reported by PortFunctions::GetConnections, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FilterDerivationConnection(const Port& src, const Port& dst) const;
};


#include "nodesystem_derivation1.hxx"


//----------------------------------------------------------------------------------------
/// The base implementation class of NodeSystemDerivationHandler. You can use this class as
/// base class whenever you implement a derivation handler.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeSystemDerivationHandler>, NodeSystemDerivationHandlerBaseClass, "net.maxon.node.class.nodesystemderivationhandlerbase");


#include "nodesystem_derivation2.hxx"


}

} // namespace maxon

#endif // NODESYSTEM_DERIVATION_H__
