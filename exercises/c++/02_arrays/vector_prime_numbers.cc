#include<iostream>
#include<tgmath.h>
#include <vector>

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

bool is_prime(const int n)
{
	for(int i{2}; i<n; i++)
	{
		if(n%i==0) return false;
	}

	return true;
}


std::vector<unsigned int> primes_less_than(const int n)
{
	unsigned int counter{0};

	std::vector<unsigned int> primes;

	for(unsigned int i{2}; i<=n; i++)
	{
		if(is_prime(i)) primes.push_back(i);
	}

	return primes;
}

template <typename T>
void print_vector(std::vector<T> vector)
{
	for(unsigned int i{0}; i<vector.size(); i++)
	{
		std::cout << i << ": " << vector[i] << "\n";
	}
}

int main()
{
	std::cout << "select the limit for the prime numbers: ";
	unsigned int limit = get_value<unsigned int>();
	std::vector<unsigned int> primes = primes_less_than(limit);
	print_vector(primes);
}
