#pragma once

#include <string>

#include "UConstants.h"

namespace cppobj 
{

  /** @class BlockInterface
  * @brief Интерфейс для блоков */
  class BlockInterface
  {
  public:
    /** @brief Конструктор */
    explicit BlockInterface();
    /** @brief Деструктор */
    virtual ~BlockInterface();
    /** @brief Информационный контроль состояния модели */
    virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) = 0;
    /** @brief Получить тип и идентификатор параметра - по умолчанию соответсвует адресу параметра, тип - вещественное; Result = - 1 - параметр не найден */
    virtual NATIVEINT getParamID(const std::string & paramName, TDataType& dataType, bool& isConst) = 0;
  };
  /** @brief Функция создания объекта - не может быть 2 таких */
  extern BlockInterface * CreateBlockObject();
}



