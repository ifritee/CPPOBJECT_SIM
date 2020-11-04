#pragma once

namespace cppobj
{

  class UIntArray;
  class UPtrExtArray;

  /** @class URunObject 
    * @brief Класс-обработчик данных из Delphi TCppObjectBlock (TRunObject) */
  class URunObject
  {
    void* m_creatorObject; ///< @brief Объект создатель
    UIntArray* m_cU;  ///< @brief Массив размерностей входов блока
    UPtrExtArray* m_U;  ///< @brief Массив входов блока
    UIntArray* m_cY;  ///< @brief Массив размерностей выходов блока
    UPtrExtArray* m_Y;  ///< @brief Массив выходов блока

  public:
    /** @brief Конструктор с параметром - указатель на объект TCppObjectBlock */
    explicit URunObject(void * object);
    /** @brief Деструктор */
    virtual ~URunObject();
    /** @brief Возвращает ссылку на Массив размерностей входов блока */
    UIntArray& cU() { return *m_cU; }
    /** @brief Возвращает ссылку на Массив размерностей выходов блока */
    UIntArray& cY() { return *m_cY; }
  };

}
