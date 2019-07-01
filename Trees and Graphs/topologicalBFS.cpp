//Topological sort using BFS
#include<iostream>
#include<queue>
using namespace std;
int v; 

void T_sort(vector< vector<int > > & graph, int in_deg[]){
	bool visited[v+1];	
	fill(visited, visited+v+1,false);
	queue<int> q;
	
	for(int i = 1; i < v+1; i++){
		if(in_deg[i] == 0){
			q.push(i);
			visited[i] = true;
		}
	}	
	
	while(!q.empty()){
		int u = q.front();		
		q.pop();
		cout << u << " " ;
		for(int i = 1; i <= v; i++){
			if(graph[u][i] && !visited[i]){
				in_deg[i]--;
			    if(in_deg[i] == 0){
					q.push(i);
					visited[i] = true;
			   	}
			}
		}
	}	
} 

int main(){
	/*
7 7
4 1
4 5
4 6
1 2
2 3
5 3
6 7
	*/
	int e;
	cin >> v >> e;

	vector< vector<int > > graph(v+1, vector<int> ( v+1,0));
	
	int in_deg[v+1];
	
	fill(in_deg,in_deg+v+1,0);
	
	for(int i = 0; i < e; i++){
		int a,b;
		cin >> a >> b;
		graph[a][b] = 1;
		in_deg[b]++;
	}
	
	T_sort(graph,in_deg);
	return 0;
}
