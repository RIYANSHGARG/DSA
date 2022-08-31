#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int v, int sv, bool *visited)
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
            printDFS(edges, v, i, visited);
        }
    }
}

void DFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}

void printBFS(int **edges, int v, int sv, bool *visited)
{
    queue<int> pendingvertices;
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
}

void BFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}

void graph()
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

    // cout << "Printing graph as DFS : " << endl;
    // DFS(edges, v);
    // cout << "Printing graph as BFS : " << endl;
    // BFS(edges, v);

    // deleting the dynamic array

    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
}

// int main()
// {
//     graph();
//     return 0;
// }