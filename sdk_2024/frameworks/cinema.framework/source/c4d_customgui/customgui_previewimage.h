/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_PREVIEWIMAGE_H__
#define CUSTOMGUI_PREVIEWIMAGE_H__

#include "c4d_customdatatype.h"
#include "c4d_gui.h"
#include "customgui_base.h"

/// Movie viewer custom GUI ID.
#define CUSTOMGUI_PREVIEWIMAGE				200001017
#define CUSTOMDATATYPE_PREVIEWIMAGE		200001018


namespace maxon
{
namespace nodes
{
namespace PREVIEW
{
	enum class IMAGETYPE;
} // namespace PREVIEW
} // namespace nodes

struct CustomGuiPreviewImageLib;

class GraphNode;

class PreviewImageData : public CINEWARE_NAMESPACE::CustomDataTypeT<CUSTOMDATATYPE_PREVIEWIMAGE>
{
private:
	PreviewImageData();
	~PreviewImageData();

public:
	Result<void> SetGraphNode(const GraphNode& graphNode, const GraphNode& settingsGraphNode, const String& title, const nodes::PREVIEW::IMAGETYPE& type);

private:
	static CustomGuiPreviewImageLib *CheckGuiPreviewImageLib(Int32 offset)
	{
		static CustomGuiPreviewImageLib *lib_PreviewImage;
		return CINEWARE_NAMESPACE::CheckLib<CustomGuiPreviewImageLib>(CUSTOMGUI_PREVIEWIMAGE, offset, lib_PreviewImage);
	}
};



class PreviewImageCustomGui : public CINEWARE_NAMESPACE::BaseCustomGui<CUSTOMGUI_PREVIEWIMAGE>
{
	PreviewImageCustomGui();
	~PreviewImageCustomGui();

public:
//	Bool SetMovie(const Filename &f);
};


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
class iPreviewImageCustomGui : public CINEWARE_NAMESPACE::iBaseCustomGui
{
	iPreviewImageCustomGui(const CINEWARE_NAMESPACE::BaseContainer &settings, CINEWARE_NAMESPACE::CUSTOMGUIPLUGIN *plugin) : CINEWARE_NAMESPACE::iBaseCustomGui(settings, plugin) { }
};
class CINEWARE_SINGLEINHERITANCE iCustomDataTypeImagePreview : public CINEWARE_NAMESPACE::iCustomDataType<iCustomDataTypeImagePreview, CUSTOMDATATYPE_PREVIEWIMAGE>
{
};
#else
class iPreviewImageCustomGui;
class iCustomDataTypeImagePreview;
#endif

class PreviewImageData;

struct CustomGuiPreviewImageLib : public CINEWARE_NAMESPACE::BaseCustomGuiLib
{
	Result<void>(iCustomDataTypeImagePreview::*SetGraphNode)(const GraphNode& graphNode, const GraphNode& settingsGraphNode, const String& title, const nodes::PREVIEW::IMAGETYPE& type);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

inline Result<void> PreviewImageData::SetGraphNode(const GraphNode& graphNode, const GraphNode& settingsGraphNode, const String& title, const nodes::PREVIEW::IMAGETYPE& type)
{
	CustomGuiPreviewImageLib *lib = PreviewImageData::CheckGuiPreviewImageLib(LIBOFFSET(CustomGuiPreviewImageLib, SetGraphNode));
	if (!lib || !lib->SetGraphNode)
		return NullptrError(MAXON_SOURCE_LOCATION);
	return (reinterpret_cast<iCustomDataTypeImagePreview*>(this)->*lib->SetGraphNode)(graphNode, settingsGraphNode, title, type);
}

} // namespace maxon

#endif // CUSTOMGUI_PREVIEWIMAGE_H__
