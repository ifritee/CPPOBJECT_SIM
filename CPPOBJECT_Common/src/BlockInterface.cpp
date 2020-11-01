#include "BlockInterface.h"

namespace cppobj
{

  BlockInterface::BlockInterface()
  {

  }

  BlockInterface::~BlockInterface()
  {
    for (UMultiSelect* multiSelect : m_multiselects) {
      delete multiSelect;
    }
    m_multiselects.clear();
  }

  void BlockInterface::addMultiselect(void* multiselect)
  {
    m_multiselects.push_back(new UMultiSelect(multiselect));
  }

  void* BlockInterface::getMultiselect(int number)
  {
    if (number < m_multiselects.size()) {
      return m_multiselects[number]->creator();
    }
    return nullptr;
  }

}
