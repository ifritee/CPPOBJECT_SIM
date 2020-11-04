#pragma once

#include "UConstants.h"

namespace cppobj
{
  /** @class UIntArray 
    * @brief Класс-обработчик данных из Delphi объекта с типом TIntArray */
  class UIntArray
  {
    void* m_object = nullptr; ///< @brief Указатель на объект TIntArray (Delphi)
    int & m_arrayLength;  ///< @brief Длина массива
    int & m_reserv; ///< @brief Возможно, тоже длина

  public:
    /** @brief Конструктор с параметром 
      * @param objet - Указатель на значение с указателем на объект TIntArray */
    explicit UIntArray(void* object);
    /** @brief Деструктор */
    virtual ~UIntArray();
    /** @brief Возвращает ссылку на выбранное данное, если данного нет, то выбрасывется исключение std::out_of_range */
    NATIVEINT & operator[] (int);
  };
}
