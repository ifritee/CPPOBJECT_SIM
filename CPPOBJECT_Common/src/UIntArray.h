#pragma once

#include "UConstants.h"

namespace cppobj
{
  /** @class UIntArray 
    * @brief �����-���������� ������ �� Delphi ������� � ����� TIntArray */
  class UIntArray
  {
    void* m_object = nullptr; ///< @brief ��������� �� ������ TIntArray (Delphi)
    SControlData* m_SControlData; ///< @brief ������ ���������� ��������
    //int & m_arrayLength;  ///< @brief ����� �������
    //int & m_reserv; ///< @brief ��������, ���� �����

  public:
    /** @brief ����������� � ���������� 
      * @param objet - ��������� �� �������� � ���������� �� ������ TIntArray */
    explicit UIntArray(void* object);
    /** @brief ���������� */
    virtual ~UIntArray();
    /** @brief ���������� ������ �� ��������� ������, ���� ������� ���, �� ������������ ���������� std::out_of_range */
    NATIVEINT & operator[] (int);
  };

} // namespace cppobj
