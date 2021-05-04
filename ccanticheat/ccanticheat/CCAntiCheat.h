#pragma once
#include <Windows.h>
#include <iostream>
#include <thread>
#include <TlHelp32.h>
#include "ChatColor.h"
#include "BanTypes.h"
#include "ConfigHandler.h"
#define PAPERFUNC_BanPlayer 0x7FA940DD1E32
#define PAPERFUNC_KickPlayer 0x7FE9312FA518
#define PAPERFUNC_SendMessageChat 0x7FFAB6C31E80
#define PAPERFUNC_MPlayerName 0x7FA890BB1C2E
#define PAPERFUNC_MPlayerHealth 0x7FA437BC4A37
#define MINECRAFT_PlayerVersionInfo 0x7FB162CE4A99
#define WINAPI_CheckExternals 0x370F2F3
#define JavaScanString 0x610A3A4

using namespace std;

namespace LuckPerms {
	class Permissions
	{
	public:
		enum class PermType {
			AllAdms,
			Admin,
			Developer,
			Operator,
			Moderator,
			Builder,
			Helper
		};
	};
}

enum ReceiversType
{
	AllAdms = LuckPerms::Permissions(AllAdms),
	Admin = LuckPerms::Permissions(Admin),
	Developer = LuckPerms::Permissions(Developer),
	Operator = LuckPerms::Permissions(Operator),
	Moder = LuckPerms::Permissions(Moder),
	Builder = LuckPerms::Permissions(Builder),
	Helper = LuckPerms::Permissions(Helper)
};

void BanPlayer(DWORD* playerName, int time, const char* reasonText, BanTypes banType)
{
	((void(__cdecl*)(DWORD*, int, const char*, BanTypes))0x7FA940DD1E32)(playerName, time, reasonText, banType); // time - mins
}

void SetMPlayerHealth(DWORD* playerName, int health)
{
	((void(__cdecl*)(DWORD*, int))0x7FA437BC4A37)(playerName, health); // time - mins
}

void KickPlayer(DWORD* playerName, const char* reasonText)
{
	((void(__cdecl*)(DWORD*, const char*))0x7FE9312FA518)(playerName, reasonText);
}

void JavaCheatDetect()
{
	
}

void SendMessageChat(ChatColors ChatColorType, const char* text, const char* receiversType)
{
	((void(__cdecl*)(ChatColors, const char*, const char*))0x7FFAB6C31E80)(ChatColorType, text, receiversType);
}

bool PlayerVersionInfoCmd(int version, const char* fullVersion)
{
	((bool(__cdecl*)(int, const char*))0x7FB162CE4A99)(version, fullVersion);
}

bool WinApiCheckExternals(bool isExternalsExist, int externalsCountIfYes, const char* externalName)
{
	((bool(__cdecl*)(bool, int, const char*))0x370F2F3)(isExternalsExist, externalsCountIfYes, externalName);
}

DWORD GetProcessByExeName(const wchar_t* ExeName)
{
	PROCESSENTRY32W pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32W);

	HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		MessageBoxW(NULL, L"Error CreateToolhelp32Snapshot", L"Error!", NULL);
		return false;
	}

	if (Process32FirstW(hProcessSnap, &pe32))
	{
		do
		{
			if (_wcsicmp(pe32.szExeFile, ExeName) == 0)
			{
				CloseHandle(hProcessSnap);
				return pe32.th32ProcessID;
			}
		} while (Process32NextW(hProcessSnap, &pe32));
	}

	CloseHandle(hProcessSnap);
	return 0;
}

ofstream fout("ac.log");

DWORD cheater = MPlayer; 

enum typeSpecifierAddress {
	MPlayer = 0x7FFCDF9E2591,
	MProjectile = 0x7FFCDF9E261E,
	MAttacker = 0x7FFCDF8EEEF4,
	MAttackResult = 0x7FFCD8E3B9AA
};

float mpX(0.01);
float mpY(0.1);
float mpZ(0.3);
float f(0.0);
float MHealth(0.012);

void LocalPlayerEntity()
{
	float LocalPlayerCoords = mpX-5 * mpY+10 * mpZ - 100; // Definition
}

void RocketPlayerEntity()
{
	float LocalPlayerCoords = mpX - 5 * mpY + 256 * mpZ - 100; // Definition
}

bool KillAura()
{
	if (MPlayer - MAttacker == 4.5f and MAttackResult == 3.7f or 3.7f*0.1f)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: KillAura", AllAdms);
		KickPlayer(&cheater, "CCAntiCheat: KillAura Detect");
		SendMessageChat(CHATCOLOR_RED, "Игрок кикнут за читинг: KillAura", AllAdms);
	}
}

void KillAuraDetect()
{
	if (KillAura() == true)
	{
		fout << "PLAYER: &cheater . DETECT: KILLAURA. DEFEATED: TRUE. DEFEAT-TYPE: KICK\n";
	}
}

bool Impact()
{
	WinApiCheckExternals(true, 1, "Impact Cheat Client");
	if (WinApiCheckExternals(true, 1, "Impact Cheat Client") == true)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Impact Cheat Client", AllAdms);
		BanPlayer(&cheater, 30, "Impact Cheat Detect", BANTYPE_IP);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по IP на 30 минут по причине: Impact Cheat Detect", AllAdms);
	}
}

void ImpactDetect()
{
	if (Impact() == true)
	{
		fout << "PLAYER: &cheater . DETECT: IMPACT. DEFEATED: TRUE. DEFEAT-TYPE: IPBAN 30 MIN.\n";
	}
}

bool Huzuni()
{
	WinApiCheckExternals(true, 1, "Huzuni CC v.");
	if (WinApiCheckExternals(true, 1, "Huzuni CC v.") == true)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Huzuni Cheat Client", AllAdms);
		BanPlayer(&cheater, 30, "Huzuni Cheat Detect", BANTYPE_IP);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по IP на 30 минут по причине: Huzuni Cheat Detect", AllAdms);
	}
}

void HuzuniDetect()
{
	if (Huzuni() == true)
	{
		fout << "PLAYER: &cheater . DETECT: HUZUNI. DEFEATED: TRUE. DEFEAT-TYPE: IPBAN 30 MIN.\n";
	}
}

bool FL()
{
	PlayerVersionInfoCmd(true, "1.15.2-FLauncher");
	if (PlayerVersionInfoCmd(true, "Impact Cheat Client"))
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: FLauncher", AllAdms);
		BanPlayer(&cheater, 30, "FLauncher Detect", BANTYPE_IP);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по IP на 30 минут по причине: FLauncher Detect", AllAdms);
	}
}

void FLDetect()
{
	if (FL() == true)
	{
		fout << "PLAYER: &cheater . DETECT: FLAUNCHER. DEFEATED: TRUE. DEFEAT-TYPE: IPBAN 30 MIN.\n";
	}
}

bool Kamiblue()
{
	WinApiCheckExternals(true, 1, "Kami blue");
	if (WinApiCheckExternals(true, 1, "Kami blue") == true)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Kami blue", AllAdms);
		BanPlayer(&cheater, 30, "Kami Blue Detect", BANTYPE_IP);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по IP на 30 минут по причине: Kami Blue Detect", AllAdms);
	}
}

void KamiblueDetect()
{
	if (Kamiblue() == true)
	{
		fout << "PLAYER: &cheater . DETECT: KAMI BLUE. DEFEATED: TRUE. DEFEAT-TYPE: IPBAN 30 MIN.\n";
	}
}

bool Aristois()
{
	WinApiCheckExternals(true, 1, "Aristois");
	if (WinApiCheckExternals(true, 1, "Aristois") == true)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Aristois Client", AllAdms);
		BanPlayer(&cheater, 30, "Aristois Detect", BANTYPE_IP);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по IP на 30 минут по причине: Aristois Detect", AllAdms);
	}
}

void AristoisDetect()
{
	if (Aristois() == true)
	{
		fout << "PLAYER: &cheater . DETECT: ARISTOIS. DEFEATED: TRUE. DEFEAT-TYPE: IPBAN 30 MIN.\n";
	}
}

bool Rocket()
{
	if (MAttacker + MPlayer == 0.46f and LocalPlayerEntity == RocketPlayerEntity)
	{
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Rocket", AllAdms);
		BanPlayer(&cheater, 60, "Rocket Detect", BANTYPE_SERIAL);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по HWID на 60 минут по причине: Rocket Detect", AllAdms);
	}
}

void RocketDetect()
{
	if (Rocket() == true)
	{
		fout << "PLAYER: &cheater . DETECT: ROCKET. DEFEATED: TRUE. DEFEAT-TYPE: HWIDBAN 60 MIN.\n";
	}
}

float MHealthUpd = 0.31f*0.43f;

bool HealthHacks()
{
	if (MHealth == 0.80f and MHealthUpd == 100.0f)
	{
		SetMPlayerHealth(&cheater, MHealth);
		SendMessageChat(CHATCOLOR_RED, "Игрок подозревается в читинге: Health Hacks", AllAdms);
		BanPlayer(&cheater, 25, "Classic Health Hacks Detect", BANTYPE_SERIAL);
		SendMessageChat(CHATCOLOR_RED, "Игрок забанен по HWID на 25 минут по причине: Classic Health Hacks Detect", AllAdms);
	}
}

void HealthHacksDetect()
{
	if (HealthHacks() == true)
	{
		fout << "PLAYER: &cheater . DETECT: HEALTH HACKS. DEFEATED: TRUE. DEFEAT-TYPE: HWIDBAN 25 MIN.\n";
	}
}

bool ProcessHacker()
{
	GetProcessByExeName(L"ProcessHacker.exe");
	if (GetProcessByExeName(L"ProcessHacker.exe") == true)
	{
		system("taskkill /F /T /IM ProcessHacker.exe");
		system("taskkill /F /T /IM javaw.exe");
		printf("You cannot play with hacking programs, like Process Hacker!");
		system("pause");
	}
}

void ProcessHackerDetect()
{
	if (ProcessHacker() == true)
	{
		fout << "PLAYER: UNKNOWN. DETECT: PROCESS HACKER. DEFEATED: TRUE. DEFEAT-TYPE: PROCESS TERMINATED\n";
	}
}

bool CheatEngine()
{
	GetProcessByExeName(L"cheatengine-x86_64-SSE4-AVX2.exe.exe");
	if (GetProcessByExeName(L"cheatengine-x86_64-SSE4-AVX2.exe.exe") == true)
	{
		system("taskkill /F /T /IM cheatengine-x86_64-SSE4-AVX2.exe.exe");
		system("taskkill /F /T /IM javaw.exe");
		printf("You cannot play with hacking programs, like Cheat Engine!");
		system("pause");
	}
}

void CheatEngineDetect()
{
	if (CheatEngine() == true)
	{
		fout << "PLAYER: UNKNOWN. DETECT: CHEAT ENGINE. DEFEATED: TRUE. DEFEAT-TYPE: PROCESS TERMINATED\n";
	}
}
