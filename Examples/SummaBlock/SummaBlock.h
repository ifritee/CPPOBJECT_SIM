#pragma once
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

    public:
      /** @brief Конструктор */
      explicit SummaBlock();
      /** @brief Деструктор */
      virtual ~SummaBlock() override;
      /** @brief Информационный контроль состояния модели */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
      /** @brief Получить тип и идентификатор параметра - по умолчанию соответсвует адресу параметра, тип - вещественное; Result = - 1 - параметр не найден */
      virtual NATIVEINT getParamID(const std::string& paramName, TDataType& dataType, bool& isConst);
    };
  }
}



