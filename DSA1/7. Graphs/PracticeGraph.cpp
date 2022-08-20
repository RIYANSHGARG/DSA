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
        if (edges[sv][i] == 1 && !visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
}

void printBFS(int **edges, int v, int sv, bool *visited)
{
    queue<int> pendingvertices;
    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentVertex = pendingvertices.front();
        pendingvertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < v; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                // cout << i << endl;
                pendingvertices.push(i);
                visited[i] = true;
            }
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

    cout << "Printing Graph in DFS : " << endl;
    printDFS(edges, v, 0, visited);
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    cout << "Printing Graph in BFS : " << endl;
    printBFS(edges, v, 0, visited);

    // deleting
    delete[] visited;
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}