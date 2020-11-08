#include <stdexcept>

#include "UIntArray.h"

namespace cppobj
{
  UIntArray::UIntArray(void* object) 
    : m_object(object)
    //m_object((void*)(*(NATIVEINT*)object))
    //, m_arrayLength(*(int*)(((NATIVEINT*)m_object) + 1))
    //, m_reserv(*(&m_arrayLength + 1))
  {

  }

  UIntArray::~UIntArray()
  {

  }

  NATIVEINT & UIntArray::operator[] (int index)
  {
    NATIVEINT* data = reinterpret_cast<NATIVEINT*>(*(reinterpret_cast<NATIVEINT*>(m_object)));
    if (*data == 0) {
      throw(std::runtime_error("Pointer to data is ZERO!"));
    }
    m_SControlData = reinterpret_cast<SControlData*>(data);
    if (index >= m_SControlData->m_length) {
      throw(std::out_of_range("index is failure"));
    }
    NATIVEINT* valData = reinterpret_cast<NATIVEINT*>(m_SControlData->m_array);
    return *valData;
  }

} // namespace cppobj
