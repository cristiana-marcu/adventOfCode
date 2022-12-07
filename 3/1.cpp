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
	std::string line;
	std::ifstream infile("input.txt");
	int total = 0;
	std::map<char, int> map;
	std::string s1, s2;

	while (std::getline(infile, line))
	{
		s1 = line.substr(0, line.length() / 2);
		s2 = line.substr(line.length() / 2, line.length() / 2);
		map.clear();
		for (int i = 0; i < s1.length(); i++)
			map[s1[i]] = 1;
		for (int i = 0; i < s2.length(); i++)
		{
			if (map[s2[i]] == 1)
			{
				total += calculatePriority(s2[i]);
				break;
			}
		}
	}
	std::cout << total << std::endl;
	return 0;
}