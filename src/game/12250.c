#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AD0C);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AE5C);

extern void func_8002AE5C(void);

typedef struct OutAEC0 {
    s32 unk0;
    s32 unk4;
} OutAEC0;

OutAEC0 *func_8002AEC0(OutAEC0 *out, s32 *arg1) {
    s32 a3, a0, v;
    out->unk0 = (s32)arg1;
    out->unk4 = 0;
    a3 = arg1[0x86];
    if ((a3 & 0xFC000000) != 0x0C000000) {
        printf(D_8001A13C, D_8001A164, 0x6A);
        exit(1);
    }
    a0 = ((s32)arg1 + 0x218) & 0xF0000000;
    out->unk4 = a0 + ((a3 & 0x3FFFFFF) << 2);
    if (a0 != ((s32)&func_8002AE5C & 0xF0000000)) {
        printf(D_8001A13C, D_8001A164, 0x3C);
        exit(1);
    }
    v = (((s32)&func_8002AE5C & 0x0FFFFFFF) >> 2) & 0x3FFFFFF;
    arg1[0x86] = (arg1[0x86] & 0xFC000000) | v;
    return out;
}

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

extern void AudioSys__UnkFunc01(s32 *, s32, s32, s32, s32);

void func_8002B42C(void) {
    s32 buf[3];
    if (D_80040858[4] != 0 || D_80040858[3] != 0 ||
        D_80040858[1] != 0 || D_80040858[2] != 0) {
        if (D_80040858[6] != 0) {
            buf[0] = 0;
            buf[1] = 6;
            AudioSys__UnkFunc01(buf, 5, 0x40, -1, 0);
        }
    }
    if (D_80040858[0] != 0) {
        buf[0] = 0;
        buf[1] = 0;
        AudioSys__UnkFunc01(buf, 1, 0x40, -1, 0);
    }
}

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

extern s32 D_80048100;
extern void func_8002B410(void);

void func_8002BECC(void) {
    func_8002B410();
    D_80048100 = 1;
}

void func_8002BEF0(void) {}

typedef struct StructFB00 {
    s32 unk0;
    s32 unk4;
    void *unk8;
} StructFB00;

extern StructFB00 D_800481DC;
extern StructFB00 D_800481CC;
extern u32 D_8001A298;
extern u32 D_8001A2B0;
extern s32 D_80040840_[3];
extern s32 D_8004084C[3];

void func_8002BF00(void) {
    D_800481DC.unk0 = 3;
    D_800481DC.unk4 = 2;
    D_800481DC.unk8 = &D_8001A298;
    D_80040840_[0] = 0;
    D_80040840_[1] = 0;
    D_80040840_[2] = 0;
    D_800481CC.unk0 = 1;
    D_800481CC.unk8 = &D_8001A2B0;
    D_800481CC.unk4 = 3;
    D_8004084C[0] = 0;
    D_8004084C[1] = 0;
    D_8004084C[2] = 0;
}

void func_8002BF70(UnkStruct00* arg0, s32 arg1) {
    arg0->unk18 = arg1;
}