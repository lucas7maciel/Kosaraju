
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>

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

    void print()
    {
        Graph reversed = this->getReversed();

        stack<int> stack;
        vector<int> visited(adjMatrix.size(), false);

        for (int i = 0; i < adjMatrix.size(); i++)
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
                DFSUtil(v, visited, adjMatrix);
                cout << endl;
            }
        }
    }

private:
    void DFS(int v, vector<int> &visited, stack<int> &st, Graph &graph)
    {
        visited[v] = 1;

        for (int i = 0; i < graph.adjMatrix.size(); i++)
        {
            if (graph.adjMatrix[v][i] && !visited[i])
            {
                DFS(i, visited, st, graph);
            }
        }

        st.push(v);
    }

    void DFSUtil(int v, vector<int> &visited, vector<vector<int>> &adj)
    {
        visited[v] = 1;
        cout << v + 1 << " ";

        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[v][i] && !visited[i])
            {
                DFSUtil(i, visited, adj);
            }
        }
    }
};

int printSolution(char *inputPath)
{
    ifstream inputFile(inputPath);

    if (inputFile.is_open())
    {
        string line;

        //
        int size, edges;

        if (getline(inputFile, line))
        {
            stringstream ss(line);

            if (ss >> size >> edges)
            {
            }
            else
            {
                cout << "Error reading numbers from line: " << line << endl;
            }
        }
        else
        {
            cout << "Falha ao informar entradas corretamente";
            return 0;
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

        graph.print();

        inputFile.close();
    }
    else
    {
        cout << "Falha ao abrir arquivo informado, verifique se o caminho esta correto";
    }

    return 0;
}
//     int size, edges;

//     cout << inputPath;

//     cin >> size >> edges;

//     Graph graph(size);

//     for (int i = 0; i < edges; i++)
//     {
//         int from, to;

//         cin >> from >> to;
//         graph.addEdge(from - 1, to - 1);
//     }

//     graph.print();
// };