#include <bits/stdc++.h>

using namespace std;

int v,e;

void alltopo(vector<int> &ans,vector<bool> &visited,list<int> g[],vector<int> &indeg){
	bool flag = false;

	for(int i = 0; i < v; i++){
		if(indeg[i] == 0 && !visited[i]){
			for(auto j : g[i]) indeg[j]--;

			ans.push_back(i);
			visited[i] = true;

			alltopo(ans,visited,g,indeg);

			visited[i] = false;
			ans.erase(ans.end()-1);

			for(auto j : g[i]){
				indeg[j]++;
			}

			flag = true;
		}
	}

	if(!flag){
		for(int i = 0; i < ans.size(); i++){
			printf("%d ",ans[i]);
		}
		puts("");
	}

}

int main() {
	
	scanf("%d%d",&v,&e);

	list<int> g[v];
	vector<int> indeg(v,0);
	int src,dest;

	for(int i = 0; i < e; i++){
		scanf("%d%d",&src,&dest);
		g[src].push_back(dest);
		indeg[dest]++;
	}

	vector<bool> visited(v,false);
	vector<int> ans;
	alltopo(ans,visited,g,indeg);
	return 0;
}

