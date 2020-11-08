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

  void BlockInterface::editFunc()
  {
    m_portData.clear(); // Очистим данные до следующего вызова метода
    m_condPortData.clear();
  }

  void BlockInterface::setPortCount(int count, int mode, int type, unsigned char side)
  {
    TPortData portData;
    portData.m_count = count;
    portData.m_mode = mode;
    portData.m_type = type;
    portData.m_side = side;
    m_portData.push_back(portData);
  }

  void BlockInterface::setCondPortCount(int count, int mode, int type, unsigned char side, const char * name, int portVariant)
  {
    TCondPortData data;
    data.m_count = count;
    data.m_mode = mode;
    strcpy_s(data.m_name, name);
    data.m_portVariant = portVariant;
    data.m_type = type;
    data.m_side = side;
    m_condPortData.push_back(data);
  }

} // namespace cppobj
