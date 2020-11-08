#pragma once

#include "UConstants.h"

namespace cppobj
{
  class UPtrExtArray
  {
    void* m_object = nullptr; ///< @brief ��������� �� ������ TPtrExtArray (Delphi)

    SControlData* m_SControlData; ///< @brief ������ ���������� ��������
  public:
    /** @brief ����������� */
    explicit UPtrExtArray(void* object);
    /** @brief ���������� */
    virtual ~UPtrExtArray();
    /** @brief ���������� ����������� ������ 
      * @param channel ����� (��������, ����) 
      * @param index ����� ������� � ������ (���� ������ ��������, �� ������������ ���������� std::out_of_range) */
    double& data(unsigned int channel, int index);
  };
} // namespace cppobj
