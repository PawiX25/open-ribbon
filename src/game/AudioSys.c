#include "common.h"

#include "globals.h"

#include <psyq/LIBGTE.H>
#include <psyq/STDIO.H>

// is this bss or data???
s16 UnkVar04 = 0;  // 0x80047F78
s32 UnkVar06 = 0;  // 0x80047F7C
s32 voice_bit = 0; // 0x80047F80
s32 D_80047F84 = 0;
s32 UnkVar07 = 0;  // 0x80047F88

char D_80047F8C[2] = "%d";
char D_80047F90[2] = "%u";
char D_80047F94[2] = "";

s32 D_80047F98 = 0xFFFF0100;
s32 D_80047F9C = 0x0000FFFF;

extern char D_80019114[];
extern char D_8001913C[];
extern s32 D_8003FC9C[];
extern s32 D_8003FD8C[];
extern void AudioSys__ParseVH(s32 *, s32 *, s32);
extern u32 func_8002038C(s32, u16);
extern void func_800202C0(s32 *, s32);
extern s32 func_8001FE34(s16);

void AudioSys__Init() {
    SpuInit();
    AudioSys__InitSpu();
    VideoSys__AddVSyncCB(&AudioSys__CallBack);
}

void AudioSys__QuitSpu() {
    VideoSys__RemoveVSyncCB(&AudioSys__CallBack);
    UnkFunc00();
    SpuQuit();
}

extern s32 func_80032F74(s32, s32);
extern s32 func_80032784(s32);
extern s32 func_80032A04(s32, s32, s32, s32);
extern void func_8002CCA8(s32, s32);
extern s16 func_80030864(s32);
extern void func_80033014(s32, s32);

void AudioSys__SetVolume(s32 arg0) {
    s32 r = func_80032F74(arg0, 0);
    s32 r2;
    if (r < 0) {
        printf(D_80019114, D_8001913C, 0x3D);
        exit(1);
    }
    r2 = func_80032784(arg0);
    r = func_80032A04(r2, r, 0, 0x3FF00000);
    if (r > 0) {
        printf(D_80019114, D_8001913C, 0x3D);
        exit(1);
    }
    func_8002CCA8(arg0, 0x467FFC00);
    r2 = func_80030864(r);
    {
        s16 r3 = (s16)r2;
        func_80033014(r3, r3);
    }
}

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_80019114);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001913C);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F1D8);

void func_8001F42C(void) {
    s32 *p;
    s32 *q;
    PakFile pf;
    s32 fd[2];
    s32 *base;
    AudioSys__Unk04(UnkVar04);
    fd[0] = 0;
    fd[1] = 0;
    if (D_8003FC9C[1] != fd[1]) {
        p = (s32*)D_8003FC9C[0];
        if (p != NULL) {
            *p = *p - 1;
            if (*p == 0) {
                pf = *(PakFile*)&D_8003FC9C[1];
                FileSys__DeleteFile(pf);
                free((void*)D_8003FC9C[0]);
            }
        }
        D_8003FC9C[1] = fd[1];
        D_8003FC9C[2] = fd[2];
        D_8003FC9C[3] = fd[3];
        D_8003FC9C[0] = fd[0];
        if (fd[0] != 0) {
            *(s32*)fd[0] = *(s32*)fd[0] + 1;
        }
    }
    p = (s32*)fd[0];
    if (p != NULL) {
        *p = *p - 1;
        if (*p == 0) {
            pf = *(PakFile*)&fd[1];
            FileSys__DeleteFile(pf);
            free((void*)fd[0]);
        }
    }
}

// This function seems to be configuring the audio settings (By the AudioSys__Unk06)
void AudioSys__UnkFunc01(UnkStruct02* arg0, s16 arg1, s16 arg2, s16 arg3)
{
    AudioSys__UnkFunc06(arg1, UnkVar04, arg0->unk0, arg0->unk4, (s16) (arg0->unk4 + 1), 0, arg2, arg2, arg3);
}

extern s32 func_8001FE34(s32);

s32 func_8001F5E4(s16 arg0) {
    return func_8001FE34(arg0);
}

int AudioSys__UnkFunc09()
{
    return AudioSys__UnkFunc08();
}

extern s32 func_80030C74(s32);

void AudioSys__ParseVH(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 i;
    s32 v0;
    s32 *table;
    arg0[0] = (s32)arg1;
    arg0[5] = arg2;
    arg0[1] = (s32)((char*)arg1 + 0x20);
    arg0[2] = (s32)((char*)arg1 + 0x820);
    v0 = ((u16*)arg1)[9] << 9;
    free(arg0[4]);
    arg0[3] = (s32)((char*)arg1 + 0x820 + v0);
    {
        s32 cnt = ((u16*)arg0[0])[0xB] + 1;
        s32 sz = cnt * 4;
        arg0[4] = (s32)func_80030C74(sz);
    }
    {
        s32 cnt2;
        i = 1;
        cnt2 = ((u16*)arg0[0])[0xB];
        if (cnt2 != 0) {
            s32 acc = 0;
            do {
                ((s32*)arg0[4])[i] = acc;
                {
                    u16 sz_w = ((u16*)arg0[3])[i - 1];
                    acc += sz_w << 3;
                }
                i++;
            } while (((u16*)arg0[0])[0xB] >= i);
        }
    }
}

typedef struct {
    char pad0[0x10];
    void *unk10;
    s32 unk14;
    void *unk18;
} AudioSysUnkStruct02;

extern u32 D_8001918C;
extern u32 AudioSys__UnknownVar;
extern void SpuFree(s32);

void AudioSys__UnkFunc00(AudioSysUnkStruct02 *arg0, s32 arg1) {
    arg0->unk18 = &D_8001918C;
    if (arg0->unk10 != NULL) {
        delete(arg0->unk10);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

s32 func_8001F74C(s32 **arg0, u8 a1, u8 a2, s32 *out_a3, s32 *out_a4) {
    u8 *p1;
    s16 *p2;
    s32 *base4;
    s32 *base5;
    s32 v;
    if (a1 >= ((u16*)arg0[0])[9]) return 0;
    p1 = (u8*)arg0[1] + a1 * 16;
    if (a2 >= p1[0]) return 0;
    p2 = (s16*)((char*)arg0[2] + ((a1 * 16 + a2) << 5));
    base4 = (s32*)arg0[4];
    base5 = (s32*)arg0[5];
    *out_a3 = base5[(s16)p2[0xB]] + (s32)base4;
    {
        u8 hi = ((u8*)arg0[0])[0x18];
        u8 lo = p1[1];
        v = ((s32)hi * (s32)lo) >> 7;
        *out_a4 = v;
    }
    return 1;
}

extern void AudioSys__ParseVH(void *, s32, s32);

typedef struct {
    s32 *unk0;
    char pad4[8];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    void *unk18;
    char pad1C[4];
    s32 unk20;
} AudioObj_New;

AudioObj_New *AudioSys__new(AudioObj_New *arg0, s32 arg1) {
    arg0->unk18 = (void*)&D_8001918C;
    arg0->unk10 = 0;
    arg0->unk18 = (void*)&AudioSys__UnknownVar;
    AudioSys__ParseVH(arg0, arg1, -1);
    arg0->unk14 = -1;
    arg0->unk20 = arg0->unk0[3] - (arg0->unkC + 0x200 - arg1);
    return arg0;
}

extern s32 func_80032CA4(s32);
extern void func_80032944(s32);
extern void func_800329A4(s32, s32);
extern char D_80019114[];
extern char D_8001913C[];

typedef struct {
    char pad0[0x14];
    s32 unk14;
    char pad18[4];
    s32 unk1C;
    s32 unk20;
} AudioSysUnkStruct02_Ext;

void AudioSys__Unk01(AudioSysUnkStruct02_Ext *arg0, s32 arg1) {
    s32 r = func_80032CA4(arg0->unk20);
    arg0->unk14 = r;
    if (r < 0) {
        printf(D_80019114, D_8001913C, 0x128);
        exit(1);
    }
    func_80032944(r);
    func_800329A4(arg0->unk1C, arg0->unk20);
    AudioSys__IsTransferCompleted(arg1);
}

typedef struct {
    char unk0[0x1c];
    s32 unk1C;
} AudioSysUnkStruct01;

void AudioSys__Unk02(AudioSysUnkStruct01* arg0, s32 arg1, s32 arg2) {
    arg0->unk1C = arg1;
    AudioSys__Unk01(arg0, arg2);
}

s32 AudioSys__IsTransferCompleted(s32 flag)
{
    return SpuIsTransferCompleted(flag != 0) != 0;
}

void AudioSys__Dtor(AudioSysUnkStruct02 *arg0, s32 arg1) {
    arg0->unk18 = &AudioSys__UnknownVar;
    if (arg0->unk14 >= 0) {
        SpuFree(arg0->unk14);
    }
    AudioSys__UnkFunc00(arg0, arg1);
}

extern void func_800328E4(s32, void *);
extern s32 D_8003FD0C;
extern s32 UnkVar05[];

void AudioSys__InitSpu(void) {
    s32 i;
    func_800328E4(0xF, &D_8003FD0C);
    for (i = 0; i < 10; i++) {
        D_8003FD8C[i] = 0;
    }
    UnkVar06 = 0;
    voice_bit = 0;
    D_80047F84 = 0;
    UnkVar07 = 0;
    for (i = 0; i < 24; i++) {
        UnkVar05[i] = -1;
    }
}

extern s32 D_8003FD8C[];

void UnkFunc00(void) {
    s32 i;
    s32 *p;
    s32 *vt;
    s16 offset;
    void (*func)(s32, s32);

    AudioSys__UnkFunc07();
    AudioSys__CallBack();
    for (i = 0; i < 10; i++) {
        p = (s32*)D_8003FD8C[i];
        if (p != NULL) {
            vt = (s32*)p[6];
            offset = ((s16*)vt)[4];
            func = (void(*)(s32, s32))vt[3];
            func((s32)p + offset, 3);
        }
    }
}

extern s32 func_800303BC(s32);

s32 AudioSys__Unk00(s32 arg0, s16 arg1) {
    s32 i;
    s32 *slot;
    s32 *new_obj;
    if ((s32)(s16)arg1 != -1) {
        printf(D_80019114, D_8001913C, 0x15E);
        exit(1);
    }
    i = 0;
    while (i < 10) {
        if (D_8003FD8C[i] == 0) break;
        i++;
    }
    if (i == 10) return -1;
    slot = &D_8003FD8C[i];
    new_obj = (s32*)func_800303BC(0x24);
    *slot = (s32)AudioSys__new(new_obj, arg0);
    return (s16)i;
}

extern s32 D_8003FD8C[];

void AudioSys__Unk05(s16 arg0, void* data, s16 flag)
{
	AudioSys__Unk02(D_8003FD8C[arg0], data, flag == 1);
}

typedef struct VT_Unk04 {
    char pad0[8];
    s16 offset8;
    char padA[2];
    void (*funcC)(s32, s32);
} VT_Unk04;

void AudioSys__Unk04(s16 arg0) {
    s32 idx = arg0;
    s32 *slot;
    s32 *item;
    if (idx >= 10) {
        printf(D_80019114, D_8001913C, 0x17A);
        exit(1);
    }
    slot = &D_8003FD8C[idx];
    item = (s32*)*slot;
    if (item != NULL) {
        VT_Unk04 *vt = (VT_Unk04*)item[6];
        vt->funcC((s32)item + vt->offset8, 3);
    }
    *slot = 0;
}

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc06);

s32 func_8001FE34(s16 arg0) {
    s32 idx = (s32)arg0;
    s32 mask;
    UnkVar05[idx] = -1;
    mask = 1 << idx;
    voice_bit = voice_bit | mask;
    UnkVar07 = UnkVar07 & ~mask;
    UnkVar06 = UnkVar06 & ~mask;
    return 0;
}

void AudioSys__UnkFunc07() // Clears the UnkVar05 values
{
    s32 i;

    voice_bit = 0xFFFFFF;
    i = 0;
    UnkVar06 = 0;
    UnkVar07 = 0;

    while (i < 24)
    {
        UnkVar05[i] = -1;
        i++;
    }
}

extern s32 func_800326F4(s32);
extern void func_80032AE4(s32);

s32 AudioSys__CallBack(void) {
    s32 mask;
    s32 status;
    s32 unkVar7 = UnkVar07;
    s32 unkVar84 = D_80047F84;
    s32 i;
    for (i = 0; i < 24; i++) {
        mask = 1 << i;
        if (((unkVar7 | unkVar84) & mask) == 0) continue;
        status = func_800326F4(mask);
        if (status >= 3) {
            if (status == 3) {
                if ((unkVar84 & mask) != 0) {
                    s32 vid = UnkVar05[i];
                    if (vid >= 0) {
                        UnkVar05[i] = -1;
                        UnkVar06 = UnkVar06 | (1 << vid);
                    }
                }
                unkVar84 = unkVar84 & ~mask;
            }
            continue;
        }
        if (status > 0) {
            unkVar7 = unkVar7 & ~mask;
            unkVar84 = unkVar84 | mask;
        } else if (status == 0) {
            if ((unkVar84 & mask) != 0) {
                s32 vid = UnkVar05[i];
                if (vid >= 0) {
                    UnkVar05[i] = -1;
                    UnkVar06 = UnkVar06 | (1 << vid);
                }
            }
            unkVar84 = unkVar84 & ~mask;
        }
    }
    D_80047F84 = unkVar84;
    UnkVar07 = unkVar7;
    if (voice_bit != 0) {
        func_80032AE4(0);
        voice_bit = 0;
    }
    if (UnkVar06 != 0) {
        func_80032AE4(1);
        UnkVar06 = 0;
    }
    return 0;
}

extern s32 D_80047F84;

s32 AudioSys__UnkFunc08(s32 arg0) {
    return ((UnkVar07 | D_80047F84) >> arg0) & 1;
}

extern s32 D_8003FC9C[];

void func_80020020(void) {
    s32 *p;
    PakFile pf;
    p = (s32*)D_8003FC9C[0];
    if (p == NULL) return;
    *p = *p - 1;
    if (*p != 0) return;
    pf = *(PakFile *)&D_8003FC9C[1];
    FileSys__DeleteFile(pf);
    free((void*)D_8003FC9C[0]);
}

void UnkCtor02(void) {
    D_8003FC9C[0] = 0;
    D_8003FC9C[1] = 0;
}

extern void *func_800202C0(void *, s32);

void *func_800200AC(void *arg0) {
    *(u8*)arg0 = 1;
    *(u16*)((char*)arg0 + 2) = 0;
    func_800202C0(arg0, 0);
    return arg0;
}

extern void func_800341A8(void *, s32, s32);

s32* func_800200E4(s32 *arg0, s32 arg1) {
    s32 i;
    arg0[6] = arg1;
    arg0[7] = 1;
    arg0[8] = -1;
    *(s8*)arg0 = 1;
    *(s16*)((char*)arg0 + 2) = 0;
    func_800202C0(arg0, 0);
    i = 0;
    do {
        ((s8*)arg0)[0x24 + i] = 0;
        i++;
    } while (i < 2);
    if ((arg1 & 3) == 0) {
        func_800341A8(arg0, 0, 2);
    }
    return arg0;
}

void UnkFunc04(UnkStruct10* arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = arg0->unk6;
    if (!(temp_a0 & 3)) {
        func_800341A8(temp_a0, 0, 0);
    }
    if (arg1 & 1) {
        free(arg0);
    }
}

extern s32 func_80033FD0(s32);
extern void func_80034170(s32, s32 *);
extern s32 D_80047F98;

void func_800201C4(s32 *arg0, s8 *arg1) {
    s32 r;
    *(s8*)arg0 = arg1[0];
    *((s8*)arg0 + 1) = arg1[1];
    if (*(u8*)arg0 != 0) {
        func_800202C0(arg0, 0);
    } else {
        func_800202C0(arg0, ~(*(u16*)((s8*)arg1 + 2)) & 0xFFFF);
    }
    r = func_80033FD0(arg0[6]);
    if (r == arg0[8]) goto end;
    if (r == 1) {
        arg0[7] = 1;
    } else if (r < 2) {
        if (r == 0) {
            func_800202C0(arg0, 0);
        }
    } else if (r == 6) {
        if (arg0[7] != 0) {
            arg0[7] = 0;
            func_80034170(arg0[6], &D_80047F98);
        }
    }
end:
    arg0[8] = r;
}

void *func_800202C0(s32 *arg0, u16 arg1) {
    u16 v;
    s32 a0_val;
    u16 v0_h, v1_h;
    *((s8*)arg0 + 4) = *((s8*)arg0 + 2);
    *((s8*)arg0 + 5) = *((s8*)arg0 + 3);
    *(u16*)((s8*)arg0 + 2) = arg1;
    a0_val = arg0[0];
    if ((a0_val & 0x500000) == 0x500000 || (a0_val & 0xA00000) == 0xA00000) {
        *(u16*)((s8*)arg0 + 2) = arg1 & 0xFF0F;
    }
    v0_h = *(u16*)((s8*)arg0 + 4);
    v1_h = *(u16*)((s8*)arg0 + 2);
    {
        u16 x = v0_h ^ v1_h;
        u16 y = v1_h & x;
        u16 z = x & ~v1_h;
        *(u16*)((s8*)arg0 + 6) = x;
        *(u16*)((s8*)arg0 + 8) = y;
        *(u16*)((s8*)arg0 + 0xA) = z;
    }
    *((s8*)arg0 + 0xE) = *((s8*)arg0 + 0xC);
    *((s8*)arg0 + 0xF) = *((s8*)arg0 + 0xD);
    {
        u16 r = (u16)func_8002038C((s32)arg0, *(u16*)((s8*)arg0 + 2));
        u16 prev_e = *(u16*)((s8*)arg0 + 0xE);
        u16 d = (prev_e ^ r) & 0xFFFF;
        u16 a = r & d;
        u16 b = d & ~r;
        *(u16*)((s8*)arg0 + 0xC) = r;
        *(u16*)((s8*)arg0 + 0x10) = d;
        *(u16*)((s8*)arg0 + 0x12) = a;
        *(u16*)((s8*)arg0 + 0x14) = b;
    }
    return NULL;
}

u32 func_8002038C(s32 a0, u16 a1) {
    u32 v = a1 & 0xFFFF;
    u32 hi = v & 0xA0;
    u32 lo = v & 0x50;
    if (hi != 0) {
        v &= 0xFFAF;
    }
    if (lo != 0) {
        v &= 0xFF5F;
    }
    return v;
}

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", AudioSys__UnknownVar);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001918C);
