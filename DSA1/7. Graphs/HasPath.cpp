#include <bits/stdc++.h>
#include "ConnectedDisconnected.cpp"
using namespace std;

bool DFSTraversal(int **edges, int v, int startv, int endv, bool *visited)
{
    int ans = false;
    visited[startv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == startv)
        {
            continue;
        }
        if (edges[startv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            if (i == endv)
            {
                return true;
            }
            DFSTraversal(edges, v, i, endv, visited);
        }
    }
    return false;
}

int main()
{
    int startv, endv;
    cin >> startv >> endv;

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

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    bool ans = DFSTraversal(edges, v, startv, endv, visited);
    cout << ans;
    return 0;
}