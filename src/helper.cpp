#include <iostream>
#include <string.h>

#include "helper.h"

using namespace std;

void printInstructions() {
    cout << "Por favor siga as instrucoes";
}

void printHelper()
{
    printf("Esta aplicacao e destinada a encontrar componentes fortemente conexas de um grafo a partir da utilizacao do algoritmo de Kosaraju!\n\n");
    
    printf("O usuario pode escolher as seguintes opcoes atraves do terminal:\n");
    printf("-f <arquivo> : Faz a leitura dos inputs utilizados a partir do arquivo informado\n");
    printf("-o <arquivo> : Redireciona a saida da aplicacao para o arquivo especificado\n");
    // printf("-i <arquivo> : Escolhe um vertice inicial para que a busca seja iniciada\n");
    printf("-h           : Exibe este helper\n\n");

    printf("As componentes conexas serao listadas individualmente em cada linha da saida!\n\n");

    printf("Formatacao desejada do input:\n");
    printf("-vertices -arestas\n");
    printf("-v1 -v2\n");
    printf("-v1 -v2\n");
    printf("(...)\n");
}