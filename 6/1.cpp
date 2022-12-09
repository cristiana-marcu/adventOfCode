#include <iostream>
#include <fstream>
#include <map>

int main()
{
	std::string line;
	std::ifstream infile("input.txt");

	getline(infile, line);
	int indexOfMarkEnd;
	std::map<char, int> map;
	std::string aux;

	for (int i = 3; i < line.length(); i ++)
	{
		map.clear();
		aux = line.substr(i - 3, 4);
		std::cout << aux << std::endl;
		for (int j = 0; j < 4; j++)
		{
			map[aux[j]] += 1;
			//std::cout << map[aux[j]] << std::endl;
		}
		int ones = 0;
		for (int k = 0; k < 4; k++)
		{
			if (map[aux[k]] == 1)
				ones++;
		}
		if (ones == 4)
		{
			std::cout << (i + 1) << std::endl;
			return (0);
		}
	}
	
}