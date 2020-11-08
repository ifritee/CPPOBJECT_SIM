#pragma once

#include <string>
#include <vector>
#include <queue>

#include "UConstants.h"
#include "UMultiSelect.h"
#include "URunObject.h"

namespace cppobj 
{
  /** @class BlockInterface
    * @brief ��������� ��� ������ */
  class BlockInterface : public URunObject
  {
  public:
    /** @brief ����������� */
    explicit BlockInterface(void *);
    /** @brief ���������� */
    virtual ~BlockInterface();
    /** @brief �������������� �������� ��������� ������ */
    virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) = 0;
    /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
    virtual NATIVEINT getParamID(const std::string & paramName, TDataType& dataType, bool& isConst) = 0;
    /** @brief ���������� ���������� ����������� ������������� */
    int getMultiselectQty() { return m_multiselectQty; }
    /** @brief ������� ���������� ������������� */
    void addMultiselect(void* multiselect);
    /** @brief ���������� ��������� ������������ ��� nullptr */
    void* getMultiselect(int number);
    /** @brief ���������� ���������� ������ ��� ��������� ����� */
    int getPortDataQty();
    /** @brief ���������� ���������� ������ ��� ��������� ��������� ����� */
    int getCondPortDataQty();
    /** @brief ���������� ������ ��� ��������� ����� */
    TPortData getPortData(int number);
    /** @brief ���������� ������ ��� ��������� ��������� ����� */
    TCondPortData getCondPortData(int number);
    /** @brief ������� ��� ����������� ��������� ���������� ���������� ����� */
    virtual void editFunc();
    /** @brief RUN-������� ����� */
    virtual NATIVEINT run(double& at, double& h, EWorkState workState) = 0;

  protected:
    int m_multiselectQty = 0; ///< @brief ���������� ����������� ��������������
    std::vector<UMultiSelect* > m_multiselects; ///< @brief ����� ��������������
    std::vector< TPortData > m_portData; ///< @brief ������ ��� ���������
    std::vector< TCondPortData > m_condPortData; ///< @brief ������ ��� ��������� ���������

    /** @brief ������� ������ ��� ��������� ����� */
    void setPortCount(int count, int mode, int type, unsigned char side);
    /** @brief ������� ������ ��� ��������� ��������� ����� */
    void setCondPortCount(int count, int mode, int type, unsigned char side, const char* name, int portVariant);
  };

  /** @brief ������� �������� ������� - �� ����� ���� 2 ����� */
  extern BlockInterface * CreateBlockObject(void *);

} // namespace cppobj



