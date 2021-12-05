#ifndef GRAPH_BASICS_H__
#define GRAPH_BASICS_H__

#include "maxon/datadictionary.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// PORT_DIR indicates the kind of a port or the direction of a connection:
/// - PORT_DIR::INPUT stands for an input port or an incoming connection (from a source).
/// - PORT_DIR::OUTPUT stands for an output port or an outgoing connection (to a target).
///
/// To support loops over those two directions, there are the special values BEGIN and END:
/// @code
/// for (PORT_DIR dir = PORT_DIR::BEGIN; dir != PORT_DIR::END; ++dir)
/// {
/// }
/// @endcode
//----------------------------------------------------------------------------------------
enum class PORT_DIR : Int
{
	INPUT = 0,														///< Input direction, i.e., an input port or an incoming connection.
	OUTPUT = 1,														///< Output direction, i.e., an output port or an outgoing connection.

	BEGIN = 0,														///< The start value for a loop over port directions.
	END = 2																///< The end value for a loop over port directions.
} MAXON_ENUM_LIST(PORT_DIR);


// needed for a loop over port directions, see PORT_DIR
inline PORT_DIR& operator ++(PORT_DIR& dir)
{
	++reinterpret_cast<UnderlyingType<PORT_DIR>&>(dir);
	return dir;
}

//----------------------------------------------------------------------------------------
/// Returns the reverse of the given direction. PORT_DIR::INPUT becomes PORT_DIR::OUTPUT and vice versa.
/// @param[in] dir								A direction.
/// @return												The reverse of dir.
//----------------------------------------------------------------------------------------
inline PORT_DIR Reverse(PORT_DIR dir)
{
	return PORT_DIR(1 - UnderlyingType<PORT_DIR>(dir));
}

//----------------------------------------------------------------------------------------
/// This tuple holds the information for an instance of a variadic port: The Id is the port
/// identifier, and the DataDictionary contains additional parameters for the instance.
//----------------------------------------------------------------------------------------
using VariadicInstance = Tuple<Id, DataDictionary>;

}

#endif // GRAPH_BASICS_H__
