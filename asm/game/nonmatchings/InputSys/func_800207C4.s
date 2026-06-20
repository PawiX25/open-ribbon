.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching func_800207C4, 0xC

glabel func_800207C4
    /* 7C4 800207C4 0000023C */  lui        $v0, %hi(D_8003FDCC)
    /* 7C8 800207C8 0800E003 */  jr         $ra
    /* 7CC 800207CC 00004224 */   addiu     $v0, $v0, %lo(D_8003FDCC)
