#ifndef FOOH
#define FOOH
#include "utility.h"

struct Foo{
  double f;
  std::string bar;
  Foo() = default;
  Foo(const std::string& s) : bar{to_upper(s)} {};
};

#endif
