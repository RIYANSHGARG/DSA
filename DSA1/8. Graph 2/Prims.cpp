// Prims Algo : one of the ways of finding MST(Min. spanning tree)

#include <bits/stdc+++.h>
using namespace std;
void Prims(int **edges, int v)
{

    // Creating all the needed arrays and initializing
    int *parent = new int[v];
    int *weight = new int[v];
    bool *visited = new bool[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    Prims(edges, v);
    return 0;
}