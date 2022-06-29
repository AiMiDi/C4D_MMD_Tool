/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white
Date:			2022/6/30
File:			vmd_loader_data.h
Description:	vmd data loader

**************************************************************************/

#ifndef _VMD_LOADER_DATAH_H_
#define _VMD_LOADER_DATAH_H_

#include <c4d_filterdata.h>

/**
* @brief VMD data loader scene loader plugins,inherit from SceneLoaderData
*/
class VMDLoaderData : public SceneLoaderData
{
public:
	virtual Bool		Identify	(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size);
	
	virtual FILEERROR	Load		(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags, maxon::String* error, BaseThread* bt);
	
	static NodeData*	Alloc()
	{
		return (NewObjClear(VMDLoaderData));
	}

};

#endif // !_VMD_LOADER_DATAH_H_
