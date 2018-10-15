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

std::vector<unsigned int> sieve_of_eratosthenes(const unsigned int max)
{
	size_t size = 8;
	std::vector<unsigned int> primes;

	if(max>=2)
	{
		primes.push_back(2);
		
		for(unsigned int i{3}; i<=max; i++)
		{
	
			unsigned int limit = sqrt(i); //upper bound for divisibility checks

			for(unsigned int j{0}; i%primes[j]!=0; j++)
			{
				if(primes[j]>limit)
				{
					primes.push_back(i);
					break;
				} 	
			}		
		}	

	}

	return primes;
}

int main()
{
	std::cout << "insert the upper bound: ";
	unsigned int upper_bound = get_value<unsigned int>();
	std::vector<unsigned int> primes = sieve_of_eratosthenes(upper_bound);
	print_vector(primes);
}
