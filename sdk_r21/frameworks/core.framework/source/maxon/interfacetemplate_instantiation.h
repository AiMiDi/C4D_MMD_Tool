#ifndef INTERFACETEMPLATE_INSTANTIATION_H__
#define INTERFACETEMPLATE_INSTANTIATION_H__

#include "maxon/interfacetemplate.h"

namespace maxon
{

MAXON_INTERFACE_INSTANTIATION(NumberInterface<Float, 8>, "float");

MAXON_DECLARATION(MAXON_MACROARG_TYPE(Class<NumberRef<Float, 8>>), FloatNumberClass, "net.maxon.class.number.float");

#include "interfacetemplate_instantiation1.hxx"
#include "interfacetemplate_instantiation2.hxx"

} // namespace maxon



#endif // INTERFACETEMPLATE_H__
