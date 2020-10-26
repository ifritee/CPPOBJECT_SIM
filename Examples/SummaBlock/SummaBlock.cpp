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
  }
}
