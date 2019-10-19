/*
    Time  : 2019-10-19,Saturday
    Desc  : no description
*/

#include <bits/stdc++.h>

#define ull         unsigned long long int
#define ll          long long int
#define endl        '\n'
#define pb(x)       push_back(x)
#define ALLONS_Y    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x)    cout << #x << ' = ' << x << endl
#define pii         pair<int,int>

#define DEBUG 1

using namespace std;

int find(int parent[],int src){
    if(parent[src] == src) return src;
    parent[src] = find(parent,parent[src]);
    return parent[src];
}

void unite(int parent[],int rank[],int src,int dest){
    int s = parent[src];
    int d = parent[dest];

    if(rank[s] < rank[d]){
        parent[s] = d;
    }else if(rank[s] > rank[d]){
        parent[d] = s;
    }else{
        rank[s]++;
        parent[d] = s;
    }
}


int krus(pair<int,pii> g[],int v,int e){

    int parent[v];
    int rank[v];

    for(int i = 0; i < v; i++){
        parent[i] = i;
        rank[i] = 0;
    }

    int min_cost = 0;

    for(int i = 0; i < e; i++){

        int src = g[i].second.first;
        int dest = g[i].second.second;
        int wt = g[i].first;

          if(find(parent,src) != find(parent,dest)){
              unite(parent,rank,src,dest);
              min_cost += wt;
          }
    }

    return min_cost;
}

int main() {
    ALLONS_Y;

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
    #endif

    int v,e;
    cin >> v >> e;

    pair<int,pii> g[e];

    int src,dest,wt;
    for(int i = 0; i < e; i++){
        cin >> src >> dest >> wt;
        g[i] = {wt,{src,dest}};
    }

    sort(g,g+e);

    cout << krus(g,v,e) << endl;

    return 0;
}