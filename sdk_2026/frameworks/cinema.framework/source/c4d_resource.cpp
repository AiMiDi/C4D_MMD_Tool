#include "c4d_resource.h"
#include "c4d_gui.h"
#include "maxon/application.h"

#ifndef __API_INTERN__
#include "c4d_memory.h"
#include "c4d_file.h"
#include "lib_description.h"

namespace cinema
{

Bool RegisterDescription(Int32 id, const maxon::String& idstr, LocalResource* res)
{
	return Description_Register(id, idstr, res ? res : g_resource.Get());
}

} // namespace cinema

#else

#include "ge_file.h"
#include "ge_memory.h"
#include "lib_description.h"
#include "res_symbols.h"

namespace cinema
{
Bool RegisterDescription(Int32 id, const maxon::String& idstr, LocalResource* res)
{
	return Description_Register(id, idstr, nullptr);
}
} // namespace cinema

#include "operatingsystem.h"
#endif

namespace cinema
{

GeResource::GeResource()
{
	lr = nullptr;
	state	 = false;
	initfn = nullptr;
	glob = false;
}

GeResource::~GeResource()
{
	Free();
}

void GeResource::Free()
{
	if (glob)
		return;

	if (lr)
	{
		C4DOS_Lr->Free(lr, _regardIsStopped);
		lr = nullptr;
	}

	if (initfn)
		DeleteObj(initfn);
}

Filename GeGetPluginResourcePath()
{
	iferr_scope_handler
	{
		err.DbgStop();
		return Filename();
	};

#ifdef __API_INTERN__
	return GetResourcePath();
#else
	extern Filename* path_storage;

#ifdef MAXON_TARGET_IOS // System
	Filename tmp = (path_storage != nullptr) ? *path_storage : GeGetPluginPath();
	tmp.ClearSuffixComplete();

	maxon::Url uName = (maxon::Application::GetUrl(maxon::APPLICATION_URLTYPE::RESOURCE_DIR) + "modules"_s + tmp.GetFileString()) iferr_return;
	Filename   fName = MaxonConvert(uName);
	return fName;
#else
	maxon::Url corelibsUrl = maxon::Application::GetUrl(maxon::APPLICATION_URLTYPE::CORELIBS_DIR) iferr_ignore("missing error handling");

	// internal modules have different resource structure
	if (path_storage && GeGetPluginPath() == MaxonConvert(corelibsUrl))
	{
		Filename tmp = *path_storage;
		tmp.ClearSuffixComplete();
		return GeGetStartupPath() + Filename("resource") + Filename("modules") + tmp.GetFileString();
	}
#endif

	// regular plugins
	return GeGetPluginPath() + Filename("res");
#endif
}

Bool GeResource::Init()
{
	return Init(GeGetPluginResourcePath());
}

Bool GeResource::Init(const Filename& path, Bool regardIsStopped)
{
	_regardIsStopped = regardIsStopped;
	if (!initfn)
	{
		initfn = NewObjClear(Filename, path);
		if (!initfn)
			return false;
	}

	if (state)
		return lr != nullptr;

	lr = C4DOS_Lr->Alloc((Filename*)&path);
	state = true;
	return lr != nullptr;
}

Bool GeResource::InitAsGlobal()
{
	glob = true;
	lr = C4DOS_Lr->GetCinemaResource();
	return lr != nullptr;
}

Bool GeResource::ReloadResource()
{
	if (glob)
		return true;
	if (!initfn)
		return false;
	return C4DOS_Lr->ReloadResource(lr, initfn);
}

const String& GeResource::LoadString(Int32 id)
{
#ifndef __API_INTERN__
	if (!lr)
	{
		if (t_C4DOS == nullptr)
		{
			// This might happen when a plugin is not initialized (missing license etc. but still tries to load strings).
			static maxon::StringInterface* nada = nullptr;
			return *(String*) &nada;
		}
		return *C4DOS_St->Default;
	}
	return C4DOS_Lr->LoadString(lr, id);
#else
	return GeLoadString(id);
#endif
}

#ifndef __API_INTERN__
GeResource g_resource;

void FreeResource()
{
	g_resource.Free();
}

const String& GeLoadString(Int32 id)
{
	return g_resource.LoadString(id);
}

String GeLoadString(Int32 id, const maxon::String& p1)
{
	Int32	 pos;
	String str = g_resource.LoadString(id);
	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p1);
	return str;
}

String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2)
{
	Int32	 pos;
	String str = g_resource.LoadString(id);
	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p1);
	pos += (Int32)p1.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p2);
	return str;
}

String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2, const maxon::String& p3)
{
	Int32	 pos;
	String str = g_resource.LoadString(id);
	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p1);
	pos += (Int32)p1.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p2);
	pos += (Int32)p2.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p3);
	return str;
}

String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2, const maxon::String& p3, const maxon::String& p4)
{
	Int32	 pos;
	String str = g_resource.LoadString(id);
	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p1);
	pos += (Int32)p1.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p2);
	pos += (Int32)p2.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p3);
	pos += (Int32)p3.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p4);
	return str;
}

String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2, const maxon::String& p3, const maxon::String& p4, const maxon::String& p5)
{
	Int32	 pos;
	String str = g_resource.LoadString(id);
	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p1);
	pos += (Int32)p1.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p2);
	pos += (Int32)p2.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p3);
	pos += (Int32)p3.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p4);
	pos += (Int32)p4.GetLength();

	if (!str.FindFirst("#", &pos))
		return String();
	str.Delete(pos, 1);
	str.InsertDeprecated(pos, p5);
	return str;
}

BaseContainer* GetMenuResource(const maxon::String& menuname)
{
	return C4DOS_Lr->GetMenuResource(menuname);
}

const GeData* SearchPluginMenuResource(const maxon::String& identifier)
{
	BaseContainer* bc = GetMenuResource(String("M_EDITOR"));
	if (!bc)
		return nullptr;

	Int32								 id;
	const GeData *			 last = nullptr, *dat;
	BrowseConstContainer browse(bc);
	while (browse.GetNext(&id, &dat))
	{
		if (id == MENURESOURCE_SUBMENU)
		{
			const BaseContainer* dc = dat->GetContainer();
			if (dc && dc->GetString(MENURESOURCE_SUBTITLE) == identifier)
			{
				last = dat;
				break;
			}
		}
	}
	return last;
}

// Search through child menus
const GeData* SearchPluginSubMenuResource(const maxon::String& identifier, BaseContainer* bc)
{
	if (!bc)
	{
		bc = GetMenuResource(String("M_EDITOR"));
		if (!bc)
			return nullptr;
	}

	Int32						id;
	const GeData*					last = nullptr, *dat;
	BrowseConstContainer browse(bc);
	while (browse.GetNext(&id, &dat))
	{
		if (id == MENURESOURCE_SUBMENU)
		{
			const BaseContainer* dc = dat->GetContainer();
			if (dc && dc->GetString(MENURESOURCE_SUBTITLE) == identifier)
			{
				last = dat;
				break;
			}
		}
		else if (id == MENURESOURCE_COMMAND)
		{
			if (dat && dat->GetString() == identifier)
			{
				last = dat;
				break;
			}
		}
	}
	return last;
}


Bool SearchMenuResource(const BaseContainer* bc, const maxon::String& searchstr)
{
	if (!bc)
		return false;

	BrowseConstContainer browse(bc);

	Int32		id	= 0;
	const GeData* dat = nullptr;

	while (browse.GetNext(&id, &dat))
	{
		if (id == MENURESOURCE_SUBMENU || id == MENURESOURCE_STRING)
		{
			if (SearchMenuResource(dat->GetContainer(), searchstr))
				return true;
		}
		else if (id == MENURESOURCE_COMMAND)
		{
			if (dat->GetString() == searchstr)
				return true;
		}
	}
	return false;
}

void UpdateMenus()
{
	C4DOS_Lr->UpdateMenus();
}
#endif

} // namespace cinema
