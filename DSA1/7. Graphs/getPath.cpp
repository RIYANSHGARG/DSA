#include <bits/stdc++.h>
using namespace std;

vector<int> getPathDFSHelper(int **edges, int v, int startv, int endv, bool *visited)
{
    vector<int> ans;
    if (startv == endv)
    {
        ans.push_back(endv);
        return ans;
    }
    visited[startv] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[startv][i] == 1 && !visited[i])
        {
            ans = getPathDFSHelper(edges, v, i, endv, visited);
            if (ans.size() != 0)
            {
                ans.push_back(startv);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> getPathDFS(int **edges, int v, int startv, int endv)
{

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    vector<int> output = getPathDFSHelper(edges, v, startv, endv, visited);
    return output;
}

// need maps to keep track of which vertex is connected with which vertex.

vector<int> getPathBFSHelper(int **edges, int v, int startv, int endv, bool *visited)
{
    vector<int> ans;

    if (startv == endv)
    {
        ans.push_back(endv);
        return ans;
    }
    visited[startv] = visited;
    queue<int> pendingvertices;
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator itr;
    pendingvertices.push(startv);
    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        pendingvertices.pop();
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
                m[i] = currentvertex;
                if (currentvertex == endv)
                {
                    int leftsidemap;
                    ans.push_back(currentvertex);
                    for (itr = m.find(i); itr != m.end(); i++)
                    {
                        if (itr->first == 0)
                        {
                            ans.push_back(0);
                            return ans;
                        }
                        ans.push_back(itr->second);
                        leftsidemap = itr->first;
                        if (itr->second == leftsidemap)
                        {
                            leftsidemap = itr->first;
                        }
                    }
                    break;
                }
            }
        }
    }
    return ans;
}

vector<int> getPathBFS(int **edges, int v, int startv, int endv)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    vector<int> output = getPathDFSHelper(edges, v, startv, endv, visited);
    return output;
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

    vector<int> ans = getPathBFS(edges, v, startv, endv);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}