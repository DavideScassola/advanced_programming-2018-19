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
	size_t size = 8;
	int* primes{new int[size]};
	int founded = 0;

	if(max>=2)
	{
		primes[founded++] = 2;
		
		for(unsigned int i{3}; i<=max; i++)
		{
			if(founded>=size) //resizing of the primes vector
			{	
				size = size*2;
				int* new_vector{new int[size]};
				for(unsigned int i{0}; i<size/2; i++)  //copyng
				new_vector[i] = primes[i];

				delete[] primes;
				primes = new_vector;	
				
			}
	
			int limit = sqrt(i);

			for(unsigned int j{0}; i%primes[j]!=0; j++)
			{
				if(primes[j]>limit)
				{
					primes[founded++] = i; std::cout << i;
					break;
				} 	
			}		
		}	

	}

	primes[founded]=-1;

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
