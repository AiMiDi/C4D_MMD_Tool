#include "maxon/jobqueue.h"
#include "c4d_fielddata.h"
#ifdef __API_INTERN__
	#include "world.h"
	#include "ge_sys_thread.h"
#else
	#include "c4d_basedocument.h"
	#include "c4d_thread.h"
#endif

static const UInt FIELDHASHMAX = maxon::LIMIT<UInt>::MAX; // The maximum hash value for the field hash

Bool ValidateFieldOutputBlockWithFlags(const FieldOutputBlock &block, FIELDSAMPLE_FLAG flags)
{
	if (MAXON_UNLIKELY(!block.IsValid()))
		return false;

	const Bool hasValueFlag = true;				// VALUE flag is 0... value array always supposed to exist.
	const Bool hasDeactivatedFlag = true;
	const Bool hasColorFlag = Int32(flags & FIELDSAMPLE_FLAG::COLOR) != 0;
	const Bool hasDirectionFlag = Int32(flags & FIELDSAMPLE_FLAG::DIRECTION) != 0;
	const Bool hasRotationFlag = Int32(flags & FIELDSAMPLE_FLAG::ROTATION) != 0;
	const Bool hasValue = block._value.IsPopulated();
	const Bool hasDeactivated = block._deactivated.IsPopulated();
	const Bool hasColor = block._color.IsPopulated();
	const Bool hasAlpha = block._alpha.IsPopulated();
	const Bool hasDirection = block._direction.IsPopulated();
	const Bool hasRotation = block._rotation.IsPopulated() && block._pivot.IsPopulated();

	// Using xor, if flag is set, we enforce the array to be present to avoid sampling crashes.
	// Also avoid unwanted arrays to not have fields calculate unwanted outputs.
	if (MAXON_UNLIKELY(hasValueFlag ^ hasValue))
		return false;

	if (MAXON_UNLIKELY(hasDeactivatedFlag ^ hasDeactivated))
		return false;

	if (MAXON_UNLIKELY(hasColorFlag ^ hasColor))
		return false;

	if (MAXON_UNLIKELY(hasColorFlag ^ hasAlpha))
		return false;

	if (MAXON_UNLIKELY(hasDirectionFlag ^ hasDirection))
		return false;

	if (MAXON_UNLIKELY(hasRotationFlag ^ hasRotation))
		return false;

	return true;
}

FIELDSAMPLE_FLAG ExtractSampleFlags(const FieldOutputBlock& block)
{
	FIELDSAMPLE_FLAG flags = FIELDSAMPLE_FLAG::VALUE;
	if (block._color.IsPopulated() && block._alpha.IsPopulated())
		flags |= FIELDSAMPLE_FLAG::COLOR;

	if (block._direction.IsPopulated())
		flags |= FIELDSAMPLE_FLAG::DIRECTION;

	if (block._rotation.IsPopulated() && block._pivot.IsPopulated())
		flags |= FIELDSAMPLE_FLAG::ROTATION;

	return flags;
}

maxon::Result<FieldOutputBlock> FieldOutputBlock::GetSubBlock(Int offset, Int blockSize) const
{
	DebugAssert(IsValid());
	
	FieldOutputBlock f;
	if (offset >= _count || offset < 0)
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);

	f._count = Min(_count - offset, blockSize);
	f._offset = _offset + offset;
	f._owner = _owner;

	if (_value.IsPopulated())
		f._value.Set(&_value[offset], f._count);
	if (_alpha.IsPopulated())
		f._alpha.Set(&_alpha[offset], f._count);
	if (_color.IsPopulated())
		f._color.Set(&_color[offset], f._count);
	if (_direction.IsPopulated())
		f._direction.Set(&_direction[offset], f._count);
	if (_rotation.IsPopulated())
		f._rotation.Set(&_rotation[offset], f._count);
	if (_pivot.IsPopulated())
		f._pivot.Set(&_pivot[offset], f._count);
	if (_deactivated.IsPopulated())
		f._deactivated.Set(&_deactivated[offset], f._count);

	return std::move(f);
}

void FieldOutputBlock::Reset()
{
	*this = FieldOutputBlock();
}

void FieldOutputBlock::CopyFrom(const FieldOutputBlock& src)
{
	DebugAssert(IsValid());

	_value = src._value;
	_alpha = src._alpha;
	_color = src._color;
	_direction = src._direction;
	_rotation = src._rotation;
	_pivot = src._pivot;
	_deactivated = src._deactivated;
	_count = src._count;
	_offset = src._offset;
	_owner = src._owner;
}

maxon::Result<void> FieldOutputBlock::CopyArrayContentFrom(const FieldOutputBlock& src)
{
	DebugAssert(IsValid());

	// Determine from the source what needs to be copied.
	const FIELDSAMPLE_FLAG srcFlags = ExtractSampleFlags(src);
	const FIELDSAMPLE_FLAG dstFlags = ExtractSampleFlags(*this);
	const FIELDSAMPLE_FLAG flags = dstFlags & srcFlags;

	// DO NOT MODIFY THE INTERNAL COUNT.
	// Destination block will keep same size, we just copy whatever data we can into it.
	const Int copyCount = Min(src._count, _count);

	if (srcFlags == dstFlags)
	{
		// Clear only the remainder of the memory
		ClearMemory(copyCount, _count - copyCount, false, false);
	}
	else
	{
		// The flags do not match, clear all memory first
		ClearMemory(false, false);
	}
	
	if (copyCount > 0)
	{
		if (MAXON_UNLIKELY(!src._value.IsPopulated() || !src._deactivated.IsPopulated()) || !_value.IsPopulated() || !_deactivated.IsPopulated())
			return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);

		CopyMemType(src._value.GetFirst(), _value.GetFirst(), copyCount);
		CopyMemType(src._deactivated.GetFirst(), _deactivated.GetFirst(), copyCount);

		if (flags & FIELDSAMPLE_FLAG::COLOR)
		{
			CopyMemType(src._alpha.GetFirst(), _alpha.GetFirst(), copyCount);
			CopyMemType(src._color.GetFirst(), _color.GetFirst(), copyCount);
		}

		if (flags & FIELDSAMPLE_FLAG::DIRECTION)
			CopyMemType(src._direction.GetFirst(), _direction.GetFirst(), copyCount);

		if (flags & FIELDSAMPLE_FLAG::ROTATION)
		{
			CopyMemType(src._rotation.GetFirst(), _rotation.GetFirst(), copyCount);
			CopyMemType(src._pivot.GetFirst(), _pivot.GetFirst(), copyCount);
		}
	}

	return maxon::OK;
}

void FieldOutputBlock::ClearMemory(Bool deactivatedOnly, Bool deactivatedState)
{
	ClearMemory(0, _count, deactivatedOnly, deactivatedState);
}

void FieldOutputBlock::ClearMemory(Int startIdx, Int count, Bool deactivatedOnly, Bool deactivatedState)
{
	DebugAssert(IsValid());

	if ((startIdx + count - 1) >= _count)
		return;

	if (!deactivatedOnly)
	{
		if (_value.IsPopulated())
			ClearMemType(_value.GetFirst() + startIdx, count);

		if (_alpha.IsPopulated())
			ClearMemType(_alpha.GetFirst() + startIdx, count);

		if (_color.IsPopulated())
			ClearMem(_color.GetFirst() + startIdx, sizeof(Vector) * count, 0);

		if (_direction.IsPopulated())
			ClearMem(_direction.GetFirst() + startIdx, sizeof(Vector) * count, 0);

		if (_rotation.IsPopulated())
			ClearMem(_rotation.GetFirst() + startIdx, sizeof(Vector) * count, 0);
		
		if (_pivot.IsPopulated())
			ClearMem(_pivot.GetFirst() + startIdx, sizeof(Vector) * count, 0);
	}

	if (_deactivated.IsPopulated())
		ClearMem(_deactivated.GetFirst() + startIdx, count, deactivatedState);
}

maxon::Crc32C FieldOutputBlock::CalculateCrc() const
{
	DebugAssert(IsValid());

	maxon::Crc32C crc;

	if (_value.IsPopulated())
		crc.Update(_value);

	if (_deactivated.IsPopulated())
		crc.Update(_deactivated);

	if (_alpha.IsPopulated())
		crc.Update(_alpha);

	if (_color.IsPopulated())
		crc.Update(_color);

	if (_direction.IsPopulated())
		crc.Update(_direction);

	if (_rotation.IsPopulated())
		crc.Update(_rotation);
	
	if (_pivot.IsPopulated())
		crc.Update(_pivot);

	crc.UpdateInt(_count);
	crc.UpdateInt(_offset);
	crc.UpdateInt(GetFullCount());

	return crc;
}

Bool FieldOutputBlock::IsValid() const
{
	if (_owner)
		DebugAssert(_owner->IsValid());

	if (MAXON_UNLIKELY(GetCount() < 0))
		return false;

	// Check mandatory array counts
	const Bool hasCount = GetCount() > 0;
	if (MAXON_UNLIKELY(_value.IsPopulated() ^ hasCount))
		return false;

	if (MAXON_UNLIKELY(_deactivated.IsPopulated() ^ hasCount))
		return false;

	// Check optional array counts, if allocated they must match our master count.
	if (MAXON_UNLIKELY(_color.IsPopulated() && (_color.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY(_alpha.IsPopulated() && (_alpha.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY(_direction.IsPopulated() && (_direction.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY(_rotation.IsPopulated() && (_rotation.GetCount() != GetCount())))
		return false;
	
	if (MAXON_UNLIKELY(_pivot.IsPopulated() && (_pivot.GetCount() != GetCount())))
		return false;

	return true;
}

Bool FieldOutputBlock::IsPopulated() const
{
	if (MAXON_UNLIKELY(!IsValid()))
	{
		return false;
	}

	return GetCount() > 0;
}

FieldOutput::FieldOutput(FieldOutput&& src)
	: MAXON_MOVE_MEMBERS(_value, _alpha, _color, _direction, _rotation, _pivot, _deactivated, _count)
{
	src._count = 0;
}

FieldOutput::~FieldOutput()
{
	Reset();
}

FieldOutput::operator FieldOutputBlock() const
{
	return GetBlock();
}

FieldOutputBlock FieldOutput::GetBlock() const
{
	DebugAssert(IsValid());

	FieldOutputBlock fullBlock;
	fullBlock._count = _count;
	fullBlock._owner = this;

	if (_value.IsPopulated())
		fullBlock._value.Set(const_cast<Float*>(_value.GetFirst()), _value.GetCount());

	if (_alpha.IsPopulated())
		fullBlock._alpha.Set(const_cast<Float*>(_alpha.GetFirst()), _alpha.GetCount());

	if (_color.IsPopulated())
		fullBlock._color.Set(const_cast<Vector*>(_color.GetFirst()), _color.GetCount());

	if (_direction.IsPopulated())
		fullBlock._direction.Set(const_cast<Vector*>(_direction.GetFirst()), _direction.GetCount());

	if (_rotation.IsPopulated())
		fullBlock._rotation.Set(const_cast<Vector*>(_rotation.GetFirst()), _rotation.GetCount());

	if (_pivot.IsPopulated())
		fullBlock._pivot.Set(const_cast<Vector*>(_pivot.GetFirst()), _pivot.GetCount());
	
	if (_deactivated.IsPopulated())
		fullBlock._deactivated.Set(const_cast<Bool*>(_deactivated.GetFirst()), _deactivated.GetCount());

	return fullBlock;
}

maxon::Result<FieldOutputBlock> FieldOutput::GetSubBlock(Int offset, Int blockSize) const
{
	iferr_scope;
	FieldOutputBlock fullBlock = GetBlock();
	FieldOutputBlock subBlock = fullBlock.GetSubBlock(offset, blockSize) iferr_return;
	return std::move(subBlock);
}

void FieldOutput::Reset()
{
	_value.Reset();
	_deactivated.Reset();
	_color.Reset();
	_alpha.Reset();
	_direction.Reset();
	_rotation.Reset();
	_pivot.Reset();

	_count = 0;
}

void FieldOutput::Flush()
{
	_value.Flush();
	_deactivated.Flush();
	_color.Flush();
	_alpha.Flush();
	_direction.Flush();
	_rotation.Flush();
	_pivot.Flush();

	_count = 0;
}

Bool FieldOutput::IsEqual(const FieldOutput &comp) const
{
	return _value.IsEqual(comp._value) &&
				_alpha.IsEqual(comp._alpha) &&
				_color.IsEqual(comp._color) &&
				_direction.IsEqual(comp._direction) &&
				_rotation.IsEqual(comp._rotation) &&
				_pivot.IsEqual(comp._pivot) &&
				_deactivated.IsEqual(comp._deactivated);
}

maxon::Result<void> FieldOutput::CopyFrom(const FieldOutput& src)
{
	DebugAssert(src.IsValid());

	iferr_scope;

	const FIELDSAMPLE_FLAG flags = ExtractSampleFlags(static_cast<FieldOutputBlock>(src));

	_count = src._count;

	// Make sure not to fail CopyFrom if size is 0.
	if (_count > 0)
	{
		Resize(_count, flags) iferr_return;

		_value.CopyFrom(src._value) iferr_return;
		_deactivated.CopyFrom(src._deactivated) iferr_return;

		if (flags & FIELDSAMPLE_FLAG::COLOR)
		{
			_color.CopyFrom(src._color) iferr_return;
			_alpha.CopyFrom(src._alpha) iferr_return;
		}
		if (flags & FIELDSAMPLE_FLAG::DIRECTION)
		{
			_direction.CopyFrom(src._direction) iferr_return;
		}
		if (flags & FIELDSAMPLE_FLAG::ROTATION)
		{
			_rotation.CopyFrom(src._rotation) iferr_return;
			_pivot.CopyFrom(src._pivot) iferr_return;
		}
	}
	else
	{
		Reset();
	}

	return maxon::OK;
}

maxon::Result<void> FieldOutput::CopyArrayContentFrom(const FieldOutput& src)
{
	iferr_scope;
	FieldOutputBlock block = GetBlock();
	const FieldOutputBlock srcBlock = src.GetBlock();
	return block.CopyArrayContentFrom(srcBlock);
}

maxon::Result<void> FieldOutput::CopyArrayContentFrom(const FieldOutputBlock& src)
{
	FieldOutputBlock block = GetBlock();
	return block.CopyArrayContentFrom(src);
}

maxon::Result<void> FieldOutput::Resize(Int newSize, FIELDSAMPLE_FLAG sampleFlags, maxon::COLLECTION_RESIZE_FLAGS resizeFlags)
{
	if (MAXON_UNLIKELY(newSize < 0))
	{
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);
	}
	else if (newSize == 0)
	{
		// On 0 resize, we flush everything to allow IsValid to perform safer validation against
		// users tinkering directly with the arrays.
		Flush();
		return maxon::OK;
	}

	iferr_scope_handler
	{
		Reset();
		return err;
	};

	_value.Resize(newSize, resizeFlags) iferr_return;
	_deactivated.Resize(newSize, resizeFlags) iferr_return;

	if (sampleFlags & FIELDSAMPLE_FLAG::COLOR)
	{
		_color.Resize(newSize, resizeFlags) iferr_return;
		_alpha.Resize(newSize, resizeFlags) iferr_return;
	}
	else
	{
		_color.Resize(0, resizeFlags) iferr_return;
		_alpha.Resize(0, resizeFlags) iferr_return;
	}

	if (sampleFlags & FIELDSAMPLE_FLAG::DIRECTION)
	{
		_direction.Resize(newSize, resizeFlags) iferr_return;
	}
	else
	{
		_direction.Resize(0, resizeFlags) iferr_return;
	}

	if (sampleFlags & FIELDSAMPLE_FLAG::ROTATION)
	{
		_rotation.Resize(newSize, resizeFlags) iferr_return;
		_pivot.Resize(newSize, resizeFlags) iferr_return;
	}
	else
	{
		_rotation.Resize(0, resizeFlags) iferr_return;
		_pivot.Resize(0, resizeFlags) iferr_return;
	}

	_count = newSize;

	return maxon::OK;
}

void FieldOutput::ClearMemory(Bool deactivatedOnly, Bool deactivatedState)
{
	ClearMemory(0, _count, deactivatedOnly, deactivatedState);
}

void FieldOutput::ClearMemory(Int startIdx, Int count, Bool deactivatedOnly, Bool deactivatedState)
{
	FieldOutputBlock block = GetBlock();
	block.ClearMemory(startIdx, count, deactivatedOnly, deactivatedState);
}

maxon::Crc32C FieldOutput::CalculateCrc() const
{
	FieldOutputBlock block = GetBlock();
	maxon::Crc32C crc = block.CalculateCrc();
	return crc;
}

maxon::Result<FieldOutput*> FieldOutput::Alloc(Int size, FIELDSAMPLE_FLAG flags)
{
	FieldOutput* outputs = nullptr;
	iferr_scope_handler
	{
		DeleteObj(outputs);
		return err;
	};

	outputs = NewObj(FieldOutput) iferr_return;
	if (size != 0)
	{
		outputs->Resize(size, flags) iferr_return;
	}

	return outputs;
}

maxon::Result<FieldOutput> FieldOutput::Create(Int size, FIELDSAMPLE_FLAG flags)
{
	FieldOutput outputs;
	iferr_scope;

	if (size != 0)
	{
		outputs.Resize(size, flags) iferr_return;
	}

	return std::move(outputs);
}

maxon::Result<FieldOutput> FieldOutput::Create(FieldOutputBlock& src)
{
	FieldOutput newOutputs;
	iferr_scope;

	// Determine from the source what needs to be copied.
	const FIELDSAMPLE_FLAG flags = ExtractSampleFlags(src);
	newOutputs.Resize(src.GetCount(), flags) iferr_return;

	FieldOutputBlock newBlock = newOutputs.GetBlock();
	newBlock.CopyArrayContentFrom(src) iferr_return;

	return std::move(newOutputs);
}

void FieldOutput::Free(FieldOutput*& p)
{
	DeleteObj(p);
}

// Validates the content of all sampling array to make sure user
// didn't hack the public content in an unwanted fashion.
Bool FieldOutput::IsValid() const
{
	if (MAXON_UNLIKELY(GetCount() < 0))
		return false;

	// Check mandatory array counts
	const Bool hasCount = _count > 0;
	if (MAXON_UNLIKELY(hasCount ^ _value.IsPopulated()))
		return false;

	if (MAXON_UNLIKELY(hasCount ^ _deactivated.IsPopulated()))
		return false;

	// Check optional array counts, if allocated they must match our master count.
	if (MAXON_UNLIKELY((_color.GetCount() > 0) && (_color.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY((_alpha.GetCount() > 0) && (_alpha.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY((_direction.GetCount() > 0) && (_direction.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY((_rotation.GetCount() > 0) && (_rotation.GetCount() != GetCount())))
		return false;

	if (MAXON_UNLIKELY((_pivot.GetCount() > 0) && (_pivot.GetCount() != GetCount())))
		return false;
	
	return true;
}

Bool FieldOutput::IsPopulated() const
{
	if (MAXON_UNLIKELY(!IsValid()))
		return false;

	return GetCount() > 0;
}

FieldShared::FieldShared(FieldShared&& src)
// SKIP _customData
	: MAXON_MOVE_MEMBERS(_finalOutput, _finalOutputDirty, _customDataDirty)
{
	if (src._customData)
	{
		// Moving the BaseContainer makes it dirty, if source was not dirty we make sure it stays this way.
		if (src._customDataDirty == src._customData->GetDirty())
		{
			_customData = std::move(src._customData);
			_customDataDirty = _customData->GetDirty();
		}
		else
		{
			_customData = std::move(src._customData);
		}
	}
}

void FieldShared::Flush()
{
	*this = FieldShared();
}

maxon::Result<void> FieldShared::CopyFrom(const FieldShared& src)
{
	iferr_scope;

	_finalOutput = src._finalOutput;
	_finalOutputDirty = src._finalOutputDirty;

	_customData = src._customData;
	_customDataDirty = src._customDataDirty;

	return maxon::OK;
}

void FieldShared::ResetDirty()
{
	_finalOutputDirty = 0;
	_customDataDirty = _customData ? _customData->GetDirty() : 0;
}

maxon::Result<void> FieldCallerStack::CopyFrom(const FieldCallerStack& src)
{
	_value = src._value;
	return _callers.CopyFrom(src._callers);
}

//----------------------------------------------------------------------------------------
/// Added a new caller to the current stack ID.
/// @param[in] currentValue				The current stack ID.
/// @param[in] caller							The new caller added to the stack ID.
/// @return												The resulting ID.
//----------------------------------------------------------------------------------------
static inline UInt AddCallerToCallerStackId(UInt currentValue, const BaseList2D* caller)
{
	if (caller)
	{
		void* marker = nullptr;
		Int32 markerSize = 0;
		caller->GetMarker().GetMemory(marker, markerSize);
		UInt* marker64 = static_cast<UInt*>(marker);

		if (marker64)
		{
			DebugAssert(markerSize == (sizeof(UInt) * 2));
			const UInt markerHash = MAXON_HASHCODE(marker64[0], marker64[1]);
			return ((currentValue & FIELDHASHMAX) * 31) + (((currentValue >> 32) & FIELDHASHMAX) * 31) + markerHash;
		}
	}

	DebugStop();
	return currentValue;
}

UInt FieldCallerStack::RecalcValue() const
{
	UInt newValue = 0;

	for (auto& caller: _callers)
	{
		newValue = AddCallerToCallerStackId(newValue, caller);
	}

	return newValue;
}

void FieldCallerStack::UpdateValue()
{
	_value = RecalcValue();
}

void FieldCallerStack::UpdateValue(const BaseList2D* caller)
{
	_value = AddCallerToCallerStackId(_value, caller);
}

maxon::Result<void> FieldCallerStack::Add(const BaseList2D* caller)
{
	iferr_scope;
	if (MAXON_UNLIKELY(!caller))
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);

	_callers.Append(caller) iferr_return;
	_value = AddCallerToCallerStackId(_value, caller);
	return maxon::OK;
}

FieldCallerStack FieldCallerStack::Add(const FieldCallerStack& src, const BaseList2D* newCaller)
{
	static_assert(!std::is_copy_constructible<FieldCallerStack>::value, "Class must not be construction copiable for allocation standards.");

	iferr_scope_handler
	{
		// Not super safe... We want an easy to type Add method for one liners.
		// Just return and empty stack that won't do any allocation on error of any kind.
		return FieldCallerStack();
	};
	FieldCallerStack newStack;
	newStack.CopyFrom(src) iferr_return;
	newStack.Add(newCaller) iferr_return;
	// Should be moved if unwanted constructors are hidden.
	return newStack;
}

Bool FieldCallerStack::IsValid() const
{
	// Stack without value is no good.
	if ((_value == 0) && (_callers.GetCount() > 0))
		return false;

	// Value without stack is accepted. if ((_value != 0) && (_callers.GetCount() == 0))

	// Must not be null.
	for (auto& caller: _callers)
	{
		if (!caller)
			return false;
	}

	return true;
}

//----------------------------------------------------------------------------------------
/// Checks if the FieldInfo data is valid. Default (empty) FieldInfo is considered valid.
//----------------------------------------------------------------------------------------
Bool FieldInfo::IsValid() const
{
	// Check if empty, default values... Would be nicer to compare with a static instance ?
	if (_threadIndex == 0 && _totalThreadCount == 1 && _callerThread == nullptr && _doc == nullptr &&
			_callerStack.GetCount() == 0 && _inputData.GetCount() == 0)
		return true;
	
	if (MAXON_UNLIKELY(_threadIndex < 0 || _threadIndex >= _totalThreadCount || _totalThreadCount < 0))
		return false;

	if (MAXON_UNLIKELY(!_inputData.IsValid()))
		return false;

	if (MAXON_UNLIKELY(!_callerStack.IsValid()))
		return false;

	return true;
}

//----------------------------------------------------------------------------------------
/// Checks if the FieldInfo is valid and non-empty (all content should be set and ready for sampling)
//----------------------------------------------------------------------------------------
Bool FieldInfo::IsPopulated() const
{
	if (MAXON_UNLIKELY(!IsValid()))
		return false;

	if (MAXON_UNLIKELY(_totalThreadCount <= 0))
		return false;

	if (MAXON_UNLIKELY(!_doc))
		return false;

	if (MAXON_UNLIKELY(!_inputData.IsPopulated()))
		return false;

	if (MAXON_UNLIKELY(_callerStack.GetCount() <= 0))
		return false;

	return true;
}

maxon::Result<void> FieldInfo::CopyFrom(const FieldInfo& src)
{
	_flags = src._flags;
	_threadIndex = src._threadIndex;
	_totalThreadCount = src._totalThreadCount;
	_callerThread = src._callerThread;
	_doc = src._doc;
	_inputData = src._inputData;

	return _callerStack.CopyFrom(src._callerStack);
}

maxon::Result<FieldInfo> FieldInfo::Create(BaseList2D* caller, const FieldInput& inputs, FIELDSAMPLE_FLAG callingFlags /*= FIELDSAMPLE_FLAG::VALUE*/, Int threadIndex /*= 0*/, Int threadCount /*= 0*/)
{
	iferr_scope;

	FieldInfo newInfo;
	newInfo._flags = callingFlags;
	newInfo._callerThread = GeGetCurrentThread();
#ifdef __API_INTERN__
	newInfo._doc = (caller && caller->GetDocument()) ? caller->GetDocument() : ADOC;
#else
	newInfo._doc = (caller && caller->GetDocument()) ? caller->GetDocument() : GetActiveDocument();
#endif
	newInfo._threadIndex = threadIndex;
	newInfo._totalThreadCount = threadCount <= 0 ? maxon::JobQueueRef::GetThreadCount(maxon::JOBQUEUE_CURRENT) : threadCount;
	newInfo._inputData = inputs;
	newInfo._callerStack.Add(caller) iferr_return;

	return std::move(newInfo);
}

maxon::Result<FieldInfo> FieldInfo::Create(BaseList2D* caller, BaseDocument* doc, FIELDSAMPLE_FLAG callingFlags, const FieldInput& inputs)
{
	iferr_scope;

	FieldInfo newInfo;
	newInfo._flags = callingFlags;
	newInfo._callerThread = GeGetCurrentThread();
	newInfo._doc = doc;
	newInfo._threadIndex = 0;
	newInfo._totalThreadCount = maxon::JobQueueRef::GetThreadCount(maxon::JOBQUEUE_CURRENT);
	newInfo._inputData = inputs;
	newInfo._callerStack.Add(caller) iferr_return;

	return std::move(newInfo);
}

maxon::Result<FieldInfo> FieldInfo::Create(const FieldCallerStack& caller, BaseDocument* doc, FIELDSAMPLE_FLAG callingFlags, const FieldInput& inputs)
{
	iferr_scope;

	FieldInfo newInfo;
	newInfo._flags = callingFlags;
	newInfo._callerThread = GeGetCurrentThread();
	newInfo._doc = doc;
	newInfo._threadIndex = 0;
	newInfo._totalThreadCount = maxon::JobQueueRef::GetThreadCount(maxon::JOBQUEUE_CURRENT);
	newInfo._inputData = inputs;
	newInfo._callerStack.CopyFrom(caller) iferr_return;

	return std::move(newInfo);
}

maxon::Result<FieldInfo> FieldInfo::Create(BaseList2D* caller, FIELDSAMPLE_FLAG callingFlags)
{
	iferr_scope;

	FieldInfo newInfo;
	newInfo._flags = callingFlags;
	newInfo._callerThread = GeGetCurrentThread();
#ifdef __API_INTERN__
	newInfo._doc = (caller && caller->GetDocument()) ? caller->GetDocument() : ADOC;
#else
	newInfo._doc = (caller && caller->GetDocument()) ? caller->GetDocument() : GetActiveDocument();
#endif
	newInfo._threadIndex = 0;
	newInfo._totalThreadCount = maxon::JobQueueRef::GetThreadCount(maxon::JOBQUEUE_CURRENT);
	newInfo._callerStack.Add(caller) iferr_return;
	if (caller->IsInstanceOf(Obase))
	{
		newInfo._inputData._transform = static_cast<BaseObject*>(caller)->GetMg();
	}

	return std::move(newInfo);
}

void FieldInput::CopyFromRaw(const FieldInput& src)
{
	*this = src;
}

FieldInput FieldInput::GetSubBlock(Int offset, Int blockSize) const
{
	FieldInput result;
	// TODO: (Psanche) This size and offset validation is very soft, fetching a sub block of a sub block can easily 
	// make out of bounds access. The full offset ain't carried across sub blocks and allocated size is not reduced to reflect
	// how far you can read in an offseted sub block.
	// ITEM#264864 [Fields] Out of Bound Management for FieldInput::GetSubBlock
	// TO BE FIXED
	if (offset >= _allocatedArraySize || offset < 0 || blockSize <= 0)
		return result;

	result._blockOffset = offset;
	result._fullArraySize = _fullArraySize;
	result._allocatedArraySize = _allocatedArraySize;
	result._blockCount = Min(blockSize, _allocatedArraySize - offset);
	result._transform = _transform;

	// Position is mandatory
	DebugAssert(_position.IsPopulated());
	if (_position.IsPopulated())
		result._position.Set(&_position[offset], result._blockCount);

	if (_direction.IsPopulated())
		result._direction.Set(&_direction[offset], result._blockCount);

	if (_uvw.IsPopulated())
		result._uvw.Set(&_uvw[offset], result._blockCount);

	return result;
}

Bool FieldInput::IsValid() const
{
	if (MAXON_UNLIKELY(GetCount() < 0 || _fullArraySize < 0 || _allocatedArraySize < 0))
		return false;

	if (MAXON_UNLIKELY(_allocatedArraySize > _fullArraySize))
		return false;

	if (MAXON_UNLIKELY(GetCount() > _allocatedArraySize))
		return false;

	if (MAXON_UNLIKELY(_blockOffset < 0 || (_blockOffset >= _fullArraySize && GetCount() > 0)))
		return false;

	// Check mandatory array counts
	const Bool hasCount = GetCount() > 0;
	if (MAXON_UNLIKELY(_position.IsPopulated() ^ hasCount))
		return false;

	// Check optional array counts, it is possible the arrays sizes are bigger than the actual count.
	// This is for a special use case when using SampleLambdas, the block count is changed directly.
	if (MAXON_UNLIKELY(_direction.IsPopulated() && (_direction.GetCount() < GetCount())))
		return false;

	if (MAXON_UNLIKELY(_uvw.IsPopulated() && (_uvw.GetCount() < GetCount())))
		return false;

	return true;
}

Bool FieldInput::IsPopulated() const
{
	if (MAXON_UNLIKELY(!IsValid()))
		return false;

	return GetCount() > 0;
}
