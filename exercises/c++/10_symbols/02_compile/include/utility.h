#ifndef UTILITYH
#define UTILITYH

#include <string>
#include <algorithm>
#include <iostream>

static std::string to_upper(const std::string& os){
  static int n = 0;
  ++n;
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}

static std::string to_lower(const std::string& os){
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

#endif
