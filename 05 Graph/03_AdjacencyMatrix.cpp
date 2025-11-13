#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;                         // number of vertices
    vector<vector<int>> adjMatrix; // adjacency matrix

public:
    Graph(int v)
    {
        this->V = v;
        adjMatrix.resize(V, vector<int>(V, 0)); // initialize VxV matrix with 0s
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // for undirected graph
    }

    void printAdjMatrix()
    {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjMatrix();

    return 0;
}
