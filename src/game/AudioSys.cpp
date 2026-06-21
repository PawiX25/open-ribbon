extern "C" void deletefn(void*) __asm__("delete");
#define delete deletefn

extern "C" {
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

extern s32 func_80032F74(void*, s32);
extern double func_80032784(void*);
extern s32 func_80032A04(double, double);
extern s32 func_8002CCA8(void*, float);
extern s32 func_80030864(s32);
extern void func_80033014(s32, s32);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__SetVolume);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_80019114);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001913C);

extern char D_80019160[];
extern s32 func_800303BC(s32);
extern void FileSys__LoadFile(PakFile*, char*, s32);
extern s32 AudioSys__Unk00(s32, s16);
extern void AudioSys__Unk05(s16, void*, s16);
extern s16 UnkVar04;

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F1D8);

typedef struct {
    s32* unk0;
    PakFile pak;
} SharedPak;

extern s32 D_8003FC9C[];
extern void FileSys__DeleteFile(PakFile);
extern void AudioSys__Unk04(s16);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_8001F42C);

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

typedef struct {
    void* unk0;
    s32* unk4;
    s16* unk8;
    s32* unkC;
    s32* unk10;
    s32 unk14;
} ParseVHObj;

extern s32* func_80030C74(s32);

void AudioSys__ParseVH(ParseVHObj* self, s32 arg1, s32 arg2) {
    s32 i;
    s32 accum;
    s32 base = arg1 + 0x820;

    self->unk0 = (void*)arg1;
    self->unk14 = arg2;
    self->unk4 = (s32*)(arg1 + 0x20);
    self->unk8 = (s16*)base;
    self->unkC = (s32*)(base + (*(u16*)(arg1 + 0x12) << 9));
    free(self->unk10);
    self->unk10 = func_80030C74((*(u16*)((s32)self->unk0 + 0x16) + 1) << 2);

    i = 1;
    accum = 0;
    if (*(u16*)((s32)self->unk0 + 0x16) == 0) {
        return;
    }
    do {
        self->unk10[i] = accum;
        accum += ((u16*)self->unkC)[i] << 3;
        i++;
    } while (i <= *(u16*)((s32)self->unk0 + 0x16));
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

s32 func_8001F74C(s32* arg0, u8 arg1, u8 arg2, s32* arg3, s32* arg4) {
    s32 v6;
    s32 v8;
    s32 result;
    u8* v7;

    if (arg1 >= *(u16*)(arg0[0] + 18)) {
        return 0;
    }
    v6 = 16 * arg1;
    v7 = (u8*)(arg0[1] + v6);
    v8 = v6 + arg2;
    if (arg2 >= *v7) {
        return 0;
    }
    result = arg0[2] + 32 * v8;
    *arg3 = arg0[5] + *(s32*)(4 * *(s16*)(result + 22) + arg0[4]);
    *arg4 = (*(u8*)(arg0[0] + 24) * v7[1]) >> 7;
    return result;
}

typedef struct {
    s32* unk0;
    char pad4[8];
    s32 unkC;
    void* unk10;
    s32 unk14;
    void* unk18;
    char pad1C[4];
    s32 unk20;
} AudioNewObj;

s32* AudioSys__new(s32* arg0, s32 arg1) {
    AudioNewObj* self = (AudioNewObj*)arg0;

    *(void* volatile*)&self->unk18 = &D_8001918C;
    self->unk10 = 0;
    self->unk18 = &AudioSys__UnknownVar;
    AudioSys__ParseVH((ParseVHObj*)self, arg1, -1);
    self->unk14 = -1;
    {
        s32 t = self->unkC + 0x200;
        self->unk20 = self->unk0[3] - (t - arg1);
    }
    return arg0;
}

extern s32 func_80032CA4(s32);
extern void func_80032944(s32);
extern void func_800329A4(s32, s32);

typedef struct {
    char pad0[0x14];
    s32 unk14;
    char pad18[4];
    s32 unk1C;
    s32 unk20;
} AudioSysUnk01Ext;

void AudioSys__Unk01(AudioSysUnk01Ext *arg0, s32 arg1) {
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
    AudioSys__Unk01((AudioSysUnk01Ext*)arg0, arg2);
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

extern s32 D_8003FD8C[];
extern s32 D_8003FD0C;
extern void func_800328E4(s32, void*);

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__InitSpu);

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

extern s32 *AudioSys__new(s32 *, s32);

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
    new_obj = (s32 *)func_800303BC(0x24);
    *slot = (s32)AudioSys__new(new_obj, arg0);
    return (s16)i;
}

extern s32 D_8003FD8C[];

void AudioSys__Unk05(s16 arg0, void* data, s16 flag)
{
	AudioSys__Unk02(D_8003FD8C[arg0], data, flag == 1);
}

typedef struct {
    char pad0[8];
    s16 unk8;
    char padA[2];
    void (*unkC)(void*, s32);
} AudioVTable;

typedef struct {
    char pad0[0x18];
    AudioVTable* unk18;
} AudioObj;

void AudioSys__Unk04(s16 arg0) {
    s32 i = arg0;

    if (i >= 0xA) {
        printf(D_80019114, D_8001913C, 0x17A);
        exit(1);
    }
    if ((AudioObj*)D_8003FD8C[i] != NULL) {
        AudioVTable* vt = ((AudioObj*)D_8003FD8C[i])->unk18;
        vt->unkC((char*)((AudioObj*)D_8003FD8C[i]) + vt->unk8, 3);
    }
    D_8003FD8C[i] = 0;
}

extern s32 func_8001F74C(s32* arg0, u8 arg1, u8 arg2, s32* arg3, s32* arg4);
extern s16 func_80033204(s16, s16, u8, u8);
extern void func_80033330(void*);
extern s32 UnkVar05[24];

/* psyq SpuVoiceAttr layout (LIBSPU.H), defined locally to avoid pulling in
 * LIBSPU.H which conflicts with this file's local SpuFree decl. */
typedef struct { s16 left, right; } LSpuVolume;
typedef struct {
    u32 voice;          /* 0x00 */
    u32 mask;           /* 0x04 */
    LSpuVolume volume;  /* 0x08 */
    LSpuVolume volmode; /* 0x0C */
    LSpuVolume volumex; /* 0x10 */
    u16 pitch;          /* 0x14 */
    u16 note;           /* 0x16 */
    u16 sample_note;    /* 0x18 */
    s16 envx;           /* 0x1A */
    u32 addr;           /* 0x1C */
    u32 loop_addr;      /* 0x20 */
    s32 a_mode;         /* 0x24 */
    s32 s_mode;         /* 0x28 */
    s32 r_mode;         /* 0x2C */
    u16 ar, dr, sr, rr, sl; /* 0x30..0x38 */
    u16 adsr1;          /* 0x3A */
    u16 adsr2;          /* 0x3C */
} LSpuVoiceAttr;

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__UnkFunc06);

s32 func_8001FE34(s32 arg0) {
    s16 v = arg0;
    s32 bit;

    UnkVar05[v] = -1;
    bit = 1 << v;
    voice_bit |= bit;
    UnkVar06 &= ~bit;
    UnkVar07 &= ~bit;
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

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", AudioSys__CallBack);

extern s32 D_80047F84;

s32 AudioSys__UnkFunc08(s32 arg0) {
    return ((UnkVar07 | D_80047F84) >> arg0) & 1;
}

extern s32 D_8003FC9C[];

void func_80020020(void) {
    s32 *p;
    p = (s32*)D_8003FC9C[0];
    if (p == NULL) return;
    *p = *p - 1;
    if (*p != 0) return;
    FileSys__DeleteFile(*(PakFile *)&D_8003FC9C[1]);
    free((void*)D_8003FC9C[0]);
}

void UnkCtor02(void) {
    D_8003FC9C[0] = 0;
    D_8003FC9C[1] = 0;
}

extern void func_800202C0();

void *func_800200AC(void *arg0) {
    *(u8*)arg0 = 1;
    *(u16*)((char*)arg0 + 2) = 0;
    func_800202C0(arg0, 0);
    return arg0;
}

typedef struct {
    u8 unk0;
    u8 pad1;
    u16 unk2;
    u8 pad4[0x14];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24[2];
} UnkStruct200E4;

extern void func_800341A8(s32, void*, s32);

UnkStruct200E4* func_800200E4(UnkStruct200E4* arg0, s32 arg1) {
    s32 i;

    arg0->unk18 = arg1;
    arg0->unk1C = 1;
    arg0->unk20 = -1;
    arg0->unk0 = 1;
    arg0->unk2 = 0;
    func_800202C0(arg0, 0);
    for (i = 0; i < 2; i++) {
        arg0->unk24[i] = 0;
    }
    if ((arg0->unk18 & 3) == 0) {
        func_800341A8(arg0->unk18, arg0->unk24, 2);
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
extern void func_80034170(s32, void*);

typedef struct {
    s8 b0;
    s8 b1;
    u16 h2;
} U201C4Hdr;

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800201C4);

extern u32 func_8002038C(s32, u32);

#define B(o) (*(s8*)((s8*)arg0 + (o)))
#define H(o) (*(u16*)((s8*)arg0 + (o)))
#define W(o) (*(u32*)((s8*)arg0 + (o)))

INCLUDE_ASM("asm/game/nonmatchings/AudioSys", func_800202C0);

#undef B
#undef H
#undef W

u32 func_8002038C(s32 arg0, u32 arg1) {
    s32 a, b;
    int new_var2;
    unsigned int new_var;
    arg1 &= 0xFFFF;
    new_var2 = arg1 & 0xA0;
    b = (new_var = (arg1 & 0x50) != 0);
    a = new_var2;
    if (a) arg1 &= 0xFFAF;
    if (b) arg1 &= 0xFF5F;
    return arg1;
}

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", AudioSys__UnknownVar);

INCLUDE_RODATA("asm/game/nonmatchings/AudioSys", D_8001918C);

}
