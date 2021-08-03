#pragma once

#include <types.h>

namespace spm::system {

double compAngle(double angle1, double angle2);
double d_abs(double d);
s32 i_abs(s32 i);

s32 rand();
s32 _rand(s32 maxValue);
s32 irand(s32 maxValue);
double frand(double maxValue);

extern "C" {

#define assert(condition, message) \
    if (!(condition)) spm::system::__assert2(__FILE__, __LINE__, #condition, message)

#define assertf(condition, message, ...) \
    if (!(condition)) spm::system::__assert2(__FILE__, __LINE__, #condition, message, __VA_ARGS__)

s32 __assert2(const char * filename, s32 line, const char * assertion, const char * message,...);

extern s32 rand_o();
extern s32 irand_o(s32 maxValue);
extern double frand_o(double maxValue);
extern double compAngle_o(double angle1, double angle2);

extern u32 RNG_SEED;
}

}
