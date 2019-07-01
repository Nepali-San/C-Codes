#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void topological_dfs(int src,vector<int> g[],vector<bool> &visited){
	visited[src] = true;

	for(auto it : g[src]){
		if(!visited[it]){
			topological_dfs(it,g,visited);
		}
	}

	ans.push_back(src);
}

int main() {
	
	int v,e;
	scanf("%d%d",&v,&e);

	vector<int> g[v];

	int src,dest;
	for(int i = 0; i < e; i++){
		cin >> src >> dest; 
		src--; dest--;
		g[src].push_back(dest);	
	}
	
	vector<bool> visited(v,false);

	for(int i = 0; i < v; i++){
		if(visited[i] == true) continue;

        	topological_dfs(i,g,visited);

	}

	//reversely display the vector
	for(int i = ans.size()-1; i >= 0; i--){
		printf("%d ",ans[i]+1);
	}
	puts("");  			//inplace of \n

	return 0;
}

