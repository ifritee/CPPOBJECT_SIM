#pragma once

#include "UConstants.h"

namespace cppobj
{
  class UPtrExtArray
  {
    void* m_object = nullptr; ///< @brief Указатель на объект TPtrExtArray (Delphi)

    SControlData* m_SControlData; ///< @brief Данные управления массивом
  public:
    /** @brief Конструктор */
    explicit UPtrExtArray(void* object);
    /** @brief Деструктор */
    virtual ~UPtrExtArray();
    /** @brief Возвращает необходимые данные 
      * @param channel канал (возможно, порт) 
      * @param index Номер данного в канале (если индекс неверный, то выбрасывется исключение std::out_of_range) */
    double& data(unsigned int channel, int index);
  };
} // namespace cppobj
