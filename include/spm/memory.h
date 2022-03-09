#pragma once

#include <types.h>
#include <wii/mem.h>

namespace spm::memory {

#define MEM1_HEAP_COUNT 3
#define MEM2_HEAP_COUNT 6
#define HEAP_COUNT 9
#define SMART_HEAP_ID 7
#define SMART_ALLOCATION_MAX 2048

struct MemWork
{
    wii::MEM::MEMEXPHeap * heapHandle[HEAP_COUNT];
    void * heapStart[HEAP_COUNT];
    void * heapEnd[HEAP_COUNT];
};

enum HeapSizeType
{
    HEAPSIZE_PERCENT_REMAINING,
    HEAPSIZE_ABSOLUTE_KB
};

struct HeapSize
{
    s32 type;
    s32 size;
};

enum HeapId {
    MAIN_HEAP,
    MAP_HEAP,
    MEM1_HEAP_3,
    EXT_HEAP,
    EFFECT_HEAP,
    WPAD_HEAP,
    SOUND_HEAP,
    SMART_HEAP,
    MEM2_HEAP_6
};

extern "C" {

extern MemWork * memoryWp;
extern HeapSize size_table[HEAP_COUNT];

void *__memAlloc(u32 heap, u32 size);
void __memFree(u32 heap, void *ptr);

}

}
