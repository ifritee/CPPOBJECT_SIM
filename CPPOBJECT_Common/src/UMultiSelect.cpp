#include "UMultiSelect.h"
#include "stringmethods.h"

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
    for (int i = 0; ; ++i) {
      if (i >= 1000) {
        returnData.clear();
        break;
      }
      else {
        int data = *(m_data->m_data + i);
        if (data == 0x1DDA1AC0) {
          break;
        }
        returnData.push_back(data);
      }
    }
    return returnData;
  }
}
