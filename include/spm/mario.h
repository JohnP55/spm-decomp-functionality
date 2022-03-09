#pragma once
#include "spm/hitdrv.h"

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

enum PlayerCharacter {
    PLAYER_MARIO,
    PLAYER_PEACH,
    PLAYER_BOWSER,
    PLAYER_LUIGI
};

enum MiscFlagValues {
	SWIMMING = 0x100,
	DOTTIE_SMALL = 0x4000,
    SWIM_SPACE = 0x400000,
    CARRIE_RIDE = 0x800000
};

enum MarioStates {
	IDLE=0,
	ACCEL=1,
	RUN=2,
	JUMP_ASC=3,
	CROUCH=4,
	SLIDE=5,
	SPRING=6,
	JUMP_DESC=10,
	THUDLEY_GP=14,
	THUDLEY_LAND=15,
	CUDGE_USE=16,
	LUIGI_CROUCH=17,
	SLIM_USE=18,
	HAZARD_RESPAWN=21,
	HAZARD_RESPAWN_ANIM_END=22,
	DEATH=24,
	FALL_RESPAWN=25,
	MIDAIR_FLIP=26,
	INVINCIBILITY_FRAMES=27,
	INVINCIBILITY_FRAMES_2=28,
    SCARED_ANIM=29,
	LIFE_SHROOM_REVIVE=30,
    SHAKE_PROMPT=31,
	SLEEP_SHAKE_PROMPT=32,
	FROZEN_SHAKE_PROMPT=33,
	THOREAU_USE=36,
	BOOMER_USE=37,
	FLEEP_USE=38,
	DOTTIE_SHRINK=39,
	DOTTIE_GROW=40,
	PICCOLO_USE=41,
	BARRY_USE=42,
	CARRIE_ON=44,
	CARRIE_OFF=45,
	MEGA_STAR_TRANSFORM=68,
	SWIM=69,
    SPACE_SWIM=70,
    CHARACTER_SWAP=71,
	PIXL_SWAP=72,
	FLIP=73,
    PARASOL_GLIDE=74,
	PARASOL_GUARD=75,
    BOWSER_FIRE=76
};

struct MarioJumpFallPara {
	u8 unk_0x00[0x08-0x0];
    float speedY;
    float jumpAnimTimer;
    float jumpAccel;
	u8 unk_0x14[0x34-0x14];
};
static_assert(sizeof(MarioJumpFallPara) == 0x34);

struct CharacterProperty
{
	float hitboxWidth;
	float hitboxHeight;
	float initSpeed;
	float maxSpeed;
	float swimmingSpeed;
};

/*
    Returns true if deleted, false otherwise
    Commands:
        1 start
        2 restart?
*/
//typedef bool (MarioStatusMainFunc)(MarioStatus * status, wii::Vec3 * iconPos, s32 command);

/*
    Returns true if it should be deleted, false otherwise
    Return is ignored except in marioStatusDeleteAll
*/ 
//typedef bool (MarioStatusDeleteFunc)(MarioStatus * status, s32 level); 

/*
    Called on map change
*/
//typedef void (MarioStatusMapChangeFunc)(MarioStatus * status);

struct MarioStatus
{
	/* 0x00 */ u32 flags;
	/* 0x04 */ u32 type; // same values as MarioWork.statusFlags
	/* 0x08 */ float timer; // time remaining, counts down to 0 in increments of marioSpeedScale
	/* 0x0C */ void * userWork;
	/* 0x10 */ void * mainFunc;
	/* 0x14 */ void * deleteFunc;
	/* 0x18 */ void * mapChangeFunc;
	/* 0x1C */ MarioStatus * prev;
	/* 0x20 */ MarioStatus * next;
};

struct MarioWork
{
    u32 flags;
    u32 miscFlags;
    u32 dispFlags;
    u32 trigFlags;
    u32 statusFlags;
    u8 effectFlags;
    u8 unknown_0x15[0x1c - 0x15];
	char** curAnimName;
	u8 unknown_0x20[0x28-0x20];
	void* animChangeHandlerFunc;
	u16 state;
	u16 prevState;
	u8 unknown_0x30[0x34 - 0x30];
	u8 ctrl;
	u8 keyOff;
	u8 unknown_0x36[0x38-0x36];
	s8 character;
	u8 unknown_0x39[0x3c - 0x39];
	s32 subState;
    u8 unknown_0x40[0x48 - 0x40];
	float invincibilityTimer;
	u8 unknown_0x4c[0x5c - 0x4c];
    wii::Vec3 position;
    u8 unknown_0x68[0xbc - 0x68];
	wii::Vec3 scale;
	wii::Vec3 unkScale;
	u8 unknown_0xc8[0x120 - 0xd4];
    s32 camId;
    u8 unknown_0x124[0x128 - 0x124];
	s32 frameBufferPosX;
	s32 frameBufferPosY;
	u8 unknown_0x130[0x148 - 0x130];
	float accelerationSpeed;
    float initSpeed;
    float maxSpeed;
	u8 unknown_0x154[0x158 - 0x154];
	float swimmingSpeed;
	u8 unknown_0x15c[0x164 - 0x15c];
	float initSpeedScale;
	u8 unknown_0x168[0x178 - 0x168];
	float movingAngle;
	u8 unknown_0x17c[0x180 - 0x17c];
	float facingAngle;
	float targetFacingAngle;
	u8 unknown_0x188[0x194 - 0x188];
	float hitboxWidth;
	float hitboxHeight;
	float baseHitboxWidth;
	float baseHitboxHeight;
	u8 unknown_0x1a4[0x1b4 - 0x1a4];
	float targetMovingAngle;
	u8 unknown_0x1b8[0x1bc - 0x1b8];
	HitObj* hitObjs1[10];
	u8 unknown_0x1e4[0x1fc - 0x1e4];
	HitObj* hitObjs2[3];
	u8 unknown_0x208[0x248 - 0x208];
	float speedScale;
	s32 animPoseIds[8];
	u8 unknown_0x26c[0x30c - 0x26c];
	u16 buttonsHeld;
	u16 buttonsPressed;
	u16 buttonsHeldRepeat;
	u16 buttonsPressedRepeat;
	u8 unknown_0x314[0x316 - 0x314];
	u8 pseudoJoystickX;
	u8 pseudoJoystickY;
	u8 unknown_0x318[0x348 - 0x318];
	s32 sfxIds[4];
	u8 unknown_0x358[0x364 - 0x358];
	float idleTimer;
	u8 unknown_0x368[0x3a4 - 0x368];
	void* caughtEnemy;
	s32 catchType;
	u8 unknown_0x3ac[0x3d0 - 0x3ac];
	float scalarSpeed;
	u8 unknown_0x3d4[0x3d8 - 0x3d4];
	wii::Vec3 respawnPosition;
	s32 isSwimming; //Read-only, set every frame to whether miscFlags has the Swimming flag set
	float megaStarTimer;
	HitObj* hitObjRideArray[24];
	s32 numHitObjRideArray;
	u8 unknown_0x450[0x9b8 - 0x450];
	HitObj* hitObjHeadArray[20];
	s32 numHitObjHeadArray;
	u8 unknown_0xa0c[0xcd8 - 0xa0c];
	MarioJumpFallPara jumpFallPara;
	u8 unknown_0xd0c[0xe80 - 0xd0c];
	MarioStatus statusTbl[32];
	u8 unknown_0x1300[0x1354 - 0x1300];
	wii::Vec3 spaceMovementDir;
	s32 gravityType;
	u8 unknown_0x1364[0x1370 - 0x1364];
	wii::Vec3 gravityVector;
	u8 unknown_0x137c[0x1480 - 0x137c];
	s32 nectCharacter;
	s32 prevPixl;
	s32 curPixl;
	u8 unknown_0x148c[0x1498 - 0x148c];
	u16 acrobatFlags;
	u8 unknown_0x149a[0x149c - 0x149a];
	float stylishLevel;
	u8 unknown_0x14a0[0x14a4 - 0x14a0];
	s32 lastStylishXp;
	s32 stylishSfxId;
	s32 stylishCombo;
	u8 unknown_0x14b0[0x14b4 - 0x14b0];
	float posLockTimer;
	u8 unknown_0x14b8[0x14c0 - 0x14b8];
	u32 acrobatJoystickFlags;
	u8 unknown_0x14c4[0x14dc - 0x14c4];
	void* acrobatCb;
	u8 unknown_0x14e0[0x14e8 - 0x14e0];
	wii::Vec3 spaceYSpdRelated;
	u8 unknown_0x14f4[0x1550 - 0x14f4];
	s32 paneNum;
    u8 unknown_0x1554[0x155c - 0x1554];
	wii::Vec3 facingTarget;
	u8 unknown_0x1568[0x156c - 0x1568];
};
static_assert(sizeof(MarioWork) == 0x156c);

void marioSpawnPlayer();
s32 marioGetGravity();
MarioWork* marioGetPtr();
float getInitSpeed();
float getMaxSpeed();
float calcSpeed(double initSpeed, bool scaleSpeed);
s32 getCrouchState();
s32 isSuperJumpHitCeiling();

u8 marioCtrlOffChk();
u8 marioKeyOffChk();
u8 marioCtrlOff();
u8 marioCtrlOn();
u8 marioKeyOff();
u8 marioKeyOn();

void marioSoundInit();

extern "C" {

	extern CharacterProperty characterProperties[4];

	extern wii::Vec3 npcScale;
	extern wii::Vec3 Vec3_8033086c;

	extern MarioWork marioWork;
	extern u8 marioCtrlOffChk_o();
	extern u8 marioKeyOffChk_o();
	extern u8 marioCtrlOff_o();
	extern u8 marioCtrlOn_o();
	extern u8 marioKeyOff_o();
	extern u8 marioKeyOn_o();
	extern void marioSetGravity(s32 type);

	extern void FUN_8013146c();
	extern void marioSpawnPlayer_o();
	extern void marioGetGravity_o();
	extern MarioWork * marioGetPtr_o();
	extern f32 getInitSpeed_o();
	extern f32 getMaxSpeed_o();
	extern f32 calcSpeed_o(double speed, bool scaleSpeed);

	extern HitObj* FUN_80136eec(float ySpd, float* xPos, float* scaledHitboxHeight, float* param_3);
	extern s32 getCrouchState_o();
	extern s32 isSuperJumpHitCeiling_o();
	extern void getGravityDotProduct(wii::Vec3* position, wii::Vec3* dest);

	extern void marioSoundInit_o();
}
}