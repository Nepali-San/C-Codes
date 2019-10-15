/*
    Time  : 2019-10-15,Tuesday
    Desc  : checking if graph is bipartite using DFS.
*/

#include <bits/stdc++.h>

#define endl                         '\n'
#define pb(x)                        push_back(x)
#define ALLONS_Y                     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

enum color{
    white,
    black,
    none
};

bool DFS(vector<vector<int>> &g, int src , vector<color> &colors,color currentColor = color::white){    

    for(auto it : g[src]){
        if (colors[it] == color::none ){

            // * color the node with adjacent color.
            colors[it] = (color)(1 - currentColor);
            
            // * recursively color other node with appropriate color.
            // * if any single node of graph returns false, then return false until it reaches to main()            
            // * to avoid checking for unchecked nodes which may return true. 

            if(!DFS(g, it, colors, colors[it])) return false;           
        }
        else if (colors[it] == currentColor){

            // * if parent and child have same color , then it is not bipartite so return false.
            return false;
        }
    }

    return true;
}

int main() {
    ALLONS_Y;

    int v, e;
    int src, dest;    

    cin >> v >> e;

    vector<vector<int> > g(v);

    for (int i = 0; i < e; i++){
        cin >> src >> dest;
        g[src].push_back(dest);
        g[dest].push_back(src);
    }
    
    vector<color> colors(v, color::none);

    // * Here 0 is assumed to be source vertex which color is white,
    colors[0] = color::white;

    bool isBipartite = DFS(g,0,colors);

    if(isBipartite) cout << "Bipartite" << endl;
    else            cout << "Not Bipartite" << endl;

    return 0;
}