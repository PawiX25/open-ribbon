#include "common.h"

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800271A0);

typedef struct {
    char pad1[0x18];
    s32 unk18;
    s32 unk1C;
} UnkStruct16;

void func_80027340(UnkStruct16 * arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v1;

    if (arg1 != 0) {
        arg0->unk18 = (s32) (arg0->unk18 + arg0->unk1C);
        return;
    }
    temp_v1 = arg0->unk18;
    if (temp_v1 != 0) {
        temp_v0 = temp_v1 + arg0->unk1C;
        arg0->unk18 = temp_v0;
        if (temp_v0 == 0) {
            arg0->unk1C = 1;
        }
    }
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_80027394);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800274EC);

s32 func_80027570(void) {
    return 1;
}

typedef struct {
    s32 unk0;
    char pad1[0x10];
    s32 unk14;
} UnkStruct12;


void func_80027578(UnkStruct12* arg0) {
    arg0->unk0 = (s32) (arg0->unk14 - 1);
}

typedef struct {
    s32 unk0;
    char pad1[0xC - 0x4];
    s32 unkC;
} UnkStruct14;

typedef struct {
    char pad1[0x10];
    s32 unk10;
} UnkStruct15;

void func_8002758C(UnkStruct14* arg0) {
    UnkStruct15* temp_v0;

    temp_v0 = arg0->unkC;
    arg0->unk0 = 0;
    temp_v0->unk10 = 0;
    UnkFunc01(temp_v0, 0x8000);
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800275BC);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_8002780C);

typedef struct {
    char pad1[0x38];
    s32 unk38;
} UnkStruct13;

s32 func_800278BC(UnkStruct13* arg0) {
    return func_80025EBC(0x335) < arg0->unk38;
}

typedef struct {
    char pad1[0x2C];
    s32 unk2C;
} UnkStruct11;

void func_800278EC(UnkStruct11* arg0) {
    arg0->unk2C = 1;
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800278F8);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800279E4);
