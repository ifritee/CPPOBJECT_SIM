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
  /** @brief Возвращает необходимое коичество мультиселектов */
  SUMMABLOCK_API int getMultiselectQty(int index);
  /** @brief Добавление очередного Multiselect */
  SUMMABLOCK_API void addMultiselect(int index, void * multiselect);
  /** @brief Возвращает очередной Мультиселект или nullptr */
  SUMMABLOCK_API void* getMultiselect(int index, int number);
  /** @brief Функция для обеспечения изменения визуальных параметров блока */
  SUMMABLOCK_API void editFunc(int index);
  /** @brief Возвращает количество данных для изменения порта */
  SUMMABLOCK_API int getPortDataQty(int index);
  /** @brief Возвращает количество данных для условного изменения порта */
  SUMMABLOCK_API int getCondPortDataQty(int index);
  /** @brief Возвращает данные для изменение порта */
  SUMMABLOCK_API TPortData getPortData(int index, int number);
  /** @brief Возвращает данные для условного изменение порта */
  SUMMABLOCK_API TCondPortData getCondPortData(int index, int number);
  /** @brief RUN-функция блока, если возвращает значение > 0 - то расчёт будет аварийно остановлен */
  SUMMABLOCK_API NATIVEINT runFunc(int index, double & at, double & h, int action);
}

