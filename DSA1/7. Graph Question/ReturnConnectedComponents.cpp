#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int v, int sv, bool *visited)
{
    // cout << sv << endl;
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

int DFS(int **edges, int v)
{
    int count = 0;
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
            count++;
        }
    }
    delete[] visited;
    return count;
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

    int ans = DFS(edges, v);
    cout << ans;
    return 0;
}