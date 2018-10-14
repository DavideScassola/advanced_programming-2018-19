#include<iostream>
#include<tgmath.h>

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

unsigned int pi(const int n) //estimator for the pi function, that returns the amount of prime numbers smaller than n
{

	return int(((1 + (1.25/log(n)))*n)/log(n))+2; 
	//the theorem of prime numbers says that pi(n)~n/log(n), I modified the function to make it an upper bound. However, as n goes to infinity the behavior is the same.
}

int* primes_less_than(const int n)
{
	size_t length = pi(n);//I choose to allocate one array only one time. I use an upper bound approximation of the pi function, i.e. pi(n):= number of prime numbers smaller than n
 
	unsigned int counter{0};

	int* primes{new int[length]};

	for(unsigned int i{2}; i<=n; i++)
	{
		if(is_prime(i)) primes[counter++]=i;
	}

	primes[counter] = -1; //to set the end of the vector

	
	std::cout << "size error:" << length-counter << "\nrelative error:"<< (double(length-counter)/double(counter))*100.0 << "%\n"; //to study the precision of the pi function estimator
	
	return primes;
}

template <typename T>
void print_vector(T* vector, size_t size)
{
	for(unsigned int i{0}; i<size; i++)
	{
		std::cout << i << ": " << vector[i] << "\n";
	}
}

void print_positive(int* vector) //this function doesn't need the size of the vector, it prints all the elements until the first negative number
{
	for(unsigned int i{0}; vector[i]>=0; i++)
	{
		std::cout << i << ": " << vector[i] << "\n";
	}
}

int main()
{
	std::cout << "select the limit for the prime numbers: ";
	unsigned int limit = get_value<unsigned int>();
	int* primes = primes_less_than(limit);
	print_positive(primes);
	delete[] primes;
}
