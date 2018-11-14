#include<iostream>

int get_int()
{
   int i;
   while(!(std::cin >> i))
   {
       std::cin.clear();
       std::cin.ignore();
   };
   return i;
}

double get_double()
{
   double d;
   while(!(std::cin >> d))
   {
       std::cin.clear();
       std::cin.ignore();
   };
   return d;
}

template<typename T>
double get_value()
{
   double d;
   while(!(std::cin >> d))
   {
       std::cin.clear();
       std::cin.ignore();
   };
   return d;
}


int main()
{
   double in = get_double();
   std::cout << in;
}
