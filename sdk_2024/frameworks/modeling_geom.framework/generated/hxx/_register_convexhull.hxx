#if 1
namespace maxon
{
	const maxon::Char* const ConvexHullInterface::MTable::_ids = 
		"ComputeConvexHull@28dd3ae2f2101955\0" // Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces)
		"ComputeConvexHull@56f88b549ec1d100\0" // Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, ConvexHullData& hull)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ConvexHullInterface::Hxx2::Unresolved : public ConvexHullInterface
	{
	public:
		static const Unresolved* Get(const ConvexHullInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ConvexHullInterface* o) { return (Unresolved*) o; }
		static Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ConvexHullInterface::ComputeConvexHull(vertices, shrink, shrinkClamp, resultVertices, resultEdges, resultFaces); return HXXRET1(UNRESOLVED);}
		static Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, Float shrink, Float shrinkClamp, ConvexHullData& hull) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ConvexHullInterface::ComputeConvexHull(vertices, shrink, shrinkClamp, hull); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE ConvexHullInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<Float>>::value,
		maxon::details::UnresolvedReturnType<Result<Float>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ConvexHullInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Float>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ConvexHullInterface_ComputeConvexHull = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull);
		#else
		tbl->ConvexHullInterface_ComputeConvexHull = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Float>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->ConvexHullInterface_ComputeConvexHull_1 = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull_1);
		#else
		tbl->ConvexHullInterface_ComputeConvexHull_1 = PRIVATE_MAXON_MF_CAST(decltype(ConvexHullInterface_ComputeConvexHull_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ConvexHullInterface_ComputeConvexHull_1);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ConvexHullInterface, "net.maxon.interface.convexhull", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
