#pragma once

#include <string>
#include <vector>

#include "UConstants.h"
#include "UMultiSelect.h"

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
    /** @brief Возвращает количество необходимых мультселектов */
    int getMultiselectQty() { return m_multiselectQty; }
    /** @brief Задание очередного Мультиселекта */
    void addMultiselect(void* multiselect);
    /** @brief Возвращает очередной Мультиселект или nullptr */
    void* getMultiselect(int number);

  protected:
    int m_multiselectQty = 0; ///< @brief Количество необходимых мультиселектов
    std::vector<UMultiSelect* > m_multiselects; ///< @brief Набор мультиселектов
  };
  /** @brief Функция создания объекта - не может быть 2 таких */
  extern BlockInterface * CreateBlockObject();
}



