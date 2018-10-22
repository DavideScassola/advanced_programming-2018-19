#include<iostream>
#include<map>

std::map<std::string,int> read_map_stdin()
{	
	std::map<std::string,int> map;
	std::string s;
	while(std::cin >> s)
		map[s]++;
	return map;
}

void print_repetitions(std::map<std::string,int> map)
{
	for(auto e : map)
		std::cout << e.first << ": " << e.second << "\n";
}

int main()
{
	std::map<std::string,int> map = read_map_stdin();
	print_repetitions(map);
}




