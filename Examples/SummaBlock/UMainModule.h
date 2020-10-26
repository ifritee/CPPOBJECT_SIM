#pragma once

#include "UConstants.h"

#ifdef CPPBLOCK_EXPORTS
#define SUMMABLOCK_API __declspec(dllexport)
#else
#define SUMMABLOCK_API __declspec(dllimport)
#endif // CPPBLOCK_EXPORTS

extern "C" 
{
  /** @brief Создание модуля (возвращает ID модуля)*/
  SUMMABLOCK_API int createModule();
  /** @brief Удаление модуля */
  SUMMABLOCK_API void destroyModule(int);
  /** @brief Информационный контроль состояния модели */
  SUMMABLOCK_API NATIVEINT infoFunc(int index, int Action, NATIVEINT aParameter);
}

