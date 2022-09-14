#ifndef TYPEVIEWER_HELPER_H__
#define TYPEVIEWER_HELPER_H__

#include "maxon/array.h"
#include "maxon/hashmap.h"
#include "maxon/tuple.h"

namespace maxon
{

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)

	// Helper declaration for natvis file. Used to avoid some long ugly type case in natvis.
	// Also not all module debug informations contains the types below. So it can happen
	// that natvis would generate error when casting to some of the types below depending on the module being debugged.
	// So by adding a helper definition, we are sure whatever module is being debugged, those types are known.
	// Definition here would cause some crash cases on shutdown. Keep the definitions in a module with Global<>.

	struct DataDictionaryNatVisHelper : public HashMap<Data, Data> {};

	struct InternedIdDataTupleNatVisHelper : public Tuple<InternedId, Data> {};

	struct InternedIdPairArrayNatVisHelper : public Array<Tuple<InternedId, InternedId>> {};
	struct IdDataTupleArrayNatVisHelper : public Array<Tuple<Id, Data>> {};
#endif

} // namespace maxon


#endif // TYPEVIEWER_HELPER_H__
