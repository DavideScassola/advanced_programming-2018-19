#include<iostream>
#include<unordered_map>

std::unordered_map<std::string,int> read_unordered_map_stdin()
{	
	std::unordered_map<std::string,int> map;
	std::string s;
	while(std::cin >> s)
		map[s]++;
	return map;
}

void print_repetitions(std::unordered_map<std::string,int> map)
{
	for(auto e : map)
		std::cout << e.first << ": " << e.second << "\n";
}

int main()
{
	std::unordered_map<std::string,int> map = read_unordered_map_stdin();
	print_repetitions(map);
}




