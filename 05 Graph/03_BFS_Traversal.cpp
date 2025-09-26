#include <iostream>
#include <vector>
#include <list>
#include <list>
#include <queue>
using namespace std;

// AdjacencyList : store all neighbours for all Vertices

class Graph
{
    int V;
    list<int> *l; // declaring a dynamic array // int arr*;

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

    void BFS_TRAVERSAL() // time complexicity : O(V + E) 
    
    // V : no of vertices // E : no of edges
    {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int u = q.front(); // u-v
            q.pop();

            cout << u << " ";

            for (int v : l[u]) // v-> immidiate neighbour
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            } 
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

    g.BFS_TRAVERSAL();
    return 0;
}
