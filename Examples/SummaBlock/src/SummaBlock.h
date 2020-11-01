#pragma once
#include <string>
#include <limits.h>

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
      char16_t * m_valString; // Delphi-основа сама выделит память и удалит ее
      int m_valColor = 0;
      char16_t* m_valText;
      NATIVEINT m_valLineStyle;
      NATIVEINT m_valBrushStyle;
      NATIVEINT m_valFloatFormat;
      TMyPoint m_valPoint;
      NATIVEINT m_valEnum;
      char16_t* m_valFileName;
      char16_t* m_valFileNameDB;
      UMultiSelect* m_multiSelect = nullptr;

    public:
      /** @brief Конструктор */
      explicit SummaBlock();
      /** @brief Деструктор */
      virtual ~SummaBlock() override;
      /** @brief Информационный контроль состояния модели */
      virtual NATIVEINT infoFunc(int Action, NATIVEINT aParameter) override final;
      /** @brief Получить тип и идентификатор параметра - по умолчанию соответсвует адресу параметра, тип - вещественное; Result = - 1 - параметр не найден */
      virtual NATIVEINT getParamID(const std::string& paramName, TDataType& dataType, bool& isConst);
      /** @brief Функция для обеспечения изменения визуальных параметров блока */
      virtual void editFunc() override final;
      /** @brief RUN-функция блока */
      virtual NATIVEINT run(double& at, double& h, EWorkState workState) override final;
    };
  }
}



