
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct AudioObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBitsPerChannel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChannelCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDataPtr);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLength);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSampleCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSampleRate);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_AudioObjectInterface_Init) (maxon::GenericComponent* this_, Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data);
	maxon::Int _AudioObjectInterface_Init_Offset;
	Int (*_AudioObjectInterface_GetChannelCount) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetChannelCount_Offset;
	Int (*_AudioObjectInterface_GetBitsPerChannel) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetBitsPerChannel_Offset;
	Float (*_AudioObjectInterface_GetSampleRate) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetSampleRate_Offset;
	Int (*_AudioObjectInterface_GetSampleCount) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetSampleCount_Offset;
	TimeValue (*_AudioObjectInterface_GetLength) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetLength_Offset;
	Block<const Char> (*_AudioObjectInterface_GetDataPtr) (const maxon::GenericComponent* this_);
	maxon::Int _AudioObjectInterface_GetDataPtr_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, Init))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, Init), W, MTable>::type::_AudioObjectInterface_Init;
		_AudioObjectInterface_Init = reinterpret_cast<const decltype(_AudioObjectInterface_Init)&>(ptr);
		_AudioObjectInterface_Init_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetChannelCount))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetChannelCount), W, MTable>::type::_AudioObjectInterface_GetChannelCount;
		_AudioObjectInterface_GetChannelCount = reinterpret_cast<const decltype(_AudioObjectInterface_GetChannelCount)&>(ptr);
		_AudioObjectInterface_GetChannelCount_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetBitsPerChannel))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetBitsPerChannel), W, MTable>::type::_AudioObjectInterface_GetBitsPerChannel;
		_AudioObjectInterface_GetBitsPerChannel = reinterpret_cast<const decltype(_AudioObjectInterface_GetBitsPerChannel)&>(ptr);
		_AudioObjectInterface_GetBitsPerChannel_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetSampleRate))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetSampleRate), W, MTable>::type::_AudioObjectInterface_GetSampleRate;
		_AudioObjectInterface_GetSampleRate = reinterpret_cast<const decltype(_AudioObjectInterface_GetSampleRate)&>(ptr);
		_AudioObjectInterface_GetSampleRate_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetSampleCount))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetSampleCount), W, MTable>::type::_AudioObjectInterface_GetSampleCount;
		_AudioObjectInterface_GetSampleCount = reinterpret_cast<const decltype(_AudioObjectInterface_GetSampleCount)&>(ptr);
		_AudioObjectInterface_GetSampleCount_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetLength))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetLength), W, MTable>::type::_AudioObjectInterface_GetLength;
		_AudioObjectInterface_GetLength = reinterpret_cast<const decltype(_AudioObjectInterface_GetLength)&>(ptr);
		_AudioObjectInterface_GetLength_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetDataPtr))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AudioObjectInterface, GetDataPtr), W, MTable>::type::_AudioObjectInterface_GetDataPtr;
		_AudioObjectInterface_GetDataPtr = reinterpret_cast<const decltype(_AudioObjectInterface_GetDataPtr)&>(ptr);
		_AudioObjectInterface_GetDataPtr_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<AudioObjectInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<AudioObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct AudioObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBitsPerChannel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChannelCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDataPtr);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLength);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSampleCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSampleRate);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static Result<void> _AudioObjectInterface_Init(maxon::GenericComponent* this_, Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data) { return ((typename S::Implementation*) this_)->Init(channelCount, bitsPerChannel, sampleRate, sampleCount, length, data); }
		static Int _AudioObjectInterface_GetChannelCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetChannelCount(); }
		static Int _AudioObjectInterface_GetBitsPerChannel(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBitsPerChannel(); }
		static Float _AudioObjectInterface_GetSampleRate(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSampleRate(); }
		static Int _AudioObjectInterface_GetSampleCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSampleCount(); }
		static TimeValue _AudioObjectInterface_GetLength(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLength(); }
		static Block<const Char> _AudioObjectInterface_GetDataPtr(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataPtr(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data) -> Result<void>
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_Init((maxon::GenericComponent*) this + mt_._AudioObjectInterface_Init_Offset, channelCount, bitsPerChannel, sampleRate, sampleCount, length, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetChannelCount() const -> Int
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetChannelCount((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetChannelCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetBitsPerChannel() const -> Int
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetBitsPerChannel((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetBitsPerChannel_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetSampleRate() const -> Float
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetSampleRate((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetSampleRate_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetSampleCount() const -> Int
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetSampleCount((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetSampleCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetLength() const -> TimeValue
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetLength((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetLength_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::GetDataPtr() const -> Block<const Char>
{
	const AudioObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AudioObjectInterface, this); return mt_._AudioObjectInterface_GetDataPtr((const maxon::GenericComponent*) this + mt_._AudioObjectInterface_GetDataPtr_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AudioObjectInterface* o_ = (AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_Init_Offset, channelCount, bitsPerChannel, sampleRate, sampleCount, length, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(Int channelCount, Int bitsPerChannel, Float sampleRate, Int sampleCount, const TimeValue& length, const Block<const Char>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AudioObjectInterface* o_ = (AudioObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_Init_Offset, channelCount, bitsPerChannel, sampleRate, sampleCount, length, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetChannelCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetChannelCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetChannelCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetChannelCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBitsPerChannel() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetBitsPerChannel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetBitsPerChannel(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetBitsPerChannel_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSampleRate() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetSampleRate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetSampleRate(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetSampleRate_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSampleCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetSampleCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetSampleCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetSampleCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLength() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<TimeValue>, TimeValue>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<TimeValue>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetLength(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetLength_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AudioObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Block<const Char>>, Block<const Char>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AudioObjectInterface* o_ = (const AudioObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AudioObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Block<const Char>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AudioObjectInterface, o_, AudioObjectInterface_GetDataPtr) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AudioObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AudioObjectInterface>() : PRIVATE_MAXON_VTABLE(AudioObjectInterface, o_); 
	return (mt_._AudioObjectInterface_GetDataPtr(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AudioObjectInterface_GetDataPtr_Offset));
}
auto AudioObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto AudioObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_AudioObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_AudioObjectInterface() { new (s_ui_maxon_AudioObjectInterface) maxon::EntityUse(AudioObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/audioobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_AudioObjectInterface(AudioObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/audioobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

