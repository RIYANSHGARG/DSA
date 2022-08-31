#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int v, int sv, bool *visited)
{
    // newvector oldvector
    vector<int> ans;
    ans.push_back(sv);
    // cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] > 0 && !visited[i])
        {
            if (i == endv)
            {
                newsum += edges[sv][i];
                return ans.push_back(i);
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
    BFS(edges, v);
    cout << endl;
    DFS(edges, v);
    return 0;
}