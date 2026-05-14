#include "common.h"
#include "globals.h"

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800271A0);

void func_80027340(UnkStruct16* arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0->unk18 += arg0->unk1C;
        return;
    }
    if (arg0->unk18 != 0) {
        arg0->unk18 += arg0->unk1C;
        if (arg0->unk18 == 0) {
            arg0->unk1C = 1;
        }
    }
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_80027394);

typedef struct {
    s32 unk0;
    char pad4[0x8];
    UnkStruct16 *unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} AnimStruct;

extern void func_80025954(UnkStruct16*);

void func_800274EC(AnimStruct* arg0, s32 arg1) {
    if (arg0->unk0 == 0) {
        arg0->unk18 = 0;
        arg0->unk1C = 1;
    }
    arg0->unk0++;
    if (arg0->unk0 > arg0->unk14) {
        func_80027340((UnkStruct16*)arg0, arg1);
        arg0->unkC->unk18 = 0;
        if (arg0->unk18 == 0) {
            func_80025954(arg0->unkC);
        }
    }
}

s32 func_80027570(void) {
    return 1;
}

void func_80027578(UnkStruct12* arg0) {
    arg0->unk0 = arg0->unk14 - 1;
}

void func_8002758C(UnkStruct14* arg0) {
    UnkStruct15* temp_v0;

    temp_v0 = arg0->unkC;
    arg0->unk0 = 0;
    temp_v0->unk10 = 0;
    UnkFunc01(temp_v0, 0x8000);
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800275BC);

typedef struct VT_E9A0 {
    char pad0[0x20];
    s16 offset20;
    char pad22[2];
    void (*func24)(s32);
    s16 offset28;
    char pad2A[2];
    void (*func2C)(s32, s32);
} VT_E9A0;

typedef struct Item_E9A0 {
    char pad0[8];
    VT_E9A0 *vt;
} Item_E9A0;

typedef struct Container_E9A0 {
    s32 count;
    Item_E9A0 *items[10];
    char pad2C[4];
    VT_E9A0 *vt30;
    char pad34[4];
    s32 unk38;
} Container_E9A0;

void func_8002780C(Container_E9A0 *arg0, s32 arg1) {
    s32 i;
    VT_E9A0 *vt = arg0->vt30;
    Item_E9A0 *item;
    VT_E9A0 *vt2;

    vt->func24((s32)arg0 + (s32)vt->offset20);
    if (arg0->count > 0) {
        i = 0;
        do {
            item = arg0->items[i];
            vt2 = item->vt;
            vt2->func2C((s32)item + (s32)vt2->offset28, arg1);
            i++;
        } while (i < arg0->count);
    }
    arg0->unk38 = func_80025EBC(0x335);
}

s32 func_800278BC(UnkStruct13* arg0) {
    return func_80025EBC(0x335) < arg0->unk38;
}

void func_800278EC(UnkStruct11* arg0) {
    arg0->unk2C = 1;
}

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800278F8);

INCLUDE_ASM("asm/game/nonmatchings/E9A0", func_800279E4);
