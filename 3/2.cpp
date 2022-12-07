#include <iostream>
#include <fstream>
#include <map>

int calculatePriority(char c)
{
	int priority;

	if (islower(c))
		priority = c - 96;
	else
		priority = c - 38;
	return (priority);
}

int main()
{
	std::string line1,  line2, line3;
	std::ifstream infile("input.txt");
	int total = 0;
	std::map<char, int> map;

	while (std::getline(infile, line1))
	{
		std::getline(infile, line2);
		std::getline(infile, line3);
		map.clear();
		for (int i = 0; i < line1.length(); i++)
			map[line1[i]] = 1;
		for (int i = 0; i < line2.length(); i++)
			if (map[line2[i]] == 1)
				map[line2[i]] = 2;
		for (int i = 0; i < line3.length(); i++)
		{
			if (map[line3[i]] == 2)
			{
				total += calculatePriority(line3[i]);
				break;
			}
		}
	}
	std::cout << total << std::endl;
	return 0;
}