#include<iostream>
#include<vector>
#include <algorithm>

std::vector<std::string> read_stdin()
{
	std::vector<std::string> vector;
	std::string s;

	while(std::cin >> s)
		vector.push_back(s);

	return vector;
}

/*
	check if there is an equal string in the vector from a certain position
*/
bool contains_from(std::vector<std::string> v, std::string s, int start)
{
	return (start<v.size()) && ( (!v.at(start).compare(s)) || contains_from(v, s, start+1) );
}

void print_avoiding_repetitions(std::vector<std::string> v)
{
	int size = v.size();

	for(int i{0}; i<size; i++)
		if(!contains_from(v,v.at(i),i+1))
			std::cout << v.at(i) << " ";

}

int main()
{
	std::vector<std::string> text = read_stdin();
	print_avoiding_repetitions(text);
}




