#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AD0C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AE5C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AEC0);

INCLUDE_ASM("asm/game/nonmatchings/12250", FontHack__UnkFunc00);

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

extern s32 D_8001A270[][2];
extern s32 D_80040840[2];

void func_8002BE50(s32 arg0) {
    arg0--;
    D_80040840[0] = D_8001A270[arg0][0];
    D_80040840[1] = D_8001A270[arg0][1];
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BE84);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BECC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BEF0);

extern s32 D_800481DC[3];
extern s32 D_800481CC[3];
extern s32 D_8001A298;
extern s32 D_8001A2B0;
extern s32 D_8004084C[3];

void func_8002BF00(void) {
    D_800481DC[0] = 3;
    D_800481DC[1] = 2;
    D_800481DC[2] = (s32)&D_8001A298;
    do {
        D_80040840[0] = 0;
        D_80040840[1] = 0;
        D_80040840[2] = 0;
        D_800481CC[0] = 1;
        D_800481CC[2] = (s32)&D_8001A2B0;
        D_800481CC[1] = 3;
        D_8004084C[0] = 0;
    } while (0);
    D_8004084C[1] = 0;
    D_8004084C[2] = 0;
}

void func_8002BF70(UnkStruct00* arg0, s32 arg1) {
    arg0->unk18 = arg1;
}