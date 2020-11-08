#include <stdexcept>

#include "URunObject.h"
#include "UIntArray.h"
#include "UPtrExtArray.h"

namespace cppobj
{
  URunObject::URunObject(void* object) 
    : m_creatorObject(object)
  {
    if (object == nullptr) {
      throw(std::logic_error("Parent object pointer is NULL"));
    }
    m_cU = new UIntArray((void *)((NATIVEINT*)(object)+1));
    m_U = new UPtrExtArray((void*)((NATIVEINT*)(object)+2));
    m_cY = new UIntArray((void*)((NATIVEINT*)(object)+3));
    m_Y = new UPtrExtArray((void*)((NATIVEINT*)(object)+4));
  }

  URunObject::~URunObject()
  {
    delete m_cU;
    delete m_U;
    delete m_cY;
    delete m_Y;
  }

  NATIVEINT& URunObject::cU(int index) 
  {
    return m_cU->operator[](index); 
  }

  NATIVEINT& URunObject::cY(int index) 
  {
    return m_cY->operator[](index); 
  }

  double& URunObject::U(unsigned int channel, int index) 
  { 
    return m_U->data(channel, index);
  }

  double& URunObject::Y(unsigned int channel, int index)
  { 
    return m_Y->data(channel, index); 
  }

} // namespace cppobj
