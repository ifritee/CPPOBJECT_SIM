#include "UMultiSelect.h"
#include "stringmethods.h"
#include "UConstants.h"

namespace cppobj
{
  UMultiSelect::UMultiSelect(void* delphiObject):
    m_creatorObject(delphiObject)
  {
    m_data = reinterpret_cast<UMSData *>(delphiObject);
  }

  UMultiSelect::~UMultiSelect()
  {

  }

  std::vector<std::string> UMultiSelect::listData() const
  {
    std::string data = string_methods::toUTF8(std::u16string(m_data->m_listNames));
    std::vector<std::string> returnData = string_methods::split(data, "\r\n");

    return returnData;
  }
  
  std::vector<int> UMultiSelect::data() const
  {
    std::vector<int> returnData;
    NATIVEINT length = *((NATIVEINT *)(m_data->m_data) - 1); // Получим количество элементов (В Delphi это -1 элемент NATIVEINT)
    for (int i = 0; i < length; ++i) {
      int data = *(m_data->m_data + i);
      returnData.push_back(data);
    }
    return returnData;
  }

} // namespace cppobj
