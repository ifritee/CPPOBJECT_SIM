#include <string.h>

#include "SummaBlock.h"
#include "ULogger.h"
#include "URunObject.h"
#include "UIntArray.h"
#include "UPtrExtArray.h"

namespace cppobj
{

  BlockInterface* CreateBlockObject(void * object)
  {
    return new cppobjsum::SummaBlock(object);
  }

  namespace cppobjsum
  {
    SummaBlock::SummaBlock(void * object) : BlockInterface(object)
    {
      m_multiselectQty = 1;
    }

    SummaBlock::~SummaBlock()
    {

    }

    NATIVEINT SummaBlock::infoFunc(int Action, NATIVEINT aParameter)
    {
      switch (Action) {
      case i_GetBlockType: {
        return t_fun;
      } break;
      case i_GetCount: {
        m_runObject->cY()[0] = 1;
        return 0;
      } break;
      case i_GetInit: {
        return 1;
      } break;
      default:
        break;
      }
      return -1;
    }

    NATIVEINT SummaBlock::getParamID(const std::string& paramName, TDataType& dataType, bool& isConst)
    {
      NATIVEINT result = -1;
      if (paramName == "var_real") {
        result = NATIVEINT(&m_valReal);
        dataType = dtDouble;
      }
      else if (paramName == "var_int") {
        result = NATIVEINT(&m_valInt);
        dataType = dtInteger;
      }
      else if (paramName == "var_bool") {
        result = NATIVEINT(&m_valBool);
        dataType = dtBool;
      }
      else if (paramName == "var_color") {
        result = NATIVEINT(&m_valColor);
        dataType = dtColor;
      }
      else if (paramName == "var_string") {
        result = NATIVEINT(&m_valString);
        dataType = dtString;
      }
      else if (paramName == "var_text") {
        result = NATIVEINT(&m_valText);
        dataType = dtText;
      }
//----- Тут нужно подумать как передавать данные -----
      else if (paramName == "var_array") {
//        result = NATIVEINT(m_valArray);
//        dataType = dtDoubleArray;
      }
      else if (paramName == "var_font") {
        //        result = NATIVEINT(m_valFont);
        //        dataType = dtFont;
      }
      else if (paramName == "var_line_style") {
         result = NATIVEINT(&m_valLineStyle);
         dataType = dtPenStyle;
      }
      else if (paramName == "var_brush_style") {
        result = NATIVEINT(&m_valBrushStyle);
        dataType = dtBrushStyle;
      }
      else if (paramName == "var_float_format") {
        result = NATIVEINT(&m_valFloatFormat);
        dataType = dtFloatFormat;
      }
      else if (paramName == "var_int_array") {
        //result = NATIVEINT(&m_valIntArray);
        //dataType = dtIntArray;
      }
      else if (paramName == "var_matrix") {
        //result = NATIVEINT(&m_valMatrix);
        //dataType = dtMatrix;
      }
      else if (paramName == "var_point") {
        result = NATIVEINT(&m_valPoint);
        dataType = dtPoint;
      }
      else if (paramName == "var_enum") {
        result = NATIVEINT(&m_valEnum);
        dataType = dtEnum;
      }
      else if (paramName == "var_file_name") {
        result = NATIVEINT(&m_valFileName);
        dataType = dtFileName;
      }
      else if (paramName == "var_file_db") {
        result = NATIVEINT(&m_valFileNameDB);
        dataType = dtDataBaseItem;
      }
      else if (paramName == "var_stream") {
//        result = NATIVEINT(&m_valStream);
//        dataType = dtStream;
      }
      else if (paramName == "var_composite") {
//        result = NATIVEINT(&m_valComposite);
//        dataType = dtComposite;
      }
      else if (paramName == "var_multi") {
        if (m_multiselects[0] != nullptr) {
          m_multiSelect = m_multiselects[0];
          result = NATIVEINT(m_multiSelect->creator());
          dataType = dtMultiSelect;
        }
      }
      return result;
    }

    void SummaBlock::editFunc()
    {
      //----- Пример управление визуализацией -----
      /*m_portData.clear();
      TPortData portData;
      portData.m_count = 1;
      portData.m_mode = 0;
      portData.m_side = 0;
      portData.m_type = 0;
      m_portData.push_back(portData);*/

      //----- Пример управление визуализацией -----
      /*m_condPortData.clear();
      TCondPortData data;
      data.m_count = 1;
      data.m_mode = 0;
      strcpy_s(data.m_name, "Hello");
      data.m_portVariant = 0;
      data.m_side = 0;
      data.m_type = 0;
      m_condPortData.push_back(data);*/
    }

    NATIVEINT SummaBlock::run(double& at, double& h, EWorkState workState)
    {
      try {
        switch (workState) {
        case f_Stop: {
        
        } break;
        case f_InitObjects: {
        
        } break;
        case f_InitState: {
        
        } break;
        case f_GoodStep: {
          double& result = m_runObject->Y().data(0, 0);
          double a1 = m_runObject->U().data(0, 0);
          double a2 = m_runObject->U().data(1, 0);
          result = a1 + a2;
        } break;
        }
      }
      catch (std::exception & e) {
        ULogger::instance()->error(e.what());
        return r_Fail;
      }
      return r_Success;
    }

  } // namespace cppobjsum
} // namespace cppobj
