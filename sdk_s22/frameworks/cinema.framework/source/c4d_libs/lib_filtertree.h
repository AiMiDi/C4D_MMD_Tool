/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_FILTERTREE_H__
#define LIB_FILTERTREE_H__

#include "c4d_library.h"

/// @addtogroup group_filtertreelibrary Filter Tree
/// @ingroup group_library
/// @{

/// Filter Tree library ID.
#define ID_LIB_FILTERTREE				200000124

/// @addtogroup ManagerType
/// @ingroup group_enumeration
/// @{
enum ManagerType
{
	SB_MANAGER	= 1,			///< Scene browser.
	TL_MANAGER	= 2,			///< Timeline.
	MAT_MANAGER	= 3,			///< %Material manager.

	DUM_MANAGER
};
/// @}

/// @addtogroup ManagerNum
/// @ingroup group_enumeration
/// @{
enum ManagerNum
{
	MANAGER_NOTOK	=	 -1,			///< N/A.
	MANAGER_1			=		0,			///< Manager 1.
	MANAGER_2			=		1,			///< Manager 2.
	MANAGER_3			=		2,			///< Manager 3.
	MANAGER_4			=		3,			///< Manager 4.

	DUM_MANNI
};
/// @}

class ManagerInfo
{
		friend void iUpdateManagerInfo(ManagerInfo *minfo);

	private:
		ManagerType	type;
		ManagerNum	num;
		NBIT				foldbit;

	private:
		Int32				imanagernum; // Cached id

		void UpdateManagerInfo();

	public:
		//----------------------------------------------------------------------------------------
		/// Default constructor.
		//----------------------------------------------------------------------------------------
		ManagerInfo() : type(DUM_MANAGER), num(MANAGER_NOTOK), foldbit(NBIT::NONE) { UpdateManagerInfo(); }

		//----------------------------------------------------------------------------------------
		/// Constructor.
		/// @param[in] t_type							The manager type: @enumerateEnum{ManagerType}
		/// @param[in] t_num							The manager number: @enumerateEnum{ManagerNum}
		/// @param[in] t_foldbit					The fold bit. See @ref NBIT.
		//----------------------------------------------------------------------------------------
		ManagerInfo(ManagerType t_type, ManagerNum t_num, NBIT t_foldbit) : type(t_type), num(t_num), foldbit(t_foldbit) { UpdateManagerInfo(); }

		//----------------------------------------------------------------------------------------
		/// Gets the manager type.
		/// @return												The manager type: @enumerateEnum{ManagerType}
		//----------------------------------------------------------------------------------------
		ManagerType GetManagerType() const { return type; }

		//----------------------------------------------------------------------------------------
		/// Gets the manager number.
		/// @return												The manager number: @enumerateEnum{ManagerNum}
		//----------------------------------------------------------------------------------------
		ManagerNum GetManagerNum() const { return num; }

		//----------------------------------------------------------------------------------------
		/// Gets the fold bit.
		/// @return												The fold bit. See @ref NBIT.
		//----------------------------------------------------------------------------------------
		NBIT GetFoldBit() const { return foldbit; }

		//----------------------------------------------------------------------------------------
		/// Gets the internal manager number.
		/// @return												The internal manager number.
		//----------------------------------------------------------------------------------------
		Int32 GetMNum() const { return imanagernum; }

		//----------------------------------------------------------------------------------------
		/// Set the manager type.
		/// @param[in] t_type							The manager type: @enumerateEnum{ManagerType}
		//----------------------------------------------------------------------------------------
		void SetManagerType(ManagerType t_type) { if (t_type == type) return; type = t_type; UpdateManagerInfo(); }

		//----------------------------------------------------------------------------------------
		/// Set the manager number.
		/// @param[in] t_num							The manager number: @enumerateEnum{ManagerNum}
		//----------------------------------------------------------------------------------------
		void SetManagerNum(ManagerNum t_num) { if (t_num == num) return; num = t_num; UpdateManagerInfo(); }

		//----------------------------------------------------------------------------------------
		/// Sets the fold bit.
		/// @param[in] t_bit							The fold bit, or @ref NOTOK. See @ref NBIT.
		//----------------------------------------------------------------------------------------
		void SetFoldBit(NBIT t_bit) { if (t_bit == foldbit) return; foldbit = t_bit; UpdateManagerInfo(); }
};

//----------------------------------------------------------------------------------------
/// Shows objects of a specific type in manager @formatParam{minfo}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] art								The object type, i.e. C4DAtom::GetClassification().
/// @param[in] minfo							The manager information.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ShowObjectArt(BaseDocument *doc, Int32 art, const ManagerInfo &minfo);

//----------------------------------------------------------------------------------------
/// Checks if an object is hidden in manager @formatParam{minfo}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] bl									The object to check.
/// @param[in] minfo							The manager information.
/// @return												@trueIfOtherwiseFalse{the object is hidden}
//----------------------------------------------------------------------------------------
Bool IsObjectHidden(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo);

//----------------------------------------------------------------------------------------
/// Checks if an object is searchable in manager @formatParam{minfo}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] bl									The object to check.
/// @param[in] minfo							The manager information.
/// @return												@trueIfOtherwiseFalse{the object is searchable}
//----------------------------------------------------------------------------------------
Bool IsObjectSearchable(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo);

//----------------------------------------------------------------------------------------
/// Checks if a layer is hidden in manager @formatParam{minfo}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] op									The layer to check.
/// @param[in] minfo							The manager information.
/// @return												@trueIfOtherwiseFalse{the layer is hidden}
//----------------------------------------------------------------------------------------
Bool IsLayerHidden(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo);

//----------------------------------------------------------------------------------------
/// Hides a layer in manager @formatParam{minfo}.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] op									The layer to check.
/// @param[in] minfo							The manager information.
/// @param[in] hide								@formatConstant{true} to hide, @formatConstant{false} to show.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool SetLayerHidden(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo, Bool hide);

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
Bool BuildFilterList(BaseDocument *doc);

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct FilterTreeLib : public C4DLibrary
{
	Bool					(*ShowObjectArt				)(BaseDocument *doc, Int32 art,       const ManagerInfo &minfo);
	Bool					(*IsObjectHidden			)(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo);
	Bool					(*IsObjectSearchable	)(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo);
	Bool					(*IsLayerHidden				)(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo);
	Bool					(*SetLayerHidden			)(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo, Bool hide);
	Bool					(*BuildFilterList			)(BaseDocument *doc);
	void					(*UpdateManagerInfo		)(ManagerInfo *minfo);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_FILTERTREE_H__
