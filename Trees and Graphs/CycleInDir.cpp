
#include<iostream>
#include<vector>
int v;
using namespace std;

int detector(int src, bool visited[],bool rstack[],vector< vector<int> > &graph){
	if(!visited[src]){
		visited[src] = true;
		rstack[src] = true;
		
		for(int i = 0; i < v; i++){
			if(graph[src][i]){
				if(!visited[i] && detector(i,visited,rstack,graph)) return true;					
				else if(rstack[i]) return true;
			}
		}
	}
	rstack[src] = false;
	return false;
}

int main(){
	int  e;
	cin >> v >> e;
	vector< vector<int> > graph(v,vector<int> (v,0));
	for(int i = 0; i < e; i++){
		int a , b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	bool visited[v];
	fill(visited,visited+v,false);
	
	bool Rstack[v];
	fill(Rstack,Rstack+v,false);
	bool flag = false;
	for(int i = 0; i < v; i++){
		if(detector(i,visited,Rstack,graph)){
			flag = true;
			break;
		}
	}
	
	if(flag) cout << "Cycle" << endl;
	else cout << "No cycle" << endl;
	return 0;
}
