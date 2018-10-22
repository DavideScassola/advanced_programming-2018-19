#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::string> read_stdin() //reads a file from stdin and puts words in a vector
{
	std::vector<std::string> vector;
	std::string s;
	while(std::cin >> s)
		vector.push_back(s);
	return vector;
}

void print_avoiding_repetitions(std::vector<std::string> v)
{
	std::sort(v.begin(), v.end()); //ordering
	int size = v.size();

	std::cout << v.at(0) << "\n"; //print the first element

	for(int i{1}; i<size; i++)
		if(v.at(i).compare(v.at(i-1))) //if a word is equal to the previous, it doesn't print it
			std::cout << v.at(i) << "\n";
}

int main()
{
	std::vector<std::string> text = read_stdin();
	print_avoiding_repetitions(text);
}




