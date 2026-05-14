#include "common.h"

#include "globals.h"

#include <psyq/STDIO.H>


INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Init);

// https://decomp.me/scratch/nhYrY
INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Quit);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Unk03);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Unk00);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Unk01);

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

typedef struct Node_2146C {
    char pad0[0x8];
    struct Node_2146C *next;
    char padC[4];
    s32 data;
    char pad14[4];
    s32 dataEnd;
} Node_2146C;

void func_8002146C(s32 arg0, Node_2146C *node) {
    Node_2146C *next;
    s32 end, start, diff;
    if (node != NULL) {
        do {
            func_8002146C(arg0, (Node_2146C*)((s32*)node)[3]);
            end = node->dataEnd;
            start = node->data;
            next = node->next;
            diff = end - start;
            if (start != 0 && diff != 0) {
                MemorySys__free((void*)start);
            }
            MemorySys__free(node);
            node = next;
        } while (node != NULL);
    }
}

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_800214E8);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", func_8002157C);

INCLUDE_ASM("asm/game/nonmatchings/InputSys", InputSys__Ctor);
