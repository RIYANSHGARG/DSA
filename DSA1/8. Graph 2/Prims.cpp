// Prims Algo : one of the ways of finding MST(Min. spanning tree)
// Time Complexity : O(n^2)

// OPTIMISE
// Adjcancy list
// Binary min Priority Queue O(log N)
// Time Complexity : O((V+E)log V)

// #include <bits/stdc+++.h>
#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int v)
{
    int minVertex = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

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

    for (int i = 0; i < v - 1; i++)
    {
        // Finding the min vertex
        int minVertex = findMinVertex(weight, visited, v);
        visited[minVertex] = true;
        // exploring the unvisited vertcies/neighbours
        for (int j = 0; j < v; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for (int i = 1; i < v; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
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

// 5 7
// 0 1 4
// 0 2 8
// 1 3 5
// 1 2 2
// 2 3 5
// 2 4 9
// 3 4 5