#include "common.h"
#include "globals.h"

extern s32 D_800480B8;
extern s32 D_800480BC;
extern char D_8001A13C[];
extern char D_8001A164[];
extern s32 D_80040858[7];
extern UnkStruct07 *D_800480C0;
extern s32 D_80048100;
extern s32 D_80048108;
extern s32 D_800480FC;
extern s32 D_80040840_[3];
extern s32 D_8004084C[3];
extern void func_8002AE5C(s32 *, u8 *);

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002AA50);

extern s32 D_800480B4;
extern void func_80024CC4(s32 *, s32);

void func_8002AD0C(s32 *arg0, s32 flag) {
    s32 *p;
    s32 *q;
    PakFile pf;
    s32 i;
    FileSys__Unknown(0);
    D_800480B4 = 0;
    p = (s32*)arg0[0];
    if (p != NULL) {
        if (p[4] > 0) {
            i = 0;
            do {
                s32 *items = (s32*)p[5];
                s32 *item = (s32*)items[i];
                if (item != NULL) {
                    func_80024CC4(item, 3);
                }
                i++;
            } while (i < p[4]);
        }
        if (p[5] != 0) {
            delete((void*)p[5]);
        }
        q = (s32*)p[0];
        if (q != NULL) {
            *q = *q - 1;
            if (*q == 0) {
                pf = *(PakFile*)&p[1];
                FileSys__DeleteFile(pf);
                free((void*)p[0]);
            }
        }
        free(p);
    }
    func_80025D1C((s32*)((char*)arg0 + 0x3C), 2);
    func_800258B0((s32*)((char*)arg0 + 0x4), 2);
    if ((flag & 1) != 0) {
        free(arg0);
    }
}

void func_8002AE5C(s32 *out, u8 *p) {
    p[0xC] = p[0xC] + (u8)D_800480B8;
    p[0xD] = p[0xD] + (u8)D_800480BC;
    *(u16*)(p + 0xE) = *(u16*)(p + 0xE);
    *(s32*)p = (*(s32*)p & 0xFF000000) | (out[0] & 0xFFFFFF);
    out[0] = (out[0] & 0xFF000000) | (*(s32*)p & 0xFFFFFF);
}

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

void FontHack__UnkFunc00(FAInstance *arg0_fa, s32 flag) {
    s32 *arg0 = (s32*)arg0_fa;
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

extern s32 D_800480B8;
extern s32 D_800480BC;
extern void func_8002F3CC(void);

void func_8002B01C(s32 a0, s32 a1, s32 a2) {
    D_800480B8 = a1 & 0x3F;
    D_800480BC = a2 & 0xFF;
    func_8002F3CC();
}

void func_8002B054(UnkStruct07* arg0) {
    if (arg0->unk0 == 0) {
        arg0->unk4 = 1;
        arg0->unk8 = 1;
        arg0->unk0 = 1;
    }
}

void func_8002B078(UnkStruct07 *arg0) {
    func_8002B054(arg0);
    D_800480C0 = arg0;
}

extern UnkStruct07 *D_800480C0;

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
    s32 v;
    v = 0x4000;
    if (D_800480C0->unk4 == 0) {
        v = 0x2000;
    }
    return v;
}

s32 func_8002B0F8(void) {
    s32 v;
    v = 0x1000;
    if (D_800480C0->unk4 == 0) {
        v = 0x4000;
    }
    return v;
}

extern void *D_80048110;
extern s32 func_80029A38(s32, s32);

void func_8002B11C(s32 arg0) {
    s32 i;
    s32 r;
    s32 v;
    s32 *vt;
    r = func_80029A38(0x78, arg0);
    v = r * r;
    v = (v * 7) + 10;
    if (((s32*)D_80048110)[4] > 0) {
        i = 0;
        do {
            vt = (s32*)((s32*)((char*)((s32*)D_80048110)[5] + i * 4))[0];
            vt[0x12] = v << 16;
            vt[0x11] = 1;
            i++;
        } while (i < ((s32*)D_80048110)[4]);
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

extern s32 D_80048114;

void func_8002B4EC(void) {
    s32 *u8_ptr;
    s32 v;
    if (D_800480E8 == 0 && D_80048108 == 0) {
        func_800293DC(&D_80040840_[0], &D_80040858[0], 0, 0, 1);
        func_8002B42C();
        {
            u8_ptr = (s32*)D_80040840_[2];
            v = D_80040840_[1] * u8_ptr[0];
            v += D_80040840_[0];
            v = (s32)((s32*)((char*)u8_ptr + 8))[v];
            ((s32*)D_80048114)[6] = v << 16;
        }
        if (D_80040858[0] != 0) {
            u8_ptr = (s32*)D_80040840_[2];
            v = D_80040840_[1] * u8_ptr[0];
            v += D_80040840_[0];
            v = (s32)((s32*)((char*)u8_ptr + 8))[v];
            D_800480FC = v + 1;
        }
        func_80025954((s32*)D_80048114);
    }
}

extern void func_800293DC(s32 *, s32 *, s32, s32, s32);
extern s32 D_800480F4;
extern s32 D_80048118;
extern void func_80025954(s32 *);
extern s32 *D_8004084C_arr;

void func_8002B5F0(void) {
    s32 *q;
    s32 v;
    if (D_800480E8 == 0 && D_80048108 == 0) {
        func_800293DC(&D_8004084C[0], &D_80040858[0], 0, 0, 1);
        func_8002B42C();
        {
            s32 a = D_8004084C[1];
            s32 *b = (s32*)D_8004084C[2];
            v = a * b[0];
            v += D_8004084C[0];
            ((s32*)D_80048118)[6] = v << 16;
        }
        if (D_80040858[0] != 0) {
            s32 a = D_8004084C[1];
            s32 *b = (s32*)D_8004084C[2];
            v = a * b[0];
            v += D_8004084C[0];
            D_800480FC = v + 6;
        }
    }
    if (D_800480F4 == 0) {
        func_80025954((s32*)D_80048118);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002B6E0);

extern void func_800293B8(void);
extern s32 D_8004810C[2];
extern s32 D_80048114_arr[2];
extern s32 D_8004811C_[2];

void func_8002BADC(void) {
    s32 i;
    PakFile tmp;
    func_800293B8();
    func_8002B1A0();
    D_80048104 = 3;
    D_80048100 = 3;
    D_800480FC = 0;
    D_80048108 = 0;
    i = 0;
    do {
        D_8004810C[i] = 0;
        i++;
    } while (i < 2);
    i = 0;
    do {
        D_80048114_arr[i] = 0;
        i++;
    } while (i < 2);
    i = 0;
    do {
        D_8004811C_[i] = 0;
        i++;
    } while (i < 2);
    func_8002B6E0();
    tmp.next = NULL;
    tmp.unk4 = 0;
    tmp.size = (s32)&D_800481DC;
    *(PakFile*)&D_80040840_[0] = tmp;
    tmp.next = NULL;
    tmp.unk4 = 0;
    tmp.size = (s32)&D_800481CC;
    *(PakFile*)&D_8004084C[0] = tmp;
}

INCLUDE_ASM("asm/game/nonmatchings/12250", func_8002BC00);

extern void func_8002B1E0(void);
extern void func_8002B4EC(void);
extern void func_8002B5F0(void);

void func_8002BDA8(void) {
    func_8002B1E0();
    if (D_80048100 == 1) {
        func_8002B5F0();
    } else if (D_80048100 < 2 && D_80048100 == 0) {
        func_8002B4EC();
    }
}

extern void func_8002B6E0(void);

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

typedef struct { s32 a; s32 b; } Pair_BE50;
extern Pair_BE50 D_8001A270[];
extern Pair_BE50 D_80040840;

void func_8002BE50(s32 arg0) {
    D_80040840 = D_8001A270[arg0 - 1];
}

extern s32 D_80048108;
extern void func_8002B42C(void);

void func_8002BE84(s32 arg0) {
    D_80040858[0] = 1;
    D_80040858[6] = 0;
    func_8002B42C();
    D_80048108 = 1;
    D_800480FC = arg0;
}

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