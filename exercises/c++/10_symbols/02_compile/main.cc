#include "utility.h"
#include "foo.h"
#include "src1.h"
#include "src2.h"

int main()
{
  print_lower("EXPECT TO SEE LOWER CASE");
  print_upper("expect to see upper case");
  Foo foo{};
  std::cout << foo.f << foo.bar << " " << to_lower(foo.bar) << std::endl;
  return 0;
}
