#pragma once


enum kombat_kodes {
	KK_THROWING_DISABLED  = 1,
	KK_FREE_WEAPON = 2,
	KK_ARMED_AND_DANGEROUS = 4,
	KK_SILENT_KOMBAT = 8,
	KK_EXPLOSIVE_KOMBAT = 16,
	KK_RANDOM_WEAPONS = 32,
	KK_NO_POWER = 64,
	KK_MANY_WEAPONS = 128,
	KK_RANDPER_KOMBAT = 256,
	KK_NO_RAIN = 512,
	KK_WEAPON_KOMBAT = 1024,
	KK_NOOB_SAIBOT_MODE = 2048,
	KK_RED_RAIN = 4096,
	KK_NO_MAX_DAMAGE = 8192,
	KK_UNLIMITED_RUN = 16384,

};


// funcs

void manywep_message();