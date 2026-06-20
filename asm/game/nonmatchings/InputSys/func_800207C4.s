.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching func_800207C4, 0xC

glabel func_800207C4
    /* 7FC4 800207C4 0480023C */  lui        $v0, %hi(D_8003FDCC)
    /* 7FC8 800207C8 0800E003 */  jr         $ra
    /* 7FCC 800207CC CCFD4224 */   addiu     $v0, $v0, %lo(D_8003FDCC)
