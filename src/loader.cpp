#include "loader.h"

#include <sys/types.h>

#include <libetc.h>
#include <libcd.h>

extern char          D_80014A08[32];
extern unsigned char D_800167D8[4];

extern "C" {

void func_800106BC() {
    if (CdMode() & 0x80) {
        return;
    }

    CdControl(CdlSetmode, (u_char*)D_800167D8, 0);

    int s0 = VSync(-1);
    while (1) {
        if (VSync(-1) >= s0 + 4) {
            break;
        }
    }
}

void func_80010720(char* out_path, char* path) {
    *out_path++ = '\\';

    while (*path != '\0') {
        char ch = *path++;
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - ('a' - 'A');
        } else if (ch == '/') {
            ch = '\\';
        }
        *out_path++ = ch;
    }

    *out_path++ = ';';
    *out_path++ = '1';
    *out_path++ = '\0';
}

#if 0
bool func_80010794(char* path) {
    CdlFILE file;

    func_80010720(D_80014A08, path);
    CdlFILE* pFile = CdSearchFile(&file, D_80014A08);

    if (pFile == NULL) {
        return false;
    }
    if (pFile == (CdlFILE*)-1) {
        return false;
    }

    D_800167DC = CdPosToInt(&pFile->pos);
    return true;
}
#else
INCLUDE_ASM("asm/loader/nonmatchings/loader", func_80010794);
#endif

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_80010800);

void func_80010884(void) {
    /* Empty */
}

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_8001088C);

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_800108BC);

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_800108EC);

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_80010A24);

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_80010A90);

INCLUDE_ASM("asm/loader/nonmatchings/loader", func_80010ABC);

INCLUDE_RODATA("asm/loader/nonmatchings/loader", D_80010100);

INCLUDE_RODATA("asm/loader/nonmatchings/loader", D_8001010C);

INCLUDE_RODATA("asm/loader/nonmatchings/loader", D_80010118);

INCLUDE_RODATA("asm/loader/nonmatchings/loader", D_80010124);

};
