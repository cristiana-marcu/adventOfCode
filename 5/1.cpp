#include <iostream>
#include <fstream>

void move(int n, std::string from, std::string to)
{
    std::string aux;

    for (int i = 1; i <= n; i++)
    {
        aux = from.substr(from.length() - 2, from.length());
        from.pop_back();
        to = to + aux;
    }
}

int execute_instructions(std::string ship[9], std::string line)
{

}

int main()
{
    std::string line;
    std::ifstream infile("input.txt");
    std::string message;
    std::string cargo[9];
    int instructions[3]; //[0] How many moves, [1] from where, [2] to where
    
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
    while (std::getline(infile, line))
    {
        for (int i = 0; i < 11; i++)
            std::getline(infile, line);
        execute_instructions(cargo, line);
    }

    return 0;
}