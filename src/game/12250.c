#include "common.h"
#include "globals.h"

typedef struct {
    s32 unk0;
} RefAD0C;

typedef struct {
    RefAD0C* unk0;
    PakFile unk4;
    s32 unk10;
    void** unk14;
} ObjAD0C;

typedef struct {
    ObjAD0C* unk0;
    char pad4[0x3C - 0x4];
    char pad3C[0x10];
} ParentAD0C;

typedef struct {
    char pad44[0x44];
    s32 unk44;
    s32 unk48;
} ObjB11C;

extern void* func_80025330(void*);
extern void* func_800303BC(s32);
extern void FileSys__LoadFile(void*, void*);
extern void func_800256CC(void*, void*, s32);
extern void func_80025B68(void*, void*, s32);
extern void func_8002AA14(void);
extern char D_8001A098[];
extern char D_8001A0B4[];
extern char D_8001A0C8[];
extern char D_8001A0DC[];
extern char D_8001A0F0[];
extern char D_8001A118[];
extern s32 D_800480B4;
extern void free(void*);
extern void FileSys__Unknown(s32);
extern void FileSys__DeleteFile(PakFile);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

extern void func_80024CC4(void*, s32);
extern void func_80025D1C(void*, s32);
extern void func_800258B0(void*, s32);

void func_8002AD0C(ParentAD0C* arg0, s32 arg1) {
    ObjAD0C* obj;
    ObjAD0C* s3;
    s32 i;

    FileSys__Unknown(0);
    D_800480B4 = 0;
    obj = arg0->unk0;
    if (obj != 0) {
        s3 = obj;
        for (i = 0; i < obj->unk10; i++) {
            void* p = obj->unk14[i];
            if (p != 0) {
                func_80024CC4(p, 3);
            }
        }
        if (obj->unk14 != 0) {
            delete(obj->unk14);
        }
        if (obj->unk0 != 0) {
            RefAD0C* ref = obj->unk0;
            s32 rc = ref->unk0 - 1;
            ref->unk0 = rc;
            if (rc == 0) {
                PakFile pf = s3->unk4;
                FileSys__DeleteFile(pf);
                free(obj->unk0);
            }
        }
        free(obj);
    }
    func_80025D1C((char*)arg0 + 0x3C, 2);
    func_800258B0((char*)arg0 + 0x4, 2);
    if (arg1 & 1) {
        free(arg0);
    }
}

extern s32 D_800480B8;
extern s32 D_800480BC;

typedef struct {
    s32 unk0;
    u8 padC[0xC - 0x4];
    u8 unkC;
    u8 unkD;
    volatile u16 unkE;
} StructAE5C;

void func_8002AE5C(s32* arg0, StructAE5C* arg1) {
    s32 mask = 0xFFFFFF;
    arg1->unkC = arg1->unkC + *(u8*)&D_800480B8;
    arg1->unkD = arg1->unkD + *(u8*)&D_800480BC;
    arg1->unkE = arg1->unkE;
    arg1->unk0 = (arg1->unk0 & 0xFF000000) | (arg0[0] & mask);
    arg0[0] = (arg0[0] & 0xFF000000) | ((s32)arg1 & mask);
}

typedef struct {
    s32 unk0;
    s32 unk4;
} ClosureAEC0;

typedef struct {
    char pad218[0x218];
    s32 unk218;
} ObjAEC0;

extern char D_8001A13C[];
extern char D_8001A164[];

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AEC0);

INCLUDE_ASM("asm/game/nonmatchings/12250", FontHack__UnkFunc00);

extern void func_8002F3CC(s32 arg0, s32 arg1);

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

typedef struct {
    s32 f0;
    s32 f4;
} LocalB42C;

extern s32 D_80040858[];
extern void AudioSys__UnkFunc01(void*, s32, s32, s32);

void func_8002B42C(void) {
    LocalB42C local;
    if (D_80040858[4] || D_80040858[3] || D_80040858[1] || D_80040858[2]) {
        if (D_80040858[6]) {
            LocalB42C* p = &local;
            p->f0 = 0;
            p->f4 = 6;
            AudioSys__UnkFunc01(p, 5, 0x40, -1);
        }
    }
    if (D_80040858[0]) {
        LocalB42C* p = &local;
        p->f0 = 0;
        p->f4 = 0;
        AudioSys__UnkFunc01(p, 1, 0x40, -1);
    }
}

typedef struct {
    s32 unk0;
    char pad4[0x8 - 0x4];
    s32* unk8;
} ObjB4EC;

typedef struct VarB4EC {
    char pad18[0x18];
    s32 unk18;
} VarB4EC;

extern s32 D_80040840[];
extern VarB4EC* D_80048114;
extern s32 D_800480FC;
extern s32 D_80048108;
extern s32 func_800293DC(void*, void*, s32, s32, s32);
extern void func_8002B42C(void);
extern void func_80025954(VarB4EC*);

void func_8002B4EC(void) {
    ObjB4EC* obj;
    if (D_800480E8 == 0 && D_80048108 == 0) {
        func_800293DC(D_80040840, D_80040858, 0, 0, 1);
        func_8002B42C();
        obj = (ObjB4EC*)D_80040840[2];
        D_80048114->unk18 = obj->unk8[D_80040840[1] * obj->unk0 + D_80040840[0]] << 16;
        if (D_80040858[0] != 0) {
            obj = (ObjB4EC*)D_80040840[2];
            D_800480FC = obj->unk8[D_80040840[1] * obj->unk0 + D_80040840[0]] + 1;
        }
        func_80025954(D_80048114);
    }
}

extern s32 D_8004084C[];
extern VarB4EC* D_80048118;

void func_8002B5F0(void) {
    ObjB4EC* obj;
    if (D_800480E8 == 0 && D_80048108 == 0) {
        func_800293DC(D_8004084C, D_80040858, 0, 0, 1);
        func_8002B42C();
        obj = (ObjB4EC*)D_8004084C[2];
        D_80048118->unk18 = (D_8004084C[1] * obj->unk0 + D_8004084C[0]) << 16;
        if (D_80040858[0] != 0) {
            obj = (ObjB4EC*)D_8004084C[2];
            D_800480FC = D_8004084C[1] * obj->unk0 + D_8004084C[0] + 6;
        }
    }
    if (D_800480F4 == 0) {
        func_80025954(D_80048118);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B6E0);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} TripleBADC;

extern void func_800293B8(void);
extern void func_8002B1A0(void);
extern void func_8002B6E0(void);
extern s32 D_800481DC[3];
extern s32 D_800481CC[3];
extern s32 D_80048100;
extern s32 D_80048104;
extern ObjAD0C* D_8004810C[];
extern void* D_8004811C[];

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BADC);

extern ObjAD0C* D_8004810C[];
extern void* D_8004811C[];

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BC00);

extern void func_8002B1E0(void);
extern void func_8002B4EC(void);
extern void func_8002B5F0(void);
extern s32 D_80048100;

void func_8002BDA8(void) {
    s32 x;

    func_8002B1E0();
    x = D_80048100;
    if (x != 1) {
        if (x < 2) {
            if (x == 0) {
                func_8002B4EC();
            }
        }
    } else {
        func_8002B5F0();
    }
}

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