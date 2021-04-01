#include <iostream>
#include <fstream>
#include <Windows.h>
#if !defined(__cplusplus)
#error Visual C++ Compiler Required!
#endif
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define DeleteFile DeleteFileA
#pragma comment(lib, "cfgCC.lib")
#pragma comment(lib, "hookCreepCrafter.lib")
#pragma warning(disable: 4311)
#pragma warning(disable: 4351)
#pragma warning(disable: 4376)

/*
	Config Handler Module by k0t0ff
	This module is open-source and it takes part in CCAntiCheat 
	Link for repository: https://github.com/kotoff-studio/CCAntiCheat
*/

using namespace std;

bool configExist = true;
bool configNeedToReload = false;

namespace ACConfig {

	void Create()
	{
		ofstream config("ac.cfg");
		config << "AC-Enabled: true\n";
		config << "MessageViewers: MDMisha, KotoffStudio, Agent_182, KceHoHc, HunterNight, nightfugue, MegaZont, Junipers, Crystalit, IIIUIIIOK, Ciklop75, Live95_Saqzinsia, IloveOksana\n";
		config << "Sorting: true\n";
		config << "Auto-ban: false\n";
		config << "Server-IP: creepcrafter.com\n";
		config << "Server-core: Paper\n";
		config << "Server-version: 1.15.2\n";
		config.close();
	}

	void Reset()
	{
		DeleteFile("ac.cfg");
		ofstream config("ac.cfg");
		config << "AC-Enabled: \n";
		config << "MessageViewers: \n";
		config << "Sorting: \n";
		config << "Auto-ban: \n";
		config << "Server-IP: \n";
		config << "Server-core: \n";
		config << "Server-version: \n";
		config.close();
	}

	void Delete()
	{
		DeleteFile("ac.cfg");
	}
}

void ConfigFuncs()
{
	if (!configExist)
	{
		system("title Config Manager");
		printf("[ - ] Config is not exist!\n");
		ACConfig::Create();
		printf("[ + ] Config created and loaded!\n");
		system("pause");
	}

	if (configExist)
	{
		system("title Config Manager");
		printf("[ + ] Config is already exists!\n");
		Sleep(2000);
		printf("[ ? ] Config Functions:\n");
		printf("END - reset config (this action delete all settings and may cause server restart!)\n");
		Sleep(1000);
		printf("NUMPAD8 - delete config (for reinstalling AntiCheat or updating for a new version)\n");
		Sleep(2000);
		system("pause");
	}

	if (GetAsyncKeyState(VK_END))
	{
		printf("[ + - ] Resetting config to the defaults..\n");
		ACConfig::Reset();
		Sleep(4500);
		printf("[ + ] Config successfully resetted to the defaults!\n");
		system("PAUSE");
	}

	if (GetAsyncKeyState(VK_NUMPAD8))
	{
		printf("[ - ] Deleting config...\n");
		ACConfig::Delete();
		printf("[ - ] Config successfully deleted!\n");
		system("pause");
	}
}