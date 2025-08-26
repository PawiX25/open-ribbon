#ifndef GAMEPARAMS_H
#define GAMEPARAMS_H

#include "common.h"

class CGameParams {
public:
    CGameParams();
private:
    PADDING(unk0, 0x78);
    s32 unk78;
    PADDING(unk7C, 0x1c);
    s32 unk98;
    PADDING(unk9C, 0x8);
};

#endif /* GAMEPARAMS_H */
