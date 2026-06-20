#include "common.h"

#include "globals.h"

// .sdata
s32 D_80047EC0 = 0;
s32 D_80047EC4 = 0;
s32 D_80047EC8 = 0;
s32 D_80047ECC = 0;
s32 buffer_i = 0; // 0x80047ED0

// what is this?!
// s32 D_80047EE0; // 0x2F6E0 -> 0x2573 => "%s"

// .sbss
s32 D_80047EE4;
s32 D_80047EE8;
s32 D_80047EEC;
s32 D_80047EF0;
s32 D_80047EF4;
s32 D_80047EF8;
s32 D_80047EFC;
s32 D_80047F00;
s32 D_80047F04;
s32 fntStream;  // 0x80047F08
s32 D_80047F0C;
s32 D_80047F10;
s32 D_80047F14;
s32 D_80047F18;

void VideoSys__FlipBuffer()
{
	buffer_i = (buffer_i + 1) % 2;
}

void VideoSys__OnDrawSync() {}

void VideoSys__OnVSync()
{
	VSyncCb* cb;

	for (cb = vsync.cb; cb < (VSyncCb*)vsync.tail; cb++)
	{
		(*cb)();
	}
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__Init);

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_80019000);

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_80019028);

typedef struct {
    s32* u0;
    s32* u4;
} VideoSysOT;

extern VideoSysOT D_8003F964[];

typedef struct {
    s32 unk0;
    void* unk4;
    s32 unk8;
} OTBuf;

extern void func_8002C150(s32);
extern char D_8001904C[];

void VideoSys__Quit(void) {
    OTBuf* n;
    OTBuf* report;
    s32 i;

    func_8002C150(0);

    report = (OTBuf*)D_8003F964[0].u0;
    printf(D_8001904C, report->unk8, report->unk0);

    for (i = 0; i < 2; i++) {
        n = (OTBuf*)D_8003F964[i].u4;
        if (n != 0) {
            if (n->unk4 != 0) {
                delete(n->unk4);
            }
            free(n);
        }
        n = (OTBuf*)D_8003F964[i].u0;
        if (n != 0) {
            free(n->unk4);
            free(n);
        }
    }
}

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_8001904C);

void VideoSys__Reset()
{
  ResetGraph(1);
  VSync(0);
  SetDispMask(0);
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", VideoSys__Flip);

extern char D_80047EE0[];
extern void func_8002FA40(s32, char *, s32);

void VideoSys__WriteFnt(s32 arg0) {
    func_8002FA40(fntStream, D_80047EE0, arg0);
}

void VideoSys__DisplayFnt()
{
	FntFlush(fntStream);
}

s32* VideoSys__GetOT(void) {
    return D_8003F964[buffer_i].u4;
}

extern char D_80019000[];
extern char D_80019028[];
extern void func_8001E4E4(struct VSyncCbList*, VSyncCb, void**);

void VideoSys__AddVSyncCB(void* cb) {
    s32 count = ((s32)vsync.tail - (s32)vsync.cb) >> 2;
    s32 cap = ((s32)vsync.unk8 - (s32)vsync.cb) >> 2;

    if ((u32)count >= (u32)cap) {
        printf(D_80019000, D_80019028, 0x23E);
        exit(1);
    }

    SwEnterCriticalSection();
    if (vsync.tail != (VSyncCb)vsync.unk8) {
        *(void**)vsync.tail = cb;
        vsync.tail = (VSyncCb)((s32)vsync.tail + 4);
    } else {
        func_8001E4E4(&vsync, vsync.tail, &cb);
    }
    SwExitCriticalSection();
}

extern s32 func_8001E658(s32, s32, s32*, s32);
extern void func_80030BF4(s32, s32, s32);

void VideoSys__RemoveVSyncCB(s32 arg0) {
    s32 v0;
    s32 v1;

    SwEnterCriticalSection();

    v0 = func_8001E658((s32)vsync.cb, (s32)vsync.tail, &arg0, 0);
    v1 = v0 + 4;
    if (v1 != (s32)vsync.tail) {
        func_80030BF4(v0, v1, ((s32)vsync.tail - v1) >> 0x2 << 0x2);
    }

    vsync.tail = (VSyncCb)((s32)vsync.tail - 4);
    SwExitCriticalSection();
}

INCLUDE_RODATA("asm/game/nonmatchings/VideoSys", D_8001906C);

extern int (*D_80048028)();
extern char D_8001906C[]; // "out of memory\n"
extern s32 MemorySys__malloc(s32);

void VideoSys__alloc(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_8001906C);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

INCLUDE_ASM("asm/game/nonmatchings/VideoSys", func_8001E4E4);
