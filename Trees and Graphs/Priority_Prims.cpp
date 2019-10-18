/*
    Time  : 2019-10-18,Friday
    Desc  : no description
*/

#include <bits/stdc++.h>

#define endl                         '\n'
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pii                          pair<int,int>

using namespace std;

int prims(vector<pii> g[],int v){

    priority_queue<pii, vector<pii>,greater<pii> > pq;
    vector<bool> visited(v,false);

    int minCost = 0;
    
    pq.push({0,0});

    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        
        if(visited[top.second]){
            continue;
        }

        minCost += top.first;
        visited[top.second] = true;

        for(auto it : g[top.second]){
            if(!visited[it.second]){
                pq.push(it);
            }
        }
    }

    return minCost;
}

int main() {
    ALLONS_Y;

    int v,e;
    cin >> v >> e; 
    vector<pii> g[v];

    int src,dest,wt;
    for(int i = 0; i < e; i++){
        cin >> src >> dest >> wt;
        g[src].push_back({wt,dest});
        g[dest].push_back({wt,src});
    }

    cout << prims(g,v) << endl;

    return 0;
}