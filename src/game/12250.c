#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AD0C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AE5C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AEC0);

INCLUDE_ASM("asm/game/nonmatchings/12250", FontHack__UnkFunc00);

extern void func_8002F3CC(s32 arg0, s32 arg1);
extern s32 D_800480B8;
extern s32 D_800480BC;

void func_8002B01C(s32 arg0, s32 arg1, s32 arg2) {
    D_800480B8 = arg1 & 0x3F;
    D_800480BC = arg2 & 0xFF;
    func_8002F3CC(arg1, arg2);
}

void func_8002B054(UnkStruct07* arg0) {
    if (arg0->unk0 == 0) {
        arg0->unk4 = 1;
        arg0->unk8 = 1;
        arg0->unk0 = 1;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkC0;

extern UnkC0* D_800480C0;

void func_8002B078(UnkC0* arg0) {
    func_8002B054((UnkStruct07*)arg0);
    D_800480C0 = arg0;
}

s32 func_8002B0A0(void) {
    return D_800480C0->unk4;
}

s32 func_8002B0B4(void) {
    return D_800480C0->unk8;
}

void func_8002B0C8(s32 arg0) {
    D_800480C0->unk8 = arg0;
}

s32 func_8002B0D4(void) {
    s32 v1 = 0x4000;
    if (D_800480C0->unk4 == 0) {
        v1 = 0x2000;
    }
    return v1;
}

s32 func_8002B0F8(void) {
    s32 v1 = 0x1000;
    if (D_800480C0->unk4 == 0) {
        v1 = 0x4000;
    }
    return v1;
}

typedef struct {
    char pad44[0x44];
    s32 unk44;
    s32 unk48;
} ObjB11C;

typedef struct {
    char pad10[0x10];
    s32 unk10;
    ObjB11C** unk14;
} StructB110;

extern StructB110* D_80048110;
extern s32 func_80029A38(s32, s32);

void func_8002B11C(s32 arg0) {
    s32 x = func_80029A38(0x78, arg0);
    StructB110* p = D_80048110;
    s32 val = (x * x * 7 + 0xA) << 16;
    s32 one = 1;
    s32 i;
    for (i = 0; i < p->unk10; i++) {
        ObjB11C* o = p->unk14[i];
        o->unk48 = val;
        o->unk44 = one;
    }
}

extern s32 D_800480E8;
extern s32 D_800480EC;
extern s32 D_800480F0;
extern s32 D_800480F4;
extern s32 D_800480F8;

void func_8002B1A0(void) {
    D_800480E8 = 0;
    D_800480EC = 0;
    D_800480F0 = 0;
    D_800480F4 = 0;
    D_800480F8 = 0;
}

extern s32 D_80048104;

void func_8002B1BC(void) {
    D_800480E8 = 1;
    if (D_80048104 == 2) {
        D_800480EC = 0;
    }
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B1E0);

void func_8002B410(void) {
    D_800480E8 = 1;
    D_800480EC = 0x14;
    D_800480F8 = 1;
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B42C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B4EC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B5F0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B6E0);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BADC);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BC00);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BDA8);

extern void func_8002B6E0(void);
extern s32 D_800480FC;
extern s32 D_80048108;

void func_8002BE00(s32 arg0) {
    if (arg0 == 1) {
        func_8002B6E0();
    }
    D_80048104 = arg0;
    func_8002B1BC();
    D_800480FC = 0;
    D_80048108 = 0;
}

extern s32 D_800480FC;

s32 func_8002BE44(void) {
    return D_800480FC;
}

extern s32 D_8001A270[][2];
extern s32 D_80040840[2];

void func_8002BE50(s32 arg0) {
    arg0--;
    D_80040840[0] = D_8001A270[arg0][0];
    D_80040840[1] = D_8001A270[arg0][1];
}

extern void func_8002B42C(void);
extern s32 D_80040858[];

void func_8002BE84(s32 arg0) {
    D_80040858[0] = 1;
    D_80040858[6] = 0;
    func_8002B42C();
    D_80048108 = 1;
    D_800480FC = arg0;
}

extern s32 D_80048100;

void func_8002BECC(void) {
    func_8002B410();
    D_80048100 = 1;
}

void func_8002BEF0(void) {
    char buf[10];
}

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