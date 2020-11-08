#pragma once

namespace cppobj
{

  class UIntArray;
  class UPtrExtArray;

  /** @class URunObject 
    * @brief �����-���������� ������ �� Delphi TCppObjectBlock (TRunObject) */
  class URunObject
  {
    void* m_creatorObject; ///< @brief ������ ���������
    UIntArray* m_cU;  ///< @brief ������ ������������ ������ �����
    UPtrExtArray* m_U;  ///< @brief ������ ������ �����
    UIntArray* m_cY;  ///< @brief ������ ������������ ������� �����
    UPtrExtArray* m_Y;  ///< @brief ������ ������� �����

  public:
    /** @brief ����������� � ���������� - ��������� �� ������ TCppObjectBlock */
    explicit URunObject(void * object);
    /** @brief ���������� */
    virtual ~URunObject();
    /** @brief ���������� ������ �� ������ ������������ ������ ����� */
    UIntArray& cU() { return *m_cU; }
    /** @brief ���������� ������ �� ������ ������������ ������� ����� */
    UIntArray& cY() { return *m_cY; }
    /** @brief ���������� ������ �� ������ ������� ������ */
    UPtrExtArray& U() { return *m_U; }
    /** @brief ���������� ������ �� ������ �������� ������ */
    UPtrExtArray& Y() { return *m_Y; }
  };

}
