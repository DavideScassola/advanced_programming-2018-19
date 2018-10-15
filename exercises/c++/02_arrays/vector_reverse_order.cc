#include<iostream>
#include<vector>

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
std::vector<T> ask_vector(const int length)
{
	std::vector<T> v;
	int counter{0};
	while(counter<length)
        {
		std::cout << counter << ":";
		v.push_back(get_value<T>());
		counter++;

	return v;
}

template<typename T>
void print_reverse(std::vector<T> vector)
{
	for(int i=vector.size()-1; i>=0; i--)
	{
		std::cout << vector[i] << " ";
	}
}

int main()
{
	std::cout << "insert the double vector dimension: ";
	int length = get_value<int>();

	std::vector<double> d_vector;
	d_vector = ask_vector<double>(length);

	std::cout << "\n reverse: ";
	print_reverse(d_vector);

	std::cout << "\ninsert the int vector dimension: ";
	length = get_value<int>();

	std::vector<int> i_vector;
	i_vector = ask_vector<int>(length);

	std::cout << "\n reverse: ";
	print_reverse(i_vector);

	return 0;
}
