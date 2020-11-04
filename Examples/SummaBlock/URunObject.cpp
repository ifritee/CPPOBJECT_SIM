#include "URunObject.h"
#include "UConstants.h"
#include "UIntArray.h"
#include "UPtrExtArray.h"

namespace cppobj
{
  URunObject::URunObject(void* object) :
    m_creatorObject(object)
  {
    //cU = (void *)(*((NATIVEINT*)(object) + 1));
    //U = (void*)(*((NATIVEINT*)(object)+2));
    //cY = (void*)(*((NATIVEINT*)(object)+3));
    //Y = (void*)(*((NATIVEINT*)(object)+4));
    m_cU = new UIntArray((void *)((NATIVEINT*)(object)+1));
    m_U = new UPtrExtArray((void*)((NATIVEINT*)(object)+2));
    m_cY = new UIntArray((void*)((NATIVEINT*)(object)+3));
    m_Y = new UPtrExtArray((void*)((NATIVEINT*)(object)+4));
  }

  URunObject::~URunObject()
  {

  }

}
