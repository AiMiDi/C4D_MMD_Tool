#ifndef MICRONODES_RUNTIME_H__
#define MICRONODES_RUNTIME_H__

#include "maxon/range.h"
#include "maxon/viewiterator.h"
#include "maxon/corenodes_helpers.h"
#include "maxon/timestamp.h"

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

class MicroNodeRuntime
{
	MAXON_INTERFACE_NONVIRTUAL(MicroNodeRuntime, MAXON_REFERENCE_NONE, "net.maxon.corenode.interface.runtime");

public:
	static MAXON_METHOD ExecutionTime GetTime(const Context& ctx);

	static MAXON_METHOD void* Alloc(Int size, Context& ctx);

	static MAXON_METHOD void Free(const void* mem, Context& ctx);

	static MAXON_METHOD void AddError(const Error& err, Context& ctx);
};


class Frame;
class FrameImpl;

class FrameData
{
public:
	FrameData* GetParent()
	{
		return _parent;
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

	const ViewIteratorMember& GetMember(Int offset) const
	{
		return *reinterpret_cast<const ViewIteratorMember*>(reinterpret_cast<const Char*>(this) + offset);
	}

	template <typename T> T& Get(Int offset)
	{
		return *reinterpret_cast<T*>(reinterpret_cast<Char*>(this) + offset);
	}

	const Frame& GetFrame() const
	{
		return *_frame;
	}

	static constexpr const Char* LLVM_TYPE = "%struct.FrameData = type { %struct.FrameData*, i8*, " MAXON_LLVM_INT ", " MAXON_LLVM_INT " }\n";
	static constexpr Char LLVM_MEMBER_INDEX = '2';
	static constexpr Char LLVM_MEMBER_BLOCK_END = '3';

private:
	FrameData(FrameData* parent, const Frame* frame) : _parent(parent), _frame(frame), _index(0), _blockEnd(0)
	{
	}

	friend class FrameImpl;
	friend class FrameDataImpl;

	FrameData* _parent;
	const Frame* _frame;
	Int _index;
	Int _blockEnd;
};


class InstructionFilterNode;

class VarAccess
{
public:
	VarAccess(Context& ctx, FrameData& frame, const Int* offsetsMap, const void* userData, const InstructionFilterNode* filter)
		: _frame(&frame), _offsetsMap(offsetsMap), _context(&ctx), _userData(userData), _filter(filter)
	{
	}

	Int GetIndex() const
	{
		return _frame->GetIndex();
	}

	Context& GetContext() const
	{
		return *_context;
	}

	const ViewIteratorMember& GetMember(ACCESS_INDEX member) const
	{
		return *reinterpret_cast<const ViewIteratorMember*>(reinterpret_cast<const Char*>(_frame) + _offsetsMap[Int(member)]);
	}

	static Int PrivateGetMemberArrayOffset()
	{
		return 0;
	}

	const Char* GetMemberArrayPointer() const
	{
		return (const Char*) this;
	}

	Result<void> Validate(const Block<const ACCESS_INDEX>& ports) const;

	const InstructionFilterNode* GetFilter() const
	{
		return _filter;
	}

	const void* GetUserData() const
	{
		DebugAssert(_userData);
		return _userData;
	}

	FrameData& GetFrameData() const
	{
		return *_frame;
	}

private:
	template <Int PORTCOUNT> friend class BatchVarAccess;

	FrameData* const _frame;
	const Int* const _offsetsMap; // contains the offsets (with respect to _frame) of the mapped ViewIteratorMember element of the member array
	Context* const _context;
	const void* _userData;
	const InstructionFilterNode* const _filter;
};


template <Int PORTCOUNT> class ContainerVarAccess;


template <Int PORTCOUNT> class BatchVarAccess
{
public:
	explicit BatchVarAccess(const VarAccess& access) : _access(&access), _context(access._context), _index(access._frame->GetIndex()), _blockEnd(access._frame->GetBlockEnd())
	{
		for (Int i = 0; i < PORTCOUNT; ++i)
		{
			_members[i] = access.GetMember(ACCESS_INDEX(i));
		}
	}

	explicit BatchVarAccess(ENUM_DONT_INITIALIZE) : _access(nullptr)
	{
	}

	BatchVarAccess(const BatchVarAccess&) = default;

	Int GetIndex() const
	{
		return _index;
	}

	Context& GetContext() const
	{
		return *_context;
	}

	static Int PrivateGetMemberArrayOffset()
	{
		return offsetof(BatchVarAccess, _members);
	}

	const Char* GetMemberArrayPointer() const
	{
		return (const Char*) &_members;
	}

	Bool HasValues() const
	{
		return MAXON_LIKELY(_index < _blockEnd);
	}

	template <Bool ENABLE_SIMD> ResultOk<void> Advance(Int from = 0, Int to = PORTCOUNT)
	{
		for (ViewIteratorMember* m = _members + from, *end = _members + to; m != end; ++m)
		{
			m->Advance<ENABLE_SIMD>();
		}
		++_index;
		return OK;
	}

private:
	const VarAccess* _access;
	Context* _context;
	Int _index;
	Int _blockEnd;
	ViewIteratorMember _members[PORTCOUNT];
};

#include "micronodes_runtime1.hxx"
#include "micronodes_runtime2.hxx"

}

} // namespace maxon

#endif // MICRONODES_RUNTIME_H__
