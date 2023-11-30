#ifndef CORENODE_WRAPPER_H__
#define CORENODE_WRAPPER_H__

#include "maxon/nodetemplate.h"
#include "maxon/corenodes.h"

namespace maxon
{

namespace nodes
{


class CoreNodeWrapperInterface : MAXON_INTERFACE_BASES(NodeTemplateInterface)
{
	MAXON_INTERFACE(CoreNodeWrapperInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.node.interface.corenodewrapperclass");
public:
	MAXON_METHOD void SetBase(const NodeTemplate& base);

	MAXON_METHOD Result<void> MapPort(const corenodes::PortId& port, const PathBlock& path);

	MAXON_METHOD Result<void> SetVariadicPort(const PathBlock& port, const Id& count);

	MAXON_FUNCTION Result<void> SetVariadicPort(const InternedId& port, const Id& count = Id())
	{
		return SetVariadicPort(ToSingletonBlock(port), count.IsEmpty() ? port : count);
	}
};


#include "corenode_wrapper1.hxx"

//----------------------------------------------------------------------------------------
/// CoreNodeWrapperLib provides a set of static methods for the creation and management of node systems.
//----------------------------------------------------------------------------------------
class CoreNodeWrapperLib
{
	MAXON_INTERFACE_NONVIRTUAL(CoreNodeWrapperLib, MAXON_REFERENCE_STATIC, "net.maxon.node.interface.corenodewrapperlib");
public:
	using NodeFinalizer = Delegate<Result<void>(const MutableRoot& root, const TemplateArguments& args)>;
	using PortMapping = Delegate<Result<BaseArray<InternedId>>(PORT_DIR dir, const Id& port)>;

	enum class FLAGS
	{
		NONE = 0,
		KEEP_LETTER_CASE = 1,
		NO_ORDERINDEX = 2,
		SETUP_NAMES = 4
	} MAXON_ENUM_FLAGS_CLASS(FLAGS);

	static MAXON_METHOD Result<CoreNodeWrapper> Wrap(const corenodes::CoreNodeFactory& factory);

	static MAXON_METHOD Result<CoreNodeWrapper> Wrap(const corenodes::CoreNodeFactory& factory, PortMapping&& mapping, NodeFinalizer&& nfinalizer, FLAGS flags = FLAGS::NONE);

	static MAXON_METHOD Result<CoreNodeWrapper> Wrap(const corenodes::CoreNode& cls, FLAGS flags = FLAGS::NONE);

	static MAXON_METHOD Result<CoreNodeWrapper> Wrap(const corenodes::CoreNode& cls, PortMapping&& mapping, NodeFinalizer&& nfinalizer, FLAGS flags = FLAGS::NONE);

	static Result<CoreNodeWrapper> Wrap(corenodes::IdOrBuilder&& nodeId, NodeFinalizer&& nfinalizer = NodeFinalizer());

	template <typename CORENODE> static Result<CoreNodeWrapper> Wrap(const Id& coreNodeId, FLAGS flags = FLAGS::NONE)
	{
		iferr_scope;
		corenodes::CoreNode n = corenodes::CreateNode<CORENODE>(coreNodeId) iferr_return;
		return Wrap(n, flags);
	}

	template <typename CORENODE, typename... ARGS> static Result<CoreNodeWrapper> Wrap(const Id& coreNodeId, NodeFinalizer&& nfinalizer, ARGS&&... args)
	{
		iferr_scope;
		corenodes::CoreNode n = corenodes::CreateNode<CORENODE>(coreNodeId, std::forward<ARGS>(args)...) iferr_return;
		return Wrap(n, PortMapping(), std::move(nfinalizer));
	}

	template <typename... T> static Result<CoreNodeWrapper> WrapCoreNodeOverload(const Char* baseId, NodeFinalizer&& nfinalizer = NodeFinalizer())
	{
		return Wrap(corenodes::IdBuilder(baseId).Append<T...>(), std::move(nfinalizer));
	}

	using WrapperFinalizer = Delegate<Result<void>(CoreNodeWrapper& wrapper)>;

	static MAXON_METHOD Result<NodeTemplate> CreateGenericWrapper(const Block<const Id>& topLevelChoices, const InternedId& topLevelSelector, const Block<const InternedId>& nestedSelectors, Bool autoOverloadResolution, WrapperFinalizer&& wfinalizer, NodeFinalizer&& nfinalizer);

	static MAXON_METHOD Result<NodeTemplate> CreateGenericWrapper(const EnumDataType& topLevelChoices, const Block<const Id>& topLevelCoreNodeIds, const InternedId& topLevelSelector, const Block<const InternedId>& nestedSelectors, Bool autoOverloadResolution, WrapperFinalizer&& wfinalizer, NodeFinalizer&& nfinalizer);

	static MAXON_METHOD Result<void> ConfigureDomainPort(const MutablePort& port, corenodes::MicroNode::FLAGS flags);
};

#include "corenode_wrapper2.hxx"

}

}

#endif // CORENODE_WRAPPER_H__
