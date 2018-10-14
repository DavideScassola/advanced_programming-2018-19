#include<iostream>
#include<string>

int main()
{
   std::string line, line_before;

   std::getline(std::cin,line_before);

   int counter{1}; //count the number of occurrences

   while(std::getline(std::cin,line))
   {
      if(line == line_before) counter++;
      else 
      {
         std::cout << line_before << " compare " << counter << " volte\n";
         counter=1;
      }

      line_before = line;
   }
}
