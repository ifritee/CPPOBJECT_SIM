#include <stdexcept>

#include "UPtrExtArray.h"

namespace cppobj
{
  UPtrExtArray::UPtrExtArray(void* object) :
    m_object(object)
  {

  }

  UPtrExtArray::~UPtrExtArray()
  {

  }

  double& UPtrExtArray::data(unsigned int channel, int index)
  {
    NATIVEINT* data = reinterpret_cast<NATIVEINT*>(*(reinterpret_cast<NATIVEINT *>(m_object)));
    if (*data == 0) {
      throw(std::runtime_error("Pointer to data is ZERO!"));
    }
    NATIVEINT chanMax = *(data - 1); // Количество каналов
    if (channel >= chanMax) {
      throw(std::out_of_range("Channel number is failure"));
    }
    m_SControlData = reinterpret_cast<SControlData*>(*(data + channel));
    double* valData = reinterpret_cast<double *>(m_SControlData->m_array);
    return *valData;
  }

} // namespace cppobj
