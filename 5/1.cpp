#include <iostream>
#include <fstream>

void move(int n, int from, int to, std::string ship[10])
{
    std::string aux;

    for (int i = 1; i <= n; i++)
    {
        aux = ship[from].substr(ship[from].length() - 1, ship[from].length());
        ship[from].pop_back();
        ship[to] = ship[to] + aux;
    }
}

int get_number(int a, int b, std::string str)
{
	std::string aux = "";

	for (int i = a; i < b; i++)
	{
		while (isdigit(str[i]))
		{
			aux += str[i];
			i++;
		}
	}
	std::cout << aux << std::endl;
	return stoi(aux);
}

void execute_instructions(std::string ship[10], std::string line)
{
    int from, to, n;
	int indexOfM = line.find('m');
	int indexOfF = line.find('f');
	int indexOfT = line.find('t');

	n = get_number(indexOfM, indexOfF, line);
	from = get_number(indexOfF, indexOfT, line);
	to = get_number(indexOfT, line.length(), line);
    
	move(n, from, to, ship);
}

int main()
{
    std::string line;
    std::ifstream infile("input.txt");
    std::string message;
    std::string cargo[10];
    
    cargo[0] = "";
    cargo[1] = "DLVTMHF";
    cargo[2] = "HQGJCTNP";
    cargo[3] = "RSDMPH";
    cargo[4] = "LBVF";
    cargo[5] = "NHGLQ";
    cargo[6] = "WBDGRMP";
    cargo[7] = "GMNRCHLQ";
    cargo[8] = "CLW";
    cargo[9] = "RDLQJZMT";
	for (int i = 0; i < 10; i++)
		std::getline(infile, line);
    while (std::getline(infile, line))
    {
		std::cout << line << std::endl;
        execute_instructions(cargo, line);
    }
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < cargo[i].length(); j++)
			if (j == (cargo[i].length() - 1))
				std::cout << cargo[i][j];
    return 0;
}