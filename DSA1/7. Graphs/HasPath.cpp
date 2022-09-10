#include <bits/stdc++.h>
using namespace std;

bool DFSTraversal(int **edges, int v, int startv, int endv, bool *visited)
{
    visited[startv] = true;
    if (startv == endv)
    {
        return true;
    }
    for (int i = 0; i < v; i++)
    {
        if (i == startv)
        {
            continue;
        }
        if (edges[startv][i] == 1 && !visited[i])
        {
            if (DFSTraversal(edges, v, i, endv, visited))
                return true;
        }
    }
    return false;
}

// if (i == endv)
//             {
//                 return true;
//             }
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
    bool result = DFSTraversal(edges, v, startv, endv, visited);
    cout << result;
    return 0;
}

// 0 3
// 5 5
// 0 1
// 0 2
// 2 4
// 1 3
// 2 3