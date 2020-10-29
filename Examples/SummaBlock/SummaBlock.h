#pragma once
#include <string>

#include "BlockInterface.h"

namespace cppobj
{
  namespace cppobjsum
  {
    class SummaBlock : public BlockInterface
    {
      double m_valReal = 0.0;
      int m_valInt = 0;
      bool m_valBool = false;
      char16_t * m_valString; // Delphi-������ ���� ������� ������ � ������ ��
      int m_valColor = 0;
      double* m_valArray;     

    public:
      /** @brief ����������� */
      explicit SummaBlock();
      /** @brief ���������� */
      virtual ~SummaBlock() override;
      /** @brief �������������� �������� ��������� ������ */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
      /** @brief �������� ��� � ������������� ��������� - �� ��������� ������������ ������ ���������, ��� - ������������; Result = - 1 - �������� �� ������ */
      virtual NATIVEINT getParamID(const std::string& paramName, TDataType& dataType, bool& isConst);
    };
  }
}



