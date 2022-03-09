#pragma once
#include <wii/types.h>

namespace spm::setup_data {

struct MiscSetupDataV6 {
    s32 instanceId; /* ignored if 0 */
    u8 unk_0x4[0x10-0x4];
    s32 unitWork[16];
    s32 field5_0x50;
    u8 unk_0x54[0x58-0x54];
    s32 npcFlag598;
    float zAxisRotation;
};

struct SetupEnemyV6 {
    wii::Vec3 pos;
    s32 id;
    MiscSetupDataV6 misc;
};

struct SetupFileV6 {
    u16 version;
    u8 unk_0x2[0x4-0x2];
    SetupEnemyV6 enemies[100];
};

}