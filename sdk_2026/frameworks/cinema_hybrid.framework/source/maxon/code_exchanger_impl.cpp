#define MAXON_UNITY_BUILD_EXCLUDE

#define MAXON_DEPENDENCY_ENABLE

#include "maxon/code_exchanger.h"
#include "maxon/websocket_json_codeexchanger.h"

#include "maxon/configuration.h"
MAXON_CONFIGURATION_BOOL(g_enableUvPolygonObject, false, maxon::CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable storing UV tag data with topology as a PolygonObject.");
MAXON_CONFIGURATION_BOOL(g_enableNewUvEditor, false, maxon::CONFIGURATION_CATEGORY::DEVELOPMENT, "Enable the new UV editor.");
MAXON_CONFIGURATION_BOOL(g_seamsTagEnabled, false, maxon::CONFIGURATION_CATEGORY::DEVELOPMENT, "Activate seams edge selection commands");

namespace maxon
{
// The active Code Exchanger, don't access it directly use GetActiveCE() and StoreActiveCE() instead for a safe access.
static CodeExchangerRef g_activeCE = CodeExchangerRef::DefaultValue();

Result<CodeExchangerRef> GetActiveCE()
{
	if (MAXON_LIKELY(g_activeCE))
		return g_activeCE;

	return IllegalStateError(MAXON_SOURCE_LOCATION, "No active CE"_s);
}

Result<void> StoreActiveCE(CodeExchangerRef ce)
{
	iferr_scope;
	CodeExchangerRef activeCe = GetActiveCE() iferr_return;

	if (ce == activeCe)
		return OK;

	if (activeCe.IsRunning())
	{
		activeCe.Stop() iferr_return;
		iferr (ce.Start())
		{
			activeCe = CodeExchangerRef::DefaultValue();
		}
	}

	activeCe = ce;
	return OK;
}

static Result<void> InitActiveCE()
{
	iferr_scope;

	iferr (g_activeCE = WebSocketJsonCodeExchanger().Create())
	{
		g_activeCE = maxon::CodeExchangerRef::DefaultValue();
	}

	return maxon::OK;
}

static void ClearActiveCE()
{
	// delete global string
	if (g_activeCE)
		g_activeCE = CodeExchangerRef::DefaultValue();
}

MAXON_INITIALIZATION(InitActiveCE, ClearActiveCE);


}
