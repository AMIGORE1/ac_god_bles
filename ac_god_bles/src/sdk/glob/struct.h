#pragma once
#include <Windows.h>
#include "../math/math.h"


struct OCurrentWeapon {
	int CurrentWeaponAmmo;			//0x0 - 0x4
	char buffer[80];				//0x0 - 0x54
	int KickBack;					//0x54 - 0x58
	char buffer2[6];				//0x58 - 0x5E
	uint16_t RecoilOne;				//0x5E
	uint16_t RecoilTwo;				//0x60
};

struct OInventory {
	char Name[12];							// 0x0 - 0xC
	OCurrentWeapon* CurrentWeaponRecoil;	// 0xC - 0x10
	OCurrentWeapon* CurrentWeapon;			//0x10 - 0x14
	OCurrentWeapon* CurrentWeaponMain;		//0x14 - 0x20
};

class Entity
{
public:
	char pad_0000[4];					//0x0000 - 0x04
	Vector3 HeadPos;					//0x0004 - 0x10
	Vector3 Velocity;					//0x0010 - 0x1C
	char pad_001C[12];					//0x001C - 0x28
	Vector3 PlayerPos;					//0x0028 - 0x34
	Vector3 ViewAngles;					//0x0034 - 0x40
	char pad_idk[25];					//0x40 - 0x5D
	int32_t OnGround;					//0x5D - 0x61
	char pad_idk2[19];					//0x61 -0x74
	uint16_t SpeedHacks;				//0x74 - 0x76
	uint16_t NoClip;					//0x76 - 0x78
	char pad_0040[116];					//0x78 - 0xEC
	int32_t PlayerHealth;				//0xEC - 0xF0
	int32_t Armor;						//0x00F0
	char pad_00F4[20];					//0x00F4
	int32_t PistolAmmo2;				//0x0108
	char pad_010C[16];					//0x010C
	int32_t AssaultRifleAmmo2;			//0x011C
	char pad_0120[12];					//0x0120
	int32_t PistolAmmo1;				//0x012C
	char pad_0130[16];					//0x0130
	int32_t AssaultRifleAmmo1;			//0x0140
	char pad_0144[12];					//0x0144
	int32_t PistolReloadDelay;			//0x0150
	char pad_0154[16];					//0x0154
	int32_t AssaultRifleReloadDelay;	//0x0164
	char pad_0168[12];					//0x0168
	int32_t AmountOfShotsFired;			//0x0174
	char pad_0178[100];					//0x0178
	int32_t BlueTeamScore;				//0x01DC
	char pad_01E0[37];					//0x01E0
	char Name[16];						//0x0205
	char pad_0215[247];					//0x0215
	int32_t Team;						//0x030C
	char pad_030C[8];					//0x314
	int32_t IsAlive;					//0x318 - 0x31C
	char pad_0302[76];					//0x368
	OInventory* Inventory;


};
