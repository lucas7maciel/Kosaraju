#include <iostream>
#include <string.h>

#include "solution/graph.h"
#include "utils/helper.h"

using namespace std;

int main(int argc, char **args)
{
    if (argc == 1)
    {
        printInstructions();
    }
    else if (!strcmp("-h", args[1]))
    {
        printHelper();
    }
    else if (!strcmp("-o", args[1]))
    {
        cout << "Redirecionando saída para" << args[2];
    }
    else if (!strcmp("-f", args[1]))
    {
        if (argc == 2) {
            cout << "Por favor especifique o arquivo de entrada";
            return 0;
        }

        printSolution(args[2]);
    }

    return 0;
}