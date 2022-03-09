#include "spm/npcdrv.h"
#include "spm/memory.h"
#include <wii/string.h>

namespace spm::npcdrv {

void npcInit() {
    memset(npcdrvWp, 0, sizeof(NPCWork));
    npcdrvWp->num = NUM_ENTRIES;
    npcdrvWp->entries = (NPCEntry*)memory::__memAlloc(memory::MAIN_HEAP, npcdrvWp->num * sizeof(NPCEntry));
    npcdrvWp->unkFrameCount = 0;
    npcdrvWp->nextTemplatedNpcId = 1;
    npcdrvWp->field15_0x30 = (void*)0;
    npcdrvWp->field_0x34 = 0;
    npcdrvWp->field38_0xb38 = 0.6;
    npcdrvWp->flag &= -3;
    npcdrvWp->flag |= 4;
    memset(npcdrvWp->fbatMaybe, 0, sizeof(npcdrvWp->fbatMaybe));
    return;
}

void npcReset() {
    memset(npcdrvWp->entries, 0, npcdrvWp->num * sizeof(NPCEntry));
    npcdrvWp->flag = 0;
    npcdrvWp->unkFrameCount = 0;
    npcdrvWp->nextTemplatedNpcId = 1;
    memset(npcdrvWp->subs, 0, sizeof(npcdrvWp->subs));
    npcdrvWp->field15_0x30 = (void*)0;
    npcdrvWp->field_0x34 = 0;
    npcdrvWp->field38_0xb38 = 0.3; // 0.3 now, but 0.6 in npcInit...
    npcdrvWp->flag &= -3;
    npcdrvWp->flag |= 4;
    return;
}

void npcWorkSetFlag2() {
    npcdrvWp->flag |= 2;
    return;
}

}