#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int v,e;
	scanf("%d%d",&v,&e);

	int src,dest;
	vector<int> g[v];

	vector<int> indeg(v,0);

	for(int  i = 0; i < e; i++){
		scanf("%d%d",&src,&dest);
		src--; dest--;
		g[src].push_back(dest);
		indeg[dest]++;
	}

	queue<int> q;
	for(int i = 0; i < v; i++)
		if(indeg[i] == 0)
			q.push(i);

	int cnt = 0;

	vector<int> ans;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);

		for(auto it:g[u]){
			if(--indeg[it] == 0){
				q.push(it);
			}
		}

		cnt++;
	}

	if(cnt != v){
		printf("cycle exists\n");
		exit(0);
	}

	for(int i = 0; i < v; i++){
		printf("%d ",ans[i]+1);
	}

	puts("");

	return 0;
}

