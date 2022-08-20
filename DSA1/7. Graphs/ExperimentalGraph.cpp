#include <bits/stdc++.h>
using namespace std;

// void printDFS(vector<vector<int>> v, int n, int sv, vector<int> visited)
// {
//     cout << sv << endl;
//     visited[sv] = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == sv)
//         {
//             continue;
//         }
//         if (v[sv][i] == 1 && !visited[i])
//         {
//             printBFS(v, n, i, visited);
//         }
//     }
// }

void printDFS(vector<vector<int>> v, int n, int sv, vector<int> visited)
{
    queue<int> pendingvertices;
    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentVertex = pendingvertices.front();
        pendingvertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
            {
                continue;
            }
            if (v[currentVertex][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<int> visited(n, 0);
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        v[f][s] = 1;
        v[s][f] = 1;
    }
    printDFS(v, n, 0, visited);
    fill(visited.begin(), visited.end(), 0);
    // print(v, n, 0, visited);

    return 0;
}