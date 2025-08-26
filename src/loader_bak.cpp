#include "loader.h"

#if 0
bool Loader::Execute(char* pszFilename) {
    u_long exe_addr;

    bool bRet = Loader::SearchFile(pszFilename);
    if (!bRet) {
        printf("exe open failed\n");
        goto fail;
    }

    bRet &= Loader::ReadFile(&g_Exec, 0, 1);
    if (!bRet) {
        printf("exe header load failed\n");
        goto fail;
    }

    exe_addr = D_800167D4 + _ramsize - 0x10000;
    assert(exe_addr == g_Exec.exec.t_addr, "C:/psj/dev/locale/game/loader.cpp", 283);

    bRet &= Loader::ReadFile((void*)exe_addr, 1, g_Exec.exec.t_size / 2048);
    if (!bRet) {
        printf("exe body load failed\n");
        goto fail;
    }

    func_80010884();

    ::StopCallback();
    ::EnterCriticalSection();
    ::FlushCache();

    bRet &= ::Exec(&g_Exec.exec, 0x9999a2f2, &gArgs);
    if (!bRet) {
        printf("Exec call failed\n");
        goto fail;
    }

fail:
    return bRet;
}
#endif

#if 0
int main() {
    printf("Loader main()\n");

    Loader::Initialize();

    D_80014960.nExecIdx = 0;
    D_80014960.unk4 = 0;
    D_80014960.unk84 = 1;
    D_80014960.unk8C = 0;

    while (1) {
        Loader::Execute(D_80010124[D_80014960.nExecIdx].pszName);
        Loader::Reset();
    }
}
#endif
