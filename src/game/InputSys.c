#include "common.h"

#include "globals.h"

#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Init);

// https://decomp.me/scratch/nhYrY
INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Quit);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Unk03);

extern char D_800191E8[];
extern char D_80019210[];
extern s32 *UnkVar03_arr[];

s32 InputSys__Unk00(s32 arg0) {
    if (arg0 >= 2) {
        printf(D_800191E8, D_80019210, 0xFD);
        exit(1);
    }
    return *UnkVar03_arr[arg0];
}

extern void func_80020AE4(s32 *, s32, s32);
extern s32 D_8003FDB4;

void InputSys__Unk01(s32 *arg0, s32 idx) {
    s32 *expected;
    s32 buf;
    s32 buf_end;
    if (idx >= 2) {
        printf(D_800191E8, D_80019210, 0x103);
        exit(1);
    }
    expected = (s32*)((char*)&D_8003FDB4 + idx * 0xC);
    if (arg0 != expected) {
        func_80020AE4(expected, arg0[0], arg0[1]);
    }
    buf_end = arg0[2];
    buf = arg0[0];
    if (buf != 0 && (buf_end - buf) == 0) {
        MemorySys__free(buf);
    }
}

extern void D_8003FDCC;

void* func_800207C4(void) {
    return &D_8003FDCC;
}

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800207D0);

void func_800208BC(void) {}

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_800191E8);

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_80019210);

INCLUDE_RODATA("asm/game/nonmatchings/InputSys", D_80019234);

extern int (*D_80048028)();
extern char D_80019234[]; // "out of memory\n"
extern s32 MemorySys__malloc(s32);

void InputSys__alloc(s32 arg0) {
    int (*var_v0)();

    do {
        var_v0 = D_80048028;
        if (var_v0 == NULL) {
            printf(&D_80019234);
            exit(1);
        }
        var_v0();
    } while (MemorySys__malloc(arg0) == 0);
}

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_80020920);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_80020AE4);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_80020BA8);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800211D4);

typedef struct ListNode_2146C {
    char pad0[8];
    struct ListNode_2146C *next;
    struct ListNode_2146C *child;
    s32 buf;
    char pad14[4];
    s32 sz;
} ListNode_2146C;

void func_8002146C(s32 arg0, ListNode_2146C *node) {
    if (node != NULL) {
        do {
            ListNode_2146C *next;
            s32 buf;
            s32 sz;
            func_8002146C(arg0, node->child);
            sz = node->sz;
            buf = node->buf;
            next = node->next;
            if (buf != 0 && (sz - buf) == 0) {
                MemorySys__free(buf);
            }
            MemorySys__free((s32)node);
            node = next;
        } while (node != NULL);
    }
}

typedef struct Inner_214E8 {
    s32 u0;
    ListNode_2146C *u4;
    void *u8;
    void *uC;
} Inner_214E8;

typedef struct Outer_214E8 {
    Inner_214E8 *u0;
    s32 u4;
} Outer_214E8;

void func_800214E8(Outer_214E8 *arg0, s32 arg1) {
    Inner_214E8 *p;
    if (arg0->u4 != 0) {
        func_8002146C((s32)arg0, arg0->u0->u4);
        p = arg0->u0;
        p->u8 = (void*)p;
        p = arg0->u0;
        p->u4 = 0;
        p = arg0->u0;
        p->uC = (void*)p;
        arg0->u4 = 0;
    }
    MemorySys__free((s32)arg0->u0);
    if ((arg1 & 1) != 0) {
        free(arg0);
    }
}

extern void *D_8003FDD8;
extern void *D_8003FDCC;
extern char D_8003FDB4[];

void func_8002157C(void) {
    UnkFunc04(&D_8003FDD8, 2);
    func_800214E8(&D_8003FDCC, 2);
    {
        char *base = D_8003FDB4;
        char *p = base + 0x18 - 0xC;
        if (base != NULL && p != base - 0xC) {
            do {
                s32 buf_end = *(s32*)(p + 8);
                s32 buf = *(s32*)p;
                if (buf != 0 && (buf_end - buf) == 0) {
                    MemorySys__free(buf);
                }
                p -= 0xC;
            } while (p != base - 0xC);
        }
    }
}

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Ctor);
