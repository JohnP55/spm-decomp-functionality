#pragma once
#include <types.h>
#include <wii/types.h>
/*
    Hitdrv handles collision with MOBJs or the map
    See also mapdrv.h and mobjdrv.h
*/

struct HitObj {
    /*
        0x80000000 is belongs to MOBJ
        0x80 is deleted
        0x40 is matrix recalculated
        0x1 is disable
        Others unknown
    */
/* 0x000 */ u16 flags;
/* 0x002 */ u8 unknown_0x2[0x4 - 0x2]; // unknown 0x2-3
/* 0x004 */ u32 attr; // unknown bitflags
/* 0x008 */ void * joint;
/* 0x00C */ u8 unknown_0xc[0xcc - 0xc]; // unknown 0xc-cb
/* 0x0CC */ wii::Vec3 position; 
/* 0x0D8 */ s16 totalTri;
/* 0x0DA */ s16 mapEntryIdx;
/* 0x0DC */ void * tris; // array of totalTri length
/* 0x0E0 */ u8 unknown_0xe0[0x100 - 0xe0]; // unknown 0xe0-ff
/* 0x100 */ void* owner;
/* 0x104 */ HitObj * parent;
/* 0x108 */ HitObj * child;
/* 0x10C */ HitObj * nextSibling;
/* 0x110 */ u8 unknown_0x110[0x114 - 0x110]; // unknown 0x110-113
}; // total size 0x114
static_assert(sizeof(HitObj) == 0x114);