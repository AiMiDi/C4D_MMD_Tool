
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* NoiseInterface::PrivateGetCppName() { return "maxon::NoiseRef"; }

struct NoiseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_NoiseInterface_Free) (const NoiseInterface* object);
	NoiseInterface* (*_NoiseInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*_NoiseInterface_Init) (NoiseInterface* this_, UInt32 seed, Int permutationTablePower);
	UInt32 (*_NoiseInterface_GetSeed) (const NoiseInterface* this_);
	Int (*_NoiseInterface_GetPermutationTablePower) (const NoiseInterface* this_);
	const BaseArray<UInt16>* (*_NoiseInterface_GetPermutationTable) (const NoiseInterface* this_);
	Result<void> (*_NoiseInterface_GetGradientTable) (const NoiseInterface* this_, Bool gradient3D, BaseArray<Vector4d32>& gradient);
	Result<void> (*_NoiseInterface_GetFbmTable) (const NoiseInterface* this_, FbmTableRef table, BaseArray<Float32>& fbm);
	const BaseArray<Vector4d32>* (*_NoiseInterface_GetRandomTable) (const NoiseInterface* this_);
	Float32 (*_NoiseInterface_SNoise) (const NoiseInterface* this_, const Vector32& p);
	Float32 (*_NoiseInterface_SNoise_1) (const NoiseInterface* this_, const Vector4d32& p);
	Float32 (*_NoiseInterface_PeriodicSNoise) (const NoiseInterface* this_, const Vector32& p, Int repeatX, Int repeatY, Int repeatZ);
	Float32 (*_NoiseInterface_PeriodicSNoise_1) (const NoiseInterface* this_, const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT);
	void (*_NoiseInterface_Voronoi) (const NoiseInterface* this_, const Vector32& p, Int maximumOrder, Float32* distance, Int32* index);
	void (*_NoiseInterface_Voronoi_1) (const NoiseInterface* this_, const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index);
	ResultMemT<FbmTableRef> (*_NoiseInterface_InitFbm) (const NoiseInterface* this_, Float32 lacunarity, Float32 gain);
	Float32 (*_NoiseInterface_Fbm) (const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves);
	Float32 (*_NoiseInterface_Fbm_1) (const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves);
	Float32 (*_NoiseInterface_Turbulence) (const NoiseInterface* this_, Vector32 p, Float32 octaves, Bool absolute);
	Float32 (*_NoiseInterface_Turbulence_1) (const NoiseInterface* this_, Vector4d32 p, Float32 octaves, Bool absolute);
	Float32 (*_NoiseInterface_RidgedMultifractal) (const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold);
	Float32 (*_NoiseInterface_RidgedMultifractal_1) (const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold);
	template <typename IMPL> void Init()
	{
		_NoiseInterface_Free = &IMPL::_NoiseInterface_Free;
		_NoiseInterface_Alloc = &IMPL::_NoiseInterface_Alloc;
		_NoiseInterface_Init = &IMPL::_NoiseInterface_Init;
		_NoiseInterface_GetSeed = &IMPL::_NoiseInterface_GetSeed;
		_NoiseInterface_GetPermutationTablePower = &IMPL::_NoiseInterface_GetPermutationTablePower;
		_NoiseInterface_GetPermutationTable = &IMPL::_NoiseInterface_GetPermutationTable;
		_NoiseInterface_GetGradientTable = &IMPL::_NoiseInterface_GetGradientTable;
		_NoiseInterface_GetFbmTable = &IMPL::_NoiseInterface_GetFbmTable;
		_NoiseInterface_GetRandomTable = &IMPL::_NoiseInterface_GetRandomTable;
		_NoiseInterface_SNoise = &IMPL::_NoiseInterface_SNoise;
		_NoiseInterface_SNoise_1 = &IMPL::_NoiseInterface_SNoise_1;
		_NoiseInterface_PeriodicSNoise = &IMPL::_NoiseInterface_PeriodicSNoise;
		_NoiseInterface_PeriodicSNoise_1 = &IMPL::_NoiseInterface_PeriodicSNoise_1;
		_NoiseInterface_Voronoi = &IMPL::_NoiseInterface_Voronoi;
		_NoiseInterface_Voronoi_1 = &IMPL::_NoiseInterface_Voronoi_1;
		_NoiseInterface_InitFbm = &IMPL::_NoiseInterface_InitFbm;
		_NoiseInterface_Fbm = &IMPL::_NoiseInterface_Fbm;
		_NoiseInterface_Fbm_1 = &IMPL::_NoiseInterface_Fbm_1;
		_NoiseInterface_Turbulence = &IMPL::_NoiseInterface_Turbulence;
		_NoiseInterface_Turbulence_1 = &IMPL::_NoiseInterface_Turbulence_1;
		_NoiseInterface_RidgedMultifractal = &IMPL::_NoiseInterface_RidgedMultifractal;
		_NoiseInterface_RidgedMultifractal_1 = &IMPL::_NoiseInterface_RidgedMultifractal_1;
	}
};

struct NoiseInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void _NoiseInterface_Free(const NoiseInterface* object) { return C::Free(object); }
		static NoiseInterface* _NoiseInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> _NoiseInterface_Init(NoiseInterface* this_, UInt32 seed, Int permutationTablePower) { return C::Get(this_)->Init(seed, permutationTablePower); }
		static UInt32 _NoiseInterface_GetSeed(const NoiseInterface* this_) { return C::Get(this_)->GetSeed(); }
		static Int _NoiseInterface_GetPermutationTablePower(const NoiseInterface* this_) { return C::Get(this_)->GetPermutationTablePower(); }
		static const BaseArray<UInt16>* _NoiseInterface_GetPermutationTable(const NoiseInterface* this_) { return C::Get(this_)->GetPermutationTable(); }
		static Result<void> _NoiseInterface_GetGradientTable(const NoiseInterface* this_, Bool gradient3D, BaseArray<Vector4d32>& gradient) { return C::Get(this_)->GetGradientTable(gradient3D, gradient); }
		static Result<void> _NoiseInterface_GetFbmTable(const NoiseInterface* this_, FbmTableRef table, BaseArray<Float32>& fbm) { return C::Get(this_)->GetFbmTable(std::forward<FbmTableRef>(table), fbm); }
		static const BaseArray<Vector4d32>* _NoiseInterface_GetRandomTable(const NoiseInterface* this_) { return C::Get(this_)->GetRandomTable(); }
		static Float32 _NoiseInterface_SNoise(const NoiseInterface* this_, const Vector32& p) { return C::Get(this_)->SNoise(p); }
		static Float32 _NoiseInterface_SNoise_1(const NoiseInterface* this_, const Vector4d32& p) { return C::Get(this_)->SNoise(p); }
		static Float32 _NoiseInterface_PeriodicSNoise(const NoiseInterface* this_, const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) { return C::Get(this_)->PeriodicSNoise(p, repeatX, repeatY, repeatZ); }
		static Float32 _NoiseInterface_PeriodicSNoise_1(const NoiseInterface* this_, const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) { return C::Get(this_)->PeriodicSNoise(p, repeatX, repeatY, repeatZ, repeatT); }
		static void _NoiseInterface_Voronoi(const NoiseInterface* this_, const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(this_)->Voronoi(p, maximumOrder, distance, index); }
		static void _NoiseInterface_Voronoi_1(const NoiseInterface* this_, const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(this_)->Voronoi(p, maximumOrder, distance, index); }
		static ResultMemT<FbmTableRef> _NoiseInterface_InitFbm(const NoiseInterface* this_, Float32 lacunarity, Float32 gain) { return C::Get(this_)->InitFbm(lacunarity, gain); }
		static Float32 _NoiseInterface_Fbm(const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves) { return C::Get(this_)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves); }
		static Float32 _NoiseInterface_Fbm_1(const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves) { return C::Get(this_)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves); }
		static Float32 _NoiseInterface_Turbulence(const NoiseInterface* this_, Vector32 p, Float32 octaves, Bool absolute) { return C::Get(this_)->Turbulence(std::forward<Vector32>(p), octaves, absolute); }
		static Float32 _NoiseInterface_Turbulence_1(const NoiseInterface* this_, Vector4d32 p, Float32 octaves, Bool absolute) { return C::Get(this_)->Turbulence(std::forward<Vector4d32>(p), octaves, absolute); }
		static Float32 _NoiseInterface_RidgedMultifractal(const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(this_)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold); }
		static Float32 _NoiseInterface_RidgedMultifractal_1(const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(this_)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Free(const NoiseInterface* object) -> void
{
	return MTable::_instance._NoiseInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Alloc(const maxon::SourceLocation& allocLocation) -> NoiseInterface*
{
	return MTable::_instance._NoiseInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Init(UInt32 seed, Int permutationTablePower) -> Result<void>
{
	return MTable::_instance._NoiseInterface_Init(this, seed, permutationTablePower);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetSeed() const -> UInt32
{
	return MTable::_instance._NoiseInterface_GetSeed(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTablePower() const -> Int
{
	return MTable::_instance._NoiseInterface_GetPermutationTablePower(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTable() const -> const BaseArray<UInt16>*
{
	return MTable::_instance._NoiseInterface_GetPermutationTable(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	return MTable::_instance._NoiseInterface_GetGradientTable(this, gradient3D, gradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	return MTable::_instance._NoiseInterface_GetFbmTable(this, std::forward<FbmTableRef>(table), fbm);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetRandomTable() const -> const BaseArray<Vector4d32>*
{
	return MTable::_instance._NoiseInterface_GetRandomTable(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector32& p) const -> Float32
{
	return MTable::_instance._NoiseInterface_SNoise(this, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector4d32& p) const -> Float32
{
	return MTable::_instance._NoiseInterface_SNoise_1(this, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> Float32
{
	return MTable::_instance._NoiseInterface_PeriodicSNoise(this, p, repeatX, repeatY, repeatZ);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> Float32
{
	return MTable::_instance._NoiseInterface_PeriodicSNoise_1(this, p, repeatX, repeatY, repeatZ, repeatT);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return MTable::_instance._NoiseInterface_Voronoi(this, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return MTable::_instance._NoiseInterface_Voronoi_1(this, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::InitFbm(Float32 lacunarity, Float32 gain) const -> ResultMemT<FbmTableRef>
{
	return MTable::_instance._NoiseInterface_InitFbm(this, lacunarity, gain);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> Float32
{
	return MTable::_instance._NoiseInterface_Fbm(this, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> Float32
{
	return MTable::_instance._NoiseInterface_Fbm_1(this, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return MTable::_instance._NoiseInterface_Turbulence(this, std::forward<Vector32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return MTable::_instance._NoiseInterface_Turbulence_1(this, std::forward<Vector4d32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return MTable::_instance._NoiseInterface_RidgedMultifractal(this, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return MTable::_instance._NoiseInterface_RidgedMultifractal_1(this, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold);
}

auto NoiseInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<NoiseRef>
{
	NoiseInterface* res_ = NoiseInterface::Alloc(MAXON_SOURCE_LOCATION);
	return NoiseRef(maxon::ForwardResultPtr<NoiseInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(UInt32 seed, Int permutationTablePower) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NoiseInterface* o_ = (NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._NoiseInterface_Init(o_, seed, permutationTablePower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSeed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_GetSeed(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPermutationTablePower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_GetPermutationTablePower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPermutationTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._NoiseInterface_GetPermutationTable(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._NoiseInterface_GetGradientTable(o_, gradient3D, gradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._NoiseInterface_GetFbmTable(o_, std::forward<FbmTableRef>(table), fbm));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetRandomTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._NoiseInterface_GetRandomTable(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SNoise(const Vector32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_SNoise(o_, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SNoise(const Vector4d32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_SNoise_1(o_, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SNoise(const Vector32& p, Float32 time) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->SNoise(p, time));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_PeriodicSNoise(o_, p, repeatX, repeatY, repeatZ));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_PeriodicSNoise_1(o_, p, repeatX, repeatY, repeatZ, repeatT));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._NoiseInterface_Voronoi(o_, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._NoiseInterface_Voronoi_1(o_, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InitFbm(Float32 lacunarity, Float32 gain) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ResultMemT<FbmTableRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._NoiseInterface_InitFbm(o_, lacunarity, gain));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_Fbm(o_, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_Fbm_1(o_, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_Turbulence(o_, std::forward<Vector32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_Turbulence_1(o_, std::forward<Vector4d32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_RidgedMultifractal(o_, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._NoiseInterface_RidgedMultifractal_1(o_, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NoiseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NoiseInterface() { new (s_ui_maxon_NoiseInterface) maxon::EntityUse(NoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NoiseInterface(NoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct RenderNoiseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Noise);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_RenderNoiseInterface_Init) (maxon::GenericComponent* this_, UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters);
	maxon::Int _RenderNoiseInterface_Init_Offset;
	Float32 (*_RenderNoiseInterface_Noise) (const maxon::GenericComponent* this_, const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int _RenderNoiseInterface_Noise_Offset;
	Float32 (*_RenderNoiseInterface_Noise_1) (const maxon::GenericComponent* this_, const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int _RenderNoiseInterface_Noise_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Init), W, MTable>::type::_RenderNoiseInterface_Init;
			_RenderNoiseInterface_Init = reinterpret_cast<const decltype(_RenderNoiseInterface_Init)&>(ptr);
			_RenderNoiseInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise), W, MTable>::type::_RenderNoiseInterface_Noise;
			_RenderNoiseInterface_Noise = reinterpret_cast<const decltype(_RenderNoiseInterface_Noise)&>(ptr);
			_RenderNoiseInterface_Noise_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise), W, MTable>::type::_RenderNoiseInterface_Noise_1;
			_RenderNoiseInterface_Noise_1 = reinterpret_cast<const decltype(_RenderNoiseInterface_Noise_1)&>(ptr);
			_RenderNoiseInterface_Noise_1_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<RenderNoiseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<RenderNoiseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct RenderNoiseInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Noise);
		static Result<void> _RenderNoiseInterface_Init(maxon::GenericComponent* this_, UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) { return ((typename S::Implementation*) this_)->Init(seed, permutationTablePower, additionalParameters); }
		static Float32 _RenderNoiseInterface_Noise(const maxon::GenericComponent* this_, const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) this_)->Noise(p, time, octaves, absolute, sampleRadius); }
		static Float32 _RenderNoiseInterface_Noise_1(const maxon::GenericComponent* this_, const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) this_)->Noise(p, time, octaves, absolute, sampleRadius); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_._RenderNoiseInterface_Init((maxon::GenericComponent*) this + mt_._RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_._RenderNoiseInterface_Noise((const maxon::GenericComponent*) this + mt_._RenderNoiseInterface_Noise_Offset, p, time, octaves, absolute, sampleRadius);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_._RenderNoiseInterface_Noise_1((const maxon::GenericComponent*) this + mt_._RenderNoiseInterface_Noise_1_Offset, p, time, octaves, absolute, sampleRadius);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_._RenderNoiseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_._RenderNoiseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_._RenderNoiseInterface_Noise(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Noise_Offset, p, time, octaves, absolute, sampleRadius));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_._RenderNoiseInterface_Noise_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._RenderNoiseInterface_Noise_1_Offset, p, time, octaves, absolute, sampleRadius));
}
auto RenderNoiseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto RenderNoiseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_RenderNoiseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_RenderNoiseInterface() { new (s_ui_maxon_RenderNoiseInterface) maxon::EntityUse(RenderNoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_RenderNoiseInterface(RenderNoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

