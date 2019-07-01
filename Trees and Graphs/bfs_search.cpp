#include<bits/stdc++.h>
using namespace std;

int main(){
	int v,e;
	cin >> v >> e;
	int a,b;
	list<int> l[v];
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		l[a-1].push_back(b-1);
		l[b-1].push_back(a-1);
	}
	
	vector<bool> visited(v,false);
	
	queue<int> Q;
	Q.push(0);
	visited[0] = true;
	
	int search;
	cin >> search;
	vector<int> dist(v);
	
	
	while(!Q.empty()){
		int u = Q.front();		
		Q.pop();
		
		if(u == search-1) cout << dist[u];	//distance from the source vertex...		
		
		for(list<int>::iterator it = l[u].begin(); it != l[u].end(); it++){
			if(!visited[*it]){
				Q.push(*it);
				visited[*it] = true;
				dist[*it] = dist[u] + 1;
			}
		}				
	}
	
	return 0;
}
