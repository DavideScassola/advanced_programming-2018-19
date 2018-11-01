#include <iostream>
#include <string>

template <typename num>
class Vector
{
  num* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  auto size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }

  // try to comment this line and recompile
  const num& operator[](const std::size_t i) const { return elem[i]; }
	
  num* begin()
  {
  	return &(elem[0]);
  }

  num* end()
  {
  	return &(elem[_size]);
  }

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {

  Vector<double> v{10};
  v[0] = 3;
  int t = 2;
  for(auto e : v)
  {

  }

  std::cout << v;
  
  return 0;
}
