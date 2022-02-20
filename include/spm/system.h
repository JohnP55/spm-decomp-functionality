#pragma once

#include <types.h>

namespace spm::system {
	
float f_abs(float i);
s32 i_abs(s32 i);

const char* getSpmarioDVDRoot();

s32 rand();
s32 _rand(s32 maxValue);
s32 irand(s32 maxValue);
float frand(float maxValue);
float compAngle(float angle1, float angle2);
float distABf(float x1, float y1, float x2, float y2);
float reviseAngle(float angle);

extern "C" {

#define assert(condition, message) \
    if (!(condition)) spm::system::__assert2(__FILE__, __LINE__, #condition, message)

#define assertf(condition, message, ...) \
    if (!(condition)) spm::system::__assert2(__FILE__, __LINE__, #condition, message, __VA_ARGS__)

s32 __assert2(const char * filename, s32 line, const char * assertion, const char * message,...);

extern const char* getSpmarioDVDRoot_o();

extern s32 rand_o();
extern s32 irand_o(s32 maxValue);
extern float frand_o(float maxValue);
extern float compAngle_o(float angle1, float angle2);
extern float distABf_o(float x1, float y1, float x2, float y2);
extern float reviseAngle_o(float angle);
extern void sysWaitDrawSync();

extern u32 RNG_SEED;
}

}
