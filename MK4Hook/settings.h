#pragma once
#include "IniReader.h"

class eSettingsManager {
public:
	static bool bEnableFreeCamera;
	static bool bDisableBackground;
	static bool bDisableFatalityCamera;
	static void Init();
};