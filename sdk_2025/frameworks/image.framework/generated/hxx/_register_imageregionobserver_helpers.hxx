#if 1
namespace maxon
{
	const maxon::Char* const ImageRegionTilesObserverInterface::MTable::_ids = 
		"Init@c49f7df11faba36e\0" // Result<void> Init(Int tileSize)
		"GetAndResetDirtyState@9998b0253add9b7e\0" // Result<void> GetAndResetDirtyState(DirtyState& dirtyState)
	"";
	const maxon::METHOD_FLAGS ImageRegionTilesObserverInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(ImageRegionTilesObserverInterface, , "net.maxon.nodes.interface.imageregionobserver.tiles", (ImageRegionObserverInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageRegionSingleTileObserverClass, , "net.maxon.class.imageregionobserver.tiles");
}
#endif
