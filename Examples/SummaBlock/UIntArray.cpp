#include <stdexcept>

#include "UIntArray.h"

namespace cppobj
{
  UIntArray::UIntArray(void* object) :
    m_object((void*)(*(NATIVEINT*)object))
    , m_arrayLength(*(int*)(((NATIVEINT*)m_object) + 1))
    , m_reserv(*(&m_arrayLength + 1))
  {

  }

  UIntArray::~UIntArray()
  {

  }

  NATIVEINT & UIntArray::operator[] (int index)
  {
    if (index >= m_arrayLength) {
      throw(std::out_of_range("index is failure"));
    }
    return *((NATIVEINT*)(*((NATIVEINT*)m_object + 2)) + index);
  }
}