#pragma once

#include <types.h>
#include <wii/types.h>

namespace spm::mario {

enum
{
    GRAV_DOWN,
    GRAV_UP,
    GRAV_LEFT,
    GRAV_RIGHT
};

#define MARIO_GRAVITY_MAX 4

enum
{
    PLAYER_MARIO,
    PLAYER_PEACH,
    PLAYER_BOWSER,
    PLAYER_LUIGI
};

struct CharacterProperty
{
	float hitboxWidth;
	float hitboxHeight;
	float initSpeed;
	float maxSpeed;
	float unk;
};

struct MarioWork
{
    u32 flag0;
    u32 flag4;
    u32 flag8;
    u32 flagc;
    u32 flag10;
    u32 flag14;
    u8 unknown_0x18[0x2c - 0x18];
	u16 state;
	u8 unknown_0x2e[0x33 - 0x2e];
	u8 ctrl;
	u8 keyOff;
	u16 cutsceneCount;
	s8 character;
    u8 unknown_0x39[0x5c - 0x39];
    wii::Vec3 position;
    u8 unknown_0x68[0xbc - 0x68];
	wii::Vec3 scale;
	wii::Vec3 unkScale;
	u8 unknown_0xc8[0x120 - 0xd4];
    s32 camId;
    u8 unknown_0x124[0x128 - 0x124];
	wii::Vec2 frameBufferPos;
	u8 unknown_0x130[0x14c - 0x130];
    float initSpeed;
    float maxSpeed;
	u8 unknown_0x154[0x158 - 0x154];
	float unkProp;
	u8 unknown_0x15c[0x194 - 0x15c];
	float scaledHitboxWidth;
	float scaledHitboxHeight;
	float hitboxWidth;
	float hitboxHeight;
	u8 unknown_0x1a4[0x3d0 - 0x1a4];
	float scalarSpeed;
	u8 unknown_0x3d4[0x3d8 - 0x3d4];
	wii::Vec3 respawnPosition;
	u8 unknown_0x3e4[0x3e8 - 0x3e4];
	float megaStarTimer;
	u8 unknown_0x3ec[0xe88 - 0x3ec];
	float statusTimer;
	u8 unknown_0xe8c[0x1360 - 0xe8c];
	s32 gravityType;
	u8 unknown_0x1364[0x1550 - 0x1364];
	s32 paneNum;
    u8 unknown_0x1554[0x156c - 0x1554];
};
static_assert(sizeof(MarioWork) == 0x156c);

void marioSpawnPlayer();
s32 marioGetGravity();
MarioWork* marioGetPtr();

extern "C" {
	extern CharacterProperty characterProperties[4];
	
	extern wii::Vec3 npcScale;
	extern wii::Vec3 Vec3_8033086c;

	extern MarioWork marioWork;
	extern bool marioCtrlOffChk();
	extern bool marioKeyOffChk();
	extern void marioSetGravity(s32 type);
	
	extern void FUN_8013146c();
	extern void marioSpawnPlayer_o();
	extern void marioGetGravity_o();
	extern MarioWork * marioGetPtr_o();

}
}
