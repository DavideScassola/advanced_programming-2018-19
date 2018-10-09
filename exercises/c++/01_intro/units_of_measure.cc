#include<iostream>

double get_double()
{
   double i;
   while(!(std::cin >> i))
   {
   std::cin.clear();
   std::cin.ignore();
   };
   return i;
}

void read_measure()
{
   std::string measure;
   std::string measure_converted;

   double d = get_double();
   std::cout << "enter the value followed by the measure unit";
   std::cin >> measure;
   if(measure=="inch")
   {
    d = 0.0254*d;
    measure_converted = "m";
    std::cout << d << " " << measure_converted << "\n";
   }  
   else if(measure=="m")
   {
    d = d/0.0254;
    measure_converted = "inch" ;
    std::cout << d << " " << measure_converted << "\n";
   }
   else
   {
    std::cout << "something goes wrong with your pc\n";
   }
}

int main()
{
  read_measure();
}
