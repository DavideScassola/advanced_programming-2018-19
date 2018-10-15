#include<iostream>
#include<cmath>
#include<vector>

template <typename T>
void print_vector(std::vector<T> vector)
{
	for(unsigned int i{0}; i<vector.size(); i++)
	{
		std::cout << i << ": " << vector[i] << "\n";
	}
}

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

std::vector<int> sieve_of_eratosthenes(const unsigned int max)
{
	std::vector<bool> isPrime;
	std::vector<int> primes;

	for(int i{0}; i<=max; i++)  isPrime.push_back(true);

	int limit = sqrt(max);


	for(int n{2}; n<=limit; n++)
	{
		if(isPrime[n])
		{
			for(int i{n*n};i<=max;i = i + n)
			{
					isPrime[i] = false;
			}
		}
	}

	for(int i{2}; i<=max; i++)
	{
		if(isPrime[i])
		{
			 primes.push_back(i);
		}
	}

	return primes;
}


int main()
{
	std::cout << "insert the upper bound: ";
	unsigned int upper_bound = get_value<unsigned int>();
	std::vector<int> primes = sieve_of_eratosthenes(upper_bound);
	print_vector(primes);
}
