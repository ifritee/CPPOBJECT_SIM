#include <stdexcept>

#include "BlockInterface.h"

namespace cppobj
{

  BlockInterface::BlockInterface(void * object) : URunObject(object)
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
    } else {
      throw(std::out_of_range("Number of port data is failure"));
    }
  }
  
  TCondPortData BlockInterface::getCondPortData(int number)
  {
    if (number < m_condPortData.size()) {
      return m_condPortData[number];
    } else {
      throw(std::out_of_range("Number of cond port data is failure"));
    }
  }

} // namespace cppobj
