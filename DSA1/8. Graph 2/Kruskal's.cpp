#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int source;
    int desitination;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void kruskal(Edge *input, int n, int E)
{
    // sorting the input array on the basis of weight;
    sort(input, input + E, compare);

    // creating arrays
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;

    // working on Solution
    while (count != n - 1)
    {
        Edge currentEdge = input[i];

        // check if current edge can be added to MST or not.
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.desitination, parent);

        if (sourceParent != destinationParent)
        {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destinationParent;
        }
        i++;
    }

    // Printing output array (if condiotion samagh ni ayi)
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].desitination)
            cout << output[i].source << " " << output[i].desitination << " " << output[i].weight << endl;
        else
            cout << output[i].desitination << " " << output[i].source << " " << output[i].weight << endl;
    }
}

int main()
{
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E];

    // Taking input
    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].desitination = d;
        input[i].weight = w;
    }

    kruskal(input, n, E);
    return 0;
}