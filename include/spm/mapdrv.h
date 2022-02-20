#pragma once
#include <wii/types.h>
#include <hitdrv.h>

/*
    mapdrv handles the rendering & collision of the main map model
*/
namespace spm::mapdrv {

typedef struct {
/* 0x0 */ u8 unknown_0x0;// unknown 0x0
/* 0x1 */ u8 cullMode;
/* 0x2 */ u8 flags;
/* 0x3 */ u8 unknown_0x3;// unknown 0x3
/* 0x4 */ u32 lightMask;
/* 0x8 */ u32 attr;
/* 0xC */ u8 unknown_0xc[0x10-0xc]; // unknown 0xc-f
} MapFileJointDrawMode; // total size 0x10

typedef struct {
/* 0x0 */ void * material;
/* 0x4 */ void * mesh;
} MapFileJointPart; // total size 0x8

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ const char * type;
/* 0x08 */ MapFileJoint * parent;
/* 0x0C */ MapFileJoint * firstChild;
/* 0x10 */ MapFileJoint * nextSibling;
/* 0x14 */ MapFileJoint * prevSibling;
/* 0x18 */ wii::Vec3 scale;
/* 0x24 */ wii::Vec3 rotation;
/* 0x30 */ wii::Vec3 translation;
/* 0x3C */ wii::Vec3 bboxMin;
/* 0x48 */ wii::Vec3 bboxMax;
/* 0x54 */ u8 unknown_0x54[0x58-0x54];// unknown 0x54-57
/* 0x58 */ MapFileJointDrawMode * drawMode;
/* 0x5C */ s32 partTableCount;
/* 0x60 */ MapFileJointPart partTable[]; // array of length partTableCount
} MapFileJoint; // total size varies

typedef struct {
/* 0x00 */ u8 unknown_0x0[0x4 - 0x0]; // unknown 0x0-3
/* 0x04 */ s32 type;
/* 0x08 */ float startZ;
/* 0x0C */ float endZ;
/* 0x10 */ wii::RGBA colour;
} MapFileFog; // total size 0x14

typedef struct {
/* 0x00 */ u32 fileSize;
/* 0x04 */ u32 mainDataSize;
/* 0x08 */ u32 relTableCount;
/* 0x0C */ u32 chunkTableCount;
/* 0x10 */ u8 unknown_0x10[0x20 - 0x10]; // unknown 0x10-1f
} MapFileHeader; // total size 0x20

typedef struct {
/* 0x0 */ u32 offset; // into main data
/* 0x4 */ u32 nameOffset; // into string table
} MapFileChunk;

typedef struct {
/* 0x00 */ MapFileHeader fileHeader;
/* 0x20 */ void * mainData;
/* 0x24 */ void * relTable;
/* 0x28 */ MapFileChunk * chunkTable;
/* 0x2C */ u8 unknown_0x2c[0x30 - 0x2c]; // unknown 0x2c-2f
/* 0x30 */ const char * stringTable;
/* 0x34 */ u8 unknown_0x34[0x3c - 0x34];// unknown 0x34-3b
/* 0x3C */ u32 flags;
/* 0x40 */ void * rawFile;
} MapFileContext; // total size 0x44

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ const char * type;
/* 0x08 */ wii::Vec3 position;
/* 0x14 */ wii::Vec3 rotation;
/* 0x20 */ wii::Vec3 scale;
/* 0x2C */ wii::RGBA colour;
/* 0x30 */ float spotAngle;
/* 0x34 */ float angleAttenuation;
/* 0x38 */ s32 distanceAttenuationType;
/* 0x3C */ u32 flags;
/* 0x40 */ s32 version;
} MapFileLightEntry; // total size 0x44

typedef struct {
/* 0x0 */ s32 count;
/* 0x4 */ MapFileLightEntry * entries[]; // array of length count
} MapFileLightTable; // total sizevaries

typedef struct {
/* 0x00 */ const char * meshName;
/* 0x04 */ wii::Vec3 translation;
/* 0x10 */ wii::Vec3 rotation;
/* 0x1C */ wii::Vec3 scale;
/* 0x28 */ u8 unknown_0x28[0x58 - 0x28]; // unknown 0x28-57
/* 0x58 */ s32 frameCount;
} MapFileMeshTrack; // total size 0x5c

typedef struct {
/* 0x0 */ s32 count;
/* 0x4 */ MapFileMeshTrack * tracks; // array of length count
} MapFileMeshTracks; // total size 0x8

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ u8 unknown_0x04[0x8 - 0x4]; // unknown 0x4-7
/* 0x08 */ float duration;
/* 0x0C */ MapFileMeshTracks * meshTracks;
/* 0x10 */ void * materialTrack;
/* 0x14 */ u8 unknown_0x14[0x20 - 0x14]; // unknown 0x14-1f
} MapFileAnimData; // total size 0x20

typedef struct {
    /*
        0x1 is hide
        Others unknown
    */
/* 0x000 */ u32 flag0;
/* 0x004 */ u32 flag4;
/* 0x008 */ u8 blendMode;
/* 0x009 */ u8 unknown_0x09[0xc - 0x9]; // unknown 0x9-b
/* 0x00C */ MapFileJoint * joint;
/* 0x010 */ wii::RGBA colour;
/* 0x014 */ u8 unknown_0x14[0x1c - 0x14]; // unknown 0x14-1b
/* 0x01C */ wii::Vec3 translation;
/* 0x028 */ wii::Mtx34 modelWorldMtx;
/* 0x058 */ u8 unknown_0x58[0xb8 - 0x58];// unknown 0x58-b7
/* 0x0B8 */ wii::Mtx34 runtimeWorldMtx;
/* 0x0E8 */ s16 offscreenId;
/* 0x0EA */ s16 mapEntryId;
/* 0x0EC */ MapObj * parent;
/* 0x0F0 */ MapObj * firstChild;
/* 0x0F4 */ MapObj * nextSibling;
/* 0x0F8 */ u16 gxBboxLeft;
/* 0x0FA */ u16 gxBboxTop;
/* 0x0FC */ u16 gxBboxRight;
/* 0x0FE */ u16 gxBboxBottom;
/* 0x100 */ void * dl_buf[8]; // display list pointers
/* 0x120 */ u32 dl_size[8]; // display list sizes
/* 0x140 */ u8 unknown_0x140[0x144 - 0x140]; // unknown 0x140-143
} MapObj; // total size 0x144

typedef struct {
/* 0x00 */ u16 flags;
/* 0x02 */ u8 unknown_0x02[0x10 - 0x2]; // unknown 0x2-f
/* 0x10 */ float timePlayed;
/* 0x14 */ float playRate;
/* 0x18 */ MapFileAnimData * fileData;
/* 0x1C */ u8 unknown_0x1c[0x28 - 0x1c]; // unknown 0x1c-27
} MapAnimObj; // total size 0x28

typedef void (MapEntryUnloadCb)();

// Internally referred to as a "kind"
typedef struct {
/* 0x000 */ s32 mapCount; // active MapEntry count (always 1?)
/* 0x004 */ u16 flags;
/* 0x006 */ char name[16];
/* 0x016 */ wii::RGBA colour;
/* 0x01A */ wii::RGBA blend1;
/* 0x01E */ wii::RGBA blend2;
/* 0x022 */ u8 unknown_0x22[0x24 - 0x22]; // unknown 0x22-23
/* 0x024 */ MapFileFog fogDefs[2];
/* 0x04C */ s32 loadStage; // used for mapLoad
/* 0x050 */ MapFileContext mapDatContext;
/* 0x094 */ void * mapDat;
/* 0x098 */ u32 mapDatSize;
/* 0x09C */ void * tpl;
/* 0x0A0 */ u32 tplSize;
/* 0x0A4 */ void * textureTable;
/* 0x0A8 */ MapFileLightTable * lightTable;
/* 0x0AC */ MapFileFog * fogData;
/* 0x0B0 */ void * materialNameTable;
/* 0x0B4 */ void * vcdTable;
/* 0x0B8 */ MapObj * rootMapObj;
/* 0x0BC */ HitObj * rootHitObj;
/* 0x0C0 */ wii::Vec3 bboxCorners[2][8];
/* 0x180 */ s32 mapObjCount;
/* 0x184 */ MapObj * mapObjs;
/* 0x188 */ s32 hitObjCount;
/* 0x18C */ HitObj * hitObj;
/* 0x190 */ s32 animCount;
/* 0x194 */ MapAnimObj * animData;
/* 0x198 */ u32 dl_size; // display list size
/* 0x19C */ void * dl_buf; // display list buffer
/* 0x1A0 */ MapEntryUnloadCb * unloadCb;
} MapEntry; // total size 0x1a4

typedef struct {
/* 0x000 */ MapEntry entries[2]; // being an array is a TTYD leftover
/* 0x348 */ u8 unknown_0x348[0x34c - 0x348]; // unknown 0x348-34b
} MapWorkGroup; // total size 0x34c

typedef struct {
/* 0x000 */ MapWorkGroup groups[2];
/* 0x698 */ s32 activeGroup;
/* 0x69C */ u8 unknown_0x69c[0x6a0 - 0x69c]; // unknown 0x69c-69f
/* 0x6A0 */ s32 dispOff;
/* 0x6A4 */ u8 unknown_0x0x6a4[0x6a8 - 0x6a4]; // unknown 0x6a4-6a7
/* 0x6A8 */ wii::RGBA paperAmbColor;
} MapWork; // total size 0x6ac

}