#include <bits/stdc++.h>
using namespace std;

vector<int> AllConnectedGraphHelper(int **edges, int v, int sv, int *visited)
{
    vector<int> ans;
    ans.push_back(sv);
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] && !visited[i])
        {
            AllConnectedGraphHelper(edges, v, i, visited);
        }
    }
    return ans;
}

vector<vector<int>> AllConnectedGraph(int **edges, int v)
{
    vector<vector<int>> ans;
    int *visited = new int[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i])
        {
            continue;
        }
        else
        {
            vector<int> Connected = AllConnectedGraphHelper(edges, v, i, visited);
            ans.push_back(Connected);
        }
    }
    delete[] visited;
    return ans;
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

    vector<vector<int>> ans;
    ans = AllConnectedGraph(edges, v);
    // v = AllConnectedGraph(edges, v);
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    // }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; i < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}