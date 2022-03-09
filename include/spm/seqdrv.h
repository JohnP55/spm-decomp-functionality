#pragma once
#include <types.h>

/*
    Seqdrv functions control the main loops of the game. One sequence is active at
    a time: its init function runs first, then its main function is ran every
    frame, and its exit function runs when changing to another sequence.
    Note: this file has some progress in the decomp, see the link in README
*/

namespace spm::seqdrv {

typedef void (AfterFunc)();

typedef struct {
/* 0x00 */ s32 seq;
/* 0x04 */ s32 stage; // number used by the seq_ functions to track their progress
/* 0x08 */ char * nextMap; // parameter for seq function, always map name?
/* 0x0C */ char * nextBero; // paramater for seq function, always door name?
/* 0x10 */ u8 padding[0x20-0x10]; // unknown 0x10-1f
/* 0x20 */ AfterFunc* afterFunc; // ran after every call to the main SeqFunc if not null
} SeqWork; // total size 0x24

typedef void (SeqFunc)(SeqWork *);

typedef struct {
/* 0x0 */ SeqFunc * init;
/* 0x4 */ SeqFunc * main;
/* 0x8 */ SeqFunc * exit; // All of these are SeqFunc
} SeqDef; // total size 0xc

enum {
    SEQ_NONE = -1, // (boot)
    SEQ_LOGO = 0,
    SEQ_TITLE = 1,
    SEQ_GAME = 2,
    SEQ_MAPCHANGE = 3,
    SEQ_GAMEOVER = 4,
    SEQ_LOAD = 5
} Seqs;

/*
    Returns now_seq or 0 if equal to -1
*/
s32 seqGetSeq();
void seqInit_SPMARIO();
void seqSetSeq(s32 seqNum, char * map, char * bero);
void seqMain();

extern "C" {

extern SeqDef seq_data[sizeof(Seqs)]; // 804287a8 - index is enum above, SEQ_NONE doesn't have an entry
extern SeqWork seqWork; // 80512360

extern s32 now_seq;
extern s32 next_seq;
extern s32 prev_seq;

extern char* next_map;
extern char* next_bero;

/*
    Initialises data used by seqdrv functions
*/
extern void seqInit_SPMARIO_o();

/*
    Sets the current sequence and its prameters
*/
extern void seqSetSeq_o(s32 seqNum, char * map, char * bero);

/*
    Calls all init, main & exit functions based on now_seq & next_seq
*/
extern void seqMain_o(); // 8017bf6c


extern s32 seqGetSeq_o();
}

}