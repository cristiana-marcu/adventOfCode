#include <iostream>
#include <fstream>
#include <vector>

int look_left(std::vector<std::string> forest, int x, int y)
{
    int result = 0;
    int i = y - 1;
    while (i >= 0)
    {
        result += 1;
        if (forest[x][i] >= forest[x][y])
            break;
        i--;
    }
    return (result);
}

int look_right(std::vector<std::string> forest, int x, int y)
{
    int result = 0;
    int i = y + 1;
 
    while (i < forest[x].length())
    {
        result += 1;
        if (forest[x][i] >= forest[x][y])
            break;
        i++;
    }
    return (result);
}

int look_up(std::vector<std::string> forest, int x, int y)
{
    int result = 0;
    int i = x - 1;
    while (i >= 0)
    {
        result += 1;
        if (forest[i][y] >= forest[x][y])
            break;
        i--;
    }
    return (result);
}

int look_down(std::vector<std::string> forest, int x, int y)
{
    int result = 0;
    int i = x + 1;
    while (i < forest.size())
    {
        result += 1;
        if (forest[i][y] >= forest[x][y])
            break;
        i++;
    }
    return (result);
}

int main()
{
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> forest;
    int scenicScore = 0;
    int left, right, up, down;
    int aux;

    while (getline(infile, line))
        forest.push_back(line);
    for (int x = 1; x < (forest.size() - 1); x++)
    {
        for (int y = 1; y < (forest[x].length() - 1); y++)
        {
            left = look_left(forest, x, y);
            right = look_right(forest, x, y);
            up = look_up(forest, x, y);
            down = look_down(forest, x, y); 
            aux = left * right * up * down;
            if (aux > scenicScore)
                scenicScore = aux;
        }
    }
    std::cout << scenicScore << std::endl;
    
}