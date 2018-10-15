#include<iostream>
#include <cmath>

void print_positive(int* vector) //this function doesn't need the size of the vector, it prints all the elements until the first negative number
{
	for(unsigned int i{0}; vector[i]>=0; i++)
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

int* sieve_of_eratosthenes(const int max)
{
	bool* isPrime{new bool[max+1]}; //grandezza iniziale arbitraria

	for( int i{0}; i<=max; i++)  isPrime[i] = true;

	int limit = sqrt(max);
	int prime_counter{max}; //number of primes we're going to find

	for(int n{2}; n<=limit; n++)
	{
		if(isPrime[n])
		{	
			for(int i{n*n};i<=max;i=i+n)
			{
					isPrime[i] = false;
			}
		}
	}
	
	int* primes{new int[max/2+1]};

	int counter{0};

	for(int i{2}; i<=max; i++)
	{
		if(isPrime[i])
		{	
			primes[counter++] = i;
		}
	}

	primes[counter]=-1;

	return primes;
}

int main()
{
	std::cout << "insert the upper bound: ";
	int upper_bound = get_value<int>();
	int* primes = sieve_of_eratosthenes(upper_bound);
	print_positive(primes);
	delete[] primes;
}
