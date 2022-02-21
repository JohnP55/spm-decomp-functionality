#pragma once
#include <spm/mario.h>

namespace spm::mario_motion {

    typedef void MarioMotFunc (mario::MarioWork*);

    struct MarioMotFuncs {
        MarioMotFunc* mainFunc;
        MarioMotFunc* deleteFunc;
    };

    void marioMotion();

    extern "C" {
        extern MarioMotFuncs marioMotTbl[78];
        extern void marioMotion_o();
    }
}