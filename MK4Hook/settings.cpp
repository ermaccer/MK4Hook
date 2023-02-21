#include "settings.h"
#include "IniReader.h"

bool eSettingsManager::bEnableFreeCamera;
bool eSettingsManager::bDisableBackground;
bool eSettingsManager::bDisableFatalityCamera;

void eSettingsManager::Init()
{
	CIniReader ini("");
	
	bEnableFreeCamera = ini.ReadBoolean("Settings", "bEnableFreeCamera", false);
	bDisableFatalityCamera = ini.ReadBoolean("Settings", "bDisableFatalityCamera", false);
	bDisableBackground = ini.ReadBoolean("Settings", "bDisableBackground", false);
}
