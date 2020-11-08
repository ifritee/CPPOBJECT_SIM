#pragma once

#include <vector>
#include <string>

namespace cppobj
{
  class UMultiSelect
  {
    void* m_creatorObject; ///< @brief ������ ���������
    /** @brief ������ � ������ ���� */
    struct UMSData {
      void* m_memory; ///< @brief ������ ������ (���� �� ������������)
      char16_t* m_listNames; ///< @brief ������������ ������
      int* m_data; ///< @brief ����� ������
    };
    UMSData * m_data = nullptr; ///< @brief ������ � ������ ����
    
  public:
    /** @brief ����������� � ���������� �� delphi-������ TMultiSelect */
    UMultiSelect(void* delphiObject);
    /** @brief ���������� */
    virtual ~UMultiSelect();
    /** @brief ���������� ��������� �� ������ ��������� */
    void* creator() { return m_creatorObject; }
    /** @brief ���������� ����� ��������� ������ */
    std::vector<std::string> listData() const;
    /** @brief ���������� ����������� ������ */
    std::vector<int> data() const;
  };

} // namespace cppobj
