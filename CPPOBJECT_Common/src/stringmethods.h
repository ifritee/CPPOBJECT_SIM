#ifndef STRINGMETHODS_H
#define STRINGMETHODS_H

#include <vector>
#include <string>
#include <codecvt>
#include <locale>

namespace string_methods
{
  std::vector<std::string> split(const std::string &s, const std::string &delim);
  std::string trim(const std::string &str);
  std::string normalize(const std::string &str);
  template <typename T> std::string toUTF8(const std::basic_string<T, std::char_traits<T>, std::allocator<T> >& source)
  {
    std::string result;
    std::wstring_convert < std::codecvt_utf8_utf16<T>, T> convertor;
    result = convertor.to_bytes(source);
    return result;
  }
}
#endif // STRINGMETHODS_H
