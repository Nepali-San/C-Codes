#include<iostream>
#include<vector>
using namespace std;

void DFS(vector<vector<int> > &graph, int src, bool visited[]){
	visited[src] = true;
//	cout << src << " ";

	for(int i = 1; i < graph.size(); i++){
		if(visited[i] == false && graph[src][i]){
			DFS(graph,i,visited);
		}
	}
}

int main(){
	int v;
	int e;
	int a, b;
	cin >> v >> e;
	
	bool visited[v+1];
	fill(visited,visited+v+1,false);	
    vector<vector<int> > graph(v + 1, vector<int> (v + 1,0));
    
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	
	}
	
    int count = 0;
    for(int i = 1; i <= v; i++){
    	if(visited[i] == false){
    		DFS(graph,i,visited);
    		count++;
		}
    	
	}
	
	cout << count << " is the no. of components ";	
	return 0;
}
