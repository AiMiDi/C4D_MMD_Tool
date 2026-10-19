#include "maxon/corenode_wrapper.h"

namespace maxon
{

namespace nodes
{

Result<CoreNodeWrapper> CoreNodeWrapperLib::Wrap(corenodes::IdOrBuilder&& nodeId, NodeFinalizer&& nfinalizer)
{
	iferr_scope;
	Id id = nodeId.GetId() iferr_return;
	const corenodes::CoreNodeFactory& n = corenodes::CoreNodes::Get(id);
	if (!n)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION, FormatString("No core node with id @ found.", id));
	return Wrap(n, PortMapping(), std::move(nfinalizer));
}

}

}
