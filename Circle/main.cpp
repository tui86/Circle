#include <iostream>
#include <windows.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "CircleProblems.h"
using namespace std;

int main() 
{
    SetConsoleOutputCP(65001);
    CircleProblems c;
    c.ProblemA("data.txt");
    c.ProblemB("data.txt");
    c.ProblemC("data.txt");
    c.ProblemD("data.txt");
    system("pause");
    return 0;
}