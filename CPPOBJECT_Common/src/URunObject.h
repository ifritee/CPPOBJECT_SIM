#pragma once

#include "UConstants.h"

namespace cppobj
{
  class UIntArray;
  class UPtrExtArray;

  /** @class URunObject 
    * @brief �����-���������� ������ �� Delphi TCppObjectBlock (TRunObject) */
  class URunObject
  {
    void* m_creatorObject;  ///< @brief ������ ���������
    UIntArray* m_cU;        ///< @brief ������ ������������ ������ �����
    UPtrExtArray* m_U;      ///< @brief ������ ������ �����
    UIntArray* m_cY;        ///< @brief ������ ������������ ������� �����
    UPtrExtArray* m_Y;      ///< @brief ������ ������� �����

  public:
    /** @brief ����������� � ���������� - ��������� �� ������ TCppObjectBlock */
    explicit URunObject(void * object);
    /** @brief ���������� */
    virtual ~URunObject();
    /** @brief ���������� ������ �� ������ ������������ ������ ����� */
    NATIVEINT& cU(int index);
    /** @brief ���������� ������ �� ������ ������������ ������� ����� */
    NATIVEINT& cY(int index);
    /** @brief ���������� ������ �� ������ ������� ������ */
    double& U(unsigned int channel, int index);
    /** @brief ���������� ������ �� ������ �������� ������ */
    double& Y(unsigned int channel, int index);
  };

} // namespace cppobj
