#include <iostream>
#include <fstream>
#include <map>

int calculatePriority(char c)
{
	int priority;

	std::cout << c << std::endl;
	if (islower(c))
		priority = c - 96;
	else
		priority = c - 38;
	std::cout << priority << std::endl;
	return (priority);
}

int main()
{
	//priority a - z : 1 - 26; ASCII 97-122
	//priority A - Z : 27 - 52; ASCII 65-90
	std::string line;
	std::ifstream infile("example.txt");
	int total = 0;
	std::map<char, int> map;
	std::string s1, s2;

	//Partir el string en 2 strings
	//Buscar el char que se repite en las dos, cuidado por si hay mas de uno
	//Calcular la prioridad y sumarla al total
	while (std::getline(infile, line))
	{
		s1 = line.substr(0, line.length() / 2);
		std::cout << s1 << std::endl;
		std::cout << line << std::endl;
		s2 = line.substr(line.length() / 2, line.length() / 2);
		//std::cout << line.length()/2 << std::endl;
		std::cout << s2 << std::endl;
		for (int i = 0; i < s1.length(); i++)
			map[s1[i]] = 1;
		for (int i = 0; i < s2.length(); i++)
		{
			if (map[s2[i]] > 0)
			{
				std::cout << map[s2[i]] << std::endl;
				total += calculatePriority(s2[i]);
				break;
			}
		}
	}
	std::cout << total << std::endl;
	return 0;
}