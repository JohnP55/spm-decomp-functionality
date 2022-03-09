#pragma once
#include <wii/types.h>
#include "spm/setup_data.h"
#include "spm/evtmgr.h"

namespace spm::npcdrv {

#define NPCTRIBE_MAX 535
#define NPCTEMPLATE_MAX 435
#define NUM_ENTRIES 50

typedef enum {
    NPC_MOVE_WALK_NO_HIT,
    NPC_MOVE_WALK,
    NPC_MOVE_STAY_NO_DAMAGE,
    NPC_MOVE_SPIN,
    NPC_MOVE_WALK_NO_HIT_2
} NPCMoveMode;
static_assert(sizeof(NPCMoveMode) == sizeof(s32));

struct DropItem {
    s32 itemId;
    s32 chance;
};

struct NPCDefense {
    s8 type;
    s8 defense;
    u16 flags;
};

struct NPCTribeAnimDef {
    s32 id;
    const char * animName;
};

struct NPCAnim {
    int m_nPoseId; /* Created by retype action */
    char animPoseName[32];
    u8 unk_0x24[0x44-0x24];
    u32 flags;
    NPCTribeAnimDef * animDefs;
    wii::Vec3 translation4c;
    wii::Vec3 translation58;
    wii::Vec3 translation64;
    wii::Vec3 scriptRotation;
    wii::Vec3 rotation7c;
    wii::Vec3 rotation88;
    wii::Vec3 translation94;
    wii::Vec3 scale;
    float field44_0xac;
    float field45_0xb0;
    float field46_0xb4;
    wii::RGBA rgba;
    wii::RGBA field48_0xbc;
    float field49_0xc0;
    int field50_0xc4;
    int curAnimDefId;
    u8 rotationOrder;
    u8 unk_0xcd[0xd0-0xcd];
    s32 lastRenderFrame;
    wii::Mtx34 mtx;
    u8 unk_0x104[0x138-0x104];
    wii::Vec3 field110_0x138;
    u8 unk_0x144[0x16c-0x144];
    u16 field148_0x16c;
    u8 unk_0x16e[0x250-0x16e];
    void* dispFunc;
};
static_assert(sizeof(NPCAnim) == 0x254);

struct NPCUnk5ac { /* Size is uncertain */
    s32 unkSfxIdArray[4];
    u8 unk_0x10[0x24-0x10];
    s32 unkSfxId;
    const char * unkSfxName_28;
    const char * unkSfxName_2c;
    float field21_0x30;
    float field22_0x34;
    float field23_0x38;
    const char * unkSfxName_3c;
    u8 unk_0x40[0x48-0x40];
};
static_assert(sizeof(NPCUnk5ac) == 0x48);

struct NPCPart {
    u16 id;
    s16 mode;
    u8 unk_0x4[0x8-0x4];
    wii::Vec3 position;
    wii::Vec3 ownerPosLastAnimChange;
    float field8_0x20;
    float yDelta;
    float field10_0x28;
    u32 flag2c;
    u32 flag30;
    u32 field13_0x34;
    u8 unk_0x38[0x3c-0x38];
    float field18_0x3c;
    float field19_0x40;
    float field20_0x44;
    s32 field21_0x48;
    NPCDefense * defenses;
    u8 unk_0x50[0x54-0x50];
    NPCAnim m_Anim;
    s32 partswork[16];
    u8 unk_0x2e8[0x378-0x2e8];
    s32 attackPower;
    u8 unk_0x37c[0x384-0x37c];
    s32 updateFunc;
    struct NPCEntry * owner;
    NPCPart * prevPart;
    NPCPart * nextPart;
    u8 unk_0x394[0x398-0x394];
};

struct NPCEntry {
    s32 id;
    s32 setupFileIndex;
    u32 flag8;
    u32 flagC;
    u32 flag10;
    u8 unk_0x14[0x1c-0x14];
    s32 lastAttackedDefenseType;
    u8 unk_0x20[0x24-0x20];
    char name[32];
    NPCAnim m_Anim;
    s32 cameraId;
    s32 offscreenid;
    wii::Vec3 position;
    u8 unk_0x2ac[0x2bc-0x2ac];
    wii::Vec3 pos2;
    wii::Vec3 pos3;
    u8 unk_0x2d4[0x2e0-0x2d4];
    wii::Vec3 pos4;
    u8 unk_0x2ec[0x2f8-0x2ec];
    NPCMoveMode moveMode;
    u8 unk_0x2fc[0x348-0x2fc];
    s32 * templateUnkScript1;
    s32 * unkScript_0x34c;
    s32 * unkScript_0x350;
    s32 * unkScript_0x354;
    s32 * unkScript_0x358;
    u32 flags_35c;
    s32 * templateUnkScript2;
    s32 * onHitScript;
    s32 * templateUnkScript4;
    s32 * templateUnkScript5;
    s32 * templateUnkScript9;
    s32 * templateUnkScript6;
    s32 * templateUnkScript7;
    s32 * templateUnkScript8;
    s32 * talkScript;
    u8 unk_0x384[0x390-0x384];
    s32 onSpawnEvtId;
    s32 unkEvtId;
    u32 flags_398;
    float tribeField0xE;
    float tribeField0x10;
    float tribeField0x12;
    u8 unk_0x3a8[0x3ac-0x3a8];
    float height;
    u8 unk_0x3b0[0x3c8-0x3b0];
    float someAngleDegrees;
    u8 unk_0x3cc[0x430-0x3cc];
    s64 prevUnkTime;
    u64 unkTime;
    u8 unk_0x440[0x44c-0x440];
    float timer_starts[4]; /* stored in seconds, set in ms? */
    float timer_ends[4];
    u32 flag46C;
    float field254_0x470;
    float field255_0x474;
    u32 tribeField0x54;
    wii::Vec3 moveStartPos;
    wii::Vec3 moveDest;
    float limit_time;
    float field260_0x498;
    s32 tribeId;
    s32 tribeId2;
    u8 unk_0x4a4[0x4ec-0x4a4];
    s32 maxHp;
    s32 hp;
    u8 unk_0x4f4[0x504-0x4f4];
    s32 miscSetupData0x50;
    s32 axisMovementUnit;
    u8 unk_0x50c[0x510-0x50c];
    s32 unitWork[16]; /* copied form MiscSetupData */
    wii::Vec3 field342_0x550;
    wii::Vec3 field343_0x55c;
    u8 unk_0x568[0x574-0x568];
    s32 dropItemId;
    u8 unk_0x578[0x57c-0x578];
    s32 templateField0x5C; /* Created by retype action */
    s32 templateField0x60;
    s32 templateField0x64;
    float field361_0x588;
    u8 unk_0x588[0x598-0x58c];
    s32 flag598;
    u8 unk_0x59c[0x5ac-0x59c];
    NPCUnk5ac unk5ac;
    u8 unk_0x5f4[0x618-0x5f4];
    float zRotation;
    int tribeCatchCardDefense;
    u8 unk_0x620[0x6f4-0x620];
    NPCDefense * defenses;
    u8 unk_0x6f8[0x714-0x6f8];
    NPCPart * parts;
    void* unkDefinitionTable;
    NPCEntry * field595_0x71c;
    NPCEntry * field596_0x720;
    u8 unk_0x724[0x730-0x724];
    NPCEntry * master; /* Created by retype action */
    NPCEntry * slaves[4];
    u8 unk_0x744[0x748-0x744];
};
static_assert(sizeof(NPCEntry) == 0x748);

struct NPCPartDef {
    u16 id;
    s16 mode;
    u8 unk_0x4[0x8-0x4];
    wii::Vec3 position;
    u32 flag2c; /* same as NPCPart->0x2c */
    u32 flag30; /* same as NPCPart->0x30 */
    wii::Vec3 field9_0x1c; /* 3 floats next to each other, always dealt with together, very likely some vector */
    NPCDefense * defenses;
    void * field11_0x2c;
    void * updateFunc;
    const char * animPoseName;
    NPCTribeAnimDef * animDefs;
    float field15_0x3c;
    float yDelta; /* Could be a vec3 xyz delta? */
    float field17_0x44;
};

struct NPCTribe {
    const char * animPoseName;
    NPCTribeAnimDef * animDefs;
    int catchCardItemid;
    s16 catchCardDefense;
    s16 field4_0xe;
    s16 field5_0x10;
    s16 field6_0x12;
    s16 field7_0x14;
    s16 field8_0x16;
    s8 maxHp;
    s8 partsCount;
    s8 _pad_1a[2];
    NPCPartDef * partsList;
    const char * field13_0x20;
    const char * field14_0x24;
    const char * field15_0x28;
    const char * field16_0x2c;
    u8 unk_0x30[0x34-0x30];
    const char * field21_0x34;
    s16 killXp;
    s16 hitXp;
    u8 unk_0x3c[0x46-0x3c];
    u16 coinDropChance;
    u16 coinDropBaseCount;
    u16 coinDropExtraChance;
    u16 coinDropExtraMax;
    u16 dropItemChance;
    DropItem * dropItemList;
    u8 unk_0x54[0x5c-0x54];
    float bounceXSpeed;
    float field43_0x60;
    s8 attack;
    s8 _pad_65[3];
};

struct NPCWorkSub {
    u32 flags;
    u8 unk_0x4[0x8-0x4];
    char message[8]; /* Created by retype action */
    u8 unk_0x10[0x14-0x10];
    wii::Vec3 pos;
    wii::Vec3 scale;
    u8 unk_0x2c[0x30-0x2c];
    s64 timePassed;
    s64 startTime;
    s64 duration;
    float field19_0x48;
    wii::RGBA colour;
    s32 field21_0x50;
    u8 unk_0x54[0x58-0x54];
};
static_assert(sizeof(NPCWorkSub) == 0x58);

struct NPCWork {
    u32 flag;
    int num;
    NPCEntry * entries;
    s32 in3dMaybe;
    u32 unkFrameCount;
    int nextTemplatedNpcId;
    spm::setup_data::SetupFileV6 * setupFile;
    s32 field7_0x1c;
    u8 unk_0x20[0x24-0x20];
    int drawHitboxes;
    void * field13_0x28;
    s32 unkEvtId2;
    void * field15_0x30;
    s32 field_0x34;
    u8 unk_0x38[0x48-0x38];
    NPCWorkSub subs[20];
    u8 fbatMaybe[1024];
    u64 field35_0xb28;
    u32 field36_0xb30;
    u32 field37_0xb34;
    float field38_0xb38;
    float field39_0xb3c;
    u8 unk_0xb40[0xb48-0xb40];
};
static_assert(sizeof(NPCWork) == 0xb48);

typedef bool (EnemyCanSpawnFunction)();
struct NPCEnemyTemplate {
    s8 field0_0x0;
    s8 field1_0x1;
    s8 field2_0x2;
    s8 field3_0x3;
    s32 instanceId;
    u8 unk_0x8[0xc-0x8];
    EnemyCanSpawnFunction * canSpawnFunction;
    u8 unk_0x10[0x14-0x10];
    s32 tribeId;
    const char * instanceName;
    const char * japaneseName;
    wii::Vec3 pos;
    u32 flags;
    spm::evtmgr::EvtScriptCode * onSpawnScript;
    spm::evtmgr::EvtScriptCode * unkScript1;
    spm::evtmgr::EvtScriptCode * unkScript2;
    spm::evtmgr::EvtScriptCode * unkScript3;
    spm::evtmgr::EvtScriptCode * unkScript4;
    spm::evtmgr::EvtScriptCode * unkScript5;
    spm::evtmgr::EvtScriptCode * unkScript6;
    spm::evtmgr::EvtScriptCode * unkScript7;
    spm::evtmgr::EvtScriptCode * unkScript8;
    spm::evtmgr::EvtScriptCode * unkScript9;
    u8 unk_0x58[0x68-0x58];
};

void npcInit();
void npcReset();
void npcWorkSetFlag2();

extern "C" {
    extern NPCTribe npcTribes[NPCTRIBE_MAX];
    extern NPCEnemyTemplate NPCEnemyTemplates[NPCTEMPLATE_MAX];
    extern NPCWork* npcdrvWp;

    extern void npcInit_o();
    extern void npcReset_o();
    extern void npcWorkSetFlag2_o();
}

}
