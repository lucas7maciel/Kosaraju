
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>

#include "graph.h"

using namespace std;

class Graph
{
    vector<vector<int>> adjMatrix;

public:
    Graph(int vectorCount)
    {
        adjMatrix = vector<vector<int>>(vectorCount, vector<int>(vectorCount, 0));
    }

    void addEdge(int from, int to)
    {
        adjMatrix[from][to] = 1;
    }

    Graph getReversed()
    {
        int size = adjMatrix.size();

        Graph graph(size);

        for (int from = 0; from < size; from++)
        {
            for (int to = 0; to < size; to++)
            {
                if (adjMatrix[from][to])
                {
                    graph.addEdge(to, from);
                }
            }
        }

        return graph;
    }

    void print(string outputPath)
    {
        ofstream outfile(outputPath);

        Graph reversed = this->getReversed();

        stack<int> stack;
        vector<int> visited(adjMatrix.size(), false);

        for (unsigned int i = 0; i < adjMatrix.size(); i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, stack, reversed);
            }
        }

        fill(visited.begin(), visited.end(), false);

        while (stack.size())
        {
            int v = stack.top();

            stack.pop();

            if (!visited[v])
            {
                DFSUtil(v, visited, adjMatrix, outfile);

                if (outfile.is_open()) {
                    outfile << endl;
                } else {
                    cout << endl;
                }
            }
        }

        // Fechar o arquivo apos seu uso
        if (outfile.is_open()) {
            outfile.close();
        }
    }

private:
    void DFS(int v, vector<int> &visited, stack<int> &st, Graph &graph)
    {
        visited[v] = 1;

        for (unsigned int i = 0; i < graph.adjMatrix.size(); i++)
        {
            if (graph.adjMatrix[v][i] && !visited[i])
            {
                DFS(i, visited, st, graph);
            }
        }

        st.push(v);
    }

    void DFSUtil(int v, vector<int> &visited, vector<vector<int>> &adj, ofstream &file)
    {
        visited[v] = 1;

        if (file.is_open()) {
            file << v + 1 << " ";
        } else {
            cout << v + 1 << " ";
        }

        for (unsigned int i = 0; i < adj.size(); i++)
        {
            if (adj[v][i] && !visited[i])
            {
                DFSUtil(i, visited, adj, file);
            }
        }
    }
};

int printSolution(string inputPath, string outputPath)
{
    ifstream inputFile(inputPath);

    // Neste caso, os inputs serao lidos a partir deste arquivo
    if (inputFile.is_open())
    {
        string line;

        int size, edges;

        if (getline(inputFile, line))
        {
            stringstream ss(line);

            if (ss >> size >> edges)
            {
            }
            else
            {
                cout << "Erro ao ler numeros do arquivo\n" << line << endl;
                return 1;
            }
        }
        else
        {
            cout << "Falha ao informar entradas corretamente";
            return 1;
        }

        //
        Graph graph(size);

        for (int i = 0; i < edges; i++)
        {
            if (!getline(inputFile, line))
            {
                cout << "Faltam linhas no input";
                return 0;
            }

            stringstream ss(line);
            int from, to;

            ss >> from >> to;

            graph.addEdge(from - 1, to - 1);
        }

        graph.print(outputPath);

        inputFile.close();
    }
    else if (inputPath.empty())
    {
        // printf("Digite os inputs pelo terminal (A formatacao pode ser encontrada no helper)\n");
        // Fazer depois...
    } else {
        printf("Falha ao abrir arquivo informado, verifique se o caminho esta correto\n");
    }

    return 0;
}