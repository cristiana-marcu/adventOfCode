#include <iostream>
#include <fstream>

char convert(char elf, char result)
{
	char converted;

	if (result == 'Y')
		converted = elf;
	else if (result == 'X')
	{
		if (elf == 'A')
			converted = 'C';
		else if (elf == 'B')
			converted = 'A';
		else if (elf == 'C')
			converted = 'B';
	}
	else if (result == 'Z')
	{
		if (elf == 'A')
			converted = 'B';
		else if (elf == 'B')
			converted = 'C';
		else if (elf == 'C')
			converted = 'A';
	}
	return (converted);
}

int play(char elf, char me)
{
	int score = 0;

	if (elf == me)
		score += 3;
	else if ((me == 'B' && elf == 'A') || (me == 'C' && elf == 'B') || (me == 'A' && elf == 'C'))
		score += 6;
	if (me == 'A')
		score += 1;
	else if (me == 'B')
		score += 2;
	else if (me == 'C')
		score += 3;
	return (score);
}


int main()
{
	//A Rock, B Paper, C scissors
	//X Loose, Y Draw, Z Win
	//1 Rock, 2 Paper, 3 scissors
	//3 draw, 6 win
	std::string line;
	std::ifstream infile("input.txt");
	int total = 0;
	char elf, me;
	while (std::getline(infile, line))
	{
		elf = line[0];
		me = convert(elf, line[2]);
		total += play(elf, me);
	}
	std::cout << total << std::endl;
	return 0;
}