#pragma once

#include <string>

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
  /** @brief Получить тип и идентификатор параметра - по умолчанию соответсвует адресу параметра, тип - вещественное; Result = - 1 - параметр не найден */
  SUMMABLOCK_API NATIVEINT getParamID(int index, const char * ParamName, TDataType& DataType, bool& IsConst);
}

