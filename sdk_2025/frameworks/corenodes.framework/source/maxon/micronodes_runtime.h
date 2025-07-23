#ifndef MICRONODES_RUNTIME_H__
#define MICRONODES_RUNTIME_H__

#include "maxon/range.h"
#include "maxon/viewiterator.h"
#include "maxon/corenodes_helpers.h"

namespace maxon
{

namespace corenodes
{

#ifdef MAXON_TARGET_64BIT
	#define MAXON_LLVM_INT "i64"
#else
	#define MAXON_LLVM_INT "i32"
#endif

#define MAXON_LLVM_LIKELY_0 ", !prof !0"
#define MAXON_LLVM_LIKELY_1 ", !prof !1"

class Context;
class MicroNodeContext;
class FrameData;
class FrameMember;
class NodeHandle;

class MicroNodeRuntime
{
	MAXON_INTERFACE_NONVIRTUAL(MicroNodeRuntime, MAXON_REFERENCE_STATIC, "net.maxon.corenode.interface.runtime");

public:

	//----------------------------------------------------------------------------------------
	/// @brief Adds an execution trace to the currently executed CoreNode.
	///	The #msg support localizable message callback.
	/// The trace will be added to #ctx and can be processed or translated to a user node path after the graph's execution.
	/// @param[in] msg								The message in Error format to allow PartFormatter delegates.
	/// @param[in] portId							Port to which the trace is related. If empty, trace will be recorded for the node itself.
	/// @param[in] ctx								The graph's execution context.
	/// @param[in] microCtx						The CoreNode's execution context.
	/// @return												True if the message was added and no message was set on the node before.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> AddMessage(const Error& msg, const Id& portId, const Context& ctx, const MicroNodeContext& microCtx);

	static MAXON_METHOD const ViewIteratorMember& GetMember(const FrameData& fd, const FrameMember& fm);
};


class Frame;
class FrameImpl;


//----------------------------------------------------------------------------------------
/// FrameData gives access to the runtime storage where members of a Frame are stored during execution.
//----------------------------------------------------------------------------------------
class FrameData
{
public:
	const FrameData* GetParent() const
	{
		return _parent;
	}

	const FrameData* GetAncestor(const Frame& frame) const
	{
		const FrameData* d = this;
		while (d && d->_frame != &frame)
			d = d->_parent;
		return d;
	}

	const FrameData& GetAncestor(Int count) const
	{
		const FrameData* a = this;
		while (--count >= 0)
		{
			a = a->_parent;
		}
		return *a;
	}

	Int GetIndex() const
	{
		return _index;
	}

	Int GetBlockEnd() const
	{
		return _blockEnd;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the data type of the member.
	/// @return												The member's data type.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _count;
	}

	const ViewIteratorMember& GetMember(Int offset) const
	{
		return *reinterpret_cast<const ViewIteratorMember*>(reinterpret_cast<const Char*>(this) + offset);
	}

	template <typename T> T& Get(Int offset)
	{
		return *reinterpret_cast<T*>(reinterpret_cast<Char*>(this) + offset);
	}

	const ViewIteratorMember& GetMember(const FrameMember& fm) const
	{
		return MicroNodeRuntime::GetMember(*this, fm);
	}

	const Frame& GetFrame() const
	{
		return *_frame;
	}

	static constexpr const Char* LLVM_TYPE = "%struct.FrameData = type { %struct.FrameData*, i8*, " MAXON_LLVM_INT ", " MAXON_LLVM_INT " }\n";
	static constexpr Char LLVM_MEMBER_INDEX = '2';
	static constexpr Char LLVM_MEMBER_BLOCK_END = '3';

private:
	FrameData(const FrameData* parent, const Frame* frame) : _parent(parent), _frame(frame)
	{
	}

	~FrameData()
	{
	}

	friend class FrameDataRef;
	friend class FrameImpl;
	friend class FrameDataImpl;

	const FrameData* const _parent;
	const Frame* const _frame;
	Int _index = 0;
	Int _blockEnd = 0;
	Int _count = 0;
};


inline UInt32 ToOffset(PORTACCESS_FLAGS offsetAndFlags)
{
	return UInt32(offsetAndFlags & PORTACCESS_FLAGS::OFFSET_MASK);
}

//----------------------------------------------------------------------------------------
/// MicroNode execution's context data holder. Can be used to access CoreNode level, Variable, ...
//----------------------------------------------------------------------------------------
class MicroNodeContext
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(MicroNodeContext);

public:

	MicroNodeContext() = default;
	~MicroNodeContext() = default;

	explicit MicroNodeContext(const NodeHandle* handle) : _handle(handle)
	{}

	const NodeHandle* GetNodeHandle() const
	{
		return _handle;
	}

private:

	const NodeHandle* const _handle = nullptr;					///< The MicroNode's parent handle. Can be used to access CoreNode level infos.

};

template <Int PORTCOUNT = -1> class DirectVarAccess;

class VarAccess
{
public:

	VarAccess() = delete;

	VarAccess(const Context& ctx, const MicroNodeContext& microCtx, FrameData& frame, const PORTACCESS_FLAGS* offsetsAndFlagsMap, Int count)
		: _frame(&frame), _offsetsAndFlagsMap(offsetsAndFlagsMap), _memberCount(count), _context(&ctx), _microContext(&microCtx)
	{
	}

	Int GetIndex() const
	{
		return _frame->GetIndex();
	}

	const Context& GetContext() const
	{
		return *_context;
	}

	const MicroNodeContext& GetMicroNodeContext() const
	{
		return *_microContext;
	}

	Int GetMemberCount() const
	{
		return _memberCount;
	}

	const ViewIteratorMember& GetMember(ACCESS_INDEX member) const
	{
		return *reinterpret_cast<const ViewIteratorMember*>(reinterpret_cast<const Char*>(_frame) + ToOffset(_offsetsAndFlagsMap[Int(member)]));
	}

	const Generic& GetMemberValue(ACCESS_INDEX member) const
	{
		return *GetMember(member).value;
	}

	Generic& GetMemberValue(ACCESS_INDEX member)
	{
		return MAXON_NONCONST_COUNTERPART(GetMemberValue(member));
	}

	PORTACCESS_FLAGS GetFlags(ACCESS_INDEX member) const
	{
		return _offsetsAndFlagsMap[Int(member)];
	}

	static Int PrivateGetMemberArrayOffset()
	{
		return 0;
	}

	const Char* GetMemberArrayPointer() const
	{
		return (const Char*) this;
	}

	FrameData& GetFrameData() const
	{
		return *_frame;
	}

private:
	template <Int PORTCOUNT> friend class DirectVarAccess;

	FrameData* const _frame = nullptr;
	const PORTACCESS_FLAGS* const _offsetsAndFlagsMap = nullptr; // in addition to flags this contains the offsets (with respect to _frame) of the mapped ViewIteratorMember element of the member array
	const Int _memberCount;
	const Context* const _context = nullptr;
	const MicroNodeContext* const _microContext = nullptr;
};


template <Int PORTCOUNT> class ContainerVarAccess;

template <Int PORTCOUNT> struct DirectVarAccessMembers
{
	ViewIteratorMember array[PORTCOUNT];

	explicit DirectVarAccessMembers(Int cnt)
	{
	}

	static Int GetMemberCount()
	{
		return PORTCOUNT;
	}
};

template <> struct DirectVarAccessMembers<-1>
{
	const Int count;

#if defined(MAXON_COMPILER_CLANG) || defined(MAXON_COMPILER_GCC)
	ViewIteratorMember array[0];
#else
	ViewIteratorMember array[];
#endif

	explicit DirectVarAccessMembers(Int cnt) : count(cnt)
	{
	}

	Int GetMemberCount() const
	{
		return count;
	}
};

template <Int PORTCOUNT> class DirectVarAccess
{
public:
	explicit DirectVarAccess(const VarAccess& access) : _access(&access), _index(access._frame->GetIndex()), _blockEnd(access._frame->GetBlockEnd()), _members(access.GetMemberCount())
	{
		const Int n = _members.GetMemberCount();
		for (Int i = 0; i < n; ++i)
		{
			_members.array[i] = access.GetMember(ACCESS_INDEX(i));
		}
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(DirectVarAccess);

	Int GetIndex() const
	{
		return _index;
	}

	const Context& GetContext() const
	{
		return *_access->_context;
	}

	const MicroNodeContext& GetMicroNodeContext() const
	{
		return *_access->_microContext;
	}

	static Int PrivateGetMemberArrayOffset()
	{
		return offsetof(DirectVarAccess, _members.array);
	}

	const Char* GetMemberArrayPointer() const
	{
		return (const Char*) &_members.array;
	}

	Bool HasValues() const
	{
		return MAXON_LIKELY(_index < _blockEnd);
	}

	template <Bool ENABLE_SIMD> ResultOk<void> Advance(Int from, Int to)
	{
		for (ViewIteratorMember* m = _members.array + from, *end = _members.array + to; m != end; ++m)
		{
			m->Advance<ENABLE_SIMD>();
		}
		++_index;
		return OK;
	}

	Int GetMemberCount() const
	{
		return _members.GetMemberCount();
	}

	PORTACCESS_FLAGS GetFlags(ACCESS_INDEX member) const
	{
		return _access->GetFlags(member);
	}

	const ViewIteratorMember& GetMember(ACCESS_INDEX member) const
	{
		return _members.array[Int(member)];
	}

	static Int GetSize(Int memberCount)
	{
		static_assert(PORTCOUNT == -1);
		return SIZEOF(DirectVarAccess) + memberCount * SIZEOF(ViewIteratorMember);
	}

private:
	const VarAccess* _access;
	Int _index;
	Int _blockEnd;
	DirectVarAccessMembers<PORTCOUNT> _members;
};

#include "micronodes_runtime1.hxx"
#include "micronodes_runtime2.hxx"

}

template <> DestructorPointer GetDestructorPointer<corenodes::FrameData>();

} // namespace maxon

#endif // MICRONODES_RUNTIME_H__
