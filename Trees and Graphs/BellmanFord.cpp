
#include<iostream>
#include<stack>
#include<queue>
#include<vector>

#define INF INT8_MAX
using namespace std;

int v; 
void function(vector< vector<int> > &graph){

	int key[v];
	fill(key,key+v,INF);
	
	key[0] = 0;
	
	bool flag;
	for(int i = 0; i < v - 1; i++){  
		flag = true;
		//use pairs to avoid nested loop below for edge(u,j)...
		for(int u = 0; u < v; u++){
			for(int j = 0; j < v; j++){
				if(graph[u][j] && key[u] != INF && key[j] > graph[u][j] + key[u]){
					key[j] = graph[u][j] + key[u];
					flag = false;
				}
			}		
	}
	
	if(flag){ cout << "broke in" << i << " iterations" << endl; break;}
	
	}
	

	//above iteration should have relaxed every edge if no negative edge cycle present... 
	for(int u = 0; u < v; u++){
		for(int j = 0; j < v; j++){
			if(graph[u][j] && key[u] != INF && key[j] > graph[u][j] + key[u]){
			cout << "negative cycle detected" << endl;
			exit(2);
			}
		}
	}

	for(int k = 0; k < v; k++){
		cout << k << " " << key[k] << endl;
	}
	
}

int main(){
	int e;
	cin >> v >> e;
	
	vector< vector<int> > graph(v,vector<int>(v,0));
	
	for(int i = 0; i < e; i++){
		int a, b,c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	
	function(graph);
	
	return 0;
}
