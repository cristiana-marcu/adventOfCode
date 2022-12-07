#include <iostream>
#include <fstream>

int get_char_index(std::string str, char c)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] == c)
            return (i);
    return (0);
}

int main()
{
    std::string line;
    std::ifstream infile("input.txt");
    int total = 0;
    int a, b, c, d;
    std::string s1, s2;
    int comma = 0; //index representing where the comma separating elfs is
    int dash = 0;  //index representing where the dash representting the ranges is
    //Input: 56-84,31-80
    //       __ __ __ __
    //       a  b ,c  d
    //       _____,_____
    //         s1    s2
    while (std::getline(infile, line))
    {
        comma = get_char_index(line, ',');
        s1 = line.substr(0, comma);
        s2 = line.substr(comma + 1, line.length());
        dash = get_char_index(s1, '-');
        a = stoi(s1.substr(0, dash));
        b = stoi(s1.substr(dash + 1, s1.length()));
        dash = get_char_index(s2, '-');
        c = stoi(s2.substr(0, dash));
        d = stoi(s2.substr(dash + 1, s2.length()));
        if ((a >= c && a <= d) || (b >= c && b <= d) || (c >= a && c <= b) || (d >= a && d <= b))
            total++;
    }
    std::cout << total << std::endl;
}