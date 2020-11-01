#pragma once

#include <vector>
#include <string>

namespace cppobj
{
  class UMultiSelect
  {
    void* m_creatorObject; ///< @brief Объект создатель
    /** @brief Данные в чистом виде */
    struct UMSData {
      void* m_memory; ///< @brief Просто данные (пока не используются)
      char16_t* m_listNames; ///< @brief Перечисление данных
      int* m_data; ///< @brief Набор данных
    };
    UMSData * m_data = nullptr; ///< @brief Данные в чистом виде
    
  public:
    /** @brief Конструктор с указателем на delphi-объект TMultiSelect */
    UMultiSelect(void* delphiObject);
    /** @brief Деструктор */
    virtual ~UMultiSelect();
    /** @brief Возвращает указатель на объект создателя */
    void* creator() { return m_creatorObject; }
    /** @brief Возвращает имена лоступных данных */
    std::vector<std::string> listData() const;
    /** @brief Возвращает назначенные данные */
    std::vector<int> data() const;
  };

}
