#include <iostream>
#include <vector>
#include <list>
using namespace std;

// AdjacencyList : store all neighbours for all Vertices

class Graph
{
    int V;
    list<int> *l; // declaring a dynamic array // int arr*;
    // above steps declares a dynamic array of type list<int> (list of type int)

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V]; // like initialising a dynamic array // arr = new int[V]
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int neigh : l[i])
            {
                cout << neigh << " ";
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

    g.printAdjList();
    return 0;
}
