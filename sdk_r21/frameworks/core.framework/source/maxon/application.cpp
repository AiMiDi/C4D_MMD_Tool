#include "maxon/application.h"

namespace maxon 
{

Result<Url> Application::GetUrl(APPLICATION_URLTYPE urlType)
{
	if (urlType == APPLICATION_URLTYPE::CURRENT_MODULE_DIR)
		return g_maxon.GetUrl().GetDirectory();
	if (urlType == APPLICATION_URLTYPE::CURRENT_MODULE_RESOURCE_DIR)
	{
		Url tmp = g_maxon.GetUrl();
		iferr (Url corelibsDir = GetUrlI(APPLICATION_URLTYPE::CORELIBS_DIR))
			return err;
		
		if (tmp.GetDirectory() == corelibsDir)
		{
			Int pos;
			String moduleName = tmp.GetName();
			if (moduleName.FindLast('.', &pos))
				moduleName = moduleName.GetLeftPart(pos);
			return GetUrlI(APPLICATION_URLTYPE::RESOURCE_DIR) + "modules"_s + moduleName; 
		}
		
		return g_maxon.GetUrl().GetDirectory() + "res"_s;
	}

	return GetUrlI(urlType);
}

} // namespace maxon
