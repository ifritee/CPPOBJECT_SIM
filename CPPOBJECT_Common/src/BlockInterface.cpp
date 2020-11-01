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

  int BlockInterface::getPortDataQty()
  {
    return static_cast<int>(m_portData.size());
  }

  int BlockInterface::getCondPortDataQty()
  {
    return static_cast<int>(m_condPortData.size());
  }

  TPortData BlockInterface::getPortData(int number)
  {
    if (number < m_portData.size()) {
      return m_portData[number];
    }
    TPortData portData;
    portData.m_mode = -1;
    return portData;
  }
  
  TCondPortData BlockInterface::getCondPortData(int number)
  {
    if (number < m_condPortData.size()) {
      return m_condPortData[number];
    }
    TCondPortData condPortData;
    condPortData.m_mode = -1;
    return condPortData;
  }

}
