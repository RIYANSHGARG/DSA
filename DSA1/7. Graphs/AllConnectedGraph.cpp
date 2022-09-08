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
            ans = AllConnectedGraphHelper(edges, v, i, visited);
            ans.push_back(sv);
        }
    }
    return ans;
}

vector<vector<int>> AllConnectedGraph(int **edges, int v)
{
    vector<vector<int>> ans;
    vector<int> Connected;
    int *visited = new int[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i])
            continue;
        else
        {
            Connected = AllConnectedGraphHelper(edges, v, i, visited);
            cout << Connected.size() << " ";
            ans.push_back(Connected);
        }
        for (int j = 0; j < Connected.size(); j++)
        {
            cout << Connected[j] << " ";
        }
        cout << endl;
    }
    cout << ans.size() << " " << ans[0].size() << endl
         << ans[1][2];
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
    cout << ans.size() << " " << ans[0].size() << endl;
    cout << ans[0][0] << ans[0][1] << ans[0][2] << ans[0][3];
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; i < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}