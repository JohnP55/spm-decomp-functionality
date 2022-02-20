#pragma once

#include <types.h>
#include <wii/types.h>

namespace spm::camdrv {

struct CamEntry
{
	u32 flag;
	s32 cam_no;
	u16 cameraMode;
	u8 unknown_0xa[0xf0 - 0xa];
	float top;
	float bottom;
	float left;
	float right;
	u8 unknown_0x100[0x158 - 0x100];
	s32 isOrtho;
	wii::Vec3 pos;
	wii::Vec3 target;
	wii::Vec3 up;
	u8 unknown_0x180[0x184 - 0x180];
	float targetDistance;
	float fovY;
	float aspect;
	float near;
	float far;
	u8 unknown_0x198[0x20c - 0x198];
	wii::Vec3 zoomStartPos;
	wii::Vec3 zoomStartTarget;
	wii::Vec3 zoomDestPos;
	wii::Vec3 zoomDestTarget;
	u8 unknown_0x23c[0x240 - 0x23c];
	s64 zoomStartTime;
	u8 unknown_0x248[0x254 - 0x248];
	void* cameraRoad;
	u8 unknown_0x258[0x2ef - 0x258];
};
static_assert(sizeof(CamEntry) == 0x2f0);

CamEntry* camGetCurPtr();
s32 camGetCurNo();

extern "C" {
	extern CamEntry* camPtrTbl[15];
	extern s32 currentCamNo;

	extern CamEntry* camGetCurPtr_o();
	extern s32 camGetCurNo_o();
}

}