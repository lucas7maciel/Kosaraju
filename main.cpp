#include <iostream>
#include <string.h>

#include "solution/main.h"

using namespace std;

int main(int argc, char **args)
{
    // Checar inputs
    // if (n tem arg)
    if (argc == 1)
    {
        printSolution();
        cout << endl;
    }
    else if (!strcmp("-h", args[1]))
    {
        cout << "eh h\n";
    }
    else if (!strcmp("-o", args[1]))
    {
        cout << "eh o\n";
    }
    else if (!strcmp("-f", args[1]))
    {
        cout << "eh f\n";
    }

    return 0;
}