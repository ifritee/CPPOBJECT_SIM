#pragma once
#include "BlockInterface.h"

namespace cppobj
{
  namespace cppobjsum
  {
    class SummaBlock : public BlockInterface
    {
    public:
      /** @brief Конструктор */
      explicit SummaBlock();
      /** @brief Деструктор */
      virtual ~SummaBlock() override;
      /** @brief Информационный контроль состояния модели */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
    };
  }
}



