#include<iostream>
#include<queue>

using namespace std;

int main(){
	int n,e,a,b;
	
	cin >> n >> e;
	int graph[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			graph[i][j] = 0;
		}
	}
	
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	
	int start = 0;
	queue<int> q;
	q.push(start);
	
	bool visited[n];	
	fill(visited,visited+n,false);
	visited[0] = true;
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		cout << u+1 << " " ;
		for(int i = 0; i < n; i++){
			if(graph[u][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}		
	return 0;
}
