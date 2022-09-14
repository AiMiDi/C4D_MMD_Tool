#if 1
namespace maxon
{
	const maxon::Char* const ConvexDecompositionInterface::MTable::_ids = 
		"Init@31ccad65e4f0036\0" // Result<void> Init(Float levelOfDetail, UInt32 maxVoxelCount)
		"GetSettings@b4a6b0e29e3a2d07\0" // Result<DataDictionary> GetSettings() const
		"IsReady@12e73654e6d65520\0" // Bool IsReady() const
		"GetProgress@a191dfac37060e46\0" // Result<UInt16> GetProgress() const
		"Compute@cf3b4914c687a717\0" // Result<void> Compute(const GeometryObject& geometryObject)
		"FetchResults@e707c2b39f1d8735\0" // Result<Array<GeometryObject>> FetchResults()
		"Cancel@3008090429c5a175\0" // Result<void> Cancel()
		"Clear@3008090429c5a175\0" // Result<void> Clear()
	"";
	const maxon::METHOD_FLAGS ConvexDecompositionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ConvexDecompositionInterface, , "net.maxon.interface.convexdecomposition", "maxon.ConvexDecompositionInterface", (ObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(ConvexDecompositionClasses);
	namespace ConvexDecompositionClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ConvexDecompositionVHACD, , "net.maxon.convexdecompositionvhacd");
	}
}
#endif
