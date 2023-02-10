/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/1
File:			vmd_loader_data.h
Description:	vmd data loader

**************************************************************************/

#ifndef _VMD_LOADER_DATAH_H_
#define _VMD_LOADER_DATAH_H_

#include "pch.h"

/**
* @brief VMD data loader scene loader plugins,inherit from SceneLoaderData
*/
class VMDLoaderData : public SceneLoaderData
{
	Bool m_is_camera = FALSE;
public:
	Bool Identify(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size) override;

	FILEERROR Load(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags, maxon::String* error, BaseThread* bt) override;
	
	static NodeData* Alloc()
	{
		return NewObjClear(VMDLoaderData);
	}

};

#endif // !_VMD_LOADER_DATAH_H_
