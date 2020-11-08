#include "URunObject.h"
#include "UConstants.h"
#include "UIntArray.h"
#include "UPtrExtArray.h"

namespace cppobj
{
  URunObject::URunObject(void* object) :
    m_creatorObject(object)
  {
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

}
