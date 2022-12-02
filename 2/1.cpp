#include <iostream>
#include <fstream>

char convert(char c)
{
	char converted;

	if (c == 'X')
		converted = 'A';
	else if (c == 'Y')
		converted = 'B';
	else if (c == 'Z')
		converted = 'C';
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

	while (std::getline(infile, line))
	{
		char elf = line[0];
		char me = line[2];
		me = convert(me);
		total += play(elf, me);
	}
	std::cout << total << std::endl;
	return 0;
}