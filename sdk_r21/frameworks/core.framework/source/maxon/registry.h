#ifndef REGISTRY_H__
#define REGISTRY_H__

#include "maxon/registrybase.h" // registrybase.h is needed to avoid a dependency on datatype.h from its entities
#include "maxon/datatype.h"

namespace maxon
{

template <typename T, typename P> const T* Registry<T, P>::IteratorBase::operator ->() const
{
	DebugAssert(_iterator->GetEntry().GetType().template Is<T>());
	return _iterator->GetEntry().template GetPtr<T>();
}

} // namespace maxon


#endif // REGISTRY_H__
