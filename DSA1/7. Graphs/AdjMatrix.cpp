// 1) arrays of vertices and edges                                                          (edge list)
// 2) array of arrays first array of vertices and further with those it is connected with   (Adjacency list)
// 3) with all vertices                                                                     (Adjcancy matrix) space - n^2

#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int v, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, v, i, visited);
        }
    }
}

void printBFS(int **edges, int v, int sv)
{
    queue<int> pendingvertices;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        pendingvertices.pop();
        cout << currentvertex << endl;
        for (int i = 0; i < v; i++)
        {
            if (i == currentvertex)
            {
                continue;
            }
            if (edges[currentvertex][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // bool *visited = new bool[v];
    // for (int i = 0; i < v; i++)
    // {
    //     visited[i] = false;
    // }
    // print(edges, v, 0, visited);
    cout << endl;
    printBFS(edges, v, 0);

    // deleting the dynamic array
    // delete[] visited;
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }

    return 0;
}