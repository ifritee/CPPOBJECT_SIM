#include <sstream>
#include <regex>

#include "stringmethods.h"

namespace string_methods
{
  std::vector<std::string> split(const std::string& input, const std::string& delim) {
    std::size_t current, previous = 0;
    std::vector<std::string> retVector;
    current = input.find(delim);
    while (current != std::string::npos) {
      retVector.push_back(input.substr(previous, current - previous));
      previous = current + delim.size();
      current = input.find(delim, previous);
    }
    retVector.push_back(input.substr(previous, current - previous));
    return retVector;
  }

  // trim from start
  static inline std::string &ltrim(std::string &s) {
#ifdef __unix__
      s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
#else
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](auto c) {
      return !std::isspace(c); }));
#endif
      return s;
  }

  // trim from end
  static std::string &rtrim(std::string &s) {
#ifdef __unix__
      s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
#else
    s.erase(std::find_if(s.rbegin(), s.rend(), [](auto c) {return !std::isspace(c); }).base(), s.end());
#endif
      return s;
  }

  std::string trim(const std::string &str)
  {
    std::string s = str;
    return ltrim(rtrim(s));
  }

  std::string normalize(const std::string &str)
  {
    std::string retString = str;
    retString.erase( std::remove(retString.begin(), retString.end(), '\r'), retString.end() );
    retString.erase( std::remove(retString.begin(), retString.end(), '\t'), retString.end() );
    size_t strBegin = retString.find_first_not_of(" ");
    size_t strEnd = retString.find_last_not_of(" ") - strBegin + 1;
    //if(strEnd == (retString.size() - 1)) { strEnd = std::string::npos; }
    if (strBegin != strEnd && strBegin != std::string::npos) {
      retString = retString.substr(strBegin, strEnd);
      retString = retString.substr(0,distance(retString.begin(),remove_if(retString.begin(),
           retString.end(), [](const char& a) { return (a == ' ') && (*(&a+1) == ' '); })));
    }
    return trim(retString);
  }
  
}
