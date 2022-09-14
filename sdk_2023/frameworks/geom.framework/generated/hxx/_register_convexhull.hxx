#if 1
namespace maxon
{
	const maxon::Char* const ConvexHullInterface::MTable::_ids = 
		"Free@461d05ad155df1fb\0" // void Free(const ConvexHullInterface* object)
		"Alloc@1f5fe13109164590\0" // ConvexHullInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"ComputeConvexHull@6104e2219912bb8\0" // Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces)
		"ComputeConvexHull@627e081146454c3f\0" // Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ConvexHullInterface::Hxx2::Unresolved : public ConvexHullInterface
	{
	public:
		static const Unresolved* Get(const ConvexHullInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ConvexHullInterface* o) { return (Unresolved*) o; }
		static void Free(const ConvexHullInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ConvexHullInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ConvexHullInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ConvexHullInterface::Alloc(allocLocation); return nullptr;}
		Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ConvexHullInterface*) this)->ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((ConvexHullInterface*) this)->ComputeConvexHull(vertices, shrink, shrinkClamp, hull); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ConvexHullInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<ConvexHullInterface*>::value,
		maxon::details::NullReturnType<Result<Float>>::value,
		maxon::details::NullReturnType<Result<Float>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ConvexHullInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConvexHullInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ConvexHullInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ConvexHullInterface_ComputeConvexHull = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull);
		#else
		tbl->ConvexHullInterface_ComputeConvexHull = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ConvexHullInterface_ComputeConvexHull_1 = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull_1);
		#else
		tbl->ConvexHullInterface_ComputeConvexHull_1 = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull_1);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ConvexHullInterface, "net.maxon.interface.convexhull", nullptr);
}
#endif
