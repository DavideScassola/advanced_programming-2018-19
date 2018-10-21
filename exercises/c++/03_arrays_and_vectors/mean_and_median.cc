#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

double mean(std::vector<double> vector)
{
	double total{0};
	for(double value : vector)
		total+=value;

	return total/vector.size();
}

double median(std::vector<double> v)
{
	std::sort(v.begin(), v.end());
	int size = v.size();
	return (v.size()%2==1) ? v.at((size-1)*0.5) : (v.at(size*0.5) + v.at( size*0.5 -1))*0.5;
}

std::vector<double> extract_double_vector(std::string file_name)
{
	std::ifstream ifile(file_name, std::ios::in);
	std::vector<double> vector;
	double num;

	while (ifile >> num)
		vector.push_back(num);

	return vector;
}

int main()
{
	std::vector<double> v = extract_double_vector("temperatures.txt");
	std::cout << "mean: " << mean(v) << " median: " << median(v) << "\n";
}
