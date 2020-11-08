#include <stdexcept>

#include "UPtrExtArray.h"
#include "UConstants.h"

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
    NATIVEINT* data = (NATIVEINT*)(*((NATIVEINT *)m_object));
    if (*data == 0) {
      throw(std::runtime_error("Pointer to data is ZERO!"));
    }
    NATIVEINT chanMax = *(data - 1); // Количество каналов
    if (channel >= chanMax) {
      throw(std::out_of_range("Channel number is failure"));
    }
    NATIVEINT * arrData = (NATIVEINT*)*(data + channel);
    int arrLength = *((int*)(arrData + 1) + 0);
    int reserve = *((int*)(arrData + 1) + 1);
    if (index >= arrLength) {
      throw(std::out_of_range("Index of data is failure"));
    }
    NATIVEINT* shift = (NATIVEINT *)((int *)(arrData + 1) + 2);
    double* valData = ((double*)*(shift) + index);

    return *valData;
  }
}
