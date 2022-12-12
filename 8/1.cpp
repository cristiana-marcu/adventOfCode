#include <iostream>
#include <fstream>
#include <vector>

int look_left(std::vector<std::string> forest, int x, int y)
{
    for (int i = y - 1; i >= 0; i--)
        if (forest[x][i] >= forest[x][y])
            return (1);
    return (0);
}

int look_right(std::vector<std::string> forest, int x, int y)
{
    for (int i = y + 1; i < forest[x].length(); i++)
        if (forest[x][i] >= forest[x][y])
            return (1);
    return (0);
}

int look_up(std::vector<std::string> forest, int x, int y)
{
    for (int i = x - 1; i >= 0; i--)
        if (forest[i][y] >= forest[x][y])
            return (1);
    return (0);
}

int look_down(std::vector<std::string> forest, int x, int y)
{
    for (int i = x + 1; i < forest.size(); i++)
        if (forest[i][y] >= forest[x][y])
            return (1);
    return (0);
}

int main()
{
    std::string line;
    std::ifstream infile("input.txt");
    std::vector<std::string> forest;
    int visibleTrees = 0;

    while (getline(infile, line))
        forest.push_back(line);
    for (int x = 0; x < forest.size(); x++)
        for (int y = 0; y < forest[x].length(); y++)
            visibleTrees++;
    std::cout << visibleTrees << std::endl;
    for (int x = 1; x < forest.size(); x++)
    {
        for (int y = 1; y < forest[x].length(); y++)
        {
            if (look_left(forest, x, y) &&
                look_right(forest, x, y) &&
                look_up(forest, x, y) &&
                look_down(forest, x, y)) 
                visibleTrees -= 1;
        }
    }
    std::cout << visibleTrees << std::endl;
    
}