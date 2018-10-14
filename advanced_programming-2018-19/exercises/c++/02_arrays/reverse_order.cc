#include<iostream>

template<typename T>
int get_value()
{
   T i;
   while(!(std::cin >> i))
   {
       std::cin.clear();
       std::cin.ignore();
   };
   return i;
}


template<typename T>
T* ask_vector(const int length)
{
	T* v{new T[length]};
	int counter{0};
	while(counter<length)
        {
		std::cout << counter << ":";
		if(v[counter]=get_value<T>())   counter++;
        }

	return v;
}

template<typename T>
void print_reverse(T* vector, const int length)
{
	for(int i=length-1; i>=0; i--)
	{
		std::cout << vector[i] << " ";
	}
}

int main()
{
	std::cout << "insert the double vector dimension: ";
	int length = get_value<int>();

	double* d_vector;
	d_vector = ask_vector<double>(length);

	std::cout << "\n reverse: ";
	print_reverse(d_vector, length);
	delete[] d_vector;


	std::cout << "insert the int vector dimension: ";
	length = get_value<int>();

	int* i_vector;
	i_vector = ask_vector<int>(length);

	std::cout << "\n reverse: ";
	print_reverse(i_vector, length);
	delete[] i_vector;

	return 0;
}
