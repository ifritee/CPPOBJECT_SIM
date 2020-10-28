#include "SummaBlock.h"

namespace cppobj
{
  BlockInterface* CreateBlockObject()
  {
    return new cppobjsum::SummaBlock();
  }

  namespace cppobjsum
  {
    SummaBlock::SummaBlock() : BlockInterface()
    {

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
      return result;
    }
  }
}
