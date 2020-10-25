// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "Windows.h"

#ifdef SUMMABLOCK_EXPORTS
#define SUMMABLOCK_API __declspec(dllexport)
#else
#define SUMMABLOCK_API __declspec(dllimport)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" {
  SUMMABLOCK_API int createModule()
  {
    return 0;
  }
  SUMMABLOCK_API void destroyModule(int)
  {

  }
}
