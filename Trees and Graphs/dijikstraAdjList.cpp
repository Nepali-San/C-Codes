#include <bits/stdc++.h>
using namespace std;

int minkey(bool visited[], int keys[], int v)
{
    int min = 1000, min_idx = -1;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (min > keys[i])
            {
                min = keys[i];
                min_idx = i;
            }
        }
    }    

    return min_idx;
}

void printparent(int u,int parent[]){
    if(u != -1){
        cout << u << " ";
        printparent(parent[u],parent);
    }
}

void shortestPath(int v, int e, list<pair<int, int>> nodes[])
{
    int source = 0;

    bool visited[v];
    int keys[v];
    int parent[v];

    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        keys[i] = 1000;
        parent[i] = -1;
    }

    keys[source] = 0;

    for (int i = 0; i < v-1; i++)
    {
        int u = minkey(visited, keys, v);

        visited[u] = true;

        for (auto i : nodes[u])
        {
            if (!visited[i.first] && keys[u] + i.second < keys[i.first])
            {
                keys[i.first] = keys[u] + i.second;
                parent[i.first] = u;
            }
        }
    }

    for(int i = 0; i < v; i++){
        cout << "keys[" << i << "] = " << keys[i] << endl;
    }    

    // printparent(5,parent);
    cout << endl;
}

int main()
{

    int v, e;
    int src, dest, wt;

    cin >> v >> e;

    list<pair<int, int>> nodes[v];

    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> wt;
        nodes[src].push_back(make_pair(dest, wt));
        nodes[dest].push_back(make_pair(src, wt));
    }

    shortestPath(v, e, nodes);

    return 0;
}