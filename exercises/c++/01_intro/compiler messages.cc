#include<iostream>

int fun()
{
   return 42;
}

int fun2(int e)
{
   return e;
}

int main()
{
   int var{2};
   //int var{12.2}; //error: narrowing conversion 
   //cA = 3; //error: ‘vAr’ was not declared ... suggested alternative: ‘var’
   //var = 12 // error: expected ‘;’ before ‘}’ token
   //std::coutt << "Hello, World!\n"; //error: ‘coutt’ is not a member of ‘std’ ... suggested alternative: ‘cout’
   //std::cout << "ciao!\n"; //if I don't include iostream -> error: ‘cout’ is not a member of ‘std’
   //cout << "ciao!\n"; //error: ‘cout’ was not declared in this scope ... suggested alternative: ... ‘std::cout’
   //double int {12.3}; //error: expected primary-expression before ‘double’
   //var = fun(12); //error: too many arguments to function ‘int fun()’
   //var = e("23"); //error: ‘e’ was not declared in this scope
   //var = fun2("David Hilbert"); //error: invalid conversion from ‘const char*’ to ‘int’
}
