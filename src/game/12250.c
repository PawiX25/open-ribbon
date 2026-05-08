#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AD0C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AE5C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AEC0);

extern char D_8001A13C[];
extern char D_8001A164[];

void FontHack__UnkFunc00(s32 *arg0, s32 flag) {
    s32 a2 = arg0[0];
    s32 a3 = arg0[1];
    s32 v;
    s32 cur;
    if (((a2 + 0x218) & 0xF0000000) != (a3 & 0xF0000000)) {
        printf(D_8001A13C, D_8001A164, 0x3C);
        exit(1);
    }
    v = (a3 & 0x0FFFFFFF) >> 2;
    cur = *(s32*)((char*)a2 + 0x218);
    *(s32*)((char*)a2 + 0x218) = (cur & 0xFC000000) | v;
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B01C);

void func_8002B054(UnkStruct07* arg0) {
    if (arg0->unk0 == 0) {
        arg0->unk4 = 1;
        arg0->unk8 = 1;
        arg0->unk0 = 1;
    }
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B078);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B0A0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B0B4);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B0C8);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B0D4);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B0F8);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B11C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B1A0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B1BC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B1E0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B410);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B42C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B4EC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B5F0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B6E0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BADC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BC00);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BDA8);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BE00);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BE44);

typedef struct { s32 a; s32 b; } Pair_BE50;
extern Pair_BE50 D_8001A270[];
extern Pair_BE50 D_80040840;

void func_8002BE50(s32 arg0) {
    D_80040840 = D_8001A270[arg0 - 1];
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BE84);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BECC);

void func_8002BEF0(void) {}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BF00);

void func_8002BF70(UnkStruct00* arg0, s32 arg1) {
    arg0->unk18 = arg1;
}