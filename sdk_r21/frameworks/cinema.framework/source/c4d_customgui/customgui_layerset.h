#ifndef CUSTOMGUI_LAYERSET_H__
#define CUSTOMGUI_LAYERSET_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "c4d_customdatatype.h"
#include "customgui_base.h"

#ifdef __API_INTERN__
	#include "ge_string.h"
	#include "ge_file.h"
#else
	#include "c4d_string.h"
	#include "c4d_file.h"
#endif

/// LayerSet custom GUI ID.
#define CUSTOMGUI_LAYERSET			200000043

/// LayerSet custom data type ID.
#define CUSTOMDATATYPE_LAYERSET 200000044

#ifndef __API_INTERN__
//-------------------------------------------------------------------------------------------------
/// Layer set custom data type (@ref CUSTOMDATATYPE_LAYERSET).
//-------------------------------------------------------------------------------------------------
class LayerSet : public CustomDataType
{
	private:
		LayerSet();
		~LayerSet();

	public:

		//----------------------------------------------------------------------------------------
		/// Checks if the layer set has content.
		/// @return												@trueIfOtherwiseFalse{the set contains any layer}
		//----------------------------------------------------------------------------------------
		Bool IsPopulated() const { return C4DOS.Pa->LSL_Content(this); }

		//----------------------------------------------------------------------------------------
		/// Checks if a layer is enabled.
		/// @param[in] name								The name of the layer to check for.
		/// @return												@trueIfOtherwiseFalse{the layer is enabled}
		//----------------------------------------------------------------------------------------
		Bool IsLayerEnabled(const maxon::String &name) const { return C4DOS.Pa->LSL_IsLayerEnabled(this, name); }

		//----------------------------------------------------------------------------------------
		/// Checks if a layer is in the set.
		/// @param[in] name								The name of the layer to check for.
		/// @return												@trueIfOtherwiseFalse{the layer is in the set}
		//----------------------------------------------------------------------------------------
		Bool FindLayerSet(const maxon::String &name) const { return C4DOS.Pa->LSL_FindLayerSet(this, name); }

		//----------------------------------------------------------------------------------------
		/// Gets the set's name.
		/// @return												The name of the set.
		//----------------------------------------------------------------------------------------
		String GetName() const { return C4DOS.Pa->LSL_GetName(this); }

		//----------------------------------------------------------------------------------------
		/// Gets the layer set mode.
		/// @return												The mode: @enumerateEnum{LAYERSETMODE}
		//----------------------------------------------------------------------------------------
		LAYERSETMODE GetMode() const { return C4DOS.Pa->LSL_GetMode(this); }

		//----------------------------------------------------------------------------------------
		/// Sets a new layer set mode.
		/// @param[in] t_mode							The mode to set: @enumerateEnum{LAYERSETMODE}
		//----------------------------------------------------------------------------------------
		void SetMode(LAYERSETMODE t_mode) { C4DOS.Pa->LSL_SetMode(this, t_mode); }

		//----------------------------------------------------------------------------------------
		/// Removes a layer.
		/// @param[in] layer							The name of the layer to remove.
		//----------------------------------------------------------------------------------------
		void RemoveLayer(const maxon::String &layer) { C4DOS.Pa->LSL_RemoveLayer(this, layer); }

		//----------------------------------------------------------------------------------------
		/// Adds a layer.
		/// @param[in] layer							The name of the layer to add.
		//----------------------------------------------------------------------------------------
		void AddLayer(const maxon::String &layer) { C4DOS.Pa->LSL_AddLayer(this, layer); }

		//----------------------------------------------------------------------------------------
		/// Flushes all layers.
		//----------------------------------------------------------------------------------------
		void FlushLayers() { C4DOS.Pa->LSL_FlushLayers(this); }

		//----------------------------------------------------------------------------------------
		/// Sets the preview mode.
		/// @param[in] s									The preview mode to set.
		//----------------------------------------------------------------------------------------
		void SetPreviewMode(Int32 s) { C4DOS.Pa->LSL_SetPreviewMode(this, s); }

		//----------------------------------------------------------------------------------------
		/// Gets the preview mode.
		/// @return												The current preview mode.
		//----------------------------------------------------------------------------------------
		Int32 GetPreviewMode(void) { return C4DOS.Pa->LSL_GetPreviewMode(this); }
		
		//----------------------------------------------------------------------------------------
		/// Assignment operator. Copies the source @formatParam{layerset}.
		/// @param[in] layerset						The source layer set.
		/// @return												The assigned layer set to the left-operand.
		//----------------------------------------------------------------------------------------
		const LayerSet& operator = (const LayerSet &layerset);

		//----------------------------------------------------------------------------------------
		/// Equality operator. Checks if the set and @formatParam{layerset} are equal.
		/// @param[in] layerset						The layer set to compare with.
		/// @return												@trueIfOtherwiseFalse{the layer sets are equal}
		//----------------------------------------------------------------------------------------
		Bool operator == (const LayerSet &layerset) const { return C4DOS.Pa->LSL_operator_cmp(this, layerset); }

		//----------------------------------------------------------------------------------------
		/// Copies the layer set to @formatParam{dst}.
		/// @param[in] dst								The destination layer set.
		//----------------------------------------------------------------------------------------
		void CopyTo(LayerSet &dst) const { C4DOS.Pa->LSL_CopyTo(this, dst); }

		/// @name Alloc/Free
		/// @{

		//----------------------------------------------------------------------------------------
		/// @allocatesA{layer set data}
		/// @return												@allocReturn{layer set data}
		//----------------------------------------------------------------------------------------
		static LayerSet* Alloc() { return C4DOS.Pa->LSL_Alloc(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{layer set datas}
	/// @param[in,out] layerset				@theToDestruct{layer set data}
	//----------------------------------------------------------------------------------------
		static void Free(LayerSet *layerset) { C4DOS.Pa->LSL_Free(layerset); }

		/// @}
};

/// @markInternal
class LayerSetHelper
{
	private:
		LayerSetHelper();
		~LayerSetHelper();
	public:
		Bool Init(const Filename &fn, const LayerSet *selection) { return C4DOS.Pa->LSH_Init(this, fn, selection); }
		Bool EditLayerSet(const maxon::String &dialogtitle, LayerSet *layerset, LayerSet *layerseta) { return C4DOS.Pa->LSH_EditLayerSet(this, dialogtitle, layerset, layerseta); }
		Bool MergeLayerSet(const LayerSet &selection, BaseBitmap *bmp, Bool preview) { return C4DOS.Pa->LSH_MergeLayerSet(this, selection, bmp, preview); }

		static LayerSetHelper* Alloc() { return C4DOS.Pa->LSH_Alloc(); }
		static void Free(LayerSetHelper *lsh) { C4DOS.Pa->LSH_Free(lsh); }
};

/// @markInternal
inline Bool CalculateLockListResolution(BaseDocument *doc, const Filename &filename, Int32 *xres, Int32 *yres)
{
	return C4DOS.Pa->CLL_CalculateResolution(doc, filename, xres, yres);
}

/// @markInternal
inline Bool CalculateLockListFilename(BaseDocument *doc, Filename &fn, LayerSet *lsl)
{
	return C4DOS.Pa->CLL_CalculateFilename(doc, fn, lsl);
}
#endif

//----------------------------------------------------------------------------------------
/// LayerSet custom GUI (@ref CUSTOMGUI_LAYERSET).
//----------------------------------------------------------------------------------------
class LayerSetCustomGui : public BaseCustomGui<CUSTOMGUI_LAYERSET>
{
		LayerSetCustomGui();
		~LayerSetCustomGui();
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iLayerSetCustomGui
	{
	};
#else
	class iLayerSetCustomGui;
#endif

struct CustomGuiLayerSetLib : public BaseCustomGuiLib
{
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LAYERSET_H__
