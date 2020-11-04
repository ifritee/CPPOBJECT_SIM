#pragma once

#include <string>
#include <vector>
#include <queue>

#include "UConstants.h"
#include "UMultiSelect.h"

namespace cppobj 
{

  class URunObject;

  /** @class BlockInterface
    * @brief Интерфейс для блоков */
  class BlockInterface
  {
  public:
    /** @brief Конструктор */
    explicit BlockInterface(void *);
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
    /** @brief Возвращает количество данных для изменения порта */
    int getPortDataQty();
    /** @brief Возвращает количество данных для условного изменения порта */
    int getCondPortDataQty();
    /** @brief Возвращает данные для изменение порта */
    TPortData getPortData(int number);
    /** @brief Возвращает данные для условного изменение порта */
    TCondPortData getCondPortData(int number);
    /** @brief Функция для обеспечения изменения визуальных параметров блока */
    virtual void editFunc() = 0;
    /** @brief RUN-функция блока */
    virtual NATIVEINT run(double& at, double& h, EWorkState workState) = 0;

  protected:
    URunObject * m_runObject = nullptr;
    int m_multiselectQty = 0; ///< @brief Количество необходимых мультиселектов
    std::vector<UMultiSelect* > m_multiselects; ///< @brief Набор мультиселектов
    std::vector< TPortData > m_portData; ///< @brief Данные для изменения
    std::vector< TCondPortData > m_condPortData; ///< @brief Данные для условного изменения
  };

  /** @brief Функция создания объекта - не может быть 2 таких */
  extern BlockInterface * CreateBlockObject(void *);
}



