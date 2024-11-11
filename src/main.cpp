#include <iostream>
#include <string.h>

#include "../include/graph.h"
#include "../include/helper.h"

using namespace std;

int main(int argc, char **args)
{
    string outputPath, inputPath;

    // Checar opcoes escolhidas
    for (int i = 0; i < argc; i++)
    {
        // Printar helper
        if (!strcmp(args[i], "-h"))
        {
            printHelper();
        }

        // Redirecionar saida para arquivo
        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            outputPath = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            printf("Um caminho para o arquivo precisa ser especificado apos '-o'\n");
        }

        // Indicar arquivo que contem o grafo de entrada
        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            inputPath = args[++i];
        }
        else if (!strcmp(args[i], "-f"))
        {
            printf("Um caminho para o arquivo precisa ser especificado apos '-f'\n");
        }
    }

    printSolution(inputPath, outputPath);
    return 0;
}